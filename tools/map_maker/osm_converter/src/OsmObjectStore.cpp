// ----------------- BEGIN LICENSE BLOCK ---------------------------------
//
// Copyright (C) 2017-2020 Intel Corporation
//
// SPDX-License-Identifier: MIT
//
// ----------------- END LICENSE BLOCK -----------------------------------

#include "ad/map/maker/osm_converter/OsmObjectStore.hpp"

#include <ctime> // for std::time()

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wconversion"
#include <osmium/builder/osm_object_builder.hpp>
#include <osmium/osm/node.hpp>
#include <osmium/osm/way.hpp>
#pragma GCC diagnostic pop

#include <ad/map/maker/common/LogChannel.hpp>
#include <ad/map/maker/common/LogFactory.hpp>
#include <ad/map/maker/geometry/Point.hpp>

namespace ad {
namespace map {
namespace maker {
namespace osm_converter {

OsmObjectStore::OsmObjectStore(common::LogFactory &logFactory)
  : mIdGenerator(1)
  , mLog(logFactory.logChannel("OsmStore"))
{
}

void OsmObjectStore::addNode(::osmium::Node const &node)
{
  ::osmium::ItemStash::handle_type handle = mStash.add_item(node);
  mIdToNodeHandle[node.id()] = handle;
  mIdGenerator.updateUniqueId(node.id());
}

void OsmObjectStore::addWay(::osmium::Way const &way)
{
  ::osmium::ItemStash::handle_type handle = mStash.add_item(way);
  mIdToWayHandle[way.id()] = handle;
  mIdGenerator.updateUniqueId(way.id());
}

bool OsmObjectStore::hasWay(::osmium::object_id_type const wayId) const
{
  return (mIdToWayHandle.count(wayId) == 1);
}

bool OsmObjectStore::hasNode(::osmium::object_id_type const nodeId) const
{
  return (mIdToNodeHandle.count(nodeId) == 1);
}

::osmium::object_id_type OsmObjectStore::buildNode(geometry::Point const &pt)
{
  return buildNode(pt, mIdGenerator.getNextUniqueObjectId());
}

template <typename ItemTypeDerived, typename ItemType>
void setDefaultInfoForBuilder(typename ::osmium::builder::OSMObjectBuilder<ItemTypeDerived, ItemType> &builder,
                              bool writeTimestamp,
                              ::osmium::object_id_type id)
{
  builder.set_user("Intel");
  builder.object().set_uid(1);
  builder.object().set_version(1);
  builder.object().set_visible(true);
  if (writeTimestamp)
  {
    builder.object().set_timestamp(std::time(nullptr));
  }
  else
  {
    builder.object().set_timestamp(0);
  }
  builder.object().set_id(id);
}

::osmium::object_id_type OsmObjectStore::buildNode(geometry::Point const &pt, ::osmium::object_id_type id)
{
  ::osmium::memory::Buffer temp_buffer{128, ::osmium::memory::Buffer::auto_grow::no};

  ::osmium::builder::NodeBuilder builder{temp_buffer};
  // can we make a common function that calls all these add_user, set_uid, ...
  // --> yes, use a templated function (this is just an exercise as all writing
  //     functionality will be removed once osm_to_lanelet_old will be removed.
  setDefaultInfoForBuilder(builder, mWriteTimestamp, id);
  builder.object().set_id(id);
  builder.object().set_location(::osmium::Location{pt.longitude, pt.latitude});

  mIdToNodeHandle[id] = mStash.add_item(builder.object());

  return id;
}

::osmium::object_id_type OsmObjectStore::buildWay(std::vector<::osmium::object_id_type> const &nodes)
{
  return buildWay(nodes, mIdGenerator.getNextUniqueObjectId());
}

::osmium::object_id_type OsmObjectStore::buildWay(std::vector<::osmium::object_id_type> const &nodes,
                                                  ::osmium::object_id_type id)
{
  ::osmium::memory::Buffer temp_buffer{64, ::osmium::memory::Buffer::auto_grow::yes};

  ::osmium::builder::WayBuilder way_builder{temp_buffer};
  setDefaultInfoForBuilder(way_builder, mWriteTimestamp, id);

  {
    ::osmium::builder::WayNodeListBuilder wnl_builder{temp_buffer, &way_builder};
    for (auto const &node : nodes)
    {
      wnl_builder.add_node_ref(::osmium::NodeRef{node, ::osmium::Location()});
    }
  }

  mIdToWayHandle[id] = mStash.add_item(way_builder.object());

  return id;
}

::osmium::object_id_type OsmObjectStore::buildRelation(
  std::function<void(::osmium::memory::Buffer &, ::osmium::builder::RelationBuilder *)> factory,
  ::osmium::object_id_type id)
{
  ::osmium::memory::Buffer temp_buffer{64, ::osmium::memory::Buffer::auto_grow::yes};
  ::osmium::builder::RelationBuilder rel_builder{temp_buffer};
  setDefaultInfoForBuilder(rel_builder, mWriteTimestamp, id);

  factory(temp_buffer, &rel_builder);

  mIdToRelationHandle[id] = mStash.add_item(rel_builder.object());

  return id;
}

::osmium::object_id_type OsmObjectStore::buildRelation(
  std::function<void(::osmium::memory::Buffer &, ::osmium::builder::RelationBuilder *)> factory)
{
  return buildRelation(factory, mIdGenerator.getNextUniqueObjectId());
}

::osmium::Node const &OsmObjectStore::node(::osmium::object_id_type const nodeId) const
{
  ::osmium::ItemStash::handle_type handle = mIdToNodeHandle.at(nodeId);
  return mStash.get<::osmium::Node>(handle);
}

::osmium::Node &OsmObjectStore::node(::osmium::object_id_type const nodeId)
{
  ::osmium::ItemStash::handle_type handle = mIdToNodeHandle.at(nodeId);
  return mStash.get<::osmium::Node>(handle);
}

::osmium::Way const &OsmObjectStore::way(::osmium::object_id_type const wayId) const
{
  ::osmium::ItemStash::handle_type handle = mIdToWayHandle.at(wayId);
  return mStash.get<::osmium::Way>(handle);
}

::osmium::Way &OsmObjectStore::way(::osmium::object_id_type const wayId)
{
  ::osmium::ItemStash::handle_type handle = mIdToWayHandle.at(wayId);
  return mStash.get<::osmium::Way>(handle);
}

::osmium::Relation const &OsmObjectStore::relation(::osmium::object_id_type const relationId) const
{
  ::osmium::ItemStash::handle_type handle = mIdToRelationHandle.at(relationId);
  return mStash.get<::osmium::Relation>(handle);
}

::osmium::Relation &OsmObjectStore::relation(::osmium::object_id_type const relationId)
{
  ::osmium::ItemStash::handle_type handle = mIdToRelationHandle.at(relationId);
  return mStash.get<::osmium::Relation>(handle);
}

std::unordered_set<::osmium::object_id_type> OsmObjectStore::allWayIds() const
{
  std::unordered_set<::osmium::object_id_type> result;
  for (auto way : mIdToWayHandle)
  {
    result.insert(way.first);
  }
  return result;
}

std::unordered_set<::osmium::object_id_type> OsmObjectStore::allNodeIds() const
{
  std::unordered_set<::osmium::object_id_type> result;
  for (auto node : mIdToNodeHandle)
  {
    result.insert(node.first);
  }
  return result;
}

void OsmObjectStore::write(::osmium::io::Writer &writer)
{
  for (auto const &nodeHandleIter : mIdToNodeHandle)
  {
    writer(mStash.get_item(nodeHandleIter.second));
  }
  for (auto const &wayHandleIter : mIdToWayHandle)
  {
    writer(mStash.get_item(wayHandleIter.second));
  }
  for (auto const &relationHandleIter : mIdToRelationHandle)
  {
    writer(mStash.get_item(relationHandleIter.second));
  }
  mStash.clear();
}

::osmium::object_id_type OsmObjectStore::getUniqueId()
{
  {
    return mIdGenerator.getNextUniqueObjectId();
  }
}

void OsmObjectStore::disableWriteTimestamp()
{
  mWriteTimestamp = false;
}

} // namespace osm_converter
} // namespace maker
} // namespace map
} // namespace ad
