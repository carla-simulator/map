/*
 * ----------------- BEGIN LICENSE BLOCK ---------------------------------
 *
 * Copyright (C) 2018-2022 Intel Corporation
 *
 * SPDX-License-Identifier: MIT
 *
 * ----------------- END LICENSE BLOCK -----------------------------------
 */

/**
 * Generated file
 * @file
 *
 * Generator Version : 11.0.0-2046
 */

#pragma once

#include <cmath>
#include <iostream>
#include <limits>
#include <sstream>
#include <stdexcept>
#include "spdlog/fmt/ostr.h"
#include "spdlog/spdlog.h"
/*!
 * @brief namespace ad
 */
namespace ad {
/*!
 * @brief namespace physics
 */
namespace physics {

/*!
 * \brief Define to indicate whether throwing exceptions is enabled
 */
#define AD_PHYSICS_RATIOVALUE_THROWS_EXCEPTION 1

#if SAFE_DATATYPES_EXPLICIT_CONVERSION
/*!
 * \brief Enable/Disable explicit conversion. Currently set to "only explicit conversion".
 */
#define _AD_PHYSICS_RATIOVALUE_EXPLICIT_CONVERSION_ explicit
#define _AD_PHYSICS_RATIOVALUE_OPERATOR_BASE_TYPE_ 0
#else
/*!
 * \brief Enable/Disable explicit conversion. Currently set to "implicit conversion allowed".
 */
#define _AD_PHYSICS_RATIOVALUE_EXPLICIT_CONVERSION_
#define _AD_PHYSICS_RATIOVALUE_OPERATOR_BASE_TYPE_ 1
#endif

/*!
 * \brief DataType RatioValue
 *
 * Defines a general ratio.
 * The unit is: Ratio
 */
class RatioValue
{
public:
  /*!
   * \brief constant defining the minimum valid RatioValue value (used in isValid())
   */
  static const double cMinValue;

  /*!
   * \brief constant defining the maximum valid RatioValue value (used in isValid())
   */
  static const double cMaxValue;

  /*!
   * \brief constant defining the assumed RatioValue value accuracy
   *   (used in comparison operator==(), operator!=())
   */
  static const double cPrecisionValue;

  /*!
   * \brief default constructor
   *
   * The default value of RatioValue is:
   * std::numeric_limits<double>::quiet_NaN()
   */
  RatioValue()
    : mRatioValue(std::numeric_limits<double>::quiet_NaN())
  {
  }

  /*!
   * \brief standard constructor
   *
   * \note \ref \_AD_PHYSICS_RATIOVALUE_EXPLICIT_CONVERSION\_ defines, if only an explicit conversion is allowed.
   */
  _AD_PHYSICS_RATIOVALUE_EXPLICIT_CONVERSION_ RatioValue(double const iRatioValue)
    : mRatioValue(iRatioValue)
  {
  }

  /*!
   * \brief standard copy constructor
   */
  RatioValue(const RatioValue &other) = default;

  /*!
   * \brief standard move constructor
   */
  RatioValue(RatioValue &&other) = default;

  /**
   * \brief standard assignment operator
   *
   * \param[in] other Other RatioValue
   *
   * \returns Reference to this RatioValue.
   */
  RatioValue &operator=(const RatioValue &other) = default;

  /**
   * \brief standard move operator
   *
   * \param[in] other Other RatioValue
   *
   * \returns Reference to this RatioValue.
   */
  RatioValue &operator=(RatioValue &&other) = default;

  /**
   * \brief standard comparison operator
   *
   * \param[in] other Other RatioValue
   *
   * \returns \c true if both RatioValue are valid and can be taken as numerically equal
   */
  bool operator==(const RatioValue &other) const
  {
    ensureValid();
    other.ensureValid();
    return std::fabs(mRatioValue - other.mRatioValue) < cPrecisionValue;
  }

  /**
   * \brief standard comparison operator
   *
   * \param[in] other Other RatioValue.
   *
   * \returns \c true if one of the RatioValue is not valid or they can be taken as numerically different
   */
  bool operator!=(const RatioValue &other) const
  {
    return !operator==(other);
  }

  /**
   * \brief standard comparison operator
   *
   * \param[in] other Other RatioValue.
   *
   * \returns \c true if both RatioValue are valid and
   *   this RatioValue is strictly numerically greater than other.
   * \note the precision of RatioValue is considered
   */
  bool operator>(const RatioValue &other) const
  {
    ensureValid();
    other.ensureValid();
    return (mRatioValue > other.mRatioValue) && operator!=(other);
  }

  /**
   * \brief standard comparison operator
   *
   * \param[in] other Other RatioValue.
   *
   * \returns \c true if both RatioValue are valid and
   *   this RatioValue is strictly numerically smaller than other.
   * \note the precision of RatioValue is considered
   */
  bool operator<(const RatioValue &other) const
  {
    ensureValid();
    other.ensureValid();
    return (mRatioValue < other.mRatioValue) && operator!=(other);
  }

  /**
   * \brief standard comparison operator
   *
   * \param[in] other Other RatioValue.
   *
   * \returns \c true if both RatioValue are valid and
   *   this RatioValue is numerically greater than other.
   * \note the precision of RatioValue is considered
   */
  bool operator>=(const RatioValue &other) const
  {
    ensureValid();
    other.ensureValid();
    return ((mRatioValue > other.mRatioValue) || operator==(other));
  }

  /**
   * \brief standard comparison operator
   *
   * \param[in] other Other RatioValue
   *
   * \returns \c true if both RatioValue are valid and
   *   this RatioValue is numerically smaller than other.
   * \note the precision of RatioValue is considered
   */
  bool operator<=(const RatioValue &other) const
  {
    ensureValid();
    other.ensureValid();
    return ((mRatioValue < other.mRatioValue) || operator==(other));
  }

  /**
   * \brief standard arithmetic operator
   *
   * \param[in] other Other RatioValue
   *
   * \returns Result of arithmetic operation.
   *
   * \note throws a std::out_of_range exception if one of the two operands or the result of
   *   the operation is not valid
   */
  RatioValue operator+(const RatioValue &other) const
  {
    ensureValid();
    other.ensureValid();
    RatioValue result(mRatioValue + other.mRatioValue);
    result.restrictToLimitsAndEnsureValid();
    return result;
  }

  /**
   * \brief standard arithmetic operator
   *
   * \param[in] other Other RatioValue
   *
   * \returns Result of arithmetic operation.
   *
   * \note throws a std::out_of_range exception if one of the two operands or the result of
   *   the operation is not valid
   */
  RatioValue &operator+=(const RatioValue &other)
  {
    ensureValid();
    other.ensureValid();
    mRatioValue += other.mRatioValue;
    restrictToLimitsAndEnsureValid();
    return *this;
  }

  /**
   * \brief standard arithmetic operator
   *
   * \param[in] other Other RatioValue
   *
   * \returns Result of arithmetic operation.
   *
   * \note throws a std::out_of_range exception if one of the two operands or the result of
   *   the operation is not valid
   */
  RatioValue operator-(const RatioValue &other) const
  {
    ensureValid();
    other.ensureValid();
    RatioValue result(mRatioValue - other.mRatioValue);
    result.restrictToLimitsAndEnsureValid();
    return result;
  }

  /**
   * \brief standard arithmetic operator
   *
   * \param[in] other Other RatioValue
   *
   * \returns Result of arithmetic operation.
   *
   * \note throws a std::out_of_range exception if one of the two operands or the result of
   *   the operation is not valid
   */
  RatioValue operator-=(const RatioValue &other)
  {
    ensureValid();
    other.ensureValid();
    mRatioValue -= other.mRatioValue;
    restrictToLimitsAndEnsureValid();
    return *this;
  }

  /**
   * \brief standard arithmetic operator
   *
   * \param[in] scalar Scalar double value
   *
   * \returns Result of arithmetic operation.
   *
   * \note throws a std::out_of_range exception if \c value or the result of
   *   the operation is not valid
   */
  RatioValue operator*(const double &scalar) const
  {
    ensureValid();
    RatioValue result(mRatioValue * scalar);
    result.restrictToLimitsAndEnsureValid();
    return result;
  }

  /**
   * \brief standard arithmetic operator
   *
   * \param[in] scalar Scalar double value
   *
   * \returns Result of arithmetic operation.
   *
   * \note throws a std::out_of_range exception if this or the result of
   *   the operation is not valid or other is zero
   */
  RatioValue operator/(const double &scalar) const
  {
    RatioValue const scalarRatioValue(scalar);
    RatioValue result(operator/(scalarRatioValue));
    result.restrictToLimitsAndEnsureValid();
    return result;
  }

  /**
   * \brief standard arithmetic operator
   *
   * \param[in] other Other RatioValue
   *
   * \returns Result of arithmetic operation.
   *
   * \note throws a std::out_of_range exception if one of the two operands or the result of
   *   the operation is not valid or other is zero
   * \note since RatioValue is a type with physical unit, the division results in the dimensionless type.
   */
  double operator/(const RatioValue &other) const
  {
    ensureValid();
    other.ensureValidNonZero();
    double const result = mRatioValue / other.mRatioValue;
    return result;
  }

  /**
   * \brief standard arithmetic operator
   *
   * \returns Result of arithmetic operation.
   *
   * \note throws a std::out_of_range exception if this or the result of
   *   the operation is not valid
   */
  RatioValue operator-() const
  {
    ensureValid();
    RatioValue result(-mRatioValue);
    result.restrictToLimitsAndEnsureValid(); // LCOV_EXCL_BR_LINE Some types do not throw an exception
    return result;
  }

  /*!
   * \brief conversion to base type: double
   *
   * \note the conversion to the base type removes the physical unit.
   */
  double toBaseType() const
  {
    return mRatioValue;
  }

  /*!
   * \returns \c true if the RatioValue is a normal value
   *
   * An RatioValue value is defined to be normal if:
   * - It is normal or zero (see std::fpclassify())
   */
  bool isNormal() const
  {
    auto const valueClass = std::fpclassify(mRatioValue);
    return ((valueClass == FP_NORMAL) || (valueClass == FP_ZERO));
  }

#if _AD_PHYSICS_RATIOVALUE_OPERATOR_BASE_TYPE_
  /*!
   * \brief conversion to base type: double
   *
   * \note the conversion to the base type removes the physical unit.
   */
  operator double() const
  {
    return mRatioValue;
  }
#endif

  /*!
   * \returns \c true if the RatioValue in a valid range
   *
   * An RatioValue value is defined to be valid if:
   * - It is normal or zero (see std::fpclassify())
   * - \ref cMinValue <= value <= \ref cMaxValue
   */
  bool isValid() const
  {
    return isNormal() && (cMinValue <= mRatioValue) && (mRatioValue <= cMaxValue);
  }

  /*!
   * \brief ensure that the RatioValue is valid
   *
   * Throws an std::out_of_range() exception if the RatioValue
   * in not valid (i.e. isValid() returns false)
   */
  void ensureValid() const
  {
    if (!isValid())
    {
      spdlog::info("ensureValid(::ad::physics::RatioValue)>> {} value out of range",
                   *this); // LCOV_EXCL_BR_LINE
#if (AD_PHYSICS_RATIOVALUE_THROWS_EXCEPTION == 1)
      throw std::out_of_range("RatioValue value out of range"); // LCOV_EXCL_BR_LINE
#endif
    }
  }

  /*!
   * \brief ensure that the RatioValue is valid and non zero
   *
   * Throws an std::out_of_range() exception if the RatioValue
   * in not valid or zero (i.e. isValid() returns false)
   */
  void ensureValidNonZero() const
  {
    ensureValid();
    if (operator==(RatioValue(0.))) // LCOV_EXCL_BR_LINE
    {
      spdlog::info("ensureValid(::ad::physics::RatioValue)>> {} value is zero",
                   *this); // LCOV_EXCL_BR_LINE
#if (AD_PHYSICS_RATIOVALUE_THROWS_EXCEPTION == 1)
      throw std::out_of_range("RatioValue value is zero"); // LCOV_EXCL_BR_LINE
#endif
    }
  }

  /**
   * @brief if possible restrict the RatioValue to it's defined limits
   *
   * If the RatioValue isNormal(), but exceeds the defined limits, it is restricted to its limits.
   * If RatioValue::isNormal() returns \c false an std::out_of_range() exception is thrown.
   * - not isNormal(): std::out_of_range() exception is thrown
   * - \ref cMinValue <= value <= \ref cMaxValue: nothing is done
   * - value < \ref cMinValue: resulting value = cMinValue
   * - value > \ref cMaxValue: resulting value = cMaxValue
   */
  void restrictToLimitsAndEnsureValid()
  {
    if (isNormal())
    {
      if (mRatioValue < cMinValue)
      {
        // mitigate exceeding the minimum
        spdlog::info("restrictToLimits(::ad::physics::RatioValue)>> {} value is smaller than allowed minimum {}. "
                     "Restrict to minimum value.",
                     *this,
                     getMin()); // LCOV_EXCL_BR_LINE
        mRatioValue = cMinValue;
      }
      else if (mRatioValue > cMaxValue)
      {
        // mitigate exceeding the maximum
        spdlog::info("restrictToLimits(::ad::physics::RatioValue)>> {} value is larger than allowed maximum {}. "
                     "Restrict to maximum value.",
                     *this,
                     getMax()); // LCOV_EXCL_BR_LINE
        mRatioValue = cMaxValue;
      }
    }
    else
    {
      spdlog::info("restrictToLimits(::ad::physics::RatioValue)>> {} value out of range", *this); // LCOV_EXCL_BR_LINE
#if (AD_PHYSICS_RATIOVALUE_THROWS_EXCEPTION == 1)
      throw std::out_of_range("RatioValue value out of range"); // LCOV_EXCL_BR_LINE
#endif
    }
  }

  /*!
   * \brief get minimum valid RatioValue (i.e. \ref cMinValue)
   */
  static RatioValue getMin()
  {
    return RatioValue(cMinValue);
  }

  /*!
   * \brief get maximum valid RatioValue (i.e. \ref cMaxValue)
   */
  static RatioValue getMax()
  {
    return RatioValue(cMaxValue);
  }

  /*!
   * \brief get assumed accuracy of RatioValue (i.e. \ref cPrecisionValue)
   */
  static RatioValue getPrecision()
  {
    return RatioValue(cPrecisionValue);
  }

  /*!
   * \brief the actual value of the type
   */
  double mRatioValue;
};

} // namespace physics
} // namespace ad
/**
 * \brief standard arithmetic operator
 *
 * \param[in] other Other RatioValue as double value
 * \param[in] value RatioValue value
 *
 * \returns Result of arithmetic operation.
 *
 * \note throws a std::out_of_range exception if \c value or the result of
 *   the operation is not valid
 */
inline ::ad::physics::RatioValue operator*(const double &other, ::ad::physics::RatioValue const &value)
{
  return value.operator*(other);
}

/*!
 * \brief namespace std
 */
namespace std {

/*!
 * \brief overload of the std::fabs for RatioValue
 */
inline ::ad::physics::RatioValue fabs(const ::ad::physics::RatioValue other)
{
  ::ad::physics::RatioValue const result(std::fabs(other.mRatioValue));
  return result;
}

/*!
 * \brief specialization of the std::numeric_limits for RatioValue
 *
 * Derived from std::numeric_limits<double> with overloaded functions:
 * std::numeric_limits<RatioValue>::lowest()  (\see RatioValue::getMin())
 * std::numeric_limits<RatioValue>::max()  (\see RatioValue::getMax())
 * std::numeric_limits<RatioValue>::epsilon()  (\see RatioValue::getPrecision())
 */
template <> class numeric_limits<::ad::physics::RatioValue> : public numeric_limits<double>
{
public:
  /*!
   * \see std::numeric_limits::lowest()
   */
  static inline ::ad::physics::RatioValue lowest()
  {
    return ::ad::physics::RatioValue::getMin();
  }
  /*!
   * \see std::numeric_limits::max()
   */
  static inline ::ad::physics::RatioValue max()
  {
    return ::ad::physics::RatioValue::getMax();
  }

  /*!
   * \see std::numeric_limits::epsilon()
   */
  static inline ::ad::physics::RatioValue epsilon()
  {
    return ::ad::physics::RatioValue::getPrecision();
  }
};

} // namespace std

/*!
 * \brief protect the definition of functions from duplicates by typedef usage within other data types
 */
#ifndef GEN_GUARD_AD_PHYSICS_RATIOVALUE
#define GEN_GUARD_AD_PHYSICS_RATIOVALUE
/*!
 * @brief namespace ad
 */
namespace ad {
/*!
 * @brief namespace physics
 */
namespace physics {

/**
 * \brief standard ostream operator
 *
 * \param[in] os The output stream to write to
 * \param[in] _value RatioValue value
 *
 * \returns The stream object.
 *
 */
inline std::ostream &operator<<(std::ostream &os, RatioValue const &_value)
{
  return os << _value.mRatioValue;
}

} // namespace physics
} // namespace ad

namespace std {
/*!
 * \brief overload of the std::to_string for RatioValue
 */
inline std::string to_string(::ad::physics::RatioValue const &value)
{
  return to_string(value.mRatioValue);
}
} // namespace std

/*!
 * \brief overload of fmt::formatter calling std::to_string
 */
template <> struct fmt::formatter<::ad::physics::RatioValue> : formatter<string_view>
{
  template <typename FormatContext> auto format(::ad::physics::RatioValue const &value, FormatContext &ctx)
  {
    return formatter<string_view>::format(std::to_string(value), ctx);
  }
};

#endif // GEN_GUARD_AD_PHYSICS_RATIOVALUE
