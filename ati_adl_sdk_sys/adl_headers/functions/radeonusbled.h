#ifndef ADL_HEADER_RADEONUSBLED_H_
#define ADL_HEADER_RADEONUSBLED_H_

#include <errno.h>
#include "../adl_defines.h"
#include "../adl_sdk.h"
#include "../adl_structures.h"

// HACK: we don't have docs for all structs used in the API, so make unknown ones void for now
#define ADL_DL_DISPLAYMODEINFO void
#define ADL_DL_DISPLAY_MODE void
#define ADLVulkanAppInfo void
#define BINFILE void
#define BOOL void
#define CUSTOMISATIONS void
#define DATATYPES void
#define LPXScreenInfo void *
#define PRIVACYTYPES void

/// Function to save programmed LED configuration onto LED flash to persist on reboot and power down. 
/// 
/// This interface allows ADL user to query the number of LED devices present. 
/// Supported Platforms:
///   Windows 7, 10 and above; 32bit and 64bit 
/// 
/// Parameters
///   [in] context       Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in] iAdapterIndex The ADL index handle of the desired adapter 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes
int ADL2_Adapter_Radeon_Usb_Led_Flash_Save ( ADL_CONTEXT_HANDLE context,
                                             int                iAdapterIndex
                                           );


/// Function to query list of supported LED pattern control. 
/// 
/// This interface allows ADL user to query list of LED patterns on the LED controller. Output can be used for set functionality 
/// Supported Platforms:
///   Windows 7, 10 and above; 32bit and 64bit 
/// 
/// Parameters
///   [in] context       Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in] iAdapterIndex The ADL index handle of the desired adapter 
///   [in]
int ADL2_Adapter_Radeon_USB_LED_Pattern_Supported_Controls_Get ( ADL_CONTEXT_HANDLE              context,
                                                                 int                             iAdapterIndex,
                                                                 ADL_RADEON_USB_LED_BAR_CONTROLS control,
                                                                 RadeonLEDBARSupportedConfig *   ConfigSupport
                                                               );


/// 
int ADL2_Adapter_Radeon_USB_LED_Support_Get ( ADL_CONTEXT_HANDLE context,
                                              int                iAdapterIndex,
                                              bool *             bLEDSupported
                                            );


/// Function to query supported LED controls. 
/// 
/// This interface allows ADL user to a bitmask of supported LED patterns on the LED controllers, including OFF and custom pattern, Rainbow, etc... 
/// Supported Platforms:
///   Windows 7, 10 and above; 32bit and 64bit 
/// 
/// Parameters
///   [in]  context        Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in]  iAdapterIndex  The ADL index handle of the desired adapter 
///   [out] ControlSupport returns a bitmask of all supported LED patterns. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes
int ADL2_Adapter_Radeon_USB_LED_Supported_Controls_Get ( ADL_CONTEXT_HANDLE             context,
                                                         int                            iAdapterIndex,
                                                         RadeonLEDBARSupportedControl * ControlSupport
                                                       );


#endif /* ADL_HEADER_RADEONUSBLED_H_ */
