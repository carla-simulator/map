// ----------------- BEGIN LICENSE BLOCK ---------------------------------
//
// Copyright (C) 2018-2021 Intel Corporation
//
// SPDX-License-Identifier: MIT
//
// ----------------- END LICENSE BLOCK -----------------------------------

/**
 * @file
 */

#pragma once

#include "ad/physics/Types.hpp"

/*!
 * @brief Arithmetic physics operation v = a * t
 *
 * @param[in] a acceleration value
 * @param[in] t duration value
 *
 * @returns v = a * t as speed value
 *
 * \note throws a std::out_of_range exception if one of the two operands is not valid.
 * \note The result is restricted to the limits of ad::physics::Speed.
 */
inline ad::physics::Speed operator*(ad::physics::Acceleration const &a, ad::physics::Duration const &t)
{
  a.ensureValid();
  t.ensureValid();
  ad::physics::Speed v(a.mAcceleration * t.mDuration);
  v.restrictToLimitsAndEnsureValid();
  return v;
}

/*!
 * @brief Arithmetic physics operation s = a * t^2
 *
 * @param[in] a acceleration value
 * @param[in] t2 duration squared value
 *
 * @returns s = a * t2 as distance value
 *
 * \note throws a std::out_of_range exception if one of the two operands is not valid.
 * \note The result is restricted to the limits of ad::physics::Distance.
 */
inline ad::physics::Distance operator*(ad::physics::Acceleration const &a, ad::physics::DurationSquared const &t2)
{
  a.ensureValid();
  t2.ensureValid();
  ad::physics::Distance s(a.mAcceleration * t2.mDurationSquared);
  s.restrictToLimitsAndEnsureValid();
  return s;
}

/*!
 * @brief Arithmetic physics operation v^2 = a * s
 *
 * @param[in] a acceleration value
 * @param[in] s distance value
 *
 * @returns v2 = a * s as speed squared value
 *
 * \note throws a std::out_of_range exception if one of the two operands is not valid.
 * \note The result is restricted to the limits of ad::physics::SpeedSquared.
 */
inline ad::physics::SpeedSquared operator*(ad::physics::Acceleration const &a, ad::physics::Distance const &s)
{
  a.ensureValid();
  s.ensureValid();
  ad::physics::SpeedSquared v2(a.mAcceleration * s.mDistance);
  v2.restrictToLimitsAndEnsureValid();
  return v2;
}

/*!
 * @brief Arithmetic physics operation v = t * a
 *
 * @param[in] t duration value
 * @param[in] a acceleration value
 *
 * @returns v = a * t as speed value
 *
 * \note throws a std::out_of_range exception if one of the two operands is not valid.
 * \note The result is restricted to the limits of ad::physics::Speed.
 */
inline ad::physics::Speed operator*(ad::physics::Duration const &t, ad::physics::Acceleration const &a)
{
  t.ensureValid();
  a.ensureValid();
  ad::physics::Speed v(a.mAcceleration * t.mDuration);
  v.restrictToLimitsAndEnsureValid();
  return v;
}

/*!
 * @brief Arithmetic physics operation s = v * t
 *
 * @param[in] v speed value
 * @param[in] t duration value
 *
 * @returns s = v * t as distance value
 *
 * \note throws a std::out_of_range exception if one of the two operands is not valid.
 * \note The result is restricted to the limits of ad::physics::Distance.
 */
inline ad::physics::Distance operator*(ad::physics::Speed const &v, ad::physics::Duration const &t)
{
  v.ensureValid();
  t.ensureValid();
  ad::physics::Distance s(v.mSpeed * t.mDuration);
  s.restrictToLimitsAndEnsureValid();
  return s;
}

/*!
 * @brief Arithmetic physics operation s = t * v
 *
 * @param[in] t duration value
 * @param[in] v speed value
 *
 * @returns s = v * t as distance value
 *
 * \note throws a std::out_of_range exception if one of the two operands is not valid.
 * \note The result is restricted to the limits of ad::physics::Distance.
 */
inline ad::physics::Distance operator*(ad::physics::Duration const &t, ad::physics::Speed const &v)
{
  t.ensureValid();
  v.ensureValid();
  ad::physics::Distance s(v.mSpeed * t.mDuration);
  s.restrictToLimitsAndEnsureValid();
  return s;
}

/*!
 * @brief Arithmetic physics operation t = s / v
 *
 * @param[in] s distance value
 * @param[in] v speed value
 *
 * @returns t = s / v as duration value
 *
 * \note throws a std::out_of_range exception if one of the two operands is not valid or if the divisor is zero
 * \note The result is restricted to the limits of ad::physics::Duration.
 */
inline ad::physics::Duration operator/(ad::physics::Distance const &s, ad::physics::Speed const &v)
{
  s.ensureValid();
  v.ensureValidNonZero();
  ad::physics::Duration t(s.mDistance / v.mSpeed);
  t.restrictToLimitsAndEnsureValid();
  return t;
}

/*!
 * @brief Arithmetic physics operation t = v / a
 *
 * @param[in] v speed value
 * @param[in] a acceleration value
 *
 * @returns t = v / a as duration value
 *
 * \note throws a std::out_of_range exception if one of the two operands is not valid or if the divisor is zero
 * \note The result is restricted to the limits of ad::physics::Duration.
 */
inline ad::physics::Duration operator/(ad::physics::Speed const &v, ad::physics::Acceleration const &a)
{
  v.ensureValid();
  a.ensureValidNonZero();
  ad::physics::Duration t(v.mSpeed / a.mAcceleration);
  t.restrictToLimitsAndEnsureValid();
  return t;
}

/*!
 * @brief Arithmetic physics operation a = v / t
 *
 * @param[in] v speed value
 * @param[in] t duration value
 *
 * @returns a = v / t as acceleration value
 *
 * \note throws a std::out_of_range exception if one of the two operands is not valid or if the divisor is zero
 * \note The result is restricted to the limits of ad::physics::Acceleration.
 */
inline ad::physics::Acceleration operator/(ad::physics::Speed const &v, ad::physics::Duration const &t)
{
  v.ensureValid();
  t.ensureValidNonZero();
  ad::physics::Acceleration a(v.mSpeed / t.mDuration);
  a.restrictToLimitsAndEnsureValid();
  return a;
}

/*!
 * @brief Arithmetic physics operation s = v^2 / a
 *
 * @param[in] v2 squared speed value
 * @param[in] a acceleration value
 *
 * @returns s = v^2 / a as distance value
 *
 * \note throws a std::out_of_range exception if one of the two operands is not valid or if the divisor is zero
 * \note The result is restricted to the limits of ad::physics::Distance.
 */
inline ad::physics::Distance operator/(ad::physics::SpeedSquared const &v2, ad::physics::Acceleration const &a)
{
  v2.ensureValid();
  a.ensureValidNonZero();
  ad::physics::Distance d(v2.mSpeedSquared / a.mAcceleration);
  d.restrictToLimitsAndEnsureValid();
  return d;
}

/*!
 * @brief Arithmetic physics operation a = v^2 / s
 *
 * @param[in] v2 squared speed value
 * @param[in] s distance value
 *
 * @returns a = v^2 / s as acceleration value
 *
 * \note throws a std::out_of_range exception if one of the two operands is not valid or if the divisor is zero
 * \note The result is restricted to the limits of ad::physics::Acceleration.
 */
inline ad::physics::Acceleration operator/(ad::physics::SpeedSquared const &v2, ad::physics::Distance const &d)
{
  v2.ensureValid();
  d.ensureValidNonZero();
  ad::physics::Acceleration a(v2.mSpeedSquared / d.mDistance);
  a.restrictToLimitsAndEnsureValid();
  return a;
}

/*!
 * @brief Arithmetic physics operation t^2 = s / a
 *
 * @param[in] s distance value
 * @param[in] a acceleration value
 *
 * @returns t^2 = s / a as squared duration value
 *
 * \note throws a std::out_of_range exception if one of the two operands is not valid or if the divisor is zero
 * \note The result is restricted to the limits of ad::physics::DurationSquared.
 */
inline ad::physics::DurationSquared operator/(ad::physics::Distance const &s, ad::physics::Acceleration const &a)
{
  s.ensureValid();
  a.ensureValidNonZero();
  ad::physics::DurationSquared t2(s.mDistance / a.mAcceleration);
  t2.restrictToLimitsAndEnsureValid();
  return t2;
}
