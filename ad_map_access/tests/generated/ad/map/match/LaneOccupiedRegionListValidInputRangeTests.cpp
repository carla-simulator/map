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

#include "ad/map/match/LaneOccupiedRegionListValidInputRange.hpp"

TEST(LaneOccupiedRegionListValidInputRangeTests, testValidInputRangeValidInputRangeMin)
{
  ::ad::map::match::LaneOccupiedRegionList value;
  ASSERT_TRUE(withinValidInputRange(value));
}

TEST(LaneOccupiedRegionListValidInputRangeTests, testValidInputRangeElementValid)
{
  ::ad::map::match::LaneOccupiedRegionList value;
  ::ad::map::match::LaneOccupiedRegion element;
  ::ad::map::lane::LaneId elementLane_id(1);
  element.lane_id = elementLane_id;
  ::ad::physics::ParametricRange elementLongitudinal_range;
  ::ad::physics::ParametricValue elementLongitudinal_rangeMinimum(0.);
  elementLongitudinal_range.minimum = elementLongitudinal_rangeMinimum;
  ::ad::physics::ParametricValue elementLongitudinal_rangeMaximum(0.);
  elementLongitudinal_range.maximum = elementLongitudinal_rangeMaximum;
  elementLongitudinal_range.maximum = elementLongitudinal_range.minimum;
  elementLongitudinal_range.minimum = elementLongitudinal_range.maximum;
  element.longitudinal_range = elementLongitudinal_range;
  ::ad::physics::ParametricRange elementLateral_range;
  ::ad::physics::ParametricValue elementLateral_rangeMinimum(0.);
  elementLateral_range.minimum = elementLateral_rangeMinimum;
  ::ad::physics::ParametricValue elementLateral_rangeMaximum(0.);
  elementLateral_range.maximum = elementLateral_rangeMaximum;
  elementLateral_range.maximum = elementLateral_range.minimum;
  elementLateral_range.minimum = elementLateral_range.maximum;
  element.lateral_range = elementLateral_range;
  value.push_back(element);
  ASSERT_TRUE(withinValidInputRange(value));
}

TEST(LaneOccupiedRegionListValidInputRangeTests, testValidInputRangeElementInvalid)
{
  ::ad::map::match::LaneOccupiedRegionList value;
  ::ad::map::match::LaneOccupiedRegion element;
  ::ad::physics::ParametricRange elementLongitudinal_range;
  ::ad::physics::ParametricValue elementLongitudinal_rangeMinimum(0. - ::ad::physics::ParametricValue::cPrecisionValue);
  elementLongitudinal_range.minimum = elementLongitudinal_rangeMinimum;
  element.longitudinal_range = elementLongitudinal_range;
  value.push_back(element);
  ASSERT_FALSE(withinValidInputRange(value));
}
