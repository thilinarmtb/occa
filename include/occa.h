#ifndef OCCA_C_HEADER
#define OCCA_C_HEADER

#include <occa/c/base.h>
#include <occa/c/cli.h>
#include <occa/c/device.h>
#include <occa/c/dtype.h>
#include <occa/c/io.h>
#include <occa/c/json.h>
#include <occa/c/kernel.h>
#include <occa/c/kernelBuilder.h>
#include <occa/c/memory.h>
#include <occa/c/properties.h>
#include <occa/c/scope.h>
#include <occa/c/uva.h>

// Just in case someone wants to run with an older format than C99
#ifndef OCCA_DISABLE_VARIADIC_MACROS

#define OCCA_ARG_COUNT(...) OCCA_ARG_COUNT2(__VA_ARGS__,                \
                                            50,49,48,47,46,45,44,43,42,41, \
                                            40,39,38,37,36,35,34,33,32,31, \
                                            30,29,28,27,26,25,24,23,22,21, \
                                            20,19,18,17,16,15,14,13,12,11, \
                                            10,9,8,7,6,5,4,3,2,1,       \
                                            0)

#define OCCA_ARG_COUNT2(KERNEL,                                   \
                        _1,_2,_3,_4,_5,_6,_7,_8,_9,_10,           \
                        _11,_12,_13,_14,_15,_16,_17,_18,_19,_20,  \
                        _21,_22,_23,_24,_25,_26,_27,_28,_29,_30,  \
                        _31,_32,_33,_34,_35,_36,_37,_38,_39,_40,  \
                        _41,_42,_43,_44,_45,_46,_47,_48,_49,_50,  \
                        N, ...) N

#define OCCA_C_RUN_KERNEL3(N, kernel, ...) occaKernelRunN(kernel, N, __VA_ARGS__)
#define OCCA_C_RUN_KERNEL2(...) OCCA_C_RUN_KERNEL3(__VA_ARGS__)
#define OCCA_C_RUN_KERNEL1(...) OCCA_C_RUN_KERNEL2(__VA_ARGS__)

#define occaKernelRun(...) OCCA_C_RUN_KERNEL1(OCCA_ARG_COUNT(__VA_ARGS__), __VA_ARGS__)

#endif // OCCA_DISABLE_VARIADIC_MACROS

#ifdef OCCA_JIT
#  undef OCCA_JIT
#endif

#define OCCA_JIT(OCCA_SCOPE, OKL_SOURCE)            \
  do {                                              \
    static occaKernelBuilder _inlinedKernelBuilder; \
    static int _inlinedKernelIsDefined = 0;         \
    if (!_inlinedKernelIsDefined) {                 \
      _inlinedKernelBuilder = (                     \
        occaKernelBuilderFromInlinedOkl(            \
          OCCA_SCOPE,                               \
          #OKL_SOURCE,                              \
          OCCA_INLINED_KERNEL_NAME                  \
        )                                           \
      );                                            \
      _inlinedKernelIsDefined = 1;                  \
    }                                               \
    occaKernelBuilderRun(_inlinedKernelBuilder,     \
                         OCCA_SCOPE);               \
  } while (0)


#endif
