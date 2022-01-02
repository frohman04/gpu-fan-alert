#ifndef ADL_HEADER_GRAPHICS_H_
#define ADL_HEADER_GRAPHICS_H_

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

/// Function to retrieve Graphic Core Info. 
/// 
/// This function implements a call to retrieve Graphic Core Info. 
/// Supported Platforms:
///   Windows Vista and Windows 7; 32bit and 64bit 
/// 
/// Parameters
///   [in]  context          Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in]  iAdapterIndex    The ADL index handle of the desired adapter. 
///   [out] pGraphicCoreInfo The pointer to Graphic Core Info 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK, or an ADL error code otherwise. Result Codes
int ADL2_Adapter_Graphic_Core_Info_Get ( ADL_CONTEXT_HANDLE   context,
                                         int                  iAdapterIndex,
                                         ADLGraphicCoreInfo * pGraphicCoreInfo
                                       );


/// On the Windows 10 system with multiple GPUs it is possible to have different driver versions installed on for each GPU. Each GPUs driver binaries will be located in dedicated disk location inside systems driver store. This function can be used to find location of the driver for given GPU designated by its adapter index. 
/// Supported Platforms:
///   Windows 10; 32bit and 64bit 
/// 
/// Parameters
///   [in]  context       Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in]  iAdapterIndex The ADL index handle of the desired adapter. 
///   [in]  iSize         size of lpDriverPath output buffer in the single byte characters. 
///   [out] iSize         size of lpDriverPath output buffer in the single byte characters. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK, or an ADL error code otherwise. Result Codes
int ADL2_Driver_Path_Get ( ADL_CONTEXT_HANDLE context,
                           int                iAdapterIndex,
                           int                iSize,
                           char *             lpDriverPath
                         );


/// This function determines whether the current graphics platform is detachable graphics one or not. 
/// Supported Platforms:
///   Windows 7, 10 and above; 32bit and 64bit 
/// 
/// Parameters
///   [in]  context  Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [out] lpStatus The pointer to the retrieved graphics platform for the system. 
///  lpStatus will be either 1 (for detachable graphics platforms) or 0 (for non-detachable graphics platforms) 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes 
/// 
/// Remarks
///   Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process. Such clients have to call ADL2_Main_Control_Create first to obtain ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using ADL2_Main_Control_Destroy.
int ADL2_Graphics_IsDetachableGraphicsPlatform_Get ( ADL_CONTEXT_HANDLE context,
                                                     int *              lpStatus
                                                   );


/// This function determines what is the Family ID of a GPU and based on that, find if it is Gfx9 and above GPU or not. 
/// Supported Platforms:
///   Windows 7, 10 and above; 32bit and 64bit 
/// 
/// Parameters
///   [in] context Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
/// 
/// Returns
///   TRUE: if Family ID is Gfx9 or above; FALSE: otherwise.
int ADL2_Graphics_IsGfx9AndAbove ( );


/// This function gets mantle versions. 
/// Supported Platforms:
///   Windows 7, 10 and above; 32bit and 64bit 
/// 
/// Parameters
///   [in] context       : Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in] mantleAppInfo : The ADLMantleAppInfo structure.
int ADL2_Graphics_MantleVersion_Get ( ADL_CONTEXT_HANDLE context,
                                      ADLMantleAppInfo * mantleAppInfo
                                    );


/// Function to retrieve the type of graphics platform the system is currently running. 
/// 
/// This function determines whether the current graphics platform is a mobile, desktop. 
/// Supported Platforms:
///   Windows 7, 10 and above; 32bit and 64bit 
/// 
/// Parameters
///   [in]  context    Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [out] lpPlatForm The pointer to the retrieved graphics platform for the system. 
///  lpPlatForm will be either GRAPHICS_PLATFORM_DESKTOP (for desktop platforms) or GRAPHICS_PLATFORM_MOBILE (for mobile platforms) 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes 
/// 
/// Remarks
///   Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call ADL2_Main_Control_Create first to obtain ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using ADL2_Main_Control_Destroy.
int ADL2_Graphics_Platform_Get ( ADL_CONTEXT_HANDLE context,
                                 int *              lpPlatForm
                               );


/// 
int ADL2_Graphics_Versions_Get ( ADL_CONTEXT_HANDLE context,
                                 ADLVersionsInfo *  lpVersionsInfo
                               );


/// Function to retrieve s version information. 
/// 
/// This function retrieves software version information and a web link to an XML file with information about the latest web-posted Catalyst drivers 
/// Supported Platforms:
///   Windows 7, 10 and above; 32bit and 64bit 
/// 
/// Parameters
///   [in]  context        Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [out] lpVersionsInfo The pointer to ADLVersionsInfoX2 structure with the retrieved version information. 
/// 
/// Returns
///   The function returns ADL_OK or ADL_OK_WARNING (if any of the version strings could not be retrieved from the system, for example "Catalyst Version"). If ADL is not initialized properly the function will return ADL_ERR_DISABLED_ADAPTER 
/// 
/// Remarks
///   Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call ADL2_Main_Control_Create first to obtain ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using ADL2_Main_Control_Destroy.
int ADL2_Graphics_VersionsX2_Get ( ADL_CONTEXT_HANDLE  context,
                                   ADLVersionsInfoX2 * lpVersionsInfo
                                 );


/// This function retrieves software version information and a web link to an XML file with information about the latest web-posted Catalyst drivers 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in]  context        Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in]  iAdapterIndex  Adapter index that belongs to the GPU. 
///   [out] lpVersionsInfo The pointer to ADLVersionsInfo2 structure with the retrieved version information. 
/// 
/// Returns
///   The function returns ADL_OK or ADL_OK_WARNING (if any of the version strings could not be retrieved from the system, for example "Catalyst Version"). If ADL is not initialized properly the function will return ADL_ERR_DISABLED_ADAPTER 
/// 
/// Remarks
///   On hybrid system with multiple GPUs (A+A) each GPU has different driver version installed. This call will allow the application to discover driver version for each GPU.
int ADL2_Graphics_VersionsX3_Get ( ADL_CONTEXT_HANDLE  context,
                                   int                 iAdapterIndex,
                                   ADLVersionsInfoX2 * lpVersionsInfo
                                 );


/// Function to get Vulkan versions. 
/// 
/// This function gets Vulkan versions. No longer used by RSX, but kept to preserve third party vendor support. 
/// Supported Platforms:
///   Windows 7, 10 and above; 32bit and 64bit 
/// 
/// Parameters
///   [in] context       : Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in] vulkanAppInfo : The ADLAppVersionInfo structure.
int ADL2_Graphics_VulkanVersion_Get ( ADL_CONTEXT_HANDLE context,
                                      ADLVulkanAppInfo * vulkanAppInfo
                                    );


/// Function to get Vulkan versions. 
/// 
/// SWDEV-261137 - This X2 function gets the Vulkan version of the currently connected display devices instead of all previously connected display devices. This X2 version is used by RSX currently, however the original function is kept to preserve third party vendor support. 
/// Supported Platforms:
///   Windows 7, 10 and above; 32bit and 64bit 
/// 
/// Parameters
///   [in] context       : Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in] vulkanAppInfo : The ADLAppVersionInfo structure.
int ADL2_Graphics_VulkanVersionX2_Get ( ADL_CONTEXT_HANDLE context,
                                        ADLVulkanAppInfo * vulkanAppInfo
                                      );


/// Function to get Vulkan versions of different GPUs. 
/// 
/// Side-by-side allows system to install 2 different drivers at the same time. This function will get the Vulkan version of the GPU passed in via adapter index. 
/// Supported Platforms:
///   Windows 7, 10 and above; 32bit and 64bit 
/// 
/// Parameters
///   [in] context       : Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in] vulkanAppInfo : The ADLAppVersionInfo structure. 
///   [in] iAdapterIndex : The adapter index of the GPU
int ADL2_Graphics_VulkanVersionX3_Get ( ADL_CONTEXT_HANDLE context,
                                        ADLVulkanAppInfo * vulkanAppInfo,
                                        int                iAdapterIndex
                                      );


/// This function retrieves SmartDC capabilities information from Driver. 
/// Supported Platforms:
///   Windows 10; 32bit and 64bit 
/// 
/// Parameters
///   [in]  context     Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [out] lpSupported The int pointer to whether SmartDC is supported on current system. If SmartDC is supported, the value is 1, otherwise it is 0. 
///   [out] lpDefault   The int pointer to whether SmartDC is enable or disabled by default. If SmartDC is by default enabled, the value is 1, otherwise it is 0. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes
int ADL2_SmartDC_Caps ( ADL_CONTEXT_HANDLE context,
                        int *              lpSupported,
                        int *              lpDefault
                      );


/// This function retrieves SmartDC current status information from Driver. 
/// Supported Platforms:
///   Windows 10; 32bit and 64bit 
/// 
/// Parameters
///   [in]  context        Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [out] lpSmartDCState The pointer to the integer of SmartDC current state flag. If SmartDC currently is enabled , the value is 1, otherwise it is 0. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes
int ADL2_SmartDC_Status_Get ( ADL_CONTEXT_HANDLE context,
                              int *              lpSmartDCState
                            );


/// This function enable/disable SmartDC from Driver. 
/// Supported Platforms:
///   Windows 10; 32bit and 64bit 
/// 
/// Parameters
///   [in]  context        Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in]  enable         The integer of SmartDC state to be set to driver. 1: Reuqest to enable SmartDC; 0: Request to disable SmartDC. 
///   [out] lpSmartDCState The pointer to the integer of SmartDC setted state flag. If SmartDC is enabled , the value is 1, otherwise it is 0. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes
int ADL2_SmartDC_Status_Set ( ADL_CONTEXT_HANDLE context,
                              int                enable,
                              int *              lpSmartDCState
                            );


/// Function to retrieve the type of graphics platform the system is currently running. 
/// 
/// This function determines whether the current graphics platform is a mobile, desktop. 
/// Supported Platforms:
///   Windows 7, 10 and above; 32bit and 64bit 
/// 
/// Parameters
///   [out] lpPlatForm The pointer to the retrieved graphics platform for the system. 
///  lpPlatForm will be either GRAPHICS_PLATFORM_DESKTOP (for desktop platforms) or GRAPHICS_PLATFORM_MOBILE (for mobile platforms) 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes
int ADL_Graphics_Platform_Get ( );


/// Function to retrieve version information. 
/// 
/// This function retrieves software version information and a web link to an XML file with information about the latest web-posted Catalyst drivers 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [out] lpVersionsInfo The pointer to ADLVersionsInfo structure with the retrieved version information. 
/// 
/// Returns
///   The function returns ADL_OK or ADL_OK_WARNING (if any of the version strings could not be retrieved from the system, for example "Catalyst Version"). If ADL is not initialized properly the function will return ADL_ERR_DISABLED_ADAPTER
int ADL_Graphics_Versions_Get ( );


#endif /* ADL_HEADER_GRAPHICS_H_ */
