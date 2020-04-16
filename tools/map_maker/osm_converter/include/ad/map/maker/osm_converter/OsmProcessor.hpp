// ----------------- BEGIN LICENSE BLOCK ---------------------------------
//
// Copyright (C) 2017-2020 Intel Corporation
//
// SPDX-License-Identifier: MIT
//
// ----------------- END LICENSE BLOCK -----------------------------------

#pragma once

#include <memory>

#include <ad/map/maker/common/OsmConverterConfig.hpp>

namespace ad {
namespace map {
namespace maker {

namespace common {
struct LogChannel;
class LogFactory;
struct OsmConverterConfig;
} // namespace common

namespace geometry {
class CoordinateTransform;
} // namespace geometry

namespace osm_converter {
struct OsmObjectStore;
struct OsmJunctionProcessor;
class PointStore;
class OsmPoiExtractor;
class OsmPoiProcessor;
struct OsmWayProcessor;
struct OsmProcessorConfig;

/**
 * @brief Preprocess data such that it can be used by a converter
 *
 * Purpose:
 * - read in a map
 * - hold data in OsmObjectStore
 * - extract junctions (OsmJunctionProcessor)
 * - maintain PointStore (together with CoordinateTransform)
 * - map POIs to way segments (through OsmPoiProcessor)
 *
 * OPEN use references or shared_ptr? Will use shared_ptr for now, prefer to switch to references!
 */
class OsmProcessor
{
public:
  OsmProcessor(common::LogFactory &logFactory);
  virtual ~OsmProcessor() = default;

  /*!
   * @brief read map and prepare data for further processing
   *
   * @param filename name of map
   */
  void parseMap(std::string const &filename, common::OsmConverterConfig const &config);

  std::shared_ptr<OsmObjectStore> objectStore() const;
  std::shared_ptr<OsmJunctionProcessor> junctionProcessor() const;
  std::shared_ptr<PointStore> pointStore() const;
  std::shared_ptr<geometry::CoordinateTransform> coordinateTransform() const;
  std::shared_ptr<OsmPoiExtractor> poiExtractor() const;
  std::shared_ptr<OsmPoiProcessor> poiProcessor() const;
  std::shared_ptr<OsmWayProcessor> wayProcessor() const;

  geometry::CoordinateTransform const &coordinateTransformRef() const;

private:
  common::LogChannel &mLog;
  common::LogFactory &mLogFactory;

  std::shared_ptr<OsmObjectStore> mObjectStore;
  std::shared_ptr<OsmJunctionProcessor> mJunctionProcessor;
  std::shared_ptr<geometry::CoordinateTransform> mCoordinateTransform;
  std::shared_ptr<PointStore> mPointStore;
  std::shared_ptr<OsmPoiExtractor> mPoiExtractor;
  std::shared_ptr<OsmPoiProcessor> mPoiProcessor;
  std::shared_ptr<OsmWayProcessor> mWayProcessor;
};

} // namespace osm_converter
} // namespace maker
} // namespace map
} // namespace ad
