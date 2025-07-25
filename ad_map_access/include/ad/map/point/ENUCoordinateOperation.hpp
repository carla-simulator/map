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

#include "ad/map/point/ENUCoordinate.hpp"
#include "ad/physics/Distance.hpp"

/**
 * @brief multiplies a ENUCoordinate with a scalar
 * @param[in] a coordinate a
 * @param[in] b scalar b
 */
inline ::ad::map::point::ENUCoordinate operator*(::ad::map::point::ENUCoordinate const &a,
                                                 ::ad::physics::Distance const &b)
{
  return a * b.mDistance;
}

/**
 * @brief multiplies a ENUCoordinate with a scalar
 * @param[in] b scalar b
 * @param[in] a coordinate a
 */
inline ::ad::map::point::ENUCoordinate operator*(::ad::physics::Distance const &b,
                                                 ::ad::map::point::ENUCoordinate const &a)
{
  return a * b.mDistance;
}

/**
 * @brief division of a ECEFCoordinate by a scalar
 * @param[in] a coordinate a
 * @param[in] b scalar b
 */
inline ::ad::map::point::ENUCoordinate operator/(::ad::map::point::ENUCoordinate const &a,
                                                 ::ad::physics::Distance const &b)
{
  return a / b.mDistance;
}

/**
 * @brief multiplies ENUCoordinate
 * @param[in] a coordinate a
 * @param[in] b coordinate b
 */
inline ::ad::map::point::ENUCoordinate operator*(::ad::map::point::ENUCoordinate const &a,
                                                 ::ad::map::point::ENUCoordinate const &b)
{
  return a * b.mENUCoordinate;
}
