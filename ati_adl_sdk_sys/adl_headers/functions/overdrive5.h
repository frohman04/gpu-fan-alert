#ifndef ADL_HEADER_OVERDRIVE5_H_
#define ADL_HEADER_OVERDRIVE5_H_

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

/// Function to retrieve current power management-related activity. 
/// 
/// This function retrieves current power management-related activity for a specified adapter. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in]     context       Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in]     iAdapterIndex The ADL index handle of the desired adapter. 
///   [in,out] lpActivity    The pointer to the ADLPMActivity structure storing the retrieved power management activity information. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes 
/// 
/// Remarks
///   Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call ADL2_Main_Control_Create first to obtain ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using ADL2_Main_Control_Destroy.
int ADL2_Overdrive5_CurrentActivity_Get ( ADL_CONTEXT_HANDLE context,
                                          int                iAdapterIndex,
                                          ADLPMActivity *    lpActivity
                                        );


/// Function to retrieve the fan speed reported by the thermal controller. 
/// 
/// This function retrieves the reported fan speed from a specified thermal controller. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in]     context                 Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in]     iAdapterIndex           The ADL index handle of the desired adapter. 
///   [in]     iThermalControllerIndex The ADL index handle of the desired thermal controller. Set to 0. 
///   [in,out] lpFanSpeedValue         The pointer to the ADLFanSpeedValue structure storing the retrieved fan speed. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes 
/// 
/// Remarks
///   Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call ADL2_Main_Control_Create first to obtain ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using ADL2_Main_Control_Destroy.
int ADL2_Overdrive5_FanSpeed_Get ( ADL_CONTEXT_HANDLE context,
                                   int                iAdapterIndex,
                                   int                iThermalControllerIndex,
                                   ADLFanSpeedValue * lpFanSpeedValue
                                 );


/// Function to set the fan speed. 
/// 
/// This function sets the fan speed for a specified adapter and thermal controller. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in] context                 Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in] iAdapterIndex           The ADL index handle of the desired adapter. 
///   [in] iThermalControllerIndex The ADL index handle of the desired thermal controller. Set to 0. 
///   [in] lpFanSpeedValue         The pointer to the ADLFanSpeedValue structure storing the desired fan speed. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes 
/// 
/// Remarks
///   Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call ADL2_Main_Control_Create first to obtain ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using ADL2_Main_Control_Destroy.
int ADL2_Overdrive5_FanSpeed_Set ( ADL_CONTEXT_HANDLE context,
                                   int                iAdapterIndex,
                                   int                iThermalControllerIndex,
                                   ADLFanSpeedValue * lpFanSpeedValue
                                 );


/// Function to retrieve the fan speed reporting capability for thermal controllers. 
/// 
/// This function retrieves the fan speed reporting capability for a specified adapter and thermal controller. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in]     context                 Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in]     iAdapterIndex           The ADL index handle of the desired adapter. 
///   [in]     iThermalControllerIndex The ADL index handle of the desired thermal controller. Set to 0. 
///   [in,out] lpFanSpeedInfo          The pointer to the ADLFanSpeedInfo structure storing the retrieved fan speed information. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes 
/// 
/// Remarks
///   Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call ADL2_Main_Control_Create first to obtain ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using ADL2_Main_Control_Destroy.
int ADL2_Overdrive5_FanSpeedInfo_Get ( ADL_CONTEXT_HANDLE context,
                                       int                iAdapterIndex,
                                       int                iThermalControllerIndex,
                                       ADLFanSpeedInfo *  lpFanSpeedInfo
                                     );


/// Function to set the fan speed to the default fan speed value. 
/// 
/// This function sets the current fan speed for a specified adapter and thermal controller to the default fan speed. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in] context                 Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in] iAdapterIndex           The ADL index handle of the desired adapter. 
///   [in] iThermalControllerIndex The ADL index handle of the desired thermal controller. Set to 0. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes 
/// 
/// Remarks
///   Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call ADL2_Main_Control_Create first to obtain ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using ADL2_Main_Control_Destroy.
int ADL2_Overdrive5_FanSpeedToDefault_Set ( ADL_CONTEXT_HANDLE context,
                                            int                iAdapterIndex,
                                            int                iThermalControllerIndex
                                          );


/// Function to retrieve the current Overdrive parameters. 
/// 
/// This function retrieves the current Overdrive parameters for a specified adapter. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in]     context        Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in]     iAdapterIndex  The ADL index handle of the desired adapter. 
///   [in,out] lpOdParameters The pointer to the ADLODParameters structure storing the retrieved Overdrive parameters. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes 
/// 
/// Remarks
///   Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call ADL2_Main_Control_Create first to obtain ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using ADL2_Main_Control_Destroy.
int ADL2_Overdrive5_ODParameters_Get ( ADL_CONTEXT_HANDLE context,
                                       int                iAdapterIndex,
                                       ADLODParameters *  lpOdParameters
                                     );


/// Function to retrieve the current or default Overdrive performance levels. 
/// 
/// This function retrieves the current or default Overdrive performance levels for a specified adapter. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in]     context               Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in]     iAdapterIndex         The ADL index handle of the desired adapter. 
///   [in]     iDefault              The value indicating whether or not to retrieve the default performance levels. 
///   [in,out] lpOdPerformanceLevels The pointer to the ADLODPerformanceLevels structure storing the retrieved information. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes 
/// 
/// Remarks
///   Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call ADL2_Main_Control_Create first to obtain ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using ADL2_Main_Control_Destroy.
int ADL2_Overdrive5_ODPerformanceLevels_Get ( ADL_CONTEXT_HANDLE       context,
                                              int                      iAdapterIndex,
                                              int                      iDefault,
                                              ADLODPerformanceLevels * lpOdPerformanceLevels
                                            );


/// Function to set the current Overdrive performance levels. 
/// 
/// This function sets the current Overdrive performance levels for a specified adapter. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in] context               Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in] iAdapterIndex         The ADL index handle of the desired adapter. 
///   [in] lpOdPerformanceLevels The pointer to the ADLODPerformanceLevels structure storing the desired performance level. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes 
/// 
/// Remarks
///   Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call ADL2_Main_Control_Create first to obtain ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using ADL2_Main_Control_Destroy.
int ADL2_Overdrive5_ODPerformanceLevels_Set ( ADL_CONTEXT_HANDLE       context,
                                              int                      iAdapterIndex,
                                              ADLODPerformanceLevels * lpOdPerformanceLevels
                                            );


/// Function to check for PowerControl capabilities. 
/// 
/// The output parameter of the function lets the caller know about whether or not Power control feature is supported. 
/// Parameters
///   [in]  context       Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in]  iAdapterIndex The ADL index handle of the desired adapter. 
///   [out] lpSupported   The pointer to the caps of adapter settings 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK (zero). Otherwise the return value is an ADL error code (non-zero). Result Codes 
/// 
/// Remarks
///   Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call ADL2_Main_Control_Create first to obtain ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using ADL2_Main_Control_Destroy.
int ADL2_Overdrive5_PowerControl_Caps ( ADL_CONTEXT_HANDLE context,
                                        int                iAdapterIndex,
                                        int *              lpSupported
                                      );


/// Function to get values of PowerControl. 
/// 
/// The parameter of the function lets the caller to get new value of the Power control 
/// Parameters
///   [in]  context        Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in]  iAdapterIndex  The ADL index handle of the desired adapter 
///   [out] lpCurrentValue pointer to the current value of Power control 
///   [out] lpDefaultValue pointer to the Default value of Power control 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. 
/// 
/// Remarks
///   Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call ADL2_Main_Control_Create first to obtain ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using ADL2_Main_Control_Destroy.
int ADL2_Overdrive5_PowerControl_Get ( ADL_CONTEXT_HANDLE context,
                                       int                iAdapterIndex,
                                       int *              lpCurrentValue,
                                       int *              lpDefaultValue
                                     );


/// Function to set values of PowerControl. 
/// 
/// The parameter of the function lets the caller to set new value to the Power control 
/// Parameters
///   [in] context       Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in] iAdapterIndex The ADL index handle of the desired adapter 
///   [in] iValue        New value of Power control 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. 
/// 
/// Remarks
///   Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call ADL2_Main_Control_Create first to obtain ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using ADL2_Main_Control_Destroy.
int ADL2_Overdrive5_PowerControl_Set ( ADL_CONTEXT_HANDLE context,
                                       int                iAdapterIndex,
                                       int                iValue
                                     );


/// Function to get values of PowerControl information. 
/// 
/// The output parameter of the function lets the caller know about Power control adjust limit , step values and default value. parameters. 
/// Parameters
///   [in]  context            Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in]  iAdapterIndex      The ADL index handle of the desired adapter 
///   [out] lpPowerControlInfo The pointer to the ADLPowerControlInfo containing value of Power ///control 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. 
/// 
/// Remarks
///   Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call ADL2_Main_Control_Create first to obtain ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using ADL2_Main_Control_Destroy.
int ADL2_Overdrive5_PowerControlInfo_Get ( ADL_CONTEXT_HANDLE    context,
                                           int                   iAdapterIndex,
                                           ADLPowerControlInfo * lpPowerControlInfo
                                         );


/// Function to retrieve thermal controller temperatures. 
/// 
/// This function retrieves thermal controller temperature information for a specified adapter and thermal controller. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in]     context                 Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in]     iAdapterIndex           The ADL index handle of the desired adapter. 
///   [in]     iThermalControllerIndex The ADL index handle of the desired thermal controller. Set to 0. 
///   [in,out] lpTemperature           The pointer to the ADLTemperature structure storing the retrieved temperature information in milli-degrees Celsius. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes 
/// 
/// Remarks
///   Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call ADL2_Main_Control_Create first to obtain ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using ADL2_Main_Control_Destroy.
int ADL2_Overdrive5_Temperature_Get ( ADL_CONTEXT_HANDLE context,
                                      int                iAdapterIndex,
                                      int                iThermalControllerIndex,
                                      ADLTemperature *   lpTemperature
                                    );


/// Function to retrieve thermal devices information. 
/// 
/// This function retrieves thermal devices information for a specified adapter and thermal controller. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in]     context                 Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in]     iAdapterIndex           The ADL index handle of the desired adapter. 
///   [in]     iThermalControllerIndex The ADL index handle of the desired thermal controller. Set to 0. 
///   [in,out] lpThermalControllerInfo The pointer to the ADLThermalControllerInfo structure storing the retrieved thermal device information. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes 
/// 
/// Remarks
///   Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call ADL2_Main_Control_Create first to obtain ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using ADL2_Main_Control_Destroy.
int ADL2_Overdrive5_ThermalDevices_Enum ( ADL_CONTEXT_HANDLE         context,
                                          int                        iAdapterIndex,
                                          int                        iThermalControllerIndex,
                                          ADLThermalControllerInfo * lpThermalControllerInfo
                                        );


/// Function to retrieve current power management capabilities. 
/// 
/// This function retrieves current power management capabilities for a specified adapter. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in] context    Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in] iSupported The pointer to an int variable which indicates if Overdrive feature is supported ( ADL_TRUE : supported, ADL_FALSE : not supported) 
///   [in] iEnabled   The pointer to an int variable which indicates if Overdrive feature is enabled ( ADL_TRUE : enabled, ADL_FALSE : disabled) 
///   [in] iEnabled   The pointer to an int variable receiving the Overdrive feature version. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK (zero). Otherwise the return value is an ADL error code (non-zero). Result Codes. If Overdrive feature is not supported the return code is ADL_ERR_NOT_SUPPORTED
/// 
/// Remarks
///   Call this API prior to calling any other Overdrive APIs to determine if this feature is supported and enabled.
int ADL2_Overdrive_Caps ( ADL_CONTEXT_HANDLE context,
                          int                iAdapterIndex,
                          int *              iSupported,
                          int *              iEnabled,
                          int *              iVersion
                        );


/// Function to retrieve current power management-related activity. 
/// 
/// This function retrieves current power management-related activity for a specified adapter. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in]     iAdapterIndex The ADL index handle of the desired adapter. 
///   [in,out] lpActivity    The pointer to the ADLPMActivity structure storing the retrieved power management activity information. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes
int ADL_Overdrive5_CurrentActivity_Get ( int             iAdapterIndex,
                                         ADLPMActivity * lpActivity
                                       );


/// Function to retrieve the fan speed reported by the thermal controller. 
/// 
/// This function retrieves the reported fan speed from a specified thermal controller. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in]     iAdapterIndex           The ADL index handle of the desired adapter. 
///   [in]     iThermalControllerIndex The ADL index handle of the desired thermal controller. Set to 0. 
///   [in,out] lpFanSpeedValue         The pointer to the ADLFanSpeedValue structure storing the retrieved fan speed. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes
int ADL_Overdrive5_FanSpeed_Get ( int                iAdapterIndex,
                                  int                iThermalControllerIndex,
                                  ADLFanSpeedValue * lpFanSpeedValue
                                );


/// Function to set the fan speed. 
/// 
/// This function sets the fan speed for a specified adapter and thermal controller. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in] iAdapterIndex           The ADL index handle of the desired adapter. 
///   [in] iThermalControllerIndex The ADL index handle of the desired thermal controller. Set to 0. 
///   [in] lpFanSpeedValue         The pointer to the ADLFanSpeedValue structure storing the desired fan speed. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes
int ADL_Overdrive5_FanSpeed_Set ( int                iAdapterIndex,
                                  int                iThermalControllerIndex,
                                  ADLFanSpeedValue * lpFanSpeedValue
                                );


/// Function to retrieve the fan speed reporting capability for thermal controllers. 
/// 
/// This function retrieves the fan speed reporting capability for a specified adapter and thermal controller. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in]     iAdapterIndex           The ADL index handle of the desired adapter. 
///   [in]     iThermalControllerIndex The ADL index handle of the desired thermal controller. Set to 0. 
///   [in,out] lpFanSpeedInfo          The pointer to the ADLFanSpeedInfo structure storing the retrieved fan speed information. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes
int ADL_Overdrive5_FanSpeedInfo_Get ( int               iAdapterIndex,
                                      int               iThermalControllerIndex,
                                      ADLFanSpeedInfo * lpFanSpeedInfo
                                    );


/// Function to set the fan speed to the default fan speed value. 
/// 
/// This function sets the current fan speed for a specified adapter and thermal controller to the default fan speed. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in] iAdapterIndex           The ADL index handle of the desired adapter. 
///   [in] iThermalControllerIndex The ADL index handle of the desired thermal controller. Set to 0. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes
int ADL_Overdrive5_FanSpeedToDefault_Set ( int iAdapterIndex,
                                           int iThermalControllerIndex
                                         );


/// Function to retrieve the current Overdrive parameters. 
/// 
/// This function retrieves the current Overdrive parameters for a specified adapter. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in]     iAdapterIndex  The ADL index handle of the desired adapter. 
///   [in,out] lpOdParameters The pointer to the ADLODParameters structure storing the retrieved Overdrive parameters. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes
int ADL_Overdrive5_ODParameters_Get ( int               iAdapterIndex,
                                      ADLODParameters * lpOdParameters
                                    );


/// Function to retrieve the current or default Overdrive performance levels. 
/// 
/// This function retrieves the current or default Overdrive performance levels for a specified adapter. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in]     iAdapterIndex         The ADL index handle of the desired adapter. 
///   [in]     iDefault              The value indicating whether or not to retrieve the default performance levels. 
///   [in,out] lpOdPerformanceLevels The pointer to the ADLODPerformanceLevels structure storing the retrieved information. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes
int ADL_Overdrive5_ODPerformanceLevels_Get ( int                      iAdapterIndex,
                                             int                      iDefault,
                                             ADLODPerformanceLevels * lpOdPerformanceLevels
                                           );


/// Function to set the current Overdrive performance levels. 
/// 
/// This function sets the current Overdrive performance levels for a specified adapter. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in] iAdapterIndex         The ADL index handle of the desired adapter. 
///   [in] lpOdPerformanceLevels The pointer to the ADLODPerformanceLevels structure storing the desired performance level. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes
int ADL_Overdrive5_ODPerformanceLevels_Set ( int                      iAdapterIndex,
                                             ADLODPerformanceLevels * lpOdPerformanceLevels
                                           );


/// Function to check for PowerControl capabilities. 
/// 
/// The output parameter of the function lets the caller know about whether or not Power control feature is supported. 
/// Parameters
///   [in]  iAdapterIndex The ADL index handle of the desired adapter. 
///   [out] lpSupported   The pointer to the caps of adapter settings 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK (zero). Otherwise the return value is an ADL error code (non-zero). Result Codes
int ADL_Overdrive5_PowerControl_Caps ( int   iAdapterIndex,
                                       int * lpSupported
                                     );


/// Function to get values of PowerControl. 
/// 
/// The parameter of the function lets the caller to get new value of the Power control 
/// Parameters
///   [in]  iAdapterIndex  The ADL index handle of the desired adapter 
///   [out] lpCurrentValue pointer to the current value of Power control 
///   [out] lpDefaultValue pointer to the Default value of Power control 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code.
int ADL_Overdrive5_PowerControl_Get ( int   iAdapterIndex,
                                      int * lpCurrentValue,
                                      int * lpDefaultValue
                                    );


/// Function to set values of PowerControl. 
/// 
/// The parameter of the function lets the caller to set new value to the Power control 
/// Parameters
///   [in] iAdapterIndex The ADL index handle of the desired adapter 
///   [in] iValue        New value of Power control 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code.
int ADL_Overdrive5_PowerControl_Set ( int iAdapterIndex,
                                      int iValue
                                    );


/// Function to get values of PowerControl information. 
/// 
/// The output parameter of the function lets the caller know about Power control adjust limit , step values and default value. parameters. 
/// Parameters
///   [in]  iAdapterIndex      The ADL index handle of the desired adapter 
///   [out] lpPowerControlInfo The pointer to the ADLPowerControlInfo containing value of Power ///control 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code.
int ADL_Overdrive5_PowerControlInfo_Get ( int                   iAdapterIndex,
                                          ADLPowerControlInfo * lpPowerControlInfo
                                        );


/// Function to retrieve thermal controller temperatures. 
/// 
/// This function retrieves thermal controller temperature information for a specified adapter and thermal controller. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in]     iAdapterIndex           The ADL index handle of the desired adapter. 
///   [in]     iThermalControllerIndex The ADL index handle of the desired thermal controller. Set to 0. 
///   [in,out] lpTemperature           The pointer to the ADLTemperature structure storing the retrieved temperature information. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes
int ADL_Overdrive5_Temperature_Get ( int              iAdapterIndex,
                                     int              iThermalControllerIndex,
                                     ADLTemperature * lpTemperature
                                   );


/// Function to retrieve thermal devices information. 
/// 
/// This function retrieves thermal devices information for a specified adapter and thermal controller. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in]     iAdapterIndex           The ADL index handle of the desired adapter. 
///   [in]     iThermalControllerIndex The ADL index handle of the desired thermal controller. Set to 0. 
///   [in,out] lpThermalControllerInfo The pointer to the ADLThermalControllerInfo structure storing the retrieved thermal device information. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes
int ADL_Overdrive5_ThermalDevices_Enum ( int                        iAdapterIndex,
                                         int                        iThermalControllerIndex,
                                         ADLThermalControllerInfo * lpThermalControllerInfo
                                       );


/// Function to retrieve current power management capabilities. 
/// 
/// This function retrieves current power management capabilities for a specified adapter. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in] iSupported The pointer to an int variable which indicates if Overdrive feature is supported ( ADL_TRUE : supported, ADL_FALSE : not supported) 
///   [in] iEnabled   The pointer to an int variable which indicates if Overdrive feature is enabled ( ADL_TRUE : enabled, ADL_FALSE : disabled) 
///   [in] iEnabled   The pointer to an int variable receiving the Overdrive feature version. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK (zero). Otherwise the return value is an ADL error code (non-zero). Result Codes. If Overdrive feature is not supported the return code is ADL_ERR_NOT_SUPPORTED
/// 
/// Remarks
///   Call this API prior to calling any other Overdrive APIs to determine if this feature is supported and enabled.
int ADL_Overdrive_Caps ( int   iAdapterIndex,
                         int * iSupported,
                         int * iEnabled,
                         int * iVersion
                       );


#endif /* ADL_HEADER_OVERDRIVE5_H_ */
