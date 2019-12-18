// ----------------- BEGIN LICENSE BLOCK ---------------------------------
//
// Copyright (C) 2018-2019 Intel Corporation
//
// SPDX-License-Identifier: MIT
//
// ----------------- END LICENSE BLOCK -----------------------------------

#pragma once

#include <stdint.h>

namespace ad {
namespace map {
namespace maker {
namespace map_data {

//! id type used throughout map_data
typedef uint64_t MapDataId;
constexpr MapDataId InvalidId = 0u;

} // namespace map_data
} // namespace maker
} // namespace map
} // namespace ad
