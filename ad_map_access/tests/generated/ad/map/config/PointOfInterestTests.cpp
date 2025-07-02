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
#include "ad/map/config/PointOfInterest.hpp"

class PointOfInterestTests : public testing::Test
{
protected:
  virtual void SetUp() override
  {
    // valid initialization
    ::ad::map::config::PointOfInterest value;
    ::ad::map::point::GeoPoint valueGeo_point;
    ::ad::map::point::Longitude valueGeo_pointLongitude(-180);
    valueGeo_point.longitude = valueGeo_pointLongitude;
    ::ad::map::point::Latitude valueGeo_pointLatitude(-90);
    valueGeo_point.latitude = valueGeo_pointLatitude;
    ::ad::map::point::Altitude valueGeo_pointAltitude(-11000);
    valueGeo_point.altitude = valueGeo_pointAltitude;
    value.geo_point = valueGeo_point;
    std::string valueName{"min"};
    value.name = valueName;
    mValue = value;
  }

  ::ad::map::config::PointOfInterest mValue;
};

TEST_F(PointOfInterestTests, copyConstruction)
{
  ::ad::map::config::PointOfInterest value(mValue);
  EXPECT_EQ(mValue, value);
}

TEST_F(PointOfInterestTests, moveConstruction)
{
  ::ad::map::config::PointOfInterest tmpValue(mValue);
  ::ad::map::config::PointOfInterest value(std::move(tmpValue));
  EXPECT_EQ(mValue, value);
}

TEST_F(PointOfInterestTests, copyAssignment)
{
  ::ad::map::config::PointOfInterest value;
  value = mValue;
  EXPECT_EQ(mValue, value);
}

TEST_F(PointOfInterestTests, moveAssignment)
{
  ::ad::map::config::PointOfInterest tmpValue(mValue);
  ::ad::map::config::PointOfInterest value;
  value = std::move(tmpValue);
  EXPECT_EQ(mValue, value);
}

TEST_F(PointOfInterestTests, comparisonOperatorEqual)
{
  ::ad::map::config::PointOfInterest valueA = mValue;
  ::ad::map::config::PointOfInterest valueB = mValue;

  EXPECT_TRUE(valueA == valueB);
  EXPECT_FALSE(valueA != valueB);
}

TEST_F(PointOfInterestTests, stringConversionTest)
{
  std::stringstream stream;
  stream << mValue;
  std::string ostreamStr = stream.str();
  std::string toStr = std::to_string(mValue);
  ASSERT_EQ(ostreamStr, toStr);
}

TEST_F(PointOfInterestTests, comparisonOperatorGeo_pointDiffers)
{
  ::ad::map::config::PointOfInterest valueA = mValue;
  ::ad::map::point::GeoPoint geo_point;
  ::ad::map::point::Longitude geo_pointLongitude(180);
  geo_point.longitude = geo_pointLongitude;
  ::ad::map::point::Latitude geo_pointLatitude(90);
  geo_point.latitude = geo_pointLatitude;
  ::ad::map::point::Altitude geo_pointAltitude(9000);
  geo_point.altitude = geo_pointAltitude;
  valueA.geo_point = geo_point;
  ::ad::map::config::PointOfInterest valueB = mValue;

  EXPECT_FALSE(valueA == valueB);
  EXPECT_TRUE(valueA != valueB);
}

TEST_F(PointOfInterestTests, comparisonOperatorNameDiffers)
{
  ::ad::map::config::PointOfInterest valueA = mValue;
  std::string name{"max"};
  valueA.name = name;
  ::ad::map::config::PointOfInterest valueB = mValue;

  EXPECT_FALSE(valueA == valueB);
  EXPECT_TRUE(valueA != valueB);
}

#if defined(__clang__) && (__clang_major__ >= 7)
#pragma GCC diagnostic pop
#endif
