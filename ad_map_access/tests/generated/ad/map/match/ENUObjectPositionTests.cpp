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
#include "ad/map/match/ENUObjectPosition.hpp"

class ENUObjectPositionTests : public testing::Test
{
protected:
  virtual void SetUp() override
  {
    // valid initialization
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
    mValue = value;
  }

  ::ad::map::match::ENUObjectPosition mValue;
};

TEST_F(ENUObjectPositionTests, copyConstruction)
{
  ::ad::map::match::ENUObjectPosition value(mValue);
  EXPECT_EQ(mValue, value);
}

TEST_F(ENUObjectPositionTests, moveConstruction)
{
  ::ad::map::match::ENUObjectPosition tmpValue(mValue);
  ::ad::map::match::ENUObjectPosition value(std::move(tmpValue));
  EXPECT_EQ(mValue, value);
}

TEST_F(ENUObjectPositionTests, copyAssignment)
{
  ::ad::map::match::ENUObjectPosition value;
  value = mValue;
  EXPECT_EQ(mValue, value);
}

TEST_F(ENUObjectPositionTests, moveAssignment)
{
  ::ad::map::match::ENUObjectPosition tmpValue(mValue);
  ::ad::map::match::ENUObjectPosition value;
  value = std::move(tmpValue);
  EXPECT_EQ(mValue, value);
}

TEST_F(ENUObjectPositionTests, comparisonOperatorEqual)
{
  ::ad::map::match::ENUObjectPosition valueA = mValue;
  ::ad::map::match::ENUObjectPosition valueB = mValue;

  EXPECT_TRUE(valueA == valueB);
  EXPECT_FALSE(valueA != valueB);
}

TEST_F(ENUObjectPositionTests, stringConversionTest)
{
  std::stringstream stream;
  stream << mValue;
  std::string ostreamStr = stream.str();
  std::string toStr = std::to_string(mValue);
  ASSERT_EQ(ostreamStr, toStr);
}

TEST_F(ENUObjectPositionTests, comparisonOperatorCenter_pointDiffers)
{
  ::ad::map::match::ENUObjectPosition valueA = mValue;
  ::ad::map::point::ENUPoint center_point;
  ::ad::map::point::ENUCoordinate center_pointX(1e8);
  center_point.x = center_pointX;
  ::ad::map::point::ENUCoordinate center_pointY(1e8);
  center_point.y = center_pointY;
  ::ad::map::point::ENUCoordinate center_pointZ(1e8);
  center_point.z = center_pointZ;
  valueA.center_point = center_point;
  ::ad::map::match::ENUObjectPosition valueB = mValue;

  EXPECT_FALSE(valueA == valueB);
  EXPECT_TRUE(valueA != valueB);
}

TEST_F(ENUObjectPositionTests, comparisonOperatorHeadingDiffers)
{
  ::ad::map::match::ENUObjectPosition valueA = mValue;
  ::ad::map::point::ENUHeading heading(3.141592655);
  valueA.heading = heading;
  ::ad::map::match::ENUObjectPosition valueB = mValue;

  EXPECT_FALSE(valueA == valueB);
  EXPECT_TRUE(valueA != valueB);
}

TEST_F(ENUObjectPositionTests, comparisonOperatorEnu_reference_pointDiffers)
{
  ::ad::map::match::ENUObjectPosition valueA = mValue;
  ::ad::map::point::GeoPoint enu_reference_point;
  ::ad::map::point::Longitude enu_reference_pointLongitude(180);
  enu_reference_point.longitude = enu_reference_pointLongitude;
  ::ad::map::point::Latitude enu_reference_pointLatitude(90);
  enu_reference_point.latitude = enu_reference_pointLatitude;
  ::ad::map::point::Altitude enu_reference_pointAltitude(9000);
  enu_reference_point.altitude = enu_reference_pointAltitude;
  valueA.enu_reference_point = enu_reference_point;
  ::ad::map::match::ENUObjectPosition valueB = mValue;

  EXPECT_FALSE(valueA == valueB);
  EXPECT_TRUE(valueA != valueB);
}

TEST_F(ENUObjectPositionTests, comparisonOperatorDimensionDiffers)
{
  ::ad::map::match::ENUObjectPosition valueA = mValue;
  ::ad::physics::Dimension3D dimension;
  ::ad::physics::Distance dimensionLength(1e9);
  dimension.length = dimensionLength;
  ::ad::physics::Distance dimensionWidth(1e9);
  dimension.width = dimensionWidth;
  ::ad::physics::Distance dimensionHeight(1e9);
  dimension.height = dimensionHeight;
  valueA.dimension = dimension;
  ::ad::map::match::ENUObjectPosition valueB = mValue;

  EXPECT_FALSE(valueA == valueB);
  EXPECT_TRUE(valueA != valueB);
}

#if defined(__clang__) && (__clang_major__ >= 7)
#pragma GCC diagnostic pop
#endif
