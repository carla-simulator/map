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

#include "ad/geometry/GeometryOperation.hpp"
#include <algorithm>
#include <cmath>
#include <limits>
#include "ad/physics/Operation.hpp"

/*!
 * @brief namespace ad
 */
namespace ad {
/*!
 * @brief namespace geometry
 */
namespace geometry {

physics::Distance getDistance(geometry::Point const &point1, geometry::Point const &point2)
{
  auto const directionalVector = point1 - point2;
  return physics::Distance(sqrt(boost::geometry::dot_product(directionalVector, directionalVector)));
}

void splitLineAtIntersectionPoint(geometry::Point const &intersectionPoint,
                                  geometry::Line const &line,
                                  Line &before,
                                  geometry::Line &after)
{
  auto *currentSection = &before;
  for (auto it = line.begin(); it != line.end(); ++it)
  {
    auto const pt = *it;
    boost::geometry::append(*currentSection, *it);
    if (((it + 1) != line.end()) && (currentSection != &after))
    {
      auto const nextPt = *(it + 1);
      auto const pt2intersection = intersectionPoint - pt;
      auto const nextPt2intersection = intersectionPoint - nextPt;
      if (boost::geometry::dot_product(pt2intersection, nextPt2intersection) < 0.)
      {
        boost::geometry::append(*currentSection, intersectionPoint);
        currentSection = &after;
        boost::geometry::append(*currentSection, intersectionPoint);
      }
    }
  }
}

Point rotateAroundPoint(ad::geometry::Point const &origin,
                        ad::geometry::Point const &relativePoint,
                        physics::Angle const &angle)
{
  Point resultPoint = relativePoint;

  boost::geometry::strategy::transform::rotate_transformer<boost::geometry::radian, double, 2, 2> rotate(-angle.mAngle);
  boost::geometry::strategy::transform::translate_transformer<double, 2, 2> translate(origin.x(), origin.y());
  boost::geometry::transform(resultPoint, resultPoint, rotate);
  boost::geometry::transform(resultPoint, resultPoint, translate);
  return resultPoint;
}

Point getPointOnCircle(ad::geometry::Point const &origin, physics::Distance const &radius, physics::Angle const &angle)
{
  return origin + toPoint(std::cos(angle) * radius, std::sin(angle) * radius);
}

Point getCircleOrigin(ad::geometry::Point const &point, physics::Distance const &radius, physics::Angle const &angle)
{
  return point - toPoint(std::cos(angle) * radius, std::sin(angle) * radius);
}

void toPolygon(::ad::physics::Distance2DList const &trajectorySet, ad::geometry::Polygon &polygon)
{
  for (auto const &distance : trajectorySet)
  {
    ::boost::geometry::append(polygon, toPoint(distance));
  }
  ::boost::geometry::correct(polygon);
}

void toPolygon(::ad::geometry::PointVector const &pointVector, ad::geometry::Polygon &polygon)
{
  ::boost::geometry::append(polygon, pointVector);
  ::boost::geometry::correct(polygon);
}

void toTrajectorySet(ad::geometry::Polygon const &polygon, ::ad::physics::Distance2DList &trajectorySet)
{
  for (auto const &point : polygon.outer())
  {
    trajectorySet.push_back(toDistance(point));
  }
}

bool collides(::ad::physics::Distance2DList const &trajectorySet1, ::ad::physics::Distance2DList const &trajectorySet2)
{
  ad::geometry::Polygon polygon1;
  ad::geometry::Polygon polygon2;
  toPolygon(trajectorySet1, polygon1);
  toPolygon(trajectorySet2, polygon2);
  return !boost::geometry::disjoint(polygon1, polygon2);
}

bool combinePolygon(ad::geometry::Polygon const &a, ad::geometry::Polygon const &b, ad::geometry::Polygon &result)
{
  if (a.outer().empty() && !b.outer().empty())
  {
    result = b;
  }
  else if (!a.outer().empty() && b.outer().empty())
  {
    result = a;
  }
  else
  {
    std::vector<ad::geometry::Polygon> unionPolygons;
    boost::geometry::union_(a.outer(), b.outer(), unionPolygons);
    if (unionPolygons.size() != 1)
    {
      auto fixed = false;
      if (unionPolygons.size() == 0)
      {
        // if union reports zero polygons, it might happen that one polygon is covered by the other
        auto aCoveredByB = true;
        for (auto it = a.outer().cbegin(); (it != a.outer().cend()) && aCoveredByB; ++it)
        {
          aCoveredByB &= boost::geometry::covered_by(*it, b.outer());
        }
        if (aCoveredByB)
        {
          fixed = true;
          result = b;
        }
        if (!fixed)
        {
          auto bCoveredByA = true;
          for (auto it = b.outer().cbegin(); (it != b.outer().cend()) && bCoveredByA; ++it)
          {
            bCoveredByA &= boost::geometry::covered_by(*it, a.outer());
          }
          if (bCoveredByA)
          {
            fixed = true;
            result = a;
          }
        }
      }
      if (!fixed)
      {
        spdlog::warn("Could not calculate combined polygon. Expected 1 polygon after union, found {}. A:\n{}\nB:\n{}",
                     unionPolygons.size(),
                     std::to_string(a),
                     std::to_string(b));
        return false;
      }
    }
    else
    {
      result = std::move(unionPolygons[0]);
    }
  }
  return true;
}

bool isInsideHeadingRange(physics::Angle const &angle, geometry::HeadingRange const &range)
{
  if (range.end >= range.begin)
  {
    return (angle >= range.begin) && (angle <= range.end);
  }
  else
  {
    return (angle >= range.begin) || (angle <= range.end);
  }
}

bool getHeadingOverlap(geometry::HeadingRange const &a,
                       geometry::HeadingRange const &b,
                       geometry::HeadingRangeVector &overlapRanges)
{
  bool aStartsInB = isInsideHeadingRange(a.begin, b);
  bool aEndsInB = isInsideHeadingRange(a.end, b);
  bool bStartsInA = isInsideHeadingRange(b.begin, a);
  bool bEndsInA = isInsideHeadingRange(b.end, a);

  auto overlaps = aStartsInB || aEndsInB || bStartsInA || bEndsInA;

  if (overlaps)
  {
    geometry::HeadingRange range;
    if (aStartsInB && aEndsInB && bStartsInA && bEndsInA)
    {
      if (!((a.begin == b.begin) && (a.end == b.end)))
      {
        geometry::HeadingRange secondRange;
        secondRange.begin = a.begin;
        secondRange.end = b.end;
        overlapRanges.push_back(secondRange);
      }
      range.begin = b.begin;
      range.end = a.end;
    }
    else if (aStartsInB && aEndsInB)
    {
      range.begin = a.begin;
      range.end = a.end;
    }
    else if (bStartsInA && bEndsInA)
    {
      range.begin = b.begin;
      range.end = b.end;
    }
    else if (aStartsInB && !aEndsInB)
    {
      range.begin = a.begin;
      range.end = b.end;
    }
    else if (bStartsInA && !bEndsInA)
    {
      range.begin = b.begin;
      range.end = a.end;
    }
    overlapRanges.push_back(range);
    return true;
  }
  return false;
}

bool getHeadingOverlap(geometry::HeadingRange const &headingRange, geometry::HeadingRangeVector &overlapRanges)
{
  geometry::HeadingRangeVector newOverlapRanges;
  if (overlapRanges.empty())
  {
    newOverlapRanges.push_back(headingRange);
  }
  else
  {
    for (auto const &range : overlapRanges)
    {
      getHeadingOverlap(headingRange, range, newOverlapRanges);
    }
  }
  overlapRanges = newOverlapRanges;
  return !overlapRanges.empty();
}
} // namespace geometry
} // namespace ad
