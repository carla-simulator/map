// ----------------- BEGIN LICENSE BLOCK ---------------------------------
//
// Copyright (C) 2018-2022 Intel Corporation
//
// SPDX-License-Identifier: MIT
//
// ----------------- END LICENSE BLOCK -----------------------------------

#include "ad/map/lane/BorderOperation.hpp"
#include <algorithm>
#include "LaneOperationPrivate.hpp"
#include "ad/map/access/Logging.hpp"
#include "ad/map/point/Operation.hpp"

namespace ad {
namespace map {
namespace lane {

physics::Distance calcLength(ENUEdge const &edge)
{
  return calcLength(edge.points);
}

physics::Distance calcLength(ECEFEdge const &edge)
{
  return calcLength(edge.points);
}

physics::Distance calcLength(GeoEdge const &edge)
{
  return calcLength(edge.points);
}

physics::Distance calcLength(ENUBorder const &border)
{
  return (calcLength(border.left.points) + calcLength(border.right.points)) / 2.;
}

physics::Distance calcLength(ECEFBorder const &border)
{
  return (calcLength(border.left.points) + calcLength(border.right.points)) / 2.;
}

physics::Distance calcLength(GeoBorder const &border)
{
  return (calcLength(border.left.points) + calcLength(border.right.points)) / 2.;
}

physics::Distance calcLength(ENUBorderList const &borderList)
{
  physics::Distance total(0.);
  for (auto const &value : borderList)
  {
    total = total + calcLength(value);
  }
  return total;
}

physics::Distance calcLength(ECEFBorderList const &borderList)
{
  physics::Distance total(0.);
  for (auto const &value : borderList)
  {
    total = total + calcLength(value);
  }
  return total;
}

physics::Distance calcLength(GeoBorderList const &borderList)
{
  physics::Distance total(0.);
  for (auto const &value : borderList)
  {
    total = total + calcLength(value);
  }
  return total;
}

void removeDegeneratedEdgePoints(ENUEdge &edge, ENUEdge const *previousEdge = nullptr)
{
  if (edge.points.size() < 2u)
  {
    return;
  }

  point::ENUPoint previousEdgeDir;
  if (previousEdge != nullptr)
  {
    if (previousEdge->points.size() < 2u)
    {
      return;
    }
    // decide if edge start point has to be adapted
    previousEdgeDir = previousEdge->points.at(previousEdge->points.size() - 1u)
      - previousEdge->points.at(previousEdge->points.size() - 2u);
    auto nextEdgeDir = edge.points[0] - previousEdge->points.at(previousEdge->points.size() - 1u);

    // if the two edges are near to each other or the direction is dramatically different,
    // the start point is overwritten by the end of the previous edge
    if ((point::vectorLength(nextEdgeDir) > point::cEdgePointBorderDistance)
        || (point::vectorDotProduct(previousEdgeDir, nextEdgeDir) < 0.))
    {
      edge.points[0] = previousEdge->points.at(previousEdge->points.size() - 1u);
    }
    else
    {
      previousEdgeDir = nextEdgeDir;
    }
  }
  else
  {
    previousEdgeDir = edge.points[1] - edge.points[0];
  }

  std::size_t pointsToDrop = 0u;
  for (std::size_t i = 1u; i < edge.points.size(); ++i)
  {
    // i-pointsToDrop > 0
    if (pointsToDrop > 0u)
    {
      edge.points[i - pointsToDrop] = edge.points[i];
    }
    auto nextEdgeDir = edge.points[i - pointsToDrop] - edge.points[i - pointsToDrop - 1];
    auto dotProduct = point::vectorDotProduct(previousEdgeDir, nextEdgeDir);
    if (dotProduct < 0.)
    {
      pointsToDrop++;
    }
    else
    {
      previousEdgeDir = nextEdgeDir;
    }
  }
  if (pointsToDrop > 0u)
  {
    std::size_t const newEdgeSize = std::max(std::size_t(2u), edge.points.size() - pointsToDrop);
    edge.points.resize(newEdgeSize);
  }
}

std::vector<std::size_t> calcSmallerEdgeIndexPairs(physics::ParametricValueList const &biggerEdgeParametricPoints,
                                                   physics::ParametricValueList const &smallerEdgeParametricPoints)
{
  std::vector<std::size_t> indexPairs;
  indexPairs.reserve(biggerEdgeParametricPoints.size());
  indexPairs.push_back(0u);
  std::size_t matchingSmallerIndex = 0u;
  for (std::size_t biggerIndex = 1u; biggerIndex < biggerEdgeParametricPoints.size(); biggerIndex++)
  {
    physics::ParametricValue minParametricDistance(1.);
    bool matchingIndexFound = false;
    // since both lists are sorted in ascending, it's ok to start search at last found index
    for (std::size_t smallerIndex = matchingSmallerIndex;
         (!matchingIndexFound) && (smallerIndex < smallerEdgeParametricPoints.size());
         smallerIndex++)
    {
      auto const parametricDistance
        = std::fabs(smallerEdgeParametricPoints[smallerIndex] - biggerEdgeParametricPoints[biggerIndex]);
      if (parametricDistance > minParametricDistance)
      {
        // the best matching edge point is the one we have seen last
        matchingSmallerIndex = smallerIndex - 1u;
        matchingIndexFound = true;
        indexPairs.push_back(matchingSmallerIndex);
      }
      else
      {
        minParametricDistance = parametricDistance;
      }
    }
    if (!matchingIndexFound)
    {
      // if not yet found, the last is the best matching one
      matchingSmallerIndex = smallerEdgeParametricPoints.size() - 1u;
      indexPairs.push_back(matchingSmallerIndex);
    }
  }
  return indexPairs;
}

point::ENUPoint interpolatePoint(point::ENUPoint const &pointBefore,
                                 point::ENUPoint const &pointAfter,
                                 physics::ParametricValue const pointBeforeParametricEdgeOffset,
                                 physics::ParametricValue const pointInterpolatedParametricEdgeOffset,
                                 physics::ParametricValue const pointAfterParametricEdgeOffset)
{
  physics::ParametricValue const parametric_offset(
    (pointInterpolatedParametricEdgeOffset - pointBeforeParametricEdgeOffset)
    / (pointAfterParametricEdgeOffset - pointBeforeParametricEdgeOffset));
  return point::vectorInterpolate(pointBefore, pointAfter, parametric_offset);
}

void fillSmallerEdge(ENUEdge const &biggerEdge, ENUEdge &smallerEdge)
{
  auto const biggerEdgeParametricPoints = getParametricEdgePoints(biggerEdge.points);
  auto const smallerEdgeParametricPoints = getParametricEdgePoints(smallerEdge.points);

  auto const smallerEdgeIndices = calcSmallerEdgeIndexPairs(biggerEdgeParametricPoints, smallerEdgeParametricPoints);

  ENUEdge newSmallerEdge;
  newSmallerEdge.points.reserve(biggerEdge.points.size());
  newSmallerEdge.points.push_back(smallerEdge.points.front());
  std::size_t lastWrittenSmallerEdgeIndex = 0u;
  for (std::size_t i = 1u; i < smallerEdgeIndices.size() - 1u; ++i)
  {
    // i-1, i, i+1 indices are valid for smallerEdgeIndices and biggerEdgeParametricPoints

    if ( // smaller point already processed, insert an interpolated
      (smallerEdgeIndices[i] == lastWrittenSmallerEdgeIndex)
      // the point before the last point of the smaller edge is already written, so we have to interpolate till the end
      || (lastWrittenSmallerEdgeIndex == (smallerEdge.points.size() - 2u)))
    {
      auto interpolatedPoint = interpolatePoint(smallerEdge.points[lastWrittenSmallerEdgeIndex],
                                                smallerEdge.points[lastWrittenSmallerEdgeIndex + 1u],
                                                biggerEdgeParametricPoints[i - 1],
                                                biggerEdgeParametricPoints[i],
                                                biggerEdgeParametricPoints[i + 1]);
      newSmallerEdge.points.push_back(interpolatedPoint);
    }
    else
    {
      lastWrittenSmallerEdgeIndex = smallerEdgeIndices[i];
      newSmallerEdge.points.push_back(smallerEdge.points[lastWrittenSmallerEdgeIndex]);
    }
  }
  newSmallerEdge.points.push_back(smallerEdge.points.back());
  smallerEdge.points.swap(newSmallerEdge.points);
}

void normalizeBorder(ENUBorder &border, ENUBorder const *previousBorder)
{
  if ((border.left.points.size() < 2u) || (border.right.points.size() < 2u))
  {
    return;
  }
  if ((previousBorder != nullptr) && (previousBorder->left.points.size() >= 2u)
      && (previousBorder->right.points.size() >= 2u))
  {
    removeDegeneratedEdgePoints(border.left, &previousBorder->left);
    removeDegeneratedEdgePoints(border.right, &previousBorder->right);
  }
  else
  {
    removeDegeneratedEdgePoints(border.left);
    removeDegeneratedEdgePoints(border.right);
  }
  if (border.left.points.size() == border.right.points.size())
  {
    return;
  }

  std::vector<std::size_t> smallerEdgeIndices;
  if (border.left.points.size() > border.right.points.size())
  {
    fillSmallerEdge(border.left, border.right);
  }
  else
  {
    fillSmallerEdge(border.right, border.left);
  }
}

IndexPairs getIndexPairs(ENUEdge const &leftEdge, ENUEdge const &rightEdge)
{
  std::size_t const maxSize = std::max(leftEdge.points.size(), rightEdge.points.size());
  std::vector<std::size_t> equalIndices;
  equalIndices.reserve(maxSize);
  for (size_t i = 0u; i < maxSize; ++i)
  {
    equalIndices.push_back(i);
  }

  IndexPairs indexPairs;
  if (leftEdge.points.size() == rightEdge.points.size())
  {
    indexPairs.leftEdgeIndices = equalIndices;
    indexPairs.rightEdgeIndices.swap(equalIndices);
  }
  else if (leftEdge.points.size() > rightEdge.points.size())
  {
    indexPairs.leftEdgeIndices.swap(equalIndices);
    indexPairs.rightEdgeIndices
      = calcSmallerEdgeIndexPairs(getParametricEdgePoints(leftEdge.points), getParametricEdgePoints(rightEdge.points));
  }
  else
  {
    indexPairs.leftEdgeIndices
      = calcSmallerEdgeIndexPairs(getParametricEdgePoints(rightEdge.points), getParametricEdgePoints(leftEdge.points));
    indexPairs.rightEdgeIndices.swap(equalIndices);
  }
  return indexPairs;
}

ENUEdge getLateralAlignmentEdge(ENUBorder const &border, physics::ParametricValue const lateral_alignment)
{
  ENUEdge result;
  result.points = point::getLateralAlignmentEdge(border.left.points, border.right.points, lateral_alignment);
  result.lateral_alignment = lateral_alignment;
  if (lateral_alignment == cLateralAlignmentLeft)
  {
    result.edge_type = EdgeType::LEFT;
  }
  else if (lateral_alignment == cLateralAlignmentRight)
  {
    result.edge_type = EdgeType::RIGHT;
  }
  else if (lateral_alignment == cLateralAlignmentCenter)
  {
    result.edge_type = EdgeType::CENTER;
  }
  else
  {
    result.edge_type = EdgeType::ALIGNED;
  }
  return result;
}

ENUEdge getLateralAlignmentEdge(ENUBorder const &border, physics::RatioValue const lateral_alignment)
{
  ENUEdge result;
  result.points = point::getLateralAlignmentEdge(border.left.points, border.right.points, lateral_alignment);
  result.lateral_alignment.mParametricValue = lateral_alignment.mRatioValue;
  if (result.lateral_alignment == cLateralAlignmentLeft)
  {
    result.edge_type = EdgeType::LEFT;
  }
  else if (result.lateral_alignment == cLateralAlignmentRight)
  {
    result.edge_type = EdgeType::RIGHT;
  }
  else if (result.lateral_alignment == cLateralAlignmentCenter)
  {
    result.edge_type = EdgeType::CENTER;
  }
  else
  {
    result.edge_type = EdgeType::ALIGNED;
  }
  return result;
}

inline bool isPointWithinBorderPoints(point::ENUPoint const &ptLeft,
                                      point::ENUPoint const &ptRight,
                                      point::ENUPoint const &enuPoint,
                                      physics::Distance const &tolerance = physics::Distance(0.01))
{
  // check if the point is actually located in between the border points
  auto const towardsLeft = ptLeft - enuPoint;
  auto const towardsRight = ptRight - enuPoint;
  auto const dotProduct = point::vectorDotProduct(towardsLeft, towardsRight);
  auto const withinBorders = (dotProduct < 0.) || (point::vectorLength(towardsLeft) < tolerance)
    || (point::vectorLength(towardsRight) < tolerance);
  return withinBorders;
}

inline point::ENUHeading createHeadingFromBorderPoints(point::ENUPoint const &ptLeft, point::ENUPoint const &ptRight)
{
  auto const headingLeftToRight = point::createENUHeading(ptLeft, ptRight);
  auto const resultHeading = point::createENUHeading(headingLeftToRight.mENUHeading + M_PI_2);
  return resultHeading;
}

point::ENUHeading getENUHeading(ENUBorderList const &borderList,
                                point::ENUPoint const &enuPoint,
                                physics::Distance const &toleranceDistanceOutsideBorder)
{
  point::ENUHeading resultHeading(2. * M_PI);

  auto firstBeforeBorderDetected = borderList.end();
  auto lastAfterBorderDetected = borderList.end();
  for (auto borderIter = borderList.begin(); borderIter != borderList.end(); borderIter++)
  {
    auto const edgeLeftLength = calcLength(borderIter->left.points);
    auto const edgeRightLength = calcLength(borderIter->right.points);

    // first of all we have to handle degenerated borders
    if ((edgeLeftLength == physics::Distance(0.)) || (edgeRightLength == physics::Distance(0.)))
    {
      if ((borderIter->left.points.size() == 0u) || (borderIter->right.points.size() == 0u))
      {
        access::getLogger()->error(
          "ad::map::lane::getENUHeading: invalid enu border of size border-left:{} border-right:{} query-point:{}!",
          borderIter->left,
          borderIter->right,
          enuPoint);
        return resultHeading;
      }

      // the question here is: are we actually before or after the border
      auto const headingLeftToRight = point::createENUHeading(borderIter->left.points[0], borderIter->right.points[0]);
      auto const headingLeftToPoint = point::createENUHeading(borderIter->left.points[0], enuPoint);
      auto const headingDiff = point::createENUHeading(headingLeftToPoint.mENUHeading - headingLeftToRight.mENUHeading);
      if (headingDiff < point::ENUHeading(0.))
      {
        if (firstBeforeBorderDetected == borderList.end())
        {
          firstBeforeBorderDetected = borderIter;
        }
      }
      else
      {
        lastAfterBorderDetected = borderIter;
      }
    }
    else
    {
      auto parametricOffsetLeft = point::findNearestPointOnEdge(borderIter->left.points, edgeLeftLength, enuPoint);
      auto parametricOffsetRight = point::findNearestPointOnEdge(borderIter->right.points, edgeRightLength, enuPoint);

      // catch errors
      if ((!parametricOffsetLeft.isValid()) || (!parametricOffsetRight.isValid()))
      {
        access::getLogger()->error(
          "ad::map::lane::getENUHeading: invalid input data border-left:{} border-right:{} query-point:{}",
          borderIter->left,
          borderIter->right.points,
          enuPoint);
        return resultHeading;
      }

      if ((parametricOffsetLeft == physics::ParametricValue(0.))
          || (parametricOffsetRight == physics::ParametricValue(0.)))
      {
        if (firstBeforeBorderDetected == borderList.end())
        {
          firstBeforeBorderDetected = borderIter;
        }
      }
      else if ((parametricOffsetLeft == physics::ParametricValue(1.))
               || (parametricOffsetRight == physics::ParametricValue(1.)))
      {
        lastAfterBorderDetected = borderIter;
      }
      else
      {
        // looks as we have found a potential segment
        auto const ptLeft = point::getParametricPoint(borderIter->left.points, parametricOffsetLeft);
        auto const ptRight = point::getParametricPoint(borderIter->right.points, parametricOffsetRight);
        bool const withinBorder = isPointWithinBorderPoints(ptLeft, ptRight, enuPoint);

        if (withinBorder)
        {
          return createHeadingFromBorderPoints(ptLeft, ptRight);
        }
      }
    }
  }

  // if we didn't find any actual match in between so far, use either the first before or the last after to create the
  // heading
  if (firstBeforeBorderDetected != borderList.end())
  {
    auto const ptLeft = firstBeforeBorderDetected->left.points.front();
    auto const ptRight = firstBeforeBorderDetected->right.points.front();
    bool const withinBorder = isPointWithinBorderPoints(ptLeft, ptRight, enuPoint, toleranceDistanceOutsideBorder);
    if (withinBorder)
    {
      return createHeadingFromBorderPoints(ptLeft, ptRight);
    }
  }
  if (lastAfterBorderDetected != borderList.end())
  {
    auto const ptLeft = lastAfterBorderDetected->left.points.back();
    auto const ptRight = lastAfterBorderDetected->right.points.back();
    bool const withinBorder = isPointWithinBorderPoints(ptLeft, ptRight, enuPoint, toleranceDistanceOutsideBorder);
    if (withinBorder)
    {
      return createHeadingFromBorderPoints(ptLeft, ptRight);
    }
  }

  return resultHeading;
}

physics::Distance getDistanceEnuPointToLateralAlignmentEdge(point::ENUPoint const &enuPoint,
                                                            ENUEdge const &lateralAlignmentEdge)
{
  auto const edgeLength = calcLength(lateralAlignmentEdge.points);
  auto const parametric_offset = point::findNearestPointOnEdge(lateralAlignmentEdge.points, edgeLength, enuPoint);
  auto const projectedPoint = point::getParametricPoint(lateralAlignmentEdge.points, edgeLength, parametric_offset);
  auto const distance = point::distance(projectedPoint, enuPoint);
  return distance;
}

bool areEdgesContinuous(ENUEdge const &first, ENUEdge const &second)
{
  if ((first.points.size() < 2u) || (second.points.size() < 2u))
  {
    return true;
  }

  auto const firstToSecondDistance = point::distance(second.points.front(), first.points.back());
  if (firstToSecondDistance < point::cEdgePointBorderDistance)
  {
    return true;
  }
  return false;
}

void performMakeTransitionToSecondEdgeContinuous(ENUEdge const &first,
                                                 ENUEdge &second,
                                                 ENUEdge *secondOtherLane = nullptr)
{
  if (areEdgesContinuous(first, second))
  {
    return;
  }
  auto const firstToSecondVec = second.points.front() - first.points.back();
  auto const firstToSecondDistance = point::vectorLength(firstToSecondVec);
  auto const firstToSecondDir = point::vectorNorm(firstToSecondVec);
  auto const firstEndDir = getEdgeEndDirectionalVector(first.points);
  auto const secondStartDir = getEdgeStartDirectionalVector(second.points);
  auto const averageEdgeDir = 0.5 * (firstEndDir + secondStartDir);
  double const sinAngle = point::vectorLength(point::vectorCrossProduct(averageEdgeDir, firstToSecondDir)).mDistance;
  // the distance of our interpolation changes depend on the offset of the two edges ends and the lateral offset
  // (given by the sine of the angle between the general edge direction and the offset direction)
  // e.g. if the offset is 3m and orthogonal we get a 6m interpolating distance
  auto const interpolatingDistance = sinAngle * 2.0 * firstToSecondDistance;

  auto const secondLength = calcLength(second.points);

  physics::ParametricValue const parametricInterpolatingDistance(std::min(.95, interpolatingDistance / secondLength));

  auto const secondParametricEdgePoints = getParametricEdgePoints(second.points);

  std::size_t const newSecondSize = second.points.size() + 1u;
  ENUEdge newSecond;
  newSecond.points.reserve(newSecondSize);
  ENUEdge newOtherSecond;
  if ((secondOtherLane != nullptr) && (secondOtherLane->points.size() == second.points.size()))
  {
    newOtherSecond.points.resize(newSecondSize);
  }
  for (std::size_t i = 1u; i < secondParametricEdgePoints.size(); ++i)
  {
    if (secondParametricEdgePoints[i] >= parametricInterpolatingDistance)
    {
      if (newSecond.points.empty())
      {
        // first point found

        // take the last point of the first edge
        newSecond.points.push_back(first.points.back());

        // calculate the interpolated point
        point::ENUPoint interpolatedPoint = interpolatePoint(second.points[i - 1],
                                                             second.points[i],
                                                             secondParametricEdgePoints[i - 1],
                                                             parametricInterpolatingDistance,
                                                             secondParametricEdgePoints[i]);

        //@todo: one potential issue is not considered in here yet:
        // if second curvature is extreme, the newly created linear edge segment by the above two points could
        // potentially intersect with the old second border and by that enlarging a driving area beyond the
        // allowed borders. To prevent from this one would have to implement 'point::vectorIntersects':
        //
        // auto const newEdgeSegment = interpolatedPoint-newSecond[0];
        // for (std::size_t j=1u; j<i; j++ )
        // {
        //     auto const checkSegment = second[j] - second[j-1u];
        //     if ( point::vectorIntersects(checkSegment, newEdgeSegment) )
        //     {
        //        i = j;
        //        std::size_t const newSecondSize = secondParametricEdgePoints.size()-i + 1u;
        //        newSecond.reserve(newSecondSize);
        //        interpolatedPoint = secondParametricEdgePoints[i-1];
        //        break;
        //     }
        // }

        // before adding the interpolated point we have to add also some interpolated points on the vector
        // newSecond[0] -> interpolatedPoint if there have been others skipped
        for (std::size_t j = 1u; j < i; ++j)
        {
          auto innerInterpolatedPoint = interpolatePoint(newSecond.points[0],
                                                         interpolatedPoint,
                                                         physics::ParametricValue(0.),
                                                         secondParametricEdgePoints[j],
                                                         parametricInterpolatingDistance);
          newSecond.points.push_back(innerInterpolatedPoint);
        }

        // then we add the interpolated point
        newSecond.points.push_back(interpolatedPoint);

        // fill the newOtherSecond lane if available
        if (newOtherSecond.points.size() > 0u)
        {
          std::size_t j = 0u;
          for (; (j < i) && (j < newOtherSecond.points.size()) && (j < secondOtherLane->points.size()); ++j)
          {
            newOtherSecond.points[j] = secondOtherLane->points.at(j);
          }
          if ((j < newOtherSecond.points.size()) && (j < secondOtherLane->points.size()))
          {
            // same parametric range than the interpolated point
            newOtherSecond.points[j] = interpolatePoint(secondOtherLane->points.at(j - 1u),
                                                        secondOtherLane->points.at(j),
                                                        secondParametricEdgePoints[i - 1],
                                                        parametricInterpolatingDistance,
                                                        secondParametricEdgePoints[i]);
          }
          for (; ((j + 1u) < newOtherSecond.points.size()) && (j < secondOtherLane->points.size()); j++)
          {
            newOtherSecond.points[j + 1u] = secondOtherLane->points.at(j);
          }
        }
      }
      // add this one
      newSecond.points.push_back(second.points[i]);
    }
  }
  second.points.swap(newSecond.points);
  if (secondOtherLane != nullptr)
  {
    secondOtherLane->points.swap(newOtherSecond.points);
  }
}

void makeTransitionToSecondEdgeContinuous(ENUEdge const &first, ENUEdge &second)
{
  performMakeTransitionToSecondEdgeContinuous(first, second);
}

void makeTransitionFromFirstEdgeContinuous(ENUEdge &first, ENUEdge const &second)
{
  if (areEdgesContinuous(first, second))
  {
    return;
  }
  // if actually something has to be calculated, we reverse the edge and let the other function do the job
  ENUEdge invertedFirstEdge = first;
  std::reverse(invertedFirstEdge.points.begin(), invertedFirstEdge.points.end());
  ENUEdge invertedSecondEdge = second;
  std::reverse(invertedSecondEdge.points.begin(), invertedSecondEdge.points.end());
  performMakeTransitionToSecondEdgeContinuous(invertedSecondEdge, invertedFirstEdge);
  first = invertedFirstEdge;
  std::reverse(first.points.begin(), first.points.end());
}

void makeTransitionToSecondBorderContinuous(ENUBorder const &first, ENUBorder &second)
{
  performMakeTransitionToSecondEdgeContinuous(first.left, second.left, &second.right);
  performMakeTransitionToSecondEdgeContinuous(first.right, second.right, &second.left);
}

void makeTransitionFromFirstBorderContinuous(ENUBorder &first, ENUBorder const &second)
{
  if (areEdgesContinuous(first.left, second.left) && areEdgesContinuous(first.right, second.right))
  {
    return;
  }
  // if actually something has to be calculated, we reverse the borders and let the other function do the job
  ENUBorder invertedFirstBorder = first;
  std::reverse(invertedFirstBorder.left.points.begin(), invertedFirstBorder.left.points.end());
  std::reverse(invertedFirstBorder.right.points.begin(), invertedFirstBorder.right.points.end());
  ENUBorder invertedSecondBorder = second;
  std::reverse(invertedSecondBorder.left.points.begin(), invertedSecondBorder.left.points.end());
  std::reverse(invertedSecondBorder.right.points.begin(), invertedSecondBorder.right.points.end());
  makeTransitionToSecondBorderContinuous(invertedSecondBorder, invertedFirstBorder);
  first = invertedFirstBorder;
  std::reverse(first.left.points.begin(), first.left.points.end());
  std::reverse(first.right.points.begin(), first.right.points.end());
}

} // namespace lane
} // namespace map
} // namespace ad
