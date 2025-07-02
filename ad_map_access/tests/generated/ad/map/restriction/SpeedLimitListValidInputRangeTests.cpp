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

#include "ad/map/restriction/SpeedLimitListValidInputRange.hpp"

TEST(SpeedLimitListValidInputRangeTests, testValidInputRangeValidInputRangeMin)
{
  ::ad::map::restriction::SpeedLimitList value;
  ASSERT_TRUE(withinValidInputRange(value));
}

TEST(SpeedLimitListValidInputRangeTests, testValidInputRangeElementValid)
{
  ::ad::map::restriction::SpeedLimitList value;
  ::ad::map::restriction::SpeedLimit element;
  ::ad::physics::Speed elementSpeed_limit(-100.);
  element.speed_limit = elementSpeed_limit;
  ::ad::physics::ParametricRange elementLane_piece;
  ::ad::physics::ParametricValue elementLane_pieceMinimum(0.);
  elementLane_piece.minimum = elementLane_pieceMinimum;
  ::ad::physics::ParametricValue elementLane_pieceMaximum(0.);
  elementLane_piece.maximum = elementLane_pieceMaximum;
  elementLane_piece.maximum = elementLane_piece.minimum;
  elementLane_piece.minimum = elementLane_piece.maximum;
  element.lane_piece = elementLane_piece;
  value.push_back(element);
  ASSERT_TRUE(withinValidInputRange(value));
}

TEST(SpeedLimitListValidInputRangeTests, testValidInputRangeElementInvalid)
{
  ::ad::map::restriction::SpeedLimitList value;
  ::ad::map::restriction::SpeedLimit element;
  ::ad::physics::Speed elementSpeed_limit(-100. * 1.1);
  element.speed_limit = elementSpeed_limit;
  value.push_back(element);
  ASSERT_FALSE(withinValidInputRange(value));
}
