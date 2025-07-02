// ----------------- BEGIN LICENSE BLOCK ---------------------------------
//
// Copyright (C) 2018-2021 Intel Corporation
//
// SPDX-License-Identifier: MIT
//
// ----------------- END LICENSE BLOCK -----------------------------------

#include "ad/map/access/Factory.hpp"

#include <algorithm>
#include "../lane/LaneOperationPrivate.hpp"
#include "ad/map/access/Logging.hpp"
#include "ad/map/access/Store.hpp"
#include "ad/map/intersection/Intersection.hpp"
#include "ad/map/landmark/LandmarkOperation.hpp"
#include "ad/map/lane/LaneOperation.hpp"
#include "ad/map/point/GeometryOperation.hpp"
#include "ad/map/point/Transform.hpp"
#include "ad/map/restriction/ParametricRangeAttributeOperation.hpp"

namespace ad {
namespace map {
namespace access {

bool Factory::add(PartitionId part_id, const lane::LaneId &id, lane::LaneType type, lane::LaneDirection dir)
{
  auto insertResult = mStore.lane_map_.insert({id, lane::Lane::Ptr()});
  auto &lanePtr = insertResult.first->second;
  if (insertResult.second)
  {
    lanePtr = std::make_shared<lane::Lane>();
    lanePtr->id = id;
    mStore.part_lane_map_[part_id].push_back(id);
  }
  lanePtr->type = type;
  lanePtr->direction = dir;
  return insertResult.second;
}

lane::LaneId Factory::add(PartitionId pid, const point::GeoPointList &left_geo, const point::GeoPointList &right_geo)
{
  lane::LaneId new_lane_id = getNextLaneId();
  if (add(pid, new_lane_id, lane::LaneType::NORMAL, lane::LaneDirection::POSITIVE))
  {
    point::CoordinateTransform cf;
    point::ECEFPointList left_ecef;
    point::ECEFPointList right_ecef;
    cf.convert(left_geo, left_ecef);
    cf.convert(right_geo, right_ecef);
    point::Geometry const left_edge = point::createGeometry(left_ecef, false);
    point::Geometry const right_edge = point::createGeometry(right_ecef, false);
    set(new_lane_id, left_edge, right_edge);
    return new_lane_id;
  }
  else
  {
    return lane::LaneId();
  }
}

lane::LaneId Factory::add(PartitionId pid,
                          const point::ECEFPointList &left_ecef,
                          const point::ECEFPointList &right_ecef,
                          const lane::LaneId &lane_id_0,
                          const lane::LaneId &lane_id_1)
{
  lane::LaneId new_lane_id = getNextLaneId();
  if (add(pid, new_lane_id, lane::LaneType::INTERSECTION, lane::LaneDirection::POSITIVE))
  {
    point::Geometry const left_edge = point::createGeometry(left_ecef, false);
    point::Geometry const right_edge = point::createGeometry(right_ecef, false);
    set(new_lane_id, left_edge, right_edge);
    if (!autoConnect(new_lane_id, lane_id_0) || !autoConnect(new_lane_id, lane_id_1)
        || !autoConnect(lane_id_0, new_lane_id) || !autoConnect(lane_id_1, new_lane_id))
    {
      throw std::runtime_error("AutoConnect failed");
    }
    return new_lane_id;
  }
  else
  {
    return lane::LaneId();
  }
}

bool Factory::addLandmark(PartitionId part_id,
                          const landmark::LandmarkId &id,
                          const landmark::LandmarkType type,
                          const point::ECEFPoint &position,
                          const point::ECEFPoint &orientation,
                          const point::Geometry &bounding_box)
{
  return add(part_id,
             id,
             type,
             position,
             orientation,
             bounding_box,
             landmark::TrafficLightType::INVALID,
             landmark::TrafficSignType::INVALID,
             "none");
}

bool Factory::addTrafficLight(PartitionId part_id,
                              const landmark::LandmarkId &id,
                              const landmark::TrafficLightType type,
                              const point::ECEFPoint &position,
                              const point::ECEFPoint &orientation,
                              const point::Geometry &bounding_box)
{
  return add(part_id,
             id,
             landmark::LandmarkType::TRAFFIC_LIGHT,
             position,
             orientation,
             bounding_box,
             type,
             landmark::TrafficSignType::INVALID,
             "none");
}

bool Factory::addTrafficSign(PartitionId part_id,
                             const landmark::LandmarkId &id,
                             const landmark::TrafficSignType type,
                             const point::ECEFPoint &position,
                             const point::ECEFPoint &orientation,
                             const point::Geometry &bounding_box,
                             const std::string &text)
{
  return add(part_id,
             id,
             landmark::LandmarkType::TRAFFIC_SIGN,
             position,
             orientation,
             bounding_box,
             landmark::TrafficLightType::INVALID,
             type,
             text);
}

bool Factory::add(PartitionId part_id,
                  const landmark::LandmarkId &id,
                  const landmark::LandmarkType type,
                  const point::ECEFPoint &position,
                  const point::ECEFPoint &orientation,
                  const point::Geometry &bounding_box,
                  const landmark::TrafficLightType traffic_light_type,
                  const landmark::TrafficSignType traffic_sign_type,
                  const std::string &text)
{
  auto insertResult = mStore.landmark_map_.insert({id, landmark::Landmark::Ptr()});
  auto &landmarkPtr = insertResult.first->second;
  if (insertResult.second)
  {
    landmarkPtr = std::make_shared<landmark::Landmark>();
    landmarkPtr->id = id;
    mStore.part_landmark_map_[part_id].push_back(id);
  }
  landmarkPtr->type = type;
  landmarkPtr->position = position;
  landmarkPtr->orientation = orientation;
  landmarkPtr->bounding_box = bounding_box;
  landmarkPtr->traffic_light_type = traffic_light_type;
  landmarkPtr->traffic_sign_type = traffic_sign_type;
  landmarkPtr->supplementary_text = text;
  // @todo: Do we need to ensure that we handle only valid objects?
  return insertResult.second;
}

//////////////////////////////////////////
// Atomic Operations -- Add Lane Attribute

bool Factory::add(const lane::LaneId &id, const lane::ContactLane &contact_lane)
{
  auto it = mStore.lane_map_.find(id);
  if (it != mStore.lane_map_.end())
  {
    lane::Lane::Ptr lane = it->second;
    if (lane)
    {
      for (auto const &existing_contact_lane : lane->contact_lanes)
      {
        if (contact_lane == existing_contact_lane)
        {
          return true;
        }
      }
      lane->contact_lanes.push_back(contact_lane);
      return true;
    }
  }
  access::getLogger()->error("Cannot add contact lane of lane. {}", id);
  return false;
}

bool Factory::add(const lane::LaneId &id, const lane::ContactLaneList &contact_lanes)
{
  for (auto contact_lane : contact_lanes)
  {
    if (!add(id, contact_lane))
    {
      access::getLogger()->error("Cannot add contact lanes of lane. {}", id);
      return false;
    }
  }
  return true;
}

bool Factory::add(const lane::LaneId &id, const restriction::SpeedLimit &speed_limit)
{
  auto it = mStore.lane_map_.find(id);
  if (it != mStore.lane_map_.end())
  {
    lane::Lane::Ptr lane = it->second;
    if (lane)
    {
      if (restriction::doesRangeAttributeOverlap(lane->speed_limits, speed_limit))
      {
        access::getLogger()->warn("Lane para-speed overlaps existing value!? {}, {}", id, speed_limit);
      }
      restriction::insertRangeAttribute(lane->speed_limits, speed_limit);
      return true;
    }
  }
  access::getLogger()->error("Cannot add restrictions of lane. {}", id);
  return false;
}

bool Factory::add(const lane::LaneId &id, const landmark::LandmarkId &landmark_id)
{
  if (!isValid(landmark_id))
  {
    access::getLogger()->error("Cannot add landmark with invalid id. {}", landmark_id);
    return false;
  }
  auto it = mStore.lane_map_.find(id);
  if (it != mStore.lane_map_.end())
  {
    lane::Lane::Ptr lane = it->second;
    if (lane)
    {
      for (auto existing_visible_landmark : lane->visible_landmarks)
      {
        if (landmark_id == existing_visible_landmark)
        {
          return true;
        }
      }
      lane->visible_landmarks.push_back(landmark_id);
      return true;
    }
  }
  access::getLogger()->error("Cannot add landmark of lane. {}", id);
  return false;
}

bool Factory::add(const lane::LaneId &id, const restriction::Restriction &restriction, bool andx)
{
  auto it = mStore.lane_map_.find(id);
  if (it != mStore.lane_map_.end())
  {
    lane::Lane::Ptr lane = it->second;
    if (lane)
    {
      if (andx)
      {
        lane->restrictions.conjunctions.push_back(restriction);
      }
      else
      {
        lane->restrictions.disjunctions.push_back(restriction);
      }
      return true;
    }
  }
  access::getLogger()->error("Cannot add restrictions of lane. {}", id);
  return false;
}

bool Factory::add(const lane::LaneId &id_from,
                  const lane::LaneId &id_to,
                  const lane::ContactLocation location,
                  const lane::ContactTypeList &types,
                  const restriction::Restrictions &restrs)
{
  if (std::find(types.begin(), types.end(), lane::ContactType::TRAFFIC_LIGHT) != types.end())
  {
    access::getLogger()->error("Trying to add traffic light contact without traffic light id. {}", id_to);
    return false;
  }

  lane::ContactLane contactLane;
  contactLane.to_lane = id_to;
  contactLane.location = location;
  contactLane.types = types;
  contactLane.restrictions = restrs;
  contactLane.landmark_id = landmark::LandmarkId();
  return add(id_from, contactLane);
}

bool Factory::add(const lane::LaneId &id_from,
                  const lane::LaneId &id_to,
                  const lane::ContactLocation location,
                  const lane::ContactTypeList &types,
                  const restriction::Restrictions &restrs,
                  const landmark::LandmarkId &traffic_light)
{
  if (!isValid(traffic_light))
  {
    access::getLogger()->error("Cannot add contact with invalid traffic light id. {}", traffic_light);
    return false;
  }

  if (std::find(types.begin(), types.end(), lane::ContactType::TRAFFIC_LIGHT) == types.end())
  {
    access::getLogger()->error("Cannot add traffic light contact due to wrong type. {}", traffic_light);
    return false;
  }

  lane::ContactLane contactLane;
  contactLane.to_lane = id_to;
  contactLane.location = location;
  contactLane.types = types;
  contactLane.restrictions = restrs;
  contactLane.landmark_id = traffic_light;
  return add(id_from, contactLane);
}

//////////////////////////////////////////
// Atomic Operations -- Set Lane Attribute

bool Factory::set(const lane::LaneId &id, lane::LaneDirection direction)
{
  auto it = mStore.lane_map_.find(id);
  if (it != mStore.lane_map_.end())
  {
    lane::Lane::Ptr lane = it->second;
    if (lane)
    {
      lane->direction = direction;
      return true;
    }
  }
  access::getLogger()->error("Cannot set direction of lane. {}", id);
  return false;
}

bool Factory::set(const lane::LaneId &id, lane::LaneType type)
{
  auto it = mStore.lane_map_.find(id);
  if (it != mStore.lane_map_.end())
  {
    lane::Lane::Ptr lane = it->second;
    if (lane)
    {
      lane->type = type;
      return true;
    }
  }
  access::getLogger()->error("Cannot set type of lane. {}", id);
  return false;
}

bool Factory::set(const lane::LaneId &id, lane::ComplianceVersion compliance_ver)
{
  auto it = mStore.lane_map_.find(id);
  if (it != mStore.lane_map_.end())
  {
    lane::Lane::Ptr lane = it->second;
    if (lane)
    {
      lane->compliance_version = compliance_ver;
      return true;
    }
  }
  access::getLogger()->error("Cannot set compliance of lane. {}", id);
  return false;
}

bool Factory::set(const lane::LaneId &id, const point::Geometry &edge_left, const point::Geometry &edge_right)
{
  auto it = mStore.lane_map_.find(id);
  if (it != mStore.lane_map_.end())
  {
    lane::Lane::Ptr lane = it->second;
    if (lane)
    {
      lane->edge_left = edge_left;
      lane->edge_right = edge_right;
      lane->bounding_sphere = point::calcBoundingSphere(edge_left, edge_right);
      lane::updateLaneLengths(*lane);
      return true;
    }
  }
  access::getLogger()->error("Cannot set edges of lane. {}", id);
  return false;
}

bool Factory::set(const lane::LaneId &id, const physics::Speed &maxSpeed)
{
  auto it = mStore.lane_map_.find(id);
  if (it != mStore.lane_map_.end())
  {
    lane::Lane::Ptr lane = it->second;
    if (lane)
    {
      lane->speed_limits.clear();
      restriction::SpeedLimit speed_limit;
      speed_limit.lane_piece.minimum = physics::ParametricValue(0.);
      speed_limit.lane_piece.maximum = physics::ParametricValue(1.);
      speed_limit.speed_limit = maxSpeed;
      lane->speed_limits.push_back(speed_limit);
      return true;
    }
  }
  access::getLogger()->error("Cannot set speed limit for the. {}", id);
  return false;
}

bool Factory::set(const lane::LaneId &id, const restriction::Restrictions &restrictions)
{
  auto it = mStore.lane_map_.find(id);
  if (it != mStore.lane_map_.end())
  {
    lane::Lane::Ptr lane = it->second;
    if (lane)
    {
      lane->restrictions = restrictions;
      return true;
    }
  }
  access::getLogger()->error("Cannot set restrictions of lane. {}", id);
  return false;
}

bool Factory::set(const lane::LaneId &id, const landmark::LandmarkIdList &landmarks)
{
  auto it = mStore.lane_map_.find(id);
  if (it != mStore.lane_map_.end())
  {
    lane::Lane::Ptr lane = it->second;
    if (lane)
    {
      lane->visible_landmarks = landmarks;
      return true;
    }
  }
  access::getLogger()->error("Cannot set bounding sphere of lane. {}", id);
  return false;
}

//////////////////////////////////////////
// Atomic Operations -- Set Map Meta Data

bool Factory::set(const TrafficType &traffic_type)
{
  if (traffic_type != TrafficType::INVALID)
  {
    mStore.meta_data_.traffic_type = traffic_type;
    return true;
  }

  return false;
}

/////////////////////////////////////
// Atomic operations -- remove things

bool Factory::deleteLane(lane::LaneId id)
{
  if (lane::isValid(id))
  {
    auto const erased = mStore.lane_map_.erase(id);
    if (erased > 0u)
    {
      bool removed_from_part_map = false;
      for (auto part_id_and_lane_ids : mStore.part_lane_map_)
      {
        auto const removeIter = std::remove(part_id_and_lane_ids.second.begin(), part_id_and_lane_ids.second.end(), id);
        if (removeIter != part_id_and_lane_ids.second.end())
        {
          part_id_and_lane_ids.second.erase(removeIter, part_id_and_lane_ids.second.end());
          removed_from_part_map = true;
          break;
        }
      }
      if (!removed_from_part_map)
      {
        access::getLogger()->error("Lane not in the Partitions?. {}", id);
      }
      return true;
    }
    else
    {
      access::getLogger()->warn("Lane is not in the Store. {}", id);
    }
  }
  else
  {
    access::getLogger()->error("Invalid lane identifier passed to Factory::deleteLane()");
  }
  return false;
}

bool Factory::deleteContacts(lane::LaneId id, lane::LaneId to_id)
{
  if (lane::isValid(id) && lane::isValid(to_id))
  {
    auto it = mStore.lane_map_.find(id);
    if (it != mStore.lane_map_.end())
    {
      lane::Lane::Ptr lane = it->second;
      if (lane)
      {
        lane::ContactLaneList &cls = lane->contact_lanes;
        cls.erase(
          std::remove_if(cls.begin(), cls.end(), [to_id](const lane::ContactLane &cl) { return cl.to_lane == to_id; }));
        return true;
      }
    }
  }
  else
  {
    access::getLogger()->error("Invalid lane identifier passed to Factory::deleteContacts()");
  }
  return false;
}

bool Factory::deleteLandmark(landmark::LandmarkId id)
{
  if (landmark::isValid(id))
  {
    auto const erased = mStore.landmark_map_.erase(id);
    if (erased > 0u)
    {
      bool removed_from_part_map = false;
      for (auto part_id_and_landmark_ids : mStore.part_landmark_map_)
      {
        auto const removeIter
          = std::remove(part_id_and_landmark_ids.second.begin(), part_id_and_landmark_ids.second.end(), id);
        if (removeIter != part_id_and_landmark_ids.second.end())
        {
          part_id_and_landmark_ids.second.erase(removeIter, part_id_and_landmark_ids.second.end());
          removed_from_part_map = true;
          break;
        }
      }
      if (!removed_from_part_map)
      {
        access::getLogger()->error("Landmark not in a partition. {}", id);
      }
      return true;
    }
    else
    {
      access::getLogger()->warn("Landmark is not in the Store. {}", id);
    }
  }
  else
  {
    access::getLogger()->error("Invalid landmark identifier passed to Factory::deleteLandmark()");
  }
  return false;
}

bool Factory::changeLaneContact(const lane::LaneId &id_from,
                                const lane::LaneId &id_to,
                                const lane::ContactType &old_contact,
                                const lane::ContactType &new_contact)
{
  bool changeSucceeded = false;
  if (lane::isValid(id_from) && lane::isValid(id_to))
  {
    auto it = mStore.lane_map_.find(id_from);
    if (it != mStore.lane_map_.end())
    {
      lane::Lane::Ptr lane = it->second;
      if (lane)
      {
        for (auto &contact_lane : lane->contact_lanes)
        {
          if (contact_lane.to_lane == id_to)
          {
            for (auto &contact_type : contact_lane.types)
            {
              if (contact_type == old_contact)
              {
                contact_type = new_contact;
                changeSucceeded = true;
              }
            }
          }
        }
      }
    }
  }
  else
  {
    access::getLogger()->error("Invalid lane identifier passed to Factory::changeLaneContact()");
  }
  return changeSucceeded;
}

////////////////
// Other Methods
bool correctLaneEdgeAtFront(::ad::map::point::Geometry &first,
                            ::ad::map::point::ECEFPoint const &new_end_point,
                            ad::physics::Distance const max_delta_length)
{
  auto previousDirection = new_end_point - first.ecef_points.back();
  ad::map::point::ECEFPointList newPoints;
  for (auto iter = first.ecef_points.rbegin(); iter != first.ecef_points.rend(); ++iter)
  {
    auto nextDirection = new_end_point - *iter;
    if (point::vectorDotProduct(previousDirection, nextDirection) < 0.)
    {
      newPoints.push_back(new_end_point);
      ad::physics::Distance newLength = calcLength(newPoints);
      // now the direction towards the new end point switches by more than 90 degrees at once
      // that should be the point where to cut the edge
      // but we only cut if we don't cut more than the given maximum allowed
      if (first.length < newLength + max_delta_length)
      {
        access::getLogger()->error(
          "Factory::correctLaneEdgeAtFront() points size change {} -> {} at the end. Length {} -> {}",
          first.ecef_points.size(),
          newPoints.size(),
          first.length,
          newLength);
        std::reverse(newPoints.begin(), newPoints.end());
        first.ecef_points.swap(newPoints);
        first.length = newLength;
        return true;
      }
      else
      {
        access::getLogger()->error(
          "Factory::correctLaneEdgeAtFront() failed. Required points size change {} -> {} at the end. Length {} -> {}",
          first.ecef_points.size(),
          newPoints.size(),
          first.length,
          newLength);
        return false;
      }
    }
    else
    {
      newPoints.push_back(*iter);
    }
  }
  // there seems to be nothing requirred to be cut
  access::getLogger()->error(
    "Factory::correctLaneEdgeAtFront() failed. No direction switch in respect to new end point detected!");
  return false;
}

bool correctLaneEdgeAtBack(::ad::map::point::Geometry &first,
                           ::ad::map::point::ECEFPoint const &new_end_point,
                           ad::physics::Distance const max_delta_length)
{
  auto previousDirection = new_end_point - first.ecef_points.front();
  ad::map::point::ECEFPointList newPoints;
  for (auto iter = first.ecef_points.begin(); iter != first.ecef_points.end(); ++iter)
  {
    auto nextDirection = new_end_point - *iter;
    if (point::vectorDotProduct(previousDirection, nextDirection) < 0.)
    {
      newPoints.push_back(new_end_point);
      ad::physics::Distance newLength = calcLength(newPoints);
      // now the direction towards the new end point switches by more than 90 degrees at once
      // that should be the point where to cut the edge
      // but we only cut if we don't cut more than the given maximum allowed
      if (first.length < newLength + max_delta_length)
      {
        access::getLogger()->error(
          "Factory::correctLaneEdgeAtBack() points size change {} -> {} at the end. Length {} -> {}",
          first.ecef_points.size(),
          newPoints.size(),
          first.length,
          newLength);
        first.ecef_points = newPoints;
        first.length = newLength;
        return true;
      }
      else
      {
        access::getLogger()->error(
          "Factory::correctLaneEdgeAtBack() failed. Required points size change {} -> {} at the end. Length {} -> {}",
          first.ecef_points.size(),
          newPoints.size(),
          first.length,
          newLength);
        return false;
      }
    }
    else
    {
      newPoints.push_back(*iter);
    }
  }
  // there seems to be nothing requirred to be cut
  access::getLogger()->error(
    "Factory::correctLaneEdgeAtBack() failed. No direction switch in respect to new end point detected!");
  return false;
}

bool correctLaneEdge(::ad::map::point::Geometry &first,
                     ::ad::map::point::Geometry const &second,
                     ad::physics::Distance const max_correction_distance = ad::physics::Distance(.5))
{
  bool ok = false;
  if (ad::map::point::distance(first.ecef_points.back(), second.ecef_points.front()) < max_correction_distance)
  {
    ok = correctLaneEdgeAtBack(first, second.ecef_points.front(), max_correction_distance);
  }
  else if (ad::map::point::distance(first.ecef_points.back(), second.ecef_points.back()) < max_correction_distance)
  {
    ok = correctLaneEdgeAtBack(first, second.ecef_points.back(), max_correction_distance);
  }
  else if (ad::map::point::distance(first.ecef_points.front(), second.ecef_points.front()) < max_correction_distance)
  {
    ok = correctLaneEdgeAtFront(first, second.ecef_points.front(), max_correction_distance);
  }
  else if (ad::map::point::distance(first.ecef_points.front(), second.ecef_points.back()) < max_correction_distance)
  {
    ok = correctLaneEdgeAtFront(first, second.ecef_points.back(), max_correction_distance);
  }
  return ok;
}

bool Factory::correctLaneBorder(lane::LaneId from_id, lane::LaneId to_id)
{
  bool ok = false;
  if (lane::isValid(from_id) && lane::isValid(to_id))
  {
    lane::Lane::Ptr from_lane = std::const_pointer_cast<lane::Lane>(mStore.getLanePtr(from_id));
    if (from_lane)
    {
      lane::Lane::ConstPtr to_lane = mStore.getLanePtr(to_id);
      if (to_lane)
      {
        if (from_lane->direction == to_lane->direction)
        {
          auto correct_left_result = correctLaneEdge(from_lane->edge_left, to_lane->edge_left);
          auto correct_right_result = correctLaneEdge(from_lane->edge_right, to_lane->edge_right);
          ok = correct_left_result && correct_right_result;
        }
        else
        {
          auto correct_left_result = correctLaneEdge(from_lane->edge_left, to_lane->edge_right);
          auto correct_right_result = correctLaneEdge(from_lane->edge_right, to_lane->edge_left);
          ok = correct_left_result && correct_right_result;
        }
      }
    }
  }

  if (!ok)
  {
    access::getLogger()->error("Factory::correctLaneBorder({} -> {}) failed", from_id, to_id);
  }
  else
  {
    access::getLogger()->info("Factory::correctLaneBorder({} -> {}) succeeded", from_id, to_id);
  }
  ok = autoConnect(from_id, to_id);
  ok &= autoConnect(to_id, from_id);
  return ok;
}

bool Factory::autoConnect(lane::LaneId from_id, lane::LaneId to_id)
{
  bool ok = false;
  if (lane::isValid(from_id) && lane::isValid(to_id))
  {
    lane::Lane::ConstPtr from_lane = mStore.getLanePtr(from_id);
    if (from_lane)
    {
      lane::Lane::ConstPtr to_lane = mStore.getLanePtr(to_id);
      if (to_lane)
      {
        if (lane::getContactLocation(*from_lane, to_id) == lane::ContactLocation::INVALID)
        {
          static constexpr auto pred = lane::ContactLocation::PREDECESSOR;
          static constexpr auto succ = lane::ContactLocation::SUCCESSOR;
          lane::ContactTypeList types = {lane::ContactType::FREE};
          restriction::Restrictions restrs;
          if (lane::getStartPoint(*from_lane) == lane::getStartPoint(*to_lane))
          {
            ok = add(from_id, to_id, pred, types, restrs);
            access::getLogger()->debug("Factory::autoConnect({} -> {}) pred succeeded {}", from_id, to_id, ok);
          }
          else if (lane::getStartPoint(*from_lane) == lane::getEndPoint(*to_lane))
          {
            ok = add(from_id, to_id, pred, types, restrs);
            access::getLogger()->debug("Factory::autoConnect({} -> {}) pred succeeded {}", from_id, to_id, ok);
          }
          else if (lane::getEndPoint(*from_lane) == lane::getStartPoint(*to_lane))
          {
            ok = add(from_id, to_id, succ, types, restrs);
            access::getLogger()->debug("Factory::autoConnect({} -> {}) succ succeeded {}", from_id, to_id, ok);
          }
          else if (lane::getEndPoint(*from_lane) == lane::getEndPoint(*to_lane))
          {
            ok = add(from_id, to_id, succ, types, restrs);
            access::getLogger()->debug("Factory::autoConnect({} -> {}) succ succeeded {}", from_id, to_id, ok);
          }
        }
      }
      else
      {
        access::getLogger()->error("Non-existing to-lane Factory::autoConnect()");
      }
    }
    else
    {
      access::getLogger()->error("Non-existing from-lane Factory::autoConnect()");
    }
  }
  else
  {
    access::getLogger()->error("Invalid lane identifier passed to Factory::autoConnect()");
  }
  return ok;
}

void Factory::setDefaultIntersectionType(intersection::IntersectionType const defaultIntersectionType)
{
  mDefaultIntersectionType = defaultIntersectionType;
}

void Factory::setDefaultTrafficLightType(landmark::TrafficLightType const defaultTrafficLightType)
{
  mDefaultTrafficLightType = defaultTrafficLightType;
}

restriction::Restrictions Factory::createRoadRestrictions() const
{
  restriction::Restriction roadRestriction;
  roadRestriction.negated = false;
  roadRestriction.passengers_min = 0.;
  roadRestriction.road_user_types
    = {restriction::RoadUserType::CAR, restriction::RoadUserType::BUS, restriction::RoadUserType::TRUCK};
  restriction::Restrictions roadRestrictions;
  roadRestrictions.conjunctions.push_back(roadRestriction);
  return roadRestrictions;
}

void Factory::addDefaultIntersectionContacts()
{
  lane::ContactType defaultIntersectionContact;
  switch (mDefaultIntersectionType)
  {
    case intersection::IntersectionType::HasWay:
      defaultIntersectionContact = lane::ContactType::RIGHT_OF_WAY;
      break;
    case intersection::IntersectionType::Stop:
      defaultIntersectionContact = lane::ContactType::STOP;
      break;
    case intersection::IntersectionType::AllWayStop:
      defaultIntersectionContact = lane::ContactType::STOP_ALL;
      break;
    case intersection::IntersectionType::Yield:
      defaultIntersectionContact = lane::ContactType::YIELD;
      break;
    case intersection::IntersectionType::Crosswalk:
      defaultIntersectionContact = lane::ContactType::CROSSWALK;
      break;
    case intersection::IntersectionType::PriorityToRight:
      defaultIntersectionContact = lane::ContactType::PRIO_TO_RIGHT;
      break;
    case intersection::IntersectionType::PriorityToRightAndStraight:
      defaultIntersectionContact = lane::ContactType::PRIO_TO_RIGHT_AND_STRAIGHT;
      break;
    case intersection::IntersectionType::TrafficLight:
      defaultIntersectionContact = lane::ContactType::TRAFFIC_LIGHT;
      break;
    case intersection::IntersectionType::Unknown:
      return;
    default:
      access::getLogger()->error("Invalid defaultIntersectionType passed {}",
                                 static_cast<int>(mDefaultIntersectionType));
      return;
  }

  for (auto &lane_entry : mStore.lane_map_)
  {
    auto lane_id = lane_entry.first;
    auto lanePtr = lane_entry.second;

    if (lanePtr->type == lane::LaneType::INTERSECTION)
    {
      continue;
    }

    // lane is not an intersection
    lane::ContactLaneList unknownIntersectionTransitions;
    lane::LaneIdSet knownIntersectionTransitions;
    for (auto const &outerContact :
         lane::getContactLanes(*lanePtr, {lane::ContactLocation::SUCCESSOR, lane::ContactLocation::PREDECESSOR}))
    {
      auto intersectionLanePtr = mStore.getLanePtr(outerContact.to_lane);
      if (intersectionLanePtr->type == lane::LaneType::INTERSECTION)
      {
        // intersection successor or predecessor found
        if (((outerContact.location == lane::ContactLocation::SUCCESSOR) && !lane::isLaneDirectionNegative(*lanePtr))
            || ((outerContact.location == lane::ContactLocation::PREDECESSOR)
                && !lane::isLaneDirectionPositive(*lanePtr)))
        {
          auto intersectionType = intersection::Intersection::intersectionTypeFromContactTypes(outerContact.types);
          if (intersectionType == intersection::IntersectionType::Unknown)
          {
            // check the other side of the transition which could carry intersection info
            for (auto const &innerContact : intersectionLanePtr->contact_lanes)
            {
              if (innerContact.to_lane == lane_id)
              {
                if (intersection::Intersection::intersectionTypeFromContactTypes(innerContact.types)
                    != intersection::IntersectionType::Unknown)
                {
                  knownIntersectionTransitions.insert(intersectionLanePtr->id);
                }
              }
            }
            if (knownIntersectionTransitions.find(intersectionLanePtr->id) == knownIntersectionTransitions.end())
            {
              unknownIntersectionTransitions.push_back(outerContact);
            }
          }
          else
          {
            knownIntersectionTransitions.insert(intersectionLanePtr->id);
          }
        }
      }
    }

    for (auto const &contact : unknownIntersectionTransitions)
    {
      if (knownIntersectionTransitions.find(contact.to_lane) == knownIntersectionTransitions.end())
      {
        auto restrictions = createRoadRestrictions();
        if (defaultIntersectionContact == lane::ContactType::TRAFFIC_LIGHT)
        {
          landmark::LandmarkId fakeTrafficLightId(landmark::LandmarkId::cMaxValue);
          point::Geometry bounding_box;
          point::ECEFPoint position;
          point::ECEFPoint orientation;
          if (contact.location == lane::ContactLocation::SUCCESSOR)
          {
            position = lanePtr->edge_right.ecef_points[lanePtr->edge_right.ecef_points.size() - 1];
            orientation = lanePtr->edge_right.ecef_points[lanePtr->edge_right.ecef_points.size() - 2];
          }
          else
          {
            position = lanePtr->edge_left.ecef_points[0];
            orientation = lanePtr->edge_left.ecef_points[1];
          }
          (void)addTrafficLight(
            access::PartitionId(0), fakeTrafficLightId, mDefaultTrafficLightType, position, orientation, bounding_box);
          add(
            lane_id, contact.to_lane, contact.location, {defaultIntersectionContact}, restrictions, fakeTrafficLightId);
        }
        else
        {
          add(lane_id, contact.to_lane, contact.location, {defaultIntersectionContact}, restrictions);
        }
      }
    }
  }
}

/////////////
// Aux Methods

lane::LaneId Factory::getNextLaneId() const
{
  lane::LaneId new_lane_id(0);
  for (auto it : mStore.lane_map_)
  {
    new_lane_id = std::max(new_lane_id, it.second->id);
  }
  new_lane_id += lane::LaneId(1);
  return new_lane_id;
}

} // namespace access
} // namespace map
} // namespace ad
