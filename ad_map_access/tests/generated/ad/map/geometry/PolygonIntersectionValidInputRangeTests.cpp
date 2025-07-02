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

#include "ad/map/geometry/PolygonIntersectionValidInputRange.hpp"

TEST(PolygonIntersectionValidInputRangeTests, testValidInputRange)
{
  ::ad::map::geometry::PolygonIntersection value;
  ::ad::map::point::ENUPointListVector valueIntersection_lines;
  ::ad::map::point::ENUPointList valueIntersection_linesElement;
  ::ad::map::point::ENUPoint valueIntersection_linesElementElement;
  ::ad::map::point::ENUCoordinate valueIntersection_linesElementElementX(-1e8);
  valueIntersection_linesElementElement.x = valueIntersection_linesElementElementX;
  ::ad::map::point::ENUCoordinate valueIntersection_linesElementElementY(-1e8);
  valueIntersection_linesElementElement.y = valueIntersection_linesElementElementY;
  ::ad::map::point::ENUCoordinate valueIntersection_linesElementElementZ(-1e8);
  valueIntersection_linesElementElement.z = valueIntersection_linesElementElementZ;
  valueIntersection_linesElement.resize(1, valueIntersection_linesElementElement);
  valueIntersection_lines.resize(1, valueIntersection_linesElement);
  value.intersection_lines = valueIntersection_lines;
  bool valueIs_within{true};
  value.is_within = valueIs_within;
  ASSERT_TRUE(withinValidInputRange(value));
}
