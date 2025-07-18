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
#include "ad/physics/AngularVelocity.hpp"

TEST(AngularVelocityTests, defaultConstructionIsInvalid)
{
  ::ad::physics::AngularVelocity value;
  EXPECT_FALSE(value.isValid());
}

TEST(AngularVelocityTests, minIsDefinedAsExpected)
{
  EXPECT_DOUBLE_EQ(-1e3, ::ad::physics::AngularVelocity::cMinValue);
  EXPECT_DOUBLE_EQ(::ad::physics::AngularVelocity::cMinValue,
                   ::ad::physics::AngularVelocity::getMin().mAngularVelocity);
}

TEST(AngularVelocityTests, maxIsDefinedAsExpected)
{
  EXPECT_DOUBLE_EQ(1e3, ::ad::physics::AngularVelocity::cMaxValue);
  EXPECT_DOUBLE_EQ(::ad::physics::AngularVelocity::cMaxValue,
                   ::ad::physics::AngularVelocity::getMax().mAngularVelocity);
}

TEST(AngularVelocityTests, precisionIsDefinedAsExpected)
{
  EXPECT_LT(0., ::ad::physics::AngularVelocity::cPrecisionValue);
  EXPECT_DOUBLE_EQ(1e-3, ::ad::physics::AngularVelocity::cPrecisionValue);
  EXPECT_DOUBLE_EQ(::ad::physics::AngularVelocity::cPrecisionValue,
                   ::ad::physics::AngularVelocity::getPrecision().mAngularVelocity);
}

TEST(AngularVelocityTests, minIsValid)
{
  EXPECT_TRUE(::ad::physics::AngularVelocity::getMin().isValid());
}

TEST(AngularVelocityTests, aboveMinIsValid)
{
  ::ad::physics::AngularVelocity value(::ad::physics::AngularVelocity::cMinValue * 0.9);
  EXPECT_TRUE(value.isValid());
}

TEST(AngularVelocityTests, belowMinIsInvalid)
{
  ::ad::physics::AngularVelocity value(::ad::physics::AngularVelocity::cMinValue * 1.1);
  EXPECT_FALSE(value.isValid());
}

TEST(AngularVelocityTests, maxIsValid)
{
  EXPECT_TRUE(::ad::physics::AngularVelocity::getMax().isValid());
}

TEST(AngularVelocityTests, aboveMaxIsInvalid)
{
  ::ad::physics::AngularVelocity value(::ad::physics::AngularVelocity::cMaxValue * 1.1);
  EXPECT_FALSE(value.isValid());
}

TEST(AngularVelocityTests, belowMaxIsValid)
{
  ::ad::physics::AngularVelocity value(::ad::physics::AngularVelocity::cMaxValue * 0.9);
  EXPECT_TRUE(value.isValid());
}

#if (AD_PHYSICS_ANGULARVELOCITY_THROWS_EXCEPTION == 1)
TEST(AngularVelocityTests, ensureValidThrowsOnInvalid)
{
  ::ad::physics::AngularVelocity value;
  EXPECT_THROW(value.ensureValid(), std::out_of_range);
}

TEST(AngularVelocityTests, ensureValidNonZeroThrowsOnInvalid)
{
  ::ad::physics::AngularVelocity value;
  EXPECT_THROW(value.ensureValidNonZero(), std::out_of_range);
}

TEST(AngularVelocityTests, ensureValidNonZeroThrowsOnZero)
{
  ::ad::physics::AngularVelocity value(0.);
  EXPECT_THROW(value.ensureValidNonZero(), std::out_of_range);
}
#endif

TEST(AngularVelocityTestsStd, numericLimitsLowestIsMin)
{
  EXPECT_DOUBLE_EQ(::ad::physics::AngularVelocity::getMin().mAngularVelocity,
                   std::numeric_limits<::ad::physics::AngularVelocity>::lowest().mAngularVelocity);
}

TEST(AngularVelocityTestsStd, numericLimitsMaxIsMax)
{
  EXPECT_DOUBLE_EQ(::ad::physics::AngularVelocity::getMax().mAngularVelocity,
                   std::numeric_limits<::ad::physics::AngularVelocity>::max().mAngularVelocity);
}

TEST(AngularVelocityTestsStd, numericLimitsEpsilonIsPrecision)
{
  EXPECT_DOUBLE_EQ(::ad::physics::AngularVelocity::getPrecision().mAngularVelocity,
                   std::numeric_limits<::ad::physics::AngularVelocity>::epsilon().mAngularVelocity);
}

TEST(AngularVelocityTestsStd, fabsIsWorkingCorrectly)
{
  EXPECT_DOUBLE_EQ(0., std::fabs(::ad::physics::AngularVelocity(-0.)).mAngularVelocity);
  EXPECT_DOUBLE_EQ(1., std::fabs(::ad::physics::AngularVelocity(-1.)).mAngularVelocity);
  EXPECT_DOUBLE_EQ(
    ::ad::physics::AngularVelocity::cPrecisionValue,
    std::fabs(::ad::physics::AngularVelocity(::ad::physics::AngularVelocity::cPrecisionValue).mAngularVelocity));
  EXPECT_DOUBLE_EQ(
    std::fabs(::ad::physics::AngularVelocity::cMinValue),
    std::fabs(::ad::physics::AngularVelocity(::ad::physics::AngularVelocity::cMinValue).mAngularVelocity));
  EXPECT_DOUBLE_EQ(
    std::fabs(::ad::physics::AngularVelocity::cMinValue),
    std::fabs(::ad::physics::AngularVelocity(-::ad::physics::AngularVelocity::cMinValue).mAngularVelocity));
  EXPECT_DOUBLE_EQ(
    std::fabs(::ad::physics::AngularVelocity::cMaxValue),
    std::fabs(::ad::physics::AngularVelocity(::ad::physics::AngularVelocity::cMaxValue).mAngularVelocity));
  EXPECT_DOUBLE_EQ(
    std::fabs(::ad::physics::AngularVelocity::cMaxValue),
    std::fabs(::ad::physics::AngularVelocity(-::ad::physics::AngularVelocity::cMaxValue).mAngularVelocity));
}

TEST(AngularVelocityTests, constructionFromValidFPValue)
{
  double const validValue = ::ad::physics::AngularVelocity::cMinValue;
  ::ad::physics::AngularVelocity value(validValue);
  EXPECT_TRUE(value.isValid());
  EXPECT_DOUBLE_EQ(validValue, value.mAngularVelocity);
}

TEST(AngularVelocityTests, copyConstructionFromValidValue)
{
  ::ad::physics::AngularVelocity const validValue(::ad::physics::AngularVelocity::cMinValue);
  ::ad::physics::AngularVelocity value(validValue);
  EXPECT_TRUE(value.isValid());
  EXPECT_DOUBLE_EQ(validValue.mAngularVelocity, value.mAngularVelocity);
}

TEST(AngularVelocityTests, moveConstructionFromValidValue)
{
  ::ad::physics::AngularVelocity validValue(::ad::physics::AngularVelocity::cMinValue);
  ::ad::physics::AngularVelocity value(std::move(validValue));
  EXPECT_TRUE(value.isValid());
  EXPECT_DOUBLE_EQ(::ad::physics::AngularVelocity::cMinValue, value.mAngularVelocity);
}

TEST(AngularVelocityTests, assignmentFromValidValue)
{
  ::ad::physics::AngularVelocity const validValue(::ad::physics::AngularVelocity::cMinValue);
  ::ad::physics::AngularVelocity value;
  value = validValue;
  EXPECT_TRUE(value.isValid());
  EXPECT_DOUBLE_EQ(validValue.mAngularVelocity, value.mAngularVelocity);
}

TEST(AngularVelocityTests, moveAssignmentFromValidValue)
{
  ::ad::physics::AngularVelocity validValue(::ad::physics::AngularVelocity::cMinValue);
  ::ad::physics::AngularVelocity value;
  value = std::move(validValue);
  EXPECT_TRUE(value.isValid());
  EXPECT_DOUBLE_EQ(::ad::physics::AngularVelocity::cMinValue, value.mAngularVelocity);
}

TEST(AngularVelocityTests, constructionFromInvalidFPValue)
{
  double const invalidValue = std::numeric_limits<double>::quiet_NaN();
  ::ad::physics::AngularVelocity value(invalidValue);
  EXPECT_FALSE(value.isValid());
}

TEST(AngularVelocityTests, copyConstructionFromInvalidValue)
{
  ::ad::physics::AngularVelocity const invalidValue(std::numeric_limits<double>::quiet_NaN());
  ::ad::physics::AngularVelocity value(invalidValue);
  EXPECT_FALSE(value.isValid());
}

TEST(AngularVelocityTests, assignmentFromInvalidValue)
{
  ::ad::physics::AngularVelocity const invalidValue(std::numeric_limits<double>::quiet_NaN());
  ::ad::physics::AngularVelocity value;
  value = invalidValue;
  EXPECT_FALSE(value.isValid());
}

TEST(AngularVelocityTests, selfAssignment)
{
  ::ad::physics::AngularVelocity value(::ad::physics::AngularVelocity::cMinValue);
  EXPECT_TRUE(value.isValid());
  value = value;
  EXPECT_TRUE(value.isValid());
}

TEST(AngularVelocityTests, ostreamOperatorTest)
{
  std::stringstream stream;
  ::ad::physics::AngularVelocity value;
  stream << value;
  ASSERT_GT(stream.str().size(), 0u);
}

#if (AD_PHYSICS_ANGULARVELOCITY_THROWS_EXCEPTION == 1)
TEST(AngularVelocityTests, comparisonOperatorsThrowOnInvalid)
{
  ::ad::physics::AngularVelocity const value(::ad::physics::AngularVelocity::cMinValue);
  ::ad::physics::AngularVelocity const invalidValue;

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

TEST(AngularVelocityTests, arithmeticOperatorsThrowOnInvalid)
{
  ::ad::physics::AngularVelocity const minimalValue(::ad::physics::AngularVelocity::cMinValue);
  ::ad::physics::AngularVelocity const maximalValue(::ad::physics::AngularVelocity::cMaxValue);
  ::ad::physics::AngularVelocity const invalidValue;
  ::ad::physics::AngularVelocity calculationValue;

  //  operator+(::ad::physics::AngularVelocity)
  EXPECT_THROW(invalidValue + maximalValue, std::out_of_range);
  EXPECT_THROW(maximalValue + invalidValue, std::out_of_range);
  EXPECT_EQ(maximalValue + maximalValue, maximalValue);

  //  operator+=(::ad::physics::AngularVelocity)
  calculationValue = invalidValue;
  EXPECT_THROW(calculationValue += maximalValue, std::out_of_range);
  calculationValue = maximalValue;
  EXPECT_THROW(calculationValue += invalidValue, std::out_of_range);
  calculationValue = maximalValue;
  EXPECT_EQ(calculationValue += maximalValue, maximalValue);

  //  operator-(::ad::physics::AngularVelocity)
  EXPECT_THROW(invalidValue - minimalValue, std::out_of_range);
  EXPECT_THROW(minimalValue - invalidValue, std::out_of_range);
  EXPECT_EQ(minimalValue - maximalValue, minimalValue);

  //  operator-=(::ad::physics::AngularVelocity)
  calculationValue = invalidValue;
  EXPECT_THROW(calculationValue -= minimalValue, std::out_of_range);
  calculationValue = minimalValue;
  EXPECT_THROW(calculationValue -= invalidValue, std::out_of_range);
  calculationValue = minimalValue;
  EXPECT_EQ(calculationValue -= maximalValue, minimalValue);

  //  operator*(double)
  EXPECT_THROW(invalidValue * maximalValue.mAngularVelocity, std::out_of_range);
  EXPECT_EQ(maximalValue * maximalValue.mAngularVelocity, maximalValue);

  //  operator/(double)
  EXPECT_THROW(invalidValue / maximalValue.mAngularVelocity, std::out_of_range);
  EXPECT_THROW(maximalValue / invalidValue.mAngularVelocity, std::out_of_range);
  EXPECT_THROW(maximalValue / 0.0, std::out_of_range);
  EXPECT_EQ(maximalValue / 0.5, maximalValue);

  //  operator/(::ad::physics::AngularVelocity)
  EXPECT_THROW(invalidValue / maximalValue, std::out_of_range);
  EXPECT_THROW(maximalValue / invalidValue, std::out_of_range);
  EXPECT_THROW(maximalValue / ::ad::physics::AngularVelocity(0.0), std::out_of_range);

  //  operator-()
  EXPECT_THROW(-invalidValue, std::out_of_range);
  if (std::fabs(maximalValue.mAngularVelocity) > std::fabs(minimalValue.mAngularVelocity))
  {
    EXPECT_EQ(-maximalValue, minimalValue);
  }
  else if (std::fabs(maximalValue.mAngularVelocity) < std::fabs(minimalValue.mAngularVelocity))
  {
    EXPECT_EQ(-minimalValue, maximalValue);
  }
  else
  {
    // impossible to trigger invalid result while operand is valid
  }
}
#endif

TEST(AngularVelocityTests, comparisonOperatorsRespectPrecision)
{
  double const precisionValueTimesTen = ::ad::physics::AngularVelocity::cPrecisionValue * 10.;
  ::ad::physics::AngularVelocity value;
  if (::ad::physics::AngularVelocity::cMinValue > precisionValueTimesTen)
  {
    value = ::ad::physics::AngularVelocity(::ad::physics::AngularVelocity::cMinValue + precisionValueTimesTen);
  }
  else if (::ad::physics::AngularVelocity::cMaxValue < precisionValueTimesTen)
  {
    value = ::ad::physics::AngularVelocity(::ad::physics::AngularVelocity::cMaxValue - precisionValueTimesTen);
  }
  else
  {
    value = ::ad::physics::AngularVelocity(precisionValueTimesTen);
  }
  ::ad::physics::AngularVelocity const sameValue = value;
  ::ad::physics::AngularVelocity const slightlyBiggerValue(value.mAngularVelocity
                                                           + ::ad::physics::AngularVelocity::cPrecisionValue * 0.9);
  ::ad::physics::AngularVelocity const slightlySmallerValue(value.mAngularVelocity
                                                            - ::ad::physics::AngularVelocity::cPrecisionValue * 0.9);
  ::ad::physics::AngularVelocity const actuallyBiggerValue(value.mAngularVelocity
                                                           + ::ad::physics::AngularVelocity::cPrecisionValue * 1.1);
  ::ad::physics::AngularVelocity const actuallySmallerValue(value.mAngularVelocity
                                                            - ::ad::physics::AngularVelocity::cPrecisionValue * 1.1);

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

TEST(AngularVelocityTests, arithmeticOperatorsComputeCorrectly)
{
  double const cDoubleNear = ::ad::physics::AngularVelocity::cPrecisionValue;
  double const precisionValueTimesTen = ::ad::physics::AngularVelocity::cPrecisionValue * 10.;
  ::ad::physics::AngularVelocity value;
  if (::ad::physics::AngularVelocity::cMinValue > precisionValueTimesTen)
  {
    value = ::ad::physics::AngularVelocity(::ad::physics::AngularVelocity::cMinValue + precisionValueTimesTen);
  }
  else if (::ad::physics::AngularVelocity::cMaxValue < precisionValueTimesTen)
  {
    value = ::ad::physics::AngularVelocity(::ad::physics::AngularVelocity::cMaxValue - precisionValueTimesTen);
  }
  else
  {
    value = ::ad::physics::AngularVelocity(precisionValueTimesTen);
  }

  ::ad::physics::AngularVelocity result;

  //  operator+(::ad::physics::AngularVelocity)
  result = value + value;
  EXPECT_NEAR(value.mAngularVelocity + value.mAngularVelocity, result.mAngularVelocity, cDoubleNear);

  //  operator+=(::ad::physics::AngularVelocity)
  result = value;
  result += value;
  EXPECT_NEAR(value.mAngularVelocity + value.mAngularVelocity, result.mAngularVelocity, cDoubleNear);

  //  operator-(::ad::physics::AngularVelocity)
  result = value - value;
  EXPECT_NEAR(value.mAngularVelocity - value.mAngularVelocity, result.mAngularVelocity, cDoubleNear);

  //  operator-=(::ad::physics::AngularVelocity)
  result = value;
  result -= value;
  EXPECT_NEAR(value.mAngularVelocity - value.mAngularVelocity, result.mAngularVelocity, cDoubleNear);

  //  operator*(double)
  result = value * 5.;
  EXPECT_NEAR(value.mAngularVelocity * 5., result.mAngularVelocity, cDoubleNear);

  //  operator*(double, ::ad::physics::AngularVelocity)
  result = 5. * value;
  EXPECT_NEAR(value.mAngularVelocity * 5., result.mAngularVelocity, cDoubleNear);

  //  operator/(double)
  result = value / value.mAngularVelocity;
  EXPECT_NEAR(value.mAngularVelocity / value.mAngularVelocity, result.mAngularVelocity, cDoubleNear);

  //  operator/(::ad::physics::AngularVelocity)
  double const doubleResult = value / value;
  EXPECT_NEAR(value.mAngularVelocity / value.mAngularVelocity, doubleResult, cDoubleNear);

  //  operator-()
  if ((::ad::physics::AngularVelocity::cMinValue < -value.mAngularVelocity)
      && (-value.mAngularVelocity < ::ad::physics::AngularVelocity::cMaxValue))
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
