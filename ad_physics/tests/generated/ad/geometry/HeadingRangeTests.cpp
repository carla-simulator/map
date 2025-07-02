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
#include "ad/geometry/HeadingRange.hpp"

class HeadingRangeTests : public testing::Test
{
protected:
  virtual void SetUp() override
  {
    // valid initialization
    ::ad::geometry::HeadingRange value;
    ::ad::physics::Angle valueBegin(-6.283185308);
    value.begin = valueBegin;
    ::ad::physics::Angle valueEnd(-6.283185308);
    value.end = valueEnd;
    mValue = value;
  }

  ::ad::geometry::HeadingRange mValue;
};

TEST_F(HeadingRangeTests, copyConstruction)
{
  ::ad::geometry::HeadingRange value(mValue);
  EXPECT_EQ(mValue, value);
}

TEST_F(HeadingRangeTests, moveConstruction)
{
  ::ad::geometry::HeadingRange tmpValue(mValue);
  ::ad::geometry::HeadingRange value(std::move(tmpValue));
  EXPECT_EQ(mValue, value);
}

TEST_F(HeadingRangeTests, copyAssignment)
{
  ::ad::geometry::HeadingRange value;
  value = mValue;
  EXPECT_EQ(mValue, value);
}

TEST_F(HeadingRangeTests, moveAssignment)
{
  ::ad::geometry::HeadingRange tmpValue(mValue);
  ::ad::geometry::HeadingRange value;
  value = std::move(tmpValue);
  EXPECT_EQ(mValue, value);
}

TEST_F(HeadingRangeTests, comparisonOperatorEqual)
{
  ::ad::geometry::HeadingRange valueA = mValue;
  ::ad::geometry::HeadingRange valueB = mValue;

  EXPECT_TRUE(valueA == valueB);
  EXPECT_FALSE(valueA != valueB);
}

TEST_F(HeadingRangeTests, stringConversionTest)
{
  std::stringstream stream;
  stream << mValue;
  std::string ostreamStr = stream.str();
  std::string toStr = std::to_string(mValue);
  ASSERT_EQ(ostreamStr, toStr);
}

TEST_F(HeadingRangeTests, comparisonOperatorBeginDiffers)
{
  ::ad::geometry::HeadingRange valueA = mValue;
  ::ad::physics::Angle begin(6.283185308);
  valueA.begin = begin;
  ::ad::geometry::HeadingRange valueB = mValue;

  EXPECT_FALSE(valueA == valueB);
  EXPECT_TRUE(valueA != valueB);
}

TEST_F(HeadingRangeTests, comparisonOperatorEndDiffers)
{
  ::ad::geometry::HeadingRange valueA = mValue;
  ::ad::physics::Angle end(6.283185308);
  valueA.end = end;
  ::ad::geometry::HeadingRange valueB = mValue;

  EXPECT_FALSE(valueA == valueB);
  EXPECT_TRUE(valueA != valueB);
}

#if defined(__clang__) && (__clang_major__ >= 7)
#pragma GCC diagnostic pop
#endif
