#ifndef ADL_HEADER_OVERDRIVEN_H_
#define ADL_HEADER_OVERDRIVEN_H_

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

/// Function to retrieve the Custom Fan support. 
/// 
/// This function retrieves the support of Custom Fan for a specified adapter. 
/// Supported Platforms:
///   Windows 7, 10 and above; 32bit and 64bit 
/// 
/// Parameters
///   [in]  context        Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in]  iAdapterIndex  The ADL index handle of the desired adapter. 
///   [out] lpSupported,if Custom Fan Supported : True else false . 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes
int ADL2_CustomFan_Caps ( ADL_CONTEXT_HANDLE context,
                          int                iAdapterIndex,
                          int *              lpSupported
                        );


/// Function to retrieve the Custom Fan current status. 
/// 
/// This function retrieves the current status of Custom Fan for a specified adapter. 
/// Supported Platforms:
///   Windows 7, 10 and above; 32bit and 64bit 
/// 
/// Parameters
///   [in]  context                Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in]  iAdapterIndex          The ADL index handle of the desired adapter. 
///   [out] lpODFanControl,returns current status of the fan control. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes
int ADL2_CustomFan_Get ( ADL_CONTEXT_HANDLE context,
                         int                iAdapterIndex,
                         ADLODNFanControl * lpODFanControl
                       );


/// Function to set the Custom Fan status. 
/// 
/// This function sets the current status of Custom Fan for a specified adapter. 
/// Supported Platforms:
///   Windows 7, 10 and above; 32bit and 64bit 
/// 
/// Parameters
///   [in] context       Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in] iAdapterIndex The ADL index handle of the desired adapter. 
///   [in] iCurrent,if   autowattman enabled : 1 else 0 . 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes
int ADL2_CustomFan_Set ( ADL_CONTEXT_HANDLE context,
                         int                iAdapterIndex,
                         ADLODNFanControl * lpODFanControl
                       );


/// This function retrieves the support of Auto wattman for a specified adapter. 
/// Supported Platforms:
///   Windows 7, 10 and above; 32bit and 64bit 
/// 
/// Parameters
///   [in]  context           Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in]  iAdapterIndex     The ADL index handle of the desired adapter. 
///   [out] lpSupported,if    autowattman Supported : True else false . 
///   [out] lpDefault,default autowattman value 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes
int ADL2_OverdriveN_AutoWattman_Caps ( ADL_CONTEXT_HANDLE context,
                                       int                iAdapterIndex,
                                       int *              lpSupported,
                                       int *              lpDefault
                                     );


/// This function retrieves the current status of Auto wattman for a specified adapter. 
/// Supported Platforms:
///   Windows 7, 10 and above; 32bit and 64bit 
/// 
/// Parameters
///   [in]  context       Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in]  iAdapterIndex The ADL index handle of the desired adapter. 
///   [out] lpCurrent,if  autowattman enabled : 1 else 0 . 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes
int ADL2_OverdriveN_AutoWattman_Get ( ADL_CONTEXT_HANDLE context,
                                      int                iAdapterIndex,
                                      int *              lpCurrent
                                    );


/// This function sets the current status of Auto wattman for a specified adapter. 
/// Supported Platforms:
///   Windows 7, 10 and above; 32bit and 64bit 
/// 
/// Parameters
///   [in] context       Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in] iAdapterIndex The ADL index handle of the desired adapter. 
///   [in] iCurrent,if   autowattman enabled : 1 else 0 . 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes
int ADL2_OverdriveN_AutoWattman_Set ( ADL_CONTEXT_HANDLE context,
                                      int                iAdapterIndex,
                                      int                iCurrent
                                    );


/// 
int ADL2_OverdriveN_Capabilities_Get ( ADL_CONTEXT_HANDLE   context,
                                       int                  iAdapterIndex,
                                       ADLODNCapabilities * lpODCapabilities
                                     );


/// Function to retrieve the OverdriveN capabilities. 
/// 
/// This function retrieves the OverdriveN capabilities for a specified adapter. 
/// Supported Platforms:
///   Windows 7, 10 and above; 32bit and 64bit 
/// 
/// Parameters
///   [in]  context          Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in]  iAdapterIndex    The ADL index handle of the desired adapter. 
///   [out] lpODCapabilities The pointer to the ADLODNCapabilitiesX2 structure storing the retrieved Overdrive parameters. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes 
/// 
/// Remarks
///   Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call ADL2_Main_Control_Create first to obtain ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using ADL2_Main_Control_Destroy.
int ADL2_OverdriveN_CapabilitiesX2_Get ( ADL_CONTEXT_HANDLE     context,
                                         int                    iAdapterIndex,
                                         ADLODNCapabilitiesX2 * lpODCapabilities
                                       );


/// This function retrieves the events counts for a specified adapter. works on earlier OD versions also. 
/// Supported Platforms:
///   Windows 7, 10 and above; 32bit and 64bit 
/// 
/// Parameters
///   [in]  context          Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in]  iAdapterIndex    The ADL index handle of the desired adapter. 
///   [in]  eventcounterType Event counter type: Thermal event = 0;VPU recovery =1. 
///   [out] eventCount,The   number of events occured. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes 
/// 
/// Remarks
///   Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call ADL2_Main_Control_Create first to obtain ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using ADL2_Main_Control_Destroy.
int ADL2_OverdriveN_CountOfEvents_Get ( ADL_CONTEXT_HANDLE context,
                                        int                iAdapterIndex,
                                        int                eventcounterType,
                                        int *              eventCount
                                      );


/// Function to retrieve the current Fan control settings. 
/// 
/// This function retrieves the current fan for a specified adapter. 
/// Supported Platforms:
///   Windows 7, 10 and above; 32bit and 64bit 
/// 
/// Parameters
///   [in]  context       Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in]  iAdapterIndex The ADL index handle of the desired adapter. 
///   [out] lpOdFanSpeed  The pointer to the ADLODNFanControl structure storing the retrieved Overdrive parameters. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes 
/// 
/// Remarks
///   Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call ADL2_Main_Control_Create first to obtain ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using ADL2_Main_Control_Destroy.
int ADL2_OverdriveN_FanControl_Get ( ADL_CONTEXT_HANDLE context,
                                     int                iAdapterIndex,
                                     ADLODNFanControl * lpODFanSpeed
                                   );


/// Function to set the current Fan controls settings. 
/// 
/// This function applies the current Fan control for a specified adapter. 
/// Supported Platforms:
///   Windows 7, 10 and above; 32bit and 64bit 
/// 
/// Parameters
///   [in] context       Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in] iAdapterIndex The ADL index handle of the desired adapter. 
///   [in] lpOdFanSpeed  The pointer to the ADLODNFanControl structure storing the retrieved Overdrive parameters. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes 
/// 
/// Remarks
///   Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call ADL2_Main_Control_Create first to obtain ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using ADL2_Main_Control_Destroy.
int ADL2_OverdriveN_FanControl_Set ( ADL_CONTEXT_HANDLE context,
                                     int                iAdapterIndex,
                                     ADLODNFanControl * lpODFanControl
                                   );


/// Function to retrieve the current memory clocks settings. 
/// 
/// This function retrieves the current memory clocks for a specified adapter. 
/// Supported Platforms:
///   Windows 7, 10 and above; 32bit and 64bit 
/// 
/// Parameters
///   [in]  context               Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in]  iAdapterIndex         The ADL index handle of the desired adapter. 
///   [out] lpODPerformanceLevels The pointer to the ADLODNPerformanceLevels structure storing the retrieved Overdrive parameters. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes 
/// 
/// Remarks
///   Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call ADL2_Main_Control_Create first to obtain ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using ADL2_Main_Control_Destroy. 
/// Deprecated:
///   This API has been deprecated.
int ADL2_OverdriveN_MemoryClocks_Get ( ADL_CONTEXT_HANDLE        context,
                                       int                       iAdapterIndex,
                                       ADLODNPerformanceLevels * lpODPerformanceLevels
                                     );


/// Function to sets the current memory clocks settings. 
/// 
/// This function applies the current memory clocks for a specified adapter. 
/// Supported Platforms:
///   Windows 7, 10 and above; 32bit and 64bit 
/// 
/// Parameters
///   [in] context               Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in] iAdapterIndex         The ADL index handle of the desired adapter. 
///   [in] lpODPerformanceLevels The pointer to the ADLODNPerformanceLevels structure to set the data to driver. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes 
/// 
/// Remarks
///   Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call ADL2_Main_Control_Create first to obtain ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using ADL2_Main_Control_Destroy. 
/// Deprecated:
///   This API has been deprecated.
int ADL2_OverdriveN_MemoryClocks_Set ( ADL_CONTEXT_HANDLE        context,
                                       int                       iAdapterIndex,
                                       ADLODNPerformanceLevels * lpODPerformanceLevels
                                     );


/// Function to retrieve the current memory clocks settings. 
/// 
/// This function retrieves the current memory clocks for a specified adapter. 
/// Supported Platforms:
///   Windows 7, 10 and above; 32bit and 64bit 
/// 
/// Parameters
///   [in]  context               Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in]  iAdapterIndex         The ADL index handle of the desired adapter. 
///   [out] lpODPerformanceLevels The pointer to the ADLODNPerformanceLevels structure storing the retrieved Overdrive parameters. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes 
/// 
/// Remarks
///   Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call ADL2_Main_Control_Create first to obtain ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using ADL2_Main_Control_Destroy.
int ADL2_OverdriveN_MemoryClocksX2_Get ( ADL_CONTEXT_HANDLE          context,
                                         int                         iAdapterIndex,
                                         ADLODNPerformanceLevelsX2 * lpODPerformanceLevels
                                       );


/// Function to sets the current memory clocks settings. 
/// 
/// This function applies the current memory clocks for a specified adapter. 
/// Supported Platforms:
///   Windows 7, 10 and above; 32bit and 64bit 
/// 
/// Parameters
///   [in] context               Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in] iAdapterIndex         The ADL index handle of the desired adapter. 
///   [in] lpODPerformanceLevels The pointer to the ADLODNPerformanceLevels structure to set the data to driver. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes 
/// 
/// Remarks
///   Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call ADL2_Main_Control_Create first to obtain ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using ADL2_Main_Control_Destroy.
int ADL2_OverdriveN_MemoryClocksX2_Set ( ADL_CONTEXT_HANDLE          context,
                                         int                         iAdapterIndex,
                                         ADLODNPerformanceLevelsX2 * lpODPerformanceLevels
                                       );


/// Function to retrieve the memory timing . 
/// 
/// This function enables/disables memory timing for a specified adapter. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in]  context         Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in]  iAdapterIndex   The ADL index handle of the desired adapter. 
///   [out] lpSupport       an integer ponter of memory timing support flag. If blockchain mode supported, the value is 1, otherwise it is 0. 
///   [out] lpCurrrentValue an integer ponter of blockchain mode currrent state. If blockchain mode is enabled, the value is 1, otherwise it is 0. 
///   [out] lpDfaultValue   an integer ponter of blockchain mode default state. If default blockchain mode is enabled, the value is 1, otherwise it is 0. 
///   [out] lpNumberLevels  an integer ponter of pointer of memory timing levels, which stores all memory levels. 
///   [out] lppLevelList    an integer ponter of memory timing levels. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes///
int ADL2_OverdriveN_MemoryTimingLevel_Get ( ADL_CONTEXT_HANDLE context,
                                            int                iAdapterIndex,
                                            int *              lpSupport,
                                            int *              lpCurrentValue,
                                            int *              lpDefaultValue,
                                            int *              lpNumberLevels,
                                            int **             lppLevelList
                                          );


/// Function to change memory timing levels. 
/// 
/// This function set GPU memory timing level for a specified adapter. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in]  context       Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in]  iAdapterIndex The ADL index handle of the desired adapter. 
///   [out] currentValue  is an integer of GPU memory timing level. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes///
int ADL2_OverdriveN_MemoryTimingLevel_Set ( ADL_CONTEXT_HANDLE context,
                                            int                iAdapterIndex,
                                            int                currentValue
                                          );


/// Function to retrieve the current OD performance status. 
/// 
/// This function retrieves the current OD performance for a specified adapter. 
/// Supported Platforms:
///   Windows 7, 10 and above; 32bit and 64bit 
/// 
/// Parameters
///   [in]  context               Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in]  iAdapterIndex         The ADL index handle of the desired adapter. 
///   [out] lpOdPerformanceStatus The pointer to the ADLODNPerformanceStatus structure storing the retrieved Overdrive parameters. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes 
/// 
/// Remarks
///   Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call ADL2_Main_Control_Create first to obtain ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using ADL2_Main_Control_Destroy.
int ADL2_OverdriveN_PerformanceStatus_Get ( ADL_CONTEXT_HANDLE        context,
                                            int                       iAdapterIndex,
                                            ADLODNPerformanceStatus * lpODPerformanceStatus
                                          );


/// Function to retrieve the current power limit settings. 
/// 
/// This function retrieves the current power limit for a specified adapter. 
/// Supported Platforms:
///   Windows 7, 10 and above; 32bit and 64bit 
/// 
/// Parameters
///   [in]  context        Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in]  iAdapterIndex  The ADL index handle of the desired adapter. 
///   [out] lpOdPowerLimit The pointer to the ADLODPowerLimitSetting structure storing the retrieved Overdrive parameters. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes 
/// 
/// Remarks
///   Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call ADL2_Main_Control_Create first to obtain ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using ADL2_Main_Control_Destroy.
int ADL2_OverdriveN_PowerLimit_Get ( ADL_CONTEXT_HANDLE        context,
                                     int                       iAdapterIndex,
                                     ADLODNPowerLimitSetting * lpODPowerLimit
                                   );


/// Function to sets the current power limit settings. 
/// 
/// This function retrieves the current power limit for a specified adapter. 
/// Supported Platforms:
///   Windows 7, 10 and above; 32bit and 64bit 
/// 
/// Parameters
///   [in] context        Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in] iAdapterIndex  The ADL index handle of the desired adapter. 
///   [in] lpOdPowerLimit The pointer to the ADLODPowerLimitSetting structure storing the retrieved Overdrive parameters. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes 
/// 
/// Remarks
///   Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call ADL2_Main_Control_Create first to obtain ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using ADL2_Main_Control_Destroy.
int ADL2_OverdriveN_PowerLimit_Set ( ADL_CONTEXT_HANDLE        context,
                                     int                       iAdapterIndex,
                                     ADLODNPowerLimitSetting * lpODPowerLimit
                                   );


/// This function retrieves the OverdriveN SCLK Auto overclock for a specified adapter. 
/// Supported Platforms:
///   Windows 7, 10 and above; 32bit and 64bit 
/// 
/// Parameters
///   [in] context       Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in] iAdapterIndex The ADL index handle of the desired adapter. 
///   [in] lpStatus      Auto overclock state ADL_TRUE ADL_FALSE 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes 
/// 
/// Remarks
///   Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call ADL2_Main_Control_Create first to obtain ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using ADL2_Main_Control_Destroy.
int ADL2_OverdriveN_SCLKAutoOverClock_Get ( ADL_CONTEXT_HANDLE context,
                                            int                iAdapterIndex,
                                            int *              lpStatus
                                          );


/// This function retrieves the OverdriveN SCLK Auto overclock state for a specified adapter. 
/// Supported Platforms:
///   Windows 7, 10 and above; 32bit and 64bit 
/// 
/// Parameters
///   [in] context       Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in] iAdapterIndex The ADL index handle of the desired adapter. 
///   [in] iStatus       Auto overclock state ADL_TRUE ADL_FALSE 
///        [in/out]      iFlags. this has two meanings. input: when reseting AOC, need to ODNControlType_Default; output: Auto overclock needs reboot or not; flags 0 or 1 - reboot required 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes 
/// 
/// Remarks
///   Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call ADL2_Main_Control_Create first to obtain ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using ADL2_Main_Control_Destroy.
int ADL2_OverdriveN_SCLKAutoOverClock_Set ( ADL_CONTEXT_HANDLE context,
                                            int                iAdapterIndex,
                                            int                iStatus,
                                            int *              iFlags
                                          );


/// Function to get Fan curve info. 
/// 
/// This function to retrieve Fan curve for a specified adapter. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in]  context                  Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in]  iAdapterIndex            The ADL index handle of the desired adapter. 
///   [out] lpOverdriveNCapabilities The pointer to the bit-vector which indicates wich ODN feature is supported. ///
///   [out] lpNumberPoints           an integer ponter of Fan curve points. 
///         [in/out]                 lpNumberOfODNExtFeatures The pointer to an integer which indicates the number of ODN features. The callee shold input the expected number of features. Then ADL can use this input to support comptiable. When returing, the number is actual number of dricver currently supported features 
///   [out] lpInitSettingList        The pointer to the list of current ODN Ext settingts. 
///   [out] lppInitSettingList       The pointer to the list of current ODN Ext range of settingts. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes
int ADL2_OverdriveN_SettingsExt_Get ( ADL_CONTEXT_HANDLE            context,
                                      int                           iAdapterIndex,
                                      int *                         lpOverdriveNExtCapabilities,
                                      int *                         lpNumberOfODNExtFeatures,
                                      ADLODNExtSingleInitSetting ** lppInitSettingList,
                                      int **                        lppCurrentSettingList
                                    );


/// Function to set fan curve (temperature and speed) 
/// 
/// This function to for set fan curve (temperature and speed) a specified adapter. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in] context                 Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in] iAdapterIndex           The ADL index handle of the desired adapter. 
///   [in] iNumberOfODNExtFeatures An integer which indicates the number of ODN features. 
///   [in] lpItemValueValidList    an integer pointer which indicates which element in lpItemValueList is valid 
///   [in] lpItemValueList         an integer pointer which indicate the current value 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes
int ADL2_OverdriveN_SettingsExt_Set ( ADL_CONTEXT_HANDLE context,
                                      int                iAdapterIndex,
                                      int                iNumberOfODNExtFeatures,
                                      int *              itemValueValidList,
                                      int *              lpItemValueList
                                    );


/// Function to retrieve the current GPU clocks settings. 
/// 
/// This function retrieves the current GPU clocks for a specified adapter. 
/// Supported Platforms:
///   Windows 7, 10 and above; 32bit and 64bit 
/// 
/// Parameters
///   [in]  context               Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in]  iAdapterIndex         The ADL index handle of the desired adapter. 
///   [out] lpODPerformanceLevels The pointer to the ADLODNPerformanceLevels structure storing the retrieved data. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes 
/// 
/// Remarks
///   Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call ADL2_Main_Control_Create first to obtain ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using ADL2_Main_Control_Destroy. 
/// Deprecated:
///   This API has been deprecated.
int ADL2_OverdriveN_SystemClocks_Get ( ADL_CONTEXT_HANDLE        context,
                                       int                       iAdapterIndex,
                                       ADLODNPerformanceLevels * lpODPerformanceLevels
                                     );


/// Function to sets the current GPU clocks settings. 
/// 
/// This function applies the current GPU clocks for a specified adapter. 
/// Supported Platforms:
///   Windows 7, 10 and above; 32bit and 64bit 
/// 
/// Parameters
///   [in] context               Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in] iAdapterIndex         The ADL index handle of the desired adapter. 
///   [in] lpODPerformanceLevels The pointer to the ADLODNPerformanceLevels structure to set the data to driver. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes 
/// 
/// Remarks
///   Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call ADL2_Main_Control_Create first to obtain ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using ADL2_Main_Control_Destroy. 
/// Deprecated:
///   This API has been deprecated.
int ADL2_OverdriveN_SystemClocks_Set ( ADL_CONTEXT_HANDLE        context,
                                       int                       iAdapterIndex,
                                       ADLODNPerformanceLevels * lpODPerformanceLevels
                                     );


/// Function to retrieve the current GPU clocks settings. 
/// 
/// This function retrieves the current GPU clocks for a specified adapter. 
/// Supported Platforms:
///   Windows 7, 10 and above; 32bit and 64bit 
/// 
/// Parameters
///   [in]  context               Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in]  iAdapterIndex         The ADL index handle of the desired adapter. 
///   [out] lpODPerformanceLevels The pointer to the ADLODNPerformanceLevels structure storing the retrieved data. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes 
/// 
/// Remarks
///   Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call ADL2_Main_Control_Create first to obtain ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using ADL2_Main_Control_Destroy.
int ADL2_OverdriveN_SystemClocksX2_Get ( ADL_CONTEXT_HANDLE          context,
                                         int                         iAdapterIndex,
                                         ADLODNPerformanceLevelsX2 * lpODPerformanceLevels
                                       );


/// Function to sets the current GPU clocks settings. 
/// 
/// This function applies the current GPU clocks for a specified adapter. 
/// Supported Platforms:
///   Windows 7, 10 and above; 32bit and 64bit 
/// 
/// Parameters
///   [in] context               Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in] iAdapterIndex         The ADL index handle of the desired adapter. 
///   [in] lpODPerformanceLevels The pointer to the ADLODNPerformanceLevels structure to set the data to driver. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes 
/// 
/// Remarks
///   Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call ADL2_Main_Control_Create first to obtain ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using ADL2_Main_Control_Destroy.
int ADL2_OverdriveN_SystemClocksX2_Set ( ADL_CONTEXT_HANDLE          context,
                                         int                         iAdapterIndex,
                                         ADLODNPerformanceLevelsX2 * lpODPerformanceLevels
                                       );


/// Function to retrieve the current temperture. 
/// 
/// This function retrieves the current temperature for a specified adapter. 
/// Supported Platforms:
///   Windows 7, 10 and above; 32bit and 64bit 
/// 
/// Parameters
///   [in]  context                      Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in]  iAdapterIndex                The ADL index handle of the desired adapter. 
///   [in]  iTemperatureType,temperature type. ADLODNTemperatureType 
///   [out] iTemperature                 The integer pointer, storing the retrieved Overdrive parameters. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes 
/// 
/// Remarks
///   Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call ADL2_Main_Control_Create first to obtain ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using ADL2_Main_Control_Destroy.
int ADL2_OverdriveN_Temperature_Get ( ADL_CONTEXT_HANDLE context,
                                      int                iAdapterIndex,
                                      int                iTemperatureType,
                                      int *              iTemperature
                                    );


/// Supported Platforms:
///   Windows 7, 10 and above; 32bit and 64bit 
/// 
/// Parameters
///   [in] context       Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in] iAdapterIndex The index of the desired adapter. 
///   [in] iEnabled      ADL_TRUE ADL_FALSE 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK (zero). Otherwise the return value is an ADL error code (non-zero). Result Codes
/// 
/// Remarks
///   Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call ADL2_Main_Control_Create first to obtain ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using ADL2_Main_Control_Destroy.
int ADL2_OverdriveN_Test_Set ( ADL_CONTEXT_HANDLE context,
                               int                iAdapterIndex,
                               int                iEnabled
                             );


/// This function retrieves the OverdriveN Throttle Notification for a specified adapter. 
/// Supported Platforms:
///   Windows 7, 10 and above; 32bit and 64bit 
/// 
/// Parameters
///   [in] context         Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in] iAdapterIndex   The ADL index handle of the desired adapter. 
///   [in] lpStatus        Throttle Notification state ADL_TRUE ADL_FALSE 
///   [in] lpThrottleFlags Throttle Notification flags ADL_ODN_THROTTLE_NOTIFICATION, which tells the reason for low performance 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes 
/// 
/// Remarks
///   Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call ADL2_Main_Control_Create first to obtain ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using ADL2_Main_Control_Destroy.
int ADL2_OverdriveN_ThrottleNotification_Get ( ADL_CONTEXT_HANDLE context,
                                               int                iAdapterIndex,
                                               int *              lpStatus,
                                               int *              lpThrottleFlags
                                             );


/// Function to get zero RPM fan control info. 
/// 
/// This function to retrieve zero RPM fan control for a specified adapter. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in]  context         Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in]  iAdapterIndex   The ADL index handle of the desired adapter. 
///   [out] lpSupport       an integer ponter of zero RMP fan control support flag. If zero RPM fan control supported, the value is 1, otherwise it is 0. 
///   [out] lpCurrrentValue an integer ponter of zero RMP fan control currrent state. If zero RPM fan control is enabled, the value is 1, otherwise it is 0. 
///   [out] lpDfaultValue   an integer ponter of zero RMP fan control default state. If zero RPM fan control is enabled, the value is 1, otherwise it is 0. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes///
int ADL2_OverdriveN_ZeroRPMFan_Get ( ADL_CONTEXT_HANDLE context,
                                     int                iAdapterIndex,
                                     int *              lpSupport,
                                     int *              lpCurrentValue,
                                     int *              lpDefaultValue
                                   );


/// Function to change Zero RPM control levels. 
/// 
/// This function set GPU Zero RPM cntrol level for a specified adapter. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in]  context       Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in]  iAdapterIndex The ADL index handle of the desired adapter. 
///   [out] currentValue  is an integer of GPU Zero RPM cntrol level. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes///
int ADL2_OverdriveN_ZeroRPMFan_Set ( ADL_CONTEXT_HANDLE context,
                                     int                iAdapterIndex,
                                     int                currentValue
                                   );


#endif /* ADL_HEADER_OVERDRIVEN_H_ */
