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

#include "ad/map/route/planning/RoutingDirectionValidInputRange.hpp"

TEST(RoutingDirectionValidInputRangeTests, testValidInputRangeValid)
{
  ASSERT_TRUE(withinValidInputRange(::ad::map::route::planning::RoutingDirection::DONT_CARE));
  ASSERT_TRUE(withinValidInputRange(::ad::map::route::planning::RoutingDirection::POSITIVE));
  ASSERT_TRUE(withinValidInputRange(::ad::map::route::planning::RoutingDirection::NEGATIVE));
}

TEST(RoutingDirectionValidInputRangeTests, testValidInputRangeInvalid)
{
  int32_t minValue = std::numeric_limits<int32_t>::max();

  minValue = std::min(minValue, static_cast<int32_t>(::ad::map::route::planning::RoutingDirection::DONT_CARE));
  minValue = std::min(minValue, static_cast<int32_t>(::ad::map::route::planning::RoutingDirection::POSITIVE));
  minValue = std::min(minValue, static_cast<int32_t>(::ad::map::route::planning::RoutingDirection::NEGATIVE));

  ASSERT_FALSE(withinValidInputRange(static_cast<::ad::map::route::planning::RoutingDirection>(minValue - 1)));
}
