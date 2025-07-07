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

#include "ad/map/route/ConnectingRouteListValidInputRange.hpp"

TEST(ConnectingRouteListValidInputRangeTests, testValidInputRangeValidInputRangeMin)
{
  ::ad::map::route::ConnectingRouteList value;
  ASSERT_TRUE(withinValidInputRange(value));
}

TEST(ConnectingRouteListValidInputRangeTests, testValidInputRangeElementValid)
{
  ::ad::map::route::ConnectingRouteList value;
  ::ad::map::route::ConnectingRoute element;
  ::ad::map::route::ConnectingRouteType elementType(::ad::map::route::ConnectingRouteType::Invalid);
  element.type = elementType;
  ::ad::map::route::FullRoute elementRoute_a;
  ::ad::map::route::RoadSegmentList elementRoute_aRoad_segments;
  ::ad::map::route::RoadSegment elementRoute_aRoad_segmentsElement;
  ::ad::map::route::LaneSegmentList elementRoute_aRoad_segmentsElementDrivable_lane_segments;
  ::ad::map::route::LaneSegment elementRoute_aRoad_segmentsElementDrivable_lane_segmentsElement;
  ::ad::map::lane::LaneId elementRoute_aRoad_segmentsElementDrivable_lane_segmentsElementLeft_neighbor(1);
  elementRoute_aRoad_segmentsElementDrivable_lane_segmentsElement.left_neighbor
    = elementRoute_aRoad_segmentsElementDrivable_lane_segmentsElementLeft_neighbor;
  ::ad::map::lane::LaneId elementRoute_aRoad_segmentsElementDrivable_lane_segmentsElementRight_neighbor(1);
  elementRoute_aRoad_segmentsElementDrivable_lane_segmentsElement.right_neighbor
    = elementRoute_aRoad_segmentsElementDrivable_lane_segmentsElementRight_neighbor;
  ::ad::map::lane::LaneIdList elementRoute_aRoad_segmentsElementDrivable_lane_segmentsElementPredecessors;
  ::ad::map::lane::LaneId elementRoute_aRoad_segmentsElementDrivable_lane_segmentsElementPredecessorsElement(1);
  elementRoute_aRoad_segmentsElementDrivable_lane_segmentsElementPredecessors.resize(
    1, elementRoute_aRoad_segmentsElementDrivable_lane_segmentsElementPredecessorsElement);
  elementRoute_aRoad_segmentsElementDrivable_lane_segmentsElement.predecessors
    = elementRoute_aRoad_segmentsElementDrivable_lane_segmentsElementPredecessors;
  ::ad::map::lane::LaneIdList elementRoute_aRoad_segmentsElementDrivable_lane_segmentsElementSuccessors;
  ::ad::map::lane::LaneId elementRoute_aRoad_segmentsElementDrivable_lane_segmentsElementSuccessorsElement(1);
  elementRoute_aRoad_segmentsElementDrivable_lane_segmentsElementSuccessors.resize(
    1, elementRoute_aRoad_segmentsElementDrivable_lane_segmentsElementSuccessorsElement);
  elementRoute_aRoad_segmentsElementDrivable_lane_segmentsElement.successors
    = elementRoute_aRoad_segmentsElementDrivable_lane_segmentsElementSuccessors;
  ::ad::map::route::LaneInterval elementRoute_aRoad_segmentsElementDrivable_lane_segmentsElementLane_interval;
  ::ad::map::lane::LaneId elementRoute_aRoad_segmentsElementDrivable_lane_segmentsElementLane_intervalLane_id(1);
  elementRoute_aRoad_segmentsElementDrivable_lane_segmentsElementLane_interval.lane_id
    = elementRoute_aRoad_segmentsElementDrivable_lane_segmentsElementLane_intervalLane_id;
  ::ad::physics::ParametricValue elementRoute_aRoad_segmentsElementDrivable_lane_segmentsElementLane_intervalStart(0.);
  elementRoute_aRoad_segmentsElementDrivable_lane_segmentsElementLane_interval.start
    = elementRoute_aRoad_segmentsElementDrivable_lane_segmentsElementLane_intervalStart;
  ::ad::physics::ParametricValue elementRoute_aRoad_segmentsElementDrivable_lane_segmentsElementLane_intervalEnd(0.);
  elementRoute_aRoad_segmentsElementDrivable_lane_segmentsElementLane_interval.end
    = elementRoute_aRoad_segmentsElementDrivable_lane_segmentsElementLane_intervalEnd;
  bool elementRoute_aRoad_segmentsElementDrivable_lane_segmentsElementLane_intervalWrong_way{true};
  elementRoute_aRoad_segmentsElementDrivable_lane_segmentsElementLane_interval.wrong_way
    = elementRoute_aRoad_segmentsElementDrivable_lane_segmentsElementLane_intervalWrong_way;
  elementRoute_aRoad_segmentsElementDrivable_lane_segmentsElement.lane_interval
    = elementRoute_aRoad_segmentsElementDrivable_lane_segmentsElementLane_interval;
  ::ad::map::route::RouteLaneOffset elementRoute_aRoad_segmentsElementDrivable_lane_segmentsElementRoute_lane_offset(
    std::numeric_limits<::ad::map::route::RouteLaneOffset>::lowest());
  elementRoute_aRoad_segmentsElementDrivable_lane_segmentsElement.route_lane_offset
    = elementRoute_aRoad_segmentsElementDrivable_lane_segmentsElementRoute_lane_offset;
  elementRoute_aRoad_segmentsElementDrivable_lane_segments.resize(
    1, elementRoute_aRoad_segmentsElementDrivable_lane_segmentsElement);
  elementRoute_aRoad_segmentsElement.drivable_lane_segments = elementRoute_aRoad_segmentsElementDrivable_lane_segments;
  ::ad::map::route::SegmentCounter elementRoute_aRoad_segmentsElementSegment_count_from_destination(
    std::numeric_limits<::ad::map::route::SegmentCounter>::lowest());
  elementRoute_aRoad_segmentsElement.segment_count_from_destination
    = elementRoute_aRoad_segmentsElementSegment_count_from_destination;
  ::ad::map::point::BoundingSphere elementRoute_aRoad_segmentsElementBounding_sphere;
  ::ad::map::point::ECEFPoint elementRoute_aRoad_segmentsElementBounding_sphereCenter;
  ::ad::map::point::ECEFCoordinate elementRoute_aRoad_segmentsElementBounding_sphereCenterX(-6400000);
  elementRoute_aRoad_segmentsElementBounding_sphereCenter.x = elementRoute_aRoad_segmentsElementBounding_sphereCenterX;
  ::ad::map::point::ECEFCoordinate elementRoute_aRoad_segmentsElementBounding_sphereCenterY(-6400000);
  elementRoute_aRoad_segmentsElementBounding_sphereCenter.y = elementRoute_aRoad_segmentsElementBounding_sphereCenterY;
  ::ad::map::point::ECEFCoordinate elementRoute_aRoad_segmentsElementBounding_sphereCenterZ(-6400000);
  elementRoute_aRoad_segmentsElementBounding_sphereCenter.z = elementRoute_aRoad_segmentsElementBounding_sphereCenterZ;
  elementRoute_aRoad_segmentsElementBounding_sphere.center = elementRoute_aRoad_segmentsElementBounding_sphereCenter;
  ::ad::physics::Distance elementRoute_aRoad_segmentsElementBounding_sphereRadius(-1e9);
  elementRoute_aRoad_segmentsElementBounding_sphere.radius = elementRoute_aRoad_segmentsElementBounding_sphereRadius;
  elementRoute_aRoad_segmentsElement.bounding_sphere = elementRoute_aRoad_segmentsElementBounding_sphere;
  elementRoute_aRoad_segments.resize(1, elementRoute_aRoad_segmentsElement);
  elementRoute_a.road_segments = elementRoute_aRoad_segments;
  ::ad::map::route::RoutePlanningCounter elementRoute_aRoute_planning_counter(
    std::numeric_limits<::ad::map::route::RoutePlanningCounter>::lowest());
  elementRoute_a.route_planning_counter = elementRoute_aRoute_planning_counter;
  ::ad::map::route::SegmentCounter elementRoute_aFull_route_segment_count(
    std::numeric_limits<::ad::map::route::SegmentCounter>::lowest());
  elementRoute_a.full_route_segment_count = elementRoute_aFull_route_segment_count;
  ::ad::map::route::RouteLaneOffset elementRoute_aDestination_lane_offset(
    std::numeric_limits<::ad::map::route::RouteLaneOffset>::lowest());
  elementRoute_a.destination_lane_offset = elementRoute_aDestination_lane_offset;
  ::ad::map::route::RouteLaneOffset elementRoute_aMin_lane_offset(
    std::numeric_limits<::ad::map::route::RouteLaneOffset>::lowest());
  elementRoute_a.min_lane_offset = elementRoute_aMin_lane_offset;
  ::ad::map::route::RouteLaneOffset elementRoute_aMax_lane_offset(
    std::numeric_limits<::ad::map::route::RouteLaneOffset>::lowest());
  elementRoute_a.max_lane_offset = elementRoute_aMax_lane_offset;
  ::ad::map::route::RouteCreationMode elementRoute_aRoute_creation_mode(::ad::map::route::RouteCreationMode::Undefined);
  elementRoute_a.route_creation_mode = elementRoute_aRoute_creation_mode;
  element.route_a = elementRoute_a;
  ::ad::map::route::FullRoute elementRoute_b;
  ::ad::map::route::RoadSegmentList elementRoute_bRoad_segments;
  ::ad::map::route::RoadSegment elementRoute_bRoad_segmentsElement;
  ::ad::map::route::LaneSegmentList elementRoute_bRoad_segmentsElementDrivable_lane_segments;
  ::ad::map::route::LaneSegment elementRoute_bRoad_segmentsElementDrivable_lane_segmentsElement;
  ::ad::map::lane::LaneId elementRoute_bRoad_segmentsElementDrivable_lane_segmentsElementLeft_neighbor(1);
  elementRoute_bRoad_segmentsElementDrivable_lane_segmentsElement.left_neighbor
    = elementRoute_bRoad_segmentsElementDrivable_lane_segmentsElementLeft_neighbor;
  ::ad::map::lane::LaneId elementRoute_bRoad_segmentsElementDrivable_lane_segmentsElementRight_neighbor(1);
  elementRoute_bRoad_segmentsElementDrivable_lane_segmentsElement.right_neighbor
    = elementRoute_bRoad_segmentsElementDrivable_lane_segmentsElementRight_neighbor;
  ::ad::map::lane::LaneIdList elementRoute_bRoad_segmentsElementDrivable_lane_segmentsElementPredecessors;
  ::ad::map::lane::LaneId elementRoute_bRoad_segmentsElementDrivable_lane_segmentsElementPredecessorsElement(1);
  elementRoute_bRoad_segmentsElementDrivable_lane_segmentsElementPredecessors.resize(
    1, elementRoute_bRoad_segmentsElementDrivable_lane_segmentsElementPredecessorsElement);
  elementRoute_bRoad_segmentsElementDrivable_lane_segmentsElement.predecessors
    = elementRoute_bRoad_segmentsElementDrivable_lane_segmentsElementPredecessors;
  ::ad::map::lane::LaneIdList elementRoute_bRoad_segmentsElementDrivable_lane_segmentsElementSuccessors;
  ::ad::map::lane::LaneId elementRoute_bRoad_segmentsElementDrivable_lane_segmentsElementSuccessorsElement(1);
  elementRoute_bRoad_segmentsElementDrivable_lane_segmentsElementSuccessors.resize(
    1, elementRoute_bRoad_segmentsElementDrivable_lane_segmentsElementSuccessorsElement);
  elementRoute_bRoad_segmentsElementDrivable_lane_segmentsElement.successors
    = elementRoute_bRoad_segmentsElementDrivable_lane_segmentsElementSuccessors;
  ::ad::map::route::LaneInterval elementRoute_bRoad_segmentsElementDrivable_lane_segmentsElementLane_interval;
  ::ad::map::lane::LaneId elementRoute_bRoad_segmentsElementDrivable_lane_segmentsElementLane_intervalLane_id(1);
  elementRoute_bRoad_segmentsElementDrivable_lane_segmentsElementLane_interval.lane_id
    = elementRoute_bRoad_segmentsElementDrivable_lane_segmentsElementLane_intervalLane_id;
  ::ad::physics::ParametricValue elementRoute_bRoad_segmentsElementDrivable_lane_segmentsElementLane_intervalStart(0.);
  elementRoute_bRoad_segmentsElementDrivable_lane_segmentsElementLane_interval.start
    = elementRoute_bRoad_segmentsElementDrivable_lane_segmentsElementLane_intervalStart;
  ::ad::physics::ParametricValue elementRoute_bRoad_segmentsElementDrivable_lane_segmentsElementLane_intervalEnd(0.);
  elementRoute_bRoad_segmentsElementDrivable_lane_segmentsElementLane_interval.end
    = elementRoute_bRoad_segmentsElementDrivable_lane_segmentsElementLane_intervalEnd;
  bool elementRoute_bRoad_segmentsElementDrivable_lane_segmentsElementLane_intervalWrong_way{true};
  elementRoute_bRoad_segmentsElementDrivable_lane_segmentsElementLane_interval.wrong_way
    = elementRoute_bRoad_segmentsElementDrivable_lane_segmentsElementLane_intervalWrong_way;
  elementRoute_bRoad_segmentsElementDrivable_lane_segmentsElement.lane_interval
    = elementRoute_bRoad_segmentsElementDrivable_lane_segmentsElementLane_interval;
  ::ad::map::route::RouteLaneOffset elementRoute_bRoad_segmentsElementDrivable_lane_segmentsElementRoute_lane_offset(
    std::numeric_limits<::ad::map::route::RouteLaneOffset>::lowest());
  elementRoute_bRoad_segmentsElementDrivable_lane_segmentsElement.route_lane_offset
    = elementRoute_bRoad_segmentsElementDrivable_lane_segmentsElementRoute_lane_offset;
  elementRoute_bRoad_segmentsElementDrivable_lane_segments.resize(
    1, elementRoute_bRoad_segmentsElementDrivable_lane_segmentsElement);
  elementRoute_bRoad_segmentsElement.drivable_lane_segments = elementRoute_bRoad_segmentsElementDrivable_lane_segments;
  ::ad::map::route::SegmentCounter elementRoute_bRoad_segmentsElementSegment_count_from_destination(
    std::numeric_limits<::ad::map::route::SegmentCounter>::lowest());
  elementRoute_bRoad_segmentsElement.segment_count_from_destination
    = elementRoute_bRoad_segmentsElementSegment_count_from_destination;
  ::ad::map::point::BoundingSphere elementRoute_bRoad_segmentsElementBounding_sphere;
  ::ad::map::point::ECEFPoint elementRoute_bRoad_segmentsElementBounding_sphereCenter;
  ::ad::map::point::ECEFCoordinate elementRoute_bRoad_segmentsElementBounding_sphereCenterX(-6400000);
  elementRoute_bRoad_segmentsElementBounding_sphereCenter.x = elementRoute_bRoad_segmentsElementBounding_sphereCenterX;
  ::ad::map::point::ECEFCoordinate elementRoute_bRoad_segmentsElementBounding_sphereCenterY(-6400000);
  elementRoute_bRoad_segmentsElementBounding_sphereCenter.y = elementRoute_bRoad_segmentsElementBounding_sphereCenterY;
  ::ad::map::point::ECEFCoordinate elementRoute_bRoad_segmentsElementBounding_sphereCenterZ(-6400000);
  elementRoute_bRoad_segmentsElementBounding_sphereCenter.z = elementRoute_bRoad_segmentsElementBounding_sphereCenterZ;
  elementRoute_bRoad_segmentsElementBounding_sphere.center = elementRoute_bRoad_segmentsElementBounding_sphereCenter;
  ::ad::physics::Distance elementRoute_bRoad_segmentsElementBounding_sphereRadius(-1e9);
  elementRoute_bRoad_segmentsElementBounding_sphere.radius = elementRoute_bRoad_segmentsElementBounding_sphereRadius;
  elementRoute_bRoad_segmentsElement.bounding_sphere = elementRoute_bRoad_segmentsElementBounding_sphere;
  elementRoute_bRoad_segments.resize(1, elementRoute_bRoad_segmentsElement);
  elementRoute_b.road_segments = elementRoute_bRoad_segments;
  ::ad::map::route::RoutePlanningCounter elementRoute_bRoute_planning_counter(
    std::numeric_limits<::ad::map::route::RoutePlanningCounter>::lowest());
  elementRoute_b.route_planning_counter = elementRoute_bRoute_planning_counter;
  ::ad::map::route::SegmentCounter elementRoute_bFull_route_segment_count(
    std::numeric_limits<::ad::map::route::SegmentCounter>::lowest());
  elementRoute_b.full_route_segment_count = elementRoute_bFull_route_segment_count;
  ::ad::map::route::RouteLaneOffset elementRoute_bDestination_lane_offset(
    std::numeric_limits<::ad::map::route::RouteLaneOffset>::lowest());
  elementRoute_b.destination_lane_offset = elementRoute_bDestination_lane_offset;
  ::ad::map::route::RouteLaneOffset elementRoute_bMin_lane_offset(
    std::numeric_limits<::ad::map::route::RouteLaneOffset>::lowest());
  elementRoute_b.min_lane_offset = elementRoute_bMin_lane_offset;
  ::ad::map::route::RouteLaneOffset elementRoute_bMax_lane_offset(
    std::numeric_limits<::ad::map::route::RouteLaneOffset>::lowest());
  elementRoute_b.max_lane_offset = elementRoute_bMax_lane_offset;
  ::ad::map::route::RouteCreationMode elementRoute_bRoute_creation_mode(::ad::map::route::RouteCreationMode::Undefined);
  elementRoute_b.route_creation_mode = elementRoute_bRoute_creation_mode;
  element.route_b = elementRoute_b;
  ::ad::physics::Distance elementRoute_a_length(-1e9);
  element.route_a_length = elementRoute_a_length;
  ::ad::physics::Distance elementRoute_b_length(-1e9);
  element.route_b_length = elementRoute_b_length;
  ::ad::physics::Probability elementHeading_rating_a(0.);
  element.heading_rating_a = elementHeading_rating_a;
  ::ad::physics::Probability elementHeading_rating_b(0.);
  element.heading_rating_b = elementHeading_rating_b;
  ::ad::map::point::ENUHeading elementRoute_a_heading_start(-3.141592655);
  element.route_a_heading_start = elementRoute_a_heading_start;
  ::ad::map::point::ENUHeading elementRoute_a_heading_end(-3.141592655);
  element.route_a_heading_end = elementRoute_a_heading_end;
  ::ad::map::point::ENUHeading elementRoute_b_heading_start(-3.141592655);
  element.route_b_heading_start = elementRoute_b_heading_start;
  ::ad::map::point::ENUHeading elementRoute_b_heading_end(-3.141592655);
  element.route_b_heading_end = elementRoute_b_heading_end;
  value.push_back(element);
  ASSERT_TRUE(withinValidInputRange(value));
}

TEST(ConnectingRouteListValidInputRangeTests, testValidInputRangeElementInvalid)
{
  ::ad::map::route::ConnectingRouteList value;
  ::ad::map::route::ConnectingRoute element;
  ::ad::map::route::ConnectingRouteType elementType(static_cast<::ad::map::route::ConnectingRouteType>(-1));
  element.type = elementType;
  value.push_back(element);
  ASSERT_FALSE(withinValidInputRange(value));
}
