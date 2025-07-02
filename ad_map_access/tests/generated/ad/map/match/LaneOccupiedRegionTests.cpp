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
#include "ad/map/match/LaneOccupiedRegion.hpp"

class LaneOccupiedRegionTests : public testing::Test
{
protected:
  virtual void SetUp() override
  {
    // valid initialization
    ::ad::map::match::LaneOccupiedRegion value;
    ::ad::map::lane::LaneId valueLane_id(1);
    value.lane_id = valueLane_id;
    ::ad::physics::ParametricRange valueLongitudinal_range;
    ::ad::physics::ParametricValue valueLongitudinal_rangeMinimum(0.);
    valueLongitudinal_range.minimum = valueLongitudinal_rangeMinimum;
    ::ad::physics::ParametricValue valueLongitudinal_rangeMaximum(0.);
    valueLongitudinal_range.maximum = valueLongitudinal_rangeMaximum;
    valueLongitudinal_range.maximum = valueLongitudinal_range.minimum;
    valueLongitudinal_range.minimum = valueLongitudinal_range.maximum;
    value.longitudinal_range = valueLongitudinal_range;
    ::ad::physics::ParametricRange valueLateral_range;
    ::ad::physics::ParametricValue valueLateral_rangeMinimum(0.);
    valueLateral_range.minimum = valueLateral_rangeMinimum;
    ::ad::physics::ParametricValue valueLateral_rangeMaximum(0.);
    valueLateral_range.maximum = valueLateral_rangeMaximum;
    valueLateral_range.maximum = valueLateral_range.minimum;
    valueLateral_range.minimum = valueLateral_range.maximum;
    value.lateral_range = valueLateral_range;
    mValue = value;
  }

  ::ad::map::match::LaneOccupiedRegion mValue;
};

TEST_F(LaneOccupiedRegionTests, copyConstruction)
{
  ::ad::map::match::LaneOccupiedRegion value(mValue);
  EXPECT_EQ(mValue, value);
}

TEST_F(LaneOccupiedRegionTests, moveConstruction)
{
  ::ad::map::match::LaneOccupiedRegion tmpValue(mValue);
  ::ad::map::match::LaneOccupiedRegion value(std::move(tmpValue));
  EXPECT_EQ(mValue, value);
}

TEST_F(LaneOccupiedRegionTests, copyAssignment)
{
  ::ad::map::match::LaneOccupiedRegion value;
  value = mValue;
  EXPECT_EQ(mValue, value);
}

TEST_F(LaneOccupiedRegionTests, moveAssignment)
{
  ::ad::map::match::LaneOccupiedRegion tmpValue(mValue);
  ::ad::map::match::LaneOccupiedRegion value;
  value = std::move(tmpValue);
  EXPECT_EQ(mValue, value);
}

TEST_F(LaneOccupiedRegionTests, comparisonOperatorEqual)
{
  ::ad::map::match::LaneOccupiedRegion valueA = mValue;
  ::ad::map::match::LaneOccupiedRegion valueB = mValue;

  EXPECT_TRUE(valueA == valueB);
  EXPECT_FALSE(valueA != valueB);
}

TEST_F(LaneOccupiedRegionTests, stringConversionTest)
{
  std::stringstream stream;
  stream << mValue;
  std::string ostreamStr = stream.str();
  std::string toStr = std::to_string(mValue);
  ASSERT_EQ(ostreamStr, toStr);
}

TEST_F(LaneOccupiedRegionTests, comparisonOperatorLane_idDiffers)
{
  ::ad::map::match::LaneOccupiedRegion valueA = mValue;
  ::ad::map::lane::LaneId lane_id(std::numeric_limits<::ad::map::lane::LaneId>::max());
  valueA.lane_id = lane_id;
  ::ad::map::match::LaneOccupiedRegion valueB = mValue;

  EXPECT_FALSE(valueA == valueB);
  EXPECT_TRUE(valueA != valueB);
}

TEST_F(LaneOccupiedRegionTests, comparisonOperatorLongitudinal_rangeDiffers)
{
  ::ad::map::match::LaneOccupiedRegion valueA = mValue;
  ::ad::physics::ParametricRange longitudinal_range;
  ::ad::physics::ParametricValue longitudinal_rangeMinimum(1.);
  longitudinal_range.minimum = longitudinal_rangeMinimum;
  ::ad::physics::ParametricValue longitudinal_rangeMaximum(1.);
  longitudinal_range.maximum = longitudinal_rangeMaximum;
  longitudinal_range.maximum = longitudinal_range.minimum;
  longitudinal_range.minimum = longitudinal_range.maximum;
  valueA.longitudinal_range = longitudinal_range;
  ::ad::map::match::LaneOccupiedRegion valueB = mValue;

  EXPECT_FALSE(valueA == valueB);
  EXPECT_TRUE(valueA != valueB);
}

TEST_F(LaneOccupiedRegionTests, comparisonOperatorLateral_rangeDiffers)
{
  ::ad::map::match::LaneOccupiedRegion valueA = mValue;
  ::ad::physics::ParametricRange lateral_range;
  ::ad::physics::ParametricValue lateral_rangeMinimum(1.);
  lateral_range.minimum = lateral_rangeMinimum;
  ::ad::physics::ParametricValue lateral_rangeMaximum(1.);
  lateral_range.maximum = lateral_rangeMaximum;
  lateral_range.maximum = lateral_range.minimum;
  lateral_range.minimum = lateral_range.maximum;
  valueA.lateral_range = lateral_range;
  ::ad::map::match::LaneOccupiedRegion valueB = mValue;

  EXPECT_FALSE(valueA == valueB);
  EXPECT_TRUE(valueA != valueB);
}

#if defined(__clang__) && (__clang_major__ >= 7)
#pragma GCC diagnostic pop
#endif
