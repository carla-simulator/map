/*
 * ----------------- BEGIN LICENSE BLOCK ---------------------------------
 *
 * Copyright (c) 2017 Computer Vision Center (CVC) at the Universitat Autonoma
 * de Barcelona (UAB).
 * Copyright (C) 2019-2024 Intel Corporation
 *
 * SPDX-License-Identifier: MIT
 *
 * ----------------- END LICENSE BLOCK -----------------------------------
 */
/**
 * @file
 */

#pragma once

#include <boost/version.hpp>
#define BOOST_MINOR (BOOST_VERSION / 100 % 1000)
#define BOOST_MAJOR (BOOST_VERSION / 100000)

#if (BOOST_MAJOR == 1) and (BOOST_MINOR < 78)

#include "opendrive/geometry/ArrayType.hpp"

namespace opendrive {
namespace geometry {

  template<class T, std::size_t N>
  using ArrayType = boost::array<T,N>;
}
}

#else

#include <array>

namespace opendrive {
namespace geometry {
  template<class T, std::size_t N>
  using ArrayType = std::array<T,N>;
}
}

#endif
