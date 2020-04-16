// ----------------- BEGIN LICENSE BLOCK ---------------------------------
//
// Copyright (C) 2017-2020 Intel Corporation
//
// SPDX-License-Identifier: MIT
//
// ----------------- END LICENSE BLOCK -----------------------------------

#pragma once

#include <memory>
#include <unordered_map>

#include "ad/map/maker/osm_converter/OsmHighwayType.hpp"
#include "ad/map/maker/osm_converter/OsmWay.hpp"

namespace osmium {
class Way;
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
 * @brief Process knowledge about lanes and width of lanes of ways
 */
struct OsmWayProcessor
{
  explicit OsmWayProcessor(common::LogFactory &logFactory);

  /*!
   * @brief iterate over all ways and lane related information
   */
  void processWays(std::shared_ptr<OsmObjectStore> store);

  OsmWay osmWay(::osmium::object_id_type const wayId) const;

  void disableExtractionOfLaneInformation();

  /**
   * @brief configureDefaultLaneWidths
   * @param laneWidthsConfiguration
   *
   * Configuration of the default lane widths is a comma-separated list of entries
   * of the form highway_type:width, e.g. primary:3.5,primary_link:3.0
   *
   * To specify a default lane widths independent of any highway_type, just give a number,
   * e.g. "3.0,primary:3.5" will set the default values for all highway types to 3.0 meters
   * except for highways of type "primary" which will have a default width of 3.5 meters.
   */
  void configureDefaultLaneWidths(std::string const &laneWidthsConfiguration);

  static constexpr double mphToKmh{1.609344}; //! see https://en.wikipedia.org/wiki/Miles_per_hour

private:
  /**
   * @brief mWay
   *
   * Provide information about lanes of a given way
   */
  std::unordered_map<::osmium::object_id_type, OsmWay> mWay{};
  common::LogChannel &mLog;
  std::unordered_map<OsmHighwayType, double> mDefaultLaneWidths{};
  double mDefaultLaneWidth{3.};

  void extractWayData(::osmium::object_id_type wayId, std::shared_ptr<OsmObjectStore> store);

  /**
   * @brief retrieve the number of lanes for the given way
   * @param way
   * @param forward extracted number of forward lanes
   * @param backward extracted number of backward lanes
   */
  void extractNumberOfLanes(::osmium::Way const &way,
                            const OsmHighwayType highwayType,
                            const bool isOneway,
                            uint32_t &forward,
                            uint32_t &backward) const;

  /**
   * @brief Extract widths from way and fill given osmWay
   * @param way original way information
   * @param forwardLanes number of forward lanes
   * @param backwardLanes number of backward lanes
   * @param osmWay to-be-filled element
   */
  void extractAndAssignWidthToOsmWay(::osmium::Way const &way,
                                     OsmHighwayType const highwayType,
                                     uint32_t const numForwardLanes,
                                     uint32_t const numBackwardLanes,
                                     OsmWay &osmWay) const;

  /**
   * @brief Extract turn lanes information and fill into given osmWay
   * @param way original way information
   * @param osmWay to-be-filled element
   */
  void extractAndAssignTurnDirectionsToOsmWay(::osmium::Way const &way,
                                              uint32_t const forwardLanes,
                                              uint32_t const backwardLanes,
                                              OsmWay &osmWay) const;

  void assignHighwayTypeToOsmWay(OsmHighwayType const highwayType, OsmWay &osmWay) const;

  void extractLayerInformation(::osmium::Way const &way, OsmWay &osmWay) const;

  /**
   * @brief extract speed limit of given way and put it into OsmWay
   *
   * We will only parse speed limits that are attached to ways. We will not consider
   * speed limits for particular types of vehicles, e.g. maxspeed:trailer
   *
   * https://wiki.openstreetmap.org/wiki/Key:maxspeed
   */
  void extractSpeedLimit(::osmium::Way const &way, OsmWay &osmWay) const;

  // return default value of no information about number of lanes is available
  int32_t assumedLaneCount(OsmHighwayType const highwayType, bool const isOneWay) const;

  double defaultWidthForHighwayType(OsmHighwayType const highwayType) const;

  /*
   * helper functions for parsing OSM data, may be moved to a common place once it's used somewhere else
   * all additional information of a way, node, relation is stored as so-called tags. These have the form
   * of <tag k='abc' v='xyz' />
   * In the given example, 'abc' is the name of the _key_, and 'xyz' is the _value_ of the key.
   *
   * The first parameter of all these function is the name of the key ('abc' in the above example).
   *
   * The prefix of each method name defines the expected type of value, these are:
   * - a boolean value (value is 'yes' or 'no')
   * - an integer value (e.g. for the number of lanes, value could be '4')
   * - a double value (e.g. for the width of the road, value could be '16')
   *
   * The _value_ can also be a _list_ of values. These are concatenated using the '|' character. E.g.
   * for specifying the width of each indiviual lane, value could be '3.5|3.5|4.0'. This means that
   * the first and second lane have a width of 3.5m and the third lane is 4.0 meters wide.
   * (This case is handled in vectorOfDoubleValueForTag).
   *
   * All these functions return true if the requested value(s) could be extracted. The result is placed
   * in the last parameter 'result'. If the value could not be extracted, 'result' is untouched.
   *
   * There can be also string as values, these are not covered yet as it is not needed for now.
   */
  bool doubleValueForTag(const char *const nameOfKey, ::osmium::Way const &way, double &result) const;
  bool
  vectorOfDoubleValueForTag(const char *const nameOfKey, ::osmium::Way const &way, std::vector<double> &result) const;
  bool
  vectorOfStringForTag(const char *const nameOfKey, ::osmium::Way const &way, std::vector<std::string> &result) const;
  bool integerValueForTag(const char *const nameOfKey, ::osmium::Way const &way, int32_t &result) const;
  bool booleanValueForTag(const char *const nameOfKey, ::osmium::Way const &way, bool &result) const;

  void logExtractedLaneWidth(OsmWay const &osmWay);

  bool mExtractLaneInformation{true};
  void adaptDefaultLaneWidth(std::string const &value);
  void adaptDefaultLaneWidthForHighwayType(std::string const &key, std::string const &value);

  bool getSpeedLimitForWay(::osmium::Way const &way, const char *const key, double &result) const;
};

} // namespace osm_converter
} // namespace maker
} // namespace map
} // namespace ad
