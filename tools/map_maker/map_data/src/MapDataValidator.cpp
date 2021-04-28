// ----------------- BEGIN LICENSE BLOCK ---------------------------------
//
// Copyright (C) 2018-2019 Intel Corporation
//
// SPDX-License-Identifier: MIT
//
// ----------------- END LICENSE BLOCK -----------------------------------

#include "ad/map/maker/map_data/MapDataValidator.hpp"
#include <ad/map/maker/common/LogChannel.hpp>
#include <ad/map/maker/common/LogFactory.hpp>
#include <ad/map/maker/geometry/Point2d.hpp>
#include <limits>
#include "ad/map/maker/map_data/MapDataStore.hpp"
#include "ad/map/maker/map_data/PolyLineConversion.hpp"

namespace ad {
namespace map {
namespace maker {
namespace map_data {

MapDataValidator::MapDataValidator(MapDataStore const &dataStore, common::LogFactory &logFactory)
  : mStore(dataStore)
  , mLog(logFactory.logChannel("Validator"))
{
}

double distanceToRoad(MapDataStore const &dataStore,
                      MapDataId const roadId,
                      geometry::Point2d const &testPoint,
                      bool const useOnlyCenterLine)
{
  auto const &road = dataStore.road(roadId);
  geometry::Point2d pointOnRoad;
  if (useOnlyCenterLine)
  {
    auto const roadPolyLine = dataStore.polyLine(road.mCenterLineId);
    auto const centerLineGeometry = polylineToGeometry(dataStore, roadPolyLine);
    pointOnRoad = centerLineGeometry.findNearestPoint(testPoint);
  }
  else
  {
    pointOnRoad = road.findNearestPoint(testPoint);
  }

  return std::sqrt(testPoint.squaredDistance(pointOnRoad));
}

MapDataId MapDataValidator::roadIdForPosition(double const x, double const y, bool const useOnlyCenterLine)
{
  auto const roadIds = mStore.listOfRoadIds();
  geometry::Point2d const testPoint{x, y};
  auto closestRoadId = InvalidId;
  double minDistance = std::numeric_limits<double>::max();
  for (auto const roadId : roadIds)
  {
    double distance = distanceToRoad(mStore, roadId, testPoint, useOnlyCenterLine);
    if (distance < minDistance)
    {
      closestRoadId = roadId;
      minDistance = distance;
    }
  }

  return closestRoadId;
}

/*
 * Possibilities of road connections:
 * A>|B> --> firstId:A, useFrontOfFirst:false, secondId:B, useFrontOfSecond:true
 * <A|B> --> firstId:A, useFrontOfFirst:true,  secondId:B, useFrontOfSecond:true
 * A>|<B --> firstId:A, useFrontOfFirst:false, secondId:B, useFrontOfSecond:false
 * <A|<B --> firstId:A, useFrontOfFirst:true,  secondId:B, useFrontOfSecond:false
 */
bool MapDataValidator::validateRoadConnection(MapDataId firstId,
                                              bool useFrontOfFirst,
                                              MapDataId secondId,
                                              bool useFrontOfSecond)
{
  if (!mStore.hasRoad(firstId))
  {
    mLog(common::LogLevel::Info) << "First id " << firstId << " is not road!\n";
    return false;
  }
  if (!mStore.hasRoad(secondId))
  {
    mLog(common::LogLevel::Info) << "Second id " << secondId << " is not road!\n";
    return false;
  }

  auto const &firstRoad = mStore.road(firstId);
  if (!firstRoad.isValid())
  {
    mLog(common::LogLevel::Info) << "First road " << firstId << " is not valid road!\n";
    return false;
  }
  auto const &secondRoad = mStore.road(secondId);
  if (!secondRoad.isValid())
  {
    mLog(common::LogLevel::Info) << "Second road " << firstId << " is not valid road!\n";
    return false;
  }

  // validate center line
  if (!validatePolyLineConnection(firstRoad.mCenterLineId, useFrontOfFirst, secondRoad.mCenterLineId, useFrontOfSecond))
  {
    return false;
  }

  {
    // validate forward lanes
    auto numFirstForward = (useFrontOfFirst ? firstRoad.mBackwardLanes.size() : firstRoad.mForwardLanes.size());
    auto numSecondForward = (useFrontOfSecond ? secondRoad.mForwardLanes.size() : secondRoad.mBackwardLanes.size());
    auto numForwardLanes = std::min(numFirstForward, numSecondForward);

    for (uint32_t l = 0u; l < numForwardLanes; ++l)
    {
      auto firstBorderId
        = (useFrontOfFirst ? firstRoad.borderIdOfBackwardLane(l, true) : firstRoad.borderIdOfForwardLane(l, false));
      auto secondBorderId
        = (useFrontOfSecond ? secondRoad.borderIdOfForwardLane(l, false) : secondRoad.borderIdOfBackwardLane(l, true));
      if (!validatePolyLineConnection(firstBorderId, useFrontOfFirst, secondBorderId, useFrontOfSecond))
      {
        mLog(common::LogLevel::Info) << "Check failed for border of forward lane " << l << "\n";
        return false;
      }
    }
  }
  // validate backward lanes
  auto numFirstBackward = (useFrontOfFirst ? firstRoad.mForwardLanes.size() : firstRoad.mBackwardLanes.size());
  auto numSecondBackward = (useFrontOfSecond ? secondRoad.mBackwardLanes.size() : secondRoad.mForwardLanes.size());
  auto numBackwardLanes = std::min(numFirstBackward, numSecondBackward);

  for (uint32_t l = 0u; l < numBackwardLanes; ++l)
  {
    auto firstBorderId
      = (useFrontOfFirst ? firstRoad.borderIdOfForwardLane(l, false) : firstRoad.borderIdOfBackwardLane(l, true));
    auto secondBorderId
      = (useFrontOfSecond ? secondRoad.borderIdOfBackwardLane(l, true) : secondRoad.borderIdOfForwardLane(l, false));
    if (!validatePolyLineConnection(firstBorderId, useFrontOfFirst, secondBorderId, useFrontOfSecond))
    {
      mLog(common::LogLevel::Info) << "Check failed for border of backward lane " << l << "\n";
      return false;
    }
  }

  return true;
}

bool MapDataValidator::validatePolyLineConnection(MapDataId firstLineId,
                                                  bool useFrontOfFirst,
                                                  MapDataId secondLineId,
                                                  bool useFrontOfSecond)
{
  if (firstLineId == InvalidId)
  {
    mLog(common::LogLevel::Info) << "First polyline id is not valid!\n";
  }

  if (secondLineId == InvalidId)
  {
    mLog(common::LogLevel::Info) << "Second polyline id is not valid!\n";
  }
  auto const &firstLine = mStore.polyLine(firstLineId).mNodes;
  auto const &secondLine = mStore.polyLine(secondLineId).mNodes;

  auto const firstPointId = (useFrontOfFirst ? firstLine.front() : firstLine.back());
  auto const secondPointId = (useFrontOfSecond ? secondLine.front() : secondLine.back());

  std::string success = "success";
  if (firstPointId != secondPointId)
  {
    success = "failed";
  }
  mLog(common::LogLevel::Verbose) << "  comparePolyLine " << success << ": " << firstLineId << "/"
                                  << (useFrontOfFirst ? "front" : "back") << " - " << secondLineId << "/"
                                  << (useFrontOfSecond ? "front" : "back") << " --- points " << firstPointId << " vs "
                                  << secondPointId << "\n";
  return (firstPointId == secondPointId);
}

bool MapDataValidator::validateBordersOfIntersection(MapDataId intersectionId)
{
  if (!mStore.hasIntersection(intersectionId))
  {
    mLog(common::LogLevel::Info) << "Id " << intersectionId << " is not intersection!\n";
    return false;
  }

  /* TODO I think this is not correct, because we assume that all roads share the connection point of the arm
   * Can't it be that an internal road has an offset from the connection point? Example (a bit hard with ASCII art):
   * (See also Intersection::setupOrUpdateInternalRoad)
   *
   *      |
   *      /
   * X->-/
   * Y->-\
   *      \
   *       \
   *       |
   *
   * Where X, Y are the connection points.
   *
   * maybe create a set that collect all checked roads and compare afterwards against the
   * internal roads Intersection.mRoads if all were covered
   */
  auto const &intersection = mStore.intersection(intersectionId);
  if (intersection.mArms.empty())
  {
    mLog(common::LogLevel::Info) << "Intersection " << intersectionId << " has no arms!!\n";
    return true;
  }

  if (intersection.mRoads.empty())
  {
    mLog(common::LogLevel::Info) << "Intersection " << intersectionId << " has no no internal roads!!\n";
    return true;
  }

  for (auto const &arm : intersection.mArms)
  {
    MapDataId armPoint = arm.connectionPoint;
    mLog(common::LogLevel::Verbose) << "Arm with id of connection point " << armPoint << "\n";
    for (uint32_t s = 0u; s < intersection.mRoads.size() - 1u; ++s)
    {
      MapDataId startRoad = intersection.mRoads.at(s);
      auto const &startLine = mStore.polyLine(mStore.road(startRoad).mCenterLineId).mNodes;
      mLog(common::LogLevel::Verbose) << " first road " << startRoad << " (" << mStore.road(startRoad).mCenterLineId
                                      << ")";
      if ((armPoint == startLine.front()) || (armPoint == startLine.back()))
      {
        mLog << " used\n";
        for (uint32_t e = s + 1u; e < intersection.mRoads.size(); ++e)
        {
          MapDataId endRoad = intersection.mRoads.at(e);
          auto const &endLine = mStore.polyLine(mStore.road(endRoad).mCenterLineId).mNodes;
          mLog(common::LogLevel::Verbose)
            << " second road " << endRoad << " (" << mStore.road(endRoad).mCenterLineId << ")";
          if ((armPoint == endLine.front()) || (armPoint == endLine.back()))
          {
            mLog << " used\n";
            if (!validateLanesAtArm(armPoint, startRoad, endRoad))
            {
              return false;
            }
          }
          else
          {
            mLog << " skipped\n";
          }
        }
      }
      else
      {
        mLog << " skipped\n";
      }
    }
  }

  return true;
}

bool MapDataValidator::validateLanesAtArm(MapDataId connectionPoint, MapDataId firstRoadId, MapDataId secondRoadId)
{
  auto const &firstRoad = mStore.road(firstRoadId);
  auto const &secondRoad = mStore.road(secondRoadId);

  auto const &firstLine = mStore.polyLine(firstRoad.mCenterLineId).mNodes;
  auto const &secondLine = mStore.polyLine(secondRoad.mCenterLineId).mNodes;
  bool firstStartsHere = (connectionPoint == firstLine.front());
  bool secondStartsHere = (connectionPoint == secondLine.front());

  // center line first
  mLog(common::LogLevel::Verbose) << "  arm: centerline\n";
  if (!validatePolyLineConnection(firstRoad.mCenterLineId, firstStartsHere, secondRoad.mCenterLineId, secondStartsHere))
  {
    return false;
  }
  // both starting or ending here, so compare forward of first with forward of second, ...
  if (firstStartsHere == secondStartsHere)
  {
    mLog(common::LogLevel::Verbose) << "  arm: same start/end (forward)\n";
    uint64_t numForward = std::min(firstRoad.mForwardLanes.size(), secondRoad.mForwardLanes.size());
    for (uint64_t i = 0u; i < numForward; ++i)
    {
      MapDataId firstBorder = firstRoad.borderIdOfForwardLane(i, false);
      MapDataId secondBorder = secondRoad.borderIdOfForwardLane(i, false);
      if (!validatePolyLineConnection(firstBorder, firstStartsHere, secondBorder, secondStartsHere))
      {
        return false;
      }
    }

    mLog(common::LogLevel::Verbose) << "  arm: same start/end (backward)\n";
    uint64_t numBackward = std::min(firstRoad.mBackwardLanes.size(), secondRoad.mBackwardLanes.size());
    for (uint32_t i = 0u; i < numBackward; ++i)
    {
      MapDataId firstBorder = firstRoad.borderIdOfBackwardLane(i, false);
      MapDataId secondBorder = secondRoad.borderIdOfBackwardLane(i, false);
      if (!validatePolyLineConnection(firstBorder, firstStartsHere, secondBorder, secondStartsHere))
      {
        return false;
      }
    }
  }
  else if (firstStartsHere && !secondStartsHere)
  {
    mLog(common::LogLevel::Verbose) << "  arm: first start, second end (forward)\n";
    uint64_t numForward = std::min(firstRoad.mForwardLanes.size(), secondRoad.mBackwardLanes.size());
    for (uint64_t i = 0u; i < numForward; ++i)
    {
      MapDataId firstBorder = firstRoad.borderIdOfForwardLane(i, false);
      MapDataId secondBorder = secondRoad.borderIdOfBackwardLane(i, true);
      if (!validatePolyLineConnection(firstBorder, firstStartsHere, secondBorder, secondStartsHere))
      {
        return false;
      }
    }

    mLog(common::LogLevel::Verbose) << "  arm: first start, second end (backward)\n";
    uint64_t numBackward = std::min(firstRoad.mBackwardLanes.size(), secondRoad.mForwardLanes.size());
    for (uint32_t i = 0u; i < numBackward; ++i)
    {
      MapDataId firstBorder = firstRoad.borderIdOfBackwardLane(i, true);
      MapDataId secondBorder = secondRoad.borderIdOfForwardLane(i, false);
      if (!validatePolyLineConnection(firstBorder, firstStartsHere, secondBorder, secondStartsHere))
      {
        return false;
      }
    }
  }
  else
  {
    mLog(common::LogLevel::Verbose) << "  arm: first end, second start (forward)\n";
    uint64_t numForward = std::min(firstRoad.mBackwardLanes.size(), secondRoad.mForwardLanes.size());
    for (uint32_t i = 0u; i < numForward; ++i)
    {
      MapDataId firstBorder = firstRoad.borderIdOfBackwardLane(i, true);
      MapDataId secondBorder = secondRoad.borderIdOfForwardLane(i, false);
      if (!validatePolyLineConnection(firstBorder, firstStartsHere, secondBorder, secondStartsHere))
      {
        return false;
      }
    }

    mLog(common::LogLevel::Verbose) << "  arm: first end, second start (backward)\n";
    uint64_t numBackward = std::min(firstRoad.mForwardLanes.size(), secondRoad.mBackwardLanes.size());
    for (uint32_t i = 0u; i < numBackward; ++i)
    {
      MapDataId firstBorder = firstRoad.borderIdOfForwardLane(i, false);
      MapDataId secondBorder = secondRoad.borderIdOfBackwardLane(i, true);
      if (!validatePolyLineConnection(firstBorder, firstStartsHere, secondBorder, secondStartsHere))
      {
        return false;
      }
    }
  }

  return true;
}

} // namespace map_data
} // namespace maker
} // namespace map
} // namespace ad
