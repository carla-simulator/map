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
        appConfig.config, osmConverterConfig.config, mapGenerationConfig.config, "osm_to_adm");

      auto const coordinateTransform = converter.osmProcessor.coordinateTransform();
      if (!coordinateTransform)
      {
        std::cerr << "Error: Coordinate transform is not initialized\n";
        return EXIT_FAILURE;
      }
      converter.dataStore.transformToGCS(*coordinateTransform);
      ::ad::map::access::Store store;
      ::ad::map::access::Factory factory(store);
      admap_generator::AdMapGenerator generator(factory, converter.dataStore, converter.logFactory);
      generator.generateADMap();
      ::ad::map::serialize::SerializerFileCRC32 serializer(true);
      size_t versionMajorWrite = ::ad::map::serialize::SerializerFileCRC32::VERSION_MAJOR;
      size_t versionMinorWrite = ::ad::map::serialize::SerializerFileCRC32::VERSION_MINOR;
      if (!serializer.open(appConfig.config.outputFile.c_str(), versionMajorWrite, versionMinorWrite))
      {
        std::cerr << "Error: Unable to open output file \"" << appConfig.config.outputFile << "\"\n";
        return EXIT_FAILURE;
      }
      bool const saved = store.save(serializer);
      bool const closed = serializer.close();
      if (!saved || !closed)
      {
        std::cerr << "Error: Failed to save ADM map to \"" << appConfig.config.outputFile << "\"\n";
        return EXIT_FAILURE;
      }

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
