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

#include "ad/map/route/RoadSegmentListValidInputRange.hpp"

TEST(RoadSegmentListValidInputRangeTests, testValidInputRangeValidInputRangeMin)
{
  ::ad::map::route::RoadSegmentList value;
  ASSERT_TRUE(withinValidInputRange(value));
}

TEST(RoadSegmentListValidInputRangeTests, testValidInputRangeElementValid)
{
  ::ad::map::route::RoadSegmentList value;
  ::ad::map::route::RoadSegment element;
  ::ad::map::route::LaneSegmentList elementDrivable_lane_segments;
  ::ad::map::route::LaneSegment elementDrivable_lane_segmentsElement;
  ::ad::map::lane::LaneId elementDrivable_lane_segmentsElementLeft_neighbor(1);
  elementDrivable_lane_segmentsElement.left_neighbor = elementDrivable_lane_segmentsElementLeft_neighbor;
  ::ad::map::lane::LaneId elementDrivable_lane_segmentsElementRight_neighbor(1);
  elementDrivable_lane_segmentsElement.right_neighbor = elementDrivable_lane_segmentsElementRight_neighbor;
  ::ad::map::lane::LaneIdList elementDrivable_lane_segmentsElementPredecessors;
  ::ad::map::lane::LaneId elementDrivable_lane_segmentsElementPredecessorsElement(1);
  elementDrivable_lane_segmentsElementPredecessors.resize(1, elementDrivable_lane_segmentsElementPredecessorsElement);
  elementDrivable_lane_segmentsElement.predecessors = elementDrivable_lane_segmentsElementPredecessors;
  ::ad::map::lane::LaneIdList elementDrivable_lane_segmentsElementSuccessors;
  ::ad::map::lane::LaneId elementDrivable_lane_segmentsElementSuccessorsElement(1);
  elementDrivable_lane_segmentsElementSuccessors.resize(1, elementDrivable_lane_segmentsElementSuccessorsElement);
  elementDrivable_lane_segmentsElement.successors = elementDrivable_lane_segmentsElementSuccessors;
  ::ad::map::route::LaneInterval elementDrivable_lane_segmentsElementLane_interval;
  ::ad::map::lane::LaneId elementDrivable_lane_segmentsElementLane_intervalLane_id(1);
  elementDrivable_lane_segmentsElementLane_interval.lane_id = elementDrivable_lane_segmentsElementLane_intervalLane_id;
  ::ad::physics::ParametricValue elementDrivable_lane_segmentsElementLane_intervalStart(0.);
  elementDrivable_lane_segmentsElementLane_interval.start = elementDrivable_lane_segmentsElementLane_intervalStart;
  ::ad::physics::ParametricValue elementDrivable_lane_segmentsElementLane_intervalEnd(0.);
  elementDrivable_lane_segmentsElementLane_interval.end = elementDrivable_lane_segmentsElementLane_intervalEnd;
  bool elementDrivable_lane_segmentsElementLane_intervalWrong_way{true};
  elementDrivable_lane_segmentsElementLane_interval.wrong_way
    = elementDrivable_lane_segmentsElementLane_intervalWrong_way;
  elementDrivable_lane_segmentsElement.lane_interval = elementDrivable_lane_segmentsElementLane_interval;
  ::ad::map::route::RouteLaneOffset elementDrivable_lane_segmentsElementRoute_lane_offset(
    std::numeric_limits<::ad::map::route::RouteLaneOffset>::lowest());
  elementDrivable_lane_segmentsElement.route_lane_offset = elementDrivable_lane_segmentsElementRoute_lane_offset;
  elementDrivable_lane_segments.resize(1, elementDrivable_lane_segmentsElement);
  element.drivable_lane_segments = elementDrivable_lane_segments;
  ::ad::map::route::SegmentCounter elementSegment_count_from_destination(
    std::numeric_limits<::ad::map::route::SegmentCounter>::lowest());
  element.segment_count_from_destination = elementSegment_count_from_destination;
  ::ad::map::point::BoundingSphere elementBounding_sphere;
  ::ad::map::point::ECEFPoint elementBounding_sphereCenter;
  ::ad::map::point::ECEFCoordinate elementBounding_sphereCenterX(-6400000);
  elementBounding_sphereCenter.x = elementBounding_sphereCenterX;
  ::ad::map::point::ECEFCoordinate elementBounding_sphereCenterY(-6400000);
  elementBounding_sphereCenter.y = elementBounding_sphereCenterY;
  ::ad::map::point::ECEFCoordinate elementBounding_sphereCenterZ(-6400000);
  elementBounding_sphereCenter.z = elementBounding_sphereCenterZ;
  elementBounding_sphere.center = elementBounding_sphereCenter;
  ::ad::physics::Distance elementBounding_sphereRadius(-1e9);
  elementBounding_sphere.radius = elementBounding_sphereRadius;
  element.bounding_sphere = elementBounding_sphere;
  value.push_back(element);
  ASSERT_TRUE(withinValidInputRange(value));
}

TEST(RoadSegmentListValidInputRangeTests, testValidInputRangeElementInvalid)
{
  ::ad::map::route::RoadSegmentList value;
  ::ad::map::route::RoadSegment element;
  ::ad::map::point::BoundingSphere elementBounding_sphere;
  ::ad::map::point::ECEFPoint elementBounding_sphereCenter;
  ::ad::map::point::ECEFCoordinate elementBounding_sphereCenterX(-6400000 * 1.1);
  elementBounding_sphereCenter.x = elementBounding_sphereCenterX;
  elementBounding_sphere.center = elementBounding_sphereCenter;
  element.bounding_sphere = elementBounding_sphere;
  value.push_back(element);
  ASSERT_FALSE(withinValidInputRange(value));
}
