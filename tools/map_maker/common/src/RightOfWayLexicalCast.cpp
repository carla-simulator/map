// ----------------- BEGIN LICENSE BLOCK ---------------------------------
//
// Copyright (C) 2018-2019 Intel Corporation
//
// SPDX-License-Identifier: MIT
//
// ----------------- END LICENSE BLOCK -----------------------------------

#include "ad/map/maker/common/RightOfWayLexicalCast.hpp"

namespace boost {

template <>::ad::map::maker::common::RightOfWay lexical_cast(std::string const &str)
{
  return ::ad::map::maker::common::rowFromString(str);
}

} // namespace boost
