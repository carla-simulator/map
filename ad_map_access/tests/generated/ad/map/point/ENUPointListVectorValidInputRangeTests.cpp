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

#include "ad/map/point/ENUPointListVectorValidInputRange.hpp"

TEST(ENUPointListVectorValidInputRangeTests, testValidInputRangeValidInputRangeMin)
{
  ::ad::map::point::ENUPointListVector value;
  ASSERT_TRUE(withinValidInputRange(value));
}

TEST(ENUPointListVectorValidInputRangeTests, testValidInputRangeElementValid)
{
  ::ad::map::point::ENUPointListVector value;
  ::ad::map::point::ENUPointList element;
  ::ad::map::point::ENUPoint elementElement;
  ::ad::map::point::ENUCoordinate elementElementX(-1e8);
  elementElement.x = elementElementX;
  ::ad::map::point::ENUCoordinate elementElementY(-1e8);
  elementElement.y = elementElementY;
  ::ad::map::point::ENUCoordinate elementElementZ(-1e8);
  elementElement.z = elementElementZ;
  element.resize(1, elementElement);
  value.push_back(element);
  ASSERT_TRUE(withinValidInputRange(value));
}
