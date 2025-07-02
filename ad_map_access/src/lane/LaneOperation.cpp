// ----------------- BEGIN LICENSE BLOCK ---------------------------------
//
// Copyright (C) 2018-2021 Intel Corporation
//
// SPDX-License-Identifier: MIT
//
// ----------------- END LICENSE BLOCK -----------------------------------

#include "ad/map/lane/LaneOperation.hpp"

#include <algorithm>
#include "LaneOperationPrivate.hpp"
#include "ad/map/access/Factory.hpp"
#include "ad/map/access/Operation.hpp"
#include "ad/map/lane/BorderOperation.hpp"
#include "ad/map/match/AdMapMatching.hpp"
#include "ad/map/match/MapMatchedOperation.hpp"
#include "ad/map/point/Operation.hpp"
#include "ad/map/route/LaneIntervalOperation.hpp"
#include "ad/physics/RangeOperation.hpp"

namespace ad {
namespace map {
namespace lane {

const static physics::Distance cMinLaneDimension(physics::Distance::cPrecisionValue);

Lane::ConstPtr getLanePtr(LaneId const &id)
{
  auto const lane = access::getStore().getLanePtr(id);

  if (!bool(lane))
  {
    throw std::invalid_argument("ad::map::lane::getLane: LaneId not found in store");
  }
  return lane;
}

Lane const &getLane(LaneId const &id)
{
  return *getLanePtr(id);
}

LaneIdList getLanes()
{
  return access::getStore().getLanes();
}

void interpolateHeadingParametricPoints(physics::Distance const &length,
                                        physics::ParametricValue const &headingT,
                                        physics::ParametricValue &longTStart,
                                        physics::ParametricValue &longTEnd)
{
  // we target an area of +- 5cm around the point to determine the heading
  if (length < physics::Distance(0.1))
  {
    longTStart = physics::ParametricValue(0.);
    longTEnd = physics::ParametricValue(1.);
  }
  else
  {
    physics::ParametricValue deltaOffset(physics::Distance(0.1) / length);
    physics::ParametricValue deltaOffsetHalf = deltaOffset / 2.;
    if (headingT > physics::ParametricValue(1.) - deltaOffsetHalf)
    {
      longTStart = physics::ParametricValue(1.) - deltaOffset;
      longTEnd = physics::ParametricValue(1.);
    }
    else if (headingT < deltaOffsetHalf)
    {
      longTStart = physics::ParametricValue(0.);
      longTEnd = deltaOffset;
    }
    else
    {
      longTStart = headingT - deltaOffsetHalf;
      longTEnd = headingT + deltaOffsetHalf;
    }
  }
}

point::ECEFHeading getLaneECEFDirection(Lane const &lane, point::ParaPoint const &para_point)
{
  physics::ParametricValue longTStart;
  physics::ParametricValue longTEnd;
  interpolateHeadingParametricPoints(lane.length, para_point.parametric_offset, longTStart, longTEnd);

  point::ECEFPoint const laneDirStart = getParametricPoint(lane, longTStart, physics::ParametricValue(.5));
  point::ECEFPoint const laneDirEnd = getParametricPoint(lane, longTEnd, physics::ParametricValue(.5));
  point::ECEFHeading const laneDirection = point::createECEFHeading(laneDirStart, laneDirEnd);
  return laneDirection;
}

point::ECEFHeading getLaneECEFHeading(match::MapMatchedPosition const &mapMatchedPosition)
{
  return getLaneECEFHeading(mapMatchedPosition.lane_point.para_point);
}

point::ECEFHeading getLaneECEFHeading(point::ParaPoint const &para_point)
{
  auto lane = getLane(para_point.lane_id);

  point::ECEFHeading laneDrivingDirection = getLaneECEFDirection(lane, para_point);
  if (!isLaneDirectionPositive(lane))
  {
    laneDrivingDirection = -1. * laneDrivingDirection;
  }
  return laneDrivingDirection;
}

point::ENUHeading getLaneENUHeading(match::MapMatchedPosition const &mapMatchedPosition)
{
  const auto gnssReference = access::getENUReferencePoint();
  return point::createENUHeading(getLaneECEFHeading(mapMatchedPosition), gnssReference);
}

point::ENUHeading getLaneENUHeading(point::ParaPoint const &para_point, point::GeoPoint const &gnssReference)
{
  return point::createENUHeading(getLaneECEFHeading(para_point), gnssReference);
}

point::ParaPoint uniqueParaPoint(point::GeoPoint const &geo_point)
{
  match::AdMapMatching mapMatching;
  auto mapMatchingResult
    = mapMatching.getMapMatchedPositions(geo_point, physics::Distance(0.1), physics::Probability(0.5));

  if (mapMatchingResult.size() == 0u)
  {
    throw std::runtime_error("uniqueLaneId: position doesn't match any lane within 0.1 meters");
  }
  if (mapMatchingResult.size() != 1u)
  {
    throw std::runtime_error("uniqueLaneId: position matches multiple lanes");
  }

  return mapMatchingResult[0].lane_point.para_point;
}

LaneId uniqueLaneId(point::GeoPoint const &geo_point)
{
  return uniqueParaPoint(geo_point).lane_id;
}

physics::Distance getWidth(Lane const &lane, physics::ParametricValue const &longitudinalOffset)
{
  physics::Distance width(0.);
  point::ECEFPoint pointOnLeftEdge;
  point::ECEFPoint pointOnRightEdge;
  if (projectParametricPointToEdges(lane, longitudinalOffset, pointOnLeftEdge, pointOnRightEdge))
  {
    width = distance(pointOnLeftEdge, pointOnRightEdge);
  }
  return width;
}

restriction::SpeedLimitList getSpeedLimits(Lane const &lane, physics::ParametricRange const &range)
{
  restriction::SpeedLimitList speed_limits;
  for (auto const &speed_limit : lane.speed_limits)
  {
    if (doRangesOverlap(speed_limit.lane_piece, range))
    {
      speed_limits.push_back(speed_limit);
    }
  }
  return speed_limits;
}

physics::Speed getMaxSpeed(Lane const &lane, physics::ParametricRange const &range)
{
  physics::Speed maxSpeed(0.);
  for (auto const &speed_limit : getSpeedLimits(lane, range))
  {
    maxSpeed = std::max(maxSpeed, speed_limit.speed_limit);
  }
  if (maxSpeed == physics::Speed(0.))
  {
    maxSpeed = std::numeric_limits<physics::Speed>::max();
  }
  return maxSpeed;
}

physics::Duration getDuration(Lane const &lane, physics::ParametricRange const &range)
{
  physics::Duration laneMinDuration{0.};
  physics::Distance coveredDurationDistance{0.};
  for (auto const &speed_limit : lane.speed_limits)
  {
    auto const intersectedRange = getIntersectionRange(speed_limit.lane_piece, range);
    if (isRangeValid(intersectedRange))
    {
      physics::Distance const speedLimitDistance = (intersectedRange.maximum - intersectedRange.minimum) * lane.length;
      physics::Speed speedLimitValue = std::numeric_limits<physics::Speed>::max();
      if (speed_limit.speed_limit > physics::Speed(0.))
      {
        speedLimitValue = speed_limit.speed_limit;
      }
      physics::Duration const speedLimitDuration = speedLimitDistance / speedLimitValue;
      laneMinDuration += speedLimitDuration;
      coveredDurationDistance += speedLimitDistance;
    }
  }
  physics::Distance const remainingDistance = (range.maximum - range.minimum) * lane.length - coveredDurationDistance;
  if (remainingDistance > physics::Distance(0.))
  {
    physics::Duration const speedLimitDuration = remainingDistance / getMaxSpeed(lane, range);
    laneMinDuration += speedLimitDuration;
  }
  return laneMinDuration;
}

ContactLaneList getContactLanes(Lane const &lane, ContactLocation const &location)
{
  if (location == ContactLocation::INVALID)
  {
    std::runtime_error("LaneOperation::getContactLanes() location is INVALID");
  }
  ContactLaneList contact_lanes;
  for (auto const &contactLane : lane.contact_lanes)
  {
    if (contactLane.location == location)
    {
      contact_lanes.push_back(contactLane);
    }
  }
  return contact_lanes;
}

ContactLaneList getContactLanes(Lane const &lane, ContactLocationList const &locations)
{
  ContactLaneList contact_lanes;
  for (auto const &location : locations)
  {
    auto const locationContactLanes = getContactLanes(lane, location);
    contact_lanes.insert(std::begin(contact_lanes), std::begin(locationContactLanes), std::end(locationContactLanes));
  }
  return contact_lanes;
}

ContactLocation getContactLocation(Lane const &lane, LaneId const &toLaneId)
{
  if (isValid(toLaneId))
  {
    for (auto const &contact_lane : lane.contact_lanes)
    {
      if (contact_lane.to_lane == toLaneId)
      {
        return contact_lane.location;
      }
    }
  }
  return ContactLocation::INVALID;
}

ContactLaneList getContactLane(Lane const &lane, LaneId const &toLaneId)
{
  ContactLaneList resultContact;

  if (isValid(toLaneId))
  {
    for (auto const &contact_lane : lane.contact_lanes)
    {
      if (contact_lane.to_lane == toLaneId)
      {
        resultContact.push_back(contact_lane);
      }
    }
  }
  return resultContact;
}

bool switchLaneContact(LaneId const &from_lane_id,
                       LaneId const &to_lane_id,
                       ContactType const &old_contact,
                       ContactType const &new_contact)
{
  access::Factory factory(access::getStore());
  return factory.changeLaneContact(from_lane_id, to_lane_id, old_contact, new_contact);
}

bool correctLaneBorder(LaneId const &from_lane_id, LaneId const &to_lane_id)
{
  access::Factory factory(access::getStore());
  return factory.correctLaneBorder(from_lane_id, to_lane_id);
}

point::ECEFPoint getParametricPoint(Lane const &lane,
                                    physics::ParametricValue const &longitudinalOffset,
                                    physics::ParametricValue const &lateralOffset)
{
  point::ECEFPoint const pt0 = getParametricPoint(lane.edge_left, longitudinalOffset);
  if (isValid(pt0))
  {
    point::ECEFPoint const pt1 = getParametricPoint(lane.edge_right, longitudinalOffset);
    if (isValid(pt1))
    {
      return point::vectorInterpolate(pt0, pt1, lateralOffset);
    }
  }
  return point::ECEFPoint();
}

bool projectParametricPointToEdges(Lane const &lane,
                                   point::ECEFPoint const &referencePoint,
                                   point::ECEFPoint &pointOnLeftEdge,
                                   point::ECEFPoint &pointOnRightEdge)
{
  if (isValid(referencePoint))
  {
    auto const longTLeft = findNearestPointOnEdge(lane.edge_left, referencePoint);
    if (isRangeValid(longTLeft))
    {
      auto const longTRight = findNearestPointOnEdge(lane.edge_right, referencePoint);
      if (isRangeValid(longTRight))
      {
        pointOnLeftEdge = getParametricPoint(lane.edge_left, longTLeft);
        pointOnRightEdge = getParametricPoint(lane.edge_right, longTRight);
        return isValid(pointOnLeftEdge) && isValid(pointOnRightEdge);
      }
    }
  }
  return false;
}

bool projectParametricPointToEdges(Lane const &lane,
                                   physics::ParametricValue const &longitudinalOffset,
                                   point::ECEFPoint &pointOnLeftEdge,
                                   point::ECEFPoint &pointOnRightEdge)
{
  point::ECEFPoint const center_point = getParametricPoint(lane, longitudinalOffset, physics::ParametricValue(0.5));
  return projectParametricPointToEdges(lane, center_point, pointOnLeftEdge, pointOnRightEdge);
}

point::ECEFPoint getProjectedParametricPoint(Lane const &lane,
                                             physics::ParametricValue const &longitudinalOffset,
                                             physics::ParametricValue const &lateralOffset)
{
  point::ECEFPoint pt0;
  point::ECEFPoint pt1;
  bool projectionResult = projectParametricPointToEdges(lane, longitudinalOffset, pt0, pt1);
  if (projectionResult)
  {
    return point::vectorInterpolate(pt0, pt1, lateralOffset);
  }
  return point::ECEFPoint();
}

bool isPyhsicalSuccessor(Lane const &lane, const Lane &other)
{
  if (isSuccessor(lane.edge_left, other.edge_left) && isSuccessor(lane.edge_right, other.edge_right))
  {
    return true;
  }
  if (isSuccessor(lane.edge_left, other.edge_right) && isSuccessor(lane.edge_right, other.edge_left))
  {
    return true;
  }
  if (isVanishingLaneStart(lane) || isVanishingLaneEnd(lane))
  {
    if (isSuccessor(lane.edge_left, other.edge_left) && isSuccessor(lane.edge_right, other.edge_left))
    {
      return true;
    }
    if (isSuccessor(lane.edge_left, other.edge_right) && isSuccessor(lane.edge_right, other.edge_right))
    {
      return true;
    }
  }
  if (isVanishingLaneEnd(other))
  {
    if (isSuccessor(lane.edge_left, other.edge_right) || isSuccessor(lane.edge_right, other.edge_right))
    {
      return true;
    }
  }
  return false;
}

bool isPhysicalPredecessor(Lane const &lane, const Lane &other)
{
  if (isPredecessor(lane.edge_left, other.edge_left) && isPredecessor(lane.edge_right, other.edge_right))
  {
    return true;
  }
  if (isPredecessor(lane.edge_left, other.edge_right) && isPredecessor(lane.edge_right, other.edge_left))
  {
    return true;
  }
  if (isVanishingLaneStart(lane) || isVanishingLaneEnd(lane))
  {
    if (isPredecessor(lane.edge_left, other.edge_left) && isPredecessor(lane.edge_right, other.edge_left))
    {
      return true;
    }
    if (isPredecessor(lane.edge_left, other.edge_right) && isPredecessor(lane.edge_right, other.edge_right))
    {
      return true;
    }
  }
  if (isVanishingLaneStart(other))
  {
    if (isPredecessor(lane.edge_left, other.edge_right) || isPredecessor(lane.edge_right, other.edge_right))
    {
      return true;
    }
  }
  return false;
}

bool isVanishingLaneStart(Lane const &lane)
{
  return haveSameStart(lane.edge_left, lane.edge_right);
}

bool isVanishingLaneEnd(Lane const &lane)
{
  return haveSameEnd(lane.edge_left, lane.edge_right);
}

bool satisfiesFilter(Lane const &lane, std::string const &typeFilter, bool isHov)
{
  if (isHov == (getHOV(lane) > restriction::PassengerCount(1)))
  {
    if (!typeFilter.empty())
    {
      auto const laneFullTypeString = toString(lane.type);
      if (typeFilter.find(laneFullTypeString) != std::string::npos)
      {
        return true;
      }
      std::size_t found = laneFullTypeString.find_last_of(":");
      auto const laneTypeWithoutPrefix = laneFullTypeString.substr(found + 1);
      if (!laneTypeWithoutPrefix.empty())
      {
        if (typeFilter.find(laneTypeWithoutPrefix) != std::string::npos)
        {
          return true;
        }
      }
    }
    else
    {
      return true;
    }
  }
  return false;
}

void updateLaneLengths(Lane &lane)
{
  if (isValid(lane.edge_left))
  {
    if (isValid(lane.edge_right))
    {
      lane.length_range.minimum = std::max(cMinLaneDimension, std::min(lane.edge_left.length, lane.edge_right.length));
      lane.length_range.maximum = std::max(cMinLaneDimension, std::max(lane.edge_left.length, lane.edge_right.length));
      lane.length = (lane.edge_left.length + lane.edge_right.length) * 0.5;

      auto widthRangeResult = calculateWidthRange(
        lane.edge_left.ecef_points, lane.edge_left.length, lane.edge_right.ecef_points, lane.edge_right.length);
      lane.width_range.minimum = std::max(cMinLaneDimension, widthRangeResult.first.minimum);
      lane.width_range.maximum = std::max(cMinLaneDimension, widthRangeResult.first.maximum);
      lane.width = std::max(cMinLaneDimension, widthRangeResult.second);
    }
    else
    {
      lane.length = std::max(cMinLaneDimension, lane.edge_left.length);
      lane.length_range.minimum = lane.length;
      lane.length_range.maximum = lane.length;
      lane.width = cMinLaneDimension;
      lane.width_range.minimum = lane.width;
      lane.width_range.maximum = lane.width;
    }
  }
  else if (isValid(lane.edge_right))
  {
    lane.length = std::max(cMinLaneDimension, lane.edge_right.length);
    lane.length_range.minimum = lane.length;
    lane.length_range.maximum = lane.length;
    lane.width = cMinLaneDimension;
    lane.width_range.minimum = lane.width;
    lane.width_range.maximum = lane.width;
  }
  else
  {
    lane.length = cMinLaneDimension;
    lane.length_range.minimum = lane.length;
    lane.length_range.maximum = lane.length;
    lane.width = cMinLaneDimension;
    lane.width_range.minimum = lane.width;
    lane.width_range.maximum = lane.width;
  }
}

point::ENUHeading getLaneENUHeading(point::ParaPoint const &position)
{
  const auto gnssReference = access::getENUReferencePoint();
  const auto laneHeading = getLaneENUHeading(position, gnssReference);
  return laneHeading;
}

bool isHeadingInLaneDirection(point::ParaPoint const &position, point::ENUHeading const &heading)
{
  const auto laneHeading = getLaneENUHeading(position);
  // enforce normalization of angle difference
  const auto headingDifference = point::createENUHeading(std::fabs(heading.mENUHeading - laneHeading.mENUHeading));

  if (std::fabs(headingDifference.mENUHeading) > M_PI / 2.)
  {
    return false;
  }

  return true;
}

bool isLaneDirectionPositive(LaneId const &lane_id)
{
  auto const lane = getLane(lane_id);
  return isLaneDirectionPositive(lane);
}

bool isLaneDirectionNegative(LaneId const &lane_id)
{
  auto const lane = getLane(lane_id);
  return isLaneDirectionNegative(lane);
}

bool projectPositionToLaneInHeadingDirection(point::ParaPoint const &position,
                                             point::ENUHeading const &heading,
                                             point::ParaPoint &projectedPosition)
{
  projectedPosition = position;
  if (isHeadingInLaneDirection(position, heading))
  {
    return true;
  }

  const auto lane = getLane(position.lane_id);
  ContactLocationList types;
  if (isLaneDirectionPositive(position.lane_id))
  {
    types.push_back(ContactLocation::LEFT);
    types.push_back(ContactLocation::RIGHT);
  }
  else
  {
    types.push_back(ContactLocation::RIGHT);
    types.push_back(ContactLocation::LEFT);
  }
  for (auto contactType : types)
  {
    auto contact_lanes = getContactLanes(lane, contactType);
    while (contact_lanes.size() > 0)
    {
      // check first neighbor
      const auto neighborLaneId = contact_lanes[0].to_lane;
      const auto neighborLane = getLane(neighborLaneId);

      projectedPosition.lane_id = neighborLaneId;
      projectedPosition.parametric_offset = position.parametric_offset;

      if (isRouteable(neighborLane) && isHeadingInLaneDirection(projectedPosition, heading))
      {
        return true;
      }
      else
      {
        contact_lanes = getContactLanes(neighborLane, contactType);
      }
    }
  }

  return false;
}

match::MapMatchedPosition calcMapMatchedPosition(Lane const &lane,
                                                 physics::ParametricValue const &longTLeft,
                                                 physics::ParametricValue const &longTRight,
                                                 point::ECEFPoint const &pt)
{
  match::MapMatchedPosition mmpos;
  point::ECEFPoint const pt_left = point::getParametricPoint(lane.edge_left, longTLeft);
  point::ECEFPoint const pt_right = point::getParametricPoint(lane.edge_right, longTRight);

  mmpos.lane_point.para_point.lane_id = lane.id;
  mmpos.lane_point.lateral_t = point::findNearestPointOnEdge(pt, pt_left, pt_right);
  physics::ParametricValue nearestT;
  if (mmpos.lane_point.lateral_t < physics::RatioValue(0.))
  {
    nearestT = physics::ParametricValue(0.);
    mmpos.type = match::MapMatchedPositionType::LANE_LEFT;
    mmpos.probability
      = std::max(physics::Probability(0.1), physics::Probability(0.5 + mmpos.lane_point.lateral_t.mRatioValue / 10.));
  }
  else if (mmpos.lane_point.lateral_t > physics::RatioValue(1.))
  {
    nearestT = physics::ParametricValue(1.);
    mmpos.type = match::MapMatchedPositionType::LANE_RIGHT;
    mmpos.probability = std::max(physics::Probability(0.1),
                                 physics::Probability(0.5 - (mmpos.lane_point.lateral_t.mRatioValue - 1.) / 10.));
  }
  else
  {
    nearestT = physics::ParametricValue(mmpos.lane_point.lateral_t.mRatioValue);
    mmpos.type = match::MapMatchedPositionType::LANE_IN;
    mmpos.probability = physics::Probability(1.)
      - std::min(physics::Probability(0.5), physics::Probability(fabs(0.5 - mmpos.lane_point.lateral_t.mRatioValue)));
  }
  mmpos.matched_point = point::vectorInterpolate(pt_left, pt_right, nearestT);
  mmpos.lane_point.para_point.parametric_offset
    = nearestT * longTRight + (physics::ParametricValue(1.) - nearestT) * longTLeft;
  mmpos.lane_point.lane_length = lane.length;
  mmpos.lane_point.lane_width = point::distance(pt_left, pt_right);
  mmpos.query_point = pt;
  mmpos.matched_point_distance = point::distance(mmpos.matched_point, mmpos.query_point);
  return mmpos;
}

match::MapMatchedPosition calcMapMatchedPositionIgnoreZ(Lane const &lane,
                                                        physics::ParametricValue const &longTLeft,
                                                        physics::ParametricValue const &longTRight,
                                                        point::ENUPoint const &_pt)
{
  match::MapMatchedPosition mmpos;
  auto const pt_left_ecef = point::getParametricPoint(lane.edge_left, longTLeft);
  point::ENUPoint pt_left = toENU(pt_left_ecef);
  auto const pt_left_z = pt_left.z;
  auto const pt_right_ecef = point::getParametricPoint(lane.edge_right, longTRight);
  point::ENUPoint pt_right = toENU(pt_right_ecef);
  auto const pt_right_z = pt_right.z;
  auto pt = _pt;
  pt.z = point::ENUCoordinate(0.);
  pt_left.z = point::ENUCoordinate(0.);
  pt_right.z = point::ENUCoordinate(0.);

  mmpos.lane_point.para_point.lane_id = lane.id;
  mmpos.lane_point.lateral_t = point::findNearestPointOnEdge(pt, pt_left, pt_right);
  physics::ParametricValue nearestT;
  if (mmpos.lane_point.lateral_t < physics::RatioValue(0.))
  {
    nearestT = physics::ParametricValue(0.);
    mmpos.type = match::MapMatchedPositionType::LANE_LEFT;
    mmpos.probability
      = std::max(physics::Probability(0.1), physics::Probability(0.5 + mmpos.lane_point.lateral_t.mRatioValue / 10.));
  }
  else if (mmpos.lane_point.lateral_t > physics::RatioValue(1.))
  {
    nearestT = physics::ParametricValue(1.);
    mmpos.type = match::MapMatchedPositionType::LANE_RIGHT;
    mmpos.probability = std::max(physics::Probability(0.1),
                                 physics::Probability(0.5 - (mmpos.lane_point.lateral_t.mRatioValue - 1.) / 10.));
  }
  else
  {
    nearestT = physics::ParametricValue(mmpos.lane_point.lateral_t.mRatioValue);
    mmpos.type = match::MapMatchedPositionType::LANE_IN;
    mmpos.probability = physics::Probability(1.)
      - std::min(physics::Probability(0.5), physics::Probability(fabs(0.5 - mmpos.lane_point.lateral_t.mRatioValue)));
  }
  mmpos.matched_point = point::vectorInterpolate(pt_left_ecef, pt_right_ecef, nearestT);
  mmpos.lane_point.para_point.parametric_offset
    = nearestT * longTRight + (physics::ParametricValue(1.) - nearestT) * longTLeft;
  mmpos.lane_point.lane_length = lane.length;
  mmpos.lane_point.lane_width = point::distance(pt_left, pt_right);

  pt.z = nearestT.mParametricValue * pt_right_z + (1. - nearestT.mParametricValue) * pt_left_z;
  mmpos.query_point = toECEF(pt);
  mmpos.matched_point_distance = point::distance(mmpos.matched_point, mmpos.query_point);
  return mmpos;
}

bool findNearestPointOnLaneIgnoreZ(Lane const &lane, point::ENUPoint const &pt, match::MapMatchedPosition &mmpos)
{
  auto const longTLeft = findNearestPointOnEdgeIgnoreZ(lane.edge_left, pt);
  if (longTLeft.isValid())
  {
    auto const longTRight = findNearestPointOnEdgeIgnoreZ(lane.edge_right, pt);
    if (longTRight.isValid())
    {
      mmpos = calcMapMatchedPositionIgnoreZ(lane, longTLeft, longTRight, pt);
      return true;
    }
  }
  return false;
}

bool findNearestPointOnLane(Lane const &lane, point::ECEFPoint const &pt, match::MapMatchedPosition &mmpos)
{
  auto const longTLeft = findNearestPointOnEdge(lane.edge_left, pt);
  if (longTLeft.isValid())
  {
    auto const longTRight = findNearestPointOnEdge(lane.edge_right, pt);
    if (longTRight.isValid())
    {
      mmpos = calcMapMatchedPosition(lane, longTLeft, longTRight, pt);
      return true;
    }
  }
  return false;
}

bool findNearestPointOnLaneInterval(route::LaneInterval const &lane_interval,
                                    point::ECEFPoint const &pt,
                                    match::MapMatchedPosition &mmpos)
{
  auto const &lane = getLane(lane_interval.lane_id);
  auto const laneRange = route::toParametricRange(lane_interval);
  auto longTLeft = findNearestPointOnEdge(lane.edge_left, pt);
  if (longTLeft.isValid())
  {
    auto longTRight = findNearestPointOnEdge(lane.edge_right, pt);
    if (longTRight.isValid())
    {
      if (!physics::isWithinRange(laneRange, longTLeft))
      {
        if (longTLeft < laneRange.minimum)
        {
          longTLeft = laneRange.minimum;
        }
        else if (longTLeft > laneRange.maximum)
        {
          longTLeft = laneRange.maximum;
        }
      }
      if (!physics::isWithinRange(laneRange, longTRight))
      {
        if (longTRight < laneRange.minimum)
        {
          longTRight = laneRange.minimum;
        }
        else if (longTRight > laneRange.maximum)
        {
          longTRight = laneRange.maximum;
        }
      }

      mmpos = calcMapMatchedPosition(lane, longTLeft, longTRight, pt);
      return true;
    }
  }
  return false;
}

physics::Distance getDistanceToLane(LaneId lane_id, match::Object const &object)
{
  // prefer fast checks first
  for (auto const &occupiedLane : object.map_matched_bounding_box.lane_occupied_regions)
  {
    if (occupiedLane.lane_id == lane_id)
    {
      return physics::Distance(0.);
    }
  }
  // already map matching result available, but not within the lane
  physics::Distance distance = std::numeric_limits<physics::Distance>::max();
  bool mapMatchedPointFound = false;
  point::ECEFPoint const objectPointECEF
    = point::toECEF(object.enu_position.center_point, object.enu_position.enu_reference_point);

  for (auto referencePoint : {match::ObjectReferencePoints::FrontLeft,
                              match::ObjectReferencePoints::FrontRight,
                              match::ObjectReferencePoints::RearLeft,
                              match::ObjectReferencePoints::RearRight})
  {
    auto mapMatchedConfidenceList = object.map_matched_bounding_box.reference_point_positions[size_t(referencePoint)];
    for (auto const &mapMatchedPosition : mapMatchedConfidenceList)
    {
      if (mapMatchedPosition.lane_point.para_point.lane_id == lane_id)
      {
        mapMatchedPointFound = true;
        // use the smallest distance if multiple have been matched
        distance = std::min(distance, point::distance(mapMatchedPosition.matched_point, objectPointECEF));
      }
    }
  }
  if (!mapMatchedPointFound)
  {
    // need to perform map matching on our own
    auto lane = getLane(lane_id);
    match::MapMatchedPosition mapMatchedPosition;
    if (findNearestPointOnLane(lane, objectPointECEF, mapMatchedPosition))
    {
      distance = point::distance(mapMatchedPosition.matched_point, objectPointECEF);
      distance
        = std::max(distance - std::max(object.enu_position.dimension.length, object.enu_position.dimension.width) / 2.,
                   physics::Distance(0.));
    }
  }

  return distance;
}

physics::Distance calcLength(LaneId const &lane_id)
{
  const auto lane = getLanePtr(lane_id);
  if (lane->length == physics::Distance(0.))
  {
    return cMinLaneDimension;
  }
  return lane->length;
}

physics::Distance calcLength(match::LaneOccupiedRegion const &laneOccupiedRegion)
{
  auto const rangeLength
    = (laneOccupiedRegion.longitudinal_range.maximum - laneOccupiedRegion.longitudinal_range.minimum);
  return rangeLength * calcLength(laneOccupiedRegion.lane_id);
}

physics::Distance calcWidth(point::ParaPoint const &para_point)
{
  return calcWidth(para_point.lane_id, para_point.parametric_offset);
}

physics::Distance calcWidth(LaneId const &lane_id, physics::ParametricValue const &longOffset)
{
  const auto lane = getLanePtr(lane_id);
  return getWidth(*lane, longOffset);
}

physics::Distance calcWidth(point::ENUPoint const &enuPoint)
{
  match::AdMapMatching mapMatching;
  const auto mapMatchedPositions
    = mapMatching.getMapMatchedPositions(enuPoint, physics::Distance(1.0), physics::Probability(0.1));

  if (mapMatchedPositions.empty())
  {
    return physics::Distance(-1.0);
  }
  return calcWidth(mapMatchedPositions.front().lane_point.para_point);
}

physics::Distance calcWidth(match::LaneOccupiedRegion const &laneOccupiedRegion)
{
  auto const rangeWidth = (laneOccupiedRegion.lateral_range.maximum - laneOccupiedRegion.lateral_range.minimum);
  return rangeWidth * calcWidth(match::getCenterParaPoint(laneOccupiedRegion));
}

ContactLocation getDirectNeighborhoodRelation(LaneId const lane_id, LaneId const checkLaneId)
{
  if (lane_id == checkLaneId)
  {
    return ContactLocation::OVERLAP;
  }
  auto lane = getLane(lane_id);
  for (auto contactLocation :
       {ContactLocation::LEFT, ContactLocation::RIGHT, ContactLocation::SUCCESSOR, ContactLocation::PREDECESSOR})
  {
    auto contact_lanes = getContactLanes(lane, contactLocation);
    auto findResult
      = std::find_if(std::begin(contact_lanes), std::end(contact_lanes), [checkLaneId](ContactLane const &contactLane) {
          return contactLane.to_lane == checkLaneId;
        });
    if (findResult != std::end(contact_lanes))
    {
      return contactLocation;
    }
  }
  return ContactLocation::INVALID;
}

bool isSuccessorOrPredecessor(LaneId const lane_id, LaneId const checkLaneId)
{
  auto const neighborhood = getDirectNeighborhoodRelation(lane_id, checkLaneId);
  return (neighborhood == ContactLocation::SUCCESSOR) || (neighborhood == ContactLocation::PREDECESSOR);
}

bool isSameOrDirectNeighbor(LaneId const lane_id, LaneId const checkLaneId)
{
  auto const neighborhood = getDirectNeighborhoodRelation(lane_id, checkLaneId);
  return (neighborhood == ContactLocation::OVERLAP) || (neighborhood == ContactLocation::LEFT)
    || (neighborhood == ContactLocation::RIGHT);
}

point::ENUPoint getENULanePoint(point::ParaPoint const parametricPoint, physics::ParametricValue const &lateralOffset)
{
  // perform map matching
  auto lane = getLane(parametricPoint.lane_id);
  auto ecefPoint = getParametricPoint(lane, parametricPoint.parametric_offset, lateralOffset);
  auto enuPoint = point::toENU(ecefPoint);
  return enuPoint;
}

bool isLaneRelevantForExpansion(lane::LaneId const &lane_id, lane::LaneIdSet const &relevantLanes)
{
  if (relevantLanes.empty())
  {
    return true;
  }
  auto const findResult = relevantLanes.find(lane_id);
  if (findResult != relevantLanes.end())
  {
    return true;
  }
  return false;
}

LaneAltitudeRange calcLaneAltitudeRange(Lane const &lane)
{
  LaneAltitudeRange altitude_range;
  bool initialize = true;
  for (auto const &pt : getCachedENUPointList(lane.edge_left))
  {
    auto const altitude = point::Altitude(pt.z.mENUCoordinate);
    if (initialize)
    {
      initialize = false;
      altitude_range.minimum = altitude;
      altitude_range.maximum = altitude;
    }
    else
    {
      altitude_range.minimum = std::min(altitude_range.minimum, altitude);
      altitude_range.maximum = std::max(altitude_range.maximum, altitude);
    }
  }
  for (auto const &pt : getCachedENUPointList(lane.edge_right))
  {
    auto const altitude = point::Altitude(pt.z.mENUCoordinate);
    altitude_range.minimum = std::min(altitude_range.minimum, altitude);
    altitude_range.maximum = std::max(altitude_range.maximum, altitude);
  }
  return altitude_range;
}

} // namespace lane
} // namespace map
} // namespace ad
