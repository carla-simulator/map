// ----------------- BEGIN LICENSE BLOCK ---------------------------------
//
// Copyright (C) 2017-2019 Intel Corporation
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
 * @class LineCoordinateSystem
 * @brief define local coordinate system given by two points in 2d space
 */
class LineCoordinateSystem
{
  //! origin of the local coordinate system
  Point2d mStart;
  //! _end_ of the local coordinate system, i.e. points _behind_ mEnd are considered to be invalid
  Point2d mEnd;
  //! orientation of the coordinate system defined by the line |mStart, mEnd|
  double mDirection;
  //! cached cosine value to avoid recalculation on each call to projectToLineCoordinateSystem
  double mCos;
  //! cached sine value to avoid recalculation on each call to projectToLineCoordinateSystem
  double mSin;
  //! length of line |mStart, mEnd|
  double mDistance;

public:
  LineCoordinateSystem(Point2d const &startPoint, Point2d const &endPoint);

  /**
   * @brief represent given point with coordinates of the local coordinate system
   * @param point
   * @return position of point relative to local coordinate system
   *
   * Calculate position of point in coordinate system defined by the line
   * mStart2d, mEnd.
   */
  Point2d projectToLineCoordinateSystem(Point2d const &point) const;

  /**
   * @return true if the orthogonal projection of point is on the line |mStart, mEnd|
   *
   * First transform the point into the local coordinate system using \ref projectToLineCoordinateSystem
   * and than call this function
   */
  bool pointIsInsideSegment(Point2d const &point, double epsilon) const;

  double length() const
  {
    return mDistance;
  }
};

} // namespace geometry
} // namespace maker
} // namespace map
} // namespace ad
