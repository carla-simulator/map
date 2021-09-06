# ----------------- BEGIN LICENSE BLOCK ---------------------------------
#
# Copyright (C) 2019-2021 Intel Corporation
#
# SPDX-License-Identifier: MIT
#
# ----------------- END LICENSE BLOCK -----------------------------------

cmake_minimum_required(VERSION 3.5)

include(../cmake/carla-map-version.cmake)
project(ad_map_access VERSION ${CARLA-MAP_VERSION})

include(../cmake/compile-options.cmake)
include(../cmake/hardening.cmake)
include(../cmake/testing.cmake)
include(../cmake/warnings.cmake)
include(../cmake/apidoc.cmake)
include(../cmake/python-binding.cmake)

#convert list to string
string (REPLACE ";" " " TARGET_LINK_FLAGS "${TARGET_LINK_OPTIONS}")

include(GNUInstallDirs)
include(CMakePackageConfigHelpers)

set(ad_map_access_TARGET_INCLUDE_DIRECTORIES)
set(ad_map_access_TARGET_LINK_LIBRARIES)

find_package(Boost REQUIRED COMPONENTS program_options filesystem)
get_target_property(BOOST_PROGRAM_OPTIONS_INTERFACE_INCLUDE_DIRS Boost::program_options INTERFACE_INCLUDE_DIRECTORIES)
list(APPEND ad_map_access_TARGET_INCLUDE_DIRECTORIES ${BOOST_PROGRAM_OPTIONS_INTERFACE_INCLUDE_DIRS})
list(APPEND ad_map_access_TARGET_LINK_LIBRARIES Boost::program_options)
get_target_property(BOOST_FILESYSTEM_INTERFACE_INCLUDE_DIRS Boost::filesystem INTERFACE_INCLUDE_DIRECTORIES)
list(APPEND ad_map_access_TARGET_INCLUDE_DIRECTORIES ${BOOST_FILESYSTEM_INTERFACE_INCLUDE_DIRS})
list(APPEND ad_map_access_TARGET_LINK_LIBRARIES Boost::filesystem)

find_package(ad_map_opendrive_reader ${CARLA-MAP_VERSION} EXACT REQUIRED CONFIG)
find_package(ad_physics ${CARLA-MAP_VERSION} EXACT REQUIRED CONFIG)
find_package(spdlog REQUIRED CONFIG)

include(generated/ad_map_access.cmake)

add_library(${PROJECT_NAME}
  ${ad_map_access_GENERATED_SOURCES}
  ${CMAKE_CURRENT_SOURCE_DIR}/src/access/AdMapAccess.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/src/access/Factory.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/src/access/GeometryStore.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/src/access/Logging.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/src/access/Operation.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/src/access/Store.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/src/access/StoreSerialization.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/src/config/MapConfigFileHandler.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/src/intersection/CoreIntersection.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/src/intersection/Intersection.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/src/landmark/LandmarkOperation.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/src/lane/BorderOperation.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/src/lane/LaneOperation.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/src/match/AdMapMatching.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/src/match/MapMatchedOperation.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/src/opendrive/AdMapFactory.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/src/opendrive/DataTypeConversion.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/src/point/BoundingSphereOperation.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/src/point/CoordinateTransform.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/src/point/ECEFOperation.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/src/point/ENUOperation.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/src/point/GeometryOperation.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/src/point/GeoOperation.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/src/point/HeadingOperation.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/src/point/Transform.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/src/restriction/RestrictionOperation.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/src/route/LaneIntervalOperation.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/src/route/Planning.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/src/route/Route.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/src/route/RouteAStar.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/src/route/RouteOperation.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/src/route/RoutePrediction.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/src/serialize/ChecksumCRC32.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/src/serialize/SerializeGeneratedLaneTypes.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/src/serialize/Serializer.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/src/serialize/StorageFile.cpp
  )

target_compile_definitions(${PROJECT_NAME} PUBLIC ${TARGET_COMPILE_DEFINITIONS})
target_compile_options(${PROJECT_NAME} PRIVATE ${TARGET_COMPILE_OPTIONS})
set_property(TARGET ${PROJECT_NAME} APPEND_STRING PROPERTY LINK_FLAGS ${TARGET_LINK_FLAGS})

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/cmake/Version.hpp.in ${CMAKE_CURRENT_BINARY_DIR}/include/${PROJECT_NAME}/Version.hpp)

target_include_directories(${PROJECT_NAME} PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/generated/include>
  $<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}/include>
  $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
  ${ad_map_access_TARGET_INCLUDE_DIRECTORIES}
)

target_link_libraries(${PROJECT_NAME} PUBLIC
  ad_physics
  ad_map_opendrive_reader
  spdlog::spdlog
  PRIVATE
  ${ad_map_access_TARGET_LINK_LIBRARIES}
)

install(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/include/
  DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
  FILES_MATCHING PATTERN "*.h" PATTERN "*.hpp"
)

install(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/generated/include/
  DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
  FILES_MATCHING PATTERN "*.h" PATTERN "*.hpp"
)

install(DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/include/
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

#####################################################################
# Tests
#####################################################################
if (BUILD_TESTING)
  add_subdirectory(tests)
endif()

#####################################################################
# Python binding
#####################################################################
if(BUILD_PYTHON_BINDING)
  add_subdirectory(python)
endif()
