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

#include "ad/map/match/ENUObjectPositionValidInputRange.hpp"

TEST(ENUObjectPositionValidInputRangeTests, testValidInputRange)
{
  ::ad::map::match::ENUObjectPosition value;
  ::ad::map::point::ENUPoint valueCenter_point;
  ::ad::map::point::ENUCoordinate valueCenter_pointX(-1e8);
  valueCenter_point.x = valueCenter_pointX;
  ::ad::map::point::ENUCoordinate valueCenter_pointY(-1e8);
  valueCenter_point.y = valueCenter_pointY;
  ::ad::map::point::ENUCoordinate valueCenter_pointZ(-1e8);
  valueCenter_point.z = valueCenter_pointZ;
  value.center_point = valueCenter_point;
  ::ad::map::point::ENUHeading valueHeading(-3.141592655);
  value.heading = valueHeading;
  ::ad::map::point::GeoPoint valueEnu_reference_point;
  ::ad::map::point::Longitude valueEnu_reference_pointLongitude(-180);
  valueEnu_reference_point.longitude = valueEnu_reference_pointLongitude;
  ::ad::map::point::Latitude valueEnu_reference_pointLatitude(-90);
  valueEnu_reference_point.latitude = valueEnu_reference_pointLatitude;
  ::ad::map::point::Altitude valueEnu_reference_pointAltitude(-11000);
  valueEnu_reference_point.altitude = valueEnu_reference_pointAltitude;
  value.enu_reference_point = valueEnu_reference_point;
  ::ad::physics::Dimension3D valueDimension;
  ::ad::physics::Distance valueDimensionLength(-1e9);
  valueDimension.length = valueDimensionLength;
  ::ad::physics::Distance valueDimensionWidth(-1e9);
  valueDimension.width = valueDimensionWidth;
  ::ad::physics::Distance valueDimensionHeight(-1e9);
  valueDimension.height = valueDimensionHeight;
  value.dimension = valueDimension;
  ASSERT_TRUE(withinValidInputRange(value));
}

TEST(ENUObjectPositionValidInputRangeTests, testValidInputRangeCenter_pointTooSmall)
{
  ::ad::map::match::ENUObjectPosition value;
  ::ad::map::point::ENUPoint valueCenter_point;
  ::ad::map::point::ENUCoordinate valueCenter_pointX(-1e8);
  valueCenter_point.x = valueCenter_pointX;
  ::ad::map::point::ENUCoordinate valueCenter_pointY(-1e8);
  valueCenter_point.y = valueCenter_pointY;
  ::ad::map::point::ENUCoordinate valueCenter_pointZ(-1e8);
  valueCenter_point.z = valueCenter_pointZ;
  value.center_point = valueCenter_point;
  ::ad::map::point::ENUHeading valueHeading(-3.141592655);
  value.heading = valueHeading;
  ::ad::map::point::GeoPoint valueEnu_reference_point;
  ::ad::map::point::Longitude valueEnu_reference_pointLongitude(-180);
  valueEnu_reference_point.longitude = valueEnu_reference_pointLongitude;
  ::ad::map::point::Latitude valueEnu_reference_pointLatitude(-90);
  valueEnu_reference_point.latitude = valueEnu_reference_pointLatitude;
  ::ad::map::point::Altitude valueEnu_reference_pointAltitude(-11000);
  valueEnu_reference_point.altitude = valueEnu_reference_pointAltitude;
  value.enu_reference_point = valueEnu_reference_point;
  ::ad::physics::Dimension3D valueDimension;
  ::ad::physics::Distance valueDimensionLength(-1e9);
  valueDimension.length = valueDimensionLength;
  ::ad::physics::Distance valueDimensionWidth(-1e9);
  valueDimension.width = valueDimensionWidth;
  ::ad::physics::Distance valueDimensionHeight(-1e9);
  valueDimension.height = valueDimensionHeight;
  value.dimension = valueDimension;

  // override member with data type value below input range minimum
  ::ad::map::point::ENUPoint invalidInitializedMember;
  ::ad::map::point::ENUCoordinate invalidInitializedMemberX(-1e8 * 1.1);
  invalidInitializedMember.x = invalidInitializedMemberX;
  value.center_point = invalidInitializedMember;
  ASSERT_FALSE(withinValidInputRange(value));
}

TEST(ENUObjectPositionValidInputRangeTests, testValidInputRangeCenter_pointTooBig)
{
  ::ad::map::match::ENUObjectPosition value;
  ::ad::map::point::ENUPoint valueCenter_point;
  ::ad::map::point::ENUCoordinate valueCenter_pointX(-1e8);
  valueCenter_point.x = valueCenter_pointX;
  ::ad::map::point::ENUCoordinate valueCenter_pointY(-1e8);
  valueCenter_point.y = valueCenter_pointY;
  ::ad::map::point::ENUCoordinate valueCenter_pointZ(-1e8);
  valueCenter_point.z = valueCenter_pointZ;
  value.center_point = valueCenter_point;
  ::ad::map::point::ENUHeading valueHeading(-3.141592655);
  value.heading = valueHeading;
  ::ad::map::point::GeoPoint valueEnu_reference_point;
  ::ad::map::point::Longitude valueEnu_reference_pointLongitude(-180);
  valueEnu_reference_point.longitude = valueEnu_reference_pointLongitude;
  ::ad::map::point::Latitude valueEnu_reference_pointLatitude(-90);
  valueEnu_reference_point.latitude = valueEnu_reference_pointLatitude;
  ::ad::map::point::Altitude valueEnu_reference_pointAltitude(-11000);
  valueEnu_reference_point.altitude = valueEnu_reference_pointAltitude;
  value.enu_reference_point = valueEnu_reference_point;
  ::ad::physics::Dimension3D valueDimension;
  ::ad::physics::Distance valueDimensionLength(-1e9);
  valueDimension.length = valueDimensionLength;
  ::ad::physics::Distance valueDimensionWidth(-1e9);
  valueDimension.width = valueDimensionWidth;
  ::ad::physics::Distance valueDimensionHeight(-1e9);
  valueDimension.height = valueDimensionHeight;
  value.dimension = valueDimension;

  // override member with data type value above input range maximum
  ::ad::map::point::ENUPoint invalidInitializedMember;
  ::ad::map::point::ENUCoordinate invalidInitializedMemberX(1e8 * 1.1);
  invalidInitializedMember.x = invalidInitializedMemberX;
  value.center_point = invalidInitializedMember;
  ASSERT_FALSE(withinValidInputRange(value));
}

TEST(ENUObjectPositionValidInputRangeTests, testValidInputRangeHeadingTooSmall)
{
  ::ad::map::match::ENUObjectPosition value;
  ::ad::map::point::ENUPoint valueCenter_point;
  ::ad::map::point::ENUCoordinate valueCenter_pointX(-1e8);
  valueCenter_point.x = valueCenter_pointX;
  ::ad::map::point::ENUCoordinate valueCenter_pointY(-1e8);
  valueCenter_point.y = valueCenter_pointY;
  ::ad::map::point::ENUCoordinate valueCenter_pointZ(-1e8);
  valueCenter_point.z = valueCenter_pointZ;
  value.center_point = valueCenter_point;
  ::ad::map::point::ENUHeading valueHeading(-3.141592655);
  value.heading = valueHeading;
  ::ad::map::point::GeoPoint valueEnu_reference_point;
  ::ad::map::point::Longitude valueEnu_reference_pointLongitude(-180);
  valueEnu_reference_point.longitude = valueEnu_reference_pointLongitude;
  ::ad::map::point::Latitude valueEnu_reference_pointLatitude(-90);
  valueEnu_reference_point.latitude = valueEnu_reference_pointLatitude;
  ::ad::map::point::Altitude valueEnu_reference_pointAltitude(-11000);
  valueEnu_reference_point.altitude = valueEnu_reference_pointAltitude;
  value.enu_reference_point = valueEnu_reference_point;
  ::ad::physics::Dimension3D valueDimension;
  ::ad::physics::Distance valueDimensionLength(-1e9);
  valueDimension.length = valueDimensionLength;
  ::ad::physics::Distance valueDimensionWidth(-1e9);
  valueDimension.width = valueDimensionWidth;
  ::ad::physics::Distance valueDimensionHeight(-1e9);
  valueDimension.height = valueDimensionHeight;
  value.dimension = valueDimension;

  // override member with data type value below input range minimum
  ::ad::map::point::ENUHeading invalidInitializedMember(-3.141592655 * 1.1);
  value.heading = invalidInitializedMember;
  ASSERT_FALSE(withinValidInputRange(value));
}

TEST(ENUObjectPositionValidInputRangeTests, testValidInputRangeHeadingTooBig)
{
  ::ad::map::match::ENUObjectPosition value;
  ::ad::map::point::ENUPoint valueCenter_point;
  ::ad::map::point::ENUCoordinate valueCenter_pointX(-1e8);
  valueCenter_point.x = valueCenter_pointX;
  ::ad::map::point::ENUCoordinate valueCenter_pointY(-1e8);
  valueCenter_point.y = valueCenter_pointY;
  ::ad::map::point::ENUCoordinate valueCenter_pointZ(-1e8);
  valueCenter_point.z = valueCenter_pointZ;
  value.center_point = valueCenter_point;
  ::ad::map::point::ENUHeading valueHeading(-3.141592655);
  value.heading = valueHeading;
  ::ad::map::point::GeoPoint valueEnu_reference_point;
  ::ad::map::point::Longitude valueEnu_reference_pointLongitude(-180);
  valueEnu_reference_point.longitude = valueEnu_reference_pointLongitude;
  ::ad::map::point::Latitude valueEnu_reference_pointLatitude(-90);
  valueEnu_reference_point.latitude = valueEnu_reference_pointLatitude;
  ::ad::map::point::Altitude valueEnu_reference_pointAltitude(-11000);
  valueEnu_reference_point.altitude = valueEnu_reference_pointAltitude;
  value.enu_reference_point = valueEnu_reference_point;
  ::ad::physics::Dimension3D valueDimension;
  ::ad::physics::Distance valueDimensionLength(-1e9);
  valueDimension.length = valueDimensionLength;
  ::ad::physics::Distance valueDimensionWidth(-1e9);
  valueDimension.width = valueDimensionWidth;
  ::ad::physics::Distance valueDimensionHeight(-1e9);
  valueDimension.height = valueDimensionHeight;
  value.dimension = valueDimension;

  // override member with data type value above input range maximum
  ::ad::map::point::ENUHeading invalidInitializedMember(3.141592655 * 1.1);
  value.heading = invalidInitializedMember;
  ASSERT_FALSE(withinValidInputRange(value));
}

TEST(ENUObjectPositionValidInputRangeTests, testValidInputRangeheadingDefault)
{
  ::ad::map::match::ENUObjectPosition value;
  ::ad::map::point::ENUHeading valueDefault;
  value.heading = valueDefault;
  ASSERT_FALSE(withinValidInputRange(value));
}

TEST(ENUObjectPositionValidInputRangeTests, testValidInputRangeEnu_reference_pointTooSmall)
{
  ::ad::map::match::ENUObjectPosition value;
  ::ad::map::point::ENUPoint valueCenter_point;
  ::ad::map::point::ENUCoordinate valueCenter_pointX(-1e8);
  valueCenter_point.x = valueCenter_pointX;
  ::ad::map::point::ENUCoordinate valueCenter_pointY(-1e8);
  valueCenter_point.y = valueCenter_pointY;
  ::ad::map::point::ENUCoordinate valueCenter_pointZ(-1e8);
  valueCenter_point.z = valueCenter_pointZ;
  value.center_point = valueCenter_point;
  ::ad::map::point::ENUHeading valueHeading(-3.141592655);
  value.heading = valueHeading;
  ::ad::map::point::GeoPoint valueEnu_reference_point;
  ::ad::map::point::Longitude valueEnu_reference_pointLongitude(-180);
  valueEnu_reference_point.longitude = valueEnu_reference_pointLongitude;
  ::ad::map::point::Latitude valueEnu_reference_pointLatitude(-90);
  valueEnu_reference_point.latitude = valueEnu_reference_pointLatitude;
  ::ad::map::point::Altitude valueEnu_reference_pointAltitude(-11000);
  valueEnu_reference_point.altitude = valueEnu_reference_pointAltitude;
  value.enu_reference_point = valueEnu_reference_point;
  ::ad::physics::Dimension3D valueDimension;
  ::ad::physics::Distance valueDimensionLength(-1e9);
  valueDimension.length = valueDimensionLength;
  ::ad::physics::Distance valueDimensionWidth(-1e9);
  valueDimension.width = valueDimensionWidth;
  ::ad::physics::Distance valueDimensionHeight(-1e9);
  valueDimension.height = valueDimensionHeight;
  value.dimension = valueDimension;

  // override member with data type value below input range minimum
  ::ad::map::point::GeoPoint invalidInitializedMember;
  ::ad::map::point::Longitude invalidInitializedMemberLongitude(-180 * 1.1);
  invalidInitializedMember.longitude = invalidInitializedMemberLongitude;
  value.enu_reference_point = invalidInitializedMember;
  ASSERT_FALSE(withinValidInputRange(value));
}

TEST(ENUObjectPositionValidInputRangeTests, testValidInputRangeEnu_reference_pointTooBig)
{
  ::ad::map::match::ENUObjectPosition value;
  ::ad::map::point::ENUPoint valueCenter_point;
  ::ad::map::point::ENUCoordinate valueCenter_pointX(-1e8);
  valueCenter_point.x = valueCenter_pointX;
  ::ad::map::point::ENUCoordinate valueCenter_pointY(-1e8);
  valueCenter_point.y = valueCenter_pointY;
  ::ad::map::point::ENUCoordinate valueCenter_pointZ(-1e8);
  valueCenter_point.z = valueCenter_pointZ;
  value.center_point = valueCenter_point;
  ::ad::map::point::ENUHeading valueHeading(-3.141592655);
  value.heading = valueHeading;
  ::ad::map::point::GeoPoint valueEnu_reference_point;
  ::ad::map::point::Longitude valueEnu_reference_pointLongitude(-180);
  valueEnu_reference_point.longitude = valueEnu_reference_pointLongitude;
  ::ad::map::point::Latitude valueEnu_reference_pointLatitude(-90);
  valueEnu_reference_point.latitude = valueEnu_reference_pointLatitude;
  ::ad::map::point::Altitude valueEnu_reference_pointAltitude(-11000);
  valueEnu_reference_point.altitude = valueEnu_reference_pointAltitude;
  value.enu_reference_point = valueEnu_reference_point;
  ::ad::physics::Dimension3D valueDimension;
  ::ad::physics::Distance valueDimensionLength(-1e9);
  valueDimension.length = valueDimensionLength;
  ::ad::physics::Distance valueDimensionWidth(-1e9);
  valueDimension.width = valueDimensionWidth;
  ::ad::physics::Distance valueDimensionHeight(-1e9);
  valueDimension.height = valueDimensionHeight;
  value.dimension = valueDimension;

  // override member with data type value above input range maximum
  ::ad::map::point::GeoPoint invalidInitializedMember;
  ::ad::map::point::Longitude invalidInitializedMemberLongitude(180 * 1.1);
  invalidInitializedMember.longitude = invalidInitializedMemberLongitude;
  value.enu_reference_point = invalidInitializedMember;
  ASSERT_FALSE(withinValidInputRange(value));
}

TEST(ENUObjectPositionValidInputRangeTests, testValidInputRangeDimensionTooSmall)
{
  ::ad::map::match::ENUObjectPosition value;
  ::ad::map::point::ENUPoint valueCenter_point;
  ::ad::map::point::ENUCoordinate valueCenter_pointX(-1e8);
  valueCenter_point.x = valueCenter_pointX;
  ::ad::map::point::ENUCoordinate valueCenter_pointY(-1e8);
  valueCenter_point.y = valueCenter_pointY;
  ::ad::map::point::ENUCoordinate valueCenter_pointZ(-1e8);
  valueCenter_point.z = valueCenter_pointZ;
  value.center_point = valueCenter_point;
  ::ad::map::point::ENUHeading valueHeading(-3.141592655);
  value.heading = valueHeading;
  ::ad::map::point::GeoPoint valueEnu_reference_point;
  ::ad::map::point::Longitude valueEnu_reference_pointLongitude(-180);
  valueEnu_reference_point.longitude = valueEnu_reference_pointLongitude;
  ::ad::map::point::Latitude valueEnu_reference_pointLatitude(-90);
  valueEnu_reference_point.latitude = valueEnu_reference_pointLatitude;
  ::ad::map::point::Altitude valueEnu_reference_pointAltitude(-11000);
  valueEnu_reference_point.altitude = valueEnu_reference_pointAltitude;
  value.enu_reference_point = valueEnu_reference_point;
  ::ad::physics::Dimension3D valueDimension;
  ::ad::physics::Distance valueDimensionLength(-1e9);
  valueDimension.length = valueDimensionLength;
  ::ad::physics::Distance valueDimensionWidth(-1e9);
  valueDimension.width = valueDimensionWidth;
  ::ad::physics::Distance valueDimensionHeight(-1e9);
  valueDimension.height = valueDimensionHeight;
  value.dimension = valueDimension;

  // override member with data type value below input range minimum
  ::ad::physics::Dimension3D invalidInitializedMember;
  ::ad::physics::Distance invalidInitializedMemberLength(-1e9 * 1.1);
  invalidInitializedMember.length = invalidInitializedMemberLength;
  value.dimension = invalidInitializedMember;
  ASSERT_FALSE(withinValidInputRange(value));
}

TEST(ENUObjectPositionValidInputRangeTests, testValidInputRangeDimensionTooBig)
{
  ::ad::map::match::ENUObjectPosition value;
  ::ad::map::point::ENUPoint valueCenter_point;
  ::ad::map::point::ENUCoordinate valueCenter_pointX(-1e8);
  valueCenter_point.x = valueCenter_pointX;
  ::ad::map::point::ENUCoordinate valueCenter_pointY(-1e8);
  valueCenter_point.y = valueCenter_pointY;
  ::ad::map::point::ENUCoordinate valueCenter_pointZ(-1e8);
  valueCenter_point.z = valueCenter_pointZ;
  value.center_point = valueCenter_point;
  ::ad::map::point::ENUHeading valueHeading(-3.141592655);
  value.heading = valueHeading;
  ::ad::map::point::GeoPoint valueEnu_reference_point;
  ::ad::map::point::Longitude valueEnu_reference_pointLongitude(-180);
  valueEnu_reference_point.longitude = valueEnu_reference_pointLongitude;
  ::ad::map::point::Latitude valueEnu_reference_pointLatitude(-90);
  valueEnu_reference_point.latitude = valueEnu_reference_pointLatitude;
  ::ad::map::point::Altitude valueEnu_reference_pointAltitude(-11000);
  valueEnu_reference_point.altitude = valueEnu_reference_pointAltitude;
  value.enu_reference_point = valueEnu_reference_point;
  ::ad::physics::Dimension3D valueDimension;
  ::ad::physics::Distance valueDimensionLength(-1e9);
  valueDimension.length = valueDimensionLength;
  ::ad::physics::Distance valueDimensionWidth(-1e9);
  valueDimension.width = valueDimensionWidth;
  ::ad::physics::Distance valueDimensionHeight(-1e9);
  valueDimension.height = valueDimensionHeight;
  value.dimension = valueDimension;

  // override member with data type value above input range maximum
  ::ad::physics::Dimension3D invalidInitializedMember;
  ::ad::physics::Distance invalidInitializedMemberLength(1e9 * 1.1);
  invalidInitializedMember.length = invalidInitializedMemberLength;
  value.dimension = invalidInitializedMember;
  ASSERT_FALSE(withinValidInputRange(value));
}
