#ifndef ADL_HEADER_OVERDRIVE8_H_
#define ADL_HEADER_OVERDRIVE8_H_

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

/// Function to query individual limits of power management logging. 
/// 
/// This function implements a call to query power management logging limits. 
/// Supported Platforms:
///   Windows Vista and Windows 7; 32bit and 64bit 
/// 
/// Parameters
///   [in]  context       Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in]  iAdapterIndex The ADL index handle of the desired adapter. 
///   [out] lpDataOutput  The pointer to PMLog sensor limits ADLPMLogSensorLimits. 
/// 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK, or an ADL error code otherwise. Result Codes
int ADL2_Adapter_PMLog_SensorLimits_Get ( ADL_CONTEXT_HANDLE     context,
                                          int                    iAdapterIndex,
                                          ADLPMLogSensorLimits * lpDataOutput
                                        );


/// Function to start power management logging. 
/// 
/// This function implements a call to start power management logging. 
/// Supported Platforms:
///   Windows Vista and Windows 7; 32bit and 64bit 
/// 
/// Parameters
///   [in]  context             Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in]  iAdapterIndex       The ADL index handle of the desired adapter. 
///   [in]  pPMLogStartInput    The pointer to ADLPMLogStartInput describing which sensors to log 
///   [out] ADLPMLogStartOutput The pointer to ADLPMLogStartOutput, returning an address where log data is stored 
///   [in]  hDevice             The D3D device handle associate with the logging session. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK, or an ADL error code otherwise. Result Codes
int ADL2_Adapter_PMLog_Start ( ADL_CONTEXT_HANDLE    context,
                               int                   iAdapterIndex,
                               ADLPMLogStartInput *  pPMLogStartInput,
                               ADLPMLogStartOutput * pPMLogStartOutput,
                               ADL_D3DKMT_HANDLE     hDevice
                             );


/// Function to stop power management logging. 
/// 
/// This function implements a call to stop power management logging. 
/// Supported Platforms:
///   Windows Vista and Windows 7; 32bit and 64bit 
/// 
/// Parameters
///   [in] context       Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in] iAdapterIndex The ADL index handle of the desired adapter. 
///   [in] hDevice       The D3D device handle associate with the logging session. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK, or an ADL error code otherwise. Result Codes
int ADL2_Adapter_PMLog_Stop ( ADL_CONTEXT_HANDLE context,
                              int                iAdapterIndex,
                              ADL_D3DKMT_HANDLE  hDevice
                            );


/// Function to retrieve power management logging support. 
/// 
/// This function implements a call to retrieve power management logging support. 
/// Supported Platforms:
///   Windows Vista and Windows 7; 32bit and 64bit 
/// 
/// Parameters
///   [in]  context           Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in]  iAdapterIndex     The ADL index handle of the desired adapter. 
///   [out] pPMLogSupportInfo The pointer to PMLog support info. 
/// 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK, or an ADL error code otherwise. Result Codes
int ADL2_Adapter_PMLog_Support_Get ( ADL_CONTEXT_HANDLE    context,
                                     int                   iAdapterIndex,
                                     ADLPMLogSupportInfo * pPMLogSupportInfo
                                   );


/// Function to retrieve the current auto tuning state. 
/// 
/// This function retrieves the Overdrive8 auto tuning settings for a specified adapter. 
/// Supported Platforms:
///   Windows 7, 10 and above; 32bit and 64bit 
/// 
/// Parameters
///   [in]  context       Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in]  iAdapterIndex The ADL index handle of the desired adapter. 
///   [out] lpDataOutput  The pointer to an bool which indicates the auto tuning state 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes
int ADL2_AutoTuningResult_Get ( ADL_CONTEXT_HANDLE context,
                                int                iAdapterIndex,
                                bool *             lpDataOutput
                              );


/// This function create the device. Adds MGPU support over legacy functions. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in]  context       Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in]  iAdapterIndex The ADL index handle of the desired desktop. 
///   [out] pDevice       The pointer to the device handle. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes
int ADL2_Device_PMLog_Device_Create ( ADL_CONTEXT_HANDLE  context,
                                      int                 iAdapterIndex,
                                      ADL_D3DKMT_HANDLE * pDevice
                                    );


/// This function destroy the device. Adds MGPU support over legacy functions. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in] context Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in] hDevice The device handle. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes
int ADL2_Device_PMLog_Device_Destroy ( ADL_CONTEXT_HANDLE context,
                                       ADL_D3DKMT_HANDLE  hDevice
                                     );


/// Function to retrieve the Overdrive8 current settings. 
/// 
/// This function retrieves the Overdrive8 current settings for a specified adapter. 
/// Supported Platforms:
///   Windows 7, 10 and above; 32bit and 64bit 
/// 
/// Parameters
///   [in]  context       Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in]  iAdapterIndex The ADL index handle of the desired adapter. 
///   [out] lpDataOutput  The pointer to the ADLPMLogDataOutput structure storing the retrieved performance metrics parameters. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes 
/// 
/// Deprecated:
///   This API has been deprecated.
int ADL2_New_QueryPMLogData_Get ( ADL_CONTEXT_HANDLE   context,
                                  int                  iAdapterIndex,
                                  ADLPMLogDataOutput * lpDataOutput
                                );


/// Function to retrieve the Overdrive8 current settings. 
/// 
/// This function retrieves the Overdrive8 current settings for a specified adapter. 
/// Supported Platforms:
///   Windows 7, 10 and above; 32bit and 64bit 
/// 
/// Parameters
///   [in]  context          Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in]  iAdapterIndex    The ADL index handle of the desired adapter. 
///   [out] lpCurrentSetting The pointer to the current settings structure storing the retrieved Overdrive parameters. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes
int ADL2_Overdrive8_Current_Setting_Get ( ADL_CONTEXT_HANDLE     context,
                                          int                    iAdapterIndex,
                                          ADLOD8CurrentSetting * lpCurrentSetting
                                        );


/// Function to retrieve the Overdrive8 current settings. This is new version of ADL2_Overdrive8_Current_SettingX2_Get. It supports new features and does not need to change the API. 
/// 
/// This function retrieves the Overdrive8 current settings for a specified adapter. 
/// Supported Platforms:
///   Windows 7, 10 and above; 32bit and 64bit 
/// 
/// Parameters
///   [in]  context           Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in]  iAdapterIndex     the ADL index handle of the desired adapter. 
///         [in/out]          lpNumberOfFeaturet the pointer to an integer which indicates the number of OD8 features. The callee should input the expected number of features. Then ADL can use this input to support compatible. When returning, the number is actual number of currently supported features by the driver 
///   [out] lpInitSettingList the pointer to the list of current OD8 settings. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes 
/// 
/// Remarks
///   Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process. Such clients have to call ADL2_Main_Control_Create first to obtain ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using ADL2_Main_Control_Destroy.
int ADL2_Overdrive8_Current_SettingX2_Get ( ADL_CONTEXT_HANDLE context,
                                            int                iAdapterIndex,
                                            int *              lpNumberOfFeatures,
                                            int **             lppCurrentSettingList
                                          );


/// Function to retrieve the Overdrive8 current settings. This is new version of ADL2_Overdrive8_Current_SettingX3_Get. It supports the availability of each item. 
/// 
/// This function retrieves the Overdrive8 current settings plus the availability. The availability of each item can be dynamically changed when something happens 
/// Supported Platforms:
///   Windows 7, 10 and above; 32bit and 64bit 
/// 
/// Parameters
///   [in]  context                    Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in]  iAdapterIndex              The ADL index handle of the desired adapter. 
///   [out] lpFeatureNotAdjustableBits The pointer to an integer which's bit indicates the feature can be adjustment now. ref\ADLOD8FeatureControl 
///         [in/out]                   lpNumberOfSettings The pointer to an integer which indicates the number of OD8 features. The callee should input the expected number of settings. Then ADL can use this input to support compatible. When returning, the number is actual number of currently supported features by the driver 
///   [out] lpInitSettingList          The pointer to the list of current OD8 settings. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes 
/// 
/// Remarks
///   Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process. Such cli
int ADL2_Overdrive8_Current_SettingX3_Get ( ADL_CONTEXT_HANDLE context,
                                            int                iAdapterIndex,
                                            int *              lpFeatureNotAdjustableBits,
                                            int *              lpNumberOfSettings,
                                            int **             lppCurrentSettingList,
                                            int                iOption
                                          );


/// 
int ADL2_Overdrive8_Init_Setting_Get ( ADL_CONTEXT_HANDLE  context,
                                       int                 iAdapterIndex,
                                       ADLOD8InitSetting * lpInitSetting
                                     );


/// Function to retrieve the Overdrive8 current range settings. This is new version of ADL2_Overdrive8_Init_Setting_Get. It supports new features and does not need to change the API. 
/// 
/// This function retrieves the Overdrive8 current range settings for a specified adapter. 
/// Supported Platforms:
///   Windows 7, 10 and above; 32bit and 64bit 
/// 
/// Parameters
///   [in]  context                  Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in]  iAdapterIndex            The ADL index handle of the desired adapter. 
///   [out] lpOverdrive8Capabilities the pointer to the bit-vector which indicates which OD8 feature is supported. 
///         [in/out]                 lpNumberOfFeatures the pointer to an integer which indicates the number of OD8 features. The callee should input the expected number of features. Then ADL can use this input to support compatiable. When returning, the number is actual number of currently supported features by the driver 
///   [out] lppInitSettingList       the pointer to the list of current OD8 range of settings. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes
int ADL2_Overdrive8_Init_SettingX2_Get ( ADL_CONTEXT_HANDLE         context,
                                         int                        iAdapterIndex,
                                         int *                      lpOverdrive8Capabilities,
                                         int *                      lpNumberOfFeatures,
                                         ADLOD8SingleInitSetting ** lppInitSettingList
                                       );


/// Function to start a shared memory session. 
/// 
/// This function Let the driver start to create a shared memory to store the sensors real values 
/// Supported Platforms:
///   Windows 7, 10 and above; 32bit and 64bit 
/// 
/// Parameters
///   [in]  context            Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in]  iAdapterIndex      The ADL index handle of the desired adapter. 
///         [IN]               iNumSensor, An integer, which indicates how many sensor will be read 
///         [IN]               lpSensorList A pointer to an integer , which contains a list of sensor's IDs 
///         [IN]               lppSharedMemory A pointer to a pointer , which contains the address of shared memory 
///   [out] ADLPMLogDataOutput A pointer to data structure ADLPMLogDataOutput, which is the sensor real value in it. 
///   [in]  iOption            Integer for extension. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK (zero). Otherwise the return value is an ADL error code (non-zero). Result Codes. If Overdrive feature is not supported, the returned code is ADL_ERR_NOT_SUPPORTED
int ADL2_Overdrive8_PMLog_ShareMemory_Read ( ADL_CONTEXT_HANDLE   context,
                                             int                  iAdapterIndex,
                                             int                  iNumSensor,
                                             int *                lpSensorList,
                                             void **              lppSharedMemory,
                                             ADLPMLogDataOutput * lpDataOutput
                                           );


/// Function to start a shared memory session. 
/// 
/// This function Let the driver start to create a shared memory to store the sensors real values 
/// Supported Platforms:
///   Windows 7, 10 and above; 32bit and 64bit 
/// 
/// Parameters
///   [in]  context               Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in]  iAdapterIndex         The ADL index handle of the desired adapter. 
///   [in]  iSampleRate           An integer which indicates how many milli-seconds the driver needs to refresh the context of the shared memory. The unite is second. 
///   [in]  iNumofPMLogSendorList An integer which indicates how many sensors need to be read. 
///   [in]  lpPMLogSendorList     A pointer to an integer, which include of sensors need to be monitored. 
///   [in]  lpDevice              A pointer to ADL_D3DKMT_HANDLE, which is 3D device handle 
///   [out] lppSharedMemory       A pointer to a pointer , which contains the address of shared memory 
///   [in]  iOption               Integer for extension. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK (zero). Otherwise the return value is an ADL error code (non-zero). Result Codes. If Overdrive feature is not supported, the returned code is ADL_ERR_NOT_SUPPORTED
int ADL2_Overdrive8_PMLog_ShareMemory_Start ( ADL_CONTEXT_HANDLE  context,
                                              int                 iAdapterIndex,
                                              int                 iSampleRate,
                                              int                 iNumofPMLogSendorList,
                                              int *               lpPMLogSendorList,
                                              ADL_D3DKMT_HANDLE * lpHDevice,
                                              void **             lppSharedMemory,
                                              int                 iOption
                                            );


/// Function to stop a shared memory session. 
/// 
/// This function let the driver stop to update shared memory with the sensors real values 
/// Supported Platforms:
///   Windows 7, 10 and above; 32bit and 64bit 
/// 
/// Parameters
///   [in] context       Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in] iAdapterIndex The ADL index handle of the desired adapter. 
///   [in] lpDevice      A pointer to pointer, which contains the address of shared memory 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK (zero). Otherwise the return value is an ADL error code (non-zero). Result Codes. If Overdrive feature is not supported, the returned code is ADL_ERR_NOT_SUPPORTED
int ADL2_Overdrive8_PMLog_ShareMemory_Stop ( ADL_CONTEXT_HANDLE  context,
                                             int                 iAdapterIndex,
                                             ADL_D3DKMT_HANDLE * lpHDevice
                                           );


/// Function to retrieve the support flag, which indicates if the shared memory way is available or not. 
/// 
/// This function retrieves the supporting flag of shared memory way is supported by the driver to read sensor's real value 
/// Supported Platforms:
///   Windows 7, 10 and above; 32bit and 64bit 
/// 
/// Parameters
///   [in]  context       Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in]  iAdapterIndex The ADL index handle of the desired adapter. 
///   [out] lpSupported   The pointer to an int variable which indicates if shared memory reading feature is supported ( ADL_TRUE : supported, ADL_FALSE : not supported) 
///   [in]  iOption       Integer for extension. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK (zero). Otherwise the return value is an ADL error code (non-zero). Result Codes. If Overdrive feature is not supported, the return code is ADL_ERR_NOT_SUPPORTED
int ADL2_Overdrive8_PMLog_ShareMemory_Support ( ADL_CONTEXT_HANDLE context,
                                                int                iAdapterIndex,
                                                int *              lpSupported,
                                                int                option
                                              );


/// Function to retrieve the PMLog sensor range value if the driver supports the sensor. 
/// 
/// This function retrieves the supported sensors range value 
/// Supported Platforms:
///   Windows 7, 10 and above; 32bit and 64bit 
/// 
/// Parameters
///   [in]  context                        Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in]  iAdapterIndex                  The ADL index handle of the desired adapter. 
///   [out] lpNumberOfSupportedSensorRange The pointer to the number of sensors' rang supported. The sensor types defined ADLSensorType 
///   [out] lppSenorRangeCapsList          The pointer to the pointer to the first range supported sensor address. This pointer does not need to be initialized by the user. However, the client needs to free the pointer after. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes
int ADL2_Overdrive8_PMLogSenorRange_Caps ( ADL_CONTEXT_HANDLE         context,
                                           int                        iAdapterIndex,
                                           int *                      lpNumberOfSupportedSensorRange,
                                           ADLOD8SingleInitSetting ** lppSenorRangeCapsList
                                         );


/// Function to retrieve the PMLog sensor real value reading support flag from the driver. 
/// 
/// This function retrieves the supported sensor list, which value can be reading from the driver 
/// Supported Platforms:
///   Windows 7, 10 and above; 32bit and 64bit 
/// 
/// Parameters
///   [in]  context                    Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in]  iAdapterIndex              The ADL index handle of the desired adapter. 
///   [out] lpNumOfSupportedSensorType The pointer to the number of sensors' rang supported. The sensor types defined ADLSensorType 
///   [out] lppSenroTypesList          The pointer to the pointer to the first value-reading supported sensor address. This pointer does not need to be initialized by the user. However, the client needs to free the pointer after. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes
int ADL2_Overdrive8_PMLogSenorType_Support_Get ( ADL_CONTEXT_HANDLE context,
                                                 int                iAdapterIndex,
                                                 int *              lpNumOfSupportedSensorType,
                                                 int **             lppSenroTypesList
                                               );


/// Function to set the Overdrive8 settings. 
/// 
/// This function set the Overdrive8 settings for a specified adapter. 
/// Supported Platforms:
///   Windows 7, 10 and above; 32bit and 64bit 
/// 
/// Parameters
///   [in]  context          Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in]  iAdapterIndex    The ADL index handle of the desired adapter. 
///   [in]  lpSetSetting     The pointer to the current settings structure set by user 
///   [out] lpCurrentSetting The pointer to the current settings structure storing the retrieved Overdrive parameters. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes
int ADL2_Overdrive8_Setting_Set ( ADL_CONTEXT_HANDLE     context,
                                  int                    iAdapterIndex,
                                  ADLOD8SetSetting *     lpSetSetting,
                                  ADLOD8CurrentSetting * lpCurrentSetting
                                );


#endif /* ADL_HEADER_OVERDRIVE8_H_ */
