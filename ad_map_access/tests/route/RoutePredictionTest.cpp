// ----------------- BEGIN LICENSE BLOCK ---------------------------------
//
// Copyright (C) 2019-2021 Intel Corporation
//
// SPDX-License-Identifier: MIT
//
// ----------------- END LICENSE BLOCK -----------------------------------

#include <ad/map/access/Logging.hpp>
#include <ad/map/access/Operation.hpp>
#include <ad/map/intersection/Intersection.hpp>
#include <ad/map/match/Operation.hpp>
#include <ad/map/route/Planning.hpp>
#include <ad/map/route/RoutePrediction.hpp>
#include <gtest/gtest.h>

using namespace ::ad;
using namespace map;
using namespace map::point;
using namespace map::route;
using namespace map::route::planning;

struct RoutePredictionTest : ::testing::Test
{
  RoutePredictionTest()
  {
  }

  virtual void SetUp()
  {
    access::cleanup();
    if (!access::init(getTestMap()))
    {
      throw std::runtime_error("Unable to initialize with " + getTestMap());
    }
    // access::getLogger()->set_level(spdlog::level::trace);

    getPredictionStartParaPoint(predictionStart.point);
    if (lane::isLaneDirectionPositive(lane::getLane(predictionStart.point.laneId)))
    {
      predictionStart.direction = route::planning::RoutingDirection::POSITIVE;
    }
    else
    {
      predictionStart.direction = route::planning::RoutingDirection::NEGATIVE;
    }
  }

  virtual void TearDown()
  {
    access::cleanup();
  }

  virtual std::string getTestMap() = 0;

  virtual void getPredictionStartParaPoint(point::ParaPoint &predictionStartResult)
  {
    auto predictionStartGeo = getPredictionStartGeo();
    ASSERT_TRUE(withinValidInputRange(predictionStartGeo));
    match::AdMapMatching mapMatching;
    auto mapMatchingResults
      = mapMatching.getMapMatchedPositions(predictionStartGeo, physics::Distance(1.), physics::Probability(0.8));

    ASSERT_GE(mapMatchingResults.size(), 1u);
    predictionStartResult = mapMatchingResults.front().lanePoint.paraPoint;
  }

  virtual point::GeoPoint getPredictionStartGeo()
  {
    point::GeoPoint resultPoint;
    auto pois = access::getPointsOfInterest();
    if (pois.size() > 0u)
    {
      resultPoint = pois.front().geoPoint;
    }
    return resultPoint;
  }

  route::planning::RoutingParaPoint predictionStart;
};

struct RoutePredictionTestTown01 : public RoutePredictionTest
{
  std::string getTestMap() override
  {
    return "test_files/Town01.txt";
  }
};

struct RoutePredictionTestTown03 : public RoutePredictionTest
{
  std::string getTestMap() override
  {
    return "test_files/Town03.txt";
  }
};

TEST_F(RoutePredictionTestTown01, route_prediction_positive)
{
  // remain in the same lane
  auto routePredictions = route::planning::predictRoutesOnDistance(predictionStart, physics::Distance(10.));
  ASSERT_EQ(routePredictions.size(), 1u);
  ASSERT_EQ(1u, routePredictions[0].roadSegments.size());
  point::ParaPoint expectedRouteEnd;
  expectedRouteEnd.laneId = predictionStart.point.laneId;
  expectedRouteEnd.parametricOffset = physics::ParametricValue(1.);
  auto findWaypointResult = route::findNearestWaypoint({expectedRouteEnd}, routePredictions[0]);
  EXPECT_TRUE(findWaypointResult.isValid());

  // the next crossing leads to a split of the route
  routePredictions = route::planning::predictRoutesOnDistance(predictionStart, physics::Distance(150.));
  EXPECT_EQ(routePredictions.size(), 2u);
}

TEST_F(RoutePredictionTestTown01, route_prediction_negative)
{
  // since standing with wrong orientation, no prediction is available
  predictionStart.direction = route::planning::RoutingDirection::NEGATIVE;
  auto routePredictions = route::planning::predictRoutesOnDistance(predictionStart, physics::Distance(10.));
  ASSERT_EQ(routePredictions.size(), 0u);

  // extending the search space doesn't help here
  routePredictions = route::planning::predictRoutesOnDistance(predictionStart, physics::Distance(150.));
  ASSERT_EQ(routePredictions.size(), 0u);
}

TEST_F(RoutePredictionTestTown01, route_prediction_dont_care)
{
  // not knowing the start direction leads to the same result as positive here
  predictionStart.direction = route::planning::RoutingDirection::DONT_CARE;
  auto routePredictions = route::planning::predictRoutesOnDistance(predictionStart, physics::Distance(10.));
  ASSERT_EQ(routePredictions.size(), 1u);
  ASSERT_EQ(1u, routePredictions[0].roadSegments.size());
  point::ParaPoint expectedRouteEnd;
  expectedRouteEnd.laneId = predictionStart.point.laneId;
  expectedRouteEnd.parametricOffset = physics::ParametricValue(1.);
  auto findWaypointResult = route::findNearestWaypoint({expectedRouteEnd}, routePredictions[0]);
  EXPECT_TRUE(findWaypointResult.isValid());

  // the next crossing leads to a split of the route
  routePredictions = route::planning::predictRoutesOnDistance(predictionStart, physics::Distance(150.));
  EXPECT_EQ(routePredictions.size(), 2u);
}

TEST_F(RoutePredictionTestTown01, route_prediction_directionless)
{
  // the directionless search allows to drive actually in both directions and change between lanes of different lane
  // direction
  auto routePredictions = route::planning::predictRoutesDirectionless(
    predictionStart.point, physics::Distance(10.), physics::Duration(100.));
  ASSERT_EQ(routePredictions.size(), 2u);
  ASSERT_EQ(1u, routePredictions[0].roadSegments.size());
  point::ParaPoint expectedRouteEnd;
  expectedRouteEnd.laneId = predictionStart.point.laneId;
  expectedRouteEnd.parametricOffset = physics::ParametricValue(1.);
  auto findWaypointResult0 = route::findNearestWaypoint({expectedRouteEnd}, routePredictions[0]);
  EXPECT_TRUE(findWaypointResult0.isValid());
  ASSERT_EQ(1u, routePredictions[1].roadSegments.size());
  expectedRouteEnd.parametricOffset = physics::ParametricValue(0.);
  auto findWaypointResult1 = route::findNearestWaypoint({expectedRouteEnd}, routePredictions[1]);
  EXPECT_TRUE(findWaypointResult1.isValid());

  // the next crossing leads to a split of the each of the routes
  routePredictions = route::planning::predictRoutesDirectionless(
    predictionStart.point, physics::Distance(150.), physics::Duration(100.));
  EXPECT_EQ(routePredictions.size(), 4u);
}

TEST_F(RoutePredictionTestTown01, route_prediction_relevant_lanes)
{
  // larger prediction distance to have two crossings and another split
  auto routePredictions = route::planning::predictRoutesOnDistance(predictionStart, physics::Distance(300.));
  ASSERT_EQ(routePredictions.size(), 3u);

  // now we restrict the prediction to the lanes of and around the first intersection
  ASSERT_GE(routePredictions[0].roadSegments.size(), 2u);
  auto intersectionLaneId = routePredictions[0].roadSegments[1].drivableLaneSegments[0].laneInterval.laneId;
  auto coreIntersection = intersection::CoreIntersection::getCoreIntersectionFor(intersectionLaneId);
  ASSERT_NE(coreIntersection, nullptr);
  auto relevantLanes = coreIntersection->internalLanes();
  relevantLanes.insert(coreIntersection->entryLanes().begin(), coreIntersection->entryLanes().end());
  relevantLanes.insert(coreIntersection->exitLanes().begin(), coreIntersection->exitLanes().end());

  routePredictions
    = route::planning::predictRoutesOnDistance(predictionStart,
                                               physics::Distance(300.),
                                               route::RouteCreationMode::SameDrivingDirection,
                                               route::planning::FilterDuplicatesMode::SubRoutesPreferLongerOnes,
                                               relevantLanes);
  // as a result the second intersection is not existing anymore and the predictions stop,
  // but the first intersection is still there, so one split is expected
  ASSERT_EQ(routePredictions.size(), 2u);
}

TEST_F(RoutePredictionTestTown03, route_prediction_positive)
{
  auto routePredictions = route::planning::predictRoutesOnDistance(predictionStart, physics::Distance(10.));
  EXPECT_EQ(routePredictions.size(), 1u);

  routePredictions = route::planning::predictRoutesOnDistance(predictionStart, physics::Distance(478.));
  EXPECT_EQ(routePredictions.size(), 18u);
}

TEST_F(RoutePredictionTestTown03, route_prediction_dont_care)
{
  predictionStart.direction = route::planning::RoutingDirection::DONT_CARE;
  auto routePredictions = route::planning::predictRoutesOnDistance(predictionStart, physics::Distance(10.));
  EXPECT_EQ(routePredictions.size(), 1u);

  routePredictions = route::planning::predictRoutesOnDistance(predictionStart, physics::Distance(478.));
  EXPECT_EQ(routePredictions.size(), 18u);
}

TEST_F(RoutePredictionTestTown03, route_prediction_constructor)
{
  predictionStart.direction = route::planning::RoutingDirection::DONT_CARE;
  auto routePredictions = route::planning::predictRoutesOnDuration(predictionStart, physics::Duration(1.));
  ASSERT_EQ(routePredictions.size(), 1u);

  routePredictions = route::planning::predictRoutes(predictionStart, physics::Distance(478.), physics::Duration(478.));
  ASSERT_EQ(routePredictions.size(), 18u);
}

TEST_F(RoutePredictionTestTown03, route_getBasicRoutes)
{
  predictionStart.direction = route::planning::RoutingDirection::DONT_CARE;
  map::route::planning::RoutePrediction routePrediction(predictionStart, physics::Distance(10.));
  if (routePrediction.calculate())
  {
    std::vector<Route::BasicRoute> res = routePrediction.getBasicRoutes();
  }
}

struct RoutePredictionTestIntersection : public RoutePredictionTestTown01
{
  point::GeoPoint getPredictionStartGeo() override
  {
    return point::createGeoPoint(point::Longitude(0.00079520), point::Latitude(-0.00284188), point::Altitude(0.));
  }
};

TEST_F(RoutePredictionTestIntersection, route_prediction_dont_stop_within_intersections)
{
  auto routePredictions = route::planning::predictRoutesOnDistance(predictionStart, physics::Distance(7.));
  EXPECT_EQ(routePredictions.size(), 2u);

  for (auto &routePrediction : routePredictions)
  {
    auto intersections = intersection::Intersection::getIntersectionsForRoute(routePrediction);
    ASSERT_EQ(1u, intersections.size());
  }
}

TEST_F(RoutePredictionTestIntersection, route_extension_dont_stop_within_intersections)
{
  auto routePredictions = route::planning::predictRoutesOnDistance(predictionStart, physics::Distance(1.));
  EXPECT_EQ(routePredictions.size(), 1u);

  route::FullRoute route = routePredictions.front();
  routePredictions.clear();

  EXPECT_TRUE(route::extendRouteToDistance(route, physics::Distance(7.), routePredictions));

  routePredictions.push_back(route);

  for (auto &routePrediction : routePredictions)
  {
    auto intersections = intersection::Intersection::getIntersectionsForRoute(routePrediction);
    ASSERT_EQ(1u, intersections.size());
  }
}

struct RoutePredictionTestRoundabout : public RoutePredictionTestTown03
{
  point::GeoPoint getPredictionStartGeo() override
  {
    return point::createGeoPoint(point::Longitude(0.00033117), point::Latitude(0.00007233), point::Altitude(0.));
  }
};

TEST_F(RoutePredictionTestRoundabout, route_prediction)
{
  auto routePredictions = route::planning::predictRoutesOnDistance(predictionStart, physics::Distance(130.));
  // starting at the east entry we get:
  // - to north
  // - to south
  // - circling just before out to east
  // the route towards the west is not present in the new map!
  EXPECT_EQ(routePredictions.size(), 3u);
}

struct RoutePredictionTestTown04 : public RoutePredictionTest
{
  void getPredictionStartParaPoint(point::ParaPoint &predictionStartResult) override
  {
    predictionStartResult.laneId = lane::LaneId(490148);
    predictionStartResult.parametricOffset = physics::ParametricValue(0.1);
  }

  std::string getTestMap() override
  {
    return "test_files/Town04.txt";
  }
};

TEST_F(RoutePredictionTestTown04, filter_duplicated_routes_multilane_not_algined)
{
  auto routePredictions
    = route::planning::predictRoutesOnDistance(predictionStart,
                                               physics::Distance(30),
                                               RouteCreationMode::SameDrivingDirection,
                                               planning::FilterDuplicatesMode::SubRoutesPreferShorterOnes);

  EXPECT_EQ(1u, routePredictions.size());
}
