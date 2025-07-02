// ----------------- BEGIN LICENSE BLOCK ---------------------------------
//
// Copyright (C) 2018-2021 Intel Corporation
//
// SPDX-License-Identifier: MIT
//
// ----------------- END LICENSE BLOCK -----------------------------------

#include "ad/map/point/GeometryOperation.hpp"

#include <algorithm>
#include "ad/map/access/Logging.hpp"
#include "ad/map/access/Operation.hpp"
#include "ad/map/point/Operation.hpp"

namespace ad {
namespace map {
namespace point {

Geometry createGeometry(const ECEFPointList &points, bool closed)
{
  Geometry geometry;
  geometry.is_closed = closed;
  geometry.ecef_points = points;
  geometry.private_enu_points_cache.enu_version = 0;
  geometry.is_valid = (points.size() >= 2) && isValid(points);
  geometry.length = calcLength(points);
  return geometry;
}

ENUPointList getCachedENUPointList(Geometry const &geometry)
{
  auto coordinateTransform = access::getCoordinateTransform();
  ENUPointCache &mutable_enuPointsCache = const_cast<Geometry *>(&geometry)->private_enu_points_cache;
  if (!coordinateTransform || geometry.private_enu_points_cache.enu_version != coordinateTransform->getENURef())
  {
    mutable_enuPointsCache.enu_points.clear();
  }
  if (geometry.private_enu_points_cache.enu_points.empty())
  {
    if (coordinateTransform)
    {
      if (coordinateTransform->isENUValid())
      {
        mutable_enuPointsCache.enu_version = coordinateTransform->getENURef();
        coordinateTransform->convert(geometry.ecef_points, mutable_enuPointsCache.enu_points);
      }
      else
      {
        access::getLogger()->error("Geometry::GetENU: ENU Reference Point not defined.");
      }
    }
    else
    {
      access::getLogger()->error("Geometry::GetENU: Coordinate transformations not defined.");
    }
  }
  return geometry.private_enu_points_cache.enu_points;
}

/////////////
// Operations

bool isSuccessor(Geometry const &geometry, const Geometry &other)
{
  if (geometry.ecef_points.empty() || other.ecef_points.empty())
  {
    return false;
  }
  else if (geometry.ecef_points.front() == other.ecef_points.back())
  {
    return true;
  }
  else if (geometry.ecef_points.back() == other.ecef_points.back())
  {
    return true;
  }
  else
  {
    return false;
  }
}

bool isPredecessor(Geometry const &geometry, const Geometry &other)
{
  if (geometry.ecef_points.empty() || other.ecef_points.empty())
  {
    return false;
  }
  else if (geometry.ecef_points.front() == other.ecef_points.front())
  {
    return true;
  }
  else if (geometry.ecef_points.back() == other.ecef_points.front())
  {
    return true;
  }
  else
  {
    return false;
  }
}

bool haveSameStart(Geometry const &geometry, const Geometry &other)
{
  if (geometry.ecef_points.empty() || other.ecef_points.empty())
  {
    return false;
  }
  else
  {
    return geometry.ecef_points.front() == other.ecef_points.front();
  }
}

bool haveSameEnd(Geometry const &geometry, const Geometry &other)
{
  if (geometry.ecef_points.empty() || other.ecef_points.empty())
  {
    return false;
  }
  else
  {
    return geometry.ecef_points.back() == other.ecef_points.back();
  }
}

point::ECEFPoint getParametricPoint(Geometry const &geometry, const physics::ParametricValue &t)
{
  return point::getParametricPoint(geometry.ecef_points, geometry.length, t);
}

void getParametricRange(Geometry const &geometry,
                        const physics::ParametricRange &trange,
                        ECEFPointList &outputPoints,
                        const bool revertOrder)
{
  outputPoints = point::getParametricRange(geometry.ecef_points, geometry.length, trange);
  if (revertOrder)
  {
    std::reverse(outputPoints.begin(), outputPoints.end());
  }
}

void getParametricRange(Geometry const &geometry,
                        const physics::ParametricRange &trange,
                        GeoPointList &outputPoints,
                        const bool revertOrder)
{
  ECEFPointList const ecef_points = point::getParametricRange(geometry.ecef_points, geometry.length, trange);
  outputPoints = toGeo(ecef_points);
  if (revertOrder)
  {
    std::reverse(outputPoints.begin(), outputPoints.end());
  }
}

void getParametricRange(Geometry const &geometry,
                        const physics::ParametricRange &trange,
                        ENUPointList &outputPoints,
                        const bool revertOrder)
{
  outputPoints = point::getParametricRange(getCachedENUPointList(geometry), geometry.length, trange);
  if (revertOrder)
  {
    std::reverse(outputPoints.begin(), outputPoints.end());
  }
}

ECEFPointList getMiddleEdge(Geometry const &geometry, Geometry const &other)
{
  return point::getLateralAlignmentEdge(
    geometry.ecef_points, geometry.length, other.ecef_points, other.length, physics::ParametricValue(0.5));
}

physics::ParametricValue findNearestPointOnEdge(Geometry const &geometry, const point::ECEFPoint &pt)
{
  return findNearestPointOnEdge(geometry.ecef_points, geometry.length, pt);
}

physics::ParametricValue findNearestPointOnEdgeIgnoreZ(Geometry const &geometry, const point::ENUPoint &pt)
{
  auto enu_points = getCachedENUPointList(geometry);
  for (auto &point : enu_points)
  {
    point.z = ENUCoordinate(0.);
  }
  auto search = pt;
  search.z = ENUCoordinate(0.);
  return findNearestPointOnEdge(enu_points, search);
}

} // namespace point
} // namespace map
} // namespace ad
