// ----------------- BEGIN LICENSE BLOCK ---------------------------------
//
// Copyright (C) 2018-2021 Intel Corporation
//
// SPDX-License-Identifier: MIT
//
// ----------------- END LICENSE BLOCK -----------------------------------

#include "ad/map/point/GeoOperation.hpp"
#include "ad/map/point/EdgeOperation.hpp"
#include "ad/map/point/Transform.hpp"

namespace ad {
namespace map {
namespace point {

Altitude const AltitudeUnknown = ::ad::map::point::Altitude::getMin();

struct CartesianCoordinate
{
  CartesianCoordinate(double const &value = 0.)
    : coordinate(value)
  {
  }
  double toBaseType() const
  {
    return coordinate;
  }
  operator double() const
  {
    return coordinate;
  }

  double coordinate;
};

struct CartesianCoordinates
{
  CartesianCoordinates() = default;
  CartesianCoordinate x;
  CartesianCoordinate y;
  CartesianCoordinate z;
};

/**
 * @brief Independent conversion to the cartesian system.
 */
CartesianCoordinates toCartesianCoordinates(GeoPoint const &point)
{
  double wgs84_r = CoordinateTransform::WGS84_R(point.latitude).mDistance;
  double lat_rad = CoordinateTransform::geocentricLatitude(point.latitude);
  double lon_rad = toRadians(point.longitude);

  double cos_lon = std::cos(lon_rad);
  double sin_lon = std::sin(lon_rad);
  double cos_lat = std::cos(lat_rad);
  double sin_lat = std::sin(lat_rad);
  CartesianCoordinates result;
  result.x = wgs84_r * cos_lon * cos_lat;
  result.y = wgs84_r * sin_lon * cos_lat;
  result.z = wgs84_r * sin_lat;

  double cos_glat = std::cos(toRadians(point.latitude));
  double sin_glat = std::sin(toRadians(point.latitude));

  result.x = result.x + point.altitude.mAltitude * cos_glat * cos_lon;
  result.y = result.y + point.altitude.mAltitude * cos_glat * sin_lon;
  result.z = result.z + point.altitude.mAltitude * sin_glat;

  return result;
}

physics::Distance distance(GeoPoint const &point, GeoPoint const &other)
{
  auto const pointCartesian = toCartesianCoordinates(point);
  auto const otherCartesian = toCartesianCoordinates(other);
  auto const delta = vectorSub(pointCartesian, otherCartesian);
  return vectorLength(delta);
}

GeoPoint zeroAltitude(GeoPoint const &point)
{
  GeoPoint pt(point);
  pt.altitude = Altitude(0);
  return pt;
}

physics::Distance flatDistance(GeoPoint const &point, GeoPoint const &other)
{
  return distance(zeroAltitude(point), zeroAltitude(other));
}

GeoPoint approxAltitude(GeoPoint const &point, const GeoPointList &pts)
{
  GeoPoint pt(zeroAltitude(point));
  if (pts.size() == 0)
  {
  }
  else if (pts.size() == 1)
  {
    pt.altitude = pts[0].altitude;
  }
  else
  {
    GeoPoint pt0(pts[0]);
    GeoPoint pt1(pts[1]);
    auto d0 = flatDistance(pt, pt0);
    auto d1 = flatDistance(pt, pt1);
    if (d0 > d1)
    {
      std::swap(pt0, pt1);
      std::swap(d0, d1);
    }
    for (size_t i = 2; i < pts.size(); i++)
    {
      auto const d = flatDistance(pt, pts[i]);
      if (d < d0)
      {
        pt1 = pt0;
        pt0 = pts[i];
        d1 = d0;
        d0 = d;
      }
      else if (d < d1)
      {
        pt1 = pts[i];
        d1 = d;
      }
    }
    auto const d01 = d0 + d1;
    if (d01 > physics::Distance(0.))
    {
      double t = d0 / d01;
      pt.altitude = (1 - t) * pt0.altitude + t * pt1.altitude;
    }
    else
    {
      pt.altitude = pt0.altitude;
    }
  }
  return pt;
}

bool isOnTheLeft(GeoPoint const &point, const GeoPoint &pt0, const GeoPoint &pt1)
{
  if ((pt1.longitude - pt0.longitude) == Longitude(0.))
  {
    if (point.longitude < pt1.longitude)
    {
      return pt1.latitude > pt0.latitude;
    }
    else if (point.longitude > pt1.longitude)
    {
      return pt1.latitude < pt0.latitude;
    }
  }
  else if ((pt1.latitude - pt0.latitude) == Latitude(0.))
  {
    if (point.latitude < pt1.latitude)
    {
      return pt1.longitude < pt0.longitude;
    }
    else if (point.latitude > pt1.latitude)
    {
      return pt1.longitude > pt0.longitude;
    }
  }
  else
  {
    auto const slope
      = physics::RatioValue((pt1.latitude - pt0.latitude).mLatitude / (pt1.longitude - pt0.longitude).mLongitude);
    if (slope != physics::RatioValue(0.))
    {
      double yi = pt0.latitude.mLatitude - pt0.longitude.mLongitude * slope.mRatioValue;
      double cs = (slope.mRatioValue * point.longitude.mLongitude) + yi;
      if (point.latitude.mLatitude > cs)
      {
        return pt1.longitude > pt0.longitude;
      }
      if (point.latitude.mLatitude < cs)
      {
        return pt1.longitude < pt0.longitude;
      }
    }
  }
  return false;
}

bool haveSameOrientation(const GeoPointList &pts0, const GeoPointList &pts1)
{
  if (pts0.size() > 1 && pts1.size() > 1)
  {
    auto const front_front = distance(pts0.front(), pts1.front());
    auto const front_back = distance(pts0.front(), pts1.back());
    return front_front < front_back;
  }
  else
  {
    return false;
  }
}

bool isOnTheLeft(const GeoPointList &pts0, const GeoPointList &pts1)
{
  if (pts0.size() > 1 && pts1.size() > 1)
  {
    return isOnTheLeft(pts0.front(), pts1[0], pts1[1]);
  }
  else
  {
    return false;
  }
}

physics::Distance calcLength(GeoPointList const &pts)
{
  return calculateEdgeLength(pts);
}

} // namespace point
} // namespace map
} // namespace ad
