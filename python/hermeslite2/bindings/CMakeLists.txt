# Copyright 2020 Free Software Foundation, Inc.
#
# This file is part of GNU Radio
#
# SPDX-License-Identifier: GPL-3.0-or-later
#

########################################################################
# Check if there is C++ code at all
########################################################################
if(NOT hermeslite2_sources)
    MESSAGE(STATUS "No C++ sources... skipping python bindings")
    return()
endif(NOT hermeslite2_sources)

########################################################################
# Check for pygccxml
########################################################################
GR_PYTHON_CHECK_MODULE_RAW(
    "pygccxml"
    "import pygccxml"
    PYGCCXML_FOUND
    )

include(GrPybind)

########################################################################
# Python Bindings
########################################################################
list(APPEND hermeslite2_python_files
    hermesNB_python.cc
    hermesWB_python.cc python_bindings.cc)

GR_PYBIND_MAKE_OOT(hermeslite2
   ../../..
   gr::hermeslite2
   "${hermeslite2_python_files}")

# copy bindings extension for use in QA test module
add_custom_command(TARGET hermeslite2_python POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:hermeslite2_python>
    ${PROJECT_BINARY_DIR}/test_modules/gnuradio/hermeslite2/
)

install(TARGETS hermeslite2_python DESTINATION ${GR_PYTHON_DIR}/gnuradio/hermeslite2 COMPONENT pythonapi)
