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
#include "ad/map/restriction/Restrictions.hpp"

class RestrictionsTests : public testing::Test
{
protected:
  virtual void SetUp() override
  {
    // valid initialization
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
    mValue = value;
  }

  ::ad::map::restriction::Restrictions mValue;
};

TEST_F(RestrictionsTests, copyConstruction)
{
  ::ad::map::restriction::Restrictions value(mValue);
  EXPECT_EQ(mValue, value);
}

TEST_F(RestrictionsTests, moveConstruction)
{
  ::ad::map::restriction::Restrictions tmpValue(mValue);
  ::ad::map::restriction::Restrictions value(std::move(tmpValue));
  EXPECT_EQ(mValue, value);
}

TEST_F(RestrictionsTests, copyAssignment)
{
  ::ad::map::restriction::Restrictions value;
  value = mValue;
  EXPECT_EQ(mValue, value);
}

TEST_F(RestrictionsTests, moveAssignment)
{
  ::ad::map::restriction::Restrictions tmpValue(mValue);
  ::ad::map::restriction::Restrictions value;
  value = std::move(tmpValue);
  EXPECT_EQ(mValue, value);
}

TEST_F(RestrictionsTests, comparisonOperatorEqual)
{
  ::ad::map::restriction::Restrictions valueA = mValue;
  ::ad::map::restriction::Restrictions valueB = mValue;

  EXPECT_TRUE(valueA == valueB);
  EXPECT_FALSE(valueA != valueB);
}

TEST_F(RestrictionsTests, stringConversionTest)
{
  std::stringstream stream;
  stream << mValue;
  std::string ostreamStr = stream.str();
  std::string toStr = std::to_string(mValue);
  ASSERT_EQ(ostreamStr, toStr);
}

TEST_F(RestrictionsTests, comparisonOperatorConjunctionsDiffers)
{
  ::ad::map::restriction::Restrictions valueA = mValue;
  ::ad::map::restriction::RestrictionList conjunctions;
  ::ad::map::restriction::Restriction conjunctionsElement;
  bool conjunctionsElementNegated{false};
  conjunctionsElement.negated = conjunctionsElementNegated;
  ::ad::map::restriction::RoadUserTypeList conjunctionsElementRoad_user_types;
  ::ad::map::restriction::RoadUserType conjunctionsElementRoad_user_typesElement(
    ::ad::map::restriction::RoadUserType::CAR_DIESEL);
  conjunctionsElementRoad_user_types.resize(2, conjunctionsElementRoad_user_typesElement);
  conjunctionsElement.road_user_types = conjunctionsElementRoad_user_types;
  ::ad::map::restriction::PassengerCount conjunctionsElementPassengers_min(
    std::numeric_limits<::ad::map::restriction::PassengerCount>::max());
  conjunctionsElement.passengers_min = conjunctionsElementPassengers_min;
  conjunctions.resize(2, conjunctionsElement);
  valueA.conjunctions = conjunctions;
  ::ad::map::restriction::Restrictions valueB = mValue;

  EXPECT_FALSE(valueA == valueB);
  EXPECT_TRUE(valueA != valueB);
}

TEST_F(RestrictionsTests, comparisonOperatorDisjunctionsDiffers)
{
  ::ad::map::restriction::Restrictions valueA = mValue;
  ::ad::map::restriction::RestrictionList disjunctions;
  ::ad::map::restriction::Restriction disjunctionsElement;
  bool disjunctionsElementNegated{false};
  disjunctionsElement.negated = disjunctionsElementNegated;
  ::ad::map::restriction::RoadUserTypeList disjunctionsElementRoad_user_types;
  ::ad::map::restriction::RoadUserType disjunctionsElementRoad_user_typesElement(
    ::ad::map::restriction::RoadUserType::CAR_DIESEL);
  disjunctionsElementRoad_user_types.resize(2, disjunctionsElementRoad_user_typesElement);
  disjunctionsElement.road_user_types = disjunctionsElementRoad_user_types;
  ::ad::map::restriction::PassengerCount disjunctionsElementPassengers_min(
    std::numeric_limits<::ad::map::restriction::PassengerCount>::max());
  disjunctionsElement.passengers_min = disjunctionsElementPassengers_min;
  disjunctions.resize(2, disjunctionsElement);
  valueA.disjunctions = disjunctions;
  ::ad::map::restriction::Restrictions valueB = mValue;

  EXPECT_FALSE(valueA == valueB);
  EXPECT_TRUE(valueA != valueB);
}

#if defined(__clang__) && (__clang_major__ >= 7)
#pragma GCC diagnostic pop
#endif
