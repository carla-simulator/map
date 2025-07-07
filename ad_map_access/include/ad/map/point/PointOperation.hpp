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

#include <cmath>

#include "ad/map/point/ECEFCoordinateOperation.hpp"
#include "ad/map/point/ENUCoordinateOperation.hpp"
#include "ad/physics/Distance.hpp"
#include "ad/physics/ParametricValue.hpp"
#include "ad/physics/RatioValue.hpp"

/** @brief namespace ad */
namespace ad {
/** @brief namespace map */
namespace map {
/** @brief namespace point */
namespace point {

/**
 * @brief calculate the cross product of two vectors
 *
 * @param[in] a vector a
 * @param[in] b vector b
 *
 * @returns vector c = a x b
 */
template <typename PointType> PointType vectorCrossProduct(PointType const &a, PointType const &b)
{
  PointType result;
  result.x = a.y * b.z - a.z * b.y;
  result.y = a.z * b.x - a.x * b.z;
  result.z = a.x * b.y - a.y * b.x;
  return result;
}

/**
 * @brief calculate the dot product of two vectors
 *
 * @param[in] a vector a
 * @param[in] b vector b
 *
 * @returns value d = a * b
 */
template <typename PointType> double vectorDotProduct(PointType const &a, PointType const &b)
{
  return a.x.toBaseType() * b.x.toBaseType() + a.y.toBaseType() * b.y.toBaseType()
    + a.z.toBaseType() * b.z.toBaseType();
}

/**
 * @brief multiplies a vector with a scalar
 * @param[in] a vector a
 * @param[in] b scalar b
 */
template <typename PointType> PointType vectorMultiplyScalar(PointType const &a, double const &b)
{
  PointType result;
  result.x = a.x * b;
  result.y = a.y * b;
  result.z = a.z * b;
  return result;
}

/**
 * @brief multiplies a vector with a scalar
 * @param[in] a vector a
 * @param[in] b scalar b
 */
template <typename PointType> PointType vectorMultiplyScalar(PointType const &a, physics::Distance const &b)
{
  return vectorMultiplyScalar(a, b.mDistance);
}

/**
 * @brief calculate the length of a vector
 *
 * @param[in] a vector a
 *
 * @returns value d = |a|
 */
template <typename PointType> physics::Distance vectorLength(PointType const &a)
{
  physics::Distance const length(std::sqrt(vectorDotProduct(a, a)));
  return length;
}

/**
 * @brief normalizes a vector
 *
 * @param[in] a vector a
 *
 * @returns vector c = a  / |a|
 */
template <typename PointType> PointType vectorNorm(PointType const &a)
{
  physics::Distance const length = vectorLength(a);
  if (length > physics::Distance(0.))
  {
    PointType result;
    result.x = a.x / length;
    result.y = a.y / length;
    result.z = a.z / length;
    return result;
  }
  return a;
}

/**
 * @brief add two vectors
 *
 * @param[in] a vector a
 * @param[in] b vector b
 *
 * @returns vector c = a + b
 */
template <typename PointType> PointType vectorAdd(PointType const &a, PointType const &b)
{
  PointType result;
  result.x = a.x + b.x;
  result.y = a.y + b.y;
  result.z = a.z + b.z;
  return result;
}

/**
 * @brief subtract two vectors from each right
 *
 * @param[in] a vector a
 * @param[in] b vector b
 *
 * @returns c = a - b
 */
template <typename PointType> PointType vectorSub(PointType const &a, PointType const &b)
{
  PointType result;
  result.x = a.x - b.x;
  result.y = a.y - b.y;
  result.z = a.z - b.z;
  return result;
}

/**
 * @brief Interpolates point between two points.
 *
 * @param[in] a vector a
 * @param[in] b vector b
 * @param[in] tparam Between 0 and 1.
 *
 * @returns Point between point a and b.
 *          with tparam==0, it will return point a;
 *          with tparam==1, it will return point b.
 */
template <typename PointType>
PointType vectorInterpolate(PointType const &a, PointType const &b, physics::ParametricValue const &tparam)
{
  return vectorExtrapolate(a, b, tparam.mParametricValue);
}

/**
 * @brief Interpolates point between two points.
 *
 * @param[in] a vector a
 * @param[in] b vector b
 * @param[in] tratio Ratio value.
 *
 * @returns Point between point a and b if tratio is in interval [0., 1.].
 *          with tratio==0, it will return point a;
 *          with tratio==1, it will return point b.
 *          Point before point a
 *          with tratio<0.
 *          Point after point b
 *          with tratio<1.
 *
 */
template <typename PointType>
PointType vectorInterpolate(PointType const &a, PointType const &b, physics::RatioValue const &tratio)
{
  return vectorExtrapolate(a, b, tratio.mRatioValue);
}

/**
 * @brief Extrapolate point based on line defined by two points.
 *
 * @param[in] a vector a
 * @param[in] b vector b
 * @param[in] scalar scalar value
 *
 * @returns Points extrapolated using point a and b.
 *          with scalar==0, it will return point a;
 *          with scalar==1, it will return point b.
 */
template <typename PointType> PointType vectorExtrapolate(PointType const &a, PointType const &b, double const &scalar)
{
  PointType result;
  result.x = (1 - scalar) * a.x + scalar * b.x;
  result.y = (1 - scalar) * a.y + scalar * b.y;
  result.z = (1 - scalar) * a.z + scalar * b.z;
  return result;
}

/**
 * @brief Computes distance between two points.
 * @returns Distance between two points in meters.
 */
template <typename PointType> physics::Distance distance(PointType const &point, PointType const &other)
{
  return vectorLength(vectorSub(point, other));
}

} // namespace point
} // namespace map
} // namespace ad
