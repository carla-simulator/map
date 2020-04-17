// ----------------- BEGIN LICENSE BLOCK ---------------------------------
//
// Copyright (C) 2018-2020 Intel Corporation
//
// SPDX-License-Identifier: MIT
//
// ----------------- END LICENSE BLOCK -----------------------------------

#pragma once

#include <boost/functional/hash.hpp>
#include <memory>
#include <unordered_map>
#include <unordered_set>

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wconversion"
#include <osmium/osm/types.hpp>
#pragma GCC diagnostic pop

#include <ad/map/maker/common/RightOfWay.hpp>
#include <ad/map/maker/geometry/Direction2d.hpp>
#include <ad/map/maker/geometry/Polyline2d.hpp>
#include <ad/map/maker/map_data/MapDataStore.hpp>
#include "ad/map/maker/osm_converter/OsmJunctionArm.hpp"
#include "ad/map/maker/osm_converter/OsmPoiExtractor.hpp"
#include "ad/map/maker/osm_converter/OsmProcessor.hpp"
#include "ad/map/maker/osm_converter/OsmToInternalMapping.hpp"
#include "ad/map/maker/osm_converter/OsmTransitionDetector.hpp"
#include "ad/map/maker/osm_converter/OsmWay.hpp"
#include "ad/map/maker/osm_converter/PoiType.hpp"

namespace ad {
namespace map {
namespace maker {

namespace common {
struct LogChannel;
class LogFactory;
} // namespace common

namespace osm_converter {

struct PointOfInterest;

struct RoadGeometry
{
  map_data::MapDataId roadId{map_data::InvalidId};
  OsmWay currentOsmWay;
  geometry::Polyline2d centerLineGeometry{};
  std::vector<::osmium::object_id_type> osmNodes;
};

/*
 * @brief Class for transfering data from OSM to MapData
 */
class OsmToInternalConverter
{
public:
  OsmToInternalConverter(OsmProcessor const &processor,
                         map_data::MapDataStore &mapDataStore,
                         common::LogFactory &logFactory);

  /**
   * @brief convert OSM data into internal map representation (map_data)
   */
  void convertMap(bool adjustLateralOffsetOfRoads);

private:
  typedef std::pair<::osmium::object_id_type, ::osmium::object_id_type> osmium_id_pair;

  OsmProcessor const &mOsmProcessor;
  std::shared_ptr<OsmJunctionProcessor> mJunctionProcessor;
  std::shared_ptr<PointStore> mPointStore;
  std::shared_ptr<OsmObjectStore> mObjectStore;
  map_data::MapDataStore &mMapDataStore;
  common::LogFactory &mLogFactory;
  common::LogChannel &mLog;
  OsmToInternalMapping mOsmMap;
  std::unordered_map<::osmium::object_id_type, map_data::MapDataId> mIntersectionMap;
  std::unordered_map<map_data::MapDataId, OsmTransitionDetector> mTransitionDetectors;
  bool mAdjustLateralOffsetOfRoads{false};

  struct IntersectionConnection
  {
    map_data::MapDataId intersectionId;
    map_data::MapDataId roadId;
    bool incoming;
    common::RightOfWay rightOfWay;
  };
  std::vector<IntersectionConnection> mIntersectionConnections;
  std::unordered_set<osmium_id_pair, ::boost::hash<osmium_id_pair>> mTraveledArms;
  std::unordered_set<::osmium::object_id_type> mProcessedTrafficLights;
  std::unordered_set<::osmium::object_id_type> mProcessedTrafficSigns;

  double const cTrafficLightDistanceToRoadBorder{1.0};   //!< in meters
  double const cTrafficLightDistanceToGround{3.0};       //!< distance to ground in meters
  double const cTrafficLightDistanceToGroundOffset{2.0}; //!< additional distance to ground
                                                         //!  in meters for traffic lanes above roads

  /**
   * @brief Process a junction.
   */
  void processJunction(::osmium::object_id_type const &junctionCenter);

  /**
   * @brief process the arm of an intersection and generate roads as necessary.
   *
   * Add all necessary intersection-road connections to mIntersectionConnections
   */
  void processArm(OsmJunctionArm const &osmArm);

  /**
   * @brief perform the connections of a Intersecion/road.
   */
  void connectRoad(map_data::MapDataId const &roadId,
                   ::osmium::object_id_type const &junctionCenter,
                   ::osmium::object_id_type const &connectionNode);

  /**
   * @brief Create new road succeeding currentRoadId
   */
  void setupSuccessorRoad(RoadGeometry &roadGeometry) const;

  /**
   * @brief Copy the info from the osmWay to the specified road.
   *
   * Set the widths of forward and backward lanes
   * Set the type of the road.
   * Set the turn lane constraints
   */
  void setRoadInfo(map_data::MapDataId const &roadId, OsmWay const &osmWay);

  /**
   * @brief Set the turn lane constraints from the osmWay to the specified road.
   */
  void setRoadTurnLanes(map_data::MapDataId const &roadId, OsmWay const &osmWay);

  void convertPois();

  /**
   * @brief converts valid traffic lights from OSM to internal map_data
   * @return true if the traffic light is valid, false otherwise
   */
  bool convertTrafficLight(::osmium::object_id_type const currentNodeId, RoadGeometry const &roadGeometry);

  double getTrafficLightOffsetForPlacement(map_data::Road const &road,
                                           bool const isForward,
                                           std::string const &placement,
                                           double const additionalLateralOffset) const;
  std::vector<geometry::Point2d>
  calculateTrafficLightPositions(::osmium::object_id_type currentNodeId,
                                 geometry::Direction2d const &shiftingDirection,
                                 map_data::Road const &road,
                                 OsmPoiExtractor::TrafficLightAttributes const &attributes) const;

  std::vector<RoadGeometry> mRoadsGeometry;
  std::size_t findRoadGeometry(map_data::MapDataId roadId) const;
  void addNodeToRoadGeometry(RoadGeometry &roadGeometry, ::osmium::object_id_type nodeId);

  /**
   * @brief convert geometrical centerline to road
   */
  void generateRoadGeometry(RoadGeometry &roadGeometry);

  /**
   * @brief Calculate the point that connects the road geometry with its successor
   */
  geometry::Point2d successorPoint(RoadGeometry const &roadGeometry);

  /**
   * @brief Calculate the point that connects the road geometry with its predecessor
   */
  geometry::Point2d predecessorPoint(RoadGeometry const &roadGeometry);

  /**
   * @brief Calculate the point that connects the road geometry with the successing intersection
   */
  geometry::Point2d successorIntersectionPoint(RoadGeometry const &roadGeometry);

  /**
   * @brief Calculate the point that connects the road geometry with the predecessing intersection
   */
  geometry::Point2d predecessorIntersectionPoint(RoadGeometry const &roadGeometry);

  void finishCurrentRoad(RoadGeometry &roadGeometry, bool setupSuccessor);

  void insertCrosswalk(map_data::IntersectionType crosswalkType,
                       map_data::MapDataId prevRoadId,
                       map_data::MapDataId currRoadId,
                       ::osmium::object_id_type prevOsmNode);

  void addTrafficSignsToRoad(::osmium::object_id_type const nodeIdOfSign, map_data::MapDataId const roadId);

  struct LandmarkOnCenterLine
  {
    ::osmium::object_id_type nodeId;
    map_data::MapDataId roadId;
  };
  std::vector<LandmarkOnCenterLine> mTrafficLights;
  void generateTrafficLight(LandmarkOnCenterLine const &data);

  std::vector<LandmarkOnCenterLine> mTrafficSigns;
  void generateTrafficSign(LandmarkOnCenterLine const &data);
};

} // namespace osm_converter
} // namespace maker
} // namespace map
} // namespace ad
