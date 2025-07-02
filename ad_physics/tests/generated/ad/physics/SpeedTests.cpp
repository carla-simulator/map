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
#include "ad/physics/Speed.hpp"
#include "ad/physics/SpeedSquared.hpp"

TEST(SpeedTests, defaultConstructionIsInvalid)
{
  ::ad::physics::Speed value;
  EXPECT_FALSE(value.isValid());
}

TEST(SpeedTests, minIsDefinedAsExpected)
{
  EXPECT_DOUBLE_EQ(-1e3, ::ad::physics::Speed::cMinValue);
  EXPECT_DOUBLE_EQ(::ad::physics::Speed::cMinValue, ::ad::physics::Speed::getMin().mSpeed);
}

TEST(SpeedTests, maxIsDefinedAsExpected)
{
  EXPECT_DOUBLE_EQ(1e3, ::ad::physics::Speed::cMaxValue);
  EXPECT_DOUBLE_EQ(::ad::physics::Speed::cMaxValue, ::ad::physics::Speed::getMax().mSpeed);
}

TEST(SpeedTests, precisionIsDefinedAsExpected)
{
  EXPECT_LT(0., ::ad::physics::Speed::cPrecisionValue);
  EXPECT_DOUBLE_EQ(1e-3, ::ad::physics::Speed::cPrecisionValue);
  EXPECT_DOUBLE_EQ(::ad::physics::Speed::cPrecisionValue, ::ad::physics::Speed::getPrecision().mSpeed);
}

TEST(SpeedTests, minIsValid)
{
  EXPECT_TRUE(::ad::physics::Speed::getMin().isValid());
}

TEST(SpeedTests, aboveMinIsValid)
{
  ::ad::physics::Speed value(::ad::physics::Speed::cMinValue * 0.9);
  EXPECT_TRUE(value.isValid());
}

TEST(SpeedTests, belowMinIsInvalid)
{
  ::ad::physics::Speed value(::ad::physics::Speed::cMinValue * 1.1);
  EXPECT_FALSE(value.isValid());
}

TEST(SpeedTests, maxIsValid)
{
  EXPECT_TRUE(::ad::physics::Speed::getMax().isValid());
}

TEST(SpeedTests, aboveMaxIsInvalid)
{
  ::ad::physics::Speed value(::ad::physics::Speed::cMaxValue * 1.1);
  EXPECT_FALSE(value.isValid());
}

TEST(SpeedTests, belowMaxIsValid)
{
  ::ad::physics::Speed value(::ad::physics::Speed::cMaxValue * 0.9);
  EXPECT_TRUE(value.isValid());
}

#if (AD_PHYSICS_SPEED_THROWS_EXCEPTION == 1)
TEST(SpeedTests, ensureValidThrowsOnInvalid)
{
  ::ad::physics::Speed value;
  EXPECT_THROW(value.ensureValid(), std::out_of_range);
}

TEST(SpeedTests, ensureValidNonZeroThrowsOnInvalid)
{
  ::ad::physics::Speed value;
  EXPECT_THROW(value.ensureValidNonZero(), std::out_of_range);
}

TEST(SpeedTests, ensureValidNonZeroThrowsOnZero)
{
  ::ad::physics::Speed value(0.);
  EXPECT_THROW(value.ensureValidNonZero(), std::out_of_range);
}
#endif

TEST(SpeedTestsStd, numericLimitsLowestIsMin)
{
  EXPECT_DOUBLE_EQ(::ad::physics::Speed::getMin().mSpeed, std::numeric_limits<::ad::physics::Speed>::lowest().mSpeed);
}

TEST(SpeedTestsStd, numericLimitsMaxIsMax)
{
  EXPECT_DOUBLE_EQ(::ad::physics::Speed::getMax().mSpeed, std::numeric_limits<::ad::physics::Speed>::max().mSpeed);
}

TEST(SpeedTestsStd, numericLimitsEpsilonIsPrecision)
{
  EXPECT_DOUBLE_EQ(::ad::physics::Speed::getPrecision().mSpeed,
                   std::numeric_limits<::ad::physics::Speed>::epsilon().mSpeed);
}

TEST(SpeedTestsStd, fabsIsWorkingCorrectly)
{
  EXPECT_DOUBLE_EQ(0., std::fabs(::ad::physics::Speed(-0.)).mSpeed);
  EXPECT_DOUBLE_EQ(1., std::fabs(::ad::physics::Speed(-1.)).mSpeed);
  EXPECT_DOUBLE_EQ(::ad::physics::Speed::cPrecisionValue,
                   std::fabs(::ad::physics::Speed(::ad::physics::Speed::cPrecisionValue).mSpeed));
  EXPECT_DOUBLE_EQ(std::fabs(::ad::physics::Speed::cMinValue),
                   std::fabs(::ad::physics::Speed(::ad::physics::Speed::cMinValue).mSpeed));
  EXPECT_DOUBLE_EQ(std::fabs(::ad::physics::Speed::cMinValue),
                   std::fabs(::ad::physics::Speed(-::ad::physics::Speed::cMinValue).mSpeed));
  EXPECT_DOUBLE_EQ(std::fabs(::ad::physics::Speed::cMaxValue),
                   std::fabs(::ad::physics::Speed(::ad::physics::Speed::cMaxValue).mSpeed));
  EXPECT_DOUBLE_EQ(std::fabs(::ad::physics::Speed::cMaxValue),
                   std::fabs(::ad::physics::Speed(-::ad::physics::Speed::cMaxValue).mSpeed));
}

TEST(SpeedTests, constructionFromValidFPValue)
{
  double const validValue = ::ad::physics::Speed::cMinValue;
  ::ad::physics::Speed value(validValue);
  EXPECT_TRUE(value.isValid());
  EXPECT_DOUBLE_EQ(validValue, value.mSpeed);
}

TEST(SpeedTests, copyConstructionFromValidValue)
{
  ::ad::physics::Speed const validValue(::ad::physics::Speed::cMinValue);
  ::ad::physics::Speed value(validValue);
  EXPECT_TRUE(value.isValid());
  EXPECT_DOUBLE_EQ(validValue.mSpeed, value.mSpeed);
}

TEST(SpeedTests, moveConstructionFromValidValue)
{
  ::ad::physics::Speed validValue(::ad::physics::Speed::cMinValue);
  ::ad::physics::Speed value(std::move(validValue));
  EXPECT_TRUE(value.isValid());
  EXPECT_DOUBLE_EQ(::ad::physics::Speed::cMinValue, value.mSpeed);
}

TEST(SpeedTests, assignmentFromValidValue)
{
  ::ad::physics::Speed const validValue(::ad::physics::Speed::cMinValue);
  ::ad::physics::Speed value;
  value = validValue;
  EXPECT_TRUE(value.isValid());
  EXPECT_DOUBLE_EQ(validValue.mSpeed, value.mSpeed);
}

TEST(SpeedTests, moveAssignmentFromValidValue)
{
  ::ad::physics::Speed validValue(::ad::physics::Speed::cMinValue);
  ::ad::physics::Speed value;
  value = std::move(validValue);
  EXPECT_TRUE(value.isValid());
  EXPECT_DOUBLE_EQ(::ad::physics::Speed::cMinValue, value.mSpeed);
}

TEST(SpeedTests, constructionFromInvalidFPValue)
{
  double const invalidValue = std::numeric_limits<double>::quiet_NaN();
  ::ad::physics::Speed value(invalidValue);
  EXPECT_FALSE(value.isValid());
}

TEST(SpeedTests, copyConstructionFromInvalidValue)
{
  ::ad::physics::Speed const invalidValue(std::numeric_limits<double>::quiet_NaN());
  ::ad::physics::Speed value(invalidValue);
  EXPECT_FALSE(value.isValid());
}

TEST(SpeedTests, assignmentFromInvalidValue)
{
  ::ad::physics::Speed const invalidValue(std::numeric_limits<double>::quiet_NaN());
  ::ad::physics::Speed value;
  value = invalidValue;
  EXPECT_FALSE(value.isValid());
}

TEST(SpeedTests, selfAssignment)
{
  ::ad::physics::Speed value(::ad::physics::Speed::cMinValue);
  EXPECT_TRUE(value.isValid());
  value = value;
  EXPECT_TRUE(value.isValid());
}

TEST(SpeedTests, ostreamOperatorTest)
{
  std::stringstream stream;
  ::ad::physics::Speed value;
  stream << value;
  ASSERT_GT(stream.str().size(), 0u);
}

#if (AD_PHYSICS_SPEED_THROWS_EXCEPTION == 1)
TEST(SpeedTests, comparisonOperatorsThrowOnInvalid)
{
  ::ad::physics::Speed const value(::ad::physics::Speed::cMinValue);
  ::ad::physics::Speed const invalidValue;

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

TEST(SpeedTests, arithmeticOperatorsThrowOnInvalid)
{
  ::ad::physics::Speed const minimalValue(::ad::physics::Speed::cMinValue);
  ::ad::physics::Speed const maximalValue(::ad::physics::Speed::cMaxValue);
  ::ad::physics::Speed const invalidValue;
  ::ad::physics::Speed calculationValue;

  //  operator+(::ad::physics::Speed)
  EXPECT_THROW(invalidValue + maximalValue, std::out_of_range);
  EXPECT_THROW(maximalValue + invalidValue, std::out_of_range);
  EXPECT_EQ(maximalValue + maximalValue, maximalValue);

  //  operator+=(::ad::physics::Speed)
  calculationValue = invalidValue;
  EXPECT_THROW(calculationValue += maximalValue, std::out_of_range);
  calculationValue = maximalValue;
  EXPECT_THROW(calculationValue += invalidValue, std::out_of_range);
  calculationValue = maximalValue;
  EXPECT_EQ(calculationValue += maximalValue, maximalValue);

  //  operator-(::ad::physics::Speed)
  EXPECT_THROW(invalidValue - minimalValue, std::out_of_range);
  EXPECT_THROW(minimalValue - invalidValue, std::out_of_range);
  EXPECT_EQ(minimalValue - maximalValue, minimalValue);

  //  operator-=(::ad::physics::Speed)
  calculationValue = invalidValue;
  EXPECT_THROW(calculationValue -= minimalValue, std::out_of_range);
  calculationValue = minimalValue;
  EXPECT_THROW(calculationValue -= invalidValue, std::out_of_range);
  calculationValue = minimalValue;
  EXPECT_EQ(calculationValue -= maximalValue, minimalValue);

  //  operator*(double)
  EXPECT_THROW(invalidValue * maximalValue.mSpeed, std::out_of_range);
  EXPECT_EQ(maximalValue * maximalValue.mSpeed, maximalValue);

  //  operator*(::ad::physics::Speed)
  EXPECT_THROW(invalidValue * maximalValue, std::out_of_range);
  EXPECT_THROW(maximalValue * invalidValue, std::out_of_range);

  //  operator/(double)
  EXPECT_THROW(invalidValue / maximalValue.mSpeed, std::out_of_range);
  EXPECT_THROW(maximalValue / invalidValue.mSpeed, std::out_of_range);
  EXPECT_THROW(maximalValue / 0.0, std::out_of_range);
  EXPECT_EQ(maximalValue / 0.5, maximalValue);

  //  operator/(::ad::physics::Speed)
  EXPECT_THROW(invalidValue / maximalValue, std::out_of_range);
  EXPECT_THROW(maximalValue / invalidValue, std::out_of_range);
  EXPECT_THROW(maximalValue / ::ad::physics::Speed(0.0), std::out_of_range);

  //  operator-()
  EXPECT_THROW(-invalidValue, std::out_of_range);
  if (std::fabs(maximalValue.mSpeed) > std::fabs(minimalValue.mSpeed))
  {
    EXPECT_EQ(-maximalValue, minimalValue);
  }
  else if (std::fabs(maximalValue.mSpeed) < std::fabs(minimalValue.mSpeed))
  {
    EXPECT_EQ(-minimalValue, maximalValue);
  }
  else
  {
    // impossible to trigger invalid result while operand is valid
  }
}
#endif

TEST(SpeedTests, comparisonOperatorsRespectPrecision)
{
  double const precisionValueTimesTen = ::ad::physics::Speed::cPrecisionValue * 10.;
  ::ad::physics::Speed value;
  if (::ad::physics::Speed::cMinValue > precisionValueTimesTen)
  {
    value = ::ad::physics::Speed(::ad::physics::Speed::cMinValue + precisionValueTimesTen);
  }
  else if (::ad::physics::Speed::cMaxValue < precisionValueTimesTen)
  {
    value = ::ad::physics::Speed(::ad::physics::Speed::cMaxValue - precisionValueTimesTen);
  }
  else
  {
    value = ::ad::physics::Speed(precisionValueTimesTen);
  }
  ::ad::physics::Speed const sameValue = value;
  ::ad::physics::Speed const slightlyBiggerValue(value.mSpeed + ::ad::physics::Speed::cPrecisionValue * 0.9);
  ::ad::physics::Speed const slightlySmallerValue(value.mSpeed - ::ad::physics::Speed::cPrecisionValue * 0.9);
  ::ad::physics::Speed const actuallyBiggerValue(value.mSpeed + ::ad::physics::Speed::cPrecisionValue * 1.1);
  ::ad::physics::Speed const actuallySmallerValue(value.mSpeed - ::ad::physics::Speed::cPrecisionValue * 1.1);

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

TEST(SpeedTests, arithmeticOperatorsComputeCorrectly)
{
  double const cDoubleNear = ::ad::physics::Speed::cPrecisionValue;
  double const precisionValueTimesTen = ::ad::physics::Speed::cPrecisionValue * 10.;
  ::ad::physics::Speed value;
  if (::ad::physics::Speed::cMinValue > precisionValueTimesTen)
  {
    value = ::ad::physics::Speed(::ad::physics::Speed::cMinValue + precisionValueTimesTen);
  }
  else if (::ad::physics::Speed::cMaxValue < precisionValueTimesTen)
  {
    value = ::ad::physics::Speed(::ad::physics::Speed::cMaxValue - precisionValueTimesTen);
  }
  else
  {
    value = ::ad::physics::Speed(precisionValueTimesTen);
  }

  ::ad::physics::Speed result;

  //  operator+(::ad::physics::Speed)
  result = value + value;
  EXPECT_NEAR(value.mSpeed + value.mSpeed, result.mSpeed, cDoubleNear);

  //  operator+=(::ad::physics::Speed)
  result = value;
  result += value;
  EXPECT_NEAR(value.mSpeed + value.mSpeed, result.mSpeed, cDoubleNear);

  //  operator-(::ad::physics::Speed)
  result = value - value;
  EXPECT_NEAR(value.mSpeed - value.mSpeed, result.mSpeed, cDoubleNear);

  //  operator-=(::ad::physics::Speed)
  result = value;
  result -= value;
  EXPECT_NEAR(value.mSpeed - value.mSpeed, result.mSpeed, cDoubleNear);

  //  operator*(double)
  result = value * 5.;
  EXPECT_NEAR(value.mSpeed * 5., result.mSpeed, cDoubleNear);

  //  operator*(::ad::physics::Speed)
  ::ad::physics::SpeedSquared const squaredResult = value * value;
  EXPECT_NEAR(value.mSpeed * value.mSpeed, squaredResult.mSpeedSquared, cDoubleNear);

  //  operator*(double, ::ad::physics::Speed)
  result = 5. * value;
  EXPECT_NEAR(value.mSpeed * 5., result.mSpeed, cDoubleNear);

  //  operator/(double)
  result = value / value.mSpeed;
  EXPECT_NEAR(value.mSpeed / value.mSpeed, result.mSpeed, cDoubleNear);

  //  operator/(::ad::physics::Speed)
  double const doubleResult = value / value;
  EXPECT_NEAR(value.mSpeed / value.mSpeed, doubleResult, cDoubleNear);

  //  operator-()
  if ((::ad::physics::Speed::cMinValue < -value.mSpeed) && (-value.mSpeed < ::ad::physics::Speed::cMaxValue))
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
