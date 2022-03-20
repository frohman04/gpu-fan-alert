#![forbid(unsafe_code)]

extern crate anyhow;
extern crate ati_adl_sys;
extern crate cpal;
extern crate crossbeam_channel;
extern crate ctrlc;
#[macro_use]
extern crate log;
extern crate simplelog;

mod sound;

use ati_adl_sys::{Adl, ADL_CONTEXT_HANDLE, ATI_VENDOR_ID};
use ati_adl_sys::{AdlAdapterInfo, AdlSensorType};
use crossbeam_channel::{bounded, select, tick, Receiver};
use simplelog::{
    ColorChoice, CombinedLogger, ConfigBuilder, LevelFilter, TermLogger, TerminalMode,
};
use std::time::Duration;

fn main() -> anyhow::Result<()> {
    CombinedLogger::init(vec![TermLogger::new(
        LevelFilter::Info,
        ConfigBuilder::default()
            .set_time_format_str("%Y-%m-%d %H:%M:%S%z")
            .set_time_to_local(true)
            .build(),
        TerminalMode::Stderr,
        ColorChoice::Auto,
    )])
    .unwrap();

    let adl = Adl::default();
    adl.ADL_Main_Control_Create(1)
        .expect("Unable to create ADL");
    let context = adl
        .ADL2_Main_Control_Create(1)
        .expect("Unable to create ADL2")
        .1;

    let num_adapters = match adl.ADL_Adapter_NumberOfAdapters_Get() {
        Ok((_, num)) => num,
        Err(s) => panic!("Unable to get number of adapters: {:?}", s),
    };
    info!("Found {} adapters", num_adapters);

    if num_adapters > 0 {
        let active_adapters = get_active_adapters(&adl);
        info!(
            "Found {:?} active adapters from ATI/AMD: {:?}",
            active_adapters.len(),
            active_adapters
                .iter()
                .map(|a| a.adapter_name.clone())
                .collect::<Vec<String>>()
        );

        fn ctrl_channel() -> Result<Receiver<()>, ctrlc::Error> {
            let (sender, receiver) = bounded(100);
            ctrlc::set_handler(move || {
                let _ = sender.send(());
            })?;

            Ok(receiver)
        }

        let ctrl_c_events = ctrl_channel()?;
        let ticks = tick(Duration::from_secs(2));

        check_temps(&adl, context, &active_adapters)?;
        loop {
            select! {
                recv(ticks) -> _ => {
                    check_temps(&adl, context, &active_adapters)?;
                }
                recv(ctrl_c_events) -> _ => {
                    info!("Exiting!");
                    break;
                }
            }
        }
    }

    adl.ADL2_Main_Control_Destroy(context)
        .expect("Unable to destroy ADL2");
    adl.ADL_Main_Control_Destroy()
        .expect("Unable to destroy ADL");

    Ok(())
}

fn get_active_adapters(adl: &Adl) -> Vec<AdlAdapterInfo> {
    match adl.ADL_Adapter_AdapterInfo_Get() {
        Ok((_, infos)) => infos
            .into_iter()
            .filter_map(
                |adapter| match adl.ADL_Adapter_Active_Get(adapter.adapter_index) {
                    Ok((_, is_active)) => {
                        if is_active && adapter.vendor_id == ATI_VENDOR_ID {
                            Some(adapter)
                        } else {
                            None
                        }
                    }
                    Err(s) => panic!(
                        "Unable to get active status for adapter {:?}: {:?}",
                        adapter.adapter_index, s
                    ),
                },
            )
            .collect(),
        Err(s) => panic!("Unable to get adapter infos: {:?}", s),
    }
}

fn check_temps(
    adl: &Adl,
    context: ADL_CONTEXT_HANDLE,
    adapters: &[AdlAdapterInfo],
) -> anyhow::Result<()> {
    for adapter in adapters {
        match adl.ADL2_New_QueryPMLogData_Get(context, adapter.adapter_index) {
            Ok((_, sensors)) => {
                let fan_speed_rpm = sensors.get(&AdlSensorType::PMLOG_FAN_RPM).unwrap().value;
                let fan_speed_pct = sensors
                    .get(&AdlSensorType::PMLOG_FAN_PERCENTAGE)
                    .unwrap()
                    .value;
                let temp_c = sensors
                    .get(&AdlSensorType::PMLOG_TEMPERATURE_HOTSPOT)
                    .unwrap()
                    .value;
                info!(
                    "Fan speed: {:>5?} RPM ({:>4?}% max) | Temp: {:>2?} \u{00b0}C",
                    fan_speed_rpm, fan_speed_pct, temp_c
                );

                if fan_speed_rpm == 65535 {
                    sound::alert()?;
                }
            }
            Err(s) => eprintln!(
                "Unable to get sensors for adapter {:?}: {:?}",
                adapter.adapter_index, s
            ),
        }
    }

    Ok(())
}
