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

#include "ad/map/config/PointOfInterestListValidInputRange.hpp"

TEST(PointOfInterestListValidInputRangeTests, testValidInputRangeValidInputRangeMin)
{
  ::ad::map::config::PointOfInterestList value;
  ASSERT_TRUE(withinValidInputRange(value));
}

TEST(PointOfInterestListValidInputRangeTests, testValidInputRangeElementValid)
{
  ::ad::map::config::PointOfInterestList value;
  ::ad::map::config::PointOfInterest element;
  ::ad::map::point::GeoPoint elementGeo_point;
  ::ad::map::point::Longitude elementGeo_pointLongitude(-180);
  elementGeo_point.longitude = elementGeo_pointLongitude;
  ::ad::map::point::Latitude elementGeo_pointLatitude(-90);
  elementGeo_point.latitude = elementGeo_pointLatitude;
  ::ad::map::point::Altitude elementGeo_pointAltitude(-11000);
  elementGeo_point.altitude = elementGeo_pointAltitude;
  element.geo_point = elementGeo_point;
  std::string elementName{"min"};
  element.name = elementName;
  value.push_back(element);
  ASSERT_TRUE(withinValidInputRange(value));
}

TEST(PointOfInterestListValidInputRangeTests, testValidInputRangeElementInvalid)
{
  ::ad::map::config::PointOfInterestList value;
  ::ad::map::config::PointOfInterest element;
  ::ad::map::point::GeoPoint elementGeo_point;
  ::ad::map::point::Longitude elementGeo_pointLongitude(-180 * 1.1);
  elementGeo_point.longitude = elementGeo_pointLongitude;
  element.geo_point = elementGeo_point;
  value.push_back(element);
  ASSERT_FALSE(withinValidInputRange(value));
}
