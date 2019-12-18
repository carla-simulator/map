// ----------------- BEGIN LICENSE BLOCK ---------------------------------
//
// Copyright (C) 2018-2019 Intel Corporation
//
// SPDX-License-Identifier: MIT
//
// ----------------- END LICENSE BLOCK -----------------------------------

#pragma once

#include "ad/map/lane/Types.hpp"
#include "ad/map/serialize/ISerializer.hpp"

/** @brief namespace ad */
namespace ad {
/** @brief namespace map */
namespace map {
/** @brief namespace serialize */
namespace serialize {

/**
 * @brief serializer for lane::Lane
 */
template <> bool doSerialize(ISerializer &serializer, lane::Lane &lane);

/**
 * @brief serializer for lane::ContactLane
 */
template <> bool doSerialize(ISerializer &serializer, lane::ContactLane &contactLane);

} // namespace serialize
} // namespace map
} // namespace ad
