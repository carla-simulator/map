# ----------------- BEGIN LICENSE BLOCK ---------------------------------
#
# Copyright (C) 2018-2019 Intel Corporation
#
# SPDX-License-Identifier: MIT
#
# ----------------- END LICENSE BLOCK -----------------------------------

#####################################################################
# MapMaker - admap_generator - library
#####################################################################
add_library(ad_map_maker_ad_map_generator STATIC
  src/AdMapGenerator.cpp
  src/AdMapLandmarkTypeGenerator.cpp
)

target_include_directories(ad_map_maker_ad_map_generator
  PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
)

add_library(${PROJECT_NAMESPACE}ad_map_generator ALIAS ad_map_maker_ad_map_generator)

target_link_libraries(ad_map_maker_ad_map_generator
  PUBLIC
  mapmaker::common
  mapmaker::map_data
  ad_map_access
)
#####################################################################
# AdMapGenerator - tests
#####################################################################

if(BUILD_TESTING)
endif()
