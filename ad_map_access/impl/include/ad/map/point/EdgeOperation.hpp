// ----------------- BEGIN LICENSE BLOCK ---------------------------------
//
// Copyright (C) 2018-2019 Intel Corporation
//
// SPDX-License-Identifier: MIT
//
// ----------------- END LICENSE BLOCK -----------------------------------

#pragma once

#include <vector>
#include "ad/map/point/PointOperation.hpp"
#include "ad/physics/Operation.hpp"
#include "ad/physics/ParametricRange.hpp"
#include "ad/physics/ParametricValueValidInputRange.hpp"

/* @brief namespace ad */
namespace ad {
/* @brief namespace map */
namespace map {
/* @brief namespace point */
namespace point {

/**
 * @brief The edge point border distance
 */
physics::Distance const cEdgePointBorderDistance{0.1};

/**
 * @brief Calculate the length of an edge
 * @param[in] edge The input edge to operate on.
 * @return The length of the edge
 */
template <typename PointType> physics::Distance calculateEdgeLength(std::vector<PointType> const &edge)
{
  physics::Distance length(0.);
  for (auto i = 1u; i < edge.size(); ++i)
  {
    length += distance(edge[i - 1u], edge[i]);
  }
  return length;
}

/**
 * @brief Get the parametric edge points
 * @param[in] edge The input edge to operate on.
 * @return Vector of parametric values on the edge.
 */
template <typename PointType>
std::vector<physics::ParametricValue> getParametricEdgePoints(std::vector<PointType> const &edge)
{
  std::vector<physics::ParametricValue> resultPoints;
  resultPoints.reserve(edge.size());
  resultPoints.push_back(physics::ParametricValue(0.));
  physics::Distance length(0.);
  for (auto i = 1u; i < edge.size(); ++i)
  {
    length += distance(edge[i - 1u], edge[i]);
    resultPoints.push_back(physics::ParametricValue(static_cast<double>(length)));
  }

  for (auto i = 1u; i < edge.size(); ++i)
  {
    if (length > physics::Distance(0.))
    {
      resultPoints[i] = resultPoints[i] / static_cast<double>(length);
    }
  }
  return resultPoints;
}

/**
 * @brief Calculates parametric point on the edge.
 * @param[in] edge The input edge to operate on.
 * @param[in] t Parameter. 0 will return first point, and 1 last point on the edge.
 * @return Parametric point on the edge.
 */
template <typename PointType>
PointType getParametricPoint(std::vector<PointType> const &edge,
                             physics::Distance const &edgeLength,
                             const physics::ParametricValue &t)
{
  if (!edge.empty())
  {
    physics::Distance length(0);
    physics::Distance length_t = edgeLength * t;
    for (size_t i = 0; i < edge.size() - 1; i++)
    {
      const auto &pt0 = edge[i];
      const auto &pt1 = edge[i + 1];
      auto d = distance(pt0, pt1);
      if (d != physics::Distance(0.))
      {
        auto length_1 = length + d;
        if (length_1 >= length_t)
        {
          auto d_t = length_t - length;
          physics::ParametricValue tt(d_t / d);
          return vectorInterpolate(pt0, pt1, tt);
        }
        else
        {
          length = length_1;
        }
      }
    }
    return edge.back();
  }
  else
  {
    return PointType();
  }
}

/**
 * @brief Calculates parametric point on the edge.
 * @param[in] edge The input edge to operate on.
 * @param[in] t Parameter. 0 will return first point, and 1 last point on the edge.
 * @return Parametric point on the edge.
 */
template <typename PointType>
PointType getParametricPoint(std::vector<PointType> const &edge, const physics::ParametricValue &t)
{
  return getParametricPoint(edge, calculateEdgeLength(edge), t);
}

/**
 * @brief Generates sub-edge for given range.
 * @param[in] edge The input edge to operate on.
 * @param[in] trange Specifies parametric range.
 * @return Sub-geometry.
 */
template <typename PointType>
std::vector<PointType> getParametricRange(std::vector<PointType> const &edge,
                                          physics::Distance const &edgeLength,
                                          const physics::ParametricRange &trange)
{
  using EdgeType = std::vector<PointType>;
  if (!edge.empty())
  {
    EdgeType pts;
    physics::Distance length(0);
    physics::Distance length_t_start = edgeLength * trange.minimum;
    size_t i = 0;
    for (; i < edge.size() - 1 && pts.empty(); i++)
    {
      const PointType &pt0 = edge[i];
      const PointType &pt1 = edge[i + 1];
      physics::Distance d = distance(pt0, pt1);
      physics::Distance length_1 = length + d;
      if ((d != physics::Distance(0)) && (length_1 >= length_t_start))
      {
        physics::Distance d_t = length_t_start - length;
        physics::ParametricValue tt(d_t / d);
        PointType pt_start = vectorInterpolate(pt0, pt1, tt);
        pts.push_back(pt_start);
        break;
      }
      else
      {
        length = length_1;
      }
    }
    if (!pts.empty())
    {
      physics::Distance length_t_end = edgeLength * trange.maximum;
      for (; i < edge.size() - 1; i++)
      {
        const PointType &pt0 = edge[i];
        const PointType &pt1 = edge[i + 1];
        physics::Distance d = distance(pt0, pt1);
        physics::Distance length_1 = length + d;
        if ((d != physics::Distance(0)) && (length_1 >= length_t_end))
        {
          physics::Distance d_t = length_t_end - length;
          physics::ParametricValue tt(d_t / d);
          PointType pt_end = vectorInterpolate(pt0, pt1, tt);
          pts.push_back(pt_end);
          return pts;
        }
        else
        {
          pts.push_back(pt1);
          length = length_1;
        }
      }
      pts.push_back(edge.back());
      return pts;
    }
  }
  return EdgeType();
}

/**
 * @brief Generates sub-edge for given range.
 * @param[in] edge The input edge to operate on.
 * @param[in] trange Specifies parametric range.
 * @return Sub-geometry.
 */
template <typename PointType>
std::vector<PointType> getParametricRange(std::vector<PointType> const &edge, const physics::ParametricRange &trange)
{
  return getParametricRange(edge, calculateEdgeLength(edge), trange);
}

/**
 * @brief Finds point on geometry nearest to given point.
 * @param[in] pt Point of interest.
 * @returns Parametric point on geometry nearest to the pt.
 *          Can be invalid (if pt is Invalid(), geometry is empty etc.).
 */
template <typename PointType>
physics::ParametricValue
findNearestPointOnEdge(std::vector<PointType> const &edge, physics::Distance const &edgeLength, const PointType &pt)
{
  if (isValid(pt))
  {
    if (edge.size() == 0)
    {
      return physics::ParametricValue();
    }
    else if ((edge.size() == 1) || (edgeLength == physics::Distance(0.)))
    {
      return physics::ParametricValue(0);
    }
    else
    {
      physics::ParametricValue t_one = findNearestPointOnSegment(pt, edge[0], edge[1]);
      PointType pt_nearest = vectorInterpolate(edge[0], edge[1], t_one);
      physics::Distance d_nearest = distance(pt, pt_nearest);
      physics::Distance offset_nearest = distance(pt_nearest, edge[0]);
      physics::Distance running_offset = physics::Distance(0);
      for (size_t i = 1; i + 1 < edge.size(); i++)
      {
        physics::ParametricValue t = findNearestPointOnSegment(pt, edge[i], edge[i + 1]);
        PointType pt_candidate = vectorInterpolate(edge[i], edge[i + 1], t);
        physics::Distance d = distance(pt_candidate, pt);
        running_offset += distance(edge[i - 1], edge[i]);
        if (d < d_nearest)
        {
          pt_nearest = pt_candidate;
          d_nearest = d;
          offset_nearest = running_offset + distance(pt_nearest, edge[i]);
        }
      }
      return physics::ParametricValue(offset_nearest / edgeLength);
    }
  }
  else
  {
    return physics::ParametricValue();
  }
}

/**
 * @brief Find the nearest point on an edge
 * @param[in] edge The input edge to operate on.
 * @param[in] pt Point of interest.
 * @returns Parametric point on geometry nearest to the pt.
 *          Can be invalid (if pt is Invalid(), geometry is empty etc.).
 */
template <typename PointType>
physics::ParametricValue findNearestPointOnEdge(std::vector<PointType> const &edge, const PointType &pt)
{
  return findNearestPointOnEdge(edge, calculateEdgeLength(edge), pt);
}

/**
 * @brief Get an edge between the two given border edges with corresponding lateralAlignment
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
 * @param[in] lateralAlignment the lateral alignment as TParam [0.;1.] used to calculate the resulting edge.
 *   The lateral alignment is relative to the left edge. If lateralAlignment is 1., the left edge is returned,
 *   if lateralAlignment is 0., the right edge is returned
 *
 * @throws std::invalid_argument if the lateralAlignment parameter is smaller than 0. or larger than 1.
 */
template <typename PointType>
std::vector<PointType> getLateralAlignmentEdge(std::vector<PointType> const &leftEdge,
                                               physics::Distance const &leftEdgeLength,
                                               std::vector<PointType> const &rightEdge,
                                               physics::Distance const &rightEdgeLength,
                                               physics::ParametricValue const lateralAlignment)
{
  using EdgeType = std::vector<PointType>;

  if (!withinValidInputRange(lateralAlignment))
  {
    throw std::invalid_argument("ad::map::point::getLateralAlignmentEdge()"
                                " the given lateralAlignment is out of range");
  }

  EdgeType const *primary;
  EdgeType const *secondary;
  physics::Distance primaryLength;
  physics::Distance secondaryLength;
  physics::ParametricValue lateralOffset = lateralAlignment;
  if (leftEdge.size() > rightEdge.size())
  {
    primary = &leftEdge;
    primaryLength = leftEdgeLength;
    secondary = &rightEdge;
    secondaryLength = rightEdgeLength;
    lateralOffset = physics::ParametricValue(1.) - lateralAlignment;
  }
  else
  {
    primary = &rightEdge;
    primaryLength = rightEdgeLength;
    secondary = &leftEdge;
    secondaryLength = leftEdgeLength;
  }

  std::vector<physics::ParametricValue> const primaryParametric = getParametricEdgePoints(*primary);
  EdgeType alignmentEdge;
  alignmentEdge.reserve(primaryParametric.size());
  for (size_t i = 0; i < primaryParametric.size(); i++)
  {
    PointType const &pri = primary->at(i);
    PointType const sec = getParametricPoint(*secondary, secondaryLength, primaryParametric[i]);
    PointType const alignmentPoint = vectorInterpolate(pri, sec, lateralOffset);
    alignmentEdge.push_back(alignmentPoint);
  }
  return alignmentEdge;
}

/**
 * @brief Get an edge between the two given border edges with corresponding lateralAlignment
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
 * @param[in] lateralAlignment the lateral alignment as TParam [0.;1.] used to calculate the resulting edge.
 *   The lateral alignment is relative to the left edge. If lateralAlignment is 1., the left edge is returned,
 *   if lateralAlignment is 0., the right edge is returned
 *
 * @throws std::invalid_argument if the lateralAlignment parameter is smaller than 0. or larger than 1.
 */
template <typename PointType>
std::vector<PointType> getLateralAlignmentEdge(std::vector<PointType> const &leftEdge,
                                               std::vector<PointType> const &rightEdge,
                                               physics::ParametricValue const lateralAlignment)
{
  return getLateralAlignmentEdge(
    leftEdge, calculateEdgeLength(leftEdge), rightEdge, calculateEdgeLength(rightEdge), lateralAlignment);
}

/**
 * @brief get a normalized vector representing the edge direction at edge start
 *
 * If the number of edge points is <= 1, zero is returned.
 * If the two start points of the edge are too close to each other, a third point is used if possible to increase
 * the accuracy.
 */
template <typename PointType> PointType getEdgeStartDirectionalVector(std::vector<PointType> const edge)
{
  if (edge.size() <= 1u)
  {
    return PointType();
  }

  auto edgeStartVec = edge[1u] - edge[0u];
  // in case the end points are too near to each other we take another point into account if possible
  if ((vectorLength(edgeStartVec) < cEdgePointBorderDistance) && (edge.size() > 2u))
  {
    edgeStartVec = edge[2u] - edge[0u];
  }
  return vectorNorm(edgeStartVec);
}

/**
 * @brief get a normalized vector representing the edge direction at edge end
 *
 * If the number of edge points is <= 1, zero is returned.
 * If the two end points of the edge are too close to each other, a third point is used if possible to increase
 * the accuracy.
 */
template <typename PointType> PointType getEdgeEndDirectionalVector(std::vector<PointType> const edge)
{
  if (edge.size() <= 1u)
  {
    return PointType();
  }

  auto edgeEndVec = edge[edge.size() - 1u] - edge[edge.size() - 2u];
  // in case the end points are too near to each other we take another point into account if possible
  if ((vectorLength(edgeEndVec) < cEdgePointBorderDistance) && (edge.size() > 2u))
  {
    edgeEndVec = edge[edge.size() - 1u] - edge[edge.size() - 3u];
  }
  return vectorNorm(edgeEndVec);
}

} // namespace point
} // namespace map
} // namespace ad
