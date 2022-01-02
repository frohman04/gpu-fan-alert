#ifndef ADL_HEADER_DISPLAYSMANAGER_H_
#define ADL_HEADER_DISPLAYSMANAGER_H_

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

/// ADL local interface. Retrieves GPU information of any AMD and non-AMD displays cloned for given GPU or all OS-known GPUs. 
/// 
/// This function retrieves information for passed adapter or -1 for all GPUs. 
/// 
/// 
/// Supported Platforms:
///   \WIn7 or above 
/// 
/// Parameters
///   [in]  context                   Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in]  iAdapterIndex             The ADL index handle of the desired adapter(one of GPU adapter index) or -1 if all GPUs are desired. For A+I system, please pass -1 only. 
///   [out] lpHasAMDAndNonAMDDIsplays pointer to an integer. It is 1 if there is any AMd and non-AMD displays cloned in the GPU or the system 
/// 
/// Returns
///   If the function valid, the return value is 1. Otherwise it is 0. 
/// 
/// Remarks
///   This API uses the memory allocation callback function provided by the user.
int ADL2_Adapter_AMDAndNonAMDDIsplayClone_Get ( ADL_CONTEXT_HANDLE context,
                                                int                iAdapterIndex,
                                                int *              lpHasAMDAndNonAMDDIsplays
                                              );


/// ADL local interface. Retrieves GPU information of special clone types for given GPU or all OS-known GPUs. 
/// 
/// This function retrieves special clone types information for passed adapter or -1 for all GPUs. Currently, cross-GPU-clone and corss-GPU-clone-AMDWithNonAMD 
/// 
/// 
/// Supported Platforms:
///   \WIn7 or above 
/// 
/// Parameters
///   [in]  context       Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in]  iAdapterIndex The ADL index handle of the desired adapter(one of GPU adapter index) or -1 if all GPUs are desired. For A+I system, please pass -1 only. 
///   [out] lpCloneTypes  pointer to an integer. It is bit vector. If the first bit is 1, the clone is cross-GPU-clone. It is may AMD with AMD or AMD with non-AMD. If The second bit is 1, the clone is cross-GPU-clone, but with non-AMD displays. It is available in WIN10 and WIN 8.1 PX A+I system 
/// 
/// Returns
///   If the function valid, the return value is 1. Otherwise it is 0. 
/// 
/// Remarks
///   if iAdapterIndex is not -1 and if there is one of cross-GPU clones found in the GPU, then cross-GPU clone is true
int ADL2_Adapter_CloneTypes_Get ( ADL_CONTEXT_HANDLE context,
                                  int                iAdapterIndex,
                                  int *              lpCloneTypes
                                );


/// ADL local interface. Disable all cross-GPU clone for given GPU or all OS-known GPUs. 
/// 
/// This function disables the cross-GPU clone for passed adapter(GPU) or -1 for all GPUs. 
/// 
/// 
/// Supported Platforms:
///   \WIn7 or above 
/// 
/// Parameters
///   [in] context       Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in] iAdapterIndex The ADL index handle of the desired adapter(one of GPU adapter index) or -1 if all GPUs are desired. For A+I system, please pass -1 only. 
///   [in] iOptions      is an integer, which decides the displays from other GPUs will be disabled or changed to extended mode. Currently, the API only supports the "disabled". This filed is just for extension for future useage. 
/// 
/// Returns
///   If the function valid, the return value is 1. Otherwise it is 0. 
/// 
/// Remarks
///   iOption support only 0 currently.
int ADL2_Adapter_CrossGPUClone_Disable ( ADL_CONTEXT_HANDLE context,
                                         int                iAdapterIndex,
                                         int                iOptions
                                       );


/// This function retrieve active desktop caps information 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in]  context            Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in]  iAdapterIndex      The ADL index handle of the desired adapter. 
///   [out] lpDesktopCapsValue Desktop caps value, bit vector. Currently designed for mix mode SLS feature 
///   [out] lpDesktopCapsMask  Desktop caps Mask 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK, or an ADL error code otherwise. Result Codes
int ADL2_Adapter_Desktop_Caps ( ADL_CONTEXT_HANDLE context,
                                int                iAdapterIndex,
                                int *              lpDesktopCapsValue,
                                int *              lpDesktopCapsMask
                              );


/// Supported Platforms:
///   Windows 7, 10 and above; 32bit and 64bit 
/// 
/// Parameters
///   [in]  context                 Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in]  iAdapterIndex           - Adapter Index. -1 not supported. Only active desktop adapter index is valid 
///   [in]  iNumOfAvailableDisplays - The number of displays can be used to create SLS 
///   [in]  lpAvailableDisplays     - Displays can be used to create SLS. The first one must be anchor display 
///   [out] lpNumSLSGrid            - The number of possible SLS grid types 
///   [out] lppSLSGrid              - possible SLS grid types 
///   [out] iOption                 - Bit vector, specifies the layout type of SLS grid data and portrait flag. There are two types of SLS layouts: relative to landscape (ref \ADL_DISPLAY_SLSGRID_CAP_OPTION_RELATIVETO_LANDSCAPE) and relative to current angle (ref \ADL_DISPLAY_SLSGRID_CAP_OPTION_RELATIVETO_CURRENTANGLE). If the current desktop associated with the input adapter is rotated to 90 or 270 degree, set bit ref \ADL_DISPLAY_SLSGRID_PORTAIT_MODE to 1 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK, or an ADL error code otherwise. Result Codes
int ADL2_Adapter_Desktop_SupportedSLSGridTypes_Get ( ADL_CONTEXT_HANDLE context,
                                                     int                iAdapterIndex,
                                                     int                iNumOfAvailableDisplays,
                                                     ADLDisplayTarget * lpAvailableDisplays,
                                                     int *              lpNumSLSGrid,
                                                     ADLSLSGrid **      lppSLSGrid,
                                                     int                iOption
                                                   );


/// Function to retrieve the adapter display manner capabilities based on ADL index. 
/// 
/// This function retrieves the adapter display manner capabilities (e.g., single, clone, extended desktop, and stretch mode). 
/// Supported Platforms:
///   Windows 7, 10 and above; 32bit and 64bit 
/// 
/// Parameters
///   [in]  context               Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in]  iAdapterIndex         The ADL index handle of the desired adapter. A value of -1 returns all adapter manner information for the system across all GPUs. 
///   [out] lpNumDisplayCaps      The Number of display manner capabilities. 
///   [out] lppAdapterDisplayCaps The lists of display manner capabilities across all GPUs. Refer to the ADLAdapterDisplayCap structure for more information. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes
/// 
/// Remarks
///   This API uses the memory allocation callback function provided by the user.
int ADL2_Adapter_Display_Caps ( ADL_CONTEXT_HANDLE      context,
                                int                     iAdapterIndex,
                                int *                   lpNumDisplayCaps,
                                ADLAdapterDisplayCap ** lppAdapterDisplayCaps
                              );


/// Function to retrieve the number of Activatable sources based on ADL Index. 
/// 
/// This function retrieves the activatable sources list for a specified input adapter. ActivatableSources is the number of displays that can be turned on simultaneously for the same GPU. For example, for AMD Radeon HD 4xxx Series and earlier this number is 2 while for ATI Radeon HD 5xxx Series the number could be 6 or 4. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in]  context       Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in]  iAdapterIndex The ADL index handle of the desired adapter. 
///   [out] lpNumSources  The pointer to the number of sources that can be activated. 
///   [out] lppSources    The pointer to the pointer to the retrieved activatable sources buffer. Refer to the ADLActivatableSource structure for more information. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes
/// 
/// Remarks
///   This API uses the memory allocation callback function provided by the user.
int ADL2_Adapter_NumberOfActivatableSources_Get ( ADL_CONTEXT_HANDLE      context,
                                                  int                     iAdapterIndex,
                                                  int *                   lpNumSources,
                                                  ADLActivatableSource ** lppSources
                                                );


/// Set SLS bezel offsets for each display index. 
/// Supported Platforms:
///   Windows 7, 10 and above; 32bit and 64bit 
/// 
/// Parameters
///   [in] context         Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in] iAdapterIndex   The ADL index of the desired adapter. This function does not support -1. 
///   [in] iSLSMapIndex    The SLS map index to apply bezel offset. 
///   [in] iNumBezelOffset input size of the SLS offset per display per mode array. 
///   [in] lpBezelOffset   List of SLS offset information, refer to ADLBezelOffset struct. 
///   [in] SLSMap          The display SLS map information. Refer to the ADLSLSMap structure for more information. 
///   [in] iOption         Option to set bezel offset. Default: ADL_DISPLAY_BEZELOFFSET_COMMIT 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes
/// 
/// Remarks
///   Call ADL_Flush_Driver_Data() after to persist settings on reboot.
int ADL2_Display_BezelOffset_Set ( ADL_CONTEXT_HANDLE context,
                                   int                iAdapterIndex,
                                   int                iSLSMapIndex,
                                   int                iNumBezelOffset,
                                   LPADLSLSOffset     lpBezelOffset,
                                   ADLSLSMap          SLSMap,
                                   int                iOption
                                 );


/// Get bezel offset stepping size for the input adapter. 
/// Supported Platforms:
///   Windows 7, 10 and above; 32bit and 64bit 
/// 
/// Parameters
///   [in]  context                       Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in]  iAdapterIndex                 The ADL index of the desired adapter. This function does not support -1. 
///   [out] iNumBezelOffsetSteppingSize   The number of Bezel offset stepping size per adapter. 
///   [out] lppBezelOffsetSteppingSizeint Bezel offset stepping size information. Refer to ADLBezelOffsetSteppingSize struct. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes 
/// 
/// Remarks
///   Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call ADL2_Main_Control_Create first to obtain ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using ADL2_Main_Control_Destroy.
int ADL2_Display_BezelOffsetSteppingSize_Get ( ADL_CONTEXT_HANDLE            context,
                                               int                           iAdapterIndex,
                                               int *                         lpNumBezelOffsetSteppingSize,
                                               ADLBezelOffsetSteppingSize ** lppBezelOffsetSteppingSize
                                             );


/// Validate the list of the SLS display configurations to determine if bezel is supported or not. 
/// Supported Platforms:
///   Windows 7, 10 and above; 32bit and 64bit 
/// 
/// Parameters
///   [in]  context                   Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in]  iAdapterIndex             The ADL index of the desired adapter. This function does not support -1. 
///   [in]  iNumPossibleSLSMap        Input size of SLS map to be validated. 
///   [in]  lpPossibleSLSMaps         List of possible SLS maps to be validated. 
///   [out] lpNumPossibleSLSMapResult Size of the valid array. 
///   [out] lppPossibleMapResult      valid result list. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes 
/// 
/// Remarks
///   Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call ADL2_Main_Control_Create first to obtain ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using ADL2_Main_Control_Destroy.
int ADL2_Display_BezelSupported_Validate ( ADL_CONTEXT_HANDLE       context,
                                           int                      iAdapterIndex,
                                           int                      iNumPossibleSLSMap,
                                           LPADLPossibleSLSMap      lpPossibleSLSMaps,
                                           int *                    lpNumPossibleSLSMapResult,
                                           LPADLPossibleMapResult * lppPossibleMapResult
                                         );


/// Function to retrieve current display map configurations. 
/// 
/// This function retrieves the current display map configurations, including the controllers and adapters mapped to each display. 
/// Supported Platforms:
///   Windows 7, 10 and above; 32bit and 64bit 
/// 
/// Parameters
///   [in]  context            Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in]  iAdapterIndex      The ADL index handle of the desired adapter. A value of -1 returns all display configurations for the system across multiple GPUs. 
///   [out] lpNumDisplayMap    The pointer to the number of retrieved display maps. 
///   [out] lppDisplayMap      The pointer to the pointer to the display manner information. Refer to the ADLDisplayMap structure for more information. 
///   [out] lpNumDisplayTarget The pointer to the display target sets retrieved. 
///   [out] lppDisplayTarget   The pointer to the pointer to the display target buffer. Refer to the ADLDisplayTarget structure for more information. 
///   [in]  iOptions           The function option. ADL_DISPLAY_DISPLAYMAP_OPTION_GPUINFO. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes
/// 
/// Remarks
///   This API uses the memory allocation callback function provided by the user.
int ADL2_Display_DisplayMapConfig_Get ( ADL_CONTEXT_HANDLE  context,
                                        int                 iAdapterIndex,
                                        int *               lpNumDisplayMap,
                                        ADLDisplayMap **    lppDisplayMap,
                                        int *               lpNumDisplayTarget,
                                        ADLDisplayTarget ** lppDisplayTarget,
                                        int                 iOptions
                                      );


/// Function to validate a list of display configurations. 
/// 
/// This function allows the user to input a potential displays map and its targets. The function can also be used to obtain a list of display targets that can be added to this given topology and a list of display targets that can be removed from this given topology. 
/// Supported Platforms:
///   Windows 7, 10 and above; 32bit and 64bit 
/// 
/// Parameters
///   [in]  context                   Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in]  iAdapterIndex             The ADL index handle of the desired adapter. This function does not support the -1 value to test topologies across multiple GPUs. 
///   [in]  iNumDisplayMap            The number of display maps in this configuration. 
///   [in]  lpDisplayMap              The pointer to the display map information. Refer to the ADLDisplayMap structure for more information. 
///   [in]  iNumDisplayTarget         The number of display target sets in this configuration. 
///   [in]  lpDisplayTarget           The pointer to the display target information. Refer to the ADLDisplayTarget structure for more information. 
///   [out] lpNumPossibleAddTarget    The pointer to the number of items in the array of lppPossibleAddTarget. 
///   [out] lppPossibleAddTarget      The pointer to the array of the display targets that can be added in the given topology. Refer to the ADLDisplayTarget structure for more information. The user is responsible for freeing the memory for this array when it is no longer needed. 
///   [out] lpNumPossibleRemoveTarget The pointer to the number of items in the array of lppPossibleRemoveTarget. 
///   [out] lppPossibleRemoveTarget   The pointer to the array of the display targets that can be removed from the given topology. Refer to the ADLDisplayTarget structure for more information. The user is responsible for freeing the memory for this array when it is no longer needed. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes
/// 
/// Remarks
///   This API uses the memory allocation callback function provided by the user.
int ADL2_Display_DisplayMapConfig_PossibleAddAndRemove ( ADL_CONTEXT_HANDLE  context,
                                                         int                 iAdapterIndex,
                                                         int                 iNumDisplayMap,
                                                         ADLDisplayMap *     lpDisplayMap,
                                                         int                 iNumDisplayTarget,
                                                         ADLDisplayTarget *  lpDisplayTarget,
                                                         int *               lpNumPossibleAddTarget,
                                                         ADLDisplayTarget ** lppPossibleAddTarget,
                                                         int *               lpNumPossibleRemoveTarget,
                                                         ADLDisplayTarget ** lppPossibleRemoveTarget
                                                       );


/// Function to set the current display configuration. 
/// 
/// This function sets the current display configurations for each display, including the controller and adapter mapped to each display. Possible display configurations are single, clone, extended desktop, and stretch mode. If clone mode is desired and the current display configuration is extended desktop mode, the function disables extended desktop mode in order to enable clone mode. If extended display mode is desired and the current display configuration is single mode, this function enables extended desktop. 
/// Supported Platforms:
///   Windows 7, 10 and above; 32bit and 64bit 
/// 
/// Parameters
///   [in] context           Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in] iAdapterIndex     The ADL index handle of the desired adapter. A value of -1 sets the displays in the system across multiple GPUs. 
///   [in] iNumDisplayMap    The number of display maps to be set. 
///   [in] lpDisplayMap      The pointer to the retrieved display map information. Refer to the ADLDisplayMap structure for more information. 
///   [in] iNumDisplayTarget The number of display target sets to be set. 
///   [in] lpDisplayTarget   The pointer to the display target information. Refer to the ADLDisplayTarget structure for more information. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes
/// 
/// Remarks
///   This API uses the memory allocation callback function provided by the user.
int ADL2_Display_DisplayMapConfig_Set ( ADL_CONTEXT_HANDLE context,
                                        int                iAdapterIndex,
                                        int                iNumDisplayMap,
                                        ADLDisplayMap *    lpDisplayMap,
                                        int                iNumDisplayTarget,
                                        ADLDisplayTarget * lpDisplayTarget
                                      );


/// Function to validate the list of the display configurations based on ADL Index. 
/// 
/// This function validate the list of the display configurations for a specified input adapter. This function is applicable to all OS platforms. 
/// Supported Platforms:
///   Windows 7, 10 and above; 32bit and 64bit 
/// 
/// Parameters
///   [in]  context                Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in]  iAdapterIndex          The ADL index handle of the desired adapter. 
///   [in]  iNumPossibleMap        The number of possible maps to be validated. 
///   [in]  lpPossibleMaps         The list of possible maps to be validated. Refer to the ADLPossibleMap structure for more information. 
///   [out] lpNumPossibleMapResult The pointer to the number of validate result list. 
///   [out] lppPossibleMapResult   The pointer to the pointer to validation result list. Refer to the ADLPossibleMapResult structure for more information. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes
/// 
/// Remarks
///   This API uses the memory allocation callback function provided by the user.
int ADL2_Display_DisplayMapConfig_Validate ( ADL_CONTEXT_HANDLE      context,
                                             int                     iAdapterIndex,
                                             int                     iNumPossibleMap,
                                             ADLPossibleMap *        lpPossibleMaps,
                                             int *                   lpNumPossibleMapResult,
                                             ADLPossibleMapResult ** lppPossibleMapResult
                                           );


/// Function to retrieve the forcible connected status of a display. 
/// 
/// This function determines whether or not a display (i.e. CV) is set to be forcibly connected. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in]  context       Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in]  iAdapterIndex The ADL index handle of the desired adapter. 
///   [in]  iDisplayIndex The desired display index. 
///   [out] lpStatus      The forcible connected status of the display. ADL_TRUE : forced connected; ADL_FALSE : otherwise. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes
/// 
/// Remarks
///   A display can be forcibly connected without being actually connected or not recognized as connected. For example, some old 50 ohm TVs are not detected properly and need to be forcibly connected in order to be turned on.
int ADL2_Display_ForcibleDisplay_Get ( ADL_CONTEXT_HANDLE context,
                                       int                iAdapterIndex,
                                       int                iDisplayIndex,
                                       int *              lpStatus
                                     );


/// Function to set the forcible connected status of a display. 
/// 
/// This function sets a display (i.e. TV) to be either forcibly connected or not forcibly connected. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in] context       Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in] iAdapterIndex The ADL index handle of the desired adapter. 
///   [in] iDisplayIndex The desired display index. 
///   [in] iStatus       The desired connection status. ADL_TRUE : forced connected; ADL_FALSE : otherwise. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes
/// 
/// Remarks
///   A display can be forcibly connected without being actually connected or not recognized as connected. For example, some old 50 ohm TVs are not detected properly and need to be forcibly connected in order to be turned on.
int ADL2_Display_ForcibleDisplay_Set ( ADL_CONTEXT_HANDLE context,
                                       int                iAdapterIndex,
                                       int                iDisplayIndex,
                                       int                iStatus
                                     );


/// Function to retrieve the display mode information. 
/// 
/// This function retrieves the current display mode information. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in]  context       Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in]  iAdapterIndex The ADL index handle of the desired adapter. A value of -1 retrieves all modes for the system across multiple GPUs. 
///   [in]  iDisplayIndex The desired display index. If the index is -1, this field is ignored. 
///   [out] lpNumModes    The pointer to the number of modes retrieved. 
///   [out] lppModes      The pointer to the pointer to the retrieved display modes. Refer to the Display ADLMode structure for more information. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes
/// 
/// Remarks
///   This API uses the memory allocation callback function provided by the user.
int ADL2_Display_Modes_Get ( ADL_CONTEXT_HANDLE context,
                             int                iAdapterIndex,
                             int                iDisplayIndex,
                             int *              lpNumModes,
                             ADLMode **         lppModes
                           );


/// Function to set display mode information. 
/// 
/// This function sets the current display mode information. 
/// Supported Platforms:
///   Windows 7, 10 and above; 32bit and 64bit 
/// 
/// Parameters
///   [in] context       Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in] iAdapterIndex The ADL index handle of the desired adapter. A value of -1 sets the modes across multiple GPUs. 
///   [in] iDisplayIndex The desired display index. If the index is -1, this field is ignored. 
///   [in] iNumModes     The number of modes to be set. 
///   [in] lpModes       The pointer to the display mode information to be set. Refer to the ADLMode structure for more information. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes
/// 
/// Remarks
///   Call ADL_Flush_Driver_Data() after to persist settings on reboot.
int ADL2_Display_Modes_Set ( ADL_CONTEXT_HANDLE context,
                             int                iAdapterIndex,
                             int                iDisplayIndex,
                             int                iNumModes,
                             ADLMode *          lpModes
                           );


/// Set SLS overlap offsets for each display index. 
/// Supported Platforms:
///   Windows 7; 32bit and 64bit and above 
/// 
/// Parameters
///   [in] context             Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in] iAdapterIndex       The ADL index of the desired adapter. This function does not support -1. 
///   [in] iSLSMapIndex        The SLS map index to apply Overlap offset. 
///   [in] iNumOverlappedModes the no. of overlapped modes defined. Each such mode refers to a set of targets in the array of targets 
///   [in] lpOverlappedModes   the list of overlapped modes defined 
///   [in] iNumTargetOffsets   the no. of targets in the list of targets 
///   [in] lpTargetOffsets     the list of target offsets for all the overlap modes defined 
///   [in] SLSMap              The display SLS map information. Refer to the ADLSLSMap structure for more information. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes
/// 
/// Remarks
///   Call ADL_Flush_Driver_Data() after to persist settings on reboot.
int ADL2_Display_Overlap_Set ( ADL_CONTEXT_HANDLE    context,
                               int                   iAdapterIndex,
                               int                   iSLSMapIndex,
                               int                   iNumOverlappedModes,
                               LPADLSLSTargetOverlap lpOverlappedModes,
                               int                   iNumTargetOffsets,
                               LPADLSLSOffset        lpTargetOffsets,
                               ADLSLSMap             SLSMap
                             );


/// Function to retrieve the possible display mappings. 
/// 
/// This function retrieves possible display mappings for an adapter. 
/// Supported Platforms:
///   Windows 7, 10 and above; 32bit and 64bit 
/// 
/// Parameters
///   [in]  context                           Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in]  iAdapterIndex                     The ADL index handle of the desired adapter. 
///   [in]  iNumberOfPresetMapping            The current number of preset mappings from the lpPresetMappings array. 
///   [in]  lpPresetMappings                  The pointer to the buffer storing the current preset mappings. Refer to the ADLPossibleMapping structure for more information. 
///   [in]  iEnquiryControllerIndex           The desired controller index for mapping. 
///   [out] lpNumberOfEnquiryPossibleMappings The pointer to the number of possible mappings from the lppEnquiryPossibleMappings array. 
///   [out] lppEnquiryPossibleMappings        The pointer to the pointer to the retrieved possible mapping buffer. Refer to the ADLPossibleMapping structure for more information. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes
/// 
/// Remarks
///   This API uses the memory allocation callback function provided by the user.
int ADL2_Display_PossibleMapping_Get ( ADL_CONTEXT_HANDLE    context,
                                       int                   iAdapterIndex,
                                       int                   iNumberOfPresetMapping,
                                       ADLPossibleMapping *  lpPresetMappings,
                                       int                   iEnquiryControllerIndex,
                                       int *                 lpNumberOfEnquiryPossibleMappings,
                                       ADLPossibleMapping ** lppEnquiryPossibleMappings
                                     );


/// Function to retrieve the OS possible modes list for an adapter (all OS platforms). 
/// 
/// This function retrieves the OS possible modes list for a specified input adapter. 
/// Supported Platforms:
///   Windows 7, 10 and above; 32bit and 64bit 
/// 
/// Parameters
///   [in]  context       Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in]  iAdapterIndex The ADL index handle of the desired adapter. 
///   [out] lpNumModes    The pointer to the number of display modes from the lppModes array. 
///   [out] lppModes      The pointer to the pointer to the retrieved possible display modes buffer. Refer to the ADLMode structure for more information. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes
/// 
/// Remarks
///   This API uses the memory allocation callback function provided by the user.
int ADL2_Display_PossibleMode_Get ( ADL_CONTEXT_HANDLE context,
                                    int                iAdapterIndex,
                                    int *              lpNumModes,
                                    ADLMode **         lppModes
                                  );


/// Function to retrieve the ATI possible modes list for an adapter and preset mapping (Windows XP). 
/// 
/// This function retrieves the ATI possible modes list based on a specified input adapter and preset mapping. This function is applicable only on Windows XP platforms. 
/// Supported Platforms:
///   Windows XP; 32bit and 64bit 
/// 
/// Parameters
///   [in]  context                    Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in]  iAdapterIndex              The ADL index handle of the desired adapter. 
///   [in]  iNumDisplayTargets         The number of display target from the lpDisplayTargets array. 
///   [in]  lpDisplayTargets           The pointer to the retrieved display target configurations. Refer to the ADLDisplayTarget structure for more information. E.g. If a CRT and TV are on as extended mode, lpMapConfigs will contain two ADLDisplayTarget structures: one CRT and one TV, both in extended manner. 
///   [in]  iLargeDesktopSupportedType The large desktop type. Refer to the ADLLARGEDESKTOPTYPE enum for more information. 
///   [in]  iDevicePanningControl      The device panning control mode. Refer to the ADLPanningMode enum for more information. 
///   [out] lpNumModes                 The pointer to the number of modes from the lppModes array. 
///   [out] lppModes                   The pointer to the pointer to the possible display modes buffer. Refer to the ADLMode structure for more information. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes
/// 
/// Remarks
///   This API uses the memory allocation callback function provided by the user.
int ADL2_Display_PossibleMode_WinXP_Get ( ADL_CONTEXT_HANDLE context,
                                          int                iAdapterIndex,
                                          int                iNumDisplayTargets,
                                          ADLDisplayTarget * lpDisplayTargets,
                                          int                iLargeDesktopSupportedType,
                                          int                iDevicePanningControl,
                                          int *              lpNumModes,
                                          ADLMode **         lppModes
                                        );


/// Get SLS builder common mode layout size 
/// Supported Platforms:
///   Windows 7; 32bit and 64bit and Above 
/// 
/// Parameters
///   [in]  context           Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in]  iAdapterIndex     - Input adapter Index. This function does not support -1 as adapter index. 
///   [in]  iNumDisplayTarget - the input size of SLS Target configurations array 
///   [in]  lpSLSTarget       - a list of SLS Target in the SLS, refer to ADLSLSTargetstruct 
///   [out] lpTotalWidth      - Virtual topology view size max width 
///   [out] lpTotalHeight     - Virtual topoplogy view size max height 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes
int ADL2_Display_SLSBuilder_CommonMode_Get ( ADL_CONTEXT_HANDLE context,
                                             int                iAdapterIndex,
                                             int                iNumDisplayTarget,
                                             ADLSLSTarget *     lpSLSTarget,
                                             int *              lpTotalWidth,
                                             int *              lpTotalHeight
                                           );


/// 
int ADL2_Display_SLSGrid_Caps ( ADL_CONTEXT_HANDLE context,
                                int                iAdapterIndex,
                                int *              lpNumSLSGrid,
                                ADLSLSGrid **      lppSLSGrid,
                                int                iOption
                              );


/// Function to create an SLS configuration. 
/// 
/// This function creates an SLS configuration with a given grid, targets, and bezel mode percent. It will output an SLS map index if the SLS map is successfully created. 
/// Supported Platforms:
///   Windows 7, 10 and above; 32bit and 64bit 
/// 
/// Parameters
///   [in]  context           Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in]  iAdapterIndex     The ADL index of the desired adapter. This function does not support -1. 
///   [in]  SLSMap            Specifies the display SLS map data that contains SLS grid and orientation information. Its type is ADLSLSMap 
///   [in]  iNumTarget        Specifies the number of displays to be used to create an SLS. 
///   [in]  lpSLSTarget       Array of displays that are used to create an SLS. The data type is ADLSLSTarget. 
///   [in]  iBezelModePercent Specifies the bezel mode percent. If these displays do not support bezel, set it to 0. 
///   [out] lpSLSMapIndex     Pointer to a variable that will receive the new created SLS map index. If an SLS grid failed to create, its value is -1, other wise, it is non-negative integer. 
///   [in]  iOption           Specifies the layout type of SLS grid data. It is bit vector. There are two types of SLS layouts,: relative to landscape (ref \ADL_DISPLAY_SLSGRID_CAP_OPTION_RELATIVETO_LANDSCAPE) and relative to current angle (ref \ADL_DISPLAY_SLSGRID_CAP_OPTION_RELATIVETO_CURRENTANGLE). 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes
/// 
/// Remarks
///   Call ADL_Flush_Driver_Data() after to persist settings on reboot.
int ADL2_Display_SLSMapConfig_Create ( ADL_CONTEXT_HANDLE context,
                                       int                iAdapterIndex,
                                       ADLSLSMap          SLSMap,
                                       int                iNumTarget,
                                       ADLSLSTarget *     lpSLSTarget,
                                       int                iBezelModePercent,
                                       int *              lpSLSMapIndex,
                                       int                iOption
                                     );


/// Function to delete an SLS map from the driver database. 
/// 
/// This function deletes an SLS map from the driver database based on the input SLS map index. 
/// Supported Platforms:
///   Windows 7, 10 and above; 32bit and 64bit 
/// 
/// Parameters
///   [in] context       Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in] iAdapterIndex The ADL index of the desired adapter. This function does not support -1. 
///   [in] iSLSMapIndex  Specifies the SLS map index to be deleted. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes
/// 
/// Remarks
///   Call ADL_Flush_Driver_Data() after to persist settings on reboot.
int ADL2_Display_SLSMapConfig_Delete ( ADL_CONTEXT_HANDLE context,
                                       int                iAdapterIndex,
                                       int                iSLSMapIndex
                                     );


/// Function to retrieve an SLS configuration. 
/// 
/// This function retrieves an SLS configuration, which includes the, SLS map, SLS targets, SLS standard modes, bezel modes or a transient mode, and offsets. 
/// Supported Platforms:
///   Windows 7, 10 and above; 32bit and 64bit 
/// 
/// Parameters
///   [in]  context               Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in]  iAdapterIndex         Specifies the adapter to be queried. This function does not support -1. 
///   [in]  iSLSMapIndex          Specifies the SLS map index to be queried. 
///   [out] lpSLSMap              Pointer to a variable that contains the SLS map data. The data type is ADLSLSMap. 
///   [out] lpNumSLSTarget        Pointer to variable that will receive the number of targets in the SLS map. 
///   [out] lppSLSTarget          Pointer of a pointer to a variable that conations targets in the SLS map. the data type is ADLDisplayTarget Application does not need to allocate memory but it should free the pointer since the memory is allocated by ADL call back function. 
///   [out] lpNumSLSNativeMode    Pointer to a variable that will receive the number of native SLS modes supported by the SLS configuration. 
///   [out] lppSLSNativeMode      Pointer of a pointer to a variable that contains the native SLS modes. the data type is ADLSLSMode. Application does not need to allocate memory but it should free the pointer since the memory is allocated by ADL call back function. 
///   [out] lpNumSLSBezelMode     Pointer to a variable that will receive the number of the bezel modes supported by the SLS configuration. 
///   [out] lppSLSbezelMode       Pointer of a pointer to a variable that contains the bezel SLS modes. the data type is ADLSLSMode. Application does not need to allocate memory but it should free the pointer since the memory is allocated by ADL call back function. 
///   [out] lpNumSLSTransientMode Pointer to a variable that will receive the number of the transient modes supported by the SLS configuration. 
///   [out] lppTransientMode      Pointer of a pointer to a variable that contains the transient SLS modes. the data type is ADLSLSMode. Application does not need to allocate memory but it should free the pointer since the memory is allocated by ADL call back function. 
///   [out] lpNumSLSOffset        Pointer to a variable that will receive the number of the SLS offset supported by the SLS configuration. 
///   [out] lppSLSOffset          Pointer of a pointer to a variable that contains the SLS offsets. the data type is ADLSLSOffset. Application does not need to allocate memory but it should free the pointer since the memory is allocated by ADL call back function. 
///   [in]  iOption               Specifies the layout type of SLS grid data. It is bit vector. There are two types of SLS layout:s, relative to landscape (ref \ADL_DISPLAY_SLSGRID_CAP_OPTION_RELATIVETO_LANDSCAPE) and relative to current angle (ref \ADL_DISPLAY_SLSGRID_CAP_OPTION_RELATIVETO_CURRENTANGLE). 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes
/// 
/// Remarks
///   This API uses the memory allocation callback function provided by the user.
int ADL2_Display_SLSMapConfig_Get ( ADL_CONTEXT_HANDLE       context,
                                    int                      iAdapterIndex,
                                    int                      iSLSMapIndex,
                                    ADLSLSMap *              lpSLSMap,
                                    int *                    lpNumSLSTarget,
                                    ADLSLSTarget **          lppSLSTarget,
                                    int *                    lpNumNativeMode,
                                    ADLSLSMode **            lppNativeMode,
                                    int *                    lpNumBezelMode,
                                    ADLBezelTransientMode ** lppBezelMode,
                                    int *                    lpNumTransientMode,
                                    ADLBezelTransientMode ** lppTransientMode,
                                    int *                    lpNumSLSOffset,
                                    ADLSLSOffset **          lppSLSOffset,
                                    int                      iOption
                                  );


/// Function to rearrange display orders in an SLS map. 
/// 
/// This function changes the display orders in an SLS map in order to make the image show on the displays correctly. 
/// Supported Platforms:
///   Windows 7, 10 and above; 32bit and 64bit 
/// 
/// Parameters
///   [in] context       Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in] iAdapterIndex Specifies the adapter to be operated on. This function does not support -1. 
///   [in] iSLSMapIndex  Specifies the SLS map index that will need to do rearrangement 
///   [in] iNumSLSTarget Specifies the number of displays in the SLS map. 
///   [in] lpSLSTarget   Array of displays that are in the SLS map. 
///   [in] slsMap        Specifies the SLS map info. Its type is ADLSLSMap. The only needed data is the map orientation. All others are ignored by the function. 
/// 
///   [in] iOption       Specifies the layout type of SLS grid data. It is bit vector. There are two types of SLS layouts, relative to landscape (ref \ADL_DISPLAY_SLSGRID_CAP_OPTION_RELATIVETO_LANDSCAPE) and relative to current angle (ref \ADL_DISPLAY_SLSGRID_CAP_OPTION_RELATIVETO_CURRENTANGLE). 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes 
/// 
/// Remarks
///   Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call ADL2_Main_Control_Create first to obtain ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using ADL2_Main_Control_Destroy.
int ADL2_Display_SLSMapConfig_Rearrange ( ADL_CONTEXT_HANDLE context,
                                          int                iAdapterIndex,
                                          int                iSLSMapIndex,
                                          int                iNumDisplayTarget,
                                          ADLSLSTarget *     lpSLSTarget,
                                          ADLSLSMap          slsMap,
                                          int                iOption
                                        );


/// Function to enable/disable SLS bind. 
/// 
/// This function enables or disables an SLS bind 
/// Supported Platforms:
///   Windows 7, 10 and above; 32bit and 64bit 
/// 
/// Parameters
///   [in] context       Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in] iAdapterIndex The ADL index of the desired adapter. This function does not support -1. 
///   [in] iSLSMapIndex  Specifies the SLS map index to be deleted. 
///   [in] iState        Specifies the action type. To enable SLS map, sets it to ADL_TRUE. Otherwise set it to ADL_FASLE. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes
/// 
/// Remarks
///   Call ADL_Flush_Driver_Data() after to persist settings on reboot.
int ADL2_Display_SLSMapConfig_SetState ( ADL_CONTEXT_HANDLE context,
                                         int                iAdapterIndex,
                                         int                iSLSMapIndex,
                                         int                iState
                                       );


/// Set SLS configuration for each display index the controller and the adapter is being mapped to 
/// Supported Platforms:
///   Windows 7; 32bit and 64bit and Above 
/// 
/// Parameters
///   [in]  context                       Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in]  iAdapterIndex                 - Input adapter Index. This function does not support -1 as adapter index. 
///   [in]  slsMap                        - SLS information, refer to ADLSLSMapstruct 
///   [in]  iNumDisplayTarget             - the input size of SLS Target configurations array 
///   [in]  lpSLSTarget                   - a list of SLS Target in the SLS, refer to ADLSLSTargetstruct 
///   [out] lpSupportedSLSLayoutImageMode - Bit vector. 
///   [out] lpReasonForNotSupportSLS      - Bit vector, if the group of the targets does not some or all of SLS layout image mode, the bit vector will give the reason codes 
///   [in]  iOption                       - Bit vector, specifies the layout type of SLS grid data and portrait flag. There are two types of SLS layouts: relative to landscape (ref \ADL_DISPLAY_SLSGRID_CAP_OPTION_RELATIVETO_LANDSCAPE) and relative to current angle (ref \ADL_DISPLAY_SLSGRID_CAP_OPTION_RELATIVETO_CURRENTANGLE). If the current desktop associated with the input adapter is rotated to 90 or 270 degree, set bit ref \ADL_DISPLAY_SLSGRID_PORTAIT_MODE to 1 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes
int ADL2_Display_SLSMapConfig_Valid ( ADL_CONTEXT_HANDLE context,
                                      int                iAdapterIndex,
                                      ADLSLSMap          slsMap,
                                      int                iNumDisplayTarget,
                                      ADLSLSTarget *     lpSLSTarget,
                                      int *              lpSupportedSLSLayoutImageMode,
                                      int *              lpReasonForNotSupportSLS,
                                      int                iOption
                                    );


/// Function to delete an list of SLS map indexes from the driver database. 
/// 
/// This function deletes all SLS maps in a list from the driver database based on the input SLS map index. 
/// Supported Platforms:
///   Windows 7, 10 and above; 32bit and 64bit 
/// 
/// Parameters
///   [in] iAdapterIndex         The ADL index of the desired adapter. This function does not support -1. 
///   [in] iNumSLSMapINdex       Specifies number of SLS Map Indexes for input 
///   [in] lpSLSMapIndexes,array of SLSMapIndexes to be deleted 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes
/// 
/// Remarks
///   Call ADL_Flush_Driver_Data() after to persist settings on reboot.
int ADL2_Display_SLSMapConfigX2_Delete ( ADL_CONTEXT_HANDLE context,
                                         int                iAdapterIndex,
                                         int                iNumSLSMapIndex,
                                         int *              lpSLSMapIndexes
                                       );


/// Function to retrieve an SLS configuration. 
/// 
/// This function retrieves an SLS configuration, which includes the, SLS map, SLS targets, SLS standard modes, bezel modes or a transient mode, and offsets. 
/// Supported Platforms:
///   Windows 7, 10 and above; 32bit and 64bit 
/// 
/// Parameters
///   [in]  context                Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in]  iAdapterIndex          Specifies the adapter to be queried. This function does not support -1. 
///   [in]  iSLSMapIndex           Specifies the SLS map index to be queried. 
///   [out] lpSLSMap               Pointer to a variable that contains the SLS map data. The data type is ADLSLSMap. 
///   [out] lpNumSLSTarget         Pointer to variable that will receive the number of targets in the SLS map. 
///   [out] lppSLSTarget           Pointer of a pointer to a variable that conations targets in the SLS map. the data type is ADLDisplayTarget Application does not need to allocate memory but it should free the pointer since the memory is allocated by ADL call back function. 
///   [out] lpNumSLSNativeMode     Pointer to a variable that will receive the number of native SLS modes supported by the SLS configuration. 
///   [out] lppSLSNativeMode       Pointer of a pointer to a variable that contains the native SLS modes. the data type is ADLSLSMode. Application does not need to allocate memory but it should free the pointer since the memory is allocated by ADL call back function. 
///   [out] lpNumNativeModeOffsets Pointer to a variable that will receive the number of native SLS mode offsets supported by the SLS configuration. 
///   [out] lppNativeModeOffsets   Pointer of a pointer to a variable that contains the native SLS mode offsets. the data type is ADLSLSOffset. Application does not need to allocate memory but it should free the pointer since the memory is allocated by ADL call back function. 
///   [out] lpNumSLSBezelMode      Pointer to a variable that will receive the number of the bezel modes supported by the SLS configuration. 
///   [out] lppSLSbezelMode        Pointer of a pointer to a variable that contains the bezel SLS modes. the data type is ADLSLSMode. Application does not need to allocate memory but it should free the pointer since the memory is allocated by ADL call back function. 
///   [out] lpNumSLSTransientMode  Pointer to a variable that will receive the number of the transient modes supported by the SLS configuration. 
///   [out] lppTransientMode       Pointer of a pointer to a variable that contains the transient SLS modes. the data type is ADLSLSMode. Application does not need to allocate memory but it should free the pointer since the memory is allocated by ADL call back function. 
///   [out] lpNumSLSOffset         Pointer to a variable that will receive the number of the SLS offset supported by the SLS configuration. 
///   [out] lppSLSOffset           Pointer of a pointer to a variable that contains the SLS offsets. the data type is ADLSLSOffset. Application does not need to allocate memory but it should free the pointer since the memory is allocated by ADL call back function. 
///   [in]  iOption                Specifies the layout type of SLS grid data. It is bit vector. There are two types of SLS layout:s, relative to landscape (ref \ADL_DISPLAY_SLSGRID_CAP_OPTION_RELATIVETO_LANDSCAPE) and relative to current angle (ref \ADL_DISPLAY_SLSGRID_CAP_OPTION_RELATIVETO_CURRENTANGLE). 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes
/// 
/// Remarks
///   This API uses the memory allocation callback function provided by the user.
int ADL2_Display_SLSMapConfigX2_Get ( ADL_CONTEXT_HANDLE       context,
                                      int                      iAdapterIndex,
                                      int                      iSLSMapIndex,
                                      ADLSLSMap *              lpSLSMap,
                                      int *                    lpNumSLSTarget,
                                      ADLSLSTarget **          lppSLSTarget,
                                      int *                    lpNumNativeMode,
                                      ADLSLSMode **            lppNativeMode,
                                      int *                    lpNumNativeModeOffsets,
                                      ADLSLSOffset **          lppNativeModeOffsets,
                                      int *                    lpNumBezelMode,
                                      ADLBezelTransientMode ** lppBezelMode,
                                      int *                    lpNumTransientMode,
                                      ADLBezelTransientMode ** lppTransientMode,
                                      int *                    lpNumSLSOffset,
                                      ADLSLSOffset **          lppSLSOffset,
                                      int                      iOption
                                    );


/// Function to get the SLS map index for a given adapter and a given display device. 
/// 
/// This function to get a SLS map index based on a group of displays that are connected in the given adapter. The driver only searches the active SLS grid database. 
/// Supported Platforms:
///   Windows 7, 10 and above; 32bit and 64bit 
/// 
/// Parameters
///   [in]  context              Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in]  iAdapterIndex        The ADL index of the desired adapter. This function does not support -1. 
///   [in]  iADLNumDisplayTarget Specifies the number of input displays. 
///   [in]  lpDisplayTarget      Array of displays that are used to do the query. The array type is ADLDisplayTarget. 
///   [out]
int ADL2_Display_SLSMapIndex_Get ( ADL_CONTEXT_HANDLE context,
                                   int                iAdapterIndex,
                                   int                iADLNumDisplayTarget,
                                   ADLDisplayTarget * lpDisplayTarget,
                                   int *              lpSLSMapIndex
                                 );


/// Function to get the active SLS map index list for a given GPU. 
/// 
/// This function retrieves a list of active SLS map indexes for a specified input GPU. 
/// Supported Platforms:
///   Windows 7, 10 and above; 32bit and 64bit 
/// 
/// Parameters
///   [in]  context              Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in]  iAdapterIndex        The ADL index of the desired adapter. This function does not support -1. 
///   [out] lpNumSLSMapIndexList Pointer to a variable that will receive the number of elements in active SLS maps index list. 
///   [out] lppSLSMapIndexList   Pointer of a pointer to a variable with type of integer array. The integer array stores all active SLS map indexes. Application does not need to allocate memory, but it should free the memory since the memory is allocated by ADL call back function. 
///   [in]  iOptions             Bit vector, specifies the type of SLS map. Currently only ADL_DISPLAY_SLSMAPINDEXLIST_OPTION_ACTIVE is supported. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes
/// 
/// Remarks
///   The driver does not support the return of all SLS grids. It only supports all active SLS grids. Therefore 0x00000001 is the only valid value for iOption.
int ADL2_Display_SLSMapIndexList_Get ( ADL_CONTEXT_HANDLE context,
                                       int                iAdapterIndex,
                                       int *              lpNumSLSMapIndexList,
                                       int **             lppSLSMapIndexList,
                                       int                iOptions
                                     );


/// Get SLS middle mode for specific adapter. 
/// Supported Platforms:
///   Windows 7, 10 and above; 32bit and 64bit 
/// 
/// Parameters
///   [in]  context                     Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in]  iAdapterIndex               The ADL index of the desired adapter. This function does not support -1. 
///   [in]  iSLSMapIndex                The SLS map index of the desired adapter. 
///   [out] lpMiddleModeSupported       If SLS middle mode is supported or not. 1: supported; otherwise: not supported. 
///   [out] lpMaxNumMiddleModeToSet     The maximum number of SLS middle modes is allowed to be set. 
///   [out] lpNumAvailableSLSMiddlemode Pointer to a variable that will receive the number of elements in a Available SLS middle mode list. 
///   [out] lppAvailableSLSMiddlemode   Pointer of a pointer to a variable that contains the Available SLS middle modes. the data type is ADLSLSMode. 
///   [out] lpNumCurrentSLSMiddleMode   Pointer to a variable that will receive the number of elements in a Current SLS middle mode list. 
///   [out] lppCurrentSLSMiddleMode     Pointer of a pointer to a variable that contains the Current SLS middle modes. the data type is ADLSLSMode. 
///   [out] lpNumDefaultSLSMiddleMode   Pointer to a variable that will receive the number of elements in a Default SLS middle mode list. 
///   [out] lppDefaultSLSMiddleMode     Pointer of a pointer to a variable that contains the Default SLS middle modes. the data type is ADLSLSMode. 
///   [in]  iOption                     Specifies the layout type of SLS grid data. It is bit vector. There are two types of SLS layouts, relative to landscape (ref \ADL_DISPLAY_SLSGRID_CAP_OPTION_RELATIVETO_LANDSCAPE) and relative to current angle (ref \ADL_DISPLAY_SLSGRID_CAP_OPTION_RELATIVETO_CURRENTANGLE). 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes
/// 
/// Remarks
///   1. Currently only support one current and one default middle mode.
/// This API uses the memory allocation callback function provided by the user.
int ADL2_Display_SLSMiddleMode_Get ( ADL_CONTEXT_HANDLE context,
                                     int                iAdapterIndex,
                                     int                iSLSMapIndex,
                                     int *              lpMiddleModeSupported,
                                     int *              lpMaxNumMiddleModeToSet,
                                     int *              lpNumAvailableSLSMiddleMode,
                                     ADLSLSMode **      lppAvailableSLSMiddleMode,
                                     int *              lpNumCurrentSLSMiddleMode,
                                     ADLSLSMode **      lppCurrentSLSMiddleMode,
                                     int *              lpNumDefaultSLSMiddleMode,
                                     ADLSLSMode **      lppDefaultSLSMiddleMode,
                                     int                iOption
                                   );


/// Set SLS middle mode for specific adapter. 
/// Supported Platforms:
///   Windows 7, 10 and above; 32bit and 64bit 
/// 
/// Parameters
///   [in] context                  Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in] iAdapterIndex            The ADL index of the desired adapter. This function does not support -1. 
///   [in] iSLSMapIndex             The SLS map index of the desired adapter. 
///   [in] iNumCurrentSLSMiddleMode The number of elements in a Current SLS middle mode list to be set. 
///   [in] lpCurrentSLSMiddleMode   Pointer of a variable that contains the Current SLS middle modes. the data type is ADLSLSMode. 
///   [in] iOption                  Specifies the layout type of SLS grid data. It is bit vector. There are two types of SLS layouts, relative to landscape (ref \ADL_DISPLAY_SLSGRID_CAP_OPTION_RELATIVETO_LANDSCAPE) and relative to current angle (ref \ADL_DISPLAY_SLSGRID_CAP_OPTION_RELATIVETO_CURRENTANGLE). 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes
/// 
/// Remarks
///   1. Currently only support one current/default middle mode.
/// Driver may returns CWDDE_OK_MODE_SET_NEEDED and CWDDE_ERR_BAD_MIDDLE_MODE.
/// for return code CWDDE_OK_MODE_SET_NEEDED, ADL needs to do Mode Set in order to make newly set middle mode replacing the old one.
/// for return code CWDDE_ERR_BAD_MIDDLE_MODE, ADL returns ADL_FAIL.
int ADL2_Display_SLSMiddleMode_Set ( ADL_CONTEXT_HANDLE context,
                                     int                iAdapterIndex,
                                     int                iSLSMapIndex,
                                     int                iNumCurrentSLSMiddleMode,
                                     ADLSLSMode *       lpCurrentSLSMiddleMode,
                                     int                iOption
                                   );


/// Function to Get an SLS records from the driver database. 
/// 
/// This function to Get an SLS records from the driver database. 
/// Supported Platforms:
///   Windows 7, 10 and above; 32bit and 64bit 
/// 
/// Parameters
///   [in]  context        Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in]  iAdapterIndex  The ADL index of the desired adapter. This function does not support -1. 
///   [in]  displayID      The desired display index. It can be retrieved from the ADLDisplayInfo data structure. 
///   [out] lpNumOfRecords gets the number of SLS Grids for the given adapter and display 
///   [out] lppGridIDList  gets the SLS Grid IDs for the given adapter and display 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes 
/// 
/// Remarks
///   Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call ADL2_Main_Control_Create first to obtain ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using ADL2_Main_Control_Destroy.
int ADL2_Display_SLSRecords_Get ( ADL_CONTEXT_HANDLE context,
                                  int                iAdapterIndex,
                                  ADLDisplayID       displayID,
                                  int *              lpNumOfRecords,
                                  int **             lppGridIDList
                                );


/// Supported Platforms:
///   Windows 7, 10 and above; 32bit and 64bit 
/// 
/// Parameters
///   [in] context       Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in] iAdapterIndex The index of the desired adapter. 
///   [in] iStatus       ADL_TRUE ADL_FALSE 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK (zero). Otherwise the return value is an ADL error code (non-zero). Result Codes
/// 
/// Remarks
///   Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call ADL2_Main_Control_Create first to obtain ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using ADL2_Main_Control_Destroy.
int ADL2_MGPUSLS_Status_Set ( ADL_CONTEXT_HANDLE context,
                              int                iAdapterIndex,
                              int                iStatus
                            );


/// Function to set the Registry key "UnsupportedMonitorModesAllowed" when 10bit Pixel format is enabled from workstation aspect. 
/// 
/// This function sets the above registry key to 1. 
/// Supported Platforms:
///   \Win7 
/// 
/// Parameters
///   [in] context       Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in] iAdapterIndex The ADL index handle of the desired adapter. 
/// 
/// Returns
///   If the function is successful, ADL_OK is returned. If iAdapterIndex is an invalid adapter index, ADL_ERR_INVALID_ADL_IDX is returned.
/// If the function is not supported, ADL_ERR_NOT_SUPPORTED is returned. For all other errors, ADL_ERR is returned. 
/// 
/// Remarks
///   Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call ADL2_Main_Control_Create first to obtain ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using ADL2_Main_Control_Destroy.
int ADL2_Workstation_EnableUnsupportedDisplayModes ( ADL_CONTEXT_HANDLE context,
                                                     int                iAdapterIndex
                                                   );


/// Function to retrieve the adapter display manner capabilities based on ADL index. 
/// 
/// This function retrieves the adapter display manner capabilities (e.g., single, clone, extended desktop, and stretch mode). 
/// Supported Platforms:
///   Windows 7, 10 and above; 32bit and 64bit 
/// 
/// Parameters
///   [in]  iAdapterIndex         The ADL index handle of the desired adapter. A value of -1 returns all adapter manner information for the system across all GPUs. 
///   [out] lpNumDisplayCaps      The Number of display manner capabilities. 
///   [out] lppAdapterDisplayCaps The lists of display manner capabilities across all GPUs. Refer to the ADLAdapterDisplayCap structure for more information. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes
/// 
/// Remarks
///   This API uses the memory allocation callback function provided by the user.
int ADL_Adapter_Display_Caps ( int                     iAdapterIndex,
                               int *                   lpNumDisplayCaps,
                               ADLAdapterDisplayCap ** lppAdapterDisplayCaps
                             );


/// Function to retrieve the number of Activatable sources based on ADL Index. 
/// 
/// This function retrieves the activatable sources list for a specified input adapter. ActivatableSources is the number of displays that can be turned on simultaneously for the same GPU. For example, for AMD Radeon HD 4xxx Series and earlier this number is 2 while for ATI Radeon HD 5xxx Series the number could be 6 or 4. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in]  iAdapterIndex The ADL index handle of the desired adapter. 
///   [out] lpNumSources  The pointer to the number of sources that can be activated. 
///   [out] lppSources    The pointer to the pointer to the retrieved activatable sources buffer. Refer to the ADLActivatableSource structure for more information. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes
/// 
/// Remarks
///   This API uses the memory allocation callback function provided by the user.
int ADL_Adapter_NumberOfActivatableSources_Get ( int                     iAdapterIndex,
                                                 int *                   lpNumSources,
                                                 ADLActivatableSource ** lppSources
                                               );


/// Set SLS bezel offsets for each display index. 
/// Supported Platforms:
///   Windows 7, 10 and above; 32bit and 64bit 
/// 
/// Parameters
///   [in] iAdapterIndex   The ADL index of the desired adapter. This function does not support -1. 
///   [in] iSLSMapIndex    The SLS map index to apply bezel offset. 
///   [in] iNumBezelOffset input size of the SLS offset per display per mode array. 
///   [in] lpBezelOffset   List of SLS offset information, refer to ADLBezelOffset struct. 
///   [in] SLSMap          The display SLS map information. Refer to the ADLSLSMap structure for more information. 
///   [in] iOption         Option to set bezel offset. Default: ADL_DISPLAY_BEZELOFFSET_COMMIT 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes
/// 
/// Remarks
///   Call ADL_Flush_Driver_Data() after to persist settings on reboot.
int ADL_Display_BezelOffset_Set ( int            iAdapterIndex,
                                  int            iSLSMapIndex,
                                  int            iNumBezelOffset,
                                  LPADLSLSOffset lpBezelOffset,
                                  ADLSLSMap      SLSMap,
                                  int            iOption
                                );


/// Get bezel offset stepping size for the input adapter. 
/// Supported Platforms:
///   Windows 7, 10 and above; 32bit and 64bit 
/// 
/// Parameters
///   [in]  iAdapterIndex                 The ADL index of the desired adapter. This function does not support -1. 
///   [out] iNumBezelOffsetSteppingSize   The number of Bezel offset stepping size per adapter. 
///   [out] lppBezelOffsetSteppingSizeint Bezel offset stepping size information. Refer to ADLBezelOffsetSteppingSize struct. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes
int ADL_Display_BezelOffsetSteppingSize_Get ( int                           iAdapterIndex,
                                              int *                         lpNumBezelOffsetSteppingSize,
                                              ADLBezelOffsetSteppingSize ** lppBezelOffsetSteppingSize
                                            );


/// Validate the list of the SLS display configurations to determine if bezel is supported or not. 
/// Supported Platforms:
///   Windows 7, 10 and above; 32bit and 64bit 
/// 
/// Parameters
///   [in]  iAdapterIndex             The ADL index of the desired adapter. This function does not support -1. 
///   [in]  iNumPossibleSLSMap        Input size of SLS map to be validated. 
///   [in]  lpPossibleSLSMaps         List of possible SLS maps to be validated. 
///   [out] lpNumPossibleSLSMapResult Size of the valid array. 
///   [out] lppPossibleMapResult      valid result list. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes
int ADL_Display_BezelSupported_Validate ( int                      iAdapterIndex,
                                          int                      iNumPossibleSLSMap,
                                          LPADLPossibleSLSMap      lpPossibleSLSMaps,
                                          int *                    lpNumPossibleSLSMapResult,
                                          LPADLPossibleMapResult * lppPossibleMapResult
                                        );


/// Function to retrieve current display map configurations. 
/// 
/// This function retrieves the current display map configurations, including the controllers and adapters mapped to each display. 
/// Supported Platforms:
///   Windows 7, 10 and above; 32bit and 64bit 
/// 
/// Parameters
///   [in]  iAdapterIndex      The ADL index handle of the desired adapter. A value of -1 returns all display configurations for the system across multiple GPUs. 
///   [out] lpNumDisplayMap    The pointer to the number of retrieved display maps. 
///   [out] lppDisplayMap      The pointer to the pointer to the display manner information. Refer to the ADLDisplayMap structure for more information. 
///   [out] lpNumDisplayTarget The pointer to the display target sets retrieved. 
///   [out] lppDisplayTarget   The pointer to the pointer to the display target buffer. Refer to the ADLDisplayTarget structure for more information. 
///   [in]  iOptions           The function option. ADL_DISPLAY_DISPLAYMAP_OPTION_GPUINFO. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes
/// 
/// Remarks
///   This API uses the memory allocation callback function provided by the user.
int ADL_Display_DisplayMapConfig_Get ( int                 iAdapterIndex,
                                       int *               lpNumDisplayMap,
                                       ADLDisplayMap **    lppDisplayMap,
                                       int *               lpNumDisplayTarget,
                                       ADLDisplayTarget ** lppDisplayTarget,
                                       int                 iOptions
                                     );


/// Function to validate a list of display configurations. 
/// 
/// This function allows the user to input a potential displays map and its targets. The function can also be used to obtain a list of display targets that can be added to this given topology and a list of display targets that can be removed from this given topology. 
/// Supported Platforms:
///   Windows 7, 10 and above; 32bit and 64bit 
/// 
/// Parameters
///   [in]  iAdapterIndex             The ADL index handle of the desired adapter. This function does not support the -1 value to test topologies across multiple GPUs. 
///   [in]  iNumDisplayMap            The number of display maps in this configuration. 
///   [in]  lpDisplayMap              The pointer to the display map information. Refer to the ADLDisplayMap structure for more information. 
///   [in]  iNumDisplayTarget         The number of display target sets in this configuration. 
///   [in]  lpDisplayTarget           The pointer to the display target information. Refer to the ADLDisplayTarget structure for more information. 
///   [out] lpNumPossibleAddTarget    The pointer to the number of items in the array of lppPossibleAddTarget. 
///   [out] lppPossibleAddTarget      The pointer to the array of the display targets that can be added in the given topology. Refer to the ADLDisplayTarget structure for more information. The user is responsible for freeing the memory for this array when it is no longer needed. 
///   [out] lpNumPossibleRemoveTarget The pointer to the number of items in the array of lppPossibleRemoveTarget. 
///   [out] lppPossibleRemoveTarget   The pointer to the array of the display targets that can be removed from the given topology. Refer to the ADLDisplayTarget structure for more information. The user is responsible for freeing the memory for this array when it is no longer needed. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes
/// 
/// Remarks
///   This API uses the memory allocation callback function provided by the user.
int ADL_Display_DisplayMapConfig_PossibleAddAndRemove ( int                 iAdapterIndex,
                                                        int                 iNumDisplayMap,
                                                        ADLDisplayMap *     lpDisplayMap,
                                                        int                 iNumDisplayTarget,
                                                        ADLDisplayTarget *  lpDisplayTarget,
                                                        int *               lpNumPossibleAddTarget,
                                                        ADLDisplayTarget ** lppPossibleAddTarget,
                                                        int *               lpNumPossibleRemoveTarget,
                                                        ADLDisplayTarget ** lppPossibleRemoveTarget
                                                      );


/// Function to set the current display configuration. 
/// 
/// This function sets the current display configurations for each display, including the controller and adapter mapped to each display. Possible display configurations are single, clone, extended desktop, and stretch mode. If clone mode is desired and the current display configuration is extended desktop mode, the function disables extended desktop mode in order to enable clone mode. If extended display mode is desired and the current display configuration is single mode, this function enables extended desktop. 
/// Supported Platforms:
///   Windows 7, 10 and above; 32bit and 64bit 
/// 
/// Parameters
///   [in] iAdapterIndex     The ADL index handle of the desired adapter. A value of -1 sets the displays in the system across multiple GPUs. 
///   [in] iNumDisplayMap    The number of display maps to be set. 
///   [in] lpDisplayMap      The pointer to the retrieved display map information. Refer to the ADLDisplayMap structure for more information. 
///   [in] iNumDisplayTarget The number of display target sets to be set. 
///   [in] lpDisplayTarget   The pointer to the display target information. Refer to the ADLDisplayTarget structure for more information. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes
/// 
/// Remarks
///   This API uses the memory allocation callback function provided by the user.
int ADL_Display_DisplayMapConfig_Set ( int                iAdapterIndex,
                                       int                iNumDisplayMap,
                                       ADLDisplayMap *    lpDisplayMap,
                                       int                iNumDisplayTarget,
                                       ADLDisplayTarget * lpDisplayTarget
                                     );


/// Function to validate the list of the display configurations based on ADL Index. 
/// 
/// This function validate the list of the display configurations for a specified input adapter. This function is applicable to all OS platforms. 
/// Supported Platforms:
///   Windows 7, 10 and above; 32bit and 64bit 
/// 
/// Parameters
///   [in]  iAdapterIndex          The ADL index handle of the desired adapter. 
///   [in]  iNumPossibleMap        The number of possible maps to be validated. 
///   [in]  lpPossibleMaps         The list of possible maps to be validated. Refer to the ADLPossibleMap structure for more information. 
///   [out] lpNumPossibleMapResult The pointer to the number of validate result list. 
///   [out] lppPossibleMapResult   The pointer to the pointer to validation result list. Refer to the ADLPossibleMapResult structure for more information. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes
/// 
/// Remarks
///   This API uses the memory allocation callback function provided by the user.
int ADL_Display_DisplayMapConfig_Validate ( int                     iAdapterIndex,
                                            int                     iNumPossibleMap,
                                            ADLPossibleMap *        lpPossibleMaps,
                                            int *                   lpNumPossibleMapResult,
                                            ADLPossibleMapResult ** lppPossibleMapResult
                                          );


/// Function to retrieve the forcible connected status of a display. 
/// 
/// This function determines whether or not a display (i.e. CV) is set to be forcibly connected. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in]  iAdapterIndex The ADL index handle of the desired adapter. 
///   [in]  iDisplayIndex The desired display index. 
///   [out] lpStatus      The forcible connected status of the display. ADL_TRUE : forced connected; ADL_FALSE : otherwise. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes
/// 
/// Remarks
///   A display can be forcibly connected without being actually connected or not recognized as connected. For example, some old 50 ohm TVs are not detected properly and need to be forcibly connected in order to be turned on.
int ADL_Display_ForcibleDisplay_Get ( int   iAdapterIndex,
                                      int   iDisplayIndex,
                                      int * lpStatus
                                    );


/// Function to set the forcible connected status of a display. 
/// 
/// This function sets a display (i.e. TV) to be either forcibly connected or not forcibly connected. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in] iAdapterIndex The ADL index handle of the desired adapter. 
///   [in] iDisplayIndex The desired display index. 
///   [in] iStatus       The desired connection status. ADL_TRUE : forced connected; ADL_FALSE : otherwise. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes
/// 
/// Remarks
///   A display can be forcibly connected without being actually connected or not recognized as connected. For example, some old 50 ohm TVs are not detected properly and need to be forcibly connected in order to be turned on.
int ADL_Display_ForcibleDisplay_Set ( int iAdapterIndex,
                                      int iDisplayIndex,
                                      int iStatus
                                    );


/// Function to retrieve the display mode information. 
/// 
/// This function retrieves the current display mode information. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in]  iAdapterIndex The ADL index handle of the desired adapter. A value of -1 retrieves all modes for the system across multiple GPUs. 
///   [in]  iDisplayIndex The desired display index. If the index is -1, this field is ignored. 
///   [out] lpNumModes    The pointer to the number of modes retrieved. 
///   [out] lppModes      The pointer to the pointer to the retrieved display modes. Refer to the Display ADLMode structure for more information. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes
/// 
/// Remarks
///   This API uses the memory allocation callback function provided by the user.
int ADL_Display_Modes_Get ( int        iAdapterIndex,
                            int        iDisplayIndex,
                            int *      lpNumModes,
                            ADLMode ** lppModes
                          );


/// Function to set display mode information. 
/// 
/// This function sets the current display mode information. 
/// Supported Platforms:
///   Windows 7, 10 and above; 32bit and 64bit 
/// 
/// Parameters
///   [in] iAdapterIndex The ADL index handle of the desired adapter. A value of -1 sets the modes across multiple GPUs. 
///   [in] iDisplayIndex The desired display index. If the index is -1, this field is ignored. 
///   [in] iNumModes     The number of modes to be set. 
///   [in] lpModes       The pointer to the display mode information to be set. Refer to the ADLMode structure for more information. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes
/// 
/// Remarks
///   Call ADL_Flush_Driver_Data() after to persist settings on reboot.
int ADL_Display_Modes_Set ( int       iAdapterIndex,
                            int       iDisplayIndex,
                            int       iNumModes,
                            ADLMode * lpModes
                          );


/// Set SLS overlap offsets for each display index. 
/// Supported Platforms:
///   Windows 7; 32bit and 64bit and above 
/// 
/// Parameters
///   [in] iAdapterIndex       The ADL index of the desired adapter. This function does not support -1. 
///   [in] iSLSMapIndex        The SLS map index to apply overlap offset. 
///   [in] iNumOverlappedModes the no. of overlapped modes defined. Each such mode refers to a set of targets in the array of targets 
///   [in] lpOverlappedModes   the list of overlapped modes defined 
///   [in] iNumTargetOffsets   the no. of targets in the list of targets 
///   [in] lpTargetOffsets     the list of target offsets for all the overlap modes defined 
///   [in] SLSMap              The display SLS map information. Refer to the ADLSLSMap structure for more information. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes
/// 
/// Remarks
///   Call ADL_Flush_Driver_Data() after to persist settings on reboot.
int ADL_Display_Overlap_Set ( int                   iAdapterIndex,
                              int                   iSLSMapIndex,
                              int                   iNumOverlappedModes,
                              LPADLSLSTargetOverlap lpOverlappedModes,
                              int                   iNumTargetOffsets,
                              LPADLSLSOffset        lpTargetOffsets,
                              ADLSLSMap             SLSMap
                            );


/// Function to retrieve the possible display mappings. 
/// 
/// This function retrieves possible display mappings for an adapter. 
/// Supported Platforms:
///   Windows 7, 10 and above; 32bit and 64bit 
/// 
/// Parameters
///   [in]  iAdapterIndex                     The ADL index handle of the desired adapter. 
///   [in]  iNumberOfPresetMapping            The current number of preset mappings from the lpPresetMappings array. 
///   [in]  lpPresetMappings                  The pointer to the buffer storing the current preset mappings. Refer to the ADLPossibleMapping structure for more information. 
///   [in]  iEnquiryControllerIndex           The desired controller index for mapping. 
///   [out] lpNumberOfEnquiryPossibleMappings The pointer to the number of possible mappings from the lppEnquiryPossibleMappings array. 
///   [out] lppEnquiryPossibleMappings        The pointer to the pointer to the retrieved possible mapping buffer. Refer to the ADLPossibleMapping structure for more information. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes
/// 
/// Remarks
///   This API uses the memory allocation callback function provided by the user.
int ADL_Display_PossibleMapping_Get ( int                   iAdapterIndex,
                                      int                   iNumberOfPresetMapping,
                                      ADLPossibleMapping *  lpPresetMappings,
                                      int                   iEnquiryControllerIndex,
                                      int *                 lpNumberOfEnquiryPossibleMappings,
                                      ADLPossibleMapping ** lppEnquiryPossibleMappings
                                    );


/// Function to retrieve the OS possible modes list for an adapter (all OS platforms). 
/// 
/// This function retrieves the OS possible modes list for a specified input adapter. 
/// Supported Platforms:
///   Windows 7, 10 and above; 32bit and 64bit 
/// 
/// Parameters
///   [in]  iAdapterIndex The ADL index handle of the desired adapter. 
///   [out] lpNumModes    The pointer to the number of display modes from the lppModes array. 
///   [out] lppModes      The pointer to the pointer to the retrieved possible display modes buffer. Refer to the ADLMode structure for more information. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes
/// 
/// Remarks
///   This API uses the memory allocation callback function provided by the user.
int ADL_Display_PossibleMode_Get ( int        iAdapterIndex,
                                   int *      lpNumModes,
                                   ADLMode ** lppModes
                                 );


/// Function to retrieve the ATI possible modes list for an adapter and preset mapping (Windows XP). 
/// 
/// This function retrieves the ATI possible modes list based on a specified input adapter and preset mapping. This function is applicable only on Windows XP platforms. 
/// Supported Platforms:
///   Windows XP; 32bit and 64bit 
/// 
/// Parameters
///   [in]  iAdapterIndex              The ADL index handle of the desired adapter. 
///   [in]  iNumDisplayTargets         The number of display target from the lpDisplayTargets array. 
///   [in]  lpDisplayTargets           The pointer to the retrieved display target configurations. Refer to the ADLDisplayTarget structure for more information. E.g. If a CRT and TV are on as extended mode, lpMapConfigs will contain two ADLDisplayTarget structures: one CRT and one TV, both in extended manner. 
///   [in]  iLargeDesktopSupportedType The large desktop type. Refer to the ADLLARGEDESKTOPTYPE enum for more information. 
///   [in]  iDevicePanningControl      The device panning control mode. Refer to the ADLPanningMode enum for more information. 
///   [out] lpNumModes                 The pointer to the number of modes from the lppModes array. 
///   [out] lppModes                   The pointer to the pointer to the possible display modes buffer. Refer to the ADLMode structure for more information. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes
/// 
/// Remarks
///   This API uses the memory allocation callback function provided by the user.
int ADL_Display_PossibleMode_WinXP_Get ( int                iAdapterIndex,
                                         int                iNumDisplayTargets,
                                         ADLDisplayTarget * lpDisplayTargets,
                                         int                iLargeDesktopSupportedType,
                                         int                iDevicePanningControl,
                                         int *              lpNumModes,
                                         ADLMode **         lppModes
                                       );


/// Function to get the current supported SLS grid patterns (MxN) for a GPU. 
/// 
/// This function gets a list of supported SLS grids for a specified input adapter based on display devices currently connected to the GPU. 
/// Supported Platforms:
///   Windows 7, 10 and above; 32bit and 64bit 
/// 
/// Parameters
///   [in]  iAdapterIndex The ADL index of the desired adapter. This function does not support -1. 
///   [out] lpNumSLSGrid  Pointer to a variable that will receive the number of elements in a supported SLS grid list. 
///   [out] lppSLSGrid    Pointer of a pointer to a variable with type ADLSLSGrid, which contains supported SLS grids the adapter supports. Application does not need to allocate memory but it should free the pointer since the memory is allocated by the ADL call back function. 
///   [in]  iOption       Bit vector, specifies the layout type of SLS grid data and portrait flag. There are two types of SLS layouts: relative to landscape (ref \ADL_DISPLAY_SLSGRID_CAP_OPTION_RELATIVETO_LANDSCAPE) and relative to current angle (ref \ADL_DISPLAY_SLSGRID_CAP_OPTION_RELATIVETO_CURRENTANGLE). If the current desktop associated with the input adapter is rotated to 90 or 270 degree, set bit ref \ADL_DISPLAY_SLSGRID_PORTAIT_MODE to 1. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes
/// 
/// Remarks
///   This API uses the memory allocation callback function provided by the user.
int ADL_Display_SLSGrid_Caps ( int           iAdapterIndex,
                               int *         lpNumSLSGrid,
                               ADLSLSGrid ** lppSLSGrid,
                               int           iOption
                             );


/// Function to create an SLS configuration. 
/// 
/// This function creates an SLS configuration with a given grid, targets, and bezel mode percent. It will output an SLS map index if the SLS map is successfully created. 
/// Supported Platforms:
///   Windows 7, 10 and above; 32bit and 64bit 
/// 
/// Parameters
///   [in]  iAdapterIndex     The ADL index of the desired adapter. This function does not support -1. 
///   [in]  SLSMap            Specifies the display SLS map data that contains SLS grid and orientation information. Its type is ADLSLSMap 
///   [in]  iNumTargetTarget  Specifies the number of displays to be used to create an SLS. 
///   [in]  lpSLSTarget       Array of displays that are used to create an SLS. The data type is ADLSLSTarget. 
///   [in]  iBezelModePercent Specifies the bezel mode percent. If these displays do not support bezel, set it to 0. 
///   [out] lpSLSMapIndex     Pointer to a variable that will receive the new created SLS map index. If an SLS grid failed to create, its value is -1, other wise, it is non-negative integer. 
///   [in]  iOption           Specifies the layout type of SLS grid data. It is bit vector. There are two types of SLS layouts,: relative to landscape (ref \ADL_DISPLAY_SLSGRID_CAP_OPTION_RELATIVETO_LANDSCAPE) and relative to current angle (ref \ADL_DISPLAY_SLSGRID_CAP_OPTION_RELATIVETO_CURRENTANGLE). 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes
/// 
/// Remarks
///   Call ADL_Flush_Driver_Data() after to persist settings on reboot.
int ADL_Display_SLSMapConfig_Create ( int            iAdapterIndex,
                                      ADLSLSMap      SLSMap,
                                      int            iNumTargetTarget,
                                      ADLSLSTarget * lpSLSTarget,
                                      int            iBezelModePercent,
                                      int *          lpSLSMapIndex,
                                      int            iOption
                                    );


/// Function to delete an SLS map from the driver database. 
/// 
/// This function deletes an SLS map from the driver database based on the input SLS map index. 
/// Supported Platforms:
///   Windows 7, 10 and above; 32bit and 64bit 
/// 
/// Parameters
///   [in] iAdapterIndex The ADL index of the desired adapter. This function does not support -1. 
///   [in] iSLSMapIndex  Specifies the SLS map index to be deleted. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes
/// 
/// Remarks
///   Call ADL_Flush_Driver_Data() after to persist settings on reboot.
int ADL_Display_SLSMapConfig_Delete ( int iAdapterIndex,
                                      int iSLSMapIndex
                                    );


/// Function to retrieve an SLS configuration. 
/// 
/// This function retrieves an SLS configuration, which includes the, SLS map, SLS targets, SLS standard modes, bezel modes or a transient mode, and offsets. 
/// Supported Platforms:
///   Windows 7, 10 and above; 32bit and 64bit 
/// 
/// Parameters
///   [in]  iAdapterIndex         Specifies the adapter to be queried. This function does not support -1. 
///   [in]  iSLSMapIndex          Specifies the SLS map index to be queried. 
///   [out] lpSLSMap              Pointer to a variable that contains the SLS map data. The data type is ADLSLSMap. 
///   [out] lpNumSLSTarget        Pointer to variable that will receive the number of targets in the SLS map. 
///   [out] lppSLSTarget          Pointer of a pointer to a variable that conations targets in the SLS map. the data type is ADLDisplayTarget Application does not need to allocate memory but it should free the pointer since the memory is allocated by ADL call back function. 
///   [out] lpNumSLSNativeMode    Pointer to a variable that will receive the number of native SLS modes supported by the SLS configuration. 
///   [out] lppSLSNativeMode      Pointer of a pointer to a variable that contains the native SLS modes. the data type is ADLSLSMode. Application does not need to allocate memory but it should free the pointer since the memory is allocated by ADL call back function. 
///   [out] lpNumSLSBezelMode     Pointer to a variable that will receive the number of the bezel modes supported by the SLS configuration. 
///   [out] lppSLSbezelMode       Pointer of a pointer to a variable that contains the bezel SLS modes. the data type is ADLSLSMode. Application does not need to allocate memory but it should free the pointer since the memory is allocated by ADL call back function. 
///   [out] lpNumSLSTransientMode Pointer to a variable that will receive the number of the transient modes supported by the SLS configuration. 
///   [out] lppTransientMode      Pointer of a pointer to a variable that contains the transient SLS modes. the data type is ADLSLSMode. Application does not need to allocate memory but it should free the pointer since the memory is allocated by ADL call back function. 
///   [out] lpNumSLSOffset        Pointer to a variable that will receive the number of the SLS offset supported by the SLS configuration. 
///   [out] lppSLSOffset          Pointer of a pointer to a variable that contains the SLS offsets. the data type is ADLSLSOffset. Application does not need to allocate memory but it should free the pointer since the memory is allocated by ADL call back function. 
///   [in]  iOption               Specifies the layout type of SLS grid data. It is bit vector. There are two types of SLS layout:s, relative to landscape (ref \ADL_DISPLAY_SLSGRID_CAP_OPTION_RELATIVETO_LANDSCAPE) and relative to current angle (ref \ADL_DISPLAY_SLSGRID_CAP_OPTION_RELATIVETO_CURRENTANGLE). 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes
/// 
/// Remarks
///   This API uses the memory allocation callback function provided by the user.
int ADL_Display_SLSMapConfig_Get ( int                      iAdapterIndex,
                                   int                      iSLSMapIndex,
                                   ADLSLSMap *              lpSLSMap,
                                   int *                    lpNumSLSTarget,
                                   ADLSLSTarget **          lppSLSTarget,
                                   int *                    lpNumNativeMode,
                                   ADLSLSMode **            lppNativeMode,
                                   int *                    lpNumBezelMode,
                                   ADLBezelTransientMode ** lppBezelMode,
                                   int *                    lpNumTransientMode,
                                   ADLBezelTransientMode ** lppTransientMode,
                                   int *                    lpNumSLSOffset,
                                   ADLSLSOffset **          lppSLSOffset,
                                   int                      iOption
                                 );


/// Function to rearrange display orders in an SLS map. 
/// 
/// This function changes the display orders in an SLS map in order to make the image show on the displays correctly. 
/// Supported Platforms:
///   Windows 7, 10 and above; 32bit and 64bit 
/// 
/// Parameters
///   [in] iAdapterIndex Specifies the adapter to be operated on. This function does not support -1. 
///   [in] iSLSMapIndex  Specifies the SLS map index that will need to do rearrangement 
///   [in] iNumSLSTarget Specifies the number of displays in the SLS map. 
///   [in] lpSLSTarget   Array of displays that are in the SLS map. 
///   [in] slsMap        Specifies the SLS map info. Its type is ADLSLSMap. The only needed data is the map orientation. All others are ignored by the function. 
/// 
///   [in] iOption       Specifies the layout type of SLS grid data. It is bit vector. There are two types of SLS layouts, relative to landscape (ref \ADL_DISPLAY_SLSGRID_CAP_OPTION_RELATIVETO_LANDSCAPE) and relative to current angle (ref \ADL_DISPLAY_SLSGRID_CAP_OPTION_RELATIVETO_CURRENTANGLE). 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes
int ADL_Display_SLSMapConfig_Rearrange ( int            iAdapterIndex,
                                         int            iSLSMapIndex,
                                         int            iNumDisplayTarget,
                                         ADLSLSTarget * lpSLSTarget,
                                         ADLSLSMap      slsMap,
                                         int            iOption
                                       );


/// Function to enable/disable SLS bind. 
/// 
/// This function enables or disables an SLS bind 
/// Supported Platforms:
///   Windows 7, 10 and above; 32bit and 64bit 
/// 
/// Parameters
///   [in] iAdapterIndex The ADL index of the desired adapter. This function does not support -1. 
///   [in] iSLSMapIndex  Specifies the SLS map index to be deleted. 
///   [in] iState        Specifies the action type. To enable SLS map, sets it to ADL_TRUE. Otherwise set it to ADL_FASLE. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes
/// 
/// Remarks
///   Call ADL_Flush_Driver_Data() after to persist settings on reboot.
int ADL_Display_SLSMapConfig_SetState ( int iAdapterIndex,
                                        int iSLSMapIndex,
                                        int iState
                                      );


/// Function to retrieve an SLS configuration. 
/// 
/// This function retrieves an SLS configuration, which includes the, SLS map, SLS targets, SLS standard modes, bezel modes or a transient mode, and offsets. 
/// Supported Platforms:
///   Windows 7, 10 and above; 32bit and 64bit 
/// 
/// Parameters
///   [in]  iAdapterIndex          Specifies the adapter to be queried. This function does not support -1. 
///   [in]  iSLSMapIndex           Specifies the SLS map index to be queried. 
///   [out] lpSLSMap               Pointer to a variable that contains the SLS map data. The data type is ADLSLSMap. 
///   [out] lpNumSLSTarget         Pointer to variable that will receive the number of targets in the SLS map. 
///   [out] lppSLSTarget           Pointer of a pointer to a variable that conations targets in the SLS map. the data type is ADLDisplayTarget Application does not need to allocate memory but it should free the pointer since the memory is allocated by ADL call back function. 
///   [out] lpNumSLSNativeMode     Pointer to a variable that will receive the number of native SLS modes supported by the SLS configuration. 
///   [out] lppSLSNativeMode       Pointer of a pointer to a variable that contains the native SLS modes. the data type is ADLSLSMode. Application does not need to allocate memory but it should free the pointer since the memory is allocated by ADL call back function. 
///   [out] lpNumNativeModeOffsets Pointer to a variable that will receive the number of native SLS mode offsets supported by the SLS configuration. 
///   [out] lppNativeModeOffsets   Pointer of a pointer to a variable that contains the native SLS mode offsets. the data type is ADLSLSOffset. Application does not need to allocate memory but it should free the pointer since the memory is allocated by ADL call back function. 
///   [out] lpNumSLSBezelMode      Pointer to a variable that will receive the number of the bezel modes supported by the SLS configuration. 
///   [out] lppSLSbezelMode        Pointer of a pointer to a variable that contains the bezel SLS modes. the data type is ADLSLSMode. Application does not need to allocate memory but it should free the pointer since the memory is allocated by ADL call back function. 
///   [out] lpNumSLSTransientMode  Pointer to a variable that will receive the number of the transient modes supported by the SLS configuration. 
///   [out] lppTransientMode       Pointer of a pointer to a variable that contains the transient SLS modes. the data type is ADLSLSMode. Application does not need to allocate memory but it should free the pointer since the memory is allocated by ADL call back function. 
///   [out] lpNumSLSOffset         Pointer to a variable that will receive the number of the SLS offset supported by the SLS configuration. 
///   [out] lppSLSOffset           Pointer of a pointer to a variable that contains the SLS offsets. the data type is ADLSLSOffset. Application does not need to allocate memory but it should free the pointer since the memory is allocated by ADL call back function. 
///   [in]  iOption                Specifies the layout type of SLS grid data. It is bit vector. There are two types of SLS layout:s, relative to landscape (ref \ADL_DISPLAY_SLSGRID_CAP_OPTION_RELATIVETO_LANDSCAPE) and relative to current angle (ref \ADL_DISPLAY_SLSGRID_CAP_OPTION_RELATIVETO_CURRENTANGLE). 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes
/// 
/// Remarks
///   This API uses the memory allocation callback function provided by the user.
int ADL_Display_SLSMapConfigX2_Get ( int                      iAdapterIndex,
                                     int                      iSLSMapIndex,
                                     ADLSLSMap *              lpSLSMap,
                                     int *                    lpNumSLSTarget,
                                     ADLSLSTarget **          lppSLSTarget,
                                     int *                    lpNumNativeMode,
                                     ADLSLSMode **            lppNativeMode,
                                     int *                    lpNumNativeModeOffsets,
                                     ADLSLSOffset **          lppNativeModeOffsets,
                                     int *                    lpNumBezelMode,
                                     ADLBezelTransientMode ** lppBezelMode,
                                     int *                    lpNumTransientMode,
                                     ADLBezelTransientMode ** lppTransientMode,
                                     int *                    lpNumSLSOffset,
                                     ADLSLSOffset **          lppSLSOffset,
                                     int                      iOption
                                   );


/// Function to get the SLS map index for a given adapter and a given display device. 
/// 
/// This function to get a SLS map index based on a group of displays that are connected in the given adapter. The driver only searches the active SLS grid database. 
/// Supported Platforms:
///   Windows 7, 10 and above; 32bit and 64bit 
/// 
/// Parameters
///   [in]  iAdapterIndex        The ADL index of the desired adapter. This function does not support -1. 
///   [in]  iADLNumDisplayTarget Specifies the number of input displays. 
///   [in]  lpDisplayTarget      Array of displays that are used to do the query. The array type is ADLDisplayTarget. 
///   [out]
int ADL_Display_SLSMapIndex_Get ( int                iAdapterIndex,
                                  int                iADLNumDisplayTarget,
                                  ADLDisplayTarget * lpDisplayTarget,
                                  int *              lpSLSMapIndex
                                );


/// Function to get the active SLS map index list for a given GPU. 
/// 
/// This function retrieves a list of active SLS map indexes for a specified input GPU. 
/// Supported Platforms:
///   Windows 7, 10 and above; 32bit and 64bit 
/// 
/// Parameters
///   [in]  iAdapterIndex        The ADL index of the desired adapter. This function does not support -1. 
///   [out] lpNumSLSMapIndexList Pointer to a variable that will receive the number of elements in active SLS maps index list. 
///   [out] lppSLSMapIndexList   Pointer of a pointer to a variable with type of integer array. The integer array stores all active SLS map indexes. Application does not need to allocate memory, but it should free the memory since the memory is allocated by ADL call back function. 
///   [in]  iOptions             Bit vector, specifies the type of SLS map. Currently only ADL_DISPLAY_SLSMAPINDEXLIST_OPTION_ACTIVE is supported. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes
/// 
/// Remarks
///   The driver does not support the return of all SLS grids. It only supports all active SLS grids. Therefore 0x00000001 is the only valid value for iOption.
int ADL_Display_SLSMapIndexList_Get ( int    iAdapterIndex,
                                      int *  lpNumSLSMapIndexList,
                                      int ** lppSLSMapIndexList,
                                      int    iOptions
                                    );


/// Get SLS middle mode for specific adapter. 
/// Supported Platforms:
///   Windows 7, 10 and above; 32bit and 64bit 
/// 
/// Parameters
///   [in]  iAdapterIndex               The ADL index of the desired adapter. This function does not support -1. 
///   [in]  iSLSMapIndex                The SLS map index of the desired adapter. 
///   [out] lpMiddleModeSupported       If SLS middle mode is supported or not. 1: supported; otherwise: not supported. 
///   [out] lpMaxNumMiddleModeToSet     The maximum number of SLS middle modes is allowed to be set. 
///   [out] lpNumAvailableSLSMiddlemode Pointer to a variable that will receive the number of elements in a Available SLS middle mode list. 
///   [out] lppAvailableSLSMiddlemode   Pointer of a pointer to a variable that contains the Available SLS middle modes. the data type is ADLSLSMode. 
///   [out] lpNumCurrentSLSMiddleMode   Pointer to a variable that will receive the number of elements in a Current SLS middle mode list. 
///   [out] lppCurrentSLSMiddleMode     Pointer of a pointer to a variable that contains the Current SLS middle modes. the data type is ADLSLSMode. 
///   [out] lpNumDefaultSLSMiddleMode   Pointer to a variable that will receive the number of elements in a Default SLS middle mode list. 
///   [out] lppDefaultSLSMiddleMode     Pointer of a pointer to a variable that contains the Default SLS middle modes. the data type is ADLSLSMode. 
///   [in]  iOption                     Specifies the layout type of SLS grid data. It is bit vector. There are two types of SLS layouts, relative to landscape (ref \ADL_DISPLAY_SLSGRID_CAP_OPTION_RELATIVETO_LANDSCAPE) and relative to current angle (ref \ADL_DISPLAY_SLSGRID_CAP_OPTION_RELATIVETO_CURRENTANGLE). 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes
/// 
/// Remarks
///   1. Currently only support one current and one default middle mode.
/// This API uses the memory allocation callback function provided by the user.
int ADL_Display_SLSMiddleMode_Get ( int           iAdapterIndex,
                                    int           iSLSMapIndex,
                                    int *         lpMiddleModeSupported,
                                    int *         lpMaxNumMiddleModeToSet,
                                    int *         lpNumAvailableSLSMiddleMode,
                                    ADLSLSMode ** lppAvailableSLSMiddleMode,
                                    int *         lpNumCurrentSLSMiddleMode,
                                    ADLSLSMode ** lppCurrentSLSMiddleMode,
                                    int *         lpNumDefaultSLSMiddleMode,
                                    ADLSLSMode ** lppDefaultSLSMiddleMode,
                                    int           iOption
                                  );


/// Set SLS middle mode for specific adapter. 
/// Supported Platforms:
///   Windows 7, 10 and above; 32bit and 64bit 
/// 
/// Parameters
///   [in] iAdapterIndex            The ADL index of the desired adapter. This function does not support -1. 
///   [in] iSLSMapIndex             The SLS map index of the desired adapter. 
///   [in] iNumCurrentSLSMiddleMode The number of elements in a Current SLS middle mode list to be set. 
///   [in] lpCurrentSLSMiddleMode   Pointer of a variable that contains the Current SLS middle modes. the data type is ADLSLSMode. 
///   [in] iOption                  Specifies the layout type of SLS grid data. It is bit vector. There are two types of SLS layouts, relative to landscape (ref \ADL_DISPLAY_SLSGRID_CAP_OPTION_RELATIVETO_LANDSCAPE) and relative to current angle (ref \ADL_DISPLAY_SLSGRID_CAP_OPTION_RELATIVETO_CURRENTANGLE). 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes
/// 
/// Remarks
///   1. Currently only support one current/default middle mode.
/// Driver may returns CWDDE_OK_MODE_SET_NEEDED and CWDDE_ERR_BAD_MIDDLE_MODE.
/// for return code CWDDE_OK_MODE_SET_NEEDED, ADL needs to do Mode Set in order to make newly set middle mode replacing the old one.
/// for return code CWDDE_ERR_BAD_MIDDLE_MODE, ADL returns ADL_FAIL.
int ADL_Display_SLSMiddleMode_Set ( int          iAdapterIndex,
                                    int          iSLSMapIndex,
                                    int          iNumCurrentSLSMiddleMode,
                                    ADLSLSMode * lpCurrentSLSMiddleMode,
                                    int          iOption
                                  );


/// Function to Get an SLS records from the driver database. 
/// 
/// This function to Get an SLS records from the driver database. 
/// Supported Platforms:
///   Windows 7, 10 and above; 32bit and 64bit 
/// 
/// Parameters
///   [in]  iAdapterIndex  The ADL index of the desired adapter. This function does not support -1. 
///   [in]  displayID      The desired display index. It can be retrieved from the ADLDisplayInfo data structure. 
///   [out] lpNumOfRecords gets the number of SLS Grids for the given adapter and display 
///   [out] lppGridIDList  gets the SLS Grid IDs for the given adapter and display 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes
int ADL_Display_SLSRecords_Get ( int          iAdapterIndex,
                                 ADLDisplayID displayID,
                                 int *        lpNumOfRecords,
                                 int **       lppGridIDList
                               );


/// Function to set the Registry key "UnsupportedMonitorModesAllowed" when 10bit Pixel format is enabled from workstation aspect. 
/// 
/// This function sets the above registry key to 1. 
/// Supported Platforms:
///   \Win7 
/// 
/// Parameters
///   [in] iAdapterIndex The ADL index handle of the desired adapter. 
/// 
/// Returns
///   If the function is successful, ADL_OK is returned. If iAdapterIndex is an invalid adapter index, ADL_ERR_INVALID_ADL_IDX is returned.
/// If the function is not supported, ADL_ERR_NOT_SUPPORTED is returned. For all other errors, ADL_ERR is returned.
int ADL_Workstation_EnableUnsupportedDisplayModes ( );


#endif /* ADL_HEADER_DISPLAYSMANAGER_H_ */
