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
#include "ad/map/lane/ENUBorder.hpp"

class ENUBorderTests : public testing::Test
{
protected:
  virtual void SetUp() override
  {
    // valid initialization
    ::ad::map::lane::ENUBorder value;
    ::ad::map::lane::ENUEdge valueLeft;
    ::ad::physics::ParametricValue valueLeftLateral_alignment(0.);
    valueLeft.lateral_alignment = valueLeftLateral_alignment;
    ::ad::map::point::ENUPointList valueLeftPoints;
    ::ad::map::point::ENUPoint valueLeftPointsElement;
    ::ad::map::point::ENUCoordinate valueLeftPointsElementX(-1e8);
    valueLeftPointsElement.x = valueLeftPointsElementX;
    ::ad::map::point::ENUCoordinate valueLeftPointsElementY(-1e8);
    valueLeftPointsElement.y = valueLeftPointsElementY;
    ::ad::map::point::ENUCoordinate valueLeftPointsElementZ(-1e8);
    valueLeftPointsElement.z = valueLeftPointsElementZ;
    valueLeftPoints.resize(1, valueLeftPointsElement);
    valueLeft.points = valueLeftPoints;
    ::ad::map::lane::EdgeType valueLeftEdge_type(::ad::map::lane::EdgeType::UNKNOWN);
    valueLeft.edge_type = valueLeftEdge_type;
    value.left = valueLeft;
    ::ad::map::lane::ENUEdge valueRight;
    ::ad::physics::ParametricValue valueRightLateral_alignment(0.);
    valueRight.lateral_alignment = valueRightLateral_alignment;
    ::ad::map::point::ENUPointList valueRightPoints;
    ::ad::map::point::ENUPoint valueRightPointsElement;
    ::ad::map::point::ENUCoordinate valueRightPointsElementX(-1e8);
    valueRightPointsElement.x = valueRightPointsElementX;
    ::ad::map::point::ENUCoordinate valueRightPointsElementY(-1e8);
    valueRightPointsElement.y = valueRightPointsElementY;
    ::ad::map::point::ENUCoordinate valueRightPointsElementZ(-1e8);
    valueRightPointsElement.z = valueRightPointsElementZ;
    valueRightPoints.resize(1, valueRightPointsElement);
    valueRight.points = valueRightPoints;
    ::ad::map::lane::EdgeType valueRightEdge_type(::ad::map::lane::EdgeType::UNKNOWN);
    valueRight.edge_type = valueRightEdge_type;
    value.right = valueRight;
    mValue = value;
  }

  ::ad::map::lane::ENUBorder mValue;
};

TEST_F(ENUBorderTests, copyConstruction)
{
  ::ad::map::lane::ENUBorder value(mValue);
  EXPECT_EQ(mValue, value);
}

TEST_F(ENUBorderTests, moveConstruction)
{
  ::ad::map::lane::ENUBorder tmpValue(mValue);
  ::ad::map::lane::ENUBorder value(std::move(tmpValue));
  EXPECT_EQ(mValue, value);
}

TEST_F(ENUBorderTests, copyAssignment)
{
  ::ad::map::lane::ENUBorder value;
  value = mValue;
  EXPECT_EQ(mValue, value);
}

TEST_F(ENUBorderTests, moveAssignment)
{
  ::ad::map::lane::ENUBorder tmpValue(mValue);
  ::ad::map::lane::ENUBorder value;
  value = std::move(tmpValue);
  EXPECT_EQ(mValue, value);
}

TEST_F(ENUBorderTests, comparisonOperatorEqual)
{
  ::ad::map::lane::ENUBorder valueA = mValue;
  ::ad::map::lane::ENUBorder valueB = mValue;

  EXPECT_TRUE(valueA == valueB);
  EXPECT_FALSE(valueA != valueB);
}

TEST_F(ENUBorderTests, stringConversionTest)
{
  std::stringstream stream;
  stream << mValue;
  std::string ostreamStr = stream.str();
  std::string toStr = std::to_string(mValue);
  ASSERT_EQ(ostreamStr, toStr);
}

TEST_F(ENUBorderTests, comparisonOperatorLeftDiffers)
{
  ::ad::map::lane::ENUBorder valueA = mValue;
  ::ad::map::lane::ENUEdge left;
  ::ad::physics::ParametricValue leftLateral_alignment(1.);
  left.lateral_alignment = leftLateral_alignment;
  ::ad::map::point::ENUPointList leftPoints;
  ::ad::map::point::ENUPoint leftPointsElement;
  ::ad::map::point::ENUCoordinate leftPointsElementX(1e8);
  leftPointsElement.x = leftPointsElementX;
  ::ad::map::point::ENUCoordinate leftPointsElementY(1e8);
  leftPointsElement.y = leftPointsElementY;
  ::ad::map::point::ENUCoordinate leftPointsElementZ(1e8);
  leftPointsElement.z = leftPointsElementZ;
  leftPoints.resize(2, leftPointsElement);
  left.points = leftPoints;
  ::ad::map::lane::EdgeType leftEdge_type(::ad::map::lane::EdgeType::RIGHT);
  left.edge_type = leftEdge_type;
  valueA.left = left;
  ::ad::map::lane::ENUBorder valueB = mValue;

  EXPECT_FALSE(valueA == valueB);
  EXPECT_TRUE(valueA != valueB);
}

TEST_F(ENUBorderTests, comparisonOperatorRightDiffers)
{
  ::ad::map::lane::ENUBorder valueA = mValue;
  ::ad::map::lane::ENUEdge right;
  ::ad::physics::ParametricValue rightLateral_alignment(1.);
  right.lateral_alignment = rightLateral_alignment;
  ::ad::map::point::ENUPointList rightPoints;
  ::ad::map::point::ENUPoint rightPointsElement;
  ::ad::map::point::ENUCoordinate rightPointsElementX(1e8);
  rightPointsElement.x = rightPointsElementX;
  ::ad::map::point::ENUCoordinate rightPointsElementY(1e8);
  rightPointsElement.y = rightPointsElementY;
  ::ad::map::point::ENUCoordinate rightPointsElementZ(1e8);
  rightPointsElement.z = rightPointsElementZ;
  rightPoints.resize(2, rightPointsElement);
  right.points = rightPoints;
  ::ad::map::lane::EdgeType rightEdge_type(::ad::map::lane::EdgeType::RIGHT);
  right.edge_type = rightEdge_type;
  valueA.right = right;
  ::ad::map::lane::ENUBorder valueB = mValue;

  EXPECT_FALSE(valueA == valueB);
  EXPECT_TRUE(valueA != valueB);
}

#if defined(__clang__) && (__clang_major__ >= 7)
#pragma GCC diagnostic pop
#endif
