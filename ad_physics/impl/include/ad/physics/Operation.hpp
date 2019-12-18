// ----------------- BEGIN LICENSE BLOCK ---------------------------------
//
// Copyright (C) 2018-2019 Intel Corporation
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
 * \note throws a std::out_of_range exception if one of the two operands or the result of
 *   the operation is not valid
 */
inline ad::physics::Speed operator*(ad::physics::Acceleration const &a, ad::physics::Duration const &t)
{
  a.ensureValid();
  t.ensureValid();
  ad::physics::Speed const v(static_cast<double>(a) * static_cast<double>(t));
  v.ensureValid();
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
 * \note throws a std::out_of_range exception if one of the two operands or the result of
 *   the operation is not valid
 */
inline ad::physics::Distance operator*(ad::physics::Acceleration const &a, ad::physics::DurationSquared const &t2)
{
  a.ensureValid();
  t2.ensureValid();
  ad::physics::Distance const s(static_cast<double>(a) * static_cast<double>(t2));
  s.ensureValid();
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
 * \note throws a std::out_of_range exception if one of the two operands or the result of
 *   the operation is not valid
 */
inline ad::physics::SpeedSquared operator*(ad::physics::Acceleration const &a, ad::physics::Distance const &s)
{
  a.ensureValid();
  s.ensureValid();
  ad::physics::SpeedSquared const v2(static_cast<double>(a) * static_cast<double>(s));
  v2.ensureValid();
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
 * \note throws a std::out_of_range exception if one of the two operands or the result of
 *   the operation is not valid
 */
inline ad::physics::Speed operator*(ad::physics::Duration const &t, ad::physics::Acceleration const &a)
{
  return operator*(a, t);
}

/*!
 * @brief Arithmetic physics operation s = v * t
 *
 * @param[in] v speed value
 * @param[in] t duration value
 *
 * @returns s = v * t as distance value
 *
 * \note throws a std::out_of_range exception if one of the two operands or the result of
 *   the operation is not valid
 */
inline ad::physics::Distance operator*(ad::physics::Speed const &v, ad::physics::Duration const &t)
{
  v.ensureValid();
  t.ensureValid();
  ad::physics::Distance const s(static_cast<double>(v) * static_cast<double>(t));
  s.ensureValid();
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
 * \note throws a std::out_of_range exception if one of the two operands or the result of
 *   the operation is not valid
 */
inline ad::physics::Distance operator*(ad::physics::Duration const &t, ad::physics::Speed const &v)
{
  return operator*(v, t);
}

/*!
 * @brief Arithmetic physics operation s = s * p
 *
 * @param[in] s distance value
 * @param[in] p parametric value
 *
 * @returns s = s * p as distance value
 *
 * \note throws a std::out_of_range exception if one of the two operands or the result of
 *   the operation is not valid
 */
inline ad::physics::Distance operator*(ad::physics::Distance const &s, ad::physics::ParametricValue const &p)
{
  p.ensureValid();
  s.ensureValid();
  ad::physics::Distance const resultingS(static_cast<double>(p) * static_cast<double>(s));
  resultingS.ensureValid();
  return resultingS;
}

/*!
 * @brief Arithmetic physics operation s = p * s
 *
 * @param[in] p parametric value
 * @param[in] s distance value
 *
 * @returns s = p * s as distance value
 *
 * \note throws a std::out_of_range exception if one of the two operands or the result of
 *   the operation is not valid
 */
inline ad::physics::Distance operator*(ad::physics::ParametricValue const &p, ad::physics::Distance const &s)
{
  return operator*(s, p);
}

/*!
 * @brief Arithmetic physics operation s = s * r
 *
 * @param[in] s distance value
 * @param[in] r ratio value
 *
 * @returns s = s * r as distance value
 *
 * \note throws a std::out_of_range exception if one of the two operands or the result of
 *   the operation is not valid
 */
inline ad::physics::Distance operator*(ad::physics::Distance const &s, ad::physics::RatioValue const &r)
{
  r.ensureValid();
  s.ensureValid();
  ad::physics::Distance const resultingS(static_cast<double>(r) * static_cast<double>(s));
  resultingS.ensureValid();
  return resultingS;
}

/*!
 * @brief Arithmetic physics operation s = r * s
 *
 * @param[in] r ratio value
 * @param[in] s distance value
 *
 * @returns s = r * s as distance value
 *
 * \note throws a std::out_of_range exception if one of the two operands or the result of
 *   the operation is not valid
 */
inline ad::physics::Distance operator*(ad::physics::RatioValue const &r, ad::physics::Distance const &s)
{
  return operator*(s, r);
}

/*!
 * @brief Arithmetic operation *
 *
 * @param[in] p1 parametric value
 * @param[in] p2 parametric value
 *
 * @returns p = p1 * p2 as parametric value
 *
 * \note throws a std::out_of_range exception if one of the two operands or the result of
 *   the operation is not valid
 */
inline ad::physics::ParametricValue operator*(ad::physics::ParametricValue const &p1,
                                              ad::physics::ParametricValue const &p2)
{
  p1.ensureValid();
  p2.ensureValid();
  ad::physics::ParametricValue const result(static_cast<double>(p1) * static_cast<double>(p2));
  result.ensureValid();
  return result;
}

/*!
 * @brief Arithmetic operation *
 *
 * @param[in] r1 ratio value
 * @param[in] r2 ratio value
 *
 * @returns r = r1 * r2 as parametric value
 *
 * \note throws a std::out_of_range exception if one of the two operands or the result of
 *   the operation is not valid
 */
inline ad::physics::RatioValue operator*(ad::physics::RatioValue const &r1, ad::physics::RatioValue const &r2)
{
  r1.ensureValid();
  r2.ensureValid();
  ad::physics::RatioValue const result(static_cast<double>(r1) * static_cast<double>(r2));
  result.ensureValid();
  return result;
}

/*!
 * @brief Arithmetic physics operation t = s / v
 *
 * @param[in] s distance value
 * @param[in] v speed value
 *
 * @returns t = s / v as duration value
 *
 * \note throws a std::out_of_range exception if one of the two operands or the result of
 *   the operation is not valid or if the divisor is zero
 */
inline ad::physics::Duration operator/(ad::physics::Distance const &s, ad::physics::Speed const &v)
{
  s.ensureValid();
  v.ensureValidNonZero();
  ad::physics::Duration const t(static_cast<double>(s) / static_cast<double>(v));
  t.ensureValid();
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
 * \note throws a std::out_of_range exception if one of the two operands or the result of
 *   the operation is not valid or if the divisor is zero
 */
inline ad::physics::Duration operator/(ad::physics::Speed const &v, ad::physics::Acceleration const &a)
{
  v.ensureValid();
  a.ensureValidNonZero();
  ad::physics::Duration const t(static_cast<double>(v) / static_cast<double>(a));
  t.ensureValid();
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
 * \note throws a std::out_of_range exception if one of the two operands or the result of
 *   the operation is not valid or if the divisor is zero
 */
inline ad::physics::Acceleration operator/(ad::physics::Speed const &v, ad::physics::Duration const &t)
{
  v.ensureValid();
  t.ensureValidNonZero();
  ad::physics::Acceleration const a(static_cast<double>(v) / static_cast<double>(t));
  a.ensureValid();
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
 * \note throws a std::out_of_range exception if one of the two operands or the result of
 *   the operation is not valid or if the divisor is zero
 */
inline ad::physics::Distance operator/(ad::physics::SpeedSquared const &v2, ad::physics::Acceleration const &a)
{
  v2.ensureValid();
  a.ensureValidNonZero();
  ad::physics::Distance const t(static_cast<double>(v2) / static_cast<double>(a));
  t.ensureValid();
  return t;
}

/*!
 * @brief Arithmetic physics operation t^2 = s / a
 *
 * @param[in] s distance value
 * @param[in] a acceleration value
 *
 * @returns t^2 = s / a as squared duration value
 *
 * \note throws a std::out_of_range exception if one of the two operands or the result of
 *   the operation is not valid or if the divisor is zero
 */
inline ad::physics::DurationSquared operator/(ad::physics::Distance const &s, ad::physics::Acceleration const &a)
{
  s.ensureValid();
  a.ensureValidNonZero();
  ad::physics::DurationSquared const t2(static_cast<double>(s) / static_cast<double>(a));
  t2.ensureValid();
  return t2;
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
 * @brief ensure the physics operators defined at global scope are also found within ad::physics namespace
 */
using ::operator*;

/*!
 * @brief ensure the physics operators defined at global scope are also found within ad::physics namespace
 */
using ::operator/;

} // namespace physics

} // namespace ad
