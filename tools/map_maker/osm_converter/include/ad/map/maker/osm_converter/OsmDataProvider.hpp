// ----------------- BEGIN LICENSE BLOCK ---------------------------------
//
// INTEL CONFIDENTIAL
//
// Copyright (c) 2017-2019 Intel Corporation
//
// This software and the related documents are Intel copyrighted materials, and
// your use of them is governed by the express license under which they were
// provided to you (License). Unless the License provides otherwise, you may not
// use, modify, copy, publish, distribute, disclose or transmit this software or
// the related documents without Intel's prior written permission.
//
// This software and the related documents are provided as is, with no express or
// implied warranties, other than those that are expressly stated in the License.
//
// ----------------- END LICENSE BLOCK -----------------------------------

#pragma once

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wconversion"
#include <osmium/osm/types.hpp>
#pragma GCC diagnostic pop

namespace osmium {
class Node;
class Way;
class Relation;
} // namespace osmium

namespace ad {
namespace map {
namespace maker {
namespace osm_converter {

class OsmDataProvider
{
public:
  virtual ~OsmDataProvider() = default;

  virtual ::osmium::Node const &node(::osmium::object_id_type const nodeId) const = 0;
  virtual ::osmium::Way const &way(::osmium::object_id_type const wayId) const = 0;
  virtual ::osmium::Relation const &relation(::osmium::object_id_type const relationId) const = 0;

  virtual ::osmium::Node &node(::osmium::object_id_type const nodeId) = 0;
  virtual ::osmium::Way &way(::osmium::object_id_type const wayId) = 0;
  virtual ::osmium::Relation &relation(::osmium::object_id_type const relationId) = 0;
};

} // namespace osm_converter
} // namespace maker
} // namespace map
} // namespace ad
