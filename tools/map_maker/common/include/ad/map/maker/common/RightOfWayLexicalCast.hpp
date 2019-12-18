// ----------------- BEGIN LICENSE BLOCK ---------------------------------
//
// Copyright (C) 2018-2019 Intel Corporation
//
// SPDX-License-Identifier: MIT
//
// ----------------- END LICENSE BLOCK -----------------------------------

#pragma once

#include <boost/lexical_cast.hpp>
#include "ad/map/maker/common/RightOfWay.hpp"

namespace boost {
template <>::ad::map::maker::common::RightOfWay lexical_cast(std::string const &str);
} // namespace boost
