// ----------------- BEGIN LICENSE BLOCK ---------------------------------
//
// Copyright (C) 2020-2021 Intel Corporation
//
// SPDX-License-Identifier: MIT
//
// ----------------- END LICENSE BLOCK -----------------------------------

/**
 * @file
 */

#pragma once

#include <cmath>
#include "ad/physics/Types.hpp"

/*!
 * @brief Arithmetic physics operation s = v * t
 *
 * @param[in] v angular speed value
 * @param[in] t duration value
 *
 * @returns s = v * t as angle value
 *
 * \note throws a std::out_of_range exception if one of the two operands or the result of
 *   the operation is not valid
 */
inline ad::physics::Angle operator*(ad::physics::AngularVelocity const &v, ad::physics::Duration const &t)
{
  v.ensureValid();
  t.ensureValid();
  ad::physics::Angle s(v.mAngularVelocity * t.mDuration);
  s.restrictToLimitsAndEnsureValid();
  return s;
}

/*!
 * @brief Arithmetic physics operation s = t * v
 *
 * @param[in] t duration value
 * @param[in] v angular speed value
 *
 * @returns s = v * t as angle value
 *
 * \note throws a std::out_of_range exception if one of the two operands or the result of
 *   the operation is not valid
 */
inline ad::physics::Angle operator*(ad::physics::Duration const &t, ad::physics::AngularVelocity const &v)
{
  t.ensureValid();
  v.ensureValid();
  ad::physics::Angle s(v.mAngularVelocity * t.mDuration);
  s.restrictToLimitsAndEnsureValid();
  return s;
}

/*!
 * @brief Arithmetic physics operation v = a * t
 *
 * @param[in] a angular acceleration value
 * @param[in] t duration value
 *
 * @returns v = a * t as angular velocity value
 *
 * \note throws a std::out_of_range exception if one of the two operands or the result of
 *   the operation is not valid
 */
inline ad::physics::AngularVelocity operator*(ad::physics::AngularAcceleration const &a, ad::physics::Duration const &t)
{
  a.ensureValid();
  t.ensureValid();
  ad::physics::AngularVelocity v(a.mAngularAcceleration * t.mDuration);
  v.restrictToLimitsAndEnsureValid();
  return v;
}

/*!
 * @brief Arithmetic physics operation v = t * a
 *
 * @param[in] t duration value
 * @param[in] a angular acceleration value
 *
 * @returns v = t * a as angular velocity value
 *
 * \note throws a std::out_of_range exception if one of the two operands or the result of
 *   the operation is not valid
 */
inline ad::physics::AngularVelocity operator*(ad::physics::Duration const &t, ad::physics::AngularAcceleration const &a)
{
  t.ensureValid();
  a.ensureValid();
  ad::physics::AngularVelocity v(a.mAngularAcceleration * t.mDuration);
  v.restrictToLimitsAndEnsureValid();
  return v;
}

/*!
 * @brief namespace ad
 */
namespace ad {
/*!
 * @brief namespace for RSS physics datatypes and operations
 */
namespace physics {

/*!
 * @brief constant PI
 */
static const Angle cPI(M_PI);

/*!
 * @brief constant 2*PI
 */
static const Angle c2PI(2. * M_PI);

/*!
 * @brief constant PI/2
 */
static const Angle cPI_2(M_PI_2);

/*!
 * @returns normalized angle in the range of [0; 2*PI)
 *
 * \note throws a std::out_of_range exception if the operand is not valid
 */
inline Angle normalizeAngle(Angle const &angle)
{
  angle.ensureValid();
  double normalizedAngle = std::fmod(angle.mAngle, 2. * M_PI);
  if (normalizedAngle < 0.)
  {
    normalizedAngle += 2. * M_PI;
  }
  return Angle(normalizedAngle);
}

/*!
 * @returns normalized angle in the range of (-PI; PI]
 *
 * \note throws a std::out_of_range exception if the operand is not valid
 */
inline Angle normalizeAngleSigned(Angle const &angle)
{
  angle.ensureValid();
  double normalizedAngle = std::fmod(angle.mAngle + M_PI, 2. * M_PI);
  if (normalizedAngle <= 0.)
  {
    normalizedAngle += M_PI;
  }
  else
  {
    normalizedAngle -= M_PI;
  }
  return Angle(normalizedAngle);
}

} // namespace physics
} // namespace ad

namespace std {

/*!
 * @returns sine of the angle
 *
 * \note throws a std::out_of_range exception if the operand is not valid
 */
inline double sin(ad::physics::Angle const &angle)
{
  angle.ensureValid();
  return sin(angle.mAngle);
}

/*!
 * @returns cosine of the angle
 *
 * \note throws a std::out_of_range exception if the operand is not valid
 */
inline double cos(ad::physics::Angle const &angle)
{
  angle.ensureValid();
  return cos(angle.mAngle);
}

/*!
 * @returns Tangent of the angle
 *
 * \note throws a std::out_of_range exception if the operand is not valid
 */
inline double tan(ad::physics::Angle const &angle)
{
  angle.ensureValid();
  return tan(angle.mAngle);
}

} // namespace std
