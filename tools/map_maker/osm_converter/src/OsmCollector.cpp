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

#include "ad/map/maker/osm_converter/OsmCollector.hpp"

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wconversion"
#include <osmium/osm/node.hpp>
#include <osmium/osm/way.hpp>
#pragma GCC diagnostic pop

#include <ad/map/maker/common/LogChannel.hpp>
#include <ad/map/maker/common/LogFactory.hpp>
#include <ad/map/maker/common/StringHelper.hpp>
#include "ad/map/maker/osm_converter/OsmObjectStore.hpp"

namespace ad {
namespace map {
namespace maker {
namespace osm_converter {

OsmCollector::OsmCollector(std::shared_ptr<OsmObjectStore> objectStore, common::LogFactory &logFactory)
  : mObjectStore(objectStore)
  , mLog(logFactory.logChannel("OsmCollector"))
{
  mAcceptableHighwayTypes.push_back("residential");
}

void OsmCollector::node(const ::osmium::Node &node) noexcept
{
  ++mNumNodes;
  mObjectStore->addNode(node);
  mLog(common::LogLevel::Verbose) << "Accepted node: " << node.id() << "\n";
}

void OsmCollector::logAcceptableHighwayTypes()
{
  common::LogLevel logLevel = common::LogLevel::Info;
  if (mLog.willLogBeWrittenAtLevel(logLevel))
  {
    mLog(logLevel) << "Accepting highway types:\n";
    for (auto t : mAcceptableHighwayTypes)
    {
      mLog(logLevel) << "  " << t << "\n";
    }
  }
}

uint32_t OsmCollector::numNodes() const
{
  return mNumNodes;
}

uint32_t OsmCollector::numWays() const
{
  return mNumWays;
}

void OsmCollector::setAcceptableHighwayTypes(std::string const &listOfTypes)
{
  mAcceptableHighwayTypes = common::splitString(listOfTypes, ',');
}

bool OsmCollector::isAcceptableHighwayType(const char *highway) const
{
  for (uint32_t i = 0u; i < mAcceptableHighwayTypes.size(); ++i)
  {
    if (strcmp(highway, mAcceptableHighwayTypes[i].c_str()) == 0)
    {
      return true;
    }
  }

  return false;
}

void OsmCollector::way(const ::osmium::Way &way) noexcept
{
  // do something with the way (if it is a highway)
  const char *highway = way.tags()["highway"];
  if (highway)
  {
    if (isAcceptableHighwayType(highway))
    {
      mLog(common::LogLevel::Verbose) << "Accepted way: " << way.id() << " of type: " << highway << "\n";
      ++mNumWays;
      mObjectStore->addWay(way);

      if (mLog.willLogBeWrittenAtLevel(common::LogLevel::Verbose))
      {
        auto const &nodelist = way.nodes();
        for (uint32_t i = 0u; i < nodelist.size(); ++i)
        {
          mLog(common::LogLevel::Verbose) << "  node " << i << " " << nodelist[i].ref() << "\n";
        }
      }
      // sample code to iterate over tags, keys and values
      //      for (auto & tag : way.tags())
      //      {
      //        mLogging << tag.key() << " " << tag.value() << "\n";
      //      }
      // mLogging << "\n";
    }
    else
    {
      mLog(common::LogLevel::Info) << "Discarded way: " << way.id() << " of type: " << highway << "\n";
    }
  }
}

} // namespace osm_converter
} // namespace maker
} // namespace map
} // namespace ad
