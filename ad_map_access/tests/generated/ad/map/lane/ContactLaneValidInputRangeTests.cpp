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

#include "ad/map/lane/ContactLaneValidInputRange.hpp"

TEST(ContactLaneValidInputRangeTests, testValidInputRange)
{
  ::ad::map::lane::ContactLane value;
  ::ad::map::lane::LaneId valueTo_lane(1);
  value.to_lane = valueTo_lane;
  ::ad::map::lane::ContactLocation valueLocation(::ad::map::lane::ContactLocation::INVALID);
  value.location = valueLocation;
  ::ad::map::lane::ContactTypeList valueTypes;
  ::ad::map::lane::ContactType valueTypesElement(::ad::map::lane::ContactType::INVALID);
  valueTypes.resize(1, valueTypesElement);
  value.types = valueTypes;
  ::ad::map::restriction::Restrictions valueRestrictions;
  ::ad::map::restriction::RestrictionList valueRestrictionsConjunctions;
  ::ad::map::restriction::Restriction valueRestrictionsConjunctionsElement;
  bool valueRestrictionsConjunctionsElementNegated{true};
  valueRestrictionsConjunctionsElement.negated = valueRestrictionsConjunctionsElementNegated;
  ::ad::map::restriction::RoadUserTypeList valueRestrictionsConjunctionsElementRoad_user_types;
  ::ad::map::restriction::RoadUserType valueRestrictionsConjunctionsElementRoad_user_typesElement(
    ::ad::map::restriction::RoadUserType::INVALID);
  valueRestrictionsConjunctionsElementRoad_user_types.resize(
    1, valueRestrictionsConjunctionsElementRoad_user_typesElement);
  valueRestrictionsConjunctionsElement.road_user_types = valueRestrictionsConjunctionsElementRoad_user_types;
  ::ad::map::restriction::PassengerCount valueRestrictionsConjunctionsElementPassengers_min(
    std::numeric_limits<::ad::map::restriction::PassengerCount>::lowest());
  valueRestrictionsConjunctionsElement.passengers_min = valueRestrictionsConjunctionsElementPassengers_min;
  valueRestrictionsConjunctions.resize(1, valueRestrictionsConjunctionsElement);
  valueRestrictions.conjunctions = valueRestrictionsConjunctions;
  ::ad::map::restriction::RestrictionList valueRestrictionsDisjunctions;
  ::ad::map::restriction::Restriction valueRestrictionsDisjunctionsElement;
  bool valueRestrictionsDisjunctionsElementNegated{true};
  valueRestrictionsDisjunctionsElement.negated = valueRestrictionsDisjunctionsElementNegated;
  ::ad::map::restriction::RoadUserTypeList valueRestrictionsDisjunctionsElementRoad_user_types;
  ::ad::map::restriction::RoadUserType valueRestrictionsDisjunctionsElementRoad_user_typesElement(
    ::ad::map::restriction::RoadUserType::INVALID);
  valueRestrictionsDisjunctionsElementRoad_user_types.resize(
    1, valueRestrictionsDisjunctionsElementRoad_user_typesElement);
  valueRestrictionsDisjunctionsElement.road_user_types = valueRestrictionsDisjunctionsElementRoad_user_types;
  ::ad::map::restriction::PassengerCount valueRestrictionsDisjunctionsElementPassengers_min(
    std::numeric_limits<::ad::map::restriction::PassengerCount>::lowest());
  valueRestrictionsDisjunctionsElement.passengers_min = valueRestrictionsDisjunctionsElementPassengers_min;
  valueRestrictionsDisjunctions.resize(1, valueRestrictionsDisjunctionsElement);
  valueRestrictions.disjunctions = valueRestrictionsDisjunctions;
  value.restrictions = valueRestrictions;
  ::ad::map::landmark::LandmarkId valueLandmark_id(std::numeric_limits<::ad::map::landmark::LandmarkId>::lowest());
  value.landmark_id = valueLandmark_id;
  ASSERT_TRUE(withinValidInputRange(value));
}

TEST(ContactLaneValidInputRangeTests, testValidInputRangeLocationTooSmall)
{
  ::ad::map::lane::ContactLane value;
  ::ad::map::lane::LaneId valueTo_lane(1);
  value.to_lane = valueTo_lane;
  ::ad::map::lane::ContactLocation valueLocation(::ad::map::lane::ContactLocation::INVALID);
  value.location = valueLocation;
  ::ad::map::lane::ContactTypeList valueTypes;
  ::ad::map::lane::ContactType valueTypesElement(::ad::map::lane::ContactType::INVALID);
  valueTypes.resize(1, valueTypesElement);
  value.types = valueTypes;
  ::ad::map::restriction::Restrictions valueRestrictions;
  ::ad::map::restriction::RestrictionList valueRestrictionsConjunctions;
  ::ad::map::restriction::Restriction valueRestrictionsConjunctionsElement;
  bool valueRestrictionsConjunctionsElementNegated{true};
  valueRestrictionsConjunctionsElement.negated = valueRestrictionsConjunctionsElementNegated;
  ::ad::map::restriction::RoadUserTypeList valueRestrictionsConjunctionsElementRoad_user_types;
  ::ad::map::restriction::RoadUserType valueRestrictionsConjunctionsElementRoad_user_typesElement(
    ::ad::map::restriction::RoadUserType::INVALID);
  valueRestrictionsConjunctionsElementRoad_user_types.resize(
    1, valueRestrictionsConjunctionsElementRoad_user_typesElement);
  valueRestrictionsConjunctionsElement.road_user_types = valueRestrictionsConjunctionsElementRoad_user_types;
  ::ad::map::restriction::PassengerCount valueRestrictionsConjunctionsElementPassengers_min(
    std::numeric_limits<::ad::map::restriction::PassengerCount>::lowest());
  valueRestrictionsConjunctionsElement.passengers_min = valueRestrictionsConjunctionsElementPassengers_min;
  valueRestrictionsConjunctions.resize(1, valueRestrictionsConjunctionsElement);
  valueRestrictions.conjunctions = valueRestrictionsConjunctions;
  ::ad::map::restriction::RestrictionList valueRestrictionsDisjunctions;
  ::ad::map::restriction::Restriction valueRestrictionsDisjunctionsElement;
  bool valueRestrictionsDisjunctionsElementNegated{true};
  valueRestrictionsDisjunctionsElement.negated = valueRestrictionsDisjunctionsElementNegated;
  ::ad::map::restriction::RoadUserTypeList valueRestrictionsDisjunctionsElementRoad_user_types;
  ::ad::map::restriction::RoadUserType valueRestrictionsDisjunctionsElementRoad_user_typesElement(
    ::ad::map::restriction::RoadUserType::INVALID);
  valueRestrictionsDisjunctionsElementRoad_user_types.resize(
    1, valueRestrictionsDisjunctionsElementRoad_user_typesElement);
  valueRestrictionsDisjunctionsElement.road_user_types = valueRestrictionsDisjunctionsElementRoad_user_types;
  ::ad::map::restriction::PassengerCount valueRestrictionsDisjunctionsElementPassengers_min(
    std::numeric_limits<::ad::map::restriction::PassengerCount>::lowest());
  valueRestrictionsDisjunctionsElement.passengers_min = valueRestrictionsDisjunctionsElementPassengers_min;
  valueRestrictionsDisjunctions.resize(1, valueRestrictionsDisjunctionsElement);
  valueRestrictions.disjunctions = valueRestrictionsDisjunctions;
  value.restrictions = valueRestrictions;
  ::ad::map::landmark::LandmarkId valueLandmark_id(std::numeric_limits<::ad::map::landmark::LandmarkId>::lowest());
  value.landmark_id = valueLandmark_id;

  // override member with data type value below input range minimum
  ::ad::map::lane::ContactLocation invalidInitializedMember(static_cast<::ad::map::lane::ContactLocation>(-1));
  value.location = invalidInitializedMember;
  ASSERT_FALSE(withinValidInputRange(value));
}

TEST(ContactLaneValidInputRangeTests, testValidInputRangeLocationTooBig)
{
  ::ad::map::lane::ContactLane value;
  ::ad::map::lane::LaneId valueTo_lane(1);
  value.to_lane = valueTo_lane;
  ::ad::map::lane::ContactLocation valueLocation(::ad::map::lane::ContactLocation::INVALID);
  value.location = valueLocation;
  ::ad::map::lane::ContactTypeList valueTypes;
  ::ad::map::lane::ContactType valueTypesElement(::ad::map::lane::ContactType::INVALID);
  valueTypes.resize(1, valueTypesElement);
  value.types = valueTypes;
  ::ad::map::restriction::Restrictions valueRestrictions;
  ::ad::map::restriction::RestrictionList valueRestrictionsConjunctions;
  ::ad::map::restriction::Restriction valueRestrictionsConjunctionsElement;
  bool valueRestrictionsConjunctionsElementNegated{true};
  valueRestrictionsConjunctionsElement.negated = valueRestrictionsConjunctionsElementNegated;
  ::ad::map::restriction::RoadUserTypeList valueRestrictionsConjunctionsElementRoad_user_types;
  ::ad::map::restriction::RoadUserType valueRestrictionsConjunctionsElementRoad_user_typesElement(
    ::ad::map::restriction::RoadUserType::INVALID);
  valueRestrictionsConjunctionsElementRoad_user_types.resize(
    1, valueRestrictionsConjunctionsElementRoad_user_typesElement);
  valueRestrictionsConjunctionsElement.road_user_types = valueRestrictionsConjunctionsElementRoad_user_types;
  ::ad::map::restriction::PassengerCount valueRestrictionsConjunctionsElementPassengers_min(
    std::numeric_limits<::ad::map::restriction::PassengerCount>::lowest());
  valueRestrictionsConjunctionsElement.passengers_min = valueRestrictionsConjunctionsElementPassengers_min;
  valueRestrictionsConjunctions.resize(1, valueRestrictionsConjunctionsElement);
  valueRestrictions.conjunctions = valueRestrictionsConjunctions;
  ::ad::map::restriction::RestrictionList valueRestrictionsDisjunctions;
  ::ad::map::restriction::Restriction valueRestrictionsDisjunctionsElement;
  bool valueRestrictionsDisjunctionsElementNegated{true};
  valueRestrictionsDisjunctionsElement.negated = valueRestrictionsDisjunctionsElementNegated;
  ::ad::map::restriction::RoadUserTypeList valueRestrictionsDisjunctionsElementRoad_user_types;
  ::ad::map::restriction::RoadUserType valueRestrictionsDisjunctionsElementRoad_user_typesElement(
    ::ad::map::restriction::RoadUserType::INVALID);
  valueRestrictionsDisjunctionsElementRoad_user_types.resize(
    1, valueRestrictionsDisjunctionsElementRoad_user_typesElement);
  valueRestrictionsDisjunctionsElement.road_user_types = valueRestrictionsDisjunctionsElementRoad_user_types;
  ::ad::map::restriction::PassengerCount valueRestrictionsDisjunctionsElementPassengers_min(
    std::numeric_limits<::ad::map::restriction::PassengerCount>::lowest());
  valueRestrictionsDisjunctionsElement.passengers_min = valueRestrictionsDisjunctionsElementPassengers_min;
  valueRestrictionsDisjunctions.resize(1, valueRestrictionsDisjunctionsElement);
  valueRestrictions.disjunctions = valueRestrictionsDisjunctions;
  value.restrictions = valueRestrictions;
  ::ad::map::landmark::LandmarkId valueLandmark_id(std::numeric_limits<::ad::map::landmark::LandmarkId>::lowest());
  value.landmark_id = valueLandmark_id;

  // override member with data type value above input range maximum
  ::ad::map::lane::ContactLocation invalidInitializedMember(static_cast<::ad::map::lane::ContactLocation>(-1));
  value.location = invalidInitializedMember;
  ASSERT_FALSE(withinValidInputRange(value));
}
