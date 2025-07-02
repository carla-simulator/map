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
#include "ad/physics/Distance.hpp"
#include "ad/physics/DistanceSquared.hpp"

TEST(DistanceTests, defaultConstructionIsInvalid)
{
  ::ad::physics::Distance value;
  EXPECT_FALSE(value.isValid());
}

TEST(DistanceTests, minIsDefinedAsExpected)
{
  EXPECT_DOUBLE_EQ(-1e9, ::ad::physics::Distance::cMinValue);
  EXPECT_DOUBLE_EQ(::ad::physics::Distance::cMinValue, ::ad::physics::Distance::getMin().mDistance);
}

TEST(DistanceTests, maxIsDefinedAsExpected)
{
  EXPECT_DOUBLE_EQ(1e9, ::ad::physics::Distance::cMaxValue);
  EXPECT_DOUBLE_EQ(::ad::physics::Distance::cMaxValue, ::ad::physics::Distance::getMax().mDistance);
}

TEST(DistanceTests, precisionIsDefinedAsExpected)
{
  EXPECT_LT(0., ::ad::physics::Distance::cPrecisionValue);
  EXPECT_DOUBLE_EQ(1e-3, ::ad::physics::Distance::cPrecisionValue);
  EXPECT_DOUBLE_EQ(::ad::physics::Distance::cPrecisionValue, ::ad::physics::Distance::getPrecision().mDistance);
}

TEST(DistanceTests, minIsValid)
{
  EXPECT_TRUE(::ad::physics::Distance::getMin().isValid());
}

TEST(DistanceTests, aboveMinIsValid)
{
  ::ad::physics::Distance value(::ad::physics::Distance::cMinValue * 0.9);
  EXPECT_TRUE(value.isValid());
}

TEST(DistanceTests, belowMinIsInvalid)
{
  ::ad::physics::Distance value(::ad::physics::Distance::cMinValue * 1.1);
  EXPECT_FALSE(value.isValid());
}

TEST(DistanceTests, maxIsValid)
{
  EXPECT_TRUE(::ad::physics::Distance::getMax().isValid());
}

TEST(DistanceTests, aboveMaxIsInvalid)
{
  ::ad::physics::Distance value(::ad::physics::Distance::cMaxValue * 1.1);
  EXPECT_FALSE(value.isValid());
}

TEST(DistanceTests, belowMaxIsValid)
{
  ::ad::physics::Distance value(::ad::physics::Distance::cMaxValue * 0.9);
  EXPECT_TRUE(value.isValid());
}

#if (AD_PHYSICS_DISTANCE_THROWS_EXCEPTION == 1)
TEST(DistanceTests, ensureValidThrowsOnInvalid)
{
  ::ad::physics::Distance value;
  EXPECT_THROW(value.ensureValid(), std::out_of_range);
}

TEST(DistanceTests, ensureValidNonZeroThrowsOnInvalid)
{
  ::ad::physics::Distance value;
  EXPECT_THROW(value.ensureValidNonZero(), std::out_of_range);
}

TEST(DistanceTests, ensureValidNonZeroThrowsOnZero)
{
  ::ad::physics::Distance value(0.);
  EXPECT_THROW(value.ensureValidNonZero(), std::out_of_range);
}
#endif

TEST(DistanceTestsStd, numericLimitsLowestIsMin)
{
  EXPECT_DOUBLE_EQ(::ad::physics::Distance::getMin().mDistance,
                   std::numeric_limits<::ad::physics::Distance>::lowest().mDistance);
}

TEST(DistanceTestsStd, numericLimitsMaxIsMax)
{
  EXPECT_DOUBLE_EQ(::ad::physics::Distance::getMax().mDistance,
                   std::numeric_limits<::ad::physics::Distance>::max().mDistance);
}

TEST(DistanceTestsStd, numericLimitsEpsilonIsPrecision)
{
  EXPECT_DOUBLE_EQ(::ad::physics::Distance::getPrecision().mDistance,
                   std::numeric_limits<::ad::physics::Distance>::epsilon().mDistance);
}

TEST(DistanceTestsStd, fabsIsWorkingCorrectly)
{
  EXPECT_DOUBLE_EQ(0., std::fabs(::ad::physics::Distance(-0.)).mDistance);
  EXPECT_DOUBLE_EQ(1., std::fabs(::ad::physics::Distance(-1.)).mDistance);
  EXPECT_DOUBLE_EQ(::ad::physics::Distance::cPrecisionValue,
                   std::fabs(::ad::physics::Distance(::ad::physics::Distance::cPrecisionValue).mDistance));
  EXPECT_DOUBLE_EQ(std::fabs(::ad::physics::Distance::cMinValue),
                   std::fabs(::ad::physics::Distance(::ad::physics::Distance::cMinValue).mDistance));
  EXPECT_DOUBLE_EQ(std::fabs(::ad::physics::Distance::cMinValue),
                   std::fabs(::ad::physics::Distance(-::ad::physics::Distance::cMinValue).mDistance));
  EXPECT_DOUBLE_EQ(std::fabs(::ad::physics::Distance::cMaxValue),
                   std::fabs(::ad::physics::Distance(::ad::physics::Distance::cMaxValue).mDistance));
  EXPECT_DOUBLE_EQ(std::fabs(::ad::physics::Distance::cMaxValue),
                   std::fabs(::ad::physics::Distance(-::ad::physics::Distance::cMaxValue).mDistance));
}

TEST(DistanceTests, constructionFromValidFPValue)
{
  double const validValue = ::ad::physics::Distance::cMinValue;
  ::ad::physics::Distance value(validValue);
  EXPECT_TRUE(value.isValid());
  EXPECT_DOUBLE_EQ(validValue, value.mDistance);
}

TEST(DistanceTests, copyConstructionFromValidValue)
{
  ::ad::physics::Distance const validValue(::ad::physics::Distance::cMinValue);
  ::ad::physics::Distance value(validValue);
  EXPECT_TRUE(value.isValid());
  EXPECT_DOUBLE_EQ(validValue.mDistance, value.mDistance);
}

TEST(DistanceTests, moveConstructionFromValidValue)
{
  ::ad::physics::Distance validValue(::ad::physics::Distance::cMinValue);
  ::ad::physics::Distance value(std::move(validValue));
  EXPECT_TRUE(value.isValid());
  EXPECT_DOUBLE_EQ(::ad::physics::Distance::cMinValue, value.mDistance);
}

TEST(DistanceTests, assignmentFromValidValue)
{
  ::ad::physics::Distance const validValue(::ad::physics::Distance::cMinValue);
  ::ad::physics::Distance value;
  value = validValue;
  EXPECT_TRUE(value.isValid());
  EXPECT_DOUBLE_EQ(validValue.mDistance, value.mDistance);
}

TEST(DistanceTests, moveAssignmentFromValidValue)
{
  ::ad::physics::Distance validValue(::ad::physics::Distance::cMinValue);
  ::ad::physics::Distance value;
  value = std::move(validValue);
  EXPECT_TRUE(value.isValid());
  EXPECT_DOUBLE_EQ(::ad::physics::Distance::cMinValue, value.mDistance);
}

TEST(DistanceTests, constructionFromInvalidFPValue)
{
  double const invalidValue = std::numeric_limits<double>::quiet_NaN();
  ::ad::physics::Distance value(invalidValue);
  EXPECT_FALSE(value.isValid());
}

TEST(DistanceTests, copyConstructionFromInvalidValue)
{
  ::ad::physics::Distance const invalidValue(std::numeric_limits<double>::quiet_NaN());
  ::ad::physics::Distance value(invalidValue);
  EXPECT_FALSE(value.isValid());
}

TEST(DistanceTests, assignmentFromInvalidValue)
{
  ::ad::physics::Distance const invalidValue(std::numeric_limits<double>::quiet_NaN());
  ::ad::physics::Distance value;
  value = invalidValue;
  EXPECT_FALSE(value.isValid());
}

TEST(DistanceTests, selfAssignment)
{
  ::ad::physics::Distance value(::ad::physics::Distance::cMinValue);
  EXPECT_TRUE(value.isValid());
  value = value;
  EXPECT_TRUE(value.isValid());
}

TEST(DistanceTests, ostreamOperatorTest)
{
  std::stringstream stream;
  ::ad::physics::Distance value;
  stream << value;
  ASSERT_GT(stream.str().size(), 0u);
}

#if (AD_PHYSICS_DISTANCE_THROWS_EXCEPTION == 1)
TEST(DistanceTests, comparisonOperatorsThrowOnInvalid)
{
  ::ad::physics::Distance const value(::ad::physics::Distance::cMinValue);
  ::ad::physics::Distance const invalidValue;

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

TEST(DistanceTests, arithmeticOperatorsThrowOnInvalid)
{
  ::ad::physics::Distance const minimalValue(::ad::physics::Distance::cMinValue);
  ::ad::physics::Distance const maximalValue(::ad::physics::Distance::cMaxValue);
  ::ad::physics::Distance const invalidValue;
  ::ad::physics::Distance calculationValue;

  //  operator+(::ad::physics::Distance)
  EXPECT_THROW(invalidValue + maximalValue, std::out_of_range);
  EXPECT_THROW(maximalValue + invalidValue, std::out_of_range);
  EXPECT_EQ(maximalValue + maximalValue, maximalValue);

  //  operator+=(::ad::physics::Distance)
  calculationValue = invalidValue;
  EXPECT_THROW(calculationValue += maximalValue, std::out_of_range);
  calculationValue = maximalValue;
  EXPECT_THROW(calculationValue += invalidValue, std::out_of_range);
  calculationValue = maximalValue;
  EXPECT_EQ(calculationValue += maximalValue, maximalValue);

  //  operator-(::ad::physics::Distance)
  EXPECT_THROW(invalidValue - minimalValue, std::out_of_range);
  EXPECT_THROW(minimalValue - invalidValue, std::out_of_range);
  EXPECT_EQ(minimalValue - maximalValue, minimalValue);

  //  operator-=(::ad::physics::Distance)
  calculationValue = invalidValue;
  EXPECT_THROW(calculationValue -= minimalValue, std::out_of_range);
  calculationValue = minimalValue;
  EXPECT_THROW(calculationValue -= invalidValue, std::out_of_range);
  calculationValue = minimalValue;
  EXPECT_EQ(calculationValue -= maximalValue, minimalValue);

  //  operator*(double)
  EXPECT_THROW(invalidValue * maximalValue.mDistance, std::out_of_range);
  EXPECT_EQ(maximalValue * maximalValue.mDistance, maximalValue);

  //  operator*(::ad::physics::Distance)
  EXPECT_THROW(invalidValue * maximalValue, std::out_of_range);
  EXPECT_THROW(maximalValue * invalidValue, std::out_of_range);

  //  operator/(double)
  EXPECT_THROW(invalidValue / maximalValue.mDistance, std::out_of_range);
  EXPECT_THROW(maximalValue / invalidValue.mDistance, std::out_of_range);
  EXPECT_THROW(maximalValue / 0.0, std::out_of_range);
  EXPECT_EQ(maximalValue / 0.5, maximalValue);

  //  operator/(::ad::physics::Distance)
  EXPECT_THROW(invalidValue / maximalValue, std::out_of_range);
  EXPECT_THROW(maximalValue / invalidValue, std::out_of_range);
  EXPECT_THROW(maximalValue / ::ad::physics::Distance(0.0), std::out_of_range);

  //  operator-()
  EXPECT_THROW(-invalidValue, std::out_of_range);
  if (std::fabs(maximalValue.mDistance) > std::fabs(minimalValue.mDistance))
  {
    EXPECT_EQ(-maximalValue, minimalValue);
  }
  else if (std::fabs(maximalValue.mDistance) < std::fabs(minimalValue.mDistance))
  {
    EXPECT_EQ(-minimalValue, maximalValue);
  }
  else
  {
    // impossible to trigger invalid result while operand is valid
  }
}
#endif

TEST(DistanceTests, comparisonOperatorsRespectPrecision)
{
  double const precisionValueTimesTen = ::ad::physics::Distance::cPrecisionValue * 10.;
  ::ad::physics::Distance value;
  if (::ad::physics::Distance::cMinValue > precisionValueTimesTen)
  {
    value = ::ad::physics::Distance(::ad::physics::Distance::cMinValue + precisionValueTimesTen);
  }
  else if (::ad::physics::Distance::cMaxValue < precisionValueTimesTen)
  {
    value = ::ad::physics::Distance(::ad::physics::Distance::cMaxValue - precisionValueTimesTen);
  }
  else
  {
    value = ::ad::physics::Distance(precisionValueTimesTen);
  }
  ::ad::physics::Distance const sameValue = value;
  ::ad::physics::Distance const slightlyBiggerValue(value.mDistance + ::ad::physics::Distance::cPrecisionValue * 0.9);
  ::ad::physics::Distance const slightlySmallerValue(value.mDistance - ::ad::physics::Distance::cPrecisionValue * 0.9);
  ::ad::physics::Distance const actuallyBiggerValue(value.mDistance + ::ad::physics::Distance::cPrecisionValue * 1.1);
  ::ad::physics::Distance const actuallySmallerValue(value.mDistance - ::ad::physics::Distance::cPrecisionValue * 1.1);

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

TEST(DistanceTests, arithmeticOperatorsComputeCorrectly)
{
  double const cDoubleNear = ::ad::physics::Distance::cPrecisionValue;
  double const precisionValueTimesTen = ::ad::physics::Distance::cPrecisionValue * 10.;
  ::ad::physics::Distance value;
  if (::ad::physics::Distance::cMinValue > precisionValueTimesTen)
  {
    value = ::ad::physics::Distance(::ad::physics::Distance::cMinValue + precisionValueTimesTen);
  }
  else if (::ad::physics::Distance::cMaxValue < precisionValueTimesTen)
  {
    value = ::ad::physics::Distance(::ad::physics::Distance::cMaxValue - precisionValueTimesTen);
  }
  else
  {
    value = ::ad::physics::Distance(precisionValueTimesTen);
  }

  ::ad::physics::Distance result;

  //  operator+(::ad::physics::Distance)
  result = value + value;
  EXPECT_NEAR(value.mDistance + value.mDistance, result.mDistance, cDoubleNear);

  //  operator+=(::ad::physics::Distance)
  result = value;
  result += value;
  EXPECT_NEAR(value.mDistance + value.mDistance, result.mDistance, cDoubleNear);

  //  operator-(::ad::physics::Distance)
  result = value - value;
  EXPECT_NEAR(value.mDistance - value.mDistance, result.mDistance, cDoubleNear);

  //  operator-=(::ad::physics::Distance)
  result = value;
  result -= value;
  EXPECT_NEAR(value.mDistance - value.mDistance, result.mDistance, cDoubleNear);

  //  operator*(double)
  result = value * 5.;
  EXPECT_NEAR(value.mDistance * 5., result.mDistance, cDoubleNear);

  //  operator*(::ad::physics::Distance)
  ::ad::physics::DistanceSquared const squaredResult = value * value;
  EXPECT_NEAR(value.mDistance * value.mDistance, squaredResult.mDistanceSquared, cDoubleNear);

  //  operator*(double, ::ad::physics::Distance)
  result = 5. * value;
  EXPECT_NEAR(value.mDistance * 5., result.mDistance, cDoubleNear);

  //  operator/(double)
  result = value / value.mDistance;
  EXPECT_NEAR(value.mDistance / value.mDistance, result.mDistance, cDoubleNear);

  //  operator/(::ad::physics::Distance)
  double const doubleResult = value / value;
  EXPECT_NEAR(value.mDistance / value.mDistance, doubleResult, cDoubleNear);

  //  operator-()
  if ((::ad::physics::Distance::cMinValue < -value.mDistance)
      && (-value.mDistance < ::ad::physics::Distance::cMaxValue))
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
