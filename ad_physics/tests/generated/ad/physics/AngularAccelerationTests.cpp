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
#include "ad/physics/AngularAcceleration.hpp"

TEST(AngularAccelerationTests, defaultConstructionIsInvalid)
{
  ::ad::physics::AngularAcceleration value;
  EXPECT_FALSE(value.isValid());
}

TEST(AngularAccelerationTests, minIsDefinedAsExpected)
{
  EXPECT_DOUBLE_EQ(-1e3, ::ad::physics::AngularAcceleration::cMinValue);
  EXPECT_DOUBLE_EQ(::ad::physics::AngularAcceleration::cMinValue,
                   ::ad::physics::AngularAcceleration::getMin().mAngularAcceleration);
}

TEST(AngularAccelerationTests, maxIsDefinedAsExpected)
{
  EXPECT_DOUBLE_EQ(1e3, ::ad::physics::AngularAcceleration::cMaxValue);
  EXPECT_DOUBLE_EQ(::ad::physics::AngularAcceleration::cMaxValue,
                   ::ad::physics::AngularAcceleration::getMax().mAngularAcceleration);
}

TEST(AngularAccelerationTests, precisionIsDefinedAsExpected)
{
  EXPECT_LT(0., ::ad::physics::AngularAcceleration::cPrecisionValue);
  EXPECT_DOUBLE_EQ(1e-4, ::ad::physics::AngularAcceleration::cPrecisionValue);
  EXPECT_DOUBLE_EQ(::ad::physics::AngularAcceleration::cPrecisionValue,
                   ::ad::physics::AngularAcceleration::getPrecision().mAngularAcceleration);
}

TEST(AngularAccelerationTests, minIsValid)
{
  EXPECT_TRUE(::ad::physics::AngularAcceleration::getMin().isValid());
}

TEST(AngularAccelerationTests, aboveMinIsValid)
{
  ::ad::physics::AngularAcceleration value(::ad::physics::AngularAcceleration::cMinValue * 0.9);
  EXPECT_TRUE(value.isValid());
}

TEST(AngularAccelerationTests, belowMinIsInvalid)
{
  ::ad::physics::AngularAcceleration value(::ad::physics::AngularAcceleration::cMinValue * 1.1);
  EXPECT_FALSE(value.isValid());
}

TEST(AngularAccelerationTests, maxIsValid)
{
  EXPECT_TRUE(::ad::physics::AngularAcceleration::getMax().isValid());
}

TEST(AngularAccelerationTests, aboveMaxIsInvalid)
{
  ::ad::physics::AngularAcceleration value(::ad::physics::AngularAcceleration::cMaxValue * 1.1);
  EXPECT_FALSE(value.isValid());
}

TEST(AngularAccelerationTests, belowMaxIsValid)
{
  ::ad::physics::AngularAcceleration value(::ad::physics::AngularAcceleration::cMaxValue * 0.9);
  EXPECT_TRUE(value.isValid());
}

#if (AD_PHYSICS_ANGULARACCELERATION_THROWS_EXCEPTION == 1)
TEST(AngularAccelerationTests, ensureValidThrowsOnInvalid)
{
  ::ad::physics::AngularAcceleration value;
  EXPECT_THROW(value.ensureValid(), std::out_of_range);
}

TEST(AngularAccelerationTests, ensureValidNonZeroThrowsOnInvalid)
{
  ::ad::physics::AngularAcceleration value;
  EXPECT_THROW(value.ensureValidNonZero(), std::out_of_range);
}

TEST(AngularAccelerationTests, ensureValidNonZeroThrowsOnZero)
{
  ::ad::physics::AngularAcceleration value(0.);
  EXPECT_THROW(value.ensureValidNonZero(), std::out_of_range);
}
#endif

TEST(AngularAccelerationTestsStd, numericLimitsLowestIsMin)
{
  EXPECT_DOUBLE_EQ(::ad::physics::AngularAcceleration::getMin().mAngularAcceleration,
                   std::numeric_limits<::ad::physics::AngularAcceleration>::lowest().mAngularAcceleration);
}

TEST(AngularAccelerationTestsStd, numericLimitsMaxIsMax)
{
  EXPECT_DOUBLE_EQ(::ad::physics::AngularAcceleration::getMax().mAngularAcceleration,
                   std::numeric_limits<::ad::physics::AngularAcceleration>::max().mAngularAcceleration);
}

TEST(AngularAccelerationTestsStd, numericLimitsEpsilonIsPrecision)
{
  EXPECT_DOUBLE_EQ(::ad::physics::AngularAcceleration::getPrecision().mAngularAcceleration,
                   std::numeric_limits<::ad::physics::AngularAcceleration>::epsilon().mAngularAcceleration);
}

TEST(AngularAccelerationTestsStd, fabsIsWorkingCorrectly)
{
  EXPECT_DOUBLE_EQ(0., std::fabs(::ad::physics::AngularAcceleration(-0.)).mAngularAcceleration);
  EXPECT_DOUBLE_EQ(1., std::fabs(::ad::physics::AngularAcceleration(-1.)).mAngularAcceleration);
  EXPECT_DOUBLE_EQ(
    ::ad::physics::AngularAcceleration::cPrecisionValue,
    std::fabs(
      ::ad::physics::AngularAcceleration(::ad::physics::AngularAcceleration::cPrecisionValue).mAngularAcceleration));
  EXPECT_DOUBLE_EQ(
    std::fabs(::ad::physics::AngularAcceleration::cMinValue),
    std::fabs(::ad::physics::AngularAcceleration(::ad::physics::AngularAcceleration::cMinValue).mAngularAcceleration));
  EXPECT_DOUBLE_EQ(
    std::fabs(::ad::physics::AngularAcceleration::cMinValue),
    std::fabs(::ad::physics::AngularAcceleration(-::ad::physics::AngularAcceleration::cMinValue).mAngularAcceleration));
  EXPECT_DOUBLE_EQ(
    std::fabs(::ad::physics::AngularAcceleration::cMaxValue),
    std::fabs(::ad::physics::AngularAcceleration(::ad::physics::AngularAcceleration::cMaxValue).mAngularAcceleration));
  EXPECT_DOUBLE_EQ(
    std::fabs(::ad::physics::AngularAcceleration::cMaxValue),
    std::fabs(::ad::physics::AngularAcceleration(-::ad::physics::AngularAcceleration::cMaxValue).mAngularAcceleration));
}

TEST(AngularAccelerationTests, constructionFromValidFPValue)
{
  double const validValue = ::ad::physics::AngularAcceleration::cMinValue;
  ::ad::physics::AngularAcceleration value(validValue);
  EXPECT_TRUE(value.isValid());
  EXPECT_DOUBLE_EQ(validValue, value.mAngularAcceleration);
}

TEST(AngularAccelerationTests, copyConstructionFromValidValue)
{
  ::ad::physics::AngularAcceleration const validValue(::ad::physics::AngularAcceleration::cMinValue);
  ::ad::physics::AngularAcceleration value(validValue);
  EXPECT_TRUE(value.isValid());
  EXPECT_DOUBLE_EQ(validValue.mAngularAcceleration, value.mAngularAcceleration);
}

TEST(AngularAccelerationTests, moveConstructionFromValidValue)
{
  ::ad::physics::AngularAcceleration validValue(::ad::physics::AngularAcceleration::cMinValue);
  ::ad::physics::AngularAcceleration value(std::move(validValue));
  EXPECT_TRUE(value.isValid());
  EXPECT_DOUBLE_EQ(::ad::physics::AngularAcceleration::cMinValue, value.mAngularAcceleration);
}

TEST(AngularAccelerationTests, assignmentFromValidValue)
{
  ::ad::physics::AngularAcceleration const validValue(::ad::physics::AngularAcceleration::cMinValue);
  ::ad::physics::AngularAcceleration value;
  value = validValue;
  EXPECT_TRUE(value.isValid());
  EXPECT_DOUBLE_EQ(validValue.mAngularAcceleration, value.mAngularAcceleration);
}

TEST(AngularAccelerationTests, moveAssignmentFromValidValue)
{
  ::ad::physics::AngularAcceleration validValue(::ad::physics::AngularAcceleration::cMinValue);
  ::ad::physics::AngularAcceleration value;
  value = std::move(validValue);
  EXPECT_TRUE(value.isValid());
  EXPECT_DOUBLE_EQ(::ad::physics::AngularAcceleration::cMinValue, value.mAngularAcceleration);
}

TEST(AngularAccelerationTests, constructionFromInvalidFPValue)
{
  double const invalidValue = std::numeric_limits<double>::quiet_NaN();
  ::ad::physics::AngularAcceleration value(invalidValue);
  EXPECT_FALSE(value.isValid());
}

TEST(AngularAccelerationTests, copyConstructionFromInvalidValue)
{
  ::ad::physics::AngularAcceleration const invalidValue(std::numeric_limits<double>::quiet_NaN());
  ::ad::physics::AngularAcceleration value(invalidValue);
  EXPECT_FALSE(value.isValid());
}

TEST(AngularAccelerationTests, assignmentFromInvalidValue)
{
  ::ad::physics::AngularAcceleration const invalidValue(std::numeric_limits<double>::quiet_NaN());
  ::ad::physics::AngularAcceleration value;
  value = invalidValue;
  EXPECT_FALSE(value.isValid());
}

TEST(AngularAccelerationTests, selfAssignment)
{
  ::ad::physics::AngularAcceleration value(::ad::physics::AngularAcceleration::cMinValue);
  EXPECT_TRUE(value.isValid());
  value = value;
  EXPECT_TRUE(value.isValid());
}

TEST(AngularAccelerationTests, ostreamOperatorTest)
{
  std::stringstream stream;
  ::ad::physics::AngularAcceleration value;
  stream << value;
  ASSERT_GT(stream.str().size(), 0u);
}

#if (AD_PHYSICS_ANGULARACCELERATION_THROWS_EXCEPTION == 1)
TEST(AngularAccelerationTests, comparisonOperatorsThrowOnInvalid)
{
  ::ad::physics::AngularAcceleration const value(::ad::physics::AngularAcceleration::cMinValue);
  ::ad::physics::AngularAcceleration const invalidValue;

  EXPECT_THROW((void)(invalidValue == value), std::out_of_range);
  EXPECT_THROW((void)(value == invalidValue), std::out_of_range);

  EXPECT_THROW((void)(invalidValue != value), std::out_of_range);
  EXPECT_THROW((void)(value != invalidValue), std::out_of_range);

  EXPECT_THROW((void)(invalidValue > value), std::out_of_range);
  EXPECT_THROW((void)(value > invalidValue), std::out_of_range);

  EXPECT_THROW((void)(invalidValue < value), std::out_of_range);
  EXPECT_THROW((void)(value < invalidValue), std::out_of_range);

  EXPECT_THROW((void)(invalidValue >= value), std::out_of_range);
  EXPECT_THROW((void)(value >= invalidValue), std::out_of_range);

  EXPECT_THROW((void)(invalidValue <= value), std::out_of_range);
  EXPECT_THROW((void)(value <= invalidValue), std::out_of_range);
}

TEST(AngularAccelerationTests, arithmeticOperatorsThrowOnInvalid)
{
  ::ad::physics::AngularAcceleration const minimalValue(::ad::physics::AngularAcceleration::cMinValue);
  ::ad::physics::AngularAcceleration const maximalValue(::ad::physics::AngularAcceleration::cMaxValue);
  ::ad::physics::AngularAcceleration const invalidValue;
  ::ad::physics::AngularAcceleration calculationValue;

  //  operator+(::ad::physics::AngularAcceleration)
  EXPECT_THROW(invalidValue + maximalValue, std::out_of_range);
  EXPECT_THROW(maximalValue + invalidValue, std::out_of_range);
  EXPECT_EQ(maximalValue + maximalValue, maximalValue);

  //  operator+=(::ad::physics::AngularAcceleration)
  calculationValue = invalidValue;
  EXPECT_THROW(calculationValue += maximalValue, std::out_of_range);
  calculationValue = maximalValue;
  EXPECT_THROW(calculationValue += invalidValue, std::out_of_range);
  calculationValue = maximalValue;
  EXPECT_EQ(calculationValue += maximalValue, maximalValue);

  //  operator-(::ad::physics::AngularAcceleration)
  EXPECT_THROW(invalidValue - minimalValue, std::out_of_range);
  EXPECT_THROW(minimalValue - invalidValue, std::out_of_range);
  EXPECT_EQ(minimalValue - maximalValue, minimalValue);

  //  operator-=(::ad::physics::AngularAcceleration)
  calculationValue = invalidValue;
  EXPECT_THROW(calculationValue -= minimalValue, std::out_of_range);
  calculationValue = minimalValue;
  EXPECT_THROW(calculationValue -= invalidValue, std::out_of_range);
  calculationValue = minimalValue;
  EXPECT_EQ(calculationValue -= maximalValue, minimalValue);

  //  operator*(double)
  EXPECT_THROW(invalidValue * maximalValue.mAngularAcceleration, std::out_of_range);
  EXPECT_EQ(maximalValue * maximalValue.mAngularAcceleration, maximalValue);

  //  operator/(double)
  EXPECT_THROW(invalidValue / maximalValue.mAngularAcceleration, std::out_of_range);
  EXPECT_THROW(maximalValue / invalidValue.mAngularAcceleration, std::out_of_range);
  EXPECT_THROW(maximalValue / 0.0, std::out_of_range);
  EXPECT_EQ(maximalValue / 0.5, maximalValue);

  //  operator/(::ad::physics::AngularAcceleration)
  EXPECT_THROW(invalidValue / maximalValue, std::out_of_range);
  EXPECT_THROW(maximalValue / invalidValue, std::out_of_range);
  EXPECT_THROW(maximalValue / ::ad::physics::AngularAcceleration(0.0), std::out_of_range);

  //  operator-()
  EXPECT_THROW(-invalidValue, std::out_of_range);
  if (std::fabs(maximalValue.mAngularAcceleration) > std::fabs(minimalValue.mAngularAcceleration))
  {
    EXPECT_EQ(-maximalValue, minimalValue);
  }
  else if (std::fabs(maximalValue.mAngularAcceleration) < std::fabs(minimalValue.mAngularAcceleration))
  {
    EXPECT_EQ(-minimalValue, maximalValue);
  }
  else
  {
    // impossible to trigger invalid result while operand is valid
  }
}
#endif

TEST(AngularAccelerationTests, comparisonOperatorsRespectPrecision)
{
  double const precisionValueTimesTen = ::ad::physics::AngularAcceleration::cPrecisionValue * 10.;
  ::ad::physics::AngularAcceleration value;
  if (::ad::physics::AngularAcceleration::cMinValue > precisionValueTimesTen)
  {
    value = ::ad::physics::AngularAcceleration(::ad::physics::AngularAcceleration::cMinValue + precisionValueTimesTen);
  }
  else if (::ad::physics::AngularAcceleration::cMaxValue < precisionValueTimesTen)
  {
    value = ::ad::physics::AngularAcceleration(::ad::physics::AngularAcceleration::cMaxValue - precisionValueTimesTen);
  }
  else
  {
    value = ::ad::physics::AngularAcceleration(precisionValueTimesTen);
  }
  ::ad::physics::AngularAcceleration const sameValue = value;
  ::ad::physics::AngularAcceleration const slightlyBiggerValue(
    value.mAngularAcceleration + ::ad::physics::AngularAcceleration::cPrecisionValue * 0.9);
  ::ad::physics::AngularAcceleration const slightlySmallerValue(
    value.mAngularAcceleration - ::ad::physics::AngularAcceleration::cPrecisionValue * 0.9);
  ::ad::physics::AngularAcceleration const actuallyBiggerValue(
    value.mAngularAcceleration + ::ad::physics::AngularAcceleration::cPrecisionValue * 1.1);
  ::ad::physics::AngularAcceleration const actuallySmallerValue(
    value.mAngularAcceleration - ::ad::physics::AngularAcceleration::cPrecisionValue * 1.1);

  // operator ==
  EXPECT_TRUE(value == sameValue);
  EXPECT_TRUE(value == slightlyBiggerValue);
  EXPECT_TRUE(value == slightlySmallerValue);
  EXPECT_FALSE(value == actuallyBiggerValue);
  EXPECT_FALSE(value == actuallySmallerValue);

  // operator !=
  EXPECT_FALSE(value != sameValue);
  EXPECT_FALSE(value != slightlyBiggerValue);
  EXPECT_FALSE(value != slightlySmallerValue);
  EXPECT_TRUE(value != actuallyBiggerValue);
  EXPECT_TRUE(value != actuallySmallerValue);

  // operator >
  EXPECT_FALSE(value > value);
  EXPECT_FALSE(slightlyBiggerValue > value);
  EXPECT_TRUE(actuallyBiggerValue > value);

  // operator >=
  EXPECT_FALSE(actuallySmallerValue >= value);
  EXPECT_TRUE(slightlySmallerValue >= value);
  EXPECT_TRUE(value >= value);
  EXPECT_TRUE(slightlyBiggerValue >= value);
  EXPECT_TRUE(actuallyBiggerValue >= value);

  // operator <
  EXPECT_FALSE(value < value);
  EXPECT_FALSE(slightlySmallerValue < value);
  EXPECT_TRUE(actuallySmallerValue < value);

  // operator <=
  EXPECT_FALSE(actuallyBiggerValue <= value);
  EXPECT_TRUE(slightlyBiggerValue <= value);
  EXPECT_TRUE(value <= value);
  EXPECT_TRUE(slightlySmallerValue <= value);
  EXPECT_TRUE(actuallySmallerValue <= value);
}

TEST(AngularAccelerationTests, arithmeticOperatorsComputeCorrectly)
{
  double const cDoubleNear = ::ad::physics::AngularAcceleration::cPrecisionValue;
  double const precisionValueTimesTen = ::ad::physics::AngularAcceleration::cPrecisionValue * 10.;
  ::ad::physics::AngularAcceleration value;
  if (::ad::physics::AngularAcceleration::cMinValue > precisionValueTimesTen)
  {
    value = ::ad::physics::AngularAcceleration(::ad::physics::AngularAcceleration::cMinValue + precisionValueTimesTen);
  }
  else if (::ad::physics::AngularAcceleration::cMaxValue < precisionValueTimesTen)
  {
    value = ::ad::physics::AngularAcceleration(::ad::physics::AngularAcceleration::cMaxValue - precisionValueTimesTen);
  }
  else
  {
    value = ::ad::physics::AngularAcceleration(precisionValueTimesTen);
  }

  ::ad::physics::AngularAcceleration result;

  //  operator+(::ad::physics::AngularAcceleration)
  result = value + value;
  EXPECT_NEAR(value.mAngularAcceleration + value.mAngularAcceleration, result.mAngularAcceleration, cDoubleNear);

  //  operator+=(::ad::physics::AngularAcceleration)
  result = value;
  result += value;
  EXPECT_NEAR(value.mAngularAcceleration + value.mAngularAcceleration, result.mAngularAcceleration, cDoubleNear);

  //  operator-(::ad::physics::AngularAcceleration)
  result = value - value;
  EXPECT_NEAR(value.mAngularAcceleration - value.mAngularAcceleration, result.mAngularAcceleration, cDoubleNear);

  //  operator-=(::ad::physics::AngularAcceleration)
  result = value;
  result -= value;
  EXPECT_NEAR(value.mAngularAcceleration - value.mAngularAcceleration, result.mAngularAcceleration, cDoubleNear);

  //  operator*(double)
  result = value * 5.;
  EXPECT_NEAR(value.mAngularAcceleration * 5., result.mAngularAcceleration, cDoubleNear);

  //  operator*(double, ::ad::physics::AngularAcceleration)
  result = 5. * value;
  EXPECT_NEAR(value.mAngularAcceleration * 5., result.mAngularAcceleration, cDoubleNear);

  //  operator/(double)
  result = value / value.mAngularAcceleration;
  EXPECT_NEAR(value.mAngularAcceleration / value.mAngularAcceleration, result.mAngularAcceleration, cDoubleNear);

  //  operator/(::ad::physics::AngularAcceleration)
  double const doubleResult = value / value;
  EXPECT_NEAR(value.mAngularAcceleration / value.mAngularAcceleration, doubleResult, cDoubleNear);

  //  operator-()
  if ((::ad::physics::AngularAcceleration::cMinValue < -value.mAngularAcceleration)
      && (-value.mAngularAcceleration < ::ad::physics::AngularAcceleration::cMaxValue))
  {
    result = -value;
  }
  else
  {
    // not clear on how to trigger valid result if such small value is not working
  }
}

#if defined(__clang__) && (__clang_major__ >= 7)
#pragma GCC diagnostic pop
#endif
