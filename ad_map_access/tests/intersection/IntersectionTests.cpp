// ----------------- BEGIN LICENSE BLOCK ---------------------------------
//
// Copyright (C) 2018-2021 Intel Corporation
//
// SPDX-License-Identifier: MIT
//
// ----------------- END LICENSE BLOCK -----------------------------------
#include <ad/map/access/Operation.hpp>
#include <ad/map/intersection/Intersection.hpp>
#include <ad/map/landmark/LandmarkOperation.hpp>
#include <ad/map/lane/LaneOperation.hpp>
#include <ad/map/lane/Types.hpp>
#include <ad/map/match/AdMapMatching.hpp>
#include <ad/map/point/Types.hpp>
#include <ad/map/route/Planning.hpp>
#include <ad/map/route/RouteOperation.hpp>
#include <algorithm>
#include <fstream>
#include <streambuf>
#include <string>
#include "MapSetup.hpp"
#include "SyntheticIntersectionTestBase.hpp"
#include "ad/map/access/Operation.hpp"
#include "ad/map/intersection/CoreIntersection.hpp"
#include "ad/map/lane/LaneOperation.hpp"
#include "ad/map/route/LaneIntervalOperation.hpp"
#include "ad/physics/RangeOperation.hpp"

#include <gtest/gtest.h>

namespace ad {
namespace map {

using namespace point;
struct IntersectionTest : ::testing::Test
{
  virtual void SetUp()
  {
    access::cleanup();
  }

  virtual void TearDown()
  {
    access::cleanup();
  }

  void compareLists(lane::LaneIdSet ids, lane::LaneIdSet otherIds) const
  {
    std::vector<lane::LaneId> idVector(ids.begin(), ids.end());
    std::vector<lane::LaneId> otherIdVector(otherIds.begin(), otherIds.end());

    std::sort(idVector.begin(), idVector.end());
    std::sort(otherIdVector.begin(), otherIdVector.end());
    ASSERT_EQ(idVector.size(), otherIdVector.size());

    for (uint32_t i = 0; i < idVector.size(); i++)
    {
      ASSERT_EQ(idVector[i], otherIdVector[i]);
    }
  }

  void compareParaLists(point::ParaPointList resultParaPoints, point::ParaPointList expectedParaPoints)
  {
    std::vector<point::ParaPoint> idVector(resultParaPoints.begin(), resultParaPoints.end());
    std::vector<point::ParaPoint> otherIdVector(expectedParaPoints.begin(), expectedParaPoints.end());

    auto compareParaWithLaneId
      = [](point::ParaPoint &left, point::ParaPoint &right) { return left.lane_id < right.lane_id; };
    std::sort(idVector.begin(), idVector.end(), compareParaWithLaneId);
    std::sort(otherIdVector.begin(), otherIdVector.end(), compareParaWithLaneId);
    ASSERT_EQ(idVector.size(), otherIdVector.size());

    for (uint32_t i = 0; i < idVector.size(); i++)
    {
      ASSERT_EQ(idVector[i], otherIdVector[i]);
    }
  }

  void processEachIntersectionEntryPoints(std::vector<intersection::CoreIntersectionPtr> coreIntersections)
  {
    bool isfoundAtTransitionToEntryLane = false;
    bool isfoundAtEntryLane = false;

    for (auto &eachCoreIntersection : coreIntersections)
    {
      auto entryPoints = eachCoreIntersection->entryParaPoints();
      auto entryBorderPoints = eachCoreIntersection->entryBorderParaPoints();

      for (auto &eachEntryBorderPoint : entryBorderPoints)
      {
        auto ecefBorderPoint = lane::getParametricPoint(lane::getLane(eachEntryBorderPoint.lane_id),
                                                        eachEntryBorderPoint.parametric_offset,
                                                        physics::ParametricValue(0.5));
        for (auto &eachEntryPoint : entryPoints)
        {
          auto ecefPoint = lane::getParametricPoint(
            lane::getLane(eachEntryPoint.lane_id), eachEntryPoint.parametric_offset, physics::ParametricValue(0.5));
          if (ecefPoint == ecefBorderPoint)
          {
            isfoundAtTransitionToEntryLane = true;
          }
        }
      }

      for (auto &eachEntryPoint : entryPoints)
      {
        auto ecefPoint = lane::getParametricPoint(
          lane::getLane(eachEntryPoint.lane_id), eachEntryPoint.parametric_offset, physics::ParametricValue(0.5));
        for (auto &eachEntryBorderPoint : entryBorderPoints)
        {
          auto ecefBorderPoint = lane::getParametricPoint(lane::getLane(eachEntryBorderPoint.lane_id),
                                                          eachEntryBorderPoint.parametric_offset,
                                                          physics::ParametricValue(0.5));
          if (ecefBorderPoint == ecefPoint)
          {
            isfoundAtEntryLane = true;
          }
        }
      }
    }

    ASSERT_EQ(true, isfoundAtTransitionToEntryLane && isfoundAtEntryLane);
  }

  void processEachIntersectionExitPoints(std::vector<intersection::CoreIntersectionPtr> coreIntersections)
  {
    for (auto &eachCoreIntersection : coreIntersections)
    {
      auto exitPoints = eachCoreIntersection->exitParaPoints();
      auto exitBorderPoints = eachCoreIntersection->exitBorderParaPoints();

      for (auto &eachExitBorderPoint : exitBorderPoints)
      {
        bool isfoundAtTransitionToExitLane = false;
        auto ecefBorderPoint = lane::getParametricPoint(lane::getLane(eachExitBorderPoint.lane_id),
                                                        eachExitBorderPoint.parametric_offset,
                                                        physics::ParametricValue(0.5));
        for (auto &eachExitPoint : exitPoints)
        {
          auto ecefPoint = lane::getParametricPoint(
            lane::getLane(eachExitPoint.lane_id), eachExitPoint.parametric_offset, physics::ParametricValue(0.5));
          if (ecefPoint == ecefBorderPoint)
          {
            isfoundAtTransitionToExitLane = true;
          }
        }
        EXPECT_TRUE(isfoundAtTransitionToExitLane);
      }

      for (auto &eachExitPoint : exitPoints)
      {
        bool isfoundAtExitLane = false;
        auto ecefBorderPoint = lane::getParametricPoint(
          lane::getLane(eachExitPoint.lane_id), eachExitPoint.parametric_offset, physics::ParametricValue(0.5));
        for (auto &eachExitBorderPoint : exitBorderPoints)
        {
          auto ecefPoint = lane::getParametricPoint(lane::getLane(eachExitBorderPoint.lane_id),
                                                    eachExitBorderPoint.parametric_offset,
                                                    physics::ParametricValue(0.5));
          if (ecefPoint == ecefBorderPoint)
          {
            isfoundAtExitLane = true;
          }
        }
        EXPECT_TRUE(isfoundAtExitLane);
      }
    }
  }
};

TEST_F(IntersectionTest, create_core_intersection_all_way_stop_all)
{
  ASSERT_NO_THROW(::map_setup::prepareMapAllWayStop());
  auto coreIntersections = ad::map::intersection::CoreIntersection::getCoreIntersectionsForMap();
  ASSERT_EQ(1u, coreIntersections.size());
}

TEST_F(IntersectionTest, create_core_intersection_town01_all)
{
  ASSERT_NO_THROW(::map_setup::prepareMapTown01PrioRight());
  auto coreIntersections = ad::map::intersection::CoreIntersection::getCoreIntersectionsForMap();
  ASSERT_EQ(12u, coreIntersections.size());
}

TEST_F(IntersectionTest, create_core_intersection_town01_from_point_inside_intersection)
{
  ASSERT_NO_THROW(::map_setup::prepareMapTown01PrioRight());
  auto coreIntersections = ad::map::intersection::CoreIntersection::getCoreIntersectionsForInLaneMatches(point::toENU(
    point::createGeoPoint(point::Longitude(0.000815115), point::Latitude(0.0000102114), point::Altitude(0))));
  ASSERT_EQ(1u, coreIntersections.size());
}

TEST_F(IntersectionTest, create_core_intersection_town01_from_point_outside_intersection)
{
  ASSERT_NO_THROW(::map_setup::prepareMapTown01PrioRight());
  auto coreIntersections = ad::map::intersection::CoreIntersection::getCoreIntersectionsForInLaneMatches(point::toENU(
    point::createGeoPoint(point::Longitude(0.0032321), point::Latitude(0.0000165612), point::Altitude(0))));
  ASSERT_EQ(0u, coreIntersections.size());
}

TEST_F(IntersectionTest, create_intersections_all_way_stop)
{
  using point::createGeoPoint;
  using namespace point;
  ASSERT_NO_THROW(::map_setup::prepareMapAllWayStop());
  auto fromWest = createGeoPoint(Longitude(8.437270), Latitude(49.018665), Altitude(0.));
  lane::LaneId fromWestId = lane::uniqueLaneId(fromWest);
  auto toEast = createGeoPoint(Longitude(8.437818), Latitude(49.018672), Altitude(0.));
  lane::LaneId toEastId = lane::uniqueLaneId(toEast);
  ASSERT_NE(fromWestId, toEastId);
  point::ParaPoint routeStart(point::createParaPoint(fromWestId, physics::ParametricValue(0.8)));
  point::ParaPoint routeEnd(point::createParaPoint(toEastId, physics::ParametricValue(0.5)));
  auto fullRoute = route::planning::planRoute(routeStart, routeEnd);

  auto intersections = intersection::Intersection::getIntersectionsForRoute(fullRoute);
  ASSERT_EQ(1u, intersections.size());
  auto const &intersection = intersections[0];
  auto iType = intersection->intersectionType();
  ASSERT_EQ(intersection::IntersectionType::AllWayStop, iType);
  ASSERT_EQ(1u, intersection->outgoingParaPointsOnRoute().size());

  lane::LaneId lane_id = intersection->outgoingParaPointsOnRoute()[0].lane_id;
  ASSERT_EQ(toEastId, lane_id);
  ::ad::physics::ParametricValue parametric_offset = intersection->outgoingParaPointsOnRoute()[0].parametric_offset;
  ASSERT_EQ(physics::ParametricValue(0.), parametric_offset);
  auto incoming = intersection->incomingLanes();
  ASSERT_EQ(3u, incoming.size());
  lane::LaneIdSet expectedIncoming{lane::LaneId{248}, lane::LaneId{252}, lane::LaneId{264}};
  compareLists(incoming, expectedIncoming);
  auto internal = intersection->internalLanes();
  ASSERT_EQ(12u, internal.size());
  lane::LaneIdSet expectedInternal{lane::LaneId{63},
                                   lane::LaneId{76},
                                   lane::LaneId{98},
                                   lane::LaneId{110},
                                   lane::LaneId{132},
                                   lane::LaneId{144},
                                   lane::LaneId{165},
                                   lane::LaneId{176},
                                   lane::LaneId{197},
                                   lane::LaneId{208},
                                   lane::LaneId{229},
                                   lane::LaneId{240}};
  compareLists(expectedInternal, internal);
  auto crossingLanes = intersection->crossingLanes();
  ASSERT_EQ(6u, crossingLanes.size());

  lane::LaneIdSet resultLaneIdSets, expectedLaneIdSets;
  resultLaneIdSets = intersection->lanesOnRoute();
  expectedLaneIdSets = lane::LaneIdSet({lane::LaneId{110}});
  compareLists(resultLaneIdSets, expectedLaneIdSets);

  resultLaneIdSets = intersection->incomingLanesOnRoute();
  expectedLaneIdSets = lane::LaneIdSet({lane::LaneId{268}});
  compareLists(resultLaneIdSets, expectedLaneIdSets);

  resultLaneIdSets = intersection->outgoingLanesOnRoute();
  expectedLaneIdSets = lane::LaneIdSet({lane::LaneId{244}});
  compareLists(resultLaneIdSets, expectedLaneIdSets);

  resultLaneIdSets = intersection->internalLanesWithLowerPriority();
  expectedLaneIdSets
    = lane::LaneIdSet({lane::LaneId{63}, lane::LaneId{98}, lane::LaneId{165}, lane::LaneId{176}, lane::LaneId{229}});
  compareLists(resultLaneIdSets, expectedLaneIdSets);

  resultLaneIdSets = intersection->outgoingLanes();
  expectedLaneIdSets = lane::LaneIdSet({lane::LaneId{244}, lane::LaneId{256}, lane::LaneId{260}, lane::LaneId{272}});
  compareLists(resultLaneIdSets, expectedLaneIdSets);

  resultLaneIdSets = intersection->entryLanes();
  expectedLaneIdSets = lane::LaneIdSet({lane::LaneId{248}, lane::LaneId{252}, lane::LaneId{264}, lane::LaneId{268}});
  compareLists(resultLaneIdSets, expectedLaneIdSets);

  physics::Speed speed;
  speed = intersection->getSpeedLimit();
  ASSERT_NEAR(speed.mSpeed, 1000, 0.001);

  ASSERT_EQ(1u, intersection->outgoingParaPointsOnRoute().size());
  lane_id = intersection->outgoingParaPointsOnRoute()[0].lane_id;
  ASSERT_EQ(lane::uniqueLaneId(toEast), lane_id);
  parametric_offset = intersection->outgoingParaPointsOnRoute()[0].parametric_offset;
  ASSERT_EQ(physics::ParametricValue(0.), parametric_offset);

  point::ParaPoint para_point;
  point::ParaPointList resultParaPoints, expectedParaPoints;

  resultParaPoints = intersection->paraPointsOnRoute();
  expectedParaPoints.clear();
  para_point.lane_id = lane::LaneId(110);
  para_point.parametric_offset = physics::ParametricValue(0);
  expectedParaPoints.push_back(para_point);
  compareParaLists(resultParaPoints, expectedParaPoints);

  resultParaPoints = intersection->incomingParaPointsOnRoute();
  expectedParaPoints.clear();
  para_point.lane_id = lane::LaneId(268);
  para_point.parametric_offset = physics::ParametricValue(1);
  expectedParaPoints.push_back(para_point);
  compareParaLists(resultParaPoints, expectedParaPoints);

  resultParaPoints = intersection->outgoingParaPoints();
  expectedParaPoints.clear();
  para_point.lane_id = lane::LaneId(272);
  para_point.parametric_offset = physics::ParametricValue(1);
  expectedParaPoints.push_back(para_point);
  para_point.lane_id = lane::LaneId(256);
  para_point.parametric_offset = physics::ParametricValue(1);
  expectedParaPoints.push_back(para_point);
  para_point.lane_id = lane::LaneId(260);
  para_point.parametric_offset = physics::ParametricValue(0);
  expectedParaPoints.push_back(para_point);
  para_point.lane_id = lane::LaneId(244);
  para_point.parametric_offset = physics::ParametricValue(0);
  expectedParaPoints.push_back(para_point);
  compareParaLists(resultParaPoints, expectedParaPoints);

  resultParaPoints = intersection->entryParaPoints();
  expectedParaPoints.clear();
  para_point.lane_id = lane::LaneId(264);
  para_point.parametric_offset = physics::ParametricValue(0);
  expectedParaPoints.push_back(para_point);
  para_point.lane_id = lane::LaneId(252);
  para_point.parametric_offset = physics::ParametricValue(1);
  expectedParaPoints.push_back(para_point);
  para_point.lane_id = lane::LaneId(268);
  para_point.parametric_offset = physics::ParametricValue(1);
  expectedParaPoints.push_back(para_point);
  para_point.lane_id = lane::LaneId(248);
  para_point.parametric_offset = physics::ParametricValue(0);
  expectedParaPoints.push_back(para_point);
  compareParaLists(resultParaPoints, expectedParaPoints);

  resultParaPoints = intersection->paraPointsOnRoute();
  expectedParaPoints.clear();
  para_point.lane_id = lane::LaneId(110);
  para_point.parametric_offset = physics::ParametricValue(0);
  expectedParaPoints.push_back(para_point);
  compareParaLists(resultParaPoints, expectedParaPoints);

  route::RouteParaPoint routeParaPoint;
  routeParaPoint = intersection->getIntersectionStartOnRoute();
  ASSERT_NEAR(routeParaPoint.parametric_offset.mParametricValue, 0., 0.001);

  route::RoutePlanningCounter routeCounter;
  routeCounter = intersection->getRoutePlanningCounter();
  ASSERT_EQ(routeCounter, 1u);
  route::SegmentCounter segmentCounter;
  segmentCounter = intersection->getRouteSegmentCountFromDestination();
  ASSERT_EQ(segmentCounter, 2u);
  intersection->updateRouteCounters(4, 5);
  routeCounter = intersection->getRoutePlanningCounter();
  ASSERT_EQ(routeCounter, 4u);
  segmentCounter = intersection->getRouteSegmentCountFromDestination();
  ASSERT_EQ(segmentCounter, 5u);
  intersection->updateRouteCounters(1, 2);

  match::MapMatchedObjectBoundingBox object;
  match::LaneOccupiedRegion region;

  object.lane_occupied_regions.clear();
  region.lane_id = lane::LaneId(110);
  object.lane_occupied_regions.push_back(region);
  ASSERT_TRUE(intersection->objectOnIntersectionRoute(object));

  object.lane_occupied_regions.clear();
  region.lane_id = lane::LaneId(132);
  object.lane_occupied_regions.push_back(region);
  ASSERT_TRUE(intersection->objectOnInternalLaneWithHigherPriority(object));

  object.lane_occupied_regions.clear();
  region.lane_id = lane::LaneId(248);
  object.lane_occupied_regions.push_back(region);
  ASSERT_TRUE(intersection->objectOnIncomingLaneWithHigherPriority(object));

  object.lane_occupied_regions.clear();
  region.lane_id = lane::LaneId(132);
  object.lane_occupied_regions.push_back(region);
  ASSERT_TRUE(intersection->objectOnCrossingLane(object));
}

TEST_F(IntersectionTest, create_intersection_from_route_ending_within_intersection)
{
  ASSERT_NO_THROW(::map_setup::prepareMapAllWayStop());
  point::ParaPoint incomingLane(point::createParaPoint(lane::LaneId{268}, physics::ParametricValue(0.8)));
  point::ParaPoint laneWithinIntersection(point::createParaPoint(lane::LaneId{110}, physics::ParametricValue(0.5)));
  auto fullRoute = route::planning::planRoute(incomingLane, laneWithinIntersection);
  ASSERT_GT(route::calcLength(fullRoute), physics::Distance(0.));
  std::vector<intersection::IntersectionPtr> intersections;
  ASSERT_NO_THROW(intersections = intersection::Intersection::getIntersectionsForRoute(fullRoute));
  ASSERT_EQ(1u, intersections.size());
}

TEST_F(IntersectionTest, traffic_lights_pfz_elf_to_rusch)
{
  using point::createGeoPoint;
  using namespace point;
  ASSERT_NO_THROW(::map_setup::prepareMapTrafficLightsPfz());
  // inner lane (1990)
  auto fromSouth = createGeoPoint(Longitude(8.457617), Latitude(49.020345), Altitude(0.));
  lane::LaneId fromSouthId = lane::uniqueLaneId(fromSouth);
  // 1964
  auto toEast = createGeoPoint(Longitude(8.457384), Latitude(49.020785), Altitude(0.));
  lane::LaneId toEastId = lane::uniqueLaneId(toEast);
  ASSERT_NE(fromSouthId, toEastId);
  point::ParaPoint routeStart(point::createParaPoint(fromSouthId, physics::ParametricValue(0.5)));
  point::ParaPoint routeEnd(point::createParaPoint(toEastId, physics::ParametricValue(0.5)));
  auto fullRoute = route::planning::planRoute(routeStart, routeEnd);
  // contain left-straight arrows type traffic light
  // no additional lanes with higher priorities
  auto intersections = intersection::Intersection::getIntersectionsForRoute(fullRoute);
  ASSERT_EQ(1u, intersections.size());
  auto const &intersection = intersections[0];
  auto iType = intersection->intersectionType();
  ASSERT_EQ(intersection::IntersectionType::TrafficLight, iType);
  auto const &priorityLanes = intersection->incomingParaPointsWithHigherPriority();
  ASSERT_EQ(priorityLanes.size(), 0u);
  auto const &lights = intersection->applicableTrafficLights();
  ASSERT_EQ(2u, lights.size());
  point::GeoPoint geo_point;
  landmark::LandmarkId id1, id2;
  geo_point = point::createGeoPoint(point::Longitude(8.457552564), point::Latitude(49.02053703), point::Altitude(3.));
  id1 = landmark::uniqueLandmarkId(geo_point);
  geo_point = point::createGeoPoint(point::Longitude(8.457664809), point::Latitude(49.02051672), point::Altitude(5.));
  id2 = landmark::uniqueLandmarkId(geo_point);
  ASSERT_EQ(1u, lights.count(id1));
  ASSERT_EQ(1u, lights.count(id2));

  lane::LaneIdSet resultLaneIdSets, expectedLaneIdSets;
  resultLaneIdSets = intersection->lanesOnRoute();
  expectedLaneIdSets = lane::LaneIdSet({lane::LaneId{360}, lane::LaneId{621}, lane::LaneId{624}});
  compareLists(resultLaneIdSets, expectedLaneIdSets);

  resultLaneIdSets = intersection->incomingLanesOnRoute();
  expectedLaneIdSets = lane::LaneIdSet({lane::LaneId{588}, lane::LaneId{598}});
  compareLists(resultLaneIdSets, expectedLaneIdSets);

  resultLaneIdSets = intersection->outgoingLanesOnRoute();
  expectedLaneIdSets = lane::LaneIdSet({lane::LaneId{471}});
  compareLists(resultLaneIdSets, expectedLaneIdSets);

  resultLaneIdSets = intersection->internalLanesWithLowerPriority();
  expectedLaneIdSets = lane::LaneIdSet({lane::LaneId{187},
                                        lane::LaneId{199},
                                        lane::LaneId{220},
                                        lane::LaneId{231},
                                        lane::LaneId{253},
                                        lane::LaneId{275},
                                        lane::LaneId{297},
                                        lane::LaneId{318},
                                        lane::LaneId{339},
                                        lane::LaneId{382},
                                        lane::LaneId{404},
                                        lane::LaneId{425},
                                        lane::LaneId{446},
                                        lane::LaneId{467},
                                        lane::LaneId{475},
                                        lane::LaneId{479},
                                        lane::LaneId{511},
                                        lane::LaneId{514},
                                        lane::LaneId{552}});
  compareLists(resultLaneIdSets, expectedLaneIdSets);

  resultLaneIdSets = intersection->outgoingLanes();
  expectedLaneIdSets
    = lane::LaneIdSet({lane::LaneId{471}, lane::LaneId{508}, lane::LaneId{548}, lane::LaneId{627}, lane::LaneId{630}});
  compareLists(resultLaneIdSets, expectedLaneIdSets);

  resultLaneIdSets = intersection->entryLanes();
  expectedLaneIdSets = lane::LaneIdSet({lane::LaneId{487},
                                        lane::LaneId{491},
                                        lane::LaneId{522},
                                        lane::LaneId{526},
                                        lane::LaneId{578},
                                        lane::LaneId{588},
                                        lane::LaneId{598}});
  compareLists(resultLaneIdSets, expectedLaneIdSets);

  point::ParaPointList resultParaPoints, expectedParaPoints;
  point::ParaPoint para_point;

  resultParaPoints = intersection->paraPointsOnRoute();
  expectedParaPoints.clear();
  para_point.lane_id = lane::LaneId(360);
  para_point.parametric_offset = physics::ParametricValue(1);
  expectedParaPoints.push_back(para_point);
  para_point.lane_id = lane::LaneId(621);
  para_point.parametric_offset = physics::ParametricValue(1);
  expectedParaPoints.push_back(para_point);
  para_point.lane_id = lane::LaneId(624);
  para_point.parametric_offset = physics::ParametricValue(1);
  expectedParaPoints.push_back(para_point);
  compareParaLists(resultParaPoints, expectedParaPoints);

  resultParaPoints = intersection->incomingParaPointsOnRoute();
  expectedParaPoints.clear();
  para_point.lane_id = lane::LaneId(588);
  para_point.parametric_offset = physics::ParametricValue(1);
  expectedParaPoints.push_back(para_point);
  para_point.lane_id = lane::LaneId(598);
  para_point.parametric_offset = physics::ParametricValue(1);
  expectedParaPoints.push_back(para_point);
  compareParaLists(resultParaPoints, expectedParaPoints);

  resultParaPoints = intersection->outgoingParaPoints();
  expectedParaPoints.clear();
  para_point.lane_id = lane::LaneId(508);
  para_point.parametric_offset = physics::ParametricValue(0);
  expectedParaPoints.push_back(para_point);
  para_point.lane_id = lane::LaneId(627);
  para_point.parametric_offset = physics::ParametricValue(1);
  expectedParaPoints.push_back(para_point);
  para_point.lane_id = lane::LaneId(548);
  para_point.parametric_offset = physics::ParametricValue(0);
  expectedParaPoints.push_back(para_point);
  para_point.lane_id = lane::LaneId(471);
  para_point.parametric_offset = physics::ParametricValue(0);
  expectedParaPoints.push_back(para_point);
  para_point.lane_id = lane::LaneId(630);
  para_point.parametric_offset = physics::ParametricValue(1);
  expectedParaPoints.push_back(para_point);
  compareParaLists(resultParaPoints, expectedParaPoints);

  resultParaPoints = intersection->entryParaPoints();
  expectedParaPoints.clear();
  para_point.lane_id = lane::LaneId(487);
  para_point.parametric_offset = physics::ParametricValue(0);
  expectedParaPoints.push_back(para_point);
  para_point.lane_id = lane::LaneId(578);
  para_point.parametric_offset = physics::ParametricValue(0);
  expectedParaPoints.push_back(para_point);
  para_point.lane_id = lane::LaneId(522);
  para_point.parametric_offset = physics::ParametricValue(0);
  expectedParaPoints.push_back(para_point);
  para_point.lane_id = lane::LaneId(588);
  para_point.parametric_offset = physics::ParametricValue(1);
  expectedParaPoints.push_back(para_point);
  para_point.lane_id = lane::LaneId(598);
  para_point.parametric_offset = physics::ParametricValue(1);
  expectedParaPoints.push_back(para_point);
  para_point.lane_id = lane::LaneId(491);
  para_point.parametric_offset = physics::ParametricValue(0);
  expectedParaPoints.push_back(para_point);
  para_point.lane_id = lane::LaneId(526);
  para_point.parametric_offset = physics::ParametricValue(0);
  expectedParaPoints.push_back(para_point);
  compareParaLists(resultParaPoints, expectedParaPoints);

  resultParaPoints = intersection->paraPointsOnRoute();
  expectedParaPoints.clear();
  para_point.lane_id = lane::LaneId(360);
  para_point.parametric_offset = physics::ParametricValue(1);
  expectedParaPoints.push_back(para_point);
  para_point.lane_id = lane::LaneId(621);
  para_point.parametric_offset = physics::ParametricValue(1);
  expectedParaPoints.push_back(para_point);
  para_point.lane_id = lane::LaneId(624);
  para_point.parametric_offset = physics::ParametricValue(1);
  expectedParaPoints.push_back(para_point);
  compareParaLists(resultParaPoints, expectedParaPoints);

  physics::Speed speed;
  speed = intersection->getSpeedLimit();
  ASSERT_NEAR(speed.mSpeed, 13.888, 0.001);

  route::RoutePlanningCounter routeCounter;
  routeCounter = intersection->getRoutePlanningCounter();
  ASSERT_EQ(fullRoute.route_planning_counter, routeCounter);
  route::SegmentCounter segmentCounter;
  segmentCounter = intersection->getRouteSegmentCountFromDestination();
  ASSERT_EQ(segmentCounter, 4u);
  intersection->updateRouteCounters(4, 5);
  routeCounter = intersection->getRoutePlanningCounter();
  ASSERT_EQ(routeCounter, 4u);
  segmentCounter = intersection->getRouteSegmentCountFromDestination();
  ASSERT_EQ(segmentCounter, 5u);
  intersection->updateRouteCounters(2, 4);
}

TEST_F(IntersectionTest, traffic_lights_pfz_rusch_to_elf)
{
  using point::createGeoPoint;
  using namespace point;
  ASSERT_NO_THROW(::map_setup::prepareMapTrafficLightsPfz());
  // inner lane (1990)
  auto fromSouth = createGeoPoint(Longitude(8.457617), Latitude(49.020345), Altitude(0.));
  lane::LaneId fromSouthId = lane::uniqueLaneId(fromSouth);
  // 1912
  auto toWest = createGeoPoint(Longitude(8.458091), Latitude(49.020521), Altitude(0.));
  lane::LaneId toWestId = lane::uniqueLaneId(toWest);
  point::ParaPoint routeStart(point::createParaPoint(fromSouthId, physics::ParametricValue(0.5)));
  point::ParaPoint routeEnd(point::createParaPoint(toWestId, physics::ParametricValue(0.5)));
  auto fullRoute = route::planning::planRoute(routeStart, routeEnd);
  // contain right arrow type traffic light
  // no additional lanes with higher priorities
  auto intersections = intersection::Intersection::getIntersectionsForRoute(fullRoute);
  ASSERT_EQ(1u, intersections.size());
  auto const &intersection = intersections[0];
  auto iType = intersection->intersectionType();
  ASSERT_EQ(intersection::IntersectionType::TrafficLight, iType);
  auto const &priorityLanes = intersection->incomingParaPointsWithHigherPriority();
  ASSERT_EQ(priorityLanes.size(), 0u);
  auto const &lights = intersection->applicableTrafficLights();
  ASSERT_EQ(2u, lights.size());
  point::GeoPoint geo_point;
  landmark::LandmarkId id1, id2;
  geo_point = point::createGeoPoint(point::Longitude(8.457704425), point::Latitude(49.02050956), point::Altitude(5.));
  id1 = landmark::uniqueLandmarkId(geo_point);
  geo_point = point::createGeoPoint(point::Longitude(8.457737438), point::Latitude(49.02050359), point::Altitude(3.));
  id2 = landmark::uniqueLandmarkId(geo_point);
  ASSERT_EQ(1u, lights.count(id1));
  ASSERT_EQ(1u, lights.count(id2));

  lane::LaneIdSet resultLaneIdSets, expectedLaneIdSets;
  resultLaneIdSets = intersection->lanesOnRoute();
  expectedLaneIdSets = lane::LaneIdSet({lane::LaneId{382}, lane::LaneId{621}, lane::LaneId{624}});
  compareLists(resultLaneIdSets, expectedLaneIdSets);

  resultLaneIdSets = intersection->incomingLanesOnRoute();
  expectedLaneIdSets = lane::LaneIdSet({lane::LaneId{588}, lane::LaneId{598}});
  compareLists(resultLaneIdSets, expectedLaneIdSets);

  resultLaneIdSets = intersection->outgoingLanesOnRoute();
  expectedLaneIdSets = lane::LaneIdSet({lane::LaneId{508}});
  compareLists(resultLaneIdSets, expectedLaneIdSets);

  resultLaneIdSets = intersection->internalLanesWithLowerPriority();
  expectedLaneIdSets = lane::LaneIdSet({lane::LaneId{187},
                                        lane::LaneId{199},
                                        lane::LaneId{220},
                                        lane::LaneId{231},
                                        lane::LaneId{253},
                                        lane::LaneId{275},
                                        lane::LaneId{297},
                                        lane::LaneId{318},
                                        lane::LaneId{339},
                                        lane::LaneId{360},
                                        lane::LaneId{404},
                                        lane::LaneId{425},
                                        lane::LaneId{446},
                                        lane::LaneId{467},
                                        lane::LaneId{475},
                                        lane::LaneId{479},
                                        lane::LaneId{511},
                                        lane::LaneId{514},
                                        lane::LaneId{552}});
  compareLists(resultLaneIdSets, expectedLaneIdSets);

  resultLaneIdSets = intersection->outgoingLanes();
  expectedLaneIdSets
    = lane::LaneIdSet({lane::LaneId{471}, lane::LaneId{508}, lane::LaneId{548}, lane::LaneId{627}, lane::LaneId{630}});
  compareLists(resultLaneIdSets, expectedLaneIdSets);

  resultLaneIdSets = intersection->entryLanes();
  expectedLaneIdSets = lane::LaneIdSet({lane::LaneId{487},
                                        lane::LaneId{491},
                                        lane::LaneId{522},
                                        lane::LaneId{526},
                                        lane::LaneId{578},
                                        lane::LaneId{588},
                                        lane::LaneId{598}});
  compareLists(resultLaneIdSets, expectedLaneIdSets);

  point::ParaPointList resultParaPoints, expectedParaPoints;
  point::ParaPoint para_point;
  resultParaPoints = intersection->paraPointsOnRoute();
  expectedParaPoints.clear();
  para_point.lane_id = lane::LaneId(621);
  para_point.parametric_offset = physics::ParametricValue(1);
  expectedParaPoints.push_back(para_point);
  para_point.lane_id = lane::LaneId(382);
  para_point.parametric_offset = physics::ParametricValue(1);
  expectedParaPoints.push_back(para_point);
  para_point.lane_id = lane::LaneId(624);
  para_point.parametric_offset = physics::ParametricValue(1);
  expectedParaPoints.push_back(para_point);
  compareParaLists(resultParaPoints, expectedParaPoints);

  resultParaPoints = intersection->incomingParaPointsOnRoute();
  expectedParaPoints.clear();
  para_point.lane_id = lane::LaneId(588);
  para_point.parametric_offset = physics::ParametricValue(1);
  expectedParaPoints.push_back(para_point);
  para_point.lane_id = lane::LaneId(598);
  para_point.parametric_offset = physics::ParametricValue(1);
  expectedParaPoints.push_back(para_point);
  compareParaLists(resultParaPoints, expectedParaPoints);

  resultParaPoints = intersection->outgoingParaPoints();
  expectedParaPoints.clear();
  para_point.lane_id = lane::LaneId(627);
  para_point.parametric_offset = physics::ParametricValue(1);
  expectedParaPoints.push_back(para_point);
  para_point.lane_id = lane::LaneId(548);
  para_point.parametric_offset = physics::ParametricValue(0);
  expectedParaPoints.push_back(para_point);
  para_point.lane_id = lane::LaneId(471);
  para_point.parametric_offset = physics::ParametricValue(0);
  expectedParaPoints.push_back(para_point);
  para_point.lane_id = lane::LaneId(630);
  para_point.parametric_offset = physics::ParametricValue(1);
  expectedParaPoints.push_back(para_point);
  para_point.lane_id = lane::LaneId(508);
  para_point.parametric_offset = physics::ParametricValue(0);
  expectedParaPoints.push_back(para_point);
  compareParaLists(resultParaPoints, expectedParaPoints);

  resultParaPoints = intersection->entryParaPoints();
  expectedParaPoints.clear();
  para_point.lane_id = lane::LaneId(487);
  para_point.parametric_offset = physics::ParametricValue(0);
  expectedParaPoints.push_back(para_point);
  para_point.lane_id = lane::LaneId(526);
  para_point.parametric_offset = physics::ParametricValue(0);
  expectedParaPoints.push_back(para_point);
  para_point.lane_id = lane::LaneId(598);
  para_point.parametric_offset = physics::ParametricValue(1);
  expectedParaPoints.push_back(para_point);
  para_point.lane_id = lane::LaneId(522);
  para_point.parametric_offset = physics::ParametricValue(0);
  expectedParaPoints.push_back(para_point);
  para_point.lane_id = lane::LaneId(588);
  para_point.parametric_offset = physics::ParametricValue(1);
  expectedParaPoints.push_back(para_point);
  para_point.lane_id = lane::LaneId(578);
  para_point.parametric_offset = physics::ParametricValue(0);
  expectedParaPoints.push_back(para_point);
  para_point.lane_id = lane::LaneId(491);
  para_point.parametric_offset = physics::ParametricValue(0);
  expectedParaPoints.push_back(para_point);
  compareParaLists(resultParaPoints, expectedParaPoints);

  resultParaPoints = intersection->paraPointsOnRoute();
  expectedParaPoints.clear();
  para_point.lane_id = lane::LaneId(621);
  para_point.parametric_offset = physics::ParametricValue(1);
  expectedParaPoints.push_back(para_point);
  para_point.lane_id = lane::LaneId(382);
  para_point.parametric_offset = physics::ParametricValue(1);
  expectedParaPoints.push_back(para_point);
  para_point.lane_id = lane::LaneId(624);
  para_point.parametric_offset = physics::ParametricValue(1);
  expectedParaPoints.push_back(para_point);
  compareParaLists(resultParaPoints, expectedParaPoints);

  physics::Speed speed;
  speed = intersection->getSpeedLimit();
  ASSERT_NEAR(speed.mSpeed, 13.888, 0.001);

  route::RoutePlanningCounter routeCounter;
  routeCounter = intersection->getRoutePlanningCounter();
  ASSERT_EQ(fullRoute.route_planning_counter, routeCounter);
  route::SegmentCounter segmentCounter;
  segmentCounter = intersection->getRouteSegmentCountFromDestination();
  ASSERT_EQ(segmentCounter, 4u);
  intersection->updateRouteCounters(4, 5);
  routeCounter = intersection->getRoutePlanningCounter();
  ASSERT_EQ(routeCounter, 4u);
  segmentCounter = intersection->getRouteSegmentCountFromDestination();
  ASSERT_EQ(segmentCounter, 5u);
  intersection->updateRouteCounters(3, 4);
}

TEST_F(IntersectionTest, extract_turn_direction)
{
  using point::createGeoPoint;
  using namespace point;
  ASSERT_NO_THROW(::map_setup::prepareMapTrafficLightsPfz());
  // inner lane (1990)
  auto fromSouth = createGeoPoint(Longitude(8.457617), Latitude(49.020345), Altitude(0.));
  lane::LaneId fromSouthId = lane::uniqueLaneId(fromSouth);
  point::ParaPoint routeStart(point::createParaPoint(fromSouthId, physics::ParametricValue(0.5)));
  // left turn
  {
    // 1964
    auto toEast = createGeoPoint(Longitude(8.457384), Latitude(49.020785), Altitude(0.));
    lane::LaneId toEastId = lane::uniqueLaneId(toEast);
    point::ParaPoint routeEnd(point::createParaPoint(toEastId, physics::ParametricValue(0.5)));
    auto fullRoute = route::planning::planRoute(routeStart, routeEnd);
    auto intersections = intersection::Intersection::getIntersectionsForRoute(fullRoute);
    ASSERT_EQ(1u, intersections.size());
    auto const &intersection = intersections[0];
    auto const &outgoing = intersection->outgoingParaPointsOnRoute();
    ASSERT_EQ(outgoing.size(), 1u);
    ASSERT_EQ(intersection::TurnDirection::Left, intersection->turnDirection());
  }
  // straight
  {
    // 1944
    auto toNorth = createGeoPoint(Longitude(8.457968), Latitude(49.020877), Altitude(0.));
    lane::LaneId toNorthId = lane::uniqueLaneId(toNorth);
    point::ParaPoint routeEnd(point::createParaPoint(toNorthId, physics::ParametricValue(0.5)));
    auto fullRoute = route::planning::planRoute(routeStart, routeEnd);
    auto intersections = intersection::Intersection::getIntersectionsForRoute(fullRoute);
    ASSERT_EQ(1u, intersections.size());
    auto const &intersection = intersections[0];
    ASSERT_EQ(intersection::TurnDirection::Straight, intersection->turnDirection());
  }
  // right turn
  {
    // 1912
    auto toWest = createGeoPoint(Longitude(8.458091), Latitude(49.020521), Altitude(0.));
    lane::LaneId toWestId = lane::uniqueLaneId(toWest);
    point::ParaPoint routeEnd(point::createParaPoint(toWestId, physics::ParametricValue(0.5)));
    auto fullRoute = route::planning::planRoute(routeStart, routeEnd);
    auto intersections = intersection::Intersection::getIntersectionsForRoute(fullRoute);
    ASSERT_EQ(1u, intersections.size());
    auto const &intersection = intersections[0];
    ASSERT_EQ(intersection::TurnDirection::Right, intersection->turnDirection());
  }
}

TEST_F(IntersectionTest, validate_tpk_to_pfz_map)
{
  ASSERT_NO_THROW(::map_setup::prepareMapTpkPfzDrive());
  // use map-matching to be independent of lane ids
  auto start = point::createGeoPoint(point::Longitude(8.4571128), point::Latitude(49.0169280), point::Altitude(0));
  auto end = point::createGeoPoint(point::Longitude(8.457508), point::Latitude(49.019861), point::Altitude(0));
  match::AdMapMatching mapMatching;
  auto from = mapMatching.getMapMatchedPositions(start, physics::Distance(1), physics::Probability(0.5));
  auto to = mapMatching.getMapMatchedPositions(end, physics::Distance(1), physics::Probability(0.5));
  ASSERT_EQ(from.size(), 1u);
  ASSERT_EQ(to.size(), 1u);
  auto fullRoute = route::planning::planRoute(from[0].lane_point.para_point, to[0].lane_point.para_point);
  auto intersections = intersection::Intersection::getIntersectionsForRoute(fullRoute);
  ASSERT_EQ(1u, intersections.size());
  auto const &intersection = intersections[0];
  auto iType = intersection->intersectionType();
  ASSERT_EQ(intersection::IntersectionType::TrafficLight, iType);

  intersection::IntersectionPtr ptrInter;
  ASSERT_FALSE((bool)ptrInter);
  ptrInter = intersection->getNextIntersectionOnRoute(fullRoute);
  ASSERT_TRUE((bool)ptrInter);
  ASSERT_EQ(intersection::IntersectionType::TrafficLight, ptrInter->intersectionType());

  match::MapMatchedObjectBoundingBox object;
  match::LaneOccupiedRegion region;
  ASSERT_FALSE(intersection->objectWithinIntersection(object));
  ASSERT_FALSE(intersection->objectOnIncomingLane(object));
  ASSERT_FALSE(intersection->objectOnInternalLaneWithLowerPriority(object));
  ASSERT_FALSE(intersection->objectOnIncomingLaneWithLowerPriority(object));
  ASSERT_FALSE(intersection->objectOnLaneWithLowerPriority(object));
  ASSERT_FALSE(intersection->objectOnInternalLaneWithHigherPriority(object));
  ASSERT_FALSE(intersection->objectOnIncomingLaneWithHigherPriority(object));
  ASSERT_FALSE(intersection->objectOnLaneWithHigherPriority(object));
  ASSERT_FALSE(intersection->objectOnCrossingLane(object));
  ASSERT_FALSE(intersection->objectOnIntersectionRoute(object));

  object.lane_occupied_regions.clear();
  region.lane_id = lane::LaneId(7127);
  object.lane_occupied_regions.push_back(region);
  ASSERT_TRUE(intersection->objectWithinIntersection(object));

  object.lane_occupied_regions.clear();
  region.lane_id = lane::LaneId(11514);
  object.lane_occupied_regions.push_back(region);
  ASSERT_TRUE(intersection->objectOnIncomingLane(object));

  object.lane_occupied_regions.clear();
  region.lane_id = lane::LaneId(11334);
  object.lane_occupied_regions.push_back(region);
  ASSERT_TRUE(intersection->objectOnInternalLaneWithLowerPriority(object));

  object.lane_occupied_regions.clear();
  region.lane_id = lane::LaneId(11517);
  object.lane_occupied_regions.push_back(region);
  ASSERT_TRUE(intersection->objectOnIncomingLaneWithLowerPriority(object));

  object.lane_occupied_regions.clear();
  region.lane_id = lane::LaneId(11517);
  object.lane_occupied_regions.push_back(region);
  ASSERT_TRUE(intersection->objectOnLaneWithLowerPriority(object));

  physics::Distance dis;
  match::Object obj;

  object.lane_occupied_regions.clear();
  region.lane_id = lane::LaneId(7127);
  object.lane_occupied_regions.push_back(region);
  obj.map_matched_bounding_box = object;
  dis = intersection->objectDistanceToIntersection(obj);
  ASSERT_NEAR(dis.mDistance, 0., 0.0001);

  object.lane_occupied_regions.clear();
  region.lane_id = lane::LaneId(7127);
  object.lane_occupied_regions.push_back(region);
  obj.map_matched_bounding_box = object;
  obj.enu_position.dimension.length = physics::Distance(1.0);
  dis = intersection->objectInterpenetrationDistanceWithIntersection(obj);
  ASSERT_NEAR(dis.mDistance, 1.0, 0.0001);

  route::FindWaypointResult findWaypoint = route::intersectionOnRoute(*intersection, fullRoute);
  ASSERT_TRUE(findWaypoint.isValid());
  route::FullRoute routeConstruct;

  ::ad::map::route::LaneSegment laneSegment;
  laneSegment.lane_interval.lane_id = lane::LaneId(7127);
  laneSegment.lane_interval.start = ::ad::physics::ParametricValue(0.2);
  laneSegment.lane_interval.end = ::ad::physics::ParametricValue(0.8);

  ::ad::map::route::LaneSegmentList drivable_lane_segments;
  drivable_lane_segments.push_back(laneSegment);
  ::ad::map::route::RoadSegment roadSegment;
  roadSegment.drivable_lane_segments = drivable_lane_segments;
  ::ad::map::route::RoadSegmentList road_segments;
  road_segments.push_back(roadSegment);
  routeConstruct.road_segments = road_segments;

  route::FindWaypointResult findWaypoint1 = route::intersectionOnRoute(*intersection, routeConstruct);
  ASSERT_TRUE(findWaypoint1.isValid());

  ASSERT_FALSE(intersection->objectRouteCrossesIntersectionRoute(fullRoute));
  ASSERT_TRUE(intersection->objectRouteFromSameArmAsIntersectionRoute(fullRoute));
  ASSERT_FALSE(intersection->objectRouteOppositeToIntersectionRoute(fullRoute));
  ASSERT_FALSE(intersection->objectRouteCrossesLanesWithHigherPriority(fullRoute));
}

TEST_F(IntersectionTest, validate_entry_exit_parapoints)
{
  ASSERT_TRUE(access::init("test_files/Town01.txt"));
  auto coreIntersections = ad::map::intersection::CoreIntersection::getCoreIntersectionsForMap();
  ASSERT_EQ(12u, coreIntersections.size());

  processEachIntersectionEntryPoints(coreIntersections);
  processEachIntersectionExitPoints(coreIntersections);
}

} // namespace map
} // namespace ad
