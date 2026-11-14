// ----------------- BEGIN LICENSE BLOCK ---------------------------------
//
// Copyright (C) 2018-2020 Intel Corporation
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
  int64_t const gx = static_cast<int64_t>(std::llround(point.x * cPointGridScale));
  int64_t const gy = static_cast<int64_t>(std::llround(point.y * cPointGridScale));

  for (int64_t dx = -1; dx <= 1; ++dx)
  {
    for (int64_t dy = -1; dy <= 1; ++dy)
    {
      auto const cellIt = mPointGrid.find(PointGridKey{gx + dx, gy + dy});
      if (cellIt != mPointGrid.end())
      {
        for (MapDataId const candidateId : cellIt->second)
        {
          if (point.squaredDistance(mPointIds.at(candidateId)) < cPointCompareSquaredEpsilon)
          {
            return candidateId;
          }
        }
      }
    }
  }

  MapDataId const id = getNextId();
  mPointIds[id] = point;
  mPointGrid[PointGridKey{gx, gy}].push_back(id);
  return id;
}

geometry::Point2d const &MapDataStore::point(MapDataId const id) const
{
  return mPointIds.at(id);
}

std::vector<MapDataId> MapDataStore::listOfPointIds() const
{
  std::vector<MapDataId> result;
  result.reserve(mPointIds.size());
  for (auto const &id : mPointIds)
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
  return mPolyLines.at(id);
}

std::vector<MapDataId> MapDataStore::listOfPolyLineIds() const
{
  std::vector<MapDataId> result;
  result.reserve(mPolyLines.size());
  for (auto const &id : mPolyLines)
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
  return mLanes.at(id);
}

std::vector<MapDataId> MapDataStore::listOfLaneIds() const
{
  std::vector<MapDataId> result;
  result.reserve(mLanes.size());
  for (auto const &id : mLanes)
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
  result.reserve(mRoads.size());
  for (auto const &id : mRoads)
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
    for (const auto &lane_id : mRoads.at(id).mForwardLanes)
    {
      deleteLane(lane_id);
    }
    for (const auto &lane_id : mRoads.at(id).mBackwardLanes)
    {
      deleteLane(lane_id);
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
  result.reserve(mIntersections.size());
  for (auto const &id : mIntersections)
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
  return mLandmarks.at(id);
}

std::vector<MapDataId> MapDataStore::listOfLandmarkIds() const
{
  std::vector<MapDataId> result;
  result.reserve(mLandmarks.size());
  for (auto const &id : mLandmarks)
  {
    result.push_back(id.first);
  }

  return result;
}

void MapDataStore::transformToGCS(geometry::CoordinateTransform const &transformer)
{
  mPointGrid.clear();
  for (auto &pointEntry : mPointIds)
  {
    auto &p = pointEntry.second;
    double lat = 0.;
    double lon = 0.;
    transformer.metricToGcs(p.x, p.y, lat, lon); // Points are stored as (longitude, latitude)
    p.x = lon;
    p.y = lat;
    int64_t const gx = static_cast<int64_t>(std::llround(p.x * cPointGridScale));
    int64_t const gy = static_cast<int64_t>(std::llround(p.y * cPointGridScale));
    mPointGrid[PointGridKey{gx, gy}].push_back(pointEntry.first);
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
