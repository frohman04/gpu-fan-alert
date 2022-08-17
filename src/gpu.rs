use ati_adl_sys::{
    Adl, AdlAdapterInfo, AdlSensorType, AdlStatus, ADL_CONTEXT_HANDLE, ATI_VENDOR_ID,
};
use int_enum::IntEnum;
use sysinfo::{ProcessExt, System, SystemExt};
use tracing::{info, warn};

use std::fs;
use std::process::Command;

pub struct Gpu {
    adl: Adl,
    context: ADL_CONTEXT_HANDLE,
    active_adapters: Vec<AdlAdapterInfo>,
    system: System,
}

impl Gpu {
    pub fn get_active_gpu() -> Self {
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
            let active_adapters = Self::get_active_adapters(&adl);
            info!(
                "Found {:?} active adapters from ATI/AMD: {:?}",
                active_adapters.len(),
                active_adapters
                    .iter()
                    .map(|a| a.adapter_name.clone())
                    .collect::<Vec<String>>()
            );

            Gpu {
                adl,
                context,
                active_adapters,
                system: System::new_all(),
            }
        } else {
            panic!("Unable to find any active GPUs")
        }
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

    pub fn get_temps(&self) -> Vec<(String, Result<TempInfo, AdlStatus>)> {
        self.active_adapters
            .iter()
            .map(|adapter| {
                match self
                    .adl
                    .ADL2_New_QueryPMLogData_Get(self.context, adapter.adapter_index)
                {
                    Ok((_, sensors)) => {
                        let fan_speed_rpm =
                            sensors.get(&AdlSensorType::PMLOG_FAN_RPM).unwrap().value;
                        let fan_speed_pct = sensors
                            .get(&AdlSensorType::PMLOG_FAN_PERCENTAGE)
                            .unwrap()
                            .value;
                        let temp_c = sensors
                            .get(&AdlSensorType::PMLOG_TEMPERATURE_HOTSPOT)
                            .unwrap()
                            .value;

                        (
                            adapter.adapter_name.clone(),
                            Ok(TempInfo {
                                fan_speed_rpm,
                                fan_speed_pct,
                                temp_c,
                            }),
                        )
                    }
                    Err(s) => (adapter.adapter_name.clone(), Err(s)),
                }
            })
            .collect()
    }

    pub fn ensure_asrock_tweak_tool_running(&mut self) {
        self.system.refresh_processes();
        if self
            .system
            .processes()
            .iter()
            .filter(|(_pid, proc)| !proc.cmd().is_empty() && proc.cmd()[0].contains("AsrPGT"))
            .peekable()
            .peek()
            .is_none()
        {
            info!(
                "Unable to find running ASRock Tweak Tool process.  \
                Restarting and resetting to known state"
            );
            self.reset_fan_throttle();
        }
    }

    fn kill_asrock_tweak_tool(&mut self) {
        self.system.refresh_processes();
        for (pid, proc) in self
            .system
            .processes()
            .iter()
            .filter(|(_pid, proc)| !proc.cmd().is_empty() && proc.cmd()[0].contains("AsrPGT"))
        {
            info!("Killing ASRock Tweak Tool (process {})", pid);
            if !proc.kill() {
                warn!("Unable to kill process!");
            }
        }
    }

    fn set_fan_throttle(&self, fan_throttle: FanThrottle) {
        let file_name = "C:\\Program Files (x86)\\ASRock Utility\\ASRPGT\\Bin\\AsrPGT.ini";

        let curr_file_contents = fs::read_to_string(file_name)
            .unwrap_or_else(|_| panic!("Unable to read config file {}", file_name));
        let new_file_contents = curr_file_contents
            .split('\n')
            .into_iter()
            .map(|line| {
                if line.starts_with("FanMode") {
                    format!("FanMode={}", fan_throttle.int_value())
                } else {
                    line.to_string()
                }
            })
            .collect::<Vec<String>>()
            .join("\n");

        fs::write(file_name, new_file_contents)
            .unwrap_or_else(|_| panic!("Unable to write config file {}", file_name));
    }

    fn launch_asrock_tweak_tool(&self) {
        Command::new("C:\\Program Files (x86)\\ASRock Utility\\ASRPGT\\Bin\\AsrPGT.exe")
            .spawn()
            .expect("Unable to launch ASRock Tweak Tool");

        // allow time for process to complete launching before continuing
        std::thread::sleep(std::time::Duration::from_millis(2000));
    }

    pub fn reset_fan_throttle(&mut self) {
        self.kill_asrock_tweak_tool();
        info!("Changing to fixed fan throttle");
        self.set_fan_throttle(FanThrottle::Fixed);
        self.launch_asrock_tweak_tool();
        self.kill_asrock_tweak_tool();
        info!("Changing back to smart fan throttle");
        self.set_fan_throttle(FanThrottle::Smart);
        self.launch_asrock_tweak_tool();
    }
}

#[repr(u8)]
#[derive(Clone, Copy, Debug, Eq, PartialEq, IntEnum)]
enum FanThrottle {
    Smart = 0,
    Fixed = 1,
    Customize = 2,
}

impl Drop for Gpu {
    fn drop(&mut self) {
        self.adl
            .ADL2_Main_Control_Destroy(self.context)
            .expect("Unable to destroy ADL2");
        self.adl
            .ADL_Main_Control_Destroy()
            .expect("Unable to destroy ADL");
    }
}

pub struct TempInfo {
    pub fan_speed_rpm: i32,
    pub fan_speed_pct: i32,
    pub temp_c: i32,
}
