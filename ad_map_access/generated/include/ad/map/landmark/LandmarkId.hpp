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
#include <cstdint>
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
 * @brief namespace landmark
 *
 * Handling of landmarks
 */
namespace landmark {

/*!
 * \brief Define to indicate whether throwing exceptions is enabled
 */
#define AD_MAP_LANDMARK_LANDMARKID_THROWS_EXCEPTION 1

#if SAFE_DATATYPES_EXPLICIT_CONVERSION
/*!
 * \brief Enable/Disable explicit conversion. Currently set to "only explicit conversion".
 */
#define _AD_MAP_LANDMARK_LANDMARKID_EXPLICIT_CONVERSION_ explicit
#define _AD_MAP_LANDMARK_LANDMARKID_OPERATOR_BASE_TYPE_ 0
#else
/*!
 * \brief Enable/Disable explicit conversion. Currently set to "implicit conversion allowed".
 */
#define _AD_MAP_LANDMARK_LANDMARKID_EXPLICIT_CONVERSION_
#define _AD_MAP_LANDMARK_LANDMARKID_OPERATOR_BASE_TYPE_ 1
#endif

/*!
 * \brief DataType LandmarkId
 *
 * Identifier of a landmark
 * The unit is: Identifier
 */
class LandmarkId
{
public:
  /*!
   * \brief constant defining the minimum valid LandmarkId value (used in isValid())
   */
  static const uint64_t cMinValue;

  /*!
   * \brief constant defining the maximum valid LandmarkId value (used in isValid())
   */
  static const uint64_t cMaxValue;

  /*!
   * \brief default constructor
   *
   * The default value of LandmarkId is:
   * std::numeric_limits<uint64_t>::quiet_NaN()
   */
  LandmarkId()
    : mLandmarkId(std::numeric_limits<uint64_t>::quiet_NaN())
  {
  }

  /*!
   * \brief standard constructor
   *
   * \note \ref \_AD_MAP_LANDMARK_LANDMARKID_EXPLICIT_CONVERSION\_ defines, if only an explicit conversion is allowed.
   */
  _AD_MAP_LANDMARK_LANDMARKID_EXPLICIT_CONVERSION_ LandmarkId(uint64_t const iLandmarkId)
    : mLandmarkId(iLandmarkId)
  {
  }

  /*!
   * \brief standard copy constructor
   */
  LandmarkId(const LandmarkId &other) = default;

  /*!
   * \brief standard move constructor
   */
  LandmarkId(LandmarkId &&other) = default;

  /**
   * \brief standard assignment operator
   *
   * \param[in] other Other LandmarkId
   *
   * \returns Reference to this LandmarkId.
   */
  LandmarkId &operator=(const LandmarkId &other) = default;

  /**
   * \brief standard move operator
   *
   * \param[in] other Other LandmarkId
   *
   * \returns Reference to this LandmarkId.
   */
  LandmarkId &operator=(LandmarkId &&other) = default;

  /**
   * \brief standard comparison operator
   *
   * \param[in] other Other LandmarkId
   *
   * \returns \c true if both LandmarkId are valid and can be taken as numerically equal
   */
  bool operator==(const LandmarkId &other) const
  {
    ensureValid();
    other.ensureValid();
    return mLandmarkId == other.mLandmarkId;
  }

  /**
   * \brief standard comparison operator
   *
   * \param[in] other Other LandmarkId.
   *
   * \returns \c true if one of the LandmarkId is not valid or they can be taken as numerically different
   */
  bool operator!=(const LandmarkId &other) const
  {
    return !operator==(other);
  }

  /**
   * \brief standard comparison operator
   *
   * \param[in] other Other LandmarkId.
   *
   * \returns \c true if both LandmarkId are valid and
   *   this LandmarkId is strictly numerically greater than other.
   * \note the precision of LandmarkId is considered
   */
  bool operator>(const LandmarkId &other) const
  {
    ensureValid();
    other.ensureValid();
    return (mLandmarkId > other.mLandmarkId) && operator!=(other);
  }

  /**
   * \brief standard comparison operator
   *
   * \param[in] other Other LandmarkId.
   *
   * \returns \c true if both LandmarkId are valid and
   *   this LandmarkId is strictly numerically smaller than other.
   * \note the precision of LandmarkId is considered
   */
  bool operator<(const LandmarkId &other) const
  {
    ensureValid();
    other.ensureValid();
    return (mLandmarkId < other.mLandmarkId) && operator!=(other);
  }

  /**
   * \brief standard comparison operator
   *
   * \param[in] other Other LandmarkId.
   *
   * \returns \c true if both LandmarkId are valid and
   *   this LandmarkId is numerically greater than other.
   * \note the precision of LandmarkId is considered
   */
  bool operator>=(const LandmarkId &other) const
  {
    ensureValid();
    other.ensureValid();
    return ((mLandmarkId > other.mLandmarkId) || operator==(other));
  }

  /**
   * \brief standard comparison operator
   *
   * \param[in] other Other LandmarkId
   *
   * \returns \c true if both LandmarkId are valid and
   *   this LandmarkId is numerically smaller than other.
   * \note the precision of LandmarkId is considered
   */
  bool operator<=(const LandmarkId &other) const
  {
    ensureValid();
    other.ensureValid();
    return ((mLandmarkId < other.mLandmarkId) || operator==(other));
  }

  /**
   * \brief standard arithmetic operator
   *
   * \param[in] other Other LandmarkId
   *
   * \returns Result of arithmetic operation.
   *
   * \note throws a std::out_of_range exception if one of the two operands or the result of
   *   the operation is not valid
   */
  LandmarkId operator+(const LandmarkId &other) const
  {
    ensureValid();
    other.ensureValid();
    LandmarkId result(mLandmarkId + other.mLandmarkId);
    result.restrictToLimitsAndEnsureValid();
    return result;
  }

  /**
   * \brief standard arithmetic operator
   *
   * \param[in] other Other LandmarkId
   *
   * \returns Result of arithmetic operation.
   *
   * \note throws a std::out_of_range exception if one of the two operands or the result of
   *   the operation is not valid
   */
  LandmarkId &operator+=(const LandmarkId &other)
  {
    ensureValid();
    other.ensureValid();
    mLandmarkId += other.mLandmarkId;
    restrictToLimitsAndEnsureValid();
    return *this;
  }

  /**
   * \brief standard arithmetic operator
   *
   * \param[in] other Other LandmarkId
   *
   * \returns Result of arithmetic operation.
   *
   * \note throws a std::out_of_range exception if one of the two operands or the result of
   *   the operation is not valid
   */
  LandmarkId operator-(const LandmarkId &other) const
  {
    ensureValid();
    other.ensureValid();
    LandmarkId result(mLandmarkId - other.mLandmarkId);
    result.restrictToLimitsAndEnsureValid();
    return result;
  }

  /**
   * \brief standard arithmetic operator
   *
   * \param[in] other Other LandmarkId
   *
   * \returns Result of arithmetic operation.
   *
   * \note throws a std::out_of_range exception if one of the two operands or the result of
   *   the operation is not valid
   */
  LandmarkId operator-=(const LandmarkId &other)
  {
    ensureValid();
    other.ensureValid();
    mLandmarkId -= other.mLandmarkId;
    restrictToLimitsAndEnsureValid();
    return *this;
  }

  /*!
   * \brief conversion to base type: uint64_t
   *
   * \note the conversion to the base type removes the physical unit.
   */
  uint64_t toBaseType() const
  {
    return mLandmarkId;
  }

  /*!
   * \returns \c true if the LandmarkId is a normal value
   *
   * An LandmarkId value is defined to be normal if:
   * - It is normal or zero (see std::fpclassify())
   */
  bool isNormal() const
  {
    auto const valueClass = std::fpclassify(mLandmarkId);
    return ((valueClass == FP_NORMAL) || (valueClass == FP_ZERO));
  }

#if _AD_MAP_LANDMARK_LANDMARKID_OPERATOR_BASE_TYPE_
  /*!
   * \brief conversion to base type: uint64_t
   *
   * \note the conversion to the base type removes the physical unit.
   */
  operator uint64_t() const
  {
    return mLandmarkId;
  }
#endif

  /*!
   * \returns \c true if the LandmarkId in a valid range
   *
   * An LandmarkId value is defined to be valid if:
   * - It is normal or zero (see std::fpclassify())
   * - \ref cMinValue <= value <= \ref cMaxValue
   */
  bool isValid() const
  {
    return isNormal() && (cMinValue <= mLandmarkId) && (mLandmarkId <= cMaxValue);
  }

  /*!
   * \brief ensure that the LandmarkId is valid
   *
   * Throws an std::out_of_range() exception if the LandmarkId
   * in not valid (i.e. isValid() returns false)
   */
  void ensureValid() const
  {
    if (!isValid())
    {
      spdlog::info("ensureValid(::ad::map::landmark::LandmarkId)>> {} value out of range",
                   *this); // LCOV_EXCL_BR_LINE
#if (AD_MAP_LANDMARK_LANDMARKID_THROWS_EXCEPTION == 1)
      throw std::out_of_range("LandmarkId value out of range"); // LCOV_EXCL_BR_LINE
#endif
    }
  }

  /*!
   * \brief ensure that the LandmarkId is valid and non zero
   *
   * Throws an std::out_of_range() exception if the LandmarkId
   * in not valid or zero (i.e. isValid() returns false)
   */
  void ensureValidNonZero() const
  {
    ensureValid();
    if (operator==(LandmarkId(0))) // LCOV_EXCL_BR_LINE
    {
      spdlog::info("ensureValid(::ad::map::landmark::LandmarkId)>> {} value is zero",
                   *this); // LCOV_EXCL_BR_LINE
#if (AD_MAP_LANDMARK_LANDMARKID_THROWS_EXCEPTION == 1)
      throw std::out_of_range("LandmarkId value is zero"); // LCOV_EXCL_BR_LINE
#endif
    }
  }

  /**
   * @brief if possible restrict the LandmarkId to it's defined limits
   *
   * If the LandmarkId isNormal(), but exceeds the defined limits, it is restricted to its limits.
   * If LandmarkId::isNormal() returns \c false an std::out_of_range() exception is thrown.
   * - not isNormal(): std::out_of_range() exception is thrown
   * - \ref cMinValue <= value <= \ref cMaxValue: nothing is done
   * - value < \ref cMinValue: resulting value = cMinValue
   * - value > \ref cMaxValue: resulting value = cMaxValue
   */
  void restrictToLimitsAndEnsureValid()
  {
    if (isNormal())
    {
      if (mLandmarkId < cMinValue)
      {
        // mitigate exceeding the minimum
        spdlog::info("restrictToLimits(::ad::map::landmark::LandmarkId)>> {} value is smaller than allowed minimum {}. "
                     "Restrict to minimum value.",
                     *this,
                     getMin()); // LCOV_EXCL_BR_LINE
        mLandmarkId = cMinValue;
      }
      else if (mLandmarkId > cMaxValue)
      {
        // mitigate exceeding the maximum
        spdlog::info("restrictToLimits(::ad::map::landmark::LandmarkId)>> {} value is larger than allowed maximum {}. "
                     "Restrict to maximum value.",
                     *this,
                     getMax()); // LCOV_EXCL_BR_LINE
        mLandmarkId = cMaxValue;
      }
    }
    else
    {
      spdlog::info("restrictToLimits(::ad::map::landmark::LandmarkId)>> {} value out of range",
                   *this); // LCOV_EXCL_BR_LINE
#if (AD_MAP_LANDMARK_LANDMARKID_THROWS_EXCEPTION == 1)
      throw std::out_of_range("LandmarkId value out of range"); // LCOV_EXCL_BR_LINE
#endif
    }
  }

  /*!
   * \brief get minimum valid LandmarkId (i.e. \ref cMinValue)
   */
  static LandmarkId getMin()
  {
    return LandmarkId(cMinValue);
  }

  /*!
   * \brief get maximum valid LandmarkId (i.e. \ref cMaxValue)
   */
  static LandmarkId getMax()
  {
    return LandmarkId(cMaxValue);
  }

  /*!
   * \brief the actual value of the type
   */
  uint64_t mLandmarkId;
};

} // namespace landmark
} // namespace map
} // namespace ad
/*!
 * \brief namespace std
 */
namespace std {

/*!
 * \brief specialization of the std::numeric_limits for LandmarkId
 *
 * Derived from std::numeric_limits<uint64_t> with overloaded functions:
 * std::numeric_limits<LandmarkId>::lowest()  (\see LandmarkId::getMin())
 * std::numeric_limits<LandmarkId>::max()  (\see LandmarkId::getMax())
 * std::numeric_limits<LandmarkId>::epsilon()  (\see LandmarkId::getPrecision())
 */
template <> class numeric_limits<::ad::map::landmark::LandmarkId> : public numeric_limits<uint64_t>
{
public:
  /*!
   * \see std::numeric_limits::lowest()
   */
  static inline ::ad::map::landmark::LandmarkId lowest()
  {
    return ::ad::map::landmark::LandmarkId::getMin();
  }
  /*!
   * \see std::numeric_limits::max()
   */
  static inline ::ad::map::landmark::LandmarkId max()
  {
    return ::ad::map::landmark::LandmarkId::getMax();
  }

  /*!
   * \see std::numeric_limits::epsilon()
   */
  static inline ::ad::map::landmark::LandmarkId epsilon()
  {
    return ::ad::map::landmark::LandmarkId(0);
  }
};

} // namespace std

/*!
 * \brief protect the definition of functions from duplicates by typedef usage within other data types
 */
#ifndef GEN_GUARD_AD_MAP_LANDMARK_LANDMARKID
#define GEN_GUARD_AD_MAP_LANDMARK_LANDMARKID
/*!
 * @brief namespace ad
 */
namespace ad {
/*!
 * @brief namespace map
 */
namespace map {
/*!
 * @brief namespace landmark
 *
 * Handling of landmarks
 */
namespace landmark {

/**
 * \brief standard ostream operator
 *
 * \param[in] os The output stream to write to
 * \param[in] _value LandmarkId value
 *
 * \returns The stream object.
 *
 */
inline std::ostream &operator<<(std::ostream &os, LandmarkId const &_value)
{
  return os << _value.mLandmarkId;
}

} // namespace landmark
} // namespace map
} // namespace ad

namespace std {
/*!
 * \brief overload of the std::to_string for LandmarkId
 */
inline std::string to_string(::ad::map::landmark::LandmarkId const &value)
{
  return to_string(value.mLandmarkId);
}
} // namespace std

/*!
 * \brief overload of fmt::formatter calling std::to_string
 */
template <> struct fmt::formatter<::ad::map::landmark::LandmarkId> : formatter<string_view>
{
  template <typename FormatContext> auto format(::ad::map::landmark::LandmarkId const &value, FormatContext &ctx)
  {
    return formatter<string_view>::format(std::to_string(value), ctx);
  }
};

#endif // GEN_GUARD_AD_MAP_LANDMARK_LANDMARKID
