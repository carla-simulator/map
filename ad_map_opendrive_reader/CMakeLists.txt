# ----------------- BEGIN LICENSE BLOCK ---------------------------------
#
# Copyright (C) 2019-2021 Intel Corporation
#
# SPDX-License-Identifier: MIT
#
# ----------------- END LICENSE BLOCK -----------------------------------

cmake_minimum_required(VERSION 3.5)

include(../cmake/carla-map-version.cmake)
project(ad_map_opendrive_reader VERSION ${CARLA-MAP_VERSION})

include(../cmake/compile-options.cmake)
include(../cmake/hardening.cmake)
include(../cmake/testing.cmake)
include(../cmake/warnings.cmake)
include(../cmake/apidoc.cmake)

#convert list to string
string (REPLACE ";" " " TARGET_LINK_FLAGS "${TARGET_LINK_OPTIONS}")

include(GNUInstallDirs)
include(CMakePackageConfigHelpers)

set(ad_map_opendrive_reader_TARGET_INCLUDE_DIRECTORIES)
set(ad_map_opendrive_reader_TARGET_LINK_LIBRARIES)

find_package(Boost REQUIRED)
list(APPEND ad_map_opendrive_reader_TARGET_INCLUDE_DIRECTORIES ${Boost_INCLUDE_DIRS})

find_package(spdlog REQUIRED CONFIG)

#pugixml
find_library(PUGIXML_LIBRARIES
  NAMES pugixml
)
find_path(PUGIXML_INCLUDE_DIR
  NAMES pugixml.hpp
)
list(APPEND ad_map_opendrive_reader_TARGET_INCLUDE_DIRECTORIES ${PUGIXML_INCLUDE_DIR})
list(APPEND ad_map_opendrive_reader_TARGET_LINK_LIBRARIES ${PUGIXML_LIBRARIES})

if((NOT PUGIXML_LIBRARIES) OR (NOT PUGIXML_INCLUDE_DIR))
  message(FATAL "Dependency pugixml not found!")
endif()

find_library(PROJ_LIBRARIES
  NAMES proj
)
find_path(PROJ_INCLUDE_DIR
  NAMES proj_api.h
)
list(APPEND ad_map_opendrive_reader_TARGET_INCLUDE_DIRECTORIES ${PROJ_INCLUDE_DIR})
list(APPEND ad_map_opendrive_reader_TARGET_LINK_LIBRARIES ${PROJ_LIBRARIES})

if((NOT PROJ_LIBRARIES) OR (NOT PROJ_INCLUDE_DIR))
  message(FATAL "Dependency proj not found!")
endif()

add_library(${PROJECT_NAME}
  ${CMAKE_CURRENT_SOURCE_DIR}/src/parser/ControllerParser.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/src/parser/GeometryParser.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/src/parser/GeoReferenceParser.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/src/parser/JunctionParser.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/src/parser/LaneParser.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/src/parser/ObjectParser.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/src/parser/OpenDriveParser.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/src/parser/ProfilesParser.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/src/parser/RoadLinkParser.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/src/parser/TrafficGroupParser.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/src/parser/TrafficSignalsParser.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/src/parser/TrafficSignParser.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/src/geometry/CenterLine.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/src/geometry/Geometry.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/src/geometry/GeometryGenerator.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/src/geometry/LaneSectionSampling.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/src/geometry/LaneUtils.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/src/OpenDrive.cpp
)

target_compile_definitions(${PROJECT_NAME} PUBLIC ${TARGET_COMPILE_DEFINITIONS})
target_compile_options(${PROJECT_NAME} PRIVATE ${TARGET_COMPILE_OPTIONS})
set_property(TARGET ${PROJECT_NAME} APPEND_STRING PROPERTY LINK_FLAGS ${TARGET_LINK_FLAGS})

target_include_directories(${PROJECT_NAME} PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
  ${ad_map_opendrive_reader_TARGET_INCLUDE_DIRECTORIES}
)

target_link_libraries(${PROJECT_NAME}
  PRIVATE
  spdlog::spdlog
  ${ad_map_opendrive_reader_TARGET_LINK_LIBRARIES}
)

install(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/include/
  DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
  FILES_MATCHING PATTERN "*.h" PATTERN "*.hpp"
)

install(TARGETS ${PROJECT_NAME} EXPORT ${PROJECT_NAME}_EXPORT
  ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
  LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

set(CMAKECONFIG_INSTALL_DIR "${CMAKE_INSTALL_LIBDIR}/cmake/${PROJECT_NAME}")

install(EXPORT ${PROJECT_NAME}_EXPORT
  FILE ${PROJECT_NAME}Targets.cmake
  DESTINATION ${CMAKECONFIG_INSTALL_DIR}
)

configure_package_config_file(${CMAKE_CURRENT_SOURCE_DIR}/cmake/Config.cmake.in
  ${CMAKE_CURRENT_BINARY_DIR}/install/${PROJECT_NAME}Config.cmake
  INSTALL_DESTINATION ${CMAKECONFIG_INSTALL_DIR}
)

write_basic_package_version_file(${CMAKE_CURRENT_BINARY_DIR}/install/${PROJECT_NAME}ConfigVersion.cmake
  COMPATIBILITY SameMajorVersion
)

install(FILES
  ${CMAKE_CURRENT_BINARY_DIR}/install/${PROJECT_NAME}Config.cmake
  ${CMAKE_CURRENT_BINARY_DIR}/install/${PROJECT_NAME}ConfigVersion.cmake
  DESTINATION ${CMAKECONFIG_INSTALL_DIR}
)
