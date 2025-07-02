/*
 * ----------------- BEGIN LICENSE BLOCK ---------------------------------
 *
 * Copyright (C) 2018-2022 Intel Corporation
 *
 * SPDX-License-Identifier: MIT
 *
 * ----------------- END LICENSE BLOCK -----------------------------------
 */

/*
 * Generated file
 */

#if defined(__clang__) && (__clang_major__ >= 7)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wself-assign-overloaded"
#endif

#include <gtest/gtest.h>
#include <limits>
#include "ad/map/config/MapEntry.hpp"

class MapEntryTests : public testing::Test
{
protected:
  virtual void SetUp() override
  {
    // valid initialization
    ::ad::map::config::MapEntry value;
    std::string valueFilename{"min"};
    value.filename = valueFilename;
    ::ad::physics::Distance valueOpen_drive_overlap_margin(-1e9);
    value.open_drive_overlap_margin = valueOpen_drive_overlap_margin;
    ::ad::map::intersection::IntersectionType valueOpen_drive_default_intersection_type(
      ::ad::map::intersection::IntersectionType::Unknown);
    value.open_drive_default_intersection_type = valueOpen_drive_default_intersection_type;
    ::ad::map::landmark::TrafficLightType valueOpen_drive_default_traffic_light_type(
      ::ad::map::landmark::TrafficLightType::INVALID);
    value.open_drive_default_traffic_light_type = valueOpen_drive_default_traffic_light_type;
    mValue = value;
  }

  ::ad::map::config::MapEntry mValue;
};

TEST_F(MapEntryTests, copyConstruction)
{
  ::ad::map::config::MapEntry value(mValue);
  EXPECT_EQ(mValue, value);
}

TEST_F(MapEntryTests, moveConstruction)
{
  ::ad::map::config::MapEntry tmpValue(mValue);
  ::ad::map::config::MapEntry value(std::move(tmpValue));
  EXPECT_EQ(mValue, value);
}

TEST_F(MapEntryTests, copyAssignment)
{
  ::ad::map::config::MapEntry value;
  value = mValue;
  EXPECT_EQ(mValue, value);
}

TEST_F(MapEntryTests, moveAssignment)
{
  ::ad::map::config::MapEntry tmpValue(mValue);
  ::ad::map::config::MapEntry value;
  value = std::move(tmpValue);
  EXPECT_EQ(mValue, value);
}

TEST_F(MapEntryTests, comparisonOperatorEqual)
{
  ::ad::map::config::MapEntry valueA = mValue;
  ::ad::map::config::MapEntry valueB = mValue;

  EXPECT_TRUE(valueA == valueB);
  EXPECT_FALSE(valueA != valueB);
}

TEST_F(MapEntryTests, stringConversionTest)
{
  std::stringstream stream;
  stream << mValue;
  std::string ostreamStr = stream.str();
  std::string toStr = std::to_string(mValue);
  ASSERT_EQ(ostreamStr, toStr);
}

TEST_F(MapEntryTests, comparisonOperatorFilenameDiffers)
{
  ::ad::map::config::MapEntry valueA = mValue;
  std::string filename{"max"};
  valueA.filename = filename;
  ::ad::map::config::MapEntry valueB = mValue;

  EXPECT_FALSE(valueA == valueB);
  EXPECT_TRUE(valueA != valueB);
}

TEST_F(MapEntryTests, comparisonOperatorOpen_drive_overlap_marginDiffers)
{
  ::ad::map::config::MapEntry valueA = mValue;
  ::ad::physics::Distance open_drive_overlap_margin(1e9);
  valueA.open_drive_overlap_margin = open_drive_overlap_margin;
  ::ad::map::config::MapEntry valueB = mValue;

  EXPECT_FALSE(valueA == valueB);
  EXPECT_TRUE(valueA != valueB);
}

TEST_F(MapEntryTests, comparisonOperatorOpen_drive_default_intersection_typeDiffers)
{
  ::ad::map::config::MapEntry valueA = mValue;
  ::ad::map::intersection::IntersectionType open_drive_default_intersection_type(
    ::ad::map::intersection::IntersectionType::TrafficLight);
  valueA.open_drive_default_intersection_type = open_drive_default_intersection_type;
  ::ad::map::config::MapEntry valueB = mValue;

  EXPECT_FALSE(valueA == valueB);
  EXPECT_TRUE(valueA != valueB);
}

TEST_F(MapEntryTests, comparisonOperatorOpen_drive_default_traffic_light_typeDiffers)
{
  ::ad::map::config::MapEntry valueA = mValue;
  ::ad::map::landmark::TrafficLightType open_drive_default_traffic_light_type(
    ::ad::map::landmark::TrafficLightType::BIKE_PEDESTRIAN_RED_YELLOW_GREEN);
  valueA.open_drive_default_traffic_light_type = open_drive_default_traffic_light_type;
  ::ad::map::config::MapEntry valueB = mValue;

  EXPECT_FALSE(valueA == valueB);
  EXPECT_TRUE(valueA != valueB);
}

#if defined(__clang__) && (__clang_major__ >= 7)
#pragma GCC diagnostic pop
#endif
