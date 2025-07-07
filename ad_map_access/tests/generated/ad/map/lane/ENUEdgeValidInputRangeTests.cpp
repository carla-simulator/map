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

#include "ad/map/lane/ENUEdgeValidInputRange.hpp"

TEST(ENUEdgeValidInputRangeTests, testValidInputRange)
{
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
  ASSERT_TRUE(withinValidInputRange(value));
}

TEST(ENUEdgeValidInputRangeTests, testValidInputRangeLateral_alignmentTooSmall)
{
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

  // override member with data type value below input range minimum
  ::ad::physics::ParametricValue invalidInitializedMember(0. - ::ad::physics::ParametricValue::cPrecisionValue);
  value.lateral_alignment = invalidInitializedMember;
  ASSERT_FALSE(withinValidInputRange(value));
}

TEST(ENUEdgeValidInputRangeTests, testValidInputRangeLateral_alignmentTooBig)
{
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

  // override member with data type value above input range maximum
  ::ad::physics::ParametricValue invalidInitializedMember(1. * 1.1);
  value.lateral_alignment = invalidInitializedMember;
  ASSERT_FALSE(withinValidInputRange(value));
}

TEST(ENUEdgeValidInputRangeTests, testValidInputRangelateral_alignmentDefault)
{
  ::ad::map::lane::ENUEdge value;
  ::ad::physics::ParametricValue valueDefault;
  value.lateral_alignment = valueDefault;
  ASSERT_FALSE(withinValidInputRange(value));
}

TEST(ENUEdgeValidInputRangeTests, testValidInputRangeEdge_typeTooSmall)
{
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

  // override member with data type value below input range minimum
  ::ad::map::lane::EdgeType invalidInitializedMember(static_cast<::ad::map::lane::EdgeType>(-1));
  value.edge_type = invalidInitializedMember;
  ASSERT_FALSE(withinValidInputRange(value));
}

TEST(ENUEdgeValidInputRangeTests, testValidInputRangeEdge_typeTooBig)
{
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

  // override member with data type value above input range maximum
  ::ad::map::lane::EdgeType invalidInitializedMember(static_cast<::ad::map::lane::EdgeType>(-1));
  value.edge_type = invalidInitializedMember;
  ASSERT_FALSE(withinValidInputRange(value));
}
