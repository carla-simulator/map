// ----------------- BEGIN LICENSE BLOCK ---------------------------------
//
// Copyright (C) 2017-2020 Intel Corporation
//
// SPDX-License-Identifier: MIT
//
// ----------------- END LICENSE BLOCK -----------------------------------

#pragma once

#include <functional>
#include <ostream>
#include <unordered_map>
#include <unordered_set>

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wconversion"
#if defined(__clang__) && (__clang_major__ >= 8)
#pragma GCC diagnostic ignored "-Wdefaulted-function-deleted"
#endif
#include <osmium/io/xml_output.hpp>
#include <osmium/osm/types.hpp>
#include <osmium/storage/item_stash.hpp>
#pragma GCC diagnostic pop

#include "ad/map/maker/osm_converter/OsmDataBuilder.hpp"
#include "ad/map/maker/osm_converter/OsmJunctionArm.hpp"
#include "ad/map/maker/osm_converter/OsmObjectIdGenerator.hpp"
#include "ad/map/maker/osm_converter/PoiType.hpp"

namespace osmium {
class Node;
class Way;

namespace memory {
class Buffer;
} // namespace memory
} // namespace osmium

namespace ad {
namespace map {
namespace maker {

namespace common {
struct LogChannel;
class LogFactory;
} // namespace common

namespace geometry {
struct Point;
} // namespace geometry

namespace osm_converter {

typedef std::unordered_set<::osmium::object_id_type> ObjectIdSet;

/**
 * @brief Hold all known objects and provide helper functionality on the objects
 *
 * Items are all kept in a so-called ItemStash.
 * @todo remove base class once the old lanelet generated is removed
 */
struct OsmObjectStore : public OsmDataBuilder
{
  explicit OsmObjectStore(common::LogFactory &logFactory);

  void addNode(::osmium::Node const &node);
  void addWay(::osmium::Way const &way);

  bool hasWay(::osmium::object_id_type const wayId) const;
  bool hasNode(::osmium::object_id_type const nodeId) const;

  ObjectIdSet const &waysForNode(::osmium::object_id_type const nodeId) const;

  /// return all known ways
  std::unordered_set<::osmium::object_id_type> allWayIds() const;

  /// return all known nodes
  std::unordered_set<::osmium::object_id_type> allNodeIds() const;

  void write(::osmium::io::Writer &writer);

  /**
   * OsmDataProvider interface implementation
   */
  virtual ::osmium::Node const &node(::osmium::object_id_type const nodeId) const override;
  virtual ::osmium::Way const &way(::osmium::object_id_type const wayId) const override;
  virtual ::osmium::Relation const &relation(::osmium::object_id_type const relationId) const override;
  virtual ::osmium::Node &node(::osmium::object_id_type const nodeId) override;
  virtual ::osmium::Way &way(::osmium::object_id_type const wayId) override;
  virtual ::osmium::Relation &relation(::osmium::object_id_type const relationId) override;

  /**
   * OsmDataBuilder interface implementation
   */
  virtual ::osmium::object_id_type buildNode(geometry::Point const &pt) override;
  virtual ::osmium::object_id_type buildNode(geometry::Point const &pt, ::osmium::object_id_type const id) override;
  virtual ::osmium::object_id_type buildWay(std::vector<::osmium::object_id_type> const &nodes) override;
  virtual ::osmium::object_id_type buildWay(std::vector<::osmium::object_id_type> const &nodes,
                                            ::osmium::object_id_type const id) override;
  virtual ::osmium::object_id_type
    buildRelation(std::function<void(::osmium::memory::Buffer &, ::osmium::builder::RelationBuilder *)>) override;
  virtual ::osmium::object_id_type
  buildRelation(std::function<void(::osmium::memory::Buffer &, ::osmium::builder::RelationBuilder *)>,
                ::osmium::object_id_type const id) override;
  virtual ::osmium::object_id_type getUniqueId() override;

  void disableWriteTimestamp();

private:
  OsmObjectIdGenerator mIdGenerator;
  ::osmium::ItemStash mStash;
  // @todo: change to map or vector, as the unordered map can lead with different compilers
  //        to different ways of processing the OSM map, which causes unittests to fail
  std::unordered_map<::osmium::object_id_type, ::osmium::ItemStash::handle_type> mIdToNodeHandle;
  std::unordered_map<::osmium::object_id_type, ::osmium::ItemStash::handle_type> mIdToWayHandle;
  std::unordered_map<::osmium::object_id_type, ::osmium::ItemStash::handle_type> mIdToRelationHandle;
  std::unordered_map<PoiType, ObjectIdSet> mPois;

  common::LogChannel &mLog;

  // return true if node was processed
  bool nodeMarkedAsHighwayRelatedPoi(::osmium::Node const &node);
  bool nodeMarkedAsNaturalRelatedPoi(::osmium::Node const &node);

  bool mWriteTimestamp{true};
};

} // namespace osm_converter
} // namespace maker
} // namespace map
} // namespace ad
