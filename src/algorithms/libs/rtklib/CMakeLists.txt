# Copyright (C) 2012-2020  (see AUTHORS file for a list of contributors)
#
# GNSS-SDR is a software-defined Global Navigation Satellite Systems receiver
#
# This file is part of GNSS-SDR.
#
# SPDX-License-Identifier: GPL-3.0-or-later
#


set(RTKLIB_LIB_SOURCES
    rtklib_rtkcmn.cc
    rtklib_ephemeris.cc
    rtklib_preceph.cc
    rtklib_sbas.cc
    rtklib_ionex.cc
    rtklib_pntpos.cc
    rtklib_ppp.cc
    rtklib_tides.cc
    rtklib_lambda.cc
    rtklib_rtkpos.cc
    rtklib_conversions.cc
    rtklib_stream.cc
    rtklib_rtksvr.cc
    rtklib_solution.cc
    rtklib_rtcm.cc
    rtklib_rtcm2.cc
    rtklib_rtcm3.cc
)

set(RTKLIB_LIB_HEADERS
    rtklib_rtkcmn.h
    rtklib_ephemeris.h
    rtklib_preceph.h
    rtklib_sbas.h
    rtklib_ionex.h
    rtklib_pntpos.h
    rtklib_ppp.h
    rtklib_tides.h
    rtklib_lambda.h
    rtklib_rtkpos.h
    rtklib_conversions.h
    rtklib_stream.h
    rtklib_rtksvr.h
    rtklib_solution.h
    rtklib_rtcm.h
    rtklib_rtcm2.h
    rtklib_rtcm3.h
    rtklib.h
)

list(SORT RTKLIB_LIB_HEADERS)
list(SORT RTKLIB_LIB_SOURCES)

source_group(Headers FILES ${RTKLIB_LIB_HEADERS})

add_library(algorithms_libs_rtklib ${RTKLIB_LIB_SOURCES} ${RTKLIB_LIB_HEADERS})

target_link_libraries(algorithms_libs_rtklib
    PRIVATE
        core_system_parameters
        Gflags::gflags
        Glog::glog
        ${LAPACK_LIBRARIES}
        ${BLAS_LIBRARIES}
)

set_property(TARGET algorithms_libs_rtklib
    APPEND PROPERTY INTERFACE_INCLUDE_DIRECTORIES
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
)
