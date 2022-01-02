#ifndef ADL_HEADER_SECURE_CRT_LINUX_H_
#define ADL_HEADER_SECURE_CRT_LINUX_H_

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

/// 
errno_t strcat_s ( char *       strDestination,
                   size_t       numberOfElements,
                   const char * strSource
                 );


/// 
errno_t strcpy_s ( char *       strDestination,
                   size_t       numberOfElements,
                   const char * strSource
                 );


/// 
errno_t strncpy_s ( char *       strDest,
                    size_t       numberOfElements,
                    const char * strSource,
                    size_t       count
                  );


/// 
errno_t wcscat_s ( wchar_t *       strDestination,
                   size_t          numberOfElements,
                   const wchar_t * strSource
                 );


/// 
errno_t wcscpy_s ( wchar_t *       strDestination,
                   size_t          numberOfElements,
                   const wchar_t * strSource
                 );


/// 
errno_t wcsncpy_s ( wchar_t *       strDest,
                    size_t          numberOfElements,
                    const wchar_t * strSource,
                    size_t          count
                  );


/// 
errno_t wcstombs_s ( size_t *        pReturnValue,
                     char *          mbstr,
                     size_t          sizeInBytes,
                     const wchar_t * wcstr,
                     size_t          count
                   );


/// 
errno_t wctomb_s ( int *   pRetValue,
                   char *  mbchar,
                   size_t  sizeInBytes,
                   wchar_t wchar
                 );


#endif /* ADL_HEADER_SECURE_CRT_LINUX_H_ */
