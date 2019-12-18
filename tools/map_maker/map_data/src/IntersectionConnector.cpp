// ----------------- BEGIN LICENSE BLOCK ---------------------------------
//
// Copyright (C) 2018-2019 Intel Corporation
//
// SPDX-License-Identifier: MIT
//
// ----------------- END LICENSE BLOCK -----------------------------------

#include "ad/map/maker/map_data/IntersectionConnector.hpp"
#include <ad/map/maker/geometry/Direction2d.hpp>
#include <algorithm>
#include "ad/map/maker/map_data/MapDataStore.hpp"
#include "ad/map/maker/map_data/Road.hpp"

namespace ad {
namespace map {
namespace maker {
namespace map_data {

void IntersectionConnector::addArm(MapDataStore const &store, uint32_t armId, IntersectionArm const &arm)
{
  auto const &road = store.road(arm.connectedRoad);
  uint32_t lanesIn = 0u;
  uint32_t lanesOut = 0u;
  std::vector<TurnDirections> turnDirectionsVector;
  if (arm.isEntry)
  {
    lanesIn = static_cast<uint32_t>(road.mForwardWidths.size());
    lanesOut = static_cast<uint32_t>(road.mBackwardWidths.size());
    turnDirectionsVector = road.mForwardTurnDirections; //! Turn direction restrictions
  }
  else
  {
    lanesIn = static_cast<uint32_t>(road.mBackwardWidths.size());
    lanesOut = static_cast<uint32_t>(road.mForwardWidths.size());
    turnDirectionsVector = road.mBackwardTurnDirections; //! Turn direction restrictions
  }

  TurnConstraints constraints;
  if (turnDirectionsVector.size() >= lanesIn) // Bike lanes also have turn lane information
  {
    for (uint32_t i = 0u; i < lanesIn; ++i)
    {
      constraints.push_back(turnDirectionsToTurnConstraint(turnDirectionsVector[i]));
    }
  }
  else
  {
    for (uint32_t i = 0u; i < lanesIn; ++i)
    {
      constraints.push_back(TurnConstraint::None);
    }
  }

  double orientation = arm.orientation;

  bool useReliableArmOrientations{false}; // @TODO: Make it a parameter?
  if (useReliableArmOrientations)
  {
    // Recalculate all arm orientations to eliminate false front lane positions for ramps.
    if (store.hasRoad(arm.connectedRoad))
    {
      const auto &road = store.road(arm.connectedRoad);
      if (store.hasPolyLine(road.mCenterLineId))
      {
        auto const &polyLine = store.polyLine(road.mCenterLineId);
        if (polyLine.mNodes.size() > 2u)
        {
          geometry::Point2d connPoint;
          geometry::Point2d roadPoint;
          if (arm.isEntry)
          {
            connPoint = store.point(polyLine.mNodes[polyLine.mNodes.size() - 1]);
            roadPoint = store.point(polyLine.mNodes[polyLine.mNodes.size() - 3]);
          }
          else
          {
            connPoint = store.point(polyLine.mNodes[0]);
            roadPoint = store.point(polyLine.mNodes[2]);
          }
          geometry::Direction2d dir(connPoint, roadPoint);
          orientation = dir.orientation;
        }
      }
    }
  }

  mArms[armId] = arm;
  addRawArm(armId, lanesIn, lanesOut, orientation, constraints);
}

void IntersectionConnector::addRawArm(
  uint32_t armId, uint32_t lanesIn, uint32_t lanesOut, double orientation, const TurnConstraints &turnConstraints)
{
  IntersectionNode node;
  node.armId = armId;
  node.lanesIn = lanesIn;
  node.lanesOut = lanesOut;
  node.orientation = orientation;
  node.turnConstraints = turnConstraints;
  mIntersectionNodesMap[armId] = node;
}

bool findArmConnection(const std::vector<IntersectionConnection> &connections,
                       uint32_t inArmId,
                       uint32_t outArmId,
                       uint32_t &id)
{
  for (uint32_t i = 0; i < connections.size(); ++i)
  {
    if (connections[i].inArmId == inArmId && connections[i].outArmId == outArmId)
    {
      id = i;
      return true;
    }
  }
  return false;
}

bool findIncomingConnection(const std::vector<IntersectionConnection> &connections,
                            uint32_t inArmId,
                            uint32_t outArmId,
                            uint32_t laneIndex,
                            uint32_t &id)
{
  for (uint32_t i = 0; i < connections.size(); ++i)
  {
    if (connections[i].inArmId == inArmId && connections[i].outArmId == outArmId
        && connections[i].inLaneId == laneIndex)
    {
      id = i;
      return true;
    }
  }
  return false;
}

bool findOutgoingConnection(const std::vector<IntersectionConnection> &connections,
                            uint32_t inArmId,
                            uint32_t outArmId,
                            uint32_t laneIndex,
                            uint32_t &id)
{
  for (uint32_t i = 0; i < connections.size(); ++i)
  {
    if (connections[i].inArmId == inArmId && connections[i].outArmId == outArmId
        && connections[i].outLaneId == laneIndex)
    {
      id = i;
      return true;
    }
  }
  return false;
}

IntersectionConnection IntersectionConnector::generateConnection(
  uint32_t inArmId, uint32_t inLaneIndex, uint32_t outArmId, uint32_t outLaneIndex, double distance)
{
  IntersectionConnection connection;
  connection.inArmId = inArmId;
  connection.inLaneId = inLaneIndex;
  connection.outArmId = outArmId;
  connection.outLaneId = outLaneIndex;
  double inArmOrientation = mIntersectionNodesMap[inArmId].orientation;
  double outArmOrientation = mIntersectionNodesMap[outArmId].orientation;

  connection.outLanePosition = lanePosition(inArmOrientation, outArmOrientation);
  connection.inTurnConstraint = mIntersectionNodesMap[inArmId].turnConstraints[inLaneIndex];
  connection.distance = distance;

  mIntersectionConnections.push_back(connection);
  return connection;
}

double IntersectionConnector::distanceBetweenLanes(MapDataStore const &store,
                                                   const IntersectionNode &nodeA,
                                                   uint32_t laneA,
                                                   const IntersectionNode &nodeB,
                                                   uint32_t laneB)
{
  double widthAtStart{0.0};
  double offsetAtStart{0.0};
  double widthAtEnd{0.0};
  double offsetAtEnd{0.0};

  if (mArms[nodeA.armId].isEntry)
  {
    widthAtStart = store.road(mArms[nodeA.armId].connectedRoad).mForwardWidths[laneA];
    for (uint32_t i = 0u; i < laneA; ++i)
    {
      offsetAtStart += store.road(mArms[nodeA.armId].connectedRoad).mForwardWidths[i];
    }
  }
  else
  {
    widthAtStart = store.road(mArms[nodeA.armId].connectedRoad).mBackwardWidths[laneA];
    for (uint32_t i = 0u; i < laneA; ++i)
    {
      offsetAtStart += store.road(mArms[nodeA.armId].connectedRoad).mBackwardWidths[i];
    }
  }

  if (mArms[nodeB.armId].isEntry)
  {
    widthAtEnd = store.road(mArms[nodeB.armId].connectedRoad).mBackwardWidths[laneB];
    for (uint32_t i = 0u; i < laneB; ++i)
    {
      offsetAtEnd += store.road(mArms[nodeB.armId].connectedRoad).mBackwardWidths[i];
    }
  }
  else
  {
    widthAtEnd = store.road(mArms[nodeB.armId].connectedRoad).mForwardWidths[laneB];
    for (uint32_t i = 0u; i < laneB; ++i)
    {
      offsetAtEnd += store.road(mArms[nodeB.armId].connectedRoad).mForwardWidths[i];
    }
  }

  geometry::Point2d referenceA = store.point(mArms[nodeA.armId].connectionPoint);
  geometry::Direction2d directionA(mArms[nodeA.armId].orientation - M_PI_2);
  geometry::Point2d pointA = directionA.movePoint(referenceA, -offsetAtStart - 0.5 * widthAtStart);

  geometry::Point2d referenceB = store.point(mArms[nodeB.armId].connectionPoint);
  geometry::Direction2d directionB(mArms[nodeB.armId].orientation - M_PI_2);
  geometry::Point2d pointB = directionB.movePoint(referenceB, offsetAtEnd + 0.5 * widthAtEnd);

  return pointA.squaredDistance(pointB);
}

void IntersectionConnector::generateConnections(MapDataStore const &store,
                                                const IntersectionNode &nodeA,
                                                const IntersectionNode &nodeB)
{
  for (uint32_t inLaneIndex = 0u; inLaneIndex < nodeA.lanesIn; ++inLaneIndex)
  {
    for (uint32_t outLaneIndex = 0u; outLaneIndex < nodeB.lanesOut; ++outLaneIndex)
    {
      generateConnection(nodeA.armId,
                         inLaneIndex,
                         nodeB.armId,
                         outLaneIndex,
                         distanceBetweenLanes(store, nodeA, inLaneIndex, nodeB, outLaneIndex));
    }
  }
}

void IntersectionConnector::generateConnections(MapDataStore const &store)
{
  for (auto const &elementA : mIntersectionNodesMap)
  {
    for (auto const &elementB : mIntersectionNodesMap)
    {
      auto const &nodeA = elementA.second;
      auto const &nodeB = elementB.second;
      if (nodeA.armId != nodeB.armId)
      {
        generateConnections(store, nodeA, nodeB);
      }
    }
  }
}

bool isConnectionForbidden(IntersectionConnection const &connection)
{
  return !isTurnAllowed(connection.inTurnConstraint, connection.outLanePosition);
}

bool isConnectionUTurn(IntersectionConnection const &connection)
{
  return connection.outLanePosition == LanePosition::UTurn;
}

bool isConnectionSharpTurn(IntersectionConnection const &connection)
{
  return connection.outLanePosition == LanePosition::SharpRight
    || connection.outLanePosition == LanePosition::SharpLeft;
}

void IntersectionConnector::removeUTurns()
{
  mIntersectionConnections.erase(
    std::remove_if(mIntersectionConnections.begin(), mIntersectionConnections.end(), isConnectionUTurn),
    mIntersectionConnections.end());
}

void IntersectionConnector::removeSharpTurns()
{
  mIntersectionConnections.erase(
    std::remove_if(mIntersectionConnections.begin(), mIntersectionConnections.end(), isConnectionSharpTurn),
    mIntersectionConnections.end());
}

bool IntersectionConnector::isConnectOneToOne()
{
  uint32_t totalLanesIn{0u};
  uint32_t totalLanesOut{0u};

  for (auto const &intersectionNodeElement : mIntersectionNodesMap)
  {
    totalLanesIn += intersectionNodeElement.second.lanesIn;
    totalLanesOut += intersectionNodeElement.second.lanesOut;
  }

  if (totalLanesIn == totalLanesOut)
  {
    return true;
  }
  else
  {
    return false;
  }
}

void IntersectionConnector::removeForbiddenConnections()
{
  mIntersectionConnections.erase(
    std::remove_if(mIntersectionConnections.begin(), mIntersectionConnections.end(), isConnectionForbidden),
    mIntersectionConnections.end());
}

/**
 * @brief Keep one to one straightforward connections. (non optimized)
 */
void keepStraightForwardConnections(std::vector<IntersectionConnection> &finalConnections,
                                    std::vector<IntersectionConnection> armConnections,
                                    const LanePosition &outLanesPosition)
{
  if (armConnections.size() > 0)
  {
    bool leftMostConnection;
    // assume the arms are already sorted from left to right in lane order
    if (outLanesPosition == LanePosition::Right || outLanesPosition == LanePosition::SharpRight
        || outLanesPosition == LanePosition::SlightlyRight)
    {
      leftMostConnection = false;
    }
    else if (outLanesPosition == LanePosition::Left || outLanesPosition == LanePosition::SharpLeft)
    {
      leftMostConnection = true;
    }
    else if (outLanesPosition == LanePosition::Front || outLanesPosition == LanePosition::SlightlyLeft)
    {
      // If forward connection then start from the side with the shortest distance.
      if (armConnections.front().distance <= armConnections.back().distance)
      {
        leftMostConnection = true;
      }
      else
      {
        leftMostConnection = false;
      }
    }
    else
    {
      leftMostConnection = true;
    }

    // Iterate over all arms, assume laneIn, laneOut ordering.
    // Find the leftmost or rightmost connection.
    // Remove all remaining connections that connect to the inLaneId or outLaneId.
    // Continue until all arm connections have been processed.

    if (leftMostConnection)
    {
      while (armConnections.size() > 0)
      {
        auto nextArmConnection = armConnections.front();
        armConnections.erase(armConnections.begin());
        uint32_t index{0u};
        while (findIncomingConnection(
          armConnections, nextArmConnection.inArmId, nextArmConnection.outArmId, nextArmConnection.inLaneId, index))
        {
          armConnections.erase(armConnections.begin() + index);
        }
        while (findOutgoingConnection(
          armConnections, nextArmConnection.inArmId, nextArmConnection.outArmId, nextArmConnection.outLaneId, index))
        {
          armConnections.erase(armConnections.begin() + index);
        }
        finalConnections.push_back(nextArmConnection);
      }
    }
    else
    {
      while (armConnections.size() > 0)
      {
        auto nextArmConnection = armConnections.back();
        armConnections.pop_back();
        uint32_t index{0u};
        while (findIncomingConnection(
          armConnections, nextArmConnection.inArmId, nextArmConnection.outArmId, nextArmConnection.inLaneId, index))
        {
          armConnections.erase(armConnections.begin() + index);
        }
        while (findOutgoingConnection(
          armConnections, nextArmConnection.inArmId, nextArmConnection.outArmId, nextArmConnection.outLaneId, index))
        {
          armConnections.erase(armConnections.begin() + index);
        }
        finalConnections.push_back(nextArmConnection);
      }
    }
  }
}

void IntersectionConnector::keepOneToOneLogicConnections()
{
  std::vector<IntersectionConnection> finalConnections;
  std::vector<IntersectionConnection> tmpConnections = mIntersectionConnections;

  // Iterate over all arms and group all the arm-to-arm connections.
  for (auto const &elementA : mIntersectionNodesMap)
  {
    for (auto const &elementB : mIntersectionNodesMap)
    {
      auto const &nodeA = elementA.second;
      auto const &nodeB = elementB.second;
      if (nodeA.armId != nodeB.armId)
      {
        std::vector<IntersectionConnection> armConnections;
        uint32_t index{0u};
        while (findArmConnection(tmpConnections, nodeA.armId, nodeB.armId, index))
        {
          armConnections.push_back(tmpConnections.at(index));
          tmpConnections.erase(tmpConnections.begin() + index);
        }
        auto outLanesPosition = lanePosition(nodeA.orientation, nodeB.orientation);
        keepStraightForwardConnections(finalConnections, armConnections, outLanesPosition);
      }
    }
  }
  std::swap(finalConnections, mIntersectionConnections);
}

void IntersectionConnector::keepOnlyClosestConnections()
{
  keepOnlyClosestOutgoingConnections();
  keepOnlyClosestIncomingConnections();
}

void IntersectionConnector::keepOnlyClosestIncomingConnections()
{
  std::vector<IntersectionConnection> remainingConnections;
  for (uint32_t i = 0u; i < mIntersectionConnections.size(); ++i)
  {
    const uint32_t inArmId = mIntersectionConnections[i].inArmId;
    const uint32_t outArmId = mIntersectionConnections[i].outArmId;
    const uint32_t laneIndex = mIntersectionConnections[i].inLaneId;
    uint32_t findId{0u};

    if (findIncomingConnection(remainingConnections, inArmId, outArmId, laneIndex, findId))
    {
      if (mIntersectionConnections.at(i).distance < remainingConnections.at(findId).distance)
      {
        remainingConnections.at(findId) = mIntersectionConnections.at(i);
      }
    }
    else
    {
      remainingConnections.push_back(mIntersectionConnections.at(i));
    }
  }
  std::swap(remainingConnections, mIntersectionConnections);
}
void IntersectionConnector::keepOnlyClosestOutgoingConnections()
{
  std::vector<IntersectionConnection> remainingConnections;
  for (uint32_t i = 0u; i < mIntersectionConnections.size(); ++i)
  {
    const uint32_t inArmId = mIntersectionConnections[i].inArmId;
    const uint32_t outArmId = mIntersectionConnections[i].outArmId;
    const uint32_t laneIndex = mIntersectionConnections[i].outLaneId;
    uint32_t findId{0u};

    if (findOutgoingConnection(remainingConnections, inArmId, outArmId, laneIndex, findId))
    {
      if (mIntersectionConnections.at(i).distance < remainingConnections.at(findId).distance)
      {
        remainingConnections.at(findId) = mIntersectionConnections.at(i);
      }
    }
    else
    {
      remainingConnections.push_back(mIntersectionConnections.at(i));
    }
  }
  std::swap(remainingConnections, mIntersectionConnections);
}

} // namespace map_data
} // namespace maker
} // namespace map
} // namespace ad
