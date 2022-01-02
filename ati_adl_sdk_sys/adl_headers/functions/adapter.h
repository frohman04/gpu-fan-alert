#ifndef ADL_HEADER_ADAPTER_H_
#define ADL_HEADER_ADAPTER_H_

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

/// Function to check if the GPU is accessible or not at the time of this call. 
/// 
/// Some GPUs enter into various power savings mode when not in use, and during this time, direct access to the GPU can result in failures. Access through proper channels (such as via ADL) always works because the software accounts for the GPU's accessibility. However, direct access outside of authorised mechanisms may fail. Use this API to find out if the GPU is currently accessible or not. If API returns GPU accessible, this status will be maintained for 2 seconds.
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in]  context         Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in]  iAdapterIndex   The ADL index handle of the desired adapter. 
///   [out] lpAccessibility The pointer to an int value which indicates if the adapter is accessible or not (ADL_TRUE : Accessible, ADL_FALSE : Not accessible) 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes 
/// 
/// Remarks
///   Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call ADL2_Main_Control_Create first to obtain ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using ADL2_Main_Control_Destroy.
int ADL2_Adapter_Accessibility_Get ( ADL_CONTEXT_HANDLE context,
                                     int                iAdapterIndex,
                                     int *              lpAccessibility
                                   );


/// This function restores the ACE INF registry defaults. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in] context       Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in] iAdapterIndex The ADL index handle of the desired adapter. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes
int ADL2_Adapter_AceDefaults_Restore ( ADL_CONTEXT_HANDLE context,
                                       int                iAdapterIndex
                                     );


/// Function to determine if the adapter is active or not. 
/// 
/// The function is used to check if the adapter associated with iAdapterIndex is active. Logic is different for Windows and Linux! 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in]  context       Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in]  iAdapterIndex The ADL index handle of the desired adapter. 
///   [out] lpStatus      The pointer to the retrieved status. ADL_TRUE : Active; ADL_FALSE : Disabled. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes 
/// 
/// Remarks
///   Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call ADL2_Main_Control_Create first to obtain ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using ADL2_Main_Control_Destroy.
int ADL2_Adapter_Active_Get ( ADL_CONTEXT_HANDLE context,
                              int                iAdapterIndex,
                              int *              lpStatus
                            );


/// Function to set the current extended desktop mode status for a display. 
/// 
/// This function enables or disables extended desktop mode for a specified display. 
/// Supported Platforms:
///   Windows 7, 10 and above; 32bit and 64bit 
/// 
/// Parameters
///   [in]  context         Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in]  iAdapterIndex   The ADL index handle of the desired adapter. 
///   [in]  iStatus         The desired display extended desktop mode status. ADL_TRUE : extended desktop mode; ADL_FALSE : otherwise. 
///   [out] lpNewlyActivate The pointer to the retrieved adapter activation information. ADL_TRUE : the adapter is activated for the first time; ADL_FALSE : otherwise. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes 
/// 
/// Remarks
///   Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call ADL2_Main_Control_Create first to obtain ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using ADL2_Main_Control_Destroy.
int ADL2_Adapter_Active_Set ( ADL_CONTEXT_HANDLE context,
                              int                iAdapterIndex,
                              int                iStatus,
                              int *              lpNewlyActivate
                            );


/// Function to set the current extended desktop mode status for the display. 
/// 
/// This function enables or disables the input adapter for a specified display. In addition, this function allows the user to enable the input adapter and pass in the preferred targets. 
/// Supported Platforms:
///   Windows 7, 10 and above; 32bit and 64bit 
/// 
/// Parameters
///   [in]  context          Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in]  iAdapterIndex    The ADL index handle of the desired adapter. 
///   [in]  iStatus          The desired display extended desktop mode status. ADL_TRUE : extended desktop mode; ADL_FALSE : otherwise. 
///   [in]  iNumPreferTarget If iStatus is TRUE, the user can pass the size of preferred Display Targets array. 
///   [in]  lpPreferTarget   If iStatus is TRUE, the user can pass the preferred Display Targets array to be enabled (with targets cloned). 
///   [out] lpNewlyActivate  The pointer to the retrieved adapter activation information. ADL_TRUE : the adapter is activated for the first time; ADL_FALSE : otherwise. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes 
/// 
/// Remarks
///   Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call ADL2_Main_Control_Create first to obtain ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using ADL2_Main_Control_Destroy.
int ADL2_Adapter_Active_SetPrefer ( ADL_CONTEXT_HANDLE context,
                                    int                iAdapterIndex,
                                    int                iStatus,
                                    int                iNumPreferTarget,
                                    ADLDisplayTarget * lpPreferTarget,
                                    int *              lpNewlyActivate
                                  );


/// Retrieves all OS-known adapter information. 
/// 
/// This function retrieves the adapter information of all OS-known adapters in the system. OS-known adapters can include adapters that are physically present in the system (logical adapters) 
/// 
///  as well as ones that are no longer present in the system but are still recognized by the OS. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in]  context    Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in]  iInputSize The size of the lpInfo buffer. 
///   [out] lpInfo     The pointer to the buffer containing the retrieved adapter information. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes 
/// 
/// 
/// Remarks
///   This API take a fixed-size output array. For dynamic-size output, use ADL_Adapter_AdapterInfoX2_Get function.
int ADL2_Adapter_AdapterInfo_Get ( ADL_CONTEXT_HANDLE context,
                                   LPAdapterInfo      lpInfo,
                                   int                iInputSize
                                 );


/// Retrieves all OS-known adapter information. 
/// 
/// This function retrieves the adapter information of all OS-known adapters in the system. OS-known adapters can include adapters that are physically present in the system (logical adapters) 
/// 
///  as well as ones that are no longer present in the system but are still recognized by the OS. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in]  context        Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [out] lppAdapterInfo is pointer to the pointer of AdapterInfo array. Initialize to NULL before calling this API. ADL will allocate the necessary memory, using the user provided callback function. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes
/// 
/// Remarks
///   This API uses the memory allocation callback function provided by the user.
int ADL2_Adapter_AdapterInfoX2_Get ( ADL_CONTEXT_HANDLE context,
                                     AdapterInfo **     lppAdapterInfo
                                   );


/// This function retrieves information for passed adapter or if pass -1, information of all OS-known adapters in the system. OS-known adapters can include adapters that are physically present in the system (logical adapters) 
/// 
///  as well as ones that are no longer present in the system but are still recognized by the OS. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in]  context        Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in]  iAdapterIndex  The ADL index handle of the desired adapter or -1 if all adapters are desired 
///   [out] number         of items in the lppAdapterInfo array. Can pass NULL pointer if passign an adapter index (in which case only one AdapterInfo is returned) 
///   [out] lppAdapterInfo pointer to the pointer of AdapterInfo array. Initialize to NULL before calling this API. ADL will allocate the necessary memory, using the user provided callback function. 
/// 
/// Returns
///   If the function valid, the return value is 1. Otherwise it is 0. 
/// 
/// Remarks
///   This API uses the memory allocation callback function provided by the user.
int ADL2_Adapter_AdapterInfoX3_Get ( ADL_CONTEXT_HANDLE context,
                                     int                iAdapterIndex,
                                     int *              numAdapters,
                                     AdapterInfo **     lppAdapterInfo
                                   );


/// This function retrieves information for passed adapter or if pass -1, information of all OS-known adapters in the system. OS-known adapters can include adapters that are physically present in the system (logical adapters) 
/// 
///  as well as ones that are no longer present in the system but are still recognized by the OS. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in]  context          Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in]  iAdapterIndex    The ADL index handle of the desired adapter or -1 if all adapters are desired 
///   [out] number           of items in the lppAdapterInfo array. Can pass NULL pointer if passing an adapter index (in which case only one AdapterInfo is returned) 
///   [out] lppAdapterInfoX2 pointer to the pointer of AdapterInfoX2 array. Initialize to NULL before calling this API. ADL will allocate the necessary memory, using the user provided callback function. 
/// 
/// Returns
///   If the function valid, the return value is 1. Otherwise it is 0. 
/// 
/// Remarks
///   This API uses the memory allocation callback function provided by the user.
int ADL2_Adapter_AdapterInfoX4_Get ( ADL_CONTEXT_HANDLE context,
                                     int                iAdapterIndex,
                                     int *              numAdapters,
                                     AdapterInfoX2 **   lppAdapterInfoX2
                                   );


/// This function disable multiple adapters in one CCD call for Win7 and later in order to improve the performace. the fucntion will fail if the current primary adapter is in the disabled adapter list 
/// Supported Platforms:
///   Windows 7; 32bit and 64bit,WIN8 
/// 
/// Parameters
///   [in] context            Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in] iNumAdapters       An integer indicates the number of desktops to be disabled. 
///   [in] lpAdapterIndexList The pointer to the integer array that contains the list of logicl adapter indexes to be disabled 
///   [in] isSkipSaveDB       A bool flag to indicate a temporary Display config setting (no SDC_SAVE_TO_DATABASE) 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes 
/// 
/// Remarks
///   Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call ADL2_Main_Control_Create first to obtain ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using ADL2_Main_Control_Destroy.
int ADL2_Adapter_AdapterList_Disable ( ADL_CONTEXT_HANDLE context,
                                       int                iNumAdapters,
                                       int *              lpAdapterIndexList,
                                       bool               isSkipSaveDB
                                     );


/// Function to get the ASICFamilyType from the adapter. 
/// 
/// This function retrieves the ASIC family types for a specified adapter. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in]  context       Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in]  iAdapterIndex The ADL index handle of the desired adapter. 
///   [out] lpAsicTypes   The pointer to the Detailed asic types information retrieved from the driver. 
///   [out] lpValids      The pointer to the bit vector indicating which bit is valid on the lpAsicTypes returned. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK (zero). Otherwise the return value is an ADL error code (non-zero). Result Codes 
/// 
/// Remarks
///   Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call ADL2_Main_Control_Create first to obtain ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using ADL2_Main_Control_Destroy.
int ADL2_Adapter_ASICFamilyType_Get ( ADL_CONTEXT_HANDLE context,
                                      int                iAdapterIndex,
                                      int *              lpAsicTypes,
                                      int *              lpValids
                                    );


/// ADL local interface. Function to retrieve the supported aspects list. 
/// 
/// This function retrieves the list of supported aspects for a specified adapter. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in]  context       Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in]  iAdapterIndex The ADL index handle of the desired adapter. 
///   [out] lpAspects     The pointer to the buffer storing the list of aspects supported for the specified adapter. 
///   [in]  iSize         The size of the lpAspects buffer. 
/// 
/// Returns
///   If the function valid, the return value is 1. Otherwise it is 0. 
/// 
/// Remarks
///   Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call ADL2_Main_Control_Create first to obtain ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using ADL2_Main_Control_Destroy.
int ADL2_Adapter_Aspects_Get ( ADL_CONTEXT_HANDLE context,
                               int                iAdapterIndex,
                               char *             lpAspects,
                               int                iSize
                             );


/// This function retrieves the Big Software & Red Stone support information for a specified adapter. Supported Platforms:Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
/// 
/// 
/// 
/// [in]iAdapterIndexThe ADL index handle of the desired adapter. 
/// 
/// [in]contextClient's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
/// 
/// [out]lpBigSwSupportMajorThe pointer to the Big Software major version information retrieved from the driver. Detailed asic types 
/// 
/// [out]lpBigSwSupportMinorThe pointer to the Big Software minor version information retrieved from the driver. Detailed asic types 
/// 
/// [out]lpRedStoneSupportThe pointer to the Red Stone support information retrieved from the driver. 
/// 
/// 
/// 
/// 
/// 
/// 
/// 
/// ReturnsIf the function succeeds, the return value is ADL_OK (zero). Otherwise the return value is an ADL error code (non-zero). Result Codes 
/// 
/// 
/// 
/// 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in]  iAdapterIndex       The ADL index handle of the desired adapter. 
///   [in]  context             Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [out] lpBigSwSupportMajor The pointer to the Big Software major version information retrieved from the driver. Detailed asic types 
///   [out] lpBigSwSupportMinor The pointer to the Big Software minor version information retrieved from the driver. Detailed asic types 
///   [out] lpRedStoneSupport   The pointer to the Red Stone support information retrieved from the driver. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK (zero). Otherwise the return value is an ADL error code (non-zero). Result Codes
int ADL2_Adapter_BigSw_Info_Get ( ADL_CONTEXT_HANDLE context,
                                  int                iAdapterIndex,
                                  int *              lpBigSwSupportMajor,
                                  int *              lpBigSwSupportMinor,
                                  int *              lpRedStoneSupport
                                );


/// 
int ADL2_Adapter_BoardLayout_Get ( ADL_CONTEXT_HANDLE    context,
                                   int                   iAdapterIndex,
                                   int *                 lpValidFlags,
                                   int *                 lpNumberSlots,
                                   ADLBracketSlotInfo ** lppBracketSlot,
                                   int *                 lpNumberConnector,
                                   ADLConnectorInfo **   lppConnector
                                 );


/// This function implements a DI call to retrieve adapter capability information . 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in]  context       Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in]  iAdapterIndex The ADL index handle of the desired adapter. 
///   [out] adapterCaps   The pointer to the structure storing the retrieved adapter capability information. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK, or an ADL error code otherwise. Result Codes 
/// 
/// Remarks
///   Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call ADL2_Main_Control_Create first to obtain ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using ADL2_Main_Control_Destroy.
int ADL2_Adapter_Caps ( ADL_CONTEXT_HANDLE context,
                        int                iAdapterIndex,
                        ADLAdapterCaps *   adapterCaps
                      );


/// This function retrieves the chipset information for a specified adapter. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in]  context       Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in]  iAdapterIndex The ADL index handle of the desired adapter. 
///   [out] lpChipSetInfo The pointer to the structure storing the retrieved chipset information. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes 
/// 
/// Remarks
///   Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call ADL2_Main_Control_Create first to obtain ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using ADL2_Main_Control_Destroy.
int ADL2_Adapter_ChipSetInfo_Get ( ADL_CONTEXT_HANDLE context,
                                   int                iAdapterIndex,
                                   ADLChipSetInfo *   lpChipSetInfo
                                 );


/// Function to retrieve clock information for an adapter. 
/// 
/// This function retrieves the clock information for a specified graphics adapter. Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// Parameters
///   [in]  context       Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in]  iAdapterIndex The ADL index handle of the desired adapter. 
///   [out] lpClockInfo   The pointer to the structure storing the retrieved core and memory clock information. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes 
/// 
/// 
/// Remarks
///   Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call ADL2_Main_Control_Create first to obtain ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using ADL2_Main_Control_Destroy. 
/// Deprecated:
///   This API has been deprecated because it does not provide accurate clocks when the ASIC is over-clocked. Use the OD5 set of APIs, when OverDrive5 is supported.
int ADL2_Adapter_ClockInfo_Get ( ADL_CONTEXT_HANDLE context,
                                 int                iAdapterIndex,
                                 ADLClockInfo *     lpClockInfo
                               );


/// Function to gets the emulation data on specified connector. 
/// 
/// This function to gets the emulation data 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in]  context          Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in]  iAdapterIndex    The ADL index handle of the desired adapter. 
///   [in]  devicePort       specifies connector index and relative MST address. 
///   [in]  iQueryType       The Specifies type of query. Define_emulation_query 
///   [out] lpConnectionData The pointer to the structure storing the retrieved information. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes 
/// 
/// Remarks
///   Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call ADL2_Main_Control_Create first to obtain ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using ADL2_Main_Control_Destroy.
int ADL2_Adapter_ConnectionData_Get ( ADL_CONTEXT_HANDLE  context,
                                      int                 iAdapterIndex,
                                      ADLDevicePort       devicePort,
                                      int                 iQueryType,
                                      ADLConnectionData * lpConnectionData
                                    );


/// Function to remove emulation on specified connector. 
/// 
/// This function removes the emulation which are emulated already 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in] context       Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in] iAdapterIndex The ADL index handle of the desired adapter. 
///   [in] devicePort    specifies connector index and relative mst address. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes 
/// 
/// Remarks
///   Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call ADL2_Main_Control_Create first to obtain ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using ADL2_Main_Control_Destroy.
int ADL2_Adapter_ConnectionData_Remove ( ADL_CONTEXT_HANDLE context,
                                         int                iAdapterIndex,
                                         ADLDevicePort      devicePort
                                       );


/// Function to set the emulation data to on specified connector. 
/// 
/// This function sets the emulation data 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in] context        Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in] iAdapterIndex  The ADL index handle of the desired adapter. 
///   [in] devicePort     specifies connector index and relative MST address. 
///   [in] ConnectionData contains connection data including the EDID data 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes 
/// 
/// Remarks
///   Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call ADL2_Main_Control_Create first to obtain ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using ADL2_Main_Control_Destroy.
int ADL2_Adapter_ConnectionData_Set ( ADL_CONTEXT_HANDLE context,
                                      int                iAdapterIndex,
                                      ADLDevicePort      devicePort,
                                      ADLConnectionData  ConnectionData
                                    );


/// Function to get the current emulation state of a given connector. 
/// 
/// This function retrieves the current emulation state 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in]  context              Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in]  iAdapterIndex        The ADL index handle of the desired adapter. 
///   [in]  devicePort           specifies connector index and relative MST address. 
///   [out] lpADLConnectionState The pointer to the structure storing the retrieved information. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes 
/// 
/// Remarks
///   Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call ADL2_Main_Control_Create first to obtain ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using ADL2_Main_Control_Destroy.
int ADL2_Adapter_ConnectionState_Get ( ADL_CONTEXT_HANDLE   context,
                                       int                  iAdapterIndex,
                                       ADLDevicePort        devicePort,
                                       ADLConnectionState * lpADLConnectionState
                                     );


/// 
int ADL2_Adapter_Crossfire_Caps ( ADL_CONTEXT_HANDLE  context,
                                  int                 iAdapterIndex,
                                  int *               lpPreferred,
                                  int *               lpNumComb,
                                  ADLCrossfireComb ** ppCrossfireComb
                                );


/// This function is used to retrieve the current information about a particular CrossfireX combination. A CrossfireX combination includes the CrossfireX capable adapter and its CrossfireX chain (a list of other adapters that will work with the CrossfireX capable adapter). The possible CrossfireX chain combinations for an adapter is retrieved from the ADL_Adapter_Crossfire_Caps function. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in]  context         Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in]  iAdapterIndex   The ADL index of the CrossfireX capable adapter to query the CrossfireX state and current information 
///   [in]  lpCrossfireComb The CrossfireX chain to get information about. 
///   [out] lpCrossfireInfo State and error information about the CrossfireX combination. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK (zero). Otherwise the return value is an ADL error code (non-zero). Result Codes 
/// 
/// Remarks
///   Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call ADL2_Main_Control_Create first to obtain ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using ADL2_Main_Control_Destroy.
int ADL2_Adapter_Crossfire_Get ( ADL_CONTEXT_HANDLE context,
                                 int                iAdapterIndex,
                                 ADLCrossfireComb * lpCrossfireComb,
                                 ADLCrossfireInfo * lpCrossfireInfo
                               );


/// Function to set CrossfireX combination settings. 
/// 
/// This function is used to enable or disable CrossfireX on a particular adapter (pointed to by iAdapterIndex), along with the indicated CrossfireX chain. The CrossfireX chain combination for the adapter must be one returned by ADL_Adapter_Crossfire_Caps(). 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in] context         Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in] iAdapterIndex   The adapter in which to enable or disable CrossfireX 
///   [in] lpCrossfireComb the CrossfireX chain combination to enable or disable for the master adapter. If this parameter is not NULL, it will enable CrossfireX with the indicated combination. If this parameter is NULL, it will disable CrossfireX on that particular adapter. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK (zero). Otherwise the return value is an ADL error code (non-zero). Result Codes 
/// 
/// Remarks
///   Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call ADL2_Main_Control_Create first to obtain ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using ADL2_Main_Control_Destroy.
int ADL2_Adapter_Crossfire_Set ( ADL_CONTEXT_HANDLE context,
                                 int                iAdapterIndex,
                                 ADLCrossfireComb * lpCrossfireComb
                               );


/// Function to get current CrossfireX settings for both QUAD and Software crossfire. 
/// 
/// On QUAD Crossfire systems this function is used to retrieve the current information about a particular CrossfireX combination. A CrossfireX combination includes the CrossfireX capable adapter and its CrossfireX chain (a list of other adapters that will work with the CrossfireX capable adapter). The possible CrossfireX chain combinations for an adapter is retrieved from the ADL_Adapter_Crossfire_Caps function. On Software Crossfire systems this function is used to query support and status of Crossfire. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in]  context         Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in]  iAdapterIndex   The ADL index of the CrossfireX capable adapter to query the CrossfireX state and current information 
///   [in]  lpCrossfireComb The CrossfireX chain to get information about. Ignored when called for Software crossfire 
///   [out] lpCrossfireInfo State and error information about the CrossfireX combination. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK (zero). Otherwise the return value is an ADL error code (non-zero). Result Codes 
/// 
/// Remarks
///   Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call ADL2_Main_Control_Create first to obtain ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using ADL2_Main_Control_Destroy.
int ADL2_Adapter_CrossfireX2_Get ( ADL_CONTEXT_HANDLE context,
                                   int                iAdapterIndex,
                                   ADLCrossfireComb * lpCrossfireComb,
                                   ADLCrossfireInfo * lpCrossfireInfo
                                 );


/// This function retrieves the Dedicated VRAM usage of given adapterThe function is used to get Dedicated VRAM usge by calling MS Counter.
/// 
/// Supported Platforms:Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
/// 
/// 
/// 
/// [in]contextClient's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
/// 
/// [in]iAdapterIndexThe index of the desired adapter. 
/// 
/// [in]iVRAMUsageInMBThe pointer to an int variable retrives the current usage of VRAM. 
/// 
/// 
/// 
/// 
/// 
/// 
/// 
/// ReturnsIf the function succeeds, the return value is ADL_OK (zero). Otherwise the return value is an ADL error code (non-zero). Result Codes 
/// 
/// RemarksClients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call ADL2_Main_Control_Create first to obtain ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using ADL2_Main_Control_Destroy. 
/// 
/// 
/// 
/// The function is used to get Dedicated VRAM usge by calling MS Counter.
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in] context        Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in] iAdapterIndex  The index of the desired adapter. 
///   [in] iVRAMUsageInMB The pointer to an int variable retrives the current usage of VRAM. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK (zero). Otherwise the return value is an ADL error code (non-zero). Result Codes 
/// 
/// Remarks
///   Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call ADL2_Main_Control_Create first to obtain ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using ADL2_Main_Control_Destroy.
int ADL2_Adapter_DedicatedVRAMUsage_Get ( ADL_CONTEXT_HANDLE context,
                                          int                iAdapterIndex,
                                          int *              iVRAMUsageInMB
                                        );


/// Function to inject Gfx EDC Error . 
/// 
/// This function implements a call to inject Gfx EDC Error. 
/// Supported Platforms:
///   Windows Vista and Windows 7; 32bit and 64bit 
/// 
/// Parameters
///   [in] context        Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in] iAdapterIndex  The ADL index handle of the desired adapter. 
///   [in] errorInjection The pointer to error injection 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK, or an ADL error code otherwise. Result Codes
int ADL2_Adapter_EDC_ErrorInjection_Set ( ADL_CONTEXT_HANDLE  context,
                                          int                 iAdapterIndex,
                                          ADLErrorInjection * errorInjection
                                        );


/// Function to retrieve Gfx EDC Error Log. 
/// 
/// This function implements a call to retrieve Gfx EDC Error Logs. 
/// Supported Platforms:
///   Windows Vista and Windows 7; 32bit and 64bit 
/// 
/// Parameters
///   [in]  context           Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in]  iAdapterIndex     The ADL index handle of the desired adapter. 
///   [out] pErrorrecordCount The pointer to the number of error records 
///   [out] errorRecords      The pointer to error records 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK, or an ADL error code otherwise. Result Codes
int ADL2_Adapter_EDC_ErrorRecords_Get ( ADL_CONTEXT_HANDLE context,
                                        int                iAdapterIndex,
                                        int *              pErrorrecordCount,
                                        ADLErrorRecord *   errorRecords
                                      );


/// Function to retrieve EDID management feature support. 
/// 
/// This function retrieves EDID Management supprot for specific adapter. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in]  context       Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in]  iAdapterIndex The ADL index handle of the desired adapter. 
///   [out] lpSupported   If the specified adapter supports EDID Management then returns ADL_TRUE else ADL_FALSE 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes 
/// 
/// Remarks
///   Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call ADL2_Main_Control_Create first to obtain ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using ADL2_Main_Control_Destroy.
int ADL2_Adapter_EDIDManagement_Caps ( ADL_CONTEXT_HANDLE context,
                                       int                iAdapterIndex,
                                       int *              lpSupported
                                     );


/// Function to sets the emulation mode of given connector. 
/// 
/// This function set the emulation mode to the driver 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in] context        Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in] iAdapterIndex  The ADL index handle of the desired adapter. 
///   [in] devicePort     specifies connector index and relative MST address. 
///   [in] iEmulationMode selected Emulated mode. Define_emulation_mode 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes 
/// 
/// Remarks
///   Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call ADL2_Main_Control_Create first to obtain ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using ADL2_Main_Control_Destroy.
int ADL2_Adapter_EmulationMode_Set ( ADL_CONTEXT_HANDLE context,
                                     int                iAdapterIndex,
                                     ADLDevicePort      devicePort,
                                     int                iEmulationMode
                                   );


/// Checks if given GPU (identified by adapter id) supports feature (iFeatureID) or not. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in]  context             Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in]  iAdapterIndex       The ADL index handle of the desired adapter. 
///   [in]  iFeatureID          The Feature index of the desired feature. ADL_UIFEATURES_GROUP 
///   [out] iIsFeatureSupported The pointer to the structure storing the retrieved adapter capability information. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK, or an ADL error code otherwise. Result Codes
int ADL2_Adapter_Feature_Caps ( ADL_CONTEXT_HANDLE   context,
                                int                  iAdapterIndex,
                                ADL_UIFEATURES_GROUP iFeatureID,
                                int *                iIsFeatureSupported
                              );


/// 
int ADL2_Adapter_FrameMetrics_Caps ( ADL_CONTEXT_HANDLE context,
                                     int                iAdapterIndex,
                                     int *              iIsFrameMonitorSupported
                                   );


/// Will try to deallocate memory that was previously allocated for Frame Metrics Duration recording inside supplied Handle. This handle is required to start, Get and stop Frame Metrics Duration recording and must be supplied in all future calls. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in] context             Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in] frameDurationHandle Handle containing information used inside Get calls to know how many Time stamp elements to read. Will be allocated by the enable call within ADL and then released after Disable call. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK, or an ADL error code otherwise. Result Codes
int ADL2_Adapter_FrameMetrics_FrameDuration_Disable ( ADL_CONTEXT_HANDLE          context,
                                                      int                         iAdapterIndex,
                                                      ADL_FRAME_DURATION_HANDLE * frameDurationHandle
                                                    );


/// Will try to allocate memory required for Frame Metrics Duration recording inside supplied Handle. This handle is required to start, Get and stop Frame Metrics Duration recording and must be supplied in all future calls. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in] context             Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in] frameDurationHandle Handle containing information used inside Get calls to know how many Time stamp elements to read. Will be allocated by the enable call within ADL and then released after Disable call. Value must be set to null before being passed in. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK, or an ADL error code otherwise. Result Codes
int ADL2_Adapter_FrameMetrics_FrameDuration_Enable ( ADL_CONTEXT_HANDLE          context,
                                                     int                         iAdapterIndex,
                                                     ADL_FRAME_DURATION_HANDLE * frameDurationHandle
                                                   );


/// Get frame metrics frame duration Data on GPU (identified by adapter id). ADL2_Adapter_FrameMetrics_FrameDuration_Enable (at least once) & then ADL2_Adapter_FrameMetrics_FrameDuration_Start must be called and succeed before Get will function. This function does not take adapterindex/vidPnSourceId so it will return the information on the adapter previously Started on. Will detect if in crossfire and Get data from all slaves as well. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in]  context               Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in]  frameDurationHandle   Handle containing information used inside Get calls to know how many Time stamp elements to read. Will be allocated by the enable call within ADL and then released after Disable call. 
///   [out] pFrameDurationsArr    Array that will be filled with the new frame durations since the last call. Durations in Microseconds 
///   [in]  frameDurationsArrSize size of pFrameTimeStampsArr array to avoid overflow. 
///   [out] elementsCopied        Number of elements copied from shared memory address to be passed into pFrameDurationsArr 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK, or an ADL error code otherwise. Result Codes
int ADL2_Adapter_FrameMetrics_FrameDuration_Get ( ADL_CONTEXT_HANDLE        context,
                                                  ADL_FRAME_DURATION_HANDLE frameDurationHandle,
                                                  unsigned long long *      pFrameDurationsArr,
                                                  unsigned int              frameDurationsArrSize,
                                                  unsigned int *            elementsCopied
                                                );


/// Start frame metrics time stamp/frame duration recording on GPU (identified by adapter id). Will try to enable TimeStamp/FrameDuration recording (ADL2_Adapter_FrameMetrics_Start will be called inside and must succeed). Will detect if in crossfire and start all slaves as well. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in] context       Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in] iAdapterIndex The ADL index handle of the desired adapter. 
///   [in] VidPnSourceId The Source ID of the Display FPS metrics will be started from. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK, or an ADL error code otherwise. Result Codes
int ADL2_Adapter_FrameMetrics_FrameDuration_Start ( ADL_CONTEXT_HANDLE context,
                                                    int                iAdapterIndex,
                                                    int                VidPnSourceId
                                                  );


/// Stop frame metrics time stamp recording on GPU (identified by adapter id). Will try to stop time stamp/Frame duration recording. (ADL2_Adapter_FrameMetrics_Stop will be called inside upon successful stop) Will detect if in crossfire and stop all slaves as well. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in] context       Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in] iAdapterIndex The ADL index handle of the desired adapter. 
///   [in] VidPnSourceId The Source ID of the Display FPS metrics will be stopped from. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK, or an ADL error code otherwise. Result Codes
int ADL2_Adapter_FrameMetrics_FrameDuration_Stop ( ADL_CONTEXT_HANDLE context,
                                                   int                iAdapterIndex,
                                                   int                VidPnSourceId
                                                 );


/// Get frame metrics monitoring Data on GPU (identified by adapter id). Will detect if in crossfire and Get data from all slaves as well. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in]  context          Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in]  iAdapterIndex    The ADL index handle of the desired adapter. 
///   [in]  VidPnSourceId    The Source ID of the Display FPS metrics will be gathered from. 
///   [out] iFramesPerSecond The FPS presented by the GPU. This is the average of all FPS presented since the last time the function was called. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK, or an ADL error code otherwise. Result Codes
int ADL2_Adapter_FrameMetrics_Get ( ADL_CONTEXT_HANDLE context,
                                    int                iAdapterIndex,
                                    int                VidPnSourceId,
                                    float *            iFramesPerSecond
                                  );


/// Start frame metrics monitoring on GPU (identified by adapter id). Will detect if in crossfire and start all slaves as well. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in] context       Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in] iAdapterIndex The ADL index handle of the desired adapter. 
///   [in] VidPnSourceId The Source ID of the Display FPS metrics will be started from. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK, or an ADL error code otherwise. Result Codes
int ADL2_Adapter_FrameMetrics_Start ( ADL_CONTEXT_HANDLE context,
                                      int                iAdapterIndex,
                                      int                VidPnSourceId
                                    );


/// Stop frame metrics monitoring on GPU (identified by adapter id). Will detect if in crossfire and stop all slaves as well. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in] context       Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in] iAdapterIndex The ADL index handle of the desired adapter. 
///   [in] VidPnSourceId The Source ID of the Display FPS metrics will be stopped from. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK, or an ADL error code otherwise. Result Codes
int ADL2_Adapter_FrameMetrics_Stop ( ADL_CONTEXT_HANDLE context,
                                     int                iAdapterIndex,
                                     int                VidPnSourceId
                                   );


/// This function retrieves the HBC Capability for a specified graphics adapter. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in]  context       : Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in]  iAdapterIndex : The ADL index handle of the desired adapter. 
///   [out] lpHbcCapable  : Will be set to 1 to indicate that given GPU supports HBC. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes 
/// 
/// Remarks
///   Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call ADL2_Main_Control_Create first to obtain ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using ADL2_Main_Control_Destroy.
int ADL2_Adapter_HBC_Caps ( ADL_CONTEXT_HANDLE context,
                            int                iAdapterIndex,
                            int *              lpHbcCapable
                          );


/// This function implements private adapter info to retrieve the configuration state of a specified adapter. 
/// Supported Platforms:
///   Windows 7, 10 and above; 32bit and 64bit 
/// 
/// Parameters
///   [in]  context       Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in]  iAdapterIndex The ADL index handle of the desired adapter. 
///   [out] lpHeadless    Integer indicating the state of the adapter.
int ADL2_Adapter_Headless_Get ( ADL_CONTEXT_HANDLE context,
                                int                iAdapterIndex,
                                int *              lpHeadless
                              );


/// Function to get the unique identifier of an adapter. 
/// 
/// This function retrieves the unique identifier of a specified adapter.
/// 
///  The adapter ID is a unique value and will be used to determine what other controllers share the same adapter.
/// 
///  The desktop will use this to find which HDCs are associated with an adapter. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in]  context       Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in]  iAdapterIndex The ADL index handle of the desired adapter. 
///   [out] lpAdapterID   The pointer to the adapter identifier. Zero means: The adapter is not AMD. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes
/// 
/// Remarks
///   This API is a duplicate to ADL_Display_AdapterID_Get()
int ADL2_Adapter_ID_Get ( ADL_CONTEXT_HANDLE context,
                          int                iAdapterIndex,
                          int *              lpAdapterID
                        );


/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in]  iAdapterIndex  The ADL index handle of the desired adapter. 
///   [in]  context        Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [out] lpCwgSupport   Will be set to 1 to indicate that given GPU supports CWG. Detailed asic types 
///   [out] lpIsGamingMode Will be set to 1 to indicate that given GPU supports Gaming Mode. Detailed asic types 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK (zero). Otherwise the return value is an ADL error code (non-zero). Result Codes
int ADL2_Adapter_IsGamingDriver_Info_Get ( ADL_CONTEXT_HANDLE context,
                                           int                iAdapterIndex,
                                           int *              lpCwgSupport,
                                           int *              lpIsGamingMode
                                         );


/// This function retrieves the memory information for a specified graphics adapter. 
/// Supported Platforms:
///   Linux; 32bit and 64bit 
/// 
/// Parameters
///   [in]  context       Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in]  iAdapterIndex The ADL index handle of the desired adapter. 
///   [out] lpMemoryInfo2 The pointer to the structure storing the retrieved memory information. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes 
/// 
/// Remarks
///   Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call ADL2_Main_Control_Create first to obtain ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using ADL2_Main_Control_Destroy.
int ADL2_Adapter_MemoryInfo2_Get ( ADL_CONTEXT_HANDLE context,
                                   int                iAdapterIndex,
                                   ADLMemoryInfo2 *   lpMemoryInfo2
                                 );


/// This function re-enumerates adapter modes 
/// Supported Platforms:
///   \Win7 
/// 
/// Parameters
///   [in] context Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes 
/// 
/// Remarks
///   For Win7 only. This internal AMD API is used to test driver's SLS middle mode feature.
int ADL2_Adapter_Modes_ReEnumerate ( );


/// Function to perform a mode switch for an adapter. 
/// 
/// This function performs a mode switch for a specified adapter. 
/// Supported Platforms:
///   Windows 7, 10 and above; 32bit and 64bit 
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
int ADL2_Adapter_ModeSwitch ( ADL_CONTEXT_HANDLE context,
                              int                iAdapterIndex
                            );


/// Function to set CrossfireX status. 
/// 
/// This function is used to enable or disable CrossfireX on a particular adapter (pointed to by iAdapterIndex). 
/// Supported Platforms:
///   Windows 7, 10 and above; 32bit and 64bit 
/// 
/// Parameters
///   [in] context       Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in] iAdapterIndex The adapter in which to enable or disable CrossfireX 
///   [in] iState        the requested CrossfireX state to be set 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK (zero). Otherwise the return value is an ADL error code (non-zero). Result Codes 
/// 
/// Remarks
///   Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call ADL2_Main_Control_Create first to obtain ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using ADL2_Main_Control_Destroy.
int ADL2_Adapter_MVPU_Set ( ADL_CONTEXT_HANDLE context,
                            int                iAdapterIndex,
                            int                iState
                          );


/// Function to retrieve the number of OS-known adapters. 
/// 
/// This function retrieves the number of graphics adapters recognized by the OS (OS-known adapters). OS-known adapters can include adapters that are physically present in the system (logical adapters) 
/// 
///  as well as ones that no longer present in the system but are still recognized by the OS. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in]  context       Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [out] lpNumAdapters The pointer to the number of OS-known adapters. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes 
/// 
/// Remarks
///   Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call ADL2_Main_Control_Create first to obtain ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using ADL2_Main_Control_Destroy.
int ADL2_Adapter_NumberOfAdapters_Get ( ADL_CONTEXT_HANDLE context,
                                        int *              lpNumAdapters
                                      );


/// 
int ADL2_Adapter_ObservedClockInfo_Get ( ADL_CONTEXT_HANDLE context,
                                         int                iAdapterIndex,
                                         int *              lpCoreClock,
                                         int *              lpMemoryClock
                                       );


/// Function to retrieve the primary display adapter index. 
/// 
/// This function retrieves the adapter index for the primary display adapter. 
/// Supported Platforms:
///   Windows 7, 10 and above; 32bit and 64bit 
/// 
/// Parameters
///   [in]  context               Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [out] lpPrimaryAdapterIndex The pointer to the ADL index handle of the primary adapter. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes 
/// 
/// Remarks
///   Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call ADL2_Main_Control_Create first to obtain ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using ADL2_Main_Control_Destroy.
int ADL2_Adapter_Primary_Get ( ADL_CONTEXT_HANDLE context,
                               int *              lpPrimaryAdapterIndex
                             );


/// Function to set the primary display adapter index. 
/// 
/// This function sets the adapter index for a specified primary display adapter. 
/// Supported Platforms:
///   Windows 7, 10 and above; 32bit and 64bit 
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
int ADL2_Adapter_Primary_Set ( ADL_CONTEXT_HANDLE context,
                               int                iAdapterIndex
                             );


/// ADL local interface. Function to query a integer registry value set by driver. 
/// 
/// This function queries a driver registry integer value for a specified adapter by specifying the subkey path and key name. 
/// Supported Platforms:
///   Windows 7, 10 and above; 32bit and 64bit 
/// 
/// Parameters
///   [in]  context           Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in]  iAdapterIndex     The ADL index handle of the desired adapter. 
///   [in]  iDriverPathOption The option of the driver path. 0: Current; 1: function1; 2: function2; 0xFFFF for all device. 
///   [in]  szSubKey          The path of registry subkey to be accessed. This is a null terminated string and the parameter can be NULL. 
///   [in]  szKeyName         The name of registry value to be got. This is a null terminated string. 
///   [out] lpKeyValue        The pointer to registry value to be got. 
/// 
/// Returns
///   If the function valid, the return value is 1. Otherwise it is 0. 
/// 
/// Remarks
///   Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call ADL2_Main_Control_Create first to obtain ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using ADL2_Main_Control_Destroy.
int ADL2_Adapter_RegValueInt_Get ( ADL_CONTEXT_HANDLE context,
                                   int                iAdapterIndex,
                                   int                iDriverPathOption,
                                   char *             szSubKey,
                                   char *             szKeyName,
                                   int *              lpKeyValue
                                 );


/// ADL local interface. Function to set a driver registry integer value. 
/// 
/// This function sets a driver registry integer value for a specified adapter by specifying the subkey path and key name. 
/// Supported Platforms:
///   Windows 7, 10 and above; 32bit and 64bit 
/// 
/// Parameters
///   [in] context           Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in] iAdapterIndex     The ADL index handle of the desired adapter. 
///   [in] iDriverPathOption The option of the driver path. 0: Current; 1: function1; 2: function2; 0xFFFF for all device. 
///   [in] szSubKey          The path of registry subkey to be accessed. This is a null terminated string and the parameter can be NULL. 
///   [in] szKeyName         The name of registry value to be set. This is a null terminated string. 
///   [in] iKeyValue         The integer registry value to be set. 
/// 
/// Returns
///   If the function valid, the return value is 1. Otherwise it is 0. 
/// 
/// Remarks
///   Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call ADL2_Main_Control_Create first to obtain ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using ADL2_Main_Control_Destroy.
int ADL2_Adapter_RegValueInt_Set ( ADL_CONTEXT_HANDLE context,
                                   int                iAdapterIndex,
                                   int                iDriverPathOption,
                                   char *             szSubKey,
                                   char *             szKeyName,
                                   int                iKeyValue
                                 );


/// ADL local interface. Function to query a string registry value set by driver. 
/// 
/// This function queries a driver registry string value for a specified adapter by specifying the subkey path and key name. 
/// Supported Platforms:
///   Windows 7, 10 and above; 32bit and 64bit 
/// 
/// Parameters
///   [in]  context           Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in]  iAdapterIndex     The ADL index handle of the desired adapter. 
///   [in]  iDriverPathOption The option of the driver path. 0: Current; 1: function1; 2: function2; 0xFFFF for all device. 
///   [in]  szSubKey          The path of registry sub key to be accessed. This is a null terminated string and the parameter can be NULL. 
///   [in]  szKeyName         The name of registry value to be got. This is a null terminated string. 
///   [in]  iSize             The size of registry value to be got. 
///   [out] lpKeyValue        The pointer to registry value to be got. 
/// 
/// Returns
///   If the function valid, the return value is 1. Otherwise it is 0. 
/// 
/// Remarks
///   Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call ADL2_Main_Control_Create first to obtain ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using ADL2_Main_Control_Destroy.
int ADL2_Adapter_RegValueString_Get ( ADL_CONTEXT_HANDLE context,
                                      int                iAdapterIndex,
                                      int                iDriverPathOption,
                                      char *             szSubKey,
                                      char *             szKeyName,
                                      int                iSize,
                                      char *             lpKeyValue
                                    );


/// ADL local interface. Function to set a driver registry string value. 
/// 
/// This function sets a driver registry string value for a specified adapter by specifying the subkey path and key name. 
/// Supported Platforms:
///   Windows 7, 10 and above; 32bit and 64bit 
/// 
/// Parameters
///   [in] context           Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in] iAdapterIndex     The ADL index handle of the desired adapter. 
///   [in] iDriverPathOption The option of the driver path. 0: Current; 1: function1; 2: function2; 0xFFFF for all device. 
///   [in] szSubKey          The path of registry sub key to be accessed. This is a null terminated string and the parameter can be NULL. 
///   [in] szKeyName         The name of registry value to be set. This is a null terminated string. 
///   [in] iSize             The size of registry value to be set. 
///   [in] lpKeyValue        The pointer to registry value to be set. 
/// 
/// Returns
///   If the function valid, the return value is 1. Otherwise it is 0. 
/// 
/// Remarks
///   Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call ADL2_Main_Control_Create first to obtain ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using ADL2_Main_Control_Destroy.
int ADL2_Adapter_RegValueString_Set ( ADL_CONTEXT_HANDLE context,
                                      int                iAdapterIndex,
                                      int                iDriverPathOption,
                                      char *             szSubKey,
                                      char *             szKeyName,
                                      int                iSize,
                                      char *             lpKeyValue
                                    );


/// Function to get the current Force3DClock setting from the adapter. 
/// 
/// This function retrieves the adapter speed information for a specified adapter. Return valud can be ADL_ADAPTER_SPEEDCAPS_SUPPORTED or “0” 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in]  context       Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in]  iAdapterIndex The ADL index handle of the desired adapter. 
///   [out] lpCaps        The caps of adapter speed settings 
///   [out] lpValid       The valid bits of adapter speed settings 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK (zero). Otherwise the return value is an ADL error code (non-zero). Result Codes 
/// 
/// Remarks
///   Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call ADL2_Main_Control_Create first to obtain ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using ADL2_Main_Control_Destroy.
int ADL2_Adapter_Speed_Caps ( ADL_CONTEXT_HANDLE context,
                              int                iAdapterIndex,
                              int *              lpCaps,
                              int *              lpValid
                            );


/// Function to get the current Speed setting from the adapter. 
/// 
/// This function retrieves the adapter speed information for a specified adapter. Return value is either ADL_CONTEXT_SPEED_UNFORCED or ADL_CONTEXT_SPEED_FORCEHIGH 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in]  context       Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in]  iAdapterIndex The ADL index handle of the desired adapter. 
///   [out] lpCurrent     The current speed setting 
///   [out] lpDefault     The default speed setting 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK (zero). Otherwise the return value is an ADL error code (non-zero). Result Codes 
/// 
/// Remarks
///   Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call ADL2_Main_Control_Create first to obtain ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using ADL2_Main_Control_Destroy.
int ADL2_Adapter_Speed_Get ( ADL_CONTEXT_HANDLE context,
                             int                iAdapterIndex,
                             int *              lpCurrent,
                             int *              lpDefault
                           );


/// Function to set the current Speed setting from the adapter. 
/// 
/// This function set the adapter speed information for a specified adapter. Input value is either ADL_CONTEXT_SPEED_UNFORCED or ADL_CONTEXT_SPEED_FORCEHIGH 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in] context       Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in] iAdapterIndex The ADL index handle of the desired adapter. 
///   [in] iSpeed        The speed to set on specified adapter 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK (zero). Otherwise the return value is an ADL error code (non-zero). Result Codes 
/// 
/// Remarks
///   Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call ADL2_Main_Control_Create first to obtain ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using ADL2_Main_Control_Destroy.
int ADL2_Adapter_Speed_Set ( ADL_CONTEXT_HANDLE context,
                             int                iAdapterIndex,
                             int                iSpeed
                           );


/// Function to get the supported connection types of given connector. 
/// 
/// This function retrieves the supported connection types and its properties 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in]  context                   Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in]  iAdapterIndex             The ADL index handle of the desired adapter. 
///   [in]  devicePort                specifies connector index and relative MST address. 
///   [out] lpADLSupportedConnections The pointer to the structure storing the retrieved information. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes 
/// 
/// Remarks
///   Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call ADL2_Main_Control_Create first to obtain ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using ADL2_Main_Control_Destroy.
int ADL2_Adapter_SupportedConnections_Get ( ADL_CONTEXT_HANDLE        context,
                                            int                       iAdapterIndex,
                                            ADLDevicePort             devicePort,
                                            ADLSupportedConnections * lpADLSupportedConnections
                                          );


/// This function implements a lhEscape call to retrieve TRGN from hardware . 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in]  context         Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in]  iAdapterIndex   The ADL index handle of the desired adapter. 
///   [in]  iTRNGSize       size of the requested TRNG 
///   [in]  iTRNGBufferSize size of the trngBuffer 
///   [out] trngBuffer      The pointer where TRNG value is stored, buffer should be allocated at client side 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK, or an ADL error code otherwise. Result Codes 
/// 
/// Remarks
///   Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call ADL2_Main_Control_Create first to obtain ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using ADL2_Main_Control_Destroy.
int ADL2_Adapter_TRNG_Get ( ADL_CONTEXT_HANDLE context,
                            int                iAdapterIndex,
                            int                iTRNGSize,
                            int                iTRNGBufferSize,
                            char *             lpTRNGBuffer
                          );


/// Retrieves adapter vendor id. 
/// 
/// This function retrieves the parsed hex vendor id 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in] context Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes
int ADL2_Adapter_VerndorID_Int_get ( ADL_CONTEXT_HANDLE context,
                                     int                iAdapterIndex
                                   );


/// ADL local interface. Function to retrieve BIOS information. 
/// 
/// This function retrieves the BIOS information for a specified adapter. 
/// Supported Platforms:
///   Linux; 32bit and 64bit 
/// 
/// Parameters
///   [in]  context       Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in]  iAdapterIndex The ADL index handle of the desired adapter. 
///   [out] lpBiosInfo    The pointer to the structure storing the retrieved BIOs information. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes 
/// 
/// Remarks
///   Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call ADL2_Main_Control_Create first to obtain ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using ADL2_Main_Control_Destroy.
int ADL2_Adapter_VideoBiosInfo_Get ( ADL_CONTEXT_HANDLE context,
                                     int                iAdapterIndex,
                                     ADLBiosInfo *      lpBiosInfo
                                   );


/// Function to get MM video theater mode info. 
/// 
/// The function is used to get multi-media video theater mode information.
/// Supported Platforms:
///   Windows Vista and Windows 7; 32bit and 64bit 
/// 
/// Parameters
///   [in]  context              Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in]  iAdapterIndex        The ADL index handle of the desired adapter. 
///   [out] lpOverlayDisplayMode The pointer to the overlay display mode. 
///   [out] lpSavedSettings      The pointer to the saved settings of the related mode. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes 
/// 
/// Remarks
///   Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call ADL2_Main_Control_Create first to obtain ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using ADL2_Main_Control_Destroy.
int ADL2_Adapter_VideoTheaterModeInfo_Get ( ADL_CONTEXT_HANDLE context,
                                            int                iAdapterIndex,
                                            int *              lpOverlayDisplayMode,
                                            int *              lpSavedSettings
                                          );


/// Function to set MM video theater mode info. 
/// 
/// The function is used to set multi-media video theater mode information.
/// Supported Platforms:
///   Windows Vista and Windows 7; 32bit and 64bit 
/// 
/// Parameters
///   [in] context             Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in] iAdapterIndex       The ADL index handle of the desired adapter. 
///   [in] iOverlayDisplayMode The overlay display mode to be set. 
///   [in] iSavedSettings      The saved settings of the related mode to be set. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes 
/// 
/// Remarks
///   Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call ADL2_Main_Control_Create first to obtain ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using ADL2_Main_Control_Destroy.
int ADL2_Adapter_VideoTheaterModeInfo_Set ( ADL_CONTEXT_HANDLE context,
                                            int                iAdapterIndex,
                                            int                iOverlayDisplayMode,
                                            int                iSavedSettings
                                          );


/// This function retrieves the VRAM usage of given adapter Supported Platforms:Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
/// 
/// 
/// 
/// [in]contextClient's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
/// 
/// [in]iAdapterIndexThe index of the desired adapter. 
/// 
/// [in]iVRAMUsageInMBThe pointer to an int variable retrives the current usage of VRAM. 
/// 
/// 
/// 
/// 
/// 
/// 
/// 
/// ReturnsIf the function succeeds, the return value is ADL_OK (zero). Otherwise the return value is an ADL error code (non-zero). Result Codes 
/// 
/// RemarksClients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call ADL2_Main_Control_Create first to obtain ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using ADL2_Main_Control_Destroy. 
/// 
/// 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in] context        Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in] iAdapterIndex  The index of the desired adapter. 
///   [in] iVRAMUsageInMB The pointer to an int variable retrives the current usage of VRAM. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK (zero). Otherwise the return value is an ADL error code (non-zero). Result Codes 
/// 
/// Remarks
///   Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call ADL2_Main_Control_Create first to obtain ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using ADL2_Main_Control_Destroy.
int ADL2_Adapter_VRAMUsage_Get ( ADL_CONTEXT_HANDLE context,
                                 int                iAdapterIndex,
                                 int *              iVRAMUsageInMB
                               );


/// Function to retrieve adapter caps information. 
/// 
/// This function implements a DI call to retrieve adapter capability information . 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in]  context       Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in]  iAdapterIndex The ADL index handle of the desired adapter. 
///   [out] adapterCaps   The pointer to the structure storing the retrieved adapter capability information. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK, or an ADL error code otherwise. Result Codes 
/// 
/// Remarks
///   Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call ADL2_Main_Control_Create first to obtain ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using ADL2_Main_Control_Destroy.
int ADL2_AdapterX2_Caps ( ADL_CONTEXT_HANDLE context,
                          int                iAdapterIndex,
                          ADLAdapterCapsX2 * adapterCaps
                        );


/// Function to get the BOOST settings This function retrieves the BOOST settings for a specified display adapter. 
/// Supported Platforms:
///   Windows 7, 10 and above; 32bit and 64bit 
/// 
/// Parameters
///   [in]  context       Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in]  iAdapterIndex The index of the desired adapter. 
///   [out] settings      The pointer to the pointer to the BOOST data structure 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK (zero). Otherwise the return value is an ADL error code (non-zero). Result Codes
int ADL2_BOOST_Settings_Get ( ADL_CONTEXT_HANDLE   context,
                              int                  iAdapterIndex,
                              ADL_BOOST_SETTINGS * settings
                            );


/// Function to set BOOST settings This function sets the user input values to BOOST feature. 
/// Supported Platforms:
///   Windows 7, 10 and above; 32bit and 64bit 
/// 
/// Parameters
///   [in]  context       Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in]  iAdapterIndex The index of the desired adapter. 
///   [in]  settings      ADL_BOOST_SETTINGS : structure with the input values 
///   [in]  changeReason  ADL_BOOST_NOTFICATION_REASON : structure with the changed feilds in settings parameter 
///   [out] errorReason   ADL_ERROR_REASON : structure with the error feilds in settings parameter. client should refer to this feild when set call is filed. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK (zero). Otherwise the return value is an ADL error code (non-zero). Result Codes
/// 
/// Remarks
///   Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call ADL2_Main_Control_Create first to obtain ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using ADL2_Main_Control_Destroy.
int ADL2_BOOST_Settings_Set ( ADL_CONTEXT_HANDLE           context,
                              int                          iAdapterIndex,
                              ADL_BOOST_SETTINGS           settings,
                              ADL_BOOST_NOTFICATION_REASON changeReason,
                              ADL_ERROR_REASON *           errorReason
                            );


/// Supported Platforms:
///   Windows 7, 10 and above; 32bit and 64bit 
/// 
/// Parameters
///   [in]  context       Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in]  iAdapterIndex The index of the desired adapter. 
///   [out] iSupported    The pointer to an int variable which indicates if Global Chill is supported ( ADL_TRUE : enabled, ADL_FALSE : disabled) 
///   [out] iCheckCaps    The pointer to an int variable which indicates if iSupported flag is to be considered from Clients ( ADL_TRUE : iSupported to be considered, ADL_FALSE : ignore iSupported) 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK (zero). Otherwise the return value is an ADL error code (non-zero). Result Codes
int ADL2_Chill_Caps_Get ( ADL_CONTEXT_HANDLE context,
                          int                iAdapterIndex,
                          int *              iSupported,
                          int *              iCheckCaps
                        );


/// Supported Platforms:
///   Windows 7, 10 and above; 32bit and 64bit 
/// 
/// Parameters
///   [in]  context       Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in]  iAdapterIndex The index of the desired adapter. 
///   [out] lpEnabled     The pointer to an int variable which indicates if Global Chill is enabled ( ADL_TRUE : enabled, ADL_FALSE : disabled) 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK (zero). Otherwise the return value is an ADL error code (non-zero). Result Codes
int ADL2_Chill_Settings_Get ( ADL_CONTEXT_HANDLE context,
                              int                iAdapterIndex,
                              int *              lpEnabled
                            );


/// Supported Platforms:
///   Windows 7, 10 and above; 32bit and 64bit 
/// 
/// Parameters
///   [in] context       Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in] iAdapterIndex The index of the desired adapter. 
///   [in] iChanged      ADL_TRUE ADL_FALSE 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK (zero). Otherwise the return value is an ADL error code (non-zero). Result Codes
/// 
/// Remarks
///   Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call ADL2_Main_Control_Create first to obtain ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using ADL2_Main_Control_Destroy.
int ADL2_Chill_Settings_Notify ( ADL_CONTEXT_HANDLE context,
                                 int                iAdapterIndex,
                                 int                iChanged
                               );


/// Supported Platforms:
///   Windows 7, 10 and above; 32bit and 64bit 
/// 
/// Parameters
///   [in] context       Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in] iAdapterIndex The index of the desired adapter. 
///   [in] iEnabled      ADL_TRUE : enables Global Chill, ADL_FALSE : disables Global Chill. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK (zero). Otherwise the return value is an ADL error code (non-zero). Result Codes
/// 
/// Remarks
///   Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call ADL2_Main_Control_Create first to obtain ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using ADL2_Main_Control_Destroy.
int ADL2_Chill_Settings_Set ( ADL_CONTEXT_HANDLE context,
                              int                iAdapterIndex,
                              int                iEnabled
                            );


/// Function to get the CHILL settings This function retrieves the CHILL settings for a specified display adapter. 
/// Supported Platforms:
///   Windows 7, 10 and above; 32bit and 64bit 
/// 
/// Parameters
///   [in]  context       Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in]  iAdapterIndex The index of the desired adapter. 
///   [out] settings      The pointer to the pointer to the CHILL data structure 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK (zero). Otherwise the return value is an ADL error code (non-zero). Result Codes
int ADL2_CHILL_SettingsX2_Get ( ADL_CONTEXT_HANDLE   context,
                                int                  iAdapterIndex,
                                ADL_CHILL_SETTINGS * settings
                              );


/// Function to set CHILL settings This function sets the user input values to CHILL feature. 
/// Supported Platforms:
///   Windows 7, 10 and above; 32bit and 64bit 
/// 
/// Parameters
///   [in]  context       Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in]  iAdapterIndex The index of the desired adapter. 
///   [in]  settings      ADL_CHILL_SETTINGS : structure with the input values 
///   [in]  changeReason  ADL_CHILL_NOTFICATION_REASON : structure with the changed feilds in settings parameter 
///   [out] errorReason   ADL_ERROR_REASON : structure with the error feilds in settings parameter. client should refer to this feild when set call is filed. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK (zero). Otherwise the return value is an ADL error code (non-zero). Result Codes
/// 
/// Remarks
///   Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call ADL2_Main_Control_Create first to obtain ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using ADL2_Main_Control_Destroy.
int ADL2_CHILL_SettingsX2_Set ( ADL_CONTEXT_HANDLE           context,
                                int                          iAdapterIndex,
                                ADL_CHILL_SETTINGS           settings,
                                ADL_CHILL_NOTFICATION_REASON changeReason,
                                ADL_ERROR_REASON *           errorReason
                              );


/// Function to get the DELAG settings This function retrieves the DELAG settings for a specified display adapter. 
/// Supported Platforms:
///   Windows 7, 10 and above; 32bit and 64bit 
/// 
/// Parameters
///   [in]  context       Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in]  iAdapterIndex The index of the desired adapter. 
///   [out] settings      The pointer to the pointer to the DEALG data structure 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK (zero). Otherwise the return value is an ADL error code (non-zero). Result Codes
int ADL2_DELAG_Settings_Get ( ADL_CONTEXT_HANDLE   context,
                              int                  iAdapterIndex,
                              ADL_DELAG_SETTINGS * settings
                            );


/// Function to set DELAG settings This function sets the user input values to DELAG feature. 
/// Supported Platforms:
///   Windows 7, 10 and above; 32bit and 64bit 
/// 
/// Parameters
///   [in]  context       Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in]  iAdapterIndex The index of the desired adapter. 
///   [in]  settings      ADL_DELAG_SETTINGS : structure with the input values 
///   [in]  changeReason  ADL_DELAG_NOTFICATION_REASON : structure with the changed feilds in settings parameter 
///   [out] errorReason   ADL_ERROR_REASON : structure with the error feilds in settings parameter. client should refer to this feild when set call is filed. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK (zero). Otherwise the return value is an ADL error code (non-zero). Result Codes
/// 
/// Remarks
///   Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call ADL2_Main_Control_Create first to obtain ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using ADL2_Main_Control_Destroy.
int ADL2_DELAG_Settings_Set ( ADL_CONTEXT_HANDLE           context,
                              int                          iAdapterIndex,
                              ADL_DELAG_SETTINGS           settings,
                              ADL_DELAG_NOTFICATION_REASON changeReason,
                              ADL_ERROR_REASON *           errorReason
                            );


/// Function to get the unique identifier of an adapter. Will be removed! Use ADL_Adapter_ID_Get() 
/// 
/// This function retrieves the unique identifier of a specified adapter.
/// 
///  The adapter ID is a unique value and will be used to determine what other controllers share the same adapter.
/// 
///  The desktop will use this to find which HDCs are associated with an adapter. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in]  context       Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in]  iAdapterIndex The ADL index handle of the desired adapter. 
///   [out] lpAdapterID   The pointer to the adapter identifier. Zero means: The adapter is not AMD. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes 
/// 
/// Remarks
///   Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call ADL2_Main_Control_Create first to obtain ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using ADL2_Main_Control_Destroy. 
/// Deprecated:
///   This API will be removed. Use the duplicate API ADL_Adapter_ID_Get()
int ADL2_Display_AdapterID_Get ( ADL_CONTEXT_HANDLE context,
                                 int                iAdapterIndex,
                                 int *              lpAdapterID
                               );


/// This function retrieves the Compatibility Mode capability. 
/// Supported Platforms:
///   Windows 7, 10 and above; 32bit and 64bit 
/// 
/// Parameters
///   [in]  context       : Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in]  iAdapterIndex : The ADL index handle of the desired adapter. 
///   [out] lpSupported   : Integer indicating capability of the CompatibilityMode Feature Support.
int ADL2_ElmCompatibilityMode_Caps ( ADL_CONTEXT_HANDLE context,
                                     int                iAdapterIndex,
                                     int *              lpSupported,
                                     int *              lpDefault
                                   );


/// This function retrieves Compatibility Mode status. 
/// Supported Platforms:
///   Windows 7, 10 and above; 32bit and 64bit 
/// 
/// Parameters
///   [in]  context                  : Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in]  iAdapterIndex            : The ADL index handle of the desired adapter. 
///   [out] lpCompatibilityModeValue : Pointer to the current CompatibilityMode status obtained
int ADL2_ElmCompatibilityMode_Status_Get ( ADL_CONTEXT_HANDLE context,
                                           int                iAdapterIndex,
                                           int *              lpValue
                                         );


/// This function update Compatibility Mode status. 
/// Supported Platforms:
///   Windows 7, 10 and above; 32bit and 64bit 
/// 
/// Parameters
///   [in] context       : Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in] iAdapterIndex : The ADL index handle of the desired adapter. 
///   [in] iFPWValue     : CompatibilityMode status to update the current compatibility Status
int ADL2_ElmCompatibilityMode_Status_Set ( ADL_CONTEXT_HANDLE context,
                                           int                iAdapterIndex,
                                           int                iValue
                                         );


/// provides the current value of the given feature 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in]  context       Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in]  iAdapterIndex The ADL index handle of the desired adapter. 
///   [in]  iFeatureID    The Feature index of the desired feature. ADL_UIFEATURES_GROUP 
///   [out] iCurrent      The pointer to the structure storing the retrieved feature current value. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK, or an ADL error code otherwise. Result Codes
int ADL2_Feature_Settings_Get ( ADL_CONTEXT_HANDLE   context,
                                int                  iAdapterIndex,
                                ADL_UIFEATURES_GROUP iFeatureID,
                                int *                iCurrent
                              );


/// sets the current value to the given adapter 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in] context       Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in] iAdapterIndex The ADL index handle of the desired adapter. 
///   [in] iFeatureID    The Feature index of the desired feature. ADL_UIFEATURES_GROUP 
///   [in] iCurrent      The pointer to the feature current value 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK, or an ADL error code otherwise. Result Codes
int ADL2_Feature_Settings_Set ( ADL_CONTEXT_HANDLE   context,
                                int                  iAdapterIndex,
                                ADL_UIFEATURES_GROUP iFeatureID,
                                int                  iCurrent
                              );


/// Function to save driver data. 
/// 
/// This function saves all required data from driver to persist updated settings 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in] context       Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in] iAdapterIndex The adapter index to be flushed. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes 
/// 
/// Remarks
///   Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call ADL2_Main_Control_Create first to obtain ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using ADL2_Main_Control_Destroy.
int ADL2_Flush_Driver_Data ( ADL_CONTEXT_HANDLE context,
                             int                iAdapterIndex
                           );


/// Function to retrieve FPS Global Setting Capability. 
/// 
/// This function retrieves the Global Setting Capability. 
/// Supported Platforms:
///   Windows 7, 10 and above; 32bit and 64bit 
/// 
/// Parameters
///   [in]  context       : Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in]  iAdapterIndex : The ADL index handle of the desired adapter. 
///   [out] lpSupported   : Integer indicating capability of the FPS Feature Support. 
///   [out] lpVersion     : Integer indicating Feature Version.
int ADL2_FPS_Caps ( ADL_CONTEXT_HANDLE context,
                    int                iAdapterIndex,
                    int *              lpSupported,
                    int *              lpVersion
                  );


/// Function to retrieve FPS Global Settings. 
/// 
/// This function retrieves FPS Global Settings. 
/// Supported Platforms:
///   Windows 7, 10 and above; 32bit and 64bit 
/// 
/// Parameters
///   [in]  context       : Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in]  iAdapterIndex : The ADL index handle of the desired adapter. 
///   [out] lpFPSSettings : Pointer to ADLFPSSettingsOutput struct which will load the Global FPS Settings
int ADL2_FPS_Settings_Get ( ADL_CONTEXT_HANDLE     context,
                            int                    iAdapterIndex,
                            ADLFPSSettingsOutput * lpFPSSettings
                          );


/// Function to reset FPS Global Settings. 
/// 
/// This function reset FPS Global Settings. 
/// Supported Platforms:
///   Windows 7, 10 and above; 32bit and 64bit 
/// 
/// Parameters
///   [in] context       : Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in] iAdapterIndex : The ADL index handle of the desired adapter.
int ADL2_FPS_Settings_Reset ( ADL_CONTEXT_HANDLE context,
                              int                iAdapterIndex
                            );


/// Function to update FPS Global Settings. 
/// 
/// This function update FPS Global Settings. 
/// Supported Platforms:
///   Windows 7, 10 and above; 32bit and 64bit 
/// 
/// Parameters
///   [in] context       : Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in] iAdapterIndex : The ADL index handle of the desired adapter. 
///   [in] lpFPSSettings : ADLFPSSettingsInput struct which will update the Global FPS Settings
int ADL2_FPS_Settings_Set ( ADL_CONTEXT_HANDLE  context,
                            int                 iAdapterIndex,
                            ADLFPSSettingsInput lpFPSSettings
                          );


/// Supported Platforms:
///   Windows 7, 10 and above; 32bit and 64bit 
/// 
/// Parameters
///   [in]  context       Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in]  iAdapterIndex The ADL index handle of the desired adapter. The adapter identifies the ASIC that the information will be returned for. 
///   [out] gcnInfo       The ADL structure that contains information about components of ASIC GCN architecture. 
/// 
/// Remarks
///   . The method is supported only for SI+ family of the ASICs and up to Carrizzo inclusive. Otherwise ADL_ERR_NOT_SUPPORTED is returned
int ADL2_GcnAsicInfo_Get ( ADL_CONTEXT_HANDLE context,
                           int                iAdapterIndex,
                           ADLGcnInfo *       gcnInfo
                         );


/// This function retrieves the GPU VM PageSize info for a specified adapter. 
/// Supported Platforms:
///   Windows 7, 10 and above; 32bit and 64bit 
/// 
/// Parameters
///   [in]  context            Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in]  iAdapterIndex      The ADL index handle of the desired adapter. 
///   [out] iVMPageSizeSupport 1 for supported and 0 for unsupported 
///   [out] iVMPageSizeType    Type will be available only if iVMPageSizeSupport is 1. 0: Invalid; 1: Gaming; 2: Mining 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes 
/// 
/// Remarks
///   Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call ADL2_Main_Control_Create first to obtain ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using ADL2_Main_Control_Destroy.
int ADL2_GPUVMPageSize_Info_Get ( ADL_CONTEXT_HANDLE context,
                                  int                iAdapterIndex,
                                  int *              iVMPageSizeSupport,
                                  int *              iVMPageSizeType
                                );


/// This function sets the GPU VM PageSize type for a specified adapter. 
/// Supported Platforms:
///   Windows 7, 10 and above; 32bit and 64bit 
/// 
/// Parameters
///   [in] context         Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in] iAdapterIndex   The ADL index handle of the desired adapter. 
///   [in] iVMPageSizeType Type will be available only if iVMPageSizeSupport = 1. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes 
/// 
/// Remarks
///   Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call ADL2_Main_Control_Create first to obtain ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using ADL2_Main_Control_Destroy.
int ADL2_GPUVMPageSize_Info_Set ( ADL_CONTEXT_HANDLE context,
                                  int                iAdapterIndex,
                                  int                iVMPageSizeType
                                );


/// The function is used to obtain the capabilities for a set of specific Multi-Media features for a specific display adapter. 
/// Supported Platforms:
///   Windows Vista and Windows 7; 32bit and 64bit 
/// 
/// Parameters
///   [in]  context        Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in]  iAdapterIndex  The ADL index handle of the desired adapter. 
///   [in]  lppFeatureCaps The pointer to the pointer to the retrieved Feature Caps array. Initialize to NULL before calling this API. 
///   [out] lpFeatureCount The pointer to the number of ADLFeatureCaps elements in the retrieved list. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes
/// 
/// Remarks
///   This API uses the memory allocation callback function provided by the user.
int ADL2_MMD_Features_Caps ( ADL_CONTEXT_HANDLE context,
                             int                iAdapterIndex,
                             ADLFeatureCaps **  lppFeatureCaps,
                             int *              lpFeatureCount
                           );


/// The function is used to obtain the values and state of a single Multi-Media feature for a specific display adapter. 
/// Supported Platforms:
///   Windows Vista and Windows 7; 32bit and 64bit 
/// 
/// Parameters
///   [in]  context          Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in]  iAdapterIndex    The ADL index handle of the desired adapter. 
///   [out] lppFeatureValues The pointer to the pointer to the retrieved ADLFeatureValues array. Initialize to NULL before calling this API. 
///   [out] lpFeatureCount   The pointer to the number of ADLFeatureValues elements in the retrieved list. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes
/// 
/// Remarks
///   This API uses the memory allocation callback function provided by the user.
int ADL2_MMD_FeatureValues_Get ( ADL_CONTEXT_HANDLE  context,
                                 int                 iAdapterIndex,
                                 ADLFeatureValues ** lppFeatureValues,
                                 int *               lpFeatureCount
                               );


/// The function is used to set the current value of a single Multi-Media feature and optionally provide the handle of SetEvent object. 
/// Supported Platforms:
///   Windows Vista and Windows 7; 32bit and 64bit 
/// 
/// Parameters
///   [in] context         Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in] iAdapterIndex   The ADL index handle of the desired adapter. 
///   [in] lpFeatureValues A pointer to the ADLFeatureValues array. Refer to ADLFeatureValues structure for more information. 
///   [in] iFeatureCount   The number of ADLFeatureValues elements in the array. 
///   [in] ClientID        The Client ID of the caller. It is recommended to provide a valid Client ID to avoid raising caller?s event object, immediately after the current value is set. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes
/// 
/// Remarks
///   Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call ADL2_Main_Control_Create first to obtain ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using ADL2_Main_Control_Destroy.
int ADL2_MMD_FeatureValues_Set ( ADL_CONTEXT_HANDLE context,
                                 int                iAdapterIndex,
                                 ADLFeatureValues * lpFeatureValues,
                                 int                iFeatureCount,
                                 int                ClientID
                               );


/// This function retrieves PageMigration Global Settings. 
/// Supported Platforms:
///   Windows 7, 10 and above; 32bit and 64bit 
/// 
/// Parameters
///   [in]  context              : Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in]  iAdapterIndex        : The ADL index handle of the desired adapter. 
///   [out] lpVirtualSegSettings : Pointer to ADLFPSSettingsOutput struct which will load the Global FPS Settings
int ADL2_PageMigration_Settings_Get ( ADL_CONTEXT_HANDLE                context,
                                      int                               iAdapterIndex,
                                      ADLVirtualSegmentSettingsOutput * lpVirtualSegSettings
                                    );


/// This function update PageMigration Global Settings. 
/// Supported Platforms:
///   Windows 7, 10 and above; 32bit and 64bit 
/// 
/// Parameters
///   [in] context       : Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in] iAdapterIndex : The ADL index handle of the desired adapter. 
///   [in] iEnabled      : Set to true if page migration is to be enabled. Set to false if page migration is to be disabled and iNewSize will be ignored. 
///   [in] iNewSize      : New size in MB
int ADL2_PageMigration_Settings_Set ( ADL_CONTEXT_HANDLE context,
                                      int                iAdapterIndex,
                                      int                iEnabled,
                                      int                iNewSize
                                    );


/// This function retrieves the Performance Tuning capability. 
/// Supported Platforms:
///   Windows 7, 10 and above; 32bit and 64bit 
/// 
/// Parameters
///   [in]  context       : Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in]  iAdapterIndex : The ADL index handle of the desired adapter. 
///   [out] lpSupported   : Integer indicating capability of the Performance Tuning Feature Support. 
///   [out] lpDefault     : Integer indicating default Performance Tuning value
int ADL2_PerformanceTuning_Caps ( ADL_CONTEXT_HANDLE context,
                                  int                iAdapterIndex,
                                  int *              lpSupported,
                                  int *              lpDefault
                                );


/// This function retrieves Performance ui tunning status. 
/// Supported Platforms:
///   Windows 7, 10 and above; 32bit and 64bit 
/// 
/// Parameters
///   [in]  context        : Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in]  iAdapterIndex  : The ADL index handle of the desired adapter. 
///   [out] lpPTuningValue : Pointer to the current performance tuning status obtained
int ADL2_PerfTuning_Status_Get ( ADL_CONTEXT_HANDLE context,
                                 int                iAdapterIndex,
                                 int *              lpPTuningValue
                               );


/// This function update FPS Performance ui tunning status. 
/// Supported Platforms:
///   Windows 7, 10 and above; 32bit and 64bit 
/// 
/// Parameters
///   [in] context        : Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in] iAdapterIndex  : The ADL index handle of the desired adapter. 
///   [in] lpPTuningValue : performance tuning status to update the current Performance Per Watt Status
int ADL2_PerfTuning_Status_Set ( ADL_CONTEXT_HANDLE context,
                                 int                iAdapterIndex,
                                 int                lpPTuningValue
                               );


/// This function retrieves the Performance Per Watt capability. 
/// Supported Platforms:
///   Windows 7, 10 and above; 32bit and 64bit 
/// 
/// Parameters
///   [in]  context       : Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in]  iAdapterIndex : The ADL index handle of the desired adapter. 
///   [out] lpSupported   : Integer indicating capability of the PPW Feature Support.
int ADL2_PPW_Caps ( ADL_CONTEXT_HANDLE context,
                    int                iAdapterIndex,
                    int *              lpSupported,
                    int *              lpDefault
                  );


/// This function retrieves Performance Per Watt status. 
/// Supported Platforms:
///   Windows 7, 10 and above; 32bit and 64bit 
/// 
/// Parameters
///   [in]  context       : Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in]  iAdapterIndex : The ADL index handle of the desired adapter. 
///   [out] lpPPWValue    : Pointer to the current PPW status obtained
int ADL2_PPW_Status_Get ( ADL_CONTEXT_HANDLE context,
                          int                iAdapterIndex,
                          int *              lpFPWValue
                        );


/// This function update FPS Performance Per Watt status. 
/// Supported Platforms:
///   Windows 7, 10 and above; 32bit and 64bit 
/// 
/// Parameters
///   [in] context       : Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in] iAdapterIndex : The ADL index handle of the desired adapter. 
///   [in] iFPWValue     : PPW status to update the current Performance Per Watt Status
int ADL2_PPW_Status_Set ( ADL_CONTEXT_HANDLE context,
                          int                iAdapterIndex,
                          int                iFPWValue
                        );


/// Function to get the Pro VSR settings This function retrieves the Pro VSR for a specified display adapter. 
/// Supported Platforms:
///   Windows 7, 10 and above; 32bit and 64bit 
/// 
/// Parameters
///   [in]  context       Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in]  iAdapterIndex The index of the desired adapter. 
///   [out] settings      The pointer to the pointer to the VSR data structure 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK (zero). Otherwise the return value is an ADL error code (non-zero). Result Codes
int ADL2_PROVSR_Settings_Get ( ADL_CONTEXT_HANDLE    context,
                               int                   iAdapterIndex,
                               ADL_PROVSR_SETTINGS * settings
                             );


/// Function to set Pro VSR settings This function sets the user input values to VSR feature. 
/// Supported Platforms:
///   Windows 7, 10 and above; 32bit and 64bit 
/// 
/// Parameters
///   [in]  context       Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in]  iAdapterIndex The index of the desired adapter. 
///   [in]  settings      ADL_PROVSR_SETTINGS : structure with the input values 
///   [in]  changeReason  ADL_PROVSR_SETTINGS_NOTFICATION_REASON : structure with the changed feilds in settings parameter 
///   [out] errorReason   ADL_ERROR_REASON : structure with the error feilds in settings parameter. client should refer to this feild when set call is filed. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK (zero). Otherwise the return value is an ADL error code (non-zero). Result Codes
/// 
/// Remarks
///   Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call ADL2_Main_Control_Create first to obtain ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using ADL2_Main_Control_Destroy.
int ADL2_PROVSR_Settings_Set ( ADL_CONTEXT_HANDLE            context,
                               int                           iAdapterIndex,
                               ADL_PROVSR_SETTINGS           settings,
                               ADL_PROVSR_NOTFICATION_REASON changeReason,
                               ADL_ERROR_REASON *            errorReason
                             );


/// Function to get the RIS settings This function retrieves the RIS settings for a specified display adapter. 
/// Supported Platforms:
///   Windows 7, 10 and above; 32bit and 64bit 
/// 
/// Parameters
///   [in]  context       Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in]  iAdapterIndex The index of the desired adapter. 
///   [out] settings      The pointer to the pointer to the RIS data structure 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK (zero). Otherwise the return value is an ADL error code (non-zero). Result Codes
int ADL2_RIS_Settings_Get ( ADL_CONTEXT_HANDLE context,
                            int                iAdapterIndex,
                            ADL_RIS_SETTINGS * settings
                          );


/// Function to set RIS settings This function sets the user input values to RIS feature. 
/// Supported Platforms:
///   Windows 7, 10 and above; 32bit and 64bit 
/// 
/// Parameters
///   [in] context       Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in] iAdapterIndex The index of the desired adapter. 
///   [in] settings      ADL_RIS_SETTINGS : structure with the input values 
///   [in] changeReason  ADL_RIS_NOTFICATION_REASON : structure with the changed feilds in settings parameter 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK (zero). Otherwise the return value is an ADL error code (non-zero). Result Codes
/// 
/// Remarks
///   Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call ADL2_Main_Control_Create first to obtain ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using ADL2_Main_Control_Destroy.
int ADL2_RIS_Settings_Set ( ADL_CONTEXT_HANDLE         context,
                            int                        iAdapterIndex,
                            ADL_RIS_SETTINGS           settings,
                            ADL_RIS_NOTFICATION_REASON changeReason
                          );


/// This function retrieves current Stress Test overdrivecapabilities for a specified adapter. 
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
int ADL2_Stress_Test_Cap ( ADL_CONTEXT_HANDLE context,
                           int                iAdapterIndex,
                           int *              iSupported,
                           int *              iEnabled,
                           int *              iVersion
                         );


/// This function retrieves current Throttle Notification overdrivecapabilities for a specified adapter. 
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
int ADL2_Throttle_Notification_Cap ( ADL_CONTEXT_HANDLE context,
                                     int                iAdapterIndex,
                                     int *              iSupported,
                                     int *              iEnabled,
                                     int *              iVersion
                                   );


/// Function to get the EDID Persistence state of the system. 
/// 
/// This function implements the functionality to get the EDID Persistence state of the system. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in]  context          Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [out] lpCurResultValue The int pointer to the current state It can be one of Define_persistence_state 
///   [out] lpDefResultValue The int pointer to the default state It can be one of Define_persistence_state 
/// 
/// Returns
///   If the function is successful, ADL_OK is returned. ADL_OK_MODE_CHANGE if success but need mode change,
/// If the function is not supported, ADL_ERR_NOT_SUPPORTED is returned. For all other errors, ADL_ERR is returned. 
/// 
/// Remarks
///   Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call ADL2_Main_Control_Create first to obtain ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using ADL2_Main_Control_Destroy.
int ADL2_Workstation_GlobalEDIDPersistence_Get ( ADL_CONTEXT_HANDLE context,
                                                 int *              lpCurResultValue,
                                                 int *              lpDefResultValue
                                               );


/// Function to set the EDID Persistence state of the system. 
/// 
/// This function implements the functionality to set the EDID Persistence mode for a system. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in] context   Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in] iCurState The current state to set for the specified adapter. Define_persistence_state 
/// 
/// Returns
///   If the function is successful, ADL_OK is returned. ADL_OK_MODE_CHANGE if success but need mode change,
/// If the function is not supported, ADL_ERR_NOT_SUPPORTED is returned. For all other errors, ADL_ERR is returned. 
/// 
/// Remarks
///   Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call ADL2_Main_Control_Create first to obtain ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using ADL2_Main_Control_Destroy.
int ADL2_Workstation_GlobalEDIDPersistence_Set ( ADL_CONTEXT_HANDLE context,
                                                 int                iCurState
                                               );


/// Function to check if the GPU is accessible or not at the time of this call. 
/// 
/// Some GPUs enter into various power savings mode when not in use, and during this time, direct access to the GPU can result in failures. Access through proper channels (such as via ADL) always works because the software accounts for the GPU's accessibility. However, direct access outside of authorised mechanisms may fail. Use this API to find out if the GPU is currently accessible or not. If API returns GPU accessible, this status will be maintained for 2 seconds.
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in]  iAdapterIndex   The ADL index handle of the desired adapter. 
///   [out] lpAccessibility The pointer to an int value which indicates if the adapter is accessible or not (ADL_TRUE : Accessible, ADL_FALSE : Not accessible) 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes
int ADL_Adapter_Accessibility_Get ( int   iAdapterIndex,
                                    int * lpAccessibility
                                  );


/// Function to determine if the adapter is active or not. 
/// 
/// The function is used to check if the adapter associated with iAdapterIndex is active. Logic is different for Windows and Linux! 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in]  iAdapterIndex The ADL index handle of the desired adapter. 
///   [out] lpStatus      The pointer to the retrieved status. ADL_TRUE : Active; ADL_FALSE : Disabled. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes
int ADL_Adapter_Active_Get ( int   iAdapterIndex,
                             int * lpStatus
                           );


/// Function to set the current extended desktop mode status for a display. 
/// 
/// This function enables or disables extended desktop mode for a specified display. 
/// Supported Platforms:
///   Windows 7, 10 and above; 32bit and 64bit 
/// 
/// Parameters
///   [in]  iAdapterIndex   The ADL index handle of the desired adapter. 
///   [in]  iStatus         The desired display extended desktop mode status. ADL_TRUE : extended desktop mode; ADL_FALSE : otherwise. 
///   [out] lpNewlyActivate The pointer to the retrieved adapter activation information. ADL_TRUE : the adapter is activated for the first time; ADL_FALSE : otherwise. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes
int ADL_Adapter_Active_Set ( int   iAdapterIndex,
                             int   iStatus,
                             int * lpNewlyActivate
                           );


/// Function to set the current extended desktop mode status for the display. 
/// 
/// This function enables or disables the input adapter for a specified display. In addition, this function allows the user to enable the input adapter and pass in the preferred targets. 
/// Supported Platforms:
///   Windows 7, 10 and above; 32bit and 64bit 
/// 
/// Parameters
///   [in]  iAdapterIndex    The ADL index handle of the desired adapter. 
///   [in]  iStatus          The desired display extended desktop mode status. ADL_TRUE : extended desktop mode; ADL_FALSE : otherwise. 
///   [in]  iNumPreferTarget If iStatus is TRUE, the user can pass the size of preferred Display Targets array. 
///   [in]  lpPreferTarget   If iStatus is TRUE, the user can pass the preferred Display Targets array to be enabled (with targets cloned). 
///   [out] lpNewlyActivate  The pointer to the retrieved adapter activation information. ADL_TRUE : the adapter is activated for the first time; ADL_FALSE : otherwise. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes
int ADL_Adapter_Active_SetPrefer ( int                iAdapterIndex,
                                   int                iStatus,
                                   int                iNumPreferTarget,
                                   ADLDisplayTarget * lpPreferTarget,
                                   int *              lpNewlyActivate
                                 );


/// Retrieves all OS-known adapter information. 
/// 
/// This function retrieves the adapter information of all OS-known adapters in the system. OS-known adapters can include adapters that are physically present in the system (logical adapters) 
/// 
///  as well as ones that are no longer present in the system but are still recognized by the OS. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in]  iInputSize The size of the lpInfo buffer. 
///   [out] lpInfo     The pointer to the buffer containing the retrieved adapter information. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes 
/// 
/// 
/// Remarks
///   This API take a fixed-size output array. For dynamic-size output, use ADL_Adapter_AdapterInfoX2_Get function.
int ADL_Adapter_AdapterInfo_Get ( LPAdapterInfo lpInfo,
                                  int           iInputSize
                                );


/// Retrieves all OS-known adapter information. 
/// 
/// This function retrieves the adapter information of all OS-known adapters in the system. OS-known adapters can include adapters that are physically present in the system (logical adapters) 
/// 
///  as well as ones that are no longer present in the system but are still recognized by the OS. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [out] lppAdapterInfo is pointer to the pointer of AdapterInfo array. Initialize to NULL before calling this API. ADL will allocate the necessary memory, using the user provided callback function. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes
/// 
/// Remarks
///   This API uses the memory allocation callback function provided by the user.
int ADL_Adapter_AdapterInfoX2_Get ( );


/// This function disable multiple adapters in one CCD call for Win7 and later in order to improve the performace. the fucntion will fail if the current primary adapter is in the disabled adapter list 
/// Supported Platforms:
///   Windows 7; 32bit and 64bit,WIN8 
/// 
/// Parameters
///   [in] iNumAdapters       An integer indicates the number of desktops to be disabled. 
///   [in] lpAdapterIndexList The pointer to the integer array that contains the list of logicl adapter indexes to be disabled 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes
int ADL_Adapter_AdapterList_Disable ( int   iNumAdapters,
                                      int * lpAdapterIndexList
                                    );


/// Function to get the ASICFamilyType from the adapter. 
/// 
/// This function retrieves the ASIC family types for a specified adapter. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in]  iAdapterIndex The ADL index handle of the desired adapter. 
///   [out] lpAsicTypes   The pointer to the Detailed asic types information retrieved from the driver. 
///   [out] lpValids      The pointer to the bit vector indicating which bit is valid on the lpAsicTypes returned. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK (zero). Otherwise the return value is an ADL error code (non-zero). Result Codes
int ADL_Adapter_ASICFamilyType_Get ( int   iAdapterIndex,
                                     int * lpAsicTypes,
                                     int * lpValids
                                   );


/// ADL local interface. Function to retrieve the supported aspects list. 
/// 
/// This function retrieves the list of supported aspects for a specified adapter. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in]  iAdapterIndex The ADL index handle of the desired adapter. 
///   [out] lpAspects     The pointer to the buffer storing the list of aspects supported for the specified adapter. 
///   [in]  iSize         The size of the lpAspects buffer. 
/// 
/// Returns
///   If the function valid, the return value is 1. Otherwise it is 0.
int ADL_Adapter_Aspects_Get ( int    iAdapterIndex,
                              char * lpAspects,
                              int    iSize
                            );


/// This function retrieves the Big Software & Red Stone support information for a specified adapter. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in]  iAdapterIndex       The ADL index handle of the desired adapter. 
///   [out] lpBigSwSupportMajor The pointer to the Big Software major version information retrieved from the driver. Detailed asic types 
///   [out] lpBigSwSupportMinor The pointer to the Big Software minor version information retrieved from the driver. Detailed asic types 
///   [out] lpRedStoneSupport   The pointer to the Red Stone support information retrieved from the driver. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK (zero). Otherwise the return value is an ADL error code (non-zero). Result Codes
int ADL_Adapter_BigSw_Info_Get ( int   iAdapterIndex,
                                 int * lpBigSwSupportMajor,
                                 int * lpBigSwSupportMinor,
                                 int * lpRedStoneSupport
                               );


/// Function to get the board layout information. 
/// 
/// This function retrieves the ASIC layout information of a specified adapter.
/// 
///  layout information includes number of slots, size and number of connectors and properties of connectors 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in]  iAdapterIndex     The ADL index handle of the desired adapter. 
///   [out] lpValidFlags      The integer pointer, specifies the valid bits of the slot & connector information. 
///   [out] lpNumberSlots     The integer pointer, specifies the number of slots 
///   [out] lppBracketSlot    The pointer to the structure, storing the bracket slot information. 
///   [out] lpNumberConnector The integer pointer, specifies the number of connectors in GPU 
///   [out] lppConnector      The pointer to the structure, storing the connectors information 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes
int ADL_Adapter_BoardLayout_Get ( int                   iAdapterIndex,
                                  int *                 lpValidFlags,
                                  int *                 lpNumberSlots,
                                  ADLBracketSlotInfo ** lppBracketSlot,
                                  int *                 lpNumberConnector,
                                  ADLConnectorInfo **   lppConnector
                                );


/// This function implements a DI call to retrieve adapter capability information . 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in]  iAdapterIndex The ADL index handle of the desired adapter. 
///   [out] adapterCaps   The pointer to the structure storing the retrieved adapter capability information. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK, or an ADL error code otherwise. Result Codes
int ADL_Adapter_Caps ( int              iAdapterIndex,
                       ADLAdapterCaps * adapterCaps
                     );


/// This function retrieves the chipset information for a specified adapter. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in]  iAdapterIndex The ADL index handle of the desired adapter. 
///   [out] lpChipSetInfo The pointer to the structure storing the retrieved chipset information. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes
int ADL_Adapter_ChipSetInfo_Get ( int              iAdapterIndex,
                                  ADLChipSetInfo * lpChipSetInfo
                                );


/// Function to retrieve clock information for an adapter. 
/// 
/// This function retrieves the clock information for a specified graphics adapter. Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// Parameters
///   [in]  iAdapterIndex The ADL index handle of the desired adapter. 
///   [out] lpClockInfo   The pointer to the structure storing the retrieved core and memory clock information. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes 
/// 
/// 
/// Deprecated:
///   This API has been deprecated because it does not provide accurate clocks when the ASIC is over-clocked. Use the OD5 set of APIs, when OverDrive5 is supported.
int ADL_Adapter_ClockInfo_Get ( int            iAdapterIndex,
                                ADLClockInfo * lpClockInfo
                              );


/// Function to gets the emulation data on specified connector. 
/// 
/// This function to gets the emulation data 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in]  iAdapterIndex    The ADL index handle of the desired adapter. 
///   [in]  devicePort       specifies connector index and relative MST address. 
///   [in]  iQueryType       The Specifies type of query. Define_emulation_query 
///   [out] lpConnectionData The pointer to the structure storing the retrieved information. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes
int ADL_Adapter_ConnectionData_Get ( int                 iAdapterIndex,
                                     ADLDevicePort       devicePort,
                                     int                 iQueryType,
                                     ADLConnectionData * lpConnectionData
                                   );


/// Function to remove emulation on specified connector. 
/// 
/// This function removes the emulation which are emulated already 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in] iAdapterIndex The ADL index handle of the desired adapter. 
///   [in] devicePort    specifies connector index and relative mst address. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes
int ADL_Adapter_ConnectionData_Remove ( int           iAdapterIndex,
                                        ADLDevicePort devicePort
                                      );


/// Function to set the emulation data to on specified connector. 
/// 
/// This function sets the emulation data 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in] iAdapterIndex  The ADL index handle of the desired adapter. 
///   [in] devicePort     specifies connector index and relative MST address. 
///   [in] ConnectionData contains connection data including the EDID data 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes
int ADL_Adapter_ConnectionData_Set ( int               iAdapterIndex,
                                     ADLDevicePort     devicePort,
                                     ADLConnectionData ConnectionData
                                   );


/// Function to get the current emulation state of a given connector. 
/// 
/// This function retrieves the current emulation state 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in]  iAdapterIndex        The ADL index handle of the desired adapter. 
///   [in]  devicePort           specifies connector index and relative MST address. 
///   [out] lpADLConnectionState The pointer to the structure storing the retrieved information. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes
int ADL_Adapter_ConnectionState_Get ( int                  iAdapterIndex,
                                      ADLDevicePort        devicePort,
                                      ADLConnectionState * lpADLConnectionState
                                    );


/// Function to retrieve CrossfireX capabilities of the system. 
/// 
/// This function is used to determine if the system is capable of doing CrossfireX, regardless if the system is setup properly. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in]  iAdapterIndex   The ADL index handle of the desired adapter to query CrossfireX capabilities 
///   [out] lpPreferred     The index of the preferred CrossfireX chain. The index is a zero based index reference in the ADLCrossfireComb list. 
///   [out] lpNumComb       The integer value indicating the number of ADLCrossfireComb structures in the lpCrossfireComb buffer 
///   [out] ppCrossfireComb The Pointer to an empty memory buffer(NULL). This function will use the callback to allocate the appropriate buffer size. This buffer will contain a list of supported CrossfireX combinations if the adapter supports CrossfireX. If the adapter does not support CrossfireX, this memory buffer will remain empty, or NULL. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK (zero). Otherwise the return value is an ADL error code (non-zero). Result Codes
/// 
/// Remarks
///   This API uses the memory allocation callback function provided by the user.
int ADL_Adapter_Crossfire_Caps ( int                 iAdapterIndex,
                                 int *               lpPreferred,
                                 int *               lpNumComb,
                                 ADLCrossfireComb ** ppCrossfireComb
                               );


/// This function is used to retrieve the current information about a particular CrossfireX combination. A CrossfireX combination includes the CrossfireX capable adapter and its CrossfireX chain (a list of other adapters that will work with the CrossfireX capable adapter). The possible CrossfireX chain combinations for an adapter is retrieved from the ADL_Adapter_Crossfire_Caps function. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in]  iAdapterIndex   The ADL index of the CrossfireX capable adapter to query the CrossfireX state and current information 
///   [in]  lpCrossfireComb The CrossfireX chain to get information about. 
///   [out] lpCrossfireInfo State and error information about the CrossfireX combination. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK (zero). Otherwise the return value is an ADL error code (non-zero). Result Codes
int ADL_Adapter_Crossfire_Get ( int                iAdapterIndex,
                                ADLCrossfireComb * lpCrossfireComb,
                                ADLCrossfireInfo * lpCrossfireInfo
                              );


/// Function to set CrossfireX combination settings. 
/// 
/// This function is used to enable or disable CrossfireX on a particular adapter (pointed to by iAdapterIndex), along with the indicated CrossfireX chain. The CrossfireX chain combination for the adapter must be one returned by ADL_Adapter_Crossfire_Caps(). 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in] iAdapterIndex   The adapter in which to enable or disable CrossfireX 
///   [in] lpCrossfireComb the CrossfireX chain combination to enable or disable for the master adapter. If this parameter is not NULL, it will enable CrossfireX with the indicated combination. If this parameter is NULL, it will disable CrossfireX on that particular adapter. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK (zero). Otherwise the return value is an ADL error code (non-zero). Result Codes
int ADL_Adapter_Crossfire_Set ( int                iAdapterIndex,
                                ADLCrossfireComb * lpCrossfireComb
                              );


/// Function to get current CrossfireX settings for both QUAD and Software crossfire. 
/// 
/// On QUAD Crossfire systems this function is used to retrieve the current information about a particular CrossfireX combination. A CrossfireX combination includes the CrossfireX capable adapter and its CrossfireX chain (a list of other adapters that will work with the CrossfireX capable adapter). The possible CrossfireX chain combinations for an adapter is retrieved from the ADL_Adapter_Crossfire_Caps function. On Software Crossfire systems this function is used to query support and status of Crossfire. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in]  iAdapterIndex   The ADL index of the CrossfireX capable adapter to query the CrossfireX state and current information 
///   [in]  lpCrossfireComb The CrossfireX chain to get information about. Ignored when called for Software crossfire 
///   [out] lpCrossfireInfo State and error information about the CrossfireX combination. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK (zero). Otherwise the return value is an ADL error code (non-zero). Result Codes
int ADL_Adapter_CrossfireX2_Get ( int                iAdapterIndex,
                                  ADLCrossfireComb * lpCrossfireComb,
                                  ADLCrossfireInfo * lpCrossfireInfo
                                );


/// Function to retrieve EDID management feature support. 
/// 
/// This function retrieves EDID Management supprot for specific adapter. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in]  iAdapterIndex The ADL index handle of the desired adapter. 
///   [out] lpSupported   If the specified adapter supports EDID Management then returns ADL_TRUE else ADL_FALSE 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes
int ADL_Adapter_EDIDManagement_Caps ( int   iAdapterIndex,
                                      int * lpSupported
                                    );


/// Function to sets the emulation mode of given connector. 
/// 
/// This function set the emulation mode to the driver 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in] iAdapterIndex  The ADL index handle of the desired adapter. 
///   [in] devicePort     specifies connector index and relative MST address. 
///   [in] iEmulationMode selected Emulated mode. Define_emulation_mode 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes
int ADL_Adapter_EmulationMode_Set ( int           iAdapterIndex,
                                    ADLDevicePort devicePort,
                                    int           iEmulationMode
                                  );


/// Function to get the unique identifier of an adapter. 
/// 
/// This function retrieves the unique identifier of a specified adapter.
/// 
///  The adapter ID is a unique value and will be used to determine what other controllers share the same adapter.
/// 
///  The desktop will use this to find which HDCs are associated with an adapter. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in]  iAdapterIndex The ADL index handle of the desired adapter. 
///   [out] lpAdapterID   The pointer to the adapter identifier. Zero means: The adapter is not AMD. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes
/// 
/// Remarks
///   This API is a duplicate to ADL_Display_AdapterID_Get()
int ADL_Adapter_ID_Get ( int   iAdapterIndex,
                         int * lpAdapterID
                       );


/// This function retrieves the memory information for a specified graphics adapter. 
/// Supported Platforms:
///   Linux; 32bit and 64bit 
/// 
/// Parameters
///   [in]  iAdapterIndex The ADL index handle of the desired adapter. 
///   [out] lpMemoryInfo2 The pointer to the structure storing the retrieved memory information. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes
int ADL_Adapter_MemoryInfo2_Get ( int              iAdapterIndex,
                                  ADLMemoryInfo2 * lpMemoryInfo2
                                );


/// This function re-enumerates adapter modes 
/// Supported Platforms:
///   \Win7 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes 
/// 
/// Remarks
///   For Win7 only. This internal AMD API is used to test driver's SLS middle mode feature.
int ADL_Adapter_Modes_ReEnumerate ( );


/// Function to perform a mode switch for an adapter. 
/// 
/// This function performs a mode switch for a specified adapter. 
/// Supported Platforms:
///   Windows 7, 10 and above; 32bit and 64bit 
/// 
/// Parameters
///   [in] iAdapterIndex The ADL index handle of the desired adapter. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes
int ADL_Adapter_ModeSwitch ( );


/// Function to retrieve the number of OS-known adapters. 
/// 
/// This function retrieves the number of graphics adapters recognized by the OS (OS-known adapters). OS-known adapters can include adapters that are physically present in the system (logical adapters) 
/// 
///  as well as ones that no longer present in the system but are still recognized by the OS. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [out] lpNumAdapters The pointer to the number of OS-known adapters. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes
int ADL_Adapter_NumberOfAdapters_Get ( );


/// Function to get the core and memory clock info of an adapter.  This is the clock displayed on CCC information center.          Specific logic is used to select appropriate clock for display in current configuration. 
/// 
/// This function retrieves the core and memory clock of an adapter. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in]  iAdapterIndex The ADL index handle of the desired adapter. 
///   [out] lpCoreClock   The pointer to the core clock retrieved from the driver in Mhz. 
///   [out] lpMemoryClock The pointer to the memory clock retrieved from the driver in Mhz. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK (zero). Otherwise the return value is an ADL error code (non-zero). Result Codes
int ADL_Adapter_ObservedClockInfo_Get ( int   iAdapterIndex,
                                        int * lpCoreClock,
                                        int * lpMemoryClock
                                      );


/// Function to get the base, game, boost and memory clock info of an adapter.          Specific logic is used to select appropriate clock for display in current configuration. 
/// 
/// This function retrieves the game, base, boost and memory clock of an adapter. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in] context Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in]
int ADL_Adapter_ObservedGameClockInfo_Get ( ADL_CONTEXT_HANDLE context,
                                            int                iAdapterIndex,
                                            int *              lpBaseClock,
                                            int *              lpGameClock,
                                            int *              lpBoostClock,
                                            int *              lpMemoryClock
                                          );


/// Function to retrieve the primary display adapter index. 
/// 
/// This function retrieves the adapter index for the primary display adapter. 
/// Supported Platforms:
///   Windows 7, 10 and above; 32bit and 64bit 
/// 
/// Parameters
///   [out] lpPrimaryAdapterIndex The pointer to the ADL index handle of the primary adapter. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes
int ADL_Adapter_Primary_Get ( );


/// Function to set the primary display adapter index. 
/// 
/// This function sets the adapter index for a specified primary display adapter. 
/// Supported Platforms:
///   Windows 7, 10 and above; 32bit and 64bit 
/// 
/// Parameters
///   [in] iAdapterIndex The ADL index handle of the desired adapter. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes
int ADL_Adapter_Primary_Set ( );


/// ADL local interface. Function to query a integer registry value set by driver. 
/// 
/// This function queries a driver registry integer value for a specified adapter by specifying the subkey path and key name. 
/// Supported Platforms:
///   Windows 7, 10 and above; 32bit and 64bit 
/// 
/// Parameters
///   [in]  iAdapterIndex     The ADL index handle of the desired adapter. 
///   [in]  iDriverPathOption The option of the driver path. 0: Current; 1: function1; 2: function2; 0xFFFF for all device. 
///   [in]  szSubKey          The path of registry subkey to be accessed. This is a null terminated string and the parameter can be NULL. 
///   [in]  szKeyName         The name of registry value to be got. This is a null terminated string. 
///   [out] lpKeyValue        The pointer to registry value to be got. 
/// 
/// Returns
///   If the function valid, the return value is 1. Otherwise it is 0.
int ADL_Adapter_RegValueInt_Get ( int    iAdapterIndex,
                                  int    iDriverPathOption,
                                  char * szSubKey,
                                  char * szKeyName,
                                  int *  lpKeyValue
                                );


/// ADL local interface. Function to set a driver registry integer value. 
/// 
/// This function sets a driver registry integer value for a specified adapter by specifying the subkey path and key name. 
/// Supported Platforms:
///   Windows 7, 10 and above; 32bit and 64bit 
/// 
/// Parameters
///   [in] iAdapterIndex     The ADL index handle of the desired adapter. 
///   [in] iDriverPathOption The option of the driver path. 0: Current; 1: function1; 2: function2; 0xFFFF for all device. 
///   [in] szSubKey          The path of registry subkey to be accessed. This is a null terminated string and the parameter can be NULL. 
///   [in] szKeyName         The name of registry value to be set. This is a null terminated string. 
///   [in] iKeyValue         The integer registry value to be set. 
/// 
/// Returns
///   If the function valid, the return value is 1. Otherwise it is 0.
int ADL_Adapter_RegValueInt_Set ( int    iAdapterIndex,
                                  int    iDriverPathOption,
                                  char * szSubKey,
                                  char * szKeyName,
                                  int    iKeyValue
                                );


/// ADL local interface. Function to query a string registry value set by driver. 
/// 
/// This function queries a driver registry string value for a specified adapter by specifying the subkey path and key name. 
/// Supported Platforms:
///   Windows 7, 10 and above; 32bit and 64bit 
/// 
/// Parameters
///   [in]  iAdapterIndex     The ADL index handle of the desired adapter. 
///   [in]  iDriverPathOption The option of the driver path. 0: Current; 1: function1; 2: function2; 0xFFFF for all device. 
///   [in]  szSubKey          The path of registry sub key to be accessed. This is a null terminated string and the parameter can be NULL. 
///   [in]  szKeyName         The name of registry value to be got. This is a null terminated string. 
///   [in]  iSize             The size of registry value to be got. 
///   [out] lpKeyValue        The pointer to registry value to be got. 
/// 
/// Returns
///   If the function valid, the return value is 1. Otherwise it is 0.
int ADL_Adapter_RegValueString_Get ( int    iAdapterIndex,
                                     int    iDriverPathOption,
                                     char * szSubKey,
                                     char * szKeyName,
                                     int    iSize,
                                     char * lpKeyValue
                                   );


/// ADL local interface. Function to set a driver registry string value. 
/// 
/// This function sets a driver registry string value for a specified adapter by specifying the subkey path and key name. 
/// Supported Platforms:
///   Windows 7, 10 and above; 32bit and 64bit 
/// 
/// Parameters
///   [in] iAdapterIndex     The ADL index handle of the desired adapter. 
///   [in] iDriverPathOption The option of the driver path. 0: Current; 1: function1; 2: function2; 0xFFFF for all device. 
///   [in] szSubKey          The path of registry sub key to be accessed. This is a null terminated string and the parameter can be NULL. 
///   [in] szKeyName         The name of registry value to be set. This is a null terminated string. 
///   [in] iSize             The size of registry value to be set. 
///   [in] lpKeyValue        The pointer to registry value to be set. 
/// 
/// Returns
///   If the function valid, the return value is 1. Otherwise it is 0.
int ADL_Adapter_RegValueString_Set ( int    iAdapterIndex,
                                     int    iDriverPathOption,
                                     char * szSubKey,
                                     char * szKeyName,
                                     int    iSize,
                                     char * lpKeyValue
                                   );


/// Function to get the current Force3DClock setting from the adapter. 
/// 
/// This function retrieves the adapter speed information for a specified adapter. Return valud can be ADL_ADAPTER_SPEEDCAPS_SUPPORTED or “0” 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in]  iAdapterIndex The ADL index handle of the desired adapter. 
///   [out] lpCaps        The caps of adapter speed settings 
///   [out] lpValid       The valid bits of adapter speed settings 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK (zero). Otherwise the return value is an ADL error code (non-zero). Result Codes
int ADL_Adapter_Speed_Caps ( int   iAdapterIndex,
                             int * lpCaps,
                             int * lpValid
                           );


/// Function to get the current Speed setting from the adapter. 
/// 
/// This function retrieves the adapter speed information for a specified adapter. Return value is either ADL_CONTEXT_SPEED_UNFORCED or ADL_CONTEXT_SPEED_FORCEHIGH 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in]  iAdapterIndex The ADL index handle of the desired adapter. 
///   [out] lpCurrent     The current speed setting 
///   [out] lpDefault     The default speed setting 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK (zero). Otherwise the return value is an ADL error code (non-zero). Result Codes
int ADL_Adapter_Speed_Get ( int   iAdapterIndex,
                            int * lpCurrent,
                            int * lpDefault
                          );


/// Function to set the current Speed setting from the adapter. 
/// 
/// This function set the adapter speed information for a specified adapter. Input value is either ADL_CONTEXT_SPEED_UNFORCED or ADL_CONTEXT_SPEED_FORCEHIGH 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in] iAdapterIndex The ADL index handle of the desired adapter. 
///   [in] iSpeed        The speed to set on specified adapter 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK (zero). Otherwise the return value is an ADL error code (non-zero). Result Codes
int ADL_Adapter_Speed_Set ( int iAdapterIndex,
                            int iSpeed
                          );


/// Function to get the supported connection types of given connector. 
/// 
/// This function retrieves the supported connection types and its properties 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in]  iAdapterIndex             The ADL index handle of the desired adapter. 
///   [in]  devicePort                specifies connector index and relative MST address. 
///   [out] lpADLSupportedConnections The pointer to the structure storing the retrieved information. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes
int ADL_Adapter_SupportedConnections_Get ( int                       iAdapterIndex,
                                           ADLDevicePort             devicePort,
                                           ADLSupportedConnections * lpADLSupportedConnections
                                         );


/// ADL local interface. Function to retrieve BIOS information. 
/// 
/// This function retrieves the BIOS information for a specified adapter. 
/// Supported Platforms:
///   Linux; 32bit and 64bit 
/// 
/// Parameters
///   [in]  iAdapterIndex The ADL index handle of the desired adapter. 
///   [out] lpBiosInfo    The pointer to the structure storing the retrieved BIOs information. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes
int ADL_Adapter_VideoBiosInfo_Get ( int           iAdapterIndex,
                                    ADLBiosInfo * lpBiosInfo
                                  );


/// Function to get MM video theater mode info. 
/// 
/// The function is used to get multi-media video theater mode information.
/// Supported Platforms:
///   Windows Vista and Windows 7; 32bit and 64bit 
/// 
/// Parameters
///   [in]  iAdapterIndex        The ADL index handle of the desired adapter. 
///   [out] lpOverlayDisplayMode The pointer to the overlay display mode. 
///   [out] lpSavedSettings      The pointer to the saved settings of the related mode. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes
int ADL_Adapter_VideoTheaterModeInfo_Get ( int   iAdapterIndex,
                                           int * lpOverlayDisplayMode,
                                           int * lpSavedSettings
                                         );


/// Function to set MM video theater mode info. 
/// 
/// The function is used to set multi-media video theater mode information.
/// Supported Platforms:
///   Windows Vista and Windows 7; 32bit and 64bit 
/// 
/// Parameters
///   [in] iAdapterIndex       The ADL index handle of the desired adapter. 
///   [in] iOverlayDisplayMode The overlay display mode to be set. 
///   [in] iSavedSettings      The saved settings of the related mode to be set. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes
int ADL_Adapter_VideoTheaterModeInfo_Set ( int iAdapterIndex,
                                           int iOverlayDisplayMode,
                                           int iSavedSettings
                                         );


/// Function to retrieve adapter caps information. 
/// 
/// This function implements a DI call to retrieve adapter capability information . 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in]  iAdapterIndex The ADL index handle of the desired adapter. 
///   [out] adapterCaps   The pointer to the structure storing the retrieved adapter capability information. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK, or an ADL error code otherwise. Result Codes
int ADL_AdapterX2_Caps ( int                iAdapterIndex,
                         ADLAdapterCapsX2 * adapterCaps
                       );


/// Function to get the unique identifier of an adapter. Will be removed! Use ADL_Adapter_ID_Get() 
/// 
/// This function retrieves the unique identifier of a specified adapter.
/// 
///  The adapter ID is a unique value and will be used to determine what other controllers share the same adapter.
/// 
///  The desktop will use this to find which HDCs are associated with an adapter. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in]  iAdapterIndex The ADL index handle of the desired adapter. 
///   [out] lpAdapterID   The pointer to the adapter identifier. Zero means: The adapter is not AMD. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes 
/// 
/// Deprecated:
///   This API will be removed. Use the duplicate API ADL_Adapter_ID_Get()
int ADL_Display_AdapterID_Get ( int   iAdapterIndex,
                                int * lpAdapterID
                              );


/// Function to save driver data. 
/// 
/// This function saves all required data from driver to persist updated settings 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in] iAdapterIndex The adapter index to be flushed. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes
int ADL_Flush_Driver_Data ( );


/// The function is used to obtain the capabilities for a set of specific Multi-Media features for a specific display adapter. 
/// Supported Platforms:
///   Windows Vista and Windows 7; 32bit and 64bit 
/// 
/// Parameters
///   [in]  iAdapterIndex  The ADL index handle of the desired adapter. 
///   [in]  lppFeatureCaps The pointer to the pointer to the retrieved Feature Caps array. Initialize to NULL before calling this API. 
///   [out] lpFeatureCount The pointer to the number of ADLFeatureCaps elements in the retrieved list. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes
/// 
/// Remarks
///   This API uses the memory allocation callback function provided by the user.
int ADL_MMD_Features_Caps ( int               iAdapterIndex,
                            ADLFeatureCaps ** lppFeatureCaps,
                            int *             lpFeatureCount
                          );


/// The function is used to obtain the values and state of a single Multi-Media feature for a specific display adapter. 
/// Supported Platforms:
///   Windows Vista and Windows 7; 32bit and 64bit 
/// 
/// Parameters
///   [in]  iAdapterIndex    The ADL index handle of the desired adapter. 
///   [out] lppFeatureValues The pointer to the pointer to the retrieved ADLFeatureValues array. Initialize to NULL before calling this API. 
///   [out] lpFeatureCount   The pointer to the number of ADLFeatureValues elements in the retrieved list. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes
/// 
/// Remarks
///   This API uses the memory allocation callback function provided by the user.
int ADL_MMD_FeatureValues_Get ( int                 iAdapterIndex,
                                ADLFeatureValues ** lppFeatureValues,
                                int *               lpFeatureCount
                              );


/// The function is used to set the current value of a single Multi-Media feature and optionally provide the handle of SetEvent object. 
/// Supported Platforms:
///   Windows Vista and Windows 7; 32bit and 64bit 
/// 
/// Parameters
///   [in] iAdapterIndex   The ADL index handle of the desired adapter. 
///   [in] lpFeatureValues A pointer to the ADLFeatureValues array. Refer to ADLFeatureValues structure for more information. 
///   [in] iFeatureCount   The number of ADLFeatureValues elements in the array. 
///   [in] ClientID        The Client ID of the caller. It is recommended to provide a valid Client ID to avoid raising caller?s event object, immediately after the current value is set. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes
int ADL_MMD_FeatureValues_Set ( int                iAdapterIndex,
                                ADLFeatureValues * lpFeatureValues,
                                int                iFeatureCount,
                                int                ClientID
                              );


/// Function to get the EDID Persistence state of the system. 
/// 
/// This function implements the functionality to get the EDID Persistence state of the system. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [out] lpCurResultValue The int pointer to the current state It can be one of Define_persistence_state 
///   [out] lpDefResultValue The int pointer to the default state It can be one of Define_persistence_state 
/// 
/// Returns
///   If the function is successful, ADL_OK is returned. ADL_OK_MODE_CHANGE if success but need mode change,
/// If the function is not supported, ADL_ERR_NOT_SUPPORTED is returned. For all other errors, ADL_ERR is returned.
int ADL_Workstation_GlobalEDIDPersistence_Get ( int * lpCurResultValue,
                                                int * lpDefResultValue
                                              );


/// Function to set the EDID Persistence state of the system. 
/// 
/// This function implements the functionality to set the EDID Persistence mode for a system. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in] iCurState The current state to set for the specified adapter. Define_persistence_state 
/// 
/// Returns
///   If the function is successful, ADL_OK is returned. ADL_OK_MODE_CHANGE if success but need mode change,
/// If the function is not supported, ADL_ERR_NOT_SUPPORTED is returned. For all other errors, ADL_ERR is returned.
int ADL_Workstation_GlobalEDIDPersistence_Set ( );


#endif /* ADL_HEADER_ADAPTER_H_ */
