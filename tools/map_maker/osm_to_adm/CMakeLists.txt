# ----------------- BEGIN LICENSE BLOCK ---------------------------------
#
# INTEL CONFIDENTIAL
#
# Copyright (c) 2018-2019 Intel Corporation
#
# This software and the related documents are Intel copyrighted materials, and
# your use of them is governed by the express license under which they were
# provided to you (License). Unless the License provides otherwise, you may not
# use, modify, copy, publish, distribute, disclose or transmit this software or
# the related documents without Intel's prior written permission.
#
# This software and the related documents are provided as is, with no express or
# implied warranties, other than those that are expressly stated in the License.
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
