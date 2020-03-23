// ----------------- BEGIN LICENSE BLOCK ---------------------------------
//
// Copyright (C) 2018-2020 Intel Corporation
//
// SPDX-License-Identifier: MIT
//
// ----------------- END LICENSE BLOCK -----------------------------------

#include "ad/map/match/AdMapMatching.hpp"

#include <algorithm>
#include <cmath>
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

match::MapMatchedPositionConfidenceList
AdMapMatching::findLanesInputChecked(std::vector<lane::Lane::ConstPtr> const &relevantLanes,
                                     point::ECEFPoint const &ecefPoint,
                                     physics::Distance const &distance)
{
  match::MapMatchedPositionConfidenceList mapMatchingResults;
  physics::Probability probabilitySum(0.);
  for (auto lane : relevantLanes)
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

std::vector<lane::Lane::ConstPtr> AdMapMatching::getRelevantLanesInputChecked(point::ECEFPoint const &ecefPoint,
                                                                              physics::Distance const &distance)
{
  std::vector<lane::Lane::ConstPtr> relevantLanes;
  point::BoundingSphere matchingSphere;
  matchingSphere.center = ecefPoint;
  matchingSphere.radius = distance;
  for (auto laneId : access::getStore().getLanes())
  {
    auto lane = access::getStore().getLanePtr(laneId);

    if (lane)
    {
      if (lane::isNear(*lane, matchingSphere))
      {
        relevantLanes.push_back(lane);
      }
    }
  }

  return relevantLanes;
}

match::MapMatchedPositionConfidenceList AdMapMatching::findLanesInputChecked(point::ECEFPoint const &ecefPoint,
                                                                             physics::Distance const &distance)
{
  return findLanesInputChecked(getRelevantLanesInputChecked(ecefPoint, distance), ecefPoint, distance);
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
                                                                    physics::Distance const &inSamplingDistance)
{
  MapMatchedObjectBoundingBox mapMatchedObjectBoundingBox;

  // if the vehicle covers multiple lanes
  // the occupied regions usually don't span up to the borders
  // To ensure that longitudinally we don't miss parts of the lane in
  // between the the sampling points, we have to reduce the sampling distance
  // to be not bigger than the matching distance.
  // Longitudinally we get then in-lane matches at the border also from sampling points before or after the lane
  auto samplingDistance = inSamplingDistance;
  if (distance < samplingDistance)
  {
    samplingDistance = distance;
    access::getLogger()->info(
      "AdMapMatching::getMapMatchedBoundingBox Sampling distance {} requested to be larger than matching distance {}."
      "Reducing sampling distance to {} which might have impact the desired run-time. Consider to increase"
      "the matching distance, if appropriate, to reduce run-time again",
      inSamplingDistance,
      distance,
      samplingDistance);
  }

  // directly calculate in ECEF to get rid of unnecessary coordinate transformations
  point::ENUPoint directionalVectorENU;
  point::ENUPoint orthogonalVectorENU;
  point::getDirectionVectorsZPlane(enuObjectPosition.heading, directionalVectorENU, orthogonalVectorENU);

  point::ECEFPoint const start = toECEF(enuObjectPosition.enuReferencePoint);
  point::ECEFPoint const directionalVectorEnd = toECEF(directionalVectorENU, enuObjectPosition.enuReferencePoint);
  point::ECEFPoint const directionalVector = vectorNorm(directionalVectorEnd - start);
  point::ECEFPoint const orthogonalVectorEnd = toECEF(orthogonalVectorENU, enuObjectPosition.enuReferencePoint);
  point::ECEFPoint const orthogonalVector = vectorNorm(orthogonalVectorEnd - start);

  point::ECEFPoint directionalLength = directionalVector * (0.5 * enuObjectPosition.dimension.length);
  point::ECEFPoint directionalWidth = orthogonalVector * (0.5 * enuObjectPosition.dimension.width);

  point::ECEFPoint referencePoints[int32_t(ObjectReferencePoints::NumPoints)];

  referencePoints[int32_t(ObjectReferencePoints::Center)]
    = toECEF(enuObjectPosition.centerPoint, enuObjectPosition.enuReferencePoint);

  referencePoints[int32_t(ObjectReferencePoints::FrontLeft)]
    = (referencePoints[int32_t(ObjectReferencePoints::Center)] + directionalLength) + directionalWidth;
  referencePoints[int32_t(ObjectReferencePoints::FrontRight)]
    = (referencePoints[int32_t(ObjectReferencePoints::Center)] + directionalLength) - directionalWidth;
  referencePoints[int32_t(ObjectReferencePoints::RearLeft)]
    = (referencePoints[int32_t(ObjectReferencePoints::Center)] - directionalLength) + directionalWidth;
  referencePoints[int32_t(ObjectReferencePoints::RearRight)]
    = (referencePoints[int32_t(ObjectReferencePoints::Center)] - directionalLength) - directionalWidth;

  if (!distance.isValid())
  {
    access::getLogger()->error("Invalid distance passed to AdMapMatching::getMapMatchedBoundingBox(): {}", distance);
    return mapMatchedObjectBoundingBox;
  }
  if (!inSamplingDistance.isValid())
  {
    access::getLogger()->error("Invalid sampling distance passed to AdMapMatching::getMapMatchedBoundingBox(): {}",
                               inSamplingDistance);
    return mapMatchedObjectBoundingBox;
  }
  for (size_t i = 0; i < size_t(ObjectReferencePoints::NumPoints); i++)
  {
    if (!isValid(referencePoints[i]))
    {
      access::getLogger()->error("Invalid reference point within AdMapMatching::getMapMatchedBoundingBox(): {}",
                                 referencePoints[i]);
      return mapMatchedObjectBoundingBox;
    }
  }

  // filter lanes on large scale first
  auto const relevantLanes = getRelevantLanesInputChecked(referencePoints[int32_t(ObjectReferencePoints::Center)],
                                                          distance + (0.5 * enuObjectPosition.dimension.length)
                                                            + (0.5 * enuObjectPosition.dimension.width));

  mapMatchedObjectBoundingBox.referencePointPositions.resize(size_t(ObjectReferencePoints::NumPoints));

  // we have to ensure that the confidence list used for the calculation of the lane regions
  // covers ALL matching samples at once!
  // Otherwise the fill-up to inner borders of the region is not working properly
  MapMatchedPositionConfidenceList regionConfidenceList;
  for (size_t i = 0; i < size_t(ObjectReferencePoints::NumPoints); i++)
  {
    mapMatchedObjectBoundingBox.referencePointPositions[i]
      = findLanesInputChecked(relevantLanes, referencePoints[i], distance);
    regionConfidenceList.insert(regionConfidenceList.end(),
                                mapMatchedObjectBoundingBox.referencePointPositions[i].begin(),
                                mapMatchedObjectBoundingBox.referencePointPositions[i].end());
  }

  // calculate actual sampling stride
  // stride below 10cm doesn't actually make sense
  physics::Distance const stride = std::max(samplingDistance, physics::Distance(0.1));

  auto const lengthStrideCount = std::ceil(enuObjectPosition.dimension.length / stride);
  auto const lengthStrideCountUInt = static_cast<uint32_t>(lengthStrideCount);
  auto const lengthStride = enuObjectPosition.dimension.length / lengthStrideCount;
  point::ECEFPoint const lengthStrideVector = directionalVector * lengthStride;

  auto const widthStrideCount = std::ceil(enuObjectPosition.dimension.width / stride);
  auto const widthStrideCountUInt = static_cast<uint32_t>(widthStrideCount);
  auto const widthStride = enuObjectPosition.dimension.width / widthStrideCount;
  point::ECEFPoint const widthStrideVector = orthogonalVector * widthStride;

  point::ECEFPoint widthStartPos = referencePoints[int32_t(ObjectReferencePoints::FrontLeft)];

  for (uint32_t widthStrideNum = 0u; widthStrideNum <= widthStrideCountUInt; widthStrideNum++)
  {
    point::ECEFPoint currentPoint = widthStartPos;
    for (uint32_t lengthStrideNum = 0u; lengthStrideNum <= lengthStrideCountUInt; lengthStrideNum++)
    {
      MapMatchedPositionConfidenceList mapMatchedPositions
        = findLanesInputChecked(relevantLanes, currentPoint, distance);
      regionConfidenceList.insert(regionConfidenceList.end(), mapMatchedPositions.begin(), mapMatchedPositions.end());

      currentPoint = currentPoint - lengthStrideVector;
    }
    widthStartPos = widthStartPos - widthStrideVector;
  }

  addLaneRegions(mapMatchedObjectBoundingBox.laneOccupiedRegions, regionConfidenceList);

  access::getLogger()->trace("getMapMatchedBoundingBox result {}", mapMatchedObjectBoundingBox);

  return mapMatchedObjectBoundingBox;
}

LaneOccupiedRegionList AdMapMatching::getLaneOccupiedRegions(std::vector<ENUObjectPosition> enuObjectPositions,
                                                             physics::Distance const &distance,
                                                             physics::Distance const &samplingDistance)
{
  LaneOccupiedRegionList laneOccupiedRegions;

  for (auto const &objectPosition : enuObjectPositions)
  {
    auto const mapMatchedBoundingBox = getMapMatchedBoundingBox(objectPosition, distance, samplingDistance);
    addLaneRegions(laneOccupiedRegions, mapMatchedBoundingBox.laneOccupiedRegions);
  }
  return laneOccupiedRegions;
}

void AdMapMatching::addLaneRegions(LaneOccupiedRegionList &laneOccupiedRegions,
                                   MapMatchedPositionConfidenceList const &mapMatchedPositions)
{
  for (auto const &currentPosition : mapMatchedPositions)
  {
    physics::ParametricValue const currentLateralOffset(static_cast<double>(currentPosition.lanePoint.lateralT));

    if (withinValidInputRange(currentLateralOffset, false))
    {
      auto search = std::find_if(std::begin(laneOccupiedRegions),
                                 std::end(laneOccupiedRegions),
                                 [currentPosition](LaneOccupiedRegion const &region) {
                                   return region.laneId == currentPosition.lanePoint.paraPoint.laneId;
                                 });

      if (search != laneOccupiedRegions.end())
      {
        unionRangeWith(search->longitudinalRange, currentPosition.lanePoint.paraPoint.parametricOffset);
        unionRangeWith(search->lateralRange, currentLateralOffset);
      }
      else
      {
        LaneOccupiedRegion laneRegion;
        laneRegion.laneId = currentPosition.lanePoint.paraPoint.laneId;
        laneRegion.longitudinalRange.maximum = currentPosition.lanePoint.paraPoint.parametricOffset;
        laneRegion.longitudinalRange.minimum = currentPosition.lanePoint.paraPoint.parametricOffset;
        laneRegion.lateralRange.maximum = currentLateralOffset;
        laneRegion.lateralRange.minimum = currentLateralOffset;
        laneOccupiedRegions.push_back(laneRegion);
      }
    }
  }
  // if the vehicle covers multiple lanes
  // the occupied regions usually don't span up to the borders
  // since in the above loop only (lateral) in-lane matches are considered.
  // But the likelihood for a match exactly at the border is very low!
  // Therefore, we have to enlarge the inner regions to cover also the space
  // in between the map matching points in lateral direction
  // This can be achieved by taking the out-of-lane matches into account
  for (auto const &currentPosition : mapMatchedPositions)
  {
    physics::ParametricValue const currentLaterOffset(static_cast<double>(currentPosition.lanePoint.lateralT));

    if (!withinValidInputRange(currentLaterOffset, false))
    {
      auto search = std::find_if(std::begin(laneOccupiedRegions),
                                 std::end(laneOccupiedRegions),
                                 [currentPosition](LaneOccupiedRegion const &region) {
                                   return region.laneId == currentPosition.lanePoint.paraPoint.laneId;
                                 });

      if (search != laneOccupiedRegions.end())
      {
        if (currentLaterOffset > physics::ParametricValue(1.0))
        {
          unionRangeWith(search->lateralRange, physics::ParametricValue(1.0));
        }
        else if (currentLaterOffset < physics::ParametricValue(0.0))
        {
          unionRangeWith(search->lateralRange, physics::ParametricValue(0.0));
        }
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
