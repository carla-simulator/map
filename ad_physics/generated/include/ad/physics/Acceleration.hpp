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
#define AD_PHYSICS_ACCELERATION_THROWS_EXCEPTION 1

#if SAFE_DATATYPES_EXPLICIT_CONVERSION
/*!
 * \brief Enable/Disable explicit conversion. Currently set to "only explicit conversion".
 */
#define _AD_PHYSICS_ACCELERATION_EXPLICIT_CONVERSION_ explicit
#define _AD_PHYSICS_ACCELERATION_OPERATOR_BASE_TYPE_ 0
#else
/*!
 * \brief Enable/Disable explicit conversion. Currently set to "implicit conversion allowed".
 */
#define _AD_PHYSICS_ACCELERATION_EXPLICIT_CONVERSION_
#define _AD_PHYSICS_ACCELERATION_OPERATOR_BASE_TYPE_ 1
#endif

/*!
 * \brief DataType Acceleration
 *
 * The rate of change of Speed of an object with respect to time.
 * The unit is: MeterPerSecondSquared
 */
class Acceleration
{
public:
  /*!
   * \brief constant defining the minimum valid Acceleration value (used in isValid())
   */
  static const double cMinValue;

  /*!
   * \brief constant defining the maximum valid Acceleration value (used in isValid())
   */
  static const double cMaxValue;

  /*!
   * \brief constant defining the assumed Acceleration value accuracy
   *   (used in comparison operator==(), operator!=())
   */
  static const double cPrecisionValue;

  /*!
   * \brief default constructor
   *
   * The default value of Acceleration is:
   * std::numeric_limits<double>::quiet_NaN()
   */
  Acceleration()
    : mAcceleration(std::numeric_limits<double>::quiet_NaN())
  {
  }

  /*!
   * \brief standard constructor
   *
   * \note \ref \_AD_PHYSICS_ACCELERATION_EXPLICIT_CONVERSION\_ defines, if only an explicit conversion is allowed.
   */
  _AD_PHYSICS_ACCELERATION_EXPLICIT_CONVERSION_ Acceleration(double const iAcceleration)
    : mAcceleration(iAcceleration)
  {
  }

  /*!
   * \brief standard copy constructor
   */
  Acceleration(const Acceleration &other) = default;

  /*!
   * \brief standard move constructor
   */
  Acceleration(Acceleration &&other) = default;

  /**
   * \brief standard assignment operator
   *
   * \param[in] other Other Acceleration
   *
   * \returns Reference to this Acceleration.
   */
  Acceleration &operator=(const Acceleration &other) = default;

  /**
   * \brief standard move operator
   *
   * \param[in] other Other Acceleration
   *
   * \returns Reference to this Acceleration.
   */
  Acceleration &operator=(Acceleration &&other) = default;

  /**
   * \brief standard comparison operator
   *
   * \param[in] other Other Acceleration
   *
   * \returns \c true if both Acceleration are valid and can be taken as numerically equal
   */
  bool operator==(const Acceleration &other) const
  {
    ensureValid();
    other.ensureValid();
    return std::fabs(mAcceleration - other.mAcceleration) < cPrecisionValue;
  }

  /**
   * \brief standard comparison operator
   *
   * \param[in] other Other Acceleration.
   *
   * \returns \c true if one of the Acceleration is not valid or they can be taken as numerically different
   */
  bool operator!=(const Acceleration &other) const
  {
    return !operator==(other);
  }

  /**
   * \brief standard comparison operator
   *
   * \param[in] other Other Acceleration.
   *
   * \returns \c true if both Acceleration are valid and
   *   this Acceleration is strictly numerically greater than other.
   * \note the precision of Acceleration is considered
   */
  bool operator>(const Acceleration &other) const
  {
    ensureValid();
    other.ensureValid();
    return (mAcceleration > other.mAcceleration) && operator!=(other);
  }

  /**
   * \brief standard comparison operator
   *
   * \param[in] other Other Acceleration.
   *
   * \returns \c true if both Acceleration are valid and
   *   this Acceleration is strictly numerically smaller than other.
   * \note the precision of Acceleration is considered
   */
  bool operator<(const Acceleration &other) const
  {
    ensureValid();
    other.ensureValid();
    return (mAcceleration < other.mAcceleration) && operator!=(other);
  }

  /**
   * \brief standard comparison operator
   *
   * \param[in] other Other Acceleration.
   *
   * \returns \c true if both Acceleration are valid and
   *   this Acceleration is numerically greater than other.
   * \note the precision of Acceleration is considered
   */
  bool operator>=(const Acceleration &other) const
  {
    ensureValid();
    other.ensureValid();
    return ((mAcceleration > other.mAcceleration) || operator==(other));
  }

  /**
   * \brief standard comparison operator
   *
   * \param[in] other Other Acceleration
   *
   * \returns \c true if both Acceleration are valid and
   *   this Acceleration is numerically smaller than other.
   * \note the precision of Acceleration is considered
   */
  bool operator<=(const Acceleration &other) const
  {
    ensureValid();
    other.ensureValid();
    return ((mAcceleration < other.mAcceleration) || operator==(other));
  }

  /**
   * \brief standard arithmetic operator
   *
   * \param[in] other Other Acceleration
   *
   * \returns Result of arithmetic operation.
   *
   * \note throws a std::out_of_range exception if one of the two operands or the result of
   *   the operation is not valid
   */
  Acceleration operator+(const Acceleration &other) const
  {
    ensureValid();
    other.ensureValid();
    Acceleration result(mAcceleration + other.mAcceleration);
    result.restrictToLimitsAndEnsureValid();
    return result;
  }

  /**
   * \brief standard arithmetic operator
   *
   * \param[in] other Other Acceleration
   *
   * \returns Result of arithmetic operation.
   *
   * \note throws a std::out_of_range exception if one of the two operands or the result of
   *   the operation is not valid
   */
  Acceleration &operator+=(const Acceleration &other)
  {
    ensureValid();
    other.ensureValid();
    mAcceleration += other.mAcceleration;
    restrictToLimitsAndEnsureValid();
    return *this;
  }

  /**
   * \brief standard arithmetic operator
   *
   * \param[in] other Other Acceleration
   *
   * \returns Result of arithmetic operation.
   *
   * \note throws a std::out_of_range exception if one of the two operands or the result of
   *   the operation is not valid
   */
  Acceleration operator-(const Acceleration &other) const
  {
    ensureValid();
    other.ensureValid();
    Acceleration result(mAcceleration - other.mAcceleration);
    result.restrictToLimitsAndEnsureValid();
    return result;
  }

  /**
   * \brief standard arithmetic operator
   *
   * \param[in] other Other Acceleration
   *
   * \returns Result of arithmetic operation.
   *
   * \note throws a std::out_of_range exception if one of the two operands or the result of
   *   the operation is not valid
   */
  Acceleration operator-=(const Acceleration &other)
  {
    ensureValid();
    other.ensureValid();
    mAcceleration -= other.mAcceleration;
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
  Acceleration operator*(const double &scalar) const
  {
    ensureValid();
    Acceleration result(mAcceleration * scalar);
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
  Acceleration operator/(const double &scalar) const
  {
    Acceleration const scalarAcceleration(scalar);
    Acceleration result(operator/(scalarAcceleration));
    result.restrictToLimitsAndEnsureValid();
    return result;
  }

  /**
   * \brief standard arithmetic operator
   *
   * \param[in] other Other Acceleration
   *
   * \returns Result of arithmetic operation.
   *
   * \note throws a std::out_of_range exception if one of the two operands or the result of
   *   the operation is not valid or other is zero
   * \note since Acceleration is a type with physical unit, the division results in the dimensionless type.
   */
  double operator/(const Acceleration &other) const
  {
    ensureValid();
    other.ensureValidNonZero();
    double const result = mAcceleration / other.mAcceleration;
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
  Acceleration operator-() const
  {
    ensureValid();
    Acceleration result(-mAcceleration);
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
    return mAcceleration;
  }

  /*!
   * \returns \c true if the Acceleration is a normal value
   *
   * An Acceleration value is defined to be normal if:
   * - It is normal or zero (see std::fpclassify())
   */
  bool isNormal() const
  {
    auto const valueClass = std::fpclassify(mAcceleration);
    return ((valueClass == FP_NORMAL) || (valueClass == FP_ZERO));
  }

#if _AD_PHYSICS_ACCELERATION_OPERATOR_BASE_TYPE_
  /*!
   * \brief conversion to base type: double
   *
   * \note the conversion to the base type removes the physical unit.
   */
  operator double() const
  {
    return mAcceleration;
  }
#endif

  /*!
   * \returns \c true if the Acceleration in a valid range
   *
   * An Acceleration value is defined to be valid if:
   * - It is normal or zero (see std::fpclassify())
   * - \ref cMinValue <= value <= \ref cMaxValue
   */
  bool isValid() const
  {
    return isNormal() && (cMinValue <= mAcceleration) && (mAcceleration <= cMaxValue);
  }

  /*!
   * \brief ensure that the Acceleration is valid
   *
   * Throws an std::out_of_range() exception if the Acceleration
   * in not valid (i.e. isValid() returns false)
   */
  void ensureValid() const
  {
    if (!isValid())
    {
      spdlog::info("ensureValid(::ad::physics::Acceleration)>> {} value out of range",
                   *this); // LCOV_EXCL_BR_LINE
#if (AD_PHYSICS_ACCELERATION_THROWS_EXCEPTION == 1)
      throw std::out_of_range("Acceleration value out of range"); // LCOV_EXCL_BR_LINE
#endif
    }
  }

  /*!
   * \brief ensure that the Acceleration is valid and non zero
   *
   * Throws an std::out_of_range() exception if the Acceleration
   * in not valid or zero (i.e. isValid() returns false)
   */
  void ensureValidNonZero() const
  {
    ensureValid();
    if (operator==(Acceleration(0.))) // LCOV_EXCL_BR_LINE
    {
      spdlog::info("ensureValid(::ad::physics::Acceleration)>> {} value is zero",
                   *this); // LCOV_EXCL_BR_LINE
#if (AD_PHYSICS_ACCELERATION_THROWS_EXCEPTION == 1)
      throw std::out_of_range("Acceleration value is zero"); // LCOV_EXCL_BR_LINE
#endif
    }
  }

  /**
   * @brief if possible restrict the Acceleration to it's defined limits
   *
   * If the Acceleration isNormal(), but exceeds the defined limits, it is restricted to its limits.
   * If Acceleration::isNormal() returns \c false an std::out_of_range() exception is thrown.
   * - not isNormal(): std::out_of_range() exception is thrown
   * - \ref cMinValue <= value <= \ref cMaxValue: nothing is done
   * - value < \ref cMinValue: resulting value = cMinValue
   * - value > \ref cMaxValue: resulting value = cMaxValue
   */
  void restrictToLimitsAndEnsureValid()
  {
    if (isNormal())
    {
      if (mAcceleration < cMinValue)
      {
        // mitigate exceeding the minimum
        spdlog::info("restrictToLimits(::ad::physics::Acceleration)>> {} value is smaller than allowed minimum {}. "
                     "Restrict to minimum value.",
                     *this,
                     getMin()); // LCOV_EXCL_BR_LINE
        mAcceleration = cMinValue;
      }
      else if (mAcceleration > cMaxValue)
      {
        // mitigate exceeding the maximum
        spdlog::info("restrictToLimits(::ad::physics::Acceleration)>> {} value is larger than allowed maximum {}. "
                     "Restrict to maximum value.",
                     *this,
                     getMax()); // LCOV_EXCL_BR_LINE
        mAcceleration = cMaxValue;
      }
    }
    else
    {
      spdlog::info("restrictToLimits(::ad::physics::Acceleration)>> {} value out of range", *this); // LCOV_EXCL_BR_LINE
#if (AD_PHYSICS_ACCELERATION_THROWS_EXCEPTION == 1)
      throw std::out_of_range("Acceleration value out of range"); // LCOV_EXCL_BR_LINE
#endif
    }
  }

  /*!
   * \brief get minimum valid Acceleration (i.e. \ref cMinValue)
   */
  static Acceleration getMin()
  {
    return Acceleration(cMinValue);
  }

  /*!
   * \brief get maximum valid Acceleration (i.e. \ref cMaxValue)
   */
  static Acceleration getMax()
  {
    return Acceleration(cMaxValue);
  }

  /*!
   * \brief get assumed accuracy of Acceleration (i.e. \ref cPrecisionValue)
   */
  static Acceleration getPrecision()
  {
    return Acceleration(cPrecisionValue);
  }

  /*!
   * \brief the actual value of the type
   */
  double mAcceleration;
};

} // namespace physics
} // namespace ad
/**
 * \brief standard arithmetic operator
 *
 * \param[in] other Other Acceleration as double value
 * \param[in] value Acceleration value
 *
 * \returns Result of arithmetic operation.
 *
 * \note throws a std::out_of_range exception if \c value or the result of
 *   the operation is not valid
 */
inline ::ad::physics::Acceleration operator*(const double &other, ::ad::physics::Acceleration const &value)
{
  return value.operator*(other);
}

/*!
 * \brief namespace std
 */
namespace std {

/*!
 * \brief overload of the std::fabs for Acceleration
 */
inline ::ad::physics::Acceleration fabs(const ::ad::physics::Acceleration other)
{
  ::ad::physics::Acceleration const result(std::fabs(other.mAcceleration));
  return result;
}

/*!
 * \brief specialization of the std::numeric_limits for Acceleration
 *
 * Derived from std::numeric_limits<double> with overloaded functions:
 * std::numeric_limits<Acceleration>::lowest()  (\see Acceleration::getMin())
 * std::numeric_limits<Acceleration>::max()  (\see Acceleration::getMax())
 * std::numeric_limits<Acceleration>::epsilon()  (\see Acceleration::getPrecision())
 */
template <> class numeric_limits<::ad::physics::Acceleration> : public numeric_limits<double>
{
public:
  /*!
   * \see std::numeric_limits::lowest()
   */
  static inline ::ad::physics::Acceleration lowest()
  {
    return ::ad::physics::Acceleration::getMin();
  }
  /*!
   * \see std::numeric_limits::max()
   */
  static inline ::ad::physics::Acceleration max()
  {
    return ::ad::physics::Acceleration::getMax();
  }

  /*!
   * \see std::numeric_limits::epsilon()
   */
  static inline ::ad::physics::Acceleration epsilon()
  {
    return ::ad::physics::Acceleration::getPrecision();
  }
};

} // namespace std

/*!
 * \brief protect the definition of functions from duplicates by typedef usage within other data types
 */
#ifndef GEN_GUARD_AD_PHYSICS_ACCELERATION
#define GEN_GUARD_AD_PHYSICS_ACCELERATION
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
 * \param[in] _value Acceleration value
 *
 * \returns The stream object.
 *
 */
inline std::ostream &operator<<(std::ostream &os, Acceleration const &_value)
{
  return os << _value.mAcceleration;
}

} // namespace physics
} // namespace ad

namespace std {
/*!
 * \brief overload of the std::to_string for Acceleration
 */
inline std::string to_string(::ad::physics::Acceleration const &value)
{
  return to_string(value.mAcceleration);
}
} // namespace std

/*!
 * \brief overload of fmt::formatter calling std::to_string
 */
template <> struct fmt::formatter<::ad::physics::Acceleration> : formatter<string_view>
{
  template <typename FormatContext> auto format(::ad::physics::Acceleration const &value, FormatContext &ctx)
  {
    return formatter<string_view>::format(std::to_string(value), ctx);
  }
};

#endif // GEN_GUARD_AD_PHYSICS_ACCELERATION
