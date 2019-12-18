# ----------------- BEGIN LICENSE BLOCK ---------------------------------
#
# Copyright (C) 2018-2019 Intel Corporation
#
# SPDX-License-Identifier: MIT
#
# ----------------- END LICENSE BLOCK -----------------------------------

#####################################################################
# MapMaker - map_data - library
#####################################################################

add_library(ad_map_maker_map_data STATIC
  src/MapDataStore.cpp
  src/Lane.cpp
  src/Intersection.cpp
  src/Road.cpp
  src/MapDataGenerator.cpp
  src/MapDataValidator.cpp
  src/LandmarkType.cpp
  src/PolyLineConversion.cpp
  src/IntersectionConnector.cpp
  src/BigIntersectionGenerator.cpp
  src/TurnConstraint.cpp
)

target_include_directories(ad_map_maker_map_data
  PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
)

target_link_libraries(ad_map_maker_map_data
  mapmaker::common
  mapmaker::geometry
  ad_map_access
)

add_library(${PROJECT_NAMESPACE}map_data ALIAS ad_map_maker_map_data)

#####################################################################
# MapData - tests
#####################################################################

if(BUILD_TESTING)
endif()
