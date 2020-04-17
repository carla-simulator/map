// ----------------- BEGIN LICENSE BLOCK ---------------------------------
//
// Copyright (C) 2017-2020 Intel Corporation
//
// SPDX-License-Identifier: MIT
//
// ----------------- END LICENSE BLOCK -----------------------------------

#include "ad/map/maker/osm_converter/OsmProcessor.hpp"

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wconversion"
#if defined(__clang__)
#if (__clang_major__ >= 8)
#pragma GCC diagnostic ignored "-Wdefaulted-function-deleted"
#endif
#pragma GCC diagnostic ignored "-Wunused-lambda-capture"
#endif
#include <osmium/io/xml_input.hpp>
#include <osmium/osm/node.hpp>
#include <osmium/osm/way.hpp>
#include <osmium/visitor.hpp> // for ::osmium::apply()
#pragma GCC diagnostic pop

#include <ad/map/maker/common/LogChannel.hpp>
#include <ad/map/maker/common/LogFactory.hpp>
#include <ad/map/maker/common/OsmConverterConfig.hpp>
#include <ad/map/maker/geometry/CoordinateTransform.hpp>
#include "ad/map/maker/osm_converter/OsmCollector.hpp"
#include "ad/map/maker/osm_converter/OsmJunctionProcessor.hpp"
#include "ad/map/maker/osm_converter/OsmObjectStore.hpp"
#include "ad/map/maker/osm_converter/OsmPoiExtractor.hpp"
#include "ad/map/maker/osm_converter/OsmPoiProcessor.hpp"
#include "ad/map/maker/osm_converter/OsmWayProcessor.hpp"
#include "ad/map/maker/osm_converter/PointStore.hpp"

namespace ad {
namespace map {
namespace maker {
namespace osm_converter {

OsmProcessor::OsmProcessor(common::LogFactory &logFactory)
  : mLog(logFactory.logChannel("OsmProcessor"))
  , mLogFactory(logFactory)
{
}

std::shared_ptr<OsmObjectStore> OsmProcessor::objectStore() const
{
  return mObjectStore;
}

std::shared_ptr<OsmJunctionProcessor> OsmProcessor::junctionProcessor() const
{
  return mJunctionProcessor;
}

std::shared_ptr<PointStore> OsmProcessor::pointStore() const
{
  return mPointStore;
}

std::shared_ptr<geometry::CoordinateTransform> OsmProcessor::coordinateTransform() const
{
  return mCoordinateTransform;
}

std::shared_ptr<OsmPoiExtractor> OsmProcessor::poiExtractor() const
{
  return mPoiExtractor;
}

std::shared_ptr<OsmPoiProcessor> OsmProcessor::poiProcessor() const
{
  return mPoiProcessor;
}

std::shared_ptr<OsmWayProcessor> OsmProcessor::wayProcessor() const
{
  return mWayProcessor;
}

void OsmProcessor::parseMap(std::string const &filename, common::OsmConverterConfig const &config)
{
  /*
   * Order of processing
   * Create collector and object store
   * read map
   * extract junctions
   * setup point store and coordinate transform
   */
  mObjectStore = std::make_shared<OsmObjectStore>(mLogFactory);
  OsmCollector collector(mObjectStore, mLogFactory);
  collector.setAcceptableHighwayTypes(config.acceptableHighwayTypes);
  collector.logAcceptableHighwayTypes();
  ::osmium::io::Reader reader{filename, ::osmium::osm_entity_bits::node | ::osmium::osm_entity_bits::way};
  ::osmium::apply(reader, collector);
  reader.close();

  mJunctionProcessor = std::make_shared<OsmJunctionProcessor>(mLogFactory, mObjectStore);
  mJunctionProcessor->setDefaultPriority(config.defaultPriority);
  mJunctionProcessor->extractJunctions();

  mPointStore = std::make_shared<PointStore>(mLogFactory);
  mPointStore->extractPointsFromStore(mObjectStore);

  ::osmium::Location refLocation;
  if (mJunctionProcessor->allJunctions().size() > 0)
  {
    ::osmium::object_id_type refNodeId = *(mJunctionProcessor->allJunctions().begin());
    ::osmium::Node const &refNode = mObjectStore->node(refNodeId);
    refLocation = refNode.location();
  }
  else if (mObjectStore->allWayIds().size() > 0)
  {
    ::osmium::object_id_type wayId = *(mObjectStore->allWayIds().begin());
    ::osmium::Way const &way = mObjectStore->way(wayId);
    ::osmium::Node const &refNode = mObjectStore->node(way.nodes().front().ref());
    refLocation = refNode.location();
  }
  else
  {
    throw std::runtime_error("No intersections and no ways given!");
  }

  mCoordinateTransform
    = std::make_shared<geometry::CoordinateTransform>(refLocation.lat_without_check(), refLocation.lon_without_check());
  mPointStore->transformToMetric(*mCoordinateTransform);

  // map POIs to segments
  mPoiExtractor = std::make_shared<OsmPoiExtractor>(mLogFactory);
  mPoiExtractor->extractPois(mObjectStore);
  mPoiProcessor = std::make_shared<OsmPoiProcessor>(mLogFactory);
  mPoiProcessor->processPois(mPoiExtractor, mObjectStore, mPointStore);

  // extract information about ways, e.g. number of lanes
  mWayProcessor = std::make_shared<OsmWayProcessor>(mLogFactory);
  mWayProcessor->configureDefaultLaneWidths(config.laneWidthsDefaults);
  if (config.ignoreLaneInfoFromMap)
  {
    mWayProcessor->disableExtractionOfLaneInformation();
  }
  mWayProcessor->processWays(mObjectStore);
}

geometry::CoordinateTransform const &OsmProcessor::coordinateTransformRef() const
{
  return *(mCoordinateTransform.get());
}

} // namespace osm_converter
} // namespace maker
} // namespace map
} // namespace ad
