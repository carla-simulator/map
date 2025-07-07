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
#define AD_PHYSICS_ANGULARVELOCITY_THROWS_EXCEPTION 1

#if SAFE_DATATYPES_EXPLICIT_CONVERSION
/*!
 * \brief Enable/Disable explicit conversion. Currently set to "only explicit conversion".
 */
#define _AD_PHYSICS_ANGULARVELOCITY_EXPLICIT_CONVERSION_ explicit
#define _AD_PHYSICS_ANGULARVELOCITY_OPERATOR_BASE_TYPE_ 0
#else
/*!
 * \brief Enable/Disable explicit conversion. Currently set to "implicit conversion allowed".
 */
#define _AD_PHYSICS_ANGULARVELOCITY_EXPLICIT_CONVERSION_
#define _AD_PHYSICS_ANGULARVELOCITY_OPERATOR_BASE_TYPE_ 1
#endif

/*!
 * \brief DataType AngularVelocity
 *
 * The rate of change of angular velocity of an object with respect to time.
 * The unit is: RadianPerSecond
 */
class AngularVelocity
{
public:
  /*!
   * \brief constant defining the minimum valid AngularVelocity value (used in isValid())
   */
  static const double cMinValue;

  /*!
   * \brief constant defining the maximum valid AngularVelocity value (used in isValid())
   */
  static const double cMaxValue;

  /*!
   * \brief constant defining the assumed AngularVelocity value accuracy
   *   (used in comparison operator==(), operator!=())
   */
  static const double cPrecisionValue;

  /*!
   * \brief default constructor
   *
   * The default value of AngularVelocity is:
   * std::numeric_limits<double>::quiet_NaN()
   */
  AngularVelocity()
    : mAngularVelocity(std::numeric_limits<double>::quiet_NaN())
  {
  }

  /*!
   * \brief standard constructor
   *
   * \note \ref \_AD_PHYSICS_ANGULARVELOCITY_EXPLICIT_CONVERSION\_ defines, if only an explicit conversion is allowed.
   */
  _AD_PHYSICS_ANGULARVELOCITY_EXPLICIT_CONVERSION_ AngularVelocity(double const iAngularVelocity)
    : mAngularVelocity(iAngularVelocity)
  {
  }

  /*!
   * \brief standard copy constructor
   */
  AngularVelocity(const AngularVelocity &other) = default;

  /*!
   * \brief standard move constructor
   */
  AngularVelocity(AngularVelocity &&other) = default;

  /**
   * \brief standard assignment operator
   *
   * \param[in] other Other AngularVelocity
   *
   * \returns Reference to this AngularVelocity.
   */
  AngularVelocity &operator=(const AngularVelocity &other) = default;

  /**
   * \brief standard move operator
   *
   * \param[in] other Other AngularVelocity
   *
   * \returns Reference to this AngularVelocity.
   */
  AngularVelocity &operator=(AngularVelocity &&other) = default;

  /**
   * \brief standard comparison operator
   *
   * \param[in] other Other AngularVelocity
   *
   * \returns \c true if both AngularVelocity are valid and can be taken as numerically equal
   */
  bool operator==(const AngularVelocity &other) const
  {
    ensureValid();
    other.ensureValid();
    return std::fabs(mAngularVelocity - other.mAngularVelocity) < cPrecisionValue;
  }

  /**
   * \brief standard comparison operator
   *
   * \param[in] other Other AngularVelocity.
   *
   * \returns \c true if one of the AngularVelocity is not valid or they can be taken as numerically different
   */
  bool operator!=(const AngularVelocity &other) const
  {
    return !operator==(other);
  }

  /**
   * \brief standard comparison operator
   *
   * \param[in] other Other AngularVelocity.
   *
   * \returns \c true if both AngularVelocity are valid and
   *   this AngularVelocity is strictly numerically greater than other.
   * \note the precision of AngularVelocity is considered
   */
  bool operator>(const AngularVelocity &other) const
  {
    ensureValid();
    other.ensureValid();
    return (mAngularVelocity > other.mAngularVelocity) && operator!=(other);
  }

  /**
   * \brief standard comparison operator
   *
   * \param[in] other Other AngularVelocity.
   *
   * \returns \c true if both AngularVelocity are valid and
   *   this AngularVelocity is strictly numerically smaller than other.
   * \note the precision of AngularVelocity is considered
   */
  bool operator<(const AngularVelocity &other) const
  {
    ensureValid();
    other.ensureValid();
    return (mAngularVelocity < other.mAngularVelocity) && operator!=(other);
  }

  /**
   * \brief standard comparison operator
   *
   * \param[in] other Other AngularVelocity.
   *
   * \returns \c true if both AngularVelocity are valid and
   *   this AngularVelocity is numerically greater than other.
   * \note the precision of AngularVelocity is considered
   */
  bool operator>=(const AngularVelocity &other) const
  {
    ensureValid();
    other.ensureValid();
    return ((mAngularVelocity > other.mAngularVelocity) || operator==(other));
  }

  /**
   * \brief standard comparison operator
   *
   * \param[in] other Other AngularVelocity
   *
   * \returns \c true if both AngularVelocity are valid and
   *   this AngularVelocity is numerically smaller than other.
   * \note the precision of AngularVelocity is considered
   */
  bool operator<=(const AngularVelocity &other) const
  {
    ensureValid();
    other.ensureValid();
    return ((mAngularVelocity < other.mAngularVelocity) || operator==(other));
  }

  /**
   * \brief standard arithmetic operator
   *
   * \param[in] other Other AngularVelocity
   *
   * \returns Result of arithmetic operation.
   *
   * \note throws a std::out_of_range exception if one of the two operands or the result of
   *   the operation is not valid
   */
  AngularVelocity operator+(const AngularVelocity &other) const
  {
    ensureValid();
    other.ensureValid();
    AngularVelocity result(mAngularVelocity + other.mAngularVelocity);
    result.restrictToLimitsAndEnsureValid();
    return result;
  }

  /**
   * \brief standard arithmetic operator
   *
   * \param[in] other Other AngularVelocity
   *
   * \returns Result of arithmetic operation.
   *
   * \note throws a std::out_of_range exception if one of the two operands or the result of
   *   the operation is not valid
   */
  AngularVelocity &operator+=(const AngularVelocity &other)
  {
    ensureValid();
    other.ensureValid();
    mAngularVelocity += other.mAngularVelocity;
    restrictToLimitsAndEnsureValid();
    return *this;
  }

  /**
   * \brief standard arithmetic operator
   *
   * \param[in] other Other AngularVelocity
   *
   * \returns Result of arithmetic operation.
   *
   * \note throws a std::out_of_range exception if one of the two operands or the result of
   *   the operation is not valid
   */
  AngularVelocity operator-(const AngularVelocity &other) const
  {
    ensureValid();
    other.ensureValid();
    AngularVelocity result(mAngularVelocity - other.mAngularVelocity);
    result.restrictToLimitsAndEnsureValid();
    return result;
  }

  /**
   * \brief standard arithmetic operator
   *
   * \param[in] other Other AngularVelocity
   *
   * \returns Result of arithmetic operation.
   *
   * \note throws a std::out_of_range exception if one of the two operands or the result of
   *   the operation is not valid
   */
  AngularVelocity operator-=(const AngularVelocity &other)
  {
    ensureValid();
    other.ensureValid();
    mAngularVelocity -= other.mAngularVelocity;
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
  AngularVelocity operator*(const double &scalar) const
  {
    ensureValid();
    AngularVelocity result(mAngularVelocity * scalar);
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
  AngularVelocity operator/(const double &scalar) const
  {
    AngularVelocity const scalarAngularVelocity(scalar);
    AngularVelocity result(operator/(scalarAngularVelocity));
    result.restrictToLimitsAndEnsureValid();
    return result;
  }

  /**
   * \brief standard arithmetic operator
   *
   * \param[in] other Other AngularVelocity
   *
   * \returns Result of arithmetic operation.
   *
   * \note throws a std::out_of_range exception if one of the two operands or the result of
   *   the operation is not valid or other is zero
   * \note since AngularVelocity is a type with physical unit, the division results in the dimensionless type.
   */
  double operator/(const AngularVelocity &other) const
  {
    ensureValid();
    other.ensureValidNonZero();
    double const result = mAngularVelocity / other.mAngularVelocity;
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
  AngularVelocity operator-() const
  {
    ensureValid();
    AngularVelocity result(-mAngularVelocity);
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
    return mAngularVelocity;
  }

  /*!
   * \returns \c true if the AngularVelocity is a normal value
   *
   * An AngularVelocity value is defined to be normal if:
   * - It is normal or zero (see std::fpclassify())
   */
  bool isNormal() const
  {
    auto const valueClass = std::fpclassify(mAngularVelocity);
    return ((valueClass == FP_NORMAL) || (valueClass == FP_ZERO));
  }

#if _AD_PHYSICS_ANGULARVELOCITY_OPERATOR_BASE_TYPE_
  /*!
   * \brief conversion to base type: double
   *
   * \note the conversion to the base type removes the physical unit.
   */
  operator double() const
  {
    return mAngularVelocity;
  }
#endif

  /*!
   * \returns \c true if the AngularVelocity in a valid range
   *
   * An AngularVelocity value is defined to be valid if:
   * - It is normal or zero (see std::fpclassify())
   * - \ref cMinValue <= value <= \ref cMaxValue
   */
  bool isValid() const
  {
    return isNormal() && (cMinValue <= mAngularVelocity) && (mAngularVelocity <= cMaxValue);
  }

  /*!
   * \brief ensure that the AngularVelocity is valid
   *
   * Throws an std::out_of_range() exception if the AngularVelocity
   * in not valid (i.e. isValid() returns false)
   */
  void ensureValid() const
  {
    if (!isValid())
    {
      spdlog::info("ensureValid(::ad::physics::AngularVelocity)>> {} value out of range",
                   *this); // LCOV_EXCL_BR_LINE
#if (AD_PHYSICS_ANGULARVELOCITY_THROWS_EXCEPTION == 1)
      throw std::out_of_range("AngularVelocity value out of range"); // LCOV_EXCL_BR_LINE
#endif
    }
  }

  /*!
   * \brief ensure that the AngularVelocity is valid and non zero
   *
   * Throws an std::out_of_range() exception if the AngularVelocity
   * in not valid or zero (i.e. isValid() returns false)
   */
  void ensureValidNonZero() const
  {
    ensureValid();
    if (operator==(AngularVelocity(0.))) // LCOV_EXCL_BR_LINE
    {
      spdlog::info("ensureValid(::ad::physics::AngularVelocity)>> {} value is zero",
                   *this); // LCOV_EXCL_BR_LINE
#if (AD_PHYSICS_ANGULARVELOCITY_THROWS_EXCEPTION == 1)
      throw std::out_of_range("AngularVelocity value is zero"); // LCOV_EXCL_BR_LINE
#endif
    }
  }

  /**
   * @brief if possible restrict the AngularVelocity to it's defined limits
   *
   * If the AngularVelocity isNormal(), but exceeds the defined limits, it is restricted to its limits.
   * If AngularVelocity::isNormal() returns \c false an std::out_of_range() exception is thrown.
   * - not isNormal(): std::out_of_range() exception is thrown
   * - \ref cMinValue <= value <= \ref cMaxValue: nothing is done
   * - value < \ref cMinValue: resulting value = cMinValue
   * - value > \ref cMaxValue: resulting value = cMaxValue
   */
  void restrictToLimitsAndEnsureValid()
  {
    if (isNormal())
    {
      if (mAngularVelocity < cMinValue)
      {
        // mitigate exceeding the minimum
        spdlog::info("restrictToLimits(::ad::physics::AngularVelocity)>> {} value is smaller than allowed minimum {}. "
                     "Restrict to minimum value.",
                     *this,
                     getMin()); // LCOV_EXCL_BR_LINE
        mAngularVelocity = cMinValue;
      }
      else if (mAngularVelocity > cMaxValue)
      {
        // mitigate exceeding the maximum
        spdlog::info("restrictToLimits(::ad::physics::AngularVelocity)>> {} value is larger than allowed maximum {}. "
                     "Restrict to maximum value.",
                     *this,
                     getMax()); // LCOV_EXCL_BR_LINE
        mAngularVelocity = cMaxValue;
      }
    }
    else
    {
      spdlog::info("restrictToLimits(::ad::physics::AngularVelocity)>> {} value out of range",
                   *this); // LCOV_EXCL_BR_LINE
#if (AD_PHYSICS_ANGULARVELOCITY_THROWS_EXCEPTION == 1)
      throw std::out_of_range("AngularVelocity value out of range"); // LCOV_EXCL_BR_LINE
#endif
    }
  }

  /*!
   * \brief get minimum valid AngularVelocity (i.e. \ref cMinValue)
   */
  static AngularVelocity getMin()
  {
    return AngularVelocity(cMinValue);
  }

  /*!
   * \brief get maximum valid AngularVelocity (i.e. \ref cMaxValue)
   */
  static AngularVelocity getMax()
  {
    return AngularVelocity(cMaxValue);
  }

  /*!
   * \brief get assumed accuracy of AngularVelocity (i.e. \ref cPrecisionValue)
   */
  static AngularVelocity getPrecision()
  {
    return AngularVelocity(cPrecisionValue);
  }

  /*!
   * \brief the actual value of the type
   */
  double mAngularVelocity;
};

} // namespace physics
} // namespace ad
/**
 * \brief standard arithmetic operator
 *
 * \param[in] other Other AngularVelocity as double value
 * \param[in] value AngularVelocity value
 *
 * \returns Result of arithmetic operation.
 *
 * \note throws a std::out_of_range exception if \c value or the result of
 *   the operation is not valid
 */
inline ::ad::physics::AngularVelocity operator*(const double &other, ::ad::physics::AngularVelocity const &value)
{
  return value.operator*(other);
}

/*!
 * \brief namespace std
 */
namespace std {

/*!
 * \brief overload of the std::fabs for AngularVelocity
 */
inline ::ad::physics::AngularVelocity fabs(const ::ad::physics::AngularVelocity other)
{
  ::ad::physics::AngularVelocity const result(std::fabs(other.mAngularVelocity));
  return result;
}

/*!
 * \brief specialization of the std::numeric_limits for AngularVelocity
 *
 * Derived from std::numeric_limits<double> with overloaded functions:
 * std::numeric_limits<AngularVelocity>::lowest()  (\see AngularVelocity::getMin())
 * std::numeric_limits<AngularVelocity>::max()  (\see AngularVelocity::getMax())
 * std::numeric_limits<AngularVelocity>::epsilon()  (\see AngularVelocity::getPrecision())
 */
template <> class numeric_limits<::ad::physics::AngularVelocity> : public numeric_limits<double>
{
public:
  /*!
   * \see std::numeric_limits::lowest()
   */
  static inline ::ad::physics::AngularVelocity lowest()
  {
    return ::ad::physics::AngularVelocity::getMin();
  }
  /*!
   * \see std::numeric_limits::max()
   */
  static inline ::ad::physics::AngularVelocity max()
  {
    return ::ad::physics::AngularVelocity::getMax();
  }

  /*!
   * \see std::numeric_limits::epsilon()
   */
  static inline ::ad::physics::AngularVelocity epsilon()
  {
    return ::ad::physics::AngularVelocity::getPrecision();
  }
};

} // namespace std

/*!
 * \brief protect the definition of functions from duplicates by typedef usage within other data types
 */
#ifndef GEN_GUARD_AD_PHYSICS_ANGULARVELOCITY
#define GEN_GUARD_AD_PHYSICS_ANGULARVELOCITY
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
 * \param[in] _value AngularVelocity value
 *
 * \returns The stream object.
 *
 */
inline std::ostream &operator<<(std::ostream &os, AngularVelocity const &_value)
{
  return os << _value.mAngularVelocity;
}

} // namespace physics
} // namespace ad

namespace std {
/*!
 * \brief overload of the std::to_string for AngularVelocity
 */
inline std::string to_string(::ad::physics::AngularVelocity const &value)
{
  return to_string(value.mAngularVelocity);
}
} // namespace std

/*!
 * \brief overload of fmt::formatter calling std::to_string
 */
template <> struct fmt::formatter<::ad::physics::AngularVelocity> : formatter<string_view>
{
  template <typename FormatContext> auto format(::ad::physics::AngularVelocity const &value, FormatContext &ctx)
  {
    return formatter<string_view>::format(std::to_string(value), ctx);
  }
};

#endif // GEN_GUARD_AD_PHYSICS_ANGULARVELOCITY
