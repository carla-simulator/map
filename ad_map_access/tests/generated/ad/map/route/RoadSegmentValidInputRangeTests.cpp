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

#include "ad/map/route/RoadSegmentValidInputRange.hpp"

TEST(RoadSegmentValidInputRangeTests, testValidInputRange)
{
  ::ad::map::route::RoadSegment value;
  ::ad::map::route::LaneSegmentList valueDrivable_lane_segments;
  ::ad::map::route::LaneSegment valueDrivable_lane_segmentsElement;
  ::ad::map::lane::LaneId valueDrivable_lane_segmentsElementLeft_neighbor(1);
  valueDrivable_lane_segmentsElement.left_neighbor = valueDrivable_lane_segmentsElementLeft_neighbor;
  ::ad::map::lane::LaneId valueDrivable_lane_segmentsElementRight_neighbor(1);
  valueDrivable_lane_segmentsElement.right_neighbor = valueDrivable_lane_segmentsElementRight_neighbor;
  ::ad::map::lane::LaneIdList valueDrivable_lane_segmentsElementPredecessors;
  ::ad::map::lane::LaneId valueDrivable_lane_segmentsElementPredecessorsElement(1);
  valueDrivable_lane_segmentsElementPredecessors.resize(1, valueDrivable_lane_segmentsElementPredecessorsElement);
  valueDrivable_lane_segmentsElement.predecessors = valueDrivable_lane_segmentsElementPredecessors;
  ::ad::map::lane::LaneIdList valueDrivable_lane_segmentsElementSuccessors;
  ::ad::map::lane::LaneId valueDrivable_lane_segmentsElementSuccessorsElement(1);
  valueDrivable_lane_segmentsElementSuccessors.resize(1, valueDrivable_lane_segmentsElementSuccessorsElement);
  valueDrivable_lane_segmentsElement.successors = valueDrivable_lane_segmentsElementSuccessors;
  ::ad::map::route::LaneInterval valueDrivable_lane_segmentsElementLane_interval;
  ::ad::map::lane::LaneId valueDrivable_lane_segmentsElementLane_intervalLane_id(1);
  valueDrivable_lane_segmentsElementLane_interval.lane_id = valueDrivable_lane_segmentsElementLane_intervalLane_id;
  ::ad::physics::ParametricValue valueDrivable_lane_segmentsElementLane_intervalStart(0.);
  valueDrivable_lane_segmentsElementLane_interval.start = valueDrivable_lane_segmentsElementLane_intervalStart;
  ::ad::physics::ParametricValue valueDrivable_lane_segmentsElementLane_intervalEnd(0.);
  valueDrivable_lane_segmentsElementLane_interval.end = valueDrivable_lane_segmentsElementLane_intervalEnd;
  bool valueDrivable_lane_segmentsElementLane_intervalWrong_way{true};
  valueDrivable_lane_segmentsElementLane_interval.wrong_way = valueDrivable_lane_segmentsElementLane_intervalWrong_way;
  valueDrivable_lane_segmentsElement.lane_interval = valueDrivable_lane_segmentsElementLane_interval;
  ::ad::map::route::RouteLaneOffset valueDrivable_lane_segmentsElementRoute_lane_offset(
    std::numeric_limits<::ad::map::route::RouteLaneOffset>::lowest());
  valueDrivable_lane_segmentsElement.route_lane_offset = valueDrivable_lane_segmentsElementRoute_lane_offset;
  valueDrivable_lane_segments.resize(1, valueDrivable_lane_segmentsElement);
  value.drivable_lane_segments = valueDrivable_lane_segments;
  ::ad::map::route::SegmentCounter valueSegment_count_from_destination(
    std::numeric_limits<::ad::map::route::SegmentCounter>::lowest());
  value.segment_count_from_destination = valueSegment_count_from_destination;
  ::ad::map::point::BoundingSphere valueBounding_sphere;
  ::ad::map::point::ECEFPoint valueBounding_sphereCenter;
  ::ad::map::point::ECEFCoordinate valueBounding_sphereCenterX(-6400000);
  valueBounding_sphereCenter.x = valueBounding_sphereCenterX;
  ::ad::map::point::ECEFCoordinate valueBounding_sphereCenterY(-6400000);
  valueBounding_sphereCenter.y = valueBounding_sphereCenterY;
  ::ad::map::point::ECEFCoordinate valueBounding_sphereCenterZ(-6400000);
  valueBounding_sphereCenter.z = valueBounding_sphereCenterZ;
  valueBounding_sphere.center = valueBounding_sphereCenter;
  ::ad::physics::Distance valueBounding_sphereRadius(-1e9);
  valueBounding_sphere.radius = valueBounding_sphereRadius;
  value.bounding_sphere = valueBounding_sphere;
  ASSERT_TRUE(withinValidInputRange(value));
}

TEST(RoadSegmentValidInputRangeTests, testValidInputRangeBounding_sphereTooSmall)
{
  ::ad::map::route::RoadSegment value;
  ::ad::map::route::LaneSegmentList valueDrivable_lane_segments;
  ::ad::map::route::LaneSegment valueDrivable_lane_segmentsElement;
  ::ad::map::lane::LaneId valueDrivable_lane_segmentsElementLeft_neighbor(1);
  valueDrivable_lane_segmentsElement.left_neighbor = valueDrivable_lane_segmentsElementLeft_neighbor;
  ::ad::map::lane::LaneId valueDrivable_lane_segmentsElementRight_neighbor(1);
  valueDrivable_lane_segmentsElement.right_neighbor = valueDrivable_lane_segmentsElementRight_neighbor;
  ::ad::map::lane::LaneIdList valueDrivable_lane_segmentsElementPredecessors;
  ::ad::map::lane::LaneId valueDrivable_lane_segmentsElementPredecessorsElement(1);
  valueDrivable_lane_segmentsElementPredecessors.resize(1, valueDrivable_lane_segmentsElementPredecessorsElement);
  valueDrivable_lane_segmentsElement.predecessors = valueDrivable_lane_segmentsElementPredecessors;
  ::ad::map::lane::LaneIdList valueDrivable_lane_segmentsElementSuccessors;
  ::ad::map::lane::LaneId valueDrivable_lane_segmentsElementSuccessorsElement(1);
  valueDrivable_lane_segmentsElementSuccessors.resize(1, valueDrivable_lane_segmentsElementSuccessorsElement);
  valueDrivable_lane_segmentsElement.successors = valueDrivable_lane_segmentsElementSuccessors;
  ::ad::map::route::LaneInterval valueDrivable_lane_segmentsElementLane_interval;
  ::ad::map::lane::LaneId valueDrivable_lane_segmentsElementLane_intervalLane_id(1);
  valueDrivable_lane_segmentsElementLane_interval.lane_id = valueDrivable_lane_segmentsElementLane_intervalLane_id;
  ::ad::physics::ParametricValue valueDrivable_lane_segmentsElementLane_intervalStart(0.);
  valueDrivable_lane_segmentsElementLane_interval.start = valueDrivable_lane_segmentsElementLane_intervalStart;
  ::ad::physics::ParametricValue valueDrivable_lane_segmentsElementLane_intervalEnd(0.);
  valueDrivable_lane_segmentsElementLane_interval.end = valueDrivable_lane_segmentsElementLane_intervalEnd;
  bool valueDrivable_lane_segmentsElementLane_intervalWrong_way{true};
  valueDrivable_lane_segmentsElementLane_interval.wrong_way = valueDrivable_lane_segmentsElementLane_intervalWrong_way;
  valueDrivable_lane_segmentsElement.lane_interval = valueDrivable_lane_segmentsElementLane_interval;
  ::ad::map::route::RouteLaneOffset valueDrivable_lane_segmentsElementRoute_lane_offset(
    std::numeric_limits<::ad::map::route::RouteLaneOffset>::lowest());
  valueDrivable_lane_segmentsElement.route_lane_offset = valueDrivable_lane_segmentsElementRoute_lane_offset;
  valueDrivable_lane_segments.resize(1, valueDrivable_lane_segmentsElement);
  value.drivable_lane_segments = valueDrivable_lane_segments;
  ::ad::map::route::SegmentCounter valueSegment_count_from_destination(
    std::numeric_limits<::ad::map::route::SegmentCounter>::lowest());
  value.segment_count_from_destination = valueSegment_count_from_destination;
  ::ad::map::point::BoundingSphere valueBounding_sphere;
  ::ad::map::point::ECEFPoint valueBounding_sphereCenter;
  ::ad::map::point::ECEFCoordinate valueBounding_sphereCenterX(-6400000);
  valueBounding_sphereCenter.x = valueBounding_sphereCenterX;
  ::ad::map::point::ECEFCoordinate valueBounding_sphereCenterY(-6400000);
  valueBounding_sphereCenter.y = valueBounding_sphereCenterY;
  ::ad::map::point::ECEFCoordinate valueBounding_sphereCenterZ(-6400000);
  valueBounding_sphereCenter.z = valueBounding_sphereCenterZ;
  valueBounding_sphere.center = valueBounding_sphereCenter;
  ::ad::physics::Distance valueBounding_sphereRadius(-1e9);
  valueBounding_sphere.radius = valueBounding_sphereRadius;
  value.bounding_sphere = valueBounding_sphere;

  // override member with data type value below input range minimum
  ::ad::map::point::BoundingSphere invalidInitializedMember;
  ::ad::map::point::ECEFPoint invalidInitializedMemberCenter;
  ::ad::map::point::ECEFCoordinate invalidInitializedMemberCenterX(-6400000 * 1.1);
  invalidInitializedMemberCenter.x = invalidInitializedMemberCenterX;
  invalidInitializedMember.center = invalidInitializedMemberCenter;
  value.bounding_sphere = invalidInitializedMember;
  ASSERT_FALSE(withinValidInputRange(value));
}

TEST(RoadSegmentValidInputRangeTests, testValidInputRangeBounding_sphereTooBig)
{
  ::ad::map::route::RoadSegment value;
  ::ad::map::route::LaneSegmentList valueDrivable_lane_segments;
  ::ad::map::route::LaneSegment valueDrivable_lane_segmentsElement;
  ::ad::map::lane::LaneId valueDrivable_lane_segmentsElementLeft_neighbor(1);
  valueDrivable_lane_segmentsElement.left_neighbor = valueDrivable_lane_segmentsElementLeft_neighbor;
  ::ad::map::lane::LaneId valueDrivable_lane_segmentsElementRight_neighbor(1);
  valueDrivable_lane_segmentsElement.right_neighbor = valueDrivable_lane_segmentsElementRight_neighbor;
  ::ad::map::lane::LaneIdList valueDrivable_lane_segmentsElementPredecessors;
  ::ad::map::lane::LaneId valueDrivable_lane_segmentsElementPredecessorsElement(1);
  valueDrivable_lane_segmentsElementPredecessors.resize(1, valueDrivable_lane_segmentsElementPredecessorsElement);
  valueDrivable_lane_segmentsElement.predecessors = valueDrivable_lane_segmentsElementPredecessors;
  ::ad::map::lane::LaneIdList valueDrivable_lane_segmentsElementSuccessors;
  ::ad::map::lane::LaneId valueDrivable_lane_segmentsElementSuccessorsElement(1);
  valueDrivable_lane_segmentsElementSuccessors.resize(1, valueDrivable_lane_segmentsElementSuccessorsElement);
  valueDrivable_lane_segmentsElement.successors = valueDrivable_lane_segmentsElementSuccessors;
  ::ad::map::route::LaneInterval valueDrivable_lane_segmentsElementLane_interval;
  ::ad::map::lane::LaneId valueDrivable_lane_segmentsElementLane_intervalLane_id(1);
  valueDrivable_lane_segmentsElementLane_interval.lane_id = valueDrivable_lane_segmentsElementLane_intervalLane_id;
  ::ad::physics::ParametricValue valueDrivable_lane_segmentsElementLane_intervalStart(0.);
  valueDrivable_lane_segmentsElementLane_interval.start = valueDrivable_lane_segmentsElementLane_intervalStart;
  ::ad::physics::ParametricValue valueDrivable_lane_segmentsElementLane_intervalEnd(0.);
  valueDrivable_lane_segmentsElementLane_interval.end = valueDrivable_lane_segmentsElementLane_intervalEnd;
  bool valueDrivable_lane_segmentsElementLane_intervalWrong_way{true};
  valueDrivable_lane_segmentsElementLane_interval.wrong_way = valueDrivable_lane_segmentsElementLane_intervalWrong_way;
  valueDrivable_lane_segmentsElement.lane_interval = valueDrivable_lane_segmentsElementLane_interval;
  ::ad::map::route::RouteLaneOffset valueDrivable_lane_segmentsElementRoute_lane_offset(
    std::numeric_limits<::ad::map::route::RouteLaneOffset>::lowest());
  valueDrivable_lane_segmentsElement.route_lane_offset = valueDrivable_lane_segmentsElementRoute_lane_offset;
  valueDrivable_lane_segments.resize(1, valueDrivable_lane_segmentsElement);
  value.drivable_lane_segments = valueDrivable_lane_segments;
  ::ad::map::route::SegmentCounter valueSegment_count_from_destination(
    std::numeric_limits<::ad::map::route::SegmentCounter>::lowest());
  value.segment_count_from_destination = valueSegment_count_from_destination;
  ::ad::map::point::BoundingSphere valueBounding_sphere;
  ::ad::map::point::ECEFPoint valueBounding_sphereCenter;
  ::ad::map::point::ECEFCoordinate valueBounding_sphereCenterX(-6400000);
  valueBounding_sphereCenter.x = valueBounding_sphereCenterX;
  ::ad::map::point::ECEFCoordinate valueBounding_sphereCenterY(-6400000);
  valueBounding_sphereCenter.y = valueBounding_sphereCenterY;
  ::ad::map::point::ECEFCoordinate valueBounding_sphereCenterZ(-6400000);
  valueBounding_sphereCenter.z = valueBounding_sphereCenterZ;
  valueBounding_sphere.center = valueBounding_sphereCenter;
  ::ad::physics::Distance valueBounding_sphereRadius(-1e9);
  valueBounding_sphere.radius = valueBounding_sphereRadius;
  value.bounding_sphere = valueBounding_sphere;

  // override member with data type value above input range maximum
  ::ad::map::point::BoundingSphere invalidInitializedMember;
  ::ad::map::point::ECEFPoint invalidInitializedMemberCenter;
  ::ad::map::point::ECEFCoordinate invalidInitializedMemberCenterX(6400000 * 1.1);
  invalidInitializedMemberCenter.x = invalidInitializedMemberCenterX;
  invalidInitializedMember.center = invalidInitializedMemberCenter;
  value.bounding_sphere = invalidInitializedMember;
  ASSERT_FALSE(withinValidInputRange(value));
}
