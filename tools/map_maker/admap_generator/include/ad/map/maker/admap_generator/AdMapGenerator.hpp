// ----------------- BEGIN LICENSE BLOCK ---------------------------------
//
// Copyright (C) 2018-2020 Intel Corporation
//
// SPDX-License-Identifier: MIT
//
// ----------------- END LICENSE BLOCK -----------------------------------

#pragma once

#include <ad/map/lane/Types.hpp>
#include <ad/map/maker/geometry/CoordinateTransform.hpp>
#include <ad/map/maker/geometry/Point2d.hpp>
#include <ad/map/maker/map_data/MapDataId.hpp>
#include <ad/map/point/Types.hpp>
#include <unordered_set>
#include <vector>

namespace ad {
namespace map {

namespace access {
class Factory;
} // namespace access

namespace maker {

namespace common {
struct LogChannel;
class LogFactory;
} // namespace common

namespace map_data {
class MapDataStore;
struct PolyLine;
struct Landmark;
struct Lane;
} // namespace map_data

namespace admap_generator {

/**
 * @brief Take all data from MapDataStore and write as ADMap API data
 */
struct AdMapGenerator
{
  AdMapGenerator(access::Factory &factory, map_data::MapDataStore const &dataStore, common::LogFactory &logFactory);

  void generateADMap();

private:
  access::Factory &mFactory;
  map_data::MapDataStore const &mDataStore;
  common::LogChannel &mLog;
  std::unordered_set<map_data::MapDataId> mProcessedLanes;
  geometry::CoordinateTransform mCoordinateTransform;

  void processRoad(map_data::MapDataId const &internalRoadId);
  void processLane(map_data::MapDataId const &internalLaneId, bool const forward);
  void processIntersectionArms();
  void setupOverlappingLanes();
  void setupOverlappingLanesForIntersection(std::unordered_set<map_data::MapDataId> const &lanes);

  void addLanesOfIntersectionToSet(map_data::MapDataId const intersectionId,
                                   std::unordered_set<map_data::MapDataId> &lanes) const;

  /**
   * @brief Check if the landmark is within a certain range of a lane.
   * @param[in] location position of the landmark
   * @param[in] border of the lane to be checked
   * @return true if the landmark is within the range, false otherwise
   */
  bool isPointCloseToBorder(geometry::Point2d const &location, std::vector<geometry::Point2d> const &border) const;
  double const cSquaredVisibleDistance{2500.}; // when is a landmark considered as being visible from a lane?

  /**
   * @brief Extract all traffic lights that are associated to a given lane.
   * @param[in] roadId is the road identifier to which the lane belongs
   * @param[in] laneIndex is the index of the lane within the road (either forward lanes, or backward lanes)
   * @return extracted set of traffic lights
   */
  std::vector<map_data::MapDataId> getLaneTrafficLights(const map_data::MapDataId &roadId, int32_t laneIndex) const;

  /**
   * @brief Add the traffic light given by internalTrafficLightId as contact to the lane given by internalLaneId.
   *        Contacts are created for all lane --> successor pairs and for all successor --> lane pairs.
   * @param internalLaneId is the lane identifier
   * @param internalTrafficLightId is the traffic light identifier
   */
  void addTrafficLightContactToLane(map_data::MapDataId const &internalLaneId,
                                    map_data::MapDataId const &internalTrafficLightId,
                                    bool isForward);

  void setupLaneGeometry(map_data::MapDataId internalLaneId);
  void setupLaneContacts(map_data::MapDataId internalLaneId);
  void setupLaneSpeedLimit(map_data::MapDataId internalLaneId, bool const forward);
  void addLandmarks();
  void generateLandmark(map_data::Landmark const &landmark);
  struct LandmarkData
  {
    point::ECEFPoint position;
    point::ECEFPoint orientation;
  };
  void fillLandmarkData(map_data::Landmark const &landmark, LandmarkData &data) const;

  struct LandmarkEntry
  {
    uint64_t id; // the id as it is used inside admap
    geometry::Point2d location;
  };
  //! holds all generated landmarks
  std::vector<LandmarkEntry> mGeneratedLandmarks;
  void addVisibleLandmarksToLanes();
  void storeGeneratedLandmark(map_data::MapDataId const landmarkId, geometry::Point2d const &location);
  std::vector<geometry::Point2d> transformPolyline(map_data::MapDataId const borderId) const;

  //! Convert internal driving direction to admap driving direction
  ::ad::map::lane::LaneDirection drivingDirection(map_data::Lane const &lane);
};

} // namespace admap_generator
} // namespace maker
} // namespace map
} // namespace ad
