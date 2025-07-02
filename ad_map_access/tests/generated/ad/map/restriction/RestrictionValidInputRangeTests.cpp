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

#include "ad/map/restriction/RestrictionValidInputRange.hpp"

TEST(RestrictionValidInputRangeTests, testValidInputRange)
{
  ::ad::map::restriction::Restriction value;
  bool valueNegated{true};
  value.negated = valueNegated;
  ::ad::map::restriction::RoadUserTypeList valueRoad_user_types;
  ::ad::map::restriction::RoadUserType valueRoad_user_typesElement(::ad::map::restriction::RoadUserType::INVALID);
  valueRoad_user_types.resize(1, valueRoad_user_typesElement);
  value.road_user_types = valueRoad_user_types;
  ::ad::map::restriction::PassengerCount valuePassengers_min(
    std::numeric_limits<::ad::map::restriction::PassengerCount>::lowest());
  value.passengers_min = valuePassengers_min;
  ASSERT_TRUE(withinValidInputRange(value));
}
