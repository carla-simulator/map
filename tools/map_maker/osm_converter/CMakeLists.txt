# ----------------- BEGIN LICENSE BLOCK ---------------------------------
#
# Copyright (C) 2017-2020 Intel Corporation
#
# SPDX-License-Identifier: MIT
#
# ----------------- END LICENSE BLOCK -----------------------------------

#####################################################################
# MapMaker - osm_converter - library
#####################################################################
add_library(ad_map_maker_osm_converter STATIC
  src/OsmCollector.cpp
  src/OsmObjectStore.cpp
  src/OsmJunctionProcessor.cpp
  src/OsmPoiExtractor.cpp
  src/OsmPoiProcessor.cpp
  src/OsmHighwayType.cpp
  src/OsmWayProcessor.cpp
  src/OsmProcessor.cpp
  src/PointStore.cpp
  src/OsmWayIterator.cpp
  src/OsmWayTraveler.cpp
  src/PoiType.cpp
  src/OsmMultiLane.cpp
  src/OsmMultiLaneInterpolation.cpp
  src/OsmTurnDirection.cpp
  src/OsmToInternalMapping.cpp
  src/OsmToInternalConverter.cpp
  src/OsmStringToTrafficSign.cpp
  src/OsmTrafficSignsDE.cpp
  src/OsmTrafficSignsPL.cpp
  src/OsmTransitionDetector.cpp
)

# For now, we make osmium public because we don't want to hide it in the implementation
target_include_directories(ad_map_maker_osm_converter
  PUBLIC
  ${OSMIUM_INCLUDE_DIRS}
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  PRIVATE
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src>
)

target_link_libraries(ad_map_maker_osm_converter
  PUBLIC
  Threads::Threads
  ${EXPAT}
  mapmaker::map_data
  mapmaker::common
  mapmaker::geometry
)

add_library(${PROJECT_NAMESPACE}osm_converter ALIAS ad_map_maker_osm_converter)

#####################################################################
# osm_converter - tests
#####################################################################

if(BUILD_TESTING)
endif()
