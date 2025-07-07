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
#include "ad/map/lane/GeoBorder.hpp"

class GeoBorderTests : public testing::Test
{
protected:
  virtual void SetUp() override
  {
    // valid initialization
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
    mValue = value;
  }

  ::ad::map::lane::GeoBorder mValue;
};

TEST_F(GeoBorderTests, copyConstruction)
{
  ::ad::map::lane::GeoBorder value(mValue);
  EXPECT_EQ(mValue, value);
}

TEST_F(GeoBorderTests, moveConstruction)
{
  ::ad::map::lane::GeoBorder tmpValue(mValue);
  ::ad::map::lane::GeoBorder value(std::move(tmpValue));
  EXPECT_EQ(mValue, value);
}

TEST_F(GeoBorderTests, copyAssignment)
{
  ::ad::map::lane::GeoBorder value;
  value = mValue;
  EXPECT_EQ(mValue, value);
}

TEST_F(GeoBorderTests, moveAssignment)
{
  ::ad::map::lane::GeoBorder tmpValue(mValue);
  ::ad::map::lane::GeoBorder value;
  value = std::move(tmpValue);
  EXPECT_EQ(mValue, value);
}

TEST_F(GeoBorderTests, comparisonOperatorEqual)
{
  ::ad::map::lane::GeoBorder valueA = mValue;
  ::ad::map::lane::GeoBorder valueB = mValue;

  EXPECT_TRUE(valueA == valueB);
  EXPECT_FALSE(valueA != valueB);
}

TEST_F(GeoBorderTests, stringConversionTest)
{
  std::stringstream stream;
  stream << mValue;
  std::string ostreamStr = stream.str();
  std::string toStr = std::to_string(mValue);
  ASSERT_EQ(ostreamStr, toStr);
}

TEST_F(GeoBorderTests, comparisonOperatorLeftDiffers)
{
  ::ad::map::lane::GeoBorder valueA = mValue;
  ::ad::map::lane::GeoEdge left;
  ::ad::physics::ParametricValue leftLateral_alignment(1.);
  left.lateral_alignment = leftLateral_alignment;
  ::ad::map::point::GeoPointList leftPoints;
  ::ad::map::point::GeoPoint leftPointsElement;
  ::ad::map::point::Longitude leftPointsElementLongitude(180);
  leftPointsElement.longitude = leftPointsElementLongitude;
  ::ad::map::point::Latitude leftPointsElementLatitude(90);
  leftPointsElement.latitude = leftPointsElementLatitude;
  ::ad::map::point::Altitude leftPointsElementAltitude(9000);
  leftPointsElement.altitude = leftPointsElementAltitude;
  leftPoints.resize(2, leftPointsElement);
  left.points = leftPoints;
  ::ad::map::lane::EdgeType leftEdge_type(::ad::map::lane::EdgeType::RIGHT);
  left.edge_type = leftEdge_type;
  valueA.left = left;
  ::ad::map::lane::GeoBorder valueB = mValue;

  EXPECT_FALSE(valueA == valueB);
  EXPECT_TRUE(valueA != valueB);
}

TEST_F(GeoBorderTests, comparisonOperatorRightDiffers)
{
  ::ad::map::lane::GeoBorder valueA = mValue;
  ::ad::map::lane::GeoEdge right;
  ::ad::physics::ParametricValue rightLateral_alignment(1.);
  right.lateral_alignment = rightLateral_alignment;
  ::ad::map::point::GeoPointList rightPoints;
  ::ad::map::point::GeoPoint rightPointsElement;
  ::ad::map::point::Longitude rightPointsElementLongitude(180);
  rightPointsElement.longitude = rightPointsElementLongitude;
  ::ad::map::point::Latitude rightPointsElementLatitude(90);
  rightPointsElement.latitude = rightPointsElementLatitude;
  ::ad::map::point::Altitude rightPointsElementAltitude(9000);
  rightPointsElement.altitude = rightPointsElementAltitude;
  rightPoints.resize(2, rightPointsElement);
  right.points = rightPoints;
  ::ad::map::lane::EdgeType rightEdge_type(::ad::map::lane::EdgeType::RIGHT);
  right.edge_type = rightEdge_type;
  valueA.right = right;
  ::ad::map::lane::GeoBorder valueB = mValue;

  EXPECT_FALSE(valueA == valueB);
  EXPECT_TRUE(valueA != valueB);
}

#if defined(__clang__) && (__clang_major__ >= 7)
#pragma GCC diagnostic pop
#endif
