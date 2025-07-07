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
 * @brief Arithmetic physics operation value = value * p
 *
 * @param[in] value physics value
 * @param[in] p parametric value
 *
 * @returns value = value * p
 *
 * \note throws a std::out_of_range exception if one of the two operands is not valid.
 * \note The result is restricted to the limits of ad::physics::Acceleration.
 */
inline ad::physics::Acceleration operator*(ad::physics::Acceleration const &value,
                                           ad::physics::ParametricValue const &p)
{
  p.ensureValid();
  value.ensureValid();
  ad::physics::Acceleration result(p.mParametricValue * value.mAcceleration);
  result.restrictToLimitsAndEnsureValid();
  return result;
}

/*!
 * @brief Arithmetic parametric operation value = p * value
 *
 * @param[in] p parametric value
 * @param[in] value physics value
 *
 * @returns value = p * value
 *
 * \note throws a std::out_of_range exception if one of the two operands is not valid.
 * \note The result is restricted to the limits of ad::physics::Acceleration.
 */
inline ad::physics::Acceleration operator*(ad::physics::ParametricValue const &p,
                                           ad::physics::Acceleration const &value)
{
  p.ensureValid();
  value.ensureValid();
  ad::physics::Acceleration result(p.mParametricValue * value.mAcceleration);
  result.restrictToLimitsAndEnsureValid();
  return result;
}

/*!
 * @brief Arithmetic physics operation value = value / p
 *
 * @param[in] value physics value
 * @param[in] p parametric value
 *
 * @returns value = value / p
 *
 * \note throws a std::out_of_range exception if one of the two operands is not valid or if the divisor is zero
 * \note The result is restricted to the limits of ad::physics::Acceleration.
 */
inline ad::physics::Acceleration operator/(ad::physics::Acceleration const &value,
                                           ad::physics::ParametricValue const &p)
{
  p.ensureValidNonZero();
  value.ensureValid();
  ad::physics::Acceleration result(value.mAcceleration / p.mParametricValue);
  result.restrictToLimitsAndEnsureValid();
  return result;
}

/* ##################  ad::physics::Angle  ################ */

/*!
 * @brief Arithmetic physics operation value = value * p
 *
 * @param[in] value physics value
 * @param[in] p parametric value
 *
 * @returns value = value * p
 *
 * \note throws a std::out_of_range exception if one of the two operands is not valid.
 * \note The result is restricted to the limits of ad::physics::Angle.
 */
inline ad::physics::Angle operator*(ad::physics::Angle const &value, ad::physics::ParametricValue const &p)
{
  p.ensureValid();
  value.ensureValid();
  ad::physics::Angle result(p.mParametricValue * value.mAngle);
  result.restrictToLimitsAndEnsureValid();
  return result;
}

/*!
 * @brief Arithmetic parametric operation value = p * value
 *
 * @param[in] p parametric value
 * @param[in] value physics value
 *
 * @returns value = p * value
 *
 * \note throws a std::out_of_range exception if one of the two operands is not valid.
 * \note The result is restricted to the limits of ad::physics::Angle.
 */
inline ad::physics::Angle operator*(ad::physics::ParametricValue const &p, ad::physics::Angle const &value)
{
  p.ensureValid();
  value.ensureValid();
  ad::physics::Angle result(p.mParametricValue * value.mAngle);
  result.restrictToLimitsAndEnsureValid();
  return result;
}

/*!
 * @brief Arithmetic physics operation value = value / p
 *
 * @param[in] value physics value
 * @param[in] p parametric value
 *
 * @returns value = value / p
 *
 * \note throws a std::out_of_range exception if one of the two operands is not valid or if the divisor is zero
 * \note The result is restricted to the limits of ad::physics::Angle.
 */
inline ad::physics::Angle operator/(ad::physics::Angle const &value, ad::physics::ParametricValue const &p)
{
  p.ensureValidNonZero();
  value.ensureValid();
  ad::physics::Angle result(value.mAngle / p.mParametricValue);
  result.restrictToLimitsAndEnsureValid();
  return result;
}

/* ##################  ad::physics::AngularAcceleration  ################ */

/*!
 * @brief Arithmetic physics operation value = value * p
 *
 * @param[in] value physics value
 * @param[in] p parametric value
 *
 * @returns value = value * p
 *
 * \note throws a std::out_of_range exception if one of the two operands is not valid.
 * \note The result is restricted to the limits of ad::physics::AngularAcceleration.
 */
inline ad::physics::AngularAcceleration operator*(ad::physics::AngularAcceleration const &value,
                                                  ad::physics::ParametricValue const &p)
{
  p.ensureValid();
  value.ensureValid();
  ad::physics::AngularAcceleration result(p.mParametricValue * value.mAngularAcceleration);
  result.restrictToLimitsAndEnsureValid();
  return result;
}

/*!
 * @brief Arithmetic parametric operation value = p * value
 *
 * @param[in] p parametric value
 * @param[in] value physics value
 *
 * @returns value = p * value
 *
 * \note throws a std::out_of_range exception if one of the two operands is not valid.
 * \note The result is restricted to the limits of ad::physics::AngularAcceleration.
 */
inline ad::physics::AngularAcceleration operator*(ad::physics::ParametricValue const &p,
                                                  ad::physics::AngularAcceleration const &value)
{
  p.ensureValid();
  value.ensureValid();
  ad::physics::AngularAcceleration result(p.mParametricValue * value.mAngularAcceleration);
  result.restrictToLimitsAndEnsureValid();
  return result;
}

/*!
 * @brief Arithmetic physics operation value = value / p
 *
 * @param[in] value physics value
 * @param[in] p parametric value
 *
 * @returns value = value / p
 *
 * \note throws a std::out_of_range exception if one of the two operands is not valid or if the divisor is zero
 * \note The result is restricted to the limits of ad::physics::AngularAcceleration.
 */
inline ad::physics::AngularAcceleration operator/(ad::physics::AngularAcceleration const &value,
                                                  ad::physics::ParametricValue const &p)
{
  p.ensureValidNonZero();
  value.ensureValid();
  ad::physics::AngularAcceleration result(value.mAngularAcceleration / p.mParametricValue);
  result.restrictToLimitsAndEnsureValid();
  return result;
}

/* ##################  ad::physics::AngularVelocity  ################ */

/*!
 * @brief Arithmetic physics operation value = value * p
 *
 * @param[in] value physics value
 * @param[in] p parametric value
 *
 * @returns value = value * p
 *
 * \note throws a std::out_of_range exception if one of the two operands is not valid.
 * \note The result is restricted to the limits of ad::physics::AngularVelocity.
 */
inline ad::physics::AngularVelocity operator*(ad::physics::AngularVelocity const &value,
                                              ad::physics::ParametricValue const &p)
{
  p.ensureValid();
  value.ensureValid();
  ad::physics::AngularVelocity result(p.mParametricValue * value.mAngularVelocity);
  result.restrictToLimitsAndEnsureValid();
  return result;
}

/*!
 * @brief Arithmetic parametric operation value = p * value
 *
 * @param[in] p parametric value
 * @param[in] value physics value
 *
 * @returns value = p * value
 *
 * \note throws a std::out_of_range exception if one of the two operands is not valid.
 * \note The result is restricted to the limits of ad::physics::AngularVelocity.
 */
inline ad::physics::AngularVelocity operator*(ad::physics::ParametricValue const &p,
                                              ad::physics::AngularVelocity const &value)
{
  p.ensureValid();
  value.ensureValid();
  ad::physics::AngularVelocity result(p.mParametricValue * value.mAngularVelocity);
  result.restrictToLimitsAndEnsureValid();
  return result;
}

/*!
 * @brief Arithmetic physics operation value = value / p
 *
 * @param[in] value physics value
 * @param[in] p parametric value
 *
 * @returns value = value / p
 *
 * \note throws a std::out_of_range exception if one of the two operands is not valid or if the divisor is zero
 * \note The result is restricted to the limits of ad::physics::AngularVelocity.
 */
inline ad::physics::AngularVelocity operator/(ad::physics::AngularVelocity const &value,
                                              ad::physics::ParametricValue const &p)
{
  p.ensureValidNonZero();
  value.ensureValid();
  ad::physics::AngularVelocity result(value.mAngularVelocity / p.mParametricValue);
  result.restrictToLimitsAndEnsureValid();
  return result;
}

/* ##################  ad::physics::Distance  ################ */

/*!
 * @brief Arithmetic physics operation value = value * p
 *
 * @param[in] value physics value
 * @param[in] p parametric value
 *
 * @returns value = value * p
 *
 * \note throws a std::out_of_range exception if one of the two operands is not valid.
 * \note The result is restricted to the limits of ad::physics::Distance.
 */
inline ad::physics::Distance operator*(ad::physics::Distance const &value, ad::physics::ParametricValue const &p)
{
  p.ensureValid();
  value.ensureValid();
  ad::physics::Distance result(p.mParametricValue * value.mDistance);
  result.restrictToLimitsAndEnsureValid();
  return result;
}

/*!
 * @brief Arithmetic parametric operation value = p * value
 *
 * @param[in] p parametric value
 * @param[in] value physics value
 *
 * @returns value = p * value
 *
 * \note throws a std::out_of_range exception if one of the two operands is not valid.
 * \note The result is restricted to the limits of ad::physics::Distance.
 */
inline ad::physics::Distance operator*(ad::physics::ParametricValue const &p, ad::physics::Distance const &value)
{
  p.ensureValid();
  value.ensureValid();
  ad::physics::Distance result(p.mParametricValue * value.mDistance);
  result.restrictToLimitsAndEnsureValid();
  return result;
}

/*!
 * @brief Arithmetic physics operation value = value / p
 *
 * @param[in] value physics value
 * @param[in] p parametric value
 *
 * @returns value = value / p
 *
 * \note throws a std::out_of_range exception if one of the two operands is not valid or if the divisor is zero
 * \note The result is restricted to the limits of ad::physics::Distance.
 */
inline ad::physics::Distance operator/(ad::physics::Distance const &value, ad::physics::ParametricValue const &p)
{
  p.ensureValidNonZero();
  value.ensureValid();
  ad::physics::Distance result(value.mDistance / p.mParametricValue);
  result.restrictToLimitsAndEnsureValid();
  return result;
}

/* ##################  ad::physics::DistanceSquared  ################ */

/*!
 * @brief Arithmetic physics operation value = value * p
 *
 * @param[in] value physics value
 * @param[in] p parametric value
 *
 * @returns value = value * p
 *
 * \note throws a std::out_of_range exception if one of the two operands is not valid.
 * \note The result is restricted to the limits of ad::physics::DistanceSquared.
 */
inline ad::physics::DistanceSquared operator*(ad::physics::DistanceSquared const &value,
                                              ad::physics::ParametricValue const &p)
{
  p.ensureValid();
  value.ensureValid();
  ad::physics::DistanceSquared result(p.mParametricValue * value.mDistanceSquared);
  result.restrictToLimitsAndEnsureValid();
  return result;
}

/*!
 * @brief Arithmetic parametric operation value = p * value
 *
 * @param[in] p parametric value
 * @param[in] value physics value
 *
 * @returns value = p * value
 *
 * \note throws a std::out_of_range exception if one of the two operands is not valid.
 * \note The result is restricted to the limits of ad::physics::DistanceSquared.
 */
inline ad::physics::DistanceSquared operator*(ad::physics::ParametricValue const &p,
                                              ad::physics::DistanceSquared const &value)
{
  p.ensureValid();
  value.ensureValid();
  ad::physics::DistanceSquared result(p.mParametricValue * value.mDistanceSquared);
  result.restrictToLimitsAndEnsureValid();
  return result;
}

/*!
 * @brief Arithmetic physics operation value = value / p
 *
 * @param[in] value physics value
 * @param[in] p parametric value
 *
 * @returns value = value / p
 *
 * \note throws a std::out_of_range exception if one of the two operands is not valid or if the divisor is zero
 * \note The result is restricted to the limits of ad::physics::DistanceSquared.
 */
inline ad::physics::DistanceSquared operator/(ad::physics::DistanceSquared const &value,
                                              ad::physics::ParametricValue const &p)
{
  p.ensureValidNonZero();
  value.ensureValid();
  ad::physics::DistanceSquared result(value.mDistanceSquared / p.mParametricValue);
  result.restrictToLimitsAndEnsureValid();
  return result;
}

/* ##################  ad::physics::Duration  ################ */

/*!
 * @brief Arithmetic physics operation value = value * p
 *
 * @param[in] value physics value
 * @param[in] p parametric value
 *
 * @returns value = value * p
 *
 * \note throws a std::out_of_range exception if one of the two operands is not valid.
 * \note The result is restricted to the limits of ad::physics::Duration.
 */
inline ad::physics::Duration operator*(ad::physics::Duration const &value, ad::physics::ParametricValue const &p)
{
  p.ensureValid();
  value.ensureValid();
  ad::physics::Duration result(p.mParametricValue * value.mDuration);
  result.restrictToLimitsAndEnsureValid();
  return result;
}

/*!
 * @brief Arithmetic parametric operation value = p * value
 *
 * @param[in] p parametric value
 * @param[in] value physics value
 *
 * @returns value = p * value
 *
 * \note throws a std::out_of_range exception if one of the two operands is not valid.
 * \note The result is restricted to the limits of ad::physics::Duration.
 */
inline ad::physics::Duration operator*(ad::physics::ParametricValue const &p, ad::physics::Duration const &value)
{
  p.ensureValid();
  value.ensureValid();
  ad::physics::Duration result(p.mParametricValue * value.mDuration);
  result.restrictToLimitsAndEnsureValid();
  return result;
}

/*!
 * @brief Arithmetic physics operation value = value / p
 *
 * @param[in] value physics value
 * @param[in] p parametric value
 *
 * @returns value = value / p
 *
 * \note throws a std::out_of_range exception if one of the two operands is not valid or if the divisor is zero
 * \note The result is restricted to the limits of ad::physics::Duration.
 */
inline ad::physics::Duration operator/(ad::physics::Duration const &value, ad::physics::ParametricValue const &p)
{
  p.ensureValidNonZero();
  value.ensureValid();
  ad::physics::Duration result(value.mDuration / p.mParametricValue);
  result.restrictToLimitsAndEnsureValid();
  return result;
}

/* ##################  ad::physics::DurationSquared  ################ */

/*!
 * @brief Arithmetic physics operation value = value * p
 *
 * @param[in] value physics value
 * @param[in] p parametric value
 *
 * @returns value = value * p
 *
 * \note throws a std::out_of_range exception if one of the two operands is not valid.
 * \note The result is restricted to the limits of ad::physics::DurationSquared.
 */
inline ad::physics::DurationSquared operator*(ad::physics::DurationSquared const &value,
                                              ad::physics::ParametricValue const &p)
{
  p.ensureValid();
  value.ensureValid();
  ad::physics::DurationSquared result(p.mParametricValue * value.mDurationSquared);
  result.restrictToLimitsAndEnsureValid();
  return result;
}

/*!
 * @brief Arithmetic parametric operation value = p * value
 *
 * @param[in] p parametric value
 * @param[in] value physics value
 *
 * @returns value = p * value
 *
 * \note throws a std::out_of_range exception if one of the two operands is not valid.
 * \note The result is restricted to the limits of ad::physics::DurationSquared.
 */
inline ad::physics::DurationSquared operator*(ad::physics::ParametricValue const &p,
                                              ad::physics::DurationSquared const &value)
{
  p.ensureValid();
  value.ensureValid();
  ad::physics::DurationSquared result(p.mParametricValue * value.mDurationSquared);
  result.restrictToLimitsAndEnsureValid();
  return result;
}

/*!
 * @brief Arithmetic physics operation value = value / p
 *
 * @param[in] value physics value
 * @param[in] p parametric value
 *
 * @returns value = value / p
 *
 * \note throws a std::out_of_range exception if one of the two operands is not valid or if the divisor is zero
 * \note The result is restricted to the limits of ad::physics::DurationSquared.
 */
inline ad::physics::DurationSquared operator/(ad::physics::DurationSquared const &value,
                                              ad::physics::ParametricValue const &p)
{
  p.ensureValidNonZero();
  value.ensureValid();
  ad::physics::DurationSquared result(value.mDurationSquared / p.mParametricValue);
  result.restrictToLimitsAndEnsureValid();
  return result;
}

/* ##################  ad::physics::ParametricValue ################ */

/*!
 * @brief Arithmetic physics operation parametric = parametric * parametric
 *
 * @param[in] p1 parametric value
 * @param[in] p2 parametric value
 *
 * @returns parametric = p1 * p2
 *
 * \note throws a std::out_of_range exception if one of the two operands is not valid.
 * \note The result is restricted to the limits of ad::physics::ParametricValue.
 */
inline ad::physics::ParametricValue operator*(ad::physics::ParametricValue const &p1,
                                              ad::physics::ParametricValue const &p2)
{
  p1.ensureValid();
  p2.ensureValid();
  ad::physics::ParametricValue result(p1.mParametricValue * p2.mParametricValue);
  result.restrictToLimitsAndEnsureValid();
  return result;
}

/* ##################  ad::physics::Probability  ################ */

/*!
 * @brief Arithmetic physics operation value = value * p
 *
 * @param[in] value physics value
 * @param[in] p parametric value
 *
 * @returns value = value * p
 *
 * \note throws a std::out_of_range exception if one of the two operands is not valid.
 * \note The result is restricted to the limits of ad::physics::Probability.
 */
inline ad::physics::Probability operator*(ad::physics::Probability const &value, ad::physics::ParametricValue const &p)
{
  p.ensureValid();
  value.ensureValid();
  ad::physics::Probability result(p.mParametricValue * value.mProbability);
  result.restrictToLimitsAndEnsureValid();
  return result;
}

/*!
 * @brief Arithmetic parametric operation value = p * value
 *
 * @param[in] p parametric value
 * @param[in] value physics value
 *
 * @returns value = p * value
 *
 * \note throws a std::out_of_range exception if one of the two operands is not valid.
 * \note The result is restricted to the limits of ad::physics::Probability.
 */
inline ad::physics::Probability operator*(ad::physics::ParametricValue const &p, ad::physics::Probability const &value)
{
  p.ensureValid();
  value.ensureValid();
  ad::physics::Probability result(p.mParametricValue * value.mProbability);
  result.restrictToLimitsAndEnsureValid();
  return result;
}

/*!
 * @brief Arithmetic physics operation value = value / p
 *
 * @param[in] value physics value
 * @param[in] p parametric value
 *
 * @returns value = value / p
 *
 * \note throws a std::out_of_range exception if one of the two operands is not valid or if the divisor is zero
 * \note The result is restricted to the limits of ad::physics::Probability.
 */
inline ad::physics::Probability operator/(ad::physics::Probability const &value, ad::physics::ParametricValue const &p)
{
  p.ensureValidNonZero();
  value.ensureValid();
  ad::physics::Probability result(value.mProbability / p.mParametricValue);
  result.restrictToLimitsAndEnsureValid();
  return result;
}

/* ##################  ad::physics::RatioValue  ################ */

/*!
 * @brief Arithmetic physics operation value = value * p
 *
 * @param[in] value physics value
 * @param[in] p parametric value
 *
 * @returns value = value * p
 *
 * \note throws a std::out_of_range exception if one of the two operands is not valid.
 * \note The result is restricted to the limits of ad::physics::RatioValue.
 */
inline ad::physics::RatioValue operator*(ad::physics::RatioValue const &value, ad::physics::ParametricValue const &p)
{
  p.ensureValid();
  value.ensureValid();
  ad::physics::RatioValue result(p.mParametricValue * value.mRatioValue);
  result.restrictToLimitsAndEnsureValid();
  return result;
}

/*!
 * @brief Arithmetic physics operation value = value / p
 *
 * @param[in] value physics value
 * @param[in] p parametric value
 *
 * @returns value = value / p
 *
 * \note throws a std::out_of_range exception if one of the two operands is not valid or if the divisor is zero
 * \note The result is restricted to the limits of ad::physics::RatioValue.
 */
inline ad::physics::RatioValue operator/(ad::physics::RatioValue const &value, ad::physics::ParametricValue const &p)
{
  p.ensureValidNonZero();
  value.ensureValid();
  ad::physics::RatioValue result(value.mRatioValue / p.mParametricValue);
  result.restrictToLimitsAndEnsureValid();
  return result;
}

/* ##################  ad::physics::Speed  ################ */

/*!
 * @brief Arithmetic physics operation value = value * p
 *
 * @param[in] value physics value
 * @param[in] p parametric value
 *
 * @returns value = value * p
 *
 * \note throws a std::out_of_range exception if one of the two operands is not valid.
 * \note The result is restricted to the limits of ad::physics::Speed.
 */
inline ad::physics::Speed operator*(ad::physics::Speed const &value, ad::physics::ParametricValue const &p)
{
  p.ensureValid();
  value.ensureValid();
  ad::physics::Speed result(p.mParametricValue * value.mSpeed);
  result.restrictToLimitsAndEnsureValid();
  return result;
}

/*!
 * @brief Arithmetic parametric operation value = p * value
 *
 * @param[in] p parametric value
 * @param[in] value physics value
 *
 * @returns value = p * value
 *
 * \note throws a std::out_of_range exception if one of the two operands is not valid.
 * \note The result is restricted to the limits of ad::physics::Speed.
 */
inline ad::physics::Speed operator*(ad::physics::ParametricValue const &p, ad::physics::Speed const &value)
{
  p.ensureValid();
  value.ensureValid();
  ad::physics::Speed result(p.mParametricValue * value.mSpeed);
  result.restrictToLimitsAndEnsureValid();
  return result;
}

/*!
 * @brief Arithmetic physics operation value = value / p
 *
 * @param[in] value physics value
 * @param[in] p parametric value
 *
 * @returns value = value / p
 *
 * \note throws a std::out_of_range exception if one of the two operands is not valid or if the divisor is zero
 * \note The result is restricted to the limits of ad::physics::Speed.
 */
inline ad::physics::Speed operator/(ad::physics::Speed const &value, ad::physics::ParametricValue const &p)
{
  p.ensureValidNonZero();
  value.ensureValid();
  ad::physics::Speed result(value.mSpeed / p.mParametricValue);
  result.restrictToLimitsAndEnsureValid();
  return result;
}

/* ##################  ad::physics::SpeedSquared  ################ */

/*!
 * @brief Arithmetic physics operation value = value * p
 *
 * @param[in] value physics value
 * @param[in] p parametric value
 *
 * @returns value = value * p
 *
 * \note throws a std::out_of_range exception if one of the two operands is not valid.
 * \note The result is restricted to the limits of ad::physics::SpeedSquared.
 */
inline ad::physics::SpeedSquared operator*(ad::physics::SpeedSquared const &value,
                                           ad::physics::ParametricValue const &p)
{
  p.ensureValid();
  value.ensureValid();
  ad::physics::SpeedSquared result(p.mParametricValue * value.mSpeedSquared);
  result.restrictToLimitsAndEnsureValid();
  return result;
}

/*!
 * @brief Arithmetic parametric operation value = p * value
 *
 * @param[in] p parametric value
 * @param[in] value physics value
 *
 * @returns value = p * value
 *
 * \note throws a std::out_of_range exception if one of the two operands is not valid.
 * \note The result is restricted to the limits of ad::physics::SpeedSquared.
 */
inline ad::physics::SpeedSquared operator*(ad::physics::ParametricValue const &p,
                                           ad::physics::SpeedSquared const &value)
{
  p.ensureValid();
  value.ensureValid();
  ad::physics::SpeedSquared result(p.mParametricValue * value.mSpeedSquared);
  result.restrictToLimitsAndEnsureValid();
  return result;
}

/*!
 * @brief Arithmetic physics operation value = value / p
 *
 * @param[in] value physics value
 * @param[in] p parametric value
 *
 * @returns value = value / p
 *
 * \note throws a std::out_of_range exception if one of the two operands is not valid or if the divisor is zero
 * \note The result is restricted to the limits of ad::physics::SpeedSquared.
 */
inline ad::physics::SpeedSquared operator/(ad::physics::SpeedSquared const &value,
                                           ad::physics::ParametricValue const &p)
{
  p.ensureValidNonZero();
  value.ensureValid();
  ad::physics::SpeedSquared result(value.mSpeedSquared / p.mParametricValue);
  result.restrictToLimitsAndEnsureValid();
  return result;
}

/* ##################  ad::physics::Weight  ################ */

/*!
 * @brief Arithmetic physics operation value = value * p
 *
 * @param[in] value physics value
 * @param[in] p parametric value
 *
 * @returns value = value * p
 *
 * \note throws a std::out_of_range exception if one of the two operands is not valid.
 * \note The result is restricted to the limits of ad::physics::Weight.
 */
inline ad::physics::Weight operator*(ad::physics::Weight const &value, ad::physics::ParametricValue const &p)
{
  p.ensureValid();
  value.ensureValid();
  ad::physics::Weight result(p.mParametricValue * value.mWeight);
  result.restrictToLimitsAndEnsureValid();
  return result;
}

/*!
 * @brief Arithmetic parametric operation value = p * value
 *
 * @param[in] p parametric value
 * @param[in] value physics value
 *
 * @returns value = p * value
 *
 * \note throws a std::out_of_range exception if one of the two operands is not valid.
 * \note The result is restricted to the limits of ad::physics::Weight.
 */
inline ad::physics::Weight operator*(ad::physics::ParametricValue const &p, ad::physics::Weight const &value)
{
  p.ensureValid();
  value.ensureValid();
  ad::physics::Weight result(p.mParametricValue * value.mWeight);
  result.restrictToLimitsAndEnsureValid();
  return result;
}

/*!
 * @brief Arithmetic physics operation value = value / p
 *
 * @param[in] value physics value
 * @param[in] p parametric value
 *
 * @returns value = value / p
 *
 * \note throws a std::out_of_range exception if one of the two operands is not valid or if the divisor is zero
 * \note The result is restricted to the limits of ad::physics::Weight.
 */
inline ad::physics::Weight operator/(ad::physics::Weight const &value, ad::physics::ParametricValue const &p)
{
  p.ensureValidNonZero();
  value.ensureValid();
  ad::physics::Weight result(value.mWeight / p.mParametricValue);
  result.restrictToLimitsAndEnsureValid();
  return result;
}
