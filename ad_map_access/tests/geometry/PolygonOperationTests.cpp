// ----------------- BEGIN LICENSE BLOCK ---------------------------------
//
// Copyright (C) 2020-2021 Intel Corporation
//
// SPDX-License-Identifier: MIT
//
// ----------------- END LICENSE BLOCK -----------------------------------

#include <ad/geometry/Types.hpp>
#include <ad/map/access/Factory.hpp>
#include <ad/map/geometry/PolygonIntersection.hpp>
#include <ad/map/geometry/PolygonOperation.hpp>
#include <ad/map/lane/LaneOperation.hpp>
#include <ad/map/lane/Types.hpp>
#include <ad/map/point/Operation.hpp>
#include <gtest/gtest.h>

using namespace ::ad;
using namespace ::ad::map;
using namespace ::ad::map::point;
using namespace ::ad::map::lane;

struct PolygonOperationTest : ::testing::Test
{
  PolygonOperationTest()
  {
  }

  virtual void SetUp()
  {
  }
  virtual void TearDown()
  {
    access::cleanup();
  }
};

TEST_F(PolygonOperationTest, single_lane_polygon)
{
  ASSERT_TRUE(access::init("test_files/AllWayStop.adm.txt"));

  ::ad::geometry::Polygon freespacePolygon;
  boost::geometry::append(freespacePolygon, ::ad::geometry::toPoint(180.16539018209366, 417.8324574772755));
  boost::geometry::append(freespacePolygon, ::ad::geometry::toPoint(181.78642415799743, 417.832510324361));
  boost::geometry::append(freespacePolygon, ::ad::geometry::toPoint(182.18722824272578, 414.8140158168727));
  boost::geometry::append(freespacePolygon, ::ad::geometry::toPoint(180.0926335389743, 414.78625473853833));
  boost::geometry::append(freespacePolygon, ::ad::geometry::toPoint(179.7009872726901, 416.26780313835496));

  ::ad::map::point::ECEFPoint referencePoint;
  ::ad::map::point::GeoPoint referencePointGeo;
  ::ad::physics::Distance influenceDistance;

  referencePointGeo = point::createGeoPoint(point::Longitude(8.43748), point::Latitude(49.0187), point::Altitude(0.));
  referencePoint = point::toECEF(referencePointGeo);
  influenceDistance = ::ad::physics::Distance(100.0);
  auto const laneIntervals
    = ::ad::map::geometry::collectLanesWithinInfluenceDistance(referencePoint, influenceDistance);

  match::LaneOccupiedRegionList result_visible_regions;
  match::LaneOccupiedRegionList result_invisible_regions;
  result_visible_regions = ::ad::map::geometry::extractInnerRegions(freespacePolygon, laneIntervals);
  result_invisible_regions = ::ad::map::geometry::extractOuterRegions(freespacePolygon, laneIntervals);
  EXPECT_EQ(result_visible_regions.size(), 0u);
  EXPECT_EQ(result_invisible_regions.size(), 21u);
}

TEST_F(PolygonOperationTest, multiple_lane_polygon)
{
  ASSERT_TRUE(access::init("test_files/AllWayStop.adm.txt"));

  ::ad::geometry::Polygon freespacePolygon;
  boost::geometry::append(freespacePolygon, ::ad::geometry::toPoint(148.589552555018, 413.9115234717101));
  boost::geometry::append(freespacePolygon, ::ad::geometry::toPoint(153.44901787369662, 415.1946848890396));
  boost::geometry::append(freespacePolygon, ::ad::geometry::toPoint(152.37266218845107, 404.2667857720142));
  boost::geometry::append(freespacePolygon, ::ad::geometry::toPoint(147.0475911639091, 403.5145215992266));

  ::ad::map::point::ECEFPoint referencePoint;
  ::ad::map::point::GeoPoint referencePointGeo;
  ::ad::physics::Distance influenceDistance;

  referencePointGeo = point::createGeoPoint(point::Longitude(8.43748), point::Latitude(49.0187), point::Altitude(0.));
  referencePoint = point::toECEF(referencePointGeo);
  influenceDistance = ::ad::physics::Distance(100.0);
  auto const laneIntervals
    = ::ad::map::geometry::collectLanesWithinInfluenceDistance(referencePoint, influenceDistance);

  match::LaneOccupiedRegionList result_visible_regions;
  match::LaneOccupiedRegionList result_invisible_regions;
  result_visible_regions = ::ad::map::geometry::extractInnerRegions(freespacePolygon, laneIntervals);
  result_invisible_regions = ::ad::map::geometry::extractOuterRegions(freespacePolygon, laneIntervals);
  EXPECT_EQ(result_visible_regions.size(), 2u);
  EXPECT_EQ(result_invisible_regions.size(), 20u);
}
