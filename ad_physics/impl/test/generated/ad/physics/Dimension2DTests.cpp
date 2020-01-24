/*
 * ----------------- BEGIN LICENSE BLOCK ---------------------------------
 *
 * Copyright (C) 2018-2020 Intel Corporation
 *
 * SPDX-License-Identifier: MIT
 *
 * ----------------- END LICENSE BLOCK -----------------------------------
 */

/*
 * Generated file
 */

#include <gtest/gtest.h>
#include <limits>
#include "ad/physics/Dimension2D.hpp"

class Dimension2DTests : public testing::Test
{
protected:
  virtual void SetUp() override
  {
    // valid initialization
    ::ad::physics::Dimension2D value;
    ::ad::physics::Distance valueLength(0.);
    value.length = valueLength;
    ::ad::physics::Distance valueWidth(0.);
    value.width = valueWidth;
    mValue = value;
  }

  ::ad::physics::Dimension2D mValue;
};

TEST_F(Dimension2DTests, copyConstruction)
{
  ::ad::physics::Dimension2D value(mValue);
  EXPECT_EQ(mValue, value);
}

TEST_F(Dimension2DTests, moveConstruction)
{
  ::ad::physics::Dimension2D value(std::move(::ad::physics::Dimension2D(mValue)));
  EXPECT_EQ(mValue, value);
}

TEST_F(Dimension2DTests, copyAssignment)
{
  ::ad::physics::Dimension2D value;
  value = mValue;
  EXPECT_EQ(mValue, value);
}

TEST_F(Dimension2DTests, moveAssignment)
{
  ::ad::physics::Dimension2D value;
  value = std::move(::ad::physics::Dimension2D(mValue));
  EXPECT_EQ(mValue, value);
}

TEST_F(Dimension2DTests, comparisonOperatorEqual)
{
  ::ad::physics::Dimension2D valueA = mValue;
  ::ad::physics::Dimension2D valueB = mValue;

  EXPECT_TRUE(valueA == valueB);
  EXPECT_FALSE(valueA != valueB);
}

TEST_F(Dimension2DTests, stringConversionTest)
{
  std::stringstream stream;
  stream << mValue;
  std::string ostreamStr = stream.str();
  std::string toStr = std::to_string(mValue);
  ASSERT_EQ(ostreamStr, toStr);
}

TEST_F(Dimension2DTests, comparisonOperatorLengthDiffers)
{
  ::ad::physics::Dimension2D valueA = mValue;
  ::ad::physics::Distance length(1e9);
  valueA.length = length;
  ::ad::physics::Dimension2D valueB = mValue;

  EXPECT_FALSE(valueA == valueB);
  EXPECT_TRUE(valueA != valueB);
}

TEST_F(Dimension2DTests, comparisonOperatorWidthDiffers)
{
  ::ad::physics::Dimension2D valueA = mValue;
  ::ad::physics::Distance width(1e9);
  valueA.width = width;
  ::ad::physics::Dimension2D valueB = mValue;

  EXPECT_FALSE(valueA == valueB);
  EXPECT_TRUE(valueA != valueB);
}
