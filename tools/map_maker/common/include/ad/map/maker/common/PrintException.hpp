// ----------------- BEGIN LICENSE BLOCK ---------------------------------
//
// Copyright (C) 2017-2020 Intel Corporation
//
// SPDX-License-Identifier: MIT
//
// ----------------- END LICENSE BLOCK -----------------------------------

#pragma once

#include <exception>
#include <iostream>

namespace ad {
namespace map {
namespace maker {
namespace common {

static void printException(std::exception const &e, size_t level = 0)
{
  std::cerr << std::string(level, '\t') << "Unhandled exception: " << e.what() << std::endl;
  try
  {
    std::rethrow_if_nested(e);
  }
  catch (const std::exception &e)
  {
    printException(e, level + 1);
  }
  catch (...)
  {
    std::cerr << std::string(level, '\t') << "Unhandled unknown exception" << std::endl;
  }
}

} // namespace common
} // namespace maker
} // namespace map
} // namespace ad
