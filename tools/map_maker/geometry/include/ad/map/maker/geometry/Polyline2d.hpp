// ----------------- BEGIN LICENSE BLOCK ---------------------------------
//
// Copyright (C) 2018-2019 Intel Corporation
//
// SPDX-License-Identifier: MIT
//
// ----------------- END LICENSE BLOCK -----------------------------------

#pragma once

#include <vector>
#include "ad/map/maker/geometry/Line2d.hpp"
#include "ad/map/maker/geometry/Point2d.hpp"

namespace ad {
namespace map {
namespace maker {

namespace common {
struct LogChannel;
} // namespace common

namespace geometry {

struct Polyline2d
{
  /**
   * List of 2d points that describe the polyline
   */
  std::vector<Point2d> points;

  /**
   * @brief calculate total length of polyline
   */
  double length() const;

  /**
   * @brief shift this polyline by distance to the left (w.r.t. direction of polyline)
   *
   * Interpolate the shifted distance between distStart and distEnd
   *
   *            y  x
   *            |  |      x---x-- = original polyline
   *   y->---y--y  |      y---y-- = shiftedPolyline
   *               |          ">" = direction of polyline
   *   x->---x-->--x
   *
   * @param distStart the polyline should be shifted by distStart at the beginning
   * @param distEnd the polyline should be shifted by distEnd at the end
   * @param shiftedPolyline, is the resulting polyline
   * @param logChannel used for logging
   */
  bool shift(const double distStart,
             double const distEnd,
             Polyline2d &shiftedPolyline,
             common::LogChannel &logChannel) const;

  /**
   * @brief shift this polyline by distance to the left (w.r.t. direction of polyline)
   *
   *            y  x
   *            |  |      x---x-- = original polyline
   *   y->---y--y  |      y---y-- = shiftedPolyline
   *               |          ">" = direction of polyline
   *   x->---x-->--x
   *
   * @param distance the polyline should be shifted
   * @param shiftedPolyline, is the resulting polyline
   */
  bool shift(const double distance, Polyline2d &shiftedPolyline, common::LogChannel &logChannel) const;

  /**
   * @brief Does the other polyline have the same direction as self?
   * @param other polyline to be checked
   * @param allowedDifference allowed difference in orientation in [rad]
   * @return true if the other polyline has the same direction
   *
   * other must have the same number of points
   *
   * Check if the generated polyline is in the same direction. For very narrow curves, the direction of the generated
   * polyline may be flipped. For example if the polyline is along an arc with radius R and the shift _distance_ is
   * greater than R then the resulting polyline is not in the same direction.
   * Another way to look at the problem is as follows: given the polyline and its shifted comrade, for each
   * line between each point of the polyline and its corresponding point in the shifted polyline there should be no
   * intersections between those lines:
   *
   * B----C
   * |    ~
   * |    ~
   * A~~~~X~~~~A'
   *      ~ ~
   *      ~   ~
   *      C'   B'
   *
   * Here, a.g. |CC'| intersects with |BB'|, "A,B,C" is the polyine, "A',B',C'" is the shifted polyine.
   */
  bool
  hasSimilarDirection(Polyline2d const &other, double const allowedDifference, common::LogChannel &logChannel) const;

  /**
   * @brief Iterates over the polyline's segments and checks wether the polyline intersects with any of them.
   */
  bool intersectsWithLine(Line2d const &line) const;

  /**
   * @brief Iterates over the polyline's segments and checks wether the polyline intersects with any of them.
   *
   * When the line intersects a segment the function returns true, intersectionIndex and intersectionPoint
   * will contain the information of where the intersection occurred.
   */
  bool intersectsWithLine(Line2d const &line, uint32_t &intersectIndex, Point2d &intersectionPoint) const;

  /**
   * @brief Iterates over the polyline's segments and splits the polyline on the first intersection encountered with the
   * splitting line.
   */
  bool splitPolyline(Polyline2d &firstPart, Polyline2d &secondPart, Line2d const &splittingLine) const;

  /**
   * @brief Finds a point on the polyline's geometry that is closest to the given point
   *
   * @param point 2d point of interest
   * @returns the projection of the point on the polyline.
   */
  Point2d findNearestPoint(Point2d const &point) const;

  /**
   * @return index of point which has smallest distance to given point
   */
  std::size_t indexOfClosestPoint(Point2d const &point) const;

  /**
   * @return length of polyline up to (including) point with given index
   */
  double subLength(std::size_t index) const;
};

} // namespace geometry
} // namespace maker
} // namespace map
} // namespace ad
