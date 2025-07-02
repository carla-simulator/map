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

#include "ad/map/point/ENUPointListValidInputRange.hpp"

TEST(ENUPointListValidInputRangeTests, testValidInputRangeValidInputRangeMin)
{
  ::ad::map::point::ENUPointList value;
  ASSERT_TRUE(withinValidInputRange(value));
}

TEST(ENUPointListValidInputRangeTests, testValidInputRangeElementValid)
{
  ::ad::map::point::ENUPointList value;
  ::ad::map::point::ENUPoint element;
  ::ad::map::point::ENUCoordinate elementX(-1e8);
  element.x = elementX;
  ::ad::map::point::ENUCoordinate elementY(-1e8);
  element.y = elementY;
  ::ad::map::point::ENUCoordinate elementZ(-1e8);
  element.z = elementZ;
  value.push_back(element);
  ASSERT_TRUE(withinValidInputRange(value));
}

TEST(ENUPointListValidInputRangeTests, testValidInputRangeElementInvalid)
{
  ::ad::map::point::ENUPointList value;
  ::ad::map::point::ENUPoint element;
  ::ad::map::point::ENUCoordinate elementX(-1e8 * 1.1);
  element.x = elementX;
  value.push_back(element);
  ASSERT_FALSE(withinValidInputRange(value));
}
