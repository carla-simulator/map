// ----------------- BEGIN LICENSE BLOCK ---------------------------------
//
// Copyright (C) 2018-2019 Intel Corporation
//
// SPDX-License-Identifier: MIT
//
// ----------------- END LICENSE BLOCK -----------------------------------

#include "ad/map/maker/geometry/Polyline2d.hpp"
#include <ad/map/maker/common/LogChannel.hpp>
#include <cmath>
#include <cstdint>
#include "ad/map/maker/geometry/Direction2d.hpp"

namespace ad {
namespace map {
namespace maker {
namespace geometry {

Point2d shiftPointOrthogonalToDirection(const Point2d &point, const Direction2d &direction, const double &distance)
{
  Direction2d shiftDirection = direction;
  shiftDirection.orientation += M_PI / 2.;
  return shiftDirection.movePoint(point, distance);
}

double Polyline2d::length() const
{
  double result{};
  for (uint32_t i = 1; i < points.size(); i++)
  {
    result += std::sqrt(points[i - 1].squaredDistance(points[i]));
  }

  return result;
}

bool Polyline2d::shift(const double distStart,
                       double const distEnd,
                       Polyline2d &shiftedPolyline,
                       common::LogChannel &logChannel) const
{
  if (points.size() < 2)
  {
    return false;
  }

  double totalLength = length();
  double deltaDist = distEnd - distStart;
  double traveledDistance{};

  // shift first point orthogonal to direction from first to second point
  Direction2d direction(points[0], points[1]);
  Point2d newPoint = shiftPointOrthogonalToDirection(points[0], direction, distStart);
  shiftedPolyline.points.push_back(newPoint);

  // all other points shift by bisecting between the two line segments
  for (uint32_t i = 1; i < points.size() - 1; i++)
  {
    traveledDistance += sqrt(points[i - 1].squaredDistance(points[i]));
    double fractionMoved = traveledDistance / totalLength;
    double baseDistance = distStart + (deltaDist * fractionMoved);

    // calculate bisecting angle
    const Direction2d directionBefore(points[i - 1], points[i]);
    const Direction2d directionAfter(points[i], points[i + 1]);
    const Direction2d shiftDirection = directionBefore.bisectionAngle(directionAfter);

    // shift point in shiftDirection with distance * scalingFactor
    // where scalingFactor is 1/sin(angle between shiftDirection and first line segment)
    double scaling = std::sin(shiftDirection.orientation - directionBefore.orientation);
    if (scaling < 0.001)
    {
      logChannel(common::LogLevel::Warning)
        << " segment have a bisection angle close to 180 degree, value is "
        << (shiftDirection.orientation - directionBefore.orientation) * 180. / M_PI << " limiting scaling to 0.01\n";
      scaling = 0.01;
    }

    newPoint = shiftDirection.movePoint(points[i], (baseDistance / scaling));
    shiftedPolyline.points.push_back(newPoint);
  }

  // shift last point orthogonal to direction from second-to-last to last point
  direction = Direction2d(points[points.size() - 2], points[points.size() - 1]);
  newPoint = shiftPointOrthogonalToDirection(points[points.size() - 1], direction, distEnd);
  shiftedPolyline.points.push_back(newPoint);

  return hasSimilarDirection(shiftedPolyline, M_PI_2 + 0.09, logChannel); /* allow up to 90 degree deviation */
}

bool Polyline2d::shift(const double distance, Polyline2d &shiftedPolyline, common::LogChannel &logChannel) const
{
  return shift(distance, distance, shiftedPolyline, logChannel);
}

bool Polyline2d::hasSimilarDirection(Polyline2d const &other,
                                     double const allowedDifference,
                                     common::LogChannel &logChannel) const
{
  if (points.size() != other.points.size())
  {
    logChannel(common::LogLevel::Warning) << "Polyline2d::isInSameDirection different number of points\n";
    return false;
  }

  bool result = true;
  for (uint32_t p = 1u; p < points.size(); ++p)
  {
    const Direction2d myDirection(points[p - 1], points[p]);
    const Direction2d otherDirection(other.points[p - 1], other.points[p]);
    // normalize orientation to [-PI .. PI] to allow comparison by subtraction
    double myOrientation = myDirection.orientation;
    if (myOrientation > M_PI)
    {
      myOrientation -= 2. * M_PI;
    }
    double otherOrientation = otherDirection.orientation;
    if (otherOrientation > M_PI)
    {
      otherOrientation -= 2. * M_PI;
    }

    double const actualDifference = std::abs(myOrientation - otherOrientation);
    if (actualDifference > allowedDifference)
    {
      logChannel(common::LogLevel::Info) << "Polyline2d::isInSameDirection difference of orientation of points "
                                         << p - 1 << ", " << p << " execeeds limit " << actualDifference << " vs "
                                         << allowedDifference << "\n";
      logChannel(common::LogLevel::Info) << "  Orientation: " << myOrientation << " other: " << otherOrientation
                                         << "\n";
      result = false;
    }
  }

  return result;
}

bool Polyline2d::intersectsWithLine(Line2d const &line) const
{
  uint32_t intersectIndex;
  Point2d intersectionPoint;
  return intersectsWithLine(line, intersectIndex, intersectionPoint);
}

bool Polyline2d::intersectsWithLine(Line2d const &line, uint32_t &intersectIndex, Point2d &intersectionPoint) const
{
  for (uint32_t k = 0; k < points.size() - 1; k++)
  {
    const auto &pointA = points[k];
    const auto &pointB = points[k + 1];
    if (Line2d::lineIntersectsSegment(line, Line2d(pointA, pointB), intersectionPoint))
    {
      intersectIndex = k;
      return true;
    }
  }

  return false;
}

bool Polyline2d::splitPolyline(Polyline2d &firstPart, Polyline2d &secondPart, Line2d const &splittingLine) const
{
  if (points.size() < 2)
  {
    return false;
  }

  uint32_t intersectionIndex{0u};
  Point2d intersectionPoint;

  if (intersectsWithLine(splittingLine, intersectionIndex, intersectionPoint))
  {
    firstPart.points.clear();
    secondPart.points.clear();

    if (intersectionPoint == points.front() || intersectionPoint == points.back())
    {
      // Intersect with first or the end point does not split the polyline
      return false;
    }

    for (uint32_t k = 0; k <= intersectionIndex; k++)
    {
      firstPart.points.push_back(points[k]);
    }
    if (intersectionPoint != points[intersectionIndex])
    {
      firstPart.points.push_back(intersectionPoint);
      secondPart.points.push_back(intersectionPoint);
    }
    for (uint32_t k = intersectionIndex + 1; k < points.size(); k++)
    {
      secondPart.points.push_back(points[k]);
    }
    return true;
  }
  return false;
}

Point2d Polyline2d::findNearestPoint(Point2d const &point) const
{
  if (points.size() < 2)
  {
    return Point2d{0., 0.};
  }

  auto nearestPoint = Line2d{points[0], points[1]}.projectOnSegment(point);
  auto nearestDistance = point.squaredDistance(nearestPoint);

  for (uint32_t k = 1; k + 1 < points.size(); k++)
  {
    auto projectedPoint = Line2d{points[k], points[k + 1]}.projectOnSegment(point);
    auto distance = point.squaredDistance(projectedPoint);
    if (distance < nearestDistance)
    {
      nearestDistance = distance;
      nearestPoint = projectedPoint;
    }
  }

  return nearestPoint;
}

std::size_t Polyline2d::indexOfClosestPoint(Point2d const &point) const
{
  std::size_t result = 0u;
  double closestDistance = points[0].squaredDistance(point);
  for (std::size_t index = 0u; index < points.size(); ++index)
  {
    double dist = points[index].squaredDistance(point);
    if (dist < closestDistance)
    {
      closestDistance = dist;
      result = index;
    }
  }
  return result;
}

double Polyline2d::subLength(std::size_t index) const
{
  double distance{0.};
  if (index > points.size() - 1)
  {
    index = points.size() - 1;
  }

  for (std::size_t i = 0u; i < index; ++i)
  {
    distance += std::sqrt(points[i].squaredDistance(points[i + 1]));
  }
  return distance;
}

} // namespace geometry
} // namespace maker
} // namespace map
} // namespace ad
