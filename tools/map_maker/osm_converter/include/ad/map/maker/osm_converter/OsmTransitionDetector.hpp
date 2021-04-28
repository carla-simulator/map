// ----------------- BEGIN LICENSE BLOCK ---------------------------------
//
// Copyright (C) 2018-2020 Intel Corporation
//
// SPDX-License-Identifier: MIT
//
// ----------------- END LICENSE BLOCK -----------------------------------

#pragma once

#include <unordered_map>
#include <vector>

#include <ad/map/maker/map_data/IntersectionArm.hpp>
#include <ad/map/maker/map_data/MapDataId.hpp>
#include <ad/map/maker/map_data/MapDataStore.hpp>

namespace ad {
namespace map {
namespace maker {
namespace osm_converter {

struct RoadGeometry;

/**
 * @brief OsmTransitionDetector class
 *
 * This class analizes the geometrical properties of the roads connecting a osm junction
 * and derives rules for shifting the junction point for every connecting road.
 */
struct OsmTransitionDetector
{
  /**
   * @brief Triggers the generation of the intersection arms' offsets.
   * @param store the MapDataStore
   * @param roadsGeometry a list that contains the geometry of the intersection arms' roads
   * @param intersectionId the intersection to be analyzed
   */
  void generateTransitionOffsets(map_data::MapDataStore const &store,
                                 std::vector<RoadGeometry> const &roadsGeometry,
                                 map_data::MapDataId const intersectionId);

  /**
   * @brief Retrieve the offset for the given road.
   * @param roadId the intersection to be analyzed
   */
  double transitionOffsetForRoad(map_data::MapDataId roadId);

  /**
   * @brief Retrieve the angle of the offset direction for the given road.
   * The angle is valid only for intersections that contain roads of type Link.
   * @param roadId the intersection to be analyzed
   */
  double transitionOffsetAngleForRoad(map_data::MapDataId roadId);

private:
  std::vector<map_data::IntersectionArm> mArms; // local copy of the intersection's arms
  std::vector<RoadGeometry> mRoadsGeometry;     // local copy of the intersection's arms geometry
  std::unordered_map<map_data::MapDataId, double> mTransitionOffsetForRoad;
  std::unordered_map<map_data::MapDataId, double> mTransitionAngleForRoad;
  bool mGenerated{false}; // sets to true if the offsets are already available for use.

  bool setRoadsGeometry(std::vector<RoadGeometry> const &roadsGeometry);
  void calculateArmsOrientation();

  /**
   * @brief Applies a default offset calculation to every road.
   */
  void generateDefaultOffset(map_data::MapDataStore const &store);

  /**
   * @brief Checks if the junction is a 3-way T junction and generates the offset points accordingly.
   *
   */
  bool generateTJunctionOffset(map_data::MapDataStore const &store);

  /**
   * @brief Checks if the junction is a 3-way Y junction and generates the offset points accordingly.
   *
   */
  bool generateYJunctionOffset(map_data::MapDataStore const &store);

  /**
   * @brief Checks if the junction is an entry/exit ramp connection and generates the offset points accordingly.
   *
   * Applies a special offset to the link in the normal direction of the arm into which the link
   * is merging.
   */
  bool generateRampJunctionOffset(map_data::MapDataStore const &store);

  struct RampJunction
  {
    uint32_t rampArmIndex{0u};
    uint32_t mergingArmIndex{0u};
    uint32_t normalArmIndex{0u};
  };

  /**
   * @brief 3-way merge junction
   */
  struct MergeJunction
  {
    uint32_t leftArmIndex{0u};
    uint32_t rightArmIndex{0u};
    uint32_t mergingArmIndex{0u};
  };

  /**
   * @brief Check whether the current junction is of type Ramp.
   * @param store The MapDataStore
   * @param junction data struct to fill in with the junction parameters.
   * @return True if the junction is of type Ramp
   */
  bool isRampJunction(map_data::MapDataStore const &store, RampJunction &junction);

  /**
   * @brief Check whether the current junction is a 3-way merge junction.
   * @param store The MapDataStore
   * @param junction data struct to fill in with the junction parameters.
   * @return True if the junction is of type Merge
   */
  bool isMergeJunction(map_data::MapDataStore const &store, MergeJunction &junction);

  /**
   * @brief Check whether the current junction is a Y form junction.
   * @param store The MapDataStore
   * @param junction data struct to fill in with the junction parameters.
   * @return True if the junction is a Y form junction
   */
  bool isYJunction(map_data::MapDataStore const &store, MergeJunction &junction);

  /**
   * @brief Check whether the current junction is a T form junction.
   * @param store The MapDataStore
   * @param junction data struct to fill in with the junction parameters.
   * @return True if the junction is a T form junction
   */
  bool isTJunction(map_data::MapDataStore const &store, MergeJunction &junction);
};

} // namespace osm_converter
} // namespace maker
} // namespace map
} // namespace ad
