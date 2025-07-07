// ----------------- BEGIN LICENSE BLOCK ---------------------------------
//
// Copyright (C) 2020-2021 Intel Corporation
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
      if (mmpt.matched_point_distance <= distance)
      {
        mapMatchingResults.push_back(mmpt);
        probabilitySum += mmpt.probability;
      }
    }
  }
  normalizeResults(mapMatchingResults, probabilitySum);
  return mapMatchingResults;
}

void AdMapMatching::normalizeResults(match::MapMatchedPositionConfidenceList &mapMatchingResults,
                                     physics::Probability const &probabilitySum)
{
  // normalize result probabilities
  if (probabilitySum > physics::Probability(0.01))
  {
    for (auto &mmpt : mapMatchingResults)
    {
      mmpt.probability = mmpt.probability / probabilitySum.mProbability;
    }
  }

  // sort the final results
  std::sort(std::begin(mapMatchingResults),
            std::end(mapMatchingResults),
            [](MapMatchedPosition const &left, MapMatchedPosition const &right) {
              return left.probability > right.probability;
            });
}

std::vector<lane::Lane::ConstPtr>
AdMapMatching::getRelevantLanesInputChecked(point::ECEFPoint const &ecefPoint,
                                            physics::Distance const &distance,
                                            ::ad::map::lane::LaneIdSet const &relevantLaneSet)
{
  std::vector<lane::Lane::ConstPtr> relevantLanes;
  if (!relevantLaneSet.empty())
  {
    for (auto lane_id : relevantLaneSet)
    {
      auto lane = access::getStore().getLanePtr(lane_id);
      if (lane)
      {
        relevantLanes.push_back(lane);
      }
    }
  }
  else
  {
    point::BoundingSphere matchingSphere;
    matchingSphere.center = ecefPoint;
    matchingSphere.radius = distance;
    for (auto lane_id : access::getStore().getLanes())
    {
      auto lane = access::getStore().getLanePtr(lane_id);

      if (lane)
      {
        if (lane::isNear(*lane, matchingSphere))
        {
          relevantLanes.push_back(lane);
        }
      }
    }
  }

  return relevantLanes;
}

match::MapMatchedPositionConfidenceList
AdMapMatching::findLanesInputCheckedAltitudeUnknown(point::GeoPoint const &geo_point,
                                                    physics::Distance const &distance,
                                                    ::ad::map::lane::LaneIdSet const &relevant_lane_set)
{
  lane::LaneIdList relevant_lanes;
  if (!relevant_lane_set.empty())
  {
    relevant_lanes.insert(relevant_lanes.begin(), relevant_lane_set.begin(), relevant_lane_set.end());
  }
  else
  {
    relevant_lanes = access::getStore().getLanes();
  }
  match::MapMatchedPositionConfidenceList map_matching_results;
  physics::Probability probability_sum(0.);
  for (auto lane_id : relevant_lanes)
  {
    auto lane = access::getStore().getLanePtr(lane_id);
    if (lane)
    {
      auto const altitude_range = calcLaneAltitudeRange(*lane);
      auto geo_point_check = geo_point;
      auto const altitude_delta_2 = (altitude_range.maximum - altitude_range.minimum) / 2.;
      geo_point_check.altitude = altitude_range.minimum + altitude_delta_2;
      point::BoundingSphere matchingSphere;
      matchingSphere.center = point::toECEF(geo_point_check);
      matchingSphere.radius = distance + physics::Distance(altitude_delta_2.mAltitude);
      if (lane::isNear(*lane, matchingSphere))
      {
        auto const enuPoint = point::toENU(geo_point_check);
        MapMatchedPosition mmpt;
        if (lane::findNearestPointOnLaneIgnoreZ(*lane, enuPoint, mmpt))
        {
          if (mmpt.matched_point_distance <= distance)
          {
            map_matching_results.push_back(mmpt);
            probability_sum += mmpt.probability;
          }
        }
      }
    }
  }
  normalizeResults(map_matching_results, probability_sum);
  return map_matching_results;
}

match::MapMatchedPositionConfidenceList
AdMapMatching::findLanesInputChecked(point::ECEFPoint const &ecefPoint,
                                     physics::Distance const &distance,
                                     ::ad::map::lane::LaneIdSet const &relevantLaneSet)
{
  return findLanesInputChecked(getRelevantLanesInputChecked(ecefPoint, distance, relevantLaneSet), ecefPoint, distance);
}

match::MapMatchedPositionConfidenceList AdMapMatching::findLanes(point::GeoPoint const &geo_point,
                                                                 physics::Distance const &distance,
                                                                 ::ad::map::lane::LaneIdSet const &relevantLaneSet)
{
  if (!distance.isValid())
  {
    access::getLogger()->error("Invalid radius passed to AdMapMatching::findLanes(): {}", distance);
    return MapMatchedPositionConfidenceList();
  }
  if (geo_point.altitude == point::AltitudeUnknown)
  {
    if (!withinValidInputRange(geo_point.latitude) || !withinValidInputRange(geo_point.longitude))
    {
      access::getLogger()->error(
        "Invalid Latitude/Longitude of Geo Point passed to AdMapMatching::findLanes() with AltitudeUnknown: {}",
        geo_point);
      return MapMatchedPositionConfidenceList();
    }
    return findLanesInputCheckedAltitudeUnknown(geo_point, distance, relevantLaneSet);
  }
  else
  {
    if (!isValid(geo_point))
    {
      access::getLogger()->error("Invalid Geo Point passed to AdMapMatching::findLanes(): {}", geo_point);
      return MapMatchedPositionConfidenceList();
    }
    return findLanesInputChecked(point::toECEF(geo_point), distance, relevantLaneSet);
  }
}

match::MapMatchedPositionConfidenceList AdMapMatching::findLanes(point::ECEFPoint const &ecefPoint,
                                                                 physics::Distance const &distance,
                                                                 ::ad::map::lane::LaneIdSet const &relevantLaneSet)
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
  return findLanesInputChecked(ecefPoint, distance, relevantLaneSet);
}

AdMapMatching::AdMapMatching()
{
}

point::ENUHeading AdMapMatching::getLaneENUHeading(MapMatchedPosition const &mapMatchedPosition) const
{
  return lane::getLaneENUHeading(mapMatchedPosition);
}

bool AdMapMatching::isLanePartOfRouteHints(lane::LaneId const &lane_id) const
{
  for (auto const &route : mRouteHints)
  {
    for (auto const &roadSegment : route.road_segments)
    {
      for (auto const &laneSegment : roadSegment.drivable_lane_segments)
      {
        if (laneSegment.lane_interval.lane_id == lane_id)
        {
          return true;
        }
      }
    }
  }
  return false;
}

double AdMapMatching::getHeadingFactor(MapMatchedPosition const &matchedPosition) const
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

    access::getLogger()->trace("getHeadingFactor {}, {}", matchedPosition.lane_point.para_point.lane_id, headingFactor);
  }
  return headingFactor;
}

MapMatchedPositionConfidenceList AdMapMatching::getMapMatchedPositions(point::GeoPoint const &geo_point,
                                                                       physics::Distance const &distance,
                                                                       physics::Probability const &minProbability) const
{
  auto mapMatchingResult = findLanes(geo_point, distance, mRelevantLanes);
  mapMatchingResult = considerMapMatchingHints(mapMatchingResult, minProbability);
  access::getLogger()->trace("MapMatching result {}", mapMatchingResult);
  return mapMatchingResult;
}

MapMatchedPositionConfidenceList AdMapMatching::getMapMatchedPositions(point::ENUPoint const &enuPoint,
                                                                       physics::Distance const &distance,
                                                                       physics::Probability const &minProbability) const
{
  return getMapMatchedPositions(point::toGeo(enuPoint), distance, minProbability);
}

MapMatchedPositionConfidenceList AdMapMatching::getMapMatchedPositions(point::ENUPoint const &enuPoint,
                                                                       point::GeoPoint const &enu_reference_point,
                                                                       physics::Distance const &distance,
                                                                       physics::Probability const &minProbability) const
{
  return getMapMatchedPositions(point::toGeo(enuPoint, enu_reference_point), distance, minProbability);
}

MapMatchedPositionConfidenceList AdMapMatching::getMapMatchedPositions(ENUObjectPosition const &enuObjectPosition,
                                                                       physics::Distance const &distance,
                                                                       physics::Probability const &minProbability)
{
  addHeadingHint(enuObjectPosition.heading, enuObjectPosition.enu_reference_point);
  auto mapMatchedPositions = getMapMatchedPositions(
    enuObjectPosition.center_point, enuObjectPosition.enu_reference_point, distance, minProbability);
  clearHeadingHints();
  return mapMatchedPositions;
}

MapMatchedPositionConfidenceList
AdMapMatching::considerMapMatchingHints(MapMatchedPositionConfidenceList const &mapMatchedPositions,
                                        physics::Probability const &minProbability) const
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
      if (isLanePartOfRouteHints(mapMatchingResult.lane_point.para_point.lane_id))
      {
        access::getLogger()->trace("AdMapMatching::considerMapMatchingHints {} is on current route",
                                   mapMatchingResult.lane_point.para_point.lane_id);
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
        = mapMatchingResults[writeIndex].probability / probabilityDivisor.mProbability;
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

MapMatchedObjectBoundingBox
AdMapMatching::getMapMatchedBoundingBox(ENUObjectPosition const &enuObjectPosition,
                                        physics::Distance const &sampling_distance,
                                        physics::Distance const &allowedObjectDistanceToLane) const
{
  MapMatchedObjectBoundingBox mapMatchedObjectBoundingBox;
  mapMatchedObjectBoundingBox.sampling_distance = sampling_distance;
  mapMatchedObjectBoundingBox.match_radius = (0.5 * enuObjectPosition.dimension.length)
    + (0.5 * enuObjectPosition.dimension.width) + (0.5 * enuObjectPosition.dimension.height)
    + std::fabs(allowedObjectDistanceToLane);

  // if the vehicle covers multiple lanes
  // the occupied regions usually don't span up to the borders
  // To ensure that longitudinally and laterally we don't miss parts of the lane in
  // between the the sampling points, we have to ensure: point matching distance >= sampling distance

  // directly calculate in ECEF to get rid of unnecessary coordinate transformations
  point::ENUPoint directionalVectorENU;
  point::ENUPoint orthogonalVectorENU;
  point::getDirectionVectorsZPlane(enuObjectPosition.heading, directionalVectorENU, orthogonalVectorENU);

  point::ECEFPoint const start = toECEF(enuObjectPosition.enu_reference_point);
  point::ECEFPoint const directionalVectorEnd = toECEF(directionalVectorENU, enuObjectPosition.enu_reference_point);
  point::ECEFPoint const directionalVector = vectorNorm(directionalVectorEnd - start);
  point::ECEFPoint const orthogonalVectorEnd = toECEF(orthogonalVectorENU, enuObjectPosition.enu_reference_point);
  point::ECEFPoint const orthogonalVector = vectorNorm(orthogonalVectorEnd - start);

  point::ECEFPoint directionalLength = directionalVector * (0.5 * enuObjectPosition.dimension.length);
  point::ECEFPoint directionalWidth = orthogonalVector * (0.5 * enuObjectPosition.dimension.width);

  point::ECEFPoint referencePoints[int32_t(ObjectReferencePoints::NumPoints)];

  referencePoints[int32_t(ObjectReferencePoints::Center)]
    = toECEF(enuObjectPosition.center_point, enuObjectPosition.enu_reference_point);

  referencePoints[int32_t(ObjectReferencePoints::FrontLeft)]
    = (referencePoints[int32_t(ObjectReferencePoints::Center)] + directionalLength) + directionalWidth;
  referencePoints[int32_t(ObjectReferencePoints::FrontRight)]
    = (referencePoints[int32_t(ObjectReferencePoints::Center)] + directionalLength) - directionalWidth;
  referencePoints[int32_t(ObjectReferencePoints::RearLeft)]
    = (referencePoints[int32_t(ObjectReferencePoints::Center)] - directionalLength) + directionalWidth;
  referencePoints[int32_t(ObjectReferencePoints::RearRight)]
    = (referencePoints[int32_t(ObjectReferencePoints::Center)] - directionalLength) - directionalWidth;

  if (!sampling_distance.isValid())
  {
    access::getLogger()->error("Invalid sampling distance passed to AdMapMatching::getMapMatchedBoundingBox(): {}",
                               sampling_distance);
    return mapMatchedObjectBoundingBox;
  }
  for (size_t i = 0; i < size_t(ObjectReferencePoints::NumPoints); i++)
  {
    if (!isValid(referencePoints[i]))
    {
      access::getLogger()->error(
        "Invalid reference point within AdMapMatching::getMapMatchedBoundingBox(): {} {} current ENU reference {}",
        referencePoints[i],
        std::to_string(enuObjectPosition),
        ad::map::access::getENUReferencePoint());
      return mapMatchedObjectBoundingBox;
    }
  }

  // filter lanes on large scale first
  auto const relevantLanes = getRelevantLanesInputChecked(
    referencePoints[int32_t(ObjectReferencePoints::Center)], mapMatchedObjectBoundingBox.match_radius, mRelevantLanes);

  mapMatchedObjectBoundingBox.reference_point_positions.resize(size_t(ObjectReferencePoints::NumPoints));

  // we have to ensure that the confidence list used for the calculation of the lane regions
  // covers ALL matching samples at once!
  // Otherwise the fill-up to inner borders of the region is not working properly
  MapMatchedPositionConfidenceList regionConfidenceList;
  for (size_t i = 0; i < size_t(ObjectReferencePoints::NumPoints); i++)
  {
    mapMatchedObjectBoundingBox.reference_point_positions[i]
      = findLanesInputChecked(relevantLanes, referencePoints[i], sampling_distance);
    regionConfidenceList.insert(regionConfidenceList.end(),
                                mapMatchedObjectBoundingBox.reference_point_positions[i].begin(),
                                mapMatchedObjectBoundingBox.reference_point_positions[i].end());
  }

  // calculate actual sampling stride
  // stride below 10cm doesn't actually make sense
  physics::Distance const stride = std::max(sampling_distance, physics::Distance(0.1));

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
        = findLanesInputChecked(relevantLanes, currentPoint, sampling_distance);
      regionConfidenceList.insert(regionConfidenceList.end(), mapMatchedPositions.begin(), mapMatchedPositions.end());

      currentPoint = currentPoint - lengthStrideVector;
    }
    widthStartPos = widthStartPos - widthStrideVector;
  }

  addLaneRegions(mapMatchedObjectBoundingBox.lane_occupied_regions, regionConfidenceList);

  access::getLogger()->trace("getMapMatchedBoundingBox result {}", mapMatchedObjectBoundingBox);

  return mapMatchedObjectBoundingBox;
}

LaneOccupiedRegionList AdMapMatching::getLaneOccupiedRegions(std::vector<ENUObjectPosition> enuObjectPositions,
                                                             physics::Distance const &sampling_distance) const
{
  LaneOccupiedRegionList lane_occupied_regions;

  for (auto const &objectPosition : enuObjectPositions)
  {
    auto const map_matched_bounding_box = getMapMatchedBoundingBox(objectPosition, sampling_distance);
    addLaneRegions(lane_occupied_regions, map_matched_bounding_box.lane_occupied_regions);
  }
  return lane_occupied_regions;
}

void AdMapMatching::addLaneRegions(LaneOccupiedRegionList &lane_occupied_regions,
                                   MapMatchedPositionConfidenceList const &mapMatchedPositions)
{
  // Basic algorithm:
  // First, collect all actual matches within the respective lane (lateral AND longitudinal)
  // Second, ensure all inner-regions are expanded to the borders (lateral AND longitudinal)

  // 1. collect matches within the lane
  std::map<lane::LaneId, physics::ParametricValue> longitudinalBorderMatches;
  for (auto const &currentPosition : mapMatchedPositions)
  {
    // only consider actual lateral in lane matches
    if (isLateralInLaneMatch(currentPosition))
    {
      physics::ParametricValue const currentLateralOffset(currentPosition.lane_point.lateral_t.mRatioValue);

      if (isLongitudinalInLaneMatch(currentPosition))
      {
        // 1.a longitudinal in lane
        auto search = std::find_if(std::begin(lane_occupied_regions),
                                   std::end(lane_occupied_regions),
                                   [currentPosition](LaneOccupiedRegion const &region) {
                                     return region.lane_id == currentPosition.lane_point.para_point.lane_id;
                                   });

        if (search != lane_occupied_regions.end())
        {
          unionRangeWith(search->longitudinal_range, currentPosition.lane_point.para_point.parametric_offset);
          unionRangeWith(search->lateral_range, currentLateralOffset);
        }
        else
        {
          LaneOccupiedRegion laneRegion;
          laneRegion.lane_id = currentPosition.lane_point.para_point.lane_id;
          laneRegion.longitudinal_range.maximum = currentPosition.lane_point.para_point.parametric_offset;
          laneRegion.longitudinal_range.minimum = currentPosition.lane_point.para_point.parametric_offset;
          laneRegion.lateral_range.maximum = currentLateralOffset;
          laneRegion.lateral_range.minimum = currentLateralOffset;
          lane_occupied_regions.push_back(laneRegion);
        }
      }
      else if ((currentPosition.lane_point.para_point.parametric_offset == physics::ParametricValue(0.))
               || (currentPosition.lane_point.para_point.parametric_offset == physics::ParametricValue(1.)))
      {
        // 1.b handle lane segments that are shorter than the sampling distance
        // If we have short lane segment the sampling could jump over it
        // Jumping over would be indicated by out of lane matches before (0.0) AND after (1.0)
        auto insertResult = longitudinalBorderMatches.insert(
          {currentPosition.lane_point.para_point.lane_id, currentPosition.lane_point.para_point.parametric_offset});
        if (!insertResult.second)
        {
          if (insertResult.first->second != currentPosition.lane_point.para_point.parametric_offset)
          {
            // found a short lane segment to be added as a whole
            auto search = std::find_if(std::begin(lane_occupied_regions),
                                       std::end(lane_occupied_regions),
                                       [currentPosition](LaneOccupiedRegion const &region) {
                                         return region.lane_id == currentPosition.lane_point.para_point.lane_id;
                                       });

            if (search != lane_occupied_regions.end())
            {
              // adapt the borders
              search->longitudinal_range.maximum = physics::ParametricValue(1.);
              search->longitudinal_range.minimum = physics::ParametricValue(0.);
            }
            else
            {
              // add the region
              LaneOccupiedRegion laneRegion;
              laneRegion.lane_id = currentPosition.lane_point.para_point.lane_id;
              laneRegion.longitudinal_range.maximum = physics::ParametricValue(1.);
              laneRegion.longitudinal_range.minimum = physics::ParametricValue(0.);
              laneRegion.lateral_range.maximum = currentLateralOffset;
              laneRegion.lateral_range.minimum = currentLateralOffset;
              lane_occupied_regions.push_back(laneRegion);
            }
          }
        }
      }
    }
  }
  // 2. If the vehicle covers multiple lanes the occupied regions usually don't span up to the borders
  // since in the above loop only collects actual matches within the lane
  // Since the likelihood for a match exactly at the border is very low, we have to enlarge
  // the inner regions to cover also the space in between the map matching points
  // This can be achieved by taking the out-of-lane matches into account.
  // (Remember: we ensured that the matching distance >= sampling distance,
  // so that respective out of lane matches are present!)
  for (auto const &currentPosition : mapMatchedPositions)
  {
    if (!isActualWithinLaneMatch(currentPosition))
    {
      auto search = std::find_if(std::begin(lane_occupied_regions),
                                 std::end(lane_occupied_regions),
                                 [currentPosition](LaneOccupiedRegion const &region) {
                                   return region.lane_id == currentPosition.lane_point.para_point.lane_id;
                                 });

      if (search != lane_occupied_regions.end())
      {
        // 2.a in longitudinal direction just perform union (either in-lane and present in each case, or out-of-lane and
        // therefore exactly 1.0 or 0.0)
        unionRangeWith(search->longitudinal_range, currentPosition.lane_point.para_point.parametric_offset);

        // 2.b in lateral direction map out-of-lane to in lane
        if (currentPosition.lane_point.lateral_t >= physics::RatioValue(1.0))
        {
          unionRangeWith(search->lateral_range, physics::ParametricValue(1.0));
        }
        else if (currentPosition.lane_point.lateral_t <= physics::RatioValue(0.0))
        {
          unionRangeWith(search->lateral_range, physics::ParametricValue(0.0));
        }
      }
    }
  }
}

void AdMapMatching::addLaneRegions(LaneOccupiedRegionList &lane_occupied_regions,
                                   LaneOccupiedRegionList const &otherLaneOccupiedRegions) const
{
  for (auto const &otherRegion : otherLaneOccupiedRegions)
  {
    auto search
      = std::find_if(std::begin(lane_occupied_regions),
                     std::end(lane_occupied_regions),
                     [otherRegion](LaneOccupiedRegion const &region) { return region.lane_id == otherRegion.lane_id; });

    if (search != lane_occupied_regions.end())
    {
      unionRangeWith(search->longitudinal_range, otherRegion.longitudinal_range);
      unionRangeWith(search->lateral_range, otherRegion.lateral_range);
    }
    else
    {
      lane_occupied_regions.push_back(otherRegion);
    }
  }
}

MapMatchedPositionConfidenceList AdMapMatching::findRouteLanes(point::ECEFPoint const &ecefPoint,
                                                               route::FullRoute const &route)
{
  if (!isValid(ecefPoint))
  {
    access::getLogger()->error("Invalid ECEF Point passed to AdMapMatching::findLanes(): {}", ecefPoint);
    return MapMatchedPositionConfidenceList();
  }
  match::MapMatchedPositionConfidenceList mapMatchingResults;
  physics::Distance distanceSum(0.);
  for (auto const &roadSegment : route.road_segments)
  {
    for (auto const &laneSegment : roadSegment.drivable_lane_segments)
    {
      MapMatchedPosition mmpt;
      if (lane::findNearestPointOnLaneInterval(laneSegment.lane_interval, ecefPoint, mmpt))
      {
        mapMatchingResults.push_back(mmpt);
        distanceSum += mmpt.matched_point_distance;
      }
    }
  }

  // set the result probabilities in respect to matched point distances
  if (distanceSum > physics::Distance(0.01))
  {
    for (auto &mmpt : mapMatchingResults)
    {
      mmpt.probability = physics::Probability(1.) - physics::Probability(mmpt.matched_point_distance / distanceSum);
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

} // namespace match
} // namespace map
} // namespace ad
