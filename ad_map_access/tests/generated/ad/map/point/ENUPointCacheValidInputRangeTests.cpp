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

#include "ad/map/point/ENUPointCacheValidInputRange.hpp"

TEST(ENUPointCacheValidInputRangeTests, testValidInputRange)
{
  ::ad::map::point::ENUPointCache value;
  ::ad::map::point::ENUPointList valueEnu_points;
  ::ad::map::point::ENUPoint valueEnu_pointsElement;
  ::ad::map::point::ENUCoordinate valueEnu_pointsElementX(-1e8);
  valueEnu_pointsElement.x = valueEnu_pointsElementX;
  ::ad::map::point::ENUCoordinate valueEnu_pointsElementY(-1e8);
  valueEnu_pointsElement.y = valueEnu_pointsElementY;
  ::ad::map::point::ENUCoordinate valueEnu_pointsElementZ(-1e8);
  valueEnu_pointsElement.z = valueEnu_pointsElementZ;
  valueEnu_points.resize(1, valueEnu_pointsElement);
  value.enu_points = valueEnu_points;
  uint64_t valueEnu_version{std::numeric_limits<uint64_t>::min()};
  value.enu_version = valueEnu_version;
  ASSERT_TRUE(withinValidInputRange(value));
}
