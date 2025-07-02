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

#include "ad/map/restriction/RestrictionListValidInputRange.hpp"

TEST(RestrictionListValidInputRangeTests, testValidInputRangeValidInputRangeMin)
{
  ::ad::map::restriction::RestrictionList value;
  ASSERT_TRUE(withinValidInputRange(value));
}

TEST(RestrictionListValidInputRangeTests, testValidInputRangeElementValid)
{
  ::ad::map::restriction::RestrictionList value;
  ::ad::map::restriction::Restriction element;
  bool elementNegated{true};
  element.negated = elementNegated;
  ::ad::map::restriction::RoadUserTypeList elementRoad_user_types;
  ::ad::map::restriction::RoadUserType elementRoad_user_typesElement(::ad::map::restriction::RoadUserType::INVALID);
  elementRoad_user_types.resize(1, elementRoad_user_typesElement);
  element.road_user_types = elementRoad_user_types;
  ::ad::map::restriction::PassengerCount elementPassengers_min(
    std::numeric_limits<::ad::map::restriction::PassengerCount>::lowest());
  element.passengers_min = elementPassengers_min;
  value.push_back(element);
  ASSERT_TRUE(withinValidInputRange(value));
}
