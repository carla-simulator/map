// ----------------- BEGIN LICENSE BLOCK ---------------------------------
//
// Copyright (C) 2018-2021 Intel Corporation
//
// SPDX-License-Identifier: MIT
//
// ----------------- END LICENSE BLOCK -----------------------------------

#include "ad/map/point/Transform.hpp"

#include "ad/map/access/Operation.hpp"
#include "ad/map/point/Operation.hpp"

namespace ad {
namespace map {
namespace point {

ECEFPoint toECEF(ENUPoint const &point, GeoPoint const &enu_reference_point)
{
  if (access::getCoordinateTransform()->isGeoProjectionValid())
  {
    return toECEF(point);
  }
  else
  {
    CoordinateTransform coordinateTransform;
    coordinateTransform.setENUReferencePoint(enu_reference_point);
    return coordinateTransform.ENU2ECEF(point);
  }
}

GeoPoint toGeo(ENUPoint const &point, GeoPoint const &enu_reference_point)
{
  if (access::getCoordinateTransform()->isGeoProjectionValid())
  {
    return toGeo(point);
  }
  else
  {
    CoordinateTransform coordinateTransform;
    coordinateTransform.setENUReferencePoint(enu_reference_point);
    return coordinateTransform.ENU2Geo(point);
  }
}

ENUPoint toENU(ECEFPoint const &point, GeoPoint const &enu_reference_point)
{
  if (access::getCoordinateTransform()->isGeoProjectionValid())
  {
    return toENU(point);
  }
  else
  {
    CoordinateTransform coordinateTransform;
    coordinateTransform.setENUReferencePoint(enu_reference_point);
    return coordinateTransform.ECEF2ENU(point);
  }
}

ENUPoint toENU(GeoPoint const &point, GeoPoint const &enu_reference_point)
{
  if (access::getCoordinateTransform()->isGeoProjectionValid())
  {
    return toENU(point);
  }
  else
  {
    CoordinateTransform coordinateTransform;
    coordinateTransform.setENUReferencePoint(enu_reference_point);
    return coordinateTransform.Geo2ENU(point);
  }
}

ECEFPointList toECEF(ENUPointList const &edge, GeoPoint const &enu_reference_point)
{
  if (access::getCoordinateTransform()->isGeoProjectionValid())
  {
    return toECEF(edge);
  }
  else
  {
    CoordinateTransform coordinateTransform;
    coordinateTransform.setENUReferencePoint(enu_reference_point);
    ECEFPointList resultEdge;
    coordinateTransform.convert(edge, resultEdge);
    return resultEdge;
  }
}

GeoPointList toGeo(ENUPointList const &edge, GeoPoint const &enu_reference_point)
{
  if (access::getCoordinateTransform()->isGeoProjectionValid())
  {
    return toGeo(edge);
  }
  else
  {
    CoordinateTransform coordinateTransform;
    coordinateTransform.setENUReferencePoint(enu_reference_point);
    GeoPointList resultEdge;
    coordinateTransform.convert(edge, resultEdge);
    return resultEdge;
  }
}

ENUPointList toENU(ECEFPointList const &edge, GeoPoint const &enu_reference_point)
{
  if (access::getCoordinateTransform()->isGeoProjectionValid())
  {
    return toENU(edge);
  }
  else
  {
    CoordinateTransform coordinateTransform;
    coordinateTransform.setENUReferencePoint(enu_reference_point);
    ENUPointList resultEdge;
    coordinateTransform.convert(edge, resultEdge);
    return resultEdge;
  }
}

ENUPointList toENU(GeoPointList const &edge, GeoPoint const &enu_reference_point)
{
  if (access::getCoordinateTransform()->isGeoProjectionValid())
  {
    return toENU(edge);
  }
  else
  {
    CoordinateTransform coordinateTransform;
    coordinateTransform.setENUReferencePoint(enu_reference_point);
    ENUPointList resultEdge;
    coordinateTransform.convert(edge, resultEdge);
    return resultEdge;
  }
}

} // namespace point
} // namespace map
} // namespace ad
