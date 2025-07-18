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

#include "ad/map/landmark/Types.hpp"
#include "ad/map/serialize/ISerializer.hpp"
#include "ad/map/serialize/SerializeGeneratedPointTypes.hpp"

/** @brief namespace ad */
namespace ad {
/** @brief namespace map */
namespace map {
/** @brief namespace serialize */
namespace serialize {

/**
 * @brief serializer for landmark::LandmarkId
 */
inline bool doSerialize(ISerializer &serializer, landmark::LandmarkId &x)
{
  return serializer.serializeGeneratedType<landmark::LandmarkId, uint64_t, SerializeableMagic::LandmarkId>(x);
}

/**
 * @brief serializer for landmark::Landmark
 */
inline bool doSerialize(ISerializer &serializer, landmark::Landmark &landmark)
{
  return serializer.serialize(SerializeableMagic::Landmark) && doSerialize(serializer, landmark.id)
    && serializer.serialize(landmark.type) && doSerialize(serializer, landmark.position)
    && doSerialize(serializer, landmark.orientation) && doSerialize(serializer, landmark.bounding_box)
    && doSerialize(serializer, landmark.supplementary_text) && serializer.serialize(landmark.traffic_light_type)
    && serializer.serialize(landmark.traffic_sign_type);
}

} // namespace serialize
} // namespace map
} // namespace ad
