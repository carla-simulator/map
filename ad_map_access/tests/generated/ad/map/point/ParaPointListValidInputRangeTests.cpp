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

#include "ad/map/point/ParaPointListValidInputRange.hpp"

TEST(ParaPointListValidInputRangeTests, testValidInputRangeValidInputRangeMin)
{
  ::ad::map::point::ParaPointList value;
  ASSERT_TRUE(withinValidInputRange(value));
}

TEST(ParaPointListValidInputRangeTests, testValidInputRangeElementValid)
{
  ::ad::map::point::ParaPointList value;
  ::ad::map::point::ParaPoint element;
  ::ad::map::lane::LaneId elementLane_id(1);
  element.lane_id = elementLane_id;
  ::ad::physics::ParametricValue elementParametric_offset(0.);
  element.parametric_offset = elementParametric_offset;
  value.push_back(element);
  ASSERT_TRUE(withinValidInputRange(value));
}

TEST(ParaPointListValidInputRangeTests, testValidInputRangeElementInvalid)
{
  ::ad::map::point::ParaPointList value;
  ::ad::map::point::ParaPoint element;
  ::ad::physics::ParametricValue elementParametric_offset(0. - ::ad::physics::ParametricValue::cPrecisionValue);
  element.parametric_offset = elementParametric_offset;
  value.push_back(element);
  ASSERT_FALSE(withinValidInputRange(value));
}
