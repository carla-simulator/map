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
#include "ad/map/route/LaneInterval.hpp"

class LaneIntervalTests : public testing::Test
{
protected:
  virtual void SetUp() override
  {
    // valid initialization
    ::ad::map::route::LaneInterval value;
    ::ad::map::lane::LaneId valueLane_id(1);
    value.lane_id = valueLane_id;
    ::ad::physics::ParametricValue valueStart(0.);
    value.start = valueStart;
    ::ad::physics::ParametricValue valueEnd(0.);
    value.end = valueEnd;
    bool valueWrong_way{true};
    value.wrong_way = valueWrong_way;
    mValue = value;
  }

  ::ad::map::route::LaneInterval mValue;
};

TEST_F(LaneIntervalTests, copyConstruction)
{
  ::ad::map::route::LaneInterval value(mValue);
  EXPECT_EQ(mValue, value);
}

TEST_F(LaneIntervalTests, moveConstruction)
{
  ::ad::map::route::LaneInterval tmpValue(mValue);
  ::ad::map::route::LaneInterval value(std::move(tmpValue));
  EXPECT_EQ(mValue, value);
}

TEST_F(LaneIntervalTests, copyAssignment)
{
  ::ad::map::route::LaneInterval value;
  value = mValue;
  EXPECT_EQ(mValue, value);
}

TEST_F(LaneIntervalTests, moveAssignment)
{
  ::ad::map::route::LaneInterval tmpValue(mValue);
  ::ad::map::route::LaneInterval value;
  value = std::move(tmpValue);
  EXPECT_EQ(mValue, value);
}

TEST_F(LaneIntervalTests, comparisonOperatorEqual)
{
  ::ad::map::route::LaneInterval valueA = mValue;
  ::ad::map::route::LaneInterval valueB = mValue;

  EXPECT_TRUE(valueA == valueB);
  EXPECT_FALSE(valueA != valueB);
}

TEST_F(LaneIntervalTests, stringConversionTest)
{
  std::stringstream stream;
  stream << mValue;
  std::string ostreamStr = stream.str();
  std::string toStr = std::to_string(mValue);
  ASSERT_EQ(ostreamStr, toStr);
}

TEST_F(LaneIntervalTests, comparisonOperatorLane_idDiffers)
{
  ::ad::map::route::LaneInterval valueA = mValue;
  ::ad::map::lane::LaneId lane_id(std::numeric_limits<::ad::map::lane::LaneId>::max());
  valueA.lane_id = lane_id;
  ::ad::map::route::LaneInterval valueB = mValue;

  EXPECT_FALSE(valueA == valueB);
  EXPECT_TRUE(valueA != valueB);
}

TEST_F(LaneIntervalTests, comparisonOperatorStartDiffers)
{
  ::ad::map::route::LaneInterval valueA = mValue;
  ::ad::physics::ParametricValue start(1.);
  valueA.start = start;
  ::ad::map::route::LaneInterval valueB = mValue;

  EXPECT_FALSE(valueA == valueB);
  EXPECT_TRUE(valueA != valueB);
}

TEST_F(LaneIntervalTests, comparisonOperatorEndDiffers)
{
  ::ad::map::route::LaneInterval valueA = mValue;
  ::ad::physics::ParametricValue end(1.);
  valueA.end = end;
  ::ad::map::route::LaneInterval valueB = mValue;

  EXPECT_FALSE(valueA == valueB);
  EXPECT_TRUE(valueA != valueB);
}

TEST_F(LaneIntervalTests, comparisonOperatorWrong_wayDiffers)
{
  ::ad::map::route::LaneInterval valueA = mValue;
  bool wrong_way{false};
  valueA.wrong_way = wrong_way;
  ::ad::map::route::LaneInterval valueB = mValue;

  EXPECT_FALSE(valueA == valueB);
  EXPECT_TRUE(valueA != valueB);
}

#if defined(__clang__) && (__clang_major__ >= 7)
#pragma GCC diagnostic pop
#endif
