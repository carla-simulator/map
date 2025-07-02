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
#define AD_PHYSICS_ANGLE_THROWS_EXCEPTION 1

#if SAFE_DATATYPES_EXPLICIT_CONVERSION
/*!
 * \brief Enable/Disable explicit conversion. Currently set to "only explicit conversion".
 */
#define _AD_PHYSICS_ANGLE_EXPLICIT_CONVERSION_ explicit
#define _AD_PHYSICS_ANGLE_OPERATOR_BASE_TYPE_ 0
#else
/*!
 * \brief Enable/Disable explicit conversion. Currently set to "implicit conversion allowed".
 */
#define _AD_PHYSICS_ANGLE_EXPLICIT_CONVERSION_
#define _AD_PHYSICS_ANGLE_OPERATOR_BASE_TYPE_ 1
#endif

/*!
 * \brief DataType Angle
 *
 * An angle measured in radians
 * The unit is: Radian
 */
class Angle
{
public:
  /*!
   * \brief constant defining the minimum valid Angle value (used in isValid())
   */
  static const double cMinValue;

  /*!
   * \brief constant defining the maximum valid Angle value (used in isValid())
   */
  static const double cMaxValue;

  /*!
   * \brief constant defining the assumed Angle value accuracy
   *   (used in comparison operator==(), operator!=())
   */
  static const double cPrecisionValue;

  /*!
   * \brief default constructor
   *
   * The default value of Angle is:
   * std::numeric_limits<double>::quiet_NaN()
   */
  Angle()
    : mAngle(std::numeric_limits<double>::quiet_NaN())
  {
  }

  /*!
   * \brief standard constructor
   *
   * \note \ref \_AD_PHYSICS_ANGLE_EXPLICIT_CONVERSION\_ defines, if only an explicit conversion is allowed.
   */
  _AD_PHYSICS_ANGLE_EXPLICIT_CONVERSION_ Angle(double const iAngle)
    : mAngle(iAngle)
  {
  }

  /*!
   * \brief standard copy constructor
   */
  Angle(const Angle &other) = default;

  /*!
   * \brief standard move constructor
   */
  Angle(Angle &&other) = default;

  /**
   * \brief standard assignment operator
   *
   * \param[in] other Other Angle
   *
   * \returns Reference to this Angle.
   */
  Angle &operator=(const Angle &other) = default;

  /**
   * \brief standard move operator
   *
   * \param[in] other Other Angle
   *
   * \returns Reference to this Angle.
   */
  Angle &operator=(Angle &&other) = default;

  /**
   * \brief standard comparison operator
   *
   * \param[in] other Other Angle
   *
   * \returns \c true if both Angle are valid and can be taken as numerically equal
   */
  bool operator==(const Angle &other) const
  {
    ensureValid();
    other.ensureValid();
    return std::fabs(mAngle - other.mAngle) < cPrecisionValue;
  }

  /**
   * \brief standard comparison operator
   *
   * \param[in] other Other Angle.
   *
   * \returns \c true if one of the Angle is not valid or they can be taken as numerically different
   */
  bool operator!=(const Angle &other) const
  {
    return !operator==(other);
  }

  /**
   * \brief standard comparison operator
   *
   * \param[in] other Other Angle.
   *
   * \returns \c true if both Angle are valid and
   *   this Angle is strictly numerically greater than other.
   * \note the precision of Angle is considered
   */
  bool operator>(const Angle &other) const
  {
    ensureValid();
    other.ensureValid();
    return (mAngle > other.mAngle) && operator!=(other);
  }

  /**
   * \brief standard comparison operator
   *
   * \param[in] other Other Angle.
   *
   * \returns \c true if both Angle are valid and
   *   this Angle is strictly numerically smaller than other.
   * \note the precision of Angle is considered
   */
  bool operator<(const Angle &other) const
  {
    ensureValid();
    other.ensureValid();
    return (mAngle < other.mAngle) && operator!=(other);
  }

  /**
   * \brief standard comparison operator
   *
   * \param[in] other Other Angle.
   *
   * \returns \c true if both Angle are valid and
   *   this Angle is numerically greater than other.
   * \note the precision of Angle is considered
   */
  bool operator>=(const Angle &other) const
  {
    ensureValid();
    other.ensureValid();
    return ((mAngle > other.mAngle) || operator==(other));
  }

  /**
   * \brief standard comparison operator
   *
   * \param[in] other Other Angle
   *
   * \returns \c true if both Angle are valid and
   *   this Angle is numerically smaller than other.
   * \note the precision of Angle is considered
   */
  bool operator<=(const Angle &other) const
  {
    ensureValid();
    other.ensureValid();
    return ((mAngle < other.mAngle) || operator==(other));
  }

  /**
   * \brief standard arithmetic operator
   *
   * \param[in] other Other Angle
   *
   * \returns Result of arithmetic operation.
   *
   * \note throws a std::out_of_range exception if one of the two operands or the result of
   *   the operation is not valid
   */
  Angle operator+(const Angle &other) const
  {
    ensureValid();
    other.ensureValid();
    Angle result(mAngle + other.mAngle);
    result.restrictToLimitsAndEnsureValid();
    return result;
  }

  /**
   * \brief standard arithmetic operator
   *
   * \param[in] other Other Angle
   *
   * \returns Result of arithmetic operation.
   *
   * \note throws a std::out_of_range exception if one of the two operands or the result of
   *   the operation is not valid
   */
  Angle &operator+=(const Angle &other)
  {
    ensureValid();
    other.ensureValid();
    mAngle += other.mAngle;
    restrictToLimitsAndEnsureValid();
    return *this;
  }

  /**
   * \brief standard arithmetic operator
   *
   * \param[in] other Other Angle
   *
   * \returns Result of arithmetic operation.
   *
   * \note throws a std::out_of_range exception if one of the two operands or the result of
   *   the operation is not valid
   */
  Angle operator-(const Angle &other) const
  {
    ensureValid();
    other.ensureValid();
    Angle result(mAngle - other.mAngle);
    result.restrictToLimitsAndEnsureValid();
    return result;
  }

  /**
   * \brief standard arithmetic operator
   *
   * \param[in] other Other Angle
   *
   * \returns Result of arithmetic operation.
   *
   * \note throws a std::out_of_range exception if one of the two operands or the result of
   *   the operation is not valid
   */
  Angle operator-=(const Angle &other)
  {
    ensureValid();
    other.ensureValid();
    mAngle -= other.mAngle;
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
  Angle operator*(const double &scalar) const
  {
    ensureValid();
    Angle result(mAngle * scalar);
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
  Angle operator/(const double &scalar) const
  {
    Angle const scalarAngle(scalar);
    Angle result(operator/(scalarAngle));
    result.restrictToLimitsAndEnsureValid();
    return result;
  }

  /**
   * \brief standard arithmetic operator
   *
   * \param[in] other Other Angle
   *
   * \returns Result of arithmetic operation.
   *
   * \note throws a std::out_of_range exception if one of the two operands or the result of
   *   the operation is not valid or other is zero
   * \note since Angle is a type with physical unit, the division results in the dimensionless type.
   */
  double operator/(const Angle &other) const
  {
    ensureValid();
    other.ensureValidNonZero();
    double const result = mAngle / other.mAngle;
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
  Angle operator-() const
  {
    ensureValid();
    Angle result(-mAngle);
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
    return mAngle;
  }

  /*!
   * \returns \c true if the Angle is a normal value
   *
   * An Angle value is defined to be normal if:
   * - It is normal or zero (see std::fpclassify())
   */
  bool isNormal() const
  {
    auto const valueClass = std::fpclassify(mAngle);
    return ((valueClass == FP_NORMAL) || (valueClass == FP_ZERO));
  }

#if _AD_PHYSICS_ANGLE_OPERATOR_BASE_TYPE_
  /*!
   * \brief conversion to base type: double
   *
   * \note the conversion to the base type removes the physical unit.
   */
  operator double() const
  {
    return mAngle;
  }
#endif

  /*!
   * \returns \c true if the Angle in a valid range
   *
   * An Angle value is defined to be valid if:
   * - It is normal or zero (see std::fpclassify())
   * - \ref cMinValue <= value <= \ref cMaxValue
   */
  bool isValid() const
  {
    return isNormal() && (cMinValue <= mAngle) && (mAngle <= cMaxValue);
  }

  /*!
   * \brief ensure that the Angle is valid
   *
   * Throws an std::out_of_range() exception if the Angle
   * in not valid (i.e. isValid() returns false)
   */
  void ensureValid() const
  {
    if (!isValid())
    {
      spdlog::info("ensureValid(::ad::physics::Angle)>> {} value out of range",
                   *this); // LCOV_EXCL_BR_LINE
#if (AD_PHYSICS_ANGLE_THROWS_EXCEPTION == 1)
      throw std::out_of_range("Angle value out of range"); // LCOV_EXCL_BR_LINE
#endif
    }
  }

  /*!
   * \brief ensure that the Angle is valid and non zero
   *
   * Throws an std::out_of_range() exception if the Angle
   * in not valid or zero (i.e. isValid() returns false)
   */
  void ensureValidNonZero() const
  {
    ensureValid();
    if (operator==(Angle(0.))) // LCOV_EXCL_BR_LINE
    {
      spdlog::info("ensureValid(::ad::physics::Angle)>> {} value is zero",
                   *this); // LCOV_EXCL_BR_LINE
#if (AD_PHYSICS_ANGLE_THROWS_EXCEPTION == 1)
      throw std::out_of_range("Angle value is zero"); // LCOV_EXCL_BR_LINE
#endif
    }
  }

  /**
   * @brief if possible restrict the Angle to it's defined limits
   *
   * If the Angle isNormal(), but exceeds the defined limits, it is restricted to its limits.
   * If Angle::isNormal() returns \c false an std::out_of_range() exception is thrown.
   * - not isNormal(): std::out_of_range() exception is thrown
   * - \ref cMinValue <= value <= \ref cMaxValue: nothing is done
   * - value < \ref cMinValue: resulting value = cMinValue
   * - value > \ref cMaxValue: resulting value = cMaxValue
   */
  void restrictToLimitsAndEnsureValid()
  {
    if (isNormal())
    {
      if (mAngle < cMinValue)
      {
        // mitigate exceeding the minimum
        spdlog::info("restrictToLimits(::ad::physics::Angle)>> {} value is smaller than allowed minimum {}. Restrict "
                     "to minimum value.",
                     *this,
                     getMin()); // LCOV_EXCL_BR_LINE
        mAngle = cMinValue;
      }
      else if (mAngle > cMaxValue)
      {
        // mitigate exceeding the maximum
        spdlog::info("restrictToLimits(::ad::physics::Angle)>> {} value is larger than allowed maximum {}. Restrict to "
                     "maximum value.",
                     *this,
                     getMax()); // LCOV_EXCL_BR_LINE
        mAngle = cMaxValue;
      }
    }
    else
    {
      spdlog::info("restrictToLimits(::ad::physics::Angle)>> {} value out of range", *this); // LCOV_EXCL_BR_LINE
#if (AD_PHYSICS_ANGLE_THROWS_EXCEPTION == 1)
      throw std::out_of_range("Angle value out of range"); // LCOV_EXCL_BR_LINE
#endif
    }
  }

  /*!
   * \brief get minimum valid Angle (i.e. \ref cMinValue)
   */
  static Angle getMin()
  {
    return Angle(cMinValue);
  }

  /*!
   * \brief get maximum valid Angle (i.e. \ref cMaxValue)
   */
  static Angle getMax()
  {
    return Angle(cMaxValue);
  }

  /*!
   * \brief get assumed accuracy of Angle (i.e. \ref cPrecisionValue)
   */
  static Angle getPrecision()
  {
    return Angle(cPrecisionValue);
  }

  /*!
   * \brief the actual value of the type
   */
  double mAngle;
};

} // namespace physics
} // namespace ad
/**
 * \brief standard arithmetic operator
 *
 * \param[in] other Other Angle as double value
 * \param[in] value Angle value
 *
 * \returns Result of arithmetic operation.
 *
 * \note throws a std::out_of_range exception if \c value or the result of
 *   the operation is not valid
 */
inline ::ad::physics::Angle operator*(const double &other, ::ad::physics::Angle const &value)
{
  return value.operator*(other);
}

/*!
 * \brief namespace std
 */
namespace std {

/*!
 * \brief overload of the std::fabs for Angle
 */
inline ::ad::physics::Angle fabs(const ::ad::physics::Angle other)
{
  ::ad::physics::Angle const result(std::fabs(other.mAngle));
  return result;
}

/*!
 * \brief specialization of the std::numeric_limits for Angle
 *
 * Derived from std::numeric_limits<double> with overloaded functions:
 * std::numeric_limits<Angle>::lowest()  (\see Angle::getMin())
 * std::numeric_limits<Angle>::max()  (\see Angle::getMax())
 * std::numeric_limits<Angle>::epsilon()  (\see Angle::getPrecision())
 */
template <> class numeric_limits<::ad::physics::Angle> : public numeric_limits<double>
{
public:
  /*!
   * \see std::numeric_limits::lowest()
   */
  static inline ::ad::physics::Angle lowest()
  {
    return ::ad::physics::Angle::getMin();
  }
  /*!
   * \see std::numeric_limits::max()
   */
  static inline ::ad::physics::Angle max()
  {
    return ::ad::physics::Angle::getMax();
  }

  /*!
   * \see std::numeric_limits::epsilon()
   */
  static inline ::ad::physics::Angle epsilon()
  {
    return ::ad::physics::Angle::getPrecision();
  }
};

} // namespace std

/*!
 * \brief protect the definition of functions from duplicates by typedef usage within other data types
 */
#ifndef GEN_GUARD_AD_PHYSICS_ANGLE
#define GEN_GUARD_AD_PHYSICS_ANGLE
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
 * \param[in] _value Angle value
 *
 * \returns The stream object.
 *
 */
inline std::ostream &operator<<(std::ostream &os, Angle const &_value)
{
  return os << _value.mAngle;
}

} // namespace physics
} // namespace ad

namespace std {
/*!
 * \brief overload of the std::to_string for Angle
 */
inline std::string to_string(::ad::physics::Angle const &value)
{
  return to_string(value.mAngle);
}
} // namespace std

/*!
 * \brief overload of fmt::formatter calling std::to_string
 */
template <> struct fmt::formatter<::ad::physics::Angle> : formatter<string_view>
{
  template <typename FormatContext> auto format(::ad::physics::Angle const &value, FormatContext &ctx)
  {
    return formatter<string_view>::format(std::to_string(value), ctx);
  }
};

#endif // GEN_GUARD_AD_PHYSICS_ANGLE
