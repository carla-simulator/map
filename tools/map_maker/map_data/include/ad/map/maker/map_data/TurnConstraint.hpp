// ----------------- BEGIN LICENSE BLOCK ---------------------------------
//
// Copyright (C) 2018-2019 Intel Corporation
//
// SPDX-License-Identifier: MIT
//
// ----------------- END LICENSE BLOCK -----------------------------------

#pragma once

#include <cmath>
#include <vector>
#include "ad/map/maker/map_data/TurnDirection.hpp"

namespace ad {
namespace map {
namespace maker {
namespace map_data {

constexpr double frontAngleOpening = M_PI / 18.0;       // 10 degrees
constexpr double slightAngleOpening = M_PI / 6.0;       // 30 degrees
constexpr double sharpTurnAngleOpening = M_PI / 3.0;    // 60 degrees
constexpr double uTurnAngleOpening = 3.0 * M_PI / 18.0; // 30 degrees

enum class TurnConstraint
{
  OnlyLeft,
  OnlyRight,
  OnlyThrough,
  LeftAndRight,
  LeftAndThrough,
  RightAndThrough,
  OnlyMergeToLeft,
  OnlyMergeToRight,
  None,
  All
};

enum class LanePosition
{
  Left,
  Right,
  Front,
  SlightlyLeft,
  SlightlyRight,
  SharpLeft,
  SharpRight,
  UTurn
};

typedef std::vector<TurnConstraint> TurnConstraints;

/**
 * @brief Returns true if the lane position does not violate the turn constraint.
 */
bool isTurnAllowed(TurnConstraint const &turnConstraint, const LanePosition &lanePosition);

/**
 * @brief Converts a vector of turn direction restrictions into a single turn constraint.
 */
TurnConstraint turnDirectionsToTurnConstraint(TurnDirections const &turnDirections);

/**
 * @brief Determines the position of the exit lane using the enter lane as reference.
 */
LanePosition lanePosition(double enterOrientation, double exitOrientation);

} // namespace map_data
} // namespace maker
} // namespace map
} // namespace ad
