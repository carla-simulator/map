// ----------------- BEGIN LICENSE BLOCK ---------------------------------
//
// Copyright (C) 2018-2020 Intel Corporation
//
// SPDX-License-Identifier: MIT
//
// ----------------- END LICENSE BLOCK -----------------------------------

#include "ad/map/maker/osm_converter/OsmToInternalConverter.hpp"
#include <ad/map/maker/common/LogChannel.hpp>
#include <ad/map/maker/common/LogFactory.hpp>
#include <ad/map/maker/common/OsmConverterConfig.hpp>
#include <ad/map/maker/common/StringHelper.hpp>
#include <ad/map/maker/map_data/Intersection.hpp>
#include <ad/map/maker/map_data/PolyLineConversion.hpp>
#include "ad/map/maker/osm_converter/OsmJunctionProcessor.hpp"
#include "ad/map/maker/osm_converter/OsmObjectStore.hpp"
#include "ad/map/maker/osm_converter/OsmProcessor.hpp"
#include "ad/map/maker/osm_converter/OsmWayProcessor.hpp"
#include "ad/map/maker/osm_converter/OsmWayTraveler.hpp"
#include "ad/map/maker/osm_converter/PointOfInterest.hpp"
#include "ad/map/maker/osm_converter/PointStore.hpp"

namespace ad {
namespace map {
namespace maker {
namespace osm_converter {

OsmToInternalConverter::OsmToInternalConverter(OsmProcessor const &processor,
                                               map_data::MapDataStore &mapDataStore,
                                               common::LogFactory &logFactory)
  : mOsmProcessor(processor)
  , mJunctionProcessor(mOsmProcessor.junctionProcessor())
  , mPointStore(mOsmProcessor.pointStore())
  , mObjectStore(mOsmProcessor.objectStore())
  , mMapDataStore(mapDataStore)
  , mLogFactory(logFactory)
  , mLog(logFactory.logChannel("OsmToMapData"))
  , mOsmMap(*(processor.pointStore().get()), mapDataStore, logFactory)
{
}

void OsmToInternalConverter::convertMap(bool adjustLateralOffsetOfRoads)
{
  mLog(common::LogLevel::Info) << "Converting map...\n";
  mAdjustLateralOffsetOfRoads = adjustLateralOffsetOfRoads;
  auto junctions = mOsmProcessor.junctionProcessor()->allJunctions();

  // First add all junctions to the MapStore so later we can reference them while creating the roads
  for (auto junctionCenter : junctions)
  {
    map_data::Intersection newIntersection(mMapDataStore, mLogFactory);
    newIntersection.mCenterPointId = mOsmMap.addNodeToMap(junctionCenter);
    newIntersection.mIntersectionType = map_data::IntersectionType::Regular;
    auto mapDataId = mMapDataStore.addIntersection(newIntersection);
    mIntersectionMap.insert(std::make_pair(junctionCenter, mapDataId));
    mLog(common::LogLevel::Verbose) << " Map junction { " << junctionCenter << " -> " << mapDataId << "} \n";
  }

  // Process all the junctions and their arms
  for (auto junctionCenter : junctions)
  {
    processJunction(junctionCenter);
  }

  // Iterate over the mIntersectionConnections and connect roads to intersections
  for (auto connection : mIntersectionConnections)
  {
    auto const &intersectionId = connection.intersectionId;
    auto const &roadId = connection.roadId;
    auto const &incoming = connection.incoming;
    auto const &rightOfWay = connection.rightOfWay;
    mLog(common::LogLevel::Verbose) << " Connecting intersection " << intersectionId << " with road " << roadId
                                    << " \n";
    if (incoming)
    {
      if (mMapDataStore.intersection(intersectionId).addIncomingRoad(roadId, rightOfWay))
      {
        mLog(common::LogLevel::Verbose) << "Intersection connected\n";
      }
    }
    else
    {
      if (mMapDataStore.intersection(intersectionId).addOutgoingRoad(roadId, rightOfWay))
      {
        mLog(common::LogLevel::Verbose) << "Intersection connected\n";
      }
    }
  }

  for (auto &road : mRoadsGeometry)
  {
    generateRoadGeometry(road);
  }

  for (auto const &intersectionId : mMapDataStore.listOfIntersectionIds())
  {
    auto &intersection = mMapDataStore.intersection(intersectionId);
    intersection.generateCenter();
  }
  for (auto const &trafficLight : mTrafficLights)
  {
    generateTrafficLight(trafficLight);
  }
  for (auto const &trafficSign : mTrafficSigns)
  {
    generateTrafficSign(trafficSign);
  }
  convertPois();
}

void OsmToInternalConverter::processJunction(::osmium::object_id_type const &junctionCenter)
{
  mLog(common::LogLevel::Verbose) << "Processing intersection " << junctionCenter << "\n";

  auto osmJunctionEntries = mJunctionProcessor->junctionArms(junctionCenter);
  for (auto osmArm : osmJunctionEntries)
  {
    mLog(common::LogLevel::Verbose) << "  Processing next junction arm " << osmArm.mArmId << " \n";

    if (mTraveledArms.insert(osmium_id_pair(junctionCenter, osmArm.mArmId)).second)
    {
      mTraveledArms.insert(osmium_id_pair(osmArm.mArmId, junctionCenter));
      processArm(osmArm);
    }
    else
    {
      mLog(common::LogLevel::Verbose) << "    Already processed arm with way " << osmArm.mWayId << " \n";
    }
  }
}

void OsmToInternalConverter::addNodeToRoadGeometry(RoadGeometry &roadGeometry, ::osmium::object_id_type nodeId)
{
  roadGeometry.centerLineGeometry.points.push_back(mOsmMap.fromOsmPoint(nodeId));
  roadGeometry.osmNodes.push_back(nodeId);
  mOsmMap.addPointForNode(nodeId, roadGeometry.centerLineGeometry.points.back());
}

void OsmToInternalConverter::processArm(OsmJunctionArm const &osmArm)
{
  auto crosswalks = mOsmProcessor.poiExtractor()->getPois(PoiType::Crosswalk);
  auto pelicanCrossings = mOsmProcessor.poiExtractor()->getPois(PoiType::PelicanCrossing);
  auto trafficLights = mOsmProcessor.poiExtractor()->getPois(PoiType::TrafficLight);
  auto wayProcessor = mOsmProcessor.wayProcessor();
  OsmWayTraveler traveler(mObjectStore, mJunctionProcessor, mPointStore, osmArm, mLogFactory.logChannel("Iterator"));
  RoadGeometry roadGeometry;
  roadGeometry.currentOsmWay = wayProcessor->osmWay(traveler.currentWay());
  roadGeometry.roadId = mMapDataStore.createRoad(mLogFactory.logChannel("Road"));
  setRoadInfo(roadGeometry.roadId, roadGeometry.currentOsmWay);

  mLog(common::LogLevel::Verbose) << "  Add intersection connection for Intersection "
                                  << mIntersectionMap[osmArm.mCenterId] << " with road " << roadGeometry.roadId
                                  << " \n";

  addNodeToRoadGeometry(roadGeometry, traveler.previousNode());
  addTrafficSignsToRoad(traveler.previousNode(), roadGeometry.roadId);

  if (mJunctionProcessor->isJunctionCenter(traveler.previousNode()))
  {
    mLog(common::LogLevel::Verbose) << "  starting at junction center on node: " << traveler.currentNode()
                                    << " coming from " << traveler.previousNode() << "\n";
    connectRoad(roadGeometry.roadId, traveler.previousNode(), traveler.currentNode());
  }

  do
  {
    mLog(common::LogLevel::Verbose) << "    WayId " << roadGeometry.currentOsmWay.mWayId << " with f/b ("
                                    << roadGeometry.currentOsmWay.mForwardLanes.mWidths.size() << "|"
                                    << roadGeometry.currentOsmWay.mBackwardLanes.mWidths.size() << ") - "
                                    << roadGeometry.currentOsmWay.mLayer << " | "
                                    << "from " << traveler.previousNode() << " to " << traveler.currentNode()
                                    << " on road " << roadGeometry.roadId
                                    << " offset: " << roadGeometry.currentOsmWay.offset() << "\n";

    if (traveler.wayHasChanged())
    {
      OsmWay oldWay = roadGeometry.currentOsmWay;
      roadGeometry.currentOsmWay = wayProcessor->osmWay(traveler.currentWay());
      mLog(common::LogLevel::Verbose) << "  way changed to " << roadGeometry.currentOsmWay.mWayId << " \n";
      if (roadGeometry.currentOsmWay.hasDifferentAttributes(oldWay))
      {
        mLog(common::LogLevel::Verbose) << "Way attributes changed\n";
        finishCurrentRoad(roadGeometry, !traveler.endReached());
      }
      else
      {
        setRoadTurnLanes(roadGeometry.roadId, roadGeometry.currentOsmWay);
      }
    }

    addNodeToRoadGeometry(roadGeometry, traveler.currentNode());
    addTrafficSignsToRoad(traveler.currentNode(), roadGeometry.roadId);

    // if node is a traffic light, split the roads and add the traffic light as landmark
    if (convertTrafficLight(traveler.currentNode(), roadGeometry))
    {
      mLog(common::LogLevel::Verbose) << "  created traffic light(s) an node: " << traveler.currentNode() << "\n";
      finishCurrentRoad(roadGeometry, !traveler.endReached());
    }

    if (mJunctionProcessor->isJunctionCenter(traveler.currentNode()))
    {
      mLog(common::LogLevel::Verbose) << "  hit junction center on node: " << traveler.currentNode() << " coming from "
                                      << traveler.previousNode() << "\n";
      connectRoad(roadGeometry.roadId, traveler.currentNode(), traveler.previousNode());
      finishCurrentRoad(roadGeometry, !traveler.endReached());
      return;
    }

    // what if a crosswalk is located at an intersection?
    if ((crosswalks.count(traveler.currentNode()) > 0) || (pelicanCrossings.count(traveler.currentNode()) > 0))
    {
      mLog(common::LogLevel::Verbose) << "  hit crosswalk on node: " << traveler.currentNode() << " coming from "
                                      << traveler.previousNode() << "\n";
      // Save current road, create Intersetion of type crosswalk, connect previous road, create and connect next road
      auto previousRoadId = roadGeometry.roadId;
      finishCurrentRoad(roadGeometry, !traveler.endReached());
      auto crosswalkType = map_data::IntersectionType::CrosswalkZebra;
      if (pelicanCrossings.count(traveler.currentNode()) > 0)
      {
        crosswalkType = map_data::IntersectionType::CrosswalkPelican;
      }
      insertCrosswalk(crosswalkType, previousRoadId, roadGeometry.roadId, traveler.previousNode());
    }
  } while (traveler.stillTraveling());

  // only add the current roadGeoemtry if if represents a valid road
  if (mRoadsGeometry.size() > 0)
  {
    auto const &lastElem = mRoadsGeometry.back();
    if (lastElem.roadId == roadGeometry.roadId)
    {
      mLog(common::LogLevel::Verbose) << " Adding road geometry for a second time!\n";
    }
  }
  mRoadsGeometry.push_back(roadGeometry);
}

void OsmToInternalConverter::insertCrosswalk(map_data::IntersectionType crosswalkType,
                                             map_data::MapDataId prevRoadId,
                                             map_data::MapDataId currRoadId,
                                             ::osmium::object_id_type prevOsmNode)
{
  map_data::Intersection crosswalkIntersection(mMapDataStore, mLogFactory);
  crosswalkIntersection.mIntersectionType = crosswalkType;
  auto mapDataId = mMapDataStore.addIntersection(crosswalkIntersection);
  mIntersectionConnections.push_back({mapDataId, prevRoadId, true, common::RightOfWay::Crosswalk});
  mIntersectionConnections.push_back({mapDataId, currRoadId, false, common::RightOfWay::Crosswalk});
  mIntersectionMap.insert(std::make_pair(prevOsmNode, mapDataId));
}

void OsmToInternalConverter::finishCurrentRoad(RoadGeometry &roadGeometry, bool setupSuccessor)
{
  // only push it if we have at least two points in, otherwise keep it
  if (roadGeometry.centerLineGeometry.points.size() > 1)
  {
    mRoadsGeometry.push_back(roadGeometry);
    // only set up a successor when there really is a successor
    if (setupSuccessor)
    {
      setupSuccessorRoad(roadGeometry);
      setRoadInfo(roadGeometry.roadId, roadGeometry.currentOsmWay);
    }
  }
  else
  {
    mLog(common::LogLevel::Info) << "Empty road - re-using\n";
  }
}

double startOffset(map_data::Road const &road)
{
  // @todo currently equal to endOffset
  if (road.mBackwardWidths.size() > 0u)
  {
    return 0.0;
  }
  return (road.forwardWidth() / 2.);
}

double endOffset(map_data::Road const &road)
{
  // @todo currently equal to startOffset
  if (road.mBackwardWidths.size() > 0u)
  {
    return 0.0;
  }
  return (road.forwardWidth() / 2.);
}

double roadOffset(map_data::Road const &road)
{
  return 0.5 * startOffset(road) + 0.5 * endOffset(road);
}

std::size_t OsmToInternalConverter::findRoadGeometry(map_data::MapDataId roadId) const
{
  for (std::size_t index = 0; index < mRoadsGeometry.size(); ++index)
  {
    if (mRoadsGeometry[index].roadId == roadId)
    {
      return index;
    }
  }
  throw std::runtime_error("Unable to find geometry for roadId");
}

geometry::Point2d OsmToInternalConverter::successorPoint(RoadGeometry const &roadGeometry)
{
  auto const &road = mMapDataStore.road(roadGeometry.roadId);
  double offsetAtEnd = (mAdjustLateralOffsetOfRoads ? endOffset(road) : 0.);

  auto const &geometryPoints = roadGeometry.centerLineGeometry.points;
  auto const &successorRoad = mMapDataStore.road(road.mSuccessor);
  auto const &successorGeometry = mRoadsGeometry[findRoadGeometry(road.mSuccessor)];
  auto const &successorGeometryPoints = successorGeometry.centerLineGeometry.points;
  auto const successorOffset = (mAdjustLateralOffsetOfRoads ? startOffset(successorRoad) : 0.);

  auto const &previousPoint = geometryPoints[geometryPoints.size() - 2];
  auto const &centerPoint = geometryPoints[geometryPoints.size() - 1];
  auto const &nextPoint = successorGeometryPoints[1];

  auto const totalOffset = 0.5 * offsetAtEnd + 0.5 * successorOffset;
  auto const contactPoint = geometry::threePointShift(previousPoint, centerPoint, nextPoint, totalOffset);
  return contactPoint;
}

geometry::Point2d OsmToInternalConverter::predecessorPoint(RoadGeometry const &roadGeometry)
{
  auto const &road = mMapDataStore.road(roadGeometry.roadId);
  double offsetAtStart = (mAdjustLateralOffsetOfRoads ? startOffset(road) : 0.);

  auto const &geometryPoints = roadGeometry.centerLineGeometry.points;
  auto const &predecessorRoad = mMapDataStore.road(road.mPredecessor);
  auto const &predecessorGeometry = mRoadsGeometry[findRoadGeometry(road.mPredecessor)];
  auto const &predecessorGeometryPoints = predecessorGeometry.centerLineGeometry.points;
  auto const predecessorOffset = (mAdjustLateralOffsetOfRoads ? endOffset(predecessorRoad) : 0.);

  auto const &previousPoint = predecessorGeometryPoints[predecessorGeometryPoints.size() - 2];
  auto const &centerPoint = geometryPoints[0];
  auto const &nextPoint = geometryPoints[1];

  auto const totalOffset = 0.5 * offsetAtStart + 0.5 * predecessorOffset;
  auto const contactPoint = geometry::threePointShift(previousPoint, centerPoint, nextPoint, totalOffset);
  return contactPoint;
}

geometry::Point2d OsmToInternalConverter::successorIntersectionPoint(RoadGeometry const &roadGeometry)
{
  auto const &road = mMapDataStore.road(roadGeometry.roadId);
  auto const &geometryPoints = roadGeometry.centerLineGeometry.points;

  auto const intersectionId = road.mSuccessor;
  mTransitionDetectors[intersectionId].generateTransitionOffsets(mMapDataStore, mRoadsGeometry, intersectionId);
  double const transitionOffset = mTransitionDetectors[intersectionId].transitionOffsetForRoad(roadGeometry.roadId);
  double const offset = (mAdjustLateralOffsetOfRoads ? transitionOffset : 0);
  auto const &point = geometryPoints[geometryPoints.size() - 1];
  geometry::Point2d contactPoint;
  if (road.mRoadType == map_data::RoadType::Link)
  {
    double const orientation = mTransitionDetectors[intersectionId].transitionOffsetAngleForRoad(roadGeometry.roadId);
    contactPoint = geometry::orthogonalShift(point, orientation, offset);
  }
  else
  {
    auto const &referencePoint = geometryPoints[geometryPoints.size() - 2];
    contactPoint = geometry::twoPointShift(point, referencePoint, offset);
  }
  return contactPoint;
}

geometry::Point2d OsmToInternalConverter::predecessorIntersectionPoint(RoadGeometry const &roadGeometry)
{
  auto const &road = mMapDataStore.road(roadGeometry.roadId);
  auto const &geometryPoints = roadGeometry.centerLineGeometry.points;

  auto const intersectionId = road.mPredecessor;
  mTransitionDetectors[intersectionId].generateTransitionOffsets(mMapDataStore, mRoadsGeometry, intersectionId);
  double const transitionOffset = mTransitionDetectors[intersectionId].transitionOffsetForRoad(roadGeometry.roadId);
  double const offset = (mAdjustLateralOffsetOfRoads ? transitionOffset : 0);
  geometry::Point2d contactPoint;
  auto const &point = geometryPoints[0];
  if (road.mRoadType == map_data::RoadType::Link)
  {
    double const orientation = mTransitionDetectors[intersectionId].transitionOffsetAngleForRoad(roadGeometry.roadId);
    contactPoint = geometry::orthogonalShift(point, orientation, -offset);
  }
  else
  {
    auto const &referencePoint = geometryPoints[1];
    contactPoint = twoPointShift(point, referencePoint, -offset);
  }
  return contactPoint;
}

void OsmToInternalConverter::generateRoadGeometry(RoadGeometry &roadGeometry)
{
  auto const &geometryPoints = roadGeometry.centerLineGeometry.points;

  if (geometryPoints.size() < 2)
  {
    mLog(common::LogLevel::Warning) << "Centerline does not have enough points\n";
    return;
  }
  auto const &road = mMapDataStore.road(roadGeometry.roadId);
  double offsetAtStart = (mAdjustLateralOffsetOfRoads ? startOffset(road) : 0.);
  double offsetAtEnd = (mAdjustLateralOffsetOfRoads ? endOffset(road) : 0.);

  mLog(common::LogLevel::Verbose) << "  Using offsets start " << offsetAtStart << " end " << offsetAtEnd << "\n";
  geometry::Polyline2d shiftedCenterLine;
  if (!roadGeometry.centerLineGeometry.shift(offsetAtStart, offsetAtEnd, shiftedCenterLine, mLog))
  {
    mLog(common::LogLevel::Warning) << "Error adjusting centerline\n";
  }

  if (mMapDataStore.hasRoad(road.mPredecessor))
  {
    shiftedCenterLine.points.front() = predecessorPoint(roadGeometry);
  }
  if (mMapDataStore.hasRoad(road.mSuccessor))
  {
    shiftedCenterLine.points.back() = successorPoint(roadGeometry);
  }
  if (mMapDataStore.hasIntersection(road.mPredecessor))
  {
    shiftedCenterLine.points.front() = predecessorIntersectionPoint(roadGeometry);
  }
  if (mMapDataStore.hasIntersection(road.mSuccessor))
  {
    shiftedCenterLine.points.back() = successorIntersectionPoint(roadGeometry);
  }

  map_data::PolyLine centerLine = map_data::geometryToPolyline(mMapDataStore, shiftedCenterLine);

  mMapDataStore.road(roadGeometry.roadId).mCenterLineId = mMapDataStore.addPolyLine(centerLine);
  for (std::size_t index = 0u; index < roadGeometry.osmNodes.size(); ++index)
  {
    mOsmMap.addNodeMappingAndPoint(
      roadGeometry.osmNodes[index], centerLine.mNodes[index], shiftedCenterLine.points[index]);
  }

  mLog(common::LogLevel::Verbose) << "  Resulting polyline:\n";
  for (auto pointId : centerLine.mNodes)
  {
    mLog(common::LogLevel::Verbose) << "    " << pointId << " " << mMapDataStore.point(pointId) << "\n";
  }
}

void OsmToInternalConverter::connectRoad(map_data::MapDataId const &roadId,
                                         ::osmium::object_id_type const &junctionCenter,
                                         ::osmium::object_id_type const &connectionNode)
{
  auto junctionArm = mJunctionProcessor->getOsmArm(junctionCenter, connectionNode);
  auto intersectionId = mIntersectionMap[junctionArm.mCenterId];
  IntersectionConnection junctionConnection{intersectionId, roadId, junctionArm.mIncoming, junctionArm.mRightOfWay};

  // Add road connection to mIntersectionConnections and mTraveledArms
  mIntersectionConnections.push_back(junctionConnection);

  if (mMapDataStore.road(roadId).mRoadType == map_data::RoadType::Link)
  {
    mMapDataStore.intersection(intersectionId).mIntersectionType = map_data::IntersectionType::Ramp;
  }
  else if (mMapDataStore.road(roadId).mRoadType == map_data::RoadType::Service)
  {
    mMapDataStore.intersection(intersectionId).mIntersectionType = map_data::IntersectionType::Service;
  }

  mTraveledArms.insert(osmium_id_pair(junctionCenter, junctionArm.mArmId));
  mTraveledArms.insert(osmium_id_pair(junctionArm.mArmId, junctionCenter));
}

void OsmToInternalConverter::setupSuccessorRoad(RoadGeometry &roadGeometry) const
{
  mLog(common::LogLevel::Verbose) << "  Split road\n";
  // setup geometry of centerline for the new road, keeping the last point
  auto const point = roadGeometry.centerLineGeometry.points.back(); // need a copy here
  roadGeometry.centerLineGeometry.points.clear();
  roadGeometry.centerLineGeometry.points.push_back(point);
  auto nodeId = roadGeometry.osmNodes.back();
  roadGeometry.osmNodes.clear();
  roadGeometry.osmNodes.push_back(nodeId);
  auto newRoadId = mMapDataStore.createRoad(mLogFactory.logChannel("Road"));
  mMapDataStore.road(roadGeometry.roadId).mSuccessor = newRoadId;
  mMapDataStore.road(newRoadId).mPredecessor = roadGeometry.roadId;
  roadGeometry.roadId = newRoadId;
}

map_data::TurnDirection fromOsmTurnDirection(const OsmTurnDirection &osmTurnDirection)
{
  switch (osmTurnDirection)
  {
    case OsmTurnDirection::Through:
      return map_data::TurnDirection::Through;
    case OsmTurnDirection::Left:
    case OsmTurnDirection::SlightLeft:
    case OsmTurnDirection::SharpLeft:
      return map_data::TurnDirection::Left;
    case OsmTurnDirection::Right:
    case OsmTurnDirection::SlightRight:
    case OsmTurnDirection::SharpRight:
      return map_data::TurnDirection::Right;
    case OsmTurnDirection::MergeToLeft:
      return map_data::TurnDirection::MergeToLeft;
    case OsmTurnDirection::MergeToRight:
      return map_data::TurnDirection::MergeToRight;
    case OsmTurnDirection::Reverse:
    case OsmTurnDirection::None:
    case OsmTurnDirection::Invalid:
      return map_data::TurnDirection::None;
  }
  throw std::runtime_error("Unknown turn direction");
}

map_data::RoadType fromOsmHighwayType(const OsmHighwayType &osmHighwayType)
{
  switch (osmHighwayType)
  {
    case OsmHighwayType::MotorwayLink:
    case OsmHighwayType::PrimaryLink:
    case OsmHighwayType::SecondaryLink:
    case OsmHighwayType::TertiaryLink:
    case OsmHighwayType::TrunkLink:
      return map_data::RoadType::Link;
    case OsmHighwayType::Motorway:
      return map_data::RoadType::Motorway;
    case OsmHighwayType::Primary:
      return map_data::RoadType::Primary;
    case OsmHighwayType::Secondary:
      return map_data::RoadType::Secondary;
    case OsmHighwayType::Tertiary:
      return map_data::RoadType::Tertiary;
    case OsmHighwayType::Trunk:
      return map_data::RoadType::Trunk;
    case OsmHighwayType::Residential:
      return map_data::RoadType::Residential;
    case OsmHighwayType::Service:
      return map_data::RoadType::Service;
    case OsmHighwayType::Unclassified:
      return map_data::RoadType::Unclassified;
    case OsmHighwayType::Invalid:
      return map_data::RoadType::Invalid;
  }
  throw std::runtime_error("Unknown highway type");
}

void OsmToInternalConverter::setRoadInfo(map_data::MapDataId const &roadId, OsmWay const &osmWay)
{
  auto &road = mMapDataStore.road(roadId);
  road.mForwardWidths = osmWay.mForwardLanes.mWidths;
  road.mBackwardWidths = osmWay.mBackwardLanes.mWidths;
  road.mRoadType = fromOsmHighwayType(osmWay.mHighwayType);
  road.mForwardSpeedLimit = osmWay.mForwardLanes.mMaxSpeed;
  road.mBackwardSpeedLimit = osmWay.mBackwardLanes.mMaxSpeed;

  setRoadTurnLanes(roadId, osmWay);
}

void OsmToInternalConverter::setRoadTurnLanes(map_data::MapDataId const &roadId, OsmWay const &osmWay)
{
  auto &road = mMapDataStore.road(roadId);
  road.mForwardTurnDirections.clear();
  road.mBackwardTurnDirections.clear();

  // allow the turn directions vector to be bigger than lanes in as the bike lanes also incorporate turn information
  if (osmWay.mForwardLanes.mTurnDirection.size() >= osmWay.mForwardLanes.mWidths.size())
  {
    for (uint32_t index = 0u; index < osmWay.mForwardLanes.mWidths.size(); ++index)
    {
      map_data::TurnDirections laneTurnDirections;
      for (const auto &osmTurnDirection : osmWay.mForwardLanes.mTurnDirection.at(index))
      {
        laneTurnDirections.push_back(fromOsmTurnDirection(osmTurnDirection));
      }
      road.mForwardTurnDirections.push_back(laneTurnDirections);
    }
  }
  if (osmWay.mBackwardLanes.mTurnDirection.size() >= osmWay.mBackwardLanes.mWidths.size())
  {
    for (uint32_t index = 0u; index < osmWay.mBackwardLanes.mWidths.size(); ++index)
    {
      map_data::TurnDirections laneTurnDirections;
      for (const auto &osmTurnDirection : osmWay.mBackwardLanes.mTurnDirection.at(index))
      {
        laneTurnDirections.push_back(fromOsmTurnDirection(osmTurnDirection));
      }
      road.mBackwardTurnDirections.push_back(laneTurnDirections);
    }
  }
}

map_data::LandmarkType fromPoiType(PoiType poiType)
{
  switch (poiType)
  {
    case PoiType::Crosswalk:
      return map_data::LandmarkType::Crosswalk;
    case PoiType::Tree:
      return map_data::LandmarkType::MiscTree;
    case PoiType::StreetLamp:
      return map_data::LandmarkType::MiscStreetLamp;
    case PoiType::FireHydrant:
      return map_data::LandmarkType::MiscFireHydrant;
    case PoiType::PowerCabinet:
      return map_data::LandmarkType::MiscPowerCabinet;
    case PoiType::Bollard:
      return map_data::LandmarkType::MiscBollard;
    case PoiType::PostBox:
      return map_data::LandmarkType::MiscPostBox;
    case PoiType::ManHole:
      return map_data::LandmarkType::MiscManHole;
    case PoiType::TrafficLight:
      return map_data::LandmarkType::TrafficLight;
    case PoiType::TrafficSign:
      return map_data::LandmarkType::Unknown; // ignored as it is handled separately
    case PoiType::PelicanCrossing:
      return map_data::LandmarkType::Unknown; // silently ignored
    case PoiType::Invalid:
      return map_data::LandmarkType::Unknown;
  }
  throw std::runtime_error("Unknown poi type");
}

void OsmToInternalConverter::convertPois()
{
  std::vector<PoiType> poiTypes{PoiType::Crosswalk,
                                PoiType::Tree,
                                PoiType::StreetLamp,
                                PoiType::FireHydrant,
                                PoiType::PowerCabinet,
                                PoiType::Bollard,
                                PoiType::PostBox,
                                PoiType::ManHole};
  for (auto poiType : poiTypes)
  {
    mLog(common::LogLevel::Verbose) << "Transferring pois of type: " << poiTypeToString(poiType) << "\n";
    auto poiList = mOsmProcessor.poiExtractor()->getPois(poiType);
    for (auto nodeId : poiList)
    {
      // create position
      auto poiLocation = mPointStore->point(nodeId);
      auto pointId = mMapDataStore.getOrCreateIdForPoint(geometry::Point2d(poiLocation.x, poiLocation.y));
      map_data::Landmark mark;
      mark.type = fromPoiType(poiType);
      mark.location = pointId;
      mark.orientation = M_PI_2;
      auto landmarkId = mMapDataStore.addLandmark(mark);
      mMapDataStore.landmark(landmarkId).index = landmarkId;
      mLog(common::LogLevel::Verbose) << " Map node (landmark) " << landmarkId << " with nodeId " << nodeId << " to "
                                      << pointId << "\n";
    }
  }
}

bool trafficLightAttributesMatchRoad(OsmPoiExtractor::TrafficLightAttributes const &attributes,
                                     OsmWay const &currentWay,
                                     common::LogChannel &logger)
{
  if (attributes.isForward && currentWay.mForwardLanes.mWidths.empty())
  {
    logger(common::LogLevel::Info) << "Traffic light is forward but no forward lanes\n";
    return false;
  }
  if (!attributes.isForward && currentWay.mBackwardLanes.mWidths.empty())
  {
    logger(common::LogLevel::Info) << "Traffic light is backward but no backward lanes\n";
    return false;
  }
  for (auto assignments : attributes.laneAssignments)
  {
    for (auto lane : assignments)
    {
      if (lane < 0)
      {
        auto const &widths = currentWay.mBackwardLanes.mWidths;
        if (widths.size() < (static_cast<std::size_t>(-lane)))
        {
          logger(common::LogLevel::Info) << "Traffic light assignment exceeds number of backward lanes\n  "
                                         << widths.size() << " vs. " << lane << "\n";
          return false;
        }
      }
      else if (lane > 0)
      {
        auto const &widths = currentWay.mForwardLanes.mWidths;
        if (widths.size() < (static_cast<std::size_t>(lane)))
        {
          logger(common::LogLevel::Info) << "Traffic light assignment exceeds number of forward lanes\n  "
                                         << widths.size() << " vs. " << lane << "\n";
          return false;
        }
      }
      else
      {
        logger(common::LogLevel::Info) << "Traffic light assignment is zero\n";
        return false;
      }
    }
  }
  return true;
}

bool OsmToInternalConverter::convertTrafficLight(::osmium::object_id_type const currentNodeId,
                                                 RoadGeometry const &roadGeometry)
{
  auto trafficLights = mOsmProcessor.poiExtractor()->getPois(PoiType::TrafficLight);
  if (trafficLights.count(currentNodeId) == 0)
  {
    return false;
  }
  // make sure the traffic light wasn't already processed
  if (!mProcessedTrafficLights.insert(currentNodeId).second)
  {
    mLog(common::LogLevel::Info) << "Trying to generate traffic lights a second time for node " << currentNodeId
                                 << "\n";
    return false;
  }
  // make sure the attributes match the current road
  auto const &attributes = mOsmProcessor.poiExtractor()->trafficLightAttributes(currentNodeId);
  if (!trafficLightAttributesMatchRoad(attributes, roadGeometry.currentOsmWay, mLog))
  {
    return false;
  }
  LandmarkOnCenterLine data;
  data.nodeId = currentNodeId;
  data.roadId = roadGeometry.roadId;
  mTrafficLights.push_back(data);
  return true;
}

void OsmToInternalConverter::generateTrafficLight(LandmarkOnCenterLine const &data)
{
  map_data::MapDataId currentPointId = mOsmMap.mapDataIdForNodeId(data.nodeId);
  auto &road = mMapDataStore.road(data.roadId);
  auto const shiftingDirection = road.shiftingDirectionAtPoint(currentPointId);
  auto const &attributes = mOsmProcessor.poiExtractor()->trafficLightAttributes(data.nodeId);
  auto geoPlacements = calculateTrafficLightPositions(data.nodeId, shiftingDirection, road, attributes);

  // add landmark for each traffic light
  for (std::size_t i = 0u; i < attributes.configs.size(); i++)
  {
    map_data::Landmark mark;
    mark.type = fromPoiType(PoiType::TrafficLight);
    // should we add this to the point map as well?
    mark.location = mMapDataStore.getOrCreateIdForPoint(geoPlacements[i]);
    mark.index = attributes.ids[i];
    mark.heightOverGround = cTrafficLightDistanceToGround;
    if (attributes.placements[i].find('t') != std::string::npos)
    {
      mark.heightOverGround += cTrafficLightDistanceToGroundOffset;
    }
    mark.supplement = attributes.configs[i];

    if (attributes.isForward)
    {
      // the orientation is orthogonal to the shifting direction (rotated clockwise by 90 deg: PI/2)
      mark.orientation = geometry::normalizeAngle(shiftingDirection.orientation - M_PI_2);
      mark.alongRoadDirection = true;
    }
    else
    {
      // the orientation is orthogonal to the shifting direction (rotated counterclockwise by 90 deg: PI/2)
      mark.alongRoadDirection = false;
      mark.orientation = geometry::normalizeAngle(shiftingDirection.orientation + M_PI_2);
    }

    // assign traffic light to a lane
    for (auto laneNumber : attributes.laneAssignments[i])
    {
      mark.laneAssignments.insert(laneNumber);
      if ((laneNumber > 0 && !attributes.isForward) || (laneNumber < 0 && attributes.isForward))
      {
        mLog(common::LogLevel::Error) << " Traffic light with nodeId " << data.nodeId
                                      << " has contradicting lane assignments " << laneNumber << " and orientation "
                                      << (attributes.isForward ? "forward" : "backward") << "\n";
        return; // really return here?
      }
    }

    const auto landmarkId = mMapDataStore.addLandmark(mark);
    road.mTrafficLights.push_back(landmarkId);
    mLog(common::LogLevel::Verbose) << " Adding traffic light with " << landmarkId << " and nodeId " << data.nodeId
                                    << " and position " << geoPlacements[i] << " " << mark.location << "\n";
  }

  // @todo add landmark pole for traffic light
}

double placementForRoadBorder(map_data::Road const &road, bool isForward, double baseDist)
{
  if (isForward)
  {
    return baseDist + road.backwardWidth();
  }
  else
  {
    return -baseDist - road.forwardWidth();
  }
}

double OsmToInternalConverter::getTrafficLightOffsetForPlacement(map_data::Road const &road,
                                                                 bool const isForward,
                                                                 std::string const &placement,
                                                                 double const additionalLateralOffset) const
{
  if (placement.empty())
  {
    throw std::invalid_argument("placement empty.");
  }

  if (placement == "l") // left of the road
  {
    return placementForRoadBorder(road, isForward, cTrafficLightDistanceToRoadBorder + additionalLateralOffset);
  }
  else if (placement == "r") // right of the road
  {
    return placementForRoadBorder(road, !isForward, cTrafficLightDistanceToRoadBorder + additionalLateralOffset);
  }
  else if ((placement.front() == 't') && (placement.size() > 1u)) // over a lane
  {
    int32_t extractedIndex{0};
    if (!common::integerFromString(&placement.c_str()[1], extractedIndex))
    {
      mLog(common::LogLevel::Error) << "Invalid index for top placement! " << placement << "\n";
      throw std::invalid_argument("Invalid index for top placement! " + placement);
    }
    if (extractedIndex < 1)
    {
      mLog(common::LogLevel::Error) << "Invalid (must be >0) index for top placement! " << placement << "\n";
      throw std::invalid_argument("Invalid (must be >0) index for top placement! " + placement);
    }
    std::size_t laneIndex = static_cast<std::size_t>(extractedIndex); // cast is allowed here, can't be <0 here
    auto const &laneWidths
      = (isForward ^ mMapDataStore.isLeftHandTraffic() ? road.mForwardWidths : road.mBackwardWidths);
    if (laneIndex > laneWidths.size())
    {
      mLog(common::LogLevel::Error) << "Invalid (out of range) index for top placement! Placing right of road. "
                                    << placement << "\n";
      return placementForRoadBorder(road, !isForward, cTrafficLightDistanceToRoadBorder + additionalLateralOffset);
    }
    double totalWidth{0.};
    for (std::size_t index = 1; index < laneIndex; ++index)
    {
      totalWidth += laneWidths[index - 1];
    }
    totalWidth += laneWidths[laneIndex - 1] / 2.;
    return (isForward ^ mMapDataStore.isLeftHandTraffic() ? -totalWidth - additionalLateralOffset
                                                          : totalWidth + additionalLateralOffset);
  }
  else
  {
    mLog(common::LogLevel::Error) << "Invalid placement! " << placement << "\n";
    throw std::invalid_argument("Invalid placement! " + placement);
  }
  throw std::logic_error("Unhandled placement"); // we should never get here.
}

std::vector<geometry::Point2d>
OsmToInternalConverter::calculateTrafficLightPositions(::osmium::object_id_type currentNodeId,
                                                       geometry::Direction2d const &shiftingDirection,
                                                       map_data::Road const &road,
                                                       OsmPoiExtractor::TrafficLightAttributes const &attributes) const
{
  auto const &currentPoint = mOsmMap.pointForNodeId(currentNodeId);

  std::string oldPlacement = "";
  double additionalLateralOffset = 0;

  std::vector<geometry::Point2d> result;
  for (auto const &where : attributes.placements)
  {
    if ((where == oldPlacement))
    {
      additionalLateralOffset += 0.2;
    }
    else
    {
      additionalLateralOffset = 0.;
    }
    double const displacement
      = getTrafficLightOffsetForPlacement(road, attributes.isForward, where, additionalLateralOffset);
    mLog(common::LogLevel::Verbose) << "Placement top for " << currentNodeId << " " << displacement << "\n";
    result.push_back(shiftingDirection.movePoint(currentPoint, displacement));
    oldPlacement = where;
  }
  return result;
}

void OsmToInternalConverter::addTrafficSignsToRoad(::osmium::object_id_type const nodeIdOfSign,
                                                   map_data::MapDataId const roadId)
{
  auto trafficSigns = mOsmProcessor.poiExtractor()->trafficSigns(nodeIdOfSign);
  if (trafficSigns.empty())
  {
    return;
  }
  // Make sure the traffic signs of the current node weren't already processed
  if (!mProcessedTrafficSigns.insert(nodeIdOfSign).second)
  {
    mLog(common::LogLevel::Info) << "Trying to generate traffic signs a second time for node " << nodeIdOfSign << "\n";
  }
  LandmarkOnCenterLine data;
  data.nodeId = nodeIdOfSign;
  data.roadId = roadId;
  mTrafficSigns.push_back(data);
}

void OsmToInternalConverter::generateTrafficSign(LandmarkOnCenterLine const &data)
{
  map_data::MapDataId currentPointId = mOsmMap.mapDataIdForNodeId(data.nodeId);
  auto &road = mMapDataStore.road(data.roadId);
  auto const roadDirection = road.shiftingDirectionAtPoint(currentPointId);
  auto const &currentPoint = mOsmMap.pointForNodeId(data.nodeId);

  double const displacementAlong
    = placementForRoadBorder(road, false ^ mMapDataStore.isLeftHandTraffic(), cTrafficLightDistanceToRoadBorder);
  auto positionAlong = roadDirection.movePoint(currentPoint, displacementAlong);
  double const displacementAgainst
    = placementForRoadBorder(road, true ^ mMapDataStore.isLeftHandTraffic(), cTrafficLightDistanceToRoadBorder);
  auto positionAgainst = roadDirection.movePoint(currentPoint, displacementAgainst);

  // defer adding a point until we really need it
  map_data::MapDataId locationIdAlong{};
  map_data::MapDataId locationIdAgainst{};

  // add landmark for each traffic sign
  auto trafficSigns = mOsmProcessor.poiExtractor()->trafficSigns(data.nodeId);
  for (map_data::Landmark mark : trafficSigns)
  {
    if (mark.alongRoadDirection)
    {
      if (locationIdAlong == map_data::InvalidId)
      {
        // should we add this point to the point map as well?
        locationIdAlong = mMapDataStore.getOrCreateIdForPoint(positionAlong);
      }
      mark.location = locationIdAlong;
      mark.orientation = geometry::normalizeAngle(roadDirection.orientation - M_PI_2);
    }
    else
    {
      if (locationIdAgainst == map_data::InvalidId)
      {
        // defer creating a point until we really need it
        locationIdAgainst = mMapDataStore.getOrCreateIdForPoint(positionAgainst);
      }
      mark.location = locationIdAgainst;
      mark.orientation = geometry::normalizeAngle(roadDirection.orientation + M_PI_2);
    }
    mark.heightOverGround = cTrafficLightDistanceToGround;

    const auto landmarkId = mMapDataStore.addLandmark(mark);
    mMapDataStore.landmark(landmarkId).index = landmarkId;
    road.mTrafficSigns.push_back(landmarkId);
    mLog(common::LogLevel::Verbose) << " Adding traffic sign with " << landmarkId << " and nodeId " << data.nodeId
                                    << " and position " << mark.location << "\n";
  }
}

} // namespace osm_converter
} // namespace maker
} // namespace map
} // namespace ad
