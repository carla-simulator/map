// ----------------- BEGIN LICENSE BLOCK ---------------------------------
//
// Copyright (C) 2018-2020 Intel Corporation
//
// SPDX-License-Identifier: MIT
//
// ----------------- END LICENSE BLOCK -----------------------------------

#include "ad/map/maker/admap_generator/AdMapGenerator.hpp"
#include <ad/map/access/Factory.hpp>
#include <ad/map/access/Types.hpp>
#include <ad/map/maker/common/LogChannel.hpp>
#include <ad/map/maker/common/LogFactory.hpp>
#include <ad/map/maker/geometry/Direction2d.hpp>
#include <ad/map/maker/geometry/Line2d.hpp>
#include <ad/map/maker/map_data/Landmark.hpp>
#include <ad/map/maker/map_data/Lane.hpp>
#include <ad/map/maker/map_data/MapDataStore.hpp>
#include <ad/map/point/Operation.hpp>
#include <ad/map/point/Transform.hpp>
#include <ad/map/point/Types.hpp>
#include <unordered_set>
#include "ad/map/maker/admap_generator/AdMapLandmarkTypeGenerator.hpp"

namespace ad {
namespace map {
namespace maker {
namespace admap_generator {

inline lane::LaneId toLaneId(map_data::MapDataId id)
{
  return lane::LaneId(id);
}

/**
 * @brief Take all data from MapDataStore and write as ADMap API data
 */
AdMapGenerator::AdMapGenerator(access::Factory &factory,
                               map_data::MapDataStore const &dataStore,
                               common::LogFactory &logFactory)
  : mFactory(factory)
  , mDataStore(dataStore)
  , mLog(logFactory.logChannel("AdMapGenerator"))
  , mCoordinateTransform(0., 0.)
{
}

void AdMapGenerator::addLanesOfIntersectionToSet(map_data::MapDataId const intersectionId,
                                                 std::unordered_set<map_data::MapDataId> &lanes) const
{
  for (auto const roadId : mDataStore.intersection(intersectionId).mRoads)
  {
    for (auto lane_id : mDataStore.road(roadId).mForwardLanes)
    {
      lanes.insert(lane_id);
    }
    for (auto lane_id : mDataStore.road(roadId).mBackwardLanes)
    {
      lanes.insert(lane_id);
    }
  }
}

::ad::map::lane::LaneDirection AdMapGenerator::drivingDirection(map_data::Lane const &lane)
{
  if (lane.drivingDirection == map_data::DrivingDirection::Forward)
  {
    return ::ad::map::lane::LaneDirection::POSITIVE;
  }
  else if (lane.drivingDirection == map_data::DrivingDirection::Backward)
  {
    return ::ad::map::lane::LaneDirection::NEGATIVE;
  }
  else
  {
    return ::ad::map::lane::LaneDirection::BIDIRECTIONAL;
  }
}

void AdMapGenerator::generateADMap()
{
  if (mDataStore.isLeftHandTraffic())
  {
    mFactory.set(access::TrafficType::LEFT_HAND_TRAFFIC);
  }
  else
  {
    mFactory.set(access::TrafficType::RIGHT_HAND_TRAFFIC);
  }

  // setup our CoordinateTransform. For that we simply take the first point in the store
  auto points = mDataStore.listOfPointIds();
  if (points.empty())
  {
    throw std::runtime_error("No points in store, cannot do anything!");
  }
  auto const &referencePoint = mDataStore.point(points.front());
  mCoordinateTransform = geometry::CoordinateTransform(referencePoint.y, referencePoint.x);
  // Keep track of the intersection lanes
  std::unordered_set<map_data::MapDataId> intersectionLanes;

  for (auto const &intersectionId : mDataStore.listOfIntersectionIds())
  {
    addLanesOfIntersectionToSet(intersectionId, intersectionLanes);
  }

  // First add all the lane's basic data to the MapStore
  for (auto const &lane_id : mDataStore.listOfLaneIds())
  {
    ::ad::map::lane::LaneType type{::ad::map::lane::LaneType::NORMAL};
    ::ad::map::lane::LaneDirection direction = drivingDirection(mDataStore.lane(lane_id));
    if (intersectionLanes.count(lane_id) > 0)
    {
      type = ::ad::map::lane::LaneType::INTERSECTION;
    }
    mFactory.add(access::PartitionId(0), toLaneId(lane_id), type, direction);
  }

  addLandmarks();

  for (auto const &roadId : mDataStore.listOfRoadIds())
  {
    processRoad(roadId);
  }
  try
  {
    setupOverlappingLanes();
  }
  catch (...)
  {
    mLog(common::LogLevel::Error) << "Overlapping lanes failed\n";
  }
  processIntersectionArms();

  addVisibleLandmarksToLanes();
}

void AdMapGenerator::processRoad(map_data::MapDataId const &internalRoadId)
{
  auto const &road = mDataStore.road(internalRoadId);
  for (std::size_t i = 0; i < road.mForwardLanes.size(); i++)
  {
    processLane(road.mForwardLanes[i], true);
    auto trafficLightIds = getLaneTrafficLights(internalRoadId, static_cast<int32_t>(i) + 1);
    for (auto id : trafficLightIds)
    {
      addTrafficLightContactToLane(road.mForwardLanes[i], id, true);
    }
  }
  for (std::size_t i = 0; i < road.mBackwardLanes.size(); i++)
  {
    processLane(road.mBackwardLanes[i], false);
    auto trafficLightIds = getLaneTrafficLights(internalRoadId, -1 - static_cast<int32_t>(i));
    for (auto id : trafficLightIds)
    {
      addTrafficLightContactToLane(road.mBackwardLanes[i], id, false);
    }
  }
}

std::vector<map_data::MapDataId> AdMapGenerator::getLaneTrafficLights(const map_data::MapDataId &roadId,
                                                                      int32_t laneIndex) const
{
  std::vector<map_data::MapDataId> trafficLightIds;
  for (auto id : mDataStore.road(roadId).mTrafficLights)
  {
    auto trafficLight = mDataStore.landmark(id);
    if (trafficLight.laneAssignments.count(laneIndex) == 1)
    {
      trafficLightIds.push_back(id);
    }
  }
  return trafficLightIds;
}

lane::ContactType toAdmContactBase(common::RightOfWay const &rightOfWay, bool usePrioToRightAndStraight)
{
  switch (rightOfWay)
  {
    using aact = lane::ContactType;
    case common::RightOfWay::Undefined:
      return aact::INVALID;
    case common::RightOfWay::Stop:
      return aact::STOP;
    case common::RightOfWay::GiveWay:
      return aact::YIELD;
    case common::RightOfWay::HasWay:
      return aact::FREE;
    case common::RightOfWay::AllWayStop:
      return aact::STOP_ALL;
    case common::RightOfWay::PriorityToRight:
      if (usePrioToRightAndStraight)
      {
        return aact::PRIO_TO_RIGHT_AND_STRAIGHT;
      }
      else
      {
        return aact::PRIO_TO_RIGHT;
      }
    case common::RightOfWay::Crosswalk:
      return aact::CROSSWALK;
    case common::RightOfWay::Ramp:
      return aact::FREE;
      // no default intended here! let the compiler detect if we missed a value!
  }
  // if the compiler doesn't catch a missing enum (e.g. warning disabled), throw at runtime
  throw(std::runtime_error("Unhandled enum value"));
}

void AdMapGenerator::processIntersectionArms()
{
  for (auto id : mDataStore.listOfIntersectionIds())
  {
    auto intersection = mDataStore.intersection(id);
    for (auto arm : intersection.mArms)
    {
      auto row = toAdmContactBase(arm.rightOfWay, mDataStore.isPrioToRightAndStraight()); // same for both directions
      using Location = lane::ContactLocation;

      if (arm.isEntry)
      {
        std::vector<map_data::MapDataId> const *forwardTrafficLanes;
        forwardTrafficLanes = &mDataStore.road(arm.connectedRoad).mForwardLanes;

        auto const &lanes = *forwardTrafficLanes;
        for (auto const &lane_id : lanes)
        {
          for (auto const &succId : mDataStore.lane(lane_id).successors)
          {
            mFactory.add(toLaneId(lane_id), toLaneId(succId), Location::SUCCESSOR, {row}, restriction::Restrictions());
          }
        }
      }
      else
      {
        std::vector<map_data::MapDataId> const *backwardTrafficLanes;
        backwardTrafficLanes = &mDataStore.road(arm.connectedRoad).mBackwardLanes;

        auto const &lanes = *backwardTrafficLanes;
        for (auto const &lane_id : lanes)
        {
          for (auto const &predId : mDataStore.lane(lane_id).predecessors)
          {
            mFactory.add(
              toLaneId(lane_id), toLaneId(predId), Location::PREDECESSOR, {row}, restriction::Restrictions());
          }
        }
      }
    }
  }
}

restriction::Restrictions createRoadRestrictions()
{
  restriction::Restriction roadRestriction;
  roadRestriction.road_user_types = restriction::RoadUserTypeList(
    {restriction::RoadUserType::CAR, restriction::RoadUserType::BUS, restriction::RoadUserType::TRUCK});
  restriction::Restrictions roadRestrictions;
  roadRestrictions.conjunctions = {roadRestriction};
  return roadRestrictions;
}

point::Geometry convertPolyLineToGeometry(map_data::MapDataStore const &store, map_data::MapDataId polyLine)
{
  point::ECEFPointList ecef_points;
  for (auto const &pointId : store.polyLine(polyLine).mNodes)
  {
    auto &mapPoint = store.point(pointId);
    point::Longitude lon(mapPoint.x);
    point::Latitude lat(mapPoint.y);
    point::Altitude alt(0.0);
    auto geo_point = point::createGeoPoint(lon, lat, alt);
    auto ecefPoint = point::toECEF(geo_point);
    ecef_points.push_back(ecefPoint);
  }
  return point::createGeometry(ecef_points, false);
}

void AdMapGenerator::setupLaneGeometry(map_data::MapDataId internalLaneId)
{
  lane::LaneId lane_id(internalLaneId);
  auto const &lane = mDataStore.lane(internalLaneId);
  point::Geometry leftBorderGeometry = convertPolyLineToGeometry(mDataStore, lane.leftBorder);
  point::Geometry rightBorderGeometry = convertPolyLineToGeometry(mDataStore, lane.rightBorder);
  mFactory.set(lane_id, leftBorderGeometry, rightBorderGeometry);
}

void AdMapGenerator::setupLaneContacts(map_data::MapDataId internalLaneId)
{
  lane::LaneId lane_id(internalLaneId);
  // set lane predecessors, successors, left and right neighbors
  auto leftNeighborId = mDataStore.lane(internalLaneId).left_neighbor;
  auto rightNeighborId = mDataStore.lane(internalLaneId).right_neighbor;

  lane::ContactTypeList const laneContinuation({lane::ContactType::LANE_CONTINUATION});
  lane::ContactTypeList const laneChange({lane::ContactType::LANE_CHANGE});
  auto roadRestrictions = createRoadRestrictions();

  lane::ContactLocation const succ(lane::ContactLocation::SUCCESSOR);
  lane::ContactLocation const pred(lane::ContactLocation::PREDECESSOR);
  lane::ContactLocation const left(lane::ContactLocation::LEFT);
  lane::ContactLocation const right(lane::ContactLocation::RIGHT);

  if (leftNeighborId != map_data::InvalidId)
  {
    mFactory.add(lane_id, toLaneId(leftNeighborId), left, laneChange, roadRestrictions);
  }
  if (rightNeighborId != map_data::InvalidId)
  {
    mFactory.add(lane_id, toLaneId(rightNeighborId), right, laneChange, roadRestrictions);
  }

  for (auto const &successorId : mDataStore.lane(internalLaneId).successors)
  {
    mFactory.add(lane_id, toLaneId(successorId), succ, laneContinuation, roadRestrictions);
  }
  for (auto const &predecessorId : mDataStore.lane(internalLaneId).predecessors)
  {
    mFactory.add(lane_id, toLaneId(predecessorId), pred, laneContinuation, roadRestrictions);
  }
}

void AdMapGenerator::setupLaneSpeedLimit(map_data::MapDataId internalLaneId, bool const forward)
{
  lane::LaneId lane_id(internalLaneId);
  auto const &lane = mDataStore.lane(internalLaneId);
  if (!mDataStore.hasRoad(lane.parentRoadId))
  {
    return;
  }
  auto const &road = mDataStore.road(lane.parentRoadId);
  if (forward)
  {
    mFactory.set(lane::LaneId(internalLaneId), physics::Speed(road.mForwardSpeedLimit));
  }
  else
  {
    mFactory.set(lane::LaneId(internalLaneId), physics::Speed(road.mBackwardSpeedLimit));
  }
}

void AdMapGenerator::processLane(map_data::MapDataId const &internalLaneId, bool const forward)
{
  mLog(common::LogLevel::Verbose) << "Processing Lane " << internalLaneId << " with polyline borders "
                                  << mDataStore.lane(internalLaneId).leftBorder << " | "
                                  << mDataStore.lane(internalLaneId).rightBorder << "\n";

  if (!mProcessedLanes.insert(internalLaneId).second)
  {
    throw std::runtime_error("lane already processed: " + std::to_string(internalLaneId));
  }
  setupLaneGeometry(internalLaneId);
  setupLaneContacts(internalLaneId);
  setupLaneSpeedLimit(internalLaneId, forward);
}

void AdMapGenerator::addTrafficLightContactToLane(map_data::MapDataId const &lane_id,
                                                  map_data::MapDataId const &internalTrafficLightId,
                                                  bool isForward)
{
  auto const id = mDataStore.landmark(internalTrafficLightId).index;
  landmark::LandmarkId trafficLightId(static_cast<uint64_t>(id));
  std::string directionString = (isForward ? "forward" : "backward");

  lane::ContactTypeList const laneContinuation({lane::ContactType::TRAFFIC_LIGHT});
  auto restrictions = createRoadRestrictions();

  lane::ContactLocation const succ(lane::ContactLocation::SUCCESSOR);
  lane::ContactLocation const pred(lane::ContactLocation::PREDECESSOR);

  for (auto const &successorId : mDataStore.lane(lane_id).successors)
  {
    mLog(common::LogLevel::Verbose) << "Adding traffic light " << id << " to contacts between Lane " << lane_id
                                    << " and " << successorId << " with direction " << directionString << "\n";
    // make sure that the successor is of type INTERSECTION to allow processing easily
    auto changeToIntersectionId = (isForward ? successorId : lane_id);
    (void)mFactory.add(access::PartitionId(0),
                       toLaneId(changeToIntersectionId),
                       ::ad::map::lane::LaneType::INTERSECTION,
                       drivingDirection(mDataStore.lane(changeToIntersectionId)));
    if (!mFactory.add(toLaneId(lane_id), toLaneId(successorId), succ, laneContinuation, restrictions, trafficLightId))
    {
      mLog(common::LogLevel::Error) << "Cannot add traffic light " << id << " to contact from Lane " << lane_id
                                    << " to " << successorId << "\n";
    }
    if (!mFactory.add(toLaneId(successorId), toLaneId(lane_id), pred, laneContinuation, restrictions, trafficLightId))
    {
      mLog(common::LogLevel::Error) << "Cannot add traffic light " << id << " to contact from Lane " << successorId
                                    << " to " << lane_id << "\n";
    }
  }
}

bool AdMapGenerator::isPointCloseToBorder(geometry::Point2d const &location,
                                          std::vector<geometry::Point2d> const &border) const
{
  if (border.empty())
  {
    return false;
  }
  for (std::size_t i = 0u; i < border.size() - 1u; ++i)
  {
    geometry::Line2d line(border[i], border[i + 1]);
    auto projection = line.lineProjection(location);
    if (projection < 0.)
    {
      if (location.squaredDistance(border[i]) < cSquaredVisibleDistance)
      {
        return true;
      }
    }
    else if (projection > 1.)
    {
      if (location.squaredDistance(border[i + 1]) < cSquaredVisibleDistance)
      {
        return true;
      }
    }
    else
    {
      return true;
    }
  }

  return false;
}

void AdMapGenerator::setupOverlappingLanes()
{
  // first run: collect all laneIds per intersection
  for (auto const intersectionId : mDataStore.listOfIntersectionIds())
  {
    std::unordered_set<map_data::MapDataId> lanes;
    addLanesOfIntersectionToSet(intersectionId, lanes);
    try
    {
      setupOverlappingLanesForIntersection(lanes);
    }
    catch (...)
    {
      mLog(common::LogLevel::Warning) << "Invalid lanes for intersection " << intersectionId
                                      << ". Overlapping lanes could not be generated.\n";
    }
  }
}

void AdMapGenerator::setupOverlappingLanesForIntersection(std::unordered_set<map_data::MapDataId> const &lanes)
{
  for (auto lane_id : lanes)
  {
    auto const &fromLane = mDataStore.lane(lane_id);
    for (auto otherLaneId : lanes)
    {
      if (lane_id != otherLaneId)
      {
        auto const &to_lane = mDataStore.lane(otherLaneId);
        if (fromLane.overlapsWithLane(mDataStore, to_lane))
        {
          mFactory.add(toLaneId(lane_id),
                       toLaneId(otherLaneId),
                       lane::ContactLocation::OVERLAP,
                       {lane::ContactType::UNKNOWN},
                       restriction::Restrictions());

          if (fromLane.hasRightContactWithLane(mDataStore, to_lane))
          {
            mFactory.add(toLaneId(lane_id),
                         toLaneId(otherLaneId),
                         lane::ContactLocation::RIGHT,
                         {lane::ContactType::UNKNOWN},
                         restriction::Restrictions());
          }
          else if (fromLane.hasLeftContactWithLane(mDataStore, to_lane))
          {
            mFactory.add(toLaneId(lane_id),
                         toLaneId(otherLaneId),
                         lane::ContactLocation::LEFT,
                         {lane::ContactType::UNKNOWN},
                         restriction::Restrictions());
          }
        }
      }
    }
  }
}

landmark::TrafficLightType toAdmTrafficLight(map_data::Landmark const &landmark)
{
  if (landmark.supplement == "s")
  {
    return landmark::TrafficLightType::STRAIGHT_RED_YELLOW_GREEN;
  }
  else if (landmark.supplement == "r")
  {
    return landmark::TrafficLightType::RIGHT_RED_YELLOW_GREEN;
  }
  else if (landmark.supplement == "l")
  {
    return landmark::TrafficLightType::LEFT_RED_YELLOW_GREEN;
  }
  else if (landmark.supplement == "ls")
  {
    return landmark::TrafficLightType::LEFT_STRAIGHT_RED_YELLOW_GREEN;
  }
  else if (landmark.supplement == "rs")
  {
    return landmark::TrafficLightType::RIGHT_STRAIGHT_RED_YELLOW_GREEN;
  }
  else if (landmark.supplement == "f")
  {
    return landmark::TrafficLightType::SOLID_RED_YELLOW_GREEN;
  }
  else if (landmark.supplement == "p")
  {
    return landmark::TrafficLightType::PEDESTRIAN_RED_GREEN;
  }
  else if (landmark.supplement == "b")
  {
    return landmark::TrafficLightType::BIKE_RED_GREEN;
  }
  else if (landmark.supplement == "pb")
  {
    return landmark::TrafficLightType::BIKE_PEDESTRIAN_RED_GREEN;
  }
  else if (landmark.supplement == "2f")
  {
    return landmark::TrafficLightType::SOLID_RED_YELLOW;
  }
  else
  {
    throw(std::runtime_error("Unhandled traffic light configuration " + landmark.supplement));
  }
}

void AdMapGenerator::fillLandmarkData(map_data::Landmark const &landmark, LandmarkData &data) const
{
  auto &mapPoint = mDataStore.point(landmark.location);
  point::Longitude lon(mapPoint.x);
  point::Latitude lat(mapPoint.y);
  point::Altitude alt(0.0 + landmark.heightOverGround);
  auto geo_point = point::createGeoPoint(lon, lat, alt);
  data.position = point::toECEF(geo_point);
  auto orientationAsPoint = geometry::Direction2d(landmark.orientation + M_PI).orientationAsPoint();
  // all coordinates are lat/lon. To calculate the orientation, we have to transform position back
  // to a metric position
  const auto localCoordinateTransform
    = geometry::CoordinateTransform(static_cast<double>(lat), static_cast<double>(lon));
  double orientationLat = 0.;
  double orientationLon = 0.;
  localCoordinateTransform.metricToGcs(orientationAsPoint.x, orientationAsPoint.y, orientationLat, orientationLon);
  data.orientation
    = point::toECEF(point::createGeoPoint(point::Longitude(orientationLon), point::Latitude(orientationLat), alt));
}

void AdMapGenerator::storeGeneratedLandmark(map_data::MapDataId const landmark_id, geometry::Point2d const &location)
{
  LandmarkEntry entry;
  entry.id = landmark_id;
  mCoordinateTransform.gcsToMetric(location.y, location.x, entry.location.x, entry.location.y);
  mGeneratedLandmarks.push_back(entry);
}

void AdMapGenerator::generateLandmark(map_data::Landmark const &landmark)
{
  // @todo make sure that we don't re-use an id of a landmark (as specified for traffic lights
  // crosswalks will not be added as landmark
  if (landmark.type == map_data::LandmarkType::Crosswalk)
  {
    return;
  }
  LandmarkData data;
  fillLandmarkData(landmark, data);
  point::Geometry bounding_box; // @todo fill with meaningful data, do we need this info?
  landmark::LandmarkId landmark_id(landmark.index);
  access::PartitionId part(0);
  if (landmark.type == map_data::LandmarkType::TrafficLight)
  {
    landmark::TrafficLightType type = toAdmTrafficLight(landmark);
    if (mFactory.addTrafficLight(part, landmark_id, type, data.position, data.orientation, bounding_box))
    {
      mLog(common::LogLevel::Verbose) << "Adding traffic light with id " << static_cast<uint64_t>(landmark_id) << "\n";
      storeGeneratedLandmark(static_cast<uint64_t>(landmark_id), mDataStore.point(landmark.location));
    }
    else
    {
      mLog(common::LogLevel::Warning) << "Unable to add traffic light " << static_cast<uint64_t>(landmark_id)
                                      << " to store!\n";
    }
  }
  else
  {
    auto traffic_sign_type = trafficSignToAdMap(landmark.type);

    if (traffic_sign_type != landmark::TrafficSignType::UNKNOWN)
    {
      std::string supplement("None");
      if (!landmark.supplement.empty())
      {
        supplement = landmark.supplement;
      }
      if (mFactory.addTrafficSign(
            part, landmark_id, traffic_sign_type, data.position, data.orientation, bounding_box, supplement))
      {
        mLog(common::LogLevel::Verbose) << "Adding traffic sign with id " << static_cast<uint64_t>(landmark_id) << "\n";
        storeGeneratedLandmark(static_cast<uint64_t>(landmark_id), mDataStore.point(landmark.location));
      }
      else
      {
        mLog(common::LogLevel::Warning) << "Unable to add traffic sign " << static_cast<uint64_t>(landmark_id)
                                        << " to store!\n";
      }
    }
    else
    {
      // a "normal" landmark
      auto landmarkType = landmarkTypeToAdMap(landmark.type);
      if (mFactory.addLandmark(part, landmark_id, landmarkType, data.position, data.orientation, bounding_box))
      {
        mLog(common::LogLevel::Verbose) << "Adding generic landmark with id " << static_cast<uint64_t>(landmark_id)
                                        << "\n";

        storeGeneratedLandmark(static_cast<uint64_t>(landmark_id), mDataStore.point(landmark.location));
      }
      else
      {
        mLog(common::LogLevel::Warning) << "Unable to add landmark " << static_cast<uint64_t>(landmark_id)
                                        << " to store!\n";
      }
    }
  }
}

void AdMapGenerator::addLandmarks()
{
  for (auto landmark_id : mDataStore.listOfLandmarkIds())
  {
    auto const &landmark = mDataStore.landmark(landmark_id);
    generateLandmark(landmark);
  }
}

std::vector<geometry::Point2d> AdMapGenerator::transformPolyline(map_data::MapDataId const borderId) const
{
  auto const &border = mDataStore.polyLine(borderId).mNodes;
  std::vector<geometry::Point2d> result;
  for (auto id : border)
  {
    auto const &point = mDataStore.point(id);
    geometry::Point2d transformed;
    mCoordinateTransform.gcsToMetric(point.y, point.x, transformed.x, transformed.y);
    result.push_back(transformed);
  }
  return result;
}

void AdMapGenerator::addVisibleLandmarksToLanes()
{
  for (auto lane_id : mDataStore.listOfLaneIds())
  {
    auto const &lane = mDataStore.lane(lane_id);
    auto leftBorder = transformPolyline(lane.leftBorder);
    auto rightBorder = transformPolyline(lane.rightBorder);
    for (auto const &landmarkEntry : mGeneratedLandmarks)
    {
      if (isPointCloseToBorder(landmarkEntry.location, leftBorder)
          || isPointCloseToBorder(landmarkEntry.location, rightBorder))
      {
        mFactory.add(lane::LaneId(lane_id), landmark::LandmarkId(landmarkEntry.id));
      }
    }
  }
}

} // namespace admap_generator
} // namespace maker
} // namespace map
} // namespace ad
