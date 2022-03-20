use ati_adl_sys::{
    Adl, AdlAdapterInfo, AdlSensorType, AdlStatus, ADL_CONTEXT_HANDLE, ATI_VENDOR_ID,
};

pub struct Gpu {
    adl: Adl,
    context: ADL_CONTEXT_HANDLE,
    active_adapters: Vec<AdlAdapterInfo>,
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
