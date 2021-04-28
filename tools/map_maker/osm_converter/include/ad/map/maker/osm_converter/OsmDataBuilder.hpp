// ----------------- BEGIN LICENSE BLOCK ---------------------------------
//
// Copyright (C) 2017-2020 Intel Corporation
//
// SPDX-License-Identifier: MIT
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
struct Point;
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
