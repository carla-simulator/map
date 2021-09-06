# ----------------- BEGIN LICENSE BLOCK ---------------------------------
#
# Copyright (C) 2019-2021 Intel Corporation
#
# SPDX-License-Identifier: MIT
#
# ----------------- END LICENSE BLOCK -----------------------------------

cmake_minimum_required(VERSION 3.5)

include(../cmake/carla-map-version.cmake)
project(ad_map_access_test_support VERSION ${CARLA-MAP_VERSION})

include(../cmake/compile-options.cmake)
include(../cmake/hardening.cmake)
include(../cmake/testing.cmake)
include(../cmake/warnings.cmake)

#convert list to string
string (REPLACE ";" " " TARGET_LINK_FLAGS "${TARGET_LINK_OPTIONS}")

include(GNUInstallDirs)
include(CMakePackageConfigHelpers)

find_package(ad_map_access ${CARLA-MAP_VERSION} REQUIRED CONFIG)

add_library(${PROJECT_NAME}
  ${CMAKE_CURRENT_SOURCE_DIR}/src/ArtificialIntersectionTestBase.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/src/IntersectionTestBase.cpp
)

target_compile_definitions(${PROJECT_NAME} PUBLIC ${TARGET_COMPILE_DEFINITIONS})
target_compile_options(${PROJECT_NAME} PRIVATE ${TARGET_COMPILE_OPTIONS})
set_property(TARGET ${PROJECT_NAME} APPEND_STRING PROPERTY LINK_FLAGS ${TARGET_LINK_FLAGS})

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/cmake/Version.hpp.in ${CMAKE_CURRENT_BINARY_DIR}/include/${PROJECT_NAME}/Version.hpp)

target_include_directories(${PROJECT_NAME} PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}/include>
  $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
)

target_link_libraries(${PROJECT_NAME} PUBLIC
  ad_map_access
)

install(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/include/
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
