// ----------------- BEGIN LICENSE BLOCK ---------------------------------
//
// INTEL CONFIDENTIAL
//
// Copyright (c) 2018-2019 Intel Corporation
//
// This software and the related documents are Intel copyrighted materials, and
// your use of them is governed by the express license under which they were
// provided to you (License). Unless the License provides otherwise, you may not
// use, modify, copy, publish, distribute, disclose or transmit this software or
// the related documents without Intel's prior written permission.
//
// This software and the related documents are provided as is, with no express or
// implied warranties, other than those that are expressly stated in the License.
//
// ----------------- END LICENSE BLOCK -----------------------------------

#include "ad/map/maker/osm_converter/OsmToInternalMapping.hpp"
#include <ad/map/maker/common/LogChannel.hpp>
#include <ad/map/maker/common/LogFactory.hpp>
#include <ad/map/maker/map_data/MapDataStore.hpp>
#include "ad/map/maker/osm_converter/PointStore.hpp"

namespace ad {
namespace map {
namespace maker {
namespace osm_converter {

OsmToInternalMapping::OsmToInternalMapping(PointStore const &pointStore,
                                           map_data::MapDataStore &mapDataStore,
                                           common::LogFactory &logFactory)
  : mPointStore(pointStore)
  , mMapDataStore(mapDataStore)
  , mLog(logFactory.logChannel("OsmToInternalMapping"))
{
}

geometry::Point2d OsmToInternalMapping::fromOsmPoint(::osmium::object_id_type osmPointId) const
{
  auto point = mPointStore.point(osmPointId);
  return geometry::Point2d(point.x, point.y);
}

map_data::MapDataId OsmToInternalMapping::getOrCreateIdForOsmPoint(::osmium::object_id_type const &osmPointId) const
{
  auto pointId = mMapDataStore.getOrCreateIdForPoint(fromOsmPoint(osmPointId));
  mLog(common::LogLevel::Verbose) << "    Map node (way) " << osmPointId << " to " << pointId << "\n";
  return pointId;
}

void OsmToInternalMapping::addNode(::osmium::object_id_type nodeId)
{
  (void)nodeId;
  // mPointMap[nodeId] = map_data::Invalid;
}

map_data::MapDataId OsmToInternalMapping::addNodeToMap(::osmium::object_id_type nodeId)
{
  auto id = getOrCreateIdForOsmPoint(nodeId);
  mPointMap[nodeId].id = id;
  mLog(common::LogLevel::Info) << "Adding node: " << nodeId << " -> " << id << " " << fromOsmPoint(nodeId) << "\n";
  return id;
}

void OsmToInternalMapping::addNodeMapping(::osmium::object_id_type const nodeId, map_data::MapDataId dataId)
{
  if (mPointMap.count(nodeId) == 1)
  {
    mLog(common::LogLevel::Info) << "Re-setting existing id. Node: " << nodeId << " Having " << mPointMap[nodeId].id
                                 << " got " << dataId << "\n";
  }

  mLog(common::LogLevel::Info) << "Adding node mapping: " << nodeId << " -> " << dataId << " " << fromOsmPoint(nodeId)
                               << "\n";
  mPointMap[nodeId].id = dataId;
}

void OsmToInternalMapping::addPointForNode(::osmium::object_id_type const nodeId, geometry::Point2d const &point)
{
  if (mPointMap.count(nodeId) == 1)
  {
    mLog(common::LogLevel::Info) << "Re-setting existing point. Node: " << nodeId << " Having " << mPointMap[nodeId].id
                                 << " with " << mPointMap[nodeId].point << " got " << point << "\n";
  }
  mLog(common::LogLevel::Info) << "Adding point for node: " << nodeId << " -> " << mPointMap[nodeId].id << " " << point
                               << "\n";
  mPointMap[nodeId].point = point;
}

void OsmToInternalMapping::addNodeMappingAndPoint(::osmium::object_id_type const nodeId,
                                                  map_data::MapDataId dataId,
                                                  geometry::Point2d const &point)
{
  if (mPointMap.count(nodeId) == 1)
  {
    mLog(common::LogLevel::Info) << "Updating existing point. Node: " << nodeId << " Having " << mPointMap[nodeId].id
                                 << " with " << mPointMap[nodeId].point << " got " << point << "\n";
  }
  mLog(common::LogLevel::Info) << "Updating data for node: " << nodeId << " -> " << dataId << " " << point << "\n";
  mPointMap[nodeId].id = dataId;
  mPointMap[nodeId].point = point;
}

geometry::Point2d const &OsmToInternalMapping::pointForNodeId(::osmium::object_id_type nodeId) const
{
  return mPointMap.at(nodeId).point;
}

map_data::MapDataId OsmToInternalMapping::mapDataIdForNodeId(::osmium::object_id_type nodeId) const
{
  return mPointMap.at(nodeId).id;
}

} // namespace osm_converter
} // namespace maker
} // namespace map
} // namespace ad
