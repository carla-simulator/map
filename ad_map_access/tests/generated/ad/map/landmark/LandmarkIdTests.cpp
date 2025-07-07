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
#include "ad/map/landmark/LandmarkId.hpp"

TEST(LandmarkIdTests, minIsValid)
{
  EXPECT_TRUE(::ad::map::landmark::LandmarkId::getMin().isValid());
}

TEST(LandmarkIdTests, aboveMinIsValid)
{
  ::ad::map::landmark::LandmarkId value(::ad::map::landmark::LandmarkId::cMinValue + 1);
  EXPECT_TRUE(value.isValid());
}

TEST(LandmarkIdTests, maxIsValid)
{
  EXPECT_TRUE(::ad::map::landmark::LandmarkId::getMax().isValid());
}

TEST(LandmarkIdTests, belowMaxIsValid)
{
  ::ad::map::landmark::LandmarkId value(::ad::map::landmark::LandmarkId::cMaxValue - 1);
  EXPECT_TRUE(value.isValid());
}

#if (AD_MAP_LANDMARK_LANDMARKID_THROWS_EXCEPTION == 1)
TEST(LandmarkIdTests, ensureValidNonZeroThrowsOnInvalid)
{
  ::ad::map::landmark::LandmarkId value;
  EXPECT_THROW(value.ensureValidNonZero(), std::out_of_range);
}

TEST(LandmarkIdTests, ensureValidNonZeroThrowsOnZero)
{
  ::ad::map::landmark::LandmarkId value(0.);
  EXPECT_THROW(value.ensureValidNonZero(), std::out_of_range);
}
#endif

TEST(LandmarkIdTestsStd, numericLimitsLowestIsMin)
{
  EXPECT_EQ(::ad::map::landmark::LandmarkId::getMin().mLandmarkId,
            std::numeric_limits<::ad::map::landmark::LandmarkId>::lowest().mLandmarkId);
}

TEST(LandmarkIdTestsStd, numericLimitsMaxIsMax)
{
  EXPECT_EQ(::ad::map::landmark::LandmarkId::getMax().mLandmarkId,
            std::numeric_limits<::ad::map::landmark::LandmarkId>::max().mLandmarkId);
}

TEST(LandmarkIdTests, copyConstructionFromValidValue)
{
  ::ad::map::landmark::LandmarkId const validValue(::ad::map::landmark::LandmarkId::cMinValue);
  ::ad::map::landmark::LandmarkId value(validValue);
  EXPECT_TRUE(value.isValid());
  EXPECT_EQ(validValue.mLandmarkId, value.mLandmarkId);
}

TEST(LandmarkIdTests, moveConstructionFromValidValue)
{
  ::ad::map::landmark::LandmarkId validValue(::ad::map::landmark::LandmarkId::cMinValue);
  ::ad::map::landmark::LandmarkId value(std::move(validValue));
  EXPECT_TRUE(value.isValid());
  EXPECT_EQ(::ad::map::landmark::LandmarkId::cMinValue, value.mLandmarkId);
}

TEST(LandmarkIdTests, assignmentFromValidValue)
{
  ::ad::map::landmark::LandmarkId const validValue(::ad::map::landmark::LandmarkId::cMinValue);
  ::ad::map::landmark::LandmarkId value;
  value = validValue;
  EXPECT_TRUE(value.isValid());
  EXPECT_EQ(validValue.mLandmarkId, value.mLandmarkId);
}

TEST(LandmarkIdTests, moveAssignmentFromValidValue)
{
  ::ad::map::landmark::LandmarkId validValue(::ad::map::landmark::LandmarkId::cMinValue);
  ::ad::map::landmark::LandmarkId value;
  value = std::move(validValue);
  EXPECT_TRUE(value.isValid());
  EXPECT_EQ(::ad::map::landmark::LandmarkId::cMinValue, value.mLandmarkId);
}

TEST(LandmarkIdTests, selfAssignment)
{
  ::ad::map::landmark::LandmarkId value(::ad::map::landmark::LandmarkId::cMinValue);
  EXPECT_TRUE(value.isValid());
  value = value;
  EXPECT_TRUE(value.isValid());
}

TEST(LandmarkIdTests, ostreamOperatorTest)
{
  std::stringstream stream;
  ::ad::map::landmark::LandmarkId value;
  stream << value;
  ASSERT_GT(stream.str().size(), 0u);
}

TEST(LandmarkIdTests, comparisonOperators)
{
  ::ad::map::landmark::LandmarkId minValue(::ad::map::landmark::LandmarkId::cMinValue);
  ::ad::map::landmark::LandmarkId maxValue(::ad::map::landmark::LandmarkId::cMaxValue);

  ASSERT_TRUE(minValue == minValue);
  ASSERT_TRUE(minValue != maxValue);
  ASSERT_TRUE(minValue < maxValue);
  ASSERT_TRUE(minValue <= minValue);
  ASSERT_TRUE(maxValue > minValue);
  ASSERT_TRUE(maxValue >= minValue);
}

TEST(LandmarkIdTests, arithmeticOperators)
{
  ::ad::map::landmark::LandmarkId minValue(::ad::map::landmark::LandmarkId::cMinValue);
  ::ad::map::landmark::LandmarkId maxValue(::ad::map::landmark::LandmarkId::cMaxValue);
  ::ad::map::landmark::LandmarkId result;

  ASSERT_EQ((minValue + minValue).mLandmarkId,
            ::ad::map::landmark::LandmarkId::cMinValue + ::ad::map::landmark::LandmarkId::cMinValue);
  result = minValue;
  result += minValue;
  ASSERT_EQ(result.mLandmarkId,
            ::ad::map::landmark::LandmarkId::cMinValue + ::ad::map::landmark::LandmarkId::cMinValue);
  ASSERT_EQ((maxValue - minValue).mLandmarkId,
            ::ad::map::landmark::LandmarkId::cMaxValue - ::ad::map::landmark::LandmarkId::cMinValue);
  result = maxValue;
  result -= minValue;
  ASSERT_EQ(result.mLandmarkId,
            ::ad::map::landmark::LandmarkId::cMaxValue - ::ad::map::landmark::LandmarkId::cMinValue);
}

#if defined(__clang__) && (__clang_major__ >= 7)
#pragma GCC diagnostic pop
#endif
