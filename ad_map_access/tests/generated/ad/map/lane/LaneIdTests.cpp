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
#include "ad/map/lane/LaneId.hpp"

TEST(LaneIdTests, minIsValid)
{
  EXPECT_TRUE(::ad::map::lane::LaneId::getMin().isValid());
}

TEST(LaneIdTests, aboveMinIsValid)
{
  ::ad::map::lane::LaneId value(::ad::map::lane::LaneId::cMinValue + 1);
  EXPECT_TRUE(value.isValid());
}

TEST(LaneIdTests, maxIsValid)
{
  EXPECT_TRUE(::ad::map::lane::LaneId::getMax().isValid());
}

TEST(LaneIdTests, belowMaxIsValid)
{
  ::ad::map::lane::LaneId value(::ad::map::lane::LaneId::cMaxValue - 1);
  EXPECT_TRUE(value.isValid());
}

#if (AD_MAP_LANE_LANEID_THROWS_EXCEPTION == 1)
TEST(LaneIdTests, ensureValidNonZeroThrowsOnInvalid)
{
  ::ad::map::lane::LaneId value;
  EXPECT_THROW(value.ensureValidNonZero(), std::out_of_range);
}

TEST(LaneIdTests, ensureValidNonZeroThrowsOnZero)
{
  ::ad::map::lane::LaneId value(0.);
  EXPECT_THROW(value.ensureValidNonZero(), std::out_of_range);
}
#endif

TEST(LaneIdTestsStd, numericLimitsLowestIsMin)
{
  EXPECT_EQ(::ad::map::lane::LaneId::getMin().mLaneId, std::numeric_limits<::ad::map::lane::LaneId>::lowest().mLaneId);
}

TEST(LaneIdTestsStd, numericLimitsMaxIsMax)
{
  EXPECT_EQ(::ad::map::lane::LaneId::getMax().mLaneId, std::numeric_limits<::ad::map::lane::LaneId>::max().mLaneId);
}

TEST(LaneIdTests, copyConstructionFromValidValue)
{
  ::ad::map::lane::LaneId const validValue(::ad::map::lane::LaneId::cMinValue);
  ::ad::map::lane::LaneId value(validValue);
  EXPECT_TRUE(value.isValid());
  EXPECT_EQ(validValue.mLaneId, value.mLaneId);
}

TEST(LaneIdTests, moveConstructionFromValidValue)
{
  ::ad::map::lane::LaneId validValue(::ad::map::lane::LaneId::cMinValue);
  ::ad::map::lane::LaneId value(std::move(validValue));
  EXPECT_TRUE(value.isValid());
  EXPECT_EQ(::ad::map::lane::LaneId::cMinValue, value.mLaneId);
}

TEST(LaneIdTests, assignmentFromValidValue)
{
  ::ad::map::lane::LaneId const validValue(::ad::map::lane::LaneId::cMinValue);
  ::ad::map::lane::LaneId value;
  value = validValue;
  EXPECT_TRUE(value.isValid());
  EXPECT_EQ(validValue.mLaneId, value.mLaneId);
}

TEST(LaneIdTests, moveAssignmentFromValidValue)
{
  ::ad::map::lane::LaneId validValue(::ad::map::lane::LaneId::cMinValue);
  ::ad::map::lane::LaneId value;
  value = std::move(validValue);
  EXPECT_TRUE(value.isValid());
  EXPECT_EQ(::ad::map::lane::LaneId::cMinValue, value.mLaneId);
}

TEST(LaneIdTests, selfAssignment)
{
  ::ad::map::lane::LaneId value(::ad::map::lane::LaneId::cMinValue);
  EXPECT_TRUE(value.isValid());
  value = value;
  EXPECT_TRUE(value.isValid());
}

TEST(LaneIdTests, ostreamOperatorTest)
{
  std::stringstream stream;
  ::ad::map::lane::LaneId value;
  stream << value;
  ASSERT_GT(stream.str().size(), 0u);
}

TEST(LaneIdTests, comparisonOperators)
{
  ::ad::map::lane::LaneId minValue(::ad::map::lane::LaneId::cMinValue);
  ::ad::map::lane::LaneId maxValue(::ad::map::lane::LaneId::cMaxValue);

  ASSERT_TRUE(minValue == minValue);
  ASSERT_TRUE(minValue != maxValue);
  ASSERT_TRUE(minValue < maxValue);
  ASSERT_TRUE(minValue <= minValue);
  ASSERT_TRUE(maxValue > minValue);
  ASSERT_TRUE(maxValue >= minValue);
}

TEST(LaneIdTests, arithmeticOperators)
{
  ::ad::map::lane::LaneId minValue(::ad::map::lane::LaneId::cMinValue);
  ::ad::map::lane::LaneId maxValue(::ad::map::lane::LaneId::cMaxValue);
  ::ad::map::lane::LaneId result;

  ASSERT_EQ((minValue + minValue).mLaneId, ::ad::map::lane::LaneId::cMinValue + ::ad::map::lane::LaneId::cMinValue);
  result = minValue;
  result += minValue;
  ASSERT_EQ(result.mLaneId, ::ad::map::lane::LaneId::cMinValue + ::ad::map::lane::LaneId::cMinValue);
  ASSERT_EQ((maxValue - minValue).mLaneId, ::ad::map::lane::LaneId::cMaxValue - ::ad::map::lane::LaneId::cMinValue);
  result = maxValue;
  result -= minValue;
  ASSERT_EQ(result.mLaneId, ::ad::map::lane::LaneId::cMaxValue - ::ad::map::lane::LaneId::cMinValue);
}

#if defined(__clang__) && (__clang_major__ >= 7)
#pragma GCC diagnostic pop
#endif
