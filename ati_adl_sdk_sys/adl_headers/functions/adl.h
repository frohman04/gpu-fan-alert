#ifndef ADL_HEADER_ADL_H_
#define ADL_HEADER_ADL_H_

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

/// Function to initialize the ADL2 interface and to obtain client's context handle. 
/// 
/// Clients can use ADL2 versions of ADL APIs to assure that there is no interference with other ADL clients that are running in the same process. Such clients have to call ADL2_Main_Control_Create first to obtain ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using ADL2_Main_Control_Destroy. ADL initialized using ADL2_Main_Control_Create will not enforce serialization of ADL API executions by multiple threads. Multiple threads will be allowed to enter to ADL at the same time. Note that ADL library is not guaranteed to be thread-safe. Client that calls ADL2_Main_Control_Create have to provide its own mechanism for ADL calls serialization. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in]  callback               The memory allocation function for memory buffer allocation. This must be provided by the user. ADL internally uses this callback to allocate memory for the output parameters returned to the user and user is responsible to free the memory once used for these parameters. ADL internal takes care of allocating and de allocating the memory for its local variables. 
///   [in]  iEnumConnectedAdapters Specify a value of 0 to retrieve adapter information for all adapters that have ever been present in the system. Specify a value of 1 to retrieve adapter information only for adapters that are physically present and enabled in the system. 
///   [out] context                ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using ADL2_Main_Control_Destroy. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes
int ADL2_Main_Control_Create ( ADL_MAIN_MALLOC_CALLBACK callback,
                               int                      iEnumConnectedAdapters,
                               ADL_CONTEXT_HANDLE *     context
                             );


/// Destroy client's ADL context. 
/// 
/// Clients can use ADL2 versions of ADL APIs to assure that there is no interference with other ADL clients that are running in the same process and to assure that ADL APIs are thread-safe. Such clients have to call ADL2_Main_Control_Create first to obtain ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using ADL2_Main_Control_Destroy. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in] context ADL_CONTEXT_HANDLE instance to destroy. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes
int ADL2_Main_Control_Destroy ( );


/// ADL local interface. Function to determine the validity of and retrieve the function pointer (similar to the GetProcAdress API) for a specified function. 
/// 
/// This function returns the function pointer of a specified function if it is valid (defined and exposed in a DLL module). Call this function to ensure that a function is valid before calling it. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in] context    Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in] lpModule   The pointer to the desired handle of the DLL. 
///   [in] lpProcName The pointer to the desired function name. 
/// 
/// Returns
///   If the specified function is valid, the return value is a function pointer. Otherwise it is NULL. 
/// 
/// Remarks
///   Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call ADL2_Main_Control_Create first to obtain ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using ADL2_Main_Control_Destroy.
void* ADL2_Main_Control_GetProcAddress ( ADL_CONTEXT_HANDLE context,
                                         void *             lpModule,
                                         char *             lpProcName
                                       );


/// Function to refresh adapter information. This function generates an adapter index value for all logical adapters that have ever been present in the system. 
/// 
/// This function updates the adapter information based on the logical adapters currently in the system. The adapter index and UDID mappings remain unchanged for each refresh call. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in] context Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes 
/// 
/// Remarks
///   Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call ADL2_Main_Control_Create first to obtain ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using ADL2_Main_Control_Destroy.
int ADL2_Main_Control_Refresh ( );


/// Function to initialize the ADL2 interface and issue client's context handle. 
/// 
/// Clients can use ADL2 versions of ADL APIs to assure that there is no interference with other ADL clients that are running in the same process. Such clients have to call ADL2_Main_Control_Create first to obtain ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using ADL2_Main_Control_Destroy. ADL2_Main_ControlX2_Create allows the client to specify desired threading behavior of ADL APIs. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in]  callback               The memory allocation function for memory buffer allocation. This must be provided by the user. This must be provided by the user. ADL internally uses this callback to allocate memory for the output parameters returned to the user and user is responsible to free the memory once used for these parameters. ADL internal takes care of allocating and de allocating the memory for its local variables. 
///   [in]  iEnumConnectedAdapters Specify a value of 0 to retrieve adapter information for all adapters that have ever been present in the system. Specify a value of 1 to retrieve adapter information only for adapters that are physically present and enabled in the system. 
///   [out] context                ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using ADL2_Main_Control_Destroy. 
///   [in]  threadingModel         Specify ADL threading behavior. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes
int ADL2_Main_ControlX2_Create ( ADL_MAIN_MALLOC_CALLBACK callback,
                                 int                      iEnumConnectedAdapters,
                                 ADL_CONTEXT_HANDLE *     context,
                                 ADLThreadingModel        threadingModel
                               );


/// Function to initialize the ADL2 interface and issue client's context handle. 
/// 
/// Clients can use ADL2 versions of ADL APIs to assure that there is no interference with other ADL clients that are running in the same process. Such clients have to call ADL2_Main_Control_Create first to obtain ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using ADL2_Main_Control_Destroy. ADL2_Main_ControlX3_Create allows customizing ADL GPU behavior by allowing to caller to pass a set of 32 bits integer 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in]  callback               The memory allocation function for memory buffer allocation. This must be provided by the user. This must be provided by the user. ADL internally uses this callback to allocate memory for the output parameters returned to the user and user is responsible to free the memory once used for these parameters. ADL internal takes care of allocating and de allocating the memory for its local variables. 
///   [in]  iEnumConnectedAdapters Specify a value of 0 to retrieve adapter information for all adapters that have ever been present in the system. Specify a value of 1 to retrieve adapter information only for adapters that are physically present and enabled in the system. 
///   [out] context                ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using ADL2_Main_Control_Destroy. 
///   [in]  threadingModel         Specify ADL threading behavior. 
///   [in]  adlCreateOptions       it will allow customizing ADL GPU behavior by allowing to caller to pass a set of 32 bits. Each bit customizes particular behavior. First usage of the flags is to customize how ADL will report adapters that are AMD but have incompatible driver installed. Setting 0 to first bit will force ADL to report such adapters as none-AMD (vendor -1002) , setting 1 to first bit will force AMD to report such adapters vendor as AMD (1002) 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes
int ADL2_Main_ControlX3_Create ( ADL_MAIN_MALLOC_CALLBACK callback,
                                 int                      iEnumConnectedAdapters,
                                 ADL_CONTEXT_HANDLE *     context,
                                 ADLThreadingModel        threadingModel,
                                 int                      adlCreateOptions
                               );


/// Client calls the function passing id of the event it listens to and handle of the event object. The graphics driver sets the event object when corresponding event occurs in the system. If the event is registered for a given GPU, unregister also needs for a given GPU. If the event is registered for each GPU, unregister is also for each GPU. 
/// Supported Platforms:
///   Windows 7, 10 and above; 32bit and 64bit 
/// 
/// Parameters
///   [in] context      Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in] adapterIndex an integer indicates a GPU. If is -1, then the API will register the event to each GPU 
///   [in] eventId      Numeric value that represents the event ID the client listens to. 
///   [in] clientID     An integer indicate who register the event. It is optional , for third part it is 0 
///   [in] evntHandle   Reference to the event object that will be set by the driver when corresponding event occurs in the system. Client obtains the handle using Win32 Create event API. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK, or an ADL error code otherwise. Result Codes 
/// 
/// Remarks
///   Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call ADL2_Main_Control_Create first to obtain ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using ADL2_Main_Control_Destroy.
int ADL2_PerGPU_GDEvent_Register ( ADL_CONTEXT_HANDLE context,
                                   int                iAdapterIndex,
                                   int                clientID,
                                   int                eventID,
                                   void *             evntHandle
                                 );


/// Client calls the function passing id of the event and un-register event. If the event is registered for a given GPU, unregister also needs for a given GPU. If the event is registered for each GPU, unregister is also for each GPU. 
/// Supported Platforms:
///   Windows 7, 10 and above; 32bit and 64bit 
/// 
/// Parameters
///   [in] context      Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in] adapterIndex an integer indicate a GPU. If is -1, then need to unregister to each GPU. 
///   [in] eventId      Numeric value that represents the event ID the client listens to. 
///   [in] clientID     An integer indicate who register the event. It is optional , for third part it is 0 
///   [in] evntHandle   Reference to the event object that will be set by the driver when corresponding event occurs in the system. Client obtains the handle using Win32 Create Event API. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK, or an ADL error code otherwise. Result Codes 
/// 
/// Remarks
///   Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call ADL2_Main_Control_Create first to obtain ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using ADL2_Main_Control_Destroy.
int ADL2_PerGPU_GDEvent_UnRegister ( ADL_CONTEXT_HANDLE context,
                                     int                iAdapterIndex,
                                     int                clientID,
                                     int                eventID,
                                     void *             evntHandle
                                   );


/// Client calls the function passing id of the event it listens to and handle of the event object. The graphics driver sets the event object when corresponding event occurs in the system. 
/// Supported Platforms:
///   Windows 7, 10 and above; 32bit and 64bit 
/// 
/// Parameters
///   [in] context    Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in] eventId    Numeric value that represents the event ID the client listens to. 
///   [in] evntHandle Reference to the event object that will be set by the driver when corresponding event occurs in the system. Client obtains the handle using Win32 CreateEvent API. 
/// 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK, or an ADL error code otherwise. Result Codes 
/// 
/// Remarks
///   Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call ADL2_Main_Control_Create first to obtain ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using ADL2_Main_Control_Destroy.
int ADL2_RegisterEvent ( ADL_CONTEXT_HANDLE context,
                         int                eventID,
                         void *             evntHandle
                       );


/// Client calls the function passing id of the event it listens to and handle of the event object. The graphics driver sets the event object when corresponding event occurs in the system. 
/// Supported Platforms:
///   Windows 7, 10 and above; 32bit and 64bit 
/// 
/// Parameters
///   [in] context    Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in] eventId    Numeric value that represents the event ID the client listens to. 
///   [in] evntHandle Reference to the event object that will be set by the driver when corresponding event occurs in the system. Client obtains the handle using Win32 CreateEvent API. 
/// 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK, or an ADL error code otherwise. Result Codes 
/// 
/// Remarks
///   Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call ADL2_Main_Control_Create first to obtain ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using ADL2_Main_Control_Destroy.
int ADL2_RegisterEventX2 ( ADL_CONTEXT_HANDLE context,
                           int                iAdapterIndex,
                           int                clientID,
                           int                eventID,
                           void *             evntHandle
                         );


/// Client calls the function passing id of the event it listens to and handle of the event object. The graphics driver will stop seting the event object when corresponding event occurs in the system. 
/// Supported Platforms:
///   Windows 7, 10 and above; 32bit and 64bit 
/// 
/// Parameters
///   [in] context    Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in] eventId    Numeric value that represents the event ID the client listens to. 
///   [in] evntHandle Reference to the event object that will need to be unregistered. Client obtains the handle using Win32 CreateEvent API. Client has to call CloseHandle Win32 API after it unregisters the handle. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK, or an ADL error code otherwise. Result Codes 
/// 
/// Remarks
///   Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call ADL2_Main_Control_Create first to obtain ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using ADL2_Main_Control_Destroy.
int ADL2_UnRegisterEvent ( ADL_CONTEXT_HANDLE context,
                           int                eventID,
                           void *             evntHandle
                         );


/// Client calls the function passing id of the event it listens to and handle of the event object. The graphics driver will stop seting the event object when corresponding event occurs in the system. 
/// Supported Platforms:
///   Windows 7, 10 and above; 32bit and 64bit 
/// 
/// Parameters
///   [in] context    Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in] eventId    Numeric value that represents the event ID the client listens to. 
///   [in] evntHandle Reference to the event object that will need to be unregistered. Client obtains the handle using Win32 CreateEvent API. Client has to call CloseHandle Win32 API after it unregisters the handle. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK, or an ADL error code otherwise. Result Codes 
/// 
/// Remarks
///   Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call ADL2_Main_Control_Create first to obtain ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using ADL2_Main_Control_Destroy.
int ADL2_UnRegisterEventX2 ( ADL_CONTEXT_HANDLE context,
                             int                iAdapterIndex,
                             int                clientID,
                             int                eventID,
                             void *             evntHandle
                           );


/// Function to initialize the ADL interface. This function should be called first. 
/// 
/// This function initializes the ADL library. ADL initialized using ADL_Main_Control_Create will not enforce serialization of ADL API executions by multiple threads. Multiple threads will be allowed to enter to ADL at the same time. Note that ADL library is not guaranteed to be thread-safe. Client that calls ADL_Main_Control_Create have to provide its own mechanism for ADL calls serialization. It also initializes global pointers and, at the same time, calls the ADL_Main_Control_Refresh function. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in] callback               The memory allocation function for memory buffer allocation. This must be provided by the user. ADL internally uses this callback to allocate memory for the output parameters returned to the user and user is responsible to free the memory once used for these parameters. ADL internal takes care of allocating and de allocating the memory for its local variables. 
///   [in] iEnumConnectedAdapters Specify a value of 0 to retrieve adapter information for all adapters that have ever been present in the system. Specify a value of 1 to retrieve adapter information only for adapters that are physically present and enabled in the system. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes
int ADL_Main_Control_Create ( ADL_MAIN_MALLOC_CALLBACK callback,
                              int                      iEnumConnectedAdapters
                            );


/// Function to destroy ADL global pointers. This function should be called last. 
/// 
/// All ADL global buffers and resources are released after this function is called. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes
int ADL_Main_Control_Destroy ( );


/// ADL local interface. Function to determine the validity of and retrieve the function pointer (similar to the GetProcAdress API) for a specified function. 
/// 
/// This function returns the function pointer of a specified function if it is valid (defined and exposed in a DLL module). Call this function to ensure that a function is valid before calling it. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in] lpModule   The pointer to the desired handle of the DLL. 
///   [in] lpProcName The pointer to the desired function name. 
/// 
/// Returns
///   If the specified function is valid, the return value is a function pointer. Otherwise it is NULL.
void* ADL_Main_Control_GetProcAddress ( void * lpModule,
                                        char * lpProcName
                                      );


/// Function to refresh adapter information. This function generates an adapter index value for all logical adapters that have ever been present in the system. 
/// 
/// This function updates the adapter information based on the logical adapters currently in the system. The adapter index and UDID mappings remain unchanged for each refresh call. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes
int ADL_Main_Control_Refresh ( );


/// Function to initialize the ADL interface. This function should be called first. 
/// 
/// This function initializes the ADL library. Allows the client to specify desired threading behavior of ADL APIs. It also initializes global pointers and, at the same time, calls the ADL_Main_Control_Refresh function. 
/// Supported Platforms:
///   Linux and Windows(XP, Vista and above); 32bit and 64bit 
/// 
/// Parameters
///   [in] callback               The memory allocation function for memory buffer allocation. This must be provided by the user. This must be provided by the user. ADL internally uses this callback to allocate memory for the output parameters returned to the user and user is responsible to free the memory once used for these parameters. ADL internal takes care of allocating and de allocating the memory for its local variables. 
///   [in] iEnumConnectedAdapters Specify a value of 0 to retrieve adapter information for all adapters that have ever been present in the system. Specify a value of 1 to retrieve adapter information only for adapters that are physically present and enabled in the system. 
///   [in] threadingModel         Specify ADL threading behavior. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes
int ADL_Main_ControlX2_Create ( ADL_MAIN_MALLOC_CALLBACK callback,
                                int                      iEnumConnectedAdapters,
                                ADLThreadingModel        threadingModel
                              );


#endif /* ADL_HEADER_ADL_H_ */
