// ----------------- BEGIN LICENSE BLOCK ---------------------------------
//
// Copyright (C) 2017-2020 Intel Corporation
//
// SPDX-License-Identifier: MIT
//
// ----------------- END LICENSE BLOCK -----------------------------------

#pragma once

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wconversion"
#include <osmium/osm/types.hpp>
#pragma GCC diagnostic pop

namespace ad {
namespace map {
namespace maker {
namespace osm_converter {

/*!
 * \brief OsmObjectIdGenerator
 */
class OsmObjectIdGenerator
{
public:
  // Default constructor
  OsmObjectIdGenerator(::osmium::object_id_type initial_id = 1)
    : value(initial_id)
  {
  }

  // Destructor
  ~OsmObjectIdGenerator() = default;

  // Default move constructor
  OsmObjectIdGenerator(OsmObjectIdGenerator &&) = default;

  // Default move assignment operator
  OsmObjectIdGenerator &operator=(OsmObjectIdGenerator &&) = default;

  // Deleted copy constructor
  OsmObjectIdGenerator(OsmObjectIdGenerator const &) = delete;

  // Deleted copy assignment operator
  OsmObjectIdGenerator &operator=(OsmObjectIdGenerator const &) = delete;

  void updateUniqueId(::osmium::object_id_type id)
  {
    if (value <= id)
    {
      value = id + 1;
    }
  }

  ::osmium::object_id_type getNextUniqueObjectId()
  {
    return value++;
  }

private:
  ::osmium::object_id_type value;
};

} // namespace osm_converter
} // namespace maker
} // namespace map
} // namespace ad
