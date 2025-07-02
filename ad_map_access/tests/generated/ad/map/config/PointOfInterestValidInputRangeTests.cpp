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

#include "ad/map/config/PointOfInterestValidInputRange.hpp"

TEST(PointOfInterestValidInputRangeTests, testValidInputRange)
{
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
  ASSERT_TRUE(withinValidInputRange(value));
}

TEST(PointOfInterestValidInputRangeTests, testValidInputRangeGeo_pointTooSmall)
{
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

  // override member with data type value below input range minimum
  ::ad::map::point::GeoPoint invalidInitializedMember;
  ::ad::map::point::Longitude invalidInitializedMemberLongitude(-180 * 1.1);
  invalidInitializedMember.longitude = invalidInitializedMemberLongitude;
  value.geo_point = invalidInitializedMember;
  ASSERT_FALSE(withinValidInputRange(value));
}

TEST(PointOfInterestValidInputRangeTests, testValidInputRangeGeo_pointTooBig)
{
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

  // override member with data type value above input range maximum
  ::ad::map::point::GeoPoint invalidInitializedMember;
  ::ad::map::point::Longitude invalidInitializedMemberLongitude(180 * 1.1);
  invalidInitializedMember.longitude = invalidInitializedMemberLongitude;
  value.geo_point = invalidInitializedMember;
  ASSERT_FALSE(withinValidInputRange(value));
}
