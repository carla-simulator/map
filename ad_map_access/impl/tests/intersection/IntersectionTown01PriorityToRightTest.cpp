// ----------------- BEGIN LICENSE BLOCK ---------------------------------
//
// Copyright (C) 2018-2020 Intel Corporation
//
// SPDX-License-Identifier: MIT
//
// ----------------- END LICENSE BLOCK -----------------------------------

#include <ad/map/point/Operation.hpp>
#include "IntersectionPriorityToRightTests.hpp"
#include "IntersectionTown01Test.hpp"
#include "MapSetup.hpp"

namespace ad {
namespace map {

struct IntersectionPrioRightTown01WestToSouthTest : IntersectionTown01WestToSouthTest,
                                                    IntersectionPriorityToRightWestToSouthTest
{
  virtual void prepareMap() const override
  {
    ::map_setup::prepareMapTown01PrioRight();
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

TEST_F(IntersectionPrioRightTown01WestToSouthTest, basic_checks)
{
  performBasicChecks();
}

} // namespace map
} // namespace ad
