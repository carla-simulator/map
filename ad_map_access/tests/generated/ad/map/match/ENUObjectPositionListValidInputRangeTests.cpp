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

#include "ad/map/match/ENUObjectPositionListValidInputRange.hpp"

TEST(ENUObjectPositionListValidInputRangeTests, testValidInputRangeLowerThanInputRangeMin)
{
  ::ad::map::match::ENUObjectPositionList value;
  ASSERT_FALSE(withinValidInputRange(value));
}

TEST(ENUObjectPositionListValidInputRangeTests, testValidInputRangeValidInputRangeMin)
{
  ::ad::map::match::ENUObjectPositionList value;
  ::ad::map::match::ENUObjectPosition element;
  ::ad::map::point::ENUPoint elementCenter_point;
  ::ad::map::point::ENUCoordinate elementCenter_pointX(-1e8);
  elementCenter_point.x = elementCenter_pointX;
  ::ad::map::point::ENUCoordinate elementCenter_pointY(-1e8);
  elementCenter_point.y = elementCenter_pointY;
  ::ad::map::point::ENUCoordinate elementCenter_pointZ(-1e8);
  elementCenter_point.z = elementCenter_pointZ;
  element.center_point = elementCenter_point;
  ::ad::map::point::ENUHeading elementHeading(-3.141592655);
  element.heading = elementHeading;
  ::ad::map::point::GeoPoint elementEnu_reference_point;
  ::ad::map::point::Longitude elementEnu_reference_pointLongitude(-180);
  elementEnu_reference_point.longitude = elementEnu_reference_pointLongitude;
  ::ad::map::point::Latitude elementEnu_reference_pointLatitude(-90);
  elementEnu_reference_point.latitude = elementEnu_reference_pointLatitude;
  ::ad::map::point::Altitude elementEnu_reference_pointAltitude(-11000);
  elementEnu_reference_point.altitude = elementEnu_reference_pointAltitude;
  element.enu_reference_point = elementEnu_reference_point;
  ::ad::physics::Dimension3D elementDimension;
  ::ad::physics::Distance elementDimensionLength(-1e9);
  elementDimension.length = elementDimensionLength;
  ::ad::physics::Distance elementDimensionWidth(-1e9);
  elementDimension.width = elementDimensionWidth;
  ::ad::physics::Distance elementDimensionHeight(-1e9);
  elementDimension.height = elementDimensionHeight;
  element.dimension = elementDimension;
  value.resize(1, element);
  ASSERT_TRUE(withinValidInputRange(value));
}

TEST(ENUObjectPositionListValidInputRangeTests, testValidInputRangeElementTypeInvalid)
{
  ::ad::map::match::ENUObjectPositionList value;
  ::ad::map::match::ENUObjectPosition element;
  ::ad::map::point::ENUPoint elementCenter_point;
  ::ad::map::point::ENUCoordinate elementCenter_pointX(-1e8 * 1.1);
  elementCenter_point.x = elementCenter_pointX;
  element.center_point = elementCenter_point;
  value.resize(1, element);
  ASSERT_FALSE(withinValidInputRange(value));
}

TEST(ENUObjectPositionListValidInputRangeTests, testValidInputRangeElementValid)
{
  ::ad::map::match::ENUObjectPositionList value;
  ::ad::map::match::ENUObjectPosition element;
  ::ad::map::point::ENUPoint elementCenter_point;
  ::ad::map::point::ENUCoordinate elementCenter_pointX(-1e8);
  elementCenter_point.x = elementCenter_pointX;
  ::ad::map::point::ENUCoordinate elementCenter_pointY(-1e8);
  elementCenter_point.y = elementCenter_pointY;
  ::ad::map::point::ENUCoordinate elementCenter_pointZ(-1e8);
  elementCenter_point.z = elementCenter_pointZ;
  element.center_point = elementCenter_point;
  ::ad::map::point::ENUHeading elementHeading(-3.141592655);
  element.heading = elementHeading;
  ::ad::map::point::GeoPoint elementEnu_reference_point;
  ::ad::map::point::Longitude elementEnu_reference_pointLongitude(-180);
  elementEnu_reference_point.longitude = elementEnu_reference_pointLongitude;
  ::ad::map::point::Latitude elementEnu_reference_pointLatitude(-90);
  elementEnu_reference_point.latitude = elementEnu_reference_pointLatitude;
  ::ad::map::point::Altitude elementEnu_reference_pointAltitude(-11000);
  elementEnu_reference_point.altitude = elementEnu_reference_pointAltitude;
  element.enu_reference_point = elementEnu_reference_point;
  ::ad::physics::Dimension3D elementDimension;
  ::ad::physics::Distance elementDimensionLength(-1e9);
  elementDimension.length = elementDimensionLength;
  ::ad::physics::Distance elementDimensionWidth(-1e9);
  elementDimension.width = elementDimensionWidth;
  ::ad::physics::Distance elementDimensionHeight(-1e9);
  elementDimension.height = elementDimensionHeight;
  element.dimension = elementDimension;
  value.push_back(element);
  ASSERT_TRUE(withinValidInputRange(value));
}

TEST(ENUObjectPositionListValidInputRangeTests, testValidInputRangeElementInvalid)
{
  ::ad::map::match::ENUObjectPositionList value;
  ::ad::map::match::ENUObjectPosition element;
  ::ad::map::point::ENUPoint elementCenter_point;
  ::ad::map::point::ENUCoordinate elementCenter_pointX(-1e8 * 1.1);
  elementCenter_point.x = elementCenter_pointX;
  element.center_point = elementCenter_point;
  value.push_back(element);
  ASSERT_FALSE(withinValidInputRange(value));
}
