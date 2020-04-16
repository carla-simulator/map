// ----------------- BEGIN LICENSE BLOCK ---------------------------------
//
// Copyright (C) 2017-2020 Intel Corporation
//
// SPDX-License-Identifier: MIT
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

struct OsmObjectStore;

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
