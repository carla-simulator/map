# ----------------- BEGIN LICENSE BLOCK ---------------------------------
#
# Copyright (C) 2017-2019 Intel Corporation
#
# SPDX-License-Identifier: MIT
#
# ----------------- END LICENSE BLOCK -----------------------------------

#####################################################################
# MapMaker - test_helper - library
#####################################################################

add_library(test_helper
  src/StringTestHelper.cpp
)

target_include_directories(test_helper
  PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  PRIVATE
  ${PROJECT_BINARY_DIR}/include
)

target_link_libraries(test_helper PRIVATE
  GTest::gtest
)

add_library(${PROJECT_NAMESPACE}test_helper ALIAS test_helper)
