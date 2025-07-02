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

#include "ad/map/lane/ENUBorderListValidInputRange.hpp"

TEST(ENUBorderListValidInputRangeTests, testValidInputRangeValidInputRangeMin)
{
  ::ad::map::lane::ENUBorderList value;
  ASSERT_TRUE(withinValidInputRange(value));
}

TEST(ENUBorderListValidInputRangeTests, testValidInputRangeElementValid)
{
  ::ad::map::lane::ENUBorderList value;
  ::ad::map::lane::ENUBorder element;
  ::ad::map::lane::ENUEdge elementLeft;
  ::ad::physics::ParametricValue elementLeftLateral_alignment(0.);
  elementLeft.lateral_alignment = elementLeftLateral_alignment;
  ::ad::map::point::ENUPointList elementLeftPoints;
  ::ad::map::point::ENUPoint elementLeftPointsElement;
  ::ad::map::point::ENUCoordinate elementLeftPointsElementX(-1e8);
  elementLeftPointsElement.x = elementLeftPointsElementX;
  ::ad::map::point::ENUCoordinate elementLeftPointsElementY(-1e8);
  elementLeftPointsElement.y = elementLeftPointsElementY;
  ::ad::map::point::ENUCoordinate elementLeftPointsElementZ(-1e8);
  elementLeftPointsElement.z = elementLeftPointsElementZ;
  elementLeftPoints.resize(1, elementLeftPointsElement);
  elementLeft.points = elementLeftPoints;
  ::ad::map::lane::EdgeType elementLeftEdge_type(::ad::map::lane::EdgeType::UNKNOWN);
  elementLeft.edge_type = elementLeftEdge_type;
  element.left = elementLeft;
  ::ad::map::lane::ENUEdge elementRight;
  ::ad::physics::ParametricValue elementRightLateral_alignment(0.);
  elementRight.lateral_alignment = elementRightLateral_alignment;
  ::ad::map::point::ENUPointList elementRightPoints;
  ::ad::map::point::ENUPoint elementRightPointsElement;
  ::ad::map::point::ENUCoordinate elementRightPointsElementX(-1e8);
  elementRightPointsElement.x = elementRightPointsElementX;
  ::ad::map::point::ENUCoordinate elementRightPointsElementY(-1e8);
  elementRightPointsElement.y = elementRightPointsElementY;
  ::ad::map::point::ENUCoordinate elementRightPointsElementZ(-1e8);
  elementRightPointsElement.z = elementRightPointsElementZ;
  elementRightPoints.resize(1, elementRightPointsElement);
  elementRight.points = elementRightPoints;
  ::ad::map::lane::EdgeType elementRightEdge_type(::ad::map::lane::EdgeType::UNKNOWN);
  elementRight.edge_type = elementRightEdge_type;
  element.right = elementRight;
  value.push_back(element);
  ASSERT_TRUE(withinValidInputRange(value));
}

TEST(ENUBorderListValidInputRangeTests, testValidInputRangeElementInvalid)
{
  ::ad::map::lane::ENUBorderList value;
  ::ad::map::lane::ENUBorder element;
  ::ad::map::lane::ENUEdge elementLeft;
  ::ad::physics::ParametricValue elementLeftLateral_alignment(0. - ::ad::physics::ParametricValue::cPrecisionValue);
  elementLeft.lateral_alignment = elementLeftLateral_alignment;
  element.left = elementLeft;
  value.push_back(element);
  ASSERT_FALSE(withinValidInputRange(value));
}
