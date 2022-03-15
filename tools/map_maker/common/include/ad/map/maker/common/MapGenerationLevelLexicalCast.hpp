// ----------------- BEGIN LICENSE BLOCK ---------------------------------
//
// Copyright (C) 2018-2019 Intel Corporation
//
// SPDX-License-Identifier: MIT
//
// ----------------- END LICENSE BLOCK -----------------------------------
/**
 * @file
 */

#pragma once

#include <boost/lexical_cast.hpp>
#include "ad/map/maker/common/MapGenerationLevel.hpp"

namespace boost {
template <>::ad::map::maker::common::MapGenerationLevel lexical_cast(std::string const &str);
} // namespace boost
