// ----------------- BEGIN LICENSE BLOCK ---------------------------------
//
// Copyright (C) 2017-2020 Intel Corporation
//
// SPDX-License-Identifier: MIT
//
// ----------------- END LICENSE BLOCK -----------------------------------

#pragma once

#include <memory>
#include <unordered_map>
#include <unordered_set>

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wconversion"
#include <osmium/osm/types.hpp>
#pragma GCC diagnostic pop

#include "ad/map/maker/osm_converter/OsmJunctionArm.hpp"

namespace osmium {
class Node;
} // namespace osmium

namespace ad {
namespace map {
namespace maker {

namespace common {
struct LogChannel;
class LogFactory;
} // namespace common

namespace osm_converter {
struct OsmObjectStore;
class PointStore;

/**
 * @brief Extract all junctions from OSM data
 *
 * A junction is given for each node where at least three ways intersect. Since a way does not need to start/end
 * at a junction, a node where another way intersects is also treated as a junction, for example
 *
 *              ^ (way B)
 *              |
 * way A >------X----->
 *
 * Here, way B starts at node X out of way A. Thus X is treated as a junction. Same is true if way B would start
 * _below_ way A.
 *
 *              ^ (way B)
 *              |
 * way A >------X----->
 *              |
 *              ^ (way B)
 */
struct OsmJunctionProcessor
{
  OsmJunctionProcessor(common::LogFactory &logFactory, std::shared_ptr<OsmObjectStore> store);
  void setDefaultPriority(common::RightOfWay const rightOfWay);

  /*!
   * @brief iterator over all ways and extract junctions
   */
  void extractJunctions();

  bool isJunctionCenter(::osmium::object_id_type const nodeId) const;

  // It should return true if the given junction can be seen as a ramp.
  bool junctionHasRamp(::osmium::object_id_type const &idOfCenter) const;

  /*!
   * \brief Return unique id of successor of way
   * \param wayId
   * \param successor id of successor
   * \return true if a successor/predecessor exists
   *
   * Be aware that the returned wayId can be us if it is a closed way
   */
  bool uniqueSuccessorForWay(::osmium::object_id_type const wayId, ::osmium::object_id_type &successor) const;
  bool uniquePredecessorForWay(::osmium::object_id_type const wayId, ::osmium::object_id_type &predecessor) const;

  std::unordered_set<::osmium::object_id_type> allJunctions() const;
  std::unordered_set<OsmJunctionArm> junctionArms(::osmium::object_id_type const junctionCenter) const;

  void logJunction(::osmium::object_id_type const junctionCenter);

  OsmJunctionArm getOsmArm(::osmium::object_id_type centerNode, ::osmium::object_id_type entryNode) const;

  // return arm that represents the ramp of the given intersection
  OsmJunctionArm getRampForJunction(::osmium::object_id_type const idOfCenter) const;

private:
  /**
   * @brief mJunction
   *
   * Provide information about junction arms (key = center point, value = set of arms)
   * If an entry has more than 2 arms, it is a real junction
   */
  std::unordered_map<::osmium::object_id_type, std::unordered_set<OsmJunctionArm>> mJunctionArms;

  /**
   * @brief cached list of all known junction centers;
   */
  std::unordered_set<::osmium::object_id_type> mJunctionCenters;

  common::LogChannel &mLog;
  std::shared_ptr<OsmObjectStore> mStore;
  common::RightOfWay mDefaultPriority{common::RightOfWay::AllWayStop};

  bool armIsRamp(OsmJunctionArm const &) const;
  void compileListOfJunctionCenters();
  common::RightOfWay rowForArm(OsmJunctionArm const &arm) const;
  bool junctionIsOffRamp(::osmium::object_id_type const idOfCenter) const;

  void setRightOfWayRamp(::osmium::object_id_type const idOfCenter);
  void setRightOfWayNormalIntersection(::osmium::object_id_type const idOfCenter);
  bool setRightOfWayNormalIntersectionFirstPass(::osmium::object_id_type const idOfCenter,
                                                std::unordered_set<OsmJunctionArm> &arms) const;
  void setRightOfWayNormalIntersectionSecondPass(::osmium::object_id_type const idOfCenter,
                                                 bool const assignHasWay,
                                                 std::unordered_set<OsmJunctionArm> const &input,
                                                 std::unordered_set<OsmJunctionArm> &output) const;

  common::RightOfWay getRowDefinedByNode(OsmJunctionArm const &arm, ::osmium::Node const &node) const;
  void extractRightOfWay();
};

} // namespace osm_converter
} // namespace maker
} // namespace map
} // namespace ad
