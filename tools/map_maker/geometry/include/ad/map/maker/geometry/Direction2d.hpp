// ----------------- BEGIN LICENSE BLOCK ---------------------------------
//
// Copyright (C) 2018-2019 Intel Corporation
//
// SPDX-License-Identifier: MIT
//
// ----------------- END LICENSE BLOCK -----------------------------------

#pragma once

#include "ad/map/maker/geometry/Point2d.hpp"

namespace ad {
namespace map {
namespace maker {
namespace geometry {

/**
 * @brief represent a normalized vector in the x-y plane
 *
 * Angles are counter-clock-wise with an angle of zero degree
 * pointing along the positive x-axis
 *
 * Check: does it make sense to cache sin,cos? e.g. for movePoint?
 */
struct Direction2d
{
  //! orientation explicitely given
  explicit Direction2d(double const _orientation);

  //! derive orientation of vector from origin to _point_
  explicit Direction2d(Point2d const &point);

  //! derive orientation described by the line segment |start,end|
  explicit Direction2d(Point2d const &start, Point2d const &end);

  //! create a new point by moving the given point in the direction of the vector (with given distance/scaling)
  Point2d movePoint(Point2d const &point, double const distance) const;

  /**
   * @brief calculate bisection between this and the other
   * @param other
   * @return bisection angle
   *
   *
   *                     C
   *                     |
   *                     |
   *                 X   |
   *                  \  |
   *                   \ |
   *                    \|
   * A-------------------B
   *                      \
   *                       \
   *                        \
   *                         Z
   *
   * Assume, "this" represents the orientation of |AB| and "other" represents |BC|. The result is the
   * direction of |BX|. If the order is reversed, i.e. "this" = |CB|, "other| = |BA|, the result is |BZ|
   *
   * Calculation: [orientation of (vector(this) + vector(other))] + 90 degree. For the example above, assume
   * |AB|, |BC| are normalized vectors, we get a new point |AB| + |BC|, thus:
   * Direction2d bisection(|AB| + |BC|);
   * and rotate by 90 degree
   * bisection.orientation += 90 degree;
   */
  Direction2d bisectionAngle(Direction2d const &other) const;

  //! create a point/vector that represents the current orientation, that is [ sin(angle), cos(angle ] ^ T
  Point2d orientationAsPoint() const;

  //! normalize orientation such that it is 0 <= orientation <= 2 * PI
  void normalize();

  //! orientation in radians, 0 (zero) is along x-axis in positive direction (going to the right)
  double orientation{};
};

//! return radians for degree
double degToRad(double angle);

//! return degree for radians
double radToDeg(double angle);

//! @return direction orthogonal to the line |from,to|
Direction2d orthogonalDirection(Point2d const &from, Point2d const &to);

//! normalize orientation such that it is 0 <= orientation <= 2 * PI
double normalizeAngle(double orientation);

/**
 * @return Calculate the bisecting angle defined by the three given points
 *
 * @see Direction2d::bisectionAngle for an explanation
 */
Direction2d bisectionAngle(Point2d const &before, Point2d const &center, Point2d const &after);

/*!
 * \brief Calculates the minimum (signed) angle difference between two angles.
 *
 */
double minimumAngleDifference(double first, double second);

/**
 * @brief Perform a shifting on the center point by calculating the shifting angle using the points before and after.
 * @param before Reference point to be used for calculating the bisecting angle.
 * @param center The point to be shifted.
 * @param after Reference point to be used for calculating the bisecting angle.
 * @param distance Shifting distance.
 * @return The center point shifted in the bisecting angle direction by the given distance.
 */
Point2d threePointShift(Point2d const &before, Point2d const &center, Point2d const &after, double const distance);

/**
 * @brief Perform a shifting on a point by calculating an orthogonal shift given a reference point.
 * @param point The point to be shifted.
 * @param reference Reference point to be used for calculating the orthogonal angle.
 * @param distance Shifting distance.
 * @return The given point shifted orthogonal to |point - reference| direction..
 */
Point2d twoPointShift(Point2d const &point, Point2d const &reference, double const distance);

/**
 * @brief Perform a shifting on a point by calculating an orthogonal shift given an orientation reference.
 * @param point The point to be shifted.
 * @param orientation Orientation to be used as reference for an orthogonal shift.
 * @param distance Shifting distance.
 * @return The given point shifted orthogonal to the given orientation.
 */
Point2d orthogonalShift(Point2d const &point, double const orientation, double const distance);

} // namespace geometry
} // namespace maker
} // namespace map
} // namespace ad
