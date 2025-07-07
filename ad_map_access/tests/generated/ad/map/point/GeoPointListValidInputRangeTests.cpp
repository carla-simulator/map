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

#include "ad/map/point/GeoPointListValidInputRange.hpp"

TEST(GeoPointListValidInputRangeTests, testValidInputRangeValidInputRangeMin)
{
  ::ad::map::point::GeoPointList value;
  ASSERT_TRUE(withinValidInputRange(value));
}

TEST(GeoPointListValidInputRangeTests, testValidInputRangeElementValid)
{
  ::ad::map::point::GeoPointList value;
  ::ad::map::point::GeoPoint element;
  ::ad::map::point::Longitude elementLongitude(-180);
  element.longitude = elementLongitude;
  ::ad::map::point::Latitude elementLatitude(-90);
  element.latitude = elementLatitude;
  ::ad::map::point::Altitude elementAltitude(-11000);
  element.altitude = elementAltitude;
  value.push_back(element);
  ASSERT_TRUE(withinValidInputRange(value));
}

TEST(GeoPointListValidInputRangeTests, testValidInputRangeElementInvalid)
{
  ::ad::map::point::GeoPointList value;
  ::ad::map::point::GeoPoint element;
  ::ad::map::point::Longitude elementLongitude(-180 * 1.1);
  element.longitude = elementLongitude;
  value.push_back(element);
  ASSERT_FALSE(withinValidInputRange(value));
}
