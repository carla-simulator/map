// ----------------- BEGIN LICENSE BLOCK ---------------------------------
//
// Copyright (C) 2018-2019 Intel Corporation
//
// SPDX-License-Identifier: MIT
//
// ----------------- END LICENSE BLOCK -----------------------------------

#include "ad/map/maker/map_data/TurnConstraint.hpp"
#include <ad/map/maker/geometry/Direction2d.hpp>

namespace ad {
namespace map {
namespace maker {
namespace map_data {

bool isTurnAllowed(const TurnConstraint &turnConstraint, const LanePosition &lanePosition)
{
  switch (turnConstraint)
  {
    case TurnConstraint::None:
      return true;
    case TurnConstraint::OnlyMergeToLeft:
      if (lanePosition == LanePosition::Front || lanePosition == LanePosition::SlightlyLeft)
      {
        return true;
      }
      return false;
    case TurnConstraint::OnlyMergeToRight:
      if (lanePosition == LanePosition::Front || lanePosition == LanePosition::SlightlyRight)
      {
        return true;
      }
      return false;
    case TurnConstraint::OnlyLeft:
      if (lanePosition == LanePosition::Left || lanePosition == LanePosition::SlightlyLeft
          || lanePosition == LanePosition::SharpLeft)
      {
        return true;
      }
      return false;
    case TurnConstraint::OnlyRight:
      if (lanePosition == LanePosition::Right || lanePosition == LanePosition::SlightlyRight
          || lanePosition == LanePosition::SharpRight)
      {
        return true;
      }
      return false;
    case TurnConstraint::OnlyThrough:
      if (lanePosition == LanePosition::Front || lanePosition == LanePosition::SlightlyLeft
          || lanePosition == LanePosition::SlightlyRight)
      {
        return true;
      }
      return false;
    case TurnConstraint::LeftAndRight:
      if (lanePosition == LanePosition::Left || lanePosition == LanePosition::SlightlyLeft
          || lanePosition == LanePosition::Right || lanePosition == LanePosition::SlightlyRight
          || lanePosition == LanePosition::SharpLeft || lanePosition == LanePosition::SharpRight)
      {
        return true;
      }
      return false;
    case TurnConstraint::LeftAndThrough:
      if (lanePosition == LanePosition::Left || lanePosition == LanePosition::SlightlyLeft
          || lanePosition == LanePosition::Front || lanePosition == LanePosition::SharpLeft)
      {
        return true;
      }
      return false;
    case TurnConstraint::RightAndThrough:
      if (lanePosition == LanePosition::Right || lanePosition == LanePosition::SlightlyRight
          || lanePosition == LanePosition::Front || lanePosition == LanePosition::SharpRight)
      {
        return true;
      }
      return false;
    case TurnConstraint::All:
    default:
      return false;
  }
}

TurnConstraint turnDirectionsToTurnConstraint(const TurnDirections &turnDirections)
{
  bool leftAllowed = false;
  bool rightAllowed = false;
  bool throughAllowed = false;
  bool mergeToLeftAllowed = false;
  bool mergeToRightAllowed = false;

  for (auto const &direction : turnDirections)
  {
    switch (direction)
    {
      case TurnDirection::Left:
      case TurnDirection::SlightLeft:
      case TurnDirection::SharpLeft:
        leftAllowed = true;
        mergeToLeftAllowed = true;
        break;
      case TurnDirection::Through:
        throughAllowed = true;
        break;
      case TurnDirection::Right:
      case TurnDirection::SlightRight:
      case TurnDirection::SharpRight:
        rightAllowed = true;
        mergeToRightAllowed = true;
        break;
      case TurnDirection::MergeToLeft:
        mergeToLeftAllowed = true;
        break;
      case TurnDirection::MergeToRight:
        mergeToRightAllowed = true;
        break;
      case TurnDirection::None:
        leftAllowed = true;
        rightAllowed = true;
        throughAllowed = true;
        mergeToLeftAllowed = true;
        mergeToRightAllowed = true;
        break;
      default:
        break;
    }
  }

  // handle the contraints one by one
  // warning the order of the ifs changes the final constraints
  if (leftAllowed && rightAllowed && throughAllowed && mergeToLeftAllowed && mergeToRightAllowed)
  {
    return TurnConstraint::None;
  }
  else if (leftAllowed && throughAllowed)
  {
    return TurnConstraint::LeftAndThrough;
  }
  else if (rightAllowed && throughAllowed)
  {
    return TurnConstraint::RightAndThrough;
  }
  else if (rightAllowed && leftAllowed)
  {
    return TurnConstraint::LeftAndRight;
  }
  else if (rightAllowed)
  {
    return TurnConstraint::OnlyRight;
  }
  else if (leftAllowed)
  {
    return TurnConstraint::OnlyLeft;
  }
  else if (mergeToLeftAllowed)
  {
    return TurnConstraint::OnlyMergeToLeft;
  }
  else if (mergeToRightAllowed)
  {
    return TurnConstraint::OnlyMergeToRight;
  }
  else if (throughAllowed)
  {
    return TurnConstraint::OnlyThrough;
  }
  else
  {
    return TurnConstraint::All;
  }
}

LanePosition lanePosition(double enterOrientation, double exitOrientation)
{
  double angleBetweenArms = geometry::minimumAngleDifference(enterOrientation, exitOrientation);

  if (fabs(fabs(angleBetweenArms) - M_PI) < frontAngleOpening)
  {
    return LanePosition::Front;
  }
  else if (fabs(fabs(angleBetweenArms) - M_PI) < slightAngleOpening && angleBetweenArms < 0.0)
  {
    return LanePosition::SlightlyRight;
  }
  else if (fabs(fabs(angleBetweenArms) - M_PI) < slightAngleOpening && angleBetweenArms > 0.0)
  {
    return LanePosition::SlightlyLeft;
  }
  else if (fabs(angleBetweenArms) < uTurnAngleOpening)
  {
    return LanePosition::UTurn;
  }
  else if (fabs(angleBetweenArms) < sharpTurnAngleOpening && angleBetweenArms > 0.0)
  {
    return LanePosition::SharpLeft;
  }
  else if (fabs(angleBetweenArms) < sharpTurnAngleOpening && angleBetweenArms < 0.0)
  {
    return LanePosition::SharpRight;
  }
  else if (angleBetweenArms > 0.0)
  {
    return LanePosition::Left;
  }
  else
  {
    return LanePosition::Right;
  }
}

} // namespace map_data
} // namespace maker
} // namespace map
} // namespace ad
