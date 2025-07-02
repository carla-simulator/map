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
#include "ad/map/lane/ECEFEdge.hpp"

class ECEFEdgeTests : public testing::Test
{
protected:
  virtual void SetUp() override
  {
    // valid initialization
    ::ad::map::lane::ECEFEdge value;
    ::ad::map::point::ECEFPointList valuePoints;
    ::ad::map::point::ECEFPoint valuePointsElement;
    ::ad::map::point::ECEFCoordinate valuePointsElementX(-6400000);
    valuePointsElement.x = valuePointsElementX;
    ::ad::map::point::ECEFCoordinate valuePointsElementY(-6400000);
    valuePointsElement.y = valuePointsElementY;
    ::ad::map::point::ECEFCoordinate valuePointsElementZ(-6400000);
    valuePointsElement.z = valuePointsElementZ;
    valuePoints.resize(1, valuePointsElement);
    value.points = valuePoints;
    ::ad::map::lane::EdgeType valueEdge_type(::ad::map::lane::EdgeType::UNKNOWN);
    value.edge_type = valueEdge_type;
    ::ad::physics::ParametricValue valueLateral_alignment(0.);
    value.lateral_alignment = valueLateral_alignment;
    mValue = value;
  }

  ::ad::map::lane::ECEFEdge mValue;
};

TEST_F(ECEFEdgeTests, copyConstruction)
{
  ::ad::map::lane::ECEFEdge value(mValue);
  EXPECT_EQ(mValue, value);
}

TEST_F(ECEFEdgeTests, moveConstruction)
{
  ::ad::map::lane::ECEFEdge tmpValue(mValue);
  ::ad::map::lane::ECEFEdge value(std::move(tmpValue));
  EXPECT_EQ(mValue, value);
}

TEST_F(ECEFEdgeTests, copyAssignment)
{
  ::ad::map::lane::ECEFEdge value;
  value = mValue;
  EXPECT_EQ(mValue, value);
}

TEST_F(ECEFEdgeTests, moveAssignment)
{
  ::ad::map::lane::ECEFEdge tmpValue(mValue);
  ::ad::map::lane::ECEFEdge value;
  value = std::move(tmpValue);
  EXPECT_EQ(mValue, value);
}

TEST_F(ECEFEdgeTests, comparisonOperatorEqual)
{
  ::ad::map::lane::ECEFEdge valueA = mValue;
  ::ad::map::lane::ECEFEdge valueB = mValue;

  EXPECT_TRUE(valueA == valueB);
  EXPECT_FALSE(valueA != valueB);
}

TEST_F(ECEFEdgeTests, stringConversionTest)
{
  std::stringstream stream;
  stream << mValue;
  std::string ostreamStr = stream.str();
  std::string toStr = std::to_string(mValue);
  ASSERT_EQ(ostreamStr, toStr);
}

TEST_F(ECEFEdgeTests, comparisonOperatorPointsDiffers)
{
  ::ad::map::lane::ECEFEdge valueA = mValue;
  ::ad::map::point::ECEFPointList points;
  ::ad::map::point::ECEFPoint pointsElement;
  ::ad::map::point::ECEFCoordinate pointsElementX(6400000);
  pointsElement.x = pointsElementX;
  ::ad::map::point::ECEFCoordinate pointsElementY(6400000);
  pointsElement.y = pointsElementY;
  ::ad::map::point::ECEFCoordinate pointsElementZ(6400000);
  pointsElement.z = pointsElementZ;
  points.resize(2, pointsElement);
  valueA.points = points;
  ::ad::map::lane::ECEFEdge valueB = mValue;

  EXPECT_FALSE(valueA == valueB);
  EXPECT_TRUE(valueA != valueB);
}

TEST_F(ECEFEdgeTests, comparisonOperatorEdge_typeDiffers)
{
  ::ad::map::lane::ECEFEdge valueA = mValue;
  ::ad::map::lane::EdgeType edge_type(::ad::map::lane::EdgeType::RIGHT);
  valueA.edge_type = edge_type;
  ::ad::map::lane::ECEFEdge valueB = mValue;

  EXPECT_FALSE(valueA == valueB);
  EXPECT_TRUE(valueA != valueB);
}

TEST_F(ECEFEdgeTests, comparisonOperatorLateral_alignmentDiffers)
{
  ::ad::map::lane::ECEFEdge valueA = mValue;
  ::ad::physics::ParametricValue lateral_alignment(1.);
  valueA.lateral_alignment = lateral_alignment;
  ::ad::map::lane::ECEFEdge valueB = mValue;

  EXPECT_FALSE(valueA == valueB);
  EXPECT_TRUE(valueA != valueB);
}

#if defined(__clang__) && (__clang_major__ >= 7)
#pragma GCC diagnostic pop
#endif
