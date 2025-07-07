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
#include "ad/map/restriction/Restriction.hpp"

class RestrictionTests : public testing::Test
{
protected:
  virtual void SetUp() override
  {
    // valid initialization
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
    mValue = value;
  }

  ::ad::map::restriction::Restriction mValue;
};

TEST_F(RestrictionTests, copyConstruction)
{
  ::ad::map::restriction::Restriction value(mValue);
  EXPECT_EQ(mValue, value);
}

TEST_F(RestrictionTests, moveConstruction)
{
  ::ad::map::restriction::Restriction tmpValue(mValue);
  ::ad::map::restriction::Restriction value(std::move(tmpValue));
  EXPECT_EQ(mValue, value);
}

TEST_F(RestrictionTests, copyAssignment)
{
  ::ad::map::restriction::Restriction value;
  value = mValue;
  EXPECT_EQ(mValue, value);
}

TEST_F(RestrictionTests, moveAssignment)
{
  ::ad::map::restriction::Restriction tmpValue(mValue);
  ::ad::map::restriction::Restriction value;
  value = std::move(tmpValue);
  EXPECT_EQ(mValue, value);
}

TEST_F(RestrictionTests, comparisonOperatorEqual)
{
  ::ad::map::restriction::Restriction valueA = mValue;
  ::ad::map::restriction::Restriction valueB = mValue;

  EXPECT_TRUE(valueA == valueB);
  EXPECT_FALSE(valueA != valueB);
}

TEST_F(RestrictionTests, stringConversionTest)
{
  std::stringstream stream;
  stream << mValue;
  std::string ostreamStr = stream.str();
  std::string toStr = std::to_string(mValue);
  ASSERT_EQ(ostreamStr, toStr);
}

TEST_F(RestrictionTests, comparisonOperatorNegatedDiffers)
{
  ::ad::map::restriction::Restriction valueA = mValue;
  bool negated{false};
  valueA.negated = negated;
  ::ad::map::restriction::Restriction valueB = mValue;

  EXPECT_FALSE(valueA == valueB);
  EXPECT_TRUE(valueA != valueB);
}

TEST_F(RestrictionTests, comparisonOperatorRoad_user_typesDiffers)
{
  ::ad::map::restriction::Restriction valueA = mValue;
  ::ad::map::restriction::RoadUserTypeList road_user_types;
  ::ad::map::restriction::RoadUserType road_user_typesElement(::ad::map::restriction::RoadUserType::CAR_DIESEL);
  road_user_types.resize(2, road_user_typesElement);
  valueA.road_user_types = road_user_types;
  ::ad::map::restriction::Restriction valueB = mValue;

  EXPECT_FALSE(valueA == valueB);
  EXPECT_TRUE(valueA != valueB);
}

TEST_F(RestrictionTests, comparisonOperatorPassengers_minDiffers)
{
  ::ad::map::restriction::Restriction valueA = mValue;
  ::ad::map::restriction::PassengerCount passengers_min(
    std::numeric_limits<::ad::map::restriction::PassengerCount>::max());
  valueA.passengers_min = passengers_min;
  ::ad::map::restriction::Restriction valueB = mValue;

  EXPECT_FALSE(valueA == valueB);
  EXPECT_TRUE(valueA != valueB);
}

#if defined(__clang__) && (__clang_major__ >= 7)
#pragma GCC diagnostic pop
#endif
