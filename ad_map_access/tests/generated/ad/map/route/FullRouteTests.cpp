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
#include "ad/map/route/FullRoute.hpp"

class FullRouteTests : public testing::Test
{
protected:
  virtual void SetUp() override
  {
    // valid initialization
    ::ad::map::route::FullRoute value;
    ::ad::map::route::RoadSegmentList valueRoad_segments;
    ::ad::map::route::RoadSegment valueRoad_segmentsElement;
    ::ad::map::route::LaneSegmentList valueRoad_segmentsElementDrivable_lane_segments;
    ::ad::map::route::LaneSegment valueRoad_segmentsElementDrivable_lane_segmentsElement;
    ::ad::map::lane::LaneId valueRoad_segmentsElementDrivable_lane_segmentsElementLeft_neighbor(1);
    valueRoad_segmentsElementDrivable_lane_segmentsElement.left_neighbor
      = valueRoad_segmentsElementDrivable_lane_segmentsElementLeft_neighbor;
    ::ad::map::lane::LaneId valueRoad_segmentsElementDrivable_lane_segmentsElementRight_neighbor(1);
    valueRoad_segmentsElementDrivable_lane_segmentsElement.right_neighbor
      = valueRoad_segmentsElementDrivable_lane_segmentsElementRight_neighbor;
    ::ad::map::lane::LaneIdList valueRoad_segmentsElementDrivable_lane_segmentsElementPredecessors;
    ::ad::map::lane::LaneId valueRoad_segmentsElementDrivable_lane_segmentsElementPredecessorsElement(1);
    valueRoad_segmentsElementDrivable_lane_segmentsElementPredecessors.resize(
      1, valueRoad_segmentsElementDrivable_lane_segmentsElementPredecessorsElement);
    valueRoad_segmentsElementDrivable_lane_segmentsElement.predecessors
      = valueRoad_segmentsElementDrivable_lane_segmentsElementPredecessors;
    ::ad::map::lane::LaneIdList valueRoad_segmentsElementDrivable_lane_segmentsElementSuccessors;
    ::ad::map::lane::LaneId valueRoad_segmentsElementDrivable_lane_segmentsElementSuccessorsElement(1);
    valueRoad_segmentsElementDrivable_lane_segmentsElementSuccessors.resize(
      1, valueRoad_segmentsElementDrivable_lane_segmentsElementSuccessorsElement);
    valueRoad_segmentsElementDrivable_lane_segmentsElement.successors
      = valueRoad_segmentsElementDrivable_lane_segmentsElementSuccessors;
    ::ad::map::route::LaneInterval valueRoad_segmentsElementDrivable_lane_segmentsElementLane_interval;
    ::ad::map::lane::LaneId valueRoad_segmentsElementDrivable_lane_segmentsElementLane_intervalLane_id(1);
    valueRoad_segmentsElementDrivable_lane_segmentsElementLane_interval.lane_id
      = valueRoad_segmentsElementDrivable_lane_segmentsElementLane_intervalLane_id;
    ::ad::physics::ParametricValue valueRoad_segmentsElementDrivable_lane_segmentsElementLane_intervalStart(0.);
    valueRoad_segmentsElementDrivable_lane_segmentsElementLane_interval.start
      = valueRoad_segmentsElementDrivable_lane_segmentsElementLane_intervalStart;
    ::ad::physics::ParametricValue valueRoad_segmentsElementDrivable_lane_segmentsElementLane_intervalEnd(0.);
    valueRoad_segmentsElementDrivable_lane_segmentsElementLane_interval.end
      = valueRoad_segmentsElementDrivable_lane_segmentsElementLane_intervalEnd;
    bool valueRoad_segmentsElementDrivable_lane_segmentsElementLane_intervalWrong_way{true};
    valueRoad_segmentsElementDrivable_lane_segmentsElementLane_interval.wrong_way
      = valueRoad_segmentsElementDrivable_lane_segmentsElementLane_intervalWrong_way;
    valueRoad_segmentsElementDrivable_lane_segmentsElement.lane_interval
      = valueRoad_segmentsElementDrivable_lane_segmentsElementLane_interval;
    ::ad::map::route::RouteLaneOffset valueRoad_segmentsElementDrivable_lane_segmentsElementRoute_lane_offset(
      std::numeric_limits<::ad::map::route::RouteLaneOffset>::lowest());
    valueRoad_segmentsElementDrivable_lane_segmentsElement.route_lane_offset
      = valueRoad_segmentsElementDrivable_lane_segmentsElementRoute_lane_offset;
    valueRoad_segmentsElementDrivable_lane_segments.resize(1, valueRoad_segmentsElementDrivable_lane_segmentsElement);
    valueRoad_segmentsElement.drivable_lane_segments = valueRoad_segmentsElementDrivable_lane_segments;
    ::ad::map::route::SegmentCounter valueRoad_segmentsElementSegment_count_from_destination(
      std::numeric_limits<::ad::map::route::SegmentCounter>::lowest());
    valueRoad_segmentsElement.segment_count_from_destination = valueRoad_segmentsElementSegment_count_from_destination;
    ::ad::map::point::BoundingSphere valueRoad_segmentsElementBounding_sphere;
    ::ad::map::point::ECEFPoint valueRoad_segmentsElementBounding_sphereCenter;
    ::ad::map::point::ECEFCoordinate valueRoad_segmentsElementBounding_sphereCenterX(-6400000);
    valueRoad_segmentsElementBounding_sphereCenter.x = valueRoad_segmentsElementBounding_sphereCenterX;
    ::ad::map::point::ECEFCoordinate valueRoad_segmentsElementBounding_sphereCenterY(-6400000);
    valueRoad_segmentsElementBounding_sphereCenter.y = valueRoad_segmentsElementBounding_sphereCenterY;
    ::ad::map::point::ECEFCoordinate valueRoad_segmentsElementBounding_sphereCenterZ(-6400000);
    valueRoad_segmentsElementBounding_sphereCenter.z = valueRoad_segmentsElementBounding_sphereCenterZ;
    valueRoad_segmentsElementBounding_sphere.center = valueRoad_segmentsElementBounding_sphereCenter;
    ::ad::physics::Distance valueRoad_segmentsElementBounding_sphereRadius(-1e9);
    valueRoad_segmentsElementBounding_sphere.radius = valueRoad_segmentsElementBounding_sphereRadius;
    valueRoad_segmentsElement.bounding_sphere = valueRoad_segmentsElementBounding_sphere;
    valueRoad_segments.resize(1, valueRoad_segmentsElement);
    value.road_segments = valueRoad_segments;
    ::ad::map::route::RoutePlanningCounter valueRoute_planning_counter(
      std::numeric_limits<::ad::map::route::RoutePlanningCounter>::lowest());
    value.route_planning_counter = valueRoute_planning_counter;
    ::ad::map::route::SegmentCounter valueFull_route_segment_count(
      std::numeric_limits<::ad::map::route::SegmentCounter>::lowest());
    value.full_route_segment_count = valueFull_route_segment_count;
    ::ad::map::route::RouteLaneOffset valueDestination_lane_offset(
      std::numeric_limits<::ad::map::route::RouteLaneOffset>::lowest());
    value.destination_lane_offset = valueDestination_lane_offset;
    ::ad::map::route::RouteLaneOffset valueMin_lane_offset(
      std::numeric_limits<::ad::map::route::RouteLaneOffset>::lowest());
    value.min_lane_offset = valueMin_lane_offset;
    ::ad::map::route::RouteLaneOffset valueMax_lane_offset(
      std::numeric_limits<::ad::map::route::RouteLaneOffset>::lowest());
    value.max_lane_offset = valueMax_lane_offset;
    ::ad::map::route::RouteCreationMode valueRoute_creation_mode(::ad::map::route::RouteCreationMode::Undefined);
    value.route_creation_mode = valueRoute_creation_mode;
    mValue = value;
  }

  ::ad::map::route::FullRoute mValue;
};

TEST_F(FullRouteTests, copyConstruction)
{
  ::ad::map::route::FullRoute value(mValue);
  EXPECT_EQ(mValue, value);
}

TEST_F(FullRouteTests, moveConstruction)
{
  ::ad::map::route::FullRoute tmpValue(mValue);
  ::ad::map::route::FullRoute value(std::move(tmpValue));
  EXPECT_EQ(mValue, value);
}

TEST_F(FullRouteTests, copyAssignment)
{
  ::ad::map::route::FullRoute value;
  value = mValue;
  EXPECT_EQ(mValue, value);
}

TEST_F(FullRouteTests, moveAssignment)
{
  ::ad::map::route::FullRoute tmpValue(mValue);
  ::ad::map::route::FullRoute value;
  value = std::move(tmpValue);
  EXPECT_EQ(mValue, value);
}

TEST_F(FullRouteTests, comparisonOperatorEqual)
{
  ::ad::map::route::FullRoute valueA = mValue;
  ::ad::map::route::FullRoute valueB = mValue;

  EXPECT_TRUE(valueA == valueB);
  EXPECT_FALSE(valueA != valueB);
}

TEST_F(FullRouteTests, stringConversionTest)
{
  std::stringstream stream;
  stream << mValue;
  std::string ostreamStr = stream.str();
  std::string toStr = std::to_string(mValue);
  ASSERT_EQ(ostreamStr, toStr);
}

TEST_F(FullRouteTests, comparisonOperatorRoad_segmentsDiffers)
{
  ::ad::map::route::FullRoute valueA = mValue;
  ::ad::map::route::RoadSegmentList road_segments;
  ::ad::map::route::RoadSegment road_segmentsElement;
  ::ad::map::route::LaneSegmentList road_segmentsElementDrivable_lane_segments;
  ::ad::map::route::LaneSegment road_segmentsElementDrivable_lane_segmentsElement;
  ::ad::map::lane::LaneId road_segmentsElementDrivable_lane_segmentsElementLeft_neighbor(
    std::numeric_limits<::ad::map::lane::LaneId>::max());
  road_segmentsElementDrivable_lane_segmentsElement.left_neighbor
    = road_segmentsElementDrivable_lane_segmentsElementLeft_neighbor;
  ::ad::map::lane::LaneId road_segmentsElementDrivable_lane_segmentsElementRight_neighbor(
    std::numeric_limits<::ad::map::lane::LaneId>::max());
  road_segmentsElementDrivable_lane_segmentsElement.right_neighbor
    = road_segmentsElementDrivable_lane_segmentsElementRight_neighbor;
  ::ad::map::lane::LaneIdList road_segmentsElementDrivable_lane_segmentsElementPredecessors;
  ::ad::map::lane::LaneId road_segmentsElementDrivable_lane_segmentsElementPredecessorsElement(
    std::numeric_limits<::ad::map::lane::LaneId>::max());
  road_segmentsElementDrivable_lane_segmentsElementPredecessors.resize(
    2, road_segmentsElementDrivable_lane_segmentsElementPredecessorsElement);
  road_segmentsElementDrivable_lane_segmentsElement.predecessors
    = road_segmentsElementDrivable_lane_segmentsElementPredecessors;
  ::ad::map::lane::LaneIdList road_segmentsElementDrivable_lane_segmentsElementSuccessors;
  ::ad::map::lane::LaneId road_segmentsElementDrivable_lane_segmentsElementSuccessorsElement(
    std::numeric_limits<::ad::map::lane::LaneId>::max());
  road_segmentsElementDrivable_lane_segmentsElementSuccessors.resize(
    2, road_segmentsElementDrivable_lane_segmentsElementSuccessorsElement);
  road_segmentsElementDrivable_lane_segmentsElement.successors
    = road_segmentsElementDrivable_lane_segmentsElementSuccessors;
  ::ad::map::route::LaneInterval road_segmentsElementDrivable_lane_segmentsElementLane_interval;
  ::ad::map::lane::LaneId road_segmentsElementDrivable_lane_segmentsElementLane_intervalLane_id(
    std::numeric_limits<::ad::map::lane::LaneId>::max());
  road_segmentsElementDrivable_lane_segmentsElementLane_interval.lane_id
    = road_segmentsElementDrivable_lane_segmentsElementLane_intervalLane_id;
  ::ad::physics::ParametricValue road_segmentsElementDrivable_lane_segmentsElementLane_intervalStart(1.);
  road_segmentsElementDrivable_lane_segmentsElementLane_interval.start
    = road_segmentsElementDrivable_lane_segmentsElementLane_intervalStart;
  ::ad::physics::ParametricValue road_segmentsElementDrivable_lane_segmentsElementLane_intervalEnd(1.);
  road_segmentsElementDrivable_lane_segmentsElementLane_interval.end
    = road_segmentsElementDrivable_lane_segmentsElementLane_intervalEnd;
  bool road_segmentsElementDrivable_lane_segmentsElementLane_intervalWrong_way{false};
  road_segmentsElementDrivable_lane_segmentsElementLane_interval.wrong_way
    = road_segmentsElementDrivable_lane_segmentsElementLane_intervalWrong_way;
  road_segmentsElementDrivable_lane_segmentsElement.lane_interval
    = road_segmentsElementDrivable_lane_segmentsElementLane_interval;
  ::ad::map::route::RouteLaneOffset road_segmentsElementDrivable_lane_segmentsElementRoute_lane_offset(
    std::numeric_limits<::ad::map::route::RouteLaneOffset>::max());
  road_segmentsElementDrivable_lane_segmentsElement.route_lane_offset
    = road_segmentsElementDrivable_lane_segmentsElementRoute_lane_offset;
  road_segmentsElementDrivable_lane_segments.resize(2, road_segmentsElementDrivable_lane_segmentsElement);
  road_segmentsElement.drivable_lane_segments = road_segmentsElementDrivable_lane_segments;
  ::ad::map::route::SegmentCounter road_segmentsElementSegment_count_from_destination(
    std::numeric_limits<::ad::map::route::SegmentCounter>::max());
  road_segmentsElement.segment_count_from_destination = road_segmentsElementSegment_count_from_destination;
  ::ad::map::point::BoundingSphere road_segmentsElementBounding_sphere;
  ::ad::map::point::ECEFPoint road_segmentsElementBounding_sphereCenter;
  ::ad::map::point::ECEFCoordinate road_segmentsElementBounding_sphereCenterX(6400000);
  road_segmentsElementBounding_sphereCenter.x = road_segmentsElementBounding_sphereCenterX;
  ::ad::map::point::ECEFCoordinate road_segmentsElementBounding_sphereCenterY(6400000);
  road_segmentsElementBounding_sphereCenter.y = road_segmentsElementBounding_sphereCenterY;
  ::ad::map::point::ECEFCoordinate road_segmentsElementBounding_sphereCenterZ(6400000);
  road_segmentsElementBounding_sphereCenter.z = road_segmentsElementBounding_sphereCenterZ;
  road_segmentsElementBounding_sphere.center = road_segmentsElementBounding_sphereCenter;
  ::ad::physics::Distance road_segmentsElementBounding_sphereRadius(1e9);
  road_segmentsElementBounding_sphere.radius = road_segmentsElementBounding_sphereRadius;
  road_segmentsElement.bounding_sphere = road_segmentsElementBounding_sphere;
  road_segments.resize(2, road_segmentsElement);
  valueA.road_segments = road_segments;
  ::ad::map::route::FullRoute valueB = mValue;

  EXPECT_FALSE(valueA == valueB);
  EXPECT_TRUE(valueA != valueB);
}

TEST_F(FullRouteTests, comparisonOperatorRoute_planning_counterDiffers)
{
  ::ad::map::route::FullRoute valueA = mValue;
  ::ad::map::route::RoutePlanningCounter route_planning_counter(
    std::numeric_limits<::ad::map::route::RoutePlanningCounter>::max());
  valueA.route_planning_counter = route_planning_counter;
  ::ad::map::route::FullRoute valueB = mValue;

  EXPECT_FALSE(valueA == valueB);
  EXPECT_TRUE(valueA != valueB);
}

TEST_F(FullRouteTests, comparisonOperatorFull_route_segment_countDiffers)
{
  ::ad::map::route::FullRoute valueA = mValue;
  ::ad::map::route::SegmentCounter full_route_segment_count(
    std::numeric_limits<::ad::map::route::SegmentCounter>::max());
  valueA.full_route_segment_count = full_route_segment_count;
  ::ad::map::route::FullRoute valueB = mValue;

  EXPECT_FALSE(valueA == valueB);
  EXPECT_TRUE(valueA != valueB);
}

TEST_F(FullRouteTests, comparisonOperatorDestination_lane_offsetDiffers)
{
  ::ad::map::route::FullRoute valueA = mValue;
  ::ad::map::route::RouteLaneOffset destination_lane_offset(
    std::numeric_limits<::ad::map::route::RouteLaneOffset>::max());
  valueA.destination_lane_offset = destination_lane_offset;
  ::ad::map::route::FullRoute valueB = mValue;

  EXPECT_FALSE(valueA == valueB);
  EXPECT_TRUE(valueA != valueB);
}

TEST_F(FullRouteTests, comparisonOperatorMin_lane_offsetDiffers)
{
  ::ad::map::route::FullRoute valueA = mValue;
  ::ad::map::route::RouteLaneOffset min_lane_offset(std::numeric_limits<::ad::map::route::RouteLaneOffset>::max());
  valueA.min_lane_offset = min_lane_offset;
  ::ad::map::route::FullRoute valueB = mValue;

  EXPECT_FALSE(valueA == valueB);
  EXPECT_TRUE(valueA != valueB);
}

TEST_F(FullRouteTests, comparisonOperatorMax_lane_offsetDiffers)
{
  ::ad::map::route::FullRoute valueA = mValue;
  ::ad::map::route::RouteLaneOffset max_lane_offset(std::numeric_limits<::ad::map::route::RouteLaneOffset>::max());
  valueA.max_lane_offset = max_lane_offset;
  ::ad::map::route::FullRoute valueB = mValue;

  EXPECT_FALSE(valueA == valueB);
  EXPECT_TRUE(valueA != valueB);
}

TEST_F(FullRouteTests, comparisonOperatorRoute_creation_modeDiffers)
{
  ::ad::map::route::FullRoute valueA = mValue;
  ::ad::map::route::RouteCreationMode route_creation_mode(::ad::map::route::RouteCreationMode::AllNeighborLanes);
  valueA.route_creation_mode = route_creation_mode;
  ::ad::map::route::FullRoute valueB = mValue;

  EXPECT_FALSE(valueA == valueB);
  EXPECT_TRUE(valueA != valueB);
}

#if defined(__clang__) && (__clang_major__ >= 7)
#pragma GCC diagnostic pop
#endif
