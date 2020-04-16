# ----------------- BEGIN LICENSE BLOCK ---------------------------------
#
# Copyright (C) 2018-2020 Intel Corporation
#
# SPDX-License-Identifier: MIT
#
# ----------------- END LICENSE BLOCK -----------------------------------

#####################################################################
# MapMaker - osm_to_adm - tool - using map_data
#####################################################################
add_executable(osm_to_adm
  src/Main.cpp
)

target_include_directories(osm_to_adm
  PRIVATE
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src>
)

target_link_libraries(osm_to_adm
  PRIVATE
  mapmaker::common
  mapmaker::geometry
  mapmaker::osm_converter
  mapmaker::map_data
  mapmaker::ad_map_generator
  ad_map_access
)

install(TARGETS osm_to_adm
  RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
