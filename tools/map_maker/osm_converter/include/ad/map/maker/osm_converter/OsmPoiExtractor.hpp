// ----------------- BEGIN LICENSE BLOCK ---------------------------------
//
// Copyright (C) 2018-2020 Intel Corporation
//
// SPDX-License-Identifier: MIT
//
// ----------------- END LICENSE BLOCK -----------------------------------

#pragma once

#include <memory>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wconversion"
#include <osmium/osm/types.hpp>
#pragma GCC diagnostic pop

#include <ad/map/maker/map_data/Landmark.hpp>
#include "ad/map/maker/osm_converter/PointOfInterest.hpp"

namespace osmium {
class Node;
} // namespace osmium

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
 * @brief Extract POIs from map
 */
class OsmPoiExtractor
{
public:
  OsmPoiExtractor(common::LogFactory &logFactory);
  virtual ~OsmPoiExtractor() = default;

  /**
   * @brief iterate over all nodes and identify points of interest
   */
  void extractPois(std::shared_ptr<OsmObjectStore> objectStore);

  std::unordered_set<::osmium::object_id_type> getPois(PoiType poiType) const;

  struct TrafficLightAttributes
  {
    std::vector<std::string> configs{};
    std::vector<std::string> placements{};
    std::vector<std::vector<int32_t>> laneAssignments{};
    std::vector<uint64_t> ids{};
    bool isForward{true};
  };

  TrafficLightAttributes const &trafficLightAttributes(::osmium::object_id_type const nodeId) const;

  // use a typedef here to make clear that the function is only returning traffic signs
  typedef std::vector<map_data::Landmark> TrafficSigns;
  //! return an empty list if there are no traffic signs for the given node
  TrafficSigns const &trafficSigns(::osmium::object_id_type const nodeId) const;

private:
  std::unordered_map<PoiType, std::unordered_set<::osmium::object_id_type>> mPois;
  std::unordered_map<::osmium::object_id_type, TrafficLightAttributes> mTrafficLights;
  std::unordered_map<::osmium::object_id_type, TrafficSigns> mTrafficSigns;
  common::LogChannel &mLog;

  /**
   * @brief identify all nodes that will be considered as point of interest
   *
   * Calls all extract<Type>RelatedPoi, see below
   *
   * Currently we extract:
   * - zebra crossings (crosswalk) --> key='highway', value='crossing'
   *   --> http://wiki.openstreetmap.org/wiki/Approved_features/Road_crossings
   * - street lamps --> key='highway', value='street_lamp'
   *   --> http://wiki.openstreetmap.org/wiki/Tag:highway%3Dstreet_lamp
   * - trees --> key='natural', value='tree'
   *   --> http://wiki.openstreetmap.org/wiki/Tag:natural%3Dtree
   * - fire hydrant --> key='emergency', value='fire_hydrant'
   *   --> http://wiki.openstreetmap.org/wiki/Tag:emergency%3Dfire_hydrant
   * - power cabinet --> key='man_made', value='street_cabinet', second key='street_cabinet', value='power'
   *   --> http://wiki.openstreetmap.org/wiki/Tag:man_made%3Dstreet_cabinet
   * - bollard --> key='barrier', value='bollard'
   *   --> http://wiki.openstreetmap.org/wiki/Tag:barrier%3Dbollard
   *   (eventually also extract barrier:block and map to Planter_contrete in Road5
   * - post box --> key='amenity' value='post_box'
   *   --> http://wiki.openstreetmap.org/wiki/Tag:amenity%3Dpost_box
   * - traffic light --> key='highway', value='traffic_signals'
   *   --> https://wiki.openstreetmap.org/wiki/Tag:highway=traffic_signals
   * - traffic sign --> key='traffic_sign' value='<list of traffic signs>'
   *   --> https://wiki.openstreetmap.org/wiki/Key:traffic_sign (only German traffic signs for now)
   */
  // all methods return true if node was processed
  void extractHighwayRelatedPoi(::osmium::Node const &node);
  void extractNaturalRelatedPoi(::osmium::Node const &node);
  void extractEmergencyRelatedPoi(::osmium::Node const &node);
  void extractManMadeRelatedPoi(::osmium::Node const &node);
  void extractBarrierRelatedPoi(::osmium::Node const &node);
  void extractAmenityRelatedPoi(::osmium::Node const &node);
  void extractTrafficSignRelatedPoi(::osmium::Node const &node);

  /**
   * @brief Get configuration and placement of a traffic light in OSM
   * @param[in] nodeId of the traffic light
   * @param[out] set of attributes of the traffic light
   * @return true if it is a valid traffic light, false otherwise
   */
  bool extractTrafficLightAttributes(::osmium::Node const &node, TrafficLightAttributes &result) const;

  /**
   * @brief extract traffic signs and map official code, e.g. DE:205 to type of Landmark
   * @param[in] nodeId of the traffic sign
   * @param[out] set of attributes of the traffic sign
   * @return true if it is a valid traffic sign, false otherwise
   */
  bool extractTrafficSigns(::osmium::Node const &node, TrafficSigns &result) const;

  /**
   * @brief extract all traffic lights from given string and add to the given \param result
   * @return false if traffic signs could not be extracted
   */
  bool addToTrafficSignAttributes(const char *value, bool isAlongLink, TrafficSigns &result) const;
};

} // namespace osm_converter
} // namespace maker
} // namespace map
} // namespace ad
