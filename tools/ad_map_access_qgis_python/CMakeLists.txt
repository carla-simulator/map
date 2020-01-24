# ----------------- BEGIN LICENSE BLOCK ---------------------------------
#
# Copyright (C) 2018-2020 Intel Corporation
#
# SPDX-License-Identifier: MIT
#
# ----------------- END LICENSE BLOCK -----------------------------------

cmake_minimum_required(VERSION 3.5)

include(GNUInstallDirs)

set(CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD 14)

project(ad_map_access_qgis_python)

find_package(ad_map_access REQUIRED CONFIG)
find_package(PythonLibs 2.7 REQUIRED)

# since this library has to be loadable from within python, it has to be shared
add_library(${PROJECT_NAME} SHARED
  src/core_py_database.cpp
  src/core_py_landmark.cpp
  src/core_py_lane.cpp
  src/core_py_log.cpp
  src/core_py_misc.cpp
  src/core_py_routing.cpp
  src/core_py_utils.cpp
  src/core_py_writer.cpp
  src/core_py.cpp
  src/py_inter_lane_maker.cpp
  src/py_landmark.cpp
  src/py_lane.cpp
  src/py_point.cpp
  src/py_restriction.cpp
  src/py_utils.cpp
)

set_target_properties(${PROJECT_NAME} PROPERTIES
  # Appending the version explicitly disabled
  OUTPUT_NAME ${PROJECT_NAME}
  # Don't call it libsomething
  PREFIX ""
)

# since python2.7 doesn't obey strict-aliasing rules...
set_target_properties(${PROJECT_NAME} PROPERTIES
  COMPILE_FLAGS "-Wno-error=strict-aliasing")

target_include_directories(${PROJECT_NAME}
  PRIVATE
  include
  ad_map_access
  ${PYTHON_INCLUDE_DIR}
)

target_link_libraries(${PROJECT_NAME}
  PUBLIC
  ad_map_access
)

#
# set proper installation path
#
if ("${AD_MAP_ACCESS_PYTHON_INSTALL_PATH}" STREQUAL "")
  set(AD_MAP_ACCESS_PYTHON_INSTALL_PATH ${CMAKE_INSTALL_PREFIX}/lib/python2.7)
endif()

install(TARGETS ${PROJECT_NAME} EXPORT ${PROJECT_NAME}_EXPORT
  ARCHIVE DESTINATION ${AD_MAP_ACCESS_PYTHON_INSTALL_PATH}
  LIBRARY DESTINATION ${AD_MAP_ACCESS_PYTHON_INSTALL_PATH}
)
