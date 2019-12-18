// ----------------- BEGIN LICENSE BLOCK ---------------------------------
//
// Copyright (C) 2018-2019 Intel Corporation
//
// SPDX-License-Identifier: MIT
//
// ----------------- END LICENSE BLOCK -----------------------------------

#include "ad/map/lane/BorderOperation.hpp"
#include <algorithm>
#include "LaneOperationPrivate.hpp"

namespace ad {
namespace map {
namespace lane {

void removeDegeneratedEdgePoints(point::ENUEdge &edge, point::ENUEdge const *previousEdge = nullptr)
{
  if (edge.size() < 2u)
  {
    return;
  }

  point::ENUPoint previousEdgeDir;
  if (previousEdge != nullptr)
  {
    if (previousEdge->size() < 2u)
    {
      return;
    }
    // decide if edge start point has to be adapted
    previousEdgeDir = previousEdge->at(previousEdge->size() - 1u) - previousEdge->at(previousEdge->size() - 2u);
    auto nextEdgeDir = edge[0] - previousEdge->at(previousEdge->size() - 1u);

    // if the two edges are near to each other or the direction is dramatically different,
    // the start point is overwritten by the end of the previous edge
    if ((point::vectorLength(nextEdgeDir) > point::cEdgePointBorderDistance)
        || (point::vectorDotProduct(previousEdgeDir, nextEdgeDir) < 0.))
    {
      edge[0] = previousEdge->at(previousEdge->size() - 1u);
    }
    else
    {
      previousEdgeDir = nextEdgeDir;
    }
  }
  else
  {
    previousEdgeDir = edge[1] - edge[0];
  }

  std::size_t pointsToDrop = 0u;
  for (std::size_t i = 1u; i < edge.size(); ++i)
  {
    // i-pointsToDrop > 0
    if (pointsToDrop > 0u)
    {
      edge[i - pointsToDrop] = edge[i];
    }
    auto nextEdgeDir = edge[i - pointsToDrop] - edge[i - pointsToDrop - 1];
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
    std::size_t const newEdgeSize = std::max(std::size_t(2u), edge.size() - pointsToDrop);
    edge.resize(newEdgeSize);
  }
}

std::vector<std::size_t>
calcSmallerEdgeIndexPairs(std::vector<physics::ParametricValue> const &biggerEdgeParametricPoints,
                          std::vector<physics::ParametricValue> const &smallerEdgeParametricPoints)
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
  physics::ParametricValue const parametricOffset(
    (pointInterpolatedParametricEdgeOffset - pointBeforeParametricEdgeOffset)
    / (pointAfterParametricEdgeOffset - pointBeforeParametricEdgeOffset));
  return point::vectorInterpolate(pointBefore, pointAfter, parametricOffset);
}

void fillSmallerEdge(point::ENUEdge const &biggerEdge, point::ENUEdge &smallerEdge)
{
  auto const biggerEdgeParametricPoints = getParametricEdgePoints(biggerEdge);
  auto const smallerEdgeParametricPoints = getParametricEdgePoints(smallerEdge);

  auto const smallerEdgeIndices = calcSmallerEdgeIndexPairs(biggerEdgeParametricPoints, smallerEdgeParametricPoints);

  point::ENUEdge newSmallerEdge;
  newSmallerEdge.reserve(biggerEdge.size());
  newSmallerEdge.push_back(smallerEdge.front());
  std::size_t lastWrittenSmallerEdgeIndex = 0u;
  for (std::size_t i = 1u; i < smallerEdgeIndices.size() - 1u; ++i)
  {
    // i-1, i, i+1 indices are valid for smallerEdgeIndices and biggerEdgeParametricPoints

    if ( // smaller point already processed, insert an interpolated
      (smallerEdgeIndices[i] == lastWrittenSmallerEdgeIndex)
      // the point before the last point of the smaller edge is already written, so we have to interpolate till the end
      || (lastWrittenSmallerEdgeIndex == (smallerEdge.size() - 2u)))
    {
      auto interpolatedPoint = interpolatePoint(smallerEdge[lastWrittenSmallerEdgeIndex],
                                                smallerEdge[lastWrittenSmallerEdgeIndex + 1u],
                                                biggerEdgeParametricPoints[i - 1],
                                                biggerEdgeParametricPoints[i],
                                                biggerEdgeParametricPoints[i + 1]);
      newSmallerEdge.push_back(interpolatedPoint);
    }
    else
    {
      lastWrittenSmallerEdgeIndex = smallerEdgeIndices[i];
      newSmallerEdge.push_back(smallerEdge[lastWrittenSmallerEdgeIndex]);
    }
  }
  newSmallerEdge.push_back(smallerEdge.back());
  smallerEdge.swap(newSmallerEdge);
}

void normalizeBorder(ENUBorder &border, ENUBorder const *previousBorder)
{
  if ((border.left.size() < 2u) || (border.right.size() < 2u))
  {
    return;
  }
  if ((previousBorder != nullptr) && (previousBorder->left.size() >= 2u) && (previousBorder->right.size() >= 2u))
  {
    removeDegeneratedEdgePoints(border.left, &previousBorder->left);
    removeDegeneratedEdgePoints(border.right, &previousBorder->right);
  }
  else
  {
    removeDegeneratedEdgePoints(border.left);
    removeDegeneratedEdgePoints(border.right);
  }
  if (border.left.size() == border.right.size())
  {
    return;
  }

  std::vector<std::size_t> smallerEdgeIndices;
  if (border.left.size() > border.right.size())
  {
    fillSmallerEdge(border.left, border.right);
  }
  else
  {
    fillSmallerEdge(border.right, border.left);
  }
}

IndexPairs getIndexPairs(point::ENUEdge const &leftEdge, point::ENUEdge const &rightEdge)
{
  std::size_t const maxSize = std::max(leftEdge.size(), rightEdge.size());
  std::vector<std::size_t> equalIndices;
  equalIndices.reserve(maxSize);
  for (size_t i = 0u; i < maxSize; ++i)
  {
    equalIndices.push_back(i);
  }

  IndexPairs indexPairs;
  if (leftEdge.size() == rightEdge.size())
  {
    indexPairs.leftEdgeIndices = equalIndices;
    indexPairs.rightEdgeIndices.swap(equalIndices);
  }
  else if (leftEdge.size() > rightEdge.size())
  {
    indexPairs.leftEdgeIndices.swap(equalIndices);
    indexPairs.rightEdgeIndices
      = calcSmallerEdgeIndexPairs(getParametricEdgePoints(leftEdge), getParametricEdgePoints(rightEdge));
  }
  else
  {
    indexPairs.leftEdgeIndices
      = calcSmallerEdgeIndexPairs(getParametricEdgePoints(rightEdge), getParametricEdgePoints(leftEdge));
    indexPairs.rightEdgeIndices.swap(equalIndices);
  }
  return indexPairs;
}

point::ENUEdge getLateralAlignmentEdge(ENUBorder const &border, physics::ParametricValue const lateralAlignment)
{
  return point::getLateralAlignmentEdge(border.left, border.right, lateralAlignment);
}

physics::Distance getDistanceEnuPointToLateralAlignmentEdge(point::ENUPoint const &enuPoint,
                                                            point::ENUEdge const &lateralAlignmentEdge)
{
  auto const edgeLength = calcLength(lateralAlignmentEdge);
  auto const parametricOffset = point::findNearestPointOnEdge(lateralAlignmentEdge, edgeLength, enuPoint);
  auto const projectedPoint = point::getParametricPoint(lateralAlignmentEdge, edgeLength, parametricOffset);
  auto const distance = point::distance(projectedPoint, enuPoint);
  return distance;
}

bool areEdgesContinuous(point::ENUEdge const &first, point::ENUEdge const &second)
{
  if ((first.size() < 2u) || (second.size() < 2u))
  {
    return true;
  }

  auto const firstToSecondDistance = point::distance(second.front(), first.back());
  if (firstToSecondDistance < point::cEdgePointBorderDistance)
  {
    return true;
  }
  return false;
}

void performMakeTransitionToSecondEdgeContinuous(point::ENUEdge const &first,
                                                 point::ENUEdge &second,
                                                 point::ENUEdge *secondOtherLane = nullptr)
{
  if (areEdgesContinuous(first, second))
  {
    return;
  }
  auto const firstToSecondVec = second.front() - first.back();
  auto const firstToSecondDistance = point::vectorLength(firstToSecondVec);
  auto const firstToSecondDir = point::vectorNorm(firstToSecondVec);
  auto const firstEndDir = getEdgeEndDirectionalVector(first);
  auto const secondStartDir = getEdgeStartDirectionalVector(second);
  auto const averageEdgeDir = 0.5 * (firstEndDir + secondStartDir);
  double const sinAngle
    = static_cast<double>(point::vectorLength(point::vectorCrossProduct(averageEdgeDir, firstToSecondDir)));
  // the distance of our interpolation changes depend on the offset of the two edges ends and the lateral offset
  // (given by the sine of the angle between the general edge direction and the offset direction)
  // e.g. if the offset is 3m and orthogonal we get a 6m interpolating distance
  auto const interpolatingDistance = sinAngle * 2.0 * firstToSecondDistance;

  auto const secondLength = calcLength(second);

  physics::ParametricValue const parametricInterpolatingDistance(std::min(.95, interpolatingDistance / secondLength));

  auto const secondParametricEdgePoints = getParametricEdgePoints(second);

  std::size_t const newSecondSize = second.size() + 1u;
  point::ENUEdge newSecond;
  newSecond.reserve(newSecondSize);
  point::ENUEdge newOtherSecond;
  if ((secondOtherLane != nullptr) && (secondOtherLane->size() == second.size()))
  {
    newOtherSecond.resize(newSecondSize);
  }
  for (std::size_t i = 1u; i < secondParametricEdgePoints.size(); ++i)
  {
    if (secondParametricEdgePoints[i] >= parametricInterpolatingDistance)
    {
      if (newSecond.empty())
      {
        // first point found

        // take the last point of the first edge
        newSecond.push_back(first.back());

        // calculate the interpolated point
        point::ENUPoint interpolatedPoint = interpolatePoint(second[i - 1],
                                                             second[i],
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
          auto innerInterpolatedPoint = interpolatePoint(newSecond[0],
                                                         interpolatedPoint,
                                                         physics::ParametricValue(0.),
                                                         secondParametricEdgePoints[j],
                                                         parametricInterpolatingDistance);
          newSecond.push_back(innerInterpolatedPoint);
        }

        // then we add the interpolated point
        newSecond.push_back(interpolatedPoint);

        // fill the newOtherSecond lane if available
        if (newOtherSecond.size() > 0u)
        {
          std::size_t j = 0u;
          for (; (j < i) && (j < newOtherSecond.size()) && (j < secondOtherLane->size()); ++j)
          {
            newOtherSecond[j] = secondOtherLane->at(j);
          }
          if ((j < newOtherSecond.size()) && (j < secondOtherLane->size()))
          {
            // same parametric range than the interpolated point
            newOtherSecond[j] = interpolatePoint(secondOtherLane->at(j - 1u),
                                                 secondOtherLane->at(j),
                                                 secondParametricEdgePoints[i - 1],
                                                 parametricInterpolatingDistance,
                                                 secondParametricEdgePoints[i]);
          }
          for (; ((j + 1u) < newOtherSecond.size()) && (j < secondOtherLane->size()); j++)
          {
            newOtherSecond[j + 1u] = secondOtherLane->at(j);
          }
        }
      }
      // add this one
      newSecond.push_back(second[i]);
    }
  }
  second.swap(newSecond);
  if (secondOtherLane != nullptr)
  {
    secondOtherLane->swap(newOtherSecond);
  }
}

void makeTransitionToSecondEdgeContinuous(point::ENUEdge const &first, point::ENUEdge &second)
{
  performMakeTransitionToSecondEdgeContinuous(first, second);
}

void makeTransitionFromFirstEdgeContinuous(point::ENUEdge &first, point::ENUEdge const &second)
{
  if (areEdgesContinuous(first, second))
  {
    return;
  }
  // if actually something has to be calculated, we reverse the edge and let the other function do the job
  point::ENUEdge invertedFirstEdge = first;
  std::reverse(invertedFirstEdge.begin(), invertedFirstEdge.end());
  point::ENUEdge invertedSecondEdge = second;
  std::reverse(invertedSecondEdge.begin(), invertedSecondEdge.end());
  performMakeTransitionToSecondEdgeContinuous(invertedSecondEdge, invertedFirstEdge);
  first = invertedFirstEdge;
  std::reverse(first.begin(), first.end());
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
  ENUBorder invertedFirstBorder;
  invertedFirstBorder.left = first.left;
  invertedFirstBorder.right = first.right;
  std::reverse(invertedFirstBorder.left.begin(), invertedFirstBorder.left.end());
  std::reverse(invertedFirstBorder.right.begin(), invertedFirstBorder.right.end());
  ENUBorder invertedSecondBorder;
  invertedSecondBorder.left = second.left;
  invertedSecondBorder.right = second.right;
  std::reverse(invertedSecondBorder.left.begin(), invertedSecondBorder.left.end());
  std::reverse(invertedSecondBorder.right.begin(), invertedSecondBorder.right.end());
  makeTransitionToSecondBorderContinuous(invertedSecondBorder, invertedFirstBorder);
  first = invertedFirstBorder;
  std::reverse(first.left.begin(), first.left.end());
  std::reverse(first.right.begin(), first.right.end());
}

} // namespace lane
} // namespace map
} // namespace ad
