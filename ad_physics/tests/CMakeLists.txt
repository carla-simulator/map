# ----------------- BEGIN LICENSE BLOCK ---------------------------------
#
# Copyright (C) 2019-2021 Intel Corporation
#
# SPDX-License-Identifier: MIT
#
# ----------------- END LICENSE BLOCK -----------------------------------

#####################################################################
# ad-physics-tests - executable setup
#####################################################################

set(EXEC_NAME ad-physics-tests)

file(GLOB_RECURSE GENERATED_TEST_SOURCES "${CMAKE_CURRENT_LIST_DIR}/generated/*.cpp")

set(TEST_SOURCES
  main.cpp
  AngleTests.cpp
  GeometryOperationTest.cpp
  ${GENERATED_TEST_SOURCES}
)

add_executable(${EXEC_NAME} ${TEST_SOURCES})

target_link_libraries(${EXEC_NAME}
  ad_physics
  GTest::gtest
  )

add_test(NAME ${EXEC_NAME} COMMAND ${EXEC_NAME} WORKING_DIRECTORY ${CMAKE_CURRENT_LIST_DIR})

target_compile_options(${EXEC_NAME} PRIVATE ${TARGET_COMPILE_OPTIONS})
set_property(TARGET ${EXEC_NAME} APPEND_STRING PROPERTY LINK_FLAGS ${TARGET_LINK_FLAGS})
