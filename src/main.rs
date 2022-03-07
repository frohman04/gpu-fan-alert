#[macro_use]
extern crate int_enum;
extern crate libc;
extern crate libloading;

mod adl;

use crate::adl::AdlAdapterInfo;
use adl::{Adl, ATI_VENDOR_ID};

fn main() {
    let adl = Adl::default();
    adl.ADL_Main_Control_Create(0)
        .expect("Unable to create ADL");

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
            println!("{:?}", adapter);
        }
    }

    adl.ADL_Main_Control_Destroy()
        .expect("Unable to destroy ADL");
}
