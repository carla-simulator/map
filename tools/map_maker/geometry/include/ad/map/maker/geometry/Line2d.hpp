// ----------------- BEGIN LICENSE BLOCK ---------------------------------
//
// Copyright (C) 2018-2019 Intel Corporation
//
// SPDX-License-Identifier: MIT
//
// ----------------- END LICENSE BLOCK -----------------------------------

#pragma once

#include <ostream>
#include "ad/map/maker/geometry/Point2d.hpp"

namespace ad {
namespace map {
namespace maker {
namespace geometry {

/**
 * @struct Line2d
 * @brief Represents a line in a two dimensional space.
 *
 * A line is defined by specifying two points along the line. These two points must be different.
 * A line can be interpreted as an infinite line or as a line segment.
 * For infinite lines the two points specify only two points along the line, without specifying a start/end points.
 * In a line segment the two points act as vertex or endpoints.
 *
 *           < Infinite Line >
 *           Point A              Point B
 *...-----------0--------------------o---------------------------...
 *
 *           < Line segment >
 *            Point A             Point B
 *              0--------------------0
 *
 * The definition of line segment or infinite line plays a crucial role while verifying if the two lines intersect.
 * The intersection of line segments is constrained to the convex hull of the end points.
 * The intersection of infinite lines is not constrained at all.
 *
 * E.g. Lines intersection, (see the graph below):
 * In infinite line intersection the lines intersect at the "x" point.
 * In line segment intersection they don't intersect at all.
 * If line 1 is an infinite line and line 2 is a line segment, then there is no intersection.
 * If line 1 is a line segment and line 2 is an infinite line, then the line 2 intersects line 1.
 *
 *      Line 1
 *        0
 *        |      Line 2
 *        x  0----------------0
 *        |
 *        |
 *        0
 */
struct Line2d
{
  Line2d() = default;

  explicit Line2d(double x1, double y1, double x2, double y2);
  explicit Line2d(Point2d _pointA, Point2d _pointB);

  // Point along the line or endpoint of a line segment in Re^2
  Point2d pointA;
  // Point along the line or endpoint of a line segment in Re^2
  Point2d pointB;

  // Length of the line segment defined by the endpoints pointA and pointB.
  double length() const;

  /**
   * @brief Returns true if the line intersects with another line. (Lines are treated as infinite lines)
   */
  bool intersects(Line2d const &other) const;

  /**
   * @brief Returns true if the line intersects with another line.
   *
   * The intersection point is written to intersectionPoint.
   */
  bool intersects(Line2d const &other, Point2d &intersectionPoint) const;

  /**
   * @brief Returns true if the line intersects with a line segment.
   *
   * A line intersects with a segment only if the two segment endpoints
   * lie on different sides of the intersecting line.
   */
  bool segmentsIntersect(Line2d const &other) const;

  /**
   * @brief Returns true if the line intersects with a line segment.
   *
   * A line intersects with a segment only if the two segment endpoints
   * lie on different sides of the intersecting line.
   * The intersection point is written to intersectionPoint.
   */
  bool segmentsIntersect(Line2d const &other, Point2d &intersectionPoint) const;

  /**
   * @brief Treats the line as a segment and checks if it intersects with another segment.
   *
   * The end points of both segments must be on different sides of the intersecting line respectively.
   */
  bool lineIntersectsSegment(Line2d const &segment) const;

  /**
   * @brief Treats the line as a segment and checks if it intersects with another segment.
   *
   * The end points of both segments must be on different sides of the intersecting line respectively.
   * The intersection point is written to intersectionPoint.
   */
  bool lineIntersectsSegment(Line2d const &segment, Point2d &intersectionPoint) const;

  /**
   * @brief  Normal line intersection. The two lines are infinite lines that could intersect at any point.
   *
   * The intersection point is written to intersectionPoint.
   */
  static bool linesIntersect(Line2d const &lineA, Line2d const &lineB, Point2d &intersectionPoint);

  /**
   * @brief  Returns true if the line intersects a segment, i.e. the ends are on different side of the intersecting line
   *
   * One point is to the left and the other to the right
   */
  static bool lineIntersectsSegment(Line2d const &line, Line2d const &segment);

  /**
   * @brief  Returns true if the line intersects a segment, i.e. the ends are on different side of the intersecting line
   *
   * One point is to the left and the other to the right
   * The intersection point is written to intersectionPoint.
   */
  static bool lineIntersectsSegment(Line2d const &line, Line2d const &segment, Point2d &intersectionPoint);

  /**
   * @brief  Returns true if two segments intersect each other.
   *
   * Two segments AB and CD intersect if and only if:
   * - The end points A and B are on opposite sides of the line cd
   * - The endpoints of C and D are on opposite sides of the line ab
   */
  static bool segmentsIntersect(Line2d const &segmentA, Line2d const &segmentB);

  /**
   * @brief  Returns true if two segments intersect each other.
   *
   * Two segments AB and CD intersect if and only if:
   * - The end points A and B are on opposite sides of the line cd
   * - The endpoints of C and D are on opposite sides of the line ab
   * The intersection point is written to intersectionPoint.
   */
  static bool segmentsIntersect(Line2d const &segmentA, Line2d const &segmentB, Point2d &intersectionPoint);

  /**
   * @brief Projects the point on the provided line, the line is treated as an infinite line.
   * i.e.the projection can happen at any point on the infinite line.
   *
   * @param The point to be projected onto the line.
   * @returns the projection of the point on the line.
   */
  Point2d projectOnLine(Point2d const &point) const;

  /**
   * @brief Projects the point on the provided line, the line is treated as a segment.
   * i.e. the projection is constrained to the segment defined by the endpoints of the line.
   *
   * @param The point to be projected onto the line.
   * @returns the projection of the point on the line.
   */
  Point2d projectOnSegment(Point2d const &point) const;

  /**
   * @brief Projects the point on the provided line.
   *
   * @param The point to be projected onto the line.
   * @returns the magnitude of the point's projection on the line.
   */
  double lineProjection(Point2d const &point) const;
};

std::ostream &operator<<(std::ostream &out, Line2d const &line);

} // namespace geometry
} // namespace maker
} // namespace map
} // namespace ad
