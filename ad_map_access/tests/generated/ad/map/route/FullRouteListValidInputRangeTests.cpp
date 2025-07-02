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

#include "ad/map/route/FullRouteListValidInputRange.hpp"

TEST(FullRouteListValidInputRangeTests, testValidInputRangeValidInputRangeMin)
{
  ::ad::map::route::FullRouteList value;
  ASSERT_TRUE(withinValidInputRange(value));
}

TEST(FullRouteListValidInputRangeTests, testValidInputRangeElementValid)
{
  ::ad::map::route::FullRouteList value;
  ::ad::map::route::FullRoute element;
  ::ad::map::route::RoadSegmentList elementRoad_segments;
  ::ad::map::route::RoadSegment elementRoad_segmentsElement;
  ::ad::map::route::LaneSegmentList elementRoad_segmentsElementDrivable_lane_segments;
  ::ad::map::route::LaneSegment elementRoad_segmentsElementDrivable_lane_segmentsElement;
  ::ad::map::lane::LaneId elementRoad_segmentsElementDrivable_lane_segmentsElementLeft_neighbor(1);
  elementRoad_segmentsElementDrivable_lane_segmentsElement.left_neighbor
    = elementRoad_segmentsElementDrivable_lane_segmentsElementLeft_neighbor;
  ::ad::map::lane::LaneId elementRoad_segmentsElementDrivable_lane_segmentsElementRight_neighbor(1);
  elementRoad_segmentsElementDrivable_lane_segmentsElement.right_neighbor
    = elementRoad_segmentsElementDrivable_lane_segmentsElementRight_neighbor;
  ::ad::map::lane::LaneIdList elementRoad_segmentsElementDrivable_lane_segmentsElementPredecessors;
  ::ad::map::lane::LaneId elementRoad_segmentsElementDrivable_lane_segmentsElementPredecessorsElement(1);
  elementRoad_segmentsElementDrivable_lane_segmentsElementPredecessors.resize(
    1, elementRoad_segmentsElementDrivable_lane_segmentsElementPredecessorsElement);
  elementRoad_segmentsElementDrivable_lane_segmentsElement.predecessors
    = elementRoad_segmentsElementDrivable_lane_segmentsElementPredecessors;
  ::ad::map::lane::LaneIdList elementRoad_segmentsElementDrivable_lane_segmentsElementSuccessors;
  ::ad::map::lane::LaneId elementRoad_segmentsElementDrivable_lane_segmentsElementSuccessorsElement(1);
  elementRoad_segmentsElementDrivable_lane_segmentsElementSuccessors.resize(
    1, elementRoad_segmentsElementDrivable_lane_segmentsElementSuccessorsElement);
  elementRoad_segmentsElementDrivable_lane_segmentsElement.successors
    = elementRoad_segmentsElementDrivable_lane_segmentsElementSuccessors;
  ::ad::map::route::LaneInterval elementRoad_segmentsElementDrivable_lane_segmentsElementLane_interval;
  ::ad::map::lane::LaneId elementRoad_segmentsElementDrivable_lane_segmentsElementLane_intervalLane_id(1);
  elementRoad_segmentsElementDrivable_lane_segmentsElementLane_interval.lane_id
    = elementRoad_segmentsElementDrivable_lane_segmentsElementLane_intervalLane_id;
  ::ad::physics::ParametricValue elementRoad_segmentsElementDrivable_lane_segmentsElementLane_intervalStart(0.);
  elementRoad_segmentsElementDrivable_lane_segmentsElementLane_interval.start
    = elementRoad_segmentsElementDrivable_lane_segmentsElementLane_intervalStart;
  ::ad::physics::ParametricValue elementRoad_segmentsElementDrivable_lane_segmentsElementLane_intervalEnd(0.);
  elementRoad_segmentsElementDrivable_lane_segmentsElementLane_interval.end
    = elementRoad_segmentsElementDrivable_lane_segmentsElementLane_intervalEnd;
  bool elementRoad_segmentsElementDrivable_lane_segmentsElementLane_intervalWrong_way{true};
  elementRoad_segmentsElementDrivable_lane_segmentsElementLane_interval.wrong_way
    = elementRoad_segmentsElementDrivable_lane_segmentsElementLane_intervalWrong_way;
  elementRoad_segmentsElementDrivable_lane_segmentsElement.lane_interval
    = elementRoad_segmentsElementDrivable_lane_segmentsElementLane_interval;
  ::ad::map::route::RouteLaneOffset elementRoad_segmentsElementDrivable_lane_segmentsElementRoute_lane_offset(
    std::numeric_limits<::ad::map::route::RouteLaneOffset>::lowest());
  elementRoad_segmentsElementDrivable_lane_segmentsElement.route_lane_offset
    = elementRoad_segmentsElementDrivable_lane_segmentsElementRoute_lane_offset;
  elementRoad_segmentsElementDrivable_lane_segments.resize(1, elementRoad_segmentsElementDrivable_lane_segmentsElement);
  elementRoad_segmentsElement.drivable_lane_segments = elementRoad_segmentsElementDrivable_lane_segments;
  ::ad::map::route::SegmentCounter elementRoad_segmentsElementSegment_count_from_destination(
    std::numeric_limits<::ad::map::route::SegmentCounter>::lowest());
  elementRoad_segmentsElement.segment_count_from_destination
    = elementRoad_segmentsElementSegment_count_from_destination;
  ::ad::map::point::BoundingSphere elementRoad_segmentsElementBounding_sphere;
  ::ad::map::point::ECEFPoint elementRoad_segmentsElementBounding_sphereCenter;
  ::ad::map::point::ECEFCoordinate elementRoad_segmentsElementBounding_sphereCenterX(-6400000);
  elementRoad_segmentsElementBounding_sphereCenter.x = elementRoad_segmentsElementBounding_sphereCenterX;
  ::ad::map::point::ECEFCoordinate elementRoad_segmentsElementBounding_sphereCenterY(-6400000);
  elementRoad_segmentsElementBounding_sphereCenter.y = elementRoad_segmentsElementBounding_sphereCenterY;
  ::ad::map::point::ECEFCoordinate elementRoad_segmentsElementBounding_sphereCenterZ(-6400000);
  elementRoad_segmentsElementBounding_sphereCenter.z = elementRoad_segmentsElementBounding_sphereCenterZ;
  elementRoad_segmentsElementBounding_sphere.center = elementRoad_segmentsElementBounding_sphereCenter;
  ::ad::physics::Distance elementRoad_segmentsElementBounding_sphereRadius(-1e9);
  elementRoad_segmentsElementBounding_sphere.radius = elementRoad_segmentsElementBounding_sphereRadius;
  elementRoad_segmentsElement.bounding_sphere = elementRoad_segmentsElementBounding_sphere;
  elementRoad_segments.resize(1, elementRoad_segmentsElement);
  element.road_segments = elementRoad_segments;
  ::ad::map::route::RoutePlanningCounter elementRoute_planning_counter(
    std::numeric_limits<::ad::map::route::RoutePlanningCounter>::lowest());
  element.route_planning_counter = elementRoute_planning_counter;
  ::ad::map::route::SegmentCounter elementFull_route_segment_count(
    std::numeric_limits<::ad::map::route::SegmentCounter>::lowest());
  element.full_route_segment_count = elementFull_route_segment_count;
  ::ad::map::route::RouteLaneOffset elementDestination_lane_offset(
    std::numeric_limits<::ad::map::route::RouteLaneOffset>::lowest());
  element.destination_lane_offset = elementDestination_lane_offset;
  ::ad::map::route::RouteLaneOffset elementMin_lane_offset(
    std::numeric_limits<::ad::map::route::RouteLaneOffset>::lowest());
  element.min_lane_offset = elementMin_lane_offset;
  ::ad::map::route::RouteLaneOffset elementMax_lane_offset(
    std::numeric_limits<::ad::map::route::RouteLaneOffset>::lowest());
  element.max_lane_offset = elementMax_lane_offset;
  ::ad::map::route::RouteCreationMode elementRoute_creation_mode(::ad::map::route::RouteCreationMode::Undefined);
  element.route_creation_mode = elementRoute_creation_mode;
  value.push_back(element);
  ASSERT_TRUE(withinValidInputRange(value));
}

TEST(FullRouteListValidInputRangeTests, testValidInputRangeElementInvalid)
{
  ::ad::map::route::FullRouteList value;
  ::ad::map::route::FullRoute element;
  ::ad::map::route::RouteCreationMode elementRoute_creation_mode(static_cast<::ad::map::route::RouteCreationMode>(-1));
  element.route_creation_mode = elementRoute_creation_mode;
  value.push_back(element);
  ASSERT_FALSE(withinValidInputRange(value));
}
