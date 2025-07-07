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

#include "ad/map/route/planning/RoutingParaPointListValidInputRange.hpp"

TEST(RoutingParaPointListValidInputRangeTests, testValidInputRangeValidInputRangeMin)
{
  ::ad::map::route::planning::RoutingParaPointList value;
  ASSERT_TRUE(withinValidInputRange(value));
}

TEST(RoutingParaPointListValidInputRangeTests, testValidInputRangeElementValid)
{
  ::ad::map::route::planning::RoutingParaPointList value;
  ::ad::map::route::planning::RoutingParaPoint element;
  ::ad::map::point::ParaPoint elementPoint;
  ::ad::map::lane::LaneId elementPointLane_id(1);
  elementPoint.lane_id = elementPointLane_id;
  ::ad::physics::ParametricValue elementPointParametric_offset(0.);
  elementPoint.parametric_offset = elementPointParametric_offset;
  element.point = elementPoint;
  ::ad::map::route::planning::RoutingDirection elementDirection(
    ::ad::map::route::planning::RoutingDirection::DONT_CARE);
  element.direction = elementDirection;
  value.push_back(element);
  ASSERT_TRUE(withinValidInputRange(value));
}

TEST(RoutingParaPointListValidInputRangeTests, testValidInputRangeElementInvalid)
{
  ::ad::map::route::planning::RoutingParaPointList value;
  ::ad::map::route::planning::RoutingParaPoint element;
  ::ad::map::point::ParaPoint elementPoint;
  ::ad::physics::ParametricValue elementPointParametric_offset(0. - ::ad::physics::ParametricValue::cPrecisionValue);
  elementPoint.parametric_offset = elementPointParametric_offset;
  element.point = elementPoint;
  value.push_back(element);
  ASSERT_FALSE(withinValidInputRange(value));
}
