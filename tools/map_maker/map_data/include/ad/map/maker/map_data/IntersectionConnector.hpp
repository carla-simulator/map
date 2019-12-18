// ----------------- BEGIN LICENSE BLOCK ---------------------------------
//
// Copyright (C) 2018-2019 Intel Corporation
//
// SPDX-License-Identifier: MIT
//
// ----------------- END LICENSE BLOCK -----------------------------------

#pragma once

#include <inttypes.h>
#include <unordered_map>
#include <vector>
#include "ad/map/maker/map_data/IntersectionArm.hpp"
#include "ad/map/maker/map_data/TurnConstraint.hpp"
#include "ad/map/maker/map_data/TurnDirection.hpp"

namespace ad {
namespace map {
namespace maker {
namespace map_data {
class MapDataStore;

/**
 * @brief Abstract representation of an intersection arm as a connection node.
 */
struct IntersectionNode
{
  uint32_t armId;
  uint32_t lanesIn;
  uint32_t lanesOut;
  double orientation;
  TurnConstraints turnConstraints;
};

/**
 * @brief Represents a connection between am inLane (start) and an outLane (end).
 */
struct IntersectionConnection
{
  uint32_t inArmId{0u};
  uint32_t inLaneId{0u};
  uint32_t outArmId{0u};
  uint32_t outLaneId{0u};
  TurnConstraint inTurnConstraint{TurnConstraint::None};
  LanePosition outLanePosition;
  double distance{0.0};

  bool operator<(IntersectionConnection const &other) const
  {
    if (inArmId != other.inArmId)
    {
      return inArmId < other.inArmId;
    }
    if (outArmId != other.outArmId)
    {
      return outArmId < other.outArmId;
    }
    if (inLaneId != other.inLaneId)
    {
      return inLaneId < other.inLaneId;
    }
    if (outLaneId != other.outLaneId)
    {
      return outLaneId < other.outLaneId;
    }
    return distance < other.distance;
  }
};

/**
 * @brief Returns true if the LanePosition contradicts the TurnConstraint.
 */
bool isConnectionForbidden(IntersectionConnection const &connection);

class IntersectionConnector
{
public:
  /**
   * @brief Generate arm information the given intersection arm.
   */
  void addArm(MapDataStore const &store, uint32_t armId, IntersectionArm const &arm);

  /**
   * @brief Add arm information explictly.
   */
  void addRawArm(
    uint32_t armId, uint32_t lanesIn, uint32_t lanesOut, double orientation, const TurnConstraints &turnConstraints);

  /**
   * @brief Iterates over all the added arms and generates connections for every lane pair.
   */
  void generateConnections(MapDataStore const &store);

  /**
   * @brief Inserts a new connection into the mIntersectionConnections vector.
   */
  IntersectionConnection
  generateConnection(uint32_t inArmId, uint32_t inLaneIndex, uint32_t outArmId, uint32_t outLaneIndex, double distance);

  /**
   * @brief Returns true if the number of inLanes match the number of outLanes
   */
  bool isConnectOneToOne();

  /**
   * @brief Keep one to one (human-logic) connections. (non optimized)
   * Assumes the arms are already ordered by (laneInIndex, laneOutIndex) and applies
   * a heuristic that keeps only the straightforward connections. i.e. the connections that would seem
   * obvious or logic for a human, by avoiding lane changes.
   */
  void keepOneToOneLogicConnections();

  /**
   * @brief Keeps only the closest connection for the set of (inArmId, outArmId, inLaneIndex) connections
   */
  void keepOnlyClosestIncomingConnections();

  /**
   * @brief Keeps only the closest connection for the set of (inArmId, outArmId, outLaneIndex) connections
   */
  void keepOnlyClosestOutgoingConnections();

  /**
   * @brief Calls keepOnlyClosestOutgoingConnections and keepOnlyClosestIncomingConnections, in this order.
   */
  void keepOnlyClosestConnections();

  /**
   * @brief Removes all the connections that contradict the turn constraint specified for the lane.
   */
  void removeForbiddenConnections();

  /**
   * @brief Removes all the connections that were categorized as UTurn.
   */
  void removeUTurns();

  /**
   * @brief Removes all the connections that were categorized as SharpLeft or SharpRight.
   */
  void removeSharpTurns();

  /**
   * @brief Removes all the connections that were categorized as SharpLeft or SharpRight.
   */
  const std::vector<IntersectionConnection> &intersectionConnections()
  {
    return mIntersectionConnections;
  }

private:
  std::vector<IntersectionConnection> mIntersectionConnections;         // The generated connections
  std::unordered_map<uint32_t, IntersectionNode> mIntersectionNodesMap; // All the lanes that can be connected
  std::unordered_map<uint32_t, IntersectionArm> mArms;                  // All the intersection arms

  /**
   * @brief Generate all possible connections between two intersection nodes, regardless if the connection is valid or
   * not.
   */
  void generateConnections(MapDataStore const &store, const IntersectionNode &nodeA, const IntersectionNode &nodeB);

  /**
   * @brief Calculate the distance between two lanes in the given intersection.
   */
  double distanceBetweenLanes(MapDataStore const &store,
                              const IntersectionNode &nodeA,
                              uint32_t laneA,
                              const IntersectionNode &nodeB,
                              uint32_t laneB);
};

} // namespace map_data
} // namespace maker
} // namespace map
} // namespace ad
