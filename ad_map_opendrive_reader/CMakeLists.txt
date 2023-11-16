# ----------------- BEGIN LICENSE BLOCK ---------------------------------
#
# Copyright (C) 2019-2022 Intel Corporation
#
# SPDX-License-Identifier: MIT
#
# ----------------- END LICENSE BLOCK -----------------------------------

cmake_minimum_required(VERSION 3.5)

project(ad_map_opendrive_reader)

include(../cmake/compile-options.cmake)
include(../cmake/hardening.cmake)
include(../cmake/testing.cmake)
include(../cmake/warnings.cmake)
include(../cmake/apidoc.cmake)

#convert list to string
string (REPLACE ";" " " TARGET_LINK_FLAGS "${TARGET_LINK_OPTIONS}")

project(ad_map_opendrive_reader VERSION 2.4.5)

include(GNUInstallDirs)
include(CMakePackageConfigHelpers)

set(CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD 14)

option(BUILD_SHARED_LIBS "Build shared libraries instead of static ones" ON)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

set(PROJECT_SOURCE_LIST
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

add_library(${PROJECT_NAME} ${PROJECT_SOURCE_LIST})

#####################################################################
# dependencies
#####################################################################

find_package(Boost REQUIRED)

find_package(spdlog REQUIRED CONFIG)

#pugixml
find_library(PUGIXML_LIBRARIES
  NAMES pugixml
)
find_path(PUGIXML_INCLUDE_DIR
  NAMES pugixml.hpp
)

if((NOT PUGIXML_LIBRARIES) OR (NOT PUGIXML_INCLUDE_DIR))
  message(FATAL "Dependency pugixml not found!")
endif()

find_library(PROJ_LIBRARIES
  NAMES proj
  HINTS
    ${CMAKE_CURRENT_BINARY_DIR}/../../install/PROJ4/lib
)
find_path(PROJ_INCLUDE_DIR
  NAMES proj_api.h
  HINTS
    ${CMAKE_CURRENT_BINARY_DIR}/../../install/PROJ4/include
)

if((NOT PROJ_LIBRARIES) OR (NOT PROJ_INCLUDE_DIR))
  message(FATAL "Dependency proj not found ${CMAKE_CURRENT_BINARY_DIR}!")
endif()

#odrSpiral
find_library(ODRSPIRAL_LIBRARIES
  NAMES odrSpiral
  HINTS
    ${CMAKE_CURRENT_BINARY_DIR}/../../dependencies/odrSpiral/lib
    ${CMAKE_CURRENT_SOURCE_DIR}/../dependencies/odrSpiral/lib
)
find_path(ODRSPIRAL_INCLUDE_DIR
  NAMES odrSpiral.h
  HINTS
    ${CMAKE_CURRENT_BINARY_DIR}/../../dependencies/odrSpiral/include
    ${CMAKE_CURRENT_SOURCE_DIR}/../dependencies/odrSpiral/include
)
list(APPEND ad_map_opendrive_reader_TARGET_INCLUDE_DIRECTORIES )
list(APPEND ad_map_opendrive_reader_TARGET_LINK_LIBRARIES )

if((NOT ODRSPIRAL_LIBRARIES) OR (NOT ODRSPIRAL_INCLUDE_DIR))
  message(FATAL "Dependency odrSpiral not found!")
endif()

target_include_directories(${PROJECT_NAME}
  PRIVATE
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  ${PUGIXML_INCLUDE_DIR}
  ${PROJ_INCLUDE_DIR}
  ${Boost_INCLUDE_DIRS}
  ${ODRSPIRAL_INCLUDE_DIR}
)

target_link_libraries(${PROJECT_NAME}
  PRIVATE
  ${PUGIXML_LIBRARIES}
  ${PROJ_LIBRARIES}
  ${ODRSPIRAL_LIBRARIES}
  spdlog::spdlog
)

set(PROJECT_PUBLIC_HEADER_LIST
  "${CMAKE_CURRENT_SOURCE_DIR}/include/opendrive/types.hpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/include/opendrive/OpenDrive.hpp"
)

set_target_properties(${PROJECT_NAME} PROPERTIES PUBLIC_HEADER "${PROJECT_PUBLIC_HEADER_LIST}")


target_compile_definitions(${PROJECT_NAME} PUBLIC ${TARGET_COMPILE_DEFINITIONS})
target_compile_options(${PROJECT_NAME} PRIVATE ${TARGET_COMPILE_OPTIONS})
set_property(TARGET ${PROJECT_NAME} APPEND_STRING PROPERTY LINK_FLAGS ${TARGET_LINK_FLAGS})

#####################################################################
# installation
#####################################################################

if(IS_ABSOLUTE "${CMAKE_INSTALL_LIBDIR}")
  file(RELATIVE_PATH CMAKE_INSTALL_LIBDIR_RELATIVE "${CMAKE_INSTALL_PREFIX}" "${CMAKE_INSTALL_LIBDIR}")
else()
  set(CMAKE_INSTALL_LIBDIR_RELATIVE "${CMAKE_INSTALL_LIBDIR}")
endif()

install(TARGETS ${PROJECT_NAME} EXPORT ${PROJECT_NAME}_EXPORT
  ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR_RELATIVE}
  LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR_RELATIVE}
  PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/opendrive
  INCLUDES DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)

set(CMAKECONFIG_INSTALL_DIR "${CMAKE_INSTALL_LIBDIR_RELATIVE}/cmake/${PROJECT_NAME}")

install(EXPORT ${PROJECT_NAME}_EXPORT
  FILE ${PROJECT_NAME}Targets.cmake
  DESTINATION ${CMAKECONFIG_INSTALL_DIR}
)

configure_package_config_file(${CMAKE_CURRENT_LIST_DIR}/cmake/Config.cmake.in
  ${CMAKE_CURRENT_BINARY_DIR}/install/${PROJECT_NAME}Config.cmake
  INSTALL_DESTINATION ${CMAKECONFIG_INSTALL_DIR}
)

write_basic_package_version_file(${CMAKE_CURRENT_BINARY_DIR}/install/${PROJECT_NAME}ConfigVersion.cmake
  COMPATIBILITY SameMajorVersion
)

install(FILES
  "${CMAKE_CURRENT_BINARY_DIR}/install/${PROJECT_NAME}Config.cmake"
  "${CMAKE_CURRENT_BINARY_DIR}/install/${PROJECT_NAME}ConfigVersion.cmake"
  DESTINATION ${CMAKECONFIG_INSTALL_DIR}
)
