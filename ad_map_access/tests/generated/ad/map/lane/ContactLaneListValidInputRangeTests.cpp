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

#include "ad/map/lane/ContactLaneListValidInputRange.hpp"

TEST(ContactLaneListValidInputRangeTests, testValidInputRangeValidInputRangeMin)
{
  ::ad::map::lane::ContactLaneList value;
  ASSERT_TRUE(withinValidInputRange(value));
}

TEST(ContactLaneListValidInputRangeTests, testValidInputRangeElementValid)
{
  ::ad::map::lane::ContactLaneList value;
  ::ad::map::lane::ContactLane element;
  ::ad::map::lane::LaneId elementTo_lane(1);
  element.to_lane = elementTo_lane;
  ::ad::map::lane::ContactLocation elementLocation(::ad::map::lane::ContactLocation::INVALID);
  element.location = elementLocation;
  ::ad::map::lane::ContactTypeList elementTypes;
  ::ad::map::lane::ContactType elementTypesElement(::ad::map::lane::ContactType::INVALID);
  elementTypes.resize(1, elementTypesElement);
  element.types = elementTypes;
  ::ad::map::restriction::Restrictions elementRestrictions;
  ::ad::map::restriction::RestrictionList elementRestrictionsConjunctions;
  ::ad::map::restriction::Restriction elementRestrictionsConjunctionsElement;
  bool elementRestrictionsConjunctionsElementNegated{true};
  elementRestrictionsConjunctionsElement.negated = elementRestrictionsConjunctionsElementNegated;
  ::ad::map::restriction::RoadUserTypeList elementRestrictionsConjunctionsElementRoad_user_types;
  ::ad::map::restriction::RoadUserType elementRestrictionsConjunctionsElementRoad_user_typesElement(
    ::ad::map::restriction::RoadUserType::INVALID);
  elementRestrictionsConjunctionsElementRoad_user_types.resize(
    1, elementRestrictionsConjunctionsElementRoad_user_typesElement);
  elementRestrictionsConjunctionsElement.road_user_types = elementRestrictionsConjunctionsElementRoad_user_types;
  ::ad::map::restriction::PassengerCount elementRestrictionsConjunctionsElementPassengers_min(
    std::numeric_limits<::ad::map::restriction::PassengerCount>::lowest());
  elementRestrictionsConjunctionsElement.passengers_min = elementRestrictionsConjunctionsElementPassengers_min;
  elementRestrictionsConjunctions.resize(1, elementRestrictionsConjunctionsElement);
  elementRestrictions.conjunctions = elementRestrictionsConjunctions;
  ::ad::map::restriction::RestrictionList elementRestrictionsDisjunctions;
  ::ad::map::restriction::Restriction elementRestrictionsDisjunctionsElement;
  bool elementRestrictionsDisjunctionsElementNegated{true};
  elementRestrictionsDisjunctionsElement.negated = elementRestrictionsDisjunctionsElementNegated;
  ::ad::map::restriction::RoadUserTypeList elementRestrictionsDisjunctionsElementRoad_user_types;
  ::ad::map::restriction::RoadUserType elementRestrictionsDisjunctionsElementRoad_user_typesElement(
    ::ad::map::restriction::RoadUserType::INVALID);
  elementRestrictionsDisjunctionsElementRoad_user_types.resize(
    1, elementRestrictionsDisjunctionsElementRoad_user_typesElement);
  elementRestrictionsDisjunctionsElement.road_user_types = elementRestrictionsDisjunctionsElementRoad_user_types;
  ::ad::map::restriction::PassengerCount elementRestrictionsDisjunctionsElementPassengers_min(
    std::numeric_limits<::ad::map::restriction::PassengerCount>::lowest());
  elementRestrictionsDisjunctionsElement.passengers_min = elementRestrictionsDisjunctionsElementPassengers_min;
  elementRestrictionsDisjunctions.resize(1, elementRestrictionsDisjunctionsElement);
  elementRestrictions.disjunctions = elementRestrictionsDisjunctions;
  element.restrictions = elementRestrictions;
  ::ad::map::landmark::LandmarkId elementLandmark_id(std::numeric_limits<::ad::map::landmark::LandmarkId>::lowest());
  element.landmark_id = elementLandmark_id;
  value.push_back(element);
  ASSERT_TRUE(withinValidInputRange(value));
}

TEST(ContactLaneListValidInputRangeTests, testValidInputRangeElementInvalid)
{
  ::ad::map::lane::ContactLaneList value;
  ::ad::map::lane::ContactLane element;
  ::ad::map::lane::ContactLocation elementLocation(static_cast<::ad::map::lane::ContactLocation>(-1));
  element.location = elementLocation;
  value.push_back(element);
  ASSERT_FALSE(withinValidInputRange(value));
}
