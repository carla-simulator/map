// ----------------- BEGIN LICENSE BLOCK ---------------------------------
//
// Copyright (C) 2018-2019 Intel Corporation
//
// SPDX-License-Identifier: MIT
//
// ----------------- END LICENSE BLOCK -----------------------------------

#pragma once

#include <ad/map/maker/geometry/Direction2d.hpp>
#include <vector>
#include "ad/map/maker/map_data/MapDataElement.hpp"
#include "ad/map/maker/map_data/RoadType.hpp"
#include "ad/map/maker/map_data/TurnDirection.hpp"

namespace ad {
namespace map {
namespace maker {

namespace common {
struct LogChannel;
} // namespace common

namespace geometry {
struct Polyline2d;
struct Line2d;
struct Point2d;
} // namespace geometry

namespace map_data {
class MapDataStore;
struct PolyLine;
enum class DrivingDirection;

static const double cMsToKmh{3.6};

struct Road : MapDataElement
{
  void generateLanes();

  /**
   * @brief Inverts the road geometrical representation but keeps the driving direction.
   */
  void invertRoadDirection();

  /**
   * @brief converts the road from right-hand to left-hand traffic
   */
  void convertToLeftHandTraffic();

  /**
   * @brief assign predecessors/successors for generated lanes
   */
  void assignSuccPredLaneNeighbors() const;

  /**
   * @brief assign left/right neighbors for generated lanes
   */
  void assignLeftRightLaneNeighbors() const;

  /**
   * @brief Add a forward lane
   * @param rightBorderId id of right border of new lane
   *
   * Takes the right border of the left lane as the id of the left border
   */
  void addForwardLane(MapDataId rightBorderId);

  /**
   * @brief Add a forward lane
   * @param leftBorderId id of left border of new lane
   *
   * Takes the left border of the right lane as the id of the left border
   */
  void addBackwardLane(MapDataId leftBorderId);

  /**
   * @brief is the road valid?
   * @return true if road is valid, i.e. it has forward or backward lanes.
   */
  bool isValid() const;

  /**
   * @brief complete width of all forward lanes
   */
  double forwardWidth() const;

  /**
   * @brief complete width of all backward lanes
   */
  double backwardWidth() const;

  /**
   * @brief return id of left/right border of requested forward lane
   * @return id of left/right border (of lane with index), InvalidId if it doesn't exist
   */
  MapDataId borderIdOfForwardLane(uint64_t index, bool returnLeft) const;

  /**
   * @brief return id of left/right border of requested backward lane
   * @return id of left/right border (of lane with index), InvalidId if it doesn't exist
   */
  MapDataId borderIdOfBackwardLane(uint64_t index, bool returnLeft) const;

  //! all lanes going forward that are generated through generateLanes
  std::vector<MapDataId> mForwardLanes;
  //! all lanes going backward that are generated through generateLanes
  std::vector<MapDataId> mBackwardLanes;

  MapDataId mCenterLineId{InvalidId};       //! course of center line of the road
  std::vector<double> mForwardWidths;       //! widths of lanes going forward
  std::vector<double> mBackwardWidths;      //! widths of lanes going backward
  std::vector<double> mForwardWidthsAtEnd;  //! widths of lanes going forward (at the end of the lane)
  std::vector<double> mBackwardWidthsAtEnd; //! widths of lanes going backward (at the end of the lane)

  int32_t mLayer{0};                       //! above or below? if != 0
  std::vector<MapDataId> mTrafficLights{}; //! traffic lights that apply for this road
  std::vector<MapDataId> mTrafficSigns{};  //! traffic signs "attached" to this road
  double mForwardSpeedLimit{0.};           //! speed limit for _all_ lanes in forward direction in [m/s], 0: no limit
  double mBackwardSpeedLimit{0.};          //! speed limit for _all_ lanes in backward direction in [m/s], 0: no limit
  double mDistanceToJunctionCenter{0.};    //! Remaining distance to the junction center, if directly connected

  std::vector<TurnDirections> mForwardTurnDirections;  //! Forward turn direction restrictions
  std::vector<TurnDirections> mBackwardTurnDirections; //! Backward turn direction restrictions

  RoadType mRoadType{RoadType::Invalid};

  MapDataId mPredecessor{InvalidId}; //! ID of previous element (if any), can be another road or an intersection
  MapDataId mSuccessor{InvalidId};   //! ID of succeeding element (if any), can be another road or an intersection

  Road() = delete;
  Road &operator=(Road const &other) = delete;

  Road(MapDataStore &dataStore, common::LogChannel &logChannel);

  /**
   * @brief Checks if all the polylines contained in this road are intersected by the line.
   * @return true when all the polylines intersect with the line
   */
  bool fullyIntersects(geometry::Line2d const &line) const;

  /**
   * @brief Cuts the road at the intersection point with the provided line.
   *
   * The operation is done in place, which means this road is modified.
   * if reverse = false, the road will keep all the points between the point 0 and the intersection point.
   * if reverse = true, the road will keep all the points between the last point and the intersection point.
   * @return true when the crop is successful
   */
  bool crop(geometry::Line2d const &line, bool reverse);

  /**
   * @brief Splits the road in two roads at the intersection point.
   *
   * if reverse = true, the returned road road with all the points between the point 0 and the intersection point.
   * if reverse = false, the returned road with all the points between the last point and the intersection point.
   * @return The id of the generated road
   */
  MapDataId split(geometry::Line2d const &line, bool reverse);

  /**
   * @brief Projects a point onto the road's geometry. Iterates over all the lane's borders and returns the nearest
   * point on it.
   *
   * @param point 2d point of interest
   * @returns the projection of the point onto the closest polyline.
   */
  geometry::Point2d findNearestPoint(geometry::Point2d const &point) const;

  /**
   * @brief calculate the direction at a given point
   *
   * Calculate direction orthogonal to the "tangent" at a given point. If the point is
   * between start and end of the road will return the bisecting angle. If the road is
   * connected, calculation will take into account position successor/predecessor.
   *
   * @return direction usable for shifting
   */
  geometry::Direction2d shiftingDirectionAtPoint(MapDataId pointId) const;

private:
  MapDataStore &mStore;
  common::LogChannel &mLog;
  std::vector<MapDataId> mCreatedLanes{};

  geometry::Polyline2d centerLineToGeometry() const;

  uint32_t considerPrevRoad(geometry::Polyline2d &polyLine) const;
  uint32_t considerNextRoad(geometry::Polyline2d &polyLine) const;

  MapDataId generateBorder(geometry::Polyline2d const &geometry,
                           uint32_t startIndex,
                           uint32_t endIndex,
                           MapDataId firstPoint,
                           MapDataId lastPoint) const;
  MapDataId beginOfRightForwardBorder(uint32_t index) const;
  MapDataId endOfRightForwardBorder(uint32_t index) const;
  MapDataId beginOfLeftBackwardBorder(uint32_t index) const;
  MapDataId endOfLeftBackwardBorder(uint32_t index) const;

  DrivingDirection calculateDrivingDirection(DrivingDirection nominalDrivingDirection) const;

  void assignLanesForRoad(MapDataId const otherId, bool otherIsSuccessor) const;
};

} // namespace map_data
} // namespace maker
} // namespace map
} // namespace ad
