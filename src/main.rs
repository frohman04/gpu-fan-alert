#![forbid(unsafe_code)]

extern crate anyhow;
extern crate ati_adl_sys;
extern crate cpal;
extern crate crossbeam_channel;
extern crate ctrlc;
#[macro_use]
extern crate int_enum;
extern crate nu_ansi_term;
extern crate sysinfo;
extern crate tracing;
extern crate tracing_appender;
extern crate tracing_subscriber;

mod gpu;
mod sound;

use crossbeam_channel::{bounded, select, tick, Receiver};
use gpu::Gpu;
use std::time::Duration;
use tracing::{info, info_span};
use tracing_subscriber::prelude::*;
use tracing_subscriber::{fmt, Registry};

fn main() -> anyhow::Result<()> {
    let ansi_enabled = nu_ansi_term::enable_ansi_support().map_or(false, |()| true);

    let file_appender = tracing_appender::rolling::hourly("./logs", "log");
    let (file_writer, _guard) = tracing_appender::non_blocking(file_appender);

    let subscriber = Registry::default()
        .with(
            fmt::Layer::default()
                .with_ansi(false)
                .with_writer(file_writer),
        )
        .with(
            fmt::Layer::default()
                .with_ansi(ansi_enabled)
                .with_writer(std::io::stderr),
        );
    tracing::subscriber::set_global_default(subscriber).expect("setting default subscriber failed");

    let mut gpu = Gpu::get_active_gpu();

    fn ctrl_channel() -> Result<Receiver<()>, ctrlc::Error> {
        let (sender, receiver) = bounded(100);
        ctrlc::set_handler(move || {
            let _ = sender.send(());
        })?;

        Ok(receiver)
    }

    let ctrl_c_events = ctrl_channel()?;
    let ticks = tick(Duration::from_secs(2));

    check_temps(&mut gpu)?;
    loop {
        select! {
            recv(ticks) -> _ => {
                check_temps(&mut gpu)?;
            }
            recv(ctrl_c_events) -> _ => {
                info!("Exiting!");
                break;
            }
        }
    }

    Ok(())
}

fn check_temps(gpu: &mut Gpu) -> anyhow::Result<()> {
    let span = info_span!("Checking temps");
    let _guard = span.enter();

    gpu.ensure_asrock_tweak_tool_running();

    for (adapter, result) in gpu.get_temps() {
        match result {
            Ok(temps) => {
                info!(
                    fan_speed_rpm = temps.fan_speed_rpm,
                    fan_speed_pct = temps.fan_speed_pct,
                    temp_c = temps.temp_c,
                    "Fan speed: {:>5?} RPM ({:>4?}% max) | Temp: {:>2?} \u{00b0}C",
                    temps.fan_speed_rpm,
                    temps.fan_speed_pct,
                    temps.temp_c,
                );

                if temps.fan_speed_rpm == 65535 {
                    gpu.reset_fan_throttle();
                }
            }
            Err(s) => eprintln!("Unable to get sensors for adapter {:?}: {:?}", adapter, s),
        }
    }

    // if any adapters still have an invalid speed, then alert audibly
    for (adapter, result) in gpu.get_temps() {
        match result {
            Ok(temps) => {
                if temps.fan_speed_rpm == 65535 {
                    sound::alert()?;
                }
            }
            Err(s) => eprintln!("Unable to get sensors for adapter {:?}: {:?}", adapter, s),
        }
    }

    Ok(())
}
