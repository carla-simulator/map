// ----------------- BEGIN LICENSE BLOCK ---------------------------------
//
// Copyright (C) 2017-2020 Intel Corporation
//
// SPDX-License-Identifier: MIT
//
// ----------------- END LICENSE BLOCK -----------------------------------

#pragma once

#include <memory>

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wconversion"
#include <osmium/osm/types.hpp>
#pragma GCC diagnostic pop

#include "ad/map/maker/osm_converter/OsmWayIterator.hpp"

namespace ad {
namespace map {
namespace maker {

namespace common {
struct LogChannel;
} // namespace common

namespace osm_converter {
struct OsmObjectStore;
struct OsmJunctionProcessor;
struct OsmJunctionArm;
class PointStore;

/**
 * @brief Provide traveler over nodes of way
 *
 * An iterator which _travels_ over ways from one OsmJunctionArm to another
 * (or a dead end). While travelling the travelled distance is recorded.
 *
 * Internally, the OsmWayTraveler makes use of an OsmWayIterator
 */
class OsmWayTraveler
{
public:
  /**
   * @brief setup way traveler
   *
   * @param store used for creating the internal OsmWayIterator
   * @param junctionProcessor used for creating the internal OsmWayIterator
   * @param pointStore used to calculate travelled distance
   * @param osmArm used for creating the internal OsmWayIterator
   * @param logging used for creating the internal OsmWayIterator
   *
   * This creates an OsmWayIterator and already applies a first call to stillTravelling.
   * As a consequence, previousNode() returns the start of the travel, currentNode()
   * gives the first node after the start.
   */
  OsmWayTraveler(std::shared_ptr<OsmObjectStore> store,
                 std::shared_ptr<OsmJunctionProcessor> junctionProcessor,
                 std::shared_ptr<PointStore> pointStore,
                 OsmJunctionArm const &osmArm,
                 common::LogChannel &logging);

  /**
   * @brief iterate to the next node
   *
   * @return true if travelling is still possible (no end of way no any junction reached)
   */
  bool stillTraveling();

  /** @return id of the current node */
  ::osmium::object_id_type currentNode() const;

  /** @return id of the previous node */
  ::osmium::object_id_type previousNode() const;

  /** @return id of the current way */
  ::osmium::object_id_type currentWay() const;

  /** @return id of the previous way */
  ::osmium::object_id_type previousWay() const;

  // @return if way id has changed since last node?
  bool wayHasChanged() const;

  /** @brief return so far travelled distance (the square of it) */
  double traveledDistance() const;

  /** @brief return total distance of the travel (only valid after the end was reached) */
  double totalDistance() const;

  /** @return true if last node was reached */
  bool endReached() const;

private:
  std::shared_ptr<PointStore> mPointStore;
  OsmWayIterator mIterator;
  ::osmium::object_id_type mPreviousNode;
  ::osmium::object_id_type mPreviousWay;
  bool mWayHasChanged{false};
  double mTraveledDistance{0.};
  double mTotalDistance{0.};
  bool mEndIsReached{false};

  double distanceFromPreviousToCurrent() const;
};

} // namespace osm_converter
} // namespace maker
} // namespace map
} // namespace ad
