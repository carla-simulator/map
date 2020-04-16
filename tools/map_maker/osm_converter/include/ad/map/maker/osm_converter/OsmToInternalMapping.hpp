// ----------------- BEGIN LICENSE BLOCK ---------------------------------
//
// Copyright (C) 2018-2020 Intel Corporation
//
// SPDX-License-Identifier: MIT
//
// ----------------- END LICENSE BLOCK -----------------------------------

#pragma once

#include <map>

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wconversion"
#include <osmium/osm/types.hpp>
#pragma GCC diagnostic pop

#include <ad/map/maker/geometry/Point2d.hpp>
#include <ad/map/maker/map_data/MapDataId.hpp>

namespace ad {
namespace map {
namespace maker {

namespace common {
struct LogChannel;
class LogFactory;
} // namespace common

namespace map_data {
class MapDataStore;
} // namespace map_data

namespace osm_converter {
class PointStore;

/*
 * @brief hold a mapping osm nodes to points in map_data (node id to DataId and position)
 */
class OsmToInternalMapping
{
public:
  OsmToInternalMapping(PointStore const &pointStore,
                       map_data::MapDataStore &mapDataStore,
                       common::LogFactory &logFactory);

  //! add a node without any mapping
  void addNode(::osmium::object_id_type nodeId);

  //! add a node to the MapDataStore, return generated id of node
  map_data::MapDataId addNodeToMap(::osmium::object_id_type nodeId);

  //! add an already created pair of node/map data ids
  void addNodeMapping(::osmium::object_id_type const nodeId, map_data::MapDataId dataId);

  //! add/update the location for the node with id nodeId
  void addPointForNode(::osmium::object_id_type const nodeId, geometry::Point2d const &point);

  //! add/update all data for node id, map data it. and location
  void addNodeMappingAndPoint(::osmium::object_id_type const nodeId,
                              map_data::MapDataId dataId,
                              geometry::Point2d const &point);

  //! @return location for given node id
  geometry::Point2d const &pointForNodeId(::osmium::object_id_type nodeId) const;

  //! @return location converted from OsmPoint
  geometry::Point2d fromOsmPoint(::osmium::object_id_type osmPointId) const;

  //! @return MapDataId for given node id
  map_data::MapDataId mapDataIdForNodeId(::osmium::object_id_type nodeId) const;

private:
  PointStore const &mPointStore;
  map_data::MapDataStore &mMapDataStore;
  common::LogChannel &mLog;

  struct PointMap
  {
    map_data::MapDataId id;
    geometry::Point2d point;
  };
  std::map<::osmium::object_id_type, PointMap> mPointMap;

  map_data::MapDataId getOrCreateIdForOsmPoint(::osmium::object_id_type const &osmPointId) const;
};

} // namespace osm_converter
} // namespace maker
} // namespace map
} // namespace ad
