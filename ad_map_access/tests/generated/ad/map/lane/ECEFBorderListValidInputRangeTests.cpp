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

#include "ad/map/lane/ECEFBorderListValidInputRange.hpp"

TEST(ECEFBorderListValidInputRangeTests, testValidInputRangeValidInputRangeMin)
{
  ::ad::map::lane::ECEFBorderList value;
  ASSERT_TRUE(withinValidInputRange(value));
}

TEST(ECEFBorderListValidInputRangeTests, testValidInputRangeElementValid)
{
  ::ad::map::lane::ECEFBorderList value;
  ::ad::map::lane::ECEFBorder element;
  ::ad::map::lane::ECEFEdge elementLeft;
  ::ad::map::point::ECEFPointList elementLeftPoints;
  ::ad::map::point::ECEFPoint elementLeftPointsElement;
  ::ad::map::point::ECEFCoordinate elementLeftPointsElementX(-6400000);
  elementLeftPointsElement.x = elementLeftPointsElementX;
  ::ad::map::point::ECEFCoordinate elementLeftPointsElementY(-6400000);
  elementLeftPointsElement.y = elementLeftPointsElementY;
  ::ad::map::point::ECEFCoordinate elementLeftPointsElementZ(-6400000);
  elementLeftPointsElement.z = elementLeftPointsElementZ;
  elementLeftPoints.resize(1, elementLeftPointsElement);
  elementLeft.points = elementLeftPoints;
  ::ad::map::lane::EdgeType elementLeftEdge_type(::ad::map::lane::EdgeType::UNKNOWN);
  elementLeft.edge_type = elementLeftEdge_type;
  ::ad::physics::ParametricValue elementLeftLateral_alignment(0.);
  elementLeft.lateral_alignment = elementLeftLateral_alignment;
  element.left = elementLeft;
  ::ad::map::lane::ECEFEdge elementRight;
  ::ad::map::point::ECEFPointList elementRightPoints;
  ::ad::map::point::ECEFPoint elementRightPointsElement;
  ::ad::map::point::ECEFCoordinate elementRightPointsElementX(-6400000);
  elementRightPointsElement.x = elementRightPointsElementX;
  ::ad::map::point::ECEFCoordinate elementRightPointsElementY(-6400000);
  elementRightPointsElement.y = elementRightPointsElementY;
  ::ad::map::point::ECEFCoordinate elementRightPointsElementZ(-6400000);
  elementRightPointsElement.z = elementRightPointsElementZ;
  elementRightPoints.resize(1, elementRightPointsElement);
  elementRight.points = elementRightPoints;
  ::ad::map::lane::EdgeType elementRightEdge_type(::ad::map::lane::EdgeType::UNKNOWN);
  elementRight.edge_type = elementRightEdge_type;
  ::ad::physics::ParametricValue elementRightLateral_alignment(0.);
  elementRight.lateral_alignment = elementRightLateral_alignment;
  element.right = elementRight;
  value.push_back(element);
  ASSERT_TRUE(withinValidInputRange(value));
}

TEST(ECEFBorderListValidInputRangeTests, testValidInputRangeElementInvalid)
{
  ::ad::map::lane::ECEFBorderList value;
  ::ad::map::lane::ECEFBorder element;
  ::ad::map::lane::ECEFEdge elementLeft;
  ::ad::map::lane::EdgeType elementLeftEdge_type(static_cast<::ad::map::lane::EdgeType>(-1));
  elementLeft.edge_type = elementLeftEdge_type;
  element.left = elementLeft;
  value.push_back(element);
  ASSERT_FALSE(withinValidInputRange(value));
}
