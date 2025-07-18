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
#include "ad/map/access/PartitionId.hpp"

TEST(PartitionIdTests, minIsDefinedAsExpected)
{
  EXPECT_EQ(0u, ::ad::map::access::PartitionId::cMinValue);
  EXPECT_EQ(::ad::map::access::PartitionId::cMinValue, ::ad::map::access::PartitionId::getMin().mPartitionId);
}

TEST(PartitionIdTests, minIsValid)
{
  EXPECT_TRUE(::ad::map::access::PartitionId::getMin().isValid());
}

TEST(PartitionIdTests, aboveMinIsValid)
{
  ::ad::map::access::PartitionId value(::ad::map::access::PartitionId::cMinValue + 1);
  EXPECT_TRUE(value.isValid());
}

TEST(PartitionIdTests, maxIsValid)
{
  EXPECT_TRUE(::ad::map::access::PartitionId::getMax().isValid());
}

TEST(PartitionIdTests, belowMaxIsValid)
{
  ::ad::map::access::PartitionId value(::ad::map::access::PartitionId::cMaxValue - 1);
  EXPECT_TRUE(value.isValid());
}

#if (AD_MAP_ACCESS_PARTITIONID_THROWS_EXCEPTION == 1)
TEST(PartitionIdTests, ensureValidNonZeroThrowsOnInvalid)
{
  ::ad::map::access::PartitionId value;
  EXPECT_THROW(value.ensureValidNonZero(), std::out_of_range);
}

TEST(PartitionIdTests, ensureValidNonZeroThrowsOnZero)
{
  ::ad::map::access::PartitionId value(0.);
  EXPECT_THROW(value.ensureValidNonZero(), std::out_of_range);
}
#endif

TEST(PartitionIdTestsStd, numericLimitsLowestIsMin)
{
  EXPECT_EQ(::ad::map::access::PartitionId::getMin().mPartitionId,
            std::numeric_limits<::ad::map::access::PartitionId>::lowest().mPartitionId);
}

TEST(PartitionIdTestsStd, numericLimitsMaxIsMax)
{
  EXPECT_EQ(::ad::map::access::PartitionId::getMax().mPartitionId,
            std::numeric_limits<::ad::map::access::PartitionId>::max().mPartitionId);
}

TEST(PartitionIdTests, copyConstructionFromValidValue)
{
  ::ad::map::access::PartitionId const validValue(::ad::map::access::PartitionId::cMinValue);
  ::ad::map::access::PartitionId value(validValue);
  EXPECT_TRUE(value.isValid());
  EXPECT_EQ(validValue.mPartitionId, value.mPartitionId);
}

TEST(PartitionIdTests, moveConstructionFromValidValue)
{
  ::ad::map::access::PartitionId validValue(::ad::map::access::PartitionId::cMinValue);
  ::ad::map::access::PartitionId value(std::move(validValue));
  EXPECT_TRUE(value.isValid());
  EXPECT_EQ(::ad::map::access::PartitionId::cMinValue, value.mPartitionId);
}

TEST(PartitionIdTests, assignmentFromValidValue)
{
  ::ad::map::access::PartitionId const validValue(::ad::map::access::PartitionId::cMinValue);
  ::ad::map::access::PartitionId value;
  value = validValue;
  EXPECT_TRUE(value.isValid());
  EXPECT_EQ(validValue.mPartitionId, value.mPartitionId);
}

TEST(PartitionIdTests, moveAssignmentFromValidValue)
{
  ::ad::map::access::PartitionId validValue(::ad::map::access::PartitionId::cMinValue);
  ::ad::map::access::PartitionId value;
  value = std::move(validValue);
  EXPECT_TRUE(value.isValid());
  EXPECT_EQ(::ad::map::access::PartitionId::cMinValue, value.mPartitionId);
}

TEST(PartitionIdTests, selfAssignment)
{
  ::ad::map::access::PartitionId value(::ad::map::access::PartitionId::cMinValue);
  EXPECT_TRUE(value.isValid());
  value = value;
  EXPECT_TRUE(value.isValid());
}

TEST(PartitionIdTests, ostreamOperatorTest)
{
  std::stringstream stream;
  ::ad::map::access::PartitionId value;
  stream << value;
  ASSERT_GT(stream.str().size(), 0u);
}

TEST(PartitionIdTests, comparisonOperators)
{
  ::ad::map::access::PartitionId minValue(::ad::map::access::PartitionId::cMinValue);
  ::ad::map::access::PartitionId maxValue(::ad::map::access::PartitionId::cMaxValue);

  ASSERT_TRUE(minValue == minValue);
  ASSERT_TRUE(minValue != maxValue);
  ASSERT_TRUE(minValue < maxValue);
  ASSERT_TRUE(minValue <= minValue);
  ASSERT_TRUE(maxValue > minValue);
  ASSERT_TRUE(maxValue >= minValue);
}

TEST(PartitionIdTests, arithmeticOperators)
{
  ::ad::map::access::PartitionId minValue(::ad::map::access::PartitionId::cMinValue);
  ::ad::map::access::PartitionId maxValue(::ad::map::access::PartitionId::cMaxValue);
  ::ad::map::access::PartitionId result;

  ASSERT_EQ((minValue + minValue).mPartitionId,
            ::ad::map::access::PartitionId::cMinValue + ::ad::map::access::PartitionId::cMinValue);
  result = minValue;
  result += minValue;
  ASSERT_EQ(result.mPartitionId, ::ad::map::access::PartitionId::cMinValue + ::ad::map::access::PartitionId::cMinValue);
  ASSERT_EQ((maxValue - minValue).mPartitionId,
            ::ad::map::access::PartitionId::cMaxValue - ::ad::map::access::PartitionId::cMinValue);
  result = maxValue;
  result -= minValue;
  ASSERT_EQ(result.mPartitionId, ::ad::map::access::PartitionId::cMaxValue - ::ad::map::access::PartitionId::cMinValue);
}

#if defined(__clang__) && (__clang_major__ >= 7)
#pragma GCC diagnostic pop
#endif
