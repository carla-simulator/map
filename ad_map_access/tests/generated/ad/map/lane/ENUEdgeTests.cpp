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
#include "ad/map/lane/ENUEdge.hpp"

class ENUEdgeTests : public testing::Test
{
protected:
  virtual void SetUp() override
  {
    // valid initialization
    ::ad::map::lane::ENUEdge value;
    ::ad::physics::ParametricValue valueLateral_alignment(0.);
    value.lateral_alignment = valueLateral_alignment;
    ::ad::map::point::ENUPointList valuePoints;
    ::ad::map::point::ENUPoint valuePointsElement;
    ::ad::map::point::ENUCoordinate valuePointsElementX(-1e8);
    valuePointsElement.x = valuePointsElementX;
    ::ad::map::point::ENUCoordinate valuePointsElementY(-1e8);
    valuePointsElement.y = valuePointsElementY;
    ::ad::map::point::ENUCoordinate valuePointsElementZ(-1e8);
    valuePointsElement.z = valuePointsElementZ;
    valuePoints.resize(1, valuePointsElement);
    value.points = valuePoints;
    ::ad::map::lane::EdgeType valueEdge_type(::ad::map::lane::EdgeType::UNKNOWN);
    value.edge_type = valueEdge_type;
    mValue = value;
  }

  ::ad::map::lane::ENUEdge mValue;
};

TEST_F(ENUEdgeTests, copyConstruction)
{
  ::ad::map::lane::ENUEdge value(mValue);
  EXPECT_EQ(mValue, value);
}

TEST_F(ENUEdgeTests, moveConstruction)
{
  ::ad::map::lane::ENUEdge tmpValue(mValue);
  ::ad::map::lane::ENUEdge value(std::move(tmpValue));
  EXPECT_EQ(mValue, value);
}

TEST_F(ENUEdgeTests, copyAssignment)
{
  ::ad::map::lane::ENUEdge value;
  value = mValue;
  EXPECT_EQ(mValue, value);
}

TEST_F(ENUEdgeTests, moveAssignment)
{
  ::ad::map::lane::ENUEdge tmpValue(mValue);
  ::ad::map::lane::ENUEdge value;
  value = std::move(tmpValue);
  EXPECT_EQ(mValue, value);
}

TEST_F(ENUEdgeTests, comparisonOperatorEqual)
{
  ::ad::map::lane::ENUEdge valueA = mValue;
  ::ad::map::lane::ENUEdge valueB = mValue;

  EXPECT_TRUE(valueA == valueB);
  EXPECT_FALSE(valueA != valueB);
}

TEST_F(ENUEdgeTests, stringConversionTest)
{
  std::stringstream stream;
  stream << mValue;
  std::string ostreamStr = stream.str();
  std::string toStr = std::to_string(mValue);
  ASSERT_EQ(ostreamStr, toStr);
}

TEST_F(ENUEdgeTests, comparisonOperatorLateral_alignmentDiffers)
{
  ::ad::map::lane::ENUEdge valueA = mValue;
  ::ad::physics::ParametricValue lateral_alignment(1.);
  valueA.lateral_alignment = lateral_alignment;
  ::ad::map::lane::ENUEdge valueB = mValue;

  EXPECT_FALSE(valueA == valueB);
  EXPECT_TRUE(valueA != valueB);
}

TEST_F(ENUEdgeTests, comparisonOperatorPointsDiffers)
{
  ::ad::map::lane::ENUEdge valueA = mValue;
  ::ad::map::point::ENUPointList points;
  ::ad::map::point::ENUPoint pointsElement;
  ::ad::map::point::ENUCoordinate pointsElementX(1e8);
  pointsElement.x = pointsElementX;
  ::ad::map::point::ENUCoordinate pointsElementY(1e8);
  pointsElement.y = pointsElementY;
  ::ad::map::point::ENUCoordinate pointsElementZ(1e8);
  pointsElement.z = pointsElementZ;
  points.resize(2, pointsElement);
  valueA.points = points;
  ::ad::map::lane::ENUEdge valueB = mValue;

  EXPECT_FALSE(valueA == valueB);
  EXPECT_TRUE(valueA != valueB);
}

TEST_F(ENUEdgeTests, comparisonOperatorEdge_typeDiffers)
{
  ::ad::map::lane::ENUEdge valueA = mValue;
  ::ad::map::lane::EdgeType edge_type(::ad::map::lane::EdgeType::RIGHT);
  valueA.edge_type = edge_type;
  ::ad::map::lane::ENUEdge valueB = mValue;

  EXPECT_FALSE(valueA == valueB);
  EXPECT_TRUE(valueA != valueB);
}

#if defined(__clang__) && (__clang_major__ >= 7)
#pragma GCC diagnostic pop
#endif
