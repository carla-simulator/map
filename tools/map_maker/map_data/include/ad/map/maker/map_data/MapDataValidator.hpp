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
class LogFactory;
struct LogChannel;
} // namespace common

namespace map_data {
class MapDataStore;

/**
 * @brief Collection of validation tasks to check consistenct of data in MapDataStore
 *
 * Currently only used in tests. But may be applied after generation later on.
 */
class MapDataValidator
{
public:
  MapDataValidator(MapDataStore const &dataStore, common::LogFactory &logFactory);

  /**
   * @brief Check connection between two roads
   *
   * Check that all borders (PolyLines) of all lanes share the same point. For each border
   * check that the first/last point of the first road is the same as the first/last point of the
   * second road.
   * If the number of lanes are different, it will not be reported as a failed check.
   *
   * @param firstId id of first road
   * @param useFrontOfFirst use the beginning (if true, end if false) of road (firstId) for comparison
   * @param secondId id of second road
   * @param useFrontOfSecond use the beginning (if true, end if false) of road (secondId) for comparison
   */
  bool validateRoadConnection(MapDataId firstId, bool useFrontOfFirst, MapDataId secondId, bool useFrontOfSecond);

  /**
   * @brief Check connection of two polylines
   *
   * Check if two given polylines share a node (its ID) at start/end, e.g.
   *
   * --a>-- X --b>--
   *
   * Two polylines a, b share the node with ID X (where X is the last node of a and the first node of b).
   *
   * @param firstLineId
   * @param useFrontOfFirst
   * @param secondLineId
   * @param useFrontOfSecond
   * @return true if connected correctly.
   *
   * Meaning of parameters is the same as in validateRoadConnection but applied for the given polyline
   */
  bool validatePolyLineConnection(MapDataId firstLineId,
                                  bool useFrontOfFirst,
                                  MapDataId secondLineId,
                                  bool useFrontOfSecond);

  /**
   * @brief check internal lanes of given intersection
   *
   * @param intersectionId id of intersection
   * @result true if valid data
   *
   * For each arm it checks if all lanes end/start with the same points
   */
  bool validateBordersOfIntersection(MapDataId intersectionId);

  bool validateLanesAtArm(MapDataId connectionPoint, MapDataId firstRoadId, MapDataId secondRoadId);

  /**
   * @brief Iterate over all the roads contained on the store and return the id of the closest road at the given
   * position.
   *
   * @param x position in X
   * @param y position in Y
   * @param useOnlyCenterLine if true the function uses only the center line of the road for the distance
   * estimation.
   * @return The id of the closest road.
   */
  MapDataId roadIdForPosition(double const x, double const y, bool const useOnlyCenterLine);

private:
  MapDataStore const &mStore;
  common::LogChannel &mLog;
};

} // namespace map_data
} // namespace maker
} // namespace map
} // namespace ad
