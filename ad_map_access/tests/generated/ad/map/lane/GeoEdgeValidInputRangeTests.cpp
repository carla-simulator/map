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

#include "ad/map/lane/GeoEdgeValidInputRange.hpp"

TEST(GeoEdgeValidInputRangeTests, testValidInputRange)
{
  ::ad::map::lane::GeoEdge value;
  ::ad::physics::ParametricValue valueLateral_alignment(0.);
  value.lateral_alignment = valueLateral_alignment;
  ::ad::map::point::GeoPointList valuePoints;
  ::ad::map::point::GeoPoint valuePointsElement;
  ::ad::map::point::Longitude valuePointsElementLongitude(-180);
  valuePointsElement.longitude = valuePointsElementLongitude;
  ::ad::map::point::Latitude valuePointsElementLatitude(-90);
  valuePointsElement.latitude = valuePointsElementLatitude;
  ::ad::map::point::Altitude valuePointsElementAltitude(-11000);
  valuePointsElement.altitude = valuePointsElementAltitude;
  valuePoints.resize(1, valuePointsElement);
  value.points = valuePoints;
  ::ad::map::lane::EdgeType valueEdge_type(::ad::map::lane::EdgeType::UNKNOWN);
  value.edge_type = valueEdge_type;
  ASSERT_TRUE(withinValidInputRange(value));
}

TEST(GeoEdgeValidInputRangeTests, testValidInputRangeLateral_alignmentTooSmall)
{
  ::ad::map::lane::GeoEdge value;
  ::ad::physics::ParametricValue valueLateral_alignment(0.);
  value.lateral_alignment = valueLateral_alignment;
  ::ad::map::point::GeoPointList valuePoints;
  ::ad::map::point::GeoPoint valuePointsElement;
  ::ad::map::point::Longitude valuePointsElementLongitude(-180);
  valuePointsElement.longitude = valuePointsElementLongitude;
  ::ad::map::point::Latitude valuePointsElementLatitude(-90);
  valuePointsElement.latitude = valuePointsElementLatitude;
  ::ad::map::point::Altitude valuePointsElementAltitude(-11000);
  valuePointsElement.altitude = valuePointsElementAltitude;
  valuePoints.resize(1, valuePointsElement);
  value.points = valuePoints;
  ::ad::map::lane::EdgeType valueEdge_type(::ad::map::lane::EdgeType::UNKNOWN);
  value.edge_type = valueEdge_type;

  // override member with data type value below input range minimum
  ::ad::physics::ParametricValue invalidInitializedMember(0. - ::ad::physics::ParametricValue::cPrecisionValue);
  value.lateral_alignment = invalidInitializedMember;
  ASSERT_FALSE(withinValidInputRange(value));
}

TEST(GeoEdgeValidInputRangeTests, testValidInputRangeLateral_alignmentTooBig)
{
  ::ad::map::lane::GeoEdge value;
  ::ad::physics::ParametricValue valueLateral_alignment(0.);
  value.lateral_alignment = valueLateral_alignment;
  ::ad::map::point::GeoPointList valuePoints;
  ::ad::map::point::GeoPoint valuePointsElement;
  ::ad::map::point::Longitude valuePointsElementLongitude(-180);
  valuePointsElement.longitude = valuePointsElementLongitude;
  ::ad::map::point::Latitude valuePointsElementLatitude(-90);
  valuePointsElement.latitude = valuePointsElementLatitude;
  ::ad::map::point::Altitude valuePointsElementAltitude(-11000);
  valuePointsElement.altitude = valuePointsElementAltitude;
  valuePoints.resize(1, valuePointsElement);
  value.points = valuePoints;
  ::ad::map::lane::EdgeType valueEdge_type(::ad::map::lane::EdgeType::UNKNOWN);
  value.edge_type = valueEdge_type;

  // override member with data type value above input range maximum
  ::ad::physics::ParametricValue invalidInitializedMember(1. * 1.1);
  value.lateral_alignment = invalidInitializedMember;
  ASSERT_FALSE(withinValidInputRange(value));
}

TEST(GeoEdgeValidInputRangeTests, testValidInputRangelateral_alignmentDefault)
{
  ::ad::map::lane::GeoEdge value;
  ::ad::physics::ParametricValue valueDefault;
  value.lateral_alignment = valueDefault;
  ASSERT_FALSE(withinValidInputRange(value));
}

TEST(GeoEdgeValidInputRangeTests, testValidInputRangeEdge_typeTooSmall)
{
  ::ad::map::lane::GeoEdge value;
  ::ad::physics::ParametricValue valueLateral_alignment(0.);
  value.lateral_alignment = valueLateral_alignment;
  ::ad::map::point::GeoPointList valuePoints;
  ::ad::map::point::GeoPoint valuePointsElement;
  ::ad::map::point::Longitude valuePointsElementLongitude(-180);
  valuePointsElement.longitude = valuePointsElementLongitude;
  ::ad::map::point::Latitude valuePointsElementLatitude(-90);
  valuePointsElement.latitude = valuePointsElementLatitude;
  ::ad::map::point::Altitude valuePointsElementAltitude(-11000);
  valuePointsElement.altitude = valuePointsElementAltitude;
  valuePoints.resize(1, valuePointsElement);
  value.points = valuePoints;
  ::ad::map::lane::EdgeType valueEdge_type(::ad::map::lane::EdgeType::UNKNOWN);
  value.edge_type = valueEdge_type;

  // override member with data type value below input range minimum
  ::ad::map::lane::EdgeType invalidInitializedMember(static_cast<::ad::map::lane::EdgeType>(-1));
  value.edge_type = invalidInitializedMember;
  ASSERT_FALSE(withinValidInputRange(value));
}

TEST(GeoEdgeValidInputRangeTests, testValidInputRangeEdge_typeTooBig)
{
  ::ad::map::lane::GeoEdge value;
  ::ad::physics::ParametricValue valueLateral_alignment(0.);
  value.lateral_alignment = valueLateral_alignment;
  ::ad::map::point::GeoPointList valuePoints;
  ::ad::map::point::GeoPoint valuePointsElement;
  ::ad::map::point::Longitude valuePointsElementLongitude(-180);
  valuePointsElement.longitude = valuePointsElementLongitude;
  ::ad::map::point::Latitude valuePointsElementLatitude(-90);
  valuePointsElement.latitude = valuePointsElementLatitude;
  ::ad::map::point::Altitude valuePointsElementAltitude(-11000);
  valuePointsElement.altitude = valuePointsElementAltitude;
  valuePoints.resize(1, valuePointsElement);
  value.points = valuePoints;
  ::ad::map::lane::EdgeType valueEdge_type(::ad::map::lane::EdgeType::UNKNOWN);
  value.edge_type = valueEdge_type;

  // override member with data type value above input range maximum
  ::ad::map::lane::EdgeType invalidInitializedMember(static_cast<::ad::map::lane::EdgeType>(-1));
  value.edge_type = invalidInitializedMember;
  ASSERT_FALSE(withinValidInputRange(value));
}
