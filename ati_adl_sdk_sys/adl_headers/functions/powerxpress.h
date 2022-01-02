#ifndef ADL_HEADER_POWERXPRESS_H_
#define ADL_HEADER_POWERXPRESS_H_

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

/// Function to retrieve the auto switch configuration setting for PowerXpress. This is not supported when DPPE state switching is configured. 
/// 
/// This function retrieves the auto switch configuration setting for PowerXpress. This is not supported when DPPE state switching is configured. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in]  context                 Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in]  iAdapterIndex           The ADL index handle of the desired adapter. 
///   [out] lpAutoSwitchOnACDCEvent The pointer to the switch configuration for ACDC. The returned value could be 0 or 1 
///   [out] lpAutoSwitchOnDCACEvent The pointer to the switch configuration for DCAC. The returned value could be 0 or 1 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes 
/// 
/// Remarks
///   Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call ADL2_Main_Control_Create first to obtain ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using ADL2_Main_Control_Destroy.
int ADL2_Display_PowerXpress_AutoSwitchConfig_Get ( ADL_CONTEXT_HANDLE context,
                                                    int                iAdapterIndex,
                                                    int *              lpAutoSwitchOnACDCEvent,
                                                    int *              lpAutoSwitchOnDCACEvent
                                                  );


/// Function to set the auto switch configuration setting for PowerXpress. This is not supported when DPPE state switching is configured. 
/// 
/// This function sets the auto switch configuration setting for PowerXpress. This is not supported when DPPE state switching is configured. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in] context                Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in] iAdapterIndex          The ADL index handle of the desired adapter. 
///   [in] iAutoSwitchOnACDCEvent The pointer to the value used to set the switch configuration for ACDC. Set value 0 or 1 
///   [in] iAutoSwitchOnDCACEvent The pointer to the value used to set the switch configuration for DCAC. Set value 0 or 1 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes 
/// 
/// Remarks
///   Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call ADL2_Main_Control_Create first to obtain ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using ADL2_Main_Control_Destroy.
int ADL2_Display_PowerXpress_AutoSwitchConfig_Set ( ADL_CONTEXT_HANDLE context,
                                                    int                iAdapterIndex,
                                                    int                iAutoSwitchOnACDCEvent,
                                                    int                iAutoSwitchOnDCACEvent
                                                  );


/// Function to get the active GPU in PowerXpress. 
/// 
/// This function retrieves the active GPU in PowerXpress. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in]  context       Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in]  iAdapterIndex The ADL index handle of the desired adapter. 
///   [out] lpActiveGPU   The pointer to the value storing the active GPU in PowerXpress: ADL_DL_POWERXPRESS_GPU_INTEGRATED or ADL_DL_POWERXPRESS_GPU_DISCRETE 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes 
/// 
/// Remarks
///   Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call ADL2_Main_Control_Create first to obtain ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using ADL2_Main_Control_Destroy.
int ADL2_Display_PowerXpressActiveGPU_Get ( ADL_CONTEXT_HANDLE context,
                                            int                iAdapterIndex,
                                            int *              lpActiveGPU
                                          );


/// Function to set the active GPU in PowerXpress. 
/// 
/// This function sets the active GPU in PowerXpress. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in]  context           Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in]  iAdapterIndex     The ADL index handle of the desired adapter. 
///   [in]  iActiveGPU        The value of the desired active GPU in PowerXpress: ADL_DL_POWERXPRESS_GPU_INTEGRATED or ADL_DL_POWERXPRESS_GPU_DISCRETE 
///   [out] lpOperationResult The pointer to the retrieved result of the operation. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes 
/// 
/// Remarks
///   Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call ADL2_Main_Control_Create first to obtain ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using ADL2_Main_Control_Destroy.
int ADL2_Display_PowerXpressActiveGPU_Set ( ADL_CONTEXT_HANDLE context,
                                            int                iAdapterIndex,
                                            int                iActiveGPU,
                                            int *              lpOperationResult
                                          );


/// Function to retrieve the PowerXpress version. 
/// 
/// This function retrieves the PowerXpress version. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in]  context       Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in]  iAdapterIndex The ADL index handle of the desired adapter. 
///   [out] lpVersion     The pointer to the value storing the retrieved version. 
/// 
/// Returns
///   If the system is PowerXpress capable, the function returns ADL_OK and lpVersion is always set to ADL_DL_POWERXPRESS_VERSION 
/// 
/// Remarks
///   Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call ADL2_Main_Control_Create first to obtain ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using ADL2_Main_Control_Destroy.
int ADL2_Display_PowerXpressVersion_Get ( ADL_CONTEXT_HANDLE context,
                                          int                iAdapterIndex,
                                          int *              lpVersion
                                        );


/// This function gets ancillary GPUs. 
/// 
/// In Power Express configuration system, the master GPU(Integrated GPU) can have several linked GPU which can be removed by the driver. These removable GPU are called ancillary devices. They are usually discrete GPUs in Power Express system 
/// Supported Platforms:
///   Windows 7; 32bit and 64bit 
/// 
/// Parameters
///   [in]  context                    Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in]  iAdapterIndex              The ADL index handle of the desired adapter. 
///   [out] lpNumberOfAncillaryDevices Pointer to a variable that indicates the number of ancillary devices. 
///   [out] lppRemovableDevices        Pointer of a pointer to a variable with type ADLBdf, which contains a list of ancillary devices . 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes 
/// 
/// Remarks
///   Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call ADL2_Main_Control_Create first to obtain ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using ADL2_Main_Control_Destroy.
int ADL2_PowerXpress_AncillaryDevices_Get ( ADL_CONTEXT_HANDLE context,
                                            int                iAdapterIndex,
                                            int *              lpNumberOfAncillaryDevices,
                                            ADLBdf **          lppAncillaryDevices
                                          );


/// This function gets the PowerXpress configuration Caps. 
/// 
/// This function gets the PowerXpress configuration Caps. 
/// Supported Platforms:
///   Windows 7; 32bit and 64bit Linux; 32bit and 64bit 
/// 
/// Parameters
///   [in]  context        Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in]  iAdapterIndex  The ADL index handle of the desired adapter. 
///   [out] lpPXConfigCaps The pointer to the PowerXpress config Caps returned: ADLPXConfigCaps 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes 
/// 
/// Remarks
///   Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call ADL2_Main_Control_Create first to obtain ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using ADL2_Main_Control_Destroy.
int ADL2_PowerXpress_Config_Caps ( ADL_CONTEXT_HANDLE context,
                                   int                iAdapterIndex,
                                   ADLPXConfigCaps *  lpPXConfigCaps
                                 );


/// This function gets PX configuration. 
/// 
/// In Power Express configuration system, the master GPU(Integrated GPU) can have several linked GPUs 
/// Supported Platforms:
///   Windows 7; 32bit and 64bitWindows 10; 32bit and 64bit 
/// 
/// Parameters
///   [in]  context         Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [out] lpPxType        Pointer to a variable that indicates the PX type ADLPxType 
///   [out] lpIGPUBdf       Pointer to a variable that indicates the IGPU BDF ADLBdf 
///   [out] lpNumberOfDGPUs Pointer to a variable that indicates the number of DGPUs. 
///   [out] lppDGPUBDFs     Pointer of a pointer to a variable with type ADLBdf, which contains a list of DGPUs . 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes 
/// 
/// Remarks
///   Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call ADL2_Main_Control_Create first to obtain ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using ADL2_Main_Control_Destroy.
int ADL2_PowerXpress_Configuration_Get ( ADL_CONTEXT_HANDLE context,
                                         enum ADLPxType *        lpPxType,
                                         ADLBdf *           lpIGPUBdf,
                                         int *              lpNumberOfDGPUs,
                                         ADLBdf **          lppDGPUBDFs
                                       );


/// This function gets the PowerXpress scheme. 
/// 
/// This function gets the PowerXpress scheme. 
/// Supported Platforms:
///   Windows 7; 32bit and 64bit 
/// 
/// Parameters
///   [in]  context                Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in]  iAdapterIndex          The ADL index handle of the desired adapter. 
///   [out] lpPXSchemeRange        The pointer to the scheme range to be returned: ADLPXScheme 
///   [out] lpPXSchemeCurrentState The pointer to the current scheme to be returned: ADLPXScheme 
///   [out] lpPXSchemeDefaultState The pointer to the default scheme to be returned: ADLPXScheme 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes 
/// 
/// Remarks
///   Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call ADL2_Main_Control_Create first to obtain ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using ADL2_Main_Control_Destroy.
int ADL2_PowerXpress_Scheme_Get ( ADL_CONTEXT_HANDLE context,
                                  int                iAdapterIndex,
                                  ADLPXScheme *      lpPXSchemeRange,
                                  ADLPXScheme *      lpPXSchemeCurrentState,
                                  ADLPXScheme *      lpPXSchemeDefaultState
                                );


/// This function sets the PowerXpress scheme. 
/// 
/// This function sets the PowerXpress scheme. 
/// Supported Platforms:
///   Windows 7; 32bit and 64bit 
/// 
/// Parameters
///   [in] context       Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in] iAdapterIndex The ADL index handle of the desired adapter. 
///   [in] scheme        The PX scheme to set: ADLPXScheme 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes 
/// 
/// Remarks
///   Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call ADL2_Main_Control_Create first to obtain ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using ADL2_Main_Control_Destroy.
int ADL2_PowerXpress_Scheme_Set ( ADL_CONTEXT_HANDLE context,
                                  int                iAdapterIndex,
                                  ADLPXScheme        scheme
                                );


/// ADL local interface. Function to get all the recently ran and currently running applications. 
/// 
/// The function is used to get all the recently ran and currently running applications in any PX/HG/DG platform 
/// Supported Platforms:
///   \WINBlue 
/// 
/// Parameters
///   [in]  context    Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in]  iListType  The type of applications to be retrieved. It can be either 1(currently running applications) or 2(recently ran applications) 
///   [out] lpNumApps  The pointer to the number of applications currently retrieved based on the iListType passed 
///   [out] lppAppList pointer to the pointer of ADLSGApplicationInfo array containing details of each application retrieved. Initialize to NULL before calling this API. ADL will allocate the necessary memory, using the user provided callback function. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes
int ADL2_SwitchableGraphics_Applications_Get ( ADL_CONTEXT_HANDLE      context,
                                               int                     iListType,
                                               int *                   lpNumApps,
                                               ADLSGApplicationInfo ** lppAppList
                                             );


/// ADL local interface. Function to get Hybrid Discrete graphics support. 
/// 
/// The function is used to get if the windows has inbuilt support for Hybrid Discrete graphics, which implies A+I 
/// Supported Platforms:
///   \WINBlue 
/// 
/// Parameters
///   [in] context Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
/// 
/// Returns
///   TRUE: HybridDiscrete; FALSE: otherwise. 
/// 
/// Remarks
///   Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call ADL2_Main_Control_Create first to obtain ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using ADL2_Main_Control_Destroy.
int ADL2_Win_IsHybridAI ( );


/// Function to retrieve the auto switch configuration setting for PowerXpress. This is not supported when DPPE state switching is configured. 
/// 
/// This function retrieves the auto switch configuration setting for PowerXpress. This is not supported when DPPE state switching is configured. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in]  iAdapterIndex           The ADL index handle of the desired adapter. 
///   [out] lpAutoSwitchOnACDCEvent The pointer to the switch configuration for ACDC. The returned value could be 0 or 1 
///   [out] lpAutoSwitchOnDCACEvent The pointer to the switch configuration for DCAC. The returned value could be 0 or 1 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes
int ADL_Display_PowerXpress_AutoSwitchConfig_Get ( int   iAdapterIndex,
                                                   int * lpAutoSwitchOnACDCEvent,
                                                   int * lpAutoSwitchOnDCACEvent
                                                 );


/// Function to set the auto switch configuration setting for PowerXpress. This is not supported when DPPE state switching is configured. 
/// 
/// This function sets the auto switch configuration setting for PowerXpress. This is not supported when DPPE state switching is configured. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in] iAdapterIndex          The ADL index handle of the desired adapter. 
///   [in] iAutoSwitchOnACDCEvent The pointer to the value used to set the switch configuration for ACDC. Set value 0 or 1 
///   [in] iAutoSwitchOnDCACEvent The pointer to the value used to set the switch configuration for DCAC. Set value 0 or 1 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes
int ADL_Display_PowerXpress_AutoSwitchConfig_Set ( int iAdapterIndex,
                                                   int iAutoSwitchOnACDCEvent,
                                                   int iAutoSwitchOnDCACEvent
                                                 );


/// Function to get the active GPU in PowerXpress. 
/// 
/// This function retrieves the active GPU in PowerXpress. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in]  iAdapterIndex The ADL index handle of the desired adapter. 
///   [out] lpActiveGPU   The pointer to the value storing the active GPU in PowerXpress: ADL_DL_POWERXPRESS_GPU_INTEGRATED or ADL_DL_POWERXPRESS_GPU_DISCRETE 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes
int ADL_Display_PowerXpressActiveGPU_Get ( int   iAdapterIndex,
                                           int * lpActiveGPU
                                         );


/// Function to set the active GPU in PowerXpress. 
/// 
/// This function sets the active GPU in PowerXpress. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in]  iAdapterIndex     The ADL index handle of the desired adapter. 
///   [in]  iActiveGPU        The value of the desired active GPU in PowerXpress: ADL_DL_POWERXPRESS_GPU_INTEGRATED or ADL_DL_POWERXPRESS_GPU_DISCRETE 
///   [out] lpOperationResult The pointer to the retrieved result of the operation. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes
int ADL_Display_PowerXpressActiveGPU_Set ( int   iAdapterIndex,
                                           int   iActiveGPU,
                                           int * lpOperationResult
                                         );


/// Function to retrieve the PowerXpress version. 
/// 
/// This function retrieves the PowerXpress version. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in]  iAdapterIndex The ADL index handle of the desired adapter. 
///   [out] lpVersion     The pointer to the value storing the retrieved version. 
/// 
/// Returns
///   If the system is PowerXpress capable, the function returns ADL_OK and lpVersion is always set to ADL_DL_POWERXPRESS_VERSION
int ADL_Display_PowerXpressVersion_Get ( int   iAdapterIndex,
                                         int * lpVersion
                                       );


/// This function gets ancillary GPUs. 
/// 
/// In Power Express configuration system, the master GPU(Integrated GPU) can have several linked GPU which can be removed by the driver. These removable GPU are called ancillary devices. They are usually discrete GPUs in Power Express system 
/// Supported Platforms:
///   Windows 7; 32bit and 64bit 
/// 
/// Parameters
///   [in]  iAdapterIndex              The ADL index handle of the desired adapter. 
///   [out] lpNumberOfAncillaryDevices Pointer to a variable that indicates the number of ancillary devices. 
///   [out] lppRemovableDevices        Pointer of a pointer to a variable with type ADLBdf, which contains a list of ancillary devices . 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes
int ADL_PowerXpress_AncillaryDevices_Get ( int       iAdapterIndex,
                                           int *     lpNumberOfAncillaryDevices,
                                           ADLBdf ** lppAncillaryDevices
                                         );


/// This function gets the PowerXpress configuration Caps. 
/// 
/// This function gets the PowerXpress configuration Caps. 
/// Supported Platforms:
///   Windows 7; 32bit and 64bit Linux; 32bit and 64bit 
/// 
/// Parameters
///   [in]  iAdapterIndex  The ADL index handle of the desired adapter. 
///   [out] lpPXConfigCaps The pointer to the PowerXpress config Caps returned: ADLPXConfigCaps 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes
int ADL_PowerXpress_Config_Caps ( int               iAdapterIndex,
                                  ADLPXConfigCaps * lpPXConfigCaps
                                );


/// This function gets the PowerXpress scheme. 
/// 
/// This function gets the PowerXpress scheme. 
/// Supported Platforms:
///   Windows 7; 32bit and 64bit 
/// 
/// Parameters
///   [in]  iAdapterIndex          The ADL index handle of the desired adapter. 
///   [out] lpPXSchemeRange        The pointer to the scheme range to be returned: ADLPXScheme 
///   [out] lpPXSchemeCurrentState The pointer to the current scheme to be returned: ADLPXScheme 
///   [out] lpPXSchemeDefaultState The pointer to the default scheme to be returned: ADLPXScheme 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes
int ADL_PowerXpress_Scheme_Get ( int           iAdapterIndex,
                                 ADLPXScheme * lpPXSchemeRange,
                                 ADLPXScheme * lpPXSchemeCurrentState,
                                 ADLPXScheme * lpPXSchemeDefaultState
                               );


/// This function sets the PowerXpress scheme. 
/// 
/// This function sets the PowerXpress scheme. 
/// Supported Platforms:
///   Windows 7; 32bit and 64bit 
/// 
/// Parameters
///   [in] iAdapterIndex The ADL index handle of the desired adapter. 
///   [in] scheme        The PX scheme to set: ADLPXScheme 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes
int ADL_PowerXpress_Scheme_Set ( int         iAdapterIndex,
                                 ADLPXScheme scheme
                               );


#endif /* ADL_HEADER_POWERXPRESS_H_ */
