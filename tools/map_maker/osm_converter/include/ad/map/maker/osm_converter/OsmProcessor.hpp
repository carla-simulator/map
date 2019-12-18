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
class OsmObjectStore;
class OsmJunctionProcessor;
class PointStore;
class OsmPoiExtractor;
class OsmPoiProcessor;
class OsmWayProcessor;
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
