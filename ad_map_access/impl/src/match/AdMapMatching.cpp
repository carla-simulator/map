// ----------------- BEGIN LICENSE BLOCK ---------------------------------
//
// Copyright (C) 2018-2019 Intel Corporation
//
// SPDX-License-Identifier: MIT
//
// ----------------- END LICENSE BLOCK -----------------------------------

#include "ad/map/match/AdMapMatching.hpp"

#include <algorithm>
#include <functional>
#include "ad/map/access/Logging.hpp"
#include "ad/map/access/Operation.hpp"
#include "ad/map/lane/LaneOperation.hpp"
#include "ad/map/match/MapMatchedOperation.hpp"
#include "ad/map/point/Transform.hpp"
#include "ad/physics/RangeOperation.hpp"

namespace ad {
namespace map {
namespace match {

match::MapMatchedPositionConfidenceList AdMapMatching::findLanesInputChecked(point::ECEFPoint const &ecefPoint,
                                                                             physics::Distance const &distance)
{
  match::MapMatchedPositionConfidenceList mapMatchingResults;
  point::BoundingSphere matchingSphere;
  matchingSphere.center = ecefPoint;
  matchingSphere.radius = distance;
  physics::Probability probabilitySum(0.);
  for (auto laneId : access::getStore().getLanes())
  {
    auto lane = access::getStore().getLanePtr(laneId);

    if (lane)
    {
      if (lane::isNear(*lane, matchingSphere))
      {
        MapMatchedPosition mmpt;
        if (lane::findNearestPointOnLane(*lane, ecefPoint, mmpt))
        {
          if (point::distance(mmpt.matchedPoint, ecefPoint) <= distance)
          {
            mapMatchingResults.push_back(mmpt);
            probabilitySum += mmpt.probability;
          }
        }
      }
    }
  }

  // normalize result probabilities
  if (probabilitySum > physics::Probability(0.01))
  {
    for (auto &mmpt : mapMatchingResults)
    {
      mmpt.probability = mmpt.probability / static_cast<double>(probabilitySum);
    }
  }

  // sort the final results
  std::sort(std::begin(mapMatchingResults),
            std::end(mapMatchingResults),
            [](MapMatchedPosition const &left, MapMatchedPosition const &right) {
              return left.probability > right.probability;
            });

  return mapMatchingResults;
}

match::MapMatchedPositionConfidenceList AdMapMatching::findLanes(point::GeoPoint const &geoPoint,
                                                                 physics::Distance const &distance)
{
  if (!isValid(geoPoint))
  {
    access::getLogger()->error("Invalid Geo Point passed to AdMapMatching::findLanes(): {}", geoPoint);
    return MapMatchedPositionConfidenceList();
  }
  if (!distance.isValid())
  {
    access::getLogger()->error("Invalid radius passed to AdMapMatching::findLanes(): {}", distance);
    return MapMatchedPositionConfidenceList();
  }
  return findLanesInputChecked(point::toECEF(geoPoint), distance);
}

match::MapMatchedPositionConfidenceList AdMapMatching::findLanes(point::ECEFPoint const &ecefPoint,
                                                                 physics::Distance const &distance)
{
  if (!isValid(ecefPoint))
  {
    access::getLogger()->error("Invalid ECEF Point passed to AdMapMatching::findLanes(): {}", ecefPoint);
    return MapMatchedPositionConfidenceList();
  }
  if (!distance.isValid())
  {
    access::getLogger()->error("Invalid radius passed to AdMapMatching::findLanes(): {}", distance);
    return MapMatchedPositionConfidenceList();
  }
  return findLanesInputChecked(ecefPoint, distance);
}

AdMapMatching::AdMapMatching()
{
}

point::ENUHeading AdMapMatching::getLaneENUHeading(MapMatchedPosition const &mapMatchedPosition)
{
  return lane::getLaneENUHeading(mapMatchedPosition);
}

bool AdMapMatching::isLanePartOfRouteHints(lane::LaneId const &laneId)
{
  for (auto const &route : mRouteHints)
  {
    for (auto const &roadSegment : route.roadSegments)
    {
      for (auto const &laneSegment : roadSegment.drivableLaneSegments)
      {
        if (laneSegment.laneInterval.laneId == laneId)
        {
          return true;
        }
      }
    }
  }
  return false;
}

double AdMapMatching::getHeadingFactor(MapMatchedPosition const &matchedPosition)
{
  double headingFactor = 1.0;

  if (mHeadingHints.size() > 0u)
  {
    point::ECEFHeading const laneDrivingDirection = lane::getLaneECEFHeading(matchedPosition);
    for (auto const &headingHint : mHeadingHints)
    {
      // -1 <= dot product <= 1  (cosine between the two directional vectors)
      auto dotProduct = headingHint * laneDrivingDirection;

      // pushes the 1. <= headingFactor <= mHeadingHintFactor
      double newHeadingFactor = 1. + (dotProduct + 1.) / 2. * mHeadingHintFactor;
      headingFactor = std::max(headingFactor, newHeadingFactor);
    }

    access::getLogger()->trace("getHeadingFactor {}, {}", matchedPosition.lanePoint.paraPoint.laneId, headingFactor);
  }
  return headingFactor;
}

MapMatchedPositionConfidenceList AdMapMatching::getMapMatchedPositions(point::GeoPoint const &geoPoint,
                                                                       physics::Distance const &distance,
                                                                       physics::Probability const &minProbability)
{
  auto mapMatchingResult = findLanes(geoPoint, distance);
  mapMatchingResult = considerMapMatchingHints(mapMatchingResult, minProbability);
  access::getLogger()->trace("MapMatching result {}", mapMatchingResult);
  return mapMatchingResult;
}

MapMatchedPositionConfidenceList AdMapMatching::getMapMatchedPositions(point::ENUPoint const &enuPoint,
                                                                       physics::Distance const &distance,
                                                                       physics::Probability const &minProbability)
{
  return getMapMatchedPositions(point::toGeo(enuPoint), distance, minProbability);
}

MapMatchedPositionConfidenceList AdMapMatching::getMapMatchedPositions(point::ENUPoint const &enuPoint,
                                                                       point::GeoPoint const &enuReferencePoint,
                                                                       physics::Distance const &distance,
                                                                       physics::Probability const &minProbability)
{
  return getMapMatchedPositions(point::toGeo(enuPoint, enuReferencePoint), distance, minProbability);
}

MapMatchedPositionConfidenceList AdMapMatching::getMapMatchedPositions(ENUObjectPosition const &enuObjectPosition,
                                                                       physics::Distance const &distance,
                                                                       physics::Probability const &minProbability)
{
  addHeadingHint(enuObjectPosition.heading, enuObjectPosition.enuReferencePoint);
  auto mapMatchedPositions = getMapMatchedPositions(
    enuObjectPosition.centerPoint, enuObjectPosition.enuReferencePoint, distance, minProbability);
  clearHeadingHints();
  return mapMatchedPositions;
}

MapMatchedPositionConfidenceList
AdMapMatching::considerMapMatchingHints(MapMatchedPositionConfidenceList const &mapMatchedPositions,
                                        physics::Probability const &minProbability)
{
  access::getLogger()->trace("considerMapMatchingHints {}", mapMatchedPositions);

  // revised probabilities can be > 1. while calculating
  physics::Probability revisedProbabilitySum(0.);
  MapMatchedPositionConfidenceList mapMatchingResults;
  mapMatchingResults.reserve(mapMatchedPositions.size());
  for (auto const &mapMatchingResult : mapMatchedPositions)
  {
    auto revisedProbability = mapMatchingResult.probability;
    if (match::isLaneType(mapMatchingResult.type))
    {
      // probability of lanes on current route are multiplied by a certain factor
      if (isLanePartOfRouteHints(mapMatchingResult.lanePoint.paraPoint.laneId))
      {
        access::getLogger()->trace("AdMapMatching::considerMapMatchingHints {} is on current route",
                                   mapMatchingResult.lanePoint.paraPoint.laneId);
        revisedProbability = revisedProbability * getRouteHintFactor();
      }

      // add heading hint factor
      revisedProbability = revisedProbability * getHeadingFactor(mapMatchingResult);
    }

    revisedProbabilitySum = revisedProbabilitySum + revisedProbability;
    mapMatchingResults.push_back(mapMatchingResult);
    mapMatchingResults.back().probability = revisedProbability;
  }

  // post processing
  do
  {
    auto const probabilityDivisor = revisedProbabilitySum;
    if (probabilityDivisor == physics::Probability(0.))
    {
      break;
    }
    revisedProbabilitySum = physics::Probability(1.);
    size_t writeIndex = 0u;
    for (size_t readIndex = 0u; readIndex < mapMatchingResults.size(); ++readIndex)
    {
      if (writeIndex != readIndex)
      {
        mapMatchingResults[writeIndex] = mapMatchingResults[readIndex];
      }
      mapMatchingResults[writeIndex].probability
        = mapMatchingResults[writeIndex].probability / static_cast<double>(probabilityDivisor);
      if (mapMatchingResults[writeIndex].probability >= minProbability)
      {
        // write index only incremented if new probability is above minProbability
        writeIndex++;
      }
      else
      {
        // otherwise the entry is dropped so the probabilities of the others have to be adapted next loop
        revisedProbabilitySum = revisedProbabilitySum - mapMatchingResults[writeIndex].probability;
      }
    }
    mapMatchingResults.resize(writeIndex);
  } while (revisedProbabilitySum < physics::Probability(1.));

  // sort the final results
  std::sort(std::begin(mapMatchingResults),
            std::end(mapMatchingResults),
            [](MapMatchedPosition const &left, MapMatchedPosition const &right) {
              return left.probability > right.probability;
            });
  return mapMatchingResults;
}

MapMatchedObjectBoundingBox AdMapMatching::getMapMatchedBoundingBox(ENUObjectPosition const &enuObjectPosition,
                                                                    physics::Distance const &distance,
                                                                    physics::Probability const &minProbability,
                                                                    physics::Distance const &samplingDistance)
{
  MapMatchedObjectBoundingBox mapMatchedObjectBoundingBox;

  point::ENUPoint directionalVector;
  point::ENUPoint orthogonalVector;
  point::getDirectionVectorsZPlane(enuObjectPosition.heading, directionalVector, orthogonalVector);

  point::ENUPoint directionalLength = directionalVector * (0.5 * enuObjectPosition.dimension.length);
  point::ENUPoint directionalWidth = orthogonalVector * (0.5 * enuObjectPosition.dimension.width);

  point::ENUPoint referencePoints[int32_t(ObjectReferencePoints::NumPoints)];

  referencePoints[int32_t(ObjectReferencePoints::Center)] = enuObjectPosition.centerPoint;

  referencePoints[int32_t(ObjectReferencePoints::FrontLeft)]
    = (enuObjectPosition.centerPoint + directionalLength) + directionalWidth;
  referencePoints[int32_t(ObjectReferencePoints::FrontRight)]
    = (enuObjectPosition.centerPoint + directionalLength) - directionalWidth;
  referencePoints[int32_t(ObjectReferencePoints::RearLeft)]
    = (enuObjectPosition.centerPoint - directionalLength) + directionalWidth;
  referencePoints[int32_t(ObjectReferencePoints::RearRight)]
    = (enuObjectPosition.centerPoint - directionalLength) - directionalWidth;

  mapMatchedObjectBoundingBox.referencePointPositions.resize(size_t(ObjectReferencePoints::NumPoints));

  for (size_t i = 0; i < size_t(ObjectReferencePoints::NumPoints); i++)
  {
    mapMatchedObjectBoundingBox.referencePointPositions[i]
      = getMapMatchedPositions(referencePoints[i], enuObjectPosition.enuReferencePoint, distance, minProbability);

    addLaneRegions(mapMatchedObjectBoundingBox.laneOccupiedRegions,
                   mapMatchedObjectBoundingBox.referencePointPositions[i]);
  }

  physics::Distance const stride = std::max(samplingDistance, physics::Distance(0.1));

  point::ENUPoint const lengthStrideVector = directionalVector * stride;
  point::ENUPoint const widthStrideVector = orthogonalVector * stride;

  point::ENUPoint widthStartPos = referencePoints[int32_t(ObjectReferencePoints::FrontLeft)];

  for (auto j = stride; j < enuObjectPosition.dimension.width; j += stride)
  {
    point::ENUPoint currentPoint = widthStartPos;
    for (auto i = stride; i < enuObjectPosition.dimension.length; i += stride)
    {
      currentPoint = currentPoint - lengthStrideVector;

      MapMatchedPositionConfidenceList mapMatchedPositions
        = getMapMatchedPositions(currentPoint, enuObjectPosition.enuReferencePoint, distance, minProbability);
      addLaneRegions(mapMatchedObjectBoundingBox.laneOccupiedRegions, mapMatchedPositions);
    }
    widthStartPos = widthStartPos - widthStrideVector;
  }

  return mapMatchedObjectBoundingBox;
}

LaneOccupiedRegionList AdMapMatching::getLaneOccupiedRegions(std::vector<ENUObjectPosition> enuObjectPositions,
                                                             physics::Distance const &distance,
                                                             physics::Probability const &minProbability,
                                                             physics::Distance const &samplingDistance)
{
  LaneOccupiedRegionList laneOccupiedRegions;

  for (auto const &objectPosition : enuObjectPositions)
  {
    auto const mapMatchedBoundingBox
      = getMapMatchedBoundingBox(objectPosition, distance, minProbability, samplingDistance);
    addLaneRegions(laneOccupiedRegions, mapMatchedBoundingBox.laneOccupiedRegions);
  }
  return laneOccupiedRegions;
}

void AdMapMatching::addLaneRegions(LaneOccupiedRegionList &laneOccupiedRegions,
                                   MapMatchedPositionConfidenceList const &mapMatchedPositions)
{
  for (auto const &currentPosition : mapMatchedPositions)
  {
    physics::ParametricValue const currentLaterOffset(static_cast<double>(currentPosition.lanePoint.lateralT));

    if (withinValidInputRange(currentLaterOffset, false))
    {
      auto search = std::find_if(std::begin(laneOccupiedRegions),
                                 std::end(laneOccupiedRegions),
                                 [currentPosition](LaneOccupiedRegion const &region) {
                                   return region.laneId == currentPosition.lanePoint.paraPoint.laneId;
                                 });

      if (search != laneOccupiedRegions.end())
      {
        unionRangeWith(search->longitudinalRange, currentPosition.lanePoint.paraPoint.parametricOffset);
        unionRangeWith(search->lateralRange, currentLaterOffset);
      }
      else
      {
        LaneOccupiedRegion laneRegion;
        laneRegion.laneId = currentPosition.lanePoint.paraPoint.laneId;
        laneRegion.longitudinalRange.maximum = currentPosition.lanePoint.paraPoint.parametricOffset;
        laneRegion.longitudinalRange.minimum = currentPosition.lanePoint.paraPoint.parametricOffset;
        laneRegion.lateralRange.maximum = currentLaterOffset;
        laneRegion.lateralRange.minimum = currentLaterOffset;
        laneOccupiedRegions.push_back(laneRegion);
      }
    }
  }
}

void AdMapMatching::addLaneRegions(LaneOccupiedRegionList &laneOccupiedRegions,
                                   LaneOccupiedRegionList const &otherLaneOccupiedRegions)
{
  for (auto const &otherRegion : otherLaneOccupiedRegions)
  {
    auto search
      = std::find_if(std::begin(laneOccupiedRegions),
                     std::end(laneOccupiedRegions),
                     [otherRegion](LaneOccupiedRegion const &region) { return region.laneId == otherRegion.laneId; });

    if (search != laneOccupiedRegions.end())
    {
      unionRangeWith(search->longitudinalRange, otherRegion.longitudinalRange);
      unionRangeWith(search->lateralRange, otherRegion.lateralRange);
    }
    else
    {
      laneOccupiedRegions.push_back(otherRegion);
    }
  }
}

} // namespace match
} // namespace map
} // namespace ad
