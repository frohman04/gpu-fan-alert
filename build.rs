#[cfg(target_os = "windows")]
use winres::WindowsResource;

#[cfg(target_os = "windows")]
fn main() {
    let mut res = WindowsResource::new();
    set_execution_level(&mut res);
    res.set_icon("icon-blue.ico");
    res.compile().unwrap();
}

#[cfg(test)]
fn set_execution_level(red: &mut WindowsResource) {
    res.set_manifest(
        r#"
<assembly xmlns="urn:schemas-microsoft-com:asm.v1" manifestVersion="1.0">
<trustInfo xmlns="urn:schemas-microsoft-com:asm.v3">
    <security>
        <requestedPrivileges>
            <requestedExecutionLevel level="requireAdministrator" uiAccess="false" />
        </requestedPrivileges>
    </security>
</trustInfo>
</assembly>
"#,
    );
}

#[cfg(not(test))]
fn set_execution_level(_red: &mut WindowsResource) {}

#[cfg(not(target_os = "windows"))]
fn main() {}
