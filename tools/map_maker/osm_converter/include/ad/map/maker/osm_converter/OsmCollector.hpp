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

#include <memory> // for std::shared_ptr
#include <ostream>
#include <string>
#include <vector>

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wconversion"
#include <osmium/handler.hpp>
#include <osmium/osm/types.hpp>
#pragma GCC diagnostic pop

namespace ad {
namespace map {
namespace maker {

namespace common {
struct LogChannel;
class LogFactory;
} // namespace common

namespace osm_converter {

class OsmObjectStore;

/**
 * @brief Delegate to collect all entities from an OSM map that we are interested in
 *
 * Provides a list of entities for further processing
 */
class OsmCollector : public ::osmium::handler::Handler
{
public:
  OsmCollector(std::shared_ptr<OsmObjectStore> objectStore, common::LogFactory &logFactory);
  virtual ~OsmCollector() = default;

  void node(const ::osmium::Node &node) noexcept;
  void way(const ::osmium::Way &way) noexcept;

  void setAcceptableHighwayTypes(std::string const &listOfTypes);
  void logAcceptableHighwayTypes();

  // relations are not considered yet
  // void relation(const ::osmium::Relation & relation) noexcept;

  uint32_t numNodes() const;
  uint32_t numWays() const;

private:
  std::shared_ptr<OsmObjectStore> mObjectStore;

  bool isAcceptableHighwayType(const char *highway) const;

  /** Holds all strings describing a valid highway type for our purpose */
  std::vector<std::string> mAcceptableHighwayTypes; // maybe we use type const char * to avoid copying

  common::LogChannel &mLog;

  /* for statistical reasons */
  uint32_t mNumNodes{};
  uint32_t mNumWays{};
};

} // namespace osm_converter
} // namespace maker
} // namespace map
} // namespace ad
