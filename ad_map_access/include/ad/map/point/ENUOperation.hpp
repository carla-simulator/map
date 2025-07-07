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

#include "ad/map/point/ENUPointListValidInputRange.hpp"
#include "ad/map/point/EdgeOperation.hpp"

/** @brief namespace ad */
namespace ad {
/** @brief namespace map */
namespace map {
/** @brief namespace point */
namespace point {

/**
 * @brief checks if the given ENUPoint is valid
 *
 * The point is valid if it's within valid input range.
 */
inline bool isValid(ENUPoint const &point, bool const logErrors = true)
{
  return withinValidInputRange(point, logErrors);
}

/**
 * @brief checks if the given ENUPointList is valid
 *
 * The pts is valid if it's within valid input range.
 */
inline bool isValid(ENUPointList const &pts, bool const logErrors = true)
{
  return withinValidInputRange(pts, logErrors);
}

/**
 * @brief create a ENUPoint
 *
 * @param[in] x x-coodinate of the point
 * @param[in] y y-coodinate of the point
 * @param[in] z z-coodinate of the point
 */
inline ENUPoint createENUPoint(double const x, double const y, double const z)
{
  ENUPoint result;
  result.x = ENUCoordinate(x);
  result.y = ENUCoordinate(y);
  result.z = ENUCoordinate(z);
  return result;
}

/**
 * @brief create a ENUPoint
 *
 * @param[in] x x-coodinate of the point
 * @param[in] y y-coodinate of the point
 * @param[in] z z-coodinate of the point
 */
inline ENUPoint createENUPoint(ENUCoordinate const x, ENUCoordinate const y, ENUCoordinate const z)
{
  ENUPoint result;
  result.x = x;
  result.y = y;
  result.z = z;
  return result;
}

/**
 * @brief get ENUPoint defining the East-Axis
 */
inline ENUPoint getEnuEastAxis()
{
  ENUPoint result;
  result.x = ENUCoordinate(1.);
  result.y = ENUCoordinate(0.);
  result.z = ENUCoordinate(0.);
  return result;
}

/**
 * @brief get ENUPoint defining the North-Axis
 */
inline ENUPoint getEnuNorthAxis()
{
  ENUPoint result;
  result.x = ENUCoordinate(0.);
  result.y = ENUCoordinate(1.);
  result.z = ENUCoordinate(0.);
  return result;
}

/**
 * @brief get ENUPoint defining the Up-Axis
 */
inline ENUPoint getEnuUpAxis()
{
  ENUPoint result;
  result.x = ENUCoordinate(0.);
  result.y = ENUCoordinate(0.);
  result.z = ENUCoordinate(1.);
  return result;
}

/**
 * @brief calculate the cross product of two vectors
 *
 * @param[in] a vector a
 * @param[in] b vector b
 *
 * @returns vector c = a x b
 */
template ENUPoint vectorCrossProduct(ENUPoint const &a, ENUPoint const &b);

/**
 * @brief calculate the dot product of two vectors
 *
 * @param[in] a vector a
 * @param[in] b vector b
 *
 * @returns value d = a * b
 */
template double vectorDotProduct(ENUPoint const &a, ENUPoint const &b);

/**
 * @brief multiplies a vector with a scalar
 * @param[in] a vector a
 * @param[in] b scalar b
 */
template ENUPoint vectorMultiplyScalar(ENUPoint const &a, double const &b);

/**
 * @brief multiplies a vector with a scalar
 * @param[in] a vector a
 * @param[in] b scalar b
 */
template ENUPoint vectorMultiplyScalar(ENUPoint const &a, physics::Distance const &b);

/**
 * @brief calculate the length of a vector
 *
 * @param[in] a vector a
 *
 * @returns value d = |a|
 */
template physics::Distance vectorLength(ENUPoint const &a);

/**
 * @brief normalizes a vector
 *
 * @param[in] a vector a
 *
 * @returns vector c = a  / |a|
 */
template ENUPoint vectorNorm(ENUPoint const &a);

/**
 * @brief add two vectors
 *
 * @param[in] a vector a
 * @param[in] b vector b
 *
 * @returns vector c = a + b
 */
template ENUPoint vectorAdd(ENUPoint const &a, ENUPoint const &b);

/**
 * @brief subtract two vectors from each right
 *
 * @param[in] a vector a
 * @param[in] b vector b
 *
 * @returns c = a - b
 */
template ENUPoint vectorSub(ENUPoint const &a, ENUPoint const &b);

/**
 * @brief Interpolates point between two points.
 *
 * @param[in] a vector a
 * @param[in] b vector b
 * @param[in] tparam Between 0 and 1.
 *
 * @returns Point between point a and b.
 *          with tparam==0, it will return point a;
 *          with tparam==1, it will return point b.
 */
template ENUPoint vectorInterpolate(ENUPoint const &a, ENUPoint const &b, physics::ParametricValue const &tparam);

/**
 * @brief Extrapolate point based on line defined by two points.
 *
 * @param[in] a vector a
 * @param[in] b vector b
 * @param[in] scalar scalar value
 *
 * @returns Points extrapolated using point a and b.
 *          with scalar==0, it will return point a;
 *          with scalar==1, it will return point b.
 */
template ENUPoint vectorExtrapolate(ENUPoint const &a, ENUPoint const &b, double const &scalar);

/**
 * @brief Computes distance between ENU points.
 * @returns Distance between two points in meters.
 */
template physics::Distance distance(ENUPoint const &point, ENUPoint const &other);

/**
 * @brief Find point nearest to the line formed by two points.
 *
 * @param[in] a point to search for
 * @param[in] pt0 First point of the line.
 * @param[in] pt1 Second point of the line.
 * @returns Value of t;  nearest point to a can be calculated as (1-t)*pt0+t*pt1.
 */
template physics::RatioValue findNearestPointOnEdge(ENUPoint const &a, const ENUPoint &pt0, const ENUPoint &pt1);

/**
 * @brief Find point nearest to the segment formed by two points.
 *
 * @param[in] a point to search for
 * @param[in] pt0 First point of the segment.
 * @param[in] pt1 Second point of the segment.
 * @returns Value of 0<=t<=1;  nearest point to this can be calculated as (1-t)*pt0+t*pt1.
 *
 */
template physics::ParametricValue
findNearestPointOnSegment(ENUPoint const &a, const ENUPoint &pt0, const ENUPoint &pt1);

/**
 * @brief Calculate the length of an edge
 * @param[in] edge The input edge to operate on.
 * @return The length of the edge
 */
template physics::Distance calculateEdgeLength(ENUPointList const &edge);

/**
 * @brief Get the parametric edge points
 * @param[in] edge The input edge to operate on.
 * @return Vector of parametric values on the edge.
 */
template physics::ParametricValueList getParametricEdgePoints(ENUPointList const &edge);

/**
 * @brief Calculates parametric point on the edge.
 * @param[in] edge The input edge to operate on.
 * @param[in] t Parameter. 0 will return first point, and 1 last point on the edge.
 * @return Parametric point on the edge.
 */
template ENUPoint
getParametricPoint(ENUPointList const &edge, physics::Distance const &edgeLength, const physics::ParametricValue &t);

/**
 * @brief Calculates parametric point on the edge.
 * @param[in] edge The input edge to operate on.
 * @param[in] t Parameter. 0 will return first point, and 1 last point on the edge.
 * @return Parametric point on the edge.
 */
template ENUPoint getParametricPoint(ENUPointList const &edge, const physics::ParametricValue &t);

/**
 * @brief Generates sub-edge for given range.
 * @param[in] edge The input edge to operate on.
 * @param[in] trange Specifies parametric range.
 * @return Sub-geometry.
 */
template ENUPointList getParametricRange(ENUPointList const &edge,
                                         physics::Distance const &edgeLength,
                                         const physics::ParametricRange &trange);

/**
 * @brief Generates sub-edge for given range.
 * @param[in] edge The input edge to operate on.
 * @param[in] trange Specifies parametric range.
 * @return Sub-geometry.
 */
template ENUPointList getParametricRange(ENUPointList const &edge, const physics::ParametricRange &trange);

/**
 * @brief Finds point on geometry nearest to given point.
 * @param[in] pt Point of interest.
 * @returns Parametric point on geometry nearest to the pt.
 *          Can be invalid (if pt is Invalid(), geometry is empty etc.).
 */
template physics::ParametricValue
findNearestPointOnEdge(ENUPointList const &edge, physics::Distance const &edgeLength, const ENUPoint &pt);

/**
 * @brief Find the nearest point on an edge
 * @param[in] edge The input edge to operate on.
 * @param[in] pt Point of interest.
 * @returns Parametric point on geometry nearest to the pt.
 *          Can be invalid (if pt is Invalid(), geometry is empty etc.).
 */
template physics::ParametricValue findNearestPointOnEdge(ENUPointList const &edge, const ENUPoint &pt);

/**
 * @brief Calculate the width range and the average width of a pair of edges
 *
 * At maximum 100 supporting points are taken into account to calculate this.
 *
 * @param[in] leftEdge the left-hand border edge as basis for the calculation
 * @param[in] leftEdgeLength the length of the left-hand border edge
 * @param[in] rightEdge the right-hand border edge as basis for the calculation
 * @param[in] rightEdgeLength the length of the left-hand border edge
 *
 * @returns pair containing the range of the width and the average width between the two input edges.
 */
template std::pair<physics::MetricRange, physics::Distance>
calculateWidthRange(ENUPointList const &edge_left,
                    physics::Distance const &edgeLeftLength,
                    ENUPointList const &edge_right,
                    physics::Distance const &edgeRightLength);

/**
 * @brief Get an edge between the two given border edges with corresponding lateral_alignment
 *
 * The left and right edges are usually the borders of some road section.
 * This function then calculates a new edge in between two other edges providing e.g. the center edge
 * (lateralAlgignment=0.5)
 * or edge with other lateral shift.
 *
 * @param[in] leftEdge the left-hand border edge as basis for the calculation
 * @param[in] leftEdgeLength the length of the left-hand border edge
 * @param[in] rightEdge the right-hand border edge as basis for the calculation
 * @param[in] rightEdgeLength the length of the left-hand border edge
 * @param[in] lateral_alignment the lateral alignment as TParam [0.;1.] used to calculate the resulting edge.
 *   The lateral alignment is relative to the left edge. If lateral_alignment is 1., the left edge is returned,
 *   if lateral_alignment is 0., the right edge is returned
 *
 * @throws std::invalid_argument if the lateral_alignment parameter is smaller than 0. or larger than 1.
 */
template ENUPointList getLateralAlignmentEdge(ENUPointList const &leftEdge,
                                              physics::Distance const &leftEdgeLength,
                                              ENUPointList const &rightEdge,
                                              physics::Distance const &rightEdgeLength,
                                              physics::ParametricValue const lateral_alignment);

/**
 * @brief Get an edge between the two given border edges with corresponding lateral_alignment
 *
 * The left and right edges are usually the borders of some road section.
 * This function then calculates a new edge in between two other edges providing e.g. the center edge
 * (lateralAlgignment=0.5)
 * or edge with other lateral shift.
 *
 * Note: if the length of the edges are already know, the overloaded getLateralAlignmentEdge() function can be called.
 *
 * @param[in] leftEdge the left-hand border edge as basis for the calculation
 * @param[in] rightEdge the right-hand border edge as basis for the calculation
 * @param[in] lateral_alignment the lateral alignment as TParam [0.;1.] used to calculate the resulting edge.
 *   The lateral alignment is relative to the left edge. If lateral_alignment is 1., the left edge is returned,
 *   if lateral_alignment is 0., the right edge is returned
 *
 * @throws std::invalid_argument if the lateral_alignment parameter is smaller than 0. or larger than 1.
 */
template ENUPointList getLateralAlignmentEdge(ENUPointList const &leftEdge,
                                              ENUPointList const &rightEdge,
                                              physics::ParametricValue const lateral_alignment);

/**
 * @brief get a normalized vector representing the edge direction at edge start
 *
 * If the number of edge points is <= 1, zero is returned.
 * If the two start points of the edge are too close to each other, a third point is used if possible to increase
 * the accuracy.
 */
template ENUPoint getEdgeStartDirectionalVector(ENUPointList const edge);

/**
 * @brief get a normalized vector representing the edge direction at edge end
 *
 * If the number of edge points is <= 1, zero is returned.
 * If the two end points of the edge are too close to each other, a third point is used if possible to increase
 * the accuracy.
 */
template ENUPoint getEdgeEndDirectionalVector(ENUPointList const edge);

/** @brief calculate the length of the provided border as distance value
 *
 * Length calculation is performed within Cartesian ENU coordinate frame.
 */
inline physics::Distance calcLength(ENUPointList const &pts)
{
  return calculateEdgeLength(pts);
}

} // namespace point
} // namespace map
} // namespace ad

/**
 * @brief calculate the dot product of two ENUPoint vectors
 *
 * @param[in] a vector a
 * @param[in] b vector b
 *
 * @returns value d = a * b
 */
inline double operator*(::ad::map::point::ENUPoint const &a, ::ad::map::point::ENUPoint const &b)
{
  return ::ad::map::point::vectorDotProduct(a, b);
}

/**
 * @brief multiplies a ENUPoint vector with a scalar
 * @param[in] a vector a
 * @param[in] b scalar b
 */
inline ::ad::map::point::ENUPoint operator*(::ad::map::point::ENUPoint const &a, ::ad::physics::Distance const &b)
{
  return ::ad::map::point::vectorMultiplyScalar(a, b);
}

/**
 * @brief multiplies a ENUPoint vector with a scalar
 * @param[in] b scalar b
 * @param[in] a vector a
 */
inline ::ad::map::point::ENUPoint operator*(::ad::physics::Distance const &b, ::ad::map::point::ENUPoint const &a)
{
  return ::ad::map::point::vectorMultiplyScalar(a, b);
}

/**
 * @brief multiplies a ENUPoint vector with a scalar
 * @param[in] a vector a
 * @param[in] b scalar b
 */
inline ::ad::map::point::ENUPoint operator*(::ad::map::point::ENUPoint const &a, double const &b)
{
  return ::ad::map::point::vectorMultiplyScalar(a, b);
}

/**
 * @brief multiplies a ENUPoint vector with a scalar
 * @param[in] b scalar b
 * @param[in] a vector a
 */
inline ::ad::map::point::ENUPoint operator*(double const &b, ::ad::map::point::ENUPoint const &a)
{
  return ::ad::map::point::vectorMultiplyScalar(a, b);
}

/**
 * @brief add two ENUPoint vectors
 *
 * @param[in] a vector a
 * @param[in] b vector b
 *
 * @returns vector c = a + b
 */
inline ::ad::map::point::ENUPoint operator+(::ad::map::point::ENUPoint const &a, ::ad::map::point::ENUPoint const &b)
{
  return ::ad::map::point::vectorAdd(a, b);
}

/**
 * @brief subtract two ENUPoint vectors from each right
 *
 * @param[in] a vector a
 * @param[in] b vector b
 *
 * @returns c = a - b
 */
inline ::ad::map::point::ENUPoint operator-(::ad::map::point::ENUPoint const &a, ::ad::map::point::ENUPoint const &b)
{
  return ::ad::map::point::vectorSub(a, b);
}
