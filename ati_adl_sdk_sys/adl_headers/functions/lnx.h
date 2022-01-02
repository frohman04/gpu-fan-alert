#ifndef ADL_HEADER_LNX_H_
#define ADL_HEADER_LNX_H_

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

/// Function to get the memory configuration of an adapter. 
/// 
/// This function retrieves the memory configuration of a specified adapter.
/// 
/// 
/// Supported Platforms:
///   Linux; 32bit and 64bit 
/// 
/// Parameters
///   [in]  context            Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in]  iAdapterIndex      The ADL index handle of the desired adapter. 
///   [in]  iScreenWidth       The pixel width of the X screen associated with the adapter. 
///   [in]  iScreenHeight      The pixel height of the X screen associated with the adapter. 
///   [in]  displayFeatureMask The valid define_adl_visiblememoryfeatures features 
///   [in]  numDisplays        Number of displays associated with the XScreen. 
///   [in]  displayFeatureList List of display features associated with each display found in the XScreen. Number of entries is numDisplays. 
///   [in]  iNumMemTypes       Size of lppMemRequired List 
///   [out] lppMemRequired     List of visible memory size required in bytes of specified type 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes 
/// 
/// Remarks
///   This API uses the memory allocation callback function provided by the user. If this API is called in Windows the return value is always ADL_ERR_NOT_SUPPORTED
int ADL2_Adapter_ConfigMemory_Get ( ADL_CONTEXT_HANDLE         context,
                                    int                        iAdapterIndex,
                                    int                        iScreenWidth,
                                    int                        iScreenHeight,
                                    int                        displayFeatureMask,
                                    int                        numDisplays,
                                    ADLMemoryDisplayFeatures * displayFeatureList,
                                    int *                      iNumMemTypes,
                                    ADLMemoryRequired **       lppMemRequired
                                  );


/// Function to retrieve memory information from the adapter. 
/// 
/// This function retrieves the memory information for a specified graphics adapter. 
/// Supported Platforms:
///   Linux; 32bit and 64bit 
/// 
/// Parameters
///   [in]  context       Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in]  iAdapterIndex The ADL index handle of the desired adapter. 
///   [out] lpMemoryInfo  The pointer to the structure storing the retrieved memory information. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes 
/// 
/// Remarks
///   Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call ADL2_Main_Control_Create first to obtain ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using ADL2_Main_Control_Destroy.
int ADL2_Adapter_MemoryInfo_Get ( ADL_CONTEXT_HANDLE context,
                                  int                iAdapterIndex,
                                  ADLMemoryInfo *    lpMemoryInfo
                                );


/// Functions to retreive Tear Free setting capabilities of the system. 
/// 
/// This function determines whether the current system is capable of applying the tear free desktop settings.
/// 
/// Tear free desktop reduces tearing in everything shown on the screen except full screen OGL applications. It double buffers the graphics adapter output ensuring that the image being drawn is not changed while a display is updating.
/// Supported Platforms:
///   Linux; 32bit and 64bit 
/// 
/// Parameters
///   [in]  context       Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in]  iAdapterIndex Ignored. May be used in the future. 
///   [out] lpTFCap       Is either ADL_TRUE or ADL_FALSE to represent if the system is capable of tear free setting or not. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes
int ADL2_Adapter_Tear_Free_Cap ( ADL_CONTEXT_HANDLE context,
                                 int                iAdapterIndex,
                                 int *              lpTFCap
                               );


/// Get the requested tear free desktop setting and current status. 
/// 
/// Gets the requested setting and current status of all the GPUs on the system.
/// 
/// Tear free desktop reduces tearing in everything shown on the screen except full screen OGL applications. It double buffers the graphics adapter output ensuring that the image being drawn is not changed while a display is updating.
/// Supported Platforms:
///   Linux; 32bit and 64bit 
/// 
/// Parameters
///   [in]  context    Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in]  iAdapter   Ignored. May be used in the future. 
///   [out] pDefault   The default requested value or NULL. 
///   [out] pRequested The requested tear free state. ADL_TRUE if it is requested on or ADL_FALSE if it requested off. 
///   [out] pStatus    The current status of tear free Define_adapter_tear_free_status 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes 
/// 
/// Remarks
///   Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call ADL2_Main_Control_Create first to obtain ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using ADL2_Main_Control_Destroy.
int ADL2_Adapter_Tear_Free_Get ( ADL_CONTEXT_HANDLE context,
                                 int                iAdapter,
                                 int *              pDefault,
                                 int *              pRequested,
                                 int *              pStatus
                               );


/// Set the requested tear free desktop setting. 
/// 
/// The tear free desktop setting is applied to all GPUs on the system.
/// 
/// Tear free desktop reduces tearing in everything shown on the screen except full screen OGL applications. It double buffers the graphics adapter output ensuring that the image being drawn is not changed while the display is updating.
/// Supported Platforms:
///   Linux; 32bit and 64bit 
/// 
/// Parameters
///   [in]  context    Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in]  iAdapter   Ignored. May be used in the future. 
///   [in]  iRequested The new requested tear free state. ADL_TRUE to request it on and ADL_FALSE to request it off. 
///   [out] pStatus    The current status of tear free Define_adapter_tear_free_status 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes 
/// 
/// Remarks
///   Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call ADL2_Main_Control_Create first to obtain ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using ADL2_Main_Control_Destroy.
int ADL2_Adapter_Tear_Free_Set ( ADL_CONTEXT_HANDLE context,
                                 int                iAdapter,
                                 int                iRequested,
                                 int *              pStatus
                               );


/// Function to retrieve all X Screen information for all OS-known adapters. 
/// 
/// This function retrieves the X Screen information of all OS-known adapters on a Linux system. OS-known adapters can include adapters that currently exist in the system (logical adapters) 
/// 
///  as well as ones that no longer exist in the system but are still recognized by the OS. 
/// Supported Platforms:
///   Linux; 32bit and 64bit 
/// 
/// Parameters
///   [in]  context       Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in]  iInputSize    The size of lpInfo buffer. 
///   [out] lpXScreenInfo The pointer to the buffer storing the retrieved X Screen information. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes 
/// 
/// 
/// Remarks
///   Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call ADL2_Main_Control_Create first to obtain ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using ADL2_Main_Control_Destroy.
int ADL2_Adapter_XScreenInfo_Get ( ADL_CONTEXT_HANDLE context,
                                   LPXScreenInfo      lpXScreenInfo,
                                   int                iInputSize
                                 );


/// Function to get the Desktop Configuration. 
/// 
/// This function retreives current the desktop configuration information. 
/// Supported Platforms:
///   Linux; 32bit and 64bit 
/// 
/// Parameters
///   [in]  context         Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in]  iAdapterIndex   The ADL index handle of the desired adapter. 
///   [out] lpDesktopConfig The pointer to the retrieved desktop configuration information.
/// Desktop Configuration Flags 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes 
/// 
/// Remarks
///   Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call ADL2_Main_Control_Create first to obtain ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using ADL2_Main_Control_Destroy. 
/// Deprecated:
///   This API has been deprecated because it was only used for RandR 1.1 (Red Hat 5.x) distributions which is now not supported.
int ADL2_DesktopConfig_Get ( ADL_CONTEXT_HANDLE context,
                             int                iAdapterIndex,
                             int *              lpDesktopConfig
                           );


/// Function to set the Desktop Configuration. 
/// 
/// This function sets the current desktop configuration information. 
/// Supported Platforms:
///   Linux; 32bit and 64bit 
/// 
/// Parameters
///   [in] context        Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in] iAdapterIndex  The ADL index handle of the desired adapter. 
///   [in] iDesktopConfig The desired Desktop Configuration information.
/// Desktop Configuration Flags 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes 
/// 
/// Remarks
///   Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call ADL2_Main_Control_Create first to obtain ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using ADL2_Main_Control_Destroy. 
/// Deprecated:
///   This API has been deprecated because it was only used for RandR 1.1 (Red Hat 5.x) distributions which is now not supported.
int ADL2_DesktopConfig_Set ( ADL_CONTEXT_HANDLE context,
                             int                iAdapterIndex,
                             int                iDesktopConfig
                           );


/// Function to set the desktop configuration. 
/// 
/// This function sets the desktop configuration. 
/// Supported Platforms:
///   Linux; 32bit and 64bit 
/// 
/// Parameters
///   [in] context                 Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in] iAdapterIndex           The ADL index handle of the desired adapter. 
///   [in] iDisplayIndex           The desired display index. 
///   [in] iDisplayControllerIndex The controller index. A field from ADLDisplayInfo structure 
///   [in] iShow                   The instruction to show the display number. Enter 0 to show and 1 to hide. 
///   [in] iDisplayNum             The number to display on screen. 
///   [in] iPosX                   The X position on screen to display index in % of screen. 
///   [in] iPosY                   The Y position on screen to display index in % of screen. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes 
/// 
/// Remarks
///   Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call ADL2_Main_Control_Create first to obtain ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using ADL2_Main_Control_Destroy.
int ADL2_Display_IdentifyDisplay ( ADL_CONTEXT_HANDLE context,
                                   int                iAdapterIndex,
                                   int                iDisplayIndex,
                                   int                iDisplayControllerIndex,
                                   int                iShow,
                                   int                iDisplayNum,
                                   int                iPosX,
                                   int                iPosY
                                 );


/// Function to get the current value of gamma for a LUT (controller). 
/// 
/// This function retrieves the current gamma value of the specified display index. Note: This replaces ADL_Controller_Color_Get 
/// Supported Platforms:
///   Linux; 32bit and 64bit 
/// 
/// Parameters
///   [in]  context        Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in]  iAdapterIndex  The ADL index handle of the desired adapter. 
///   [in]  iDisplayIndex  The desired display index. 
///   [out] lpGammaCurrent The pointer to the retrieved current gamma information structure. 
///   [out] lpGammaDefault The pointer to the retrieved default gamma information structure. 
///   [out] lpGammaMin     The pointer to the retrieved minimum gamma information structure. 
///   [out] lpGammaMax     The pointer to the retrieved maximum gamma information structure. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes 
/// 
/// Remarks
///   Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call ADL2_Main_Control_Create first to obtain ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using ADL2_Main_Control_Destroy.
int ADL2_Display_LUTColor_Get ( ADL_CONTEXT_HANDLE context,
                                int                iAdapterIndex,
                                int                iDisplayIndex,
                                ADLGamma *         lpGammaCurrent,
                                ADLGamma *         lpGammaDefault,
                                ADLGamma *         lpGammaMin,
                                ADLGamma *         lpGammaMax
                              );


/// Function to set the current gamma value for a LUT (controller). 
/// 
/// This function sets the gamma value of a specified display index (controller) Note: This replaces ADL_Controller_Color_Set 
/// Supported Platforms:
///   Linux; 32bit and 64bit 
/// 
/// Parameters
///   [in] context       Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in] iAdapterIndex The ADL index handle of the desired adapter. 
///   [in] iDisplayIndex The desired display index. 
///   [in] adlGamma      The Gamma information structure. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes 
/// 
/// Remarks
///   Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call ADL2_Main_Control_Create first to obtain ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using ADL2_Main_Control_Destroy.
int ADL2_Display_LUTColor_Set ( ADL_CONTEXT_HANDLE context,
                                int                iAdapterIndex,
                                int                iDisplayIndex,
                                ADLGamma           adlGamma
                              );


/// Function to retrieve the name of the Xrandr display. 
/// 
/// This function retrieves the Xrandr display name based on a specified adapter and display. 
/// Supported Platforms:
///   Linux; 32bit and 64bit 
/// 
/// Parameters
///   [in]  context             Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in]  iAdapterIndex       The ADL index handle of the desired adapter. 
///   [in]  iDisplayIndex       The ADL index handle of the desired display. 
///   [out] lpXrandrDisplayName The pointer to the buffer storing the retrieved Xrandr display name. 
///   [in]  iBuffSize           The size of the lpXrandrDisplayName buffer. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes 
/// 
/// Remarks
///   Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call ADL2_Main_Control_Create first to obtain ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using ADL2_Main_Control_Destroy.
int ADL2_Display_XrandrDisplayName_Get ( ADL_CONTEXT_HANDLE context,
                                         int                iAdapterIndex,
                                         int                iDisplayIndex,
                                         char *             lpXrandrDisplayName,
                                         int                iBuffSize
                                       );


/// Function to dynamically enable displays on a GPU. 
/// 
/// This function dynamically enables displays on a GPU. Supported on randr 1.1 distributions. This function is not supported on randr 1.2 and newer distributions. 
/// Supported Platforms:
///   Linux; 32bit and 64bit 
/// 
/// Parameters
///   [in] context            Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in] iAdapterIndex      The ADL index handle of the desired adapter. 
///   [in] lpDisplayIndexList The pointer to the list of display indexes that will be enabled. All others will be disabled. 
///   [in] iDisplayListSize   The size of the list. 
///   [in] bPersistOnly       Non-zero value means that settings will not take effect until system restart 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes 
/// 
/// Remarks
///   Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call ADL2_Main_Control_Create first to obtain ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using ADL2_Main_Control_Destroy. 
/// Deprecated:
///   This API has been deprecated because it was only used for RandR 1.1 (Red Hat 5.x) distributions which is now not supported.
int ADL2_DisplayEnable_Set ( ADL_CONTEXT_HANDLE context,
                             int                iAdapterIndex,
                             int *              lpDisplayIndexList,
                             int                iDisplayListSize,
                             int                bPersistOnly
                           );


/// Function to retrieve the number of enabled displays. 
/// 
/// This function retrieves the current number of enabled displays. 
/// Supported Platforms:
///   Linux; 32bit and 64bit 
/// 
/// Parameters
///   [in]  context            Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in]  iAdapterIndex      The ADL index handle of the desired adapter. 
///   [out] lpNumberOfDisplays The pointer to the number of enabled displays. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes 
/// 
/// Remarks
///   Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call ADL2_Main_Control_Create first to obtain ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using ADL2_Main_Control_Destroy. 
/// Deprecated:
///   This API has been deprecated because it was only used for RandR 1.1 (Red Hat 5.x) distributions which is now not supported.
int ADL2_NumberOfDisplayEnable_Get ( ADL_CONTEXT_HANDLE context,
                                     int                iAdapterIndex,
                                     int *              lpNumberOfDisplays
                                   );


/// Function to get the memory configuration of an adapter. 
/// 
/// This function retrieves the memory configuration of a specified adapter.
/// 
/// 
/// Supported Platforms:
///   Linux; 32bit and 64bit 
/// 
/// Parameters
///   [in]  iAdapterIndex      The ADL index handle of the desired adapter. 
///   [in]  iScreenWidth       The pixel width of the X screen associated with the adapter. 
///   [in]  iScreenHeight      The pixel height of the X screen associated with the adapter. 
///   [in]  displayFeatureMask The valid define_adl_visiblememoryfeatures features 
///   [in]  numDisplays        Number of displays associated with the XScreen. 
///   [in]  displayFeatureList List of display features associated with each display found in the XScreen. Number of entries is numDisplays. 
///   [in]  iNumMemTypes       Size of lppMemRequired List 
///   [out] lppMemRequired     List of visible memory size required in bytes of specified type 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes 
/// 
/// Remarks
///   This API uses the memory allocation callback function provided by the user. If this API is called in Windows the return value is always ADL_ERR_NOT_SUPPORTED
int ADL_Adapter_ConfigMemory_Get ( int                        iAdapterIndex,
                                   int                        iScreenWidth,
                                   int                        iScreenHeight,
                                   int                        displayFeatureMask,
                                   int                        numDisplays,
                                   ADLMemoryDisplayFeatures * displayFeatureList,
                                   int *                      iNumMemTypes,
                                   ADLMemoryRequired **       lppMemRequired
                                 );


/// Function to retrieve memory information from the adapter. 
/// 
/// This function retrieves the memory information for a specified graphics adapter. 
/// Supported Platforms:
///   Linux; 32bit and 64bit 
/// 
/// Parameters
///   [in]  iAdapterIndex The ADL index handle of the desired adapter. 
///   [out] lpMemoryInfo  The pointer to the structure storing the retrieved memory information. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes
int ADL_Adapter_MemoryInfo_Get ( int             iAdapterIndex,
                                 ADLMemoryInfo * lpMemoryInfo
                               );


/// Get the requested tear free desktop setting and current status. 
/// 
/// Gets the requested setting and current status of all the GPUs on the system.
/// 
/// Tear free desktop reduces tearing in everything shown on the screen except full screen OGL applications. It double buffers the graphics adapter output ensuring that the image being drawn is not changed while a display is updating.
/// Supported Platforms:
///   Linux; 32bit and 64bit 
/// 
/// Parameters
///   [in]  iAdapter   Ignored. May be used in the future. 
///   [out] pDefault   The default requested value or NULL. 
///   [out] pRequested The requested tear free state. ADL_TRUE if it is requested on or ADL_FALSE if it requested off. 
///   [out] pStatus    The current status of tear free Define_adapter_tear_free_status 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes
int ADL_Adapter_Tear_Free_Get ( int   iAdapter,
                                int * pDefault,
                                int * pRequested,
                                int * pStatus
                              );


/// Set the requested tear free desktop setting. 
/// 
/// The tear free desktop setting is applied to all GPUs on the system.
/// 
/// Tear free desktop reduces tearing in everything shown on the screen except full screen OGL applications. It double buffers the graphics adapter output ensuring that the image being drawn is not changed while the display is updating.
/// Supported Platforms:
///   Linux; 32bit and 64bit 
/// 
/// Parameters
///   [in]  iAdapter   Ignored. May be used in the future. 
///   [in]  iRequested The new requested tear free state. ADL_TRUE to request it on and ADL_FALSE to request it off. 
///   [out] pStatus    The current status of tear free Define_adapter_tear_free_status 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes
int ADL_Adapter_Tear_Free_Set ( int   iAdapter,
                                int   iRequested,
                                int * pStatus
                              );


/// Function to retrieve all X Screen information for all OS-known adapters. 
/// 
/// This function retrieves the X Screen information of all OS-known adapters on a Linux system. OS-known adapters can include adapters that currently exist in the system (logical adapters) 
/// 
///  as well as ones that no longer exist in the system but are still recognized by the OS. 
/// Supported Platforms:
///   Linux; 32bit and 64bit 
/// 
/// Parameters
///   [in]  iInputSize    The size of lpInfo buffer. 
///   [out] lpXScreenInfo The pointer to the buffer storing the retrieved X Screen information. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes
int ADL_Adapter_XScreenInfo_Get ( LPXScreenInfo lpXScreenInfo,
                                  int           iInputSize
                                );


/// Function to get the Desktop Configuration. 
/// 
/// This function retreives current the desktop configuration information. 
/// Supported Platforms:
///   Linux; 32bit and 64bit 
/// 
/// Parameters
///   [in]  iAdapterIndex   The ADL index handle of the desired adapter. 
///   [out] lpDesktopConfig The pointer to the retrieved desktop configuration information.
/// Desktop Configuration Flags 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes 
/// 
/// Deprecated:
///   This API has been deprecated because it was only used for RandR 1.1 (Red Hat 5.x) distributions which is now not supported.
int ADL_DesktopConfig_Get ( int   iAdapterIndex,
                            int * lpDesktopConfig
                          );


/// Function to set the Desktop Configuration. 
/// 
/// This function sets the current desktop configuration information. 
/// Supported Platforms:
///   Linux; 32bit and 64bit 
/// 
/// Parameters
///   [in] iAdapterIndex  The ADL index handle of the desired adapter. 
///   [in] iDesktopConfig The desired Desktop Configuration information.
/// Desktop Configuration Flags 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes 
/// 
/// Deprecated:
///   This API has been deprecated because it was only used for RandR 1.1 (Red Hat 5.x) distributions which is now not supported.
int ADL_DesktopConfig_Set ( int iAdapterIndex,
                            int iDesktopConfig
                          );


/// Function to set the desktop configuration. 
/// 
/// This function sets the desktop configuration. 
/// Supported Platforms:
///   Linux; 32bit and 64bit 
/// 
/// Parameters
///   [in] iAdapterIndex           The ADL index handle of the desired adapter. 
///   [in] iDisplayIndex           The desired display index. 
///   [in] iDisplayControllerIndex The controller index. A field from ADLDisplayInfo structure 
///   [in] iShow                   The instruction to show the display number. Enter 0 to show and 1 to hide. 
///   [in] iDisplayNum             The number to display on screen. 
///   [in] iPosX                   The X position on screen to display index in % of screen. 
///   [in] iPosY                   The Y position on screen to display index in % of screen. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes
int ADL_Display_IdentifyDisplay ( int iAdapterIndex,
                                  int iDisplayIndex,
                                  int iDisplayControllerIndex,
                                  int iShow,
                                  int iDisplayNum,
                                  int iPosX,
                                  int iPosY
                                );


/// Function to get the current value of gamma for a LUT (controller). 
/// 
/// This function retrieves the current gamma value of the specified display index. Note: This replaces ADL_Controller_Color_Get 
/// Supported Platforms:
///   Linux; 32bit and 64bit 
/// 
/// Parameters
///   [in]  iAdapterIndex  The ADL index handle of the desired adapter. 
///   [in]  iDisplayIndex  The desired display index. 
///   [out] lpGammaCurrent The pointer to the retrieved current gamma information structure. 
///   [out] lpGammaDefault The pointer to the retrieved default gamma information structure. 
///   [out] lpGammaMin     The pointer to the retrieved minimum gamma information structure. 
///   [out] lpGammaMax     The pointer to the retrieved maximum gamma information structure. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes
int ADL_Display_LUTColor_Get ( int        iAdapterIndex,
                               int        iDisplayIndex,
                               ADLGamma * lpGammaCurrent,
                               ADLGamma * lpGammaDefault,
                               ADLGamma * lpGammaMin,
                               ADLGamma * lpGammaMax
                             );


/// Function to set the current gamma value for a LUT (controller). 
/// 
/// This function sets the gamma value of a specified display index (controller) Note: This replaces ADL_Controller_Color_Set 
/// Supported Platforms:
///   Linux; 32bit and 64bit 
/// 
/// Parameters
///   [in] iAdapterIndex The ADL index handle of the desired adapter. 
///   [in] iDisplayIndex The desired display index. 
///   [in] adlGamma      The Gamma information structure. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes
int ADL_Display_LUTColor_Set ( int      iAdapterIndex,
                               int      iDisplayIndex,
                               ADLGamma adlGamma
                             );


/// Function to retrieve the name of the Xrandr display. 
/// 
/// This function retrieves the Xrandr display name based on a specified adapter and display. 
/// Supported Platforms:
///   Linux; 32bit and 64bit 
/// 
/// Parameters
///   [in]  iAdapterIndex       The ADL index handle of the desired adapter. 
///   [in]  iDisplayIndex       The ADL index handle of the desired display. 
///   [out] lpXrandrDisplayName The pointer to the buffer storing the retrieved Xrandr display name. 
///   [in]  iBuffSize           The size of the lpXrandrDisplayName buffer. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes
int ADL_Display_XrandrDisplayName_Get ( int    iAdapterIndex,
                                        int    iDisplayIndex,
                                        char * lpXrandrDisplayName,
                                        int    iBuffSize
                                      );


/// Function to dynamically enable displays on a GPU. 
/// 
/// This function dynamically enables displays on a GPU. Supported on randr 1.1 distributions. This function is not supported on randr 1.2 and newer distributions. 
/// Supported Platforms:
///   Linux; 32bit and 64bit 
/// 
/// Parameters
///   [in] iAdapterIndex      The ADL index handle of the desired adapter. 
///   [in] lpDisplayIndexList The pointer to the list of display indexes that will be enabled. All others will be disabled. 
///   [in] iDisplayListSize   The size of the list. 
///   [in] bPersistOnly       Non-zero value means that settings will not take effect until system restart 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes 
/// 
/// Deprecated:
///   This API has been deprecated because it was only used for RandR 1.1 (Red Hat 5.x) distributions which is now not supported.
int ADL_DisplayEnable_Set ( int   iAdapterIndex,
                            int * lpDisplayIndexList,
                            int   iDisplayListSize,
                            int   bPersistOnly
                          );


/// Function to retrieve the number of enabled displays. 
/// 
/// This function retrieves the current number of enabled displays. 
/// Supported Platforms:
///   Linux; 32bit and 64bit 
/// 
/// Parameters
///   [in]  iAdapterIndex      The ADL index handle of the desired adapter. 
///   [out] lpNumberOfDisplays The pointer to the number of enabled displays. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes 
/// 
/// Deprecated:
///   This API has been deprecated because it was only used for RandR 1.1 (Red Hat 5.x) distributions which is now not supported.
int ADL_NumberOfDisplayEnable_Get ( int   iAdapterIndex,
                                    int * lpNumberOfDisplays
                                  );


#endif /* ADL_HEADER_LNX_H_ */
