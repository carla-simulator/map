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

#include <gtest/gtest.h>

#include <limits>

#include "ad/map/point/LatitudeValidInputRange.hpp"

TEST(LatitudeValidInputRangeTests, testValidInputRangeUninitialized)
{
  ::ad::map::point::Latitude value;
  ASSERT_FALSE(withinValidInputRange(value));
}

TEST(LatitudeValidInputRangeTests, testValidInputRangeMinOk)
{
  ::ad::map::point::Latitude value(-90);
  ASSERT_TRUE(withinValidInputRange(value));
}

TEST(LatitudeValidInputRangeTests, testValidInputRangeMaxOk)
{
  ::ad::map::point::Latitude value(90);
  ASSERT_TRUE(withinValidInputRange(value));
}

TEST(LatitudeValidInputRangeTests, testValidInputRangeBelowMin)
{
  ::ad::map::point::Latitude value(::ad::map::point::Latitude::cMinValue * 1.1);
  ASSERT_FALSE(withinValidInputRange(value));
}

TEST(LatitudeValidInputRangeTests, testValidInputRangeExceedsMax)
{
  ::ad::map::point::Latitude value(::ad::map::point::Latitude::cMaxValue * 1.1);
  ASSERT_FALSE(withinValidInputRange(value));
}

TEST(LatitudeValidInputRangeTests, testValidInputRangeInputMinOk)
{
  ::ad::map::point::Latitude value(-90);
  ASSERT_TRUE(withinValidInputRange(value));
}

TEST(LatitudeValidInputRangeTests, testValidInputRangeInputMaxOk)
{
  ::ad::map::point::Latitude value(90);
  ASSERT_TRUE(withinValidInputRange(value));
}

TEST(LatitudeValidInputRangeTests, testValidInputRangeBelowInputMin)
{
  ::ad::map::point::Latitude value(-90 * 1.1);
  ASSERT_FALSE(withinValidInputRange(value));
}

TEST(LatitudeValidInputRangeTests, testValidInputRangeExceedsInputMax)
{
  ::ad::map::point::Latitude value(90 * 1.1);
  ASSERT_FALSE(withinValidInputRange(value));
}
