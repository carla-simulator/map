// ----------------- BEGIN LICENSE BLOCK ---------------------------------
//
// Copyright (C) 2018-2021 Intel Corporation
//
// SPDX-License-Identifier: MIT
//
// ----------------- END LICENSE BLOCK -----------------------------------

#include <ad/map/access/Factory.hpp>
#include <ad/map/access/Operation.hpp>
#include <ad/map/lane/LaneOperation.hpp>
#include <ad/map/point/Operation.hpp>
#include <ad/map/route/LaneIntervalOperation.hpp>
#include <ad/map/route/RouteOperation.hpp>
#include <ad/map/route/Types.hpp>
#include <algorithm>
#include <gtest/gtest.h>
#include "../point/RandomGeometry.hpp"

using namespace ::ad;
using namespace ::ad::map;
using namespace ::ad::map::route;
using namespace ::ad::map::point;
using namespace ::ad::map::lane;

struct LaneIntervalOperationTest : ::testing::Test
{
  LaneIntervalOperationTest()
  {
  }

  virtual void SetUp()
  {
  }
  virtual void TearDown()
  {
    access::cleanup();
  }
  void setupSingleLongLaneV1()
  {
    mStorePtr.reset(new access::Store());
    pFactory.reset(new access::Factory(*mStorePtr));
    // setup one single long lane
    point::GeoPoint bottomRight
      = point::createGeoPoint(point::Longitude(8.04937788), point::Latitude(49.00736837), point::Altitude(0.));
    point::GeoPoint upRight
      = point::createGeoPoint(point::Longitude(8.05010064), point::Latitude(49.00884320), point::Altitude(0.));
    point::GeoPoint bottomLeft
      = point::createGeoPoint(point::Longitude(8.04933898), point::Latitude(49.00737633), point::Altitude(0.));
    point::GeoPoint upLeft
      = point::createGeoPoint(point::Longitude(8.05006151), point::Latitude(49.00885163), point::Altitude(0.));

    point::ECEFPointList rightPoints;
    rightPoints.push_back(point::toECEF(bottomRight));
    rightPoints.push_back(point::toECEF(upRight));
    rightEdge = point::createGeometry(rightPoints, false);
    point::ECEFPointList leftPoints;
    leftPoints.push_back(point::toECEF(bottomLeft));
    leftPoints.push_back(point::toECEF(upLeft));
    leftEdge = point::createGeometry(leftPoints, false);
    pFactory->set(access::TrafficType::RIGHT_HAND_TRAFFIC);

    pFactory->add(p, lane_id, lane::LaneType::NORMAL, lane::LaneDirection::POSITIVE);

    pFactory->set(lane_id, leftEdge, rightEdge);

    access::cleanup();
    ASSERT_TRUE(access::init(mStorePtr));
  }
  void setupSingleLongLaneV2()
  {
    mStorePtr.reset(new access::Store());
    pFactory.reset(new access::Factory(*mStorePtr));

    pts_ecef1.clear();
    pts_ecef2.clear();
    basePoint = randECEFPoint();
    pts_ecef1.push_back(basePoint);
    pts_ecef1.push_back(basePoint + createECEFPoint(10., 0., 0.));
    pts_ecef2.push_back(basePoint + createECEFPoint(0., 10., 0.));
    pts_ecef2.push_back(basePoint + createECEFPoint(10., 10., 0.));
    geo1 = createGeometry(pts_ecef1, false);
    geo2 = createGeometry(pts_ecef2, false);
    x12 = lane::LaneId(i++);
    pFactory->add(p, x12, lane::LaneType::NORMAL, lane::LaneDirection::POSITIVE);
    pFactory->set(access::TrafficType::RIGHT_HAND_TRAFFIC);
    pFactory->set(x12, geo1, geo2);
    laneInt1.start = ::ad::physics::ParametricValue(0.2);
    laneInt1.end = ::ad::physics::ParametricValue(0.8);
    laneInt2.start = ::ad::physics::ParametricValue(0.8);
    laneInt2.end = ::ad::physics::ParametricValue(0.2);

    access::cleanup();
    ASSERT_TRUE(access::init(mStorePtr));
  }
  lane::LaneId lane_id{4711}, x11, x12, x13;
  uint32_t i = 100;
  route::LaneInterval laneInt1, laneInt2;
  ECEFPoint basePoint;
  ECEFPointList pts_ecef1, pts_ecef2, pts_ecef3, pts_ecef4;
  access::PartitionId p{0};
  point::Geometry leftEdge, rightEdge, geo1, geo2;
  access::Store::Ptr mStorePtr;
  std::shared_ptr<access::Factory> pFactory;
};

TEST_F(LaneIntervalOperationTest, LaneIntervalOperation)
{
  setupSingleLongLaneV1();
  laneInt1.lane_id = lane_id;
  laneInt1.start = ::ad::physics::ParametricValue(0.2);
  laneInt1.end = ::ad::physics::ParametricValue(0.8);

  point::ParaPoint first, second;
  first.lane_id = lane::LaneId(100);
  first.parametric_offset = ::ad::physics::ParametricValue(0.2);
  second.lane_id = lane::LaneId(100);
  second.parametric_offset = ::ad::physics::ParametricValue(0.8);
  EXPECT_THROW(getSignedDistance(laneInt1, first, second), std::invalid_argument);
  EXPECT_THROW(getUnsignedDistance(laneInt1, first, second), std::invalid_argument);
  first.lane_id = lane::LaneId(4711);
  EXPECT_THROW(getSignedDistance(laneInt1, first, second), std::invalid_argument);
  EXPECT_THROW(getUnsignedDistance(laneInt1, first, second), std::invalid_argument);
  second.lane_id = lane::LaneId(4711);
  ASSERT_EQ(getSignedDistance(laneInt1, first, second), ::ad::physics::ParametricValue(0.6));
  laneInt1.end = ::ad::physics::ParametricValue(0.1);
  ASSERT_EQ(getSignedDistance(laneInt1, first, second), ::ad::physics::ParametricValue(-0.6));
  ASSERT_EQ(getUnsignedDistance(laneInt1, first, second), ::ad::physics::ParametricValue(0.6));

  laneInt1.start = laneInt1.end = ::ad::physics::ParametricValue(0.5);
  ASSERT_EQ(extendIntervalFromStart(laneInt1, physics::Distance(0.5)), laneInt1);
  ASSERT_EQ(extendIntervalFromEnd(laneInt1, physics::Distance(0.5)), laneInt1);

  LaneInterval resultInterval;
  ASSERT_EQ(extendIntervalUntilStart(laneInt1), laneInt1);
  ASSERT_EQ(extendIntervalUntilEnd(laneInt1), laneInt1);

  laneInt1.end = ::ad::physics::ParametricValue(0.8);
  resultInterval = laneInt1;
  resultInterval.start = ::ad::physics::ParametricValue(0.0);
  ASSERT_EQ(extendIntervalUntilStart(laneInt1), resultInterval);
  resultInterval = laneInt1;
  resultInterval.end = ::ad::physics::ParametricValue(1.0);
  ASSERT_EQ(extendIntervalUntilEnd(laneInt1), resultInterval);

  laneInt1.end = ::ad::physics::ParametricValue(0.2);
  resultInterval = laneInt1;
  resultInterval.start = ::ad::physics::ParametricValue(1.0);
  ASSERT_EQ(extendIntervalUntilStart(laneInt1), resultInterval);
  resultInterval = laneInt1;
  resultInterval.end = ::ad::physics::ParametricValue(0.0);
  ASSERT_EQ(extendIntervalUntilEnd(laneInt1), resultInterval);

  laneInt1.end = ::ad::physics::ParametricValue(0.8);
  resultInterval = laneInt1;
  ASSERT_EQ(cutIntervalAtStart(laneInt1, ::ad::physics::ParametricValue(0.1)), resultInterval);
  ASSERT_EQ(cutIntervalAtEnd(laneInt1, ::ad::physics::ParametricValue(0.1)), resultInterval);

  resultInterval.start = ::ad::physics::ParametricValue(0.6);
  ASSERT_EQ(cutIntervalAtStart(laneInt1, ::ad::physics::ParametricValue(0.6)), resultInterval);
  resultInterval = laneInt1;
  resultInterval.end = ::ad::physics::ParametricValue(0.6);
  ASSERT_EQ(cutIntervalAtEnd(laneInt1, ::ad::physics::ParametricValue(0.6)), resultInterval);

  laneInt1.start = ::ad::physics::ParametricValue(0.5);
  laneInt1.end = ::ad::physics::ParametricValue(0.3);
  resultInterval = shortenIntervalFromBegin(laneInt1, physics::Distance(17.2351));
  ASSERT_EQ(resultInterval.lane_id, laneInt1.lane_id);
  ASSERT_EQ(resultInterval.end, laneInt1.end);
  ASSERT_NEAR(resultInterval.start.mParametricValue, 0.4, 0.0001);

  resultInterval = restrictIntervalFromBegin(laneInt1, physics::Distance(17.2351));
  ASSERT_EQ(resultInterval.lane_id, laneInt1.lane_id);
  ASSERT_EQ(resultInterval.start, laneInt1.start);
  ASSERT_NEAR(resultInterval.end.mParametricValue, 0.4, 0.0001);
  laneInt1.start = ::ad::physics::ParametricValue(0.3);
  laneInt1.end = ::ad::physics::ParametricValue(0.5);
  resultInterval = restrictIntervalFromBegin(laneInt1, physics::Distance(17.2351));
  ASSERT_EQ(resultInterval.lane_id, laneInt1.lane_id);
  ASSERT_EQ(resultInterval.start, laneInt1.start);
  ASSERT_NEAR(resultInterval.end.mParametricValue, 0.4, 0.0001);
}

TEST_F(LaneIntervalOperationTest, GetEdgeAndBorder)
{
  setupSingleLongLaneV2();

  GeoEdge edge_geo1, edge_geo2;
  ECEFEdge edge_ecef1;
  Geometry geo3, geo4;

  laneInt1.lane_id = x12;

  lane::ECEFBorder border_ecef1;
  border_ecef1 = getECEFBorder(laneInt1);
  pts_ecef3.clear();
  pts_ecef4.clear();
  pts_ecef3.push_back(basePoint + createECEFPoint(2., 0., 0.));
  pts_ecef3.push_back(basePoint + createECEFPoint(8., 0., 0.));
  pts_ecef4.push_back(basePoint + createECEFPoint(2., 10., 0.));
  pts_ecef4.push_back(basePoint + createECEFPoint(8., 10., 0.));
  ASSERT_EQ(border_ecef1.left.points, pts_ecef3);
  ASSERT_EQ(border_ecef1.right.points, pts_ecef4);

  RoadSegment roadSeg;
  struct LaneSegment laneSeg;
  laneSeg.lane_interval = laneInt1;
  roadSeg.drivable_lane_segments.push_back(laneSeg);
  {
    lane::ECEFBorder border_ecef_road;
    border_ecef_road = getECEFBorderOfRoadSegment(roadSeg, physics::ParametricValue(0.1));
    // road segment borders use projection
    ASSERT_EQ(border_ecef_road.left.edge_type, lane::EdgeType::LEFT_PROJECTED);
    ASSERT_EQ(border_ecef_road.right.edge_type, lane::EdgeType::RIGHT_PROJECTED);
    // lane interval borders not, so adapt before check the reset for equality
    // since in the case of one straight lane interval the projection has no effect
    border_ecef_road.left.edge_type = lane::EdgeType::LEFT;
    border_ecef_road.right.edge_type = lane::EdgeType::RIGHT;
    ASSERT_EQ(border_ecef1.left, border_ecef_road.left);
    ASSERT_EQ(border_ecef1.right, border_ecef_road.right);
  }

  edge_ecef1 = getLeftECEFEdge(laneInt1);
  ASSERT_EQ(edge_ecef1.points, pts_ecef3);
  edge_ecef1 = getRightECEFEdge(laneInt1);
  ASSERT_EQ(edge_ecef1.points, pts_ecef4);

  lane::GeoBorder geo_border1 = getGeoBorder(laneInt1);
  ASSERT_EQ(geo_border1.left.points, toGeo(pts_ecef3));
  ASSERT_EQ(geo_border1.right.points, toGeo(pts_ecef4));

  {
    lane::GeoBorder border_geo_road;
    border_geo_road = getGeoBorderOfRoadSegment(roadSeg, physics::ParametricValue(0.1));
    // road segment borders use projection
    ASSERT_EQ(border_geo_road.left.edge_type, lane::EdgeType::LEFT_PROJECTED);
    ASSERT_EQ(border_geo_road.right.edge_type, lane::EdgeType::RIGHT_PROJECTED);
    // lane interval borders not, so adapt before check the reset for equality
    // since in the case of one straight lane interval the projection has no effect
    border_geo_road.left.edge_type = lane::EdgeType::LEFT;
    border_geo_road.right.edge_type = lane::EdgeType::RIGHT;
    ASSERT_EQ(geo_border1.left, border_geo_road.left);
    ASSERT_EQ(geo_border1.right, border_geo_road.right);
  }

  edge_geo1 = getLeftGeoEdge(laneInt1);
  ASSERT_EQ(edge_geo1.points, toGeo(pts_ecef3));
  edge_geo1 = getRightGeoEdge(laneInt1);
  ASSERT_EQ(edge_geo1.points, toGeo(pts_ecef4));

  GeoPoint geo_pt1 = toGeo(basePoint);
  access::setENUReferencePoint(geo_pt1);
  CoordinateTransform mCoordinateTransform;
  mCoordinateTransform.setENUReferencePoint(access::getENUReferencePoint());
  lane::ENUBorder border_enu1 = getENUBorder(laneInt1);
  ENUEdge edge_enu1, edge_enu2, edge_enu3;
  edge_enu1.points.push_back(mCoordinateTransform.ECEF2ENU(basePoint + createECEFPoint(2., 0., 0.)));
  edge_enu1.points.push_back(mCoordinateTransform.ECEF2ENU(basePoint + createECEFPoint(8., 0., 0.)));
  edge_enu1.edge_type = lane::EdgeType::LEFT;
  edge_enu1.lateral_alignment = lane::cLateralAlignmentLeft;
  edge_enu2.points.push_back(mCoordinateTransform.ECEF2ENU(basePoint + createECEFPoint(2., 10., 0.)));
  edge_enu2.points.push_back(mCoordinateTransform.ECEF2ENU(basePoint + createECEFPoint(8., 10., 0.)));
  edge_enu2.edge_type = lane::EdgeType::RIGHT;
  edge_enu2.lateral_alignment = lane::cLateralAlignmentRight;
  ASSERT_EQ(border_enu1.left, edge_enu1);
  ASSERT_EQ(border_enu1.right, edge_enu2);

  {
    lane::ENUBorder border_enu_road;
    border_enu_road = getENUBorderOfRoadSegment(roadSeg, physics::ParametricValue(0.1));
    // road segment borders use projection
    ASSERT_EQ(border_enu_road.left.edge_type, lane::EdgeType::LEFT_PROJECTED);
    ASSERT_EQ(border_enu_road.right.edge_type, lane::EdgeType::RIGHT_PROJECTED);
    // lane interval borders not, so adapt before check the reset for equality
    // since in the case of one straight lane interval the projection has no effect
    border_enu_road.left.edge_type = lane::EdgeType::LEFT;
    border_enu_road.right.edge_type = lane::EdgeType::RIGHT;
    ASSERT_EQ(border_enu1.left, border_enu_road.left);
    ASSERT_EQ(border_enu1.right, border_enu_road.right);
  }

  edge_enu3 = getLeftENUEdge(laneInt1);
  ASSERT_EQ(edge_enu3, edge_enu1);
  edge_enu3 = getRightENUEdge(laneInt1);
  ASSERT_EQ(edge_enu3, edge_enu2);

  border_enu1 = getENUProjectedBorder(laneInt1);
  // used projection
  ASSERT_EQ(border_enu1.left.edge_type, lane::EdgeType::LEFT_PROJECTED);
  ASSERT_EQ(border_enu1.right.edge_type, lane::EdgeType::RIGHT_PROJECTED);
  // lane interval borders not, so adapt before check the reset for equality
  // since in the case of one straight lane interval the projection has no effect
  border_enu1.left.edge_type = lane::EdgeType::LEFT;
  border_enu1.right.edge_type = lane::EdgeType::RIGHT;
  ASSERT_EQ(border_enu1.left, edge_enu1);
  ASSERT_EQ(border_enu1.right, edge_enu2);
  edge_enu3 = getLeftProjectedENUEdge(laneInt1);
  // used projection
  ASSERT_EQ(edge_enu3.edge_type, lane::EdgeType::LEFT_PROJECTED);
  edge_enu3.edge_type = lane::EdgeType::LEFT;
  ASSERT_EQ(edge_enu3, edge_enu1);
  edge_enu3 = getRightProjectedENUEdge(laneInt1);
  // used projection
  ASSERT_EQ(edge_enu3.edge_type, lane::EdgeType::RIGHT_PROJECTED);
  edge_enu3.edge_type = lane::EdgeType::RIGHT;
  ASSERT_EQ(edge_enu3, edge_enu2);

  laneInt2.lane_id = x12;

  edge_ecef1 = getLeftECEFEdge(laneInt2);
  reverse(pts_ecef4.begin(), pts_ecef4.end());
  ASSERT_EQ(edge_ecef1.points, pts_ecef4);

  edge_ecef1 = getRightECEFEdge(laneInt2);
  reverse(pts_ecef3.begin(), pts_ecef3.end());
  ASSERT_EQ(edge_ecef1.points, pts_ecef3);

  edge_geo1 = getLeftGeoEdge(laneInt2);
  ASSERT_EQ(edge_geo1.points, toGeo(pts_ecef4));
  edge_geo1 = getRightGeoEdge(laneInt2);
  ASSERT_EQ(edge_geo1.points, toGeo(pts_ecef3));

  // create reverted version of edge_enu1/2
  auto reverted_edge_enu1 = edge_enu1;
  reverse(reverted_edge_enu1.points.begin(), reverted_edge_enu1.points.end());
  reverted_edge_enu1.edge_type = edge_enu2.edge_type;
  reverted_edge_enu1.lateral_alignment = edge_enu2.lateral_alignment;
  auto reverted_edge_enu2 = edge_enu2;
  reverse(reverted_edge_enu2.points.begin(), reverted_edge_enu2.points.end());
  reverted_edge_enu2.edge_type = edge_enu1.edge_type;
  reverted_edge_enu2.lateral_alignment = edge_enu1.lateral_alignment;

  edge_enu3 = getLeftProjectedENUEdge(laneInt2);
  // used projection
  ASSERT_EQ(edge_enu3.edge_type, lane::EdgeType::LEFT_PROJECTED);
  edge_enu3.edge_type = lane::EdgeType::LEFT;
  ASSERT_EQ(edge_enu3, reverted_edge_enu2);
  edge_enu3 = getRightProjectedENUEdge(laneInt2);
  // used projection
  ASSERT_EQ(edge_enu3.edge_type, lane::EdgeType::RIGHT_PROJECTED);
  edge_enu3.edge_type = lane::EdgeType::RIGHT;
  ASSERT_EQ(edge_enu3, reverted_edge_enu1);

  border_enu1 = getENUProjectedBorder(laneInt2);
  // used projection
  ASSERT_EQ(border_enu1.left.edge_type, lane::EdgeType::LEFT_PROJECTED);
  ASSERT_EQ(border_enu1.right.edge_type, lane::EdgeType::RIGHT_PROJECTED);
  border_enu1.left.edge_type = lane::EdgeType::LEFT;
  border_enu1.right.edge_type = lane::EdgeType::RIGHT;
  ASSERT_EQ(border_enu1.left, reverted_edge_enu2);
  ASSERT_EQ(border_enu1.right, reverted_edge_enu1);
}

TEST_F(LaneIntervalOperationTest, GetProjectedENUEdgeOnTown01)
{
  ASSERT_TRUE(access::init("test_files/Town01.txt"));

  ENUPoint point_edu1 = createENUPoint(4.453, -4.560, 0);
  ASSERT_NEAR(lane::calcWidth(point_edu1).mDistance, 3.99, 0.0001);
  GeoPoint point_geo1 = toGeo(point_edu1);
  auto startLaneId = lane::uniqueLaneId(point_geo1);
  laneInt1.lane_id = startLaneId;
  laneInt1.start = ::ad::physics::ParametricValue(0.2);
  laneInt1.end = ::ad::physics::ParametricValue(0.8);
  laneInt2.lane_id = startLaneId;
  laneInt2.start = ::ad::physics::ParametricValue(0.8);
  laneInt2.end = ::ad::physics::ParametricValue(0.2);

  ENUEdge edge_enu1, edge_enu2, edge_enu3, edge_enu4;
  edge_enu1 = getLeftProjectedENUEdge(laneInt1);
  ASSERT_GT(edge_enu1.points.size(), 0u);

  edge_enu2 = getRightProjectedENUEdge(laneInt1);
  ASSERT_GT(edge_enu2.points.size(), 0u);

  lane::ENUBorder border_enu1;
  border_enu1 = getENUProjectedBorder(laneInt1);
  ASSERT_EQ(border_enu1.left, edge_enu1);
  ASSERT_EQ(border_enu1.right, edge_enu2);

  // create reverted version of edge_enu1/2
  auto reverted_edge_enu1 = edge_enu1;
  reverse(reverted_edge_enu1.points.begin(), reverted_edge_enu1.points.end());
  reverted_edge_enu1.edge_type = edge_enu2.edge_type;
  reverted_edge_enu1.lateral_alignment = edge_enu2.lateral_alignment;
  auto reverted_edge_enu2 = edge_enu2;
  reverse(reverted_edge_enu2.points.begin(), reverted_edge_enu2.points.end());
  reverted_edge_enu2.edge_type = edge_enu1.edge_type;
  reverted_edge_enu2.lateral_alignment = edge_enu1.lateral_alignment;

  edge_enu3 = getLeftProjectedENUEdge(laneInt2);
  ASSERT_EQ(edge_enu3, reverted_edge_enu2);

  edge_enu4 = getRightProjectedENUEdge(laneInt2);
  ASSERT_EQ(edge_enu4, reverted_edge_enu1);

  border_enu1 = getENUProjectedBorder(laneInt2);
  ASSERT_EQ(border_enu1.left, reverted_edge_enu2);
  ASSERT_EQ(border_enu1.right, reverted_edge_enu1);
}

TEST_F(LaneIntervalOperationTest, GetProjectedOffsetOnNeighborLane)
{
  setupSingleLongLaneV2();
  physics::ParametricValue paraVal;

  laneInt2.lane_id = lane::LaneId(1003);
  EXPECT_THROW(getProjectedParametricOffsetOnNeighborLane(laneInt1, laneInt2, ::ad::physics::ParametricValue(0.8)),
               std::invalid_argument);

  laneInt1.lane_id = x12;
  laneInt2.lane_id = x12;
  paraVal = getProjectedParametricOffsetOnNeighborLane(laneInt1, laneInt2, ::ad::physics::ParametricValue(0.8));
  ASSERT_EQ(paraVal, ::ad::physics::ParametricValue(0.8));

  pts_ecef1.clear();
  pts_ecef2.clear();
  pts_ecef1.push_back(createECEFPoint(20000, 200000, 300000));
  pts_ecef1.push_back(createECEFPoint(30000, 200000, 300000));
  pts_ecef2.push_back(createECEFPoint(20000, 300000, 300000));
  pts_ecef2.push_back(createECEFPoint(30000, 300000, 300000));
  geo1 = createGeometry(pts_ecef1, false);
  geo2 = createGeometry(pts_ecef2, false);
  x11 = lane::LaneId(i++);
  pFactory->add(p, x11, lane::LaneType::NORMAL, lane::LaneDirection::POSITIVE);
  pFactory->set(x11, geo1, geo2);

  pts_ecef1.clear();
  pts_ecef2.clear();
  pts_ecef1.push_back(createECEFPoint(30000, 200000, 300000));
  pts_ecef1.push_back(createECEFPoint(40000, 200000, 300000));
  pts_ecef2.push_back(createECEFPoint(30000, 300000, 300000));
  pts_ecef2.push_back(createECEFPoint(40000, 300000, 300000));
  geo1 = createGeometry(pts_ecef1, false);
  geo2 = createGeometry(pts_ecef2, false);
  x12 = lane::LaneId(i++);
  pFactory->add(p, x12, lane::LaneType::NORMAL, lane::LaneDirection::POSITIVE);
  pFactory->set(x12, geo1, geo2);

  pts_ecef1.clear();
  pts_ecef2.clear();
  pts_ecef1.push_back(createECEFPoint(40000, 200000, 300000));
  pts_ecef1.push_back(createECEFPoint(50000, 200000, 300000));
  pts_ecef2.push_back(createECEFPoint(40000, 300000, 300000));
  pts_ecef2.push_back(createECEFPoint(50000, 300000, 300000));
  geo1 = createGeometry(pts_ecef1, false);
  geo2 = createGeometry(pts_ecef2, false);
  x13 = lane::LaneId(i++);
  pFactory->add(p, x13, lane::LaneType::NORMAL, lane::LaneDirection::POSITIVE);
  pFactory->set(x13, geo1, geo2);

  lane::ContactLocation left(lane::ContactLocation::LEFT);
  lane::ContactLocation right(lane::ContactLocation::RIGHT);
  lane::ContactTypeList free({lane::ContactType::FREE});
  restriction::Restriction all_vehicles;
  all_vehicles.road_user_types
    = {restriction::RoadUserType::CAR, restriction::RoadUserType::BUS, restriction::RoadUserType::TRUCK};
  restriction::RestrictionList all_vehicles_list;
  all_vehicles_list.push_back(all_vehicles);
  restriction::Restrictions all_vehicle_restrs;
  all_vehicle_restrs.conjunctions = all_vehicles_list;
  ASSERT_TRUE(pFactory->add(x12, x11, left, free, all_vehicle_restrs));
  ASSERT_TRUE(pFactory->add(x12, x13, right, free, all_vehicle_restrs));

  laneInt1.lane_id = x12;
  laneInt1.start = ::ad::physics::ParametricValue(0.2);
  laneInt1.end = ::ad::physics::ParametricValue(0.8);
  laneInt2.lane_id = x11;
  laneInt2.start = ::ad::physics::ParametricValue(0.2);
  laneInt2.end = ::ad::physics::ParametricValue(0.8);
  paraVal = getProjectedParametricOffsetOnNeighborLane(laneInt1, laneInt2, ::ad::physics::ParametricValue(0.8));
  ASSERT_DOUBLE_EQ(paraVal.mParametricValue, 1.0);

  laneInt2.lane_id = x13;
  paraVal = getProjectedParametricOffsetOnNeighborLane(laneInt1, laneInt2, ::ad::physics::ParametricValue(0.8));
  ASSERT_DOUBLE_EQ(paraVal.mParametricValue, 0.0);
}

TEST_F(LaneIntervalOperationTest, RouteInterval)
{
  setupSingleLongLaneV2();
  point::ParaPoint para;
  FullRoute fullRoute;
  EXPECT_THROW(getIntervalStart(fullRoute, x12), std::invalid_argument);

  ::ad::map::route::LaneSegment laneSegment;
  laneSegment.lane_interval.lane_id = x12;
  laneSegment.lane_interval.start = ::ad::physics::ParametricValue(0.2);
  laneSegment.lane_interval.end = ::ad::physics::ParametricValue(0.8);

  ::ad::map::route::LaneSegmentList drivable_lane_segments;
  drivable_lane_segments.push_back(laneSegment);
  ::ad::map::route::RoadSegment roadSegment;
  roadSegment.drivable_lane_segments = drivable_lane_segments;
  ::ad::map::route::RoadSegmentList road_segments;
  road_segments.push_back(roadSegment);
  fullRoute.road_segments = road_segments;
  para = getIntervalStart(fullRoute, x12);
  ASSERT_EQ(para.lane_id, x12);
  ASSERT_EQ(para.parametric_offset, ::ad::physics::ParametricValue(0.2));

  para = getLaneParaPoint(physics::ParametricValue(0.5), laneSegment.lane_interval);
  ASSERT_EQ(para.lane_id, x12);
  ASSERT_NEAR(para.parametric_offset.mParametricValue, 0.5, 0.0001);

  laneSegment.lane_interval.start = ::ad::physics::ParametricValue(0.5);
  laneSegment.lane_interval.end = ::ad::physics::ParametricValue(0.5);
  para = getLaneParaPoint(physics::ParametricValue(0.5), laneSegment.lane_interval);
  ASSERT_EQ(para.lane_id, x12);
  ASSERT_NEAR(para.parametric_offset.mParametricValue, 0.5, 0.0001);

  FullRoute emptyRoute;
  match::MapMatchedPositionConfidenceList centerMapMatched;
  EXPECT_THROW(signedDistanceToLane(lane::LaneId(100), emptyRoute, centerMapMatched), std::runtime_error);

  laneSegment.lane_interval.start = ::ad::physics::ParametricValue(0.5);
  laneSegment.lane_interval.end = ::ad::physics::ParametricValue(0.4);
  para.lane_id = x12;
  para.parametric_offset = ::ad::physics::ParametricValue(0.3);
  ASSERT_TRUE(isAfterInterval(laneSegment.lane_interval, para));
}
