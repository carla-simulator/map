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

#include "ad/map/point/GeometryValidInputRange.hpp"

TEST(GeometryValidInputRangeTests, testValidInputRange)
{
  ::ad::map::point::Geometry value;
  bool valueIs_valid{true};
  value.is_valid = valueIs_valid;
  bool valueIs_closed{true};
  value.is_closed = valueIs_closed;
  ::ad::map::point::ECEFPointList valueEcef_points;
  ::ad::map::point::ECEFPoint valueEcef_pointsElement;
  ::ad::map::point::ECEFCoordinate valueEcef_pointsElementX(-6400000);
  valueEcef_pointsElement.x = valueEcef_pointsElementX;
  ::ad::map::point::ECEFCoordinate valueEcef_pointsElementY(-6400000);
  valueEcef_pointsElement.y = valueEcef_pointsElementY;
  ::ad::map::point::ECEFCoordinate valueEcef_pointsElementZ(-6400000);
  valueEcef_pointsElement.z = valueEcef_pointsElementZ;
  valueEcef_points.resize(1, valueEcef_pointsElement);
  value.ecef_points = valueEcef_points;
  ::ad::physics::Distance valueLength(-1e9);
  value.length = valueLength;
  ::ad::map::point::ENUPointCache valuePrivate_enu_points_cache;
  ::ad::map::point::ENUPointList valuePrivate_enu_points_cacheEnu_points;
  ::ad::map::point::ENUPoint valuePrivate_enu_points_cacheEnu_pointsElement;
  ::ad::map::point::ENUCoordinate valuePrivate_enu_points_cacheEnu_pointsElementX(-1e8);
  valuePrivate_enu_points_cacheEnu_pointsElement.x = valuePrivate_enu_points_cacheEnu_pointsElementX;
  ::ad::map::point::ENUCoordinate valuePrivate_enu_points_cacheEnu_pointsElementY(-1e8);
  valuePrivate_enu_points_cacheEnu_pointsElement.y = valuePrivate_enu_points_cacheEnu_pointsElementY;
  ::ad::map::point::ENUCoordinate valuePrivate_enu_points_cacheEnu_pointsElementZ(-1e8);
  valuePrivate_enu_points_cacheEnu_pointsElement.z = valuePrivate_enu_points_cacheEnu_pointsElementZ;
  valuePrivate_enu_points_cacheEnu_points.resize(1, valuePrivate_enu_points_cacheEnu_pointsElement);
  valuePrivate_enu_points_cache.enu_points = valuePrivate_enu_points_cacheEnu_points;
  uint64_t valuePrivate_enu_points_cacheEnu_version{std::numeric_limits<uint64_t>::min()};
  valuePrivate_enu_points_cache.enu_version = valuePrivate_enu_points_cacheEnu_version;
  value.private_enu_points_cache = valuePrivate_enu_points_cache;
  ASSERT_TRUE(withinValidInputRange(value));
}

TEST(GeometryValidInputRangeTests, testValidInputRangeLengthTooSmall)
{
  ::ad::map::point::Geometry value;
  bool valueIs_valid{true};
  value.is_valid = valueIs_valid;
  bool valueIs_closed{true};
  value.is_closed = valueIs_closed;
  ::ad::map::point::ECEFPointList valueEcef_points;
  ::ad::map::point::ECEFPoint valueEcef_pointsElement;
  ::ad::map::point::ECEFCoordinate valueEcef_pointsElementX(-6400000);
  valueEcef_pointsElement.x = valueEcef_pointsElementX;
  ::ad::map::point::ECEFCoordinate valueEcef_pointsElementY(-6400000);
  valueEcef_pointsElement.y = valueEcef_pointsElementY;
  ::ad::map::point::ECEFCoordinate valueEcef_pointsElementZ(-6400000);
  valueEcef_pointsElement.z = valueEcef_pointsElementZ;
  valueEcef_points.resize(1, valueEcef_pointsElement);
  value.ecef_points = valueEcef_points;
  ::ad::physics::Distance valueLength(-1e9);
  value.length = valueLength;
  ::ad::map::point::ENUPointCache valuePrivate_enu_points_cache;
  ::ad::map::point::ENUPointList valuePrivate_enu_points_cacheEnu_points;
  ::ad::map::point::ENUPoint valuePrivate_enu_points_cacheEnu_pointsElement;
  ::ad::map::point::ENUCoordinate valuePrivate_enu_points_cacheEnu_pointsElementX(-1e8);
  valuePrivate_enu_points_cacheEnu_pointsElement.x = valuePrivate_enu_points_cacheEnu_pointsElementX;
  ::ad::map::point::ENUCoordinate valuePrivate_enu_points_cacheEnu_pointsElementY(-1e8);
  valuePrivate_enu_points_cacheEnu_pointsElement.y = valuePrivate_enu_points_cacheEnu_pointsElementY;
  ::ad::map::point::ENUCoordinate valuePrivate_enu_points_cacheEnu_pointsElementZ(-1e8);
  valuePrivate_enu_points_cacheEnu_pointsElement.z = valuePrivate_enu_points_cacheEnu_pointsElementZ;
  valuePrivate_enu_points_cacheEnu_points.resize(1, valuePrivate_enu_points_cacheEnu_pointsElement);
  valuePrivate_enu_points_cache.enu_points = valuePrivate_enu_points_cacheEnu_points;
  uint64_t valuePrivate_enu_points_cacheEnu_version{std::numeric_limits<uint64_t>::min()};
  valuePrivate_enu_points_cache.enu_version = valuePrivate_enu_points_cacheEnu_version;
  value.private_enu_points_cache = valuePrivate_enu_points_cache;

  // override member with data type value below input range minimum
  ::ad::physics::Distance invalidInitializedMember(-1e9 * 1.1);
  value.length = invalidInitializedMember;
  ASSERT_FALSE(withinValidInputRange(value));
}

TEST(GeometryValidInputRangeTests, testValidInputRangeLengthTooBig)
{
  ::ad::map::point::Geometry value;
  bool valueIs_valid{true};
  value.is_valid = valueIs_valid;
  bool valueIs_closed{true};
  value.is_closed = valueIs_closed;
  ::ad::map::point::ECEFPointList valueEcef_points;
  ::ad::map::point::ECEFPoint valueEcef_pointsElement;
  ::ad::map::point::ECEFCoordinate valueEcef_pointsElementX(-6400000);
  valueEcef_pointsElement.x = valueEcef_pointsElementX;
  ::ad::map::point::ECEFCoordinate valueEcef_pointsElementY(-6400000);
  valueEcef_pointsElement.y = valueEcef_pointsElementY;
  ::ad::map::point::ECEFCoordinate valueEcef_pointsElementZ(-6400000);
  valueEcef_pointsElement.z = valueEcef_pointsElementZ;
  valueEcef_points.resize(1, valueEcef_pointsElement);
  value.ecef_points = valueEcef_points;
  ::ad::physics::Distance valueLength(-1e9);
  value.length = valueLength;
  ::ad::map::point::ENUPointCache valuePrivate_enu_points_cache;
  ::ad::map::point::ENUPointList valuePrivate_enu_points_cacheEnu_points;
  ::ad::map::point::ENUPoint valuePrivate_enu_points_cacheEnu_pointsElement;
  ::ad::map::point::ENUCoordinate valuePrivate_enu_points_cacheEnu_pointsElementX(-1e8);
  valuePrivate_enu_points_cacheEnu_pointsElement.x = valuePrivate_enu_points_cacheEnu_pointsElementX;
  ::ad::map::point::ENUCoordinate valuePrivate_enu_points_cacheEnu_pointsElementY(-1e8);
  valuePrivate_enu_points_cacheEnu_pointsElement.y = valuePrivate_enu_points_cacheEnu_pointsElementY;
  ::ad::map::point::ENUCoordinate valuePrivate_enu_points_cacheEnu_pointsElementZ(-1e8);
  valuePrivate_enu_points_cacheEnu_pointsElement.z = valuePrivate_enu_points_cacheEnu_pointsElementZ;
  valuePrivate_enu_points_cacheEnu_points.resize(1, valuePrivate_enu_points_cacheEnu_pointsElement);
  valuePrivate_enu_points_cache.enu_points = valuePrivate_enu_points_cacheEnu_points;
  uint64_t valuePrivate_enu_points_cacheEnu_version{std::numeric_limits<uint64_t>::min()};
  valuePrivate_enu_points_cache.enu_version = valuePrivate_enu_points_cacheEnu_version;
  value.private_enu_points_cache = valuePrivate_enu_points_cache;

  // override member with data type value above input range maximum
  ::ad::physics::Distance invalidInitializedMember(1e9 * 1.1);
  value.length = invalidInitializedMember;
  ASSERT_FALSE(withinValidInputRange(value));
}

TEST(GeometryValidInputRangeTests, testValidInputRangelengthDefault)
{
  ::ad::map::point::Geometry value;
  ::ad::physics::Distance valueDefault;
  value.length = valueDefault;
  ASSERT_FALSE(withinValidInputRange(value));
}
