#ifndef ADL_HEADER_WORKSTATION_H_
#define ADL_HEADER_WORKSTATION_H_

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

/// Function to retrieve the number of GL-Sync connectors on an adapter. 
/// 
/// This function retrieves the number of GL-Sync connectors that are available on a specified adapter. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in]  context                 Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in]  iAdapterIndex           The ADL index handle of the desired adapter. 
///   [out] lpNumOfGLSyncConnectors The pointer to the retrieved number of GL-Sync connectors on the specified adapter. 
/// 
/// Returns
///   If the function is successful, ADL_OK is returned. If iAdapterIndex is an invalid adapter index, ADL_ERR_INVALID_ADL_IDX is returned.
/// If the function is not supported, ADL_ERR_NOT_SUPPORTED is returned. For all other errors, ADL_ERR is returned. 
/// 
/// Remarks
///   Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call ADL2_Main_Control_Create first to obtain ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using ADL2_Main_Control_Destroy.
int ADL2_Workstation_AdapterNumOfGLSyncConnectors_Get ( ADL_CONTEXT_HANDLE context,
                                                        int                iAdapterIndex,
                                                        int *              lpNumOfGLSyncConnectors
                                                      );


/// Function to retrieve current workstation capabilities. 
/// 
/// This function retrieves information regarding the capabilities of a specified workstation card. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in]  context       Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in]  iAdapterIndex The ADL index handle of the desired adapter. 
///   [out] lpValidBits   The pointer to a bit-oriented value. If a bit is set to 1, then the corresponding bit in lpCaps is valid. If a bit is set to 0, then the corresponding bit in lpCaps should be ignored. 
///   [out] lpCaps        The pointer to a bit-oriented value representing a specific workstation capability. Workstation Capabilities 
/// 
/// Returns
///   If the function is successful, ADL_OK is returned. If lpValidBits and/or lpCaps is NULL, ADL_ERR_NULL_POINTER is returned.
/// If iAdapterIndex is an invalid adapter index, ADL_ERR_INVALID_ADL_IDX is returned. If the function is not supported, ADL_ERR_NOT_SUPPORTED is returned. For all other errors, ADL_ERR is returned. 
/// 
/// Remarks
///   Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call ADL2_Main_Control_Create first to obtain ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using ADL2_Main_Control_Destroy.
int ADL2_Workstation_Caps ( ADL_CONTEXT_HANDLE context,
                            int                iAdapterIndex,
                            int *              lpValidBits,
                            int *              lpCaps
                          );


/// Function to get current requested state of Deep Bit Depth and related settings. 
/// 
/// This function returns if specified adapter supports Deep Bit Depth, grayscale and gamma bypass and their defaults. These settings are applicable to system wide to all currently known adapters. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in]  context        Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [out] lpCurDBDState  : The requested deep bit depth state. This is the state the user wishes to put the deep bit depth feature to Deep Bit Depth 
///   [out] lpDefDBDState  The default deep bit depth state state of the system. Deep Bit Depth 
///   [out] lpCurGrayscale Not currently used. It is there for future use. 
///   [out] lpDefGrayscale Not currently used. It is there for future use. 
///   [out] lpCurBypass    Not currently used. It is there for future use. 
///   [out] lpDefBypass    Not currently used. It is there for future use. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes 
/// 
/// Remarks
///   Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call ADL2_Main_Control_Create first to obtain ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using ADL2_Main_Control_Destroy.
int ADL2_Workstation_DeepBitDepth_Get ( ADL_CONTEXT_HANDLE context,
                                        int *              lpCurDBDState,
                                        int *              lpDefDBDState,
                                        int *              lpCurGrayscale,
                                        int *              lpDefGrayscale,
                                        int *              lpCurBypass,
                                        int *              lpDefBypass
                                      );


/// Function to set requested state of Deep Bit Depth and related settings. 
/// 
/// This function sets for the specified adapter supports Deep Bit Depth, grayscale and gamma bypass These settings are applicable to system wide to all currently known adapters. A restart is required to apply settings, ADL_OK_RESTART will be return from function. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in] context      Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in] iDBDState    The requested Deep bit depth state to set the system to.Deep Bit Depth 
///   [in] iGrayscale   Not currently used. It is there for future use. 
///   [in] iBypassGamma Not currently used. It is there for future use. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK_RESTART. Otherwise the return value is an ADL error code. Result Codes
int ADL2_Workstation_DeepBitDepth_Set ( ADL_CONTEXT_HANDLE context,
                                        int                iDBDState,
                                        int                iGrayscale,
                                        int                iBypassGamma
                                      );


/// This function returns if specified adapter supports Deep Bit Depth and their defaults. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in]  context       Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in]  iAdapterIndex The ADL index handle of the desired adapter. 
///   [out] lpDBDDefault  The default deep bit depth state of the system. DISPLAY_10BIT_MODE_STATE 
///   [out] lpCurDBDState : The requested deep bit depth state. This is the state the user wishes to put the deep bit depth feature to DISPLAY_10BIT_MODE_STATE 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes 
/// 
/// Remarks
///   Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call ADL2_Main_Control_Create first to obtain ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using ADL2_Main_Control_Destroy.
int ADL2_Workstation_DeepBitDepthX2_Get ( ADL_CONTEXT_HANDLE context,
                                          int                iAdapterIndex,
                                          int *              lpDefDBDState,
                                          int *              lpCurDBDState
                                        );


/// This function Deep Bit Depth sets for the specified adapter A restart is required to apply settings, ADL_OK_RESTART will be return from function. 
/// 
/// 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in] context       Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in] iAdapterIndex The ADL index handle of the desired adapter. 
///   [in] iDBDState     The requested Deep bit depth state to set the system to.DISPLAY_10BIT_MODE_STATE 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK_RESTART. Otherwise the return value is an ADL error code. Result Codes 
/// 
/// Remarks
///   Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call ADL2_Main_Control_Create first to obtain ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using ADL2_Main_Control_Destroy.
int ADL2_Workstation_DeepBitDepthX2_Set ( ADL_CONTEXT_HANDLE context,
                                          int                iAdapterIndex,
                                          int                iDBDState
                                        );


/// Function to determine whether or not a display is capable of Genlock functionality. 
/// 
/// This function determines whether a specified display can be used for Framelock/Genlock. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in]  context       Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in]  iAdapterIndex The ADL index handle of the desired adapter. 
///   [in]  iDisplayIndex The desired display index, which can be retrieved from the ADLDisplayInfo data structure. 
///   [out] lpCanGenlock  The pointer to the retrieved Genlock capabilities. 1: the display is Genlock-capable; 0: the display is not Genlock-capable. 
/// 
/// Returns
///   If the function is successful, ADL_OK is returned. If iAdapterIndex is an invalid adapter index, ADL_ERR_INVALID_ADL_IDX is returned.
/// If the function is not supported, ADL_ERR_NOT_SUPPORTED is returned. For all other errors, ADL_ERR is returned. 
/// 
/// Remarks
///   Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call ADL2_Main_Control_Create first to obtain ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using ADL2_Main_Control_Destroy.
int ADL2_Workstation_DisplayGenlockCapable_Get ( ADL_CONTEXT_HANDLE context,
                                                 int                iAdapterIndex,
                                                 int                iDisplayIndex,
                                                 int *              lpCanGenlock
                                               );


/// Function to retrieve the GL-Sync mode for a display. 
/// 
/// This function implements the DI call to retrieve the GL-Sync mode for a specified display. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in]  context       Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in]  iAdapterIndex The ADL index handle of the desired adapter. 
///   [in]  iDisplayIndex The desired display index. 
///   [out] lpGlSyncMode  The pointer to the ADLGlSyncMode structure storing the GL-Sync mode of the specified display. 
/// 
/// Returns
///   If the function is successful, ADL_OK is returned. If iAdapterIndex is an invalid adapter index, ADL_ERR_INVALID_ADL_IDX is returned.
/// If the function is not supported, ADL_ERR_NOT_SUPPORTED is returned. For all other errors, ADL_ERR is returned. 
/// 
/// Remarks
///   Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call ADL2_Main_Control_Create first to obtain ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using ADL2_Main_Control_Destroy.
int ADL2_Workstation_DisplayGLSyncMode_Get ( ADL_CONTEXT_HANDLE context,
                                             int                iAdapterIndex,
                                             int                iDisplayIndex,
                                             ADLGlSyncMode *    lpGlSyncMode
                                           );


/// Function to set the GL-Sync mode for a display. 
/// 
/// This function implements the DI call to set the GL-Sync mode for a specified display. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in] context       Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in] iAdapterIndex The ADL index handle of the desired adapter. 
///   [in] iDisplayIndex The desired display index. 
///   [in] glSyncMode    The ADLGlSyncMode structure describing the GL-Sync mode to set for the specified display. 
/// 
/// Returns
///   If the function is successful, ADL_OK is returned. ADL_OK_MODE_CHANGE if success but need mode change,
/// If iAdapterIndex is an invalid adapter index, ADL_ERR_INVALID_ADL_IDX is returned. If the function is not supported, ADL_ERR_NOT_SUPPORTED is returned. For all other errors, ADL_ERR is returned. 
/// 
/// Remarks
///   Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call ADL2_Main_Control_Create first to obtain ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using ADL2_Main_Control_Destroy.
int ADL2_Workstation_DisplayGLSyncMode_Set ( ADL_CONTEXT_HANDLE context,
                                             int                iAdapterIndex,
                                             int                iDisplayIndex,
                                             ADLGlSyncMode      glSyncMode
                                           );


/// Function to get ECC (Error Correction Code) Capabilities on the specified adapter. This function implements the CI call to get ECC (Error Correction Code) Capabilities on the specified adapter. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in]  context       Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in]  iAdapterIndex - The index of the desired adapter. 
///   [out] lpSupported   - returns the bolean capability, whether ECC is supported or not(ADL_TRUE or ADL_FALSE) for the specified adapter 
/// 
/// Returns
///   If the function is successful, ADL_OK is returned, If iAdapterIndex is an invalid adapter index, ADL_ERR_INVALID_ADL_IDX is returned. If the function is not supported, ADL_ERR_NOT_SUPPORTED is returned. For all other errors, ADL_ERR is returned. 
/// 
/// Remarks
///   Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call ADL2_Main_Control_Create first to obtain ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using ADL2_Main_Control_Destroy.
int ADL2_Workstation_ECC_Caps ( ADL_CONTEXT_HANDLE context,
                                int                iAdapterIndex,
                                int *              lpSupported
                              );


/// Function to get ECC (Error Correction Code) current and desired states on the specified adapter. This function implements the CI call to get ECC (Error Correction Code) current mode(driver applied mode) and the desired mode (user requested mode) on the specified adapter. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in]  context       Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in]  iAdapterIndex - The index of the desired adapter. 
///   [out] lpDefaultMode - Default ECC Mode (ECC_MODE_OFF, ECC_MODE_ON).Define_ecc_mode_states. 
///   [out] lpCurrentMode - ECC Mode that is currently stored in the permanent store for driver. (ECC_MODE_OFF, ECC_MODE_ON).Define_ecc_mode_states. 
///   [out] lpDesiredMode - Desired ECC mode from the user, once the user reboots the machine DesiredMode will be applied to CurrentMode (ECC_MODE_OFF, ECC_MODE_ON). Define_ecc_mode_states. 
/// 
/// Returns
///   If the function is successful, ADL_OK is returned, If iAdapterIndex is an invalid adapter index, ADL_ERR_INVALID_ADL_IDX is returned. If the function is not supported, ADL_ERR_NOT_SUPPORTED is returned. For all other errors, ADL_ERR is returned. 
/// 
/// Remarks
///   Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call ADL2_Main_Control_Create first to obtain ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using ADL2_Main_Control_Destroy.
int ADL2_Workstation_ECC_Get ( ADL_CONTEXT_HANDLE context,
                               int                iAdapterIndex,
                               int *              lpDefaultMode,
                               int *              lpCurrentMode,
                               int *              lpDesiredMode
                             );


/// Function to set ECC Mode on the specified adapter This function implements the CI call to set ECC (Error Correction Code) to turn on and off this feature on the specified adapter. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in] context       Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in] iAdapterIndex - The index of the desired adapter. 
///   [in] iDesiredMode  - ECC Mode currently accepts ECC_MODE_OFF or ECC_MODE_ON. Define_ecc_mode_states 
/// 
/// Returns
///   If the function is successful, ADL_OK is returned, If iAdapterIndex is an invalid adapter index, ADL_ERR_INVALID_ADL_IDX is returned. If the function is not supported, ADL_ERR_NOT_SUPPORTED is returned. For all other errors, ADL_ERR is returned. 
/// 
/// Remarks
///   Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call ADL2_Main_Control_Create first to obtain ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using ADL2_Main_Control_Destroy.
int ADL2_Workstation_ECC_Set ( ADL_CONTEXT_HANDLE context,
                               int                iAdapterIndex,
                               int                iDesiredMode
                             );


/// Function to get ECC statistics on the specified adapter. This function implements the CI call to get SEC(Single Error Correct) and DED(Double Error Detect) Counts on the specified adapter. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in]  context       Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in]  iAdapterIndex - The index of the desired adapter. 
///   [out] lpAdlEccData  - is of type ADLECCData. Gets the SEC & DED counts ADLECCData 
/// 
/// Returns
///   If the function is successful, ADL_OK is returned, If iAdapterIndex is an invalid adapter index, ADL_ERR_INVALID_ADL_IDX is returned. If the function is not supported, ADL_ERR_NOT_SUPPORTED is returned. For all other errors, ADL_ERR is returned. 
/// 
/// Remarks
///   Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call ADL2_Main_Control_Create first to obtain ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using ADL2_Main_Control_Destroy.
int ADL2_Workstation_ECCData_Get ( ADL_CONTEXT_HANDLE context,
                                   int                iAdapterIndex,
                                   ADLECCData *       lpAdlEccData
                                 );


/// Function to get ECC (Error Correction Code) current and desired states on the specified adapter. This function implements the CI call to get ECC (Error Correction Code) current mode(driver applied mode) and the desired mode (user requested mode) on the specified adapter. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in]  context       Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in]  iAdapterIndex - The index of the desired adapter. 
///   [out] lpModeType    - Default ECC Mode (ECC_MODE_OFF, ECC_MODE_ON, ECC_MODE_HBM).Define_ecc_mode_states. 
///   [out] lpDefaultMode - Default ECC Mode (ECC_MODE_OFF, ECC_MODE_ON, ECC_MODE_HBM).Define_ecc_mode_states. 
///   [out] lpCurrentMode - ECC Mode that is currently stored in the permanent store for driver. (ECC_MODE_OFF, ECC_MODE_ON, ECC_MODE_HBM).Define_ecc_mode_states. 
///   [out] lpDesiredMode - Desired ECC mode from the user, once the user reboots the machine DesiredMode will be applied to CurrentMode (ECC_MODE_OFF, ECC_MODE_ON, ECC_MODE_HBM ). Define_ecc_mode_states. 
/// 
/// Returns
///   If the function is successful, ADL_OK is returned, If iAdapterIndex is an invalid adapter index, ADL_ERR_INVALID_ADL_IDX is returned. If the function is not supported, ADL_ERR_NOT_SUPPORTED is returned. For all other errors, ADL_ERR is returned. 
/// 
/// Remarks
///   Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call ADL2_Main_Control_Create first to obtain ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using ADL2_Main_Control_Destroy.
int ADL2_Workstation_ECCX2_Get ( ADL_CONTEXT_HANDLE context,
                                 int                iAdapterIndex,
                                 int *              lpModeType,
                                 int *              lpDefaultMode,
                                 int *              lpCurrentMode,
                                 int *              lpDesiredMode
                               );


/// Function to retrieve the GL-Sync Genlock configuration settings. 
/// 
/// This function retrieves the Genlock configuration settings of a specific GPU connector on a GL-Sync module attached to a specified adapter on a GL-Sync connector. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in]  context               Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in]  iAdapterIndex         The ADL index handle of the desired adapter. 
///   [in]  iGlSyncConnector      The index of the desired GL-Sync connector. The index can range from 0 to NumOfGLSyncConnectors - 1. 
///   [in]  iGlValidMask          The mask indicating the Genlock settings to be retrieved (bit field of ADL_GLSYNC_CONFIGMASK_*). Genlock related values 
///   [out] lpGlSyncGenlockConfig The pointer to the ADLGLSyncGenlockConfig structure with the retrieved Genlock settings. 
/// 
/// Returns
///   If the function is successful, ADL_OK is returned. If iAdapterIndex is an invalid adapter index, ADL_ERR_INVALID_ADL_IDX is returned.
/// If the function is not supported, ADL_ERR_NOT_SUPPORTED is returned. For all other errors, ADL_ERR is returned. 
/// 
/// Remarks
///   Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call ADL2_Main_Control_Create first to obtain ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using ADL2_Main_Control_Destroy.
int ADL2_Workstation_GLSyncGenlockConfiguration_Get ( ADL_CONTEXT_HANDLE       context,
                                                      int                      iAdapterIndex,
                                                      int                      iGlSyncConnector,
                                                      int                      iGlValidMask,
                                                      ADLGLSyncGenlockConfig * lpGlSyncGenlockConfig
                                                    );


/// Function to set the GL-Sync Genlock configuration settings. 
/// 
/// This function sets the Genlock configuration settings of a specific GPU connector on a GL-Sync module attached to a specified adapter on a GL-Sync connector. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in] context             Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in] iAdapterIndex       The ADL index handle of the desired adapter. 
///   [in] iGlSyncConnector    The index of the desired GL-Sync connector. The index can range from 0 to NumOfGLSyncConnectors - 1. 
///   [in] glSyncGenlockConfig The Genlock settings to be set in ADLGLSyncGenlockConfig structure 
/// 
/// Returns
///   If the function is successful, ADL_OK is returned. If iAdapterIndex is an invalid adapter index, ADL_ERR_INVALID_ADL_IDX is returned.
/// If the function is not supported, ADL_ERR_NOT_SUPPORTED is returned. For all other errors, ADL_ERR is returned. 
/// 
/// Remarks
///   Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call ADL2_Main_Control_Create first to obtain ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using ADL2_Main_Control_Destroy.
int ADL2_Workstation_GLSyncGenlockConfiguration_Set ( ADL_CONTEXT_HANDLE     context,
                                                      int                    iAdapterIndex,
                                                      int                    iGlSyncConnector,
                                                      ADLGLSyncGenlockConfig glSyncGenlockConfig
                                                    );


/// Function to detect the GL-Sync module. 
/// 
/// This function detects the GL-Sync module attached to a specified adapter and GL-Sync connector. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in]  context          Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in]  iAdapterIndex    The ADL index handle of the desired adapter. 
///   [in]  iGlSyncConnector The index of the desired GL-Sync connector. The index can range from 0 to NumOfGLSyncConnectors - 1. 
///   [out] lpGlSyncModuleID The pointer to the retrieved GL-Sync module information. If no GL-Sync module is attached, lpGlSyncModuleID->ulModuleID is set to 0. 
/// 
/// Returns
///   If the function is successful, ADL_OK is returned. If iAdapterIndex is an invalid adapter index, ADL_ERR_INVALID_ADL_IDX is returned.
/// If the function is not supported, ADL_ERR_NOT_SUPPORTED is returned. For all other errors, ADL_ERR is returned. 
/// 
/// Remarks
///   Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call ADL2_Main_Control_Create first to obtain ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using ADL2_Main_Control_Destroy.
int ADL2_Workstation_GLSyncModuleDetect_Get ( ADL_CONTEXT_HANDLE  context,
                                              int                 iAdapterIndex,
                                              int                 iGlSyncConnector,
                                              ADLGLSyncModuleID * lpGlSyncModuleID
                                            );


/// Function to describe the GL-Sync module caps. 
/// 
/// This function describes the hardware capabilities of the GL-Sync module attached to a specific adapter and GL-Sync connector.
/// 
/// This API uses the Caller's Memory Allocation Callback Function to allocate memory pointed by ppGlSyncPorts. Caller is responsible to de-alocate the memory. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in]  context             Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in]  iAdapterIndex       The ADL index handle of the desired adapter. 
///   [in]  iGlSyncConnector    The index of the desired GL-Sync connector. The index can range from 0 to NumOfGLSyncConnectors - 1. 
///   [out] lpNumGLSyncGPUPorts The pointer to the number of GPU ports on the specified GL-Sync module. 
///   [out] lpNumGlSyncPorts    The pointer to the number of external ports (RJ45/BNC) on the specified GL-Sync module. 
///   [out] lpMaxSyncDelay      The pointer to the maximum value of the sync delay Genlock setting. 
///   [out] lpMaxSampleRate     The pointer to the maximum value of the sample rate Genlock setting. 
///   [out] ppGlSyncPorts       The pointer to the pointer to the retrieved information about the external ports on the specified GL-Sync connector.
/// The user passes a memory allocation callback to allocate memory for this and to free the memory once done with it. 
/// 
/// Returns
///   If the function is successful, ADL_OK is returned. If iAdapterIndex is an invalid adapter index, ADL_ERR_INVALID_ADL_IDX is returned.
/// If the function is not supported, ADL_ERR_NOT_SUPPORTED is returned. For all other errors, ADL_ERR is returned. 
/// 
/// Remarks
///   Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call ADL2_Main_Control_Create first to obtain ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using ADL2_Main_Control_Destroy.
int ADL2_Workstation_GLSyncModuleInfo_Get ( ADL_CONTEXT_HANDLE   context,
                                            int                  iAdapterIndex,
                                            int                  iGlSyncConnector,
                                            int *                lpNumGLSyncGPUPorts,
                                            int *                lpNumGlSyncPorts,
                                            int *                lpMaxSyncDelay,
                                            int *                lpMaxSampleRate,
                                            ADLGLSyncPortCaps ** ppGlSyncPorts
                                          );


/// Function to retrieve GL-Sync port information. 
/// 
/// This function implements the DI call to retrieve the information about a GL-Sync port of a specified GL-Sync module and adapter. This API uses the Caller's Memory Allocation Callback Function to allocate memory pointed by ppGlSyncLEDs. Caller is responsible to de-alocate the memory. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in]  context          Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in]  iAdapterIndex    The ADL index handle of the desired adapter. 
///   [in]  iGlSyncConnector The index of the desired GL-Sync connector. The index can range from 0 to NumOfGLSyncConnectors - 1. 
///   [in]  iGlSyncPortType  The desired GL-Sync port (ADL_GLSYNC_PORT_*). Genlock related values 
///   [in]  iNumLEDs         The number of LEDs for the specified port. If the number of LEDs is unknown, specify a value of 0. 
///   [out] lpGlSyncPortInfo The pointer to the retrieved port information in ADLGlSyncPortInfo structure 
///   [out] ppGlSyncLEDs     The pointer to the pointer to the retrieved information about the LEDs associated to the specified GL-Sync connector.
/// The user must pass a memory allocation callback to allocate memory for this and to free the memory once done with it. 
/// 
/// Returns
///   If the function is successful, ADL_OK is returned. If iAdapterIndex is an invalid adapter index, ADL_ERR_INVALID_ADL_IDX is returned.
/// If the function is not supported, ADL_ERR_NOT_SUPPORTED is returned. For all other errors, ADL_ERR is returned. 
/// 
/// Remarks
///   Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call ADL2_Main_Control_Create first to obtain ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using ADL2_Main_Control_Destroy.
int ADL2_Workstation_GLSyncPortState_Get ( ADL_CONTEXT_HANDLE  context,
                                           int                 iAdapterIndex,
                                           int                 iGlSyncConnector,
                                           int                 iGlSyncPortType,
                                           int                 iNumLEDs,
                                           ADLGlSyncPortInfo * lpGlSyncPortInfo,
                                           int **              ppGlSyncLEDs
                                         );


/// Function to perform GL-Sync port control. 
/// 
/// This function implements the DI call to enable or disable an output signal on the RJ-45 ports of a specified GL-Sync module and adapter. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in] context           Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in] iAdapterIndex     The ADL index handle of the desired adapter. 
///   [in] iGlSyncConnector  The index of the desired GL-Sync connector. The index can range from 0 to NumOfGLSyncConnectors - 1. 
///   [in] glSyncPortControl The ADLGlSyncPortControl structure to be set. 
/// 
/// Returns
///   If the function is successful, ADL_OK is returned. If iAdapterIndex is an invalid adapter index, ADL_ERR_INVALID_ADL_IDX is returned.
/// If the function is not supported, ADL_ERR_NOT_SUPPORTED is returned. For all other errors, ADL_ERR is returned. 
/// 
/// Remarks
///   Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call ADL2_Main_Control_Create first to obtain ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using ADL2_Main_Control_Destroy.
int ADL2_Workstation_GLSyncPortState_Set ( ADL_CONTEXT_HANDLE   context,
                                           int                  iAdapterIndex,
                                           int                  iGlSyncConnector,
                                           ADLGlSyncPortControl glSyncPortControl
                                         );


/// Function to get the supported GL-Sync topology. 
/// 
/// This function implements the DI call to set the GL-Sync mode for a specified display. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in]  context          Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in]  iAdapterIndex    The ADL index handle of the desired adapter. 
///   [in]  iNumSyncModes    
///   [in]  glSyncModes      
///   [out] iNumSugSyncModes 
///   [out] glSugSyncModes   
/// 
/// Returns
///   If the function is successful, ADL_OK is returned.
/// If iAdapterIndex is an invalid adapter index, ADL_ERR_INVALID_ADL_IDX is returned. If the function is not supported, ADL_ERR_NOT_SUPPORTED is returned. For all other errors, ADL_ERR is returned. 
/// 
/// Remarks
///   Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call ADL2_Main_Control_Create first to obtain ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using ADL2_Main_Control_Destroy.
int ADL2_Workstation_GLSyncSupportedTopology_Get ( ADL_CONTEXT_HANDLE context,
                                                   int                iAdapterIndex,
                                                   int                iNumSyncModes,
                                                   ADLGlSyncMode2 *   glSyncModes,
                                                   int *              iNumSugSyncModes,
                                                   ADLGlSyncMode2 **  glSugSyncModes
                                                 );


/// Function to set the load balancing capabilities for the specified adapter. 
/// 
/// This function implements the CI call to Get the load balancing caps for a specified adapter. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in]  context       Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in]  iAdapterIndex The ADL index handle of the desired adapter. 
///   [out] lpResultMask  The int pointer to the mask bits of load balancing of the specified adapter, It can be combination of ADL_WORKSTATION_LOADBALANCING_SUPPORTED, ref ADL_WORKSTATION_LOADBALANCING_AVAILABLE. 
///   [out] lpResultValue The int pointer to the capable load balancing bits of the specified adapter. It can be combination of ADL_WORKSTATION_LOADBALANCING_SUPPORTED, ref ADL_WORKSTATION_LOADBALANCING_AVAILABLE 
/// 
/// Returns
///   If the function is successful, ADL_OK is returned. ADL_OK_MODE_CHANGE if success but need mode change,
/// If iAdapterIndex is an invalid adapter index, ADL_ERR_INVALID_ADL_IDX is returned. If the function is not supported, ADL_ERR_NOT_SUPPORTED is returned. For all other errors, ADL_ERR is returned. 
/// 
/// Remarks
///   Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call ADL2_Main_Control_Create first to obtain ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using ADL2_Main_Control_Destroy.
int ADL2_Workstation_LoadBalancing_Caps ( ADL_CONTEXT_HANDLE context,
                                          int                iAdapterIndex,
                                          int *              lpResultMask,
                                          int *              lpResultValue
                                        );


/// Function to get the load balancing state of the specified adapter. 
/// 
/// This function implements the PCS access to Get the load balancing state for a specified adapter. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in]  context          Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [out] lpResultMask     The int pointer to mask bit of state. It can be combination of ADL_WORKSTATION_LOADBALANCING_DISABLED, ref ADL_WORKSTATION_LOADBALANCING_ENABLED. 
///   [out] lpCurResultValue The int pointer to the current state It can be one of ADL_WORKSTATION_LOADBALANCING_DISABLED, ref ADL_WORKSTATION_LOADBALANCING_ENABLED. 
///   [out] lpDefResultValue The int pointer to the dafault state It can be one of ADL_WORKSTATION_LOADBALANCING_DISABLED, ref ADL_WORKSTATION_LOADBALANCING_ENABLED. 
/// 
/// Returns
///   If the function is successful, ADL_OK is returned. ADL_OK_MODE_CHANGE if success but need mode change,
/// If iAdapterIndex is an invalid adapter index, ADL_ERR_INVALID_ADL_IDX is returned. If the function is not supported, ADL_ERR_NOT_SUPPORTED is returned. For all other errors, ADL_ERR is returned. 
/// 
/// Remarks
///   Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call ADL2_Main_Control_Create first to obtain ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using ADL2_Main_Control_Destroy.
int ADL2_Workstation_LoadBalancing_Get ( ADL_CONTEXT_HANDLE context,
                                         int *              lpResultMask,
                                         int *              lpCurResultValue,
                                         int *              lpDefResultValue
                                       );


/// Function to set the load balancing state of the specified adapter. 
/// 
/// This function implements the PCS access to set the load balancing mode for a specified adapter. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in] context   Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in] iCurState The current state to set for the specified adapter. 
/// 
/// Returns
///   If the function is successful, ADL_OK is returned. ADL_OK_MODE_CHANGE if success but need mode change,
/// If iAdapterIndex is an invalid adapter index, ADL_ERR_INVALID_ADL_IDX is returned. If the function is not supported, ADL_ERR_NOT_SUPPORTED is returned. For all other errors, ADL_ERR is returned. 
/// 
/// Remarks
///   Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call ADL2_Main_Control_Create first to obtain ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using ADL2_Main_Control_Destroy.
int ADL2_Workstation_LoadBalancing_Set ( ADL_CONTEXT_HANDLE context,
                                         int                iCurState
                                       );


/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in]  context           Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in]  iAdapterIndex,ADL index handle of the desired adapter. 
///   [out] lpSupported,The   pointer to the caps of adapter settings. If the specified adapter supports SDI, it is set to ADL_TRUE, else set to ADL_FALSE 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK (zero). Otherwise the return value is an ADL error code (non-zero). Result Codes 
/// 
/// Remarks
///   Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call ADL2_Main_Control_Create first to obtain ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using ADL2_Main_Control_Destroy.
int ADL2_Workstation_SDI_Caps ( ADL_CONTEXT_HANDLE context,
                                int                iAdapterIndex,
                                int *              lpSupported
                              );


/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in]  context           Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in]  iAdapterIndex,ADL index handle of the desired adapter. 
///   [out] lpDefualt,pointer to the default SDI settings of the specified adapter. 
///   [out] lpCurrent,pointer to the driver SDI settings of the specified adapter. 
///   [out] lpDriver,pointer  to the user requested SDI seetings of the specified adapter. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK (zero). Otherwise the return value is an ADL error code (non-zero). Result Codes 
/// 
/// Remarks
///   Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call ADL2_Main_Control_Create first to obtain ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using ADL2_Main_Control_Destroy.
int ADL2_Workstation_SDI_Get ( ADL_CONTEXT_HANDLE context,
                               int                iAdapterIndex,
                               ADLSDIData *       lpDefualt,
                               ADLSDIData *       lpDriver,
                               ADLSDIData *       lpCurrent
                             );


/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in] context                Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in] iAdapterIndex,ADL      index handle of the desired adapter. 
///   [in] iSDIState,SDI          state (possiable values ADL_SDI_ON or ADL_SDI_OFF 
///   [in] iSizeofSDISegment,size of the apreture 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK (zero). Otherwise the return value is an ADL error code (non-zero). Result Codes 
/// 
/// Remarks
///   Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call ADL2_Main_Control_Create first to obtain ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using ADL2_Main_Control_Destroy.
int ADL2_Workstation_SDI_Set ( ADL_CONTEXT_HANDLE context,
                               int                iAdapterIndex,
                               int                iSDIState,
                               int                iSizeofSDISegment
                             );


/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in]  context                      Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in]  iAdapterIndex,ADL            index handle of the desired adapter. 
///   [out] lpMemorySegmentCount,pointer to the supported memory segment count of the specified adapter 
///   [out] lppMemorySegmentList,pointer to the supported memory segment list of the specified adapter 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK (zero). Otherwise the return value is an ADL error code (non-zero). Result Codes 
/// 
/// Remarks
///   Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call ADL2_Main_Control_Create first to obtain ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using ADL2_Main_Control_Destroy.
int ADL2_Workstation_SDISegmentList_Get ( ADL_CONTEXT_HANDLE context,
                                          int                iAdapterIndex,
                                          int *              lpMemorySegmentCount,
                                          int **             lppMemorySegmentList
                                        );


/// Function to retreive the worstation stereo mode. 
/// 
/// This function retrieves the current and default workstation stereo mode. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in]  context       Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in]  iAdapterIndex The ADL index handle of the desired adapter. 
///   [out] lpDefState    The pointer to the default stereo mode. Workstation Capabilities 
///   [out] lpCurState    The pointer to the current stereo mode. Workstation Capabilities 
/// 
/// Returns
///   If the function is successful, ADL_OK is returned. If lpDefState and/or lpCurState are NULL, ADL_ERR_NULL_POINTER is returned.
/// If iAdapterIndex is an invalid adapter index, ADL_ERR_INVALID_ADL_IDX is returned. If the function is not supported, ADL_ERR_NOT_SUPPORTED is returned. For all other errors, ADL_ERR is returned. 
/// 
/// Remarks
///   Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call ADL2_Main_Control_Create first to obtain ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using ADL2_Main_Control_Destroy.
int ADL2_Workstation_Stereo_Get ( ADL_CONTEXT_HANDLE context,
                                  int                iAdapterIndex,
                                  int *              lpDefState,
                                  int *              lpCurState
                                );


/// Function to set the workstation stereo mode. 
/// 
/// This function sets the current workstation stereo mode. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in] context       Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in] iAdapterIndex The ADL index handle of the desired adapter. 
///   [in] iCurState     The desired workstation stereo mode. Workstation Capabilities 
/// 
/// Returns
///   If the function is successful, ADL_OK is returned. If iAdapterIndex is an invalid adapter index, ADL_ERR_INVALID_ADL_IDX is returned.
/// If the function is not supported, ADL_ERR_NOT_SUPPORTED is returned. For all other errors, ADL_ERR is returned. 
/// 
/// Remarks
///   Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call ADL2_Main_Control_Create first to obtain ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using ADL2_Main_Control_Destroy.
int ADL2_Workstation_Stereo_Set ( ADL_CONTEXT_HANDLE context,
                                  int                iAdapterIndex,
                                  int                iCurState
                                );


/// This function retrieves current workattaion overdrivecapabilities for a specified adapter. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in] context    Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in] iSupported The pointer to an int variable which indicates if Overdrive feature is supported ( ADL_TRUE : supported, ADL_FALSE : not supported) 
///   [in] iEnabled   The pointer to an int variable which indicates if Overdrive feature is enabled ( ADL_TRUE : enabled, ADL_FALSE : disabled) 
///   [in] iVersion   The pointer to an int variable receiving the Overdrive feature version. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK (zero). Otherwise the return value is an ADL error code (non-zero). Result Codes. If Overdrive feature is not supported the return code is ADL_ERR_NOT_SUPPORTED
/// 
/// Remarks
///   Call this API prior to calling any other Overdrive APIs to determine if this feature is supported and enabled.
int ADL2_WS_Overdrive_Caps ( ADL_CONTEXT_HANDLE context,
                             int                iAdapterIndex,
                             int *              iSupported,
                             int *              iEnabled,
                             int *              iVersion
                           );


/// Function to retrieve the number of GL-Sync connectors on an adapter. 
/// 
/// This function retrieves the number of GL-Sync connectors that are available on a specified adapter. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in]  iAdapterIndex           The ADL index handle of the desired adapter. 
///   [out] lpNumOfGLSyncConnectors The pointer to the retrieved number of GL-Sync connectors on the specified adapter. 
/// 
/// Returns
///   If the function is successful, ADL_OK is returned. If iAdapterIndex is an invalid adapter index, ADL_ERR_INVALID_ADL_IDX is returned.
/// If the function is not supported, ADL_ERR_NOT_SUPPORTED is returned. For all other errors, ADL_ERR is returned.
int ADL_Workstation_AdapterNumOfGLSyncConnectors_Get ( int   iAdapterIndex,
                                                       int * lpNumOfGLSyncConnectors
                                                     );


/// Function to retrieve current workstation capabilities. 
/// 
/// This function retrieves information regarding the capabilities of a specified workstation card. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in]  iAdapterIndex The ADL index handle of the desired adapter. 
///   [out] lpValidBits   The pointer to a bit-oriented value. If a bit is set to 1, then the corresponding bit in lpCaps is valid. If a bit is set to 0, then the corresponding bit in lpCaps should be ignored. 
///   [out] lpCaps        The pointer to a bit-oriented value representing a specific workstation capability. Workstation Capabilities 
/// 
/// Returns
///   If the function is successful, ADL_OK is returned. If lpValidBits and/or lpCaps is NULL, ADL_ERR_NULL_POINTER is returned.
/// If iAdapterIndex is an invalid adapter index, ADL_ERR_INVALID_ADL_IDX is returned. If the function is not supported, ADL_ERR_NOT_SUPPORTED is returned. For all other errors, ADL_ERR is returned.
int ADL_Workstation_Caps ( int   iAdapterIndex,
                           int * lpValidBits,
                           int * lpCaps
                         );


/// Function to get current requested state of Deep Bit Depth and related settings. 
/// 
/// This function returns if specified adapter supports Deep Bit Depth, grayscale and gamma bypass and their defaults. These settings are applicable to system wide to all currently known adapters. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [out] lpCurDBDState  : The requested deep bit depth state. This is the state the user wishes to put the deep bit depth feature to Deep Bit Depth 
///   [out] lpDefDBDState  The default deep bit depth state state of the system. Deep Bit Depth 
///   [out] lpCurGrayscale Not currently used. It is there for future use. 
///   [out] lpDefGrayscale Not currently used. It is there for future use. 
///   [out] lpCurBypass    Not currently used. It is there for future use. 
///   [out] lpDefBypass    Not currently used. It is there for future use. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes
int ADL_Workstation_DeepBitDepth_Get ( int * lpCurDBDState,
                                       int * lpDefDBDState,
                                       int * lpCurGrayscale,
                                       int * lpDefGrayscale,
                                       int * lpCurBypass,
                                       int * lpDefBypass
                                     );


/// Function to set requested state of Deep Bit Depth and related settings. 
/// 
/// This function sets for the specified adapter supports Deep Bit Depth, grayscale and gamma bypass These settings are applicable to system wide to all currently known adapters. A restart is required to apply settings, ADL_OK_RESTART will be return from function. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in] iDBDState    The requested Deep bit depth state to set the system to.Deep Bit Depth 
///   [in] iGrayscale   Not currently used. It is there for future use. 
///   [in] iBypassGamma Not currently used. It is there for future use. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK_RESTART. Otherwise the return value is an ADL error code. Result Codes
int ADL_Workstation_DeepBitDepth_Set ( int iDBDState,
                                       int iGrayscale,
                                       int iBypassGamma
                                     );


/// This function returns if specified adapter supports Deep Bit Depth and their defaults. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in]  iAdapterIndex The ADL index handle of the desired adapter. 
///   [out] lpDBDDefault  The default deep bit depth state state of the system. DISPLAY_10BIT_MODE_STATE 
///   [out] lpCurDBDState : The requested deep bit depth state. This is the state the user wishes to put the deep bit depth feature to DISPLAY_10BIT_MODE_STATE 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes
int ADL_Workstation_DeepBitDepthX2_Get ( int   iAdapterIndex,
                                         int * lpDefDBDState,
                                         int * lpCurDBDState
                                       );


/// This function Deep Bit Depth sets for the specified adapter A restart is required to apply settings, ADL_OK_RESTART will be return from function. 
/// 
/// 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in] iAdapterIndex The ADL index handle of the desired adapter. 
///   [in] iDBDState     The requested Deep bit depth state to set the system to.DISPLAY_10BIT_MODE_STATE 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK_RESTART. Otherwise the return value is an ADL error code. Result Codes
int ADL_Workstation_DeepBitDepthX2_Set ( int iAdapterIndex,
                                         int iDBDState
                                       );


/// Function to determine whether or not a display is capable of Genlock functionality. 
/// 
/// This function determines whether a specified display can be used for Framelock/Genlock. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in]  iAdapterIndex The ADL index handle of the desired adapter. 
///   [in]  iDisplayIndex The desired display index, which can be retrieved from the ADLDisplayInfo data structure. 
///   [out] lpCanGenlock  The pointer to the retrieved Genlock capabilities. 1: the display is Genlock-capable; 0: the display is not Genlock-capable. 
/// 
/// Returns
///   If the function is successful, ADL_OK is returned. If iAdapterIndex is an invalid adapter index, ADL_ERR_INVALID_ADL_IDX is returned.
/// If the function is not supported, ADL_ERR_NOT_SUPPORTED is returned. For all other errors, ADL_ERR is returned.
int ADL_Workstation_DisplayGenlockCapable_Get ( int   iAdapterIndex,
                                                int   iDisplayIndex,
                                                int * lpCanGenlock
                                              );


/// Function to retrieve the GL-Sync mode for a display. 
/// 
/// This function implements the DI call to retrieve the GL-Sync mode for a specified display. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in]  iAdapterIndex The ADL index handle of the desired adapter. 
///   [in]  iDisplayIndex The desired display index. 
///   [out] lpGlSyncMode  The pointer to the ADLGlSyncMode structure storing the GL-Sync mode of the specified display. 
/// 
/// Returns
///   If the function is successful, ADL_OK is returned. If iAdapterIndex is an invalid adapter index, ADL_ERR_INVALID_ADL_IDX is returned.
/// If the function is not supported, ADL_ERR_NOT_SUPPORTED is returned. For all other errors, ADL_ERR is returned.
int ADL_Workstation_DisplayGLSyncMode_Get ( int             iAdapterIndex,
                                            int             iDisplayIndex,
                                            ADLGlSyncMode * lpGlSyncMode
                                          );


/// Function to set the GL-Sync mode for a display. 
/// 
/// This function implements the DI call to set the GL-Sync mode for a specified display. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in] iAdapterIndex The ADL index handle of the desired adapter. 
///   [in] iDisplayIndex The desired display index. 
///   [in] glSyncMode    The ADLGlSyncMode structure describing the GL-Sync mode to set for the specified display. 
/// 
/// Returns
///   If the function is successful, ADL_OK is returned. ADL_OK_MODE_CHANGE if success but need mode change,
/// If iAdapterIndex is an invalid adapter index, ADL_ERR_INVALID_ADL_IDX is returned. If the function is not supported, ADL_ERR_NOT_SUPPORTED is returned. For all other errors, ADL_ERR is returned.
int ADL_Workstation_DisplayGLSyncMode_Set ( int           iAdapterIndex,
                                            int           iDisplayIndex,
                                            ADLGlSyncMode glSyncMode
                                          );


/// Function to get ECC (Error Correction Code) Capabilities on the specified adapter. This function implements the CI call to get ECC (Error Correction Code) Capabilities on the specified adapter. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in]  iAdapterIndex - The index of the desired adapter. 
///   [out] lpSupported   - returns the bolean capability, whether ECC is supported or not(ADL_TRUE or ADL_FALSE) for the specified adapter 
/// 
/// Returns
///   If the function is successful, ADL_OK is returned, If iAdapterIndex is an invalid adapter index, ADL_ERR_INVALID_ADL_IDX is returned. If the function is not supported, ADL_ERR_NOT_SUPPORTED is returned. For all other errors, ADL_ERR is returned.
int ADL_Workstation_ECC_Caps ( int   iAdapterIndex,
                               int * lpSupported
                             );


/// Function to get ECC (Error Correction Code) current and desired states on the specified adapter. This function implements the CI call to get ECC (Error Correction Code) current mode(driver applied mode) and the desired mode (user requested mode) on the specified adapter. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in]  iAdapterIndex - The index of the desired adapter. 
///   [out] lpDefaultMode - Default ECC Mode (ECC_MODE_OFF, ECC_MODE_ON).Define_ecc_mode_states. 
///   [out] lpCurrentMode - ECC Mode that is currently stored in the permanent store for driver. (ECC_MODE_OFF, ECC_MODE_ON).Define_ecc_mode_states. 
///   [out] lpDesiredMode - Desired ECC mode from the user, once the user reboots the machine DesiredMode will be applied to CurrentMode (ECC_MODE_OFF, ECC_MODE_ON). Define_ecc_mode_states. 
/// 
/// Returns
///   If the function is successful, ADL_OK is returned, If iAdapterIndex is an invalid adapter index, ADL_ERR_INVALID_ADL_IDX is returned. If the function is not supported, ADL_ERR_NOT_SUPPORTED is returned. For all other errors, ADL_ERR is returned.
int ADL_Workstation_ECC_Get ( int   iAdapterIndex,
                              int * lpDefaultMode,
                              int * lpCurrentMode,
                              int * lpDesiredMode
                            );


/// Function to set ECC Mode on the specified adapter This function implements the CI call to set ECC (Error Correction Code) to turn on and off this feature on the specified adapter. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in] iAdapterIndex - The index of the desired adapter. 
///   [in] iDesiredMode  - ECC Mode currently accepts ECC_MODE_OFF or ECC_MODE_ON. Define_ecc_mode_states 
/// 
/// Returns
///   If the function is successful, ADL_OK is returned, If iAdapterIndex is an invalid adapter index, ADL_ERR_INVALID_ADL_IDX is returned. If the function is not supported, ADL_ERR_NOT_SUPPORTED is returned. For all other errors, ADL_ERR is returned.
int ADL_Workstation_ECC_Set ( int iAdapterIndex,
                              int iDesiredMode
                            );


/// Function to get ECC statistics on the specified adapter. This function implements the CI call to get SEC(Single Error Correct) and DED(Double Error Detect) Counts on the specified adapter. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in]  iAdapterIndex - The index of the desired adapter. 
///   [out] lpAdlEccData  - is of type ADLECCData. Gets the SEC & DED counts ADLECCData 
/// 
/// Returns
///   If the function is successful, ADL_OK is returned, If iAdapterIndex is an invalid adapter index, ADL_ERR_INVALID_ADL_IDX is returned. If the function is not supported, ADL_ERR_NOT_SUPPORTED is returned. For all other errors, ADL_ERR is returned.
int ADL_Workstation_ECCData_Get ( int          iAdapterIndex,
                                  ADLECCData * lpAdlEccData
                                );


/// Function to get ECC (Error Correction Code) current and desired states on the specified adapter. This function implements the CI call to get ECC (Error Correction Code) current mode(driver applied mode) and the desired mode (user requested mode) on the specified adapter. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in]  iAdapterIndex - The index of the desired adapter. 
///   [out] lpModeType    - Default ECC Mode (ECC_MODE_OFF, ECC_MODE_ON, ECC_MODE_HBM).Define_ecc_mode_states. 
///   [out] lpDefaultMode - Default ECC Mode (ECC_MODE_OFF, ECC_MODE_ON, ECC_MODE_HBM).Define_ecc_mode_states. 
///   [out] lpCurrentMode - ECC Mode that is currently stored in the permanent store for driver. (ECC_MODE_OFF, ECC_MODE_ON, ECC_MODE_HBM).Define_ecc_mode_states. 
///   [out] lpDesiredMode - Desired ECC mode from the user, once the user reboots the machine DesiredMode will be applied to CurrentMode (ECC_MODE_OFF, ECC_MODE_ON, ECC_MODE_HBM). Define_ecc_mode_states. 
/// 
/// Returns
///   If the function is successful, ADL_OK is returned, If iAdapterIndex is an invalid adapter index, ADL_ERR_INVALID_ADL_IDX is returned. If the function is not supported, ADL_ERR_NOT_SUPPORTED is returned. For all other errors, ADL_ERR is returned.
int ADL_Workstation_ECCX2_Get ( int   iAdapterIndex,
                                int * lpModeType,
                                int * lpDefaultMode,
                                int * lpCurrentMode,
                                int * lpDesiredMode
                              );


/// Function to retrieve the GL-Sync Genlock configuration settings. 
/// 
/// This function retrieves the Genlock configuration settings of a specific GPU connector on a GL-Sync module attached to a specified adapter on a GL-Sync connector. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in]  iAdapterIndex         The ADL index handle of the desired adapter. 
///   [in]  iGlSyncConnector      The index of the desired GL-Sync connector. The index can range from 0 to NumOfGLSyncConnectors - 1. 
///   [in]  iGlValidMask          The mask indicating the Genlock settings to be retrieved (bit field of ADL_GLSYNC_CONFIGMASK_*). Genlock related values 
///   [out] lpGlSyncGenlockConfig The pointer to the ADLGLSyncGenlockConfig structure with the retrieved Genlock settings. 
/// 
/// Returns
///   If the function is successful, ADL_OK is returned. If iAdapterIndex is an invalid adapter index, ADL_ERR_INVALID_ADL_IDX is returned.
/// If the function is not supported, ADL_ERR_NOT_SUPPORTED is returned. For all other errors, ADL_ERR is returned.
int ADL_Workstation_GLSyncGenlockConfiguration_Get ( int                      iAdapterIndex,
                                                     int                      iGlSyncConnector,
                                                     int                      iGlValidMask,
                                                     ADLGLSyncGenlockConfig * lpGlSyncGenlockConfig
                                                   );


/// Function to set the GL-Sync Genlock configuration settings. 
/// 
/// This function sets the Genlock configuration settings of a specific GPU connector on a GL-Sync module attached to a specified adapter on a GL-Sync connector. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in] iAdapterIndex       The ADL index handle of the desired adapter. 
///   [in] iGlSyncConnector    The index of the desired GL-Sync connector. The index can range from 0 to NumOfGLSyncConnectors - 1. 
///   [in] glSyncGenlockConfig The Genlock settings to be set in ADLGLSyncGenlockConfig structure 
/// 
/// Returns
///   If the function is successful, ADL_OK is returned. If iAdapterIndex is an invalid adapter index, ADL_ERR_INVALID_ADL_IDX is returned.
/// If the function is not supported, ADL_ERR_NOT_SUPPORTED is returned. For all other errors, ADL_ERR is returned.
int ADL_Workstation_GLSyncGenlockConfiguration_Set ( int                    iAdapterIndex,
                                                     int                    iGlSyncConnector,
                                                     ADLGLSyncGenlockConfig glSyncGenlockConfig
                                                   );


/// Function to detect the GL-Sync module. 
/// 
/// This function detects the GL-Sync module attached to a specified adapter and GL-Sync connector. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in]  iAdapterIndex    The ADL index handle of the desired adapter. 
///   [in]  iGlSyncConnector The index of the desired GL-Sync connector. The index can range from 0 to NumOfGLSyncConnectors - 1. 
///   [out] lpGlSyncModuleID The pointer to the retrieved GL-Sync module information. If no GL-Sync module is attached, lpGlSyncModuleID->ulModuleID is set to 0. 
/// 
/// Returns
///   If the function is successful, ADL_OK is returned. If iAdapterIndex is an invalid adapter index, ADL_ERR_INVALID_ADL_IDX is returned.
/// If the function is not supported, ADL_ERR_NOT_SUPPORTED is returned. For all other errors, ADL_ERR is returned.
int ADL_Workstation_GLSyncModuleDetect_Get ( int                 iAdapterIndex,
                                             int                 iGlSyncConnector,
                                             ADLGLSyncModuleID * lpGlSyncModuleID
                                           );


/// Function to describe the GL-Sync module caps. 
/// 
/// This function describes the hardware capabilities of the GL-Sync module attached to a specific adapter and GL-Sync connector.
/// 
/// This API uses the Caller's Memory Allocation Callback Function to allocate memory pointed by ppGlSyncPorts. Caller is responsible to de-alocate the memory. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in]  iAdapterIndex       The ADL index handle of the desired adapter. 
///   [in]  iGlSyncConnector    The index of the desired GL-Sync connector. The index can range from 0 to NumOfGLSyncConnectors - 1. 
///   [out] lpNumGLSyncGPUPorts The pointer to the number of GPU ports on the specified GL-Sync module. 
///   [out] lpNumGlSyncPorts    The pointer to the number of external ports (RJ45/BNC) on the specified GL-Sync module. 
///   [out] lpMaxSyncDelay      The pointer to the maximum value of the sync delay Genlock setting. 
///   [out] lpMaxSampleRate     The pointer to the maximum value of the sample rate Genlock setting. 
///   [out] ppGlSyncPorts       The pointer to the pointer to the retrieved information about the external ports on the specified GL-Sync connector.
/// The user passes a memory allocation callback to allocate memory for this and to free the memory once done with it. 
/// 
/// Returns
///   If the function is successful, ADL_OK is returned. If iAdapterIndex is an invalid adapter index, ADL_ERR_INVALID_ADL_IDX is returned.
/// If the function is not supported, ADL_ERR_NOT_SUPPORTED is returned. For all other errors, ADL_ERR is returned.
int ADL_Workstation_GLSyncModuleInfo_Get ( int                  iAdapterIndex,
                                           int                  iGlSyncConnector,
                                           int *                lpNumGLSyncGPUPorts,
                                           int *                lpNumGlSyncPorts,
                                           int *                lpMaxSyncDelay,
                                           int *                lpMaxSampleRate,
                                           ADLGLSyncPortCaps ** ppGlSyncPorts
                                         );


/// Function to retrieve GL-Sync port information. 
/// 
/// This function implements the DI call to retrieve the information about a GL-Sync port of a specified GL-Sync module and adapter. This API uses the Caller's Memory Allocation Callback Function to allocate memory pointed by ppGlSyncLEDs. Caller is responsible to de-alocate the memory. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in]  iAdapterIndex    The ADL index handle of the desired adapter. 
///   [in]  iGlSyncConnector The index of the desired GL-Sync connector. The index can range from 0 to NumOfGLSyncConnectors - 1. 
///   [in]  iGlSyncPortType  The desired GL-Sync port (ADL_GLSYNC_PORT_*). Genlock related values 
///   [in]  iNumLEDs         The number of LEDs for the specified port. If the number of LEDs is unknown, specify a value of 0. 
///   [out] lpGlSyncPortInfo The pointer to the retrieved port information in ADLGlSyncPortInfo structure 
///   [out] ppGlSyncLEDs     The pointer to the pointer to the retrieved information about the LEDs associated to the specified GL-Sync connector.
/// The user must pass a memory allocation callback to allocate memory for this and to free the memory once done with it. 
/// 
/// Returns
///   If the function is successful, ADL_OK is returned. If iAdapterIndex is an invalid adapter index, ADL_ERR_INVALID_ADL_IDX is returned.
/// If the function is not supported, ADL_ERR_NOT_SUPPORTED is returned. For all other errors, ADL_ERR is returned.
int ADL_Workstation_GLSyncPortState_Get ( int                 iAdapterIndex,
                                          int                 iGlSyncConnector,
                                          int                 iGlSyncPortType,
                                          int                 iNumLEDs,
                                          ADLGlSyncPortInfo * lpGlSyncPortInfo,
                                          int **              ppGlSyncLEDs
                                        );


/// Function to perform GL-Sync port control. 
/// 
/// This function implements the DI call to enable or disable an output signal on the RJ-45 ports of a specified GL-Sync module and adapter. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in] iAdapterIndex     The ADL index handle of the desired adapter. 
///   [in] iGlSyncConnector  The index of the desired GL-Sync connector. The index can range from 0 to NumOfGLSyncConnectors - 1. 
///   [in] glSyncPortControl The ADLGlSyncPortControl structure to be set. 
/// 
/// Returns
///   If the function is successful, ADL_OK is returned. If iAdapterIndex is an invalid adapter index, ADL_ERR_INVALID_ADL_IDX is returned.
/// If the function is not supported, ADL_ERR_NOT_SUPPORTED is returned. For all other errors, ADL_ERR is returned.
int ADL_Workstation_GLSyncPortState_Set ( int                  iAdapterIndex,
                                          int                  iGlSyncConnector,
                                          ADLGlSyncPortControl glSyncPortControl
                                        );


/// Function to get the supported GL-Sync topology. 
/// 
/// This function implements the DI call to set the GL-Sync mode for a specified display. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in]  iAdapterIndex    The ADL index handle of the desired adapter. 
///   [in]  iNumSyncModes    
///   [in]  glSyncModes      
///   [out] iNumSugSyncModes 
///   [out] glSugSyncModes   
/// 
/// Returns
///   If the function is successful, ADL_OK is returned.
/// If iAdapterIndex is an invalid adapter index, ADL_ERR_INVALID_ADL_IDX is returned. If the function is not supported, ADL_ERR_NOT_SUPPORTED is returned. For all other errors, ADL_ERR is returned.
int ADL_Workstation_GLSyncSupportedTopology_Get ( int               iAdapterIndex,
                                                  int               iNumSyncModes,
                                                  ADLGlSyncMode2 *  glSyncModes,
                                                  int *             iNumSugSyncModes,
                                                  ADLGlSyncMode2 ** glSugSyncModes
                                                );


/// Function to set the load balancing capabilities for the specified adapter. 
/// 
/// This function implements the CI call to Get the load balancing caps for a specified adapter. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in]  iAdapterIndex The ADL index handle of the desired adapter. 
///   [out] lpResultMask  The int pointer to the mask bits of load balancing of the specified adapter, It can be combination of ADL_WORKSTATION_LOADBALANCING_SUPPORTED, ref ADL_WORKSTATION_LOADBALANCING_AVAILABLE. 
///   [out] lpResultValue The int pointer to the capable load balancing bits of the specified adapter. It can be combination of ADL_WORKSTATION_LOADBALANCING_SUPPORTED, ref ADL_WORKSTATION_LOADBALANCING_AVAILABLE 
/// 
/// Returns
///   If the function is successful, ADL_OK is returned. ADL_OK_MODE_CHANGE if success but need mode change,
/// If iAdapterIndex is an invalid adapter index, ADL_ERR_INVALID_ADL_IDX is returned. If the function is not supported, ADL_ERR_NOT_SUPPORTED is returned. For all other errors, ADL_ERR is returned.
int ADL_Workstation_LoadBalancing_Caps ( int   iAdapterIndex,
                                         int * lpResultMask,
                                         int * lpResultValue
                                       );


/// Function to get the load balancing state of the specified adapter. 
/// 
/// This function implements the PCS access to Get the load balancing state for a specified adapter. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [out] lpResultMask     The int pointer to mask bit of state. It can be combination of ADL_WORKSTATION_LOADBALANCING_DISABLED, ref ADL_WORKSTATION_LOADBALANCING_ENABLED. 
///   [out] lpCurResultValue The int pointer to the current state It can be one of ADL_WORKSTATION_LOADBALANCING_DISABLED, ref ADL_WORKSTATION_LOADBALANCING_ENABLED. 
///   [out] lpDefResultValue The int pointer to the dafault state It can be one of ADL_WORKSTATION_LOADBALANCING_DISABLED, ref ADL_WORKSTATION_LOADBALANCING_ENABLED. 
/// 
/// Returns
///   If the function is successful, ADL_OK is returned. ADL_OK_MODE_CHANGE if success but need mode change,
/// If iAdapterIndex is an invalid adapter index, ADL_ERR_INVALID_ADL_IDX is returned. If the function is not supported, ADL_ERR_NOT_SUPPORTED is returned. For all other errors, ADL_ERR is returned.
int ADL_Workstation_LoadBalancing_Get ( int * lpResultMask,
                                        int * lpCurResultValue,
                                        int * lpDefResultValue
                                      );


/// Function to set the load balancing state of the specified adapter. 
/// 
/// This function implements the PCS access to set the load balancing mode for a specified adapter. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in] iCurState The current state to set for the specified adapter. 
/// 
/// Returns
///   If the function is successful, ADL_OK is returned. ADL_OK_MODE_CHANGE if success but need mode change,
/// If iAdapterIndex is an invalid adapter index, ADL_ERR_INVALID_ADL_IDX is returned. If the function is not supported, ADL_ERR_NOT_SUPPORTED is returned. For all other errors, ADL_ERR is returned.
int ADL_Workstation_LoadBalancing_Set ( );


/// Function to check for Serial Digital Interface capabilities. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in]  iAdapterIndex,ADL index handle of the desired adapter. 
///   [out] lpSupported,The   pointer to the caps of adapter settings. If the specified adapter supports SDI, it is set to ADL_TRUE, else set to ADL_FALSE 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK (zero). Otherwise the return value is an ADL error code (non-zero). Result Codes
int ADL_Workstation_SDI_Caps ( int   iAdapterIndex,
                               int * lpSupported
                             );


/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in]  iAdapterIndex,ADL index handle of the desired adapter. 
///   [out] lpDefualt,pointer to the default SDI settings of the specified adapter. 
///   [out] lpCurrent,pointer to the driver SDI settings of the specified adapter. 
///   [out] lpDriver,pointer  to the user requested SDI seetings of the specified adapter. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK (zero). Otherwise the return value is an ADL error code (non-zero). Result Codes
int ADL_Workstation_SDI_Get ( int          iAdapterIndex,
                              ADLSDIData * lpDefualt,
                              ADLSDIData * lpDriver,
                              ADLSDIData * lpCurrent
                            );


/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in] iAdapterIndex,ADL      index handle of the desired adapter. 
///   [in] iSDIState,SDI          state (possiable values ADL_SDI_ON or ADL_SDI_OFF 
///   [in] iSizeofSDISegment,size of the apreture 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK (zero). Otherwise the return value is an ADL error code (non-zero). Result Codes
int ADL_Workstation_SDI_Set ( int iAdapterIndex,
                              int iSDIState,
                              int iSizeofSDISegment
                            );


/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in]  iAdapterIndex,ADL            index handle of the desired adapter. 
///   [out] lpMemorySegmentCount,pointer to the supported memory segment count of the specified adapter 
///   [out] lppMemorySegmentList,pointer to the supported memory segment list of the specified adapter 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK (zero). Otherwise the return value is an ADL error code (non-zero). Result Codes
int ADL_Workstation_SDISegmentList_Get ( int    iAdapterIndex,
                                         int *  lpMemorySegmentCount,
                                         int ** lppMemorySegmentList
                                       );


/// Function to retreive the worstation stereo mode. 
/// 
/// This function retrieves the current and default workstation stereo mode. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in]  iAdapterIndex The ADL index handle of the desired adapter. 
///   [out] lpDefState    The pointer to the default stereo mode. Workstation Capabilities 
///   [out] lpCurState    The pointer to the current stereo mode. Workstation Capabilities 
/// 
/// Returns
///   If the function is successful, ADL_OK is returned. If lpDefState and/or lpCurState are NULL, ADL_ERR_NULL_POINTER is returned.
/// If iAdapterIndex is an invalid adapter index, ADL_ERR_INVALID_ADL_IDX is returned. If the function is not supported, ADL_ERR_NOT_SUPPORTED is returned. For all other errors, ADL_ERR is returned.
int ADL_Workstation_Stereo_Get ( int   iAdapterIndex,
                                 int * lpDefState,
                                 int * lpCurState
                               );


/// Function to set the workstation stereo mode. 
/// 
/// This function sets the current workstation stereo mode. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in] iAdapterIndex The ADL index handle of the desired adapter. 
///   [in] iCurState     The desired workstation stereo mode. Workstation Capabilities 
/// 
/// Returns
///   If the function is successful, ADL_OK is returned. If iAdapterIndex is an invalid adapter index, ADL_ERR_INVALID_ADL_IDX is returned.
/// If the function is not supported, ADL_ERR_NOT_SUPPORTED is returned. For all other errors, ADL_ERR is returned.
int ADL_Workstation_Stereo_Set ( int iAdapterIndex,
                                 int iCurState
                               );


#endif /* ADL_HEADER_WORKSTATION_H_ */
