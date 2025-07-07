// ----------------- BEGIN LICENSE BLOCK ---------------------------------
//
// Copyright (C) 2018-2021 Intel Corporation
//
// SPDX-License-Identifier: MIT
//
// ----------------- END LICENSE BLOCK -----------------------------------
/**
 * @file
 */

#pragma once

#include "ad/map/access/Types.hpp"
#include "ad/map/serialize/ISerializer.hpp"

/** @brief namespace ad */
namespace ad {
/** @brief namespace map */
namespace map {
/** @brief namespace serialize */
namespace serialize {

/**
 * @brief Serializer for access::PartitionId
 */
inline bool doSerialize(ISerializer &serializer, access::PartitionId &x)
{
  return serializer.serializeGeneratedType<access::PartitionId, uint64_t, SerializeableMagic::PartitionId>(x);
}

/**
 * @brief Serializer for access::GeometryStoreItem
 */
inline bool doSerialize(ISerializer &serializer, access::GeometryStoreItem &item)
{
  return serializer.serialize(SerializeableMagic::GeometryStoreItem) && serializer.serialize(item.left_edge_offset)
    && serializer.serialize(item.left_edge_points) && serializer.serialize(item.right_edge_offset)
    && serializer.serialize(item.right_edge_points);
}

/**
 * @brief Serializer for access::MapMetaData
 */
inline bool doSerialize(ISerializer &serializer, access::MapMetaData &metaData)
{
  return serializer.serialize(SerializeableMagic::MapMetaData) && serializer.serialize(metaData.traffic_type);
}

} // namespace serialize
} // namespace map
} // namespace ad
