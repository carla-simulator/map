// ----------------- BEGIN LICENSE BLOCK ---------------------------------
//
// Copyright (C) 2018-2020 Intel Corporation
//
// SPDX-License-Identifier: MIT
//
// ----------------- END LICENSE BLOCK -----------------------------------

#include "ad/map/maker/osm_converter/OsmPoiExtractor.hpp"
#include <ad/map/maker/common/LogChannel.hpp>
#include <ad/map/maker/common/LogFactory.hpp>
#include <ad/map/maker/common/StringHelper.hpp>
#include "ad/map/maker/osm_converter/OsmObjectStore.hpp"
#include "ad/map/maker/osm_converter/OsmStringToTrafficSign.hpp"

namespace ad {
namespace map {
namespace maker {
namespace osm_converter {

OsmPoiExtractor::OsmPoiExtractor(common::LogFactory &logFactory)
  : mLog(logFactory.logChannel("OsmPoiExtractor"))
{
}

void OsmPoiExtractor::extractHighwayRelatedPoi(::osmium::Node const &node)
{
  // type highway
  const char *highway = node.tags()["highway"];
  if (highway)
  {
    if (strcmp("crossing", highway) == 0)
    {
      const char *crossing_ref = node.tags()["crossing_ref"];
      if (crossing_ref)
      {
        if (strcmp("zebra", crossing_ref) == 0)
        {
          mLog(common::LogLevel::Verbose) << "Mark node " << node.id() << " as zebra crossing\n";
          mPois[PoiType::Crosswalk].insert(node.id());
        }
        else if (strcmp("pelican", crossing_ref) == 0)
        {
          mLog(common::LogLevel::Verbose)
            << "Mark node " << node.id() << " as pedestrian crossing with traffic lights\n";
          mPois[PoiType::PelicanCrossing].insert(node.id());
        }
      }
    }
    else if (strcmp("street_lamp", highway) == 0)
    {
      mLog(common::LogLevel::Verbose) << "Mark node " << node.id() << " as street lamp\n";
      mPois[PoiType::StreetLamp].insert(node.id());
    }
    else if (strcmp("traffic_signals", highway) == 0)
    {
      TrafficLightAttributes trafficLight;
      if (extractTrafficLightAttributes(node, trafficLight))
      {
        mLog(common::LogLevel::Verbose) << "Mark node " << node.id() << " as traffic light\n";
        mPois[PoiType::TrafficLight].insert(node.id());
        mTrafficLights[node.id()] = trafficLight;
      }
      else
      {
        mLog(common::LogLevel::Verbose) << "Node " << node.id() << " is traffic light but suffers information\n";
      }
    }
    // no else intended here
  }
}

void OsmPoiExtractor::extractNaturalRelatedPoi(::osmium::Node const &node)
{
  const char *natural = node.tags()["natural"];
  if (natural)
  {
    if (strcmp("tree", natural) == 0)
    {
      mLog(common::LogLevel::Verbose) << "Mark node " << node.id() << " as tree\n";
      PoiType treeType = PoiType::Tree;
      // In case we want to distinguish between types of trees ...
      //      const char *leaftype = node.tags()["leaf_type"];
      //      if (leaftype)
      //      {
      //      if (strcmp("broadleaved", leaftype) == 0)
      //      {
      //        treeType = PoiType::BroadLeavedTree;
      //      }
      //      else if (strcmp("needleleaved", leaftype) == 0)
      //      {
      //        treeType = PoiType::NeedleLeavedTree;
      //      }
      //      }
      mPois[treeType].insert(node.id());
    }
  }
}

void OsmPoiExtractor::extractEmergencyRelatedPoi(::osmium::Node const &node)
{
  const char *emergency = node.tags()["emergency"];
  if (emergency)
  {
    if (strcmp("fire_hydrant", emergency) == 0)
    {
      PoiType hydrantType = PoiType::ManHole;
      const char *fire_hydrant_type = node.tags()["fire_hydrant:type"];
      if ((fire_hydrant_type != nullptr) && (strcmp("pillar", fire_hydrant_type) == 0))
      {
        hydrantType = PoiType::FireHydrant;
        mLog(common::LogLevel::Verbose) << "Mark node " << node.id() << " as fire hydrant\n";
      }
      else
      {
        mLog(common::LogLevel::Verbose) << "Mark node " << node.id() << " as man hole\n";
      }
      mPois[hydrantType].insert(node.id());
    }
  }
}

void OsmPoiExtractor::extractManMadeRelatedPoi(::osmium::Node const &node)
{
  const char *man_made = node.tags()["man_made"];
  if (man_made)
  {
    if (strcmp("street_cabinet", man_made) == 0)
    {
      mLog(common::LogLevel::Verbose) << "Mark node " << node.id() << " as power cabinet\n";
      PoiType treeType = PoiType::PowerCabinet;
      mPois[treeType].insert(node.id());
    }
  }
}

void OsmPoiExtractor::extractBarrierRelatedPoi(::osmium::Node const &node)
{
  const char *barrier = node.tags()["barrier"];
  if (barrier)
  {
    if (strcmp("bollard", barrier) == 0)
    {
      mLog(common::LogLevel::Verbose) << "Mark node " << node.id() << " as bollard\n";
      PoiType treeType = PoiType::Bollard;
      mPois[treeType].insert(node.id());
    }
  }
}

void OsmPoiExtractor::extractAmenityRelatedPoi(::osmium::Node const &node)
{
  const char *amenity = node.tags()["amenity"];
  if (amenity)
  {
    if (strcmp("post_box", amenity) == 0)
    {
      mLog(common::LogLevel::Verbose) << "Mark node " << node.id() << " as post box\n";
      PoiType treeType = PoiType::PostBox;
      mPois[treeType].insert(node.id());
    }
  }
}

void OsmPoiExtractor::extractTrafficSignRelatedPoi(::osmium::Node const &node)
{
  const char *sign = node.tags()["traffic_sign"];
  const char *signForward = node.tags()["traffic_sign:forward"];
  const char *signBackward = node.tags()["traffic_sign:backward"];
  // can all be set at the same time, see TPK_PFZ_route_only, node 1213046550
  if (sign || signForward || signBackward)
  {
    TrafficSigns trafficSigns;
    if (extractTrafficSigns(node, trafficSigns))
    {
      mLog(common::LogLevel::Verbose) << "Mark node " << node.id() << " as traffic sign\n";
      mPois[PoiType::TrafficSign].insert(node.id());
      mTrafficSigns[node.id()] = trafficSigns;
    }
    else
    {
      mLog(common::LogLevel::Verbose) << "Node " << node.id() << " is traffic sign but has unhandled value(s)\n";
    }
  }
}

// strictly speaking, we have to continue processing if we hit something, e.g. a traffic sign
// because a node can have additional tags
void OsmPoiExtractor::extractPois(std::shared_ptr<OsmObjectStore> objectStore)
{
  mPois.clear();
  for (auto nodeId : objectStore->allNodeIds())
  {
    ::osmium::Node const &node = objectStore->node(nodeId);
    extractHighwayRelatedPoi(node);
    extractNaturalRelatedPoi(node);
    extractEmergencyRelatedPoi(node);
    extractManMadeRelatedPoi(node);
    extractBarrierRelatedPoi(node);
    extractAmenityRelatedPoi(node);
    extractTrafficSignRelatedPoi(node);
  }
}

ObjectIdSet OsmPoiExtractor::getPois(PoiType poiType) const
{
  if (mPois.count(poiType) > 0)
  {
    return mPois.at(poiType);
  }

  return ObjectIdSet();
}

bool OsmPoiExtractor::extractTrafficLightAttributes(::osmium::Node const &node, TrafficLightAttributes &result) const
{
  const char *config = node.tags()["traffic_signals:configuration"];
  const char *placement = node.tags()["traffic_signals:placement"];
  const char *direction = node.tags()["traffic_signals:direction"];
  const char *laneAssignment = node.tags()["traffic_signals:lane_assignment"];
  const char *ids = node.tags()["traffic_signals:id"];

  if ((config == nullptr) || (placement == nullptr) || (laneAssignment == nullptr) || (ids == nullptr))
  {
    mLog(common::LogLevel::Info) << "Traffic light for node " << node.id() << " misses information: ";
    if (config == nullptr)
    {
      mLog << "configuration, ";
    }
    if (placement == nullptr)
    {
      mLog << "placement, ";
    }
    if (laneAssignment == nullptr)
    {
      mLog << "assignment, ";
    }
    if (ids == nullptr)
    {
      mLog << "ids";
    }
    mLog << "\n";
    return false;
  }

  result.configs = common::splitString(config, '|');
  result.placements = common::splitString(placement, '|');
  auto assignmentsOverallLanes = common::splitString(laneAssignment, '|');
  for (auto const &overallLane : assignmentsOverallLanes)
  {
    std::vector<int32_t> laneAssignment;
    auto assignmentPerLane = common::splitString(overallLane, ',');
    for (auto perLane : assignmentPerLane)
    {
      int32_t value{};
      if (!common::integerFromString(perLane.c_str(), value))
      {
        mLog(common::LogLevel::Error) << "Unable to extract lane assignment for node " << node.id() << " value "
                                      << perLane << "\n";
        return false;
      }
      laneAssignment.push_back(value);
    }
    result.laneAssignments.push_back(laneAssignment);
  }

  auto idPerTrafficLight = common::splitString(ids, '|');
  for (auto const &id : idPerTrafficLight)
  {
    int32_t value{};
    if (!common::integerFromString(id.c_str(), value))
    {
      mLog(common::LogLevel::Error) << "Unable to extract id for node " << node.id() << " value " << id << "\n";
      return false;
    }
    if (value < 0)
    {
      mLog(common::LogLevel::Error) << "Got negative id for node " << node.id() << " value " << id << "\n";
    }
    result.ids.push_back(static_cast<uint64_t>(value));
  }

  result.isForward = true;
  if (direction != nullptr)
  {
    result.isForward = (std::string(direction) == "forward");
  }

  if ((result.placements.size() != result.configs.size())
      || (result.placements.size() != result.laneAssignments.size()))
  {
    // number of traffic lights (configs) does not match number of placements
    mLog(common::LogLevel::Error) << "Error handling traffic light " << node.id() << "\n";
    return false;
  }

  return true;
}

OsmPoiExtractor::TrafficLightAttributes const &
OsmPoiExtractor::trafficLightAttributes(::osmium::object_id_type const nodeId) const
{
  return mTrafficLights.at(nodeId);
}

/**
 * Given a string of something[supplement] the function
 * puts "something" into \ref signType and "supplment" into \ref supplement
 * If no supplement is given, only 'ref signType is filled
 * If the terminating ']' is missing, false is returned.
 *
 * @todo Ouch, a sign can have multiple [], e.g.
 * DE:430[Basel][A 5];DE:430[Stuttgart][A 8]
 * For now, we will only extract "Stuttgart" as supplement
 */
bool extractSignAndSupplement(std::string const &value, std::string &signType, std::string &supplement)
{
  std::string valueWithFixedQuotes = common::replace("\"", "[", value);
  valueWithFixedQuotes = common::replace("\"", "]", valueWithFixedQuotes);
  auto parts = common::splitString(valueWithFixedQuotes, '[');
  signType = parts[0];
  if (parts.size() == 2)
  {
    supplement = parts[1];
    if (parts[1].back() == ']')
    {
      supplement.pop_back();
    }
    else
    {
      supplement.clear();
      return false;
    }
  }
  return true;
}
/*
 * The value is composed as follows:
 * <group>;<group>
 * with group:
 * <sign>,<sign>
 * with sign:
 * DE:xyy with an option [num]
 *
 * Example:
 * DE:205;DE:209-10,DE:1022-10
 * First group:
 * Yield
 * Second group
 * Turn Left + Free for bycicles
 *
 * For now we will not use the information that the items are grouped but instead
 * simply make a list of traffic signs, e.g. for the above example:
 * 1. 205
 * 2. 209-10
 * 3. 1022-10
 * (instead of a list of lists {205}, {209-10, 1022-10})
 *
 * Known issues:
 * A semicolon ';' can also appear inside brackets '[...]' This is not handled correctly. For our maps that
 * doesn't hurt because it's only used to specify multiple directions on Motorways, e.g. DE:430[Basel; Ettlingen]
 */
bool OsmPoiExtractor::addToTrafficSignAttributes(const char *value, bool isAlongLink, TrafficSigns &result) const
{
  (void)isAlongLink;
  (void)result;
  auto groups = common::splitString(value, ';');
  for (auto group : groups)
  {
    mLog(common::LogLevel::Verbose) << "  Processing group: " << group << "\n";
    auto items = common::splitString(group, ',');
    for (auto item : items)
    {
      map_data::Landmark extraction;
      extraction.alongRoadDirection = isAlongLink;
      mLog(common::LogLevel::Verbose) << "    Processing item: " << item << "\n";
      std::string signString;
      if (extractSignAndSupplement(item, signString, extraction.supplement))
      {
        extraction.type = landmarkTypeFromString(signString, mLog);
        mLog(common::LogLevel::Verbose) << "  Extracted traffic sign " << signString << " and mapped to "
                                        << toString(extraction.type) << "\n";
        if (extraction.type != map_data::LandmarkType::Unknown)
        {
          if (!extraction.supplement.empty())
          {
            mLog(common::LogLevel::Verbose) << "    Supplemental information: " << extraction.supplement << "\n";
          }
          result.push_back(extraction);
        }
      }
      else
      {
        mLog(common::LogLevel::Warning) << "    Supplemental information: Missing terminating ']'\n";
      }
    }
  }
  return true;
}

bool OsmPoiExtractor::extractTrafficSigns(::osmium::Node const &node, TrafficSigns &result) const
{
  mLog(common::LogLevel::Verbose) << "Extracting traffic signs for node: " << node.id() << "\n";
  const char *sign = node.tags()["traffic_sign"];
  if (sign)
  {
    addToTrafficSignAttributes(sign, true, result);
  }

  const char *signForward = node.tags()["traffic_sign:forward"];
  if (signForward)
  {
    addToTrafficSignAttributes(signForward, true, result);
  }

  const char *signBackward = node.tags()["traffic_sign:backward"];
  if (signBackward)
  {
    addToTrafficSignAttributes(signBackward, false, result);
  }
  return true;
}

OsmPoiExtractor::TrafficSigns const &OsmPoiExtractor::trafficSigns(::osmium::object_id_type const nodeId) const
{
  static TrafficSigns emptyResult{};
  if (mTrafficSigns.count(nodeId))
  {
    return mTrafficSigns.at(nodeId);
  }
  return emptyResult;
}

} // namespace osm_converter
} // namespace maker
} // namespace map
} // namespace ad
