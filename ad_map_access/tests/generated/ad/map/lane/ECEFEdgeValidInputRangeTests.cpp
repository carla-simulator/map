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

#include "ad/map/lane/ECEFEdgeValidInputRange.hpp"

TEST(ECEFEdgeValidInputRangeTests, testValidInputRange)
{
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
  ASSERT_TRUE(withinValidInputRange(value));
}

TEST(ECEFEdgeValidInputRangeTests, testValidInputRangeEdge_typeTooSmall)
{
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

  // override member with data type value below input range minimum
  ::ad::map::lane::EdgeType invalidInitializedMember(static_cast<::ad::map::lane::EdgeType>(-1));
  value.edge_type = invalidInitializedMember;
  ASSERT_FALSE(withinValidInputRange(value));
}

TEST(ECEFEdgeValidInputRangeTests, testValidInputRangeEdge_typeTooBig)
{
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

  // override member with data type value above input range maximum
  ::ad::map::lane::EdgeType invalidInitializedMember(static_cast<::ad::map::lane::EdgeType>(-1));
  value.edge_type = invalidInitializedMember;
  ASSERT_FALSE(withinValidInputRange(value));
}

TEST(ECEFEdgeValidInputRangeTests, testValidInputRangeLateral_alignmentTooSmall)
{
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

  // override member with data type value below input range minimum
  ::ad::physics::ParametricValue invalidInitializedMember(0. - ::ad::physics::ParametricValue::cPrecisionValue);
  value.lateral_alignment = invalidInitializedMember;
  ASSERT_FALSE(withinValidInputRange(value));
}

TEST(ECEFEdgeValidInputRangeTests, testValidInputRangeLateral_alignmentTooBig)
{
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

  // override member with data type value above input range maximum
  ::ad::physics::ParametricValue invalidInitializedMember(1. * 1.1);
  value.lateral_alignment = invalidInitializedMember;
  ASSERT_FALSE(withinValidInputRange(value));
}

TEST(ECEFEdgeValidInputRangeTests, testValidInputRangelateral_alignmentDefault)
{
  ::ad::map::lane::ECEFEdge value;
  ::ad::physics::ParametricValue valueDefault;
  value.lateral_alignment = valueDefault;
  ASSERT_FALSE(withinValidInputRange(value));
}
