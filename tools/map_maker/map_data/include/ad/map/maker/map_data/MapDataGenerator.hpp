// ----------------- BEGIN LICENSE BLOCK ---------------------------------
//
// Copyright (C) 2018-2020 Intel Corporation
//
// SPDX-License-Identifier: MIT
//
// ----------------- END LICENSE BLOCK -----------------------------------

#pragma once

#include "ad/map/maker/map_data/MapDataId.hpp"

namespace ad {
namespace map {
namespace maker {
namespace common {
struct MapGenerationConfig;
struct LogChannel;
class LogFactory;
} // namespace common

namespace map_data {
class MapDataStore;

/**
 * @brief Convert a basic skeleton map into real lanes and intersections
 *
 * Iterates over all intersections and roads and generates lanes from the
 * skeleton lines.
 */
class MapDataGenerator
{
public:
  MapDataGenerator(MapDataStore &dataStore, common::LogFactory &logFactory);

  /**
   * @brief generate map based on data given in MapDataStore
   * @param config parameters for generation
   *
   * Depending on the mode of operation (see common::MapGenerationLevel)
   * the method iterates over all roads and intersections and generates the
   * requested data.
   *
   * If mode is raw nothing will be done
   * If mode is skeleton it will only generate the structures inside intersections without generating any lanes
   * If mode is full, intersections are generated including internal lanes and also all lanes for all roads
   * outside intersections are generated.
   *
   * All data is put back into the MapDataStore.
   */
  void generateMap(common::MapGenerationConfig const &config);

private:
  MapDataStore &mStore;
  common::LogFactory &mLogFactory;
  common::LogChannel &mLog;

  double mDistanceToIntersectionCenter{8.}; //! either a config-option and/or derive from surrounding intersections
  double mBezierInterpolationSteps{1.};     //! granularity of interpolation
  bool mFullInterpolation{true};            //! generate full set of data?

  void generateIntersections();
  void generateLanes();
  void assignLaneRelations();
};

} // namespace map_data
} // namespace maker
} // namespace map
} // namespace ad
