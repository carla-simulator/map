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
#include "ad/map/route/RoadSegment.hpp"

class RoadSegmentTests : public testing::Test
{
protected:
  virtual void SetUp() override
  {
    // valid initialization
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
    valueDrivable_lane_segmentsElementLane_interval.wrong_way
      = valueDrivable_lane_segmentsElementLane_intervalWrong_way;
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
    mValue = value;
  }

  ::ad::map::route::RoadSegment mValue;
};

TEST_F(RoadSegmentTests, copyConstruction)
{
  ::ad::map::route::RoadSegment value(mValue);
  EXPECT_EQ(mValue, value);
}

TEST_F(RoadSegmentTests, moveConstruction)
{
  ::ad::map::route::RoadSegment tmpValue(mValue);
  ::ad::map::route::RoadSegment value(std::move(tmpValue));
  EXPECT_EQ(mValue, value);
}

TEST_F(RoadSegmentTests, copyAssignment)
{
  ::ad::map::route::RoadSegment value;
  value = mValue;
  EXPECT_EQ(mValue, value);
}

TEST_F(RoadSegmentTests, moveAssignment)
{
  ::ad::map::route::RoadSegment tmpValue(mValue);
  ::ad::map::route::RoadSegment value;
  value = std::move(tmpValue);
  EXPECT_EQ(mValue, value);
}

TEST_F(RoadSegmentTests, comparisonOperatorEqual)
{
  ::ad::map::route::RoadSegment valueA = mValue;
  ::ad::map::route::RoadSegment valueB = mValue;

  EXPECT_TRUE(valueA == valueB);
  EXPECT_FALSE(valueA != valueB);
}

TEST_F(RoadSegmentTests, stringConversionTest)
{
  std::stringstream stream;
  stream << mValue;
  std::string ostreamStr = stream.str();
  std::string toStr = std::to_string(mValue);
  ASSERT_EQ(ostreamStr, toStr);
}

TEST_F(RoadSegmentTests, comparisonOperatorDrivable_lane_segmentsDiffers)
{
  ::ad::map::route::RoadSegment valueA = mValue;
  ::ad::map::route::LaneSegmentList drivable_lane_segments;
  ::ad::map::route::LaneSegment drivable_lane_segmentsElement;
  ::ad::map::lane::LaneId drivable_lane_segmentsElementLeft_neighbor(
    std::numeric_limits<::ad::map::lane::LaneId>::max());
  drivable_lane_segmentsElement.left_neighbor = drivable_lane_segmentsElementLeft_neighbor;
  ::ad::map::lane::LaneId drivable_lane_segmentsElementRight_neighbor(
    std::numeric_limits<::ad::map::lane::LaneId>::max());
  drivable_lane_segmentsElement.right_neighbor = drivable_lane_segmentsElementRight_neighbor;
  ::ad::map::lane::LaneIdList drivable_lane_segmentsElementPredecessors;
  ::ad::map::lane::LaneId drivable_lane_segmentsElementPredecessorsElement(
    std::numeric_limits<::ad::map::lane::LaneId>::max());
  drivable_lane_segmentsElementPredecessors.resize(2, drivable_lane_segmentsElementPredecessorsElement);
  drivable_lane_segmentsElement.predecessors = drivable_lane_segmentsElementPredecessors;
  ::ad::map::lane::LaneIdList drivable_lane_segmentsElementSuccessors;
  ::ad::map::lane::LaneId drivable_lane_segmentsElementSuccessorsElement(
    std::numeric_limits<::ad::map::lane::LaneId>::max());
  drivable_lane_segmentsElementSuccessors.resize(2, drivable_lane_segmentsElementSuccessorsElement);
  drivable_lane_segmentsElement.successors = drivable_lane_segmentsElementSuccessors;
  ::ad::map::route::LaneInterval drivable_lane_segmentsElementLane_interval;
  ::ad::map::lane::LaneId drivable_lane_segmentsElementLane_intervalLane_id(
    std::numeric_limits<::ad::map::lane::LaneId>::max());
  drivable_lane_segmentsElementLane_interval.lane_id = drivable_lane_segmentsElementLane_intervalLane_id;
  ::ad::physics::ParametricValue drivable_lane_segmentsElementLane_intervalStart(1.);
  drivable_lane_segmentsElementLane_interval.start = drivable_lane_segmentsElementLane_intervalStart;
  ::ad::physics::ParametricValue drivable_lane_segmentsElementLane_intervalEnd(1.);
  drivable_lane_segmentsElementLane_interval.end = drivable_lane_segmentsElementLane_intervalEnd;
  bool drivable_lane_segmentsElementLane_intervalWrong_way{false};
  drivable_lane_segmentsElementLane_interval.wrong_way = drivable_lane_segmentsElementLane_intervalWrong_way;
  drivable_lane_segmentsElement.lane_interval = drivable_lane_segmentsElementLane_interval;
  ::ad::map::route::RouteLaneOffset drivable_lane_segmentsElementRoute_lane_offset(
    std::numeric_limits<::ad::map::route::RouteLaneOffset>::max());
  drivable_lane_segmentsElement.route_lane_offset = drivable_lane_segmentsElementRoute_lane_offset;
  drivable_lane_segments.resize(2, drivable_lane_segmentsElement);
  valueA.drivable_lane_segments = drivable_lane_segments;
  ::ad::map::route::RoadSegment valueB = mValue;

  EXPECT_FALSE(valueA == valueB);
  EXPECT_TRUE(valueA != valueB);
}

TEST_F(RoadSegmentTests, comparisonOperatorSegment_count_from_destinationDiffers)
{
  ::ad::map::route::RoadSegment valueA = mValue;
  ::ad::map::route::SegmentCounter segment_count_from_destination(
    std::numeric_limits<::ad::map::route::SegmentCounter>::max());
  valueA.segment_count_from_destination = segment_count_from_destination;
  ::ad::map::route::RoadSegment valueB = mValue;

  EXPECT_FALSE(valueA == valueB);
  EXPECT_TRUE(valueA != valueB);
}

TEST_F(RoadSegmentTests, comparisonOperatorBounding_sphereDiffers)
{
  ::ad::map::route::RoadSegment valueA = mValue;
  ::ad::map::point::BoundingSphere bounding_sphere;
  ::ad::map::point::ECEFPoint bounding_sphereCenter;
  ::ad::map::point::ECEFCoordinate bounding_sphereCenterX(6400000);
  bounding_sphereCenter.x = bounding_sphereCenterX;
  ::ad::map::point::ECEFCoordinate bounding_sphereCenterY(6400000);
  bounding_sphereCenter.y = bounding_sphereCenterY;
  ::ad::map::point::ECEFCoordinate bounding_sphereCenterZ(6400000);
  bounding_sphereCenter.z = bounding_sphereCenterZ;
  bounding_sphere.center = bounding_sphereCenter;
  ::ad::physics::Distance bounding_sphereRadius(1e9);
  bounding_sphere.radius = bounding_sphereRadius;
  valueA.bounding_sphere = bounding_sphere;
  ::ad::map::route::RoadSegment valueB = mValue;

  EXPECT_FALSE(valueA == valueB);
  EXPECT_TRUE(valueA != valueB);
}

#if defined(__clang__) && (__clang_major__ >= 7)
#pragma GCC diagnostic pop
#endif
