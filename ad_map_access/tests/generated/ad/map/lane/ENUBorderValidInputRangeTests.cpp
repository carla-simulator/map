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

#include "ad/map/lane/ENUBorderValidInputRange.hpp"

TEST(ENUBorderValidInputRangeTests, testValidInputRange)
{
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
  ASSERT_TRUE(withinValidInputRange(value));
}

TEST(ENUBorderValidInputRangeTests, testValidInputRangeLeftTooSmall)
{
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

  // override member with data type value below input range minimum
  ::ad::map::lane::ENUEdge invalidInitializedMember;
  ::ad::physics::ParametricValue invalidInitializedMemberLateral_alignment(
    0. - ::ad::physics::ParametricValue::cPrecisionValue);
  invalidInitializedMember.lateral_alignment = invalidInitializedMemberLateral_alignment;
  value.left = invalidInitializedMember;
  ASSERT_FALSE(withinValidInputRange(value));
}

TEST(ENUBorderValidInputRangeTests, testValidInputRangeLeftTooBig)
{
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

  // override member with data type value above input range maximum
  ::ad::map::lane::ENUEdge invalidInitializedMember;
  ::ad::physics::ParametricValue invalidInitializedMemberLateral_alignment(1. * 1.1);
  invalidInitializedMember.lateral_alignment = invalidInitializedMemberLateral_alignment;
  value.left = invalidInitializedMember;
  ASSERT_FALSE(withinValidInputRange(value));
}

TEST(ENUBorderValidInputRangeTests, testValidInputRangeRightTooSmall)
{
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

  // override member with data type value below input range minimum
  ::ad::map::lane::ENUEdge invalidInitializedMember;
  ::ad::physics::ParametricValue invalidInitializedMemberLateral_alignment(
    0. - ::ad::physics::ParametricValue::cPrecisionValue);
  invalidInitializedMember.lateral_alignment = invalidInitializedMemberLateral_alignment;
  value.right = invalidInitializedMember;
  ASSERT_FALSE(withinValidInputRange(value));
}

TEST(ENUBorderValidInputRangeTests, testValidInputRangeRightTooBig)
{
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

  // override member with data type value above input range maximum
  ::ad::map::lane::ENUEdge invalidInitializedMember;
  ::ad::physics::ParametricValue invalidInitializedMemberLateral_alignment(1. * 1.1);
  invalidInitializedMember.lateral_alignment = invalidInitializedMemberLateral_alignment;
  value.right = invalidInitializedMember;
  ASSERT_FALSE(withinValidInputRange(value));
}
