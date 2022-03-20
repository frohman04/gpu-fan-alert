#![forbid(unsafe_code)]

extern crate anyhow;
extern crate ati_adl_sys;
extern crate cpal;
extern crate crossbeam_channel;
extern crate ctrlc;
#[macro_use]
extern crate log;
extern crate simplelog;

mod gpu;
mod sound;

use crossbeam_channel::{bounded, select, tick, Receiver};
use gpu::Gpu;
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

    let gpu = Gpu::get_active_gpu();

    fn ctrl_channel() -> Result<Receiver<()>, ctrlc::Error> {
        let (sender, receiver) = bounded(100);
        ctrlc::set_handler(move || {
            let _ = sender.send(());
        })?;

        Ok(receiver)
    }

    let ctrl_c_events = ctrl_channel()?;
    let ticks = tick(Duration::from_secs(2));

    check_temps(&gpu)?;
    loop {
        select! {
            recv(ticks) -> _ => {
                check_temps(&gpu)?;
            }
            recv(ctrl_c_events) -> _ => {
                info!("Exiting!");
                break;
            }
        }
    }

    Ok(())
}

fn check_temps(gpu: &Gpu) -> anyhow::Result<()> {
    for (adapter, result) in gpu.get_temps() {
        match result {
            Ok(temps) => {
                info!(
                    "Fan speed: {:>5?} RPM ({:>4?}% max) | Temp: {:>2?} \u{00b0}C",
                    temps.fan_speed_rpm, temps.fan_speed_pct, temps.temp_c
                );

                if temps.fan_speed_rpm == 65535 {
                    sound::alert()?;
                }
            }
            Err(s) => eprintln!("Unable to get sensors for adapter {:?}: {:?}", adapter, s),
        }
    }

    Ok(())
}
