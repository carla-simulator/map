// ----------------- BEGIN LICENSE BLOCK ---------------------------------
//
// Copyright (C) 2018-2021 Intel Corporation
//
// SPDX-License-Identifier: MIT
//
// ----------------- END LICENSE BLOCK -----------------------------------

#include "ad/map/serialize/SerializeGeneratedLaneTypes.hpp"
#include "../lane/LaneOperationPrivate.hpp"
#include "ad/map/point/BoundingSphereOperation.hpp"
#include "ad/map/point/ECEFOperation.hpp"
#include "ad/map/serialize/SerializeGeneratedTypes.hpp"

namespace ad {
namespace map {
namespace serialize {

bool doSerialize(ISerializer &serializer, lane::Lane &lane)
{
  bool ok = serializer.serialize(SerializeableMagic::Lane) && doSerialize(serializer, lane.id)
    && serializer.serialize(lane.type) && serializer.serialize(lane.direction)
    && doSerialize(serializer, lane.restrictions) && doSerialize(serializer, lane.length)
    && doSerialize(serializer, lane.length_range) && doSerialize(serializer, lane.width)
    && doSerialize(serializer, lane.width_range)
    && serializer.serializeObjectVector(lane.speed_limits)
    // @toDo: version 0.4 compat: keep Edge in for backward compat
    && serializer.serialize(SerializeableMagic::Edge)
    && doSerialize(serializer, lane.edge_left)
    // @toDo: version 0.4 compat: keep Edge in for backward compat
    && serializer.serialize(SerializeableMagic::Edge) && doSerialize(serializer, lane.edge_right)
    && serializer.serializeObjectVector(lane.contact_lanes) && serializer.serialize(SerializeableMagic::ComplianceVer)
    && serializer.serialize(lane.compliance_version) && doSerialize(serializer, lane.bounding_sphere)
    && serializer.serializeObjectVector(lane.visible_landmarks);

  if (ok)
  {
    //@toDO: version 0.4 compat: cope with empty bounding sphere in old files
    if ((lane.bounding_sphere.center == point::createECEFPoint(0., 0., 0.))
        || (lane.bounding_sphere.radius == physics::Distance(0.)))
    {
      lane.bounding_sphere = point::calcBoundingSphere(lane.edge_left, lane.edge_right);
    }
    if (lane.length == physics::Distance(0.))
    {
      // cope with stored zero length lanes
      lane::updateLaneLengths(lane);
    }
  }
  return ok;
}

bool doSerialize(ISerializer &serializer, lane::ContactLane &contactLane)
{
  return serializer.serialize(SerializeableMagic::ContactLane) && doSerialize(serializer, contactLane.to_lane)
    && serializer.serialize(contactLane.location) && serializer.serializeVector(contactLane.types)
    && doSerialize(serializer, contactLane.restrictions) && doSerialize(serializer, contactLane.landmark_id);
}

} // namespace serialize
} // namespace map
} // namespace ad
