// ----------------- BEGIN LICENSE BLOCK ---------------------------------
//
// Copyright (C) 2018-2019 Intel Corporation
//
// SPDX-License-Identifier: MIT
//
// ----------------- END LICENSE BLOCK -----------------------------------

#pragma once

#include <ostream>
#include "ad/map/maker/geometry/Point.hpp"

namespace ad {
namespace map {
namespace maker {
namespace geometry {

/*!
 * \brief Straigh line represented as Ax + By + C = 0
 */
struct straight2d
{
  double A{0.0};
  double B{0.0};
  double C{0.0};
};

/*!
 * \brief 2-dimensional Cartesian space vector
 *
 * TODO move into separate class
 */
struct vec2d
{
  explicit vec2d(double x_, double y_);
  explicit vec2d(Point const &first, Point const &second);
  explicit vec2d(double const len, double const suv1x, double const suv1y);

  double x{0.0};
  double y{0.0};

  double length() const;
  void scale(double const factor);
  void normalize();

  std::string toString() const;
};

std::ostream &operator<<(std::ostream &out, vec2d const &p);

/*!
 * \brief 2-dimensional Cartesian space circle represented as center point and radius
 */
struct circle2d
{
  Point center;
  double radius;
};

/*!
 * \brief "Human understandable" side definition
 */
enum class Side
{
  LEFT,
  RIGHT
};
// needed?

/**
 * \brief An unit vector along X axis
 */
vec2d const xVersor();

/**
 * \brief An unit vector along Y axis
 */
vec2d const yVersor();

/*!
 * \brief A binary operation on two vectors in three-dimensional space.
 * Given two linearly independent vectors u and v, the cross product, u × v, is a vector that is perpendicular to both
 * u and v and thus normal to the plane containing them.
 */
double cross_product(vec2d const &u, vec2d const &v);
// needed?

/*!
 * \brief An algebraic operation that takes two vectors and returns a single number.
 * The dot product, u · v, is the sum of the products of the corresponding dimension magnitudes of given vectors
 */
double dot_product(vec2d const &u, vec2d const &v);
// needed?

/*!
 * \brief Returns an absolute angle value in radians between two vectors.
 * The returned value is in range 0 ... PI
 */
double angle(vec2d const &u, vec2d const &v);
// needed?

/*!
 * \brief Returns the directed angle value in radians between two vectors.
 * The returned value is in range -PI ... PI
 *
 * \return 0 ... PI if rotation from u to v is counter-clockwise, -PI ... 0 otherwise
 */
double directedAngle(vec2d const &u, vec2d const &v);

/*!
 * \brief Returns the directed angle value in radians between X axis and straight going through given two points.
 * The returned value is in range -PI ... PI
 *
 * \return 0 ... PI if rotation from u to v is counter-clockwise, -PI ... 0 otherwise
 */
double directedAngle(Point const &a, Point const &b);

/*!
 * \brief Generates a vector rotated by 90 degrees to the given one either to left or right.
 * The length of a resulting vector is by default 1.0
 *
 * For given vector:
 *
 *  *----->
 *       a
 *
 * The resulting vector is either:
 *
 *  ^
 *  |
 *  |
 *  *----->  or:  *----->
 *       a        |    a
 *                |
 *                v
 */
vec2d rotated90Vector(vec2d const &v, Side const side, double const len = 1.0);

/*!
 * \brief Generates a vector rotated by a half angle value between two given vectors.
 *
 * For given vectors:
 *
 * ^ a
 *  \
 *   \
 *    *----->
 *         b
 * The resulting vector is either:
 *
 * ^ a   ^           ^ a
 *  \   /    or:      \
 *   \ /               \
 *    *----->           *----->
 *         b           /     b
 *                    /
 *                   v
 */
// same as below but with SIDE right
vec2d bisectingVector(vec2d const &u, vec2d const &v, double const len);
vec2d bisectingVector(vec2d const &u, vec2d const &v, Side const side, double const len);

/*!
 * \brief Rotates a 2d vector counter-clockwise by 90 degrees.
 */
void rotate90CounterClockwise(vec2d &v);

/*!
 * \brief Rotates a 2d vector clockwise by 90 degrees.
 */
void rotate90Clockwise(vec2d &v);

/*!
 * \brief Rotates a 2d vector by 180 degrees.
 */
void rotate180(vec2d &v);

/*!
 * \brief Rotates a 2d vector by a given directed angle.
 */
void rotate(double angle, vec2d &v);
// make part of class

/*!
 * \brief Generates a rotated Point around origin by given directed angle.
 */
Point rotated(Point const &origin, double theta, Point const &pt);

/*!
 * \brief Returns a distance between two points.
 */
double distance(Point const &p1, Point const &p2);

/*!
 * \brief Moves a point by a given offset vector.
 */
void move(vec2d const &offset, Point &pt);
// rework: make part of vec2d, and return a Point

/*!
 * \brief Generates a vector that is perpendicular to straight line going through given points with given length and
 * rotated to given side.
 */
vec2d rotated90OffsetVector(Point const &first, Point const &second, double const laneWidth, Side const side);

/*!
 * \brief Returns coefficients of a straight going through given two points.
 */
straight2d lineCoefs(Point const &first, Point const &second);

/*!
 * \brief Returns coefficients of a straight going through given two points shifted to a give side by a given offset
 */
straight2d parallelShiftedLineCoefs(Point first, Point second, double const laneWidth, Side const side);

/*!
 * \brief Moves a straight line by a given vector
 */
void move(vec2d const &offset, straight2d &straight);

/*!
 * \brief Checks whether two straight lines  have a crossing point.
 */
bool haveCrossingPoint(straight2d first, straight2d second);

/*!
 * \brief Returns a crossing point of two given straight lines.
 */
Point crossingPoint(straight2d first, straight2d second);

/*!
 * \brief Returns a crossing point of a ray going through a circle. The point is a closer to beginning of a ray crossing
 * point.
 */
Point closerCrossingPoint(Point const &a, Point const &b, circle2d const &c);

} // namespace geometry
} // namespace maker
} // namespace map
} // namespace ad
