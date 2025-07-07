/*
 * ----------------- BEGIN LICENSE BLOCK ---------------------------------
 *
 * Copyright (C) 2018-2022 Intel Corporation
 *
 * SPDX-License-Identifier: MIT
 *
 * ----------------- END LICENSE BLOCK -----------------------------------
 */

/*
 * Generated file
 */

#if defined(__clang__) && (__clang_major__ >= 7)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wself-assign-overloaded"
#endif

#include <gtest/gtest.h>
#include <limits>
#include "ad/map/route/ConnectingRoute.hpp"

class ConnectingRouteTests : public testing::Test
{
protected:
  virtual void SetUp() override
  {
    // valid initialization
    ::ad::map::route::ConnectingRoute value;
    ::ad::map::route::ConnectingRouteType valueType(::ad::map::route::ConnectingRouteType::Invalid);
    value.type = valueType;
    ::ad::map::route::FullRoute valueRoute_a;
    ::ad::map::route::RoadSegmentList valueRoute_aRoad_segments;
    ::ad::map::route::RoadSegment valueRoute_aRoad_segmentsElement;
    ::ad::map::route::LaneSegmentList valueRoute_aRoad_segmentsElementDrivable_lane_segments;
    ::ad::map::route::LaneSegment valueRoute_aRoad_segmentsElementDrivable_lane_segmentsElement;
    ::ad::map::lane::LaneId valueRoute_aRoad_segmentsElementDrivable_lane_segmentsElementLeft_neighbor(1);
    valueRoute_aRoad_segmentsElementDrivable_lane_segmentsElement.left_neighbor
      = valueRoute_aRoad_segmentsElementDrivable_lane_segmentsElementLeft_neighbor;
    ::ad::map::lane::LaneId valueRoute_aRoad_segmentsElementDrivable_lane_segmentsElementRight_neighbor(1);
    valueRoute_aRoad_segmentsElementDrivable_lane_segmentsElement.right_neighbor
      = valueRoute_aRoad_segmentsElementDrivable_lane_segmentsElementRight_neighbor;
    ::ad::map::lane::LaneIdList valueRoute_aRoad_segmentsElementDrivable_lane_segmentsElementPredecessors;
    ::ad::map::lane::LaneId valueRoute_aRoad_segmentsElementDrivable_lane_segmentsElementPredecessorsElement(1);
    valueRoute_aRoad_segmentsElementDrivable_lane_segmentsElementPredecessors.resize(
      1, valueRoute_aRoad_segmentsElementDrivable_lane_segmentsElementPredecessorsElement);
    valueRoute_aRoad_segmentsElementDrivable_lane_segmentsElement.predecessors
      = valueRoute_aRoad_segmentsElementDrivable_lane_segmentsElementPredecessors;
    ::ad::map::lane::LaneIdList valueRoute_aRoad_segmentsElementDrivable_lane_segmentsElementSuccessors;
    ::ad::map::lane::LaneId valueRoute_aRoad_segmentsElementDrivable_lane_segmentsElementSuccessorsElement(1);
    valueRoute_aRoad_segmentsElementDrivable_lane_segmentsElementSuccessors.resize(
      1, valueRoute_aRoad_segmentsElementDrivable_lane_segmentsElementSuccessorsElement);
    valueRoute_aRoad_segmentsElementDrivable_lane_segmentsElement.successors
      = valueRoute_aRoad_segmentsElementDrivable_lane_segmentsElementSuccessors;
    ::ad::map::route::LaneInterval valueRoute_aRoad_segmentsElementDrivable_lane_segmentsElementLane_interval;
    ::ad::map::lane::LaneId valueRoute_aRoad_segmentsElementDrivable_lane_segmentsElementLane_intervalLane_id(1);
    valueRoute_aRoad_segmentsElementDrivable_lane_segmentsElementLane_interval.lane_id
      = valueRoute_aRoad_segmentsElementDrivable_lane_segmentsElementLane_intervalLane_id;
    ::ad::physics::ParametricValue valueRoute_aRoad_segmentsElementDrivable_lane_segmentsElementLane_intervalStart(0.);
    valueRoute_aRoad_segmentsElementDrivable_lane_segmentsElementLane_interval.start
      = valueRoute_aRoad_segmentsElementDrivable_lane_segmentsElementLane_intervalStart;
    ::ad::physics::ParametricValue valueRoute_aRoad_segmentsElementDrivable_lane_segmentsElementLane_intervalEnd(0.);
    valueRoute_aRoad_segmentsElementDrivable_lane_segmentsElementLane_interval.end
      = valueRoute_aRoad_segmentsElementDrivable_lane_segmentsElementLane_intervalEnd;
    bool valueRoute_aRoad_segmentsElementDrivable_lane_segmentsElementLane_intervalWrong_way{true};
    valueRoute_aRoad_segmentsElementDrivable_lane_segmentsElementLane_interval.wrong_way
      = valueRoute_aRoad_segmentsElementDrivable_lane_segmentsElementLane_intervalWrong_way;
    valueRoute_aRoad_segmentsElementDrivable_lane_segmentsElement.lane_interval
      = valueRoute_aRoad_segmentsElementDrivable_lane_segmentsElementLane_interval;
    ::ad::map::route::RouteLaneOffset valueRoute_aRoad_segmentsElementDrivable_lane_segmentsElementRoute_lane_offset(
      std::numeric_limits<::ad::map::route::RouteLaneOffset>::lowest());
    valueRoute_aRoad_segmentsElementDrivable_lane_segmentsElement.route_lane_offset
      = valueRoute_aRoad_segmentsElementDrivable_lane_segmentsElementRoute_lane_offset;
    valueRoute_aRoad_segmentsElementDrivable_lane_segments.resize(
      1, valueRoute_aRoad_segmentsElementDrivable_lane_segmentsElement);
    valueRoute_aRoad_segmentsElement.drivable_lane_segments = valueRoute_aRoad_segmentsElementDrivable_lane_segments;
    ::ad::map::route::SegmentCounter valueRoute_aRoad_segmentsElementSegment_count_from_destination(
      std::numeric_limits<::ad::map::route::SegmentCounter>::lowest());
    valueRoute_aRoad_segmentsElement.segment_count_from_destination
      = valueRoute_aRoad_segmentsElementSegment_count_from_destination;
    ::ad::map::point::BoundingSphere valueRoute_aRoad_segmentsElementBounding_sphere;
    ::ad::map::point::ECEFPoint valueRoute_aRoad_segmentsElementBounding_sphereCenter;
    ::ad::map::point::ECEFCoordinate valueRoute_aRoad_segmentsElementBounding_sphereCenterX(-6400000);
    valueRoute_aRoad_segmentsElementBounding_sphereCenter.x = valueRoute_aRoad_segmentsElementBounding_sphereCenterX;
    ::ad::map::point::ECEFCoordinate valueRoute_aRoad_segmentsElementBounding_sphereCenterY(-6400000);
    valueRoute_aRoad_segmentsElementBounding_sphereCenter.y = valueRoute_aRoad_segmentsElementBounding_sphereCenterY;
    ::ad::map::point::ECEFCoordinate valueRoute_aRoad_segmentsElementBounding_sphereCenterZ(-6400000);
    valueRoute_aRoad_segmentsElementBounding_sphereCenter.z = valueRoute_aRoad_segmentsElementBounding_sphereCenterZ;
    valueRoute_aRoad_segmentsElementBounding_sphere.center = valueRoute_aRoad_segmentsElementBounding_sphereCenter;
    ::ad::physics::Distance valueRoute_aRoad_segmentsElementBounding_sphereRadius(-1e9);
    valueRoute_aRoad_segmentsElementBounding_sphere.radius = valueRoute_aRoad_segmentsElementBounding_sphereRadius;
    valueRoute_aRoad_segmentsElement.bounding_sphere = valueRoute_aRoad_segmentsElementBounding_sphere;
    valueRoute_aRoad_segments.resize(1, valueRoute_aRoad_segmentsElement);
    valueRoute_a.road_segments = valueRoute_aRoad_segments;
    ::ad::map::route::RoutePlanningCounter valueRoute_aRoute_planning_counter(
      std::numeric_limits<::ad::map::route::RoutePlanningCounter>::lowest());
    valueRoute_a.route_planning_counter = valueRoute_aRoute_planning_counter;
    ::ad::map::route::SegmentCounter valueRoute_aFull_route_segment_count(
      std::numeric_limits<::ad::map::route::SegmentCounter>::lowest());
    valueRoute_a.full_route_segment_count = valueRoute_aFull_route_segment_count;
    ::ad::map::route::RouteLaneOffset valueRoute_aDestination_lane_offset(
      std::numeric_limits<::ad::map::route::RouteLaneOffset>::lowest());
    valueRoute_a.destination_lane_offset = valueRoute_aDestination_lane_offset;
    ::ad::map::route::RouteLaneOffset valueRoute_aMin_lane_offset(
      std::numeric_limits<::ad::map::route::RouteLaneOffset>::lowest());
    valueRoute_a.min_lane_offset = valueRoute_aMin_lane_offset;
    ::ad::map::route::RouteLaneOffset valueRoute_aMax_lane_offset(
      std::numeric_limits<::ad::map::route::RouteLaneOffset>::lowest());
    valueRoute_a.max_lane_offset = valueRoute_aMax_lane_offset;
    ::ad::map::route::RouteCreationMode valueRoute_aRoute_creation_mode(::ad::map::route::RouteCreationMode::Undefined);
    valueRoute_a.route_creation_mode = valueRoute_aRoute_creation_mode;
    value.route_a = valueRoute_a;
    ::ad::map::route::FullRoute valueRoute_b;
    ::ad::map::route::RoadSegmentList valueRoute_bRoad_segments;
    ::ad::map::route::RoadSegment valueRoute_bRoad_segmentsElement;
    ::ad::map::route::LaneSegmentList valueRoute_bRoad_segmentsElementDrivable_lane_segments;
    ::ad::map::route::LaneSegment valueRoute_bRoad_segmentsElementDrivable_lane_segmentsElement;
    ::ad::map::lane::LaneId valueRoute_bRoad_segmentsElementDrivable_lane_segmentsElementLeft_neighbor(1);
    valueRoute_bRoad_segmentsElementDrivable_lane_segmentsElement.left_neighbor
      = valueRoute_bRoad_segmentsElementDrivable_lane_segmentsElementLeft_neighbor;
    ::ad::map::lane::LaneId valueRoute_bRoad_segmentsElementDrivable_lane_segmentsElementRight_neighbor(1);
    valueRoute_bRoad_segmentsElementDrivable_lane_segmentsElement.right_neighbor
      = valueRoute_bRoad_segmentsElementDrivable_lane_segmentsElementRight_neighbor;
    ::ad::map::lane::LaneIdList valueRoute_bRoad_segmentsElementDrivable_lane_segmentsElementPredecessors;
    ::ad::map::lane::LaneId valueRoute_bRoad_segmentsElementDrivable_lane_segmentsElementPredecessorsElement(1);
    valueRoute_bRoad_segmentsElementDrivable_lane_segmentsElementPredecessors.resize(
      1, valueRoute_bRoad_segmentsElementDrivable_lane_segmentsElementPredecessorsElement);
    valueRoute_bRoad_segmentsElementDrivable_lane_segmentsElement.predecessors
      = valueRoute_bRoad_segmentsElementDrivable_lane_segmentsElementPredecessors;
    ::ad::map::lane::LaneIdList valueRoute_bRoad_segmentsElementDrivable_lane_segmentsElementSuccessors;
    ::ad::map::lane::LaneId valueRoute_bRoad_segmentsElementDrivable_lane_segmentsElementSuccessorsElement(1);
    valueRoute_bRoad_segmentsElementDrivable_lane_segmentsElementSuccessors.resize(
      1, valueRoute_bRoad_segmentsElementDrivable_lane_segmentsElementSuccessorsElement);
    valueRoute_bRoad_segmentsElementDrivable_lane_segmentsElement.successors
      = valueRoute_bRoad_segmentsElementDrivable_lane_segmentsElementSuccessors;
    ::ad::map::route::LaneInterval valueRoute_bRoad_segmentsElementDrivable_lane_segmentsElementLane_interval;
    ::ad::map::lane::LaneId valueRoute_bRoad_segmentsElementDrivable_lane_segmentsElementLane_intervalLane_id(1);
    valueRoute_bRoad_segmentsElementDrivable_lane_segmentsElementLane_interval.lane_id
      = valueRoute_bRoad_segmentsElementDrivable_lane_segmentsElementLane_intervalLane_id;
    ::ad::physics::ParametricValue valueRoute_bRoad_segmentsElementDrivable_lane_segmentsElementLane_intervalStart(0.);
    valueRoute_bRoad_segmentsElementDrivable_lane_segmentsElementLane_interval.start
      = valueRoute_bRoad_segmentsElementDrivable_lane_segmentsElementLane_intervalStart;
    ::ad::physics::ParametricValue valueRoute_bRoad_segmentsElementDrivable_lane_segmentsElementLane_intervalEnd(0.);
    valueRoute_bRoad_segmentsElementDrivable_lane_segmentsElementLane_interval.end
      = valueRoute_bRoad_segmentsElementDrivable_lane_segmentsElementLane_intervalEnd;
    bool valueRoute_bRoad_segmentsElementDrivable_lane_segmentsElementLane_intervalWrong_way{true};
    valueRoute_bRoad_segmentsElementDrivable_lane_segmentsElementLane_interval.wrong_way
      = valueRoute_bRoad_segmentsElementDrivable_lane_segmentsElementLane_intervalWrong_way;
    valueRoute_bRoad_segmentsElementDrivable_lane_segmentsElement.lane_interval
      = valueRoute_bRoad_segmentsElementDrivable_lane_segmentsElementLane_interval;
    ::ad::map::route::RouteLaneOffset valueRoute_bRoad_segmentsElementDrivable_lane_segmentsElementRoute_lane_offset(
      std::numeric_limits<::ad::map::route::RouteLaneOffset>::lowest());
    valueRoute_bRoad_segmentsElementDrivable_lane_segmentsElement.route_lane_offset
      = valueRoute_bRoad_segmentsElementDrivable_lane_segmentsElementRoute_lane_offset;
    valueRoute_bRoad_segmentsElementDrivable_lane_segments.resize(
      1, valueRoute_bRoad_segmentsElementDrivable_lane_segmentsElement);
    valueRoute_bRoad_segmentsElement.drivable_lane_segments = valueRoute_bRoad_segmentsElementDrivable_lane_segments;
    ::ad::map::route::SegmentCounter valueRoute_bRoad_segmentsElementSegment_count_from_destination(
      std::numeric_limits<::ad::map::route::SegmentCounter>::lowest());
    valueRoute_bRoad_segmentsElement.segment_count_from_destination
      = valueRoute_bRoad_segmentsElementSegment_count_from_destination;
    ::ad::map::point::BoundingSphere valueRoute_bRoad_segmentsElementBounding_sphere;
    ::ad::map::point::ECEFPoint valueRoute_bRoad_segmentsElementBounding_sphereCenter;
    ::ad::map::point::ECEFCoordinate valueRoute_bRoad_segmentsElementBounding_sphereCenterX(-6400000);
    valueRoute_bRoad_segmentsElementBounding_sphereCenter.x = valueRoute_bRoad_segmentsElementBounding_sphereCenterX;
    ::ad::map::point::ECEFCoordinate valueRoute_bRoad_segmentsElementBounding_sphereCenterY(-6400000);
    valueRoute_bRoad_segmentsElementBounding_sphereCenter.y = valueRoute_bRoad_segmentsElementBounding_sphereCenterY;
    ::ad::map::point::ECEFCoordinate valueRoute_bRoad_segmentsElementBounding_sphereCenterZ(-6400000);
    valueRoute_bRoad_segmentsElementBounding_sphereCenter.z = valueRoute_bRoad_segmentsElementBounding_sphereCenterZ;
    valueRoute_bRoad_segmentsElementBounding_sphere.center = valueRoute_bRoad_segmentsElementBounding_sphereCenter;
    ::ad::physics::Distance valueRoute_bRoad_segmentsElementBounding_sphereRadius(-1e9);
    valueRoute_bRoad_segmentsElementBounding_sphere.radius = valueRoute_bRoad_segmentsElementBounding_sphereRadius;
    valueRoute_bRoad_segmentsElement.bounding_sphere = valueRoute_bRoad_segmentsElementBounding_sphere;
    valueRoute_bRoad_segments.resize(1, valueRoute_bRoad_segmentsElement);
    valueRoute_b.road_segments = valueRoute_bRoad_segments;
    ::ad::map::route::RoutePlanningCounter valueRoute_bRoute_planning_counter(
      std::numeric_limits<::ad::map::route::RoutePlanningCounter>::lowest());
    valueRoute_b.route_planning_counter = valueRoute_bRoute_planning_counter;
    ::ad::map::route::SegmentCounter valueRoute_bFull_route_segment_count(
      std::numeric_limits<::ad::map::route::SegmentCounter>::lowest());
    valueRoute_b.full_route_segment_count = valueRoute_bFull_route_segment_count;
    ::ad::map::route::RouteLaneOffset valueRoute_bDestination_lane_offset(
      std::numeric_limits<::ad::map::route::RouteLaneOffset>::lowest());
    valueRoute_b.destination_lane_offset = valueRoute_bDestination_lane_offset;
    ::ad::map::route::RouteLaneOffset valueRoute_bMin_lane_offset(
      std::numeric_limits<::ad::map::route::RouteLaneOffset>::lowest());
    valueRoute_b.min_lane_offset = valueRoute_bMin_lane_offset;
    ::ad::map::route::RouteLaneOffset valueRoute_bMax_lane_offset(
      std::numeric_limits<::ad::map::route::RouteLaneOffset>::lowest());
    valueRoute_b.max_lane_offset = valueRoute_bMax_lane_offset;
    ::ad::map::route::RouteCreationMode valueRoute_bRoute_creation_mode(::ad::map::route::RouteCreationMode::Undefined);
    valueRoute_b.route_creation_mode = valueRoute_bRoute_creation_mode;
    value.route_b = valueRoute_b;
    ::ad::physics::Distance valueRoute_a_length(-1e9);
    value.route_a_length = valueRoute_a_length;
    ::ad::physics::Distance valueRoute_b_length(-1e9);
    value.route_b_length = valueRoute_b_length;
    ::ad::physics::Probability valueHeading_rating_a(0.);
    value.heading_rating_a = valueHeading_rating_a;
    ::ad::physics::Probability valueHeading_rating_b(0.);
    value.heading_rating_b = valueHeading_rating_b;
    ::ad::map::point::ENUHeading valueRoute_a_heading_start(-3.141592655);
    value.route_a_heading_start = valueRoute_a_heading_start;
    ::ad::map::point::ENUHeading valueRoute_a_heading_end(-3.141592655);
    value.route_a_heading_end = valueRoute_a_heading_end;
    ::ad::map::point::ENUHeading valueRoute_b_heading_start(-3.141592655);
    value.route_b_heading_start = valueRoute_b_heading_start;
    ::ad::map::point::ENUHeading valueRoute_b_heading_end(-3.141592655);
    value.route_b_heading_end = valueRoute_b_heading_end;
    mValue = value;
  }

  ::ad::map::route::ConnectingRoute mValue;
};

TEST_F(ConnectingRouteTests, copyConstruction)
{
  ::ad::map::route::ConnectingRoute value(mValue);
  EXPECT_EQ(mValue, value);
}

TEST_F(ConnectingRouteTests, moveConstruction)
{
  ::ad::map::route::ConnectingRoute tmpValue(mValue);
  ::ad::map::route::ConnectingRoute value(std::move(tmpValue));
  EXPECT_EQ(mValue, value);
}

TEST_F(ConnectingRouteTests, copyAssignment)
{
  ::ad::map::route::ConnectingRoute value;
  value = mValue;
  EXPECT_EQ(mValue, value);
}

TEST_F(ConnectingRouteTests, moveAssignment)
{
  ::ad::map::route::ConnectingRoute tmpValue(mValue);
  ::ad::map::route::ConnectingRoute value;
  value = std::move(tmpValue);
  EXPECT_EQ(mValue, value);
}

TEST_F(ConnectingRouteTests, comparisonOperatorEqual)
{
  ::ad::map::route::ConnectingRoute valueA = mValue;
  ::ad::map::route::ConnectingRoute valueB = mValue;

  EXPECT_TRUE(valueA == valueB);
  EXPECT_FALSE(valueA != valueB);
}

TEST_F(ConnectingRouteTests, stringConversionTest)
{
  std::stringstream stream;
  stream << mValue;
  std::string ostreamStr = stream.str();
  std::string toStr = std::to_string(mValue);
  ASSERT_EQ(ostreamStr, toStr);
}

TEST_F(ConnectingRouteTests, comparisonOperatorTypeDiffers)
{
  ::ad::map::route::ConnectingRoute valueA = mValue;
  ::ad::map::route::ConnectingRouteType type(::ad::map::route::ConnectingRouteType::Merging);
  valueA.type = type;
  ::ad::map::route::ConnectingRoute valueB = mValue;

  EXPECT_FALSE(valueA == valueB);
  EXPECT_TRUE(valueA != valueB);
}

TEST_F(ConnectingRouteTests, comparisonOperatorRoute_aDiffers)
{
  ::ad::map::route::ConnectingRoute valueA = mValue;
  ::ad::map::route::FullRoute route_a;
  ::ad::map::route::RoadSegmentList route_aRoad_segments;
  ::ad::map::route::RoadSegment route_aRoad_segmentsElement;
  ::ad::map::route::LaneSegmentList route_aRoad_segmentsElementDrivable_lane_segments;
  ::ad::map::route::LaneSegment route_aRoad_segmentsElementDrivable_lane_segmentsElement;
  ::ad::map::lane::LaneId route_aRoad_segmentsElementDrivable_lane_segmentsElementLeft_neighbor(
    std::numeric_limits<::ad::map::lane::LaneId>::max());
  route_aRoad_segmentsElementDrivable_lane_segmentsElement.left_neighbor
    = route_aRoad_segmentsElementDrivable_lane_segmentsElementLeft_neighbor;
  ::ad::map::lane::LaneId route_aRoad_segmentsElementDrivable_lane_segmentsElementRight_neighbor(
    std::numeric_limits<::ad::map::lane::LaneId>::max());
  route_aRoad_segmentsElementDrivable_lane_segmentsElement.right_neighbor
    = route_aRoad_segmentsElementDrivable_lane_segmentsElementRight_neighbor;
  ::ad::map::lane::LaneIdList route_aRoad_segmentsElementDrivable_lane_segmentsElementPredecessors;
  ::ad::map::lane::LaneId route_aRoad_segmentsElementDrivable_lane_segmentsElementPredecessorsElement(
    std::numeric_limits<::ad::map::lane::LaneId>::max());
  route_aRoad_segmentsElementDrivable_lane_segmentsElementPredecessors.resize(
    2, route_aRoad_segmentsElementDrivable_lane_segmentsElementPredecessorsElement);
  route_aRoad_segmentsElementDrivable_lane_segmentsElement.predecessors
    = route_aRoad_segmentsElementDrivable_lane_segmentsElementPredecessors;
  ::ad::map::lane::LaneIdList route_aRoad_segmentsElementDrivable_lane_segmentsElementSuccessors;
  ::ad::map::lane::LaneId route_aRoad_segmentsElementDrivable_lane_segmentsElementSuccessorsElement(
    std::numeric_limits<::ad::map::lane::LaneId>::max());
  route_aRoad_segmentsElementDrivable_lane_segmentsElementSuccessors.resize(
    2, route_aRoad_segmentsElementDrivable_lane_segmentsElementSuccessorsElement);
  route_aRoad_segmentsElementDrivable_lane_segmentsElement.successors
    = route_aRoad_segmentsElementDrivable_lane_segmentsElementSuccessors;
  ::ad::map::route::LaneInterval route_aRoad_segmentsElementDrivable_lane_segmentsElementLane_interval;
  ::ad::map::lane::LaneId route_aRoad_segmentsElementDrivable_lane_segmentsElementLane_intervalLane_id(
    std::numeric_limits<::ad::map::lane::LaneId>::max());
  route_aRoad_segmentsElementDrivable_lane_segmentsElementLane_interval.lane_id
    = route_aRoad_segmentsElementDrivable_lane_segmentsElementLane_intervalLane_id;
  ::ad::physics::ParametricValue route_aRoad_segmentsElementDrivable_lane_segmentsElementLane_intervalStart(1.);
  route_aRoad_segmentsElementDrivable_lane_segmentsElementLane_interval.start
    = route_aRoad_segmentsElementDrivable_lane_segmentsElementLane_intervalStart;
  ::ad::physics::ParametricValue route_aRoad_segmentsElementDrivable_lane_segmentsElementLane_intervalEnd(1.);
  route_aRoad_segmentsElementDrivable_lane_segmentsElementLane_interval.end
    = route_aRoad_segmentsElementDrivable_lane_segmentsElementLane_intervalEnd;
  bool route_aRoad_segmentsElementDrivable_lane_segmentsElementLane_intervalWrong_way{false};
  route_aRoad_segmentsElementDrivable_lane_segmentsElementLane_interval.wrong_way
    = route_aRoad_segmentsElementDrivable_lane_segmentsElementLane_intervalWrong_way;
  route_aRoad_segmentsElementDrivable_lane_segmentsElement.lane_interval
    = route_aRoad_segmentsElementDrivable_lane_segmentsElementLane_interval;
  ::ad::map::route::RouteLaneOffset route_aRoad_segmentsElementDrivable_lane_segmentsElementRoute_lane_offset(
    std::numeric_limits<::ad::map::route::RouteLaneOffset>::max());
  route_aRoad_segmentsElementDrivable_lane_segmentsElement.route_lane_offset
    = route_aRoad_segmentsElementDrivable_lane_segmentsElementRoute_lane_offset;
  route_aRoad_segmentsElementDrivable_lane_segments.resize(2, route_aRoad_segmentsElementDrivable_lane_segmentsElement);
  route_aRoad_segmentsElement.drivable_lane_segments = route_aRoad_segmentsElementDrivable_lane_segments;
  ::ad::map::route::SegmentCounter route_aRoad_segmentsElementSegment_count_from_destination(
    std::numeric_limits<::ad::map::route::SegmentCounter>::max());
  route_aRoad_segmentsElement.segment_count_from_destination
    = route_aRoad_segmentsElementSegment_count_from_destination;
  ::ad::map::point::BoundingSphere route_aRoad_segmentsElementBounding_sphere;
  ::ad::map::point::ECEFPoint route_aRoad_segmentsElementBounding_sphereCenter;
  ::ad::map::point::ECEFCoordinate route_aRoad_segmentsElementBounding_sphereCenterX(6400000);
  route_aRoad_segmentsElementBounding_sphereCenter.x = route_aRoad_segmentsElementBounding_sphereCenterX;
  ::ad::map::point::ECEFCoordinate route_aRoad_segmentsElementBounding_sphereCenterY(6400000);
  route_aRoad_segmentsElementBounding_sphereCenter.y = route_aRoad_segmentsElementBounding_sphereCenterY;
  ::ad::map::point::ECEFCoordinate route_aRoad_segmentsElementBounding_sphereCenterZ(6400000);
  route_aRoad_segmentsElementBounding_sphereCenter.z = route_aRoad_segmentsElementBounding_sphereCenterZ;
  route_aRoad_segmentsElementBounding_sphere.center = route_aRoad_segmentsElementBounding_sphereCenter;
  ::ad::physics::Distance route_aRoad_segmentsElementBounding_sphereRadius(1e9);
  route_aRoad_segmentsElementBounding_sphere.radius = route_aRoad_segmentsElementBounding_sphereRadius;
  route_aRoad_segmentsElement.bounding_sphere = route_aRoad_segmentsElementBounding_sphere;
  route_aRoad_segments.resize(2, route_aRoad_segmentsElement);
  route_a.road_segments = route_aRoad_segments;
  ::ad::map::route::RoutePlanningCounter route_aRoute_planning_counter(
    std::numeric_limits<::ad::map::route::RoutePlanningCounter>::max());
  route_a.route_planning_counter = route_aRoute_planning_counter;
  ::ad::map::route::SegmentCounter route_aFull_route_segment_count(
    std::numeric_limits<::ad::map::route::SegmentCounter>::max());
  route_a.full_route_segment_count = route_aFull_route_segment_count;
  ::ad::map::route::RouteLaneOffset route_aDestination_lane_offset(
    std::numeric_limits<::ad::map::route::RouteLaneOffset>::max());
  route_a.destination_lane_offset = route_aDestination_lane_offset;
  ::ad::map::route::RouteLaneOffset route_aMin_lane_offset(
    std::numeric_limits<::ad::map::route::RouteLaneOffset>::max());
  route_a.min_lane_offset = route_aMin_lane_offset;
  ::ad::map::route::RouteLaneOffset route_aMax_lane_offset(
    std::numeric_limits<::ad::map::route::RouteLaneOffset>::max());
  route_a.max_lane_offset = route_aMax_lane_offset;
  ::ad::map::route::RouteCreationMode route_aRoute_creation_mode(::ad::map::route::RouteCreationMode::AllNeighborLanes);
  route_a.route_creation_mode = route_aRoute_creation_mode;
  valueA.route_a = route_a;
  ::ad::map::route::ConnectingRoute valueB = mValue;

  EXPECT_FALSE(valueA == valueB);
  EXPECT_TRUE(valueA != valueB);
}

TEST_F(ConnectingRouteTests, comparisonOperatorRoute_bDiffers)
{
  ::ad::map::route::ConnectingRoute valueA = mValue;
  ::ad::map::route::FullRoute route_b;
  ::ad::map::route::RoadSegmentList route_bRoad_segments;
  ::ad::map::route::RoadSegment route_bRoad_segmentsElement;
  ::ad::map::route::LaneSegmentList route_bRoad_segmentsElementDrivable_lane_segments;
  ::ad::map::route::LaneSegment route_bRoad_segmentsElementDrivable_lane_segmentsElement;
  ::ad::map::lane::LaneId route_bRoad_segmentsElementDrivable_lane_segmentsElementLeft_neighbor(
    std::numeric_limits<::ad::map::lane::LaneId>::max());
  route_bRoad_segmentsElementDrivable_lane_segmentsElement.left_neighbor
    = route_bRoad_segmentsElementDrivable_lane_segmentsElementLeft_neighbor;
  ::ad::map::lane::LaneId route_bRoad_segmentsElementDrivable_lane_segmentsElementRight_neighbor(
    std::numeric_limits<::ad::map::lane::LaneId>::max());
  route_bRoad_segmentsElementDrivable_lane_segmentsElement.right_neighbor
    = route_bRoad_segmentsElementDrivable_lane_segmentsElementRight_neighbor;
  ::ad::map::lane::LaneIdList route_bRoad_segmentsElementDrivable_lane_segmentsElementPredecessors;
  ::ad::map::lane::LaneId route_bRoad_segmentsElementDrivable_lane_segmentsElementPredecessorsElement(
    std::numeric_limits<::ad::map::lane::LaneId>::max());
  route_bRoad_segmentsElementDrivable_lane_segmentsElementPredecessors.resize(
    2, route_bRoad_segmentsElementDrivable_lane_segmentsElementPredecessorsElement);
  route_bRoad_segmentsElementDrivable_lane_segmentsElement.predecessors
    = route_bRoad_segmentsElementDrivable_lane_segmentsElementPredecessors;
  ::ad::map::lane::LaneIdList route_bRoad_segmentsElementDrivable_lane_segmentsElementSuccessors;
  ::ad::map::lane::LaneId route_bRoad_segmentsElementDrivable_lane_segmentsElementSuccessorsElement(
    std::numeric_limits<::ad::map::lane::LaneId>::max());
  route_bRoad_segmentsElementDrivable_lane_segmentsElementSuccessors.resize(
    2, route_bRoad_segmentsElementDrivable_lane_segmentsElementSuccessorsElement);
  route_bRoad_segmentsElementDrivable_lane_segmentsElement.successors
    = route_bRoad_segmentsElementDrivable_lane_segmentsElementSuccessors;
  ::ad::map::route::LaneInterval route_bRoad_segmentsElementDrivable_lane_segmentsElementLane_interval;
  ::ad::map::lane::LaneId route_bRoad_segmentsElementDrivable_lane_segmentsElementLane_intervalLane_id(
    std::numeric_limits<::ad::map::lane::LaneId>::max());
  route_bRoad_segmentsElementDrivable_lane_segmentsElementLane_interval.lane_id
    = route_bRoad_segmentsElementDrivable_lane_segmentsElementLane_intervalLane_id;
  ::ad::physics::ParametricValue route_bRoad_segmentsElementDrivable_lane_segmentsElementLane_intervalStart(1.);
  route_bRoad_segmentsElementDrivable_lane_segmentsElementLane_interval.start
    = route_bRoad_segmentsElementDrivable_lane_segmentsElementLane_intervalStart;
  ::ad::physics::ParametricValue route_bRoad_segmentsElementDrivable_lane_segmentsElementLane_intervalEnd(1.);
  route_bRoad_segmentsElementDrivable_lane_segmentsElementLane_interval.end
    = route_bRoad_segmentsElementDrivable_lane_segmentsElementLane_intervalEnd;
  bool route_bRoad_segmentsElementDrivable_lane_segmentsElementLane_intervalWrong_way{false};
  route_bRoad_segmentsElementDrivable_lane_segmentsElementLane_interval.wrong_way
    = route_bRoad_segmentsElementDrivable_lane_segmentsElementLane_intervalWrong_way;
  route_bRoad_segmentsElementDrivable_lane_segmentsElement.lane_interval
    = route_bRoad_segmentsElementDrivable_lane_segmentsElementLane_interval;
  ::ad::map::route::RouteLaneOffset route_bRoad_segmentsElementDrivable_lane_segmentsElementRoute_lane_offset(
    std::numeric_limits<::ad::map::route::RouteLaneOffset>::max());
  route_bRoad_segmentsElementDrivable_lane_segmentsElement.route_lane_offset
    = route_bRoad_segmentsElementDrivable_lane_segmentsElementRoute_lane_offset;
  route_bRoad_segmentsElementDrivable_lane_segments.resize(2, route_bRoad_segmentsElementDrivable_lane_segmentsElement);
  route_bRoad_segmentsElement.drivable_lane_segments = route_bRoad_segmentsElementDrivable_lane_segments;
  ::ad::map::route::SegmentCounter route_bRoad_segmentsElementSegment_count_from_destination(
    std::numeric_limits<::ad::map::route::SegmentCounter>::max());
  route_bRoad_segmentsElement.segment_count_from_destination
    = route_bRoad_segmentsElementSegment_count_from_destination;
  ::ad::map::point::BoundingSphere route_bRoad_segmentsElementBounding_sphere;
  ::ad::map::point::ECEFPoint route_bRoad_segmentsElementBounding_sphereCenter;
  ::ad::map::point::ECEFCoordinate route_bRoad_segmentsElementBounding_sphereCenterX(6400000);
  route_bRoad_segmentsElementBounding_sphereCenter.x = route_bRoad_segmentsElementBounding_sphereCenterX;
  ::ad::map::point::ECEFCoordinate route_bRoad_segmentsElementBounding_sphereCenterY(6400000);
  route_bRoad_segmentsElementBounding_sphereCenter.y = route_bRoad_segmentsElementBounding_sphereCenterY;
  ::ad::map::point::ECEFCoordinate route_bRoad_segmentsElementBounding_sphereCenterZ(6400000);
  route_bRoad_segmentsElementBounding_sphereCenter.z = route_bRoad_segmentsElementBounding_sphereCenterZ;
  route_bRoad_segmentsElementBounding_sphere.center = route_bRoad_segmentsElementBounding_sphereCenter;
  ::ad::physics::Distance route_bRoad_segmentsElementBounding_sphereRadius(1e9);
  route_bRoad_segmentsElementBounding_sphere.radius = route_bRoad_segmentsElementBounding_sphereRadius;
  route_bRoad_segmentsElement.bounding_sphere = route_bRoad_segmentsElementBounding_sphere;
  route_bRoad_segments.resize(2, route_bRoad_segmentsElement);
  route_b.road_segments = route_bRoad_segments;
  ::ad::map::route::RoutePlanningCounter route_bRoute_planning_counter(
    std::numeric_limits<::ad::map::route::RoutePlanningCounter>::max());
  route_b.route_planning_counter = route_bRoute_planning_counter;
  ::ad::map::route::SegmentCounter route_bFull_route_segment_count(
    std::numeric_limits<::ad::map::route::SegmentCounter>::max());
  route_b.full_route_segment_count = route_bFull_route_segment_count;
  ::ad::map::route::RouteLaneOffset route_bDestination_lane_offset(
    std::numeric_limits<::ad::map::route::RouteLaneOffset>::max());
  route_b.destination_lane_offset = route_bDestination_lane_offset;
  ::ad::map::route::RouteLaneOffset route_bMin_lane_offset(
    std::numeric_limits<::ad::map::route::RouteLaneOffset>::max());
  route_b.min_lane_offset = route_bMin_lane_offset;
  ::ad::map::route::RouteLaneOffset route_bMax_lane_offset(
    std::numeric_limits<::ad::map::route::RouteLaneOffset>::max());
  route_b.max_lane_offset = route_bMax_lane_offset;
  ::ad::map::route::RouteCreationMode route_bRoute_creation_mode(::ad::map::route::RouteCreationMode::AllNeighborLanes);
  route_b.route_creation_mode = route_bRoute_creation_mode;
  valueA.route_b = route_b;
  ::ad::map::route::ConnectingRoute valueB = mValue;

  EXPECT_FALSE(valueA == valueB);
  EXPECT_TRUE(valueA != valueB);
}

TEST_F(ConnectingRouteTests, comparisonOperatorRoute_a_lengthDiffers)
{
  ::ad::map::route::ConnectingRoute valueA = mValue;
  ::ad::physics::Distance route_a_length(1e9);
  valueA.route_a_length = route_a_length;
  ::ad::map::route::ConnectingRoute valueB = mValue;

  EXPECT_FALSE(valueA == valueB);
  EXPECT_TRUE(valueA != valueB);
}

TEST_F(ConnectingRouteTests, comparisonOperatorRoute_b_lengthDiffers)
{
  ::ad::map::route::ConnectingRoute valueA = mValue;
  ::ad::physics::Distance route_b_length(1e9);
  valueA.route_b_length = route_b_length;
  ::ad::map::route::ConnectingRoute valueB = mValue;

  EXPECT_FALSE(valueA == valueB);
  EXPECT_TRUE(valueA != valueB);
}

TEST_F(ConnectingRouteTests, comparisonOperatorHeading_rating_aDiffers)
{
  ::ad::map::route::ConnectingRoute valueA = mValue;
  ::ad::physics::Probability heading_rating_a(1.);
  valueA.heading_rating_a = heading_rating_a;
  ::ad::map::route::ConnectingRoute valueB = mValue;

  EXPECT_FALSE(valueA == valueB);
  EXPECT_TRUE(valueA != valueB);
}

TEST_F(ConnectingRouteTests, comparisonOperatorHeading_rating_bDiffers)
{
  ::ad::map::route::ConnectingRoute valueA = mValue;
  ::ad::physics::Probability heading_rating_b(1.);
  valueA.heading_rating_b = heading_rating_b;
  ::ad::map::route::ConnectingRoute valueB = mValue;

  EXPECT_FALSE(valueA == valueB);
  EXPECT_TRUE(valueA != valueB);
}

TEST_F(ConnectingRouteTests, comparisonOperatorRoute_a_heading_startDiffers)
{
  ::ad::map::route::ConnectingRoute valueA = mValue;
  ::ad::map::point::ENUHeading route_a_heading_start(3.141592655);
  valueA.route_a_heading_start = route_a_heading_start;
  ::ad::map::route::ConnectingRoute valueB = mValue;

  EXPECT_FALSE(valueA == valueB);
  EXPECT_TRUE(valueA != valueB);
}

TEST_F(ConnectingRouteTests, comparisonOperatorRoute_a_heading_endDiffers)
{
  ::ad::map::route::ConnectingRoute valueA = mValue;
  ::ad::map::point::ENUHeading route_a_heading_end(3.141592655);
  valueA.route_a_heading_end = route_a_heading_end;
  ::ad::map::route::ConnectingRoute valueB = mValue;

  EXPECT_FALSE(valueA == valueB);
  EXPECT_TRUE(valueA != valueB);
}

TEST_F(ConnectingRouteTests, comparisonOperatorRoute_b_heading_startDiffers)
{
  ::ad::map::route::ConnectingRoute valueA = mValue;
  ::ad::map::point::ENUHeading route_b_heading_start(3.141592655);
  valueA.route_b_heading_start = route_b_heading_start;
  ::ad::map::route::ConnectingRoute valueB = mValue;

  EXPECT_FALSE(valueA == valueB);
  EXPECT_TRUE(valueA != valueB);
}

TEST_F(ConnectingRouteTests, comparisonOperatorRoute_b_heading_endDiffers)
{
  ::ad::map::route::ConnectingRoute valueA = mValue;
  ::ad::map::point::ENUHeading route_b_heading_end(3.141592655);
  valueA.route_b_heading_end = route_b_heading_end;
  ::ad::map::route::ConnectingRoute valueB = mValue;

  EXPECT_FALSE(valueA == valueB);
  EXPECT_TRUE(valueA != valueB);
}

#if defined(__clang__) && (__clang_major__ >= 7)
#pragma GCC diagnostic pop
#endif
