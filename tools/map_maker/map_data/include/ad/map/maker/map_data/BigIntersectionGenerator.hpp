// ----------------- BEGIN LICENSE BLOCK ---------------------------------
//
// Copyright (C) 2018-2019 Intel Corporation
//
// SPDX-License-Identifier: MIT
//
// ----------------- END LICENSE BLOCK -----------------------------------

#pragma once

#include <unordered_map>
#include <unordered_set>
#include <vector>
#include "ad/map/maker/map_data/MapDataElement.hpp"

namespace ad {
namespace map {
namespace maker {

namespace common {
class LogFactory;
} // namespace common

namespace map_data {
class MapDataStore;

/**
 * @brief Provides functionality for detect and generate big intersections.
 * A big intersection is a cluster of intersections which in the real world represent a single intersection.
 */
class BigIntersectionGenerator
{
public:
  BigIntersectionGenerator(MapDataStore &mapDataStore, common::LogFactory &logFactory);

  /**
   * @brief detect and generate the big intersections.
   */
  void generateBigIntersections(double interpolationStepSize, bool fullInterpolation);

private:
  MapDataStore &mStore;
  common::LogFactory &mLogFactory;

  static constexpr double mBigIntersectionSearchRadius = 25. * 25.; // in meters * meters

  /**
   * @brief Search the map data store for big intersections.
   */
  void detectBigIntersections(std::unordered_set<MapDataId> &intersections,
                              std::unordered_map<uint32_t, std::vector<MapDataId>> &bigIntersections);

  /**
   * @brief Returns true if the intersection(intersectionId) is of type IntersectionType::Ramp.
   */
  bool isRampIntersection(MapDataId const intersectionId) const;

  /**
   * @brief Count the number of one way arms in a given intersection.
   */
  uint64_t numberOfOneWayArms(MapDataId intersectionId);

  /**
   * @brief Count the number of service roads in a given intersection.
   */
  uint64_t numberOfNonServiceArms(MapDataId intersectionId);

  /**
   * @brief Generate a big intersection from a vector of intersection ids (cluster of intersections).
   */
  void
  generateBigIntersection(std::vector<MapDataId> intersectionIds, double interpolationStepSize, bool fullInterpolation);

  /**
   * @brief Returns a vector of intersection ids, these intersections are directly connected to the given intersection.
   * Direct connection means that there is only a single road that connects both intersections.
   */
  std::vector<MapDataId> connectedIntersections(MapDataId intersectionId);

  /**
   * @brief Calculates the square distance between two intersections.
   * The center of the intersections is used to calculate distance.
   */
  double squaredDistanceBetweenIntersections(MapDataId intersectionIdA, MapDataId intersectionIdB);

  /**
   * @brief Verifies a list of conditions to check if an intersection is a big intersection candidate.
   */
  bool isBigIntersectionCandidate(MapDataId intersectionId);

  /**
   * @brief Verifies a list of conditions to check if two intersections form in fact a big intersection.
   * The intersectionIdA must be a big intersection candidate.
   */
  bool formBigIntersection(MapDataId intersectionIdA, MapDataId intersectionIdB);
};

} // namespace map_data
} // namespace maker
} // namespace map
} // namespace ad
