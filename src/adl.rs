#![allow(non_upper_case_globals)]
#![allow(non_camel_case_types)]
#![allow(non_snake_case)]

use int_enum::IntEnum;
use libloading::{Library, Symbol};
use os::raw::{c_int, c_void};
use std::os;

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

    pub fn ADL_Main_Control_Create(&self, iEnumConnectedAdapters: i32) -> AdlResult {
        unsafe {
            type ADL_MAIN_MALLOC_CALLBACK =
                Option<unsafe extern "C" fn(arg1: c_int) -> *mut c_void>;

            let func: Symbol<unsafe extern "C" fn(ADL_MAIN_MALLOC_CALLBACK, i32) -> i32> = self
                .lib
                .get(b"ADL_Main_Control_Create")
                .expect("Unable to load function ADL_Main_Control_Create");
            let raw_stat = func(Some(Adl::ADL_Main_Memory_Alloc), iEnumConnectedAdapters);
            AdlStatus::toResult(raw_stat)
        }
    }

    pub fn ADL_Main_Control_Destroy(&self) -> AdlResult {
        unsafe {
            let func: Symbol<unsafe extern "C" fn() -> i32> = self
                .lib
                .get(b"ADL_Main_Control_Destroy")
                .expect("Unable to load function ADL_Main_Control_Destroy");
            let raw_stat = func();
            AdlStatus::toResult(raw_stat)
        }
    }

    pub fn ADL_Adapter_NumberOfAdapters_Get(&self) -> (AdlResult, i32) {
        unsafe {
            let func: Symbol<unsafe extern "C" fn(*mut i32) -> i32> = self
                .lib
                .get(b"ADL_Adapter_NumberOfAdapters_Get")
                .expect("Unable to load function ADL_Adapter_NumberOfAdapters_Get");
            let mut num: Box<i32> = Box::default();
            let raw_stat = func(&mut *num);
            match AdlStatus::toResult(raw_stat) {
                s @ Ok(_) => (s, *num.as_ref()),
                s @ Err(_) => (s, -1),
            }
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
}
