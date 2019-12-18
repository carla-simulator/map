// ----------------- BEGIN LICENSE BLOCK ---------------------------------
//
// Copyright (C) 2018-2019 Intel Corporation
//
// SPDX-License-Identifier: MIT
//
// ----------------- END LICENSE BLOCK -----------------------------------

#include "ad/map/maker/map_data/Lane.hpp"
#include <ad/map/maker/geometry/Point2d.hpp>
#include <boost/geometry.hpp>
#include <boost/geometry/geometries/point_xy.hpp>
#include <unordered_set>
#include "ad/map/maker/map_data/MapDataStore.hpp"
#include "ad/map/maker/map_data/PolyLineConversion.hpp"

namespace ad {
namespace map {
namespace maker {
namespace map_data {

typedef ::boost::geometry::model::d2::point_xy<double> Boost2dPoint;
typedef ::boost::geometry::model::polygon<Boost2dPoint> BoostPolygon;

BoostPolygon fromLane(MapDataStore const &store, Lane const &lane)
{
  auto const &leftBorder = store.polyLine(lane.leftBorder).mNodes;
  auto const &rightBorder = store.polyLine(lane.rightBorder).mNodes;
  // at first shot, we assume that both borders have the same order of points, e.g. from left to right
  std::vector<Boost2dPoint> points;
  for (auto const id : leftBorder)
  {
    auto const &p = store.point(id);
    points.push_back({p.x, p.y});
  }
  for (auto it = rightBorder.rbegin(); it != rightBorder.rend(); ++it)
  {
    auto const &p = store.point(*it);
    points.push_back({p.x, p.y});
  }
  // close polygon
  points.push_back(points.front());
  BoostPolygon result;
  ::boost::geometry::assign_points(result, points);
  // ensure that all polygons have the same orientation
  ::boost::geometry::correct(result);
  return result;
}

bool Lane::overlapsWithLane(MapDataStore const &store, Lane const &other) const
{
  if (&other == this)
  {
    return true;
  }
  auto thisP = fromLane(store, *this);
  auto thatP = fromLane(store, other);
  std::deque<BoostPolygon> output;
  (void)::boost::geometry::intersection(thisP, thatP, output);
  return (!output.empty());
}

Contact Lane::checkLeftRightContact(MapDataStore const &store, Lane const &other) const
{
  if (&other == this)
  {
    return Contact::Overlap;
  }

  // check forward contact
  auto const &thisLeftBorder = store.polyLine(leftBorder).mNodes;
  auto const &thisRightBorder = store.polyLine(rightBorder).mNodes;

  auto const &otherLeftBorder = store.polyLine(other.leftBorder).mNodes;
  auto const &otherRightBorder = store.polyLine(other.rightBorder).mNodes;

  auto const thisLeftStart = thisLeftBorder.front();
  auto const thisRightStart = thisRightBorder.front();
  auto const otherLeftStart = otherLeftBorder.front();
  auto const otherRightStart = otherRightBorder.front();

  auto const thisLeftEnd = thisLeftBorder.back();
  auto const thisRightEnd = thisRightBorder.back();
  auto const otherLeftEnd = otherLeftBorder.back();
  auto const otherRightEnd = otherRightBorder.back();

  std::unordered_set<MapDataId> startPoints;
  std::unordered_set<MapDataId> endPoints;

  startPoints.insert(thisLeftStart);
  startPoints.insert(thisRightStart);
  startPoints.insert(otherLeftStart);
  startPoints.insert(otherRightStart);

  endPoints.insert(thisLeftEnd);
  endPoints.insert(thisRightEnd);
  endPoints.insert(otherLeftEnd);
  endPoints.insert(otherRightEnd);

  // No contact means that all id points are unique and therefore we would have 4 points on each set.
  if ((startPoints.size() < 4) && (endPoints.size() < 4))
  {
    if ((thisLeftStart == otherRightStart) || (thisLeftEnd == otherRightEnd))
    {
      return Contact::Left;
    }

    if ((thisRightStart == otherLeftStart) || (thisRightEnd == otherLeftEnd))
    {
      return Contact::Right;
    }
  }

  // @TODO handle reverse contact. i.e. when there is contact with the inverted(other lane).

  return Contact::None;
}

bool Lane::hasLeftContactWithLane(MapDataStore const &store, Lane const &other) const
{
  if (checkLeftRightContact(store, other) == Contact::Left)
  {
    return true;
  }
  return false;
}

bool Lane::hasRightContactWithLane(MapDataStore const &store, Lane const &other) const
{
  if (checkLeftRightContact(store, other) == Contact::Right)
  {
    return true;
  }
  return false;
}

void Lane::invertLaneDirection(MapDataStore &store, bool invertBorderPolylines)
{
  if (invertBorderPolylines)
  {
    auto &leftBorderPolyLine = store.polyLine(leftBorder);
    auto &rightBorderPolyLine = store.polyLine(rightBorder);
    std::reverse(leftBorderPolyLine.mNodes.begin(), leftBorderPolyLine.mNodes.end());
    std::reverse(rightBorderPolyLine.mNodes.begin(), rightBorderPolyLine.mNodes.end());
  }

  if (drivingDirection == DrivingDirection::Forward)
  {
    drivingDirection = DrivingDirection::Backward;
  }
  else if (drivingDirection == DrivingDirection::Backward)
  {
    drivingDirection = DrivingDirection::Forward;
  }

  std::swap(leftBorder, rightBorder);
  std::swap(leftNeighbor, rightNeighbor);
  std::swap(predecessors, successors);
}

geometry::Point2d Lane::findNearestPoint(MapDataStore const &store, geometry::Point2d const &point) const
{
  if (leftBorder == InvalidId || rightBorder == InvalidId)
  {
    return geometry::Point2d{0.0, 0.0};
  }
  auto leftPoint = findNearestPointOnLeftBorder(store, point);
  auto rightPoint = findNearestPointOnRightBorder(store, point);
  double leftDistance = leftPoint.squaredDistance(point);
  double rightDistance = rightPoint.squaredDistance(point);

  if (leftDistance < rightDistance)
  {
    return leftPoint;
  }
  else
  {
    return rightPoint;
  }
}

geometry::Point2d Lane::findNearestPointOnLeftBorder(MapDataStore const &store, geometry::Point2d const &point) const
{
  if (!store.hasPolyLine(leftBorder))
  {
    return geometry::Point2d{0.0, 0.0};
  }
  auto borderPolyLine = store.polyLine(leftBorder);
  auto geometry = polylineToGeometry(store, borderPolyLine);
  return geometry.findNearestPoint(point);
}

geometry::Point2d Lane::findNearestPointOnRightBorder(MapDataStore const &store, geometry::Point2d const &point) const
{
  if (!store.hasPolyLine(rightBorder))
  {
    return geometry::Point2d{0.0, 0.0};
  }
  auto borderPolyLine = store.polyLine(rightBorder);
  auto geometry = polylineToGeometry(store, borderPolyLine);
  return geometry.findNearestPoint(point);
}

} // namespace map_data
} // namespace maker
} // namespace map
} // namespace ad
