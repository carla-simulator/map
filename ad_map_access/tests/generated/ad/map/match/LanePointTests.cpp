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
#include "ad/map/match/LanePoint.hpp"

class LanePointTests : public testing::Test
{
protected:
  virtual void SetUp() override
  {
    // valid initialization
    ::ad::map::match::LanePoint value;
    ::ad::map::point::ParaPoint valuePara_point;
    ::ad::map::lane::LaneId valuePara_pointLane_id(1);
    valuePara_point.lane_id = valuePara_pointLane_id;
    ::ad::physics::ParametricValue valuePara_pointParametric_offset(0.);
    valuePara_point.parametric_offset = valuePara_pointParametric_offset;
    value.para_point = valuePara_point;
    ::ad::physics::RatioValue valueLateral_t(std::numeric_limits<::ad::physics::RatioValue>::lowest());
    value.lateral_t = valueLateral_t;
    ::ad::physics::Distance valueLane_length(-1e9);
    value.lane_length = valueLane_length;
    ::ad::physics::Distance valueLane_width(-1e9);
    value.lane_width = valueLane_width;
    mValue = value;
  }

  ::ad::map::match::LanePoint mValue;
};

TEST_F(LanePointTests, copyConstruction)
{
  ::ad::map::match::LanePoint value(mValue);
  EXPECT_EQ(mValue, value);
}

TEST_F(LanePointTests, moveConstruction)
{
  ::ad::map::match::LanePoint tmpValue(mValue);
  ::ad::map::match::LanePoint value(std::move(tmpValue));
  EXPECT_EQ(mValue, value);
}

TEST_F(LanePointTests, copyAssignment)
{
  ::ad::map::match::LanePoint value;
  value = mValue;
  EXPECT_EQ(mValue, value);
}

TEST_F(LanePointTests, moveAssignment)
{
  ::ad::map::match::LanePoint tmpValue(mValue);
  ::ad::map::match::LanePoint value;
  value = std::move(tmpValue);
  EXPECT_EQ(mValue, value);
}

TEST_F(LanePointTests, comparisonOperatorEqual)
{
  ::ad::map::match::LanePoint valueA = mValue;
  ::ad::map::match::LanePoint valueB = mValue;

  EXPECT_TRUE(valueA == valueB);
  EXPECT_FALSE(valueA != valueB);
}

TEST_F(LanePointTests, stringConversionTest)
{
  std::stringstream stream;
  stream << mValue;
  std::string ostreamStr = stream.str();
  std::string toStr = std::to_string(mValue);
  ASSERT_EQ(ostreamStr, toStr);
}

TEST_F(LanePointTests, comparisonOperatorPara_pointDiffers)
{
  ::ad::map::match::LanePoint valueA = mValue;
  ::ad::map::point::ParaPoint para_point;
  ::ad::map::lane::LaneId para_pointLane_id(std::numeric_limits<::ad::map::lane::LaneId>::max());
  para_point.lane_id = para_pointLane_id;
  ::ad::physics::ParametricValue para_pointParametric_offset(1.);
  para_point.parametric_offset = para_pointParametric_offset;
  valueA.para_point = para_point;
  ::ad::map::match::LanePoint valueB = mValue;

  EXPECT_FALSE(valueA == valueB);
  EXPECT_TRUE(valueA != valueB);
}

TEST_F(LanePointTests, comparisonOperatorLateral_tDiffers)
{
  ::ad::map::match::LanePoint valueA = mValue;
  ::ad::physics::RatioValue lateral_t(std::numeric_limits<::ad::physics::RatioValue>::max());
  valueA.lateral_t = lateral_t;
  ::ad::map::match::LanePoint valueB = mValue;

  EXPECT_FALSE(valueA == valueB);
  EXPECT_TRUE(valueA != valueB);
}

TEST_F(LanePointTests, comparisonOperatorLane_lengthDiffers)
{
  ::ad::map::match::LanePoint valueA = mValue;
  ::ad::physics::Distance lane_length(1e9);
  valueA.lane_length = lane_length;
  ::ad::map::match::LanePoint valueB = mValue;

  EXPECT_FALSE(valueA == valueB);
  EXPECT_TRUE(valueA != valueB);
}

TEST_F(LanePointTests, comparisonOperatorLane_widthDiffers)
{
  ::ad::map::match::LanePoint valueA = mValue;
  ::ad::physics::Distance lane_width(1e9);
  valueA.lane_width = lane_width;
  ::ad::map::match::LanePoint valueB = mValue;

  EXPECT_FALSE(valueA == valueB);
  EXPECT_TRUE(valueA != valueB);
}

#if defined(__clang__) && (__clang_major__ >= 7)
#pragma GCC diagnostic pop
#endif
