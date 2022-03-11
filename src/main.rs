extern crate anyhow;
extern crate cpal;
#[macro_use]
extern crate int_enum;
extern crate libc;
extern crate libloading;
extern crate strum;
extern crate strum_macros;
extern crate time;

mod adl;
mod sound;

use crate::adl::{Adl, ATI_VENDOR_ID};
use crate::adl::{AdlAdapterInfo, AdlSensorType};

fn main() -> anyhow::Result<()> {
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
    println!("Found {} adapters", num_adapters);

    if num_adapters > 0 {
        let active_adapters: Vec<AdlAdapterInfo> = match adl.ADL_Adapter_AdapterInfo_Get() {
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
        };
        println!(
            "Found {:?} active adapters from ATI/AMD: {:?}",
            active_adapters.len(),
            active_adapters
                .iter()
                .map(|a| a.adapter_name.clone())
                .collect::<Vec<String>>()
        );
        for adapter in active_adapters {
            println!(
                "{}",
                time::OffsetDateTime::now_local()?
                    .format(&time::format_description::well_known::Rfc2822)?
            );
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
                    println!(
                        "  Fan speed (RPM): {:?} ({:?}%)",
                        fan_speed_rpm, fan_speed_pct
                    );
                    println!("  Temp (deg C):    {:?}", temp_c);

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
    }

    adl.ADL2_Main_Control_Destroy(context)
        .expect("Unable to destroy ADL2");
    adl.ADL_Main_Control_Destroy()
        .expect("Unable to destroy ADL");

    Ok(())
}
