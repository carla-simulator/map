// ----------------- BEGIN LICENSE BLOCK ---------------------------------
//
// Copyright (C) 2018-2021 Intel Corporation
//
// SPDX-License-Identifier: MIT
//
// ----------------- END LICENSE BLOCK -----------------------------------
/**
 * @file
 */

#pragma once

#include "ad/map/access/Operation.hpp"
#include "ad/map/point/CoordinateTransform.hpp"
#include "ad/map/point/Types.hpp"

/** @brief namespace ad */
namespace ad {
/** @brief namespace map */
namespace map {
/** @brief namespace point */
namespace point {

/**
 * @brief perform coordinate transformation from GeoPoint to ECEFPoint
 */
inline ECEFPoint toECEF(GeoPoint const &point)
{
  return access::getCoordinateTransform()->Geo2ECEF(point);
}

/**
 * @brief perform coordinate transformation from ENUPoint to ECEFPoint
 *
 * The transformation into ENU coordinate frame makes use of the globally set ENUReferencePoint
 * (see AdMapAccess::setENUReferencePoint())
 */
inline ECEFPoint toECEF(ENUPoint const &point)
{
  return access::getCoordinateTransform()->ENU2ECEF(point);
}

/**
 * @brief perform coordinate transformation from ENUPoint to ECEFPoint
 *
 * The transformation into ENU coordinate frame makes use of the provided enu_reference_point
 */
ECEFPoint toECEF(ENUPoint const &point, GeoPoint const &enu_reference_point);

/**
 * @brief perform coordinate transformation from ECEFPoint to GeoPoint
 */
inline GeoPoint toGeo(ECEFPoint const &point)
{
  return access::getCoordinateTransform()->ECEF2Geo(point);
}

/**
 * @brief perform coordinate transformation from ENUPoint to GeoPoint
 *
 * The transformation into ENU coordinate frame makes use of the globally set ENUReferencePoint
 * (see AdMapAccess::setENUReferencePoint())
 */
inline GeoPoint toGeo(ENUPoint const &point)
{
  return access::getCoordinateTransform()->ENU2Geo(point);
}

/**
 * @brief perform coordinate transformation from ENUPoint to GeoPoint
 *
 * The transformation into ENU coordinate frame makes use of the provided enu_reference_point
 */
GeoPoint toGeo(ENUPoint const &point, GeoPoint const &enu_reference_point);

/**
 * @brief perform coordinate transformation from ECEFPoint to ENUPoint
 *
 * The transformation into ENU coordinate frame makes use of the globally set ENUReferencePoint
 * (see AdMapAccess::setENUReferencePoint())
 */
inline ENUPoint toENU(ECEFPoint const &point)
{
  return access::getCoordinateTransform()->ECEF2ENU(point);
}

/**
 * @brief perform coordinate transformation from GeoPoint to ENUPoint
 *
 * The transformation into ENU coordinate frame makes use of the globally set ENUReferencePoint
 * (see AdMapAccess::setENUReferencePoint())
 */
inline ENUPoint toENU(GeoPoint const &point)
{
  return access::getCoordinateTransform()->Geo2ENU(point);
}

/**
 * @brief perform coordinate transformation from ECEFPoint to ENUPoint
 *
 * The transformation into ENU coordinate frame makes use of the provided enu_reference_point
 */
ENUPoint toENU(ECEFPoint const &point, GeoPoint const &enu_reference_point);

/**
 * @brief perform coordinate transformation from GeoPoint to ENUPoint
 *
 * The transformation into ENU coordinate frame makes use of the provided enu_reference_point
 */
ENUPoint toENU(GeoPoint const &point, GeoPoint const &enu_reference_point);

/**
 * @brief perform coordinate transformation from GeoPointList to ECEFPointList
 */
inline ECEFPointList toECEF(GeoPointList const &pts)
{
  ECEFPointList resultPointList;
  access::getCoordinateTransform()->convert(pts, resultPointList);
  return resultPointList;
}

/**
 * @brief perform coordinate transformation from ENUPointList to ECEFPointList
 *
 * The transformation into ENU coordinate frame makes use of the globally set ENUReferencePoint
 * (see AdMapAccess::setENUReferencePoint())
 */
inline ECEFPointList toECEF(ENUPointList const &pts)
{
  ECEFPointList resultPointList;
  access::getCoordinateTransform()->convert(pts, resultPointList);
  return resultPointList;
}

/**
 * @brief perform coordinate transformation from ENUPointList to ECEFPointList
 *
 * The transformation into ENU coordinate frame makes use of the provided ENUReferencePoint
 */
ECEFPointList toECEF(ENUPointList const &pts, GeoPoint const &enu_reference_point);

/**
 * @brief perform coordinate transformation from ECEFPointList to GeoPointList
 */
inline GeoPointList toGeo(ECEFPointList const &pts)
{
  GeoPointList resultPointList;
  access::getCoordinateTransform()->convert(pts, resultPointList);
  return resultPointList;
}

/**
 * @brief perform coordinate transformation from ENUPointList to GeoPointList
 *
 * The transformation into ENU coordinate frame makes use of the globally set ENUReferencePoint
 * (see AdMapAccess::setENUReferencePoint())
 */
inline GeoPointList toGeo(ENUPointList const &pts)
{
  GeoPointList resultPointList;
  access::getCoordinateTransform()->convert(pts, resultPointList);
  return resultPointList;
}

/**
 * @brief perform coordinate transformation from ENUPointList to GeoPointList
 *
 * The transformation into ENU coordinate frame makes use of the provided ENUReferencePoint
 */
GeoPointList toGeo(ENUPointList const &pts, GeoPoint const &enu_reference_point);

/**
 * @brief perform coordinate transformation from ECEFPointList to ENUPointList
 *
 * The transformation into ENU coordinate frame makes use of the globally set ENUReferencePoint
 * (see AdMapAccess::setENUReferencePoint())
 */
inline ENUPointList toENU(ECEFPointList const &pts)
{
  ENUPointList resultPointList;
  access::getCoordinateTransform()->convert(pts, resultPointList);
  return resultPointList;
}

/**
 * @brief perform coordinate transformation from GeoPointList to ENUPointList
 *
 * The transformation into ENU coordinate frame makes use of the globally set ENUReferencePoint
 * (see AdMapAccess::setENUReferencePoint())
 */
inline ENUPointList toENU(GeoPointList const &pts)
{
  ENUPointList resultPointList;
  access::getCoordinateTransform()->convert(pts, resultPointList);
  return resultPointList;
}

/**
 * @brief perform coordinate transformation from ECEFPointList to ENUPointList
 *
 * The transformation into ENU coordinate frame makes use of the provided ENUReferencePoint
 */
ENUPointList toENU(ECEFPointList const &pts, GeoPoint const &enu_reference_point);

/**
 * @brief perform coordinate transformation from GeoPointList to ENUPointList
 *
 * The transformation into ENU coordinate frame makes use of the provided ENUReferencePoint
 */
ENUPointList toENU(GeoPointList const &pts, GeoPoint const &enu_reference_point);

} // namespace point
} // namespace map
} // namespace ad
