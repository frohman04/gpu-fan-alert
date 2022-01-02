#ifndef ADL_HEADER_OVERDRIVE6_H_
#define ADL_HEADER_OVERDRIVE6_H_

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

/// Function returns the advanced fan control capability of the specified adapter. Advanced fan control is the feature which makes the fan speed is always kept to a minimum so the acoustics are also minimized. The end user will be able to select the target ASIC temperature and fan PWM% via the CCC or other applications. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in]  context       Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in]  iAdapterIndex The ADL index handle of the desired adapter. 
///   [out] lpSupported   a pointer to an int containing the current advanced fan control(AFC) feature status. Possible Values: 1 - AFC Enabled, 0 - AFC Disabled. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. 
/// 
/// Remarks
///   Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process and to assure that ADL API are thread-safe. Such clients have to call ADL2_Main_Control_Create first to obtain ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using ADL2_Main_Control_Destroy.
int ADL2_Overdrive6_AdvancedFan_Caps ( ADL_CONTEXT_HANDLE context,
                                       int                iAdapterIndex,
                                       int *              lpSupported
                                     );


/// Function to retrieve the current Overdrive capabilities. 
/// 
/// This function retrieves the current Overdrive capabilities for a specified adapter. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in]     context          Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in]     iAdapterIndex    The ADL index handle of the desired adapter. 
///   [in,out] lpODCapabilities The pointer to the ADLOD6Capabilities structure storing the retrieved Overdrive parameters. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes 
/// 
/// Remarks
///   Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call ADL2_Main_Control_Create first to obtain ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using ADL2_Main_Control_Destroy.
int ADL2_Overdrive6_Capabilities_Get ( ADL_CONTEXT_HANDLE   context,
                                       int                  iAdapterIndex,
                                       ADLOD6Capabilities * lpODCapabilities
                                     );


/// Function to retrieve the current Overdrive extension capabilities . 
/// 
/// This function retrieves the current Overdrive extension capabilities for a specified adapter. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in]     context          Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in]     iAdapterIndex    The ADL index handle of the desired adapter. 
///   [in,out] lpODCapabilities The pointer to the ADLOD6CapabilitiesEx structure storing the retrieved Overdrive parameters. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes 
/// 
/// Remarks
///   Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call ADL2_Main_Control_Create first to obtain ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using ADL2_Main_Control_Destroy.
int ADL2_Overdrive6_CapabilitiesEx_Get ( ADL_CONTEXT_HANDLE     context,
                                         int                    iAdapterIndex,
                                         ADLOD6CapabilitiesEx * lpODCapabilities
                                       );


/// Function Requests to Acquire or Release I2C of the specified adapter . 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in] context       Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in] iAdapterIndex The ADL index handle of the desired adapter. 
///   [in] iControl      int to specify whether to acquire or release I2C. #define CWDDEPM_I2C_RELEASE 0 #define CWDDEPM_I2C_ACQUIRE 1 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. 
/// 
/// Remarks
///   Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process and to assure that ADL API are thread-safe. Such clients have to call ADL2_Main_Control_Create first to obtain ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using ADL2_Main_Control_Destroy.
int ADL2_Overdrive6_ControlI2C ( ADL_CONTEXT_HANDLE context,
                                 int                iAdapterIndex,
                                 int                iControl
                               );


/// Function returns the current power of the specified adapter . 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in]  context        Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in]  iAdapterIndex  The ADL index handle of the desired adapter. 
///   [in]  ePowerType     The int to specify the power type. 0 Is for ASIC Total Power. 
///   [out] lpCurrentValue The int pointer containing the current power in Watts with 8 fractional bits. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. 
/// 
/// Remarks
///   Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process and to assure that ADL API are thread-safe. Such clients have to call ADL2_Main_Control_Create first to obtain ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using ADL2_Main_Control_Destroy.
int ADL2_Overdrive6_CurrentPower_Get ( ADL_CONTEXT_HANDLE context,
                                       int                iAdapterIndex,
                                       int                iPowerType,
                                       int *              lpCurrentValue
                                     );


/// Function to retrieve current Overdrive and performance-related activity. 
/// 
/// This function retrieves current Overdrive and performance-related activity for a specified adapter. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in]     context         Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in]     iAdapterIndex   The ADL index handle of the desired adapter. 
///   [in,out] lpCurrentStatus The pointer to the ADLOD6CurrentStatus structure storing the retrieved activity information. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes 
/// 
/// Remarks
///   Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call ADL2_Main_Control_Create first to obtain ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using ADL2_Main_Control_Destroy.
int ADL2_Overdrive6_CurrentStatus_Get ( ADL_CONTEXT_HANDLE    context,
                                        int                   iAdapterIndex,
                                        ADLOD6CurrentStatus * lpCurrentStatus
                                      );


/// Function returns default target Fan PWM and current Fan PWM value of the specified adapter. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in]  context        Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in]  iAdapterIndex  The ADL index handle of the desired adapter. 
///   [out] lpDefaultValue a pointer to an int that will contain default Fan PWM value for specified adapter. 
///   [out] lpCurrentValue a pointer to an int that will contain current Fan PWM value for specified adapter. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. 
/// 
/// Remarks
///   Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process and to assure that ADL API are thread-safe. Such clients have to call ADL2_Main_Control_Create first to obtain ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using ADL2_Main_Control_Destroy.
int ADL2_Overdrive6_FanPWMLimitData_Get ( ADL_CONTEXT_HANDLE context,
                                          int                iAdapterIndex,
                                          int *              lpCurrentValue,
                                          int *              lpDefaultValue
                                        );


/// Function changes the target Fan PWM current value of the specified adapter . 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in]  context       Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in]  iAdapterIndex The ADL index handle of the desired adapter. 
///   [out] iCurrentValue int value containing new Fan PWM value to apply for specified adapter. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. 
/// 
/// Remarks
///   Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process and to assure that ADL API are thread-safe. Such clients have to call ADL2_Main_Control_Create first to obtain ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using ADL2_Main_Control_Destroy.
int ADL2_Overdrive6_FanPWMLimitData_Set ( ADL_CONTEXT_HANDLE context,
                                          int                iAdapterIndex,
                                          int                iCurrentValue
                                        );


/// Function returns the target Fan PWM range of the specified adapter . 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in]  context           Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in]  iAdapterIndex     The ADL index handle of the desired adapter. 
///   [out] lpFanPWMLimitInfo a pointer to an ADLOD6ParameterRange structure containing acceptable Fan PWM range to work with. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. 
/// 
/// Remarks
///   Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process and to assure that ADL API are thread-safe. Such clients have to call ADL2_Main_Control_Create first to obtain ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using ADL2_Main_Control_Destroy.
int ADL2_Overdrive6_FanPWMLimitRangeInfo_Get ( ADL_CONTEXT_HANDLE     context,
                                               int                    iAdapterIndex,
                                               ADLOD6ParameterRange * lpFanPWMLimitInfo
                                             );


/// Function to retrieve the fan speed reported by the thermal controller. 
/// 
/// This function retrieves the reported fan speed from a specified adapter. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in]     context        Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in]     iAdapterIndex  The ADL index handle of the desired adapter. 
///   [in,out] lpFanSpeedInfo The pointer to the ADLOD6FanSpeedInfo structure storing the retrieved fan speed. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes 
/// 
/// Remarks
///   Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call ADL2_Main_Control_Create first to obtain ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using ADL2_Main_Control_Destroy.
int ADL2_Overdrive6_FanSpeed_Get ( ADL_CONTEXT_HANDLE   context,
                                   int                  iAdapterIndex,
                                   ADLOD6FanSpeedInfo * lpFanSpeedInfo
                                 );


/// Function to reset the fan speed to the default. 
/// 
/// This function resets the fan speed for a specified adapter to the default. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in] context       Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in] iAdapterIndex The ADL index handle of the desired adapter. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes 
/// 
/// Remarks
///   Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call ADL2_Main_Control_Create first to obtain ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using ADL2_Main_Control_Destroy.
int ADL2_Overdrive6_FanSpeed_Reset ( ADL_CONTEXT_HANDLE context,
                                     int                iAdapterIndex
                                   );


/// Function to set the fan speed. 
/// 
/// This function sets the fan speed for a specified adapter. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in] context         Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in] iAdapterIndex   The ADL index handle of the desired adapter. 
///   [in] lpFanSpeedValue The pointer to the ADLOD6FanSpeedValue structure containing the new fan speed value to be set. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes 
/// 
/// Remarks
///   Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call ADL2_Main_Control_Create first to obtain ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using ADL2_Main_Control_Destroy.
int ADL2_Overdrive6_FanSpeed_Set ( ADL_CONTEXT_HANDLE    context,
                                   int                   iAdapterIndex,
                                   ADLOD6FanSpeedValue * lpFanSpeedValue
                                 );


/// Function returns the fuzzy control capability of the specified adapter. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in]  context       Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in]  iAdapterIndex The ADL index handle of the desired adapter. 
///   [out] lpSupported   a pointer to an int containing the current fuzzy control feature capability. Possible Values: 1 - fuzzy support, 0 - fuzzy not support. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code.
int ADL2_Overdrive6_FuzzyController_Caps ( ADL_CONTEXT_HANDLE context,
                                           int                iAdapterIndex,
                                           int *              lpSupported
                                         );


/// Function to check for PowerControl capabilities. 
/// 
/// This function returns the PowerControl capability of the specified adapter. PowerControl is the feature which allows the performance characteristics of the GPU to be adjusted by changing the PowerTune power limits. Increasing the PowerControl value can increase maximum performance, but may cause more power to be consumed. Decreasing the PowerControl value can lower power consumption, but may cause lower performance. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in]  context       Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in]  iAdapterIndex The ADL index handle of the desired adapter. 
///   [out] lpSupported   The pointer to a value that receives the PowerControl capability of the adapter. Non-zero if PowerControl is supported. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK (zero). Otherwise the return value is an ADL error code (non-zero). Result Codes 
/// 
/// Remarks
///   Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call ADL2_Main_Control_Create first to obtain ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using ADL2_Main_Control_Destroy.
int ADL2_Overdrive6_PowerControl_Caps ( ADL_CONTEXT_HANDLE context,
                                        int                iAdapterIndex,
                                        int *              lpSupported
                                      );


/// Function to get the current and default PowerControl adjustment values. 
/// 
/// This function returns the current and default PowerControl adjustment values for the specified adapter. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in]  context        Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in]  iAdapterIndex  The ADL index handle of the desired adapter. 
///   [out] lpCurrentValue pointer to the current PowerControl adjustment value. 
///   [out] lpDefaultValue pointer to the default PowerControl adjustment value. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. 
/// 
/// Remarks
///   Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call ADL2_Main_Control_Create first to obtain ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using ADL2_Main_Control_Destroy.
int ADL2_Overdrive6_PowerControl_Get ( ADL_CONTEXT_HANDLE context,
                                       int                iAdapterIndex,
                                       int *              lpCurrentValue,
                                       int *              lpDefaultValue
                                     );


/// Function to set the current PowerControl adjustment value. 
/// 
/// This function sets the current PowerControl adjustment value. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in] context       Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in] iAdapterIndex The ADL index handle of the desired adapter. 
///   [in] iValue        The new PowerControl adjustment value to be set. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. 
/// 
/// Remarks
///   Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call ADL2_Main_Control_Create first to obtain ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using ADL2_Main_Control_Destroy.
int ADL2_Overdrive6_PowerControl_Set ( ADL_CONTEXT_HANDLE context,
                                       int                iAdapterIndex,
                                       int                iValue
                                     );


/// Function to get the PowerControl adjustment range. 
/// 
/// This function returns the PowerControl adjustment range (in percentage) for the specified adapter. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in]     context            Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in]     iAdapterIndex      The ADL index handle of the desired adapter. 
///   [in,out] lpPowerControlInfo The pointer to the ADLOD6PowerControlInfo returning the PowerControl adjustment range. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. 
/// 
/// Remarks
///   Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call ADL2_Main_Control_Create first to obtain ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using ADL2_Main_Control_Destroy.
int ADL2_Overdrive6_PowerControlInfo_Get ( ADL_CONTEXT_HANDLE       context,
                                           int                      iAdapterIndex,
                                           ADLOD6PowerControlInfo * lpPowerControlInfo
                                         );


/// Function to reset the Overdrive clock ranges to default. 
/// 
/// This function resets the Overdrive clock ranges to default for a specified adapter. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in] context       Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in] iAdapterIndex The ADL index handle of the desired adapter. 
///   [in] iStateType    The power state which will be reset to default clock ranges. Currently only performance state is supported. Possible Values: ADL_OD6_SETSTATE_PERFORMANCE 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes 
/// 
/// Remarks
///   Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call ADL2_Main_Control_Create first to obtain ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using ADL2_Main_Control_Destroy.
int ADL2_Overdrive6_State_Reset ( ADL_CONTEXT_HANDLE context,
                                  int                iAdapterIndex,
                                  int                iStateType
                                );


/// Function to set the current Overdrive clock ranges. 
/// 
/// This function sets the current Overdrive clock ranges for a specified adapter. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in] context       Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in] iAdapterIndex The ADL index handle of the desired adapter. 
///   [in] iStateType    The power state which will have clock ranges changed. Currently only performance state is supported. Possible Values: ADL_OD6_SETSTATE_PERFORMANCE 
///   [in] lpStateInfo   Pointer to the structure ADLOD6StateInfo containing clock ranges to be set. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes 
/// 
/// Remarks
///   Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call ADL2_Main_Control_Create first to obtain ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using ADL2_Main_Control_Destroy.
int ADL2_Overdrive6_State_Set ( ADL_CONTEXT_HANDLE context,
                                int                iAdapterIndex,
                                int                iStateType,
                                ADLOD6StateInfo *  lpStateInfo
                              );


/// Function to retrieve the current or default Overdrive extension clock ranges. 
/// 
/// This function retrieves the current or default Overdrive extension clock ranges for a specified adapter. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in]     context       Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in]     iAdapterIndex The ADL index handle of the desired adapter. 
///   [in]     iStateType    Specifies if default or current clock ranges for the power state will be retrieved. Currently only performance state is supported. Possible Values: ADL_OD6_GETSTATEINFO_DEFAULT_PERFORMANCE, ADL_OD6_GETSTATEINFO_CUSTOM_PERFORMANCE, ADL_OD6_GETSTATEINFO_CURRENT 
///   [in,out] lpStateInfo   Pointer to the retrieved clock range info structure ADLOD6StateEx. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes 
/// 
/// Remarks
///   Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call ADL2_Main_Control_Create first to obtain ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using ADL2_Main_Control_Destroy.
int ADL2_Overdrive6_StateEx_Get ( ADL_CONTEXT_HANDLE context,
                                  int                iAdapterIndex,
                                  int                iStateType,
                                  ADLOD6StateEx *    lpODState
                                );


/// Function to set the current Overdrive extension clock ranges. 
/// 
/// This function sets the current Overdrive extension clock ranges for a specified adapter. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in] context       Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in] iAdapterIndex The ADL index handle of the desired adapter. 
///   [in] iStateType    The power state which will have clock ranges changed. Currently only performance state is supported. Possible Values: ADL_OD6_SETSTATE_PERFORMANCE 
///   [in] lpStateInfo   Pointer to the structure ADLOD6StateEx containing clock ranges to be set. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes 
/// 
/// Remarks
///   Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call ADL2_Main_Control_Create first to obtain ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using ADL2_Main_Control_Destroy.
int ADL2_Overdrive6_StateEx_Set ( ADL_CONTEXT_HANDLE context,
                                  int                iAdapterIndex,
                                  int                iStateType,
                                  ADLOD6StateEx *    lpODState
                                );


/// Function to retrieve the current or default Overdrive clock ranges. 
/// 
/// This function retrieves the current or default Overdrive clock ranges for a specified adapter. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in]     context       Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in]     iAdapterIndex The ADL index handle of the desired adapter. 
///   [in]     iStateType    Specifies if default or current clock ranges for the power state will be retrieved. Currently only performance state is supported. Possible Values: ADL_OD6_GETSTATEINFO_DEFAULT_PERFORMANCE, ADL_OD6_GETSTATEINFO_CUSTOM_PERFORMANCE, ADL_OD6_GETSTATEINFO_CURRENT 
///   [in,out] lpStateInfo   Pointer to the retrieved clock range info structure ADLOD6StateInfo. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes 
/// 
/// Remarks
///   Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call ADL2_Main_Control_Create first to obtain ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using ADL2_Main_Control_Destroy.
int ADL2_Overdrive6_StateInfo_Get ( ADL_CONTEXT_HANDLE context,
                                    int                iAdapterIndex,
                                    int                iStateType,
                                    ADLOD6StateInfo *  lpStateInfo
                                  );


/// Function returns default target temperature and current temp. value of the specified adapter. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in]  context        Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in]  iAdapterIndex  The ADL index handle of the desired adapter. 
///   [out] lpDefaultValue a pointer to an int that will contain default temperature value for specified adapter. 
///   [out] lpCurrentValue a pointer to an int that will contain current temperature value for specified adapter. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. 
/// 
/// Remarks
///   Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process and to assure that ADL API are thread-safe. Such clients have to call ADL2_Main_Control_Create first to obtain ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using ADL2_Main_Control_Destroy.
int ADL2_Overdrive6_TargetTemperatureData_Get ( ADL_CONTEXT_HANDLE context,
                                                int                iAdapterIndex,
                                                int *              lpCurrentValue,
                                                int *              lpDefaultValue
                                              );


/// Function changes the target temperature current value of the specified adapter . 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in]  context       Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in]  iAdapterIndex The ADL index handle of the desired adapter. 
///   [out] iCurrentValue int value containing new temperature value to apply for specified adapter. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. 
/// 
/// Remarks
///   Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process and to assure that ADL API are thread-safe. Such clients have to call ADL2_Main_Control_Create first to obtain ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using ADL2_Main_Control_Destroy.
int ADL2_Overdrive6_TargetTemperatureData_Set ( ADL_CONTEXT_HANDLE context,
                                                int                iAdapterIndex,
                                                int                iCurrentValue
                                              );


/// Function returns the target temperature range of the specified adapter . 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in]  context                 Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in]  iAdapterIndex           The ADL index handle of the desired adapter. 
///   [out] lpTargetTemperatureInfo a pointer to an ADLOD6ParameterRange structure containing acceptable temperature range to work with. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. 
/// 
/// Remarks
///   Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process and to assure that ADL API are thread-safe. Such clients have to call ADL2_Main_Control_Create first to obtain ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using ADL2_Main_Control_Destroy.
int ADL2_Overdrive6_TargetTemperatureRangeInfo_Get ( ADL_CONTEXT_HANDLE     context,
                                                     int                    iAdapterIndex,
                                                     ADLOD6ParameterRange * lpTargetTemperatureInfo
                                                   );


/// Function to retrieve GPU temperature from the thermal controller. 
/// 
/// This function retrieves GPU temperature from the thermal controller for a specified adapter. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in]     context       Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in]     iAdapterIndex The ADL index handle of the desired adapter. 
///   [in,out] lpTemperature The pointer to the retrieved temperature in milli-degrees Celsius. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes 
/// 
/// Remarks
///   Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call ADL2_Main_Control_Create first to obtain ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using ADL2_Main_Control_Destroy.
int ADL2_Overdrive6_Temperature_Get ( ADL_CONTEXT_HANDLE context,
                                      int                iAdapterIndex,
                                      int *              lpTemperature
                                    );


/// Function to retrieve capabilities of the GPU thermal controller. 
/// 
/// This function retrieves GPU thermal controller capabilities for a specified adapter. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in]     context                 Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in]     iAdapterIndex           The ADL index handle of the desired adapter. 
///   [in,out] lpThermalControllerInfo The pointer to the ADLThermalControllerInfo structure storing the retrieved GPU thermal controller information. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes 
/// 
/// Remarks
///   Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call ADL2_Main_Control_Create first to obtain ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using ADL2_Main_Control_Destroy.
int ADL2_Overdrive6_ThermalController_Caps ( ADL_CONTEXT_HANDLE            context,
                                             int                           iAdapterIndex,
                                             ADLOD6ThermalControllerCaps * lpThermalControllerCaps
                                           );


/// Function to retrieve the current Thermal Limit Unlock feature status. 
/// 
/// This function to retrieve the current Thermal Limit Unlock feature status. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in]  context       Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in]  iAdapterIndex The ADL index handle of the desired adapter. 
///   [in]  iStateType    The power state which will have clock ranges changed. Currently only performance state is supported. Possible Values: ADL_OD6_SETSTATE_PERFORMANCE 
///   [out] pEnable       a pointer to an int containing the current TLU status. Possible Values: 1 - Enable TLU, 0 - Disable TLU. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. 
/// 
/// Remarks
///   Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call ADL2_Main_Control_Create first to obtain ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using ADL2_Main_Control_Destroy.
int ADL2_Overdrive6_ThermalLimitUnlock_Get ( ADL_CONTEXT_HANDLE context,
                                             int                iAdapterIndex,
                                             int                iStateType,
                                             int *              pEnabled
                                           );


/// Function to enable the current Thermal Limit Unlock feature. 
/// 
/// This function enable the current Thermal Limit Unlock feature. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in] context       Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in] iAdapterIndex The ADL index handle of the desired adapter. 
///   [in] iStateType    The power state which will have clock ranges changed. Currently only performance state is supported. Possible Values: ADL_OD6_SETSTATE_PERFORMANCE 
///   [in] iEnable       1 - Enable TLU, 0 - Disable TLU. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. 
/// 
/// Remarks
///   Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call ADL2_Main_Control_Create first to obtain ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using ADL2_Main_Control_Destroy.
int ADL2_Overdrive6_ThermalLimitUnlock_Set ( ADL_CONTEXT_HANDLE context,
                                             int                iAdapterIndex,
                                             int                iStateType,
                                             int                iEnable
                                           );


/// Function to get the current and default VoltageControl adjustment values. 
/// 
/// This function returns the current and default VoltageControl adjustment values for the specified adapter. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in]  context        Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in]  iAdapterIndex  The ADL index handle of the desired adapter. 
///   [out] lpCurrentValue pointer to the current VoltageControl adjustment value. 
///   [out] lpDefaultValue pointer to the default VoltageControl adjustment value. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. 
/// 
/// Remarks
///   Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call ADL2_Main_Control_Create first to obtain ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using ADL2_Main_Control_Destroy.
int ADL2_Overdrive6_VoltageControl_Get ( ADL_CONTEXT_HANDLE context,
                                         int                iAdapterIndex,
                                         int *              lpCurrentValue,
                                         int *              lpDefaultValue
                                       );


/// Function to set the current VoltageControl adjustment value. 
/// 
/// This function sets the current VoltageControl adjustment value. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in] context       Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in] iAdapterIndex The ADL index handle of the desired adapter. 
///   [in] iValue        The new VoltageControl adjustment value to be set. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. 
/// 
/// Remarks
///   Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call ADL2_Main_Control_Create first to obtain ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using ADL2_Main_Control_Destroy.
int ADL2_Overdrive6_VoltageControl_Set ( ADL_CONTEXT_HANDLE context,
                                         int                iAdapterIndex,
                                         int                iValue
                                       );


/// Function to get the VoltageControl adjustment range. 
/// 
/// This function returns the VoltageControl adjustment range for the specified adapter. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in]     context              Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in]     iAdapterIndex        The ADL index handle of the desired adapter. 
///   [in,out] lpVoltageControlInfo The pointer to the ADLOD6VoltageControlInfo returning the VoltageControl adjustment range. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. 
/// 
/// Remarks
///   Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call ADL2_Main_Control_Create first to obtain ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using ADL2_Main_Control_Destroy.
int ADL2_Overdrive6_VoltageControlInfo_Get ( ADL_CONTEXT_HANDLE         context,
                                             int                        iAdapterIndex,
                                             ADLOD6VoltageControlInfo * lpVoltageControlInfo
                                           );


/// Function returns the advanced fan control capability of the specified adapter. Advanced fan control is the feature which makes the fan speed is always kept to a minimum within current settings so the acoustics are also minimized. The end users are able to select the target ASIC temperature and fan PWM% via the CCC or other applications. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in]  iAdapterIndex The ADL index handle of the desired adapter. 
///   [out] lpSupported   a pointer to an int containing the current advanced fan control(AFC) feature status. Possible Values: 1 - AFC Enabled, 0 - AFC Disabled. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code.
int ADL_Overdrive6_AdvancedFan_Caps ( int   iAdapterIndex,
                                      int * lpSupported
                                    );


/// Function to retrieve the current Overdrive capabilities. 
/// 
/// This function retrieves the current Overdrive capabilities for a specified adapter. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in]     iAdapterIndex    The ADL index handle of the desired adapter. 
///   [in,out] lpODCapabilities The pointer to the ADLOD6Capabilities structure storing the retrieved Overdrive parameters. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes
int ADL_Overdrive6_Capabilities_Get ( int                  iAdapterIndex,
                                      ADLOD6Capabilities * lpODCapabilities
                                    );


/// Function to retrieve the current Overdrive extension capabilities. 
/// 
/// This function retrieves the current Overdrive extension capabilities for a specified adapter. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in]     iAdapterIndex    The ADL index handle of the desired adapter. 
///   [in,out] lpODCapabilities The pointer to the ADLOD6CapabilitiesEx structure storing the retrieved Overdrive parameters. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes
int ADL_Overdrive6_CapabilitiesEx_Get ( int                    iAdapterIndex,
                                        ADLOD6CapabilitiesEx * lpODCapabilities
                                      );


/// Function to retrieve current Overdrive and performance-related activity. 
/// 
/// This function retrieves current Overdrive and performance-related activity for a specified adapter. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in]     iAdapterIndex   The ADL index handle of the desired adapter. 
///   [in,out] lpCurrentStatus The pointer to the ADLOD6CurrentStatus structure storing the retrieved activity information. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes
int ADL_Overdrive6_CurrentStatus_Get ( int                   iAdapterIndex,
                                       ADLOD6CurrentStatus * lpCurrentStatus
                                     );


/// Function returns default target Fan PWM and current Fan PWM value of the specified adapter. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in]  iAdapterIndex  The ADL index handle of the desired adapter. 
///   [out] lpDefaultValue a pointer to an int that will contain default Fan PWM value for specified adapter. 
///   [out] lpCurrentValue a pointer to an int that will contain current Fan PWM value for specified adapter. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code.
int ADL_Overdrive6_FanPWMLimitData_Get ( int   iAdapterIndex,
                                         int * lpCurrentValue,
                                         int * lpDefaultValue
                                       );


/// Function changes the target Fan PWM current value of the specified adapter . 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in]  iAdapterIndex The ADL index handle of the desired adapter. 
///   [out] iCurrentValue int value containing new Fan PWM value to apply for specified adapter. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code.
int ADL_Overdrive6_FanPWMLimitData_Set ( int iAdapterIndex,
                                         int iCurrentValue
                                       );


/// Function returns the target Fan PWM range of the specified adapter . 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in]  iAdapterIndex     The ADL index handle of the desired adapter. 
///   [out] lpFanPWMLimitInfo a pointer to an ADLOD6ParameterRange structure containing acceptable Fan PWM range to work with. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code.
int ADL_Overdrive6_FanPWMLimitRangeInfo_Get ( int                    iAdapterIndex,
                                              ADLOD6ParameterRange * lpFanPWMLimitInfo
                                            );


/// Function to retrieve the fan speed reported by the thermal controller. 
/// 
/// This function retrieves the reported fan speed from a specified adapter. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in]     iAdapterIndex  The ADL index handle of the desired adapter. 
///   [in,out] lpFanSpeedInfo The pointer to the ADLOD6FanSpeedInfo structure storing the retrieved fan speed. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes
int ADL_Overdrive6_FanSpeed_Get ( int                  iAdapterIndex,
                                  ADLOD6FanSpeedInfo * lpFanSpeedInfo
                                );


/// Function to reset the fan speed to the default. 
/// 
/// This function resets the fan speed for a specified adapter to the default. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in] iAdapterIndex The ADL index handle of the desired adapter. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes
int ADL_Overdrive6_FanSpeed_Reset ( );


/// Function to set the fan speed. 
/// 
/// This function sets the fan speed for a specified adapter. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in] iAdapterIndex   The ADL index handle of the desired adapter. 
///   [in] lpFanSpeedValue The pointer to the ADLOD6FanSpeedValue structure containing the new fan speed value to be set. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes
int ADL_Overdrive6_FanSpeed_Set ( int                   iAdapterIndex,
                                  ADLOD6FanSpeedValue * lpFanSpeedValue
                                );


/// Function returns the fuzzy control capability of the specified adapter. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in]  iAdapterIndex The ADL index handle of the desired adapter. 
///   [out] lpSupported   a pointer to an int containing the current fuzzy control feature capability. Possible Values: 1 - fuzzy support, 0 - fuzzy not support. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code.
int ADL_Overdrive6_FuzzyController_Caps ( int   iAdapterIndex,
                                          int * lpSupported
                                        );


/// Function to check for PowerControl capabilities. 
/// 
/// This function returns the PowerControl capability of the specified adapter. PowerControl is the feature which allows the performance characteristics of the GPU to be adjusted by changing the PowerTune power limits. Increasing the PowerControl value can increase maximum performance, but may cause more power to be consumed. Decreasing the PowerControl value can lower power consumption, but may cause lower performance. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in]  iAdapterIndex The ADL index handle of the desired adapter. 
///   [out] lpSupported   The pointer to a value that receives the PowerControl capability of the adapter. Non-zero if PowerControl is supported. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK (zero). Otherwise the return value is an ADL error code (non-zero). Result Codes
int ADL_Overdrive6_PowerControl_Caps ( int   iAdapterIndex,
                                       int * lpSupported
                                     );


/// Function to get the current and default PowerControl adjustment values. 
/// 
/// This function returns the current and default PowerControl adjustment values for the specified adapter. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in]  iAdapterIndex  The ADL index handle of the desired adapter. 
///   [out] lpCurrentValue pointer to the current PowerControl adjustment value. 
///   [out] lpDefaultValue pointer to the default PowerControl adjustment value. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code.
int ADL_Overdrive6_PowerControl_Get ( int   iAdapterIndex,
                                      int * lpCurrentValue,
                                      int * lpDefaultValue
                                    );


/// Function to set the current PowerControl adjustment value. 
/// 
/// This function sets the current PowerControl adjustment value. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in] iAdapterIndex The ADL index handle of the desired adapter. 
///   [in] iValue        The new PowerControl adjustment value to be set. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code.
int ADL_Overdrive6_PowerControl_Set ( int iAdapterIndex,
                                      int iValue
                                    );


/// Function to get the PowerControl adjustment range. 
/// 
/// This function returns the PowerControl adjustment range (in percentage) for the specified adapter. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in]     iAdapterIndex      The ADL index handle of the desired adapter. 
///   [in,out] lpPowerControlInfo The pointer to the ADLOD6PowerControlInfo returning the PowerControl adjustment range. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code.
int ADL_Overdrive6_PowerControlInfo_Get ( int                      iAdapterIndex,
                                          ADLOD6PowerControlInfo * lpPowerControlInfo
                                        );


/// Function to reset the Overdrive clock ranges to default. 
/// 
/// This function resets the Overdrive clock ranges to default for a specified adapter. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in] iAdapterIndex The ADL index handle of the desired adapter. 
///   [in] iStateType    The power state which will be reset to default clock ranges. Currently only performance state is supported. Possible Values: ADL_OD6_SETSTATE_PERFORMANCE 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes
int ADL_Overdrive6_State_Reset ( int iAdapterIndex,
                                 int iStateType
                               );


/// Function to set the current Overdrive clock ranges. 
/// 
/// This function sets the current Overdrive clock ranges for a specified adapter. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in] iAdapterIndex The ADL index handle of the desired adapter. 
///   [in] iStateType    The power state which will have clock ranges changed. Currently only performance state is supported. Possible Values: ADL_OD6_SETSTATE_PERFORMANCE 
///   [in] lpStateInfo   Pointer to the structure ADLOD6StateInfo containing clock ranges to be set. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes
int ADL_Overdrive6_State_Set ( int               iAdapterIndex,
                               int               iStateType,
                               ADLOD6StateInfo * lpStateInfo
                             );


/// Function to retrieve the current or default Overdrive extension clock ranges. 
/// 
/// This function retrieves the current or default Overdrive extension clock ranges for a specified adapter. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in]     iAdapterIndex The ADL index handle of the desired adapter. 
///   [in]     iStateType    Specifies if default or current clock ranges for the power state will be retrieved. Currently only performance state is supported. Possible Values: ADL_OD6_GETSTATEINFO_DEFAULT_PERFORMANCE, ADL_OD6_GETSTATEINFO_CUSTOM_PERFORMANCE, ADL_OD6_GETSTATEINFO_CURRENT 
///   [in,out] lpStateInfo   Pointer to the retrieved clock range info structure ADLOD6StateEx. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes
int ADL_Overdrive6_StateEx_Get ( int             iAdapterIndex,
                                 int             iStateType,
                                 ADLOD6StateEx * lpODState
                               );


/// Function to set the current Overdrive extension clock ranges. 
/// 
/// This function sets the current Overdrive extension clock ranges for a specified adapter. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in] iAdapterIndex The ADL index handle of the desired adapter. 
///   [in] iStateType    The power state which will have clock ranges changed. Currently only performance state is supported. Possible Values: ADL_OD6_SETSTATE_PERFORMANCE 
///   [in] lpStateInfo   Pointer to the structure ADLOD6StateEx containing clock ranges to be set. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes
int ADL_Overdrive6_StateEx_Set ( int             iAdapterIndex,
                                 int             iStateType,
                                 ADLOD6StateEx * lpODState
                               );


/// Function to retrieve the current or default Overdrive clock ranges. 
/// 
/// This function retrieves the current or default Overdrive clock ranges for a specified adapter. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in]     iAdapterIndex The ADL index handle of the desired adapter. 
///   [in]     iStateType    Specifies if default or current clock ranges for the power state will be retrieved. Currently only performance state is supported. Possible Values: ADL_OD6_GETSTATEINFO_DEFAULT_PERFORMANCE, ADL_OD6_GETSTATEINFO_CUSTOM_PERFORMANCE, ADL_OD6_GETSTATEINFO_CURRENT 
///   [in,out] lpStateInfo   Pointer to the retrieved clock range info structure ADLOD6StateInfo. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes
int ADL_Overdrive6_StateInfo_Get ( int               iAdapterIndex,
                                   int               iStateType,
                                   ADLOD6StateInfo * lpStateInfo
                                 );


/// Function returns default target temperature and current temp. value of the specified adapter. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in]  iAdapterIndex  The ADL index handle of the desired adapter. 
///   [out] lpDefaultValue a pointer to an int that will contain default temperature value for specified adapter. 
///   [out] lpCurrentValue a pointer to an int that will contain current temperature value for specified adapter. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code.
int ADL_Overdrive6_TargetTemperatureData_Get ( int   iAdapterIndex,
                                               int * lpCurrentValue,
                                               int * lpDefaultValue
                                             );


/// Function changes the target temperature current value of the specified adapter . 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in]  iAdapterIndex The ADL index handle of the desired adapter. 
///   [out] iCurrentValue int value containing new temperature value to apply for specified adapter. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code.
int ADL_Overdrive6_TargetTemperatureData_Set ( int iAdapterIndex,
                                               int iCurrentValue
                                             );


/// Function returns the target temperature range of the specified adapter . 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in]  iAdapterIndex           The ADL index handle of the desired adapter. 
///   [out] lpTargetTemperatureInfo a pointer to an ADLOD6ParameterRange structure containing acceptable temperature range to work with. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code.
int ADL_Overdrive6_TargetTemperatureRangeInfo_Get ( int                    iAdapterIndex,
                                                    ADLOD6ParameterRange * lpTargetTemperatureInfo
                                                  );


/// Function to retrieve GPU temperature from the thermal controller. 
/// 
/// This function retrieves GPU temperature from the thermal controller for a specified adapter. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in]     iAdapterIndex The ADL index handle of the desired adapter. 
///   [in,out] lpTemperature The pointer to the retrieved temperature. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes
int ADL_Overdrive6_Temperature_Get ( int   iAdapterIndex,
                                     int * lpTemperature
                                   );


/// Function to retrieve capabilities of the GPU thermal controller. 
/// 
/// This function retrieves GPU thermal controller capabilities for a specified adapter. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in]     iAdapterIndex           The ADL index handle of the desired adapter. 
///   [in,out] lpThermalControllerInfo The pointer to the ADLThermalControllerInfo structure storing the retrieved GPU thermal controller information. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes
int ADL_Overdrive6_ThermalController_Caps ( int                           iAdapterIndex,
                                            ADLOD6ThermalControllerCaps * lpThermalControllerCaps
                                          );


/// Function to retrieve the current Thermal Limit Unlock feature status. 
/// 
/// This function to retrieve the current Thermal Limit Unlock feature status. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in]  context       Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in]  iAdapterIndex The ADL index handle of the desired adapter. 
///   [in]  iStateType    The power state which will have clock ranges changed. Currently only performance state is supported. Possible Values: ADL_OD6_SETSTATE_PERFORMANCE 
///   [out] pEnable       a pointer to an int containing the current TLU status. Possible Values: 1 - Enable TLU, 0 - Disable TLU. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes
int ADL_Overdrive6_ThermalLimitUnlock_Get ( int   iAdapterIndex,
                                            int   iStateType,
                                            int * pEnabled
                                          );


/// Function to enable the current Thermal Limit Unlock feature. 
/// 
/// This function enable the current Thermal Limit Unlock feature. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in] context       Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in] iAdapterIndex The ADL index handle of the desired adapter. 
///   [in] iStateType    The power state which will have clock ranges changed. Currently only performance state is supported. Possible Values: ADL_OD6_SETSTATE_PERFORMANCE 
///   [in] iEnable       1 - Enable TLU, 0 - Disable TLU. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes
int ADL_Overdrive6_ThermalLimitUnlock_Set ( int iAdapterIndex,
                                            int iStateType,
                                            int iEnable
                                          );


/// Function to get the current and default VoltageControl adjustment values. 
/// 
/// This function returns the current and default VoltageControl adjustment values for the specified adapter. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in]  iAdapterIndex  The ADL index handle of the desired adapter. 
///   [out] lpCurrentValue pointer to the current VoltageControl adjustment value. 
///   [out] lpDefaultValue pointer to the default VoltageControl adjustment value. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code.
int ADL_Overdrive6_VoltageControl_Get ( int   iAdapterIndex,
                                        int * lpCurrentValue,
                                        int * lpDefaultValue
                                      );


/// Function to set the current VoltageControl adjustment value. 
/// 
/// This function sets the current VoltageControl adjustment value. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in] iAdapterIndex The ADL index handle of the desired adapter. 
///   [in] iValue        The new VoltageControl adjustment value to be set. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code.
int ADL_Overdrive6_VoltageControl_Set ( int iAdapterIndex,
                                        int iValue
                                      );


/// Function to get the VoltageControl adjustment range. 
/// 
/// This function returns the VoltageControl adjustment range for the specified adapter. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in]     iAdapterIndex        The ADL index handle of the desired adapter. 
///   [in,out] lpVoltageControlInfo The pointer to the ADLOD6VoltageControlInfo returning the VoltageControl adjustment range. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code.
int ADL_Overdrive6_VoltageControlInfo_Get ( int                        iAdapterIndex,
                                            ADLOD6VoltageControlInfo * lpVoltageControlInfo
                                          );


#endif /* ADL_HEADER_OVERDRIVE6_H_ */
