// ----------------- BEGIN LICENSE BLOCK ---------------------------------
//
// Copyright (C) 2018-2019 Intel Corporation
//
// SPDX-License-Identifier: MIT
//
// ----------------- END LICENSE BLOCK -----------------------------------

#include "ad/map/maker/geometry/Line2d.hpp"
#include <cmath>
#include <limits>

namespace ad {
namespace map {
namespace maker {
namespace geometry {

Line2d::Line2d(double x1, double y1, double x2, double y2)
{
  pointA = Point2d(x1, y1);
  pointB = Point2d(x2, y2);
}

Line2d::Line2d(Point2d _pointA, Point2d _pointB)
{
  pointA = _pointA;
  pointB = _pointB;
}

double Line2d::length() const
{
  return sqrt(pointA.squaredDistance(pointB));
}

bool Line2d::intersects(Line2d const &other) const
{
  Point2d intersectionPoint;
  return linesIntersect(*this, other, intersectionPoint);
}

bool Line2d::intersects(Line2d const &other, Point2d &intersectionPoint) const
{
  return linesIntersect(*this, other, intersectionPoint);
}

bool Line2d::lineIntersectsSegment(Line2d const &segment) const
{
  Point2d intersectionPoint;
  return lineIntersectsSegment(*this, segment, intersectionPoint);
}

bool Line2d::lineIntersectsSegment(Line2d const &segment, Point2d &intersectionPoint) const
{
  return lineIntersectsSegment(*this, segment, intersectionPoint);
}

bool Line2d::segmentsIntersect(Line2d const &other) const
{
  Point2d intersectionPoint;
  return segmentsIntersect(*this, other, intersectionPoint);
}

bool Line2d::segmentsIntersect(Line2d const &other, Point2d &intersectionPoint) const
{
  return segmentsIntersect(*this, other, intersectionPoint);
}

bool Line2d::linesIntersect(Line2d const &lineA, Line2d const &lineB, Point2d &intersectionPoint)
{
  auto &p1 = lineA.pointA;
  auto &p2 = lineA.pointB;
  auto &p3 = lineB.pointA;
  auto &p4 = lineB.pointB;

  // Calculate intersection point
  auto px_num = (p1.x * p2.y - p1.y * p2.x) * (p3.x - p4.x) - (p1.x - p2.x) * (p3.x * p4.y - p3.y * p4.x);
  auto py_num = (p1.x * p2.y - p1.y * p2.x) * (p3.y - p4.y) - (p1.y - p2.y) * (p3.x * p4.y - p3.y * p4.x);
  auto det = (p1.x - p2.x) * (p3.y - p4.y) - (p1.y - p2.y) * (p3.x - p4.x);

  if (det == 0.0)
  {
    return false;
  }

  intersectionPoint.x = px_num / det;
  intersectionPoint.y = py_num / det;

  return true;
}

bool Line2d::lineIntersectsSegment(Line2d const &line, Line2d const &segment)
{
  auto &p1 = line.pointA;
  auto &p2 = line.pointB;

  auto &s1 = segment.pointA;
  auto &s2 = segment.pointB;

  double distanceToPointA = (s1.x - p1.x) * (p2.y - p1.y) - (s1.y - p1.y) * (p2.x - p1.x);
  double distanceToPointB = (s2.x - p1.x) * (p2.y - p1.y) - (s2.y - p1.y) * (p2.x - p1.x);

  if (distanceToPointA * distanceToPointB > 0)
  {
    // Both points are on the same side of the line
    // The case when the distance is zero means that at least one of the points lies on the line.
    // We will also consider this as an intersection
    // Other degenerate cases such as two overlapping segments is not address here.
    return false;
  }
  // The points lie on different sides of the line
  return true;
}

bool Line2d::lineIntersectsSegment(Line2d const &line, Line2d const &segment, Point2d &intersectionPoint)
{
  if (!lineIntersectsSegment(line, segment))
  {
    return false;
  }
  return linesIntersect(line, segment, intersectionPoint);
}

bool Line2d::segmentsIntersect(Line2d const &segmentA, Line2d const &segmentB)
{
  if (lineIntersectsSegment(segmentA, segmentB) && lineIntersectsSegment(segmentB, segmentA))
  {
    return true;
  }
  return false;
}

bool Line2d::segmentsIntersect(Line2d const &segmentA, Line2d const &segmentB, Point2d &intersectionPoint)
{
  if (!segmentsIntersect(segmentA, segmentB))
  {
    return false;
  }

  return linesIntersect(segmentA, segmentB, intersectionPoint);
}

Point2d Line2d::projectOnLine(Point2d const &point) const
{
  double t = lineProjection(point);
  return (1 - t) * pointA + t * pointB;
}

Point2d Line2d::projectOnSegment(Point2d const &point) const
{
  double t = lineProjection(point);
  if (t >= 1.0)
  {
    return pointB;
  }
  if (t <= 0.0)
  {
    return pointA;
  }

  return (1 - t) * pointA + t * pointB;
}

double Line2d::lineProjection(Point2d const &point) const
{
  double deltaX = pointB.x - pointA.x;
  double deltaY = pointB.y - pointA.y;
  double dx = point.x - pointA.x;
  double dy = point.y - pointA.y;
  double den = deltaX * deltaX + deltaY * deltaY;
  if (den > std::numeric_limits<double>::epsilon())
  {
    double num = dx * deltaX + dy * deltaY;
    return num / den;
  }
  else
  {
    return 0.5;
  }
}

std::ostream &operator<<(std::ostream &out, Line2d const &line)
{
  return out << "line[" << line.pointA << ", " << line.pointB << ", length:" << line.length() << " m]";
}

} // namespace geometry
} // namespace maker
} // namespace map
} // namespace ad
