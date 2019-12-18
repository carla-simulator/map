// ----------------- BEGIN LICENSE BLOCK ---------------------------------
//
// Copyright (C) 2018-2019 Intel Corporation
//
// SPDX-License-Identifier: MIT
//
// ----------------- END LICENSE BLOCK -----------------------------------

#include "ad/map/maker/map_data/MapDataStore.hpp"
#include <ad/map/maker/common/LogChannel.hpp>
#include <ad/map/maker/common/LogFactory.hpp>

namespace ad {
namespace map {
namespace maker {
namespace map_data {

MapDataStore::MapDataStore(common::LogFactory &logFactory)
  : mLog(logFactory.logChannel("MapDataStore"))
{
}

MapDataId MapDataStore::getOrCreateIdForPoint(geometry::Point2d const &point)
{
  auto found = mPointToId.find(point);
  if (found != mPointToId.end())
  {
    return found->second;
  }

  MapDataId id = getNextId();
  mPointToId[point] = id;
  mPointIds[id] = point;
  return id;
}

geometry::Point2d const &MapDataStore::point(MapDataId const id) const
{
  return mPointIds.at(id);
}

std::vector<MapDataId> MapDataStore::listOfPointIds() const
{
  std::vector<MapDataId> result;
  for (auto id : mPointIds)
  {
    result.push_back(id.first);
  }

  return result;
}

bool MapDataStore::hasPoint(MapDataId const id) const
{
  return (mPointIds.count(id) > 0);
}

MapDataId MapDataStore::createPolyLine()
{
  return addPolyLine(PolyLine());
}

MapDataId MapDataStore::addPolyLine(PolyLine const &element)
{
  auto nextId = getNextId();
  mPolyLines[nextId] = element;
  mPolyLines[nextId].mId = nextId;
  return nextId;
}

PolyLine const &MapDataStore::polyLine(MapDataId const id) const
{
  return mPolyLines.at(id);
}

PolyLine &MapDataStore::polyLine(MapDataId const id)
{
  return mPolyLines[id];
}

std::vector<MapDataId> MapDataStore::listOfPolyLineIds() const
{
  std::vector<MapDataId> result;
  for (auto id : mPolyLines)
  {
    result.push_back(id.first);
  }

  return result;
}

bool MapDataStore::hasPolyLine(MapDataId const id) const
{
  return (mPolyLines.count(id) > 0);
}

MapDataId MapDataStore::addLane(Lane const &element)
{
  auto nextId = getNextId();
  mLanes[nextId] = element;
  mLanes[nextId].mId = nextId;
  return nextId;
}

Lane const &MapDataStore::lane(MapDataId const id) const
{
  return mLanes.at(id);
}

Lane &MapDataStore::lane(MapDataId const id)
{
  return mLanes[id];
}

std::vector<MapDataId> MapDataStore::listOfLaneIds() const
{
  std::vector<MapDataId> result;
  for (auto id : mLanes)
  {
    result.push_back(id.first);
  }

  return result;
}

bool MapDataStore::hasLane(MapDataId const id) const
{
  return (mLanes.count(id) > 0);
}

void MapDataStore::deleteLane(MapDataId const id)
{
  if (hasLane(id))
  {
    mLanes.erase(id);
  }
}

MapDataId MapDataStore::createRoad(common::LogChannel &logChannel)
{
  Road road(*this, logChannel);
  return addRoad(road);
}

MapDataId MapDataStore::addRoad(Road const &element)
{
  auto nextId = getNextId();
  mRoads.insert({nextId, element});
  road(nextId).mId = nextId;
  return nextId;
}

Road const &MapDataStore::road(MapDataId const id) const
{
  return mRoads.at(id);
}

Road &MapDataStore::road(MapDataId const id)
{
  return mRoads.at(id);
}

std::vector<MapDataId> MapDataStore::listOfRoadIds() const
{
  std::vector<MapDataId> result;
  for (auto id : mRoads)
  {
    result.push_back(id.first);
  }

  return result;
}

bool MapDataStore::hasRoad(MapDataId const id) const
{
  return (mRoads.count(id) > 0);
}

void MapDataStore::deleteRoad(MapDataId const id)
{
  if (hasRoad(id))
  {
    for (const auto &laneId : mRoads.at(id).mForwardLanes)
    {
      deleteLane(laneId);
    }
    for (const auto &laneId : mRoads.at(id).mBackwardLanes)
    {
      deleteLane(laneId);
    }

    mRoads.erase(id);
  }
}

MapDataId MapDataStore::addIntersection(Intersection const &element)
{
  auto nextId = getNextId();
  mIntersections.insert({nextId, element});
  intersection(nextId).mId = nextId;
  return nextId;
}

Intersection const &MapDataStore::intersection(MapDataId const id) const
{
  return mIntersections.at(id);
}

Intersection &MapDataStore::intersection(MapDataId const id)
{
  return mIntersections.at(id);
}

std::vector<MapDataId> MapDataStore::listOfIntersectionIds() const
{
  std::vector<MapDataId> result;
  for (auto id : mIntersections)
  {
    result.push_back(id.first);
  }

  return result;
}

bool MapDataStore::hasIntersection(MapDataId const id) const
{
  return (mIntersections.count(id) > 0);
}

void MapDataStore::deleteIntersection(MapDataId const id)
{
  if (hasIntersection(id))
  {
    mIntersections.erase(id);
  }
}

MapDataId MapDataStore::getNextId()
{
  MapDataId result = mNextId;
  ++mNextId;
  return result;
}

MapDataId MapDataStore::addLandmark(Landmark const &element)
{
  auto nextId = getNextId();
  mLandmarks[nextId] = element;
  mLandmarks[nextId].mId = nextId;
  return nextId;
}

Landmark const &MapDataStore::landmark(MapDataId const id) const
{
  return mLandmarks.at(id);
}

Landmark &MapDataStore::landmark(MapDataId const id)
{
  return mLandmarks[id];
}

std::vector<MapDataId> MapDataStore::listOfLandmarkIds() const
{
  std::vector<MapDataId> result;
  for (auto id : mLandmarks)
  {
    result.push_back(id.first);
  }

  return result;
}

void MapDataStore::transformToGCS(geometry::CoordinateTransform const &transformer)
{
  mPointToId.clear();
  for (auto &pointEntry : mPointIds)
  {
    auto &p = pointEntry.second;
    transformer.metricToGcs(p.x, p.y, p.y, p.x); // Points are stored as (longitude, latitude)
    mPointToId[p] = pointEntry.first;
  }
}

void MapDataStore::setLeftHandTraffic()
{
  mUseLeftHandTraffic = true;
}

bool MapDataStore::isLeftHandTraffic() const
{
  return mUseLeftHandTraffic;
}

void MapDataStore::setPrioToRightAndStraight()
{
  mUsePrioToRightAndStraight = true;
}

bool MapDataStore::isPrioToRightAndStraight() const
{
  return mUsePrioToRightAndStraight;
}

} // namespace map_data
} // namespace maker
} // namespace map
} // namespace ad
