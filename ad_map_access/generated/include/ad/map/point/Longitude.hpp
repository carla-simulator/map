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
#define AD_MAP_POINT_LONGITUDE_THROWS_EXCEPTION 1

#if SAFE_DATATYPES_EXPLICIT_CONVERSION
/*!
 * \brief Enable/Disable explicit conversion. Currently set to "only explicit conversion".
 */
#define _AD_MAP_POINT_LONGITUDE_EXPLICIT_CONVERSION_ explicit
#define _AD_MAP_POINT_LONGITUDE_OPERATOR_BASE_TYPE_ 0
#else
/*!
 * \brief Enable/Disable explicit conversion. Currently set to "implicit conversion allowed".
 */
#define _AD_MAP_POINT_LONGITUDE_EXPLICIT_CONVERSION_
#define _AD_MAP_POINT_LONGITUDE_OPERATOR_BASE_TYPE_ 1
#endif

/*!
 * \brief DataType Longitude
 *
 * WGS-84 Longitude
 * The unit is: Degree
 */
class Longitude
{
public:
  /*!
   * \brief constant defining the minimum valid Longitude value (used in isValid())
   */
  static const double cMinValue;

  /*!
   * \brief constant defining the maximum valid Longitude value (used in isValid())
   */
  static const double cMaxValue;

  /*!
   * \brief constant defining the assumed Longitude value accuracy
   *   (used in comparison operator==(), operator!=())
   */
  static const double cPrecisionValue;

  /*!
   * \brief default constructor
   *
   * The default value of Longitude is:
   * std::numeric_limits<double>::quiet_NaN()
   */
  Longitude()
    : mLongitude(std::numeric_limits<double>::quiet_NaN())
  {
  }

  /*!
   * \brief standard constructor
   *
   * \note \ref \_AD_MAP_POINT_LONGITUDE_EXPLICIT_CONVERSION\_ defines, if only an explicit conversion is allowed.
   */
  _AD_MAP_POINT_LONGITUDE_EXPLICIT_CONVERSION_ Longitude(double const iLongitude)
    : mLongitude(iLongitude)
  {
  }

  /*!
   * \brief standard copy constructor
   */
  Longitude(const Longitude &other) = default;

  /*!
   * \brief standard move constructor
   */
  Longitude(Longitude &&other) = default;

  /**
   * \brief standard assignment operator
   *
   * \param[in] other Other Longitude
   *
   * \returns Reference to this Longitude.
   */
  Longitude &operator=(const Longitude &other) = default;

  /**
   * \brief standard move operator
   *
   * \param[in] other Other Longitude
   *
   * \returns Reference to this Longitude.
   */
  Longitude &operator=(Longitude &&other) = default;

  /**
   * \brief standard comparison operator
   *
   * \param[in] other Other Longitude
   *
   * \returns \c true if both Longitude are valid and can be taken as numerically equal
   */
  bool operator==(const Longitude &other) const
  {
    ensureValid();
    other.ensureValid();
    return std::fabs(mLongitude - other.mLongitude) < cPrecisionValue;
  }

  /**
   * \brief standard comparison operator
   *
   * \param[in] other Other Longitude.
   *
   * \returns \c true if one of the Longitude is not valid or they can be taken as numerically different
   */
  bool operator!=(const Longitude &other) const
  {
    return !operator==(other);
  }

  /**
   * \brief standard comparison operator
   *
   * \param[in] other Other Longitude.
   *
   * \returns \c true if both Longitude are valid and
   *   this Longitude is strictly numerically greater than other.
   * \note the precision of Longitude is considered
   */
  bool operator>(const Longitude &other) const
  {
    ensureValid();
    other.ensureValid();
    return (mLongitude > other.mLongitude) && operator!=(other);
  }

  /**
   * \brief standard comparison operator
   *
   * \param[in] other Other Longitude.
   *
   * \returns \c true if both Longitude are valid and
   *   this Longitude is strictly numerically smaller than other.
   * \note the precision of Longitude is considered
   */
  bool operator<(const Longitude &other) const
  {
    ensureValid();
    other.ensureValid();
    return (mLongitude < other.mLongitude) && operator!=(other);
  }

  /**
   * \brief standard comparison operator
   *
   * \param[in] other Other Longitude.
   *
   * \returns \c true if both Longitude are valid and
   *   this Longitude is numerically greater than other.
   * \note the precision of Longitude is considered
   */
  bool operator>=(const Longitude &other) const
  {
    ensureValid();
    other.ensureValid();
    return ((mLongitude > other.mLongitude) || operator==(other));
  }

  /**
   * \brief standard comparison operator
   *
   * \param[in] other Other Longitude
   *
   * \returns \c true if both Longitude are valid and
   *   this Longitude is numerically smaller than other.
   * \note the precision of Longitude is considered
   */
  bool operator<=(const Longitude &other) const
  {
    ensureValid();
    other.ensureValid();
    return ((mLongitude < other.mLongitude) || operator==(other));
  }

  /**
   * \brief standard arithmetic operator
   *
   * \param[in] other Other Longitude
   *
   * \returns Result of arithmetic operation.
   *
   * \note throws a std::out_of_range exception if one of the two operands or the result of
   *   the operation is not valid
   */
  Longitude operator+(const Longitude &other) const
  {
    ensureValid();
    other.ensureValid();
    Longitude result(mLongitude + other.mLongitude);
    result.restrictToLimitsAndEnsureValid();
    return result;
  }

  /**
   * \brief standard arithmetic operator
   *
   * \param[in] other Other Longitude
   *
   * \returns Result of arithmetic operation.
   *
   * \note throws a std::out_of_range exception if one of the two operands or the result of
   *   the operation is not valid
   */
  Longitude &operator+=(const Longitude &other)
  {
    ensureValid();
    other.ensureValid();
    mLongitude += other.mLongitude;
    restrictToLimitsAndEnsureValid();
    return *this;
  }

  /**
   * \brief standard arithmetic operator
   *
   * \param[in] other Other Longitude
   *
   * \returns Result of arithmetic operation.
   *
   * \note throws a std::out_of_range exception if one of the two operands or the result of
   *   the operation is not valid
   */
  Longitude operator-(const Longitude &other) const
  {
    ensureValid();
    other.ensureValid();
    Longitude result(mLongitude - other.mLongitude);
    result.restrictToLimitsAndEnsureValid();
    return result;
  }

  /**
   * \brief standard arithmetic operator
   *
   * \param[in] other Other Longitude
   *
   * \returns Result of arithmetic operation.
   *
   * \note throws a std::out_of_range exception if one of the two operands or the result of
   *   the operation is not valid
   */
  Longitude operator-=(const Longitude &other)
  {
    ensureValid();
    other.ensureValid();
    mLongitude -= other.mLongitude;
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
  Longitude operator*(const double &scalar) const
  {
    ensureValid();
    Longitude result(mLongitude * scalar);
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
  Longitude operator/(const double &scalar) const
  {
    Longitude const scalarLongitude(scalar);
    Longitude result(operator/(scalarLongitude));
    result.restrictToLimitsAndEnsureValid();
    return result;
  }

  /**
   * \brief standard arithmetic operator
   *
   * \param[in] other Other Longitude
   *
   * \returns Result of arithmetic operation.
   *
   * \note throws a std::out_of_range exception if one of the two operands or the result of
   *   the operation is not valid or other is zero
   * \note since Longitude is a type with physical unit, the division results in the dimensionless type.
   */
  double operator/(const Longitude &other) const
  {
    ensureValid();
    other.ensureValidNonZero();
    double const result = mLongitude / other.mLongitude;
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
  Longitude operator-() const
  {
    ensureValid();
    Longitude result(-mLongitude);
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
    return mLongitude;
  }

  /*!
   * \returns \c true if the Longitude is a normal value
   *
   * An Longitude value is defined to be normal if:
   * - It is normal or zero (see std::fpclassify())
   */
  bool isNormal() const
  {
    auto const valueClass = std::fpclassify(mLongitude);
    return ((valueClass == FP_NORMAL) || (valueClass == FP_ZERO));
  }

#if _AD_MAP_POINT_LONGITUDE_OPERATOR_BASE_TYPE_
  /*!
   * \brief conversion to base type: double
   *
   * \note the conversion to the base type removes the physical unit.
   */
  operator double() const
  {
    return mLongitude;
  }
#endif

  /*!
   * \returns \c true if the Longitude in a valid range
   *
   * An Longitude value is defined to be valid if:
   * - It is normal or zero (see std::fpclassify())
   * - \ref cMinValue <= value <= \ref cMaxValue
   */
  bool isValid() const
  {
    return isNormal() && (cMinValue <= mLongitude) && (mLongitude <= cMaxValue);
  }

  /*!
   * \brief ensure that the Longitude is valid
   *
   * Throws an std::out_of_range() exception if the Longitude
   * in not valid (i.e. isValid() returns false)
   */
  void ensureValid() const
  {
    if (!isValid())
    {
      spdlog::info("ensureValid(::ad::map::point::Longitude)>> {} value out of range",
                   *this); // LCOV_EXCL_BR_LINE
#if (AD_MAP_POINT_LONGITUDE_THROWS_EXCEPTION == 1)
      throw std::out_of_range("Longitude value out of range"); // LCOV_EXCL_BR_LINE
#endif
    }
  }

  /*!
   * \brief ensure that the Longitude is valid and non zero
   *
   * Throws an std::out_of_range() exception if the Longitude
   * in not valid or zero (i.e. isValid() returns false)
   */
  void ensureValidNonZero() const
  {
    ensureValid();
    if (operator==(Longitude(0.))) // LCOV_EXCL_BR_LINE
    {
      spdlog::info("ensureValid(::ad::map::point::Longitude)>> {} value is zero",
                   *this); // LCOV_EXCL_BR_LINE
#if (AD_MAP_POINT_LONGITUDE_THROWS_EXCEPTION == 1)
      throw std::out_of_range("Longitude value is zero"); // LCOV_EXCL_BR_LINE
#endif
    }
  }

  /**
   * @brief if possible restrict the Longitude to it's defined limits
   *
   * If the Longitude isNormal(), but exceeds the defined limits, it is restricted to its limits.
   * If Longitude::isNormal() returns \c false an std::out_of_range() exception is thrown.
   * - not isNormal(): std::out_of_range() exception is thrown
   * - \ref cMinValue <= value <= \ref cMaxValue: nothing is done
   * - value < \ref cMinValue: resulting value = cMinValue
   * - value > \ref cMaxValue: resulting value = cMaxValue
   */
  void restrictToLimitsAndEnsureValid()
  {
    if (isNormal())
    {
      if (mLongitude < cMinValue)
      {
        // mitigate exceeding the minimum
        spdlog::info("restrictToLimits(::ad::map::point::Longitude)>> {} value is smaller than allowed minimum {}. "
                     "Restrict to minimum value.",
                     *this,
                     getMin()); // LCOV_EXCL_BR_LINE
        mLongitude = cMinValue;
      }
      else if (mLongitude > cMaxValue)
      {
        // mitigate exceeding the maximum
        spdlog::info("restrictToLimits(::ad::map::point::Longitude)>> {} value is larger than allowed maximum {}. "
                     "Restrict to maximum value.",
                     *this,
                     getMax()); // LCOV_EXCL_BR_LINE
        mLongitude = cMaxValue;
      }
    }
    else
    {
      spdlog::info("restrictToLimits(::ad::map::point::Longitude)>> {} value out of range", *this); // LCOV_EXCL_BR_LINE
#if (AD_MAP_POINT_LONGITUDE_THROWS_EXCEPTION == 1)
      throw std::out_of_range("Longitude value out of range"); // LCOV_EXCL_BR_LINE
#endif
    }
  }

  /*!
   * \brief get minimum valid Longitude (i.e. \ref cMinValue)
   */
  static Longitude getMin()
  {
    return Longitude(cMinValue);
  }

  /*!
   * \brief get maximum valid Longitude (i.e. \ref cMaxValue)
   */
  static Longitude getMax()
  {
    return Longitude(cMaxValue);
  }

  /*!
   * \brief get assumed accuracy of Longitude (i.e. \ref cPrecisionValue)
   */
  static Longitude getPrecision()
  {
    return Longitude(cPrecisionValue);
  }

  /*!
   * \brief the actual value of the type
   */
  double mLongitude;
};

} // namespace point
} // namespace map
} // namespace ad
/**
 * \brief standard arithmetic operator
 *
 * \param[in] other Other Longitude as double value
 * \param[in] value Longitude value
 *
 * \returns Result of arithmetic operation.
 *
 * \note throws a std::out_of_range exception if \c value or the result of
 *   the operation is not valid
 */
inline ::ad::map::point::Longitude operator*(const double &other, ::ad::map::point::Longitude const &value)
{
  return value.operator*(other);
}

/*!
 * \brief namespace std
 */
namespace std {

/*!
 * \brief overload of the std::fabs for Longitude
 */
inline ::ad::map::point::Longitude fabs(const ::ad::map::point::Longitude other)
{
  ::ad::map::point::Longitude const result(std::fabs(other.mLongitude));
  return result;
}

/*!
 * \brief specialization of the std::numeric_limits for Longitude
 *
 * Derived from std::numeric_limits<double> with overloaded functions:
 * std::numeric_limits<Longitude>::lowest()  (\see Longitude::getMin())
 * std::numeric_limits<Longitude>::max()  (\see Longitude::getMax())
 * std::numeric_limits<Longitude>::epsilon()  (\see Longitude::getPrecision())
 */
template <> class numeric_limits<::ad::map::point::Longitude> : public numeric_limits<double>
{
public:
  /*!
   * \see std::numeric_limits::lowest()
   */
  static inline ::ad::map::point::Longitude lowest()
  {
    return ::ad::map::point::Longitude::getMin();
  }
  /*!
   * \see std::numeric_limits::max()
   */
  static inline ::ad::map::point::Longitude max()
  {
    return ::ad::map::point::Longitude::getMax();
  }

  /*!
   * \see std::numeric_limits::epsilon()
   */
  static inline ::ad::map::point::Longitude epsilon()
  {
    return ::ad::map::point::Longitude::getPrecision();
  }
};

} // namespace std

/*!
 * \brief protect the definition of functions from duplicates by typedef usage within other data types
 */
#ifndef GEN_GUARD_AD_MAP_POINT_LONGITUDE
#define GEN_GUARD_AD_MAP_POINT_LONGITUDE
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
 * \param[in] _value Longitude value
 *
 * \returns The stream object.
 *
 */
inline std::ostream &operator<<(std::ostream &os, Longitude const &_value)
{
  return os << _value.mLongitude;
}

} // namespace point
} // namespace map
} // namespace ad

namespace std {
/*!
 * \brief overload of the std::to_string for Longitude
 */
inline std::string to_string(::ad::map::point::Longitude const &value)
{
  return to_string(value.mLongitude);
}
} // namespace std

/*!
 * \brief overload of fmt::formatter calling std::to_string
 */
template <> struct fmt::formatter<::ad::map::point::Longitude> : formatter<string_view>
{
  template <typename FormatContext> auto format(::ad::map::point::Longitude const &value, FormatContext &ctx)
  {
    return formatter<string_view>::format(std::to_string(value), ctx);
  }
};

#endif // GEN_GUARD_AD_MAP_POINT_LONGITUDE
