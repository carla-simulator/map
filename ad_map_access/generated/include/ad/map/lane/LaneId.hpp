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
 * @brief namespace lane
 *
 * Handling of lanes
 */
namespace lane {

/*!
 * \brief Define to indicate whether throwing exceptions is enabled
 */
#define AD_MAP_LANE_LANEID_THROWS_EXCEPTION 1

#if SAFE_DATATYPES_EXPLICIT_CONVERSION
/*!
 * \brief Enable/Disable explicit conversion. Currently set to "only explicit conversion".
 */
#define _AD_MAP_LANE_LANEID_EXPLICIT_CONVERSION_ explicit
#define _AD_MAP_LANE_LANEID_OPERATOR_BASE_TYPE_ 0
#else
/*!
 * \brief Enable/Disable explicit conversion. Currently set to "implicit conversion allowed".
 */
#define _AD_MAP_LANE_LANEID_EXPLICIT_CONVERSION_
#define _AD_MAP_LANE_LANEID_OPERATOR_BASE_TYPE_ 1
#endif

/*!
 * \brief DataType LaneId
 *
 * Defines the identifier of a lane of the map.
 * The unit is: Identifier
 */
class LaneId
{
public:
  /*!
   * \brief constant defining the minimum valid LaneId value (used in isValid())
   */
  static const uint64_t cMinValue;

  /*!
   * \brief constant defining the maximum valid LaneId value (used in isValid())
   */
  static const uint64_t cMaxValue;

  /*!
   * \brief default constructor
   *
   * The default value of LaneId is:
   * std::numeric_limits<uint64_t>::quiet_NaN()
   */
  LaneId()
    : mLaneId(std::numeric_limits<uint64_t>::quiet_NaN())
  {
  }

  /*!
   * \brief standard constructor
   *
   * \note \ref \_AD_MAP_LANE_LANEID_EXPLICIT_CONVERSION\_ defines, if only an explicit conversion is allowed.
   */
  _AD_MAP_LANE_LANEID_EXPLICIT_CONVERSION_ LaneId(uint64_t const iLaneId)
    : mLaneId(iLaneId)
  {
  }

  /*!
   * \brief standard copy constructor
   */
  LaneId(const LaneId &other) = default;

  /*!
   * \brief standard move constructor
   */
  LaneId(LaneId &&other) = default;

  /**
   * \brief standard assignment operator
   *
   * \param[in] other Other LaneId
   *
   * \returns Reference to this LaneId.
   */
  LaneId &operator=(const LaneId &other) = default;

  /**
   * \brief standard move operator
   *
   * \param[in] other Other LaneId
   *
   * \returns Reference to this LaneId.
   */
  LaneId &operator=(LaneId &&other) = default;

  /**
   * \brief standard comparison operator
   *
   * \param[in] other Other LaneId
   *
   * \returns \c true if both LaneId are valid and can be taken as numerically equal
   */
  bool operator==(const LaneId &other) const
  {
    ensureValid();
    other.ensureValid();
    return mLaneId == other.mLaneId;
  }

  /**
   * \brief standard comparison operator
   *
   * \param[in] other Other LaneId.
   *
   * \returns \c true if one of the LaneId is not valid or they can be taken as numerically different
   */
  bool operator!=(const LaneId &other) const
  {
    return !operator==(other);
  }

  /**
   * \brief standard comparison operator
   *
   * \param[in] other Other LaneId.
   *
   * \returns \c true if both LaneId are valid and
   *   this LaneId is strictly numerically greater than other.
   * \note the precision of LaneId is considered
   */
  bool operator>(const LaneId &other) const
  {
    ensureValid();
    other.ensureValid();
    return (mLaneId > other.mLaneId) && operator!=(other);
  }

  /**
   * \brief standard comparison operator
   *
   * \param[in] other Other LaneId.
   *
   * \returns \c true if both LaneId are valid and
   *   this LaneId is strictly numerically smaller than other.
   * \note the precision of LaneId is considered
   */
  bool operator<(const LaneId &other) const
  {
    ensureValid();
    other.ensureValid();
    return (mLaneId < other.mLaneId) && operator!=(other);
  }

  /**
   * \brief standard comparison operator
   *
   * \param[in] other Other LaneId.
   *
   * \returns \c true if both LaneId are valid and
   *   this LaneId is numerically greater than other.
   * \note the precision of LaneId is considered
   */
  bool operator>=(const LaneId &other) const
  {
    ensureValid();
    other.ensureValid();
    return ((mLaneId > other.mLaneId) || operator==(other));
  }

  /**
   * \brief standard comparison operator
   *
   * \param[in] other Other LaneId
   *
   * \returns \c true if both LaneId are valid and
   *   this LaneId is numerically smaller than other.
   * \note the precision of LaneId is considered
   */
  bool operator<=(const LaneId &other) const
  {
    ensureValid();
    other.ensureValid();
    return ((mLaneId < other.mLaneId) || operator==(other));
  }

  /**
   * \brief standard arithmetic operator
   *
   * \param[in] other Other LaneId
   *
   * \returns Result of arithmetic operation.
   *
   * \note throws a std::out_of_range exception if one of the two operands or the result of
   *   the operation is not valid
   */
  LaneId operator+(const LaneId &other) const
  {
    ensureValid();
    other.ensureValid();
    LaneId result(mLaneId + other.mLaneId);
    result.restrictToLimitsAndEnsureValid();
    return result;
  }

  /**
   * \brief standard arithmetic operator
   *
   * \param[in] other Other LaneId
   *
   * \returns Result of arithmetic operation.
   *
   * \note throws a std::out_of_range exception if one of the two operands or the result of
   *   the operation is not valid
   */
  LaneId &operator+=(const LaneId &other)
  {
    ensureValid();
    other.ensureValid();
    mLaneId += other.mLaneId;
    restrictToLimitsAndEnsureValid();
    return *this;
  }

  /**
   * \brief standard arithmetic operator
   *
   * \param[in] other Other LaneId
   *
   * \returns Result of arithmetic operation.
   *
   * \note throws a std::out_of_range exception if one of the two operands or the result of
   *   the operation is not valid
   */
  LaneId operator-(const LaneId &other) const
  {
    ensureValid();
    other.ensureValid();
    LaneId result(mLaneId - other.mLaneId);
    result.restrictToLimitsAndEnsureValid();
    return result;
  }

  /**
   * \brief standard arithmetic operator
   *
   * \param[in] other Other LaneId
   *
   * \returns Result of arithmetic operation.
   *
   * \note throws a std::out_of_range exception if one of the two operands or the result of
   *   the operation is not valid
   */
  LaneId operator-=(const LaneId &other)
  {
    ensureValid();
    other.ensureValid();
    mLaneId -= other.mLaneId;
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
    return mLaneId;
  }

  /*!
   * \returns \c true if the LaneId is a normal value
   *
   * An LaneId value is defined to be normal if:
   * - It is normal or zero (see std::fpclassify())
   */
  bool isNormal() const
  {
    auto const valueClass = std::fpclassify(mLaneId);
    return ((valueClass == FP_NORMAL) || (valueClass == FP_ZERO));
  }

#if _AD_MAP_LANE_LANEID_OPERATOR_BASE_TYPE_
  /*!
   * \brief conversion to base type: uint64_t
   *
   * \note the conversion to the base type removes the physical unit.
   */
  operator uint64_t() const
  {
    return mLaneId;
  }
#endif

  /*!
   * \returns \c true if the LaneId in a valid range
   *
   * An LaneId value is defined to be valid if:
   * - It is normal or zero (see std::fpclassify())
   * - \ref cMinValue <= value <= \ref cMaxValue
   */
  bool isValid() const
  {
    return isNormal() && (cMinValue <= mLaneId) && (mLaneId <= cMaxValue);
  }

  /*!
   * \brief ensure that the LaneId is valid
   *
   * Throws an std::out_of_range() exception if the LaneId
   * in not valid (i.e. isValid() returns false)
   */
  void ensureValid() const
  {
    if (!isValid())
    {
      spdlog::info("ensureValid(::ad::map::lane::LaneId)>> {} value out of range",
                   *this); // LCOV_EXCL_BR_LINE
#if (AD_MAP_LANE_LANEID_THROWS_EXCEPTION == 1)
      throw std::out_of_range("LaneId value out of range"); // LCOV_EXCL_BR_LINE
#endif
    }
  }

  /*!
   * \brief ensure that the LaneId is valid and non zero
   *
   * Throws an std::out_of_range() exception if the LaneId
   * in not valid or zero (i.e. isValid() returns false)
   */
  void ensureValidNonZero() const
  {
    ensureValid();
    if (operator==(LaneId(0))) // LCOV_EXCL_BR_LINE
    {
      spdlog::info("ensureValid(::ad::map::lane::LaneId)>> {} value is zero",
                   *this); // LCOV_EXCL_BR_LINE
#if (AD_MAP_LANE_LANEID_THROWS_EXCEPTION == 1)
      throw std::out_of_range("LaneId value is zero"); // LCOV_EXCL_BR_LINE
#endif
    }
  }

  /**
   * @brief if possible restrict the LaneId to it's defined limits
   *
   * If the LaneId isNormal(), but exceeds the defined limits, it is restricted to its limits.
   * If LaneId::isNormal() returns \c false an std::out_of_range() exception is thrown.
   * - not isNormal(): std::out_of_range() exception is thrown
   * - \ref cMinValue <= value <= \ref cMaxValue: nothing is done
   * - value < \ref cMinValue: resulting value = cMinValue
   * - value > \ref cMaxValue: resulting value = cMaxValue
   */
  void restrictToLimitsAndEnsureValid()
  {
    if (isNormal())
    {
      if (mLaneId < cMinValue)
      {
        // mitigate exceeding the minimum
        spdlog::info("restrictToLimits(::ad::map::lane::LaneId)>> {} value is smaller than allowed minimum {}. "
                     "Restrict to minimum value.",
                     *this,
                     getMin()); // LCOV_EXCL_BR_LINE
        mLaneId = cMinValue;
      }
      else if (mLaneId > cMaxValue)
      {
        // mitigate exceeding the maximum
        spdlog::info("restrictToLimits(::ad::map::lane::LaneId)>> {} value is larger than allowed maximum {}. Restrict "
                     "to maximum value.",
                     *this,
                     getMax()); // LCOV_EXCL_BR_LINE
        mLaneId = cMaxValue;
      }
    }
    else
    {
      spdlog::info("restrictToLimits(::ad::map::lane::LaneId)>> {} value out of range", *this); // LCOV_EXCL_BR_LINE
#if (AD_MAP_LANE_LANEID_THROWS_EXCEPTION == 1)
      throw std::out_of_range("LaneId value out of range"); // LCOV_EXCL_BR_LINE
#endif
    }
  }

  /*!
   * \brief get minimum valid LaneId (i.e. \ref cMinValue)
   */
  static LaneId getMin()
  {
    return LaneId(cMinValue);
  }

  /*!
   * \brief get maximum valid LaneId (i.e. \ref cMaxValue)
   */
  static LaneId getMax()
  {
    return LaneId(cMaxValue);
  }

  /*!
   * \brief the actual value of the type
   */
  uint64_t mLaneId;
};

} // namespace lane
} // namespace map
} // namespace ad
/*!
 * \brief namespace std
 */
namespace std {

/*!
 * \brief specialization of the std::numeric_limits for LaneId
 *
 * Derived from std::numeric_limits<uint64_t> with overloaded functions:
 * std::numeric_limits<LaneId>::lowest()  (\see LaneId::getMin())
 * std::numeric_limits<LaneId>::max()  (\see LaneId::getMax())
 * std::numeric_limits<LaneId>::epsilon()  (\see LaneId::getPrecision())
 */
template <> class numeric_limits<::ad::map::lane::LaneId> : public numeric_limits<uint64_t>
{
public:
  /*!
   * \see std::numeric_limits::lowest()
   */
  static inline ::ad::map::lane::LaneId lowest()
  {
    return ::ad::map::lane::LaneId::getMin();
  }
  /*!
   * \see std::numeric_limits::max()
   */
  static inline ::ad::map::lane::LaneId max()
  {
    return ::ad::map::lane::LaneId::getMax();
  }

  /*!
   * \see std::numeric_limits::epsilon()
   */
  static inline ::ad::map::lane::LaneId epsilon()
  {
    return ::ad::map::lane::LaneId(0);
  }
};

} // namespace std

/*!
 * \brief protect the definition of functions from duplicates by typedef usage within other data types
 */
#ifndef GEN_GUARD_AD_MAP_LANE_LANEID
#define GEN_GUARD_AD_MAP_LANE_LANEID
/*!
 * @brief namespace ad
 */
namespace ad {
/*!
 * @brief namespace map
 */
namespace map {
/*!
 * @brief namespace lane
 *
 * Handling of lanes
 */
namespace lane {

/**
 * \brief standard ostream operator
 *
 * \param[in] os The output stream to write to
 * \param[in] _value LaneId value
 *
 * \returns The stream object.
 *
 */
inline std::ostream &operator<<(std::ostream &os, LaneId const &_value)
{
  return os << _value.mLaneId;
}

} // namespace lane
} // namespace map
} // namespace ad

namespace std {
/*!
 * \brief overload of the std::to_string for LaneId
 */
inline std::string to_string(::ad::map::lane::LaneId const &value)
{
  return to_string(value.mLaneId);
}
} // namespace std

/*!
 * \brief overload of fmt::formatter calling std::to_string
 */
template <> struct fmt::formatter<::ad::map::lane::LaneId> : formatter<string_view>
{
  template <typename FormatContext> auto format(::ad::map::lane::LaneId const &value, FormatContext &ctx)
  {
    return formatter<string_view>::format(std::to_string(value), ctx);
  }
};

#endif // GEN_GUARD_AD_MAP_LANE_LANEID
