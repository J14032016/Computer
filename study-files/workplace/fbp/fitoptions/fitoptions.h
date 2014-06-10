/*
 * MATLAB Compiler: 4.11 (R2009b)
 * Date: Fri May 16 21:34:07 2014
 * Arguments: "-B" "macro_default" "-l" "fitoptions.m" 
 */

#ifndef __fitoptions_h
#define __fitoptions_h 1

#if defined(__cplusplus) && !defined(mclmcrrt_h) && defined(__linux__)
#  pragma implementation "mclmcrrt.h"
#endif
#include "mclmcrrt.h"
#ifdef __cplusplus
extern "C" {
#endif

#if defined(__SUNPRO_CC)
/* Solaris shared libraries use __global, rather than mapfiles
 * to define the API exported from a shared library. __global is
 * only necessary when building the library -- files including
 * this header file to use the library do not need the __global
 * declaration; hence the EXPORTING_<library> logic.
 */

#ifdef EXPORTING_fitoptions
#define PUBLIC_fitoptions_C_API __global
#else
#define PUBLIC_fitoptions_C_API /* No import statement needed. */
#endif

#define LIB_fitoptions_C_API PUBLIC_fitoptions_C_API

#elif defined(_HPUX_SOURCE)

#ifdef EXPORTING_fitoptions
#define PUBLIC_fitoptions_C_API __declspec(dllexport)
#else
#define PUBLIC_fitoptions_C_API __declspec(dllimport)
#endif

#define LIB_fitoptions_C_API PUBLIC_fitoptions_C_API


#else

#define LIB_fitoptions_C_API

#endif

/* This symbol is defined in shared libraries. Define it here
 * (to nothing) in case this isn't a shared library. 
 */
#ifndef LIB_fitoptions_C_API 
#define LIB_fitoptions_C_API /* No special import/export declaration */
#endif

extern LIB_fitoptions_C_API 
bool MW_CALL_CONV fitoptionsInitializeWithHandlers(
       mclOutputHandlerFcn error_handler, 
       mclOutputHandlerFcn print_handler);

extern LIB_fitoptions_C_API 
bool MW_CALL_CONV fitoptionsInitialize(void);

extern LIB_fitoptions_C_API 
void MW_CALL_CONV fitoptionsTerminate(void);



extern LIB_fitoptions_C_API 
void MW_CALL_CONV fitoptionsPrintStackTrace(void);

extern LIB_fitoptions_C_API 
bool MW_CALL_CONV mlxFitoptions(int nlhs, mxArray *plhs[], int nrhs, mxArray *prhs[]);

extern LIB_fitoptions_C_API 
long MW_CALL_CONV fitoptionsGetMcrID();



extern LIB_fitoptions_C_API bool MW_CALL_CONV mlfFitoptions(int nargout, mxArray** f, mxArray* varargin);

#ifdef __cplusplus
}
#endif
#endif
