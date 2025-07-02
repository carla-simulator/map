// ----------------- BEGIN LICENSE BLOCK ---------------------------------
//
// Copyright (C) 2020-2021 Intel Corporation
//
// SPDX-License-Identifier: MIT
//
// ----------------- END LICENSE BLOCK -----------------------------------

#include <../src/opendrive/DataTypeConversion.hpp>
#include <ad/map/access/Operation.hpp>
#include <ad/map/access/Store.hpp>
#include <ad/map/config/MapConfigFileHandler.hpp>
#include <ad/map/intersection/Intersection.hpp>
#include <ad/map/intersection/IntersectionType.hpp>
#include <ad/map/intersection/Types.hpp>
#include <ad/map/landmark/LandmarkOperation.hpp>
#include <ad/map/lane/ContactLane.hpp>
#include <ad/map/lane/ContactLaneList.hpp>
#include <ad/map/lane/LaneOperation.hpp>
#include <ad/map/lane/Types.hpp>
#include <ad/map/match/AdMapMatching.hpp>
#include <ad/map/opendrive/AdMapFactory.hpp>
#include <ad/map/point/Operation.hpp>
#include <ad/map/point/Types.hpp>
#include <ad/map/route/Planning.hpp>
#include <ad/map/route/RouteOperation.hpp>
#include <ad/map/serialize/SerializerFileCRC32.hpp>
#include <fstream>
#include <gtest/gtest.h>
#include <streambuf>
#include <string>
#include "ad/map/access/Logging.hpp"
#include "spdlog/spdlog.h"

using namespace ::ad;
using namespace ::ad::map;
using namespace ::ad::map::opendrive;
using namespace ::ad::map::landmark;

struct OpenDriveAccessTests : ::testing::Test
{
  virtual void SetUp()
  {
    access::cleanup();
  }
  virtual void TearDown()
  {
    access::cleanup();
  }

  void checkEdgePoints(lane::LaneId lane_id, point::ECEFPointList const &edge)
  {
    EXPECT_GE(edge.size(), 2u) << lane_id;
    if (edge.size() > 2u)
    {
      for (auto pointIter = edge.begin(); pointIter != edge.end(); pointIter++)
      {
        auto nextPointIter = pointIter + 1;
        if (nextPointIter != edge.end())
        {
          auto deltaPoints = *pointIter - *nextPointIter;
          auto pointDistance = vectorLength(deltaPoints);
          EXPECT_NE(pointDistance, physics::Distance(0.)) << lane_id << " num: " << edge.size();
        }
      }
    }
    physics::ParametricRange trange;
    trange.minimum = physics::ParametricValue(0.);
    trange.maximum = physics::ParametricValue(1.);
    auto ecefs = point::getParametricRange(edge, trange);
    EXPECT_EQ(edge.size(), ecefs.size()) << lane_id;
  }

  void checkEdgeContacts(lane::Lane const &lane)
  {
    if (lane::isRouteable(lane))
    {
      for (auto successorContact : lane::getContactLanes(lane, lane::ContactLocation::SUCCESSOR))
      {
        auto successorLane = lane::getLane(successorContact.to_lane);
        if (successorLane.direction == lane.direction)
        {
          EXPECT_EQ(lane.edge_left.ecef_points.back(), successorLane.edge_left.ecef_points.front())
            << lane.id << " succ: " << successorLane.id << " " << toENU(lane.edge_left.ecef_points.back())
            << toENU(successorLane.edge_left.ecef_points.front());
          EXPECT_EQ(lane.edge_right.ecef_points.back(), successorLane.edge_right.ecef_points.front())
            << lane.id << " succ: " << successorLane.id << " " << toENU(lane.edge_right.ecef_points.back())
            << toENU(successorLane.edge_right.ecef_points.front());
        }
        else
        {
          EXPECT_EQ(lane.edge_left.ecef_points.back(), successorLane.edge_right.ecef_points.back())
            << lane.id << " succ: " << successorLane.id << " " << toENU(lane.edge_left.ecef_points.back())
            << toENU(successorLane.edge_right.ecef_points.back());
          EXPECT_EQ(lane.edge_right.ecef_points.back(), successorLane.edge_left.ecef_points.back())
            << lane.id << " succ: " << successorLane.id << " " << toENU(lane.edge_right.ecef_points.back())
            << toENU(successorLane.edge_left.ecef_points.back());
        }
      }
      for (auto predecessorContact : lane::getContactLanes(lane, lane::ContactLocation::PREDECESSOR))
      {
        auto predecessorLane = lane::getLane(predecessorContact.to_lane);
        if (predecessorLane.direction == lane.direction)
        {
          EXPECT_EQ(lane.edge_left.ecef_points.front(), predecessorLane.edge_left.ecef_points.back())
            << lane.id << " pre: " << predecessorLane.id << " " << toENU(lane.edge_left.ecef_points.front())
            << toENU(predecessorLane.edge_left.ecef_points.back());
          EXPECT_EQ(lane.edge_right.ecef_points.front(), predecessorLane.edge_right.ecef_points.back())
            << lane.id << " pre: " << predecessorLane.id << " " << toENU(lane.edge_right.ecef_points.front())
            << toENU(predecessorLane.edge_right.ecef_points.back());
        }
        else
        {
          EXPECT_EQ(lane.edge_left.ecef_points.front(), predecessorLane.edge_right.ecef_points.front())
            << lane.id << " pre: " << predecessorLane.id << " " << toENU(lane.edge_left.ecef_points.front())
            << toENU(predecessorLane.edge_right.ecef_points.front());
          EXPECT_EQ(lane.edge_right.ecef_points.front(), predecessorLane.edge_left.ecef_points.front())
            << lane.id << " pre: " << predecessorLane.id << " " << toENU(lane.edge_right.ecef_points.front())
            << toENU(predecessorLane.edge_left.ecef_points.front());
        }
      }
      for (auto leftContact : lane::getContactLanes(lane, lane::ContactLocation::LEFT))
      {
        auto leftLane = lane::getLane(leftContact.to_lane);
        EXPECT_EQ(lane.edge_left.ecef_points.front(), leftLane.edge_right.ecef_points.front())
          << lane.id << " left: " << leftLane.id << " " << toENU(lane.edge_left.ecef_points.front())
          << toENU(leftLane.edge_right.ecef_points.front());
        EXPECT_EQ(lane.edge_left.ecef_points.back(), leftLane.edge_right.ecef_points.back())
          << lane.id << " left: " << leftLane.id << " " << toENU(lane.edge_left.ecef_points.back())
          << toENU(leftLane.edge_right.ecef_points.back());
      }
      for (auto rightContact : lane::getContactLanes(lane, lane::ContactLocation::RIGHT))
      {
        auto rightLane = lane::getLane(rightContact.to_lane);
        EXPECT_EQ(lane.edge_right.ecef_points.front(), rightLane.edge_left.ecef_points.front())
          << lane.id << " right: " << rightLane.id << " " << toENU(lane.edge_right.ecef_points.front())
          << toENU(rightLane.edge_left.ecef_points.front());
        EXPECT_EQ(lane.edge_right.ecef_points.back(), rightLane.edge_left.ecef_points.back())
          << lane.id << " right: " << rightLane.id << " " << toENU(lane.edge_right.ecef_points.back())
          << toENU(rightLane.edge_left.ecef_points.back());
      }
    }
  }

  void checkAreaMapMatching(lane::LaneIdSet const &lanesToTest, lane::LaneIdSet const &lanesTestArea)
  {
    match::AdMapMatching mapMatching;
    mapMatching.setRelevantLanes(lanesTestArea);

    for (auto lane_id : lanesToTest)
    {
      auto lane = lane::getLane(lane_id);
      auto ecefPoint0 = lane::getParametricPoint(lane, physics::ParametricValue(0.), physics::ParametricValue(.5));
      auto enuPoint0 = point::toENU(ecefPoint0);
      auto mapMatchedPositions0
        = mapMatching.getMapMatchedPositions(enuPoint0, physics::Distance(5.), physics::Probability(0.));
      auto ecefPoint1 = lane::getParametricPoint(lane, physics::ParametricValue(1.), physics::ParametricValue(.5));
      auto enuPoint1 = point::toENU(ecefPoint1);
      auto mapMatchedPositions1
        = mapMatching.getMapMatchedPositions(enuPoint1, physics::Distance(5.), physics::Probability(0.));
      auto contact_lanes = lane::getContactLanes(lane,
                                                 {lane::ContactLocation::LEFT,
                                                  lane::ContactLocation::RIGHT,
                                                  lane::ContactLocation::SUCCESSOR,
                                                  lane::ContactLocation::PREDECESSOR});
      lane::LaneIdSet expectedLanes;
      expectedLanes.insert(lane.id);
      for (auto contactLane : contact_lanes)
      {
        if (lanesTestArea.find(contactLane.to_lane) != lanesTestArea.end())
        {
          expectedLanes.insert(contactLane.to_lane);
        }
      }
      EXPECT_NE(expectedLanes.size(), 0u);
      for (auto const &matchedPosition : mapMatchedPositions0)
      {
        EXPECT_TRUE(lanesTestArea.find(matchedPosition.lane_point.para_point.lane_id) != lanesTestArea.end());
        expectedLanes.erase(matchedPosition.lane_point.para_point.lane_id);
      }
      for (auto const &matchedPosition : mapMatchedPositions1)
      {
        EXPECT_TRUE(lanesTestArea.find(matchedPosition.lane_point.para_point.lane_id) != lanesTestArea.end());
        expectedLanes.erase(matchedPosition.lane_point.para_point.lane_id);
      }

      EXPECT_EQ(expectedLanes.size(), 0u)
        << "LaneID: " << lane.id << " expectedLanes: " << expectedLanes << " testArea: " << lanesTestArea
        << " pos0: " << mapMatchedPositions0 << " pos1: " << mapMatchedPositions1 << " contact: " << contact_lanes;

      mapMatching.addHeadingHint(point::createENUHeading(0.), access::getENUReferencePoint());
      for (auto paramLon = physics::ParametricValue(0.); paramLon <= physics::ParametricValue(1.);
           paramLon += physics::ParametricValue(0.1))
      {
        for (auto paramLat = physics::ParametricValue(0.); paramLat <= physics::ParametricValue(1.);
             paramLat += physics::ParametricValue(0.2))
        {
          auto ecefPoint = lane::getParametricPoint(lane, paramLon, paramLat);
          auto enuPoint = point::toENU(ecefPoint);
          EXPECT_NO_THROW(auto mapMatchedPositions = mapMatching.getMapMatchedPositions(
                            enuPoint, physics::Distance(5.), physics::Probability(0.)));
        }
      }
    }
  }

  intersection::IntersectionType checkRightOfWay(lane::LaneId laneIdOfEntryPoint,
                                                 lane::ContactLocation currentContactLocation)
  {
    auto laneOutside = lane::getLane(laneIdOfEntryPoint);
    for (auto &currentContactFromOutside : lane::getContactLanes(laneOutside, currentContactLocation))
    {
      auto intersectionTypeFromOutside
        = intersection::Intersection::intersectionTypeFromContactTypes(currentContactFromOutside.types);
      if (intersectionTypeFromOutside != intersection::IntersectionType::Unknown)
      {
        return intersectionTypeFromOutside;
      }
      else
      {
        auto laneInside = lane::getLane(currentContactFromOutside.to_lane);
        auto contactLanesFromInside = lane::getContactLane(laneInside, laneIdOfEntryPoint);
        for (auto currentContactLaneFromInside : contactLanesFromInside)
        {
          auto intersectionTypeFromInside
            = intersection::Intersection::intersectionTypeFromContactTypes(currentContactLaneFromInside.types);
          if (intersectionTypeFromInside != intersection::IntersectionType::Unknown)
          {
            return intersectionTypeFromInside;
          }
        }
      }
    }
    return intersection::IntersectionType::Unknown;
  }

  intersection::IntersectionType getIntersectionTypeFromParaPoints(point::ParaPointList const &paraPointsList)
  {
    intersection::IntersectionType intersectionType = intersection::IntersectionType::Unknown;

    for (auto &currentPoint : paraPointsList)
    {
      if (currentPoint.parametric_offset == physics::ParametricValue(1.0))
      {
        intersectionType = checkRightOfWay(currentPoint.lane_id, lane::ContactLocation::SUCCESSOR);
      }
      else
      {
        intersectionType = checkRightOfWay(currentPoint.lane_id, lane::ContactLocation::PREDECESSOR);
      }
    }
    return intersectionType;
  }
};

TEST_F(OpenDriveAccessTests, read_config)
{
  config::MapConfigFileHandler configHandler{};
  ASSERT_TRUE(configHandler.readConfig("test_files/Town01.txt"));
  ASSERT_TRUE(configHandler.isInitialized());
}

TEST_F(OpenDriveAccessTests, read_map)
{
  ASSERT_TRUE(access::init("test_files/Town01.txt"));

  auto lanes = lane::getLanes();
  ASSERT_GT(lanes.size(), 0u);

  // write map for convenience
  access::saveAsAdm("test_files/Town01.adm");
}

TEST_F(OpenDriveAccessTests, read_written_map)
{
  ASSERT_TRUE(access::init("test_files/Town01.adm.txt"));

  point::Longitude validLon(0.);
  point::Latitude validLat(0.);
  point::Altitude validAlt(0.);

  auto pExpected = point::createGeoPoint(validLon, validLat, validAlt);
  auto p = access::getENUReferencePoint();
  ASSERT_EQ(pExpected, p);

  auto lanes = lane::getLanes();
  ASSERT_GT(lanes.size(), 0u);
}

TEST_F(OpenDriveAccessTests, lane_points_town01)
{
  ASSERT_TRUE(access::init("test_files/Town01.txt"));

  for (auto lane_id : lane::getLanes())
  {
    auto lane = lane::getLane(lane_id);
    checkEdgePoints(lane.id, lane.edge_left.ecef_points);
    checkEdgePoints(lane.id, lane.edge_right.ecef_points);
  }
}

TEST_F(OpenDriveAccessTests, lane_contact_points_town01)
{
  ASSERT_TRUE(access::init("test_files/Town01.txt"));

  for (auto lane_id : lane::getLanes())
  {
    auto lane = lane::getLane(lane_id);
    checkEdgeContacts(lane);
  }
}

TEST_F(OpenDriveAccessTests, lane_points_town03)
{
  ASSERT_TRUE(access::init("test_files/Town03.txt"));

  for (auto lane_id : lane::getLanes())
  {
    auto lane = lane::getLane(lane_id);
    checkEdgePoints(lane.id, lane.edge_left.ecef_points);
    checkEdgePoints(lane.id, lane.edge_right.ecef_points);
  }
}

TEST_F(OpenDriveAccessTests, lane_contact_points_town03)
{
  ASSERT_TRUE(access::init("test_files/Town03.txt"));

  for (auto lane_id : lane::getLanes())
  {
    auto lane = lane::getLane(lane_id);
    checkEdgeContacts(lane);
  }
}

TEST_F(OpenDriveAccessTests, lane_points_town04)
{
  ASSERT_TRUE(access::init("test_files/Town04.txt"));

  for (auto lane_id : lane::getLanes())
  {
    auto lane = lane::getLane(lane_id);
    checkEdgePoints(lane.id, lane.edge_left.ecef_points);
    checkEdgePoints(lane.id, lane.edge_right.ecef_points);
  }
}

TEST_F(OpenDriveAccessTests, lane_contact_points_town04)
{
  ASSERT_TRUE(access::init("test_files/Town04.txt"));

  for (auto lane_id : lane::getLanes())
  {
    auto lane = lane::getLane(lane_id);
    checkEdgeContacts(lane);
  }
}

TEST_F(OpenDriveAccessTests, map_matching_town01_relevant_lanes_map_area)
{
  ASSERT_TRUE(access::init("test_files/Town01.txt"));

  std::vector<point::BoundingSphere> boundingSpheres;
  auto tileRadius = physics::Distance(10);
  for (auto xCoordinate = point::ENUCoordinate(-tileRadius.mDistance); xCoordinate < point::ENUCoordinate(500.);
       xCoordinate += point::ENUCoordinate(1.5 * tileRadius.mDistance))
  {
    for (auto yCoordinate = point::ENUCoordinate(tileRadius.mDistance); yCoordinate > -point::ENUCoordinate(500.);
         yCoordinate -= point::ENUCoordinate(1.5 * tileRadius.mDistance))
    {
      point::BoundingSphere bounding_sphere;
      bounding_sphere.center = point::toECEF(point::createENUPoint(xCoordinate, yCoordinate, point::ENUCoordinate(0.)));
      bounding_sphere.radius = tileRadius;
      boundingSpheres.push_back(bounding_sphere);
    }
  }

  std::vector<lane::LaneIdSet> boundingSphereLanesToTest;
  std::vector<lane::LaneIdSet> boundingSphereLanesTestArea;
  boundingSphereLanesToTest.resize(boundingSpheres.size());
  boundingSphereLanesTestArea.resize(boundingSpheres.size());
  for (auto lane_id : lane::getLanes())
  {
    auto lane = lane::getLane(lane_id);
    bool laneConsidered = false;
    for (auto i = 0u; i < boundingSpheres.size(); i++)
    {
      auto const laneDistance = point::distance(lane.bounding_sphere, boundingSpheres[i]);
      if (!laneConsidered && (laneDistance == physics::Distance(0.)))
      {
        boundingSphereLanesToTest[i].insert(lane_id);
        laneConsidered = true;
      }
      if (laneDistance <= physics::Distance(5.))
      {
        boundingSphereLanesTestArea[i].insert(lane_id);
      }
    }
    if (!laneConsidered)
    {
      EXPECT_TRUE(false) << lane_id << " " << point::toENU(lane.bounding_sphere.center);
    }
  }

  size_t testedLanesCount = 0u;
  for (auto i = 0u; i < boundingSpheres.size(); i++)
  {
    testedLanesCount += boundingSphereLanesToTest[i].size();
    checkAreaMapMatching(boundingSphereLanesToTest[i], boundingSphereLanesTestArea[i]);
  }
  ASSERT_EQ(testedLanesCount, lane::getLanes().size());
}

TEST_F(OpenDriveAccessTests, TrafficSignTest)
{
  ASSERT_TRUE(access::init("test_files/bad/Town01copy.txt"));
  LandmarkIdList idList;
  idList = getLandmarks();
  ASSERT_EQ(idList.size(), 3u);
}

TEST_F(OpenDriveAccessTests, defaultIntersectionType)
{
  ASSERT_TRUE(access::init("test_files/bad/Town01copyAllWayStop.txt"));
  access::cleanup();
  ASSERT_TRUE(access::init("test_files/bad/Town01copyCrosswalk.txt"));
  access::cleanup();
  ASSERT_TRUE(access::init("test_files/bad/Town01copyHasWay.txt"));
  access::cleanup();
  ASSERT_TRUE(access::init("test_files/bad/Town01copyPriorityToRight.txt"));
  access::cleanup();
  ASSERT_TRUE(access::init("test_files/bad/Town01copyPriorityToRightAndStraight.txt"));
  access::cleanup();
  ASSERT_TRUE(access::init("test_files/bad/Town01copyStop.txt"));
  access::cleanup();
  ASSERT_TRUE(access::init("test_files/bad/Town01copyTrafficLight.txt"));
  access::cleanup();
  ASSERT_TRUE(access::init("test_files/bad/Town01copyUnknown.txt"));
  access::cleanup();
  ASSERT_TRUE(access::init("test_files/bad/Town01copyYield.txt"));
  access::cleanup();
  ASSERT_FALSE(access::init("test_files/bad/Town01copyNotValid.txt"));
  access::cleanup();
}

TEST_F(OpenDriveAccessTests, branch)
{
  access::Store::Ptr mStorePtr;
  mStorePtr.reset(new access::Store());
  ad::map::opendrive::AdMapFactory factory(*mStorePtr);
  ASSERT_FALSE(factory.createAdMap(std::string("test_files/bad/NoneExists.xodr"), 2.0));

  access::cleanup();
  ASSERT_FALSE(factory.createAdMap(std::string("test_files/bad/TownEmpty.xodr"), 2.0));
}

TEST_F(OpenDriveAccessTests, DataTypeConversion)
{
  ASSERT_TRUE(access::init("test_files/Town01.txt"));
  ASSERT_EQ(landmark::LandmarkType::TRAFFIC_LIGHT, toLandmarkType(1000001));
  ASSERT_EQ(landmark::LandmarkType::OTHER, toLandmarkType(1000003));
  ASSERT_EQ(landmark::LandmarkType::TRAFFIC_SIGN, toLandmarkType(101));
  ASSERT_EQ(landmark::LandmarkType::UNKNOWN, toLandmarkType(99));

  ASSERT_EQ(landmark::TrafficSignType::DANGER, toTrafficSignType(101, 0));
  ASSERT_EQ(landmark::TrafficSignType::DANGER, toTrafficSignType(102, 0));

  ASSERT_EQ(landmark::TrafficSignType::LANES_MERGING, toTrafficSignType(120, 0));

  ASSERT_EQ(landmark::TrafficSignType::CAUTION_PEDESTRIAN, toTrafficSignType(133, 0));

  ASSERT_EQ(landmark::TrafficSignType::CAUTION_BICYCLE, toTrafficSignType(138, 0));
  ASSERT_EQ(landmark::TrafficSignType::YIELD, toTrafficSignType(205, 0));
  ASSERT_EQ(landmark::TrafficSignType::STOP, toTrafficSignType(206, 0));

  ASSERT_EQ(landmark::TrafficSignType::ROUNDABOUT, toTrafficSignType(215, 0));
  ASSERT_EQ(landmark::TrafficSignType::PASS_RIGHT, toTrafficSignType(222, 0));

  ASSERT_EQ(landmark::TrafficSignType::ACCESS_FORBIDDEN, toTrafficSignType(250, 0));
  ASSERT_EQ(landmark::TrafficSignType::ACCESS_FORBIDDEN_MOTORVEHICLES, toTrafficSignType(251, 0));
  ASSERT_EQ(landmark::TrafficSignType::ACCESS_FORBIDDEN_TRUCKS, toTrafficSignType(253, 0));
  ASSERT_EQ(landmark::TrafficSignType::ACCESS_FORBIDDEN_BICYCLE, toTrafficSignType(254, 0));
  ASSERT_EQ(landmark::TrafficSignType::ACCESS_FORBIDDEN_WEIGHT, toTrafficSignType(263, 0));
  ASSERT_EQ(landmark::TrafficSignType::ACCESS_FORBIDDEN_WIDTH, toTrafficSignType(264, 0));
  ASSERT_EQ(landmark::TrafficSignType::ACCESS_FORBIDDEN_HEIGHT, toTrafficSignType(265, 0));
  ASSERT_EQ(landmark::TrafficSignType::ACCESS_FORBIDDEN_WRONG_DIR, toTrafficSignType(267, 0));

  ASSERT_EQ(landmark::TrafficSignType::MAX_SPEED, toTrafficSignType(274, -1));
  ASSERT_EQ(landmark::TrafficSignType::SPEED_ZONE_30_BEGIN, toTrafficSignType(274, 1));
  ASSERT_EQ(landmark::TrafficSignType::SPEED_ZONE_30_END, toTrafficSignType(274, 2));
  ASSERT_EQ(landmark::TrafficSignType::MAX_SPEED, toTrafficSignType(274, 3));

  ASSERT_EQ(landmark::TrafficSignType::HAS_WAY_NEXT_INTERSECTION, toTrafficSignType(301, 0));
  ASSERT_EQ(landmark::TrafficSignType::PRIORITY_WAY, toTrafficSignType(306, 0));
  ASSERT_EQ(landmark::TrafficSignType::CITY_BEGIN, toTrafficSignType(310, 0));
  ASSERT_EQ(landmark::TrafficSignType::CITY_END, toTrafficSignType(311, 0));
  ASSERT_EQ(landmark::TrafficSignType::MOTORVEHICLE_BEGIN, toTrafficSignType(331, 0));
  ASSERT_EQ(landmark::TrafficSignType::UNKNOWN, toTrafficSignType(332, 0));

  ASSERT_EQ(lane::ContactType::YIELD, toContactType(205));
  ASSERT_EQ(lane::ContactType::STOP, toContactType(206));
  ASSERT_EQ(lane::ContactType::RIGHT_OF_WAY, toContactType(301));
  ASSERT_EQ(lane::ContactType::RIGHT_OF_WAY, toContactType(306));
  ASSERT_EQ(lane::ContactType::TRAFFIC_LIGHT, toContactType(1000001));
  ASSERT_EQ(lane::ContactType::UNKNOWN, toContactType(1100001));

  ASSERT_EQ(landmark::TrafficLightType::SOLID_RED_YELLOW_GREEN, toTrafficLightType(1000001, 0));
  ASSERT_EQ(landmark::TrafficLightType::PEDESTRIAN_RED_GREEN, toTrafficLightType(1000002, 0));
  ASSERT_EQ(landmark::TrafficLightType::BIKE_PEDESTRIAN_RED_GREEN, toTrafficLightType(1000007, 0));
  ASSERT_EQ(landmark::TrafficLightType::UNKNOWN, toTrafficLightType(1000008, 0));
  ASSERT_EQ(landmark::TrafficLightType::SOLID_RED_YELLOW, toTrafficLightType(1000009, 0));
  ASSERT_EQ(landmark::TrafficLightType::UNKNOWN, toTrafficLightType(1000010, 0));
  ASSERT_EQ(landmark::TrafficLightType::LEFT_RED_YELLOW_GREEN, toTrafficLightType(1000011, 10));
  ASSERT_EQ(landmark::TrafficLightType::RIGHT_RED_YELLOW_GREEN, toTrafficLightType(1000011, 20));
  ASSERT_EQ(landmark::TrafficLightType::STRAIGHT_RED_YELLOW_GREEN, toTrafficLightType(1000011, 30));
  ASSERT_EQ(landmark::TrafficLightType::LEFT_STRAIGHT_RED_YELLOW_GREEN, toTrafficLightType(1000011, 40));
  ASSERT_EQ(landmark::TrafficLightType::RIGHT_STRAIGHT_RED_YELLOW_GREEN, toTrafficLightType(1000011, 50));
  ASSERT_EQ(landmark::TrafficLightType::UNKNOWN, toTrafficLightType(1000011, 60));
  ASSERT_EQ(landmark::TrafficLightType::UNKNOWN, toTrafficLightType(1000012, 0));
  ASSERT_EQ(landmark::TrafficLightType::BIKE_RED_GREEN, toTrafficLightType(1000013, 0));
  ASSERT_EQ(landmark::TrafficLightType::UNKNOWN, toTrafficLightType(1000014, 0));
  ASSERT_EQ(landmark::TrafficLightType::UNKNOWN, toTrafficLightType(1000015, 0));
  ASSERT_EQ(landmark::TrafficLightType::UNKNOWN, toTrafficLightType(1000016, 0));

  ::opendrive::SignalReference signalReference;
  signalReference.parametricPosition = 0.5;
  ASSERT_EQ(lane::ContactLocation::SUCCESSOR, toContactLocation(signalReference, true));
  signalReference.parametricPosition = 0.4;
  ASSERT_EQ(lane::ContactLocation::PREDECESSOR, toContactLocation(signalReference, true));
  signalReference.inLaneOrientation = true;
  ASSERT_EQ(lane::ContactLocation::SUCCESSOR, toContactLocation(signalReference, false));
  signalReference.inLaneOrientation = false;
  ASSERT_EQ(lane::ContactLocation::PREDECESSOR, toContactLocation(signalReference, false));
  ASSERT_EQ(landmark::LandmarkId(100), toLandmarkId((int)100));
}

TEST_F(OpenDriveAccessTests, verify_intersections_Town01)
{
  ASSERT_TRUE(access::init("test_files/Town01.txt"));

  auto coreIntersections = ad::map::intersection::CoreIntersection::getCoreIntersectionsForMap();
  ASSERT_EQ(12u, coreIntersections.size());

  point::ParaPointList entryParaPoints, exitParaPoints;

  for (auto &eachcoreIntersection : coreIntersections)
  {
    entryParaPoints = eachcoreIntersection->entryParaPoints();
    EXPECT_EQ(intersection::IntersectionType::TrafficLight, getIntersectionTypeFromParaPoints(entryParaPoints));
  }

  for (auto &eachcoreIntersection : coreIntersections)
  {
    exitParaPoints = eachcoreIntersection->exitParaPoints();
    EXPECT_EQ(intersection::IntersectionType::Unknown, getIntersectionTypeFromParaPoints(exitParaPoints));
  }
}

TEST_F(OpenDriveAccessTests, verify_intersections_AllWayStop)
{
  ASSERT_TRUE(access::init("test_files/AllWayStop.adm.txt"));
  auto coreIntersections = ad::map::intersection::CoreIntersection::getCoreIntersectionsForMap();
  ASSERT_EQ(1u, coreIntersections.size());

  point::ParaPointList entryParaPoints, exitParaPoints;

  for (auto &eachcoreIntersection : coreIntersections)
  {
    entryParaPoints = eachcoreIntersection->entryParaPoints();
    EXPECT_EQ(intersection::IntersectionType::AllWayStop, getIntersectionTypeFromParaPoints(entryParaPoints));
  }

  for (auto &eachcoreIntersection : coreIntersections)
  {
    exitParaPoints = eachcoreIntersection->exitParaPoints();
    EXPECT_EQ(intersection::IntersectionType::Unknown, getIntersectionTypeFromParaPoints(exitParaPoints));
  }
}

TEST_F(OpenDriveAccessTests, verify_default_handling)
{
  std::ifstream mapFile("test_files/Town04.xodr");
  std::stringstream openDriveContentStream;

  openDriveContentStream << mapFile.rdbuf();
  std::string openDriveContent = openDriveContentStream.str();
  ASSERT_TRUE(access::initFromOpenDriveContent(
    openDriveContent, 0.2, intersection::IntersectionType::HasWay, landmark::TrafficLightType::SOLID_RED_YELLOW));

  auto incomingLane
    = point::createGeoPoint(point::Longitude(-0.00118857), point::Latitude(-0.000331594), point::AltitudeUnknown);
  lane::LaneId incomingLaneId = lane::uniqueLaneId(incomingLane);
  auto outgoingLane
    = createGeoPoint(point::Longitude(-0.00103814), point::Latitude(-0.000329589), point::AltitudeUnknown);
  lane::LaneId outgoingLaneId = lane::uniqueLaneId(outgoingLane);
  point::ParaPoint routeStart(point::createParaPoint(incomingLaneId, physics::ParametricValue(0.5)));
  point::ParaPoint routeEnd(point::createParaPoint(outgoingLaneId, physics::ParametricValue(0.5)));
  auto fullRoute = route::planning::planRoute(routeStart, routeEnd);
  ASSERT_GT(route::calcLength(fullRoute), physics::Distance(0.));
  std::vector<intersection::IntersectionPtr> intersections;
  ASSERT_NO_THROW(intersections = intersection::Intersection::getIntersectionsForRoute(fullRoute));
  ASSERT_EQ(1u, intersections.size());

  for (auto &each : intersections)
  {
    auto entryParaPoints = each->entryParaPoints();
    for (auto &eachParaPoint : entryParaPoints)
    {
      if (eachParaPoint.lane_id == incomingLaneId)
      {
        EXPECT_EQ(intersection::IntersectionType::HasWay, getIntersectionTypeFromParaPoints({eachParaPoint}));
      }
    }

    auto exitParaPoints = each->exitParaPoints();
    for (auto &eachParaPoint : exitParaPoints)
    {
      if (eachParaPoint.lane_id == outgoingLaneId)
      {
        EXPECT_EQ(intersection::IntersectionType::Unknown, getIntersectionTypeFromParaPoints({eachParaPoint}));
      }
    }
  }
}
