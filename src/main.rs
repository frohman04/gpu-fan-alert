#[macro_use]
extern crate int_enum;
extern crate libc;
extern crate libloading;
extern crate strum;
extern crate strum_macros;

mod adl;

use crate::adl::{AdlAdapterInfo, AdlSensorType};
use adl::{Adl, ATI_VENDOR_ID};

fn main() {
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
        let active_adapters: Vec<(i32, AdlAdapterInfo)> = match adl.ADL_Adapter_AdapterInfo_Get() {
            Ok((_, infos)) => infos
                .into_iter()
                .filter_map(
                    |adapter| match adl.ADL_Adapter_Active_Get(adapter.adapter_index) {
                        Ok((_, is_active)) => {
                            if is_active && adapter.vendor_id == ATI_VENDOR_ID {
                                match adl.ADL_Adapter_ID_Get(adapter.adapter_index) {
                                    Ok((_, adapter_id)) => Some((adapter_id, adapter)),
                                    Err(s) => panic!(
                                        "Unable to get adapter id for adapter {:?}: {:?}",
                                        adapter.adapter_index, s
                                    ),
                                }
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
            active_adapters.iter().map(|a| a.0).collect::<Vec<i32>>()
        );
        for adapter in active_adapters {
            match adl.ADL2_New_QueryPMLogData_Get(context, adapter.1.adapter_index) {
                Ok((_, sensors)) => {
                    println!(
                        "Fan speed (RPM): {:?} ({:?}%)",
                        sensors.get(&AdlSensorType::PMLOG_FAN_RPM).unwrap().value,
                        sensors
                            .get(&AdlSensorType::PMLOG_FAN_PERCENTAGE)
                            .unwrap()
                            .value
                    );
                    println!(
                        "Temp (deg C):    {:?}",
                        sensors
                            .get(&AdlSensorType::PMLOG_TEMPERATURE_HOTSPOT)
                            .unwrap()
                            .value
                    );
                }
                Err(s) => panic!(
                    "Unable to get sensors for adapter {:?}: {:?}",
                    adapter.1.adapter_index, s
                ),
            }
        }
    }

    adl.ADL2_Main_Control_Destroy(context)
        .expect("Unable to destroy ADL2");
    adl.ADL_Main_Control_Destroy()
        .expect("Unable to destroy ADL");
}
