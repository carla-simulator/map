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

/**
 * @brief Provide iterator over nodes of way
 *
 * Iterator over the nodes of a way. If the last point of a way is reached and
 * there is only one successor the iterator will _jump_ to the next way.
 */
class OsmWayIterator
{
public:
  /**
   * @brief create an iterator for the given OsmJunctionArm
   *
   * Throws an exception if the data in the OsmJunctionArm does not allow to create
   * a valid iterator.
   *
   * The created iterator positions itself already in a way such that the user
   * can directly start to iterate.
   * If the OsmJunctionArm describes an incoming entry, the iterator rewinds to the
   * previous junction (or the start of the way). If it's an outgoing arm, the iterator
   * starts at the given center of intersection.
   */
  static OsmWayIterator setupWayIteratorForJunctionArm(std::shared_ptr<OsmObjectStore> store,
                                                       std::shared_ptr<OsmJunctionProcessor> junctionProcessor,
                                                       OsmJunctionArm const &osmArm,
                                                       common::LogChannel &logging);

  OsmWayIterator(std::shared_ptr<OsmObjectStore> store,
                 std::shared_ptr<OsmJunctionProcessor> junctionProcessor,
                 ::osmium::object_id_type const wayId,
                 size_t const indexInNodeList,
                 common::LogChannel &logging);

  bool isValid() const;

  /** return id of the current way */
  ::osmium::object_id_type currentWay() const;

  /** return id of the current node */
  ::osmium::object_id_type currentNode() const;

  /**
   * @brief Move on to the next element
   *
   * currentNode, currentWay will be updated accordingly
   *
   * @return true if successful, false if we are already at the last node of the segment
   *         (either there is no unique successor or there is no successor at all)
   */
  bool next();

  /**
   * @brief Go back to the previous element
   *
   * currentNode, currentWay will be updated accordingly
   *
   * @return true if successful, false if we are already at the first node of the segment
   *         (either there is no unique predecessor or there is no predecessor at all)
   */
  bool prev();

  /**
   * @brief Go back to the beginning of the way
   *
   * Iterate back until there is a dead end or there is a junction
   * currentNode, currentWay will be updated accordingly
   *
   * If the current way is a closed polygon, rewind will continue iterating
   * until it hits an intersection or all nodes are processed.
   */
  void rewind();

private:
  void extractNodeAndValidateIndex();
  std::shared_ptr<OsmObjectStore> mStore;
  std::shared_ptr<OsmJunctionProcessor> mJunctionProcessor;

  ::osmium::object_id_type mWay;
  ::osmium::object_id_type mCurrentNode;

  std::size_t mIndex{0}; // index in array of nodes
  bool mIsValid{false};
  common::LogChannel &mLog;
};

} // namespace osm_converter
} // namespace maker
} // namespace map
} // namespace ad
