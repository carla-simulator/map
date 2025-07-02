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

#include "ad/map/lane/GeoBorderListValidInputRange.hpp"

TEST(GeoBorderListValidInputRangeTests, testValidInputRangeValidInputRangeMin)
{
  ::ad::map::lane::GeoBorderList value;
  ASSERT_TRUE(withinValidInputRange(value));
}

TEST(GeoBorderListValidInputRangeTests, testValidInputRangeElementValid)
{
  ::ad::map::lane::GeoBorderList value;
  ::ad::map::lane::GeoBorder element;
  ::ad::map::lane::GeoEdge elementLeft;
  ::ad::physics::ParametricValue elementLeftLateral_alignment(0.);
  elementLeft.lateral_alignment = elementLeftLateral_alignment;
  ::ad::map::point::GeoPointList elementLeftPoints;
  ::ad::map::point::GeoPoint elementLeftPointsElement;
  ::ad::map::point::Longitude elementLeftPointsElementLongitude(-180);
  elementLeftPointsElement.longitude = elementLeftPointsElementLongitude;
  ::ad::map::point::Latitude elementLeftPointsElementLatitude(-90);
  elementLeftPointsElement.latitude = elementLeftPointsElementLatitude;
  ::ad::map::point::Altitude elementLeftPointsElementAltitude(-11000);
  elementLeftPointsElement.altitude = elementLeftPointsElementAltitude;
  elementLeftPoints.resize(1, elementLeftPointsElement);
  elementLeft.points = elementLeftPoints;
  ::ad::map::lane::EdgeType elementLeftEdge_type(::ad::map::lane::EdgeType::UNKNOWN);
  elementLeft.edge_type = elementLeftEdge_type;
  element.left = elementLeft;
  ::ad::map::lane::GeoEdge elementRight;
  ::ad::physics::ParametricValue elementRightLateral_alignment(0.);
  elementRight.lateral_alignment = elementRightLateral_alignment;
  ::ad::map::point::GeoPointList elementRightPoints;
  ::ad::map::point::GeoPoint elementRightPointsElement;
  ::ad::map::point::Longitude elementRightPointsElementLongitude(-180);
  elementRightPointsElement.longitude = elementRightPointsElementLongitude;
  ::ad::map::point::Latitude elementRightPointsElementLatitude(-90);
  elementRightPointsElement.latitude = elementRightPointsElementLatitude;
  ::ad::map::point::Altitude elementRightPointsElementAltitude(-11000);
  elementRightPointsElement.altitude = elementRightPointsElementAltitude;
  elementRightPoints.resize(1, elementRightPointsElement);
  elementRight.points = elementRightPoints;
  ::ad::map::lane::EdgeType elementRightEdge_type(::ad::map::lane::EdgeType::UNKNOWN);
  elementRight.edge_type = elementRightEdge_type;
  element.right = elementRight;
  value.push_back(element);
  ASSERT_TRUE(withinValidInputRange(value));
}

TEST(GeoBorderListValidInputRangeTests, testValidInputRangeElementInvalid)
{
  ::ad::map::lane::GeoBorderList value;
  ::ad::map::lane::GeoBorder element;
  ::ad::map::lane::GeoEdge elementLeft;
  ::ad::physics::ParametricValue elementLeftLateral_alignment(0. - ::ad::physics::ParametricValue::cPrecisionValue);
  elementLeft.lateral_alignment = elementLeftLateral_alignment;
  element.left = elementLeft;
  value.push_back(element);
  ASSERT_FALSE(withinValidInputRange(value));
}
