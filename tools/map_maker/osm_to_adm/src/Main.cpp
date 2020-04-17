// ----------------- BEGIN LICENSE BLOCK ---------------------------------
//
// Copyright (C) 2018-2020 Intel Corporation
//
// SPDX-License-Identifier: MIT
//
// ----------------- END LICENSE BLOCK -----------------------------------

#include <ad/map/access/Factory.hpp>
#include <ad/map/access/Store.hpp>
#include <ad/map/maker/admap_generator/AdMapGenerator.hpp>
#include <ad/map/maker/common/AppConfigDescription.hpp>
#include <ad/map/maker/common/MapGenerationConfigDescription.hpp>
#include <ad/map/maker/common/OsmConverterConfigDescription.hpp>
#include <ad/map/maker/common/PrintException.hpp>
#include <ad/map/maker/common/ProgramOptions.hpp>
#include <ad/map/maker/osm_converter/OsmConverter.hpp>
#include <ad/map/serialize/SerializerFileCRC32.hpp>

#include <chrono> /* for std::chrono::systemclock::time_point */
#include <iostream>

using namespace ::ad::map::maker;

int main(int argc, char *argv[])
{
  try
  {
    common::ProgramOptions programOptions{"convert OpenStreetMap data into ADM"};
    common::AppConfigDescription appConfig;
    programOptions.addOptionGroup(appConfig);
    common::OsmConverterConfigDescription osmConverterConfig;
    programOptions.addOptionGroup(osmConverterConfig);
    common::MapGenerationConfigDescription mapGenerationConfig;
    programOptions.addOptionGroup(mapGenerationConfig);

    if (programOptions.parseOptions(argc, argv))
    {
      auto const startOfProcessing = std::chrono::system_clock::now();
      ::osm_converter::OsmConverter converter(
        appConfig.config, osmConverterConfig.config, mapGenerationConfig.config, "osm_to_lanelet");

      // @todo do we need to dereference?
      converter.dataStore.transformToGCS(*converter.osmProcessor.coordinateTransform());
      ::ad::map::access::Store store;
      ::ad::map::access::Factory factory(store);
      admap_generator::AdMapGenerator generator(factory, converter.dataStore, converter.logFactory);
      generator.generateADMap();
      ::ad::map::serialize::SerializerFileCRC32 serializer(true);
      size_t versionMajorWrite = ::ad::map::serialize::SerializerFileCRC32::VERSION_MAJOR;
      size_t versionMinorWrite = ::ad::map::serialize::SerializerFileCRC32::VERSION_MINOR;
      serializer.open(appConfig.config.outputFile.c_str(), versionMajorWrite, versionMinorWrite);
      store.save(serializer);
      serializer.close();

      if (appConfig.config.printStats)
      {
        auto const endOfProcessing = std::chrono::system_clock::now();
        auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(endOfProcessing - startOfProcessing);
        std::cout << "Total time: " << elapsed.count() << "ms\n";
      }
    }
  }
  catch (std::exception &e)
  {
    common::printException(e);
    return EXIT_FAILURE;
  }
  catch (...)
  {
    std::cerr << "Unhandled unknown exception" << std::endl;
    return EXIT_FAILURE;
  }

  return EXIT_SUCCESS;
}
