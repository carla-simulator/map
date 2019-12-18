// ----------------- BEGIN LICENSE BLOCK ---------------------------------
//
// Copyright (C) 2018-2019 Intel Corporation
//
// SPDX-License-Identifier: MIT
//
// ----------------- END LICENSE BLOCK -----------------------------------

#pragma once

#include <vector>
#include "ad/map/maker/map_data/MapDataElement.hpp"

namespace ad {
namespace map {
namespace maker {

namespace geometry {
struct Point2d;
} // namespace geometry

namespace map_data {

class MapDataStore;

enum class DrivingDirection
{
  Forward,
  Backward,
  Bidirectional,
  Invalid
};

enum class Contact
{
  Left,
  Right,
  Overlap,
  None
};

struct Lane : MapDataElement
{
  MapDataId parentRoadId{InvalidId};
  MapDataId leftBorder{InvalidId};
  MapDataId rightBorder{InvalidId};

  // left, right neighbor lanes, with respect to the orientation (order) of the points
  MapDataId leftNeighbor{InvalidId};
  MapDataId rightNeighbor{InvalidId};

  // predecessor and successor lanes, with respect to the orientation (order) of the points
  std::vector<MapDataId> predecessors;
  std::vector<MapDataId> successors;

  DrivingDirection drivingDirection{DrivingDirection::Invalid};

  Lane(MapDataId parentId, MapDataId leftBorderId, MapDataId rightBorderId, DrivingDirection direction)
    : parentRoadId{parentId}
    , leftBorder(leftBorderId)
    , rightBorder(rightBorderId)
    , drivingDirection(direction)
  {
  }
  Lane() = default;

  /**
   * @brief Test if the other lane has left or right contact with this lane.
   * @param other
   * @return The contact type.
   */
  Contact checkLeftRightContact(MapDataStore const &store, Lane const &other) const;

  /**
   * @brief Test if the other lane has contact with the left border of this lane.
   * @param other
   * @return True if there is left contact.
   */
  bool hasLeftContactWithLane(MapDataStore const &store, Lane const &other) const;

  /**
   * @brief Test if the other lane has contact with the right border of this lane.
   * @param other
   * @return True if there is right contact.
   */
  bool hasRightContactWithLane(MapDataStore const &store, Lane const &other) const;

  /**
   * @brief Test if this lane has an overlap with other lane
   * @param other
   * @return true if lanes overlap (that is the intersection is non-empty)
   */
  bool overlapsWithLane(MapDataStore const &store, Lane const &other) const;

  /**
   * @brief Inverts the lane geometrical representation, i.e. borders, border points, successors/predecessors and
   * neighbors.
   *
   * Although the driving direction is also inverted (Forward to Backward and viceversa) it represents
   * the same driving direction for the new lane orientation. In other terms, the driving direction remains unchanged.
   *
   * Original lane:
   *  [l0]-------[l1]------[l2]  left border
   *
   *     ---->---- (driving direction Forward)
   *
   *  [r0]---[r1]---[r2]---[r3]  right border
   *
   * Resulting lane with invertBorderPolylines = true:
   *  [l2]-------[l1]------[l0] right border
   *
   *     ---->---- (driving direction Backward)
   *
   *  [r3]---[r2]---[r1]---[r0] left border
   *
   * Resulting lane with invertBorderPolylines = false:
   *  [l0]-------[l1]------[l2] right border
   *
   *     ----<---- (driving direction Backward)
   *
   *  [r0]---[r1]---[r2]---[r3] left border
   *
   * @param store, the MapDataStore object
   * @param invertBorderPolylines If true, this method inverts the order of the borders' points.
   */
  void invertLaneDirection(MapDataStore &store, bool invertBorderPolylines);

  /**
   * @brief Finds point on either the left or right border that is closest to the given point.
   *
   * @param store the MapDataStore object
   * @param point 2d point of interest
   * @returns the projection of the point on the closest border polyline.
   */
  geometry::Point2d findNearestPoint(MapDataStore const &store, geometry::Point2d const &point) const;

  /**
   * @brief Finds point on the left border's geometry that is closest to the given point
   *
   * @param store the MapDataStore object
   * @param point 2d point of interest
   * @returns the projection of the point onto the left border polyline.
   */
  geometry::Point2d findNearestPointOnLeftBorder(MapDataStore const &store, geometry::Point2d const &point) const;

  /**
   * @brief Finds point on the right border's geometry that is closest to the given point
   *
   * @param store the MapDataStore object
   * @param point 2d point of interest
   * @returns the projection of the point onto the right border polyline.
   */
  geometry::Point2d findNearestPointOnRightBorder(MapDataStore const &store, geometry::Point2d const &point) const;
};

} // namespace map_data
} // namespace maker
} // namespace map
} // namespace ad
