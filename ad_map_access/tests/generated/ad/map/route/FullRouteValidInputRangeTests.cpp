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

#include <gtest/gtest.h>

#include <limits>

#include "ad/map/route/FullRouteValidInputRange.hpp"

TEST(FullRouteValidInputRangeTests, testValidInputRange)
{
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
  ASSERT_TRUE(withinValidInputRange(value));
}

TEST(FullRouteValidInputRangeTests, testValidInputRangeRoute_creation_modeTooSmall)
{
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

  // override member with data type value below input range minimum
  ::ad::map::route::RouteCreationMode invalidInitializedMember(static_cast<::ad::map::route::RouteCreationMode>(-1));
  value.route_creation_mode = invalidInitializedMember;
  ASSERT_FALSE(withinValidInputRange(value));
}

TEST(FullRouteValidInputRangeTests, testValidInputRangeRoute_creation_modeTooBig)
{
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

  // override member with data type value above input range maximum
  ::ad::map::route::RouteCreationMode invalidInitializedMember(static_cast<::ad::map::route::RouteCreationMode>(-1));
  value.route_creation_mode = invalidInitializedMember;
  ASSERT_FALSE(withinValidInputRange(value));
}
