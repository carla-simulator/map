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

#include "ad/map/route/ConnectingRouteValidInputRange.hpp"

TEST(ConnectingRouteValidInputRangeTests, testValidInputRange)
{
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
  ASSERT_TRUE(withinValidInputRange(value));
}

TEST(ConnectingRouteValidInputRangeTests, testValidInputRangeTypeTooSmall)
{
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

  // override member with data type value below input range minimum
  ::ad::map::route::ConnectingRouteType invalidInitializedMember(
    static_cast<::ad::map::route::ConnectingRouteType>(-1));
  value.type = invalidInitializedMember;
  ASSERT_FALSE(withinValidInputRange(value));
}

TEST(ConnectingRouteValidInputRangeTests, testValidInputRangeTypeTooBig)
{
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

  // override member with data type value above input range maximum
  ::ad::map::route::ConnectingRouteType invalidInitializedMember(
    static_cast<::ad::map::route::ConnectingRouteType>(-1));
  value.type = invalidInitializedMember;
  ASSERT_FALSE(withinValidInputRange(value));
}

TEST(ConnectingRouteValidInputRangeTests, testValidInputRangeRoute_aTooSmall)
{
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

  // override member with data type value below input range minimum
  ::ad::map::route::FullRoute invalidInitializedMember;
  ::ad::map::route::RouteCreationMode invalidInitializedMemberRoute_creation_mode(
    static_cast<::ad::map::route::RouteCreationMode>(-1));
  invalidInitializedMember.route_creation_mode = invalidInitializedMemberRoute_creation_mode;
  value.route_a = invalidInitializedMember;
  ASSERT_FALSE(withinValidInputRange(value));
}

TEST(ConnectingRouteValidInputRangeTests, testValidInputRangeRoute_aTooBig)
{
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

  // override member with data type value above input range maximum
  ::ad::map::route::FullRoute invalidInitializedMember;
  ::ad::map::route::RouteCreationMode invalidInitializedMemberRoute_creation_mode(
    static_cast<::ad::map::route::RouteCreationMode>(-1));
  invalidInitializedMember.route_creation_mode = invalidInitializedMemberRoute_creation_mode;
  value.route_a = invalidInitializedMember;
  ASSERT_FALSE(withinValidInputRange(value));
}

TEST(ConnectingRouteValidInputRangeTests, testValidInputRangeRoute_bTooSmall)
{
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

  // override member with data type value below input range minimum
  ::ad::map::route::FullRoute invalidInitializedMember;
  ::ad::map::route::RouteCreationMode invalidInitializedMemberRoute_creation_mode(
    static_cast<::ad::map::route::RouteCreationMode>(-1));
  invalidInitializedMember.route_creation_mode = invalidInitializedMemberRoute_creation_mode;
  value.route_b = invalidInitializedMember;
  ASSERT_FALSE(withinValidInputRange(value));
}

TEST(ConnectingRouteValidInputRangeTests, testValidInputRangeRoute_bTooBig)
{
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

  // override member with data type value above input range maximum
  ::ad::map::route::FullRoute invalidInitializedMember;
  ::ad::map::route::RouteCreationMode invalidInitializedMemberRoute_creation_mode(
    static_cast<::ad::map::route::RouteCreationMode>(-1));
  invalidInitializedMember.route_creation_mode = invalidInitializedMemberRoute_creation_mode;
  value.route_b = invalidInitializedMember;
  ASSERT_FALSE(withinValidInputRange(value));
}

TEST(ConnectingRouteValidInputRangeTests, testValidInputRangeRoute_a_lengthTooSmall)
{
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

  // override member with data type value below input range minimum
  ::ad::physics::Distance invalidInitializedMember(-1e9 * 1.1);
  value.route_a_length = invalidInitializedMember;
  ASSERT_FALSE(withinValidInputRange(value));
}

TEST(ConnectingRouteValidInputRangeTests, testValidInputRangeRoute_a_lengthTooBig)
{
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

  // override member with data type value above input range maximum
  ::ad::physics::Distance invalidInitializedMember(1e9 * 1.1);
  value.route_a_length = invalidInitializedMember;
  ASSERT_FALSE(withinValidInputRange(value));
}

TEST(ConnectingRouteValidInputRangeTests, testValidInputRangeroute_a_lengthDefault)
{
  ::ad::map::route::ConnectingRoute value;
  ::ad::physics::Distance valueDefault;
  value.route_a_length = valueDefault;
  ASSERT_FALSE(withinValidInputRange(value));
}

TEST(ConnectingRouteValidInputRangeTests, testValidInputRangeRoute_b_lengthTooSmall)
{
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

  // override member with data type value below input range minimum
  ::ad::physics::Distance invalidInitializedMember(-1e9 * 1.1);
  value.route_b_length = invalidInitializedMember;
  ASSERT_FALSE(withinValidInputRange(value));
}

TEST(ConnectingRouteValidInputRangeTests, testValidInputRangeRoute_b_lengthTooBig)
{
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

  // override member with data type value above input range maximum
  ::ad::physics::Distance invalidInitializedMember(1e9 * 1.1);
  value.route_b_length = invalidInitializedMember;
  ASSERT_FALSE(withinValidInputRange(value));
}

TEST(ConnectingRouteValidInputRangeTests, testValidInputRangeroute_b_lengthDefault)
{
  ::ad::map::route::ConnectingRoute value;
  ::ad::physics::Distance valueDefault;
  value.route_b_length = valueDefault;
  ASSERT_FALSE(withinValidInputRange(value));
}

TEST(ConnectingRouteValidInputRangeTests, testValidInputRangeHeading_rating_aTooSmall)
{
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

  // override member with data type value below input range minimum
  ::ad::physics::Probability invalidInitializedMember(0. - ::ad::physics::Probability::cPrecisionValue);
  value.heading_rating_a = invalidInitializedMember;
  ASSERT_FALSE(withinValidInputRange(value));
}

TEST(ConnectingRouteValidInputRangeTests, testValidInputRangeHeading_rating_aTooBig)
{
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

  // override member with data type value above input range maximum
  ::ad::physics::Probability invalidInitializedMember(1. * 1.1);
  value.heading_rating_a = invalidInitializedMember;
  ASSERT_FALSE(withinValidInputRange(value));
}

TEST(ConnectingRouteValidInputRangeTests, testValidInputRangeheading_rating_aDefault)
{
  ::ad::map::route::ConnectingRoute value;
  ::ad::physics::Probability valueDefault;
  value.heading_rating_a = valueDefault;
  ASSERT_FALSE(withinValidInputRange(value));
}

TEST(ConnectingRouteValidInputRangeTests, testValidInputRangeHeading_rating_bTooSmall)
{
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

  // override member with data type value below input range minimum
  ::ad::physics::Probability invalidInitializedMember(0. - ::ad::physics::Probability::cPrecisionValue);
  value.heading_rating_b = invalidInitializedMember;
  ASSERT_FALSE(withinValidInputRange(value));
}

TEST(ConnectingRouteValidInputRangeTests, testValidInputRangeHeading_rating_bTooBig)
{
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

  // override member with data type value above input range maximum
  ::ad::physics::Probability invalidInitializedMember(1. * 1.1);
  value.heading_rating_b = invalidInitializedMember;
  ASSERT_FALSE(withinValidInputRange(value));
}

TEST(ConnectingRouteValidInputRangeTests, testValidInputRangeheading_rating_bDefault)
{
  ::ad::map::route::ConnectingRoute value;
  ::ad::physics::Probability valueDefault;
  value.heading_rating_b = valueDefault;
  ASSERT_FALSE(withinValidInputRange(value));
}

TEST(ConnectingRouteValidInputRangeTests, testValidInputRangeRoute_a_heading_startTooSmall)
{
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

  // override member with data type value below input range minimum
  ::ad::map::point::ENUHeading invalidInitializedMember(-3.141592655 * 1.1);
  value.route_a_heading_start = invalidInitializedMember;
  ASSERT_FALSE(withinValidInputRange(value));
}

TEST(ConnectingRouteValidInputRangeTests, testValidInputRangeRoute_a_heading_startTooBig)
{
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

  // override member with data type value above input range maximum
  ::ad::map::point::ENUHeading invalidInitializedMember(3.141592655 * 1.1);
  value.route_a_heading_start = invalidInitializedMember;
  ASSERT_FALSE(withinValidInputRange(value));
}

TEST(ConnectingRouteValidInputRangeTests, testValidInputRangeroute_a_heading_startDefault)
{
  ::ad::map::route::ConnectingRoute value;
  ::ad::map::point::ENUHeading valueDefault;
  value.route_a_heading_start = valueDefault;
  ASSERT_FALSE(withinValidInputRange(value));
}

TEST(ConnectingRouteValidInputRangeTests, testValidInputRangeRoute_a_heading_endTooSmall)
{
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

  // override member with data type value below input range minimum
  ::ad::map::point::ENUHeading invalidInitializedMember(-3.141592655 * 1.1);
  value.route_a_heading_end = invalidInitializedMember;
  ASSERT_FALSE(withinValidInputRange(value));
}

TEST(ConnectingRouteValidInputRangeTests, testValidInputRangeRoute_a_heading_endTooBig)
{
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

  // override member with data type value above input range maximum
  ::ad::map::point::ENUHeading invalidInitializedMember(3.141592655 * 1.1);
  value.route_a_heading_end = invalidInitializedMember;
  ASSERT_FALSE(withinValidInputRange(value));
}

TEST(ConnectingRouteValidInputRangeTests, testValidInputRangeroute_a_heading_endDefault)
{
  ::ad::map::route::ConnectingRoute value;
  ::ad::map::point::ENUHeading valueDefault;
  value.route_a_heading_end = valueDefault;
  ASSERT_FALSE(withinValidInputRange(value));
}

TEST(ConnectingRouteValidInputRangeTests, testValidInputRangeRoute_b_heading_startTooSmall)
{
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

  // override member with data type value below input range minimum
  ::ad::map::point::ENUHeading invalidInitializedMember(-3.141592655 * 1.1);
  value.route_b_heading_start = invalidInitializedMember;
  ASSERT_FALSE(withinValidInputRange(value));
}

TEST(ConnectingRouteValidInputRangeTests, testValidInputRangeRoute_b_heading_startTooBig)
{
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

  // override member with data type value above input range maximum
  ::ad::map::point::ENUHeading invalidInitializedMember(3.141592655 * 1.1);
  value.route_b_heading_start = invalidInitializedMember;
  ASSERT_FALSE(withinValidInputRange(value));
}

TEST(ConnectingRouteValidInputRangeTests, testValidInputRangeroute_b_heading_startDefault)
{
  ::ad::map::route::ConnectingRoute value;
  ::ad::map::point::ENUHeading valueDefault;
  value.route_b_heading_start = valueDefault;
  ASSERT_FALSE(withinValidInputRange(value));
}

TEST(ConnectingRouteValidInputRangeTests, testValidInputRangeRoute_b_heading_endTooSmall)
{
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

  // override member with data type value below input range minimum
  ::ad::map::point::ENUHeading invalidInitializedMember(-3.141592655 * 1.1);
  value.route_b_heading_end = invalidInitializedMember;
  ASSERT_FALSE(withinValidInputRange(value));
}

TEST(ConnectingRouteValidInputRangeTests, testValidInputRangeRoute_b_heading_endTooBig)
{
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

  // override member with data type value above input range maximum
  ::ad::map::point::ENUHeading invalidInitializedMember(3.141592655 * 1.1);
  value.route_b_heading_end = invalidInitializedMember;
  ASSERT_FALSE(withinValidInputRange(value));
}

TEST(ConnectingRouteValidInputRangeTests, testValidInputRangeroute_b_heading_endDefault)
{
  ::ad::map::route::ConnectingRoute value;
  ::ad::map::point::ENUHeading valueDefault;
  value.route_b_heading_end = valueDefault;
  ASSERT_FALSE(withinValidInputRange(value));
}
