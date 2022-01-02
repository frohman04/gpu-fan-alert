#ifndef ADL_HEADER_DISPLAY_H_
#define ADL_HEADER_DISPLAY_H_

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

/// Function to retrieve Timing Override support. 
/// 
/// This function retrieves Timing Override support for a specified display. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in]  context       Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in]  iAdapterIndex The ADL index handle of the desired adapter. 
///   [out] lpSupported   If the specified adapter supports Custom Resolutions then returns ADL_TRUE else ADL_FALSE 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes 
/// 
/// Remarks
///   Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call ADL2_Main_Control_Create first to obtain ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using ADL2_Main_Control_Destroy.
int ADL2_Adapter_ModeTimingOverride_Caps ( ADL_CONTEXT_HANDLE context,
                                           int                iAdapterIndex,
                                           int *              lpSupported
                                         );


/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in] context       Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in] iAdapterIndex The index of the desired adapter. 
///   [in] iSupported    The pointer to an int variable which indicates if VariBright is supported ( ADL_TRUE : supported, ADL_FALSE : not supported) 
///   [in] iEnabled      The pointer to an int variable which indicates if VariBright is enabled ( ADL_TRUE : enabled, ADL_FALSE : disabled) 
///   [in] iEnabled      The pointer to an int variable receiving the VariBright version. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK (zero). Otherwise the return value is an ADL error code (non-zero). Result Codes
/// 
/// Remarks
///   Call this API first. Only if VariBright feature is supported and enabled call ADL_Adapter_VariBrightLevel_Get() or ADL_Adapter_VariBrightLevel_Set()
int ADL2_Adapter_VariBright_Caps ( ADL_CONTEXT_HANDLE context,
                                   int                iAdapterIndex,
                                   int *              iSupported,
                                   int *              iEnabled,
                                   int *              iVersion
                                 );


/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in] context       Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in] iAdapterIndex The index of the desired adapter. 
///   [in] iEnabled      ADL_TRUE : enables VariBright, ADL_FALSE : disables VariBright. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK (zero). Otherwise the return value is an ADL error code (non-zero). Result Codes
/// 
/// Remarks
///   Call ADL_Adapter_VariBright_CapsX2() first to determine if VariBright feature is supported.
int ADL2_Adapter_VariBrightEnable_Set ( ADL_CONTEXT_HANDLE context,
                                        int                iAdapterIndex,
                                        int                iEnabled
                                      );


/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in] context         Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in] iAdapterIndex   The index of the desired adapter. 
///   [in] iDefaultLevel   The pointer to an int variable with the default VariBright level. 
///   [in] iNumberOfLevels The pointer to an int variable receiving the number of VariBright levels (the Maximum value for VariBright level). 
///   [in] iStep           The pointer to an int variable receiving the VariBright step. Determines the increments of the VariBright transition from one level to another. 
///   [in] iCurrentLevel   The pointer to an int variable receiving the Current VariBright level. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK (zero). Otherwise the return value is an ADL error code (non-zero). Result Codes
/// 
/// Remarks
///   Call ADL_Adapter_VariBright_CapsX2() first to determine if VariBright feature is supported.
int ADL2_Adapter_VariBrightLevel_Get ( ADL_CONTEXT_HANDLE context,
                                       int                iAdapterIndex,
                                       int *              iDefaultLevel,
                                       int *              iNumberOfLevels,
                                       int *              iStep,
                                       int *              iCurrentLevel
                                     );


/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in] context           Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in] iAdapterIndex     The index of the desired adapter. 
///   [in] iCurrentLevel     The VariBright level to be set. The range is from zero to iNumberOfLevels returned from ADL_Adapter_VariBrightLevel_Get() 
///   [in] iApplyImmediately If set to ADL_TRUE the VariBright level is applied immediately. If ADL_FALSE - the level is applied gradually. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK (zero). Otherwise the return value is an ADL error code (non-zero). Result Codes.
/// 
/// Remarks
///   Call ADL_Adapter_VariBright_CapsX2() first to determine if VariBright feature is supported.
int ADL2_Adapter_VariBrightLevel_Set ( ADL_CONTEXT_HANDLE context,
                                       int                iAdapterIndex,
                                       int                iCurrentLevel,
                                       int                iApplyImmediately
                                     );


/// Function to set the current EDS mode enumeration mode. 
/// 
/// This function sets the current EDS mode enumeration mode: Safe or Unsafe(raw modes). 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in] context       Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in] iAdapterIndex The ADL index handle of the desired adapter. 
///   [in] unsafeMode    The EDS mode enumeration mode to set (0: Safe mode, 1: Unsafe mode). 
/// 
/// Returns
///   Succeed: ADL_OK. Otherwise: ADL error code Result Codes
int ADL2_CDS_UnsafeMode_Set ( ADL_CONTEXT_HANDLE context,
                              int                iAdapterIndex,
                              int                unsafeMode
                            );


/// Function to retrieve the settings of the CV dongle. 
/// 
/// This function retrieves the CV dongle settings. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in]  context                     Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in]  iAdapterIndex               The ADL index handle of the desired adapter. 
///   [in]  iDisplayIndex               The desired display index. It can be retrieved from the ADLDisplayInfo data structure. 
///   [out] lpDongleSetting             The pointer to the CV dongle settings. 
///   [out] lpOverrideSettingsSupported The pointer to the supported override settings. 
///   [out] lpCurOverrideSettings       The pointer to the current CV override settings.
/// Values used by ADL_CV_DongleSettings_xxx 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes 
/// 
/// Remarks
///   Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call ADL2_Main_Control_Create first to obtain ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using ADL2_Main_Control_Destroy. 
/// Deprecated:
///   Dropping support for component, composite, and S-Video connectors.
int ADL2_CV_DongleSettings_Get ( ADL_CONTEXT_HANDLE context,
                                 int                iAdapterIndex,
                                 int                iDisplayIndex,
                                 int *              lpDongleSetting,
                                 int *              lpOverrideSettingsSupported,
                                 int *              lpCurOverrideSettings
                               );


/// Function to reset the CV settings to its default settings. 
/// 
/// This function resets the CV dongle settings. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in] context       Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in] iAdapterIndex The ADL index handle of the desired adapter. 
///   [in] iDisplayIndex The desired display index. It can be retrieved from the ADLDisplayInfo data structure. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes
/// 
/// Remarks
///   Call ADL_Flush_Driver_Data() after to persist settings on reboot. 
/// Deprecated:
///   Dropping support for component, composite, and S-Video connectors.
int ADL2_CV_DongleSettings_Reset ( ADL_CONTEXT_HANDLE context,
                                   int                iAdapterIndex,
                                   int                iDisplayIndex
                                 );


/// Function to set the current CV dongle settings. 
/// 
/// This function sets the current CV dongle settings to a specified setting. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in] context           Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in] iAdapterIndex     The ADL index handle of the desired adapter. 
///   [in] iDisplayIndex     The desired display index. It can be retrieved from the ADLDisplayInfo data structure. 
///   [in] iOverrideSettings The new CV settings. Values used by ADL_CV_DongleSettings_xxx 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes
/// 
/// Remarks
///   Call ADL_Flush_Driver_Data() after to persist settings on reboot. 
/// Deprecated:
///   Dropping support for component, composite, and S-Video connectors.
int ADL2_CV_DongleSettings_Set ( ADL_CONTEXT_HANDLE context,
                                 int                iAdapterIndex,
                                 int                iDisplayIndex,
                                 int                iOverrideSettings
                               );


/// Function to get the Allow Only CE Timings setting. 
/// 
/// This function sets the Allow Only CE Timings setting for a specified display. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in] context       Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in] iAdapterIndex The ADL index handle of the desired adapter. 
///   [in] iDisplayIndex The desired display index. It can be retrieved from the ADLDisplayInfo data structure. 
///   [in] lpSupport     The pointer to the value indicating whether AllowOnlyCETimings is supported. 1: supported; 0: not supported. 
///   [in] lpCurrent     The pointer to the value indicating whether AllowOnlyCETimings is currently enabled. 1: enabled; 0: disabled. 
///   [in] lpDefault     The pointer to the AllowOnlyCETimings default setting. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK, ADL_ERR_NULL_POINTER if any of the inputs is NULL, Otherwise the return value is an ADL_ERR. Result Codes 
/// 
/// Remarks
///   Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call ADL2_Main_Control_Create first to obtain ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using ADL2_Main_Control_Destroy.
int ADL2_DFP_AllowOnlyCETimings_Get ( ADL_CONTEXT_HANDLE context,
                                      int                iAdapterIndex,
                                      int                iDisplayIndex,
                                      int *              lpSupport,
                                      int *              lpCurrent,
                                      int *              lpDefault
                                    );


/// Function to set the Allow Only CE Timings setting. 
/// 
/// This function sets the Allow Only CE Timings setting for a specified display. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in] context       Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in] iAdapterIndex The ADL index handle of the desired adapter. 
///   [in] iDisplayIndex The desired display index. It can be retrieved from the ADLDisplayInfo data structure. 
///   [in] iCurrent      The desired Allow Only CE Timings state for the specified display. 1: enabled; 0: disabled.. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes
/// 
/// Remarks
///   Call ADL_Flush_Driver_Data() after to persist settings on reboot.
int ADL2_DFP_AllowOnlyCETimings_Set ( ADL_CONTEXT_HANDLE context,
                                      int                iAdapterIndex,
                                      int                iDisplayIndex,
                                      int                iCurrent
                                    );


/// Function to get the display base audio support. 
/// 
/// This function determines whether base display audio support is available. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in]  context       Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in]  iAdapterIndex The ADL index handle of the desired adapter. 
///   [in]  iDisplayIndex The desired display index. It can be retrieved from the ADLDisplayInfo data structure. 
///   [out] lpSupport     The int pointer to the value indicating whether the feature is supported by the driver. 1: feature is supported; 0: feature is not supported. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes 
/// 
/// Remarks
///   Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call ADL2_Main_Control_Create first to obtain ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using ADL2_Main_Control_Destroy.
int ADL2_DFP_BaseAudioSupport_Get ( ADL_CONTEXT_HANDLE context,
                                    int                iAdapterIndex,
                                    int                iDisplayIndex,
                                    int *              lpSupport
                                  );


/// Function to get the GPUScalingEnable setting. 
/// 
/// This function sets the GPU Scaling Enable setting for a specified display. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in] context       Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in] iAdapterIndex The ADL index handle of the desired adapter. 
///   [in] iDisplayIndex The desired display index. It can be retrieved from the ADLDisplayInfo data structure. 
///   [in] lpSupport     The pointer to the value indicating whether GPUScalingEnable is supported. 1: supported; 0: not supported. 
///   [in] lpCurrent     The pointer to the value indicating whether GPUScalingEnable is currently enabled. 1: enabled; 0: disabled. 
///   [in] lpDefault     The pointer to the GPUScalingEnable default setting. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK, ADL_ERR_NULL_POINTER if any of the inputs is NULL, Otherwise the return value is an ADL_ERR. Result Codes 
/// 
/// Remarks
///   Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call ADL2_Main_Control_Create first to obtain ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using ADL2_Main_Control_Destroy.
int ADL2_DFP_GPUScalingEnable_Get ( ADL_CONTEXT_HANDLE context,
                                    int                iAdapterIndex,
                                    int                iDisplayIndex,
                                    int *              lpSupport,
                                    int *              lpCurrent,
                                    int *              lpDefault
                                  );


/// Function to set the GPUScalingEnable setting. 
/// 
/// This function sets the GPU Scaling Enable setting for a specified display. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in] context       Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in] iAdapterIndex The ADL index handle of the desired adapter. 
///   [in] iDisplayIndex The desired display index. It can be retrieved from the ADLDisplayInfo data structure. 
///   [in] iCurrent      The desired GPU Scaling Enable state for the specified display. 1: enabled; 0: disabled.. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes
/// 
/// Remarks
///   Call ADL_Flush_Driver_Data() after to persist settings on reboot.
int ADL2_DFP_GPUScalingEnable_Set ( ADL_CONTEXT_HANDLE context,
                                    int                iAdapterIndex,
                                    int                iDisplayIndex,
                                    int                iCurrent
                                  );


/// Function to get the display HDMI support. 
/// 
/// This function determines whether the base display HDMI support is available. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in]  context       Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in]  iAdapterIndex The ADL index handle of the desired adapter. 
///   [in]  iDisplayIndex The desired display index. It can be retrieved from the ADLDisplayInfo data structure. 
///   [out] lpSupport     The int pointer indicating whether the feature is supported by the driver. If the feature is supported, a value of 1 is stored. Otherwise, a value of 0 is stored. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes 
/// 
/// Remarks
///   Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call ADL2_Main_Control_Create first to obtain ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using ADL2_Main_Control_Destroy.
int ADL2_DFP_HDMISupport_Get ( ADL_CONTEXT_HANDLE context,
                               int                iAdapterIndex,
                               int                iDisplayIndex,
                               int *              lpSupport
                             );


/// Function to get the display MVPU analog support. 
/// 
/// This function determines whether display MVPU analog support is available. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in]  context       Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in]  iAdapterIndex The ADL index handle of the desired adapter. 
///   [in]  iDisplayIndex The desired display index. It can be retrieved from the ADLDisplayInfo data structure. 
///   [out] lpSupport     The int pointer to the value indicating whether the feature is supported by the driver. 1: feature is supported; 0: feature is not supported. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes 
/// 
/// Remarks
///   Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call ADL2_Main_Control_Create first to obtain ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using ADL2_Main_Control_Destroy.
int ADL2_DFP_MVPUAnalogSupport_Get ( ADL_CONTEXT_HANDLE context,
                                     int                iAdapterIndex,
                                     int                iDisplayIndex,
                                     int *              lpSupport
                                   );


/// Function to retrieve PixelFormat caps. 
/// 
/// This function retrieves the pixel format caps for a specified display. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in]  context       Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in]  iAdapterIndex The ADL index handle of the desired adapter. 
///   [in]  iDisplayIndex The desired display index. It can be retrieved from the ADLDisplayInfo data structure. 
///   [out] lpValidBits   The pointer to the bit field indicating which bits in the lpValidCaps parameter are valid. 
///   [out] lpValidCaps   The pointer to the valid pixel formats caps. Pixel Formats values 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes
/// 
/// Remarks
///   This API is supported only by HDMI.
int ADL2_DFP_PixelFormat_Caps ( ADL_CONTEXT_HANDLE context,
                                int                iAdapterIndex,
                                int                iDisplayIndex,
                                int *              lpValidBits,
                                int *              lpValidCaps
                              );


/// Function to retrieve current pixel format setting. 
/// 
/// This function retrieves the pixel format setting for a specified display. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in]  context       Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in]  iAdapterIndex The ADL index handle of the desired adapter. 
///   [in]  iDisplayIndex The desired display index. It can be retrieved from the ADLDisplayInfo data structure. 
///   [out] lpCurState    The pointer to the current pixel format of the display. Pixel Formats values 
///   [out] lpDefault     The pointer to the default pixel format of the display. Pixel Formats values 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes
/// 
/// Remarks
///   This API is supported only by HDMI.
int ADL2_DFP_PixelFormat_Get ( ADL_CONTEXT_HANDLE context,
                               int                iAdapterIndex,
                               int                iDisplayIndex,
                               int *              lpCurState,
                               int *              lpDefault
                             );


/// Function to set the current pixel format setting. 
/// 
/// This function sets the pixel format setting for a specified display. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in] context       Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in] iAdapterIndex The ADL index handle of the desired adapter. 
///   [in] iDisplayIndex The desired display index. It can be retrieved from the ADLDisplayInfo data structure. 
///   [in] iState        The desired pixel format for the specified display. Pixel Formats values 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes
/// 
/// Remarks
///   This API is supported only by HDMI.
int ADL2_DFP_PixelFormat_Set ( ADL_CONTEXT_HANDLE context,
                               int                iAdapterIndex,
                               int                iDisplayIndex,
                               int                iState
                             );


/// Function to retrieve the adjustment display information. 
/// 
/// This function retrieves the display adjustment information for a specified adapter and display. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in]  context       Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in]  iAdapterIndex The ADL index handle of the desired adapter. 
///   [in]  iDisplayIndex The desired display index. It can be retrieved from the ADLDisplayInfo data structure. 
///   [out] lpInfo        The pointer to the adjustment information retrieved from the driver.
/// Display Adjustment Capabilities 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes 
/// 
/// Remarks
///   Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call ADL2_Main_Control_Create first to obtain ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using ADL2_Main_Control_Destroy.
int ADL2_Display_AdjustCaps_Get ( ADL_CONTEXT_HANDLE context,
                                  int                iAdapterIndex,
                                  int                iDisplayIndex,
                                  int *              lpInfo
                                );


/// Function to retrieve the adjustment coherent setting. 
/// 
/// This function retrieves the current adjustment coherent setting
/// 
/// It is applicable to DFP/DFP2 display types. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in]  context                     Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in]  iAdapterIndex               The ADL index handle of the desired adapter. 
///   [in]  iDisplayIndex               The desired display index. It can be retrieved from the ADLDisplayInfo data structure. 
///   [out] lpAdjustmentCoherentCurrent The pointer to the retrieved adjustment coherent setting. 1: Coherent; 0: non-coherent 
///   [out] lpAdjustmentCoherentDefault The pointer to the retrieved default setting. 1: Coherent; 0: Non-coherent 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes 
/// 
/// Remarks
///   Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call ADL2_Main_Control_Create first to obtain ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using ADL2_Main_Control_Destroy.
int ADL2_Display_AdjustmentCoherent_Get ( ADL_CONTEXT_HANDLE context,
                                          int                iAdapterIndex,
                                          int                iDisplayIndex,
                                          int *              lpAdjustmentCoherentCurrent,
                                          int *              lpAdjustmentCoherentDefault
                                        );


/// Function to set the adjustment coherent setting. 
/// 
/// This function sets the current adjustment coherent setting to a specified setting. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in] context             Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in] iAdapterIndex       The ADL index handle of the desired adapter. 
///   [in] iDisplayIndex       The desired display index. It can be retrieved from the ADLDisplayInfo data structure. 
///   [in] iAdjustmentCoherent The desired adjustment coherent setting. 1: Coherent; 0: Non-coherent 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes
/// 
/// Remarks
///   Call ADL_Flush_Driver_Data() after to persist settings on reboot.
int ADL2_Display_AdjustmentCoherent_Set ( ADL_CONTEXT_HANDLE context,
                                          int                iAdapterIndex,
                                          int                iDisplayIndex,
                                          int                iAdjustmentCoherent
                                        );


/// Function to get the number of displays and controllers supported by an adapter. 
/// 
/// This function retrieves the number of displays and controllers that are supported by a specified adapter. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in]  context              Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in]  iAdapterIndex        The ADL index handle of the desired adapter. 
///   [out] lpNumberOfControlers The pointer to the variable storing the total number of controllers. This variable must be initialized. 
///   [out] lpNumberOfDisplays   The pointer to the variable storing the total number of displays. This variable must be initialized. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes 
/// 
/// Remarks
///   Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call ADL2_Main_Control_Create first to obtain ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using ADL2_Main_Control_Destroy.
int ADL2_Display_Capabilities_Get ( ADL_CONTEXT_HANDLE context,
                                    int                iAdapterIndex,
                                    int *              lpNumberOfControlers,
                                    int *              lpNumberOfDisplays
                                  );


/// Function to retrieve the detailed information a specified display color item. 
/// 
/// This function retrieves the detailed information for a specified display color. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in]  context       Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in]  iAdapterIndex The ADL index handle of the desired adapter. 
///   [in]  iDisplayIndex The desired display index. It can be retrieved from the ADLDisplayInfo data structure. 
///   [in]  iColorType    The desired color type. It can be any of the defined type. Display Color Type and Source 
///   [out] lpCurrent     The pointer to the current color value. 
///   [out] lpDefault     The pointer to the default color value. 
///   [out] lpMin         The pointer to the minimum color value. 
///   [out] lpMax         The pointer to the maximum color value. 
///   [out] lpStep        The pointer to the increment of the color setting. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes 
/// 
/// Remarks
///   Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call ADL2_Main_Control_Create first to obtain ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using ADL2_Main_Control_Destroy.
int ADL2_Display_Color_Get ( ADL_CONTEXT_HANDLE context,
                             int                iAdapterIndex,
                             int                iDisplayIndex,
                             int                iColorType,
                             int *              lpCurrent,
                             int *              lpDefault,
                             int *              lpMin,
                             int *              lpMax,
                             int *              lpStep
                           );


/// Function to set the current value of a specific color and type. 
/// 
/// 
/// 
/// This function sets the display color for a specified adapter, display, and color type. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in] context       Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in] iAdapterIndex The ADL index handle of the desired adapter. 
///   [in] iDisplayIndex The desired display index. It can be retrieved from the ADLDisplayInfo data structure. 
///   [in] iColorType    The desired color type. It can be any of the defined type. Display Color Type and Source 
///   [in] iCurrent      The desired color value. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes
/// 
/// Remarks
///   Call ADL_Flush_Driver_Data() after to persist settings on reboot.
int ADL2_Display_Color_Set ( ADL_CONTEXT_HANDLE context,
                             int                iAdapterIndex,
                             int                iDisplayIndex,
                             int                iColorType,
                             int                iCurrent
                           );


/// Function to get the Color Caps display information. 
/// 
/// This function retrieves the display Color Caps information for a specified adapter and display. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in]  context       Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in]  iAdapterIndex The ADL index handle of the desired adapter. 
///   [in]  iDisplayIndex The desired display index. It can be retrieved from the ADLDisplayInfo data structure. 
///   [out] lpCaps        The pointer to the Color Caps information retrieved from the driver. Display Color Type and Source 
///   [out] lpValids      The pointer to the bit vector indicating which bit is valid on the lpCaps returned. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes 
/// 
/// Remarks
///   Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call ADL2_Main_Control_Create first to obtain ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using ADL2_Main_Control_Destroy.
int ADL2_Display_ColorCaps_Get ( ADL_CONTEXT_HANDLE context,
                                 int                iAdapterIndex,
                                 int                iDisplayIndex,
                                 int *              lpCaps,
                                 int *              lpValids
                               );


/// Function to get color depth. HDMI and DPonly. 
/// 
/// This function retrieves the current display on given adpaters current color depth. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in]  context       Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in]  iAdapterIndex The ADL index handle of the desired adapter per physical GPU. 
///   [in]  iDisplayIndex The desired display index. It can be retrieved from the ADLDisplayInfo data structure. 
///   [out] lpColorDepth  The pointer to the current color depth setting for given display. Define_colordepth_constants 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes
int ADL2_Display_ColorDepth_Get ( ADL_CONTEXT_HANDLE context,
                                  int                iAdapterIndex,
                                  int                iDisplayIndex,
                                  int *              lpColorDepth
                                );


/// Function to set color depth. HDMI and DPonly. 
/// 
/// This function sets a user select color depth to current display on given adapter. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in] context       Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in] iAdapterIndex The ADL index handle of the desired adapter per physical GPU. 
///   [in] iDisplayIndex The desired display index. It can be retrieved from the ADLDisplayInfo data structure. 
///   [in] iColorDepth   Requested color depth. Define_colordepth_constants 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes
int ADL2_Display_ColorDepth_Set ( ADL_CONTEXT_HANDLE context,
                                  int                iAdapterIndex,
                                  int                iDisplayIndex,
                                  int                iColorDepth
                                );


/// Function to get color temperature source. 
/// 
/// This function retrieves the current color temperature source. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in]  context       Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in]  iAdapterIndex The ADL index handle of the desired adapter. 
///   [in]  iDisplayIndex The desired display index. It can be retrieved from the ADLDisplayInfo data structure. 
///   [out] lpTempSource  The pointer of the retrieved current color temperature source. Display Color Type and Source 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes 
/// 
/// Remarks
///   Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call ADL2_Main_Control_Create first to obtain ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using ADL2_Main_Control_Destroy.
int ADL2_Display_ColorTemperatureSource_Get ( ADL_CONTEXT_HANDLE context,
                                              int                iAdapterIndex,
                                              int                iDisplayIndex,
                                              int *              lpTempSource
                                            );


/// Function to set the color temperature source. 
/// 
/// This function sets the current color temperature source. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in] context       Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in] iAdapterIndex The ADL index handle of the desired adapter. 
///   [in] iDisplayIndex The desired display index. It can be retrieved from the ADLDisplayInfo data structure. 
///   [in] iTempSource   The desired color temperature source. Display Color Type and Source 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes
/// 
/// Remarks
///   Call ADL_Flush_Driver_Data() after to persist settings on reboot.
int ADL2_Display_ColorTemperatureSource_Set ( ADL_CONTEXT_HANDLE context,
                                              int                iAdapterIndex,
                                              int                iDisplayIndex,
                                              int                iTempSource
                                            );


/// Function to get default color temperature source. 
/// 
/// This function retrieves the default color temperature source. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in]  context             Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in]  iAdapterIndex       The ADL index handle of the desired adapter. 
///   [in]  iDisplayIndex       The desired display index. It can be retrieved from the ADLDisplayInfo data structure. 
///   [out] lpTempSourceDefault The pointer of the retrieved default color temperature source. Display Color Type and Source 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes 
/// 
/// Remarks
///   Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call ADL2_Main_Control_Create first to obtain ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using ADL2_Main_Control_Destroy.
int ADL2_Display_ColorTemperatureSourceDefault_Get ( ADL_CONTEXT_HANDLE context,
                                                     int                iAdapterIndex,
                                                     int                iDisplayIndex,
                                                     int *              lpTempSourceDefault
                                                   );


/// Function to indicate whether displays are physically connected to an adapter. 
/// 
/// This function indicates whether displays are physically connected to a specified adapter. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in]  context       Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in]  iAdapterIndex The ADL index handle of the desired adapter. 
///   [out] lpConnections The pointer to the bit field indicating whether the output connectors on the specified adapter have devices physically attached to them. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes 
/// 
/// Remarks
///   Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call ADL2_Main_Control_Create first to obtain ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using ADL2_Main_Control_Destroy.
int ADL2_Display_ConnectedDisplays_Get ( ADL_CONTEXT_HANDLE context,
                                         int                iAdapterIndex,
                                         int *              lpConnections
                                       );


/// Function to get the minimum, maximum, and default values of an overlay adjustment. 
/// 
/// This function retrieves the minimum, maximum, and default values of an overlay adjustment for a specified adapter. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in]     context        Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in]     iAdapterIndex  The ADL index handle of the desired adapter. 
///   [in]     lpOverlayInput The pointer to the ADLControllerOverlayInput structure. 
///   [in,out] lpCapsInfo     The pointer to the ADLControllerOverlayInfo structure storing the retrieved overlay adjustment information. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes 
/// 
/// Remarks
///   Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call ADL2_Main_Control_Create first to obtain ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using ADL2_Main_Control_Destroy.
int ADL2_Display_ControllerOverlayAdjustmentCaps_Get ( ADL_CONTEXT_HANDLE          context,
                                                       int                         iAdapterIndex,
                                                       ADLControllerOverlayInput * lpOverlayInput,
                                                       ADLControllerOverlayInfo *  lpCapsInfo
                                                     );


/// Function to retrieve the current setting of an overlay adjustment. 
/// 
/// This function retrieves the current setting of an overlay adjustment. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in]  context       Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in]  iAdapterIndex The ADL index handle of the desired adapter. 
///   [out] lpOverlay     The pointer to the retrieved overlay adjustment ADLControllerOverlayInput structure. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes 
/// 
/// Remarks
///   Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call ADL2_Main_Control_Create first to obtain ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using ADL2_Main_Control_Destroy.
int ADL2_Display_ControllerOverlayAdjustmentData_Get ( ADL_CONTEXT_HANDLE          context,
                                                       int                         iAdapterIndex,
                                                       ADLControllerOverlayInput * lpOverlay
                                                     );


/// Function to set the current setting of an overlay adjustment. 
/// 
/// This function sets the current setting of an overlay adjustment. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in]     context       Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in]     iAdapterIndex The ADL index handle of the desired adapter. 
///   [in,out] lpOverlay     The pointer to the overlay adjustment ADLControllerOverlayInput structure. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes
/// 
/// Remarks
///   Call ADL_Flush_Driver_Data() after to persist settings on reboot.
int ADL2_Display_ControllerOverlayAdjustmentData_Set ( ADL_CONTEXT_HANDLE          context,
                                                       int                         iAdapterIndex,
                                                       ADLControllerOverlayInput * lpOverlay
                                                     );


/// Function to add a customized mode. 
/// 
/// This function adds a custom mode to the customized mode list. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in] context       Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in] iAdapterIndex The ADL index handle of the desired adapter. 
///   [in] iDisplayIndex The desired display index. It can be retrieved from the ADLDisplayInfo data structure. 
///   [in] customMode    The custom mode to be added to the list. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes
/// 
/// Remarks
///   Call ADL_Flush_Driver_Data() after to persist settings on reboot.
int ADL2_Display_CustomizedMode_Add ( ADL_CONTEXT_HANDLE context,
                                      int                iAdapterIndex,
                                      int                iDisplayIndex,
                                      ADLCustomMode      customMode
                                    );


/// Function to delete a customized mode. 
/// 
/// This function deletes a custom mode from the customized mode list. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in] context       Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in] iAdapterIndex The ADL index handle of the desired adapter. 
///   [in] iDisplayIndex The desired display index. It can be retrieved from the ADLDisplayInfo data structure. 
///   [in] iIndex        The index value of the mode to be deleted. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes
/// 
/// Remarks
///   Call ADL_Flush_Driver_Data() after to persist settings on reboot.
int ADL2_Display_CustomizedMode_Delete ( ADL_CONTEXT_HANDLE context,
                                         int                iAdapterIndex,
                                         int                iDisplayIndex,
                                         int                iIndex
                                       );


/// Function to validate a customized mode. 
/// 
/// This function validates a custom mode from the customized mode list. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in]  context       Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in]  iAdapterIndex The ADL index handle of the desired adapter. 
///   [in]  iDisplayIndex The desired display index. It can be retrieved from the ADLDisplayInfo data structure. 
///   [in]  customMode    The custom mode to be validated. 
///   [out] lpValid       The pointer to the retrieved validation bit. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes 
/// 
/// Remarks
///   Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call ADL2_Main_Control_Create first to obtain ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using ADL2_Main_Control_Destroy.
int ADL2_Display_CustomizedMode_Validate ( ADL_CONTEXT_HANDLE context,
                                           int                iAdapterIndex,
                                           int                iDisplayIndex,
                                           ADLCustomMode      customMode,
                                           int *              lpValid
                                         );


/// Function to retrieve the customized mode list. 
/// 
/// This function retrieves the customized mode list for a specified display. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in]  context          Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in]  iAdapterIndex    The ADL index handle of the desired adapter. 
///   [in]  iDisplayIndex    The desired display index. It can be retrieved from the ADLDisplayInfo data structure. 
///   [out] lpCustomModeList The pointer to the list of the returned ADLCustomMode structures. The user should allocate the memory: Number of modes * sizeof ( ADLCustomMode ) 
///   [in]  iBuffSize        The size of the lpCustomModelist buffer. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes 
/// 
/// Remarks
///   Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call ADL2_Main_Control_Create first to obtain ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using ADL2_Main_Control_Destroy.
int ADL2_Display_CustomizedModeList_Get ( ADL_CONTEXT_HANDLE context,
                                          int                iAdapterIndex,
                                          int                iDisplayIndex,
                                          ADLCustomMode *    lpCustomModeList,
                                          int                iBuffSize
                                        );


/// Function to retrieve the number of customized modes. 
/// 
/// This function retrieves the number of customized modes for a specified display. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in]  context       Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in]  iAdapterIndex The ADL index handle of the desired adapter. 
///   [in]  iDisplayIndex The desired display index. It can be retrieved from the ADLDisplayInfo data structure. 
///   [out] lpListNum     The pointer to the number of available modes. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes 
/// 
/// Remarks
///   Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call ADL2_Main_Control_Create first to obtain ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using ADL2_Main_Control_Destroy.
int ADL2_Display_CustomizedModeListNum_Get ( ADL_CONTEXT_HANDLE context,
                                             int                iAdapterIndex,
                                             int                iDisplayIndex,
                                             int *              lpListNum
                                           );


/// Function to retrieve per display Display Connectivity Experience information. 
/// 
/// This function retrieves the Display Connectivity Experience settings of a display. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in]  context        Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in]  iAdapterIndex  The ADL index handle of the desired adapter. 
///   [in]  iDisplayIndex  The desired display index. It can be retrieved from the ADLDisplayInfo data structure. 
///   [out] lpFreeSyncCaps The pointer to the ADLDceSettings structure 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes 
/// 
/// Remarks
///   Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call ADL2_Main_Control_Create first to obtain ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using ADL2_Main_Control_Destroy.
int ADL2_Display_DCE_Get ( ADL_CONTEXT_HANDLE context,
                           int                iAdapterIndex,
                           int                iDisplayIndex,
                           ADLDceSettings *   lpADLDceSettings
                         );


/// Function to retrieve per display Display Connectivity Experience information. 
/// 
/// This function sets the Display Connectivity Experience settings of a display. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in]  context        Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in]  iAdapterIndex  The ADL index handle of the desired adapter. 
///   [in]  iDisplayIndex  The desired display index. It can be retrieved from the ADLDisplayInfo data structure. 
///   [out] lpFreeSyncCaps The pointer to the ADLDceSettings structure 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes 
/// 
/// Remarks
///   Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call ADL2_Main_Control_Create first to obtain ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using ADL2_Main_Control_Destroy.
int ADL2_Display_DCE_Set ( ADL_CONTEXT_HANDLE context,
                           int                iAdapterIndex,
                           int                iDisplayIndex,
                           ADLDceSettings *   lpADLDceSettings
                         );


/// Function to get Display DDC block access. 
/// 
/// This function provides means for applications to send/receive data in the DDC information block via the 12C bus. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in]  context        Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in]  iAdapterIndex  The ADL index handle of the desired adapter. 
///   [in]  iDisplayIndex  The desired display index. It can be retrieved from the ADLDisplayInfo data structure. 
///   [in]  iOption        Combination of ADL_DDC_OPTION_SWITCHDDC2 and ADL_DDC_OPTION_RESTORECOMMAND 
/// 
///   [in]  iCommandIndex  The index of the command to be saved in the registry. This parameter is used only when ADL_DDC_OPTION_RESTORECOMMAND of iOption is specified. Otherwize set this parameter to 0. 
///   [in]  iSendMsgLen    The size of the send message buffer. 
///   [in]  lpucSendMsgBuf The pointer to the send message buffer. 
///   [out] lpulRecvMsgLen The pointer to the size of the receive message buffer. 
///   [out] lpucRecvMsgBuf The pointer to the retrieved receive message buffer. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes
/// 
/// Remarks
///   To send data without receiving anything back, specify non-zero send message size and non-NULL buffer, then set the receive message size to 0 and buffer to NULL.
///  To receive data, you have to send a command defined by the I2C protocol to the display, so you will always have to send some sequence of bytes to the display, even if you only want to read from the display.
///  To send and receive data at the same time, specify non-zero send and receive message size and non-NULL send and receive message buffers. You will have to worry about sending proper commands to the display, as defined by the I2C protocol.
int ADL2_Display_DDCBlockAccess_Get ( ADL_CONTEXT_HANDLE context,
                                      int                iAdapterIndex,
                                      int                iDisplayIndex,
                                      int                iOption,
                                      int                iCommandIndex,
                                      int                iSendMsgLen,
                                      char *             lpucSendMsgBuf,
                                      int *              lpulRecvMsgLen,
                                      char *             lpucRecvMsgBuf
                                    );


/// Function to get the DDC info. 
/// 
/// This function retrieves the display device config (DDC) information only if the device has the information. No assumption should be made that this call will cause the driver will do real time detection. The driver determines when DDC detection should take place. If a display is attached and it supports DDC, all available information should be returned and ADLDDCInfo.ulSupportsDDC should be set to 1. Any fields that are not supported by an attached DDC display should be zeroed on return. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in]  context       Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in]  iAdapterIndex The ADL index handle of the desired adapter. 
///   [in]  iDisplayIndex The desired display index. It can be retrieved from the ADLDisplayInfo data structure. 
///   [out] lpInfo        The pointer to the ADLDDCInfo structure storing all DDC retrieved from the driver. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes 
/// 
/// Remarks
///   Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call ADL2_Main_Control_Create first to obtain ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using ADL2_Main_Control_Destroy.
int ADL2_Display_DDCInfo2_Get ( ADL_CONTEXT_HANDLE context,
                                int                iAdapterIndex,
                                int                iDisplayIndex,
                                ADLDDCInfo2 *      lpInfo
                              );


/// Function to get the DDC info. 
/// 
/// This function retrieves the display device config (DDC) information only if the device has the information. No assumption should be made that this call will cause the driver will do real time detection. The driver determines when DDC detection should take place. If a display is attached and it supports DDC, all available information should be returned and ADLDDCInfo.ulSupportsDDC should be set to 1. Any fields that are not supported by an attached DDC display should be zeroed on return. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in]  context       Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in]  iAdapterIndex The ADL index handle of the desired adapter. 
///   [in]  iDisplayIndex The desired display index. It can be retrieved from the ADLDisplayInfo data structure. 
///   [out] lpInfo        The pointer to the ADLDDCInfo structure storing all DDC retrieved from the driver. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes 
/// 
/// Remarks
///   Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call ADL2_Main_Control_Create first to obtain ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using ADL2_Main_Control_Destroy.
int ADL2_Display_DDCInfo_Get ( ADL_CONTEXT_HANDLE context,
                               int                iAdapterIndex,
                               int                iDisplayIndex,
                               ADLDDCInfo *       lpInfo
                             );


/// Function to get the current Deflicker setting from the display. This function retrieves the Deflicker information for a specified display. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in]  context       Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in]  iAdapterIndex The index of the desired adapter. 
///   [in]  iDisplayIndex The index of the desired display. 
///   [out] lpCurrent     The current Deflicker setting 
///   [out] lpDefault     The default Deflicker setting 
///   [out] lpMin         The current Deflicker setting 
///   [out] lpMax         The default Deflicker setting 
///   [out] lpStep        The current Deflicker setting 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK (zero). Otherwise the return value is an ADL error code (non-zero). Result Codes 
/// 
/// Remarks
///   Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call ADL2_Main_Control_Create first to obtain ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using ADL2_Main_Control_Destroy.
int ADL2_Display_Deflicker_Get ( ADL_CONTEXT_HANDLE context,
                                 int                iAdapterIndex,
                                 int                iDisplayIndex,
                                 int *              lpCurrent,
                                 int *              lpDefault,
                                 int *              lpMin,
                                 int *              lpMax,
                                 int *              lpStep
                               );


/// Function to set the current Deflicker setting for the display. This function set the Deflicker setting for a specified display. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in] context       Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in] iAdapterIndex The index of the desired adapter. 
///   [in] iDisplayIndex The index of the desired display. 
///   [in] iCurrent      The new Deflicker setting 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK (zero). Otherwise the return value is an ADL error code (non-zero). Result Codes
/// 
/// Remarks
///   Call ADL_Flush_Driver_Data() after to persist settings on reboot.
int ADL2_Display_Deflicker_Set ( ADL_CONTEXT_HANDLE context,
                                 int                iAdapterIndex,
                                 int                iDisplayindex,
                                 int                iCurrent
                               );


/// Function to get HDTV capability settings. 
/// 
/// This function retrieves HDTV capability settings for a specified display. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in]  context         Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in]  iAdapterIndex   The ADL index handle of the desired adapter. 
///   [in]  iDisplayIndex   The desired display index. It can be retrieved from the ADLDisplayInfo data structure. 
///   [out] lpDisplayConfig The pointer to the retrieved display configuration. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes 
/// 
/// Remarks
///   Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call ADL2_Main_Control_Create first to obtain ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using ADL2_Main_Control_Destroy.
int ADL2_Display_DeviceConfig_Get ( ADL_CONTEXT_HANDLE context,
                                    int                iAdapterIndex,
                                    int                iDisplayIndex,
                                    ADLDisplayConfig * lpDisplayConfig
                                  );


/// This function gets the application availability for display content value and ITC flag. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in] context       Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in] iAdapterIndex The index of the desired adapter. 
///   [in] iDisplayIndex The index of the desired display. 
///   [in] pCapContent   The current cap setting(if display content and ITC data are retrievable); where pCapContent returns the bitOR value of all supported ADLDisplayContent.iContentType (i.e. according to definitions of ADLDisplayContent.iContentType, if all content is supported it is expected that pCapContent will return with a value of, Graphics | Photo | Cinema |Game = 15) 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK (zero). Otherwise the return value is an ADL error code (non-zero). Result Codes
/// 
/// Remarks
///   Call ADL_Flush_Driver_Data() after to persist settings on reboot.
int ADL2_Display_DisplayContent_Cap ( ADL_CONTEXT_HANDLE context,
                                      int                iAdapterIndex,
                                      int                iDisplayIndex,
                                      int *              pCapContent
                                    );


/// This function gets the picture setting (Graphics, Photo, Cinema or Gaming) on any HDMI that supports these modes. The application associated with this function is designed such that, even if the ITC display option is toggled 'OFF' (unchecked), this function will still return the last display content mode that was set (or initial value of Graphics) 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in] context       Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in] iAdapterIndex The index of the desired adapter. 
///   [in] iDisplayIndex The index of the desired display. 
///   [in] piContent     The current display content setting; where piContent is one of ADLDisplayContent.iContentType 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK (zero). Otherwise the return value is an ADL error code (non-zero). Result Codes 
/// 
/// Remarks
///   Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call ADL2_Main_Control_Create first to obtain ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using ADL2_Main_Control_Destroy.
int ADL2_Display_DisplayContent_Get ( ADL_CONTEXT_HANDLE context,
                                      int                iAdapterIndex,
                                      int                iDisplayIndex,
                                      int *              piContent
                                    );


/// This function sets the picture setting (Graphics, Photo, Cinema or Gaming) on any HDMI that supports these modes. The application associated with this function is designed such that, the ITC display option must be toggled 'ON' (checked) before display content options become available for setting. If the display content is set, but the ITC is toggled 'OFF', the display content options will disable (gray-out), but still show which display content was last 'set'. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in] context       Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in] iAdapterIndex The index of the desired adapter. 
///   [in] iDisplayIndex The index of the desired display. 
///   [in] iContent      The display content desired to be set; where iContent is one of ADLDisplayContent.iContentType 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK (zero). Otherwise the return value is an ADL error code (non-zero). Result Codes
/// 
/// Remarks
///   Call ADL_Flush_Driver_Data() after to persist settings on reboot.
int ADL2_Display_DisplayContent_Set ( ADL_CONTEXT_HANDLE context,
                                      int                iAdapterIndex,
                                      int                iDisplayIndex,
                                      int                iContent
                                    );


/// Function to retrieve the adapter display information. 
/// 
/// This function retrieves display information for a specified adapter. Display information includes display index, name, type, and display connection status, etc.
/// 
/// This API uses the Caller's Memory Allocation Callback Function to allocate memory pointed by lppInfo. Caller is responsible to de-alocate the memory. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in]  context       Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in]  iAdapterIndex The ADL index handle of the desired adapter. 
///   [out] lpNumDisplays The pointer to the number of displays detected. 
///   [out] lppInfo       The pointer to the pointer to the retrieved display information array. Initialize to NULL before calling this API. Refer to the ADLDisplayInfo structure for more information. 
///   [in]  iForceDetect  0: Do not force detection of the adapters in the system; 1 : Force detection 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes
/// 
/// Remarks
///   This API uses the memory allocation callback function provided by the user.
int ADL2_Display_DisplayInfo_Get ( ADL_CONTEXT_HANDLE context,
                                   int                iAdapterIndex,
                                   int *              lpNumDisplays,
                                   ADLDisplayInfo **  lppInfo,
                                   int                iForceDetect
                                 );


/// Function to retrieve the dither state. 
/// 
/// This function retrieves the dither state for a specified display. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in]  context       Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in]  iAdapterIndex The ADL index handle of the desired adapter. 
///   [in]  iDisplayIndex The desired display index. It can be retrieved from the ADLDisplayInfo data structure. 
///   [out] lpDitherState The pointer to the value storing the retrieved dither state. See Dithering options 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes 
/// 
/// Remarks
///   Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call ADL2_Main_Control_Create first to obtain ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using ADL2_Main_Control_Destroy.
int ADL2_Display_DitherState_Get ( ADL_CONTEXT_HANDLE context,
                                   int                iAdapterIndex,
                                   int                iDisplayIndex,
                                   int *              lpDitherState
                                 );


/// Function to set the dither state. 
/// 
/// This function sets the dither state. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in] context       Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in] iAdapterIndex The ADL index handle of the desired adapter. 
///   [in] iDisplayIndex The desired display index. It can be retrieved from the ADLDisplayInfo data structure. 
///   [in] iDitherState  The desired dither state. For the list of valid states see Dithering options 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes
/// 
/// Remarks
///   The final bit depth after dithering must match the input bit depth of the monitor. The function call will fail if it doesn't.
int ADL2_Display_DitherState_Set ( ADL_CONTEXT_HANDLE context,
                                   int                iAdapterIndex,
                                   int                iDisplayIndex,
                                   int                iDitherState
                                 );


/// Function to get the Down-scaling Caps display information. 
/// 
/// This function retrieves the Down-scaling Caps information for a specified adapter and display. 
/// Supported Platforms:
///   \Win7 and above 
/// 
/// Parameters
///   [in]  context       Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in]  iAdapterIndex The ADL index handle of the desired adapter. 
///   [in]  iDisplayID    The desired display ID. It can be retrieved from the ADLDisplayInfo data structure. 
///   [out] lpCaps        The pointer to the Down-scaling Caps information retrieved from the driver. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes
int ADL2_Display_Downscaling_Caps ( ADL_CONTEXT_HANDLE context,
                                    int                iAdapterIndex,
                                    int                iDisplayID,
                                    int *              lpCaps
                                  );


/// Function to retrieve the Display Port MST information. 
/// 
/// This function retrieves display port MST information for a specified adapter. Display port MST information includes display indexes, names, bandwidth, identifiers, relative address and display connection, etc.
/// 
/// This API uses the Caller's Memory Allocation Callback Function to allocate memory pointed by lppDisplayDPMstInfo. Caller is responsible to de-alocate the memory. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in]  context             Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in]  iAdapterIndex       The ADL index handle of the desired adapter. A value of -1 returns all displays in the system across multiple GPUs. 
///   [out] lpNumDisplays       The pointer to the number of displays detected. 
///   [out] lppDisplayDPMstInfo The pointer to the list of the retrieved display port MST information array. Initialize to NULL before calling this API. Refer to the ADLDisplayDPMSTInfo structure for more information. 
///   [in]  iForceDetect        ADL_FALSE: Do not force detection of the adapters in the system; ADL_TRUE: Force detection 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes
/// 
/// Remarks
///   This API uses the memory allocation callback function provided by the user.
int ADL2_Display_DpMstInfo_Get ( ADL_CONTEXT_HANDLE     context,
                                 int                    iAdapterIndex,
                                 int *                  lpNumDisplays,
                                 ADLDisplayDPMSTInfo ** lppDisplayDPMstInfo,
                                 int                    iForceDetect
                               );


/// This function scans to all the adapters and tries to destroy the dummy virtual monitor in each. The driver only allows this type of monitor on one of the GPUs and it is its responsibility to make sure the call succeeds as expected. This is part of a temporary implementation for supporting a virtual xInput device hacked in software until we have a driver for such a device. 
/// Supported Platforms:
///   \Win7 and above 
/// 
/// Parameters
///   [in] context   Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in] iTargetID The display ID of the dummy virtual display. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes
int ADL2_Display_DummyVirtual_Destroy ( ADL_CONTEXT_HANDLE context,
                                        int                iTargetID
                                      );


/// This function scans to all the adapters and tries to find or enable a dummy virtual monitor. The driver only allows this type of monitor on one of the GPUs and it is its responsibility to make sure the call succeeds as expected. This is part of a temporary implementation for supporting a virtual xInput device hacked in software until we have a driver for such a device. 
/// Supported Platforms:
///   \Win7 and above 
/// 
/// Parameters
///   [in]  context             Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in]  iVirtualDisplayType The type of virtual display. 
///   [out] iTargetID           The display ID of the dummy virtual display. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes
int ADL2_Display_DummyVirtual_Get ( ADL_CONTEXT_HANDLE context,
                                    int                iVirtualDisplayType,
                                    int *              iTargetID
                                  );


/// Function to get the EDID data. 
/// 
/// This function retrieves the EDID data for a specififed display. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in]     context       Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in]     iAdapterIndex The ADL index handle of the desired adapter. 
///   [in]     iDisplayIndex The desired display index. It can be retrieved from the ADLDisplayInfo data structure. 
///   [in,out] lpEDIDData    The pointer to the ADLDisplayEDIDData structure storing the retrieved EDID data. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes 
/// 
/// Remarks
///   Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call ADL2_Main_Control_Create first to obtain ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using ADL2_Main_Control_Destroy.
int ADL2_Display_EdidData_Get ( ADL_CONTEXT_HANDLE   context,
                                int                  iAdapterIndex,
                                int                  iDisplayIndex,
                                ADLDisplayEDIDData * lpEDIDData
                              );


/// Function to get the current FilterSVideo setting from the display. This function retrieves the S-Video Sharpness Control information for a specified display. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in]  context       Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in]  iAdapterIndex The index of the desired adapter. 
///   [in]  iDisplayIndex The index of the desired display. 
///   [out] lpCurrent     The current FilterSVideo setting 
///   [out] lpDefault     The default FilterSVideo setting 
///   [out] lpMin         The current FilterSVideo setting 
///   [out] lpMax         The default FilterSVideo setting 
///   [out] lpStep        The current FilterSVideo setting 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK (zero). Otherwise the return value is an ADL error code (non-zero). Result Codes 
/// 
/// Remarks
///   Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call ADL2_Main_Control_Create first to obtain ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using ADL2_Main_Control_Destroy.
int ADL2_Display_FilterSVideo_Get ( ADL_CONTEXT_HANDLE context,
                                    int                iAdapterIndex,
                                    int                iDisplayIndex,
                                    int *              lpCurrent,
                                    int *              lpDefault,
                                    int *              lpMin,
                                    int *              lpMax,
                                    int *              lpStep
                                  );


/// Function to set the current FilterSVideo setting for the display. This function set the S-Video Sharpness Control setting for a specified display. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in] context       Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in] iAdapterIndex The index of the desired adapter. 
///   [in] iDisplayIndex The index of the desired display. 
///   [in] iCurrent      The new FilterSVideo setting 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK (zero). Otherwise the return value is an ADL error code (non-zero). Result Codes
/// 
/// Remarks
///   Call ADL_Flush_Driver_Data() after to persist settings on reboot.
int ADL2_Display_FilterSVideo_Set ( ADL_CONTEXT_HANDLE context,
                                    int                iAdapterIndex,
                                    int                iDisplayIndex,
                                    int                iCurrent
                                  );


/// Function to retrieve the available display formats. 
/// 
/// This call retrieves the available display formats 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in]  context               Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in]  iAdapterIndex         The ADL index handle of the desired adapter. 
///   [in]  iDisplayIndex         The desired display index. It can be retrieved from the ADLDisplayInfo data structure. 
///   [out] lpSettingsSupported   The pointer to the supported settings. Formats Override Settings 
///   [out] lpSettingsSupportedEx The pointer to the extended supported settings. Formats Override Settings 
///   [out] lpCurSettings         The pointer to the current override settings Formats Override Settings 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes 
/// 
/// Remarks
///   Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call ADL2_Main_Control_Create first to obtain ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using ADL2_Main_Control_Destroy.
int ADL2_Display_FormatsOverride_Get ( ADL_CONTEXT_HANDLE context,
                                       int                iAdapterIndex,
                                       int                iDisplayIndex,
                                       int *              lpSettingsSupported,
                                       int *              lpSettingsSupportedEx,
                                       int *              lpCurSettings
                                     );


/// Function to overide the display formats. 
/// 
/// This call overrides the display formats 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in] context           Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in] iAdapterIndex     The ADL index handle of the desired adapter. 
///   [in] iDisplayIndex     The desired display index. It can be retrieved from the ADLDisplayInfo data structure. 
///   [in] iOverrideSettings The new format settings Formats Override Settings 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes
/// 
/// Remarks
///   Call ADL_Flush_Driver_Data() after to persist settings on reboot.
int ADL2_Display_FormatsOverride_Set ( ADL_CONTEXT_HANDLE context,
                                       int                iAdapterIndex,
                                       int                iDisplayIndex,
                                       int                iOverrideSettings
                                     );


/// Function to retrieve per display FreeSync capability information. 
/// 
/// This function retrieves the FreeSync capabilities of a display. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in]  context        Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in]  iAdapterIndex  The ADL index handle of the desired adapter. 
///   [in]  iDisplayIndex  The desired display index. It can be retrieved from the ADLDisplayInfo data structure. 
///   [out] lpFreeSyncCaps The pointer to the ADLFreeSyncCap structure storing the retrieved FreeSync capabilities for the requested display index. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes 
/// 
/// Remarks
///   Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call ADL2_Main_Control_Create first to obtain ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using ADL2_Main_Control_Destroy.
int ADL2_Display_FreeSync_Cap ( ADL_CONTEXT_HANDLE context,
                                int                iAdapterIndex,
                                int                iDisplayIndex,
                                ADLFreeSyncCap *   lpFreeSyncCaps
                              );


/// Function to get the current state and capability of the FreeSync feature. 
/// 
/// 
/// 
/// This function gets the current and default FreeSync settings for a specified display along with the supported FreeSync refresh rate range. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in]  context                   Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in]  iAdapterIndex             The ADL index handle of the desired adapter. 
///   [in]  iDisplayIndex             The desired display index. It can be retrieved from the ADLDisplayInfo data structure. 
///   [out] lpCurrent                 The pointer to the FreeSync setting currently applied. It is a bit vector. Define_freesync_usecase 
///   [out] lpDefault                 The pointer to the default FreeSync setting. It is a bit vector. Define_freesync_usecase 
///   [out] lpMinRefreshRateInMicroHz The pointer to the minimum refresh rate in the range supported by FreeSync in microhertz. 
///   [out] lpMaxRefreshRateInMicroHz The pointer to the maximum refresh rate in the range supported by FreeSync in microhertz. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK, ADL_ERR_NULL_POINTER if any of the inputs is NULL, Otherwise the return value is an ADL_ERR. Result Codes 
/// 
/// Remarks
///   Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call ADL2_Main_Control_Create first to obtain ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using ADL2_Main_Control_Destroy.
int ADL2_Display_FreeSyncState_Get ( ADL_CONTEXT_HANDLE context,
                                     int                iAdapterIndex,
                                     int                iDisplayIndex,
                                     int *              lpCurrent,
                                     int *              lpDefault,
                                     int *              lpMinRefreshRateInMicroHz,
                                     int *              lpMaxRefreshRateInMicroHz
                                   );


/// Function to set the current state of the FreeSync feature. 
/// 
/// 
/// 
/// This function sets the FreeSync feature enable state for a specified display. There is a second input parameter that may be used to request a specific refresh rate to be applied. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in] context               Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in] iAdapterIndex         The ADL index handle of the desired adapter. 
///   [in] iDisplayIndex         The desired display index. It can be retrieved from the ADLDisplayInfo data structure. 
///   [in] iSetting              The desired FreeSync setting to be applied for the specified display. Define_freesync_usecase 
///   [in] iRefreshRateInMicroHz If non-zero value is specified, this indicates a request to set a specific refresh rate in microhertz. Otherwise, driver default will decide FreeSync refresh rate dynamically. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes
/// 
/// Remarks
///   Call ADL_Flush_Driver_Data() after to persist settings on reboot.
int ADL2_Display_FreeSyncState_Set ( ADL_CONTEXT_HANDLE context,
                                     int                iAdapterIndex,
                                     int                iDisplayIndex,
                                     int                iSetting,
                                     int                iRefreshRateInMicroHz
                                   );


/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in]  context       Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in]  iAdapterIndex The index of the desired adapter. 
///   [in]  iDisplayIndex The index of the desired display. 
///   [in]  gamut         The gamut reference - whether it is related to graphics or video, source or destination 
///   [out] ADLGamutInfo  driver supplies the mask of supported gamut spaces and white points, driver supports this feature from NI ASIC. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK (zero). Otherwise the return value is an ADL error code (non-zero). Result Codes 
/// 
/// Remarks
///   Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call ADL2_Main_Control_Create first to obtain ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using ADL2_Main_Control_Destroy.
int ADL2_Display_Gamut_Caps ( ADL_CONTEXT_HANDLE context,
                              int                iAdapterIndex,
                              int                iDisplayIndex,
                              ADLGamutReference  gamut,
                              ADLGamutInfo *     lpCap
                            );


/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in]  context       Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in]  iAdapterIndex The index of the desired adapter. 
///   [in]  iDisplayIndex The index of the desired display. 
///   [in]  gamut         . The gamut reference - whether it is related to graphics or video, source or destination 
///   [out] ADLGamutData  driver supplies the currently used gamut, driver supports this feature from NI ASIC. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK (zero). Otherwise the return value is an ADL error code (non-zero). Result Codes 
/// 
/// Remarks
///   Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call ADL2_Main_Control_Create first to obtain ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using ADL2_Main_Control_Destroy.
int ADL2_Display_Gamut_Get ( ADL_CONTEXT_HANDLE context,
                             int                iAdapterIndex,
                             int                iDisplayIndex,
                             ADLGamutReference  gamut,
                             ADLGamutData *     lpSource
                           );


/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in] context       Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in] iAdapterIndex The index of the desired adapter. 
///   [in] iDisplayIndex The index of the desired display. 
///   [in] gamut         The gamut reference - whether it is related to graphics or video, source or destination 
///   [in] ADLGamutData  to be set, the method sets the new gamut or saves the requested gamut if the current destination if gamut from EDID. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK (zero). Otherwise the return value is an ADL error code (non-zero). Result Codes 
/// 
/// Remarks
///   Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call ADL2_Main_Control_Create first to obtain ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using ADL2_Main_Control_Destroy.
int ADL2_Display_Gamut_Set ( ADL_CONTEXT_HANDLE   context,
                             int                  iAdapterIndex,
                             int                  iDisplayIndex,
                             ADLGamutReference    gamut,
                             const ADLGamutData * lpSource
                           );


/// This function retrieves the HDCP settings of a display. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in]  context        Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in]  iAdapterIndex  The ADL index handle of the desired adapter. 
///   [in]  iDisplayIndex  The desired display index. 
///   [out] lpHDCPSettings The pointer to the ADLDceSettings structure 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes
int ADL2_Display_HDCP_Get ( ADL_CONTEXT_HANDLE context,
                            int                iAdapterIndex,
                            int                iDisplayIndex,
                            ADLHDCPSettings *  lpHDCPSettings
                          );


/// This function sets the HDCP settings of a display. Will require reboot to have settings changed. This reboot does not need to be immediate. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in] iAdapterIndex The ADL index handle of the desired adapter. 
///   [in] iDisplayIndex The desired display index. 
///   [in] iSetToDefault iSetToDefault ==1, set to default value and ignore iEnable value. 
///   [in] iEnable       If iSetToDefault ==0 use iEnable. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK or ADL_OK_RESTART. Otherwise the return value is an ADL error code. Result Codes
int ADL2_Display_HDCP_Set ( ADL_CONTEXT_HANDLE context,
                            int                iAdapterIndex,
                            int                iDisplayIndex,
                            int                iSetToDefault,
                            int                iEnable
                          );


/// This function retrieves whether a display is HDR supported and Enabled 
/// Supported Platforms:
///   \Win10 
/// 
/// Parameters
///   [in]  context       Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in]  iAdapterIndex The ADL index handle of the desired adapter. 
///   [in]  displayID     The desired display ID. 
///   [out] iSupport      The pointer to the int whose value is set to true if the display supports HDR 
///   [out] iEnable       The pointer to the int whose value is set to true if the display HDR is enabled 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes
int ADL2_Display_HDRState_Get ( ADL_CONTEXT_HANDLE context,
                                int                iAdapterIndex,
                                ADLDisplayID       displayID,
                                int *              iSupport,
                                int *              iEnable
                              );


/// This function sets HDR state to display 
/// Supported Platforms:
///   \Win10 
/// 
/// Parameters
///   [in] context       Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in] iAdapterIndex The ADL index handle of the desired adapter. 
///   [in] displayID     The desired display ID. 
///   [in] iEnable       enable HDR state of Display 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes
int ADL2_Display_HDRState_Set ( ADL_CONTEXT_HANDLE context,
                                int                iAdapterIndex,
                                ADLDisplayID       displayID,
                                int                iEnable
                              );


/// Function to retrieve the display image expansion setting. 
/// 
/// This function retrieves the current, default, and the feature supported values of the image expansion setting. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in]  context       Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in]  iAdapterIndex The ADL index handle of the desired adapter. 
///   [in]  iDisplayIndex The desired display index. It can be retrieved from the ADLDisplayInfo data structure. 
///   [out] lpSupport     The pointer to the value indicating whether the feature is supported by the driver. 1: feature is supported; 0: feature is not supported. 
///   [out] lpCurrent     The pointer to the current setting of display image expansion. Its alternative value is 1 or 0. 
///   [out] lpDefault     The pointer to the default setting of display image expansion. Its alternative value is 1 or 0. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes 
/// 
/// Remarks
///   Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call ADL2_Main_Control_Create first to obtain ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using ADL2_Main_Control_Destroy.
int ADL2_Display_ImageExpansion_Get ( ADL_CONTEXT_HANDLE context,
                                      int                iAdapterIndex,
                                      int                iDisplayIndex,
                                      int *              lpSupport,
                                      int *              lpCurrent,
                                      int *              lpDefault
                                    );


/// Function to set the display image expansion setting. 
/// 
/// This function sets the current value of display image expansion setting. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in] context       Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in] iAdapterIndex The ADL index handle of the desired adapter. 
///   [in] iDisplayIndex The desired display index. It can be retrieved from the ADLDisplayInfo data structure. 
///   [in] iCurrent      The desired setting of display image expansion. Possible values are 1 or 0. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes
/// 
/// Remarks
///   Call ADL_Flush_Driver_Data() after to persist settings on reboot.
int ADL2_Display_ImageExpansion_Set ( ADL_CONTEXT_HANDLE context,
                                      int                iAdapterIndex,
                                      int                iDisplayIndex,
                                      int                iCurrent
                                    );


/// This function retrieves the maximum horizontal and vertical resolution as well as the maximum refresh rate for a specified display and adapter. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in]  context       Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in]  iAdapterIndex The ADL index handle of the graphics adapter corresponding to the desired display. 
///   [in]  iDisplayIndex The ADL index handle of the desired display. 
///   [out] lpMaxHRes     The pointer to the maximum horizontal resolution for the specified display. 
///   [out] lpMaxVRes     The pointer to the maximum vertical resolution for the specified display. 
///   [out] lpMaxRefresh  The pointer to the maximum refresh rate for the specfied display. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes 
/// 
/// Remarks
///   Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call ADL2_Main_Control_Create first to obtain ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using ADL2_Main_Control_Destroy.
int ADL2_Display_Limits_Get ( ADL_CONTEXT_HANDLE context,
                              int                iAdapterIndex,
                              int                iDisplayIndex,
                              int *              lpMaxHRes,
                              int *              lpMaxVRes,
                              int *              lpMaxRefresh
                            );


/// Function to delete display mode timing override information. 
/// 
/// This function delete display mode timing override information for a specified display. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in] context       Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in] iAdapterIndex The ADL index handle of the desired adapter. 
///   [in] displayID     The desired display index. It can be retrieved from the ADLDisplayInfo data structure. 
///   [in] lpModeIn      The pointer to the ADLDisplayMode structure storing the desired display mode. 
///   [in] iForceUpdate  The value which forces the update of the timing override information. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes 
/// 
/// Remarks
///   Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call ADL2_Main_Control_Create first to obtain ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using ADL2_Main_Control_Destroy.
int ADL2_Display_ModeTimingOverride_Delete ( ADL_CONTEXT_HANDLE context,
                                             int                iAdapterIndex,
                                             ADLDisplayID       displayID,
                                             ADLDisplayModeX2 * lpMode,
                                             int                iForceUpdate
                                           );


/// Function to retrieve display mode timing override information. 
/// 
/// This function retrieves display mode timing override information for a specified display. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in]  context       Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in]  iAdapterIndex The ADL index handle of the desired adapter. 
///   [in]  iDisplayIndex The desired display index. It can be retrieved from the ADLDisplayInfo data structure. 
///   [in]  lpModeIn      The pointer to the ADLDisplayMode structure storing the desired display mode. 
///   [out] lpModeInfoOut The pointer to the ADLDisplayModeInfo structure storing the retrieved display mode information. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes 
/// 
/// Remarks
///   Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call ADL2_Main_Control_Create first to obtain ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using ADL2_Main_Control_Destroy. 
/// Deprecated:
///   This API has been deprecated. It has been replaced with API ADL2_Display_ModeTimingOverrideX2_Get
int ADL2_Display_ModeTimingOverride_Get ( ADL_CONTEXT_HANDLE   context,
                                          int                  iAdapterIndex,
                                          int                  iDisplayIndex,
                                          ADLDisplayMode *     lpModeIn,
                                          ADLDisplayModeInfo * lpModeInfoOut
                                        );


/// Function to set display mode timing override information. 
/// 
/// This function sets display mode timing override information for a specified display. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in] context       Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in] iAdapterIndex The ADL index handle of the desired adapter. 
///   [in] iDisplayIndex The desired display index. It can be retrieved from the ADLDisplayInfo data structure. 
///   [in] lpMode        The pointer to the ADLDisplayModeInfo structure which sets the display mode timing override information. 
///   [in] iForceUpdate  The value which forces the update of the timing override information. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes
/// 
/// Remarks
///   Call ADL_Flush_Driver_Data() after to persist settings on reboot.
int ADL2_Display_ModeTimingOverride_Set ( ADL_CONTEXT_HANDLE   context,
                                          int                  iAdapterIndex,
                                          int                  iDisplayIndex,
                                          ADLDisplayModeInfo * lpMode,
                                          int                  iForceUpdate
                                        );


/// Function to retrieve display mode timing override information. 
/// 
/// This function retrieves display mode timing override information for a specified display. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in]  context       Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in]  iAdapterIndex The ADL index handle of the desired adapter. 
///   [in]  iDisplayIndex The desired display index. It can be retrieved from the ADLDisplayInfo data structure. 
///   [in]  lpModeIn      The pointer to the structure storing the desired display mode. 
///   [out] lpModeInfoOut The pointer to the structure storing the retrieved display mode information. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes 
/// 
/// Remarks
///   Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call ADL2_Main_Control_Create first to obtain ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using ADL2_Main_Control_Destroy. 
/// Deprecated:
///   This API has been deprecated.
int ADL2_Display_ModeTimingOverrideInfo_Get ( ADL_CONTEXT_HANDLE       context,
                                              int                      iAdapterIndex,
                                              int                      iDisplayIndex,
                                              ADL_DL_DISPLAY_MODE *    lpModeIn,
                                              ADL_DL_DISPLAYMODEINFO * lpModeInfoOut
                                            );


/// Function to get the display mode timing override list. 
/// 
/// This function retrieves display mode timing override list. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in]  context            Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in]  iAdapterIndex      The ADL index handle of the desired adapter. 
///   [in]  iDisplayIndex      The desired display index. It can be retrieved from the ADLDisplayInfo data structure. 
///   [in]  iMaxNumOfOverrides The maximum number of elements in the array pointed by lpModeInfoList. The number specified must be > 0. 
///   [out] lpModeInfoList     The pointer to the retrieved ADLDisplayModeInfo structure. This pointer must be allocated by the user. 
///   [out] lpNumOfOverrides   The pointer to the actual number of the retrieved overridden modes. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes 
/// 
/// Remarks
///   Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call ADL2_Main_Control_Create first to obtain ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using ADL2_Main_Control_Destroy. 
/// Deprecated:
///   This API has been deprecated. It has been replaced with API ADL2_Display_ModeTimingOverrideListX2_Get
int ADL2_Display_ModeTimingOverrideList_Get ( ADL_CONTEXT_HANDLE   context,
                                              int                  iAdapterIndex,
                                              int                  iDisplayIndex,
                                              int                  iMaxNumOfOverrides,
                                              ADLDisplayModeInfo * lpModeInfoList,
                                              int *                lpNumOfOverrides
                                            );


/// Function to get the display mode timing override list. 
/// 
/// This function retrieves display mode timing override list. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in]  context        Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in]  iAdapterIndex  The ADL index handle of the desired adapter. 
///   [in]  displayID      The desired display index. It can be retrieved from the ADLDisplayInfo data structure. 
///   [out] lpNumOfModes   The pointer to the actual number of the retrieved overridden modes. 
///   [out] lpModeInfoList The pointer to the retrieved ADLDisplayModeInfo structure. This pointer must be allocated by the user. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes 
/// 
/// Remarks
///   Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call ADL2_Main_Control_Create first to obtain ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using ADL2_Main_Control_Destroy.
int ADL2_Display_ModeTimingOverrideListX2_Get ( ADL_CONTEXT_HANDLE    context,
                                                int                   iAdapterIndex,
                                                ADLDisplayID          displayID,
                                                int *                 lpNumOfModes,
                                                ADLDisplayModeInfo ** lpModeInfoList
                                              );


/// This function retrieves display mode timing override list. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in]  context        Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in]  iAdapterIndex  The ADL index handle of the desired adapter. 
///   [in]  displayID      The desired display index. It can be retrieved from the ADLDisplayInfo data structure. 
///   [out] lpNumOfModes   The pointer to the actual number of the retrieved overridden modes. 
///   [out] lpModeInfoList The pointer to the retrieved ADLDisplayModeInfo structure. This pointer must be allocated by the user. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes 
/// 
/// Remarks
///   Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call ADL2_Main_Control_Create first to obtain ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using ADL2_Main_Control_Destroy.
int ADL2_Display_ModeTimingOverrideListX3_Get ( ADL_CONTEXT_HANDLE      context,
                                                int                     iAdapterIndex,
                                                ADLDisplayID            displayID,
                                                int *                   lpNumOfModes,
                                                ADLDisplayModeInfoX2 ** lpModeInfoList
                                              );


/// Function to retrieve display mode timing override information. 
/// 
/// This function retrieves display mode timing override information for a specified display. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in]  context       Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in]  iAdapterIndex The ADL index handle of the desired adapter. 
///   [in]  displayID     The desired display index. It can be retrieved from the ADLDisplayInfo data structure. 
///   [in]  lpModeIn      The pointer to the ADLDisplayMode structure storing the desired display mode. 
///   [out] lpModeInfoOut The pointer to the ADLDisplayModeInfo structure storing the retrieved display mode information. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes 
/// 
/// Remarks
///   Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call ADL2_Main_Control_Create first to obtain ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using ADL2_Main_Control_Destroy.
int ADL2_Display_ModeTimingOverrideX2_Get ( ADL_CONTEXT_HANDLE   context,
                                            int                  iAdapterIndex,
                                            ADLDisplayID         displayID,
                                            ADLDisplayModeX2 *   lpModeIn,
                                            ADLDisplayModeInfo * lpModeInfoOut
                                          );


/// This function sets display mode timing override information for a specified display. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in] context       Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in] iAdapterIndex The ADL index handle of the desired adapter. 
///   [in] iDisplayIndex The desired display index. It can be retrieved from the ADLDisplayInfo data structure. 
///   [in] lpMode        The pointer to the ADLDisplayModeInfo structure which sets the display mode timing override information. 
///   [in] iForceUpdate  The value which forces the update of the timing override information. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes
/// 
/// Remarks
///   Call ADL_Flush_Driver_Data() after to persist settings on reboot.
int ADL2_Display_ModeTimingOverrideX2_Set ( ADL_CONTEXT_HANDLE     context,
                                            int                    iAdapterIndex,
                                            int                    iDisplayIndex,
                                            ADLDisplayModeInfoX2 * lpMode,
                                            int                    iForceUpdate
                                          );


/// This function retrieves display mode timing override information for a specified display. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in]  context       Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in]  iAdapterIndex The ADL index handle of the desired adapter. 
///   [in]  displayID     The desired display index. It can be retrieved from the ADLDisplayInfo data structure. 
///   [in]  lpModeIn      The pointer to the ADLDisplayMode structure storing the desired display mode. 
///   [out] lpModeInfoOut The pointer to the ADLDisplayModeInfo structure storing the retrieved display mode information. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes 
/// 
/// Remarks
///   Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call ADL2_Main_Control_Create first to obtain ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using ADL2_Main_Control_Destroy.
int ADL2_Display_ModeTimingOverrideX3_Get ( ADL_CONTEXT_HANDLE     context,
                                            int                    iAdapterIndex,
                                            ADLDisplayID           displayID,
                                            ADLDisplayModeX2 *     lpModeIn,
                                            ADLDisplayModeInfoX2 * lpModeInfoOut
                                          );


/// Function to retrieve the information about MultiVPU capabilities. 
/// 
/// This function retrieves the information about MultiVPU capabilities. 
/// Supported Platforms:
///   Windows 7, 10 and above; 32bit and 64bit 
/// 
/// Parameters
///   [in]     context       Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in]     iAdapterIndex The ADL index handle of the desired adapter. 
///   [in,out] lpMvpuCaps    The structure storing the retrieved information about MultiVPU capabilities. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes
/// 
/// Remarks
///   The maximum number of adapters is ADL_DL_MAX_MVPU_ADAPTERS
int ADL2_Display_MVPUCaps_Get ( ADL_CONTEXT_HANDLE context,
                                int                iAdapterIndex,
                                ADLMVPUCaps *      lpMvpuCaps
                              );


/// Function to retrieve information about MultiVPU status. 
/// 
/// This function retrieves information about MultiVPU status. 
/// Supported Platforms:
///   Windows 7, 10 and above; 32bit and 64bit 
/// 
/// Parameters
///   [in]     context       Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in]     iAdapterIndex The ADL index handle of the desired adapter. 
///   [in,out] lpMvpuStatus  The structure storing the retrieved information about MultiVPU status. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes 
/// 
/// Remarks
///   Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call ADL2_Main_Control_Create first to obtain ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using ADL2_Main_Control_Destroy.
int ADL2_Display_MVPUStatus_Get ( ADL_CONTEXT_HANDLE context,
                                  int                iAdapterIndex,
                                  ADLMVPUStatus *    lpMvpuStatus
                                );


/// Function to retrieve the number of displays supported by an adapter. 
/// 
/// This function retrieves the number of displays that is supported by a specified adapter. Supported displays include devices that are connected and disconnected together with those enabled and disabled devices. 
/// 
/// 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in]  context       Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in]  iAdapterIndex The ADL index handle of the desired adapter. 
///   [out] lpNumDisplays The pointer to the number of displays supported by the adapter. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes 
/// 
/// Remarks
///   Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call ADL2_Main_Control_Create first to obtain ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using ADL2_Main_Control_Destroy.
int ADL2_Display_NumberOfDisplays_Get ( ADL_CONTEXT_HANDLE context,
                                        int                iAdapterIndex,
                                        int *              lpNumDisplays
                                      );


/// Function to set the OD clock configuration. 
/// 
/// This function sets the OD clock configuration. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in] context         Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in] iAdapterIndex   The ADL index handle of the desired adapter. 
///   [in] lpOdClockConfig The pointer to the structure used to set the OD clock configuration. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes
/// 
/// Remarks
///   Call ADL_Flush_Driver_Data() after to persist settings on reboot.
int ADL2_Display_ODClockConfig_Set ( ADL_CONTEXT_HANDLE        context,
                                     int                       iAdapterIndex,
                                     ADLAdapterODClockConfig * lpOdClockConfig
                                   );


/// Function to retrieve the OD clock information. 
/// 
/// This function retrieves the OD clock information. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in]  context       Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in]  iAdapterIndex The ADL index handle of the desired adapter. 
///   [out] lpOdClockInfo The pointer to the structure storing the retrieved clock information. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes 
/// 
/// Remarks
///   Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call ADL2_Main_Control_Create first to obtain ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using ADL2_Main_Control_Destroy.
int ADL2_Display_ODClockInfo_Get ( ADL_CONTEXT_HANDLE      context,
                                   int                     iAdapterIndex,
                                   ADLAdapterODClockInfo * lpOdClockInfo
                                 );


/// Function to retrieve the current value of gamma for each controller. 
/// 
/// This function retrieves the Overscan value for a specified display. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in]  context       Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in]  iAdapterIndex The ADL index handle of the desired adapter. 
///   [in]  iDisplayIndex The desired display index. It can be retrieved from the ADLDisplayInfo data structure. 
///   [out] lpCurrent     The pointer to the current Overscan value. 
///   [out] lpDefualt     The pointer to the default Overscan value. 
///   [out] lpMin         The pointer to the minimum Overscan value. 
///   [out] lpMax         The pointer to the maximum Overscan value. 
///   [out] lpStep        The pointer to the increment of the Overscan value. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. 
/// 
/// Remarks
///   Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call ADL2_Main_Control_Create first to obtain ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using ADL2_Main_Control_Destroy.
int ADL2_Display_Overscan_Get ( ADL_CONTEXT_HANDLE context,
                                int                iAdapterIndex,
                                int                iDisplayIndex,
                                int *              lpCurrent,
                                int *              lpDefualt,
                                int *              lpMin,
                                int *              lpMax,
                                int *              lpStep
                              );


/// Function to set the current value of gamma for each controller. 
/// 
/// This function sets the Overscan value for a specified display. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in] context       Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in] iAdapterIndex The ADL index handle of the desired adapter. 
///   [in] iDisplayIndex The desired display index. It can be retrieved from the ADLDisplayInfo data structure. 
///   [in] iCurrent      The desired Overscan value. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes
/// 
/// Remarks
///   Call ADL_Flush_Driver_Data() after to persist settings on reboot.
int ADL2_Display_Overscan_Set ( ADL_CONTEXT_HANDLE context,
                                int                iAdapterIndex,
                                int                iDisplayIndex,
                                int                iCurrent
                              );


/// Function to retrieve the current display pixel format. HDMI only. 
/// 
/// This function retrieves the current display pixel format. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in]  context       Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in]  iAdapterIndex The ADL index handle of the desired adapter. 
///   [in]  iDisplayIndex The desired display index. It can be retrieved from the ADLDisplayInfo data structure. 
///   [out] lpPixelFormat The pointer to the pixel format. Pixel Formats values 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes 
/// 
/// Remarks
///   Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call ADL2_Main_Control_Create first to obtain ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using ADL2_Main_Control_Destroy.
int ADL2_Display_PixelFormat_Get ( ADL_CONTEXT_HANDLE context,
                                   int                iAdapterIndex,
                                   int                iDisplayIndex,
                                   int *              lpPixelFormat
                                 );


/// Function to set the current display pixel format. HDMI only. 
/// 
/// This function sets the current display pixel format. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in] context       Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in] iAdapterIndex The ADL index handle of the desired adapter. 
///   [in] iDisplayIndex The desired display index. It can be retrieved from the ADLDisplayInfo data structure. 
///   [in] iPixelFormat  The desired pixel format. Pixel Formats values 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes
/// 
/// Remarks
///   Call ADL_Flush_Driver_Data() after to persist settings on reboot.
int ADL2_Display_PixelFormat_Set ( ADL_CONTEXT_HANDLE context,
                                   int                iAdapterIndex,
                                   int                iDisplayIndex,
                                   int                iPixelFormat
                                 );


/// Function to retrieve the current display pixel format. HDMI only. 
/// 
/// This function retrieves the current display pixel format. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in]  context          Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in]  iAdapterIndex    The ADL index handle of the desired adapter. 
///   [in]  iDisplayIndex    The desired display index. It can be retrieved from the ADLDisplayInfo data structure. 
///   [out] lpDefPixelFormat The pointer to the default pixel format. Pixel Formats values 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes 
/// 
/// Remarks
///   Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call ADL2_Main_Control_Create first to obtain ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using ADL2_Main_Control_Destroy.
int ADL2_Display_PixelFormatDefault_Get ( ADL_CONTEXT_HANDLE context,
                                          int                iAdapterIndex,
                                          int                iDisplayIndex,
                                          int *              lpDefPixelFormat
                                        );


/// Function to get Device Display Position. 
/// 
/// This function retrieves the display position parameters for a specified adapter and display. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in]  context       Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in]  iAdapterIndex The ADL index handle of the desired adapter. 
///   [in]  iDisplayIndex The desired display index. It can be retrieved from the ADLDisplayInfo data structure. 
///   [out] lpX           The pointer to the current X coordinate display position. 
///   [out] lpY           The pointer to the current Y coordinate display position. 
///   [out] lpXDefault    The pointer to the default X coordinate display position. 
///   [out] lpYDefault    The pointer to the default Y coordinate display position. 
///   [out] lpMinX        The pointer to the minimum X display size. 
///   [out] lpMinY        The pointer to the minimum Y display size. 
///   [out] lpMaxX        The pointer to the maximum X display size. 
///   [out] lpMaxY        The pointer to the maximum Y display size. 
///   [out] lpStepX       The pointer to the step size along the X axis. 
///   [out] lpStepY       The pointer to the step size along the Y axis. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes 
/// 
/// Remarks
///   Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call ADL2_Main_Control_Create first to obtain ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using ADL2_Main_Control_Destroy.
int ADL2_Display_Position_Get ( ADL_CONTEXT_HANDLE context,
                                int                iAdapterIndex,
                                int                iDisplayIndex,
                                int *              lpX,
                                int *              lpY,
                                int *              lpXDefault,
                                int *              lpYDefault,
                                int *              lpMinX,
                                int *              lpMinY,
                                int *              lpMaxX,
                                int *              lpMaxY,
                                int *              lpStepX,
                                int *              lpStepY
                              );


/// Function to set the Device Display Position. 
/// 
/// This function sets the display X and Y position values for a specified adapter and display. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in] context       Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in] iAdapterIndex The ADL index handle of the desired adapter. 
///   [in] iDisplayIndex The desired display index. It can be retrieved from the ADLDisplayInfo data structure. 
///   [in] iX            The desired X coordinate position. 
///   [in] iY            The desired Y coordinate position. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes
/// 
/// Remarks
///   Call ADL_Flush_Driver_Data() after to persist settings on reboot.
int ADL2_Display_Position_Set ( ADL_CONTEXT_HANDLE context,
                                int                iAdapterIndex,
                                int                iDisplayIndex,
                                int                iX,
                                int                iY
                              );


/// This function retrieves the preferred display mode information. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in]  context       Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in]  iAdapterIndex The ADL index handle of the desired adapter. A value of -1 retrieves all modes for the system across multiple GPUs. 
///   [in]  iDisplayIndex The desired display index. If the index is -1, this field is ignored. 
///   [out] lpNumModes    The pointer to the number of modes retrieved. 
///   [out] lppModes      The pointer to the pointer to the retrieved preffered display modes. Refer to the Display ADLMode structure for more information. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes
/// 
/// Remarks
///   This API uses the memory allocation callback function provided by the user.
int ADL2_Display_PreferredMode_Get ( ADL_CONTEXT_HANDLE context,
                                     int                iAdapterIndex,
                                     int                iDisplayIndex,
                                     int *              lpNumModes,
                                     ADLMode **         lppModes
                                   );


/// Function to retrieve the display perserved aspect ratio of an adapter. 
/// 
/// This function retrieves the current, default, and the feature supported values of the display preserved aspect ratio. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in]  context       Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in]  iAdapterIndex The ADL index handle of the desired adapter. 
///   [in]  iDisplayIndex The desired display index. It can be retrieved from the ADLDisplayInfo data structure. 
///   [out] lpSupport     The pointer to the value indicating whether the feature is supported by the driver. 1: feature is supported; 0: feature is not supported. 
///   [out] lpCurrent     The pointer to the current setting of display preserved aspect ratio. Its alternative value is 1 or 0. 
///   [out] lpDefault     The pointer to the default setting of display preserved aspect ratio. Its alternative value is 1 or 0. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes 
/// 
/// Remarks
///   Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call ADL2_Main_Control_Create first to obtain ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using ADL2_Main_Control_Destroy.
int ADL2_Display_PreservedAspectRatio_Get ( ADL_CONTEXT_HANDLE context,
                                            int                iAdapterIndex,
                                            int                iDisplayIndex,
                                            int *              lpSupport,
                                            int *              lpCurrent,
                                            int *              lpDefault
                                          );


/// Function to set the display preserved aspect ratio. 
/// 
/// This function sets the current value of display preserved aspect ratio. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in] context       Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in] iAdapterIndex The ADL index handle of the desired adapter. 
///   [in] iDisplayIndex The desired display index. It can be retrieved from the ADLDisplayInfo data structure. 
///   [in] iCurrent      The desired display preserved aspect ratio setting. Possible values are 1 or 0. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes
/// 
/// Remarks
///   Call ADL_Flush_Driver_Data() after to persist settings on reboot.
int ADL2_Display_PreservedAspectRatio_Set ( ADL_CONTEXT_HANDLE context,
                                            int                iAdapterIndex,
                                            int                iDisplayIndex,
                                            int                iCurrent
                                          );


/// Function to get the current display property value. 
/// 
/// This function retrieves the current display property value for a specified display. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in]  context           Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in]  iAdapterIndex     The ADL index handle of the desired adapter. 
///   [in]  iDisplayIndex     The desired display index. It can be retrieved from the ADLDisplayInfo data structure. 
///   [out] lpDisplayProperty The pointer to the ADLDisplayProperty structure storing the retrieved display property value. lpDisplayProperty->iExpansionMode contains the Expansion Mode value. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes 
/// 
/// Remarks
///   Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call ADL2_Main_Control_Create first to obtain ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using ADL2_Main_Control_Destroy.
int ADL2_Display_Property_Get ( ADL_CONTEXT_HANDLE   context,
                                int                  iAdapterIndex,
                                int                  iDisplayIndex,
                                ADLDisplayProperty * lpDisplayProperty
                              );


/// Function to set current display property value. 
/// 
/// This function sets current display property value for a specified display. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in] context           Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in] iAdapterIndex     The ADL index handle of the desired adapter. 
///   [in] iDisplayIndex     The desired display index. It can be retrieved from the ADLDisplayInfo data structure. 
///   [in] lpDisplayProperty The pointer to the desired ADLDisplayProperty structure. Set lpDisplayProperty->iExpansionMode with an Expansion Mode value. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes
/// 
/// Remarks
///   Call ADL_Flush_Driver_Data() after to persist settings on reboot.
int ADL2_Display_Property_Set ( ADL_CONTEXT_HANDLE   context,
                                int                  iAdapterIndex,
                                int                  iDisplayIndex,
                                ADLDisplayProperty * lpDisplayProperty
                              );


/// Function to retrieve the reduced blanking setting. 
/// 
/// This function retrieves the current reduced blanking setting. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in]  context                  Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in]  iAdapterIndex            The ADL index handle of the desired adapter. 
///   [in]  iDisplayIndex            The desired display index. It can be retrieved from the ADLDisplayInfo data structure. 
///   [out] lpReducedBlankingCurrent The pointer to the current reduced blanking setting. 
///   [out] lpReducedBlankingDefault The pointer to the retrieved default setting. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes 
/// 
/// Remarks
///   Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call ADL2_Main_Control_Create first to obtain ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using ADL2_Main_Control_Destroy.
int ADL2_Display_ReducedBlanking_Get ( ADL_CONTEXT_HANDLE context,
                                       int                iAdapterIndex,
                                       int                iDisplayIndex,
                                       int *              lpReducedBlankingCurrent,
                                       int *              lpReducedBlankingDefault
                                     );


/// Function to set the reduced blanking setting. 
/// 
/// This function sets the current reduced blanking setting to a specified setting. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in] context          Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in] iAdapterIndex    The ADL index handle of the desired adapter. 
///   [in] iDisplayIndex    The desired display index. It can be retrieved from the ADLDisplayInfo data structure. 
///   [in] iReducedBlanking The desired reduced blanking setting. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes
/// 
/// Remarks
///   Call ADL_Flush_Driver_Data() after to persist settings on reboot.
int ADL2_Display_ReducedBlanking_Set ( ADL_CONTEXT_HANDLE context,
                                       int                iAdapterIndex,
                                       int                iDisplayIndex,
                                       int                iReducedBlanking
                                     );


/// Function to get the Device Display Size. 
/// 
/// This function retrieves the display position parameters. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in]  context         Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in]  iAdapterIndex   The ADL index handle of the desired adapter. 
///   [in]  iDisplayIndex   The desired display index. It can be retrieved from the ADLDisplayInfo data structure. 
///   [out] lpWidth         The pointer to the current display width. 
///   [out] lpHeight        The pointer to the current display height. 
///   [out] lpDefaultWidth  The pointer to the default display width. 
///   [out] lpDefaultHeight The pointer to the default display height. 
///   [out] lpMinWidth      The pointer to the minimum display width. 
///   [out] lpMinHeight     The pointer to the minimum display height. 
///   [out] lpMaxWidth      The pointer to the maximum display width. 
///   [out] lpMaxHeight     The pointer to the maximum display height. 
///   [out] lpStepWidth     The pointer to the step width. 
///   [out] lpStepHeight    The pointer to the step height. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes 
/// 
/// Remarks
///   Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call ADL2_Main_Control_Create first to obtain ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using ADL2_Main_Control_Destroy.
int ADL2_Display_Size_Get ( ADL_CONTEXT_HANDLE context,
                            int                iAdapterIndex,
                            int                iDisplayIndex,
                            int *              lpWidth,
                            int *              lpHeight,
                            int *              lpDefaultWidth,
                            int *              lpDefaultHeight,
                            int *              lpMinWidth,
                            int *              lpMinHeight,
                            int *              lpMaxWidth,
                            int *              lpMaxHeight,
                            int *              lpStepWidth,
                            int *              lpStepHeight
                          );


/// Function to set the Device Display Size. 
/// 
/// This function sets the display width and height values. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in] context       Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in] iAdapterIndex The ADL index handle of the desired adapter. 
///   [in] iDisplayIndex The desired display index. It can be retrieved from the ADLDisplayInfo data structure. 
///   [in] iWidth        The desired width of the display. 
///   [in] iHeight       The desired height of the display. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes
/// 
/// Remarks
///   Call ADL_Flush_Driver_Data() after to persist settings on reboot.
int ADL2_Display_Size_Set ( ADL_CONTEXT_HANDLE context,
                            int                iAdapterIndex,
                            int                iDisplayIndex,
                            int                iWidth,
                            int                iHeight
                          );


/// Function to retrieve the supported color depth. HDMI and DPonly. 
/// 
/// This function retrieves the current display on given adpaters supported color depths –When supported Color depth is one format only, no need expose the User interface. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in]  context       Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in]  iAdapterIndex the ADL index handle of the desired adapter per physical GPU. 
///   [in]  iDisplayIndex The desired display index. It can be retrieved from the ADLDisplayInfo data structure. 
///   [out] lpColorDepth  The pointer to the bit vector of all display supported color depths. define_color_depth_bits 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes
int ADL2_Display_SupportedColorDepth_Get ( ADL_CONTEXT_HANDLE context,
                                           int                iAdapterIndex,
                                           int                iDisplayIndex,
                                           int *              lpColorDepth
                                         );


/// Function to retrieve the supported pixel format. HDMI only. 
/// 
/// This function retrieves the supported pixel format. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in]  context       Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in]  iAdapterIndex The ADL index handle of the desired adapter. 
///   [in]  iDisplayIndex The desired display index. It can be retrieved from the ADLDisplayInfo data structure. 
///   [out] lpPixelFormat The pointer to the supported pixel format. Pixel Formats values 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes 
/// 
/// Remarks
///   Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call ADL2_Main_Control_Create first to obtain ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using ADL2_Main_Control_Destroy.
int ADL2_Display_SupportedPixelFormat_Get ( ADL_CONTEXT_HANDLE context,
                                            int                iAdapterIndex,
                                            int                iDisplayIndex,
                                            int *              lpPixelFormat
                                          );


/// Function to retrieve the Display Switching Flag from the registry. 
/// 
/// This function retrieves the Display Switching Flag from the registery for a specified adapter. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in]  iAdapterIndex The ADL index handle of the desired adapter. 
///   [out] lpResult      The pointer to value storing the retrieved flag. 1: Driver will not accept display switching request; 0: User can request display switching. 
///   [in]  context       Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes 
/// 
/// Remarks
///   Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call ADL2_Main_Control_Create first to obtain ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using ADL2_Main_Control_Destroy.
int ADL2_Display_SwitchingCapability_Get ( ADL_CONTEXT_HANDLE context,
                                           int                iAdapterIndex,
                                           int *              lpResult
                                         );


/// Function to retrieve current display mode timing override information. 
/// 
/// This function retrieves current display mode timing override information for a specified display. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in]  context       Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in]  iAdapterIndex The ADL index handle of the desired adapter. 
///   [in]  displayID     The desired display index. It can be retrieved from the ADLDisplayInfo data structure. 
///   [out] lpModeInfoOut The pointer to the ADLDisplayModeInfo structure storing the retrieved display mode information. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes 
/// 
/// Remarks
///   Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call ADL2_Main_Control_Create first to obtain ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using ADL2_Main_Control_Destroy.
int ADL2_Display_TargetTiming_Get ( ADL_CONTEXT_HANDLE   context,
                                    int                  iAdapterIndex,
                                    ADLDisplayID         displayID,
                                    ADLDisplayModeInfo * lpModeInfoOut
                                  );


/// This function retrieves current display mode timing override information for a specified display. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in]  context       Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in]  iAdapterIndex The ADL index handle of the desired adapter. 
///   [in]  displayID     The desired display index. It can be retrieved from the ADLDisplayInfo data structure. 
///   [out] lpModeInfoOut The pointer to the ADLDisplayModeInfo structure storing the retrieved display mode information. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes 
/// 
/// Remarks
///   Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call ADL2_Main_Control_Create first to obtain ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using ADL2_Main_Control_Destroy.
int ADL2_Display_TargetTimingX2_Get ( ADL_CONTEXT_HANDLE     context,
                                      int                    iAdapterIndex,
                                      ADLDisplayID           displayID,
                                      ADLDisplayModeInfoX2 * lpModeInfoOut
                                    );


/// Function to retrieve the TV Caps display information. 
/// 
/// This function retrieves the display adjustment information. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in]  context       Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in]  iAdapterIndex The ADL index handle of the desired adapter. 
///   [in]  iDisplayIndex The desired display index. It can be retrieved from the ADLDisplayInfo data structure. 
///   [out] lpcaps        The pointer to the TV Caps information retrieved from the driver. TV Capabilities and Standards 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes 
/// 
/// Remarks
///   Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call ADL2_Main_Control_Create first to obtain ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using ADL2_Main_Control_Destroy. 
/// Deprecated:
///   Dropping support for component, composite, and S-Video connectors.
int ADL2_Display_TVCaps_Get ( ADL_CONTEXT_HANDLE context,
                              int                iAdapterIndex,
                              int                iDisplayIndex,
                              int *              lpcaps
                            );


/// Function to get the current UnderScan Auto setting from the display. This function retrieves the UnderScan Auto information for a specified display. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in]  context       Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in]  iAdapterIndex The index of the desired adapter. 
///   [in]  iDisplayIndex The index of the desired display. 
///   [out] lpCurrent     The current underscan auto setting 
///   [out] lpDefault     The default underscan auto setting 
///   [out] lpMin         The current underscan auto setting 
///   [out] lpMax         The default underscan auto setting 
///   [out] lpStep        The current underscan auto setting 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK (zero). Otherwise the return value is an ADL error code (non-zero). Result Codes 
/// 
/// Remarks
///   Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call ADL2_Main_Control_Create first to obtain ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using ADL2_Main_Control_Destroy.
int ADL2_Display_UnderScan_Auto_Get ( ADL_CONTEXT_HANDLE context,
                                      int                iAdapterIndex,
                                      int                iDisplayIndex,
                                      int *              lpCurrent,
                                      int *              lpDefault,
                                      int *              lpMin,
                                      int *              lpMax,
                                      int *              lpStep
                                    );


/// Function to set the current UnderScan Auto setting for the display. This function set the UnderScan Auto setting for a specified display. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in] context       Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in] iAdapterIndex The index of the desired adapter. 
///   [in] iDisplayIndex The index of the desired display. 
///   [in] iCurrent      The new underscan auto setting 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK (zero). Otherwise the return value is an ADL error code (non-zero). Result Codes
/// 
/// Remarks
///   Call ADL_Flush_Driver_Data() after to persist settings on reboot.
int ADL2_Display_UnderScan_Auto_Set ( ADL_CONTEXT_HANDLE context,
                                      int                iAdapterIndex,
                                      int                iDisplayIndex,
                                      int                iCurrent
                                    );


/// Function to retrieve the detailed information for underscan. 
/// 
/// This function retrieves the detailed information for underscan. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in]  context       Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in]  iAdapterIndex The ADL index handle of the desired adapter. 
///   [in]  iDisplayIndex The desired display index. It can be retrieved from the ADLDisplayInfo data structure. 
///   [out] lpCurrent     The pointer to the current underscan value. 
///   [out] lpDefault     The pointer to the default underscan value. 
///   [out] lpMin         The pointer to the minimum underscan value. 
///   [out] lpMax         The pointer to the maximum underscan value. 
///   [out] lpStep        The pointer to the increment of the underscan setting. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes 
/// 
/// Remarks
///   Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call ADL2_Main_Control_Create first to obtain ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using ADL2_Main_Control_Destroy.
int ADL2_Display_Underscan_Get ( ADL_CONTEXT_HANDLE context,
                                 int                iAdapterIndex,
                                 int                iDisplayIndex,
                                 int *              lpCurrent,
                                 int *              lpDefault,
                                 int *              lpMin,
                                 int *              lpMax,
                                 int *              lpStep
                               );


/// Function to set the current value of underscan. 
/// 
/// 
/// 
/// This function sets the display underscan for a specified adapter, display. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in] context       Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in] iAdapterIndex The ADL index handle of the desired adapter. 
///   [in] iDisplayIndex The desired display index. It can be retrieved from the ADLDisplayInfo data structure. 
///   [in] iCurrent      The desired underscan value. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes
/// 
/// Remarks
///   Call ADL_Flush_Driver_Data() after to persist settings on reboot.
int ADL2_Display_Underscan_Set ( ADL_CONTEXT_HANDLE context,
                                 int                iAdapterIndex,
                                 int                iDisplayIndex,
                                 int                iCurrent
                               );


/// Function to get the value of under scan enabled. 
/// 
/// 
/// 
/// This function gets the display under scan enabled flag for a specified adapter, display. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in] context       Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in] iAdapterIndex The ADL index handle of the desired adapter. 
///   [in] iDisplayIndex The desired display index. It can be retrieved from the ADLDisplayInfo data structure. 
///   [in] *lpCurrent    pointer to the the under scan enabled current value. Enabled :1 ; disabled:0 
///   [in] *lpDefault    pointer to the the under scan enabled default value. Enabled :1 ; disabled:0 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes
/// 
/// Remarks
///   Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call ADL2_Main_Control_Create first to obtain ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using ADL2_Main_Control_Destroy.
int ADL2_Display_UnderscanState_Get ( ADL_CONTEXT_HANDLE context,
                                      int                iAdapterIndex,
                                      int                iDisplayIndex,
                                      int *              lpCurrent,
                                      int *              lpDefault
                                    );


/// Function to set the value of under scan enabled. 
/// 
/// 
/// 
/// This function sets the display under scan enabled flag for a specified adapter, display. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in] context           Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in] iAdapterIndex     The ADL index handle of the desired adapter. 
///   [in] iDisplayIndex     The desired display index. It can be retrieved from the ADLDisplayInfo data structure. 
///   [in] iUnderscanEnabled the the under scan enabled value. Enabled :1 ; disabled:0 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes
/// 
/// Remarks
///   Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call ADL2_Main_Control_Create first to obtain ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using ADL2_Main_Control_Destroy.
int ADL2_Display_UnderscanState_Set ( ADL_CONTEXT_HANDLE context,
                                      int                iAdapterIndex,
                                      int                iDisplayIndex,
                                      int                iUnderscanEnabled
                                    );


/// Function to get the value of under scan support. 
/// 
/// 
/// 
/// This function gets the display under scan support flag for a specified adapter, display. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in] context       Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in] iAdapterIndex The ADL index handle of the desired adapter. 
///   [in] iDisplayIndex The desired display index. It can be retrieved from the ADLDisplayInfo data structure. 
///   [in] *lpSupport    pointer to the the under scan support value. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes
/// 
/// Remarks
///   Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call ADL2_Main_Control_Create first to obtain ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using ADL2_Main_Control_Destroy.
int ADL2_Display_UnderscanSupport_Get ( ADL_CONTEXT_HANDLE context,
                                        int                iAdapterIndex,
                                        int                iDisplayIndex,
                                        int *              lpSupport
                                      );


/// Function to check if the selected adapter supports the view port control. 
/// 
/// This function used to check if the selected adapter supports the view port control. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in]  context       Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in]  iAdapterIndex The ADL index handle of the desired adapter. 
///   [out] lpSupported   is if this adapter supports the view port control. ADL_TRUE: the view port control are supported; otherwise: not supported. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes 
/// 
/// Remarks
///   Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call ADL2_Main_Control_Create first to obtain ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using ADL2_Main_Control_Destroy.
int ADL2_Display_ViewPort_Cap ( ADL_CONTEXT_HANDLE context,
                                int                iAdapterIndex,
                                int *              lpSupported
                              );


/// Function to get the view position, view size or view pan lock of a selected display. 
/// 
/// This function used to get the view position, view size or view pan lock of a selected display. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in]  context          Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in]  iAdapterIndex    The ADL index handle of the desired adapter. 
///   [in]  iDisplayIndex    The desired display index. It can be retrieved from the ADLDisplayInfo data structure. 
///   [out] lpControllerMode The pointer to the ADLControllerMode structure. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes 
/// 
/// Remarks
///   Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call ADL2_Main_Control_Create first to obtain ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using ADL2_Main_Control_Destroy.
int ADL2_Display_ViewPort_Get ( ADL_CONTEXT_HANDLE  context,
                                int                 iAdapterIndex,
                                int                 iDisplayIndex,
                                ADLControllerMode * lpControllerMode
                              );


/// Function to change the view position, view size or view pan lock of a selected display. 
/// 
/// This function used to change the view position, view size or view pan lock of a selected display. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in] context           Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in] iAdapterIndex     The ADL index handle of the desired adapter. 
///   [in] iDisplayIndex     The desired display index. It can be retrieved from the ADLDisplayInfo data structure. 
///   [in] lpControllerMode. The pointer to the ADLControllerMode structure. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes 
/// 
/// Remarks
///   Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call ADL2_Main_Control_Create first to obtain ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using ADL2_Main_Control_Destroy.
int ADL2_Display_ViewPort_Set ( ADL_CONTEXT_HANDLE  context,
                                int                 iAdapterIndex,
                                int                 iDisplayIndex,
                                ADLControllerMode * lpControllerMode
                              );


/// This function retrieves the type of virtual display for the given display. 
/// Supported Platforms:
///   Windows 7; 32bit and 64bit and above 
/// 
/// Parameters
///   [in]  context       Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in]  iAdapterIndex The ADL index handle of the desired adapter. 
///   [in]  iDisplayIndex The desired display index. 
///   [out] iVirtualType  The pointer to ADL_VIRTUALDISPLAY_TYPE telling virtual display type. See ADL_VIRTUALDISPLAY_TYPE 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes
int ADL2_Display_VirtualType_Get ( ADL_CONTEXT_HANDLE        context,
                                   int                       iAdapterIndex,
                                   int                       iDisplayIndex,
                                   ADL_VIRTUALDISPLAY_TYPE * iVirtualType
                                 );


/// Function to write and read I2C. 
/// 
/// This function writes and reads I2C. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in]     context       Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in]     iAdapterIndex The ADL index handle of the desired adapter. 
///   [in,out] plI2C         A pointer to the ADLI2C structure. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes 
/// 
/// Remarks
///   Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call ADL2_Main_Control_Create first to obtain ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using ADL2_Main_Control_Destroy.
int ADL2_Display_WriteAndReadI2C ( ADL_CONTEXT_HANDLE context,
                                   int                iAdapterIndex,
                                   ADLI2C *           plI2C
                                 );


/// This function writes and reads I2C. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in]     context       Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in]     iAdapterIndex The ADL index handle of the desired adapter. 
///   [in,out] plI2C         A pointer to the ADLI2CLargePayload structure. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes 
/// 
/// Remarks
///   Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call ADL2_Main_Control_Create first to obtain ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using ADL2_Main_Control_Destroy.
int ADL2_Display_WriteAndReadI2CLargePayload ( ADL_CONTEXT_HANDLE   context,
                                               int                  iAdapterIndex,
                                               ADLI2CLargePayload * plI2C
                                             );


/// Function to retrieve the I2C API revision. 
/// 
/// This function retrieves the I2C API revision. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in]  context       Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in]  iAdapterIndex The ADL index handle of the desired adapter. 
///   [out] lpMajor       The pointer to the major version. 
///   [out] lpMinor       The pointer to the minor version. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes 
/// 
/// Remarks
///   Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call ADL2_Main_Control_Create first to obtain ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using ADL2_Main_Control_Destroy.
int ADL2_Display_WriteAndReadI2CRev_Get ( ADL_CONTEXT_HANDLE context,
                                          int                iAdapterIndex,
                                          int *              lpMajor,
                                          int *              lpMinor
                                        );


/// Checks if given GPU (identified by adapter id) supports Turbo Sync functionality or not 
/// Supported Platforms:
///   Windows 7, 10 and above; 32bit and 64bit 
/// 
/// Parameters
///   [in]  context       : Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in]  iAdapterIndex : The ADL index handle of the desired adapter. 
///   [out]
int ADL2_TurboSyncSupport_Get ( ADL_CONTEXT_HANDLE context,
                                int                iAdapterIndex,
                                int *              iTurboSyncSupported
                              );


/// Function to retrieve the TV standard. 
/// 
/// This function retrieves the TV standard for a specified display. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in]  context              Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in]  iAdapterIndex        The ADL index handle of the desired adapter. 
///   [in]  iDisplayIndex        The desired display index. It can be retrieved from the ADLDisplayInfo data structure. 
///   [out] lpCurrent            The pointer to the current TV standard. TV Capabilities and Standards 
///   [out] lpDefault            The pointer to the default TV standard. TV Capabilities and Standards 
///   [out] lpSupportedStandards The pointer to the bit vector of the support video standard. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes 
/// 
/// Remarks
///   Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call ADL2_Main_Control_Create first to obtain ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using ADL2_Main_Control_Destroy. 
/// Deprecated:
///   Dropping support for component, composite, and S-Video connectors.
int ADL2_TV_Standard_Get ( ADL_CONTEXT_HANDLE context,
                           int                iAdapterIndex,
                           int                iDisplayIndex,
                           int *              lpCurrent,
                           int *              lpDefault,
                           int *              lpSupportedStandards
                         );


/// Function to set the TV standard. 
/// 
/// This function sets the TV Standard for a specified display. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in] context       Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in] iAdapterIndex The ADL index handle of the desired adapter. 
///   [in] iDisplayIndex The desired display index. It can be retrieved from the ADLDisplayInfo data structure. 
///   [in] iCurrent      The desired TV Standard. TV Capabilities and Standards 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes
/// 
/// Remarks
///   Call ADL_Flush_Driver_Data() after to persist settings on reboot. 
/// Deprecated:
///   Dropping support for component, composite, and S-Video connectors.
int ADL2_TV_Standard_Set ( ADL_CONTEXT_HANDLE context,
                           int                iAdapterIndex,
                           int                iDisplayIndex,
                           int                iCurrent
                         );


/// Supported Platforms:
///   Windows 7, 10 and above; 32bit and 64bit 
/// 
/// Parameters
///   [in] context       Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in] iAdapterIndex The index of the desired adapter. 
///   [in] iSetting      user blob features. ADL_USER_SETTINGS 
///   [in] iChanged      ADL_TRUE ADL_FALSE 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK (zero). Otherwise the return value is an ADL error code (non-zero). Result Codes
/// 
/// Remarks
///   Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call ADL2_Main_Control_Create first to obtain ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using ADL2_Main_Control_Destroy.
int ADL2_User_Settings_Notify ( ADL_CONTEXT_HANDLE context,
                                int                iAdapterIndex,
                                ADL_USER_SETTINGS  iSetting,
                                int                iChanged
                              );


/// Function to retrieve Timing Override support. 
/// 
/// This function retrieves Timing Override support for a specified display. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in]  iAdapterIndex The ADL index handle of the desired adapter. 
///   [out] lpSupported   If the specified adapter supports Custom Resolutions then returns ADL_TRUE else ADL_FALSE 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes
int ADL_Adapter_ModeTimingOverride_Caps ( int   iAdapterIndex,
                                          int * lpSupported
                                        );


/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in] iAdapterIndex The index of the desired adapter. 
///   [in] iSupported    The pointer to an int variable which indicates if VariBright is supported ( ADL_TRUE : supported, ADL_FALSE : not supported) 
///   [in] iEnabled      The pointer to an int variable which indicates if VariBright is enabled ( ADL_TRUE : enabled, ADL_FALSE : disabled) 
///   [in] iEnabled      The pointer to an int variable receiving the VariBright version. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK (zero). Otherwise the return value is an ADL error code (non-zero). Result Codes
/// 
/// Remarks
///   Call this API first. Only if VariBright feature is supported and enabled call ADL_Adapter_VariBrightLevel_Get() or ADL_Adapter_VariBrightLevel_Set()
int ADL_Adapter_VariBright_Caps ( int   iAdapterIndex,
                                  int * iSupported,
                                  int * iEnabled,
                                  int * iVersion
                                );


/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in] iAdapterIndex The index of the desired adapter. 
///   [in] iEnabled      ADL_TRUE : enables VariBright, ADL_FALSE : disables VariBright. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK (zero). Otherwise the return value is an ADL error code (non-zero). Result Codes
/// 
/// Remarks
///   Call ADL_Adapter_VariBright_CapsX2() first to determine if VariBright feature is supported.
int ADL_Adapter_VariBrightEnable_Set ( int iAdapterIndex,
                                       int iEnabled
                                     );


/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in] iAdapterIndex   The index of the desired adapter. 
///   [in] iDefaultLevel   The pointer to an int variable with the default VariBright level. 
///   [in] iNumberOfLevels The pointer to an int variable receiving the number of VariBright levels (the Maximum value for VariBright level). 
///   [in] iStep           The pointer to an int variable receiving the VariBright step. Determines the increments of the VariBright transition from one level to another. 
///   [in] iCurrentLevel   The pointer to an int variable receiving the Current VariBright level. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK (zero). Otherwise the return value is an ADL error code (non-zero). Result Codes
/// 
/// Remarks
///   Call ADL_Adapter_VariBright_CapsX2() first to determine if VariBright feature is supported.
int ADL_Adapter_VariBrightLevel_Get ( int   iAdapterIndex,
                                      int * iDefaultLevel,
                                      int * iNumberOfLevels,
                                      int * iStep,
                                      int * iCurrentLevel
                                    );


/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in] iAdapterIndex     The index of the desired adapter. 
///   [in] iCurrentLevel     The VariBright level to be set. The range is from zero to iNumberOfLevels returned from ADL_Adapter_VariBrightLevel_Get() 
///   [in] iApplyImmediately If set to ADL_TRUE the VariBright level is applied immediately. If ADL_FALSE - the level is applied gradually. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK (zero). Otherwise the return value is an ADL error code (non-zero). Result Codes.
/// 
/// Remarks
///   Call ADL_Adapter_VariBright_CapsX2() first to determine if VariBright feature is supported.
int ADL_Adapter_VariBrightLevel_Set ( int iAdapterIndex,
                                      int iCurrentLevel,
                                      int iApplyImmediately
                                    );


/// Function to set the current EDS mode enumeration mode. 
/// 
/// This function sets the current EDS mode enumeration mode: Safe or Unsafe(raw modes). 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in] iAdapterIndex The ADL index handle of the desired adapter. 
///   [in] unsafeMode    The EDS mode enumeration mode to set (0: Safe mode, 1: Unsafe mode). 
/// 
/// Returns
///   Succeed: ADL_OK. Otherwise: ADL error code Result Codes
int ADL_CDS_UnsafeMode_Set ( int iAdapterIndex,
                             int unsafeMode
                           );


/// Function to retrieve the settings of the CV dongle. 
/// 
/// This function retrieves the CV dongle settings. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in]  iAdapterIndex               The ADL index handle of the desired adapter. 
///   [in]  iDisplayIndex               The desired display index. It can be retrieved from the ADLDisplayInfo data structure. 
///   [out] lpDongleSetting             The pointer to the CV dongle settings. 
///   [out] lpOverrideSettingsSupported The pointer to the supported override settings. 
///   [out] lpCurOverrideSettings       The pointer to the current CV override settings.
/// Values used by ADL_CV_DongleSettings_xxx 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes 
/// 
/// Deprecated:
///   Dropping support for component, composite, and S-Video connectors.
int ADL_CV_DongleSettings_Get ( int   iAdapterIndex,
                                int   iDisplayIndex,
                                int * lpDongleSetting,
                                int * lpOverrideSettingsSupported,
                                int * lpCurOverrideSettings
                              );


/// Function to reset the CV settings to its default settings. 
/// 
/// This function resets the CV dongle settings. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in] iAdapterIndex The ADL index handle of the desired adapter. 
///   [in] iDisplayIndex The desired display index. It can be retrieved from the ADLDisplayInfo data structure. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes
/// 
/// Remarks
///   Call ADL_Flush_Driver_Data() after to persist settings on reboot. 
/// Deprecated:
///   Dropping support for component, composite, and S-Video connectors.
int ADL_CV_DongleSettings_Reset ( int iAdapterIndex,
                                  int iDisplayIndex
                                );


/// Function to set the current CV dongle settings. 
/// 
/// This function sets the current CV dongle settings to a specified setting. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in] iAdapterIndex     The ADL index handle of the desired adapter. 
///   [in] iDisplayIndex     The desired display index. It can be retrieved from the ADLDisplayInfo data structure. 
///   [in] iOverrideSettings The new CV settings. Values used by ADL_CV_DongleSettings_xxx 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes
/// 
/// Remarks
///   Call ADL_Flush_Driver_Data() after to persist settings on reboot. 
/// Deprecated:
///   Dropping support for component, composite, and S-Video connectors.
int ADL_CV_DongleSettings_Set ( int iAdapterIndex,
                                int iDisplayIndex,
                                int iOverrideSettings
                              );


/// Function to get the Allow Only CE Timings setting. 
/// 
/// This function sets the Allow Only CE Timings setting for a specified display. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in] iAdapterIndex The ADL index handle of the desired adapter. 
///   [in] iDisplayIndex The desired display index. It can be retrieved from the ADLDisplayInfo data structure. 
///   [in] lpSupport     The pointer to the value indicating whether AllowOnlyCETimings is supported. 1: supported; 0: not supported. 
///   [in] lpCurrent     The pointer to the value indicating whether AllowOnlyCETimings is currently enabled. 1: enabled; 0: disabled. 
///   [in] lpDefault     The pointer to the AllowOnlyCETimings default setting. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK, ADL_ERR_NULL_POINTER if any of the inputs is NULL, Otherwise the return value is an ADL_ERR. Result Codes
int ADL_DFP_AllowOnlyCETimings_Get ( int   iAdapterIndex,
                                     int   iDisplayIndex,
                                     int * lpSupport,
                                     int * lpCurrent,
                                     int * lpDefault
                                   );


/// Function to set the Allow Only CE Timings setting. 
/// 
/// This function sets the Allow Only CE Timings setting for a specified display. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in] iAdapterIndex The ADL index handle of the desired adapter. 
///   [in] iDisplayIndex The desired display index. It can be retrieved from the ADLDisplayInfo data structure. 
///   [in] iCurrent      The desired Allow Only CE Timings state for the specified display. 1: enabled; 0: disabled.. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes
/// 
/// Remarks
///   Call ADL_Flush_Driver_Data() after to persist settings on reboot.
int ADL_DFP_AllowOnlyCETimings_Set ( int iAdapterIndex,
                                     int iDisplayIndex,
                                     int iCurrent
                                   );


/// Function to get the display base audio support. 
/// 
/// This function determines whether base display audio support is available. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in]  iAdapterIndex The ADL index handle of the desired adapter. 
///   [in]  iDisplayIndex The desired display index. It can be retrieved from the ADLDisplayInfo data structure. 
///   [out] lpSupport     The int pointer to the value indicating whether the feature is supported by the driver. 1: feature is supported; 0: feature is not supported. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes
int ADL_DFP_BaseAudioSupport_Get ( int   iAdapterIndex,
                                   int   iDisplayIndex,
                                   int * lpSupport
                                 );


/// Function to get the GPUScalingEnable setting. 
/// 
/// This function sets the GPU Scaling Enable setting for a specified display. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in] iAdapterIndex The ADL index handle of the desired adapter. 
///   [in] iDisplayIndex The desired display index. It can be retrieved from the ADLDisplayInfo data structure. 
///   [in] lpSupport     The pointer to the value indicating whether GPUScalingEnable is supported. 1: supported; 0: not supported. 
///   [in] lpCurrent     The pointer to the value indicating whether GPUScalingEnable is currently enabled. 1: enabled; 0: disabled. 
///   [in] lpDefault     The pointer to the GPUScalingEnable default setting. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK, ADL_ERR_NULL_POINTER if any of the inputs is NULL, Otherwise the return value is an ADL_ERR. Result Codes
int ADL_DFP_GPUScalingEnable_Get ( int   iAdapterIndex,
                                   int   iDisplayIndex,
                                   int * lpSupport,
                                   int * lpCurrent,
                                   int * lpDefault
                                 );


/// Function to set the GPUScalingEnable setting. 
/// 
/// This function sets the GPU Scaling Enable setting for a specified display. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in] iAdapterIndex The ADL index handle of the desired adapter. 
///   [in] iDisplayIndex The desired display index. It can be retrieved from the ADLDisplayInfo data structure. 
///   [in] iCurrent      The desired GPU Scaling Enable state for the specified display. 1: enabled; 0: disabled.. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes
/// 
/// Remarks
///   Call ADL_Flush_Driver_Data() after to persist settings on reboot.
int ADL_DFP_GPUScalingEnable_Set ( int iAdapterIndex,
                                   int iDisplayIndex,
                                   int iCurrent
                                 );


/// Function to get the display HDMI support. 
/// 
/// This function determines whether the base display HDMI support is available. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in]  iAdapterIndex The ADL index handle of the desired adapter. 
///   [in]  iDisplayIndex The desired display index. It can be retrieved from the ADLDisplayInfo data structure. 
///   [out] lpSupport     The int pointer indicating whether the feature is supported by the driver. If the feature is supported, a value of 1 is stored. Otherwise, a value of 0 is stored. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes
int ADL_DFP_HDMISupport_Get ( int   iAdapterIndex,
                              int   iDisplayIndex,
                              int * lpSupport
                            );


/// Function to get the display MVPU analog support. 
/// 
/// This function determines whether display MVPU analog support is available. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in]  iAdapterIndex The ADL index handle of the desired adapter. 
///   [in]  iDisplayIndex The desired display index. It can be retrieved from the ADLDisplayInfo data structure. 
///   [out] lpSupport     The int pointer to the value indicating whether the feature is supported by the driver. 1: feature is supported; 0: feature is not supported. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes
int ADL_DFP_MVPUAnalogSupport_Get ( int   iAdapterIndex,
                                    int   iDisplayIndex,
                                    int * lpSupport
                                  );


/// Function to retrieve PixelFormat caps. 
/// 
/// This function retrieves the pixel format caps for a specified display. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in]  iAdapterIndex The ADL index handle of the desired adapter. 
///   [in]  iDisplayIndex The desired display index. It can be retrieved from the ADLDisplayInfo data structure. 
///   [out] lpValidBits   The pointer to the bit field indicating which bits in the lpValidCaps parameter are valid. 
///   [out] lpValidCaps   The pointer to the valid pixel formats caps. Pixel Formats values 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes
/// 
/// Remarks
///   This API is supported only by HDMI.
int ADL_DFP_PixelFormat_Caps ( int   iAdapterIndex,
                               int   iDisplayIndex,
                               int * lpValidBits,
                               int * lpValidCaps
                             );


/// Function to retrieve current pixel format setting. 
/// 
/// This function retrieves the pixel format setting for a specified display. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in]  iAdapterIndex The ADL index handle of the desired adapter. 
///   [in]  iDisplayIndex The desired display index. It can be retrieved from the ADLDisplayInfo data structure. 
///   [out] lpCurState    The pointer to the current pixel format of the display. Pixel Formats values 
///   [out] lpDefault     The pointer to the default pixel format of the display. Pixel Formats values 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes
/// 
/// Remarks
///   This API is supported only by HDMI.
int ADL_DFP_PixelFormat_Get ( int   iAdapterIndex,
                              int   iDisplayIndex,
                              int * lpCurState,
                              int * lpDefault
                            );


/// Function to set the current pixel format setting. 
/// 
/// This function sets the pixel format setting for a specified display. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in] iAdapterIndex The ADL index handle of the desired adapter. 
///   [in] iDisplayIndex The desired display index. It can be retrieved from the ADLDisplayInfo data structure. 
///   [in] iState        The desired pixel format for the specified display. Pixel Formats values 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes
/// 
/// Remarks
///   This API is supported only by HDMI.
int ADL_DFP_PixelFormat_Set ( int iAdapterIndex,
                              int iDisplayIndex,
                              int iState
                            );


/// Function to retrieve the adjustment display information. 
/// 
/// This function retrieves the display adjustment information for a specified adapter and display. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in]  iAdapterIndex The ADL index handle of the desired adapter. 
///   [in]  iDisplayIndex The desired display index. It can be retrieved from the ADLDisplayInfo data structure. 
///   [out] lpInfo        The pointer to the adjustment information retrieved from the driver.
/// Display Adjustment Capabilities 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes
int ADL_Display_AdjustCaps_Get ( int   iAdapterIndex,
                                 int   iDisplayIndex,
                                 int * lpInfo
                               );


/// Function to retrieve the adjustment coherent setting. 
/// 
/// This function retrieves the current adjustment coherent setting
/// 
/// It is applicable to DFP/DFP2 display types. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in]  iAdapterIndex               The ADL index handle of the desired adapter. 
///   [in]  iDisplayIndex               The desired display index. It can be retrieved from the ADLDisplayInfo data structure. 
///   [out] lpAdjustmentCoherentCurrent The pointer to the retrieved adjustment coherent setting. 1: Coherent; 0: non-coherent 
///   [out] lpAdjustmentCoherentDefault The pointer to the retrieved default setting. 1: Coherent; 0: Non-coherent 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes
int ADL_Display_AdjustmentCoherent_Get ( int   iAdapterIndex,
                                         int   iDisplayIndex,
                                         int * lpAdjustmentCoherentCurrent,
                                         int * lpAdjustmentCoherentDefault
                                       );


/// Function to set the adjustment coherent setting. 
/// 
/// This function sets the current adjustment coherent setting to a specified setting. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in] iAdapterIndex       The ADL index handle of the desired adapter. 
///   [in] iDisplayIndex       The desired display index. It can be retrieved from the ADLDisplayInfo data structure. 
///   [in] iAdjustmentCoherent The desired adjustment coherent setting. 1: Coherent; 0: Non-coherent 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes
/// 
/// Remarks
///   Call ADL_Flush_Driver_Data() after to persist settings on reboot.
int ADL_Display_AdjustmentCoherent_Set ( int iAdapterIndex,
                                         int iDisplayIndex,
                                         int iAdjustmentCoherent
                                       );


/// Function to get the number of displays and controllers supported by an adapter. 
/// 
/// This function retrieves the number of displays and controllers that are supported by a specified adapter. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in]  iAdapterIndex        The ADL index handle of the desired adapter. 
///   [out] lpNumberOfControlers The pointer to the variable storing the total number of controllers. This variable must be initialized. 
///   [out] lpNumberOfDisplays   The pointer to the variable storing the total number of displays. This variable must be initialized. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes
int ADL_Display_Capabilities_Get ( int   iAdapterIndex,
                                   int * lpNumberOfControlers,
                                   int * lpNumberOfDisplays
                                 );


/// Function to retrieve the detailed information a specified display color item. 
/// 
/// This function retrieves the detailed information for a specified display color. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in]  iAdapterIndex The ADL index handle of the desired adapter. 
///   [in]  iDisplayIndex The desired display index. It can be retrieved from the ADLDisplayInfo data structure. 
///   [in]  iColorType    The desired color type. It can be any of the defined type. Display Color Type and Source 
///   [out] lpCurrent     The pointer to the current color value. 
///   [out] lpDefault     The pointer to the default color value. 
///   [out] lpMin         The pointer to the minimum color value. 
///   [out] lpMax         The pointer to the maximum color value. 
///   [out] lpStep        The pointer to the increment of the color setting. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes
int ADL_Display_Color_Get ( int   iAdapterIndex,
                            int   iDisplayIndex,
                            int   iColorType,
                            int * lpCurrent,
                            int * lpDefault,
                            int * lpMin,
                            int * lpMax,
                            int * lpStep
                          );


/// Function to set the current value of a specific color and type. 
/// 
/// 
/// 
/// This function sets the display color for a specified adapter, display, and color type. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in] iAdapterIndex The ADL index handle of the desired adapter. 
///   [in] iDisplayIndex The desired display index. It can be retrieved from the ADLDisplayInfo data structure. 
///   [in] iColorType    The desired color type. It can be any of the defined type. Display Color Type and Source 
///   [in] iCurrent      The desired color value. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes
/// 
/// Remarks
///   Call ADL_Flush_Driver_Data() after to persist settings on reboot.
int ADL_Display_Color_Set ( int iAdapterIndex,
                            int iDisplayIndex,
                            int iColorType,
                            int iCurrent
                          );


/// Function to get the Color Caps display information. 
/// 
/// This function retrieves the display Color Caps information for a specified adapter and display. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in]  iAdapterIndex The ADL index handle of the desired adapter. 
///   [in]  iDisplayIndex The desired display index. It can be retrieved from the ADLDisplayInfo data structure. 
///   [out] lpCaps        The pointer to the Color Caps information retrieved from the driver. Display Color Type and Source 
///   [out] lpValids      The pointer to the bit vector indicating which bit is valid on the lpCaps returned. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes
int ADL_Display_ColorCaps_Get ( int   iAdapterIndex,
                                int   iDisplayIndex,
                                int * lpCaps,
                                int * lpValids
                              );


/// Function to get color depth. HDMI and DPonly. 
/// 
/// This function retrieves the current display on given adpaters current color depth. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in]  iAdapterIndex The ADL index handle of the desired adapter per physical GPU. 
///   [in]  iDisplayIndex The desired display index. It can be retrieved from the ADLDisplayInfo data structure. 
///   [out] lpColorDepth  The pointer to the current color depth setting for given display. Define_colordepth_constants 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes
int ADL_Display_ColorDepth_Get ( int   iAdapterIndex,
                                 int   iDisplayIndex,
                                 int * lpColorDepth
                               );


/// Function to set color depth. HDMI and DPonly. 
/// 
/// This function sets a user select color depth to current display on given adapter. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in] iAdapterIndex The ADL index handle of the desired adapter per physical GPU. 
///   [in] iDisplayIndex The desired display index. It can be retrieved from the ADLDisplayInfo data structure. 
///   [in] iColorDepth   Requested color depth. Define_colordepth_constants 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes
int ADL_Display_ColorDepth_Set ( int iAdapterIndex,
                                 int iDisplayIndex,
                                 int iColorDepth
                               );


/// Function to get color temperature source. 
/// 
/// This function retrieves the current color temperature source. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in]  iAdapterIndex The ADL index handle of the desired adapter. 
///   [in]  iDisplayIndex The desired display index. It can be retrieved from the ADLDisplayInfo data structure. 
///   [out] lpTempSource  The pointer of the retrieved current color temperature source. Display Color Type and Source 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes
int ADL_Display_ColorTemperatureSource_Get ( int   iAdapterIndex,
                                             int   iDisplayIndex,
                                             int * lpTempSource
                                           );


/// Function to set the color temperature source. 
/// 
/// This function sets the current color temperature source. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in] iAdapterIndex The ADL index handle of the desired adapter. 
///   [in] iDisplayIndex The desired display index. It can be retrieved from the ADLDisplayInfo data structure. 
///   [in] iTempSource   The desired color temperature source. Display Color Type and Source 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes
/// 
/// Remarks
///   Call ADL_Flush_Driver_Data() after to persist settings on reboot.
int ADL_Display_ColorTemperatureSource_Set ( int iAdapterIndex,
                                             int iDisplayIndex,
                                             int iTempSource
                                           );


/// Function to indicate whether displays are physically connected to an adapter. 
/// 
/// This function indicates whether displays are physically connected to a specified adapter. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in]  iAdapterIndex The ADL index handle of the desired adapter. 
///   [out] lpConnections The pointer to the bit field indicating whether the output connectors on the specified adapter have devices physically attached to them. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes
int ADL_Display_ConnectedDisplays_Get ( int   iAdapterIndex,
                                        int * lpConnections
                                      );


/// Function to get the minimum, maximum, and default values of an overlay adjustment. 
/// 
/// This function retrieves the minimum, maximum, and default values of an overlay adjustment for a specified adapter. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in]     iAdapterIndex  The ADL index handle of the desired adapter. 
///   [in]     lpOverlayInput The pointer to the ADLControllerOverlayInput structure. 
///   [in,out] lpCapsInfo     The pointer to the ADLControllerOverlayInfo structure storing the retrieved overlay adjustment information. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes
int ADL_Display_ControllerOverlayAdjustmentCaps_Get ( int                         iAdapterIndex,
                                                      ADLControllerOverlayInput * lpOverlayInput,
                                                      ADLControllerOverlayInfo *  lpCapsInfo
                                                    );


/// Function to retrieve the current setting of an overlay adjustment. 
/// 
/// This function retrieves the current setting of an overlay adjustment. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in]  iAdapterIndex The ADL index handle of the desired adapter. 
///   [out] lpOverlay     The pointer to the retrieved overlay adjustment ADLControllerOverlayInput structure. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes
int ADL_Display_ControllerOverlayAdjustmentData_Get ( int                         iAdapterIndex,
                                                      ADLControllerOverlayInput * lpOverlay
                                                    );


/// Function to set the current setting of an overlay adjustment. 
/// 
/// This function sets the current setting of an overlay adjustment. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in]     iAdapterIndex The ADL index handle of the desired adapter. 
///   [in,out] lpOverlay     The pointer to the overlay adjustment ADLControllerOverlayInput structure. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes
/// 
/// Remarks
///   Call ADL_Flush_Driver_Data() after to persist settings on reboot.
int ADL_Display_ControllerOverlayAdjustmentData_Set ( int                         iAdapterIndex,
                                                      ADLControllerOverlayInput * lpOverlay
                                                    );


/// Function to add a customized mode. 
/// 
/// This function adds a custom mode to the customized mode list. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in] iAdapterIndex The ADL index handle of the desired adapter. 
///   [in] iDisplayIndex The desired display index. It can be retrieved from the ADLDisplayInfo data structure. 
///   [in] customMode    The custom mode to be added to the list. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes
/// 
/// Remarks
///   Call ADL_Flush_Driver_Data() after to persist settings on reboot.
int ADL_Display_CustomizedMode_Add ( int           iAdapterIndex,
                                     int           iDisplayIndex,
                                     ADLCustomMode customMode
                                   );


/// Function to delete a customized mode. 
/// 
/// This function deletes a custom mode from the customized mode list. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in] iAdapterIndex The ADL index handle of the desired adapter. 
///   [in] iDisplayIndex The desired display index. It can be retrieved from the ADLDisplayInfo data structure. 
///   [in] iIndex        The index value of the mode to be deleted. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes
/// 
/// Remarks
///   Call ADL_Flush_Driver_Data() after to persist settings on reboot.
int ADL_Display_CustomizedMode_Delete ( int iAdapterIndex,
                                        int iDisplayIndex,
                                        int iIndex
                                      );


/// Function to validate a customized mode. 
/// 
/// This function validates a custom mode from the customized mode list. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in]  iAdapterIndex The ADL index handle of the desired adapter. 
///   [in]  iDisplayIndex The desired display index. It can be retrieved from the ADLDisplayInfo data structure. 
///   [in]  customMode    The custom mode to be validated. 
///   [out] lpValid       The pointer to the retrieved validation bit. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes
int ADL_Display_CustomizedMode_Validate ( int           iAdapterIndex,
                                          int           iDisplayIndex,
                                          ADLCustomMode customMode,
                                          int *         lpValid
                                        );


/// Function to retrieve the customized mode list. 
/// 
/// This function retrieves the customized mode list for a specified display. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in]  iAdapterIndex    The ADL index handle of the desired adapter. 
///   [in]  iDisplayIndex    The desired display index. It can be retrieved from the ADLDisplayInfo data structure. 
///   [out] lpCustomModeList The pointer to the list of the returned ADLCustomMode structures. The user should allocate the memory: Number of modes * sizeof ( ADLCustomMode ) 
///   [in]  iBuffSize        The size of the lpCustomModelist buffer. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes
int ADL_Display_CustomizedModeList_Get ( int             iAdapterIndex,
                                         int             iDisplayIndex,
                                         ADLCustomMode * lpCustomModeList,
                                         int             iBuffSize
                                       );


/// Function to retrieve the number of customized modes. 
/// 
/// This function retrieves the number of customized modes for a specified display. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in]  iAdapterIndex The ADL index handle of the desired adapter. 
///   [in]  iDisplayIndex The desired display index. It can be retrieved from the ADLDisplayInfo data structure. 
///   [out] lpListNum     The pointer to the number of available modes. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes
int ADL_Display_CustomizedModeListNum_Get ( int   iAdapterIndex,
                                            int   iDisplayIndex,
                                            int * lpListNum
                                          );


/// Function to retrieve per display Display Connectivity Experience information. 
/// 
/// This function retrieves the Display Connectivity Experience settings of a display. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in]  iAdapterIndex  The ADL index handle of the desired adapter. 
///   [in]  iDisplayIndex  The desired display index. It can be retrieved from the ADLDisplayInfo data structure. 
///   [out] lpFreeSyncCaps The pointer to the ADLDceSettings structure 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes
int ADL_Display_DCE_Get ( int              iAdapterIndex,
                          int              iDisplayIndex,
                          ADLDceSettings * lpADLDceSettings
                        );


/// Function to retrieve per display Display Connectivity Experience information. 
/// 
/// This function sets the Display Connectivity Experience settings of a display. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in]  iAdapterIndex  The ADL index handle of the desired adapter. 
///   [in]  iDisplayIndex  The desired display index. It can be retrieved from the ADLDisplayInfo data structure. 
///   [out] lpFreeSyncCaps The pointer to the ADLDceSettings structure 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes
int ADL_Display_DCE_Set ( int              iAdapterIndex,
                          int              iDisplayIndex,
                          ADLDceSettings * lpADLDceSettings
                        );


/// Function to get Display DDC block access. 
/// 
/// This function provides means for applications to send/receive data in the DDC information block via the 12C bus. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in]  iAdapterIndex  The ADL index handle of the desired adapter. 
///   [in]  iDisplayIndex  The desired display index. It can be retrieved from the ADLDisplayInfo data structure. 
///   [in]  iOption        Combination of ADL_DDC_OPTION_SWITCHDDC2 and ADL_DDC_OPTION_RESTORECOMMAND 
/// 
///   [in]  iCommandIndex  The index of the command to be saved in the registry. This parameter is used only when ADL_DDC_OPTION_RESTORECOMMAND of iOption is specified. Otherwize set this parameter to 0. 
///   [in]  iSendMsgLen    The size of the send message buffer. 
///   [in]  lpucSendMsgBuf The pointer to the send message buffer. 
///   [out] lpulRecvMsgLen The pointer to the size of the receive message buffer. 
///   [out] lpucRecvMsgBuf The pointer to the retrieved receive message buffer. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes
/// 
/// Remarks
///   To send data without receiving anything back, specify non-zero send message size and non-NULL buffer, then set the receive message size to 0 and buffer to NULL.
///  To receive data, you have to send a command defined by the I2C protocol to the display, so you will always have to send some sequence of bytes to the display, even if you only want to read from the display.
///  To send and receive data at the same time, specify non-zero send and receive message size and non-NULL send and receive message buffers. You will have to worry about sending proper commands to the display, as defined by the I2C protocol.
int ADL_Display_DDCBlockAccess_Get ( int    iAdapterIndex,
                                     int    iDisplayIndex,
                                     int    iOption,
                                     int    iCommandIndex,
                                     int    iSendMsgLen,
                                     char * lpucSendMsgBuf,
                                     int *  lpulRecvMsgLen,
                                     char * lpucRecvMsgBuf
                                   );


/// Function to get the DDC info. 
/// 
/// This function retrieves the display device config (DDC) information only if the device has the information. No assumption should be made that this call will cause the driver will do real time detection. The driver determines when DDC detection should take place. If a display is attached and it supports DDC, all available information should be returned and ADLDDCInfo.ulSupportsDDC should be set to 1. Any fields that are not supported by an attached DDC display should be zeroed on return. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in]  iAdapterIndex The ADL index handle of the desired adapter. 
///   [in]  iDisplayIndex The desired display index. It can be retrieved from the ADLDisplayInfo data structure. 
///   [out] lpInfo        The pointer to the ADLDDCInfo structure storing all DDC retrieved from the driver. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes
int ADL_Display_DDCInfo2_Get ( int           iAdapterIndex,
                               int           iDisplayIndex,
                               ADLDDCInfo2 * lpInfo
                             );


/// Function to get the DDC info. 
/// 
/// This function retrieves the display device config (DDC) information only if the device has the information. No assumption should be made that this call will cause the driver will do real time detection. The driver determines when DDC detection should take place. If a display is attached and it supports DDC, all available information should be returned and ADLDDCInfo.ulSupportsDDC should be set to 1. Any fields that are not supported by an attached DDC display should be zeroed on return. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in]  iAdapterIndex The ADL index handle of the desired adapter. 
///   [in]  iDisplayIndex The desired display index. It can be retrieved from the ADLDisplayInfo data structure. 
///   [out] lpInfo        The pointer to the ADLDDCInfo structure storing all DDC retrieved from the driver. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes
int ADL_Display_DDCInfo_Get ( int          iAdapterIndex,
                              int          iDisplayIndex,
                              ADLDDCInfo * lpInfo
                            );


/// Function to get the current Deflicker setting from the display. This function retrieves the Deflicker information for a specified display. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in]  iAdapterIndex The index of the desired adapter. 
///   [in]  iDisplayIndex The index of the desired display. 
///   [out] lpCurrent     The current Deflicker setting 
///   [out] lpDefault     The default Deflicker setting 
///   [out] lpMin         The current Deflicker setting 
///   [out] lpMax         The default Deflicker setting 
///   [out] lpStep        The current Deflicker setting 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK (zero). Otherwise the return value is an ADL error code (non-zero). Result Codes
int ADL_Display_Deflicker_Get ( int   iAdapterIndex,
                                int   iDisplayIndex,
                                int * lpCurrent,
                                int * lpDefault,
                                int * lpMin,
                                int * lpMax,
                                int * lpStep
                              );


/// Function to set the current Deflicker setting for the display. This function set the Deflicker setting for a specified display. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in] iAdapterIndex The index of the desired adapter. 
///   [in] iDisplayIndex The index of the desired display. 
///   [in] iCurrent      The new Deflicker setting 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK (zero). Otherwise the return value is an ADL error code (non-zero). Result Codes
/// 
/// Remarks
///   Call ADL_Flush_Driver_Data() after to persist settings on reboot.
int ADL_Display_Deflicker_Set ( int iAdapterIndex,
                                int iDisplayindex,
                                int iCurrent
                              );


/// Function to get HDTV capability settings. 
/// 
/// This function retrieves HDTV capability settings for a specified display. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in]  iAdapterIndex   The ADL index handle of the desired adapter. 
///   [in]  iDisplayIndex   The desired display index. It can be retrieved from the ADLDisplayInfo data structure. 
///   [out] lpDisplayConfig The pointer to the retrieved display configuration. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes
int ADL_Display_DeviceConfig_Get ( int                iAdapterIndex,
                                   int                iDisplayIndex,
                                   ADLDisplayConfig * lpDisplayConfig
                                 );


/// This function gets the application availability for display content value and ITC flag. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in] iAdapterIndex The index of the desired adapter. 
///   [in] iDisplayIndex The index of the desired display. 
///   [in] pCapContent   The current cap setting(if display content and ITC data are retrievable); where pCapContent returns the bitOR value of all supported ADLDisplayContent.iContentType (i.e. according to definitions of ADLDisplayContent.iContentType, if all content is supported it is expected that pCapContent will return with a value of, Graphics | Photo | Cinema |Game = 15) 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK (zero). Otherwise the return value is an ADL error code (non-zero). Result Codes
/// 
/// Remarks
///   Call ADL_Flush_Driver_Data() after to persist settings on reboot.
int ADL_Display_DisplayContent_Cap ( int   iAdapterIndex,
                                     int   iDisplayIndex,
                                     int * pCapContent
                                   );


/// This function gets the picture setting (Graphics, Photo, Cinema or Gaming) on any HDMI that supports these modes. The application associated with this function is designed such that, even if the ITC display option is toggled 'OFF' (unchecked), this function will still return the last display content mode that was set (or initial value of Graphics) 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in] iAdapterIndex The index of the desired adapter. 
///   [in] iDisplayIndex The index of the desired display. 
///   [in] piContent     The current display content setting; where piContent is one of ADLDisplayContent.iContentType 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK (zero). Otherwise the return value is an ADL error code (non-zero). Result Codes
int ADL_Display_DisplayContent_Get ( int   iAdapterIndex,
                                     int   iDisplayIndex,
                                     int * piContent
                                   );


/// This function sets the picture setting (Graphics, Photo, Cinema or Gaming) on any HDMI that supports these modes. The application associated with this function is designed such that, the ITC display option must be toggled 'ON' (checked) before display content options become available for setting. If the display content is set, but the ITC is toggled 'OFF', the display content options will disable (gray-out), but still show which display content was last 'set'. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in] iAdapterIndex The index of the desired adapter. 
///   [in] iDisplayIndex The index of the desired display. 
///   [in] iContent      The display content desired to be set; where iContent is one of ADLDisplayContent.iContentType 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK (zero). Otherwise the return value is an ADL error code (non-zero). Result Codes
/// 
/// Remarks
///   Call ADL_Flush_Driver_Data() after to persist settings on reboot.
int ADL_Display_DisplayContent_Set ( int iAdapterIndex,
                                     int iDisplayIndex,
                                     int iContent
                                   );


/// Function to retrieve the adapter display information. 
/// 
/// This function retrieves display information for a specified adapter. Display information includes display index, name, type, and display connection status, etc.
/// 
/// This API uses the Caller's Memory Allocation Callback Function to allocate memory pointed by lppInfo. Caller is responsible to de-alocate the memory. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in]  iAdapterIndex The ADL index handle of the desired adapter. 
///   [out] lpNumDisplays The pointer to the number of displays detected. 
///   [out] lppInfo       The pointer to the pointer to the retrieved display information array. Initialize to NULL before calling this API. Refer to the ADLDisplayInfo structure for more information. 
///   [in]  iForceDetect  0: Do not force detection of the adapters in the system; 1 : Force detection 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes
/// 
/// Remarks
///   This API uses the memory allocation callback function provided by the user.
int ADL_Display_DisplayInfo_Get ( int               iAdapterIndex,
                                  int *             lpNumDisplays,
                                  ADLDisplayInfo ** lppInfo,
                                  int               iForceDetect
                                );


/// Function to retrieve the dither state. 
/// 
/// This function retrieves the dither state for a specified display. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in]  iAdapterIndex The ADL index handle of the desired adapter. 
///   [in]  iDisplayIndex The desired display index. It can be retrieved from the ADLDisplayInfo data structure. 
///   [out] lpDitherState The pointer to the value storing the retrieved dither state. See Dithering options 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes
int ADL_Display_DitherState_Get ( int   iAdapterIndex,
                                  int   iDisplayIndex,
                                  int * lpDitherState
                                );


/// Function to set the dither state. 
/// 
/// This function sets the dither state. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in] iAdapterIndex The ADL index handle of the desired adapter. 
///   [in] iDisplayIndex The desired display index. It can be retrieved from the ADLDisplayInfo data structure. 
///   [in] iDitherState  The desired dither state. For the list of valid states see Dithering options 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes
/// 
/// Remarks
///   The final bit depth after dithering must match the input bit depth of the monitor. The function call will fail if it doesn't.
int ADL_Display_DitherState_Set ( int iAdapterIndex,
                                  int iDisplayIndex,
                                  int iDitherState
                                );


/// Function to get the Down-scaling Caps display information. 
/// 
/// This function retrieves the Down-scaling Caps information for a specified adapter and display. 
/// Supported Platforms:
///   \Win7 and above 
/// 
/// Parameters
///   [in]  iAdapterIndex The ADL index handle of the desired adapter. 
///   [in]  iDisplayID    The desired display ID. It can be retrieved from the ADLDisplayInfo data structure. 
///   [out] lpCaps        The pointer to the Down-scaling Caps information retrieved from the driver. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes
int ADL_Display_Downscaling_Caps ( int   iAdapterIndex,
                                   int   iDisplayID,
                                   int * lpCaps
                                 );


/// Function to retrieve the Display Port MST information. 
/// 
/// This function retrieves display port MST information for a specified adapter. Display port MST information includes display indexes, names, bandwidth, identifiers, relative address and display connection, etc.
/// 
/// This API uses the Caller's Memory Allocation Callback Function to allocate memory pointed by lppDisplayDPMstInfo. Caller is responsible to de-alocate the memory. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in]  iAdapterIndex       The ADL index handle of the desired adapter. A value of -1 returns all displays in the system across multiple GPUs. 
///   [out] lpNumDisplays       The pointer to the number of displays detected. 
///   [out] lppDisplayDPMstInfo The pointer to the list of the retrieved display port MST information array. Initialize to NULL before calling this API. Refer to the ADLDisplayDPMSTInfo structure for more information. 
///   [in]  iForceDetect        ADL_FALSE: Do not force detection of the adapters in the system; ADL_TRUE: Force detection 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes
/// 
/// Remarks
///   This API uses the memory allocation callback function provided by the user.
int ADL_Display_DpMstInfo_Get ( int                    iAdapterIndex,
                                int *                  lpNumDisplays,
                                ADLDisplayDPMSTInfo ** lppDisplayDPMstInfo,
                                int                    iForceDetect
                              );


/// Function to get the EDID data. 
/// 
/// This function retrieves the EDID data for a specififed display. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in]     iAdapterIndex The ADL index handle of the desired adapter. 
///   [in]     iDisplayIndex The desired display index. It can be retrieved from the ADLDisplayInfo data structure. 
///   [in,out] lpEDIDData    The pointer to the ADLDisplayEDIDData structure storing the retrieved EDID data. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes
int ADL_Display_EdidData_Get ( int                  iAdapterIndex,
                               int                  iDisplayIndex,
                               ADLDisplayEDIDData * lpEDIDData
                             );


/// Function to get the current FilterSVideo setting from the display. This function retrieves the S-Video Sharpness Control information for a specified display. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in]  iAdapterIndex The index of the desired adapter. 
///   [in]  iDisplayIndex The index of the desired display. 
///   [out] lpCurrent     The current FilterSVideo setting 
///   [out] lpDefault     The default FilterSVideo setting 
///   [out] lpMin         The current FilterSVideo setting 
///   [out] lpMax         The default FilterSVideo setting 
///   [out] lpStep        The current FilterSVideo setting 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK (zero). Otherwise the return value is an ADL error code (non-zero). Result Codes
int ADL_Display_FilterSVideo_Get ( int   iAdapterIndex,
                                   int   iDisplayIndex,
                                   int * lpCurrent,
                                   int * lpDefault,
                                   int * lpMin,
                                   int * lpMax,
                                   int * lpStep
                                 );


/// Function to set the current FilterSVideo setting for the display. This function set the S-Video Sharpness Control setting for a specified display. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in] iAdapterIndex The index of the desired adapter. 
///   [in] iDisplayIndex The index of the desired display. 
///   [in] iCurrent      The new FilterSVideo setting 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK (zero). Otherwise the return value is an ADL error code (non-zero). Result Codes
/// 
/// Remarks
///   Call ADL_Flush_Driver_Data() after to persist settings on reboot.
int ADL_Display_FilterSVideo_Set ( int iAdapterIndex,
                                   int iDisplayIndex,
                                   int iCurrent
                                 );


/// Function to retrieve the available display formats. 
/// 
/// This call retrieves the available display formats 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in]  iAdapterIndex         The ADL index handle of the desired adapter. 
///   [in]  iDisplayIndex         The desired display index. It can be retrieved from the ADLDisplayInfo data structure. 
///   [out] lpSettingsSupported   The pointer to the supported settings. Formats Override Settings 
///   [out] lpSettingsSupportedEx The pointer to the extended supported settings. Formats Override Settings 
///   [out] lpCurSettings         The pointer to the current override settings Formats Override Settings 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes
int ADL_Display_FormatsOverride_Get ( int   iAdapterIndex,
                                      int   iDisplayIndex,
                                      int * lpSettingsSupported,
                                      int * lpSettingsSupportedEx,
                                      int * lpCurSettings
                                    );


/// Function to overide the display formats. 
/// 
/// This call overrides the display formats 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in] iAdapterIndex     The ADL index handle of the desired adapter. 
///   [in] iDisplayIndex     The desired display index. It can be retrieved from the ADLDisplayInfo data structure. 
///   [in] iOverrideSettings The new format settings Formats Override Settings 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes
/// 
/// Remarks
///   Call ADL_Flush_Driver_Data() after to persist settings on reboot.
int ADL_Display_FormatsOverride_Set ( int iAdapterIndex,
                                      int iDisplayIndex,
                                      int iOverrideSettings
                                    );


/// Function to retrieve per display FreeSync capability information. 
/// 
/// This function retrieves the FreeSync capabilities of a display. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in]  iAdapterIndex  The ADL index handle of the desired adapter. 
///   [in]  iDisplayIndex  The desired display index. It can be retrieved from the ADLDisplayInfo data structure. 
///   [out] lpFreeSyncCaps The pointer to the ADLFreeSyncCap structure storing the retrieved FreeSync capabilities for the requested display index. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes
int ADL_Display_FreeSync_Cap ( int              iAdapterIndex,
                               int              iDisplayIndex,
                               ADLFreeSyncCap * lpFreeSyncCaps
                             );


/// Function to get the current state and capability of the FreeSync feature. 
/// 
/// 
/// 
/// This function gets the current and default FreeSync settings for a specified display along with the supported FreeSync refresh rate range. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in]  iAdapterIndex             The ADL index handle of the desired adapter. 
///   [in]  iDisplayIndex             The desired display index. It can be retrieved from the ADLDisplayInfo data structure. 
///   [out] lpCurrent                 The pointer to the FreeSync setting currently applied. It is a bit vector. Define_freesync_usecase 
///   [out] lpDefault                 The pointer to the default FreeSync setting. It is a bit vector. Define_freesync_usecase 
///   [out] lpMinRefreshRateInMicroHz The pointer to the minimum refresh rate in the range supported by FreeSync in microhertz. 
///   [out] lpMaxRefreshRateInMicroHz The pointer to the maximum refresh rate in the range supported by FreeSync in microhertz. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK, ADL_ERR_NULL_POINTER if any of the inputs is NULL, Otherwise the return value is an ADL_ERR. Result Codes 
/// 
/// Remarks
///   Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call ADL2_Main_Control_Create first to obtain ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using ADL2_Main_Control_Destroy.
int ADL_Display_FreeSyncState_Get ( int   iAdapterIndex,
                                    int   iDisplayIndex,
                                    int * lpCurrent,
                                    int * lpDefault,
                                    int * lpMinRefreshRateInMicroHz,
                                    int * lpMaxRefreshRateInMicroHz
                                  );


/// Function to set the current state of the FreeSync feature. 
/// 
/// 
/// 
/// This function sets the FreeSync feature enable state for a specified display. There is a second input parameter that may be used to request a specific refresh rate to be applied. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in] iAdapterIndex         The ADL index handle of the desired adapter. 
///   [in] iDisplayIndex         The desired display index. It can be retrieved from the ADLDisplayInfo data structure. 
///   [in] iSetting              The desired FreeSync setting to be applied for the specified display. Define_freesync_usecase 
///   [in] iRefreshRateInMicroHz If non-zero value is specified, this indicates a request to set a specific refresh rate in microhertz. Otherwise, driver default will decide FreeSync refresh rate dynamically. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes
/// 
/// Remarks
///   Call ADL_Flush_Driver_Data() after to persist settings on reboot.
int ADL_Display_FreeSyncState_Set ( int iAdapterIndex,
                                    int iDisplayIndex,
                                    int iSetting,
                                    int iRefreshRateInMicroHz
                                  );


/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in]  iAdapterIndex The index of the desired adapter. 
///   [in]  iDisplayIndex The index of the desired display. 
///   [in]  gamut         The gamut reference - whether it is related to graphics or video, source or destination 
///   [out] ADLGamutInfo  driver supplies the mask of supported gamut spaces and white points, driver supports this feature from NI ASIC. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK (zero). Otherwise the return value is an ADL error code (non-zero). Result Codes
int ADL_Display_Gamut_Caps ( int               iAdapterIndex,
                             int               iDisplayIndex,
                             ADLGamutReference gamut,
                             ADLGamutInfo *    lpCap
                           );


/// Function to get the current ADLGamutData setting for the display. This function get the ADLGamutData setting for a specified display. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in]  iAdapterIndex The index of the desired adapter. 
///   [in]  iDisplayIndex The index of the desired display. 
///   [in]  gamut         . The gamut reference - whether it is related to graphics or video, source or destination 
///   [out] ADLGamutData  driver supplies the currently used gamut, driver supports this feature from NI ASIC. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK (zero). Otherwise the return value is an ADL error code (non-zero). Result Codes
int ADL_Display_Gamut_Get ( int               iAdapterIndex,
                            int               iDisplayIndex,
                            ADLGamutReference gamut,
                            ADLGamutData *    lpSource
                          );


/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in] iAdapterIndex The index of the desired adapter. 
///   [in] iDisplayIndex The index of the desired display. 
///   [in] gamut         The gamut reference - whether it is related to graphics or video, source or destination 
///   [in] ADLGamutData  to be set, the method sets the new gamut or saves the requested gamut if the current destination if gamut from EDID. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK (zero). Otherwise the return value is an ADL error code (non-zero). Result Codes
int ADL_Display_Gamut_Set ( int                  iAdapterIndex,
                            int                  iDisplayIndex,
                            ADLGamutReference    gamut,
                            const ADLGamutData * lpSource
                          );


/// Function to retrieve the display image expansion setting. 
/// 
/// This function retrieves the current, default, and the feature supported values of the image expansion setting. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in]  iAdapterIndex The ADL index handle of the desired adapter. 
///   [in]  iDisplayIndex The desired display index. It can be retrieved from the ADLDisplayInfo data structure. 
///   [out] lpSupport     The pointer to the value indicating whether the feature is supported by the driver. 1: feature is supported; 0: feature is not supported. 
///   [out] lpCurrent     The pointer to the current setting of display image expansion. Its alternative value is 1 or 0. 
///   [out] lpDefault     The pointer to the default setting of display image expansion. Its alternative value is 1 or 0. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes
int ADL_Display_ImageExpansion_Get ( int   iAdapterIndex,
                                     int   iDisplayIndex,
                                     int * lpSupport,
                                     int * lpCurrent,
                                     int * lpDefault
                                   );


/// Function to set the display image expansion setting. 
/// 
/// This function sets the current value of display image expansion setting. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in] iAdapterIndex The ADL index handle of the desired adapter. 
///   [in] iDisplayIndex The desired display index. It can be retrieved from the ADLDisplayInfo data structure. 
///   [in] iCurrent      The desired setting of display image expansion. Possible values are 1 or 0. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes
/// 
/// Remarks
///   Call ADL_Flush_Driver_Data() after to persist settings on reboot.
int ADL_Display_ImageExpansion_Set ( int iAdapterIndex,
                                     int iDisplayIndex,
                                     int iCurrent
                                   );


/// This function retrieves the maximum horizontal and vertical resolution as well as the maximum refresh rate for a specified display and adapter. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in]  iAdapterIndex The ADL index handle of the graphics adapter corresponding to the desired display. 
///   [in]  iDisplayIndex The ADL index handle of the desired display. 
///   [out] lpMaxHRes     The pointer to the maximum horizontal resolution for the specified display. 
///   [out] lpMaxVRes     The pointer to the maximum vertical resolution for the specified display. 
///   [out] lpMaxRefresh  The pointer to the maximum refresh rate for the specfied display. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes
int ADL_Display_Limits_Get ( int   iAdapterIndex,
                             int   iDisplayIndex,
                             int * lpMaxHRes,
                             int * lpMaxVRes,
                             int * lpMaxRefresh
                           );


/// Function to delete display mode timing override information. 
/// 
/// This function delete display mode timing override information for a specified display. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in] iAdapterIndex The ADL index handle of the desired adapter. 
///   [in] displayID     The desired display index. It can be retrieved from the ADLDisplayInfo data structure. 
///   [in] lpModeIn      The pointer to the ADLDisplayMode structure storing the desired display mode. 
///   [in] iForceUpdate  The value which forces the update of the timing override information. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes
int ADL_Display_ModeTimingOverride_Delete ( int                iAdapterIndex,
                                            ADLDisplayID       displayID,
                                            ADLDisplayModeX2 * lpMode,
                                            int                iForceUpdate
                                          );


/// Function to retrieve display mode timing override information. 
/// 
/// This function retrieves display mode timing override information for a specified display. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in]  iAdapterIndex The ADL index handle of the desired adapter. 
///   [in]  iDisplayIndex The desired display index. It can be retrieved from the ADLDisplayInfo data structure. 
///   [in]  lpModeIn      The pointer to the ADLDisplayMode structure storing the desired display mode. 
///   [out] lpModeInfoOut The pointer to the ADLDisplayModeInfo structure storing the retrieved display mode information. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes 
/// 
/// Deprecated:
///   This API has been deprecated. It has been replaced with API ADL_Display_ModeTimingOverrideX2_Get
int ADL_Display_ModeTimingOverride_Get ( int                  iAdapterIndex,
                                         int                  iDisplayIndex,
                                         ADLDisplayMode *     lpModeIn,
                                         ADLDisplayModeInfo * lpModeInfoOut
                                       );


/// Function to set display mode timing override information. 
/// 
/// This function sets display mode timing override information for a specified display. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in] iAdapterIndex The ADL index handle of the desired adapter. 
///   [in] iDisplayIndex The desired display index. It can be retrieved from the ADLDisplayInfo data structure. 
///   [in] lpMode        The pointer to the ADLDisplayModeInfo structure which sets the display mode timing override information. 
///   [in] iForceUpdate  The value which forces the update of the timing override information. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes
/// 
/// Remarks
///   Call ADL_Flush_Driver_Data() after to persist settings on reboot.
int ADL_Display_ModeTimingOverride_Set ( int                  iAdapterIndex,
                                         int                  iDisplayIndex,
                                         ADLDisplayModeInfo * lpMode,
                                         int                  iForceUpdate
                                       );


/// Function to retrieve display mode timing override information. 
/// 
/// This function retrieves display mode timing override information for a specified display. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in]  iAdapterIndex The ADL index handle of the desired adapter. 
///   [in]  iDisplayIndex The desired display index. It can be retrieved from the ADLDisplayInfo data structure. 
///   [in]  lpModeIn      The pointer to the structure storing the desired display mode. 
///   [out] lpModeInfoOut The pointer to the structure storing the retrieved display mode information. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes 
/// 
/// Deprecated:
///   This API has been deprecated.
int ADL_Display_ModeTimingOverrideInfo_Get ( int                      iAdapterIndex,
                                             int                      iDisplayIndex,
                                             ADL_DL_DISPLAY_MODE *    lpModeIn,
                                             ADL_DL_DISPLAYMODEINFO * lpModeInfoOut
                                           );


/// Function to get the display mode timing override list. 
/// 
/// This function retrieves display mode timing override list. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in]  iAdapterIndex      The ADL index handle of the desired adapter. 
///   [in]  iDisplayIndex      The desired display index. It can be retrieved from the ADLDisplayInfo data structure. 
///   [in]  iMaxNumOfOverrides The maximum number of elements in the array pointed by lpModeInfoList. The number specified must be > 0. 
///   [out] lpModeInfoList     The pointer to the retrieved ADLDisplayModeInfo structure. This pointer must be allocated by the user. 
///   [out] lpNumOfOverrides   The pointer to the actual number of the retrieved overridden modes. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes 
/// 
/// Deprecated:
///   This API has been deprecated. It has been replaced with API ADL_Display_ModeTimingOverrideListX2_Get
int ADL_Display_ModeTimingOverrideList_Get ( int                  iAdapterIndex,
                                             int                  iDisplayIndex,
                                             int                  iMaxNumOfOverrides,
                                             ADLDisplayModeInfo * lpModeInfoList,
                                             int *                lpNumOfOverrides
                                           );


/// Function to get the display mode timing override list. 
/// 
/// This function retrieves display mode timing override list. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in]  iAdapterIndex  The ADL index handle of the desired adapter. 
///   [in]  displayID      The desired display index. It can be retrieved from the ADLDisplayInfo data structure. 
///   [out] lpNumOfModes   The pointer to the actual number of the retrieved overridden modes. 
///   [out] lpModeInfoList The pointer to the retrieved ADLDisplayModeInfo structure. This pointer must be allocated by the user. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes
int ADL_Display_ModeTimingOverrideListX2_Get ( int                   iAdapterIndex,
                                               ADLDisplayID          displayID,
                                               int *                 lpNumOfModes,
                                               ADLDisplayModeInfo ** lpModeInfoList
                                             );


/// Function to retrieve display mode timing override information. 
/// 
/// This function retrieves display mode timing override information for a specified display. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in]  iAdapterIndex The ADL index handle of the desired adapter. 
///   [in]  displayID     The desired display index. It can be retrieved from the ADLDisplayInfo data structure. 
///   [in]  lpModeIn      The pointer to the ADLDisplayMode structure storing the desired display mode. 
///   [out] lpModeInfoOut The pointer to the ADLDisplayModeInfo structure storing the retrieved display mode information. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes
int ADL_Display_ModeTimingOverrideX2_Get ( int                  iAdapterIndex,
                                           ADLDisplayID         displayID,
                                           ADLDisplayModeX2 *   lpModeIn,
                                           ADLDisplayModeInfo * lpModeInfoOut
                                         );


/// Function to retrieve the information about MultiVPU capabilities. 
/// 
/// This function retrieves the information about MultiVPU capabilities. 
/// Supported Platforms:
///   Windows 7, 10 and above; 32bit and 64bit 
/// 
/// Parameters
///   [in]     iAdapterIndex The ADL index handle of the desired adapter. 
///   [in,out] lpMvpuCaps    The structure storing the retrieved information about MultiVPU capabilities. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes
/// 
/// Remarks
///   The maximum number of adapters is ADL_DL_MAX_MVPU_ADAPTERS
int ADL_Display_MVPUCaps_Get ( int           iAdapterIndex,
                               ADLMVPUCaps * lpMvpuCaps
                             );


/// Function to retrieve information about MultiVPU status. 
/// 
/// This function retrieves information about MultiVPU status. 
/// Supported Platforms:
///   Windows 7, 10 and above; 32bit and 64bit 
/// 
/// Parameters
///   [in]     iAdapterIndex The ADL index handle of the desired adapter. 
///   [in,out] lpMvpuStatus  The structure storing the retrieved information about MultiVPU status. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes
int ADL_Display_MVPUStatus_Get ( int             iAdapterIndex,
                                 ADLMVPUStatus * lpMvpuStatus
                               );


/// Function to retrieve the number of displays supported by an adapter. 
/// 
/// This function retrieves the number of displays that is supported by a specified adapter. Supported displays include devices that are connected and disconnected together with those enabled and disabled devices. 
/// 
/// 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in]  iAdapterIndex The ADL index handle of the desired adapter. 
///   [out] lpNumDisplays The pointer to the number of displays supported by the adapter. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes
int ADL_Display_NumberOfDisplays_Get ( int   iAdapterIndex,
                                       int * lpNumDisplays
                                     );


/// Function to set the OD clock configuration. 
/// 
/// This function sets the OD clock configuration. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in] iAdapterIndex   The ADL index handle of the desired adapter. 
///   [in] lpOdClockConfig The pointer to the structure used to set the OD clock configuration. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes
/// 
/// Remarks
///   Call ADL_Flush_Driver_Data() after to persist settings on reboot.
int ADL_Display_ODClockConfig_Set ( int                       iAdapterIndex,
                                    ADLAdapterODClockConfig * lpOdClockConfig
                                  );


/// Function to retrieve the OD clock information. 
/// 
/// This function retrieves the OD clock information. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in]  iAdapterIndex The ADL index handle of the desired adapter. 
///   [out] lpOdClockInfo The pointer to the structure storing the retrieved clock information. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes
int ADL_Display_ODClockInfo_Get ( int                     iAdapterIndex,
                                  ADLAdapterODClockInfo * lpOdClockInfo
                                );


/// Function to retrieve the current value of gamma for each controller. 
/// 
/// This function retrieves the Overscan value for a specified display. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in]  iAdapterIndex The ADL index handle of the desired adapter. 
///   [in]  iDisplayIndex The desired display index. It can be retrieved from the ADLDisplayInfo data structure. 
///   [out] lpCurrent     The pointer to the current Overscan value. 
///   [out] lpDefualt     The pointer to the default Overscan value. 
///   [out] lpMin         The pointer to the minimum Overscan value. 
///   [out] lpMax         The pointer to the maximum Overscan value. 
///   [out] lpStep        The pointer to the increment of the Overscan value. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code.
int ADL_Display_Overscan_Get ( int   iAdapterIndex,
                               int   iDisplayIndex,
                               int * lpCurrent,
                               int * lpDefualt,
                               int * lpMin,
                               int * lpMax,
                               int * lpStep
                             );


/// Function to set the current value of gamma for each controller. 
/// 
/// This function sets the Overscan value for a specified display. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in] iAdapterIndex The ADL index handle of the desired adapter. 
///   [in] iDisplayIndex The desired display index. It can be retrieved from the ADLDisplayInfo data structure. 
///   [in] iCurrent      The desired Overscan value. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes
/// 
/// Remarks
///   Call ADL_Flush_Driver_Data() after to persist settings on reboot.
int ADL_Display_Overscan_Set ( int iAdapterIndex,
                               int iDisplayIndex,
                               int iCurrent
                             );


/// Function to retrieve the current display pixel format. HDMI only. 
/// 
/// This function retrieves the current display pixel format. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in]  iAdapterIndex The ADL index handle of the desired adapter. 
///   [in]  iDisplayIndex The desired display index. It can be retrieved from the ADLDisplayInfo data structure. 
///   [out] lpPixelFormat The pointer to the pixel format. Pixel Formats values 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes
int ADL_Display_PixelFormat_Get ( int   iAdapterIndex,
                                  int   iDisplayIndex,
                                  int * lpPixelFormat
                                );


/// Function to set the current display pixel format. HDMI only. 
/// 
/// This function sets the current display pixel format. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in] iAdapterIndex The ADL index handle of the desired adapter. 
///   [in] iDisplayIndex The desired display index. It can be retrieved from the ADLDisplayInfo data structure. 
///   [in] iPixelFormat  The desired pixel format. Pixel Formats values 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes
/// 
/// Remarks
///   Call ADL_Flush_Driver_Data() after to persist settings on reboot.
int ADL_Display_PixelFormat_Set ( int iAdapterIndex,
                                  int iDisplayIndex,
                                  int iPixelFormat
                                );


/// Function to get Device Display Position. 
/// 
/// This function retrieves the display position parameters for a specified adapter and display. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in]  iAdapterIndex The ADL index handle of the desired adapter. 
///   [in]  iDisplayIndex The desired display index. It can be retrieved from the ADLDisplayInfo data structure. 
///   [out] lpX           The pointer to the current X coordinate display position. 
///   [out] lpY           The pointer to the current Y coordinate display position. 
///   [out] lpXDefault    The pointer to the default X coordinate display position. 
///   [out] lpYDefault    The pointer to the default Y coordinate display position. 
///   [out] lpMinX        The pointer to the minimum X display size. 
///   [out] lpMinY        The pointer to the minimum Y display size. 
///   [out] lpMaxX        The pointer to the maximum X display size. 
///   [out] lpMaxY        The pointer to the maximum Y display size. 
///   [out] lpStepX       The pointer to the step size along the X axis. 
///   [out] lpStepY       The pointer to the step size along the Y axis. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes
int ADL_Display_Position_Get ( int   iAdapterIndex,
                               int   iDisplayIndex,
                               int * lpX,
                               int * lpY,
                               int * lpXDefault,
                               int * lpYDefault,
                               int * lpMinX,
                               int * lpMinY,
                               int * lpMaxX,
                               int * lpMaxY,
                               int * lpStepX,
                               int * lpStepY
                             );


/// Function to set the Device Display Position. 
/// 
/// This function sets the display X and Y position values for a specified adapter and display. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in] iAdapterIndex The ADL index handle of the desired adapter. 
///   [in] iDisplayIndex The desired display index. It can be retrieved from the ADLDisplayInfo data structure. 
///   [in] iX            The desired X coordinate position. 
///   [in] iY            The desired Y coordinate position. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes
/// 
/// Remarks
///   Call ADL_Flush_Driver_Data() after to persist settings on reboot.
int ADL_Display_Position_Set ( int iAdapterIndex,
                               int iDisplayIndex,
                               int iX,
                               int iY
                             );


/// Function to retrieve the display perserved aspect ratio of an adapter. 
/// 
/// This function retrieves the current, default, and the feature supported values of the display preserved aspect ratio. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in]  iAdapterIndex The ADL index handle of the desired adapter. 
///   [in]  iDisplayIndex The desired display index. It can be retrieved from the ADLDisplayInfo data structure. 
///   [out] lpSupport     The pointer to the value indicating whether the feature is supported by the driver. 1: feature is supported; 0: feature is not supported. 
///   [out] lpCurrent     The pointer to the current setting of display preserved aspect ratio. Its alternative value is 1 or 0. 
///   [out] lpDefault     The pointer to the default setting of display preserved aspect ratio. Its alternative value is 1 or 0. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes
int ADL_Display_PreservedAspectRatio_Get ( int   iAdapterIndex,
                                           int   iDisplayIndex,
                                           int * lpSupport,
                                           int * lpCurrent,
                                           int * lpDefault
                                         );


/// Function to set the display preserved aspect ratio. 
/// 
/// This function sets the current value of display preserved aspect ratio. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in] iAdapterIndex The ADL index handle of the desired adapter. 
///   [in] iDisplayIndex The desired display index. It can be retrieved from the ADLDisplayInfo data structure. 
///   [in] iCurrent      The desired display preserved aspect ratio setting. Possible values are 1 or 0. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes
/// 
/// Remarks
///   Call ADL_Flush_Driver_Data() after to persist settings on reboot.
int ADL_Display_PreservedAspectRatio_Set ( int iAdapterIndex,
                                           int iDisplayIndex,
                                           int iCurrent
                                         );


/// Function to get the current display property value. 
/// 
/// This function retrieves the current display property value for a specified display. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in]  iAdapterIndex     The ADL index handle of the desired adapter. 
///   [in]  iDisplayIndex     The desired display index. It can be retrieved from the ADLDisplayInfo data structure. 
///   [out] lpDisplayProperty The pointer to the ADLDisplayProperty structure storing the retrieved display property value. lpDisplayProperty->iExpansionMode contains the Expansion Mode value. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes
int ADL_Display_Property_Get ( int                  iAdapterIndex,
                               int                  iDisplayIndex,
                               ADLDisplayProperty * lpDisplayProperty
                             );


/// Function to set current display property value. 
/// 
/// This function sets current display property value for a specified display. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in] iAdapterIndex     The ADL index handle of the desired adapter. 
///   [in] iDisplayIndex     The desired display index. It can be retrieved from the ADLDisplayInfo data structure. 
///   [in] lpDisplayProperty The pointer to the desired ADLDisplayProperty structure. Set lpDisplayProperty->iExpansionMode with an Expansion Mode value. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes
/// 
/// Remarks
///   Call ADL_Flush_Driver_Data() after to persist settings on reboot.
int ADL_Display_Property_Set ( int                  iAdapterIndex,
                               int                  iDisplayIndex,
                               ADLDisplayProperty * lpDisplayProperty
                             );


/// Function to retrieve the reduced blanking setting. 
/// 
/// This function retrieves the current reduced blanking setting. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in]  iAdapterIndex            The ADL index handle of the desired adapter. 
///   [in]  iDisplayIndex            The desired display index. It can be retrieved from the ADLDisplayInfo data structure. 
///   [out] lpReducedBlankingCurrent The pointer to the current reduced blanking setting. 
///   [out] lpReducedBlankingDefault The pointer to the retrieved default setting. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes
int ADL_Display_ReducedBlanking_Get ( int   iAdapterIndex,
                                      int   iDisplayIndex,
                                      int * lpReducedBlankingCurrent,
                                      int * lpReducedBlankingDefault
                                    );


/// Function to set the reduced blanking setting. 
/// 
/// This function sets the current reduced blanking setting to a specified setting. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in] iAdapterIndex    The ADL index handle of the desired adapter. 
///   [in] iDisplayIndex    The desired display index. It can be retrieved from the ADLDisplayInfo data structure. 
///   [in] iReducedBlanking The desired reduced blanking setting. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes
/// 
/// Remarks
///   Call ADL_Flush_Driver_Data() after to persist settings on reboot.
int ADL_Display_ReducedBlanking_Set ( int iAdapterIndex,
                                      int iDisplayIndex,
                                      int iReducedBlanking
                                    );


/// Function to get the Device Display Size. 
/// 
/// This function retrieves the display position parameters. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in]  iAdapterIndex   The ADL index handle of the desired adapter. 
///   [in]  iDisplayIndex   The desired display index. It can be retrieved from the ADLDisplayInfo data structure. 
///   [out] lpWidth         The pointer to the current display width. 
///   [out] lpHeight        The pointer to the current display height. 
///   [out] lpDefaultWidth  The pointer to the default display width. 
///   [out] lpDefaultHeight The pointer to the default display height. 
///   [out] lpMinWidth      The pointer to the minimum display width. 
///   [out] lpMinHeight     The pointer to the minimum display height. 
///   [out] lpMaxWidth      The pointer to the maximum display width. 
///   [out] lpMaxHeight     The pointer to the maximum display height. 
///   [out] lpStepWidth     The pointer to the step width. 
///   [out] lpStepHeight    The pointer to the step height. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes
int ADL_Display_Size_Get ( int   iAdapterIndex,
                           int   iDisplayIndex,
                           int * lpWidth,
                           int * lpHeight,
                           int * lpDefaultWidth,
                           int * lpDefaultHeight,
                           int * lpMinWidth,
                           int * lpMinHeight,
                           int * lpMaxWidth,
                           int * lpMaxHeight,
                           int * lpStepWidth,
                           int * lpStepHeight
                         );


/// Function to set the Device Display Size. 
/// 
/// This function sets the display width and height values. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in] iAdapterIndex The ADL index handle of the desired adapter. 
///   [in] iDisplayIndex The desired display index. It can be retrieved from the ADLDisplayInfo data structure. 
///   [in] iWidth        The desired width of the display. 
///   [in] iHeight       The desired height of the display. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes
/// 
/// Remarks
///   Call ADL_Flush_Driver_Data() after to persist settings on reboot.
int ADL_Display_Size_Set ( int iAdapterIndex,
                           int iDisplayIndex,
                           int iWidth,
                           int iHeight
                         );


/// Function to retrieve the supported color depth. HDMI and DPonly. 
/// 
/// This function retrieves the current display on given adpaters supported color depths –When supported Color depth is one format only, no need expose the User interface. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in]  iAdapterIndex the ADL index handle of the desired adapter per physical GPU. 
///   [in]  iDisplayIndex The desired display index. It can be retrieved from the ADLDisplayInfo data structure. 
///   [out] lpColorDepth  The pointer to the bit vector of all display supported color depths. define_color_depth_bits 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes
int ADL_Display_SupportedColorDepth_Get ( int   iAdapterIndex,
                                          int   iDisplayIndex,
                                          int * lpColorDepth
                                        );


/// Function to retrieve the supported pixel format. HDMI only. 
/// 
/// This function retrieves the supported pixel format. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in]  iAdapterIndex The ADL index handle of the desired adapter. 
///   [in]  iDisplayIndex The desired display index. It can be retrieved from the ADLDisplayInfo data structure. 
///   [out] lpPixelFormat The pointer to the supported pixel format. Pixel Formats values 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes
int ADL_Display_SupportedPixelFormat_Get ( int   iAdapterIndex,
                                           int   iDisplayIndex,
                                           int * lpPixelFormat
                                         );


/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes
int ADL_Display_SwitchingCapability_Get ( int   iAdapterIndex,
                                          int * lpResult
                                        );


/// Function to retrieve current display mode timing override information. 
/// 
/// This function retrieves current display mode timing override information for a specified display. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in]  iAdapterIndex The ADL index handle of the desired adapter. 
///   [in]  displayID     The desired display index. It can be retrieved from the ADLDisplayInfo data structure. 
///   [out] lpModeInfoOut The pointer to the ADLDisplayModeInfo structure storing the retrieved display mode information. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes
int ADL_Display_TargetTiming_Get ( int                  iAdapterIndex,
                                   ADLDisplayID         displayID,
                                   ADLDisplayModeInfo * lpModeInfoOut
                                 );


/// Function to retrieve the TV Caps display information. 
/// 
/// This function retrieves the display adjustment information. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in]  iAdapterIndex The ADL index handle of the desired adapter. 
///   [in]  iDisplayIndex The desired display index. It can be retrieved from the ADLDisplayInfo data structure. 
///   [out] lpcaps        The pointer to the TV Caps information retrieved from the driver. TV Capabilities and Standards 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes 
/// 
/// Deprecated:
///   Dropping support for component, composite, and S-Video connectors.
int ADL_Display_TVCaps_Get ( int   iAdapterIndex,
                             int   iDisplayIndex,
                             int * lpcaps
                           );


/// Function to get the current UnderScan Auto setting from the display. This function retrieves the UnderScan Auto information for a specified display. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in]  iAdapterIndex The index of the desired adapter. 
///   [in]  iDisplayIndex The index of the desired display. 
///   [out] lpCurrent     The current underscan auto setting 
///   [out] lpDefault     The default underscan auto setting 
///   [out] lpMin         The current underscan auto setting 
///   [out] lpMax         The default underscan auto setting 
///   [out] lpStep        The current underscan auto setting 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK (zero). Otherwise the return value is an ADL error code (non-zero). Result Codes
int ADL_Display_UnderScan_Auto_Get ( int   iAdapterIndex,
                                     int   iDisplayIndex,
                                     int * lpCurrent,
                                     int * lpDefault,
                                     int * lpMin,
                                     int * lpMax,
                                     int * lpStep
                                   );


/// Function to set the current UnderScan Auto setting for the display. This function set the UnderScan Auto setting for a specified display. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in] iAdapterIndex The index of the desired adapter. 
///   [in] iDisplayIndex The index of the desired display. 
///   [in] iCurrent      The new underscan auto setting 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK (zero). Otherwise the return value is an ADL error code (non-zero). Result Codes
/// 
/// Remarks
///   Call ADL_Flush_Driver_Data() after to persist settings on reboot.
int ADL_Display_UnderScan_Auto_Set ( int iAdapterIndex,
                                     int iDisplayIndex,
                                     int iCurrent
                                   );


/// Function to retrieve the detailed information for underscan. 
/// 
/// This function retrieves the detailed information for underscan. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in]  iAdapterIndex The ADL index handle of the desired adapter. 
///   [in]  iDisplayIndex The desired display index. It can be retrieved from the ADLDisplayInfo data structure. 
///   [out] lpCurrent     The pointer to the current underscan value. 
///   [out] lpDefault     The pointer to the default underscan value. 
///   [out] lpMin         The pointer to the minimum underscan value. 
///   [out] lpMax         The pointer to the maximum underscan value. 
///   [out] lpStep        The pointer to the increment of the underscan setting. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes
int ADL_Display_Underscan_Get ( int   iAdapterIndex,
                                int   iDisplayIndex,
                                int * lpCurrent,
                                int * lpDefault,
                                int * lpMin,
                                int * lpMax,
                                int * lpStep
                              );


/// Function to set the current value of underscan. 
/// 
/// 
/// 
/// This function sets the display underscan for a specified adapter, display. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in] iAdapterIndex The ADL index handle of the desired adapter. 
///   [in] iDisplayIndex The desired display index. It can be retrieved from the ADLDisplayInfo data structure. 
///   [in] iCurrent      The desired underscan value. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes
/// 
/// Remarks
///   Call ADL_Flush_Driver_Data() after to persist settings on reboot.
int ADL_Display_Underscan_Set ( int iAdapterIndex,
                                int iDisplayIndex,
                                int iCurrent
                              );


/// Function to check if the selected adapter supports the view port control. 
/// 
/// This function used to check if the selected adapter supports the view port control. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in]  iAdapterIndex The ADL index handle of the desired adapter. 
///   [out] lpSupported   is if this adapter supports the view port control. ADL_TRUE: the view port control are supported; otherwise: not supported. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes
int ADL_Display_ViewPort_Cap ( int   iAdapterIndex,
                               int * lpSupported
                             );


/// Function to get the view position, view size or view pan lock of a selected display. 
/// 
/// This function used to get the view position, view size or view pan lock of a selected display. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in]  iAdapterIndex    The ADL index handle of the desired adapter. 
///   [in]  iDisplayIndex    The desired display index. It can be retrieved from the ADLDisplayInfo data structure. 
///   [out] lpControllerMode The pointer to the ADLControllerMode structure. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes
int ADL_Display_ViewPort_Get ( int                 iAdapterIndex,
                               int                 iDisplayIndex,
                               ADLControllerMode * lpControllerMode
                             );


/// Function to change the view position, view size or view pan lock of a selected display. 
/// 
/// This function used to change the view position, view size or view pan lock of a selected display. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in] iAdapterIndex     The ADL index handle of the desired adapter. 
///   [in] iDisplayIndex     The desired display index. It can be retrieved from the ADLDisplayInfo data structure. 
///   [in] lpControllerMode. The pointer to the ADLControllerMode structure. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes
int ADL_Display_ViewPort_Set ( int                 iAdapterIndex,
                               int                 iDisplayIndex,
                               ADLControllerMode * lpControllerMode
                             );


/// Function to write and read I2C. 
/// 
/// This function writes and reads I2C. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in]     iAdapterIndex The ADL index handle of the desired adapter. 
///   [in,out] plI2C         A pointer to the ADLI2C structure. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes
int ADL_Display_WriteAndReadI2C ( int      iAdapterIndex,
                                  ADLI2C * plI2C
                                );


/// This function writes and reads I2C. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in]     iAdapterIndex The ADL index handle of the desired adapter. 
///   [in,out] plI2C         A pointer to the ADLI2CLargePayload structure. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes
int ADL_Display_WriteAndReadI2CLargePayload ( int                  iAdapterIndex,
                                              ADLI2CLargePayload * plI2C
                                            );


/// Function to retrieve the I2C API revision. 
/// 
/// This function retrieves the I2C API revision. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in]  iAdapterIndex The ADL index handle of the desired adapter. 
///   [out] lpMajor       The pointer to the major version. 
///   [out] lpMinor       The pointer to the minor version. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes
int ADL_Display_WriteAndReadI2CRev_Get ( int   iAdapterIndex,
                                         int * lpMajor,
                                         int * lpMinor
                                       );


/// Function to retrieve the TV standard. 
/// 
/// This function retrieves the TV standard for a specified display. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in]  iAdapterIndex        The ADL index handle of the desired adapter. 
///   [in]  iDisplayIndex        The desired display index. It can be retrieved from the ADLDisplayInfo data structure. 
///   [out] lpCurrent            The pointer to the current TV standard. TV Capabilities and Standards 
///   [out] lpDefault            The pointer to the default TV standard. TV Capabilities and Standards 
///   [out] lpSupportedStandards The pointer to the bit vector of the support video standard. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes 
/// 
/// Deprecated:
///   Dropping support for component, composite, and S-Video connectors.
int ADL_TV_Standard_Get ( int   iAdapterIndex,
                          int   iDisplayIndex,
                          int * lpCurrent,
                          int * lpDefault,
                          int * lpSupportedStandards
                        );


/// Function to set the TV standard. 
/// 
/// This function sets the TV Standard for a specified display. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in] iAdapterIndex The ADL index handle of the desired adapter. 
///   [in] iDisplayIndex The desired display index. It can be retrieved from the ADLDisplayInfo data structure. 
///   [in] iCurrent      The desired TV Standard. TV Capabilities and Standards 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes
/// 
/// Remarks
///   Call ADL_Flush_Driver_Data() after to persist settings on reboot. 
/// Deprecated:
///   Dropping support for component, composite, and S-Video connectors.
int ADL_TV_Standard_Set ( int iAdapterIndex,
                          int iDisplayIndex,
                          int iCurrent
                        );


#endif /* ADL_HEADER_DISPLAY_H_ */
