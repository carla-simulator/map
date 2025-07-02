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
 * @brief namespace map
 */
namespace map {
/*!
 * @brief namespace point
 *
 * Handling geographic positions in different coordinate systems
 */
namespace point {

/*!
 * \brief Define to indicate whether throwing exceptions is enabled
 */
#define AD_MAP_POINT_ALTITUDE_THROWS_EXCEPTION 1

#if SAFE_DATATYPES_EXPLICIT_CONVERSION
/*!
 * \brief Enable/Disable explicit conversion. Currently set to "only explicit conversion".
 */
#define _AD_MAP_POINT_ALTITUDE_EXPLICIT_CONVERSION_ explicit
#define _AD_MAP_POINT_ALTITUDE_OPERATOR_BASE_TYPE_ 0
#else
/*!
 * \brief Enable/Disable explicit conversion. Currently set to "implicit conversion allowed".
 */
#define _AD_MAP_POINT_ALTITUDE_EXPLICIT_CONVERSION_
#define _AD_MAP_POINT_ALTITUDE_OPERATOR_BASE_TYPE_ 1
#endif

/*!
 * \brief DataType Altitude
 *
 * WGS-84 Altitude
 * Depth of the Mariana Trench [m] 10994
 * Height of the Mount Everest [m] 8848
 * The unit is: Meter
 */
class Altitude
{
public:
  /*!
   * \brief constant defining the minimum valid Altitude value (used in isValid())
   */
  static const double cMinValue;

  /*!
   * \brief constant defining the maximum valid Altitude value (used in isValid())
   */
  static const double cMaxValue;

  /*!
   * \brief constant defining the assumed Altitude value accuracy
   *   (used in comparison operator==(), operator!=())
   */
  static const double cPrecisionValue;

  /*!
   * \brief default constructor
   *
   * The default value of Altitude is:
   * std::numeric_limits<double>::quiet_NaN()
   */
  Altitude()
    : mAltitude(std::numeric_limits<double>::quiet_NaN())
  {
  }

  /*!
   * \brief standard constructor
   *
   * \note \ref \_AD_MAP_POINT_ALTITUDE_EXPLICIT_CONVERSION\_ defines, if only an explicit conversion is allowed.
   */
  _AD_MAP_POINT_ALTITUDE_EXPLICIT_CONVERSION_ Altitude(double const iAltitude)
    : mAltitude(iAltitude)
  {
  }

  /*!
   * \brief standard copy constructor
   */
  Altitude(const Altitude &other) = default;

  /*!
   * \brief standard move constructor
   */
  Altitude(Altitude &&other) = default;

  /**
   * \brief standard assignment operator
   *
   * \param[in] other Other Altitude
   *
   * \returns Reference to this Altitude.
   */
  Altitude &operator=(const Altitude &other) = default;

  /**
   * \brief standard move operator
   *
   * \param[in] other Other Altitude
   *
   * \returns Reference to this Altitude.
   */
  Altitude &operator=(Altitude &&other) = default;

  /**
   * \brief standard comparison operator
   *
   * \param[in] other Other Altitude
   *
   * \returns \c true if both Altitude are valid and can be taken as numerically equal
   */
  bool operator==(const Altitude &other) const
  {
    ensureValid();
    other.ensureValid();
    return std::fabs(mAltitude - other.mAltitude) < cPrecisionValue;
  }

  /**
   * \brief standard comparison operator
   *
   * \param[in] other Other Altitude.
   *
   * \returns \c true if one of the Altitude is not valid or they can be taken as numerically different
   */
  bool operator!=(const Altitude &other) const
  {
    return !operator==(other);
  }

  /**
   * \brief standard comparison operator
   *
   * \param[in] other Other Altitude.
   *
   * \returns \c true if both Altitude are valid and
   *   this Altitude is strictly numerically greater than other.
   * \note the precision of Altitude is considered
   */
  bool operator>(const Altitude &other) const
  {
    ensureValid();
    other.ensureValid();
    return (mAltitude > other.mAltitude) && operator!=(other);
  }

  /**
   * \brief standard comparison operator
   *
   * \param[in] other Other Altitude.
   *
   * \returns \c true if both Altitude are valid and
   *   this Altitude is strictly numerically smaller than other.
   * \note the precision of Altitude is considered
   */
  bool operator<(const Altitude &other) const
  {
    ensureValid();
    other.ensureValid();
    return (mAltitude < other.mAltitude) && operator!=(other);
  }

  /**
   * \brief standard comparison operator
   *
   * \param[in] other Other Altitude.
   *
   * \returns \c true if both Altitude are valid and
   *   this Altitude is numerically greater than other.
   * \note the precision of Altitude is considered
   */
  bool operator>=(const Altitude &other) const
  {
    ensureValid();
    other.ensureValid();
    return ((mAltitude > other.mAltitude) || operator==(other));
  }

  /**
   * \brief standard comparison operator
   *
   * \param[in] other Other Altitude
   *
   * \returns \c true if both Altitude are valid and
   *   this Altitude is numerically smaller than other.
   * \note the precision of Altitude is considered
   */
  bool operator<=(const Altitude &other) const
  {
    ensureValid();
    other.ensureValid();
    return ((mAltitude < other.mAltitude) || operator==(other));
  }

  /**
   * \brief standard arithmetic operator
   *
   * \param[in] other Other Altitude
   *
   * \returns Result of arithmetic operation.
   *
   * \note throws a std::out_of_range exception if one of the two operands or the result of
   *   the operation is not valid
   */
  Altitude operator+(const Altitude &other) const
  {
    ensureValid();
    other.ensureValid();
    Altitude result(mAltitude + other.mAltitude);
    result.restrictToLimitsAndEnsureValid();
    return result;
  }

  /**
   * \brief standard arithmetic operator
   *
   * \param[in] other Other Altitude
   *
   * \returns Result of arithmetic operation.
   *
   * \note throws a std::out_of_range exception if one of the two operands or the result of
   *   the operation is not valid
   */
  Altitude &operator+=(const Altitude &other)
  {
    ensureValid();
    other.ensureValid();
    mAltitude += other.mAltitude;
    restrictToLimitsAndEnsureValid();
    return *this;
  }

  /**
   * \brief standard arithmetic operator
   *
   * \param[in] other Other Altitude
   *
   * \returns Result of arithmetic operation.
   *
   * \note throws a std::out_of_range exception if one of the two operands or the result of
   *   the operation is not valid
   */
  Altitude operator-(const Altitude &other) const
  {
    ensureValid();
    other.ensureValid();
    Altitude result(mAltitude - other.mAltitude);
    result.restrictToLimitsAndEnsureValid();
    return result;
  }

  /**
   * \brief standard arithmetic operator
   *
   * \param[in] other Other Altitude
   *
   * \returns Result of arithmetic operation.
   *
   * \note throws a std::out_of_range exception if one of the two operands or the result of
   *   the operation is not valid
   */
  Altitude operator-=(const Altitude &other)
  {
    ensureValid();
    other.ensureValid();
    mAltitude -= other.mAltitude;
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
  Altitude operator*(const double &scalar) const
  {
    ensureValid();
    Altitude result(mAltitude * scalar);
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
  Altitude operator/(const double &scalar) const
  {
    Altitude const scalarAltitude(scalar);
    Altitude result(operator/(scalarAltitude));
    result.restrictToLimitsAndEnsureValid();
    return result;
  }

  /**
   * \brief standard arithmetic operator
   *
   * \param[in] other Other Altitude
   *
   * \returns Result of arithmetic operation.
   *
   * \note throws a std::out_of_range exception if one of the two operands or the result of
   *   the operation is not valid or other is zero
   * \note since Altitude is a type with physical unit, the division results in the dimensionless type.
   */
  double operator/(const Altitude &other) const
  {
    ensureValid();
    other.ensureValidNonZero();
    double const result = mAltitude / other.mAltitude;
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
  Altitude operator-() const
  {
    ensureValid();
    Altitude result(-mAltitude);
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
    return mAltitude;
  }

  /*!
   * \returns \c true if the Altitude is a normal value
   *
   * An Altitude value is defined to be normal if:
   * - It is normal or zero (see std::fpclassify())
   */
  bool isNormal() const
  {
    auto const valueClass = std::fpclassify(mAltitude);
    return ((valueClass == FP_NORMAL) || (valueClass == FP_ZERO));
  }

#if _AD_MAP_POINT_ALTITUDE_OPERATOR_BASE_TYPE_
  /*!
   * \brief conversion to base type: double
   *
   * \note the conversion to the base type removes the physical unit.
   */
  operator double() const
  {
    return mAltitude;
  }
#endif

  /*!
   * \returns \c true if the Altitude in a valid range
   *
   * An Altitude value is defined to be valid if:
   * - It is normal or zero (see std::fpclassify())
   * - \ref cMinValue <= value <= \ref cMaxValue
   */
  bool isValid() const
  {
    return isNormal() && (cMinValue <= mAltitude) && (mAltitude <= cMaxValue);
  }

  /*!
   * \brief ensure that the Altitude is valid
   *
   * Throws an std::out_of_range() exception if the Altitude
   * in not valid (i.e. isValid() returns false)
   */
  void ensureValid() const
  {
    if (!isValid())
    {
      spdlog::info("ensureValid(::ad::map::point::Altitude)>> {} value out of range",
                   *this); // LCOV_EXCL_BR_LINE
#if (AD_MAP_POINT_ALTITUDE_THROWS_EXCEPTION == 1)
      throw std::out_of_range("Altitude value out of range"); // LCOV_EXCL_BR_LINE
#endif
    }
  }

  /*!
   * \brief ensure that the Altitude is valid and non zero
   *
   * Throws an std::out_of_range() exception if the Altitude
   * in not valid or zero (i.e. isValid() returns false)
   */
  void ensureValidNonZero() const
  {
    ensureValid();
    if (operator==(Altitude(0.))) // LCOV_EXCL_BR_LINE
    {
      spdlog::info("ensureValid(::ad::map::point::Altitude)>> {} value is zero",
                   *this); // LCOV_EXCL_BR_LINE
#if (AD_MAP_POINT_ALTITUDE_THROWS_EXCEPTION == 1)
      throw std::out_of_range("Altitude value is zero"); // LCOV_EXCL_BR_LINE
#endif
    }
  }

  /**
   * @brief if possible restrict the Altitude to it's defined limits
   *
   * If the Altitude isNormal(), but exceeds the defined limits, it is restricted to its limits.
   * If Altitude::isNormal() returns \c false an std::out_of_range() exception is thrown.
   * - not isNormal(): std::out_of_range() exception is thrown
   * - \ref cMinValue <= value <= \ref cMaxValue: nothing is done
   * - value < \ref cMinValue: resulting value = cMinValue
   * - value > \ref cMaxValue: resulting value = cMaxValue
   */
  void restrictToLimitsAndEnsureValid()
  {
    if (isNormal())
    {
      if (mAltitude < cMinValue)
      {
        // mitigate exceeding the minimum
        spdlog::info("restrictToLimits(::ad::map::point::Altitude)>> {} value is smaller than allowed minimum {}. "
                     "Restrict to minimum value.",
                     *this,
                     getMin()); // LCOV_EXCL_BR_LINE
        mAltitude = cMinValue;
      }
      else if (mAltitude > cMaxValue)
      {
        // mitigate exceeding the maximum
        spdlog::info("restrictToLimits(::ad::map::point::Altitude)>> {} value is larger than allowed maximum {}. "
                     "Restrict to maximum value.",
                     *this,
                     getMax()); // LCOV_EXCL_BR_LINE
        mAltitude = cMaxValue;
      }
    }
    else
    {
      spdlog::info("restrictToLimits(::ad::map::point::Altitude)>> {} value out of range", *this); // LCOV_EXCL_BR_LINE
#if (AD_MAP_POINT_ALTITUDE_THROWS_EXCEPTION == 1)
      throw std::out_of_range("Altitude value out of range"); // LCOV_EXCL_BR_LINE
#endif
    }
  }

  /*!
   * \brief get minimum valid Altitude (i.e. \ref cMinValue)
   */
  static Altitude getMin()
  {
    return Altitude(cMinValue);
  }

  /*!
   * \brief get maximum valid Altitude (i.e. \ref cMaxValue)
   */
  static Altitude getMax()
  {
    return Altitude(cMaxValue);
  }

  /*!
   * \brief get assumed accuracy of Altitude (i.e. \ref cPrecisionValue)
   */
  static Altitude getPrecision()
  {
    return Altitude(cPrecisionValue);
  }

  /*!
   * \brief the actual value of the type
   */
  double mAltitude;
};

} // namespace point
} // namespace map
} // namespace ad
/**
 * \brief standard arithmetic operator
 *
 * \param[in] other Other Altitude as double value
 * \param[in] value Altitude value
 *
 * \returns Result of arithmetic operation.
 *
 * \note throws a std::out_of_range exception if \c value or the result of
 *   the operation is not valid
 */
inline ::ad::map::point::Altitude operator*(const double &other, ::ad::map::point::Altitude const &value)
{
  return value.operator*(other);
}

/*!
 * \brief namespace std
 */
namespace std {

/*!
 * \brief overload of the std::fabs for Altitude
 */
inline ::ad::map::point::Altitude fabs(const ::ad::map::point::Altitude other)
{
  ::ad::map::point::Altitude const result(std::fabs(other.mAltitude));
  return result;
}

/*!
 * \brief specialization of the std::numeric_limits for Altitude
 *
 * Derived from std::numeric_limits<double> with overloaded functions:
 * std::numeric_limits<Altitude>::lowest()  (\see Altitude::getMin())
 * std::numeric_limits<Altitude>::max()  (\see Altitude::getMax())
 * std::numeric_limits<Altitude>::epsilon()  (\see Altitude::getPrecision())
 */
template <> class numeric_limits<::ad::map::point::Altitude> : public numeric_limits<double>
{
public:
  /*!
   * \see std::numeric_limits::lowest()
   */
  static inline ::ad::map::point::Altitude lowest()
  {
    return ::ad::map::point::Altitude::getMin();
  }
  /*!
   * \see std::numeric_limits::max()
   */
  static inline ::ad::map::point::Altitude max()
  {
    return ::ad::map::point::Altitude::getMax();
  }

  /*!
   * \see std::numeric_limits::epsilon()
   */
  static inline ::ad::map::point::Altitude epsilon()
  {
    return ::ad::map::point::Altitude::getPrecision();
  }
};

} // namespace std

/*!
 * \brief protect the definition of functions from duplicates by typedef usage within other data types
 */
#ifndef GEN_GUARD_AD_MAP_POINT_ALTITUDE
#define GEN_GUARD_AD_MAP_POINT_ALTITUDE
/*!
 * @brief namespace ad
 */
namespace ad {
/*!
 * @brief namespace map
 */
namespace map {
/*!
 * @brief namespace point
 *
 * Handling geographic positions in different coordinate systems
 */
namespace point {

/**
 * \brief standard ostream operator
 *
 * \param[in] os The output stream to write to
 * \param[in] _value Altitude value
 *
 * \returns The stream object.
 *
 */
inline std::ostream &operator<<(std::ostream &os, Altitude const &_value)
{
  return os << _value.mAltitude;
}

} // namespace point
} // namespace map
} // namespace ad

namespace std {
/*!
 * \brief overload of the std::to_string for Altitude
 */
inline std::string to_string(::ad::map::point::Altitude const &value)
{
  return to_string(value.mAltitude);
}
} // namespace std

/*!
 * \brief overload of fmt::formatter calling std::to_string
 */
template <> struct fmt::formatter<::ad::map::point::Altitude> : formatter<string_view>
{
  template <typename FormatContext> auto format(::ad::map::point::Altitude const &value, FormatContext &ctx)
  {
    return formatter<string_view>::format(std::to_string(value), ctx);
  }
};

#endif // GEN_GUARD_AD_MAP_POINT_ALTITUDE
