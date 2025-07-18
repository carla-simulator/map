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

#include "ad/map/point/ECEFCoordinate.hpp"
#include "ad/physics/Distance.hpp"

/**
 * @brief multiplies a ECEFCoordinate with a scalar
 * @param[in] a coordinate a
 * @param[in] b scalar b
 */
inline ::ad::map::point::ECEFCoordinate operator*(::ad::map::point::ECEFCoordinate const &a,
                                                  ::ad::physics::Distance const &b)
{
  return a * b.mDistance;
}

/**
 * @brief multiplies a ECEFCoordinate with a scalar
 * @param[in] b scalar b
 * @param[in] a coordinate a
 */
inline ::ad::map::point::ECEFCoordinate operator*(::ad::physics::Distance const &b,
                                                  ::ad::map::point::ECEFCoordinate const &a)
{
  return a * b.mDistance;
}

/**
 * @brief division of a ECEFCoordinate by a scalar
 * @param[in] a coordinate a
 * @param[in] b scalar b
 */
inline ::ad::map::point::ECEFCoordinate operator/(::ad::map::point::ECEFCoordinate const &a,
                                                  ::ad::physics::Distance const &b)
{
  return a / b.mDistance;
}

/**
 * @brief multiplies ECEFCoordinates
 * @param[in] a coordinate a
 * @param[in] b coordinate b
 */
inline ::ad::map::point::ECEFCoordinate operator*(::ad::map::point::ECEFCoordinate const &a,
                                                  ::ad::map::point::ECEFCoordinate const &b)
{
  return a * b.mECEFCoordinate;
}
