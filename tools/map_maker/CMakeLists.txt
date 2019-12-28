# ----------------- BEGIN LICENSE BLOCK ---------------------------------
#
# Copyright (C) 2017-2019 Intel Corporation
#
# SPDX-License-Identifier: MIT
#
# ----------------- END LICENSE BLOCK -----------------------------------
cmake_minimum_required(VERSION 3.5)

#####################################################################
# MapMaker - general setup
#####################################################################
project(MapMaker)
set(PROJECT_NAMESPACE mapmaker::)

option(BUILD_MAP_MAKER "Build tool to generate ad_map from OSM" OFF)

if (NOT BUILD_MAP_MAKER)
  return()
endif()

include(../../cmake/testing.cmake)
include(GNUInstallDirs)
include(CMakePackageConfigHelpers)

find_package(ad_map_access REQUIRED CONFIG)

# This is for libosmium
find_package(Osmium 2.13 QUIET)

if (NOT OSMIUM_FOUND)
  message(STATUS "Unable to find relevant version of libosmium2-dev. Initiate download...")

  configure_file(libosmium-cmake.txt.in libosmium-download/CMakeLists.txt)
  execute_process(COMMAND "${CMAKE_COMMAND}" . RESULT_VARIABLE result WORKING_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}/libosmium-download")
  execute_process(COMMAND "${CMAKE_COMMAND}" --build . RESULT_VARIABLE result WORKING_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}/libosmium-download")

  set(OSMIUM_INCLUDE_DIRS ${CMAKE_CURRENT_BINARY_DIR}/libosmium-src/include)
endif()

#osmium's xml_input needs threads, and libexpat
set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)
find_library(EXPAT NAMES "expat")

set(CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
#todo add -Wshadow
add_compile_options(-Wall -Wextra -Werror -Wconversion -pedantic)

#####################################################################
# Libraries
#####################################################################
if(BUILD_TESTING)
  add_subdirectory(test_helper)
endif()
add_subdirectory(geometry)
add_subdirectory(common)
add_subdirectory(osm_converter)
add_subdirectory(map_data)
add_subdirectory(admap_generator)

#####################################################################
# Binaries
#####################################################################
add_subdirectory(osm_to_adm)
