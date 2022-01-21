#[macro_use]
extern crate int_enum;
extern crate libc;
extern crate libloading;

mod adl;

use adl::Adl;

fn main() {
    let adl = Adl::default();
    adl.ADL_Main_Control_Create(0)
        .expect("Unable to create ADL");

    let num_adapters = match adl.ADL_Adapter_NumberOfAdapters_Get() {
        (Ok(_), num) => num,
        (Err(s), _) => panic!("Unable to get number of adapters: {:?}", s),
    };
    println!("Found {} adapters", num_adapters);

    adl.ADL_Main_Control_Destroy()
        .expect("Unable to destroy ADL");
}
