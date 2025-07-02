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
#include <ad/map/test_support/NoLogTestMacros.hpp>
#include <gtest/gtest.h>

using namespace ::ad;
using namespace ::ad::map;
using namespace ::ad::map::match;

struct AdMapMatchingTest : ::testing::Test
{
  AdMapMatchingTest()
  {
  }

  virtual void SetUp()
  {
    access::cleanup();
    access::init("test_files/TPK.adm.txt");
    mRouteHint = route::FullRoute();
    mMinProbabilty = physics::Probability(0.05);
    mHeadingHints.clear();
    mMapMatching = new match::AdMapMatching();
  }

  virtual void TearDown()
  {
    delete mMapMatching;
    access::cleanup();
  }

  void compareMapMatching(int line, point::GeoPoint const &geo_point, std::size_t const expectedNumberOfMatches);

  void addRouteHint()
  {
    // with route hint straigth through Albert-Nestler-Str
    auto hintPoint
      = point::createGeoPoint(point::Longitude(8.4401803), point::Latitude(49.0191987), point::Altitude(0.));
    auto mapMatchingResults = mMapMatching->getMapMatchedPositions(hintPoint, physics::Distance(0.01), mMinProbabilty);
    ASSERT_EQ(mapMatchingResults.size(), 1u);
    route::RoadSegment roadSegment;
    route::LaneSegment laneSegment;
    laneSegment.lane_interval.lane_id = mapMatchingResults.front().lane_point.para_point.lane_id;
    laneSegment.lane_interval.start = physics::ParametricValue(0.);
    laneSegment.lane_interval.end = physics::ParametricValue(1.);
    roadSegment.drivable_lane_segments.push_back(laneSegment);
    mRouteHint.road_segments.push_back(roadSegment);
  }

  /* A note on the test setup:
   * Location is the intersection Albert-Nestler-Str crossing Ada-Lovelace-Str
   *
   * Given:
   *            |  -> Albert-Nestler-Str
   *            |
   * -----------+
   *  ^         |
   *  |         |  -> Albert-Nestler-Str
   *  |
   *  Ada-Lovel.
   *
   * All points for matching (mTestPoints) should be along the lane from south to north
   * inside the intersection, e.g.
   * 8.4401468/49.0191790
   * 8.4401701/49.0192037
   * 8.4401889/49.0192335
   * are all along that lane (ordered from south to north)
   */

  std::string mTestFile{"test_files/TPK.adm.txt"};
  std::vector<std::pair<point::GeoPoint, size_t>> mTestPoints{
    std::make_pair(point::createGeoPoint(point::Longitude(8.4400665), point::Latitude(49.0192005), point::Altitude(0.)),
                   0u),
    std::make_pair(point::createGeoPoint(point::Longitude(8.4401882), point::Latitude(49.0191939), point::Altitude(0.)),
                   1u),
    std::make_pair(
      point::createGeoPoint(point::Longitude(8.4401882), point::Latitude(49.0191939), point::AltitudeUnknown), 1u),
    std::make_pair(point::createGeoPoint(point::Longitude(8.4401510), point::Latitude(49.0191792), point::Altitude(0.)),
                   2u),
    std::make_pair(point::createGeoPoint(point::Longitude(8.4401742), point::Latitude(49.0192009), point::Altitude(0.)),
                   3u),
    // approaching middle of the intersection
    std::make_pair(point::createGeoPoint(point::Longitude(8.4401540), point::Latitude(49.0192082), point::Altitude(0.)),
                   4u)};

  route::FullRoute mRouteHint;
  std::vector<point::ENUHeading> mHeadingHints;
  physics::Probability mMinProbabilty;
  match::AdMapMatching *mMapMatching;
};

void AdMapMatchingTest::compareMapMatching(int line,
                                           point::GeoPoint const &geo_point,
                                           std::size_t const expectedNumberOfMatches)
{
  physics::Distance searchDist(1);

  struct TestResult
  {
    match::MapMatchedPosition mapMatchedPosition;
    lane::LaneDirection laneDirection;
  };

  std::vector<TestResult> testResults;

  mMapMatching->addRouteHint(mRouteHint);
  for (auto headingHint : mHeadingHints)
  {
    mMapMatching->addHeadingHint(headingHint, ad::map::access::getENUReferencePoint());
  }

  auto mapMatchingResults = mMapMatching->getMapMatchedPositions(geo_point, searchDist, mMinProbabilty);

  for (auto mapMatchingResult : mapMatchingResults)
  {
    TestResult result;
    result.mapMatchedPosition = mapMatchingResult;
    result.laneDirection = lane::getLane(result.mapMatchedPosition.lane_point.para_point.lane_id).direction;
    testResults.push_back(result);
  }

  ASSERT_EQ(expectedNumberOfMatches, testResults.size()) << " compareMapMatching called from " << line << "\n";

  if ((mRouteHint.road_segments.size() > 0u) && (testResults.size() > 0u))
  {
    ASSERT_EQ(1u, mRouteHint.road_segments.size()) << " compareMapMatching called from " << line << "\n";
    ASSERT_EQ(1u, mRouteHint.road_segments[0].drivable_lane_segments.size())
      << " compareMapMatching called from " << line << "\n";
    ASSERT_LT(0u, testResults.size()) << " compareMapMatching called from " << line << "\n";
    ASSERT_EQ(mRouteHint.road_segments[0].drivable_lane_segments[0].lane_interval.lane_id,
              testResults[0].mapMatchedPosition.lane_point.para_point.lane_id)
      << " compareMapMatching called from " << line << "\n";
  }
}

TEST_F(AdMapMatchingTest, perform_map_matching_no_route_hints)
{
  for (auto testElement : mTestPoints)
  {
    compareMapMatching(__LINE__, testElement.first, testElement.second);
  }
}

TEST_F(AdMapMatchingTest, isLanePartOfRouteHints)
{
  addRouteHint();

  mMapMatching->addRouteHint(mRouteHint);

  EXPECT_TRUE(mMapMatching->isLanePartOfRouteHints(
    mRouteHint.road_segments.front().drivable_lane_segments.front().lane_interval.lane_id));
  EXPECT_FALSE(mMapMatching->isLanePartOfRouteHints(
    mRouteHint.road_segments.front().drivable_lane_segments.front().lane_interval.lane_id + lane::LaneId(1)));
}

TEST_F(AdMapMatchingTest, perform_map_matching_with_route_hints)
{
  addRouteHint();
  for (auto testElement : mTestPoints)
  {
    compareMapMatching(__LINE__, testElement.first, testElement.second);
  }
}

TEST_F(AdMapMatchingTest, perform_map_matching_with_heading_hints)
{
  mMinProbabilty = physics::Probability(0.05);
  mHeadingHints.push_back(point::createENUHeading(point::degree2radians(70)));
  for (auto testElement : mTestPoints)
  {
    compareMapMatching(__LINE__, testElement.first, testElement.second);
  }

  mHeadingHints.clear();
  mHeadingHints.push_back(point::createENUHeading(point::degree2radians(-110)));
  for (auto testElement : mTestPoints)
  {
    compareMapMatching(__LINE__, testElement.first, testElement.second);
  }
}

TEST_F(AdMapMatchingTest, laneOperation)
{
  addRouteHint();

  mMapMatching->addRouteHint(mRouteHint);
  auto hintPoint = point::createGeoPoint(point::Longitude(8.4401803), point::Latitude(49.0191987), point::Altitude(0.));
  MapMatchedPositionConfidenceList mapMatchingResults;
  EXECUTE_NO_LOG(mapMatchingResults = mMapMatching->findLanes(point::ECEFPoint(), physics::Distance(0.01)));
  ASSERT_EQ(mapMatchingResults.size(), 0u);
  mapMatchingResults = mMapMatching->findLanes(toECEF(hintPoint), physics::Distance());
  ASSERT_EQ(mapMatchingResults.size(), 0u);
  mapMatchingResults = mMapMatching->findLanes(toECEF(hintPoint), physics::Distance(0.01));
  ASSERT_EQ(mapMatchingResults.size(), 1u);
  ASSERT_NEAR(ad::map::lane::calcWidth(toENU(hintPoint)).mDistance, 3.0039, 0.0001);

  LaneOccupiedRegionList lane_occupied_regions;
  LaneOccupiedRegionList otherLaneOccupiedRegions;

  LaneOccupiedRegion region1, region2;
  region1.lane_id = map::lane::LaneId(10);
  physics::ParametricRange range;
  range.minimum = physics::ParametricValue(0.1);
  range.maximum = physics::ParametricValue(0.2);
  region1.longitudinal_range = range;
  range.maximum = physics::ParametricValue(0.3);
  region1.lateral_range = range;
  otherLaneOccupiedRegions.push_back(region1);
  mMapMatching->addLaneRegions(lane_occupied_regions, otherLaneOccupiedRegions);
  ASSERT_EQ(lane_occupied_regions[0].lateral_range, range);

  region2 = region1;
  range.maximum = physics::ParametricValue(0.4);
  region2.lateral_range = range;
  otherLaneOccupiedRegions.clear();
  otherLaneOccupiedRegions.push_back(region2);
  mMapMatching->addLaneRegions(lane_occupied_regions, otherLaneOccupiedRegions);
  ASSERT_EQ(lane_occupied_regions[0].lateral_range, range);
}
