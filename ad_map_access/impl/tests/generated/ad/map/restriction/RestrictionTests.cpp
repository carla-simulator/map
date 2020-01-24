/*
 * ----------------- BEGIN LICENSE BLOCK ---------------------------------
 *
 * Copyright (C) 2018-2020 Intel Corporation
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
    ::ad::map::restriction::RoadUserTypeList valueRoadUserTypes;
    ::ad::map::restriction::RoadUserType valueRoadUserTypesElement(::ad::map::restriction::RoadUserType::INVALID);
    valueRoadUserTypes.resize(1, valueRoadUserTypesElement);
    value.roadUserTypes = valueRoadUserTypes;
    ::ad::map::restriction::PassengerCount valuePassengersMin(
      std::numeric_limits<::ad::map::restriction::PassengerCount>::lowest());
    value.passengersMin = valuePassengersMin;
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
  ::ad::map::restriction::Restriction value(std::move(::ad::map::restriction::Restriction(mValue)));
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
  ::ad::map::restriction::Restriction value;
  value = std::move(::ad::map::restriction::Restriction(mValue));
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

TEST_F(RestrictionTests, comparisonOperatorRoadUserTypesDiffers)
{
  ::ad::map::restriction::Restriction valueA = mValue;
  ::ad::map::restriction::RoadUserTypeList roadUserTypes;
  ::ad::map::restriction::RoadUserType roadUserTypesElement(::ad::map::restriction::RoadUserType::CAR_DIESEL);
  roadUserTypes.resize(2, roadUserTypesElement);
  valueA.roadUserTypes = roadUserTypes;
  ::ad::map::restriction::Restriction valueB = mValue;

  EXPECT_FALSE(valueA == valueB);
  EXPECT_TRUE(valueA != valueB);
}

TEST_F(RestrictionTests, comparisonOperatorPassengersMinDiffers)
{
  ::ad::map::restriction::Restriction valueA = mValue;
  ::ad::map::restriction::PassengerCount passengersMin(
    std::numeric_limits<::ad::map::restriction::PassengerCount>::max());
  valueA.passengersMin = passengersMin;
  ::ad::map::restriction::Restriction valueB = mValue;

  EXPECT_FALSE(valueA == valueB);
  EXPECT_TRUE(valueA != valueB);
}
