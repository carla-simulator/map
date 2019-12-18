# ----------------- BEGIN LICENSE BLOCK ---------------------------------
#
# Copyright (C) 2018-2019 Intel Corporation
#
# SPDX-License-Identifier: MIT
#
# ----------------- END LICENSE BLOCK -----------------------------------

#####################################################################
# MapMaker - geometry - library
#####################################################################

find_library(LAPACK_LIB NAMES lapacke PATHS /usr/lib DOC "Dynamic lapack library (lapacke)")
if (NOT LAPACK_LIB)
  message(FATAL_ERROR "Unable to find lapacke. Maybe you need to install liblapacke-dev and libopenblas-dev. Set LAPACK_LIB.")
endif()

add_library(ad_map_maker_geometry STATIC
  src/CoordinateTransform.cpp
  src/Point2d.cpp
  src/Polyline2d.cpp
  src/Line2d.cpp
  src/Direction2d.cpp
  src/CubicSpline.cpp
  src/Circle.cpp
  src/Point.cpp # only temporary
  src/ArithmeticHelpers.cpp # only temporary
  src/QuadraticBezier.cpp
  src/CubicBezier.cpp
  src/LineCoordinateSystem.cpp
  src/Clothoid.cpp
)

target_include_directories(ad_map_maker_geometry
  PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  PRIVATE
  ${OSMIUM_INCLUDE_DIRS}
  ${PROJECT_BINARY_DIR}/include
)

target_link_libraries(ad_map_maker_geometry
  PUBLIC
  mapmaker::common
  ${LAPACK_LIB}
)

add_library(${PROJECT_NAMESPACE}geometry ALIAS ad_map_maker_geometry)

#####################################################################
# Geometry - tests
#####################################################################

if(BUILD_TESTING)
endif()
