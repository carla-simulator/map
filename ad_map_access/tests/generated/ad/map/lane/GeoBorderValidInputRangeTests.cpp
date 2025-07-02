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

#include "ad/map/lane/GeoBorderValidInputRange.hpp"

TEST(GeoBorderValidInputRangeTests, testValidInputRange)
{
  ::ad::map::lane::GeoBorder value;
  ::ad::map::lane::GeoEdge valueLeft;
  ::ad::physics::ParametricValue valueLeftLateral_alignment(0.);
  valueLeft.lateral_alignment = valueLeftLateral_alignment;
  ::ad::map::point::GeoPointList valueLeftPoints;
  ::ad::map::point::GeoPoint valueLeftPointsElement;
  ::ad::map::point::Longitude valueLeftPointsElementLongitude(-180);
  valueLeftPointsElement.longitude = valueLeftPointsElementLongitude;
  ::ad::map::point::Latitude valueLeftPointsElementLatitude(-90);
  valueLeftPointsElement.latitude = valueLeftPointsElementLatitude;
  ::ad::map::point::Altitude valueLeftPointsElementAltitude(-11000);
  valueLeftPointsElement.altitude = valueLeftPointsElementAltitude;
  valueLeftPoints.resize(1, valueLeftPointsElement);
  valueLeft.points = valueLeftPoints;
  ::ad::map::lane::EdgeType valueLeftEdge_type(::ad::map::lane::EdgeType::UNKNOWN);
  valueLeft.edge_type = valueLeftEdge_type;
  value.left = valueLeft;
  ::ad::map::lane::GeoEdge valueRight;
  ::ad::physics::ParametricValue valueRightLateral_alignment(0.);
  valueRight.lateral_alignment = valueRightLateral_alignment;
  ::ad::map::point::GeoPointList valueRightPoints;
  ::ad::map::point::GeoPoint valueRightPointsElement;
  ::ad::map::point::Longitude valueRightPointsElementLongitude(-180);
  valueRightPointsElement.longitude = valueRightPointsElementLongitude;
  ::ad::map::point::Latitude valueRightPointsElementLatitude(-90);
  valueRightPointsElement.latitude = valueRightPointsElementLatitude;
  ::ad::map::point::Altitude valueRightPointsElementAltitude(-11000);
  valueRightPointsElement.altitude = valueRightPointsElementAltitude;
  valueRightPoints.resize(1, valueRightPointsElement);
  valueRight.points = valueRightPoints;
  ::ad::map::lane::EdgeType valueRightEdge_type(::ad::map::lane::EdgeType::UNKNOWN);
  valueRight.edge_type = valueRightEdge_type;
  value.right = valueRight;
  ASSERT_TRUE(withinValidInputRange(value));
}

TEST(GeoBorderValidInputRangeTests, testValidInputRangeLeftTooSmall)
{
  ::ad::map::lane::GeoBorder value;
  ::ad::map::lane::GeoEdge valueLeft;
  ::ad::physics::ParametricValue valueLeftLateral_alignment(0.);
  valueLeft.lateral_alignment = valueLeftLateral_alignment;
  ::ad::map::point::GeoPointList valueLeftPoints;
  ::ad::map::point::GeoPoint valueLeftPointsElement;
  ::ad::map::point::Longitude valueLeftPointsElementLongitude(-180);
  valueLeftPointsElement.longitude = valueLeftPointsElementLongitude;
  ::ad::map::point::Latitude valueLeftPointsElementLatitude(-90);
  valueLeftPointsElement.latitude = valueLeftPointsElementLatitude;
  ::ad::map::point::Altitude valueLeftPointsElementAltitude(-11000);
  valueLeftPointsElement.altitude = valueLeftPointsElementAltitude;
  valueLeftPoints.resize(1, valueLeftPointsElement);
  valueLeft.points = valueLeftPoints;
  ::ad::map::lane::EdgeType valueLeftEdge_type(::ad::map::lane::EdgeType::UNKNOWN);
  valueLeft.edge_type = valueLeftEdge_type;
  value.left = valueLeft;
  ::ad::map::lane::GeoEdge valueRight;
  ::ad::physics::ParametricValue valueRightLateral_alignment(0.);
  valueRight.lateral_alignment = valueRightLateral_alignment;
  ::ad::map::point::GeoPointList valueRightPoints;
  ::ad::map::point::GeoPoint valueRightPointsElement;
  ::ad::map::point::Longitude valueRightPointsElementLongitude(-180);
  valueRightPointsElement.longitude = valueRightPointsElementLongitude;
  ::ad::map::point::Latitude valueRightPointsElementLatitude(-90);
  valueRightPointsElement.latitude = valueRightPointsElementLatitude;
  ::ad::map::point::Altitude valueRightPointsElementAltitude(-11000);
  valueRightPointsElement.altitude = valueRightPointsElementAltitude;
  valueRightPoints.resize(1, valueRightPointsElement);
  valueRight.points = valueRightPoints;
  ::ad::map::lane::EdgeType valueRightEdge_type(::ad::map::lane::EdgeType::UNKNOWN);
  valueRight.edge_type = valueRightEdge_type;
  value.right = valueRight;

  // override member with data type value below input range minimum
  ::ad::map::lane::GeoEdge invalidInitializedMember;
  ::ad::physics::ParametricValue invalidInitializedMemberLateral_alignment(
    0. - ::ad::physics::ParametricValue::cPrecisionValue);
  invalidInitializedMember.lateral_alignment = invalidInitializedMemberLateral_alignment;
  value.left = invalidInitializedMember;
  ASSERT_FALSE(withinValidInputRange(value));
}

TEST(GeoBorderValidInputRangeTests, testValidInputRangeLeftTooBig)
{
  ::ad::map::lane::GeoBorder value;
  ::ad::map::lane::GeoEdge valueLeft;
  ::ad::physics::ParametricValue valueLeftLateral_alignment(0.);
  valueLeft.lateral_alignment = valueLeftLateral_alignment;
  ::ad::map::point::GeoPointList valueLeftPoints;
  ::ad::map::point::GeoPoint valueLeftPointsElement;
  ::ad::map::point::Longitude valueLeftPointsElementLongitude(-180);
  valueLeftPointsElement.longitude = valueLeftPointsElementLongitude;
  ::ad::map::point::Latitude valueLeftPointsElementLatitude(-90);
  valueLeftPointsElement.latitude = valueLeftPointsElementLatitude;
  ::ad::map::point::Altitude valueLeftPointsElementAltitude(-11000);
  valueLeftPointsElement.altitude = valueLeftPointsElementAltitude;
  valueLeftPoints.resize(1, valueLeftPointsElement);
  valueLeft.points = valueLeftPoints;
  ::ad::map::lane::EdgeType valueLeftEdge_type(::ad::map::lane::EdgeType::UNKNOWN);
  valueLeft.edge_type = valueLeftEdge_type;
  value.left = valueLeft;
  ::ad::map::lane::GeoEdge valueRight;
  ::ad::physics::ParametricValue valueRightLateral_alignment(0.);
  valueRight.lateral_alignment = valueRightLateral_alignment;
  ::ad::map::point::GeoPointList valueRightPoints;
  ::ad::map::point::GeoPoint valueRightPointsElement;
  ::ad::map::point::Longitude valueRightPointsElementLongitude(-180);
  valueRightPointsElement.longitude = valueRightPointsElementLongitude;
  ::ad::map::point::Latitude valueRightPointsElementLatitude(-90);
  valueRightPointsElement.latitude = valueRightPointsElementLatitude;
  ::ad::map::point::Altitude valueRightPointsElementAltitude(-11000);
  valueRightPointsElement.altitude = valueRightPointsElementAltitude;
  valueRightPoints.resize(1, valueRightPointsElement);
  valueRight.points = valueRightPoints;
  ::ad::map::lane::EdgeType valueRightEdge_type(::ad::map::lane::EdgeType::UNKNOWN);
  valueRight.edge_type = valueRightEdge_type;
  value.right = valueRight;

  // override member with data type value above input range maximum
  ::ad::map::lane::GeoEdge invalidInitializedMember;
  ::ad::physics::ParametricValue invalidInitializedMemberLateral_alignment(1. * 1.1);
  invalidInitializedMember.lateral_alignment = invalidInitializedMemberLateral_alignment;
  value.left = invalidInitializedMember;
  ASSERT_FALSE(withinValidInputRange(value));
}

TEST(GeoBorderValidInputRangeTests, testValidInputRangeRightTooSmall)
{
  ::ad::map::lane::GeoBorder value;
  ::ad::map::lane::GeoEdge valueLeft;
  ::ad::physics::ParametricValue valueLeftLateral_alignment(0.);
  valueLeft.lateral_alignment = valueLeftLateral_alignment;
  ::ad::map::point::GeoPointList valueLeftPoints;
  ::ad::map::point::GeoPoint valueLeftPointsElement;
  ::ad::map::point::Longitude valueLeftPointsElementLongitude(-180);
  valueLeftPointsElement.longitude = valueLeftPointsElementLongitude;
  ::ad::map::point::Latitude valueLeftPointsElementLatitude(-90);
  valueLeftPointsElement.latitude = valueLeftPointsElementLatitude;
  ::ad::map::point::Altitude valueLeftPointsElementAltitude(-11000);
  valueLeftPointsElement.altitude = valueLeftPointsElementAltitude;
  valueLeftPoints.resize(1, valueLeftPointsElement);
  valueLeft.points = valueLeftPoints;
  ::ad::map::lane::EdgeType valueLeftEdge_type(::ad::map::lane::EdgeType::UNKNOWN);
  valueLeft.edge_type = valueLeftEdge_type;
  value.left = valueLeft;
  ::ad::map::lane::GeoEdge valueRight;
  ::ad::physics::ParametricValue valueRightLateral_alignment(0.);
  valueRight.lateral_alignment = valueRightLateral_alignment;
  ::ad::map::point::GeoPointList valueRightPoints;
  ::ad::map::point::GeoPoint valueRightPointsElement;
  ::ad::map::point::Longitude valueRightPointsElementLongitude(-180);
  valueRightPointsElement.longitude = valueRightPointsElementLongitude;
  ::ad::map::point::Latitude valueRightPointsElementLatitude(-90);
  valueRightPointsElement.latitude = valueRightPointsElementLatitude;
  ::ad::map::point::Altitude valueRightPointsElementAltitude(-11000);
  valueRightPointsElement.altitude = valueRightPointsElementAltitude;
  valueRightPoints.resize(1, valueRightPointsElement);
  valueRight.points = valueRightPoints;
  ::ad::map::lane::EdgeType valueRightEdge_type(::ad::map::lane::EdgeType::UNKNOWN);
  valueRight.edge_type = valueRightEdge_type;
  value.right = valueRight;

  // override member with data type value below input range minimum
  ::ad::map::lane::GeoEdge invalidInitializedMember;
  ::ad::physics::ParametricValue invalidInitializedMemberLateral_alignment(
    0. - ::ad::physics::ParametricValue::cPrecisionValue);
  invalidInitializedMember.lateral_alignment = invalidInitializedMemberLateral_alignment;
  value.right = invalidInitializedMember;
  ASSERT_FALSE(withinValidInputRange(value));
}

TEST(GeoBorderValidInputRangeTests, testValidInputRangeRightTooBig)
{
  ::ad::map::lane::GeoBorder value;
  ::ad::map::lane::GeoEdge valueLeft;
  ::ad::physics::ParametricValue valueLeftLateral_alignment(0.);
  valueLeft.lateral_alignment = valueLeftLateral_alignment;
  ::ad::map::point::GeoPointList valueLeftPoints;
  ::ad::map::point::GeoPoint valueLeftPointsElement;
  ::ad::map::point::Longitude valueLeftPointsElementLongitude(-180);
  valueLeftPointsElement.longitude = valueLeftPointsElementLongitude;
  ::ad::map::point::Latitude valueLeftPointsElementLatitude(-90);
  valueLeftPointsElement.latitude = valueLeftPointsElementLatitude;
  ::ad::map::point::Altitude valueLeftPointsElementAltitude(-11000);
  valueLeftPointsElement.altitude = valueLeftPointsElementAltitude;
  valueLeftPoints.resize(1, valueLeftPointsElement);
  valueLeft.points = valueLeftPoints;
  ::ad::map::lane::EdgeType valueLeftEdge_type(::ad::map::lane::EdgeType::UNKNOWN);
  valueLeft.edge_type = valueLeftEdge_type;
  value.left = valueLeft;
  ::ad::map::lane::GeoEdge valueRight;
  ::ad::physics::ParametricValue valueRightLateral_alignment(0.);
  valueRight.lateral_alignment = valueRightLateral_alignment;
  ::ad::map::point::GeoPointList valueRightPoints;
  ::ad::map::point::GeoPoint valueRightPointsElement;
  ::ad::map::point::Longitude valueRightPointsElementLongitude(-180);
  valueRightPointsElement.longitude = valueRightPointsElementLongitude;
  ::ad::map::point::Latitude valueRightPointsElementLatitude(-90);
  valueRightPointsElement.latitude = valueRightPointsElementLatitude;
  ::ad::map::point::Altitude valueRightPointsElementAltitude(-11000);
  valueRightPointsElement.altitude = valueRightPointsElementAltitude;
  valueRightPoints.resize(1, valueRightPointsElement);
  valueRight.points = valueRightPoints;
  ::ad::map::lane::EdgeType valueRightEdge_type(::ad::map::lane::EdgeType::UNKNOWN);
  valueRight.edge_type = valueRightEdge_type;
  value.right = valueRight;

  // override member with data type value above input range maximum
  ::ad::map::lane::GeoEdge invalidInitializedMember;
  ::ad::physics::ParametricValue invalidInitializedMemberLateral_alignment(1. * 1.1);
  invalidInitializedMember.lateral_alignment = invalidInitializedMemberLateral_alignment;
  value.right = invalidInitializedMember;
  ASSERT_FALSE(withinValidInputRange(value));
}
