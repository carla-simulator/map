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
#include "ad/map/restriction/SpeedLimit.hpp"

class SpeedLimitTests : public testing::Test
{
protected:
  virtual void SetUp() override
  {
    // valid initialization
    ::ad::map::restriction::SpeedLimit value;
    ::ad::physics::Speed valueSpeed_limit(-100.);
    value.speed_limit = valueSpeed_limit;
    ::ad::physics::ParametricRange valueLane_piece;
    ::ad::physics::ParametricValue valueLane_pieceMinimum(0.);
    valueLane_piece.minimum = valueLane_pieceMinimum;
    ::ad::physics::ParametricValue valueLane_pieceMaximum(0.);
    valueLane_piece.maximum = valueLane_pieceMaximum;
    valueLane_piece.maximum = valueLane_piece.minimum;
    valueLane_piece.minimum = valueLane_piece.maximum;
    value.lane_piece = valueLane_piece;
    mValue = value;
  }

  ::ad::map::restriction::SpeedLimit mValue;
};

TEST_F(SpeedLimitTests, copyConstruction)
{
  ::ad::map::restriction::SpeedLimit value(mValue);
  EXPECT_EQ(mValue, value);
}

TEST_F(SpeedLimitTests, moveConstruction)
{
  ::ad::map::restriction::SpeedLimit tmpValue(mValue);
  ::ad::map::restriction::SpeedLimit value(std::move(tmpValue));
  EXPECT_EQ(mValue, value);
}

TEST_F(SpeedLimitTests, copyAssignment)
{
  ::ad::map::restriction::SpeedLimit value;
  value = mValue;
  EXPECT_EQ(mValue, value);
}

TEST_F(SpeedLimitTests, moveAssignment)
{
  ::ad::map::restriction::SpeedLimit tmpValue(mValue);
  ::ad::map::restriction::SpeedLimit value;
  value = std::move(tmpValue);
  EXPECT_EQ(mValue, value);
}

TEST_F(SpeedLimitTests, comparisonOperatorEqual)
{
  ::ad::map::restriction::SpeedLimit valueA = mValue;
  ::ad::map::restriction::SpeedLimit valueB = mValue;

  EXPECT_TRUE(valueA == valueB);
  EXPECT_FALSE(valueA != valueB);
}

TEST_F(SpeedLimitTests, stringConversionTest)
{
  std::stringstream stream;
  stream << mValue;
  std::string ostreamStr = stream.str();
  std::string toStr = std::to_string(mValue);
  ASSERT_EQ(ostreamStr, toStr);
}

TEST_F(SpeedLimitTests, comparisonOperatorSpeed_limitDiffers)
{
  ::ad::map::restriction::SpeedLimit valueA = mValue;
  ::ad::physics::Speed speed_limit(100.);
  valueA.speed_limit = speed_limit;
  ::ad::map::restriction::SpeedLimit valueB = mValue;

  EXPECT_FALSE(valueA == valueB);
  EXPECT_TRUE(valueA != valueB);
}

TEST_F(SpeedLimitTests, comparisonOperatorLane_pieceDiffers)
{
  ::ad::map::restriction::SpeedLimit valueA = mValue;
  ::ad::physics::ParametricRange lane_piece;
  ::ad::physics::ParametricValue lane_pieceMinimum(1.);
  lane_piece.minimum = lane_pieceMinimum;
  ::ad::physics::ParametricValue lane_pieceMaximum(1.);
  lane_piece.maximum = lane_pieceMaximum;
  lane_piece.maximum = lane_piece.minimum;
  lane_piece.minimum = lane_piece.maximum;
  valueA.lane_piece = lane_piece;
  ::ad::map::restriction::SpeedLimit valueB = mValue;

  EXPECT_FALSE(valueA == valueB);
  EXPECT_TRUE(valueA != valueB);
}

#if defined(__clang__) && (__clang_major__ >= 7)
#pragma GCC diagnostic pop
#endif
