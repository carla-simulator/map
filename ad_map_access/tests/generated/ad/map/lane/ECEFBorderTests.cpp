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
#include "ad/map/lane/ECEFBorder.hpp"

class ECEFBorderTests : public testing::Test
{
protected:
  virtual void SetUp() override
  {
    // valid initialization
    ::ad::map::lane::ECEFBorder value;
    ::ad::map::lane::ECEFEdge valueLeft;
    ::ad::map::point::ECEFPointList valueLeftPoints;
    ::ad::map::point::ECEFPoint valueLeftPointsElement;
    ::ad::map::point::ECEFCoordinate valueLeftPointsElementX(-6400000);
    valueLeftPointsElement.x = valueLeftPointsElementX;
    ::ad::map::point::ECEFCoordinate valueLeftPointsElementY(-6400000);
    valueLeftPointsElement.y = valueLeftPointsElementY;
    ::ad::map::point::ECEFCoordinate valueLeftPointsElementZ(-6400000);
    valueLeftPointsElement.z = valueLeftPointsElementZ;
    valueLeftPoints.resize(1, valueLeftPointsElement);
    valueLeft.points = valueLeftPoints;
    ::ad::map::lane::EdgeType valueLeftEdge_type(::ad::map::lane::EdgeType::UNKNOWN);
    valueLeft.edge_type = valueLeftEdge_type;
    ::ad::physics::ParametricValue valueLeftLateral_alignment(0.);
    valueLeft.lateral_alignment = valueLeftLateral_alignment;
    value.left = valueLeft;
    ::ad::map::lane::ECEFEdge valueRight;
    ::ad::map::point::ECEFPointList valueRightPoints;
    ::ad::map::point::ECEFPoint valueRightPointsElement;
    ::ad::map::point::ECEFCoordinate valueRightPointsElementX(-6400000);
    valueRightPointsElement.x = valueRightPointsElementX;
    ::ad::map::point::ECEFCoordinate valueRightPointsElementY(-6400000);
    valueRightPointsElement.y = valueRightPointsElementY;
    ::ad::map::point::ECEFCoordinate valueRightPointsElementZ(-6400000);
    valueRightPointsElement.z = valueRightPointsElementZ;
    valueRightPoints.resize(1, valueRightPointsElement);
    valueRight.points = valueRightPoints;
    ::ad::map::lane::EdgeType valueRightEdge_type(::ad::map::lane::EdgeType::UNKNOWN);
    valueRight.edge_type = valueRightEdge_type;
    ::ad::physics::ParametricValue valueRightLateral_alignment(0.);
    valueRight.lateral_alignment = valueRightLateral_alignment;
    value.right = valueRight;
    mValue = value;
  }

  ::ad::map::lane::ECEFBorder mValue;
};

TEST_F(ECEFBorderTests, copyConstruction)
{
  ::ad::map::lane::ECEFBorder value(mValue);
  EXPECT_EQ(mValue, value);
}

TEST_F(ECEFBorderTests, moveConstruction)
{
  ::ad::map::lane::ECEFBorder tmpValue(mValue);
  ::ad::map::lane::ECEFBorder value(std::move(tmpValue));
  EXPECT_EQ(mValue, value);
}

TEST_F(ECEFBorderTests, copyAssignment)
{
  ::ad::map::lane::ECEFBorder value;
  value = mValue;
  EXPECT_EQ(mValue, value);
}

TEST_F(ECEFBorderTests, moveAssignment)
{
  ::ad::map::lane::ECEFBorder tmpValue(mValue);
  ::ad::map::lane::ECEFBorder value;
  value = std::move(tmpValue);
  EXPECT_EQ(mValue, value);
}

TEST_F(ECEFBorderTests, comparisonOperatorEqual)
{
  ::ad::map::lane::ECEFBorder valueA = mValue;
  ::ad::map::lane::ECEFBorder valueB = mValue;

  EXPECT_TRUE(valueA == valueB);
  EXPECT_FALSE(valueA != valueB);
}

TEST_F(ECEFBorderTests, stringConversionTest)
{
  std::stringstream stream;
  stream << mValue;
  std::string ostreamStr = stream.str();
  std::string toStr = std::to_string(mValue);
  ASSERT_EQ(ostreamStr, toStr);
}

TEST_F(ECEFBorderTests, comparisonOperatorLeftDiffers)
{
  ::ad::map::lane::ECEFBorder valueA = mValue;
  ::ad::map::lane::ECEFEdge left;
  ::ad::map::point::ECEFPointList leftPoints;
  ::ad::map::point::ECEFPoint leftPointsElement;
  ::ad::map::point::ECEFCoordinate leftPointsElementX(6400000);
  leftPointsElement.x = leftPointsElementX;
  ::ad::map::point::ECEFCoordinate leftPointsElementY(6400000);
  leftPointsElement.y = leftPointsElementY;
  ::ad::map::point::ECEFCoordinate leftPointsElementZ(6400000);
  leftPointsElement.z = leftPointsElementZ;
  leftPoints.resize(2, leftPointsElement);
  left.points = leftPoints;
  ::ad::map::lane::EdgeType leftEdge_type(::ad::map::lane::EdgeType::RIGHT);
  left.edge_type = leftEdge_type;
  ::ad::physics::ParametricValue leftLateral_alignment(1.);
  left.lateral_alignment = leftLateral_alignment;
  valueA.left = left;
  ::ad::map::lane::ECEFBorder valueB = mValue;

  EXPECT_FALSE(valueA == valueB);
  EXPECT_TRUE(valueA != valueB);
}

TEST_F(ECEFBorderTests, comparisonOperatorRightDiffers)
{
  ::ad::map::lane::ECEFBorder valueA = mValue;
  ::ad::map::lane::ECEFEdge right;
  ::ad::map::point::ECEFPointList rightPoints;
  ::ad::map::point::ECEFPoint rightPointsElement;
  ::ad::map::point::ECEFCoordinate rightPointsElementX(6400000);
  rightPointsElement.x = rightPointsElementX;
  ::ad::map::point::ECEFCoordinate rightPointsElementY(6400000);
  rightPointsElement.y = rightPointsElementY;
  ::ad::map::point::ECEFCoordinate rightPointsElementZ(6400000);
  rightPointsElement.z = rightPointsElementZ;
  rightPoints.resize(2, rightPointsElement);
  right.points = rightPoints;
  ::ad::map::lane::EdgeType rightEdge_type(::ad::map::lane::EdgeType::RIGHT);
  right.edge_type = rightEdge_type;
  ::ad::physics::ParametricValue rightLateral_alignment(1.);
  right.lateral_alignment = rightLateral_alignment;
  valueA.right = right;
  ::ad::map::lane::ECEFBorder valueB = mValue;

  EXPECT_FALSE(valueA == valueB);
  EXPECT_TRUE(valueA != valueB);
}

#if defined(__clang__) && (__clang_major__ >= 7)
#pragma GCC diagnostic pop
#endif
