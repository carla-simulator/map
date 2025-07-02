# ----------------- BEGIN LICENSE BLOCK ---------------------------------
#
# Copyright (C) 2018-2021 Intel Corporation
#
# SPDX-License-Identifier: MIT
#
# ----------------- END LICENSE BLOCK -----------------------------------

set(EXEC_NAME ad_map_access_tests)

file(GLOB_RECURSE GENERATED_TEST_SOURCES "${CMAKE_CURRENT_LIST_DIR}/generated/*.cpp")

set(TEST_SOURCES_WITH_PRIVATE_ACCESS
  intersection/SyntheticIntersectionTestBase.cpp
  match/AdMapMatchingTests.cpp
)

set(TEST_SOURCES
  access/AdMapAccessTests.cpp
  access/FactoryTests.cpp
  access/GeometryStoreTests.cpp
  config/MapConfigFileHandlerTests.cpp
  geometry/PolygonOperationTests.cpp
  intersection/MapSetup.cpp
  intersection/MapSetupTests.cpp
  intersection/SyntheticIntersectionTestBase.cpp
  intersection/IntersectionTests.cpp
  intersection/IntersectionPriorityToRightLefthandTests.cpp
  intersection/IntersectionPriorityToRightSingaporeTests.cpp
  intersection/IntersectionPriorityToRightTests.cpp
  intersection/IntersectionYieldLefthandTests.cpp
  intersection/IntersectionYieldTests.cpp
  intersection/IntersectionBasicTrafficLightTest.cpp
  intersection/IntersectionTrafficLightTests.cpp
  intersection/IntersectionTpkPFZYieldTest.cpp
  intersection/IntersectionTpkPFZPriorityToRightTest.cpp
  intersection/IntersectionTpkPFZTrafficLightTest.cpp
  landmark/KnownTrafficSigns.cpp
  landmark/LandmarkOperationTests.cpp
  landmark/TrafficLightTests.cpp
  landmark/TrafficSignTests.cpp
  lane/LaneOperationTests.cpp
  match/AdMapBoundingBoxMapMatchingTest.cpp
  opendrive/OpenDriveAccessTests.cpp
  point/CoordinateTransformTests.cpp
  point/GeometryOperationTests.cpp
  point/GeoOperationTests.cpp
  point/PointOperationTests.cpp
  route/RoutePlanningTests.cpp
  route/RoutePredictionTest.cpp
  route/LaneChangeTests.cpp
  route/LaneIntervalOperationTest.cpp
  serialize/SerializationTests.cpp
  ${TEST_SOURCES_WITH_PRIVATE_ACCESS}
  main.cpp
  ${GENERATED_TEST_SOURCES}
)
set_source_files_properties(${TEST_SOURCES_WITH_PRIVATE_ACCESS} PROPERITES COMPILE_FLAGS -fno-access-control)

add_executable(${EXEC_NAME} ${TEST_SOURCES})

target_link_libraries(${EXEC_NAME}
  ad_map_access
  ad_map_access_test_support
  GTest::gtest
  )

add_test(NAME ${EXEC_NAME} COMMAND ${EXEC_NAME} WORKING_DIRECTORY ${CMAKE_CURRENT_LIST_DIR})

target_compile_options(${EXEC_NAME} PRIVATE ${TARGET_COMPILE_OPTIONS})
set_property(TARGET ${EXEC_NAME} APPEND_STRING PROPERTY LINK_FLAGS ${TARGET_LINK_FLAGS})
