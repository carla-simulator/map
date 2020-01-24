// ----------------- BEGIN LICENSE BLOCK ---------------------------------
//
// Copyright (C) 2019-2020 Intel Corporation
//
// SPDX-License-Identifier: MIT
//
// ----------------- END LICENSE BLOCK -----------------------------------

#include <ad/map/access/Operation.hpp>
#include <ad/map/match/Operation.hpp>
#include <ad/map/route/Planning.hpp>
//#include "ad/map/route/RouteAStar.hpp"
//#include "ad/map/route/RouteOperation.hpp"
#include <gtest/gtest.h>
#include "ad/map/route/RoutePrediction.hpp"

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
    auto pois = access::getPointsOfInterest();
    ASSERT_GE(pois.size(), 1u);
    match::AdMapMatching mapMatching;
    auto mapMatchingResults
      = mapMatching.getMapMatchedPositions(pois.front().geoPoint, physics::Distance(1.), physics::Probability(0.8));

    ASSERT_GE(mapMatchingResults.size(), 1u);
    predictionStart.point = mapMatchingResults.front().lanePoint.paraPoint;
    predictionStart.direction = route::planning::RoutingDirection::POSITIVE;
  }

  virtual void TearDown()
  {
    access::cleanup();
  }

  virtual std::string getTestMap() = 0;

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
    return "test_files/Town03.adm.txt";
  }
};

TEST_F(RoutePredictionTestTown01, route_prediction_positive)
{
  auto routePredictions = route::planning::predictRoutesOnDistance(predictionStart, physics::Distance(10.));
  EXPECT_EQ(routePredictions.size(), 1u);

  routePredictions = route::planning::predictRoutesOnDistance(predictionStart, physics::Distance(500.));
  EXPECT_EQ(routePredictions.size(), 6u);
}

TEST_F(RoutePredictionTestTown01, route_prediction_dont_care)
{
  predictionStart.direction = route::planning::RoutingDirection::DONT_CARE;
  auto routePredictions = route::planning::predictRoutesOnDistance(predictionStart, physics::Distance(10.));
  EXPECT_EQ(routePredictions.size(), 1u);

  routePredictions = route::planning::predictRoutesOnDistance(predictionStart, physics::Distance(500.));
  EXPECT_EQ(routePredictions.size(), 6u);
}

TEST_F(RoutePredictionTestTown03, route_prediction_positive)
{
  auto routePredictions = route::planning::predictRoutesOnDistance(predictionStart, physics::Distance(10.));
  EXPECT_EQ(routePredictions.size(), 1u);

  routePredictions = route::planning::predictRoutesOnDistance(predictionStart, physics::Distance(500.));
  EXPECT_EQ(routePredictions.size(), 1u);
}

TEST_F(RoutePredictionTestTown03, route_prediction_dont_care)
{
  predictionStart.direction = route::planning::RoutingDirection::DONT_CARE;
  auto routePredictions = route::planning::predictRoutesOnDistance(predictionStart, physics::Distance(10.));
  EXPECT_EQ(routePredictions.size(), 2u);

  routePredictions = route::planning::predictRoutesOnDistance(predictionStart, physics::Distance(500.));
  EXPECT_EQ(routePredictions.size(), 38u);
}

TEST_F(RoutePredictionTestTown03, route_prediction_constructor)
{
  predictionStart.direction = route::planning::RoutingDirection::DONT_CARE;
  auto routePredictions = route::planning::predictRoutesOnDuration(predictionStart, physics::Duration(500.));
  ASSERT_EQ(routePredictions.size(), 167u);

  routePredictions = route::planning::predictRoutes(predictionStart, physics::Distance(500.), physics::Duration(500.));
  ASSERT_EQ(routePredictions.size(), 38u);
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

//@todo: create more meaningful test setups including some concrete situations
