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

#include "ad/map/restriction/RestrictionsValidInputRange.hpp"

TEST(RestrictionsValidInputRangeTests, testValidInputRange)
{
  ::ad::map::restriction::Restrictions value;
  ::ad::map::restriction::RestrictionList valueConjunctions;
  ::ad::map::restriction::Restriction valueConjunctionsElement;
  bool valueConjunctionsElementNegated{true};
  valueConjunctionsElement.negated = valueConjunctionsElementNegated;
  ::ad::map::restriction::RoadUserTypeList valueConjunctionsElementRoad_user_types;
  ::ad::map::restriction::RoadUserType valueConjunctionsElementRoad_user_typesElement(
    ::ad::map::restriction::RoadUserType::INVALID);
  valueConjunctionsElementRoad_user_types.resize(1, valueConjunctionsElementRoad_user_typesElement);
  valueConjunctionsElement.road_user_types = valueConjunctionsElementRoad_user_types;
  ::ad::map::restriction::PassengerCount valueConjunctionsElementPassengers_min(
    std::numeric_limits<::ad::map::restriction::PassengerCount>::lowest());
  valueConjunctionsElement.passengers_min = valueConjunctionsElementPassengers_min;
  valueConjunctions.resize(1, valueConjunctionsElement);
  value.conjunctions = valueConjunctions;
  ::ad::map::restriction::RestrictionList valueDisjunctions;
  ::ad::map::restriction::Restriction valueDisjunctionsElement;
  bool valueDisjunctionsElementNegated{true};
  valueDisjunctionsElement.negated = valueDisjunctionsElementNegated;
  ::ad::map::restriction::RoadUserTypeList valueDisjunctionsElementRoad_user_types;
  ::ad::map::restriction::RoadUserType valueDisjunctionsElementRoad_user_typesElement(
    ::ad::map::restriction::RoadUserType::INVALID);
  valueDisjunctionsElementRoad_user_types.resize(1, valueDisjunctionsElementRoad_user_typesElement);
  valueDisjunctionsElement.road_user_types = valueDisjunctionsElementRoad_user_types;
  ::ad::map::restriction::PassengerCount valueDisjunctionsElementPassengers_min(
    std::numeric_limits<::ad::map::restriction::PassengerCount>::lowest());
  valueDisjunctionsElement.passengers_min = valueDisjunctionsElementPassengers_min;
  valueDisjunctions.resize(1, valueDisjunctionsElement);
  value.disjunctions = valueDisjunctions;
  ASSERT_TRUE(withinValidInputRange(value));
}
