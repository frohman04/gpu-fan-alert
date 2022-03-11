#![allow(non_upper_case_globals)]
#![allow(non_camel_case_types)]
#![allow(non_snake_case)]

use int_enum::IntEnum;
use libloading::{Library, Symbol};
use std::collections::HashMap;
use std::hash::Hash;
use std::mem;
use std::os::raw::{c_char, c_int, c_void};
use std::ptr;
use strum::IntoEnumIterator;
use strum_macros::EnumIter;

pub const ATI_VENDOR_ID: i32 = 1002;

pub struct Adl {
    lib: Library,
}

impl Default for Adl {
    fn default() -> Self {
        unsafe {
            Self {
                lib: match Library::new("atiadlxx.dll") {
                    Ok(lib) => lib,
                    Err(_) => match Library::new("atiadlxy.dll") {
                        Ok(lib) => lib,
                        Err(e) => panic!("Unable to load ADL library: {}", e),
                    },
                },
            }
        }
    }
}

impl Adl {
    unsafe extern "C" fn ADL_Main_Memory_Alloc(size: i32) -> *mut libc::c_void {
        libc::malloc(size as usize)
    }

    /// Function to initialize the ADL interface. This function should be called first.
    ///
    /// This function initializes the ADL library. ADL initialized using ADL_Main_Control_Create
    /// will not enforce serialization of ADL API executions by multiple threads. Multiple threads
    /// will be allowed to enter to ADL at the same time. Note that ADL library is not guaranteed
    /// to be thread-safe. Client that calls ADL_Main_Control_Create have to provide its own
    /// mechanism for ADL calls serialization. It also initializes global pointers and, at the same
    /// time, calls the ADL_Main_Control_Refresh function.
    ///
    /// Supported platforms: Linux and Windows(XP, Vista and above); 32bit and 64bit
    ///
    /// Arguments:
    /// * `enumConnectedAdapters`: Specify a value of 0 to retrieve adapter information for all
    ///     adapters that have ever been present in the system. Specify a value of 1 to retrieve
    ///     adapter information only for adapters that are physically present and enabled in the
    ///     system.
    pub fn ADL_Main_Control_Create(&self, enum_connected_adapters: i32) -> AdlResult {
        unsafe {
            type ADL_MAIN_MALLOC_CALLBACK =
                Option<unsafe extern "C" fn(arg1: c_int) -> *mut c_void>;

            let func: Symbol<unsafe extern "C" fn(ADL_MAIN_MALLOC_CALLBACK, c_int) -> c_int> = self
                .lib
                .get(b"ADL_Main_Control_Create")
                .expect("Unable to load function ADL_Main_Control_Create");
            let raw_stat = func(Some(Adl::ADL_Main_Memory_Alloc), enum_connected_adapters);
            AdlStatus::toResult(raw_stat)
        }
    }

    /// Function to destroy ADL global pointers. This function should be called last.
    ///
    /// All ADL global buffers and resources are released after this function is called.
    ///
    /// Supported platforms: Linux and Windows(XP, Vista and above); 32bit and 64bit
    pub fn ADL_Main_Control_Destroy(&self) -> AdlResult {
        unsafe {
            let func: Symbol<unsafe extern "C" fn() -> c_int> = self
                .lib
                .get(b"ADL_Main_Control_Destroy")
                .expect("Unable to load function ADL_Main_Control_Destroy");
            let raw_stat = func();
            AdlStatus::toResult(raw_stat)
        }
    }

    /// Function to initialize the ADL2 interface and to obtain client's context handle.
    ///
    /// Clients can use ADL2 versions of ADL APIs to assure that there is no interference with other
    /// ADL clients that are running in the same process. Such clients have to call
    /// ADL2_Main_Control_Create first to obtain ADL_CONTEXT_HANDLE instance that has to be passed
    /// to each subsequent ADL2 call and finally destroyed using ADL2_Main_Control_Destroy.  ADL
    /// initialized using ADL2_Main_Control_Create will not enforce serialization of ADL API
    /// executions by multiple threads. Multiple threads will be allowed to enter to ADL at the same
    /// time. Note that ADL library is not guaranteed to be thread-safe. Client that calls
    /// ADL2_Main_Control_Create have to provide its own mechanism for ADL calls serialization.
    ///
    /// Arguments:
    /// * `enum_connected_adapters`: Specify a value of 0 to retrieve adapter information for all
    ///     adapters that have ever been present in the system. Specify a value of 1 to retrieve
    ///     adapter information only for adapters that are physically present and enabled in the
    ///     system.
    ///
    /// Returns:
    ///   ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and
    ///   finally destroyed using ADL2_Main_Control_Destroy.
    ///
    /// Supported platforms: Linux and Windows(XP, Vista and above); 32bit and 64bit
    pub fn ADL2_Main_Control_Create(
        &self,
        enum_connected_adapters: i32,
    ) -> AdlResultWithValue<ADL_CONTEXT_HANDLE> {
        unsafe {
            type ADL_MAIN_MALLOC_CALLBACK =
                Option<unsafe extern "C" fn(arg1: c_int) -> *mut c_void>;

            let func: Symbol<
                unsafe extern "C" fn(
                    ADL_MAIN_MALLOC_CALLBACK,
                    c_int,
                    *mut ADL_CONTEXT_HANDLE,
                ) -> c_int,
            > = self
                .lib
                .get(b"ADL2_Main_Control_Create")
                .expect("Unable to load function ADL2_Main_Control_Create");
            let mut context: Box<ADL_CONTEXT_HANDLE> = Box::new(ptr::null_mut());
            let raw_stat = func(
                Some(Adl::ADL_Main_Memory_Alloc),
                enum_connected_adapters,
                context.as_mut(),
            );
            AdlStatus::toResultWithValue(raw_stat, || *context)
        }
    }

    /// Destroy client's ADL context.
    ///
    /// Clients can use ADL2 versions of ADL APIs to assure that there is no interference with other
    /// ADL clients that are running in the same process and to assure that ADL APIs are
    /// thread-safe. Such clients have to call ADL2_Main_Control_Create first to obtain
    /// ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally
    /// destroyed using ADL2_Main_Control_Destroy.
    ///
    /// Arguments:
    /// * `context`: ADL_CONTEXT_HANDLE instance to destroy
    ///
    /// Supported platforms: Linux and Windows(XP, Vista and above); 32bit and 64bit
    pub fn ADL2_Main_Control_Destroy(&self, context: ADL_CONTEXT_HANDLE) -> AdlResult {
        unsafe {
            let func: Symbol<unsafe extern "C" fn(ADL_CONTEXT_HANDLE) -> c_int> = self
                .lib
                .get(b"ADL2_Main_Control_Destroy")
                .expect("Unable to load function ADL2_Main_Control_Destroy");
            let raw_stat = func(context);
            AdlStatus::toResult(raw_stat)
        }
    }

    /// Function to retrieve the number of OS-known adapters.
    ///
    /// This function retrieves the number of graphics adapters recognized by the OS (OS-known
    /// adapters). OS-known adapters can include adapters that are physically present in the system
    /// (logical adapters) as well as ones that no longer present in the system but are still
    /// recognized by the OS.
    ///
    /// Supported platforms: Linux and Windows(XP, Vista and above); 32bit and 64bit
    pub fn ADL_Adapter_NumberOfAdapters_Get(&self) -> AdlResultWithValue<usize> {
        unsafe {
            let func: Symbol<unsafe extern "C" fn(*mut c_int) -> c_int> = self
                .lib
                .get(b"ADL_Adapter_NumberOfAdapters_Get")
                .expect("Unable to load function ADL_Adapter_NumberOfAdapters_Get");
            let mut num: Box<i32> = Box::default();
            let raw_stat = func(&mut *num);
            AdlStatus::toResultWithValue(raw_stat, || *num.as_ref() as usize)
        }
    }

    /// Retrieves all OS-known adapter information.
    ///
    /// This function retrieves the adapter information of all OS-known adapters in the system.
    /// OS-known adapters can include adapters that are physically present in the system (logical
    /// adapters) as well as ones that are no longer present in the system but are still recognized
    /// by the OS.
    ///
    /// Supported platforms: Linux and Windows(XP, Vista and above); 32bit and 64bit
    pub fn ADL_Adapter_AdapterInfo_Get(&self) -> AdlResultWithValue<Vec<AdlAdapterInfo>> {
        let num_adapters = match self.ADL_Adapter_NumberOfAdapters_Get() {
            Ok((_, num)) => num,
            Err(s) => panic!("Unable to get number of adapters: {:?}", s),
        };

        unsafe {
            let func: Symbol<unsafe extern "C" fn(*mut AdlAdapterInfoInternal, c_int) -> c_int> =
                self.lib
                    .get(b"ADL_Adapter_AdapterInfo_Get")
                    .expect("Unable to load function ADL_Adapter_AdapterInfo_Get");
            let mut infos = vec![AdlAdapterInfoInternal::default(); num_adapters];
            let raw_stat = func(
                infos.as_mut_ptr(),
                mem::size_of_val(infos.as_slice()) as i32,
            );
            AdlStatus::toResultWithValue(raw_stat, || {
                infos.into_iter().map(AdlAdapterInfo::from).collect()
            })
        }
    }

    /// Function to determine if the adapter is active or not.
    ///
    /// The function is used to check if the adapter associated with iAdapterIndex is active. Logic
    /// is different for Windows and Linux!
    ///
    /// Parameters:
    ///   adapter_index: The ADL index handle of the desired adapter
    ///
    /// Supported Platforms: Linux and Windows(XP, Vista and above); 32bit and 64bit
    pub fn ADL_Adapter_Active_Get(&self, adapter_index: i32) -> AdlResultWithValue<bool> {
        unsafe {
            let func: Symbol<unsafe extern "C" fn(c_int, *mut c_int) -> c_int> = self
                .lib
                .get(b"ADL_Adapter_Active_Get")
                .expect("Unable to load function ADL_Adapter_Active_Get");
            let mut status = Box::new(-1i32);
            let raw_stat = func(adapter_index, status.as_mut());
            AdlStatus::toResultWithValue(raw_stat, || AdlBool::from_int(*status).unwrap().into())
        }
    }

    /// Function to retrieve the Overdrive8 current settings.
    ///
    /// This function retrieves the Overdrive8 current settings for a specified adapter.
    ///
    /// Arguments:
    /// * `context`: Client's ADL context handle ADL_CONTEXT_HANDLE obtained from  
    ///     ADL2_Main_Control_Create
    /// * `adapter_index`: The ADL index handle of the desired adapter
    ///
    /// Returns:
    /// The pointer to the ADLPMLogDataOutput structure storing the retrieved performance metrics
    /// parameters.
    ///
    /// Supported Platforms: Windows 7, 10 and above; 32bit and 64bit
    pub fn ADL2_New_QueryPMLogData_Get(
        &self,
        context: ADL_CONTEXT_HANDLE,
        adapter_index: i32,
    ) -> AdlResultWithValue<ADLPMLogDataOutput> {
        unsafe {
            let func: Symbol<
                unsafe extern "C" fn(
                    ADL_CONTEXT_HANDLE,
                    c_int,
                    *mut ADLPMLogDataOutputInternal,
                ) -> c_int,
            > = self
                .lib
                .get(b"ADL2_New_QueryPMLogData_Get")
                .expect("Unable to load function ADL2_New_QueryPMLogData_Get");
            let mut output = Box::new(ADLPMLogDataOutputInternal::default());
            let raw_stat = func(context, adapter_index, output.as_mut());
            AdlStatus::toResultWithValue(raw_stat, || ADLPMLogDataOutput::from(*output))
        }
    }
}

/// Handle to ADL client context.
///
/// ADL clients obtain context handle from initial call to \\ref ADL2_Main_Control_Create.
/// Clients have to pass the handle to each subsequent ADL call and finally destroy
/// the context with call to \\ref ADL2_Main_Control_Destroy
pub type ADL_CONTEXT_HANDLE = *mut c_void;

#[repr(i32)]
#[derive(Clone, Copy, Debug, Eq, PartialEq, IntEnum)]
pub enum AdlBool {
    True = 1,
    False = 0,
}

impl From<AdlBool> for bool {
    fn from(adl_bool: AdlBool) -> Self {
        match adl_bool {
            AdlBool::True => true,
            AdlBool::False => false,
        }
    }
}

#[repr(i32)]
#[derive(Clone, Copy, Debug, Eq, PartialEq, IntEnum)]
pub enum AdlStatus {
    /// All Ok, but need to wait
    OkWait = 4,
    /// All Ok, but need restart
    OkRestart = 3,
    /// All Ok, but need mode change
    OkModeChange = 2,
    /// All Ok, but with warning
    OkWarning = 1,
    /// ADL function completed successfully
    Ok = 0,
    /// Generic Error.  Most likely one or more of the Escape calls to the driver failed!
    Err = -1,
    /// ADL not initialized
    ErrNotInit = -2,
    /// One of the parameter passed is invalid
    ErrInvalidParam = -3,
    /// One of the parameter size is invalid
    ErrInvalidParamSize = -4,
    /// Invalid ADL index passed
    ErrInvalidAdlIdx = -5,
    /// Invalid controller index passed
    ErrInvalidControllerIdx = -6,
    /// Invalid display index passed
    ErrInvalidDisplayIdx = -7,
    /// Function not supported by the driver
    ErrNotSupported = -8,
    /// Null pointer error
    ErrNullPointer = -9,
    /// Call can't be made due to disabled adapter
    ErrDisabledAdapter = -10,
    /// Invalid callback
    ErrInvalidCallback = -11,
    /// Display resource conflict
    ErrResourceConflict = -12,
    /// Failed to update some of the values.  Can be returned by set request that include multiple
    /// values if not all values were successfully committed
    ErrSetIncomplete = -20,
    /// There's no Linux XDisplay in Linux Console environment
    ErrNoXDisplay = -21,
    /// Escape call failed because of incompatible driver found in driver store
    ErrCallToIncompatibleDriver = -22,
}

type AdlResult = Result<AdlStatus, AdlStatus>;
type AdlResultWithValue<T> = Result<(AdlStatus, T), AdlStatus>;

impl AdlStatus {
    pub fn toResult(raw_status: i32) -> AdlResult {
        match AdlStatus::from_int(raw_status) {
            Ok(s @ AdlStatus::Ok) => Ok(s),
            Ok(s @ AdlStatus::OkWait) => Ok(s),
            Ok(s @ AdlStatus::OkRestart) => Ok(s),
            Ok(s @ AdlStatus::OkWarning) => Ok(s),
            Ok(s @ AdlStatus::OkModeChange) => Ok(s),
            Ok(s) => Err(s),
            Err(e) => panic!("Unable to parse ADL status code: {}", e),
        }
    }

    pub fn toResultWithValue<T, F>(raw_status: i32, value: F) -> AdlResultWithValue<T>
    where
        F: FnOnce() -> T,
    {
        match AdlStatus::from_int(raw_status) {
            Ok(s @ AdlStatus::Ok) => Ok((s, value())),
            Ok(s @ AdlStatus::OkWait) => Ok((s, value())),
            Ok(s @ AdlStatus::OkRestart) => Ok((s, value())),
            Ok(s @ AdlStatus::OkWarning) => Ok((s, value())),
            Ok(s @ AdlStatus::OkModeChange) => Ok((s, value())),
            Ok(s) => Err(s),
            Err(e) => panic!("Unable to parse ADL status code: {}", e),
        }
    }
}

/// Structure containing information about the graphics adapter.
///
/// This structure is used to store various information about the graphics adapter.  This
/// information can be returned to the user. Alternatively, it can be used to access various
/// driver calls to set or fetch various settings upon the user's request.
#[repr(C)]
#[derive(Copy, Clone, Debug)]
struct AdlAdapterInfoInternal {
    /// Size of the structure.
    pub size: c_int,
    /// The ADL index handle. One GPU may be associated with one or two index handles
    pub adapter_index: c_int,
    /// The unique device ID associated with this adapter.
    pub udid: [c_char; 256usize],
    /// The BUS number associated with this adapter.
    pub bus_number: c_int,
    /// The driver number associated with this adapter.
    pub device_number: c_int,
    /// The function number.
    pub function_number: c_int,
    /// The vendor ID associated with this adapter.
    pub vendor_id: c_int,
    /// Adapter name.
    pub adapter_name: [c_char; 256usize],
    /// Display name. For example, \"\\\\\\\\Display0\" for Windows or \":0:0\" for Linux.
    pub display_name: [c_char; 256usize],
    /// Present or not; 1 if present and 0 if not present.  It the logical adapter is present, the
    /// display name such as \\\\\\\\.\\\\Display1 can be found from OS
    pub present: c_int,
    /// Exist or not; 1 is exist and 0 is not present.
    pub exist: c_int,
    /// Driver registry path.
    pub driver_path: [c_char; 256usize],
    /// Driver registry path Ext for.
    pub driver_path_ext: [c_char; 256usize],
    /// PNP string from Windows.
    pub pnp_string: [c_char; 256usize],
    /// It is generated from EnumDisplayDevices.
    pub os_display_index: c_int,
}

impl Default for AdlAdapterInfoInternal {
    fn default() -> Self {
        Self {
            size: -1,
            adapter_index: -1,
            udid: [0i8; 256],
            bus_number: -1,
            device_number: -1,
            function_number: -1,
            vendor_id: -1,
            adapter_name: [0i8; 256],
            display_name: [0i8; 256],
            present: -1,
            exist: -1,
            driver_path: [0i8; 256],
            driver_path_ext: [0i8; 256],
            pnp_string: [0i8; 256],
            os_display_index: -1,
        }
    }
}

/// Structure containing information about the graphics adapter.
///
/// This structure is used to store various information about the graphics adapter.  This
/// information can be returned to the user. Alternatively, it can be used to access various
/// driver calls to set or fetch various settings upon the user's request.
#[derive(Clone, Debug)]
pub struct AdlAdapterInfo {
    /// Size of the structure.
    pub size: i32,
    /// The ADL index handle. One GPU may be associated with one or two index handles
    pub adapter_index: i32,
    /// The unique device ID associated with this adapter.
    pub udid: [c_char; 256usize],
    /// The BUS number associated with this adapter.
    pub bus_number: i32,
    /// The driver number associated with this adapter.
    pub device_number: i32,
    /// The function number.
    pub function_number: i32,
    /// The vendor ID associated with this adapter.
    pub vendor_id: i32,
    /// Adapter name.
    pub adapter_name: String,
    /// Display name. For example, \"\\\\\\\\Display0\" for Windows or \":0:0\" for Linux.
    pub display_name: String,
    /// Present or not.  It the logical adapter is present, the display name such as
    /// \\\\\\\\.\\\\Display1 can be found from OS.
    pub present: bool,
    /// Exist or not.
    pub exist: bool,
    /// Driver registry path.
    pub driver_path: String,
    /// Driver registry path Ext for.
    pub driver_path_ext: String,
    /// PNP string from Windows.
    pub pnp_string: [c_char; 256usize],
    /// It is generated from EnumDisplayDevices.
    pub os_display_index: i32,
}

impl From<AdlAdapterInfoInternal> for AdlAdapterInfo {
    fn from(info: AdlAdapterInfoInternal) -> Self {
        Self {
            size: info.size,
            adapter_index: info.adapter_index,
            udid: info.udid,
            bus_number: info.bus_number,
            device_number: info.device_number,
            function_number: info.function_number,
            vendor_id: info.vendor_id,
            adapter_name: from_bytes(&info.adapter_name),
            display_name: from_bytes(&info.display_name),
            present: info.present == 1,
            exist: info.exist == 1,
            driver_path: from_bytes(&info.driver_path),
            driver_path_ext: from_bytes(&info.driver_path_ext),
            pnp_string: info.pnp_string,
            os_display_index: info.os_display_index,
        }
    }
}

#[repr(usize)]
#[derive(Clone, Copy, Debug, Eq, PartialEq, Hash, IntEnum, EnumIter)]
pub enum AdlSensorType {
    SENSOR_MAXTYPES = 0,
    PMLOG_CLK_GFXCLK = 1,
    PMLOG_CLK_MEMCLK = 2,
    PMLOG_CLK_SOCCLK = 3,
    PMLOG_CLK_UVDCLK1 = 4,
    PMLOG_CLK_UVDCLK2 = 5,
    PMLOG_CLK_VCECLK = 6,
    PMLOG_CLK_VCNCLK = 7,
    PMLOG_TEMPERATURE_EDGE = 8,
    PMLOG_TEMPERATURE_MEM = 9,
    PMLOG_TEMPERATURE_VRVDDC = 10,
    PMLOG_TEMPERATURE_VRMVDD = 11,
    PMLOG_TEMPERATURE_LIQUID = 12,
    PMLOG_TEMPERATURE_PLX = 13,
    PMLOG_FAN_RPM = 14,
    PMLOG_FAN_PERCENTAGE = 15,
    PMLOG_SOC_VOLTAGE = 16,
    PMLOG_SOC_POWER = 17,
    PMLOG_SOC_CURRENT = 18,
    PMLOG_INFO_ACTIVITY_GFX = 19,
    PMLOG_INFO_ACTIVITY_MEM = 20,
    PMLOG_GFX_VOLTAGE = 21,
    PMLOG_MEM_VOLTAGE = 22,
    PMLOG_ASIC_POWER = 23,
    PMLOG_TEMPERATURE_VRSOC = 24,
    PMLOG_TEMPERATURE_VRMVDD0 = 25,
    PMLOG_TEMPERATURE_VRMVDD1 = 26,
    PMLOG_TEMPERATURE_HOTSPOT = 27,
    PMLOG_TEMPERATURE_GFX = 28,
    PMLOG_TEMPERATURE_SOC = 29,
    PMLOG_GFX_POWER = 30,
    PMLOG_GFX_CURRENT = 31,
    PMLOG_TEMPERATURE_CPU = 32,
    PMLOG_CPU_POWER = 33,
    PMLOG_CLK_CPUCLK = 34,
    PMLOG_THROTTLER_STATUS = 35,
    PMLOG_CLK_VCN1CLK1 = 36,
    PMLOG_CLK_VCN1CLK2 = 37,
    PMLOG_SMART_POWERSHIFT_CPU = 38,
    PMLOG_SMART_POWERSHIFT_DGPU = 39,
    PMLOG_BUS_SPEED = 40,
    PMLOG_BUS_LANES = 41,
    PMLOG_TEMPERATURE_LIQUID0 = 42,
    PMLOG_TEMPERATURE_LIQUID1 = 43,
    PMLOG_CLK_FCLK = 44,
    PMLOG_THROTTLER_STATUS_CPU = 45,
    PMLOG_MAX_SENSORS_REAL = 46,
}

#[repr(C)]
#[derive(Copy, Clone, Debug)]
struct ADLSingleSensorDataInternal {
    supported: AdlBool,
    value: c_int,
}

impl Default for ADLSingleSensorDataInternal {
    fn default() -> Self {
        Self {
            supported: AdlBool::False,
            value: -1,
        }
    }
}

#[derive(Copy, Clone, Debug)]
pub struct ADLSingleSensorData {
    pub supported: bool,
    pub value: i32,
}

impl From<ADLSingleSensorDataInternal> for ADLSingleSensorData {
    fn from(data: ADLSingleSensorDataInternal) -> Self {
        Self {
            supported: bool::from(data.supported),
            value: data.value,
        }
    }
}

#[repr(C)]
#[derive(Clone, Debug)]
struct ADLPMLogDataOutputInternal {
    size: c_int,
    sensors: [ADLSingleSensorDataInternal; 256],
}

impl Default for ADLPMLogDataOutputInternal {
    fn default() -> Self {
        Self {
            size: 0,
            sensors: [ADLSingleSensorDataInternal::default(); 256],
        }
    }
}

pub type ADLPMLogDataOutput = HashMap<AdlSensorType, ADLSingleSensorData>;

impl From<ADLPMLogDataOutputInternal> for ADLPMLogDataOutput {
    fn from(output: ADLPMLogDataOutputInternal) -> Self {
        let mut map = HashMap::default();
        for sensor_type in AdlSensorType::iter() {
            if sensor_type.int_value() <= output.size as usize {
                map.insert(
                    sensor_type,
                    ADLSingleSensorData::from(output.sensors[sensor_type.int_value()]),
                );
            }
        }
        map
    }
}

fn from_bytes(bytes: &[i8]) -> String {
    String::from_utf8(
        bytes
            .iter()
            .filter_map(|&c| if c == 0 { None } else { Some(c as u8) })
            .collect(),
    )
    .unwrap()
}
