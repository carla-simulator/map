// ----------------- BEGIN LICENSE BLOCK ---------------------------------
//
// INTEL CONFIDENTIAL
//
// Copyright (c) 2018-2019 Intel Corporation
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

#include <ad/map/maker/common/AppConfig.hpp>
#include <ad/map/maker/common/LogFactory.hpp>
#include <ad/map/maker/common/MapGenerationConfig.hpp>
#include <ad/map/maker/common/OsmConverterConfig.hpp>
#include <ad/map/maker/common/TaskTimer.hpp>
#include <ad/map/maker/map_data/MapDataGenerator.hpp>
#include <ad/map/maker/map_data/MapDataStore.hpp>
#include "ad/map/maker/osm_converter/OsmCollector.hpp"
#include "ad/map/maker/osm_converter/OsmObjectStore.hpp"
#include "ad/map/maker/osm_converter/OsmProcessor.hpp"
#include "ad/map/maker/osm_converter/OsmToInternalConverter.hpp"

namespace ad {
namespace map {
namespace maker {
namespace osm_converter {

/**
 * @brief read in file (OSM) and convert into internal representation
 */
struct OsmConverter
{
  OsmConverter(common::AppConfig const &appConfig,
               common::OsmConverterConfig const &osmConverterConfig,
               common::MapGenerationConfig const &mapGenerationConfig,
               std::string applicationName)
    : logFactory(appConfig.loggingConfig)
    , taskTimer(logFactory.logChannel(applicationName))
    , dataStore(logFactory)
    , osmProcessor(logFactory)
  {
    taskTimer.start("Reading OSM map data");
    osmProcessor.parseMap(appConfig.inputFile, osmConverterConfig);
    taskTimer.stop();

    taskTimer.start("Converting to internal map data");
    if (mapGenerationConfig.leftHandTraffic)
    {
      dataStore.setLeftHandTraffic();
    }
    if (mapGenerationConfig.prioToRightAndStraight)
    {
      dataStore.setPrioToRightAndStraight();
    }
    OsmToInternalConverter osmToMapData(osmProcessor, dataStore, logFactory);
    osmToMapData.convertMap(osmConverterConfig.adjustLateralOffsetOfRoad);
    map_data::MapDataGenerator mapGenerator(dataStore, logFactory);
    mapGenerator.generateMap(mapGenerationConfig);
    taskTimer.stop();
  }

  common::LogFactory logFactory;
  common::TaskTimer taskTimer;
  map_data::MapDataStore dataStore;
  OsmProcessor osmProcessor;
};

} // namespace osm_converter
} // namespace maker
} // namespace map
} // namespace ad
