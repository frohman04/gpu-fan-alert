#![allow(non_upper_case_globals)]
#![allow(non_camel_case_types)]
#![allow(non_snake_case)]

use int_enum::IntEnum;
use libloading::{Library, Symbol};
use std::mem;
use std::os::raw::{c_char, c_int, c_void};

pub struct Adl {
    lib: Library,
}

impl Default for Adl {
    fn default() -> Self {
        unsafe {
            Adl {
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
    pub fn ADL_Main_Control_Create(&self, enumConnectedAdapters: i32) -> AdlResult {
        unsafe {
            type ADL_MAIN_MALLOC_CALLBACK =
                Option<unsafe extern "C" fn(arg1: c_int) -> *mut c_void>;

            let func: Symbol<unsafe extern "C" fn(ADL_MAIN_MALLOC_CALLBACK, c_int) -> c_int> = self
                .lib
                .get(b"ADL_Main_Control_Create")
                .expect("Unable to load function ADL_Main_Control_Create");
            let raw_stat = func(Some(Adl::ADL_Main_Memory_Alloc), enumConnectedAdapters);
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
        AdlAdapterInfoInternal {
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
        AdlAdapterInfo {
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

fn from_bytes(bytes: &[i8]) -> String {
    String::from_utf8(
        bytes
            .iter()
            .filter_map(|&c| if c == 0 { None } else { Some(c as u8) })
            .collect(),
    )
    .unwrap()
}
