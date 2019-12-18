# ----------------- BEGIN LICENSE BLOCK ---------------------------------
#
# Copyright (C) 2017-2019 Intel Corporation
#
# SPDX-License-Identifier: MIT
#
# ----------------- END LICENSE BLOCK -----------------------------------

#####################################################################
# MapMaker - Common - library
#####################################################################
find_package(Boost COMPONENTS REQUIRED
  program_options
  system
  filesystem
)

# TODO split into common, Logging, ProgramOptions?
add_library(ad_map_maker_common  STATIC
  src/StringHelper.cpp
  src/LogLevel.cpp
  src/LogChannel.cpp
  src/LogFactory.cpp
  src/RightOfWay.cpp
  src/RightOfWayLexicalCast.cpp
  src/AppConfigDescription.cpp
  src/OsmConverterConfigDescription.cpp
  src/MapGenerationConfigDescription.cpp
  src/ProgramOptions.cpp
  src/MapGenerationLevel.cpp
  src/MapGenerationLevelLexicalCast.cpp
  src/TaskTimer.cpp
)

target_include_directories(ad_map_maker_common
  PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/include>
  PRIVATE
  ${PROJECT_BINARY_DIR}/include
)

target_link_libraries(ad_map_maker_common
  Boost::program_options
  Boost::system
  Boost::filesystem
  ad_map_access
)

add_library(${PROJECT_NAMESPACE}common ALIAS ad_map_maker_common)

#####################################################################
# Common - tests
#####################################################################

if(BUILD_TESTING)
endif()
