// ----------------- BEGIN LICENSE BLOCK ---------------------------------
//
// Copyright (C) 2018-2019 Intel Corporation
//
// SPDX-License-Identifier: MIT
//
// ----------------- END LICENSE BLOCK -----------------------------------

#include "ad/map/maker/geometry/LineCoordinateSystem.hpp"
#include <cmath>
#include "ad/map/maker/geometry/Direction2d.hpp"

namespace ad {
namespace map {
namespace maker {
namespace geometry {

LineCoordinateSystem::LineCoordinateSystem(Point2d const &startPoint, Point2d const &endPoint)
  : mStart(startPoint)
  , mEnd(endPoint)
  , mDirection(-Direction2d(mStart, mEnd).orientation)
  , mCos(std::cos(mDirection))
  , mSin(std::sin(mDirection))
  , mDistance(projectToLineCoordinateSystem(mEnd).x + 0.1)
{
}

Point2d LineCoordinateSystem::projectToLineCoordinateSystem(Point2d const &point) const
{
  Point2d Z = point - mStart;
  Point2d result;
  result.x = mCos * Z.x - mSin * Z.y;
  result.y = mSin * Z.x + mCos * Z.y;
  return result;
}

bool LineCoordinateSystem::pointIsInsideSegment(Point2d const &point, double epsilon) const
{
  if ((point.x < -epsilon) || (point.x > (mDistance + epsilon)))
  {
    return false;
  }
  return true;
}

} // namespace geometry
} // namespace maker
} // namespace map
} // namespace ad
