// ----------------- BEGIN LICENSE BLOCK ---------------------------------
//
// Copyright (C) 2018-2019 Intel Corporation
//
// SPDX-License-Identifier: MIT
//
// ----------------- END LICENSE BLOCK -----------------------------------

#include "ad/map/maker/map_data/BigIntersectionGenerator.hpp"
#include <ad/map/maker/common/LogFactory.hpp>
#include "ad/map/maker/map_data/MapDataStore.hpp"

namespace ad {
namespace map {
namespace maker {
namespace map_data {

BigIntersectionGenerator::BigIntersectionGenerator(MapDataStore &mapDataStore, common::LogFactory &logFactory)
  : mStore(mapDataStore)
  , mLogFactory(logFactory)
{
}

void BigIntersectionGenerator::generateBigIntersection(std::vector<MapDataId> intersectionIds,
                                                       double interpolationStepSize,
                                                       bool fullInterpolation)
{
  for (auto const &intersectionId : intersectionIds)
  {
    Intersection &intersection = mStore.intersection(intersectionId);
    intersection.generateArmData(interpolationStepSize, fullInterpolation);
  }

  Intersection newIntersection(mStore, mLogFactory);
  newIntersection.mIntersectionType = IntersectionType::Complex;

  geometry::Point2d newCenter;
  for (auto const &intersectionId : intersectionIds)
  {
    newCenter += mStore.point(mStore.intersection(intersectionId).mCenterPointId);
    for (auto const &thisArm : mStore.intersection(intersectionId).mArms)
    {
      bool connectRoad = true;
      for (auto const &otherIntersectionId : intersectionIds)
      {
        if (otherIntersectionId != intersectionId)
        {
          for (auto const &otherArm : mStore.intersection(otherIntersectionId).mArms)
          {
            if (otherArm.connectedRoad == thisArm.connectedRoad)
            {
              connectRoad = false;
              mStore.deleteRoad(thisArm.connectedRoad);
            }
          }
        }
      }

      if (connectRoad)
      {
        newIntersection.mArms.push_back(thisArm);
      }
    }
  }
  for (auto const &intersectionId : intersectionIds)
  {
    mStore.deleteIntersection(intersectionId);
  }

  newCenter = newCenter * (1.0 / static_cast<double>(intersectionIds.size()));
  newIntersection.mCenterPointId = mStore.getOrCreateIdForPoint(newCenter);
  auto newIntersectionId = mStore.addIntersection(newIntersection);
  auto &bigIntersection = mStore.intersection(newIntersectionId);
  bigIntersection.generateInternalRoadsAndGeometry(interpolationStepSize, fullInterpolation);
}

void BigIntersectionGenerator::generateBigIntersections(double interpolationStepSize, bool fullInterpolation)
{
  std::unordered_set<MapDataId> specialIntersectionsSet;
  std::unordered_map<uint32_t, std::vector<MapDataId>> bigIntersectionsIdMap;
  detectBigIntersections(specialIntersectionsSet, bigIntersectionsIdMap);

  for (auto const bigIntersectionIds : bigIntersectionsIdMap)
  {
    generateBigIntersection(bigIntersectionIds.second, interpolationStepSize, fullInterpolation);
  }
}

std::vector<MapDataId> BigIntersectionGenerator::connectedIntersections(MapDataId intersectionId)
{
  std::vector<MapDataId> directlyConnectedIntersections;

  for (const auto &intersectionArm : mStore.intersection(intersectionId).mArms)
  {
    if (intersectionArm.connectedRoad != InvalidId)
    {
      MapDataId nextId;
      if (intersectionArm.isEntry)
      {
        nextId = mStore.road(intersectionArm.connectedRoad).mPredecessor;
      }
      else
      {
        nextId = mStore.road(intersectionArm.connectedRoad).mSuccessor;
      }
      if (mStore.hasIntersection(nextId) && intersectionId != nextId)
      {
        directlyConnectedIntersections.push_back(nextId);
      }
    }
  }

  return directlyConnectedIntersections;
}

double BigIntersectionGenerator::squaredDistanceBetweenIntersections(MapDataId intersectionIdA,
                                                                     MapDataId intersectionIdB)
{
  auto const &intersectionA = mStore.intersection(intersectionIdA);
  auto const &intersectionB = mStore.intersection(intersectionIdB);
  auto const &pointA = mStore.point(intersectionA.mCenterPointId);
  auto const &pointB = mStore.point(intersectionB.mCenterPointId);

  return pointA.squaredDistance(pointB);
}

bool BigIntersectionGenerator::formBigIntersection(MapDataId intersectionIdA, MapDataId intersectionIdB)
{
  if (isRampIntersection(intersectionIdB))
  {
    return false;
  }

  if (numberOfOneWayArms(intersectionIdB) < 2u)
  {
    return false;
  }

  if (squaredDistanceBetweenIntersections(intersectionIdA, intersectionIdB) > mBigIntersectionSearchRadius)
  {
    return false;
  }

  return true;
}

bool BigIntersectionGenerator::isRampIntersection(MapDataId const intersectionId) const
{
  return (mStore.intersection(intersectionId).mIntersectionType == IntersectionType::Ramp);
}

bool BigIntersectionGenerator::isBigIntersectionCandidate(MapDataId intersectionId)
{
  if (intersectionId == InvalidId)
  {
    return false;
  }

  if (isRampIntersection(intersectionId))
  {
    return false;
  }

  if (numberOfNonServiceArms(intersectionId) < 4u)
  {
    return false;
  }

  if (numberOfOneWayArms(intersectionId) < 2u)
  {
    return false;
  }

  return true;
}

void BigIntersectionGenerator::detectBigIntersections(
  std::unordered_set<MapDataId> &intersectionIds,
  std::unordered_map<uint32_t, std::vector<MapDataId>> &bigIntersections)
{
  uint32_t bigIntersectionId = 0u;
  std::unordered_map<MapDataId, uint32_t> bigIntersectionMap;
  bigIntersections.clear();
  intersectionIds.clear();

  for (const auto intersectionId : mStore.listOfIntersectionIds())
  {
    if (isBigIntersectionCandidate(intersectionId))
    {
      const auto directlyConnectedIntersections = connectedIntersections(intersectionId);
      for (const auto nextIntersectionId : directlyConnectedIntersections)
      {
        if (formBigIntersection(intersectionId, nextIntersectionId))
        {
          // The intersections are clustered, with cluster id <bigIntersectionId>
          // Before adding an intersection pair, we check if any of the two intersections is already in the map
          // In such case the same <bigIntersectionId> is given to the new intersection
          // (i.e. they are part of a big intersection already in the map)
          // If none of the intersections is on the map then the intersections form a new big intersection.
          if (bigIntersectionMap.count(intersectionId) > 0)
          {
            bigIntersectionMap[nextIntersectionId] = bigIntersectionMap[intersectionId];
          }
          else if (bigIntersectionMap.count(nextIntersectionId) > 0)
          {
            bigIntersectionMap[intersectionId] = bigIntersectionMap[nextIntersectionId];
          }
          else
          {
            ++bigIntersectionId;
            bigIntersectionMap[intersectionId] = bigIntersectionId;
            bigIntersectionMap[nextIntersectionId] = bigIntersectionId;
          }

          intersectionIds.insert(intersectionId);
          intersectionIds.insert(nextIntersectionId);
        }
      }
    }
  }

  for (const auto &element : bigIntersectionMap)
  {
    bigIntersections[element.second].push_back(element.first);
  }
}

uint64_t BigIntersectionGenerator::numberOfOneWayArms(MapDataId intersectionId)
{
  uint64_t numberOfArms = 0;
  for (const auto &arm : mStore.intersection(intersectionId).mArms)
  {
    const auto &road = mStore.road(arm.connectedRoad);
    if (road.mRoadType != RoadType::Service)
    {
      uint64_t nForwardLanes = road.mForwardWidths.size();
      uint64_t nBackwardLanes = road.mBackwardWidths.size();
      if (nForwardLanes == 0u && nBackwardLanes >= 1u)
      {
        ++numberOfArms;
      }
      else if (nBackwardLanes == 0u && nForwardLanes >= 1u)
      {
        ++numberOfArms;
      }
    }
  }
  return numberOfArms;
}

uint64_t BigIntersectionGenerator::numberOfNonServiceArms(MapDataId intersectionId)
{
  uint64_t numberOfArms = 0;
  for (const auto &arm : mStore.intersection(intersectionId).mArms)
  {
    const auto &road = mStore.road(arm.connectedRoad);
    if (road.mRoadType != RoadType::Service)
    {
      ++numberOfArms;
    }
  }
  return numberOfArms;
}

} // namespace map_data
} // namespace maker
} // namespace map
} // namespace ad
