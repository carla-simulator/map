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

#include "ad/map/lane/ECEFBorderValidInputRange.hpp"

TEST(ECEFBorderValidInputRangeTests, testValidInputRange)
{
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
  ASSERT_TRUE(withinValidInputRange(value));
}

TEST(ECEFBorderValidInputRangeTests, testValidInputRangeLeftTooSmall)
{
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

  // override member with data type value below input range minimum
  ::ad::map::lane::ECEFEdge invalidInitializedMember;
  ::ad::map::lane::EdgeType invalidInitializedMemberEdge_type(static_cast<::ad::map::lane::EdgeType>(-1));
  invalidInitializedMember.edge_type = invalidInitializedMemberEdge_type;
  value.left = invalidInitializedMember;
  ASSERT_FALSE(withinValidInputRange(value));
}

TEST(ECEFBorderValidInputRangeTests, testValidInputRangeLeftTooBig)
{
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

  // override member with data type value above input range maximum
  ::ad::map::lane::ECEFEdge invalidInitializedMember;
  ::ad::map::lane::EdgeType invalidInitializedMemberEdge_type(static_cast<::ad::map::lane::EdgeType>(-1));
  invalidInitializedMember.edge_type = invalidInitializedMemberEdge_type;
  value.left = invalidInitializedMember;
  ASSERT_FALSE(withinValidInputRange(value));
}

TEST(ECEFBorderValidInputRangeTests, testValidInputRangeRightTooSmall)
{
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

  // override member with data type value below input range minimum
  ::ad::map::lane::ECEFEdge invalidInitializedMember;
  ::ad::map::lane::EdgeType invalidInitializedMemberEdge_type(static_cast<::ad::map::lane::EdgeType>(-1));
  invalidInitializedMember.edge_type = invalidInitializedMemberEdge_type;
  value.right = invalidInitializedMember;
  ASSERT_FALSE(withinValidInputRange(value));
}

TEST(ECEFBorderValidInputRangeTests, testValidInputRangeRightTooBig)
{
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

  // override member with data type value above input range maximum
  ::ad::map::lane::ECEFEdge invalidInitializedMember;
  ::ad::map::lane::EdgeType invalidInitializedMemberEdge_type(static_cast<::ad::map::lane::EdgeType>(-1));
  invalidInitializedMember.edge_type = invalidInitializedMemberEdge_type;
  value.right = invalidInitializedMember;
  ASSERT_FALSE(withinValidInputRange(value));
}
