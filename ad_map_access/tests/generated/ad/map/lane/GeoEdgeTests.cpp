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
#include "ad/map/lane/GeoEdge.hpp"

class GeoEdgeTests : public testing::Test
{
protected:
  virtual void SetUp() override
  {
    // valid initialization
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
    mValue = value;
  }

  ::ad::map::lane::GeoEdge mValue;
};

TEST_F(GeoEdgeTests, copyConstruction)
{
  ::ad::map::lane::GeoEdge value(mValue);
  EXPECT_EQ(mValue, value);
}

TEST_F(GeoEdgeTests, moveConstruction)
{
  ::ad::map::lane::GeoEdge tmpValue(mValue);
  ::ad::map::lane::GeoEdge value(std::move(tmpValue));
  EXPECT_EQ(mValue, value);
}

TEST_F(GeoEdgeTests, copyAssignment)
{
  ::ad::map::lane::GeoEdge value;
  value = mValue;
  EXPECT_EQ(mValue, value);
}

TEST_F(GeoEdgeTests, moveAssignment)
{
  ::ad::map::lane::GeoEdge tmpValue(mValue);
  ::ad::map::lane::GeoEdge value;
  value = std::move(tmpValue);
  EXPECT_EQ(mValue, value);
}

TEST_F(GeoEdgeTests, comparisonOperatorEqual)
{
  ::ad::map::lane::GeoEdge valueA = mValue;
  ::ad::map::lane::GeoEdge valueB = mValue;

  EXPECT_TRUE(valueA == valueB);
  EXPECT_FALSE(valueA != valueB);
}

TEST_F(GeoEdgeTests, stringConversionTest)
{
  std::stringstream stream;
  stream << mValue;
  std::string ostreamStr = stream.str();
  std::string toStr = std::to_string(mValue);
  ASSERT_EQ(ostreamStr, toStr);
}

TEST_F(GeoEdgeTests, comparisonOperatorLateral_alignmentDiffers)
{
  ::ad::map::lane::GeoEdge valueA = mValue;
  ::ad::physics::ParametricValue lateral_alignment(1.);
  valueA.lateral_alignment = lateral_alignment;
  ::ad::map::lane::GeoEdge valueB = mValue;

  EXPECT_FALSE(valueA == valueB);
  EXPECT_TRUE(valueA != valueB);
}

TEST_F(GeoEdgeTests, comparisonOperatorPointsDiffers)
{
  ::ad::map::lane::GeoEdge valueA = mValue;
  ::ad::map::point::GeoPointList points;
  ::ad::map::point::GeoPoint pointsElement;
  ::ad::map::point::Longitude pointsElementLongitude(180);
  pointsElement.longitude = pointsElementLongitude;
  ::ad::map::point::Latitude pointsElementLatitude(90);
  pointsElement.latitude = pointsElementLatitude;
  ::ad::map::point::Altitude pointsElementAltitude(9000);
  pointsElement.altitude = pointsElementAltitude;
  points.resize(2, pointsElement);
  valueA.points = points;
  ::ad::map::lane::GeoEdge valueB = mValue;

  EXPECT_FALSE(valueA == valueB);
  EXPECT_TRUE(valueA != valueB);
}

TEST_F(GeoEdgeTests, comparisonOperatorEdge_typeDiffers)
{
  ::ad::map::lane::GeoEdge valueA = mValue;
  ::ad::map::lane::EdgeType edge_type(::ad::map::lane::EdgeType::RIGHT);
  valueA.edge_type = edge_type;
  ::ad::map::lane::GeoEdge valueB = mValue;

  EXPECT_FALSE(valueA == valueB);
  EXPECT_TRUE(valueA != valueB);
}

#if defined(__clang__) && (__clang_major__ >= 7)
#pragma GCC diagnostic pop
#endif
