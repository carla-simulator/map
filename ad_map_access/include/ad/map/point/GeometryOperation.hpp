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

#include "ad/map/point/CoordinateTransform.hpp"
#include "ad/map/point/ECEFPointList.hpp"
#include "ad/map/point/ENUPointList.hpp"
#include "ad/map/point/GeoPointList.hpp"
#include "ad/map/point/Geometry.hpp"
#include "ad/physics/ParametricRange.hpp"

/** @brief namespace ad */
namespace ad {
/** @brief namespace map */
namespace map {
/** @brief namespace point */
namespace point {

/**
 * @brief validity check
 *
 * @param[in] geometry the geometry to check
 */
inline bool isValid(Geometry const &geometry)
{
  return geometry.is_valid;
}

/**
 * @brief create a geometry
 * @param[in] points the points to create the geometry from
 * @param[in] closed should the geometry be closed?
 */
Geometry createGeometry(const ECEFPointList &points, bool closed);

/**
 * @brief get the cached ENUPointList for a geometry
 * @param[in] geometry the geometry to work on
 * @returns Polyline that defines this Geometry in the ENU frame.
 * \note    Prior to the method call, valid coordinate transformation object must
 *          be set using SetCoordinateTransform().
 *          ENU geometry will be calculated on-the-fly if
 *          - it was not previously calculated, or
 *          - ENU reference point has been changed.
 */
ENUPointList getCachedENUPointList(Geometry const &geometry);

/**
 * @brief Checks if Geometry is longitudinally connected with another Geometry at the end.
 * @param[in] other Other object. Must be IsValid()!
 * @returns True if this Geometry longitudinally connected with another Geometry at the end.
 */
bool isSuccessor(Geometry const &edge, const Geometry &other);

/**
 * @brief Checks if Geometry is longitudinally connected with another Geometry at the start.
 * @param[in] other Other object. Must be IsValid()!
 * @returns True if this Geometry longitudinally connected with another Geometry at the start.
 */
bool isPredecessor(Geometry const &edge, const Geometry &other);

/**
 * @brief Checks if two edges have same start point.
 * @param[in] other Other object. Must be IsValid()!
 * @returns True if this Geometry have same start point as another Geometry.
 */
bool haveSameStart(Geometry const &edge, const Geometry &other);

/**
 * @brief Checks if two edges have same end point.
 * @param[in] other Other object. Must be IsValid()!
 * @returns True if this Points have same end point as another Points.
 */
bool haveSameEnd(Geometry const &edge, const Geometry &other);

/**
 * @brief Calculates parametric point on the geometry.
 * @param[in] t Parameter. 0 will return first point, and 1 last point on the geometry.
 * @return Parameteric point on the geometry. Can be invalid.
 */
point::ECEFPoint getParametricPoint(Geometry const &geometry, const physics::ParametricValue &t);

/**
 * @brief Generates sub-geometry for given range.
 * @param[in] geometry source geometry.
 * @param[in] trange Specifies parametric range.
 * @param[out] outputPoints The output edge to be filled with the sub-geometry points
 * @param[in] revertOrder optional parameter: if set \c true the order of the points in the outputPoints is in reverse
 * order of the geometry
 * @return Sub-geometry.
 */
void getParametricRange(Geometry const &geometry,
                        const physics::ParametricRange &trange,
                        ECEFPointList &outputPoints,
                        const bool revertOrder = false);

/**
 * @brief Generates sub-geometry for given range.
 * @param[in] geometry source geometry.
 * @param[in] trange Specifies parametric range.
 * @param[out] outputPoints The output edge to be filled with the sub-geometry points
 * @param[in] revertOrder optional parameter: if set \c true the order of the points in the outputPoints is in reverse
 * order of the geometry
 * @return Sub-geometry.
 */
void getParametricRange(Geometry const &geometry,
                        const physics::ParametricRange &trange,
                        GeoPointList &outputPoints,
                        const bool revertOrder = false);

/**
 * @brief Generates sub-geometry for given range.
 * This overloaded member internally makes use of the getCachedENUPointList() feature of the geometry.
 *
 * @param[in] geometry source geometry.
 * @param[in] trange Specifies parametric range.
 * @param[out] outputPoints The output edge to be filled with the sub-geometry points
 * @param[in] revertOrder optional parameter: if set \c true the order of the points in the outputPoints is in reverse
 * order of the geometry
 * @return Sub-geometry.
 */
void getParametricRange(Geometry const &geometry,
                        const physics::ParametricRange &trange,
                        ENUPointList &outputPoints,
                        const bool revertOrder = false);

/**
 * @brief Finds point on geometry nearest to given point.
 * @param[in] pt Point of interest.
 * @returns Parametric point on geometry nearest to the pt.
 *          Can be invalid (if pt is Invalid(), geometry is empty etc.).
 */
physics::ParametricValue findNearestPointOnEdge(Geometry const &geometry, const point::ECEFPoint &pt);

/**
 * @brief Finds point on geometry nearest to given point considering only the x,y components of the ENUPoint
 * @param[in] pt Point of interest (z-coordinate is ignored on the operation)
 * @returns Parametric point on geometry nearest to the pt.
 *          Can be invalid (if pt is Invalid(), geometry is empty etc.).
 */
physics::ParametricValue findNearestPointOnEdgeIgnoreZ(Geometry const &geometry, const point::ENUPoint &pt);

/**
 * @brief Calculates middle line between two Geometries.
 * @param[in] geometry A geometry
 * @param[in] other Another geometry.
 * @returns Middle line between two Geometry. Contains same number of points as biggest one.
 */
ECEFPointList getMiddleEdge(Geometry const &geometry, Geometry const &other);

} // namespace point
} // namespace map
} // namespace ad
