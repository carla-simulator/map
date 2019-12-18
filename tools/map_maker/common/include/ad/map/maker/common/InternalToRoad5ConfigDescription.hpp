// ----------------- BEGIN LICENSE BLOCK ---------------------------------
//
// Copyright (C) 2018-2019 Intel Corporation
//
// SPDX-License-Identifier: MIT
//
// ----------------- END LICENSE BLOCK -----------------------------------

#pragma once

#include <boost/program_options/options_description.hpp>
#include "ad/map/maker/common/InternalToRoad5Config.hpp"

namespace ad {
namespace map {
namespace maker {
namespace common {

/*!
 * \brief Option parsing for InternalToRoad5
 */
struct InternalToRoad5ConfigDescription : ::boost::program_options::options_description
{
  InternalToRoad5ConfigDescription();
  InternalToRoad5Config config;
};

} // namespace common
} // namespace maker
} // namespace map
} // namespace ad
