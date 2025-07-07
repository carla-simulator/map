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

#if defined(__clang__) && (__clang_major__ >= 7)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wself-assign-overloaded"
#endif

#include <gtest/gtest.h>
#include <limits>
#include "ad/map/lane/ContactLane.hpp"

class ContactLaneTests : public testing::Test
{
protected:
  virtual void SetUp() override
  {
    // valid initialization
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
    mValue = value;
  }

  ::ad::map::lane::ContactLane mValue;
};

TEST_F(ContactLaneTests, copyConstruction)
{
  ::ad::map::lane::ContactLane value(mValue);
  EXPECT_EQ(mValue, value);
}

TEST_F(ContactLaneTests, moveConstruction)
{
  ::ad::map::lane::ContactLane tmpValue(mValue);
  ::ad::map::lane::ContactLane value(std::move(tmpValue));
  EXPECT_EQ(mValue, value);
}

TEST_F(ContactLaneTests, copyAssignment)
{
  ::ad::map::lane::ContactLane value;
  value = mValue;
  EXPECT_EQ(mValue, value);
}

TEST_F(ContactLaneTests, moveAssignment)
{
  ::ad::map::lane::ContactLane tmpValue(mValue);
  ::ad::map::lane::ContactLane value;
  value = std::move(tmpValue);
  EXPECT_EQ(mValue, value);
}

TEST_F(ContactLaneTests, comparisonOperatorEqual)
{
  ::ad::map::lane::ContactLane valueA = mValue;
  ::ad::map::lane::ContactLane valueB = mValue;

  EXPECT_TRUE(valueA == valueB);
  EXPECT_FALSE(valueA != valueB);
}

TEST_F(ContactLaneTests, stringConversionTest)
{
  std::stringstream stream;
  stream << mValue;
  std::string ostreamStr = stream.str();
  std::string toStr = std::to_string(mValue);
  ASSERT_EQ(ostreamStr, toStr);
}

TEST_F(ContactLaneTests, comparisonOperatorTo_laneDiffers)
{
  ::ad::map::lane::ContactLane valueA = mValue;
  ::ad::map::lane::LaneId to_lane(std::numeric_limits<::ad::map::lane::LaneId>::max());
  valueA.to_lane = to_lane;
  ::ad::map::lane::ContactLane valueB = mValue;

  EXPECT_FALSE(valueA == valueB);
  EXPECT_TRUE(valueA != valueB);
}

TEST_F(ContactLaneTests, comparisonOperatorLocationDiffers)
{
  ::ad::map::lane::ContactLane valueA = mValue;
  ::ad::map::lane::ContactLocation location(::ad::map::lane::ContactLocation::OVERLAP);
  valueA.location = location;
  ::ad::map::lane::ContactLane valueB = mValue;

  EXPECT_FALSE(valueA == valueB);
  EXPECT_TRUE(valueA != valueB);
}

TEST_F(ContactLaneTests, comparisonOperatorTypesDiffers)
{
  ::ad::map::lane::ContactLane valueA = mValue;
  ::ad::map::lane::ContactTypeList types;
  ::ad::map::lane::ContactType typesElement(::ad::map::lane::ContactType::PRIO_TO_RIGHT_AND_STRAIGHT);
  types.resize(2, typesElement);
  valueA.types = types;
  ::ad::map::lane::ContactLane valueB = mValue;

  EXPECT_FALSE(valueA == valueB);
  EXPECT_TRUE(valueA != valueB);
}

TEST_F(ContactLaneTests, comparisonOperatorRestrictionsDiffers)
{
  ::ad::map::lane::ContactLane valueA = mValue;
  ::ad::map::restriction::Restrictions restrictions;
  ::ad::map::restriction::RestrictionList restrictionsConjunctions;
  ::ad::map::restriction::Restriction restrictionsConjunctionsElement;
  bool restrictionsConjunctionsElementNegated{false};
  restrictionsConjunctionsElement.negated = restrictionsConjunctionsElementNegated;
  ::ad::map::restriction::RoadUserTypeList restrictionsConjunctionsElementRoad_user_types;
  ::ad::map::restriction::RoadUserType restrictionsConjunctionsElementRoad_user_typesElement(
    ::ad::map::restriction::RoadUserType::CAR_DIESEL);
  restrictionsConjunctionsElementRoad_user_types.resize(2, restrictionsConjunctionsElementRoad_user_typesElement);
  restrictionsConjunctionsElement.road_user_types = restrictionsConjunctionsElementRoad_user_types;
  ::ad::map::restriction::PassengerCount restrictionsConjunctionsElementPassengers_min(
    std::numeric_limits<::ad::map::restriction::PassengerCount>::max());
  restrictionsConjunctionsElement.passengers_min = restrictionsConjunctionsElementPassengers_min;
  restrictionsConjunctions.resize(2, restrictionsConjunctionsElement);
  restrictions.conjunctions = restrictionsConjunctions;
  ::ad::map::restriction::RestrictionList restrictionsDisjunctions;
  ::ad::map::restriction::Restriction restrictionsDisjunctionsElement;
  bool restrictionsDisjunctionsElementNegated{false};
  restrictionsDisjunctionsElement.negated = restrictionsDisjunctionsElementNegated;
  ::ad::map::restriction::RoadUserTypeList restrictionsDisjunctionsElementRoad_user_types;
  ::ad::map::restriction::RoadUserType restrictionsDisjunctionsElementRoad_user_typesElement(
    ::ad::map::restriction::RoadUserType::CAR_DIESEL);
  restrictionsDisjunctionsElementRoad_user_types.resize(2, restrictionsDisjunctionsElementRoad_user_typesElement);
  restrictionsDisjunctionsElement.road_user_types = restrictionsDisjunctionsElementRoad_user_types;
  ::ad::map::restriction::PassengerCount restrictionsDisjunctionsElementPassengers_min(
    std::numeric_limits<::ad::map::restriction::PassengerCount>::max());
  restrictionsDisjunctionsElement.passengers_min = restrictionsDisjunctionsElementPassengers_min;
  restrictionsDisjunctions.resize(2, restrictionsDisjunctionsElement);
  restrictions.disjunctions = restrictionsDisjunctions;
  valueA.restrictions = restrictions;
  ::ad::map::lane::ContactLane valueB = mValue;

  EXPECT_FALSE(valueA == valueB);
  EXPECT_TRUE(valueA != valueB);
}

TEST_F(ContactLaneTests, comparisonOperatorLandmark_idDiffers)
{
  ::ad::map::lane::ContactLane valueA = mValue;
  ::ad::map::landmark::LandmarkId landmark_id(std::numeric_limits<::ad::map::landmark::LandmarkId>::max());
  valueA.landmark_id = landmark_id;
  ::ad::map::lane::ContactLane valueB = mValue;

  EXPECT_FALSE(valueA == valueB);
  EXPECT_TRUE(valueA != valueB);
}

#if defined(__clang__) && (__clang_major__ >= 7)
#pragma GCC diagnostic pop
#endif
