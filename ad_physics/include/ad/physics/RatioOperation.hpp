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

#include "ad/physics/Types.hpp"

/* ##################  ad::physics::Acceleration  ################ */

/*!
 * @brief Arithmetic physics operation value = value * r
 *
 * @param[in] value physics value
 * @param[in] r ratio value
 *
 * @returns value = value * r
 *
 * \note throws a std::out_of_range exception if one of the two operands is not valid.
 * \note The result is restricted to the limits of ad::physics::Acceleration.
 */
inline ad::physics::Acceleration operator*(ad::physics::Acceleration const &value, ad::physics::RatioValue const &r)
{
  r.ensureValid();
  value.ensureValid();
  ad::physics::Acceleration result(r.mRatioValue * value.mAcceleration);
  result.restrictToLimitsAndEnsureValid();
  return result;
}

/*!
 * @brief Arithmetic ratio operation value = r * value
 *
 * @param[in] r ratio value
 * @param[in] value physics value
 *
 * @returns value = r * value
 *
 * \note throws a std::out_of_range exception if one of the two operands is not valid.
 * \note The result is restricted to the limits of ad::physics::Acceleration.
 */
inline ad::physics::Acceleration operator*(ad::physics::RatioValue const &r, ad::physics::Acceleration const &value)
{
  r.ensureValid();
  value.ensureValid();
  ad::physics::Acceleration result(r.mRatioValue * value.mAcceleration);
  result.restrictToLimitsAndEnsureValid();
  return result;
}

/*!
 * @brief Arithmetic physics operation value = value / r
 *
 * @param[in] value physics value
 * @param[in] r ratio value
 *
 * @returns value = value / r
 *
 * \note throws a std::out_of_range exception if one of the two operands is not valid or if the divisor is zero
 * \note The result is restricted to the limits of ad::physics::Acceleration.
 */
inline ad::physics::Acceleration operator/(ad::physics::Acceleration const &value, ad::physics::RatioValue const &r)
{
  r.ensureValidNonZero();
  value.ensureValid();
  ad::physics::Acceleration result(value.mAcceleration / r.mRatioValue);
  result.restrictToLimitsAndEnsureValid();
  return result;
}

/* ##################  ad::physics::Angle  ################ */

/*!
 * @brief Arithmetic physics operation value = value * r
 *
 * @param[in] value physics value
 * @param[in] r ratio value
 *
 * @returns value = value * r
 *
 * \note throws a std::out_of_range exception if one of the two operands is not valid.
 * \note The result is restricted to the limits of ad::physics::Angle.
 */
inline ad::physics::Angle operator*(ad::physics::Angle const &value, ad::physics::RatioValue const &r)
{
  r.ensureValid();
  value.ensureValid();
  ad::physics::Angle result(r.mRatioValue * value.mAngle);
  result.restrictToLimitsAndEnsureValid();
  return result;
}

/*!
 * @brief Arithmetic ratio operation value = r * value
 *
 * @param[in] r ratio value
 * @param[in] value physics value
 *
 * @returns value = r * value
 *
 * \note throws a std::out_of_range exception if one of the two operands is not valid.
 * \note The result is restricted to the limits of ad::physics::Angle.

 *   the operation is not valid
 */
inline ad::physics::Angle operator*(ad::physics::RatioValue const &r, ad::physics::Angle const &value)
{
  r.ensureValid();
  value.ensureValid();
  ad::physics::Angle result(r.mRatioValue * value.mAngle);
  result.restrictToLimitsAndEnsureValid();
  return result;
}

/*!
 * @brief Arithmetic physics operation value = value / r
 *
 * @param[in] value physics value
 * @param[in] r ratio value
 *
 * @returns value = value / r
 *
 * \note throws a std::out_of_range exception if one of the two operands is not valid or if the divisor is zero
 * \note The result is restricted to the limits of ad::physics::Angle.
 */
inline ad::physics::Angle operator/(ad::physics::Angle const &value, ad::physics::RatioValue const &r)
{
  r.ensureValidNonZero();
  value.ensureValid();
  ad::physics::Angle result(value.mAngle / r.mRatioValue);
  result.restrictToLimitsAndEnsureValid();
  return result;
}

/* ##################  ad::physics::AngularAcceleration  ################ */

/*!
 * @brief Arithmetic physics operation value = value * r
 *
 * @param[in] value physics value
 * @param[in] r ratio value
 *
 * @returns value = value * r
 *
 * \note throws a std::out_of_range exception if one of the two operands is not valid.
 * \note The result is restricted to the limits of ad::physics::AngularAcceleration.
 */
inline ad::physics::AngularAcceleration operator*(ad::physics::AngularAcceleration const &value,
                                                  ad::physics::RatioValue const &r)
{
  r.ensureValid();
  value.ensureValid();
  ad::physics::AngularAcceleration result(r.mRatioValue * value.mAngularAcceleration);
  result.restrictToLimitsAndEnsureValid();
  return result;
}

/*!
 * @brief Arithmetic ratio operation value = r * value
 *
 * @param[in] r ratio value
 * @param[in] value physics value
 *
 * @returns value = r * value
 *
 * \note throws a std::out_of_range exception if one of the two operands is not valid.
 * \note The result is restricted to the limits of ad::physics::AngularAcceleration.
 */
inline ad::physics::AngularAcceleration operator*(ad::physics::RatioValue const &r,
                                                  ad::physics::AngularAcceleration const &value)
{
  r.ensureValid();
  value.ensureValid();
  ad::physics::AngularAcceleration result(r.mRatioValue * value.mAngularAcceleration);
  result.restrictToLimitsAndEnsureValid();
  return result;
}

/*!
 * @brief Arithmetic physics operation value = value / r
 *
 * @param[in] value physics value
 * @param[in] r ratio value
 *
 * @returns value = value / r
 *
 * \note throws a std::out_of_range exception if one of the two operands is not valid or if the divisor is zero
 * \note The result is restricted to the limits of ad::physics::AngularAcceleration.
 */
inline ad::physics::AngularAcceleration operator/(ad::physics::AngularAcceleration const &value,
                                                  ad::physics::RatioValue const &r)
{
  r.ensureValidNonZero();
  value.ensureValid();
  ad::physics::AngularAcceleration result(value.mAngularAcceleration / r.mRatioValue);
  result.restrictToLimitsAndEnsureValid();
  return result;
}

/* ##################  ad::physics::AngularVelocity  ################ */

/*!
 * @brief Arithmetic physics operation value = value * r
 *
 * @param[in] value physics value
 * @param[in] r ratio value
 *
 * @returns value = value * r
 *
 * \note throws a std::out_of_range exception if one of the two operands is not valid.
 * \note The result is restricted to the limits of ad::physics::AngularVelocity.
 */
inline ad::physics::AngularVelocity operator*(ad::physics::AngularVelocity const &value,
                                              ad::physics::RatioValue const &r)
{
  r.ensureValid();
  value.ensureValid();
  ad::physics::AngularVelocity result(r.mRatioValue * value.mAngularVelocity);
  result.restrictToLimitsAndEnsureValid();
  return result;
}

/*!
 * @brief Arithmetic ratio operation value = r * value
 *
 * @param[in] r ratio value
 * @param[in] value physics value
 *
 * @returns value = r * value
 *
 * \note throws a std::out_of_range exception if one of the two operands is not valid.
 * \note The result is restricted to the limits of ad::physics::AngularVelocity.
 */
inline ad::physics::AngularVelocity operator*(ad::physics::RatioValue const &r,
                                              ad::physics::AngularVelocity const &value)
{
  r.ensureValid();
  value.ensureValid();
  ad::physics::AngularVelocity result(r.mRatioValue * value.mAngularVelocity);
  result.restrictToLimitsAndEnsureValid();
  return result;
}

/*!
 * @brief Arithmetic physics operation value = value / r
 *
 * @param[in] value physics value
 * @param[in] r ratio value
 *
 * @returns value = value / r
 *
 * \note throws a std::out_of_range exception if one of the two operands is not valid or if the divisor is zero
 * \note The result is restricted to the limits of ad::physics::AngularVelocity.
 */
inline ad::physics::AngularVelocity operator/(ad::physics::AngularVelocity const &value,
                                              ad::physics::RatioValue const &r)
{
  r.ensureValidNonZero();
  value.ensureValid();
  ad::physics::AngularVelocity result(value.mAngularVelocity / r.mRatioValue);
  result.restrictToLimitsAndEnsureValid();
  return result;
}

/* ##################  ad::physics::Distance  ################ */

/*!
 * @brief Arithmetic physics operation value = value * r
 *
 * @param[in] value physics value
 * @param[in] r ratio value
 *
 * @returns value = value * r
 *
 * \note throws a std::out_of_range exception if one of the two operands is not valid.
 * \note The result is restricted to the limits of ad::physics::Distance.
 */
inline ad::physics::Distance operator*(ad::physics::Distance const &value, ad::physics::RatioValue const &r)
{
  r.ensureValid();
  value.ensureValid();
  ad::physics::Distance result(r.mRatioValue * value.mDistance);
  result.restrictToLimitsAndEnsureValid();
  return result;
}

/*!
 * @brief Arithmetic ratio operation value = r * value
 *
 * @param[in] r ratio value
 * @param[in] value physics value
 *
 * @returns value = r * value
 *
 * \note throws a std::out_of_range exception if one of the two operands is not valid.
 * \note The result is restricted to the limits of ad::physics::Distance.
 */
inline ad::physics::Distance operator*(ad::physics::RatioValue const &r, ad::physics::Distance const &value)
{
  r.ensureValid();
  value.ensureValid();
  ad::physics::Distance result(r.mRatioValue * value.mDistance);
  result.restrictToLimitsAndEnsureValid();
  return result;
}

/*!
 * @brief Arithmetic physics operation value = value / r
 *
 * @param[in] value physics value
 * @param[in] r ratio value
 *
 * @returns value = value / r
 *
 * \note throws a std::out_of_range exception if one of the two operands is not valid or if the divisor is zero
 * \note The result is restricted to the limits of ad::physics::Distance.
 */
inline ad::physics::Distance operator/(ad::physics::Distance const &value, ad::physics::RatioValue const &r)
{
  r.ensureValidNonZero();
  value.ensureValid();
  ad::physics::Distance result(value.mDistance / r.mRatioValue);
  result.restrictToLimitsAndEnsureValid();
  return result;
}

/* ##################  ad::physics::DistanceSquared  ################ */

/*!
 * @brief Arithmetic physics operation value = value * r
 *
 * @param[in] value physics value
 * @param[in] r ratio value
 *
 * @returns value = value * r
 *
 * \note throws a std::out_of_range exception if one of the two operands is not valid.
 * \note The result is restricted to the limits of ad::physics::DistanceSquared.
 */
inline ad::physics::DistanceSquared operator*(ad::physics::DistanceSquared const &value,
                                              ad::physics::RatioValue const &r)
{
  r.ensureValid();
  value.ensureValid();
  ad::physics::DistanceSquared result(r.mRatioValue * value.mDistanceSquared);
  result.restrictToLimitsAndEnsureValid();
  return result;
}

/*!
 * @brief Arithmetic ratio operation value = r * value
 *
 * @param[in] r ratio value
 * @param[in] value physics value
 *
 * @returns value = r * value
 *
 * \note throws a std::out_of_range exception if one of the two operands is not valid.
 * \note The result is restricted to the limits of ad::physics::DistanceSquared.
 */
inline ad::physics::DistanceSquared operator*(ad::physics::RatioValue const &r,
                                              ad::physics::DistanceSquared const &value)
{
  r.ensureValid();
  value.ensureValid();
  ad::physics::DistanceSquared result(r.mRatioValue * value.mDistanceSquared);
  result.restrictToLimitsAndEnsureValid();
  return result;
}

/*!
 * @brief Arithmetic physics operation value = value / r
 *
 * @param[in] value physics value
 * @param[in] r ratio value
 *
 * @returns value = value / r
 *
 * \note throws a std::out_of_range exception if one of the two operands is not valid or if the divisor is zero
 * \note The result is restricted to the limits of ad::physics::DistanceSquared.
 */
inline ad::physics::DistanceSquared operator/(ad::physics::DistanceSquared const &value,
                                              ad::physics::RatioValue const &r)
{
  r.ensureValidNonZero();
  value.ensureValid();
  ad::physics::DistanceSquared result(value.mDistanceSquared / r.mRatioValue);
  result.restrictToLimitsAndEnsureValid();
  return result;
}

/* ##################  ad::physics::Duration  ################ */

/*!
 * @brief Arithmetic physics operation value = value * r
 *
 * @param[in] value physics value
 * @param[in] r ratio value
 *
 * @returns value = value * r
 *
 * \note throws a std::out_of_range exception if one of the two operands is not valid.
 * \note The result is restricted to the limits of ad::physics::Duration.
 */
inline ad::physics::Duration operator*(ad::physics::Duration const &value, ad::physics::RatioValue const &r)
{
  r.ensureValid();
  value.ensureValid();
  ad::physics::Duration result(r.mRatioValue * value.mDuration);
  result.restrictToLimitsAndEnsureValid();
  return result;
}

/*!
 * @brief Arithmetic ratio operation value = r * value
 *
 * @param[in] r ratio value
 * @param[in] value physics value
 *
 * @returns value = r * value
 *
 * \note throws a std::out_of_range exception if one of the two operands is not valid.
 * \note The result is restricted to the limits of ad::physics::Duration.
 */
inline ad::physics::Duration operator*(ad::physics::RatioValue const &r, ad::physics::Duration const &value)
{
  r.ensureValid();
  value.ensureValid();
  ad::physics::Duration result(r.mRatioValue * value.mDuration);
  result.restrictToLimitsAndEnsureValid();
  return result;
}

/*!
 * @brief Arithmetic physics operation value = value / r
 *
 * @param[in] value physics value
 * @param[in] r ratio value
 *
 * @returns value = value / r
 *
 * \note throws a std::out_of_range exception if one of the two operands is not valid or if the divisor is zero
 * \note The result is restricted to the limits of ad::physics::Duration.
 */
inline ad::physics::Duration operator/(ad::physics::Duration const &value, ad::physics::RatioValue const &r)
{
  r.ensureValidNonZero();
  value.ensureValid();
  ad::physics::Duration result(value.mDuration / r.mRatioValue);
  result.restrictToLimitsAndEnsureValid();
  return result;
}

/* ##################  ad::physics::DurationSquared  ################ */

/*!
 * @brief Arithmetic physics operation value = value * r
 *
 * @param[in] value physics value
 * @param[in] r ratio value
 *
 * @returns value = value * r
 *
 * \note throws a std::out_of_range exception if one of the two operands is not valid.
 * \note The result is restricted to the limits of ad::physics::DurationSquared.
 */
inline ad::physics::DurationSquared operator*(ad::physics::DurationSquared const &value,
                                              ad::physics::RatioValue const &r)
{
  r.ensureValid();
  value.ensureValid();
  ad::physics::DurationSquared result(r.mRatioValue * value.mDurationSquared);
  result.restrictToLimitsAndEnsureValid();
  return result;
}

/*!
 * @brief Arithmetic ratio operation value = r * value
 *
 * @param[in] r ratio value
 * @param[in] value physics value
 *
 * @returns value = r * value
 *
 * \note throws a std::out_of_range exception if one of the two operands is not valid.
 * \note The result is restricted to the limits of ad::physics::DurationSquared.
 */
inline ad::physics::DurationSquared operator*(ad::physics::RatioValue const &r,
                                              ad::physics::DurationSquared const &value)
{
  r.ensureValid();
  value.ensureValid();
  ad::physics::DurationSquared result(r.mRatioValue * value.mDurationSquared);
  result.restrictToLimitsAndEnsureValid();
  return result;
}

/*!
 * @brief Arithmetic physics operation value = value / r
 *
 * @param[in] value physics value
 * @param[in] r ratio value
 *
 * @returns value = value / r
 *
 * \note throws a std::out_of_range exception if one of the two operands is not valid or if the divisor is zero
 * \note The result is restricted to the limits of ad::physics::DurationSquared.
 */
inline ad::physics::DurationSquared operator/(ad::physics::DurationSquared const &value,
                                              ad::physics::RatioValue const &r)
{
  r.ensureValidNonZero();
  value.ensureValid();
  ad::physics::DurationSquared result(value.mDurationSquared / r.mRatioValue);
  result.restrictToLimitsAndEnsureValid();
  return result;
}

/* ##################  ad::physics::ParametricValue ################ */

/*!
 * @brief Arithmetic physics operation value = value * r
 *
 * @param[in] value physics value
 * @param[in] r ratio value
 *
 * @returns value = value * r
 *
 * \note throws a std::out_of_range exception if one of the two operands is not valid.
 * \note The result is restricted to the limits of ad::physics::Angle.
 */
inline ad::physics::ParametricValue operator*(ad::physics::ParametricValue const &value,
                                              ad::physics::RatioValue const &r)
{
  value.ensureValid();
  r.ensureValid();
  ad::physics::ParametricValue result(value.mParametricValue * r.mRatioValue);
  result.restrictToLimitsAndEnsureValid();
  return result;
}

/*!
 * @brief Arithmetic physics operation value = value / r
 *
 * @param[in] value physics value
 * @param[in] r ratio value
 *
 * @returns value = value / r
 *
 * \note throws a std::out_of_range exception if one of the two operands is not valid or if the divisor is zero
 * \note The result is restricted to the limits of ad::physics::ParametricValue.
 */
inline ad::physics::ParametricValue operator/(ad::physics::ParametricValue const &value,
                                              ad::physics::RatioValue const &r)
{
  r.ensureValidNonZero();
  value.ensureValid();
  ad::physics::ParametricValue result(value.mParametricValue / r.mRatioValue);
  result.restrictToLimitsAndEnsureValid();
  return result;
}

/* ##################  ad::physics::Probability  ################ */

/*!
 * @brief Arithmetic physics operation value = value * r
 *
 * @param[in] value physics value
 * @param[in] r ratio value
 *
 * @returns value = value * r
 *
 * \note throws a std::out_of_range exception if one of the two operands is not valid.
 * \note The result is restricted to the limits of ad::physics::Probability.
 */
inline ad::physics::Probability operator*(ad::physics::Probability const &value, ad::physics::RatioValue const &r)
{
  r.ensureValid();
  value.ensureValid();
  ad::physics::Probability result(r.mRatioValue * value.mProbability);
  result.restrictToLimitsAndEnsureValid();
  return result;
}

/*!
 * @brief Arithmetic ratio operation value = r * value
 *
 * @param[in] r ratio value
 * @param[in] value physics value
 *
 * @returns value = r * value
 *
 * \note throws a std::out_of_range exception if one of the two operands is not valid.
 * \note The result is restricted to the limits of ad::physics::Probability.
 */
inline ad::physics::Probability operator*(ad::physics::RatioValue const &r, ad::physics::Probability const &value)
{
  r.ensureValid();
  value.ensureValid();
  ad::physics::Probability result(r.mRatioValue * value.mProbability);
  result.restrictToLimitsAndEnsureValid();
  return result;
}

/*!
 * @brief Arithmetic physics operation value = value / r
 *
 * @param[in] value physics value
 * @param[in] r ratio value
 *
 * @returns value = value / r
 *
 * \note throws a std::out_of_range exception if one of the two operands is not valid or if the divisor is zero
 * \note The result is restricted to the limits of ad::physics::Probability.
 */
inline ad::physics::Probability operator/(ad::physics::Probability const &value, ad::physics::RatioValue const &r)
{
  r.ensureValidNonZero();
  value.ensureValid();
  ad::physics::Probability result(value.mProbability / r.mRatioValue);
  result.restrictToLimitsAndEnsureValid();
  return result;
}

/* ##################  ad::physics::RatioValue  ################ */

/*!
 * @brief Arithmetic physics operation ratio = ratio * ratio
 *
 * @param[in] r1 ratio value
 * @param[in] r2 ratio value
 *
 * @returns ratio = r1 * r2
 *
 * \note throws a std::out_of_range exception if one of the two operands is not valid.
 * \note The result is restricted to the limits of ad::physics::RatioValue.
 */
inline ad::physics::RatioValue operator*(ad::physics::RatioValue const &r1, ad::physics::RatioValue const &r2)
{
  r1.ensureValid();
  r2.ensureValid();
  ad::physics::RatioValue result(r1.mRatioValue * r2.mRatioValue);
  result.restrictToLimitsAndEnsureValid();
  return result;
}

/* ##################  ad::physics::Speed  ################ */

/*!
 * @brief Arithmetic physics operation value = value * r
 *
 * @param[in] value physics value
 * @param[in] r ratio value
 *
 * @returns value = value * r
 *
 * \note throws a std::out_of_range exception if one of the two operands is not valid.
 * \note The result is restricted to the limits of ad::physics::Speed.
 */
inline ad::physics::Speed operator*(ad::physics::Speed const &value, ad::physics::RatioValue const &r)
{
  r.ensureValid();
  value.ensureValid();
  ad::physics::Speed result(r.mRatioValue * value.mSpeed);
  result.restrictToLimitsAndEnsureValid();
  return result;
}

/*!
 * @brief Arithmetic ratio operation value = r * value
 *
 * @param[in] r ratio value
 * @param[in] value physics value
 *
 * @returns value = r * value
 *
 * \note throws a std::out_of_range exception if one of the two operands is not valid.
 * \note The result is restricted to the limits of ad::physics::Speed.
 */
inline ad::physics::Speed operator*(ad::physics::RatioValue const &r, ad::physics::Speed const &value)
{
  r.ensureValid();
  value.ensureValid();
  ad::physics::Speed result(r.mRatioValue * value.mSpeed);
  result.restrictToLimitsAndEnsureValid();
  return result;
}

/*!
 * @brief Arithmetic physics operation value = value / r
 *
 * @param[in] value physics value
 * @param[in] r ratio value
 *
 * @returns value = value / r
 *
 * \note throws a std::out_of_range exception if one of the two operands is not valid or if the divisor is zero
 * \note The result is restricted to the limits of ad::physics::Speed.
 */
inline ad::physics::Speed operator/(ad::physics::Speed const &value, ad::physics::RatioValue const &r)
{
  r.ensureValidNonZero();
  value.ensureValid();
  ad::physics::Speed result(value.mSpeed / r.mRatioValue);
  result.restrictToLimitsAndEnsureValid();
  return result;
}

/* ##################  ad::physics::SpeedSquared  ################ */

/*!
 * @brief Arithmetic physics operation value = value * r
 *
 * @param[in] value physics value
 * @param[in] r ratio value
 *
 * @returns value = value * r
 *
 * \note throws a std::out_of_range exception if one of the two operands is not valid.
 * \note The result is restricted to the limits of ad::physics::SpeedSquared.
 */
inline ad::physics::SpeedSquared operator*(ad::physics::SpeedSquared const &value, ad::physics::RatioValue const &r)
{
  r.ensureValid();
  value.ensureValid();
  ad::physics::SpeedSquared result(r.mRatioValue * value.mSpeedSquared);
  result.restrictToLimitsAndEnsureValid();
  return result;
}

/*!
 * @brief Arithmetic ratio operation value = r * value
 *
 * @param[in] r ratio value
 * @param[in] value physics value
 *
 * @returns value = r * value
 *
 * \note throws a std::out_of_range exception if one of the two operands is not valid.
 * \note The result is restricted to the limits of ad::physics::SpeedSquared.
 */
inline ad::physics::SpeedSquared operator*(ad::physics::RatioValue const &r, ad::physics::SpeedSquared const &value)
{
  r.ensureValid();
  value.ensureValid();
  ad::physics::SpeedSquared result(r.mRatioValue * value.mSpeedSquared);
  result.restrictToLimitsAndEnsureValid();
  return result;
}

/*!
 * @brief Arithmetic physics operation value = value / r
 *
 * @param[in] value physics value
 * @param[in] r ratio value
 *
 * @returns value = value / r
 *
 * \note throws a std::out_of_range exception if one of the two operands is not valid or if the divisor is zero
 * \note The result is restricted to the limits of ad::physics::SpeedSquared.
 */
inline ad::physics::SpeedSquared operator/(ad::physics::SpeedSquared const &value, ad::physics::RatioValue const &r)
{
  r.ensureValidNonZero();
  value.ensureValid();
  ad::physics::SpeedSquared result(value.mSpeedSquared / r.mRatioValue);
  result.restrictToLimitsAndEnsureValid();
  return result;
}

/* ##################  ad::physics::Weight  ################ */

/*!
 * @brief Arithmetic physics operation value = value * r
 *
 * @param[in] value physics value
 * @param[in] r ratio value
 *
 * @returns value = value * r
 *
 * \note throws a std::out_of_range exception if one of the two operands is not valid.
 * \note The result is restricted to the limits of ad::physics::Weight.
 */
inline ad::physics::Weight operator*(ad::physics::Weight const &value, ad::physics::RatioValue const &r)
{
  r.ensureValid();
  value.ensureValid();
  ad::physics::Weight result(r.mRatioValue * value.mWeight);
  result.restrictToLimitsAndEnsureValid();
  return result;
}

/*!
 * @brief Arithmetic ratio operation value = r * value
 *
 * @param[in] r ratio value
 * @param[in] value physics value
 *
 * @returns value = r * value
 *
 * \note throws a std::out_of_range exception if one of the two operands is not valid.
 * \note The result is restricted to the limits of ad::physics::Weight.
 */
inline ad::physics::Weight operator*(ad::physics::RatioValue const &r, ad::physics::Weight const &value)
{
  r.ensureValid();
  value.ensureValid();
  ad::physics::Weight result(r.mRatioValue * value.mWeight);
  result.restrictToLimitsAndEnsureValid();
  return result;
}

/*!
 * @brief Arithmetic physics operation value = value / r
 *
 * @param[in] value physics value
 * @param[in] r ratio value
 *
 * @returns value = value / r
 *
 * \note throws a std::out_of_range exception if one of the two operands is not valid or if the divisor is zero
 * \note The result is restricted to the limits of ad::physics::Weight.
 */
inline ad::physics::Weight operator/(ad::physics::Weight const &value, ad::physics::RatioValue const &r)
{
  r.ensureValidNonZero();
  value.ensureValid();
  ad::physics::Weight result(value.mWeight / r.mRatioValue);
  result.restrictToLimitsAndEnsureValid();
  return result;
}
