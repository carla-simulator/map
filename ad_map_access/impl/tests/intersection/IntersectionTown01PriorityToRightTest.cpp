// ----------------- BEGIN LICENSE BLOCK ---------------------------------
//
// Copyright (C) 2018-2019 Intel Corporation
//
// SPDX-License-Identifier: MIT
//
// ----------------- END LICENSE BLOCK -----------------------------------

#include <ad/map/point/Operation.hpp>
#include "IntersectionPriorityToRightTests.hpp"
#include "MapSetup.hpp"

namespace ad {
namespace map {

struct IntersectionTown01WestToSouthTest : IntersectionPriorityToRightWestToSouthTest
{
  virtual point::GeoPoint getGeoFromSouth() const override
  {
    return point::createGeoPoint(point::Longitude(8.00490650359), point::Latitude(49.0000165612), point::Altitude(0));
  }

  virtual point::GeoPoint getGeoToSouth() const override
  {
    return point::createGeoPoint(point::Longitude(8.0048934219), point::Latitude(48.9999830507), point::Altitude(0));
  }

  virtual point::GeoPoint getGeoFromWest() const override
  {
    return point::createGeoPoint(point::Longitude(8.00462843722), point::Latitude(48.9997976038), point::Altitude(0));
  }

  virtual point::GeoPoint getGeoToWest() const override
  {
    return point::createGeoPoint(point::Longitude(8.0045717552), point::Latitude(48.9997433894), point::Altitude(0));
  }

  virtual point::GeoPoint getGeoFromNorth() const override
  {
    return point::createGeoPoint(point::Longitude(8.00424859652), point::Latitude(48.9999829343), point::Altitude(0));
  }

  virtual point::GeoPoint getGeoToNorth() const override
  {
    return point::createGeoPoint(point::Longitude(8.00423629191), point::Latitude(49.0000237813), point::Altitude(0));
  }

  virtual point::GeoPoint getGeoFromEast() const override
  {
    return point::GeoPoint();
  }

  virtual point::GeoPoint getGeoToEast() const override
  {
    return point::GeoPoint();
  }

  virtual lane::LaneIdSet expectedInternalLanesWithHigherPriority() const override
  {
    if (expectedIntersectionType() == intersection::IntersectionType::Unknown)
    {
      // since intersection type is unknown, the crossing lanes are taken as critical
      return expectedCrossingLanes();
    }
    else
    {
      return IntersectionPriorityToRightWestToSouthTest::expectedInternalLanesWithHigherPriority();
    }
  }

  virtual lane::LaneIdSet expectedIncomingLanesWithHigherPriority() const override
  {
    if (expectedIntersectionType() == intersection::IntersectionType::Unknown)
    {
      // since intersection type is unknown, the incoming lane from North (which crosses) has higher prio
      return createUnorderedLaneIdSet({mFromNorth});
    }
    else
    {
      return IntersectionPriorityToRightWestToSouthTest::expectedIncomingLanesWithHigherPriority();
    }
  }

  virtual lane::LaneIdSet expectedIncomingLanesWithLowerPriority() const override
  {
    if (expectedIntersectionType() == intersection::IntersectionType::Unknown)
    {
      // since intersection type is unknown, the incoming lane from South has lower prio since not crossing
      return createUnorderedLaneIdSet({mFromSouth});
    }
    else
    {
      return IntersectionPriorityToRightWestToSouthTest::expectedIncomingLanesWithLowerPriority();
    }
  }

  virtual lane::LaneIdSet expectedCrossingLanes() const override
  {
    // since there are four internal lanes within the intersection from north to south (510149, 510249, 510349, 510449)
    // the precalculated from the base class don't work here
    // we have to reduce to the lower half of the lanes
    return createUnorderedLaneIdSet({lane::LaneId(510349), lane::LaneId(510449)});
  }
};

struct IntersectionPrioRightTown01WestToSouthTest : public IntersectionTown01WestToSouthTest
{
  virtual void prepareMap() const override
  {
    ::map_setup::prepareMapTown01PrioRight();
  }
};

TEST_F(IntersectionPrioRightTown01WestToSouthTest, basic_checks)
{
  performBasicChecks();
}

struct IntersectionUnknownTown01WestToSouthTest : public IntersectionTown01WestToSouthTest
{
  virtual void prepareMap() const override
  {
    ::map_setup::prepareMapTown01Unknown();
  }

  virtual intersection::IntersectionType expectedIntersectionType() const override
  {
    // for the moment we have no correct intersection types yet from open drive
    return intersection::IntersectionType::Unknown;
  }
};

TEST_F(IntersectionUnknownTown01WestToSouthTest, basic_checks)
{
  performBasicChecks();
}

} // namespace map
} // namespace ad
