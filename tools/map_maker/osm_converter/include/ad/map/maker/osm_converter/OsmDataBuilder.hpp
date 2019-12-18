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

#include <functional>
#include <vector>

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wconversion"
#include <osmium/osm/types.hpp>
#pragma GCC diagnostic pop

#include "ad/map/maker/osm_converter/OsmDataProvider.hpp"

namespace osmium {
class Relation;

namespace memory {
class Buffer;
} // namespace memory

namespace builder {
class RelationBuilder;
} // namespace builder
} // namespace osmium

namespace ad {
namespace map {
namespace maker {

namespace geometry {
class Point;
} // namespace geometry

namespace osm_converter {

class OsmDataBuilder : public OsmDataProvider
{
public:
  virtual ~OsmDataBuilder() = default;

  virtual ::osmium::object_id_type buildNode(geometry::Point const &pt) = 0;
  virtual ::osmium::object_id_type buildNode(geometry::Point const &pt, ::osmium::object_id_type const id) = 0;
  virtual ::osmium::object_id_type buildWay(std::vector<::osmium::object_id_type> const &nodes) = 0;
  virtual ::osmium::object_id_type buildWay(std::vector<::osmium::object_id_type> const &nodes,
                                            ::osmium::object_id_type const id)
    = 0;
  virtual ::osmium::object_id_type
  buildRelation(std::function<void(::osmium::memory::Buffer &, ::osmium::builder::RelationBuilder *)>)
    = 0;
  virtual ::osmium::object_id_type
  buildRelation(std::function<void(::osmium::memory::Buffer &, ::osmium::builder::RelationBuilder *)>,
                ::osmium::object_id_type const id)
    = 0;
  virtual ::osmium::object_id_type getUniqueId() = 0;
};

} // namespace osm_converter
} // namespace maker
} // namespace map
} // namespace ad
