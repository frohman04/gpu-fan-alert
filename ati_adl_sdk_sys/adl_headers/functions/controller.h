#ifndef ADL_HEADER_CONTROLLER_H_
#define ADL_HEADER_CONTROLLER_H_

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

/// Function to get the current value of gamma for a controller. 
/// 
/// This function retrieves the current gamma value of the specified controller. 
/// Supported Platforms:
///   Linux; 32bit and 64bit 
/// 
/// Parameters
///   [in]  context          Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in]  iAdapterIndex    The ADL index handle of the desired adapter. 
///   [in]  iControllerIndex The desired controller index. 
///   [out] lpGammaCurrent   The pointer to the retrieved current gamma information structure. 
///   [out] lpGammaDefault   The pointer to the retrieved default gamma information structure. 
///   [out] lpGammaMin       The pointer to the retrieved minimum gamma information structure. 
///   [out] lpGammaMax       The pointer to the retrieved maximum gamma information structure. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes 
/// 
/// Remarks
///   Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call ADL2_Main_Control_Create first to obtain ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using ADL2_Main_Control_Destroy. 
/// Deprecated:
///   This API has been deprecated because the controller index is no longer used with DAL2. Replaced by ADL_Display_LUTColor_Get
int ADL2_Controller_Color_Get ( ADL_CONTEXT_HANDLE context,
                                int                iAdapterIndex,
                                int                iControllerIndex,
                                ADLGamma *         lpGammaCurrent,
                                ADLGamma *         lpGammaDefault,
                                ADLGamma *         lpGammaMin,
                                ADLGamma *         lpGammaMax
                              );


/// Function to set the current gamma value for a controller. 
/// 
/// This function sets the gamma value of a specified controller. 
/// Supported Platforms:
///   Linux; 32bit and 64bit 
/// 
/// Parameters
///   [in] context          Client's ADL context handle ADL_CONTEXT_HANDLE obtained from ADL2_Main_Control_Create. 
///   [in] iAdapterIndex    The ADL index handle of the desired adapter. 
///   [in] iControllerIndex The desired controller index. 
///   [in] adlGamma         The Gamma information structure. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes 
/// 
/// Remarks
///   Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call ADL2_Main_Control_Create first to obtain ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using ADL2_Main_Control_Destroy. 
/// Deprecated:
///   This API has been deprecated because the controller index is no longer used with DAL2. Replaced by ADL_Display_LUTColor_Set
int ADL2_Controller_Color_Set ( ADL_CONTEXT_HANDLE context,
                                int                iAdapterIndex,
                                int                iControllerIndex,
                                ADLGamma           adlGamma
                              );


/// Function to get the current value of gamma for a controller. 
/// 
/// This function retrieves the current gamma value of the specified controller. 
/// Supported Platforms:
///   Linux; 32bit and 64bit 
/// 
/// Parameters
///   [in]  iAdapterIndex    The ADL index handle of the desired adapter. 
///   [in]  iControllerIndex The desired controller index. 
///   [out] lpGammaCurrent   The pointer to the retrieved current gamma information structure. 
///   [out] lpGammaDefault   The pointer to the retrieved default gamma information structure. 
///   [out] lpGammaMin       The pointer to the retrieved minimum gamma information structure. 
///   [out] lpGammaMax       The pointer to the retrieved maximum gamma information structure. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes 
/// 
/// Deprecated:
///   This API has been deprecated because the controller index is no longer used with DAL2. Replaced by ADL_Display_LUTColor_Get
int ADL_Controller_Color_Get ( int        iAdapterIndex,
                               int        iControllerIndex,
                               ADLGamma * lpGammaCurrent,
                               ADLGamma * lpGammaDefault,
                               ADLGamma * lpGammaMin,
                               ADLGamma * lpGammaMax
                             );


/// Function to set the current gamma value for a controller. 
/// 
/// This function sets the gamma value of a specified controller. 
/// Supported Platforms:
///   Linux; 32bit and 64bit 
/// 
/// Parameters
///   [in] iAdapterIndex    The ADL index handle of the desired adapter. 
///   [in] iControllerIndex The desired controller index. 
///   [in] adlGamma         The Gamma information structure. 
/// 
/// Returns
///   If the function succeeds, the return value is ADL_OK. Otherwise the return value is an ADL error code. Result Codes 
/// 
/// Deprecated:
///   This API has been deprecated because the controller index is no longer used with DAL2. Replaced by ADL_Display_LUTColor_Set
int ADL_Controller_Color_Set ( int      iAdapterIndex,
                               int      iControllerIndex,
                               ADLGamma adlGamma
                             );


#endif /* ADL_HEADER_CONTROLLER_H_ */
