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

#include "ad/geometry/HeadingRangeVectorValidInputRange.hpp"

TEST(HeadingRangeVectorValidInputRangeTests, testValidInputRangeValidInputRangeMin)
{
  ::ad::geometry::HeadingRangeVector value;
  ASSERT_TRUE(withinValidInputRange(value));
}

TEST(HeadingRangeVectorValidInputRangeTests, testValidInputRangeElementValid)
{
  ::ad::geometry::HeadingRangeVector value;
  ::ad::geometry::HeadingRange element;
  ::ad::physics::Angle elementBegin(-6.283185308);
  element.begin = elementBegin;
  ::ad::physics::Angle elementEnd(-6.283185308);
  element.end = elementEnd;
  value.push_back(element);
  ASSERT_TRUE(withinValidInputRange(value));
}

TEST(HeadingRangeVectorValidInputRangeTests, testValidInputRangeElementInvalid)
{
  ::ad::geometry::HeadingRangeVector value;
  ::ad::geometry::HeadingRange element;
  ::ad::physics::Angle elementBegin(-6.283185308 * 1.1);
  element.begin = elementBegin;
  value.push_back(element);
  ASSERT_FALSE(withinValidInputRange(value));
}
