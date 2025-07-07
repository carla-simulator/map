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

#include <ad/geometry/Types.hpp>
#include <ad/physics/Types.hpp>

/*!
 * @brief namespace ad
 */
namespace ad {
/*!
 * @brief namespace geometry
 */
namespace geometry {

/**
 * @brief convert a trajectory set to a polygon
 *
 * @param[in] trajectorySet trajectory set to convert
 * @param[out] polygon converted polygon
 */
void toPolygon(::ad::physics::Distance2DList const &trajectorySet, ad::geometry::Polygon &polygon);

/**
 * @brief convert a list of points to a polygon
 *
 * @param[in] pointVector point vector to convert
 * @param[out] polygon converted polygon
 */
void toPolygon(::ad::geometry::PointVector const &pointVector, ad::geometry::Polygon &polygon);

/**
 * @brief convert a polygon to a trajectory set
 *
 * @param[in] polygon polygon to convert
 * @param[out] trajectorySet converted trajectory set
 */
void toTrajectorySet(ad::geometry::Polygon const &polygon, ::ad::physics::Distance2DList &trajectorySet);

/**
 * @brief rotate a point around another point
 *
 * @param[in] origin         absolute origin
 * @param[in] relativePoint  point to rotate, relative to origin
 * @param[in] angle          angle to rotate the point
 *
 * @returns rotated point
 */
Point rotateAroundPoint(ad::geometry::Point const &origin,
                        ad::geometry::Point const &relativePoint,
                        physics::Angle const &angle);

/**
 * @brief calculate a point on a circle
 *
 * @param[in] origin absolute origin
 * @param[in] radius radius of circle
 * @param[in] angle  angle to rotate the point
 *
 * @returns resulting point
 */
Point getPointOnCircle(ad::geometry::Point const &origin, physics::Distance const &radius, physics::Angle const &angle);

/**
 * @brief calculate the circle origin
 *
 * @param[in] point  point on circle
 * @param[in] radius radius of circle
 * @param[in] angle  circle angle for point
 *
 * @returns circle origin
 */
Point getCircleOrigin(ad::geometry::Point const &point, physics::Distance const &radius, physics::Angle const &angle);

/**
 * @brief check if two trajectory sets collide
 *
 * @param[in]  trajectorySet1 first trajectory set
 * @param[in]  trajectorySet2 second trajectory set
 *
 * @returns true if trajectory sets collide, otherwise false
 */
bool collides(::ad::physics::Distance2DList const &trajectorySet1, ::ad::physics::Distance2DList const &trajectorySet2);

/**
 * @brief Combine two polygons
 *
 * @param[in]  a       polygon a
 * @param[in]  b       polygon b
 * @param[out] result  resulting polygon
 *
 * @returns false if a failure occurred during calculations, true otherwise
 */
bool combinePolygon(ad::geometry::Polygon const &a, ad::geometry::Polygon const &b, ad::geometry::Polygon &result);

/**
 * @brief calculate points on a circle arc
 *
 * @param[in]  origin   absolute origin
 * @param[in]  radius   radius of circle
 * @param[in]  from     starting angle
 * @param[in]  delta    angle of the arc
 * @param[out] geometry geometry the calculated points are added to
 */
template <typename T>
void calculateCircleArc(Point origin,
                        physics::Distance const &radius,
                        physics::Angle const &from,
                        physics::Angle const &delta,
                        physics::Angle const &stepWidth,
                        T &geometry)
{
  physics::Angle currentAngle = from;
  physics::Angle maxAngle = currentAngle + delta;
  while (currentAngle <= maxAngle)
  {
    boost::geometry::append(geometry, getPointOnCircle(origin, radius, currentAngle));
    currentAngle += stepWidth;
  }
  if (currentAngle - stepWidth != maxAngle)
  {
    boost::geometry::append(geometry, getPointOnCircle(origin, radius, maxAngle));
  }
}

/**
 * @brief check if an angle is within a range
 *
 * @param[in] angle angle to check
 * @param[in] range heading range
 *
 * @returns true if inside angle range, otherwise false
 */
bool isInsideHeadingRange(physics::Angle const &angle, geometry::HeadingRange const &range);

/**
 * @brief get the overlap between two angle ranges
 *
 * @param[in]  a            first heading range
 * @param[in]  b            second heading range
 * @param[out] overlapRange overlapping heading ranges
 *
 * @returns true if overlap exists, otherwise false
 */
bool getHeadingOverlap(geometry::HeadingRange const &a,
                       geometry::HeadingRange const &b,
                       geometry::HeadingRangeVector &overlapRanges);

/**
 * @brief get the overlap between an angle range and a heading range
 *
 * @param[in]    headingRange angle range
 * @param[inout] overlapRanges overlapping heading ranges
 *
 * @returns true if overlap exists, otherwise false
 */
bool getHeadingOverlap(geometry::HeadingRange const &headingRange, geometry::HeadingRangeVector &overlapRanges);

} // namespace geometry
} // namespace ad
