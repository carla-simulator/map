// ----------------- BEGIN LICENSE BLOCK ---------------------------------
//
// Copyright (C) 2018-2021 Intel Corporation
//
// SPDX-License-Identifier: MIT
//
// ----------------- END LICENSE BLOCK -----------------------------------

#include <ad/map/access/Operation.hpp>
#include <ad/map/lane/LaneOperation.hpp>
#include <ad/map/match/AdMapMatching.hpp>
#include <ad/map/point/Operation.hpp>
#include <algorithm>
#include <gtest/gtest.h>
#include "ad/map/match/MapMatchedOperation.hpp"

using namespace ::ad;
using namespace ::ad::map;
using namespace ::ad::map::match;

struct AdMapBoundingBoxMapMatchingTest : ::testing::Test
{
  AdMapBoundingBoxMapMatchingTest()
  {
  }

  virtual void SetUp()
  {
    access::cleanup();
    access::init("test_files/TPK.adm.txt");

    mMinProbabilty = physics::Probability(0.05);
    mSamplingDistance = physics::Distance(1.);

    config::PointOfInterest poi;
    ASSERT_TRUE(access::getPointOfInterest("T1", poi));
    mObjectPosition.enu_reference_point = access::getENUReferencePoint();
    mObjectPosition.center_point = point::toENU(poi.geo_point);
    mObjectPosition.heading = point::createENUHeading(M_PI_2);
    mObjectPosition.dimension.width = physics::Distance(0.7);
    mObjectPosition.dimension.length = physics::Distance(4.);
    mObjectPosition.dimension.height = physics::Distance(0.);
  }

  virtual void TearDown()
  {
    // make sure that we leave the singleton "clean"
    access::cleanup();
  }

  physics::Probability mMinProbabilty;
  physics::Distance mSamplingDistance;
  match::ENUObjectPosition mObjectPosition;
};

TEST_F(AdMapBoundingBoxMapMatchingTest, box_within_single_lane)
{
  match::AdMapMatching mapMatching;
  auto centerMapMatched = mapMatching.getMapMatchedPositions(mObjectPosition, mSamplingDistance, mMinProbabilty);

  point::ParaPointList para = getParaPoints(centerMapMatched);
  ASSERT_EQ(para.size(), 2u);

  ASSERT_FALSE(centerMapMatched.empty());
  auto heading = mapMatching.getLaneENUHeading(centerMapMatched.front());

  mObjectPosition.heading = heading;
  mObjectPosition.dimension.width = physics::Distance(1.5);
  mObjectPosition.dimension.length = physics::Distance(3);

  auto result = mapMatching.getMapMatchedBoundingBox(mObjectPosition, mSamplingDistance);

  ASSERT_EQ(result.lane_occupied_regions.size(), 1u);
  for (auto centerMatch : centerMapMatched)
  {
    if (centerMatch.type == match::MapMatchedPositionType::LANE_IN)
    {
      ASSERT_EQ(centerMatch.lane_point.para_point.lane_id, result.lane_occupied_regions.front().lane_id);
      ASSERT_LE(result.lane_occupied_regions.front().lateral_range.minimum,
                result.lane_occupied_regions.front().lateral_range.maximum);
      ASSERT_LE(result.lane_occupied_regions.front().longitudinal_range.minimum,
                result.lane_occupied_regions.front().longitudinal_range.maximum);
    }
  }

  ASSERT_EQ(getObjectENUHeading(result), heading);
  match::MapMatchedObjectBoundingBox saveResult = result;
  result.reference_point_positions[int32_t(match::ObjectReferencePoints::RearLeft)].clear();
  result.reference_point_positions[int32_t(match::ObjectReferencePoints::RearRight)].clear();
  result.reference_point_positions[int32_t(match::ObjectReferencePoints::FrontLeft)].clear();
  result.reference_point_positions[int32_t(match::ObjectReferencePoints::FrontRight)].clear();
  EXPECT_THROW(getObjectENUHeading(result), std::runtime_error);
  result = saveResult;
  result.reference_point_positions[int32_t(match::ObjectReferencePoints::RearRight)].clear();
  result.reference_point_positions[int32_t(match::ObjectReferencePoints::FrontRight)].clear();
  ASSERT_EQ(getObjectENUHeading(result), heading);
  result = saveResult;
  result.reference_point_positions[int32_t(match::ObjectReferencePoints::RearLeft)].clear();
  result.reference_point_positions[int32_t(match::ObjectReferencePoints::FrontLeft)].clear();
  ASSERT_EQ(getObjectENUHeading(result), heading);
  result = saveResult;
  result.reference_point_positions[int32_t(match::ObjectReferencePoints::RearLeft)].clear();
  result.reference_point_positions[int32_t(match::ObjectReferencePoints::RearRight)].clear();
  ASSERT_EQ(getObjectENUHeading(result), heading);
  result = saveResult;
  result.reference_point_positions[int32_t(match::ObjectReferencePoints::FrontLeft)].clear();
  result.reference_point_positions[int32_t(match::ObjectReferencePoints::FrontRight)].clear();
  ASSERT_EQ(getObjectENUHeading(result), heading);
  result = saveResult;

  std::vector<ENUObjectPosition> enuObjs;
  enuObjs.push_back(mObjectPosition);
  LaneOccupiedRegionList occRegion = mapMatching.getLaneOccupiedRegions(enuObjs, mSamplingDistance);

  lane::LaneId x11;
  ASSERT_EQ(occRegion.size(), 1u);
  for (auto centerMatch : centerMapMatched)
  {
    if (centerMatch.type == match::MapMatchedPositionType::LANE_IN)
    {
      x11 = centerMatch.lane_point.para_point.lane_id;
      ASSERT_EQ(centerMatch.lane_point.para_point.lane_id, occRegion.front().lane_id);
    }
  }

  physics::Distance dis = signedDistanceToLane(occRegion.front().lane_id, centerMapMatched);
  ASSERT_EQ(dis, physics::Distance(0));

  lane::LaneId x(100);
  MapMatchedPositionConfidenceList matchList;
  MapMatchedPosition matchPos;
  matchPos.lane_point.lane_width = physics::Distance(1.0);
  matchPos.lane_point.para_point.lane_id = x;

  matchPos.type = match::MapMatchedPositionType::LANE_LEFT;
  matchPos.lane_point.lateral_t = physics::RatioValue(1.0);
  matchList.clear();
  matchList.push_back(matchPos);
  EXPECT_THROW(signedDistanceToLane(x, matchList), std::runtime_error);

  matchPos.type = match::MapMatchedPositionType::LANE_LEFT;
  matchPos.lane_point.lateral_t = physics::RatioValue(-1.0);
  matchList.clear();
  matchList.push_back(matchPos);
  ASSERT_EQ(signedDistanceToLane(x, matchList), physics::Distance(-1.0));

  matchPos.type = match::MapMatchedPositionType::LANE_RIGHT;
  matchPos.lane_point.lateral_t = physics::RatioValue(0.8);
  matchList.clear();
  matchList.push_back(matchPos);
  EXPECT_THROW(signedDistanceToLane(x, matchList), std::runtime_error);

  matchPos.type = match::MapMatchedPositionType::LANE_RIGHT;
  matchPos.lane_point.lateral_t = physics::RatioValue(1.5);
  matchList.clear();
  matchList.push_back(matchPos);
  ASSERT_EQ(signedDistanceToLane(x, matchList), physics::Distance(0.5));

  matchPos.type = match::MapMatchedPositionType::INVALID;
  matchPos.lane_point.lateral_t = physics::RatioValue(1.0);
  matchList.clear();
  matchList.push_back(matchPos);
  EXPECT_THROW(signedDistanceToLane(x, matchList), std::runtime_error);

  Object obj;
  obj.enu_position = mObjectPosition;
  obj.map_matched_bounding_box = result;
  dis = getDistanceToLane(x11, obj);
  ASSERT_EQ(dis, physics::Distance(0));
  dis = getDistanceToLane(para[0].lane_id, obj);
  ASSERT_NEAR(dis.mDistance, 1.7429, 0.0001);
}

TEST_F(AdMapBoundingBoxMapMatchingTest, rotated_box_within_two_lateral_lanes)
{
  match::AdMapMatching mapMatching;
  auto centerMapMatched = mapMatching.getMapMatchedPositions(mObjectPosition, mSamplingDistance, mMinProbabilty);

  ASSERT_EQ(centerMapMatched.size(), 2u);
  auto heading = mapMatching.getLaneENUHeading(centerMapMatched.front());

  mObjectPosition.heading = heading;
  mObjectPosition.dimension.width = physics::Distance(4.);
  mObjectPosition.dimension.length = physics::Distance(1.5);

  auto result = mapMatching.getMapMatchedBoundingBox(mObjectPosition, mSamplingDistance);

  ASSERT_EQ(result.lane_occupied_regions.size(), 2u);

  auto searchFront = std::find_if(result.lane_occupied_regions.begin(),
                                  result.lane_occupied_regions.end(),
                                  [&centerMapMatched](match::LaneOccupiedRegion const &other) {
                                    return other.lane_id == centerMapMatched.front().lane_point.para_point.lane_id;
                                  });
  ASSERT_TRUE(searchFront != std::end(result.lane_occupied_regions));

  auto searchBack = std::find_if(result.lane_occupied_regions.begin(),
                                 result.lane_occupied_regions.end(),
                                 [&centerMapMatched](match::LaneOccupiedRegion const &other) {
                                   return other.lane_id == centerMapMatched.back().lane_point.para_point.lane_id;
                                 });
  ASSERT_TRUE(searchBack != std::end(result.lane_occupied_regions));

  // ensure the whole lane region up the the lane borders is covered
  auto laneContactRelation = lane::getDirectNeighborhoodRelation(centerMapMatched.front().lane_point.para_point.lane_id,
                                                                 centerMapMatched.back().lane_point.para_point.lane_id);
  if (laneContactRelation == lane::ContactLocation::LEFT)
  {
    ASSERT_EQ(physics::ParametricValue(0.), searchFront->lateral_range.minimum);
    ASSERT_LT(physics::ParametricValue(0.), searchFront->lateral_range.maximum);
    ASSERT_EQ(physics::ParametricValue(1.), searchBack->lateral_range.maximum);
    ASSERT_GT(physics::ParametricValue(1.), searchFront->lateral_range.minimum);
  }
  else if (laneContactRelation == lane::ContactLocation::RIGHT)
  {
    ASSERT_EQ(physics::ParametricValue(0.), searchBack->lateral_range.minimum);
    ASSERT_LT(physics::ParametricValue(0.), searchBack->lateral_range.maximum);
    ASSERT_EQ(physics::ParametricValue(1.), searchFront->lateral_range.maximum);
    ASSERT_LT(physics::ParametricValue(1.), searchFront->lateral_range.minimum);
  }
  else
  {
    ASSERT_TRUE(false);
  }

  // reconstruct length and width of vehicle
  physics::Distance vehicleWidth(0.);
  for (auto const &occupiedRegion : result.lane_occupied_regions)
  {
    auto const vehicleLength = lane::getLane(occupiedRegion.lane_id).length
      * (occupiedRegion.longitudinal_range.maximum - occupiedRegion.longitudinal_range.minimum);
    ASSERT_LE(vehicleLength * 0.9, mObjectPosition.dimension.length);
    ASSERT_GE(vehicleLength * 1.1, mObjectPosition.dimension.length);

    vehicleWidth += lane::getLane(occupiedRegion.lane_id).width
      * (occupiedRegion.lateral_range.maximum - occupiedRegion.lateral_range.minimum);
  }

  ASSERT_LE(vehicleWidth * 0.9, mObjectPosition.dimension.width);
  ASSERT_GE(vehicleWidth * 1.1, mObjectPosition.dimension.width);
}

TEST_F(AdMapBoundingBoxMapMatchingTest, box_covering_three_lanes_longitudinal)
{
  auto objectCenter = point::toENU(
    point::createGeoPoint(point::Longitude(8.439497056), point::Latitude(49.018312553), point::Altitude(0.)));

  match::AdMapMatching mapMatching;
  auto centerMapMatched = mapMatching.getMapMatchedPositions(objectCenter, mSamplingDistance, mMinProbabilty);

  ASSERT_EQ(centerMapMatched.size(), 1u);

  auto const centerLaneId = centerMapMatched.front().lane_point.para_point.lane_id;
  auto objectPosition = mObjectPosition;
  auto heading = mapMatching.getLaneENUHeading(centerMapMatched.front());

  objectPosition.heading = heading;
  objectPosition.center_point = objectCenter;
  objectPosition.dimension.width = physics::Distance(2.5);
  objectPosition.dimension.length = physics::Distance(6.);

  auto result = mapMatching.getMapMatchedBoundingBox(objectPosition, mSamplingDistance);

  ASSERT_EQ(result.lane_occupied_regions.size(), 3u);

  // reconstruct length and width of vehicle
  physics::Distance vehicleLength(0.);
  for (auto const &occupiedRegion : result.lane_occupied_regions)
  {
    // longitudinal
    if (occupiedRegion.lane_id == centerLaneId)
    {
      // center lane fully covered
      ASSERT_EQ(physics::ParametricValue(0.), occupiedRegion.longitudinal_range.minimum);
      ASSERT_EQ(physics::ParametricValue(1.), occupiedRegion.longitudinal_range.maximum);
    }
    else if (occupiedRegion.longitudinal_range.minimum == physics::ParametricValue(0.))
    {
      // other lane not fully covered, but definitely some parts of it
      ASSERT_NE(physics::ParametricValue(0.), occupiedRegion.longitudinal_range.maximum);
      ASSERT_NE(physics::ParametricValue(1.), occupiedRegion.longitudinal_range.maximum);
    }
    else
    {
      // other lane not fully covered, but definitely some parts of it
      ASSERT_EQ(physics::ParametricValue(1.), occupiedRegion.longitudinal_range.maximum);
      ASSERT_NE(physics::ParametricValue(0.), occupiedRegion.longitudinal_range.minimum);
      ASSERT_NE(physics::ParametricValue(1.), occupiedRegion.longitudinal_range.minimum);
    }

    vehicleLength += lane::getLane(occupiedRegion.lane_id).length
      * (occupiedRegion.longitudinal_range.maximum - occupiedRegion.longitudinal_range.minimum);

    // lateral always in between
    ASSERT_NE(physics::ParametricValue(0.), occupiedRegion.lateral_range.minimum);
    ASSERT_NE(physics::ParametricValue(1.), occupiedRegion.lateral_range.minimum);
    ASSERT_NE(physics::ParametricValue(0.), occupiedRegion.lateral_range.maximum);
    ASSERT_NE(physics::ParametricValue(1.), occupiedRegion.lateral_range.maximum);

    auto const vehicleWidth = lane::getLane(occupiedRegion.lane_id).width
      * (occupiedRegion.lateral_range.maximum - occupiedRegion.lateral_range.minimum);
    ASSERT_LE(vehicleWidth * 0.9, objectPosition.dimension.width);
    ASSERT_GE(vehicleWidth * 1.1, objectPosition.dimension.width);
  }

  ASSERT_LE(vehicleLength * 0.9, objectPosition.dimension.length);
  ASSERT_GE(vehicleLength * 1.1, objectPosition.dimension.length);
}

TEST_F(AdMapBoundingBoxMapMatchingTest, box_not_touching_second_lane_within_sampling_distance)
{
  auto objectCenter = point::toENU(
    point::createGeoPoint(point::Longitude(8.4394653), point::Latitude(49.0182735), point::Altitude(0.)));

  match::AdMapMatching mapMatching;
  auto centerMapMatched = mapMatching.getMapMatchedPositions(objectCenter, mSamplingDistance, mMinProbabilty);

  ASSERT_EQ(centerMapMatched.size(), 1u);

  auto objectPosition = mObjectPosition;
  objectPosition.heading = mapMatching.getLaneENUHeading(centerMapMatched.front());
  objectPosition.center_point = objectCenter;
  objectPosition.dimension.width = physics::Distance(2.5);
  objectPosition.dimension.length = physics::Distance(6.);

  auto result = mapMatching.getMapMatchedBoundingBox(objectPosition, mSamplingDistance);

  ASSERT_EQ(result.lane_occupied_regions.size(), 1u);
}
