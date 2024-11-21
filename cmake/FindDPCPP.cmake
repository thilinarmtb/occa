###############################################################################
# FIND module for DPCPP components
# This Find module is also distributed alongside the occa package config file!
###############################################################################

message(CHECK_START "Looking for DPC++")
unset(missingDpcppComponents)

find_path(
  SYCL_INCLUDE_DIR
  NAMES
    sycl/sycl.hpp
  PATHS
    ENV SYCL_ROOT
    /opt/intel/oneapi/compiler/latest/linux
    ${SYCL_ROOT}
  PATH_SUFFIXES
    include/sycl
    include/CL
    include/sycl/CL)

find_library(
  SYCL_LIBRARIES
  NAMES
    sycl libsycl
  PATHS
    ENV SYCL_ROOT
    /opt/intel/oneapi/compiler/latest/linux
    ${SYCL_ROOT}
  PATH_SUFFIXES
    lib)

include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(
    DPCPP
    REQUIRED_VARS
    SYCL_INCLUDE_DIR
    SYCL_LIBRARIES)

if(DPCPP_FOUND AND NOT TARGET OCCA::depends::DPCPP)
  # Create our wrapper imported target
  # Put it in the OCCA namespace to make it clear that we created it.
  add_library(OCCA::depends::DPCPP INTERFACE IMPORTED)
  set_target_properties(OCCA::depends::DPCPP PROPERTIES
    INTERFACE_INCLUDE_DIRECTORIES "${SYCL_INCLUDE_DIR};${SYCL_INCLUDE_DIR}/sycl"
    INTERFACE_LINK_LIBRARIES "${SYCL_LIBRARIES}"
  )
endif()
