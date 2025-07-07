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
#include "ad/physics/Angle.hpp"

TEST(AngleTests, defaultConstructionIsInvalid)
{
  ::ad::physics::Angle value;
  EXPECT_FALSE(value.isValid());
}

TEST(AngleTests, precisionIsDefinedAsExpected)
{
  EXPECT_LT(0., ::ad::physics::Angle::cPrecisionValue);
  EXPECT_DOUBLE_EQ(1e-3, ::ad::physics::Angle::cPrecisionValue);
  EXPECT_DOUBLE_EQ(::ad::physics::Angle::cPrecisionValue, ::ad::physics::Angle::getPrecision().mAngle);
}

TEST(AngleTests, minIsValid)
{
  EXPECT_TRUE(::ad::physics::Angle::getMin().isValid());
}

TEST(AngleTests, aboveMinIsValid)
{
  ::ad::physics::Angle value(::ad::physics::Angle::cMinValue * 0.9);
  EXPECT_TRUE(value.isValid());
}

TEST(AngleTests, belowMinIsInvalid)
{
  ::ad::physics::Angle value(::ad::physics::Angle::cMinValue * 1.1);
  EXPECT_FALSE(value.isValid());
}

TEST(AngleTests, maxIsValid)
{
  EXPECT_TRUE(::ad::physics::Angle::getMax().isValid());
}

TEST(AngleTests, aboveMaxIsInvalid)
{
  ::ad::physics::Angle value(::ad::physics::Angle::cMaxValue * 1.1);
  EXPECT_FALSE(value.isValid());
}

TEST(AngleTests, belowMaxIsValid)
{
  ::ad::physics::Angle value(::ad::physics::Angle::cMaxValue * 0.9);
  EXPECT_TRUE(value.isValid());
}

#if (AD_PHYSICS_ANGLE_THROWS_EXCEPTION == 1)
TEST(AngleTests, ensureValidThrowsOnInvalid)
{
  ::ad::physics::Angle value;
  EXPECT_THROW(value.ensureValid(), std::out_of_range);
}

TEST(AngleTests, ensureValidNonZeroThrowsOnInvalid)
{
  ::ad::physics::Angle value;
  EXPECT_THROW(value.ensureValidNonZero(), std::out_of_range);
}

TEST(AngleTests, ensureValidNonZeroThrowsOnZero)
{
  ::ad::physics::Angle value(0.);
  EXPECT_THROW(value.ensureValidNonZero(), std::out_of_range);
}
#endif

TEST(AngleTestsStd, numericLimitsLowestIsMin)
{
  EXPECT_DOUBLE_EQ(::ad::physics::Angle::getMin().mAngle, std::numeric_limits<::ad::physics::Angle>::lowest().mAngle);
}

TEST(AngleTestsStd, numericLimitsMaxIsMax)
{
  EXPECT_DOUBLE_EQ(::ad::physics::Angle::getMax().mAngle, std::numeric_limits<::ad::physics::Angle>::max().mAngle);
}

TEST(AngleTestsStd, numericLimitsEpsilonIsPrecision)
{
  EXPECT_DOUBLE_EQ(::ad::physics::Angle::getPrecision().mAngle,
                   std::numeric_limits<::ad::physics::Angle>::epsilon().mAngle);
}

TEST(AngleTestsStd, fabsIsWorkingCorrectly)
{
  EXPECT_DOUBLE_EQ(0., std::fabs(::ad::physics::Angle(-0.)).mAngle);
  EXPECT_DOUBLE_EQ(1., std::fabs(::ad::physics::Angle(-1.)).mAngle);
  EXPECT_DOUBLE_EQ(::ad::physics::Angle::cPrecisionValue,
                   std::fabs(::ad::physics::Angle(::ad::physics::Angle::cPrecisionValue).mAngle));
  EXPECT_DOUBLE_EQ(std::fabs(::ad::physics::Angle::cMinValue),
                   std::fabs(::ad::physics::Angle(::ad::physics::Angle::cMinValue).mAngle));
  EXPECT_DOUBLE_EQ(std::fabs(::ad::physics::Angle::cMinValue),
                   std::fabs(::ad::physics::Angle(-::ad::physics::Angle::cMinValue).mAngle));
  EXPECT_DOUBLE_EQ(std::fabs(::ad::physics::Angle::cMaxValue),
                   std::fabs(::ad::physics::Angle(::ad::physics::Angle::cMaxValue).mAngle));
  EXPECT_DOUBLE_EQ(std::fabs(::ad::physics::Angle::cMaxValue),
                   std::fabs(::ad::physics::Angle(-::ad::physics::Angle::cMaxValue).mAngle));
}

TEST(AngleTests, constructionFromValidFPValue)
{
  double const validValue = ::ad::physics::Angle::cMinValue;
  ::ad::physics::Angle value(validValue);
  EXPECT_TRUE(value.isValid());
  EXPECT_DOUBLE_EQ(validValue, value.mAngle);
}

TEST(AngleTests, copyConstructionFromValidValue)
{
  ::ad::physics::Angle const validValue(::ad::physics::Angle::cMinValue);
  ::ad::physics::Angle value(validValue);
  EXPECT_TRUE(value.isValid());
  EXPECT_DOUBLE_EQ(validValue.mAngle, value.mAngle);
}

TEST(AngleTests, moveConstructionFromValidValue)
{
  ::ad::physics::Angle validValue(::ad::physics::Angle::cMinValue);
  ::ad::physics::Angle value(std::move(validValue));
  EXPECT_TRUE(value.isValid());
  EXPECT_DOUBLE_EQ(::ad::physics::Angle::cMinValue, value.mAngle);
}

TEST(AngleTests, assignmentFromValidValue)
{
  ::ad::physics::Angle const validValue(::ad::physics::Angle::cMinValue);
  ::ad::physics::Angle value;
  value = validValue;
  EXPECT_TRUE(value.isValid());
  EXPECT_DOUBLE_EQ(validValue.mAngle, value.mAngle);
}

TEST(AngleTests, moveAssignmentFromValidValue)
{
  ::ad::physics::Angle validValue(::ad::physics::Angle::cMinValue);
  ::ad::physics::Angle value;
  value = std::move(validValue);
  EXPECT_TRUE(value.isValid());
  EXPECT_DOUBLE_EQ(::ad::physics::Angle::cMinValue, value.mAngle);
}

TEST(AngleTests, constructionFromInvalidFPValue)
{
  double const invalidValue = std::numeric_limits<double>::quiet_NaN();
  ::ad::physics::Angle value(invalidValue);
  EXPECT_FALSE(value.isValid());
}

TEST(AngleTests, copyConstructionFromInvalidValue)
{
  ::ad::physics::Angle const invalidValue(std::numeric_limits<double>::quiet_NaN());
  ::ad::physics::Angle value(invalidValue);
  EXPECT_FALSE(value.isValid());
}

TEST(AngleTests, assignmentFromInvalidValue)
{
  ::ad::physics::Angle const invalidValue(std::numeric_limits<double>::quiet_NaN());
  ::ad::physics::Angle value;
  value = invalidValue;
  EXPECT_FALSE(value.isValid());
}

TEST(AngleTests, selfAssignment)
{
  ::ad::physics::Angle value(::ad::physics::Angle::cMinValue);
  EXPECT_TRUE(value.isValid());
  value = value;
  EXPECT_TRUE(value.isValid());
}

TEST(AngleTests, ostreamOperatorTest)
{
  std::stringstream stream;
  ::ad::physics::Angle value;
  stream << value;
  ASSERT_GT(stream.str().size(), 0u);
}

#if (AD_PHYSICS_ANGLE_THROWS_EXCEPTION == 1)
TEST(AngleTests, comparisonOperatorsThrowOnInvalid)
{
  ::ad::physics::Angle const value(::ad::physics::Angle::cMinValue);
  ::ad::physics::Angle const invalidValue;

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

TEST(AngleTests, arithmeticOperatorsThrowOnInvalid)
{
  ::ad::physics::Angle const minimalValue(::ad::physics::Angle::cMinValue);
  ::ad::physics::Angle const maximalValue(::ad::physics::Angle::cMaxValue);
  ::ad::physics::Angle const invalidValue;
  ::ad::physics::Angle calculationValue;

  //  operator+(::ad::physics::Angle)
  EXPECT_THROW(invalidValue + maximalValue, std::out_of_range);
  EXPECT_THROW(maximalValue + invalidValue, std::out_of_range);
  EXPECT_THROW(maximalValue + maximalValue, std::out_of_range);

  //  operator+=(::ad::physics::Angle)
  calculationValue = invalidValue;
  EXPECT_THROW(calculationValue += maximalValue, std::out_of_range);
  calculationValue = maximalValue;
  EXPECT_THROW(calculationValue += invalidValue, std::out_of_range);
  calculationValue = maximalValue;
  EXPECT_THROW(calculationValue += maximalValue, std::out_of_range);

  //  operator-(::ad::physics::Angle)
  EXPECT_THROW(invalidValue - minimalValue, std::out_of_range);
  EXPECT_THROW(minimalValue - invalidValue, std::out_of_range);
  EXPECT_THROW(minimalValue - maximalValue, std::out_of_range);

  //  operator-=(::ad::physics::Angle)
  calculationValue = invalidValue;
  EXPECT_THROW(calculationValue -= minimalValue, std::out_of_range);
  calculationValue = minimalValue;
  EXPECT_THROW(calculationValue -= invalidValue, std::out_of_range);
  calculationValue = minimalValue;
  EXPECT_THROW(calculationValue -= maximalValue, std::out_of_range);

  //  operator*(double)
  EXPECT_THROW(invalidValue * maximalValue.mAngle, std::out_of_range);
  EXPECT_THROW(maximalValue * maximalValue.mAngle, std::out_of_range);

  //  operator/(double)
  EXPECT_THROW(invalidValue / maximalValue.mAngle, std::out_of_range);
  EXPECT_THROW(maximalValue / invalidValue.mAngle, std::out_of_range);
  EXPECT_THROW(maximalValue / 0.0, std::out_of_range);
  EXPECT_THROW(maximalValue / 0.5, std::out_of_range);

  //  operator/(::ad::physics::Angle)
  EXPECT_THROW(invalidValue / maximalValue, std::out_of_range);
  EXPECT_THROW(maximalValue / invalidValue, std::out_of_range);
  EXPECT_THROW(maximalValue / ::ad::physics::Angle(0.0), std::out_of_range);

  //  operator-()
  EXPECT_THROW(-invalidValue, std::out_of_range);
  if (std::fabs(maximalValue.mAngle) > std::fabs(minimalValue.mAngle))
  {
    EXPECT_EQ(-maximalValue, minimalValue);
  }
  else if (std::fabs(maximalValue.mAngle) < std::fabs(minimalValue.mAngle))
  {
    EXPECT_EQ(-minimalValue, maximalValue);
  }
  else
  {
    // impossible to trigger invalid result while operand is valid
  }
}
#endif

TEST(AngleTests, comparisonOperatorsRespectPrecision)
{
  double const precisionValueTimesTen = ::ad::physics::Angle::cPrecisionValue * 10.;
  ::ad::physics::Angle value;
  if (::ad::physics::Angle::cMinValue > precisionValueTimesTen)
  {
    value = ::ad::physics::Angle(::ad::physics::Angle::cMinValue + precisionValueTimesTen);
  }
  else if (::ad::physics::Angle::cMaxValue < precisionValueTimesTen)
  {
    value = ::ad::physics::Angle(::ad::physics::Angle::cMaxValue - precisionValueTimesTen);
  }
  else
  {
    value = ::ad::physics::Angle(precisionValueTimesTen);
  }
  ::ad::physics::Angle const sameValue = value;
  ::ad::physics::Angle const slightlyBiggerValue(value.mAngle + ::ad::physics::Angle::cPrecisionValue * 0.9);
  ::ad::physics::Angle const slightlySmallerValue(value.mAngle - ::ad::physics::Angle::cPrecisionValue * 0.9);
  ::ad::physics::Angle const actuallyBiggerValue(value.mAngle + ::ad::physics::Angle::cPrecisionValue * 1.1);
  ::ad::physics::Angle const actuallySmallerValue(value.mAngle - ::ad::physics::Angle::cPrecisionValue * 1.1);

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

TEST(AngleTests, arithmeticOperatorsComputeCorrectly)
{
  double const cDoubleNear = ::ad::physics::Angle::cPrecisionValue;
  double const precisionValueTimesTen = ::ad::physics::Angle::cPrecisionValue * 10.;
  ::ad::physics::Angle value;
  if (::ad::physics::Angle::cMinValue > precisionValueTimesTen)
  {
    value = ::ad::physics::Angle(::ad::physics::Angle::cMinValue + precisionValueTimesTen);
  }
  else if (::ad::physics::Angle::cMaxValue < precisionValueTimesTen)
  {
    value = ::ad::physics::Angle(::ad::physics::Angle::cMaxValue - precisionValueTimesTen);
  }
  else
  {
    value = ::ad::physics::Angle(precisionValueTimesTen);
  }

  ::ad::physics::Angle result;

  //  operator+(::ad::physics::Angle)
  result = value + value;
  EXPECT_NEAR(value.mAngle + value.mAngle, result.mAngle, cDoubleNear);

  //  operator+=(::ad::physics::Angle)
  result = value;
  result += value;
  EXPECT_NEAR(value.mAngle + value.mAngle, result.mAngle, cDoubleNear);

  //  operator-(::ad::physics::Angle)
  result = value - value;
  EXPECT_NEAR(value.mAngle - value.mAngle, result.mAngle, cDoubleNear);

  //  operator-=(::ad::physics::Angle)
  result = value;
  result -= value;
  EXPECT_NEAR(value.mAngle - value.mAngle, result.mAngle, cDoubleNear);

  //  operator*(double)
  result = value * 5.;
  EXPECT_NEAR(value.mAngle * 5., result.mAngle, cDoubleNear);

  //  operator*(double, ::ad::physics::Angle)
  result = 5. * value;
  EXPECT_NEAR(value.mAngle * 5., result.mAngle, cDoubleNear);

  //  operator/(double)
  result = value / value.mAngle;
  EXPECT_NEAR(value.mAngle / value.mAngle, result.mAngle, cDoubleNear);

  //  operator/(::ad::physics::Angle)
  double const doubleResult = value / value;
  EXPECT_NEAR(value.mAngle / value.mAngle, doubleResult, cDoubleNear);

  //  operator-()
  if ((::ad::physics::Angle::cMinValue < -value.mAngle) && (-value.mAngle < ::ad::physics::Angle::cMaxValue))
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
