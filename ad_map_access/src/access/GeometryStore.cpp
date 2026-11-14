// ----------------- BEGIN LICENSE BLOCK ---------------------------------
//
// Copyright (C) 2018-2021 Intel Corporation
//
// SPDX-License-Identifier: MIT
//
// ----------------- END LICENSE BLOCK -----------------------------------

#include "GeometryStore.hpp"
#include <algorithm>
#include <cstdlib>
#include <limits>
#include <memory>
#include "../lane/LaneOperationPrivate.hpp"
#include "ad/map/access/Logging.hpp"
#include "ad/map/access/Store.hpp"
#include "ad/map/lane/LaneOperation.hpp"
#include "ad/map/point/BoundingSphereOperation.hpp"
#include "ad/map/point/GeometryOperation.hpp"
#include "ad/map/serialize/SerializeGeneratedTypes.hpp"

namespace ad {
namespace map {
namespace access {

GeometryStore::GeometryStore(Store const *map_store)
{
  store_ = nullptr;
  points3d_ = 0;
  capacity3d_ = 0;
  map_store_ = map_store;
}

GeometryStore::~GeometryStore()
{
  destroy();
}

/////////////
// Operations

bool GeometryStore::store(lane::Lane::ConstPtr lane)
{
  if (lane)
  {
    lane::LaneId id = lane->id;
    auto it = lane_items_.find(id);
    if (it == lane_items_.end())
    {
      uint32_t offset_left = 0, size_left = 0;
      if (store(lane, lane::ContactLocation::LEFT, offset_left, size_left))
      {
        uint32_t offset_right = 0, size_right = 0;
        if (store(lane, lane::ContactLocation::RIGHT, offset_right, size_right))
        {
          GeometryStoreItem item;
          item.left_edge_offset = offset_left;
          item.left_edge_points = size_left;
          item.right_edge_offset = offset_right;
          item.right_edge_points = size_right;
          lane_items_[id] = item;
          return true;
        }
      }
    }
    else
    {
      access::getLogger()->error("GeometryStore: Lane already in Store?! {}", id);
      throw std::runtime_error("GeometryStore: Lane already in Store?! ");
    }
  }
  else
  {
    throw std::runtime_error("GeometryStore: Lane invalid");
  }
  return false;
}

bool GeometryStore::restore(lane::Lane::Ptr lane) const
{
  if (lane)
  {
    lane::LaneId id = lane->id;
    auto it = lane_items_.find(id);
    if (it != lane_items_.end())
    {
      const GeometryStoreItem &item = it->second;
      point::ECEFPointList left;
      if (restore(left, item.left_edge_offset, item.left_edge_points))
      {
        point::ECEFPointList right;
        if (restore(right, item.right_edge_offset, item.right_edge_points))
        {
          lane->edge_left = point::createGeometry(left, false);
          lane->edge_right = point::createGeometry(right, false);
          if ((lane->bounding_sphere.center == point::createECEFPoint(0., 0., 0.))
              || (lane->bounding_sphere.radius == physics::Distance(0.)))
          {
            lane->bounding_sphere = point::calcBoundingSphere(lane->edge_left, lane->edge_right);
          }
          if (lane->length == physics::Distance(0.))
          {
            lane::updateLaneLengths(*lane);
          }
          return true;
        }
        else
        {
          access::getLogger()->error("GeometryStore: Lane right edge not in Store?! {}", id);
        }
      }
      else
      {
        access::getLogger()->error("GeometryStore: Lane left edge not in Store?! {}", id);
      }
    }
    else
    {
      access::getLogger()->error("GeometryStore: Lane not in Store?! {}", id);
    }
  }
  else
  {
    throw std::runtime_error("GeometryStore: Lane invalid");
  }
  return false;
}

bool GeometryStore::check(lane::Lane::ConstPtr lane) const
{
  if (lane)
  {
    lane::LaneId id = lane->id;
    auto it = lane_items_.find(id);
    if (it != lane_items_.end())
    {
      const GeometryStoreItem &item = it->second;
      point::ECEFPointList left;
      if (restore(left, item.left_edge_offset, item.left_edge_points))
      {
        point::ECEFPointList right;
        if (restore(right, item.right_edge_offset, item.right_edge_points))
        {
          if (lane->edge_left.ecef_points == left && lane->edge_right.ecef_points == right)
          {
            return true;
          }
          else
          {
            access::getLogger()->error("GeometryStore: Lane geometry mismatch?! {}", id);
          }
        }
        else
        {
          access::getLogger()->error("GeometryStore: Lane right edge not in Store?! {}", id);
        }
      }
      else
      {
        access::getLogger()->error("GeometryStore: Lane left edge not in Store?! {}", id);
      }
    }
    else
    {
      access::getLogger()->error("GeometryStore: Lane not in Store?! {}", id);
    }
  }
  else
  {
    throw std::runtime_error("GeometryStore: Lane invalid");
  }
  return false;
}

///////////////
// Aux Methods

bool GeometryStore::store(lane::Lane::ConstPtr lane, lane::ContactLocation location, uint32_t &offs3d, uint32_t &size)
{
  if ((location != lane::ContactLocation::LEFT) && (location != lane::ContactLocation::RIGHT))
  {
    throw std::runtime_error("Location must be LEFT or RIGHT");
  }
  const point::ECEFPointList &ecef
    = (location == lane::ContactLocation::LEFT) ? lane->edge_left.ecef_points : lane->edge_right.ecef_points;
  if (ecef.size() > std::numeric_limits<uint32_t>::max())
  {
    return false;
  }
  size = static_cast<uint32_t>(ecef.size());
  lane::ContactLaneList contact_lanes = lane::getContactLanes(*lane, location);
  for (auto const &contact_lane : contact_lanes)
  {
    lane::LaneId contact_lane_id = contact_lane.to_lane;
    auto it = lane_items_.find(contact_lane_id);
    if (it != lane_items_.end())
    {
      lane::Lane::ConstPtr clane
        = (map_store_ != nullptr) ? map_store_->getLanePtr(contact_lane_id) : lane::getLanePtr(contact_lane_id);
      if (clane)
      {
        const point::ECEFPointList &ecef1
          = (location == lane::ContactLocation::LEFT) ? clane->edge_right.ecef_points : clane->edge_left.ecef_points;
        if (ecef == ecef1)
        {
          offs3d
            = (location == lane::ContactLocation::LEFT) ? it->second.right_edge_offset : it->second.left_edge_offset;
          return true;
        }
      }
    }
  }
  return store(ecef, offs3d);
}

bool GeometryStore::store(const point::ECEFPointList &ecef, uint32_t &offset3d)
{
  if (ecef.size() > std::numeric_limits<uint32_t>::max() - points3d_)
  {
    access::getLogger()->error("GeometryStore: Point count overflow.");
    return false;
  }
  while (static_cast<size_t>(points3d_) + ecef.size() > static_cast<size_t>(capacity3d_))
  {
    if (!expand())
    {
      return false;
    }
  }
  offset3d = points3d_;
  for (auto const &pt : ecef)
  {
    size_t index = static_cast<size_t>(points3d_++) * 3u;
    store_[index++] = pt.x.mECEFCoordinate;
    store_[index++] = pt.y.mECEFCoordinate;
    store_[index++] = pt.z.mECEFCoordinate;
  }
  return true;
}

bool GeometryStore::restore(point::ECEFPointList &ecef, uint32_t offset3d, uint32_t points3d) const
{
  if (!ecef.empty())
  {
    throw std::runtime_error("ecef not empty");
  }
  if (static_cast<size_t>(offset3d) + static_cast<size_t>(points3d) <= static_cast<size_t>(capacity3d_))
  {
    ecef.reserve(points3d);
    for (size_t index = static_cast<size_t>(offset3d) * 3u; points3d != 0u; points3d--)
    {
      point::ECEFPoint pt;
      pt.x = point::ECEFCoordinate(store_[index++]);
      pt.y = point::ECEFCoordinate(store_[index++]);
      pt.z = point::ECEFCoordinate(store_[index++]);
      ecef.push_back(pt);
    }
    return true;
  }
  else
  {
    return false;
  }
}

//////////////
// Aux Methods

void GeometryStore::destroy()
{
  if (store_ != nullptr)
  {
    free(store_);
    store_ = nullptr;
    access::getLogger()->debug("GeometryStore: Destroyed.");
  }
  points3d_ = 0;
  capacity3d_ = 0;
}

bool GeometryStore::expand()
{
  if (store_ == nullptr)
  {
    return create(SIZE_INCREMENT);
  }
  else
  {
    if (capacity3d_ == std::numeric_limits<uint32_t>::max())
    {
      access::getLogger()->error("GeometryStore: Maximum capacity reached.");
      return false;
    }
    uint32_t const new_capacity = (capacity3d_ > std::numeric_limits<uint32_t>::max() / 2u)
      ? std::numeric_limits<uint32_t>::max()
      : std::max(capacity3d_ * 2u, capacity3d_ + SIZE_INCREMENT);
    size_t const bytes = static_cast<size_t>(new_capacity) * 3u * sizeof(double);
    double *store = static_cast<double *>(std::realloc(store_, bytes));
    if (store != nullptr)
    {
      store_ = store;
      capacity3d_ = new_capacity;
      return true;
    }
    else
    {
      access::getLogger()->error("GeometryStore: Cannot expand to {} bytes.", bytes);
      return false;
    }
  }
}

bool GeometryStore::create(uint32_t capacity3d)
{
  destroy();
  if (capacity3d == 0u)
  {
    return true;
  }
  size_t const bytes = static_cast<size_t>(capacity3d) * 3u * sizeof(double);
  store_ = static_cast<double *>(std::malloc(bytes));
  if (store_ != nullptr)
  {
    points3d_ = 0;
    capacity3d_ = capacity3d;
    return true;
  }
  else
  {
    access::getLogger()->error("GeometryStore: Cannot allocate {} bytes.", bytes);
    return false;
  }
}

bool GeometryStore::serialize(serialize::ISerializer &serializer)
{
  bool ok = serializer.serialize(serialize::SerializeableMagic::GeometryStore)
    && serializer.serializeObjectMap(lane_items_) && serializer.serialize(points3d_);

  /*Todo the two lines below will be deleted after the map are generated again without use_zfp_*/
  bool use_zfp_ = false;
  ok = ok && serializer.serialize(use_zfp_);

  if (ok)
  {
    size_t const bytes = static_cast<size_t>(points3d_) * 3u * sizeof(double);
    if (!serializer.isStoring())
    {
      uint32_t const target_points3d = points3d_;
      if (create(target_points3d))
      {
        points3d_ = capacity3d_;
      }
      else
      {
        return false;
      }
      ok = serializer.read(store_, bytes);
    }
    else
    {
      ok = serializer.write(store_, bytes);
    }
  }
  return ok;
}

} // namespace access
} // namespace map
} // namespace ad
