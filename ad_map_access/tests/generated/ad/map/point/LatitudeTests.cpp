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
#include "ad/map/point/Latitude.hpp"

TEST(LatitudeTests, defaultConstructionIsInvalid)
{
  ::ad::map::point::Latitude value;
  EXPECT_FALSE(value.isValid());
}

TEST(LatitudeTests, minIsDefinedAsExpected)
{
  EXPECT_DOUBLE_EQ(-90, ::ad::map::point::Latitude::cMinValue);
  EXPECT_DOUBLE_EQ(::ad::map::point::Latitude::cMinValue, ::ad::map::point::Latitude::getMin().mLatitude);
}

TEST(LatitudeTests, maxIsDefinedAsExpected)
{
  EXPECT_DOUBLE_EQ(90, ::ad::map::point::Latitude::cMaxValue);
  EXPECT_DOUBLE_EQ(::ad::map::point::Latitude::cMaxValue, ::ad::map::point::Latitude::getMax().mLatitude);
}

TEST(LatitudeTests, precisionIsDefinedAsExpected)
{
  EXPECT_LT(0., ::ad::map::point::Latitude::cPrecisionValue);
  EXPECT_DOUBLE_EQ(1e-8, ::ad::map::point::Latitude::cPrecisionValue);
  EXPECT_DOUBLE_EQ(::ad::map::point::Latitude::cPrecisionValue, ::ad::map::point::Latitude::getPrecision().mLatitude);
}

TEST(LatitudeTests, minIsValid)
{
  EXPECT_TRUE(::ad::map::point::Latitude::getMin().isValid());
}

TEST(LatitudeTests, aboveMinIsValid)
{
  ::ad::map::point::Latitude value(::ad::map::point::Latitude::cMinValue * 0.9);
  EXPECT_TRUE(value.isValid());
}

TEST(LatitudeTests, belowMinIsInvalid)
{
  ::ad::map::point::Latitude value(::ad::map::point::Latitude::cMinValue * 1.1);
  EXPECT_FALSE(value.isValid());
}

TEST(LatitudeTests, maxIsValid)
{
  EXPECT_TRUE(::ad::map::point::Latitude::getMax().isValid());
}

TEST(LatitudeTests, aboveMaxIsInvalid)
{
  ::ad::map::point::Latitude value(::ad::map::point::Latitude::cMaxValue * 1.1);
  EXPECT_FALSE(value.isValid());
}

TEST(LatitudeTests, belowMaxIsValid)
{
  ::ad::map::point::Latitude value(::ad::map::point::Latitude::cMaxValue * 0.9);
  EXPECT_TRUE(value.isValid());
}

#if (AD_MAP_POINT_LATITUDE_THROWS_EXCEPTION == 1)
TEST(LatitudeTests, ensureValidThrowsOnInvalid)
{
  ::ad::map::point::Latitude value;
  EXPECT_THROW(value.ensureValid(), std::out_of_range);
}

TEST(LatitudeTests, ensureValidNonZeroThrowsOnInvalid)
{
  ::ad::map::point::Latitude value;
  EXPECT_THROW(value.ensureValidNonZero(), std::out_of_range);
}

TEST(LatitudeTests, ensureValidNonZeroThrowsOnZero)
{
  ::ad::map::point::Latitude value(0.);
  EXPECT_THROW(value.ensureValidNonZero(), std::out_of_range);
}
#endif

TEST(LatitudeTestsStd, numericLimitsLowestIsMin)
{
  EXPECT_DOUBLE_EQ(::ad::map::point::Latitude::getMin().mLatitude,
                   std::numeric_limits<::ad::map::point::Latitude>::lowest().mLatitude);
}

TEST(LatitudeTestsStd, numericLimitsMaxIsMax)
{
  EXPECT_DOUBLE_EQ(::ad::map::point::Latitude::getMax().mLatitude,
                   std::numeric_limits<::ad::map::point::Latitude>::max().mLatitude);
}

TEST(LatitudeTestsStd, numericLimitsEpsilonIsPrecision)
{
  EXPECT_DOUBLE_EQ(::ad::map::point::Latitude::getPrecision().mLatitude,
                   std::numeric_limits<::ad::map::point::Latitude>::epsilon().mLatitude);
}

TEST(LatitudeTestsStd, fabsIsWorkingCorrectly)
{
  EXPECT_DOUBLE_EQ(0., std::fabs(::ad::map::point::Latitude(-0.)).mLatitude);
  EXPECT_DOUBLE_EQ(1., std::fabs(::ad::map::point::Latitude(-1.)).mLatitude);
  EXPECT_DOUBLE_EQ(::ad::map::point::Latitude::cPrecisionValue,
                   std::fabs(::ad::map::point::Latitude(::ad::map::point::Latitude::cPrecisionValue).mLatitude));
  EXPECT_DOUBLE_EQ(std::fabs(::ad::map::point::Latitude::cMinValue),
                   std::fabs(::ad::map::point::Latitude(::ad::map::point::Latitude::cMinValue).mLatitude));
  EXPECT_DOUBLE_EQ(std::fabs(::ad::map::point::Latitude::cMinValue),
                   std::fabs(::ad::map::point::Latitude(-::ad::map::point::Latitude::cMinValue).mLatitude));
  EXPECT_DOUBLE_EQ(std::fabs(::ad::map::point::Latitude::cMaxValue),
                   std::fabs(::ad::map::point::Latitude(::ad::map::point::Latitude::cMaxValue).mLatitude));
  EXPECT_DOUBLE_EQ(std::fabs(::ad::map::point::Latitude::cMaxValue),
                   std::fabs(::ad::map::point::Latitude(-::ad::map::point::Latitude::cMaxValue).mLatitude));
}

TEST(LatitudeTests, constructionFromValidFPValue)
{
  double const validValue = ::ad::map::point::Latitude::cMinValue;
  ::ad::map::point::Latitude value(validValue);
  EXPECT_TRUE(value.isValid());
  EXPECT_DOUBLE_EQ(validValue, value.mLatitude);
}

TEST(LatitudeTests, copyConstructionFromValidValue)
{
  ::ad::map::point::Latitude const validValue(::ad::map::point::Latitude::cMinValue);
  ::ad::map::point::Latitude value(validValue);
  EXPECT_TRUE(value.isValid());
  EXPECT_DOUBLE_EQ(validValue.mLatitude, value.mLatitude);
}

TEST(LatitudeTests, moveConstructionFromValidValue)
{
  ::ad::map::point::Latitude validValue(::ad::map::point::Latitude::cMinValue);
  ::ad::map::point::Latitude value(std::move(validValue));
  EXPECT_TRUE(value.isValid());
  EXPECT_DOUBLE_EQ(::ad::map::point::Latitude::cMinValue, value.mLatitude);
}

TEST(LatitudeTests, assignmentFromValidValue)
{
  ::ad::map::point::Latitude const validValue(::ad::map::point::Latitude::cMinValue);
  ::ad::map::point::Latitude value;
  value = validValue;
  EXPECT_TRUE(value.isValid());
  EXPECT_DOUBLE_EQ(validValue.mLatitude, value.mLatitude);
}

TEST(LatitudeTests, moveAssignmentFromValidValue)
{
  ::ad::map::point::Latitude validValue(::ad::map::point::Latitude::cMinValue);
  ::ad::map::point::Latitude value;
  value = std::move(validValue);
  EXPECT_TRUE(value.isValid());
  EXPECT_DOUBLE_EQ(::ad::map::point::Latitude::cMinValue, value.mLatitude);
}

TEST(LatitudeTests, constructionFromInvalidFPValue)
{
  double const invalidValue = std::numeric_limits<double>::quiet_NaN();
  ::ad::map::point::Latitude value(invalidValue);
  EXPECT_FALSE(value.isValid());
}

TEST(LatitudeTests, copyConstructionFromInvalidValue)
{
  ::ad::map::point::Latitude const invalidValue(std::numeric_limits<double>::quiet_NaN());
  ::ad::map::point::Latitude value(invalidValue);
  EXPECT_FALSE(value.isValid());
}

TEST(LatitudeTests, assignmentFromInvalidValue)
{
  ::ad::map::point::Latitude const invalidValue(std::numeric_limits<double>::quiet_NaN());
  ::ad::map::point::Latitude value;
  value = invalidValue;
  EXPECT_FALSE(value.isValid());
}

TEST(LatitudeTests, selfAssignment)
{
  ::ad::map::point::Latitude value(::ad::map::point::Latitude::cMinValue);
  EXPECT_TRUE(value.isValid());
  value = value;
  EXPECT_TRUE(value.isValid());
}

TEST(LatitudeTests, ostreamOperatorTest)
{
  std::stringstream stream;
  ::ad::map::point::Latitude value;
  stream << value;
  ASSERT_GT(stream.str().size(), 0u);
}

#if (AD_MAP_POINT_LATITUDE_THROWS_EXCEPTION == 1)
TEST(LatitudeTests, comparisonOperatorsThrowOnInvalid)
{
  ::ad::map::point::Latitude const value(::ad::map::point::Latitude::cMinValue);
  ::ad::map::point::Latitude const invalidValue;

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

TEST(LatitudeTests, arithmeticOperatorsThrowOnInvalid)
{
  ::ad::map::point::Latitude const minimalValue(::ad::map::point::Latitude::cMinValue);
  ::ad::map::point::Latitude const maximalValue(::ad::map::point::Latitude::cMaxValue);
  ::ad::map::point::Latitude const invalidValue;
  ::ad::map::point::Latitude calculationValue;

  //  operator+(::ad::map::point::Latitude)
  EXPECT_THROW(invalidValue + maximalValue, std::out_of_range);
  EXPECT_THROW(maximalValue + invalidValue, std::out_of_range);
  EXPECT_EQ(maximalValue + maximalValue, maximalValue);

  //  operator+=(::ad::map::point::Latitude)
  calculationValue = invalidValue;
  EXPECT_THROW(calculationValue += maximalValue, std::out_of_range);
  calculationValue = maximalValue;
  EXPECT_THROW(calculationValue += invalidValue, std::out_of_range);
  calculationValue = maximalValue;
  EXPECT_EQ(calculationValue += maximalValue, maximalValue);

  //  operator-(::ad::map::point::Latitude)
  EXPECT_THROW(invalidValue - minimalValue, std::out_of_range);
  EXPECT_THROW(minimalValue - invalidValue, std::out_of_range);
  EXPECT_EQ(minimalValue - maximalValue, minimalValue);

  //  operator-=(::ad::map::point::Latitude)
  calculationValue = invalidValue;
  EXPECT_THROW(calculationValue -= minimalValue, std::out_of_range);
  calculationValue = minimalValue;
  EXPECT_THROW(calculationValue -= invalidValue, std::out_of_range);
  calculationValue = minimalValue;
  EXPECT_EQ(calculationValue -= maximalValue, minimalValue);

  //  operator*(double)
  EXPECT_THROW(invalidValue * maximalValue.mLatitude, std::out_of_range);
  EXPECT_EQ(maximalValue * maximalValue.mLatitude, maximalValue);

  //  operator/(double)
  EXPECT_THROW(invalidValue / maximalValue.mLatitude, std::out_of_range);
  EXPECT_THROW(maximalValue / invalidValue.mLatitude, std::out_of_range);
  EXPECT_THROW(maximalValue / 0.0, std::out_of_range);
  EXPECT_EQ(maximalValue / 0.5, maximalValue);

  //  operator/(::ad::map::point::Latitude)
  EXPECT_THROW(invalidValue / maximalValue, std::out_of_range);
  EXPECT_THROW(maximalValue / invalidValue, std::out_of_range);
  EXPECT_THROW(maximalValue / ::ad::map::point::Latitude(0.0), std::out_of_range);

  //  operator-()
  EXPECT_THROW(-invalidValue, std::out_of_range);
  if (std::fabs(maximalValue.mLatitude) > std::fabs(minimalValue.mLatitude))
  {
    EXPECT_EQ(-maximalValue, minimalValue);
  }
  else if (std::fabs(maximalValue.mLatitude) < std::fabs(minimalValue.mLatitude))
  {
    EXPECT_EQ(-minimalValue, maximalValue);
  }
  else
  {
    // impossible to trigger invalid result while operand is valid
  }
}
#endif

TEST(LatitudeTests, comparisonOperatorsRespectPrecision)
{
  double const precisionValueTimesTen = ::ad::map::point::Latitude::cPrecisionValue * 10.;
  ::ad::map::point::Latitude value;
  if (::ad::map::point::Latitude::cMinValue > precisionValueTimesTen)
  {
    value = ::ad::map::point::Latitude(::ad::map::point::Latitude::cMinValue + precisionValueTimesTen);
  }
  else if (::ad::map::point::Latitude::cMaxValue < precisionValueTimesTen)
  {
    value = ::ad::map::point::Latitude(::ad::map::point::Latitude::cMaxValue - precisionValueTimesTen);
  }
  else
  {
    value = ::ad::map::point::Latitude(precisionValueTimesTen);
  }
  ::ad::map::point::Latitude const sameValue = value;
  ::ad::map::point::Latitude const slightlyBiggerValue(value.mLatitude
                                                       + ::ad::map::point::Latitude::cPrecisionValue * 0.9);
  ::ad::map::point::Latitude const slightlySmallerValue(value.mLatitude
                                                        - ::ad::map::point::Latitude::cPrecisionValue * 0.9);
  ::ad::map::point::Latitude const actuallyBiggerValue(value.mLatitude
                                                       + ::ad::map::point::Latitude::cPrecisionValue * 1.1);
  ::ad::map::point::Latitude const actuallySmallerValue(value.mLatitude
                                                        - ::ad::map::point::Latitude::cPrecisionValue * 1.1);

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

TEST(LatitudeTests, arithmeticOperatorsComputeCorrectly)
{
  double const cDoubleNear = ::ad::map::point::Latitude::cPrecisionValue;
  double const precisionValueTimesTen = ::ad::map::point::Latitude::cPrecisionValue * 10.;
  ::ad::map::point::Latitude value;
  if (::ad::map::point::Latitude::cMinValue > precisionValueTimesTen)
  {
    value = ::ad::map::point::Latitude(::ad::map::point::Latitude::cMinValue + precisionValueTimesTen);
  }
  else if (::ad::map::point::Latitude::cMaxValue < precisionValueTimesTen)
  {
    value = ::ad::map::point::Latitude(::ad::map::point::Latitude::cMaxValue - precisionValueTimesTen);
  }
  else
  {
    value = ::ad::map::point::Latitude(precisionValueTimesTen);
  }

  ::ad::map::point::Latitude result;

  //  operator+(::ad::map::point::Latitude)
  result = value + value;
  EXPECT_NEAR(value.mLatitude + value.mLatitude, result.mLatitude, cDoubleNear);

  //  operator+=(::ad::map::point::Latitude)
  result = value;
  result += value;
  EXPECT_NEAR(value.mLatitude + value.mLatitude, result.mLatitude, cDoubleNear);

  //  operator-(::ad::map::point::Latitude)
  result = value - value;
  EXPECT_NEAR(value.mLatitude - value.mLatitude, result.mLatitude, cDoubleNear);

  //  operator-=(::ad::map::point::Latitude)
  result = value;
  result -= value;
  EXPECT_NEAR(value.mLatitude - value.mLatitude, result.mLatitude, cDoubleNear);

  //  operator*(double)
  result = value * 5.;
  EXPECT_NEAR(value.mLatitude * 5., result.mLatitude, cDoubleNear);

  //  operator*(double, ::ad::map::point::Latitude)
  result = 5. * value;
  EXPECT_NEAR(value.mLatitude * 5., result.mLatitude, cDoubleNear);

  //  operator/(double)
  result = value / value.mLatitude;
  EXPECT_NEAR(value.mLatitude / value.mLatitude, result.mLatitude, cDoubleNear);

  //  operator/(::ad::map::point::Latitude)
  double const doubleResult = value / value;
  EXPECT_NEAR(value.mLatitude / value.mLatitude, doubleResult, cDoubleNear);

  //  operator-()
  if ((::ad::map::point::Latitude::cMinValue < -value.mLatitude)
      && (-value.mLatitude < ::ad::map::point::Latitude::cMaxValue))
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
