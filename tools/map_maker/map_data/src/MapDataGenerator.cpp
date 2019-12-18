// ----------------- BEGIN LICENSE BLOCK ---------------------------------
//
// Copyright (C) 2018-2019 Intel Corporation
//
// SPDX-License-Identifier: MIT
//
// ----------------- END LICENSE BLOCK -----------------------------------

#include "ad/map/maker/map_data/MapDataGenerator.hpp"
#include <ad/map/maker/common/LogChannel.hpp>
#include <ad/map/maker/common/LogFactory.hpp>
#include <ad/map/maker/common/MapGenerationConfig.hpp>
#include <boost/functional/hash.hpp>
#include <unordered_set>
#include "ad/map/maker/map_data/BigIntersectionGenerator.hpp"
#include "ad/map/maker/map_data/MapDataStore.hpp"

namespace ad {
namespace map {
namespace maker {
namespace map_data {

MapDataGenerator::MapDataGenerator(MapDataStore &dataStore, common::LogFactory &logFactory)
  : mStore(dataStore)
  , mLogFactory(logFactory)
  , mLog(logFactory.logChannel("MapDataGenerator"))
{
}
void MapDataGenerator::generateIntersections()
{
  auto bigIntersectionGenerator = BigIntersectionGenerator(mStore, mLogFactory);
  bigIntersectionGenerator.generateBigIntersections(mBezierInterpolationSteps, mFullInterpolation);

  for (auto const id : mStore.listOfIntersectionIds())
  {
    Intersection &intersection = mStore.intersection(id);
    if (intersection.mIntersectionType != IntersectionType::Complex)
    {
      intersection.generateInnerData(mBezierInterpolationSteps, mFullInterpolation);
    }
  }
}

void MapDataGenerator::generateLanes()
{
  for (auto const id : mStore.listOfRoadIds())
  {
    Road &road = mStore.road(id);
    road.generateLanes();
  }
}

void MapDataGenerator::assignLaneRelations()
{
  for (auto const id : mStore.listOfRoadIds())
  {
    Road &road = mStore.road(id);
    road.assignSuccPredLaneNeighbors();
  }
}

void MapDataGenerator::generateMap(common::MapGenerationConfig const &config)
{
  mDistanceToIntersectionCenter = config.defaultIntersectionRadius;
  mBezierInterpolationSteps = config.interpolationStepsBezier;
  mFullInterpolation = (config.generationLevel == common::MapGenerationLevel::Full);

  if (config.interpolateRawRoads)
  {
    // to be implemented: iterate over all polylines/roads and do cubic spline interpolation
  }

  if (mFullInterpolation || (config.generationLevel == common::MapGenerationLevel::Skeleton))
  {
    generateIntersections();
  }

  if (mFullInterpolation)
  {
    generateLanes();
    assignLaneRelations();
  }

  if (mStore.isLeftHandTraffic())
  {
    for (auto roadId : mStore.listOfRoadIds())
    {
      Road &road = mStore.road(roadId);
      road.convertToLeftHandTraffic();
    }
  }
}

} // namespace map_data
} // namespace maker
} // namespace map
} // namespace ad
