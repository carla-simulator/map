// ----------------- BEGIN LICENSE BLOCK ---------------------------------
//
// Copyright (C) 2018-2021 Intel Corporation
//
// SPDX-License-Identifier: MIT
//
// ----------------- END LICENSE BLOCK -----------------------------------

#include "ad/map/point/GeometryOperation.hpp"

#include <algorithm>
#include <array>
#include <cmath>
#include <functional>
#include <mutex>
#include "ad/map/access/Logging.hpp"
#include "ad/map/access/Operation.hpp"
#include "ad/map/point/Operation.hpp"

namespace ad {
namespace map {
namespace point {

namespace {

std::mutex &getGeometryCacheMutex(Geometry const &geometry)
{
  static std::array<std::mutex, 64u> cacheMutexes;
  size_t const idx = std::hash<Geometry const *>{}(&geometry) % cacheMutexes.size();
  return cacheMutexes[idx];
}

ENUPointList const &ensureCachedENUPointListLocked(Geometry const &geometry)
{
  auto coordinateTransform = access::getCoordinateTransform();
  ENUPointCache &mutable_enuPointsCache = const_cast<Geometry *>(&geometry)->private_enu_points_cache;
  if (!coordinateTransform || geometry.private_enu_points_cache.enu_version != coordinateTransform->getENURef())
  {
    mutable_enuPointsCache.enu_points.clear();
  }
  if (geometry.private_enu_points_cache.enu_points.empty() && !geometry.ecef_points.empty())
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

} // namespace

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
  std::lock_guard<std::mutex> const lock(getGeometryCacheMutex(geometry));
  return ensureCachedENUPointListLocked(geometry);
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
  {
    std::lock_guard<std::mutex> const lock(getGeometryCacheMutex(geometry));
    ENUPointList const &enu_points = ensureCachedENUPointListLocked(geometry);
    outputPoints = point::getParametricRange(enu_points, geometry.length, trange);
  }
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
  point::ENUPoint search = pt;
  search.z = ENUCoordinate(0.);
  if (!isValid(search))
  {
    return physics::ParametricValue();
  }

  std::lock_guard<std::mutex> const lock(getGeometryCacheMutex(geometry));
  ENUPointList const &enu_points = ensureCachedENUPointListLocked(geometry);
  if (enu_points.empty())
  {
    return physics::ParametricValue();
  }
  if (enu_points.size() == 1u)
  {
    return physics::ParametricValue(0.);
  }

  double const sx = search.x.mENUCoordinate;
  double const sy = search.y.mENUCoordinate;

  physics::Distance totalLength(0.);
  physics::Distance runningOffset(0.);
  physics::Distance offsetNearest(0.);
  double dNearestSq = 0.;
  physics::Distance dNearest(0.);

  for (size_t i = 0u; i + 1u < enu_points.size(); ++i)
  {
    double const x0 = enu_points[i].x.mENUCoordinate;
    double const y0 = enu_points[i].y.mENUCoordinate;
    double const dx = enu_points[i + 1u].x.mENUCoordinate - x0;
    double const dy = enu_points[i + 1u].y.mENUCoordinate - y0;
    double const segLenSq = dx * dx + dy * dy;
    double const segLen = std::sqrt(segLenSq);
    physics::Distance const segDist(segLen);

    double const px = sx - x0;
    double const py = sy - y0;
    double t = 0.5;
    if (segLenSq > 0.)
    {
      t = std::min(1.0, std::max(0.0, (px * dx + py * dy) / segLenSq));
    }
    double const candDx = px - t * dx;
    double const candDy = py - t * dy;
    double const distSq = candDx * candDx + candDy * candDy;

    if (i == 0u)
    {
      dNearestSq = distSq;
      dNearest = physics::Distance(std::sqrt(distSq));
      offsetNearest = physics::Distance(t * segLen);
    }
    else if (distSq < dNearestSq)
    {
      physics::Distance const d(std::sqrt(distSq));
      if (d < dNearest)
      {
        dNearest = d;
        dNearestSq = distSq;
        offsetNearest = runningOffset + physics::Distance(t * segLen);
      }
    }

    runningOffset += segDist;
    totalLength += segDist;
  }

  if (totalLength == physics::Distance(0.))
  {
    return physics::ParametricValue(0.);
  }
  double const ratio = std::min(1.0, std::max(0.0, static_cast<double>(offsetNearest / totalLength)));
  return physics::ParametricValue(ratio);
}

template ECEFPoint vectorCrossProduct(ECEFPoint const &a, ECEFPoint const &b);
template double vectorDotProduct(ECEFPoint const &a, ECEFPoint const &b);
template ECEFPoint vectorMultiplyScalar(ECEFPoint const &a, double const &b);
template ECEFPoint vectorMultiplyScalar(ECEFPoint const &a, physics::Distance const &b);
template physics::Distance vectorLength(ECEFPoint const &a);
template ECEFPoint vectorNorm(ECEFPoint const &a);
template ECEFPoint vectorAdd(ECEFPoint const &a, ECEFPoint const &b);
template ECEFPoint vectorSub(ECEFPoint const &a, ECEFPoint const &b);
template ECEFPoint vectorInterpolate(ECEFPoint const &a, ECEFPoint const &b, physics::ParametricValue const &tparam);
template ECEFPoint vectorExtrapolate(ECEFPoint const &a, ECEFPoint const &b, double const &scalar);
template physics::Distance distance(ECEFPoint const &point, ECEFPoint const &other);
template physics::RatioValue findNearestPointOnEdge(ECEFPoint const &a, const ECEFPoint &pt0, const ECEFPoint &pt1);
template physics::ParametricValue
findNearestPointOnSegment(ECEFPoint const &a, const ECEFPoint &pt0, const ECEFPoint &pt1);
template physics::Distance calculateEdgeLength(ECEFPointList const &edge);
template physics::ParametricValueList getParametricEdgePoints(ECEFPointList const &edge);
template ECEFPoint
getParametricPoint(ECEFPointList const &edge, physics::Distance const &edgeLength, const physics::ParametricValue &t);
template ECEFPoint getParametricPoint(ECEFPointList const &edge, const physics::ParametricValue &t);
template ECEFPointList getParametricRange(ECEFPointList const &edge,
                                          physics::Distance const &edgeLength,
                                          const physics::ParametricRange &trange);
template ECEFPointList getParametricRange(ECEFPointList const &edge, const physics::ParametricRange &trange);
template physics::ParametricValue
findNearestPointOnEdge(ECEFPointList const &edge, physics::Distance const &edgeLength, const ECEFPoint &pt);
template physics::ParametricValue findNearestPointOnEdge(ECEFPointList const &edge, const ECEFPoint &pt);
template std::pair<physics::MetricRange, physics::Distance>
calculateWidthRange(ECEFPointList const &edge_left,
                    physics::Distance const &edgeLeftLength,
                    ECEFPointList const &edge_right,
                    physics::Distance const &edgeRightLength);
template ECEFPointList getLateralAlignmentEdge(ECEFPointList const &leftEdge,
                                               physics::Distance const &leftEdgeLength,
                                               ECEFPointList const &rightEdge,
                                               physics::Distance const &rightEdgeLength,
                                               physics::ParametricValue const lateral_alignment);
template ECEFPointList getLateralAlignmentEdge(ECEFPointList const &leftEdge,
                                               ECEFPointList const &rightEdge,
                                               physics::ParametricValue const lateral_alignment);
template ECEFPoint getEdgeStartDirectionalVector(ECEFPointList const &edge);
template ECEFPoint getEdgeEndDirectionalVector(ECEFPointList const &edge);

template ENUPoint vectorCrossProduct(ENUPoint const &a, ENUPoint const &b);
template double vectorDotProduct(ENUPoint const &a, ENUPoint const &b);
template ENUPoint vectorMultiplyScalar(ENUPoint const &a, double const &b);
template ENUPoint vectorMultiplyScalar(ENUPoint const &a, physics::Distance const &b);
template physics::Distance vectorLength(ENUPoint const &a);
template ENUPoint vectorNorm(ENUPoint const &a);
template ENUPoint vectorAdd(ENUPoint const &a, ENUPoint const &b);
template ENUPoint vectorSub(ENUPoint const &a, ENUPoint const &b);
template ENUPoint vectorInterpolate(ENUPoint const &a, ENUPoint const &b, physics::ParametricValue const &tparam);
template ENUPoint vectorExtrapolate(ENUPoint const &a, ENUPoint const &b, double const &scalar);
template physics::Distance distance(ENUPoint const &point, ENUPoint const &other);
template physics::RatioValue findNearestPointOnEdge(ENUPoint const &a, const ENUPoint &pt0, const ENUPoint &pt1);
template physics::ParametricValue
findNearestPointOnSegment(ENUPoint const &a, const ENUPoint &pt0, const ENUPoint &pt1);
template physics::Distance calculateEdgeLength(ENUPointList const &edge);
template physics::ParametricValueList getParametricEdgePoints(ENUPointList const &edge);
template ENUPoint
getParametricPoint(ENUPointList const &edge, physics::Distance const &edgeLength, const physics::ParametricValue &t);
template ENUPoint getParametricPoint(ENUPointList const &edge, const physics::ParametricValue &t);
template ENUPointList getParametricRange(ENUPointList const &edge,
                                         physics::Distance const &edgeLength,
                                         const physics::ParametricRange &trange);
template ENUPointList getParametricRange(ENUPointList const &edge, const physics::ParametricRange &trange);
template physics::ParametricValue
findNearestPointOnEdge(ENUPointList const &edge, physics::Distance const &edgeLength, const ENUPoint &pt);
template physics::ParametricValue findNearestPointOnEdge(ENUPointList const &edge, const ENUPoint &pt);
template std::pair<physics::MetricRange, physics::Distance>
calculateWidthRange(ENUPointList const &edge_left,
                    physics::Distance const &edgeLeftLength,
                    ENUPointList const &edge_right,
                    physics::Distance const &edgeRightLength);
template ENUPointList getLateralAlignmentEdge(ENUPointList const &leftEdge,
                                              physics::Distance const &leftEdgeLength,
                                              ENUPointList const &rightEdge,
                                              physics::Distance const &rightEdgeLength,
                                              physics::ParametricValue const lateral_alignment);
template ENUPointList getLateralAlignmentEdge(ENUPointList const &leftEdge,
                                              ENUPointList const &rightEdge,
                                              physics::ParametricValue const lateral_alignment);
template ENUPoint getEdgeStartDirectionalVector(ENUPointList const &edge);
template ENUPoint getEdgeEndDirectionalVector(ENUPointList const &edge);

} // namespace point
} // namespace map
} // namespace ad
