#ifndef ADL_HEADER_APPPROFILES_H_
#define ADL_HEADER_APPPROFILES_H_

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

/// The API allows an user mode process to enable/disable KMD app profile interception
/// Supported Platforms:
///   Windows 7, 10 and above; 32bit and 64bit 
/// 
/// Parameters
///   [in] iAppType Specify 1 for games 
///   [in] iProcId  The process id of the u ser mode process. KMD will stop interception if this process terminates for any reason. 
///   [in] iEnabled 1 - Enable, 0 - Disable the interception 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes
int ADL2_ApplicationProfiles_AppInterception_Set ( ADL_CONTEXT_HANDLE context,
                                                   int                iAppType,
                                                   unsigned int       iProcId,
                                                   int                iEnabled
                                                 );


/// Sets the list of application that KMD needs to intercept
/// Supported Platforms:
///   Windows 7, 10 and above; 32bit and 64bit 
/// 
/// Parameters
///   [in] iAppType      Specify 1 for games 
///   [in] iNumberOfApps Number of apps in the list 
///   [in] lpAppInfo     Array of App info in the list 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes
int ADL2_ApplicationProfiles_AppInterceptionList_Set ( ADL_CONTEXT_HANDLE       context,
                                                       int                      iAppType,
                                                       int                      iNumberOfApps,
                                                       ADLAppInterceptionInfo * lpAppInfo
                                                     );


/// This function builds and returns list of applications that exist in the given area of System, OEM and User blobs. User blob has precedence over OEM blob, OEM blob has precedence over System blob. 
/// Supported Platforms:
///   Windows 7, 10 and above; 32bit and 64bit 
/// 
/// Parameters
///   [in]  context          Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in]  driverArea       Specifies driver area 
///   [out] numApps          Returns number of application record in given driver area 
///   [out] adlApplications  Returns the pointer to application records 
///   [in]  allowDuplication If it's false and duplicated records of application exist (e.g. in System and User blob), then only one recored is returned, otherwise, return all same records from all blobs 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes
/// 
/// Remarks
///   This API builds and returns list of applications that exist in the given area of System, OEM and User blobs. User blob has precedence over OEM blob, OEM blob has precedence over System blob. *** This function CANNOT be used outside of AMD because the return parameter contains structure from internal "shared_escape.h"
int ADL2_ApplicationProfiles_Applications_Get ( ADL_CONTEXT_HANDLE      context,
                                                const wchar_t *         driverArea,
                                                int *                   numApps,
                                                ADLApplicationRecord ** adlApplications
                                              );


/// The API allows an user mode process to instruct KMD to resume a process that it has suspended
/// Supported Platforms:
///   Windows 7, 10 and above; 32bit and 64bit 
/// 
/// Parameters
///   [in] iAppType  Specify 1 for games 
///   [in] ProcessId The id of the process that is to be resumed 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes
int ADL2_ApplicationProfiles_AppStartStop_Resume ( ADL_CONTEXT_HANDLE context,
                                                   int                iAppType,
                                                   unsigned int       ProcessId
                                                 );


/// The API allows an user mode process to retrieve information about the recent App Start/Stop event
/// 
/// The API allows an user mode process to retrieve information about the recent App Start/Stop event
/// Supported Platforms:
///   Windows 7, 10 and above; 32bit and 64bit 
/// 
/// Parameters
///   [in,out] lpAppInfo One ADLAppInterceptionInfo strucuture. For input, specify the app state (APP_PROC_CREATION or APP_PROC_TERMINATE). ADL will fill in other information for output. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes
int ADL2_ApplicationProfiles_AppStartStopInfo_Get ( ADL_CONTEXT_HANDLE       context,
                                                    int                      iAppType,
                                                    ADLAppInterceptionInfo * lpAppInfo
                                                  );


/// This function converts C style structures into Compact style for writing a blob file 
/// Supported Platforms:
///   Windows 7, 10 and above; 32bit and 64bit 
/// 
/// Parameters
///   [in]  context        Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in]  pCustomisation Specifies pointer to Customization of database 
///   [out] outCompact     The pointer to compact structure. 
///   [out] outSize        The size of compact structure 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes
/// 
/// Remarks
///   This API converts C style structures into Compact style for writing a blob file
int ADL2_ApplicationProfiles_ConvertToCompact ( ADL_CONTEXT_HANDLE context,
                                                CUSTOMISATIONS *   pCustomisation,
                                                BINFILE *          outCompact,
                                                int *              outSize
                                              );


/// This function retrieves privacy type for the specified area 
/// Supported Platforms:
///   Windows 7, 10 and above; 32bit and 64bit 
/// 
/// Parameters
///   [in]  context              Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in]  DriverArea           Specifies driver area 
///   [out] outDriverAreaPrivacy The pointer to privacy for the specified area/ 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes
/// 
/// Remarks
///   This API retrieves privacy type for the specified area
int ADL2_ApplicationProfiles_DriverAreaPrivacy_Get ( ADL_CONTEXT_HANDLE context,
                                                     const wchar_t *    DriverArea,
                                                     PRIVACYTYPES *     outDriverAreaPrivacy
                                                   );


/// This function retrieves the pointer to Customization structure of the specified blob file. 
/// Supported Platforms:
///   Windows 7, 10 and above; 32bit and 64bit 
/// 
/// Parameters
///   [in]  context           Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in]  Databaseln        Specifies the type of blob file 
///   [out] pCustomizationOut The pointer to Customization structure of the specified blob file 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes
/// 
/// Remarks
///   This API retrieves the pointer to Customization structure of the specified blob file
int ADL2_ApplicationProfiles_GetCustomization ( ADL_CONTEXT_HANDLE context,
                                                ADL_AP_DATABASE    Databaseln,
                                                CUSTOMISATIONS *   pCustomizationOut
                                              );


/// Function to retrieve the recent application list from registry. 
/// 
/// This function retrieves the recent application list from registry. This API uses the Caller's Memory Allocation Callback Function to allocate memory pointed by lppAppList. Caller is responsible to de-allocate the memory. 
/// Supported Platforms:
///   Windows 7, 10 and above; 32bit and 64bit 
/// 
/// Parameters
///   [in]  context    Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in]  iListType  Specifies the type of the list to retrieve, defined in ApplicationListType 
///   [out] lpNumApps  The pointer to the number of applications in the list. 
///   [out] lppAppList The pointer to the pointer to the retrieved application list from registry. Set it to NULL prior to call this API. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes
/// 
/// Remarks
///   This API uses the memory allocation callback function provided by the user.
int ADL2_ApplicationProfiles_HitLists_Get ( ADL_CONTEXT_HANDLE    context,
                                            int                   iListType,
                                            int *                 lpNumApps,
                                            ADLApplicationData ** lppAppList
                                          );


/// Function to retrieve the recent application list from registry. 
/// 
/// This function retrieves the recent application list from registry. This API uses the Caller's Memory Allocation Callback Function to allocate memory pointed by lppAppList. Caller is responsible to de-allocate the memory. 
/// Supported Platforms:
///   Windows 7, 10 and above; 32bit and 64bit 
/// 
/// Parameters
///   [in]  context    Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in]  iListType  Specifies the type of the list to retrieve, defined in ApplicationListType 
///   [out] lpNumApps  The pointer to the number of applications in the list. 
///   [out] lppAppList The pointer to the pointer to the retrieved application list from registry. Set it to NULL prior to call this API. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes
/// 
/// Remarks
///   This API uses the memory allocation callback function provided by the user.
int ADL2_ApplicationProfiles_HitListsX2_Get ( ADL_CONTEXT_HANDLE      context,
                                              int                     iListType,
                                              int *                   lpNumApps,
                                              ADLApplicationDataX2 ** lppAppList
                                            );


/// Function to retrieve the recent application list from registry. 
/// 
/// This function retrieves the recent application list from registry. This API uses the Caller's Memory Allocation Callback Function to allocate memory pointed by lppAppList. Caller is responsible to de-allocate the memory. 
/// Supported Platforms:
///   Windows 7, 10 and above; 32bit and 64bit 
/// 
/// Parameters
///   [in]  context    Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in]  iListType  Specifies the type of the list to retrieve, defined in ApplicationListType 
///   [out] lpNumApps  The pointer to the number of applications in the list. 
///   [out] lppAppList The pointer to the pointer to the retrieved application list from registry including process id. Set it to NULL prior to call this API. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes
/// 
/// Remarks
///   This API uses the memory allocation callback function provided by the user.
int ADL2_ApplicationProfiles_HitListsX3_Get ( ADL_CONTEXT_HANDLE      context,
                                              int                     iListType,
                                              int *                   lpNumApps,
                                              ADLApplicationDataX3 ** lppAppList
                                            );


/// This function creates new application based on driver area, profile name and property records. 
/// Supported Platforms:
///   Windows 7, 10 and above; 32bit and 64bit 
/// 
/// Parameters
///   [in] context         Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in] driverArea      Specifies driver area where profile declares 
///   [in] profileName     Specifies the name of profile to be created 
///   [in] numProperties   Specifies the number of properties in the profile to be created 
///   [in] propertyRecords The pointer to property records in the profile to be created 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes
/// 
/// Remarks
///   This API add a profile to the specified Area
int ADL2_ApplicationProfiles_Profile_Create ( ADL_CONTEXT_HANDLE              context,
                                              const wchar_t *                 driverArea,
                                              const wchar_t *                 profileName,
                                              int                             numProperties,
                                              const ADLPropertyRecordCreate * propertyRecords
                                            );


/// This function checks if the specified profile exist or not in system blob. 
/// Supported Platforms:
///   Windows 7, 10 and above; 32bit and 64bit 
/// 
/// Parameters
///   [in]  context     Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in]  DriverArea  Specifies driver area 
///   [in]  ProfileName Specifies the name of profile 
///   [out] outExists   Indicates if the specified profile exists or not 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes
/// 
/// Remarks
///   This API checks if the specified profile exist or not in system blob.
int ADL2_ApplicationProfiles_Profile_Exist ( ADL_CONTEXT_HANDLE context,
                                             const wchar_t *    DriverArea,
                                             const wchar_t *    ProfileName,
                                             BOOL *             outExists
                                           );


/// This function removes the specified profile from the User blb. 
/// Supported Platforms:
///   Windows 7, 10 and above; 32bit and 64bit 
/// 
/// Parameters
///   [in] context     Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in] driverArea  Specifies driver area where profile delcares 
///   [in] profileName Specifies the name of profile to be removed 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes
/// 
/// Remarks
///   This API removes the specified profile from the User blb.
int ADL2_ApplicationProfiles_Profile_Remove ( ADL_CONTEXT_HANDLE context,
                                              const wchar_t *    driverArea,
                                              const wchar_t *    profileName
                                            );


/// This function assigns a profile in a new or existing application record. 
/// Supported Platforms:
///   Windows 7, 10 and above; 32bit and 64bit 
/// 
/// Parameters
///   [in] context     Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in] FileName    Specifies the name of file 
///   [in] Path        Specifies the path where file locates 
///   [in] Version     Specifies version 
///   [in] DriverArea  Specifies driver area where Profile exists 
///   [in] ProfileName Specifies Profile to use 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes
/// 
/// Remarks
///   This API assigns a profile in a new or existing application record. If area exists, then override use record, otherwise, create a new use record
int ADL2_ApplicationProfiles_ProfileApplication_Assign ( ADL_CONTEXT_HANDLE context,
                                                         const wchar_t *    FileName,
                                                         const wchar_t *    Path,
                                                         const wchar_t *    Version,
                                                         const wchar_t *    DriverArea,
                                                         const wchar_t *    ProfileName
                                                       );


/// This function assigns a profile in a new or existing application record. 
/// Supported Platforms:
///   Windows 7, 10 and above; 32bit and 64bit 
/// 
/// Parameters
///   [in] context     Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in] FileName    Specifies the name of file 
///   [in] Path        Specifies the path where file locates 
///   [in] Version     Specifies version 
///   [in] Title       Specifies title 
///   [in] DriverArea  Specifies driver area where Profile exists 
///   [in] ProfileName Specifies Profile to use 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes
/// 
/// Remarks
///   This API assigns a profile in a new or existing application record. If area exists, then override use record, otherwise, create a new use record
int ADL2_ApplicationProfiles_ProfileApplicationX2_Assign ( ADL_CONTEXT_HANDLE context,
                                                           const wchar_t *    FileName,
                                                           const wchar_t *    Path,
                                                           const wchar_t *    Version,
                                                           const wchar_t *    Title,
                                                           const wchar_t *    DriverArea,
                                                           const wchar_t *    ProfileName
                                                         );


/// This function provides capabilities which are identical to existing ADL_ApplicationProfiles_ProfileOfAnApplication_Search. Distinct of existing 
/// 
///  This API uses the Caller's Memory Allocation Callback Function to allocate memory pointed by lppProfile. Caller is responsible to de-allocate the memory. 
/// Supported Platforms:
///   Windows 7, 10 and above; 32bit and 64bit 
/// 
/// Parameters
///   [in]  context        Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in]  fileName       Specifies the name of file 
///   [in]  path           Specifies the path where file locates 
///   [in]  version        Specifies version 
///   [in]  appProfileArea Specifies driver area where Profile exists 
///   [out] lppProfile     The pointer to the profile. Will be used to return profiles used by specific application record in the given driver area. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes
/// 
/// Remarks
///   This API removes the specified application record. rNote. OtNote that this function will ONLY reside in private portion of ADL for internal debug only, never exposed to public.
int ADL2_ApplicationProfiles_ProfileOfAnApplication_InMemorySearch ( ADL_CONTEXT_HANDLE       context,
                                                                     const wchar_t *          fileName,
                                                                     const wchar_t *          path,
                                                                     const wchar_t *          version,
                                                                     const wchar_t *          appProfileArea,
                                                                     ADLApplicationProfile ** lppProfile
                                                                   );


/// Function to retrieve the profile of an application defined in driver. 
/// 
/// This function retrieves the profile information of an application. This API uses the Caller's Memory Allocation Callback Function to allocate memory pointed by lppProfile. Caller is responsible to de-allocate the memory. 
/// Supported Platforms:
///   Windows 7, 10 and above; 32bit and 64bit 
/// 
/// Parameters
///   [in]  context        Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in]  FileName       Specifies the application file name 
///   [in]  Path           Specifies the application file path 
///   [in]  Version        Specifies the application version 
///   [in]  AppProfileArea Specifies the area the profile works on (like 'PX', 'D3D', etc. ) 
///   [out] lppProfile     The pointer to the pointer to the retrieved application profile. Set it to NULL prior to call this API. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes
/// 
/// Remarks
///   This API will be replaced with a new API that supports unicode. This API uses the memory allocation callback function provided by the user.
int ADL2_ApplicationProfiles_ProfileOfAnApplication_Search ( ADL_CONTEXT_HANDLE       context,
                                                             const char *             FileName,
                                                             const char *             Path,
                                                             const char *             Version,
                                                             const char *             AppProfileArea,
                                                             ADLApplicationProfile ** lppProfile
                                                           );


/// This function retrieves the profile information of an application. This API uses the Caller's Memory Allocation Callback Function to allocate memory pointed by lppProfile. Caller is responsible to de-allocate the memory. 
/// Supported Platforms:
///   Windows 7, 10 and above; 32bit and 64bit 
/// 
/// Parameters
///   [in]  context        Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in]  FileName       Specifies the application file name 
///   [in]  Path           Specifies the application file path 
///   [in]  Version        Specifies the application version 
///   [in]  AppProfileArea Specifies the area the profile works on (like 'PX', 'D3D', etc. ) 
///   [out] lppProfile     The pointer to the pointer to the retrieved application profile. Set it to NULL prior to call this API. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes
/// 
/// Remarks
///   This API uses the memory allocation callback function provided by the user.
int ADL2_ApplicationProfiles_ProfileOfAnApplicationX2_Search ( ADL_CONTEXT_HANDLE       context,
                                                               const wchar_t *          FileName,
                                                               const wchar_t *          Path,
                                                               const wchar_t *          Version,
                                                               const wchar_t *          AppProfileArea,
                                                               ADLApplicationProfile ** lppProfile
                                                             );


/// This function retrieves data type for the specified property. 
/// Supported Platforms:
///   Windows 7, 10 and above; 32bit and 64bit 
/// 
/// Parameters
///   [in]  context      Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in]  DriverArea   Specifies driver area where Property belong to 
///   [in]  PropertyName Specifies name of property 
///   [out] outType      The data type of property 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes
/// 
/// Remarks
///   This API retrieves data type for the specified property.
int ADL2_ApplicationProfiles_PropertyType_Get ( ADL_CONTEXT_HANDLE context,
                                                const wchar_t *    DriverArea,
                                                const wchar_t *    PropertyName,
                                                DATATYPES *        outType
                                              );


/// This function returns release of installed system application profile blob file. 
/// Supported Platforms:
///   Windows 7, 10 and above; 32bit and 64bit 
/// 
/// Parameters
///   [in]  context    Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [out] strRelease The pointer to the stRelease. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes
/// 
/// Remarks
///   This API returns release of installed system application profile blob file.
int ADL2_ApplicationProfiles_Release_Get ( ADL_CONTEXT_HANDLE context,
                                           wchar_t **         strRelease
                                         );


/// This function removes the specified application record. 
/// Supported Platforms:
///   Windows 7, 10 and above; 32bit and 64bit 
/// 
/// Parameters
///   [in] context    Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in] FileName   Specifies the name of file 
///   [in] Path       Specifies the path where file locates 
///   [in] Version    Specifies version 
///   [in] DriverArea Specifies driver area where Profile exists 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes
/// 
/// Remarks
///   This API removes the specified application record.
int ADL2_ApplicationProfiles_RemoveApplication ( ADL_CONTEXT_HANDLE context,
                                                 const wchar_t *    FileName,
                                                 const wchar_t *    Path,
                                                 const wchar_t *    Version,
                                                 const wchar_t *    DriverArea
                                               );


/// Function to Reload System appprofiles. 
/// 
/// This function Reloads System appprofiles by reloading system profile and loading user profile. 
/// Supported Platforms:
///   Windows 7, 10 and above; 32bit and 64bit 
/// 
/// Parameters
///   [in] context Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes 
/// 
/// Remarks
///   Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call ADL2_Main_Control_Create first to obtain ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using ADL2_Main_Control_Destroy.
int ADL2_ApplicationProfiles_System_Reload ( );


/// Function to Load User appprofiles. 
/// 
/// This function Loads User appprofiles by loadding system profile and user profile. 
/// Supported Platforms:
///   Windows 7, 10 and above; 32bit and 64bit 
/// 
/// Parameters
///   [in] context Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes 
/// 
/// Remarks
///   Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call ADL2_Main_Control_Create first to obtain ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using ADL2_Main_Control_Destroy.
int ADL2_ApplicationProfiles_User_Load ( );


/// Function to Unload User appprofiles. 
/// 
/// This function Unloads User appprofiles by unloading user profile. 
/// Supported Platforms:
///   Windows 7, 10 and above; 32bit and 64bit 
/// 
/// Parameters
///   [in] context Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes 
/// 
/// Remarks
///   Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call ADL2_Main_Control_Create first to obtain ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using ADL2_Main_Control_Destroy.
int ADL2_ApplicationProfiles_User_Unload ( );


/// Sets the list of application that KMD might need to intercept, have choice to ask KMD to WaitToResume on app load or not
/// Supported Platforms:
///   Windows 7, 10 and above; 32bit and 64bit 
/// 
/// Parameters
///   [in] iAppType      Specify 1 for games 
///   [in] iNumberOfApps Number of apps in the list 
///   [in] lpAppInfo     Array of App info in the list 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes
int ADL2_ApplicationProfilesX2_AppInterceptionList_Set ( ADL_CONTEXT_HANDLE         context,
                                                         int                        iAppType,
                                                         int                        iNumberOfApps,
                                                         ADLAppInterceptionInfoX2 * lpAppInfo
                                                       );


/// This function builds and returns list of applications that exist in the given area of System, OEM and User blobs. User blob has precedence over OEM blob, OEM blob has precedence over System blob. 
/// Supported Platforms:
///   Windows 7, 10 and above; 32bit and 64bit 
/// 
/// Parameters
///   [in]  driverArea       Specifies driver area 
///   [out] numApps          Returns number of application record in given driver area 
///   [out] adlApplications  Returns the pointer to application records 
///   [in]  allowDuplication If it's false and duplicated records of application exist (e.g. in System and User blob), then only one recored is returned, otherwise, return all same records from all blobs 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes
/// 
/// Remarks
///   This API builds and returns list of applications that exist in the given area of System, OEM and User blobs. User blob has precedence over OEM blob, OEM blob has precedence over System blob. *** This function CANNOT be used outside of AMD because the return parameter contains structure from internal "shared_escape.h"
int ADL_ApplicationProfiles_Applications_Get ( const wchar_t *         driverArea,
                                               int *                   numApps,
                                               ADLApplicationRecord ** adlApplications
                                             );


/// This function converts C style structures into Compact style for writing a blob file 
/// Supported Platforms:
///   Windows 7, 10 and above; 32bit and 64bit 
/// 
/// Parameters
///   [in]  pCustomisation Specifies pointer to Customization of database 
///   [out] outCompact     The pointer to compact structure. 
///   [out] outSize        The size of compact structure 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes
/// 
/// Remarks
///   This API converts C style structures into Compact style for writing a blob file
int ADL_ApplicationProfiles_ConvertToCompact ( CUSTOMISATIONS * pCustomisation,
                                               BINFILE *        outCompact,
                                               int *            outSize
                                             );


/// This function retrieves privacy type for the specified area 
/// Supported Platforms:
///   Windows 7, 10 and above; 32bit and 64bit 
/// 
/// Parameters
///   [in]  DriverArea           Specifies driver area 
///   [out] outDriverAreaPrivacy The pointer to privacy for the specified area/ 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes
/// 
/// Remarks
///   This API retrieves privacy type for the specified area
int ADL_ApplicationProfiles_DriverAreaPrivacy_Get ( const wchar_t * DriverArea,
                                                    PRIVACYTYPES *  outDriverAreaPrivacy
                                                  );


/// This function retrieves the pointer to Customization structure of the specified blob file. 
/// Supported Platforms:
///   Windows 7, 10 and above; 32bit and 64bit 
/// 
/// Parameters
///   [in]  Databaseln        Specifies the type of blob file 
///   [out] pCustomizationOut The pointer to Customization structure of the specified blob file 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes
/// 
/// Remarks
///   This API retrieves the pointer to Customization structure of the specified blob file
int ADL_ApplicationProfiles_GetCustomization ( ADL_AP_DATABASE  Databaseln,
                                               CUSTOMISATIONS * pCustomizationOut
                                             );


/// Function to retrieve the recent application list from registry. 
/// 
/// This function retrieves the recent application list from registry. This API uses the Caller's Memory Allocation Callback Function to allocate memory pointed by lppAppList. Caller is responsible to de-allocate the memory. 
/// Supported Platforms:
///   Windows 7, 10 and above; 32bit and 64bit 
/// 
/// Parameters
///   [in]  iListType  Specifies the type of the list to retrieve, defined in ApplicationListType 
///   [out] lpNumApps  The pointer to the number of applications in the list. 
///   [out] lppAppList The pointer to the pointer to the retrieved application list from registry. Set it to NULL prior to call this API. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes
/// 
/// Remarks
///   This API uses the memory allocation callback function provided by the user.
int ADL_ApplicationProfiles_HitLists_Get ( int                   iListType,
                                           int *                 lpNumApps,
                                           ADLApplicationData ** lppAppList
                                         );


/// Function to retrieve the recent application list from registry. 
/// 
/// This function retrieves the recent application list from registry. This API uses the Caller's Memory Allocation Callback Function to allocate memory pointed by lppAppList. Caller is responsible to de-allocate the memory. 
/// Supported Platforms:
///   Windows 7, 10 and above; 32bit and 64bit 
/// 
/// Parameters
///   [in]  iListType  Specifies the type of the list to retrieve, defined in ApplicationListType 
///   [out] lpNumApps  The pointer to the number of applications in the list. 
///   [out] lppAppList The pointer to the pointer to the retrieved application list from registry. Set it to NULL prior to call this API. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes
/// 
/// Remarks
///   This API uses the memory allocation callback function provided by the user.
int ADL_ApplicationProfiles_HitListsX2_Get ( int                     iListType,
                                             int *                   lpNumApps,
                                             ADLApplicationDataX2 ** lppAppList
                                           );


/// This function creates new application based on driver area, profile name and property records. 
/// Supported Platforms:
///   Windows 7, 10 and above; 32bit and 64bit 
/// 
/// Parameters
///   [in] driverArea      Specifies driver area where profile declares 
///   [in] profileName     Specifies the name of profile to be created 
///   [in] numProperties   Specifies the number of properties in the profile to be created 
///   [in] propertyRecords The pointer to property records in the profile to be created 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes
/// 
/// Remarks
///   This API add a profile to the specified Area
int ADL_ApplicationProfiles_Profile_Create ( const wchar_t *                 driverArea,
                                             const wchar_t *                 profileName,
                                             int                             numProperties,
                                             const ADLPropertyRecordCreate * propertyRecords
                                           );


/// This function checks if the specified profile exist or not in system blob. 
/// Supported Platforms:
///   Windows 7, 10 and above; 32bit and 64bit 
/// 
/// Parameters
///   [in]  DriverArea  Specifies driver area 
///   [in]  ProfileName Specifies the name of profile 
///   [out] outExists   Indicates if the specified profile exists or not 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes
/// 
/// Remarks
///   This API checks if the specified profile exist or not in system blob.
int ADL_ApplicationProfiles_Profile_Exist ( const wchar_t * DriverArea,
                                            const wchar_t * ProfileName,
                                            BOOL *          outExists
                                          );


/// This function removes the specified profile from the User blb. 
/// Supported Platforms:
///   Windows 7, 10 and above; 32bit and 64bit 
/// 
/// Parameters
///   [in] driverArea  Specifies driver area where profile delcares 
///   [in] profileName Specifies the name of profile to be removed 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes
/// 
/// Remarks
///   This API removes the specified profile from the User blb.
int ADL_ApplicationProfiles_Profile_Remove ( const wchar_t * driverArea,
                                             const wchar_t * profileName
                                           );


/// This function assigns a profile in a new or existing application record. 
/// Supported Platforms:
///   Windows 7, 10 and above; 32bit and 64bit 
/// 
/// Parameters
///   [in] FileName    Specifies the name of file 
///   [in] Path        Specifies the path where file locates 
///   [in] Version     Specifies version 
///   [in] DriverArea  Specifies driver area where Profile exists 
///   [in] ProfileName Specifies Profile to use 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes
/// 
/// Remarks
///   This API assigns a profile in a new or existing application record. If area exists, then override use record, otherwise, create a new use record
int ADL_ApplicationProfiles_ProfileApplication_Assign ( const wchar_t * FileName,
                                                        const wchar_t * Path,
                                                        const wchar_t * Version,
                                                        const wchar_t * DriverArea,
                                                        const wchar_t * ProfileName
                                                      );


/// This function assigns a profile in a new or existing application record. 
/// Supported Platforms:
///   Windows 7, 10 and above; 32bit and 64bit 
/// 
/// Parameters
///   [in] FileName    Specifies the name of file 
///   [in] Path        Specifies the path where file locates 
///   [in] Version     Specifies version 
///   [in] Title       Specifies title 
///   [in] DriverArea  Specifies driver area where Profile exists 
///   [in] ProfileName Specifies Profile to use 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes
/// 
/// Remarks
///   This API assigns a profile in a new or existing application record. If area exists, then override use record, otherwise, create a new use record
int ADL_ApplicationProfiles_ProfileApplicationX2_Assign ( const wchar_t * FileName,
                                                          const wchar_t * Path,
                                                          const wchar_t * Version,
                                                          const wchar_t * Title,
                                                          const wchar_t * DriverArea,
                                                          const wchar_t * ProfileName
                                                        );


/// Supported Platforms:
///   Windows 7, 10 and above; 32bit and 64bit 
/// 
/// Parameters
///   [in]  fileName       Specifies the name of file 
///   [in]  path           Specifies the path where file locates 
///   [in]  version        Specifies version 
///   [in]  appProfileArea Specifies driver area where Profile exists 
///   [out] lppProfile     The pointer to the profile. Will be used to return profiles used by specific application record in the given driver area. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes
/// 
/// Remarks
///   This API removes the specified application record. rNote. OtNote that this function will ONLY reside in private portion of ADL for internal debug only, never exposed to public.
int ADL_ApplicationProfiles_ProfileOfAnApplication_InMemorySearch ( const wchar_t *          fileName,
                                                                    const wchar_t *          path,
                                                                    const wchar_t *          version,
                                                                    const wchar_t *          appProfileArea,
                                                                    ADLApplicationProfile ** lppProfile
                                                                  );


/// Function to retrieve the profile of an application defined in driver. 
/// 
/// This function retrieves the profile information of an application. This API uses the Caller's Memory Allocation Callback Function to allocate memory pointed by lppProfile. Caller is responsible to de-allocate the memory. 
/// Supported Platforms:
///   Windows 7, 10 and above; 32bit and 64bit 
/// 
/// Parameters
///   [in]  FileName       Specifies the application file name 
///   [in]  Path           Specifies the application file path 
///   [in]  Version        Specifies the application version 
///   [in]  AppProfileArea Specifies the area the profile works on (like 'PX', 'D3D', etc. ) 
///   [out] lppProfile     The pointer to the pointer to the retrieved application profile. Set it to NULL prior to call this API. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes
/// 
/// Remarks
///   This API will be replaced with a new API that supports unicode. This API uses the memory allocation callback function provided by the user.
int ADL_ApplicationProfiles_ProfileOfAnApplication_Search ( const char *             FileName,
                                                            const char *             Path,
                                                            const char *             Version,
                                                            const char *             AppProfileArea,
                                                            ADLApplicationProfile ** lppProfile
                                                          );


/// This function retrieves the profile information of an application. This API uses the Caller's Memory Allocation Callback Function to allocate memory pointed by lppProfile. Caller is responsible to de-allocate the memory. 
/// Supported Platforms:
///   Windows 7, 10 and above; 32bit and 64bit 
/// 
/// Parameters
///   [in]  FileName       Specifies the application file name 
///   [in]  Path           Specifies the application file path 
///   [in]  Version        Specifies the application version 
///   [in]  AppProfileArea Specifies the area the profile works on (like 'PX', 'D3D', etc. ) 
///   [out] lppProfile     The pointer to the pointer to the retrieved application profile. Set it to NULL prior to call this API. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes
/// 
/// Remarks
///   This API uses the memory allocation callback function provided by the user.
int ADL_ApplicationProfiles_ProfileOfAnApplicationX2_Search ( const wchar_t *          FileName,
                                                              const wchar_t *          Path,
                                                              const wchar_t *          Version,
                                                              const wchar_t *          AppProfileArea,
                                                              ADLApplicationProfile ** lppProfile
                                                            );


/// This function retrieves data type for the specified property. 
/// Supported Platforms:
///   Windows 7, 10 and above; 32bit and 64bit 
/// 
/// Parameters
///   [in]  DriverArea   Specifies driver area where Property belong to 
///   [in]  PropertyName Specifies name of property 
///   [out] outType      The data type of property 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes
/// 
/// Remarks
///   This API retrieves data type for the specified property.
int ADL_ApplicationProfiles_PropertyType_Get ( const wchar_t * DriverArea,
                                               const wchar_t * PropertyName,
                                               DATATYPES *     outType
                                             );


/// This function returns release of installed system application profile blob file. 
/// Supported Platforms:
///   Windows 7, 10 and above; 32bit and 64bit 
/// 
/// Parameters
///   [out] strRelease The pointer to the stRelease. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes
/// 
/// Remarks
///   This API returns release of installed system application profile blob file.
int ADL_ApplicationProfiles_Release_Get ( );


/// This function removes the specified application record. 
/// Supported Platforms:
///   Windows 7, 10 and above; 32bit and 64bit 
/// 
/// Parameters
///   [in] FileName   Specifies the name of file 
///   [in] Path       Specifies the path where file locates 
///   [in] Version    Specifies version 
///   [in] DriverArea Specifies driver area where Profile exists 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes
/// 
/// Remarks
///   This API removes the specified application record.
int ADL_ApplicationProfiles_RemoveApplication ( const wchar_t * FileName,
                                                const wchar_t * Path,
                                                const wchar_t * Version,
                                                const wchar_t * DriverArea
                                              );


/// Function to Reload System appprofiles. 
/// 
/// This function Reloads System appprofiles by reloading system profile and loading user profile. 
/// Supported Platforms:
///   Windows 7, 10 and above; 32bit and 64bit 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes
int ADL_ApplicationProfiles_System_Reload ( );


/// Function to Load User appprofiles. 
/// 
/// This function Loads User appprofiles by loadding system profile and user profile. 
/// Supported Platforms:
///   Windows 7, 10 and above; 32bit and 64bit 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes
int ADL_ApplicationProfiles_User_Load ( );


/// Function to Unload User appprofiles. 
/// 
/// This function Unloads User appprofiles by unloading user profile. 
/// Supported Platforms:
///   Windows 7, 10 and above; 32bit and 64bit 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes
int ADL_ApplicationProfiles_User_Unload ( );


/// 
int GetAMDAdapterIndex ( );


#endif /* ADL_HEADER_APPPROFILES_H_ */
