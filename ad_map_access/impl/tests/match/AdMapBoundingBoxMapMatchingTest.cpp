// ----------------- BEGIN LICENSE BLOCK ---------------------------------
//
// Copyright (C) 2018-2020 Intel Corporation
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
    mDistance = physics::Distance(1.);

    mObjectPosition.centerPoint = point::createENUPoint(0, 0, 0);
    mObjectPosition.heading = point::createENUHeading(M_PI_2);
    mObjectPosition.dimension.width = physics::Distance(0.7);
    mObjectPosition.dimension.length = physics::Distance(4.);
    mObjectPosition.dimension.height = physics::Distance(0.);
    config::PointOfInterest poi;
    ASSERT_TRUE(access::getPointOfInterest("T1", poi));
    mObjectPosition.enuReferencePoint = poi.geoPoint;
  }

  virtual void TearDown()
  {
    // make sure that we leave the singleton "clean"
    access::cleanup();
  }

  physics::Probability mMinProbabilty;
  physics::Distance mDistance;
  match::ENUObjectPosition mObjectPosition;
};

TEST_F(AdMapBoundingBoxMapMatchingTest, box_within_single_lane)
{
  match::AdMapMatching mapMatching;
  auto centerMapMatched = mapMatching.getMapMatchedPositions(mObjectPosition, mDistance, mMinProbabilty);

  point::ParaPointList para = getParaPoints(centerMapMatched);
  ASSERT_EQ(para.size(), 2u);

  ASSERT_FALSE(centerMapMatched.empty());
  auto heading = mapMatching.getLaneENUHeading(centerMapMatched.front());

  mObjectPosition.heading = heading;
  mObjectPosition.dimension.width = physics::Distance(1.5);
  mObjectPosition.dimension.length = physics::Distance(3);

  auto result = mapMatching.getMapMatchedBoundingBox(mObjectPosition, mDistance, mMinProbabilty);

  ASSERT_EQ(result.laneOccupiedRegions.size(), 1u);
  for (auto centerMatch : centerMapMatched)
  {
    if (centerMatch.type == match::MapMatchedPositionType::LANE_IN)
    {
      ASSERT_EQ(centerMatch.lanePoint.paraPoint.laneId, result.laneOccupiedRegions.front().laneId);
    }
  }

  ASSERT_EQ(getObjectENUHeading(result), heading);
  match::MapMatchedObjectBoundingBox saveResult = result;
  result.referencePointPositions[int32_t(match::ObjectReferencePoints::RearLeft)].clear();
  result.referencePointPositions[int32_t(match::ObjectReferencePoints::RearRight)].clear();
  result.referencePointPositions[int32_t(match::ObjectReferencePoints::FrontLeft)].clear();
  result.referencePointPositions[int32_t(match::ObjectReferencePoints::FrontRight)].clear();
  EXPECT_THROW(getObjectENUHeading(result), std::runtime_error);
  result = saveResult;
  result.referencePointPositions[int32_t(match::ObjectReferencePoints::RearRight)].clear();
  result.referencePointPositions[int32_t(match::ObjectReferencePoints::FrontRight)].clear();
  ASSERT_EQ(getObjectENUHeading(result), heading);
  result = saveResult;
  result.referencePointPositions[int32_t(match::ObjectReferencePoints::RearLeft)].clear();
  result.referencePointPositions[int32_t(match::ObjectReferencePoints::FrontLeft)].clear();
  ASSERT_EQ(getObjectENUHeading(result), heading);
  result = saveResult;
  result.referencePointPositions[int32_t(match::ObjectReferencePoints::RearLeft)].clear();
  result.referencePointPositions[int32_t(match::ObjectReferencePoints::RearRight)].clear();
  ASSERT_EQ(getObjectENUHeading(result), heading);
  result = saveResult;
  result.referencePointPositions[int32_t(match::ObjectReferencePoints::FrontLeft)].clear();
  result.referencePointPositions[int32_t(match::ObjectReferencePoints::FrontRight)].clear();
  ASSERT_EQ(getObjectENUHeading(result), heading);
  result = saveResult;

  std::vector<ENUObjectPosition> enuObjs;
  enuObjs.push_back(mObjectPosition);
  LaneOccupiedRegionList occRegion = mapMatching.getLaneOccupiedRegions(enuObjs, mDistance, mMinProbabilty);

  lane::LaneId x11;
  ASSERT_EQ(occRegion.size(), 1u);
  for (auto centerMatch : centerMapMatched)
  {
    if (centerMatch.type == match::MapMatchedPositionType::LANE_IN)
    {
      x11 = centerMatch.lanePoint.paraPoint.laneId;
      ASSERT_EQ(centerMatch.lanePoint.paraPoint.laneId, occRegion.front().laneId);
    }
  }

  physics::Distance dis = signedDistanceToLane(occRegion.front().laneId, centerMapMatched);
  ASSERT_EQ(dis, physics::Distance(0));

  lane::LaneId x(100);
  MapMatchedPositionConfidenceList matchList;
  MapMatchedPosition matchPos;
  matchPos.lanePoint.laneWidth = physics::Distance(1.0);
  matchPos.lanePoint.paraPoint.laneId = x;

  matchPos.type = match::MapMatchedPositionType::LANE_LEFT;
  matchPos.lanePoint.lateralT = physics::RatioValue(1.0);
  matchList.clear();
  matchList.push_back(matchPos);
  EXPECT_THROW(signedDistanceToLane(x, matchList), std::runtime_error);

  matchPos.type = match::MapMatchedPositionType::LANE_LEFT;
  matchPos.lanePoint.lateralT = physics::RatioValue(-1.0);
  matchList.clear();
  matchList.push_back(matchPos);
  ASSERT_EQ(signedDistanceToLane(x, matchList), physics::Distance(-1.0));

  matchPos.type = match::MapMatchedPositionType::LANE_RIGHT;
  matchPos.lanePoint.lateralT = physics::RatioValue(0.8);
  matchList.clear();
  matchList.push_back(matchPos);
  EXPECT_THROW(signedDistanceToLane(x, matchList), std::runtime_error);

  matchPos.type = match::MapMatchedPositionType::LANE_RIGHT;
  matchPos.lanePoint.lateralT = physics::RatioValue(1.5);
  matchList.clear();
  matchList.push_back(matchPos);
  ASSERT_EQ(signedDistanceToLane(x, matchList), physics::Distance(0.5));

  matchPos.type = match::MapMatchedPositionType::INVALID;
  matchPos.lanePoint.lateralT = physics::RatioValue(1.0);
  matchList.clear();
  matchList.push_back(matchPos);
  EXPECT_THROW(signedDistanceToLane(x, matchList), std::runtime_error);

  Object obj;
  obj.enuPosition = mObjectPosition;
  obj.mapMatchedBoundingBox = result;
  dis = getDistanceToLane(x11, obj);
  ASSERT_EQ(dis, physics::Distance(0));
  dis = getDistanceToLane(para[0].laneId, obj);
  ASSERT_NEAR((double)dis, 1.7429, 0.0001);
}

TEST_F(AdMapBoundingBoxMapMatchingTest, rotate_box_within_lane)
{
  match::AdMapMatching mapMatching;
  auto centerMapMatched = mapMatching.getMapMatchedPositions(mObjectPosition, mDistance, mMinProbabilty);

  ASSERT_EQ(centerMapMatched.size(), 2u);
  auto heading = mapMatching.getLaneENUHeading(centerMapMatched.front());

  mObjectPosition.heading = point::createENUHeading(static_cast<double>(heading) + M_PI_2);
  mObjectPosition.dimension.width = physics::Distance(1.5);
  mObjectPosition.dimension.length = physics::Distance(4.);

  auto result = mapMatching.getMapMatchedBoundingBox(mObjectPosition, mDistance, mMinProbabilty);

  ASSERT_EQ(result.laneOccupiedRegions.size(), 2u);

  auto search = std::find_if(result.laneOccupiedRegions.begin(),
                             result.laneOccupiedRegions.end(),
                             [&centerMapMatched](match::LaneOccupiedRegion const &other) {
                               return other.laneId == centerMapMatched.front().lanePoint.paraPoint.laneId;
                             });
  ASSERT_TRUE(search != std::end(result.laneOccupiedRegions));

  search = std::find_if(result.laneOccupiedRegions.begin(),
                        result.laneOccupiedRegions.end(),
                        [&centerMapMatched](match::LaneOccupiedRegion const &other) {
                          return other.laneId == centerMapMatched.back().lanePoint.paraPoint.laneId;
                        });
  ASSERT_TRUE(search != std::end(result.laneOccupiedRegions));
}
