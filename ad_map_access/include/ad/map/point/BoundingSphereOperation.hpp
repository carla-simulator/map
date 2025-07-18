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

#include "ad/map/point/BoundingSphere.hpp"
#include "ad/map/point/ECEFOperation.hpp"
#include "ad/map/point/Geometry.hpp"

/**
 * @brief calculate the union of two BoundingSpheres
 *
 * @param[in] a BoundingSphere a
 * @param[in] b BoundingSphere b
 *
 * @returns union BoundingSpere containing both: a U b
 */
::ad::map::point::BoundingSphere operator+(::ad::map::point::BoundingSphere const &a,
                                           ::ad::map::point::BoundingSphere const &b);

/** @brief namespace ad */
namespace ad {
/** @brief namespace map */
namespace map {
/** @brief namespace point */
namespace point {

/**
 * @brief Computes distance between BoundingSpheres.
 * @returns Distance between two bounding spheres in meters.
 */
inline physics::Distance distance(BoundingSphere const &left, BoundingSphere const &right)
{
  physics::Distance const distanceCenter = distance(left.center, right.center);
  return std::max(physics::Distance(0.), distanceCenter - left.radius - right.radius);
}

/**
 * @brief calculate the bounding sphere of two edges
 */
BoundingSphere calcBoundingSphere(Geometry const &edge_left, Geometry const &edge_right);

/**
 * @brief Computes union of BoundingSpheres.
 *
 * @param[in] a BoundingSphere a
 * @param[in] b BoundingSphere b
 *
 * @returns union BoundingSpere containing both: a U b
 */
inline BoundingSphere getUnion(BoundingSphere const &left, BoundingSphere const &right)
{
  return left + right;
}

} // namespace point
} // namespace map
} // namespace ad
