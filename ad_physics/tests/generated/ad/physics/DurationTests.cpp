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
#include "ad/physics/Duration.hpp"
#include "ad/physics/DurationSquared.hpp"

TEST(DurationTests, defaultConstructionIsInvalid)
{
  ::ad::physics::Duration value;
  EXPECT_FALSE(value.isValid());
}

TEST(DurationTests, minIsDefinedAsExpected)
{
  EXPECT_DOUBLE_EQ(-1e6, ::ad::physics::Duration::cMinValue);
  EXPECT_DOUBLE_EQ(::ad::physics::Duration::cMinValue, ::ad::physics::Duration::getMin().mDuration);
}

TEST(DurationTests, maxIsDefinedAsExpected)
{
  EXPECT_DOUBLE_EQ(1e6, ::ad::physics::Duration::cMaxValue);
  EXPECT_DOUBLE_EQ(::ad::physics::Duration::cMaxValue, ::ad::physics::Duration::getMax().mDuration);
}

TEST(DurationTests, precisionIsDefinedAsExpected)
{
  EXPECT_LT(0., ::ad::physics::Duration::cPrecisionValue);
  EXPECT_DOUBLE_EQ(1e-3, ::ad::physics::Duration::cPrecisionValue);
  EXPECT_DOUBLE_EQ(::ad::physics::Duration::cPrecisionValue, ::ad::physics::Duration::getPrecision().mDuration);
}

TEST(DurationTests, minIsValid)
{
  EXPECT_TRUE(::ad::physics::Duration::getMin().isValid());
}

TEST(DurationTests, aboveMinIsValid)
{
  ::ad::physics::Duration value(::ad::physics::Duration::cMinValue * 0.9);
  EXPECT_TRUE(value.isValid());
}

TEST(DurationTests, belowMinIsInvalid)
{
  ::ad::physics::Duration value(::ad::physics::Duration::cMinValue * 1.1);
  EXPECT_FALSE(value.isValid());
}

TEST(DurationTests, maxIsValid)
{
  EXPECT_TRUE(::ad::physics::Duration::getMax().isValid());
}

TEST(DurationTests, aboveMaxIsInvalid)
{
  ::ad::physics::Duration value(::ad::physics::Duration::cMaxValue * 1.1);
  EXPECT_FALSE(value.isValid());
}

TEST(DurationTests, belowMaxIsValid)
{
  ::ad::physics::Duration value(::ad::physics::Duration::cMaxValue * 0.9);
  EXPECT_TRUE(value.isValid());
}

#if (AD_PHYSICS_DURATION_THROWS_EXCEPTION == 1)
TEST(DurationTests, ensureValidThrowsOnInvalid)
{
  ::ad::physics::Duration value;
  EXPECT_THROW(value.ensureValid(), std::out_of_range);
}

TEST(DurationTests, ensureValidNonZeroThrowsOnInvalid)
{
  ::ad::physics::Duration value;
  EXPECT_THROW(value.ensureValidNonZero(), std::out_of_range);
}

TEST(DurationTests, ensureValidNonZeroThrowsOnZero)
{
  ::ad::physics::Duration value(0.);
  EXPECT_THROW(value.ensureValidNonZero(), std::out_of_range);
}
#endif

TEST(DurationTestsStd, numericLimitsLowestIsMin)
{
  EXPECT_DOUBLE_EQ(::ad::physics::Duration::getMin().mDuration,
                   std::numeric_limits<::ad::physics::Duration>::lowest().mDuration);
}

TEST(DurationTestsStd, numericLimitsMaxIsMax)
{
  EXPECT_DOUBLE_EQ(::ad::physics::Duration::getMax().mDuration,
                   std::numeric_limits<::ad::physics::Duration>::max().mDuration);
}

TEST(DurationTestsStd, numericLimitsEpsilonIsPrecision)
{
  EXPECT_DOUBLE_EQ(::ad::physics::Duration::getPrecision().mDuration,
                   std::numeric_limits<::ad::physics::Duration>::epsilon().mDuration);
}

TEST(DurationTestsStd, fabsIsWorkingCorrectly)
{
  EXPECT_DOUBLE_EQ(0., std::fabs(::ad::physics::Duration(-0.)).mDuration);
  EXPECT_DOUBLE_EQ(1., std::fabs(::ad::physics::Duration(-1.)).mDuration);
  EXPECT_DOUBLE_EQ(::ad::physics::Duration::cPrecisionValue,
                   std::fabs(::ad::physics::Duration(::ad::physics::Duration::cPrecisionValue).mDuration));
  EXPECT_DOUBLE_EQ(std::fabs(::ad::physics::Duration::cMinValue),
                   std::fabs(::ad::physics::Duration(::ad::physics::Duration::cMinValue).mDuration));
  EXPECT_DOUBLE_EQ(std::fabs(::ad::physics::Duration::cMinValue),
                   std::fabs(::ad::physics::Duration(-::ad::physics::Duration::cMinValue).mDuration));
  EXPECT_DOUBLE_EQ(std::fabs(::ad::physics::Duration::cMaxValue),
                   std::fabs(::ad::physics::Duration(::ad::physics::Duration::cMaxValue).mDuration));
  EXPECT_DOUBLE_EQ(std::fabs(::ad::physics::Duration::cMaxValue),
                   std::fabs(::ad::physics::Duration(-::ad::physics::Duration::cMaxValue).mDuration));
}

TEST(DurationTests, constructionFromValidFPValue)
{
  double const validValue = ::ad::physics::Duration::cMinValue;
  ::ad::physics::Duration value(validValue);
  EXPECT_TRUE(value.isValid());
  EXPECT_DOUBLE_EQ(validValue, value.mDuration);
}

TEST(DurationTests, copyConstructionFromValidValue)
{
  ::ad::physics::Duration const validValue(::ad::physics::Duration::cMinValue);
  ::ad::physics::Duration value(validValue);
  EXPECT_TRUE(value.isValid());
  EXPECT_DOUBLE_EQ(validValue.mDuration, value.mDuration);
}

TEST(DurationTests, moveConstructionFromValidValue)
{
  ::ad::physics::Duration validValue(::ad::physics::Duration::cMinValue);
  ::ad::physics::Duration value(std::move(validValue));
  EXPECT_TRUE(value.isValid());
  EXPECT_DOUBLE_EQ(::ad::physics::Duration::cMinValue, value.mDuration);
}

TEST(DurationTests, assignmentFromValidValue)
{
  ::ad::physics::Duration const validValue(::ad::physics::Duration::cMinValue);
  ::ad::physics::Duration value;
  value = validValue;
  EXPECT_TRUE(value.isValid());
  EXPECT_DOUBLE_EQ(validValue.mDuration, value.mDuration);
}

TEST(DurationTests, moveAssignmentFromValidValue)
{
  ::ad::physics::Duration validValue(::ad::physics::Duration::cMinValue);
  ::ad::physics::Duration value;
  value = std::move(validValue);
  EXPECT_TRUE(value.isValid());
  EXPECT_DOUBLE_EQ(::ad::physics::Duration::cMinValue, value.mDuration);
}

TEST(DurationTests, constructionFromInvalidFPValue)
{
  double const invalidValue = std::numeric_limits<double>::quiet_NaN();
  ::ad::physics::Duration value(invalidValue);
  EXPECT_FALSE(value.isValid());
}

TEST(DurationTests, copyConstructionFromInvalidValue)
{
  ::ad::physics::Duration const invalidValue(std::numeric_limits<double>::quiet_NaN());
  ::ad::physics::Duration value(invalidValue);
  EXPECT_FALSE(value.isValid());
}

TEST(DurationTests, assignmentFromInvalidValue)
{
  ::ad::physics::Duration const invalidValue(std::numeric_limits<double>::quiet_NaN());
  ::ad::physics::Duration value;
  value = invalidValue;
  EXPECT_FALSE(value.isValid());
}

TEST(DurationTests, selfAssignment)
{
  ::ad::physics::Duration value(::ad::physics::Duration::cMinValue);
  EXPECT_TRUE(value.isValid());
  value = value;
  EXPECT_TRUE(value.isValid());
}

TEST(DurationTests, ostreamOperatorTest)
{
  std::stringstream stream;
  ::ad::physics::Duration value;
  stream << value;
  ASSERT_GT(stream.str().size(), 0u);
}

#if (AD_PHYSICS_DURATION_THROWS_EXCEPTION == 1)
TEST(DurationTests, comparisonOperatorsThrowOnInvalid)
{
  ::ad::physics::Duration const value(::ad::physics::Duration::cMinValue);
  ::ad::physics::Duration const invalidValue;

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

TEST(DurationTests, arithmeticOperatorsThrowOnInvalid)
{
  ::ad::physics::Duration const minimalValue(::ad::physics::Duration::cMinValue);
  ::ad::physics::Duration const maximalValue(::ad::physics::Duration::cMaxValue);
  ::ad::physics::Duration const invalidValue;
  ::ad::physics::Duration calculationValue;

  //  operator+(::ad::physics::Duration)
  EXPECT_THROW(invalidValue + maximalValue, std::out_of_range);
  EXPECT_THROW(maximalValue + invalidValue, std::out_of_range);
  EXPECT_EQ(maximalValue + maximalValue, maximalValue);

  //  operator+=(::ad::physics::Duration)
  calculationValue = invalidValue;
  EXPECT_THROW(calculationValue += maximalValue, std::out_of_range);
  calculationValue = maximalValue;
  EXPECT_THROW(calculationValue += invalidValue, std::out_of_range);
  calculationValue = maximalValue;
  EXPECT_EQ(calculationValue += maximalValue, maximalValue);

  //  operator-(::ad::physics::Duration)
  EXPECT_THROW(invalidValue - minimalValue, std::out_of_range);
  EXPECT_THROW(minimalValue - invalidValue, std::out_of_range);
  EXPECT_EQ(minimalValue - maximalValue, minimalValue);

  //  operator-=(::ad::physics::Duration)
  calculationValue = invalidValue;
  EXPECT_THROW(calculationValue -= minimalValue, std::out_of_range);
  calculationValue = minimalValue;
  EXPECT_THROW(calculationValue -= invalidValue, std::out_of_range);
  calculationValue = minimalValue;
  EXPECT_EQ(calculationValue -= maximalValue, minimalValue);

  //  operator*(double)
  EXPECT_THROW(invalidValue * maximalValue.mDuration, std::out_of_range);
  EXPECT_EQ(maximalValue * maximalValue.mDuration, maximalValue);

  //  operator*(::ad::physics::Duration)
  EXPECT_THROW(invalidValue * maximalValue, std::out_of_range);
  EXPECT_THROW(maximalValue * invalidValue, std::out_of_range);

  //  operator/(double)
  EXPECT_THROW(invalidValue / maximalValue.mDuration, std::out_of_range);
  EXPECT_THROW(maximalValue / invalidValue.mDuration, std::out_of_range);
  EXPECT_THROW(maximalValue / 0.0, std::out_of_range);
  EXPECT_EQ(maximalValue / 0.5, maximalValue);

  //  operator/(::ad::physics::Duration)
  EXPECT_THROW(invalidValue / maximalValue, std::out_of_range);
  EXPECT_THROW(maximalValue / invalidValue, std::out_of_range);
  EXPECT_THROW(maximalValue / ::ad::physics::Duration(0.0), std::out_of_range);

  //  operator-()
  EXPECT_THROW(-invalidValue, std::out_of_range);
  if (std::fabs(maximalValue.mDuration) > std::fabs(minimalValue.mDuration))
  {
    EXPECT_EQ(-maximalValue, minimalValue);
  }
  else if (std::fabs(maximalValue.mDuration) < std::fabs(minimalValue.mDuration))
  {
    EXPECT_EQ(-minimalValue, maximalValue);
  }
  else
  {
    // impossible to trigger invalid result while operand is valid
  }
}
#endif

TEST(DurationTests, comparisonOperatorsRespectPrecision)
{
  double const precisionValueTimesTen = ::ad::physics::Duration::cPrecisionValue * 10.;
  ::ad::physics::Duration value;
  if (::ad::physics::Duration::cMinValue > precisionValueTimesTen)
  {
    value = ::ad::physics::Duration(::ad::physics::Duration::cMinValue + precisionValueTimesTen);
  }
  else if (::ad::physics::Duration::cMaxValue < precisionValueTimesTen)
  {
    value = ::ad::physics::Duration(::ad::physics::Duration::cMaxValue - precisionValueTimesTen);
  }
  else
  {
    value = ::ad::physics::Duration(precisionValueTimesTen);
  }
  ::ad::physics::Duration const sameValue = value;
  ::ad::physics::Duration const slightlyBiggerValue(value.mDuration + ::ad::physics::Duration::cPrecisionValue * 0.9);
  ::ad::physics::Duration const slightlySmallerValue(value.mDuration - ::ad::physics::Duration::cPrecisionValue * 0.9);
  ::ad::physics::Duration const actuallyBiggerValue(value.mDuration + ::ad::physics::Duration::cPrecisionValue * 1.1);
  ::ad::physics::Duration const actuallySmallerValue(value.mDuration - ::ad::physics::Duration::cPrecisionValue * 1.1);

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

TEST(DurationTests, arithmeticOperatorsComputeCorrectly)
{
  double const cDoubleNear = ::ad::physics::Duration::cPrecisionValue;
  double const precisionValueTimesTen = ::ad::physics::Duration::cPrecisionValue * 10.;
  ::ad::physics::Duration value;
  if (::ad::physics::Duration::cMinValue > precisionValueTimesTen)
  {
    value = ::ad::physics::Duration(::ad::physics::Duration::cMinValue + precisionValueTimesTen);
  }
  else if (::ad::physics::Duration::cMaxValue < precisionValueTimesTen)
  {
    value = ::ad::physics::Duration(::ad::physics::Duration::cMaxValue - precisionValueTimesTen);
  }
  else
  {
    value = ::ad::physics::Duration(precisionValueTimesTen);
  }

  ::ad::physics::Duration result;

  //  operator+(::ad::physics::Duration)
  result = value + value;
  EXPECT_NEAR(value.mDuration + value.mDuration, result.mDuration, cDoubleNear);

  //  operator+=(::ad::physics::Duration)
  result = value;
  result += value;
  EXPECT_NEAR(value.mDuration + value.mDuration, result.mDuration, cDoubleNear);

  //  operator-(::ad::physics::Duration)
  result = value - value;
  EXPECT_NEAR(value.mDuration - value.mDuration, result.mDuration, cDoubleNear);

  //  operator-=(::ad::physics::Duration)
  result = value;
  result -= value;
  EXPECT_NEAR(value.mDuration - value.mDuration, result.mDuration, cDoubleNear);

  //  operator*(double)
  result = value * 5.;
  EXPECT_NEAR(value.mDuration * 5., result.mDuration, cDoubleNear);

  //  operator*(::ad::physics::Duration)
  ::ad::physics::DurationSquared const squaredResult = value * value;
  EXPECT_NEAR(value.mDuration * value.mDuration, squaredResult.mDurationSquared, cDoubleNear);

  //  operator*(double, ::ad::physics::Duration)
  result = 5. * value;
  EXPECT_NEAR(value.mDuration * 5., result.mDuration, cDoubleNear);

  //  operator/(double)
  result = value / value.mDuration;
  EXPECT_NEAR(value.mDuration / value.mDuration, result.mDuration, cDoubleNear);

  //  operator/(::ad::physics::Duration)
  double const doubleResult = value / value;
  EXPECT_NEAR(value.mDuration / value.mDuration, doubleResult, cDoubleNear);

  //  operator-()
  if ((::ad::physics::Duration::cMinValue < -value.mDuration)
      && (-value.mDuration < ::ad::physics::Duration::cMaxValue))
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
