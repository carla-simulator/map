// ----------------- BEGIN LICENSE BLOCK ---------------------------------
//
// Copyright (C) 2017-2020 Intel Corporation
//
// SPDX-License-Identifier: MIT
//
// ----------------- END LICENSE BLOCK -----------------------------------

#include "ad/map/maker/osm_converter/OsmWayProcessor.hpp"

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wconversion"
#include <osmium/osm/way.hpp>
#pragma GCC diagnostic pop

#include <ad/map/maker/common/LogChannel.hpp>
#include <ad/map/maker/common/LogFactory.hpp>
#include <ad/map/maker/common/StringHelper.hpp>
#include <ad/map/maker/map_data/Road.hpp> /* for cMsToKmh */
#include "ad/map/maker/osm_converter/OsmHighwayType.hpp"
#include "ad/map/maker/osm_converter/OsmObjectStore.hpp"

namespace ad {
namespace map {
namespace maker {
namespace osm_converter {

OsmWayProcessor::OsmWayProcessor(common::LogFactory &logFactory)
  : mLog(logFactory.logChannel("OsmWayProcessor"))
{
  mDefaultLaneWidths[OsmHighwayType::Motorway] = 3.5;
  /*
    MotorwayLink,
    Primary,
    PrimaryLink,
    Secondary,
    SecondaryLink,
    Tertiary,
    TertiaryLink,
    Trunk,
    TrunkLink,
    Residential,
    Service,
    Unclassified,
  */
}

void OsmWayProcessor::disableExtractionOfLaneInformation()
{
  mLog(common::LogLevel::Info) << "Ignoring lane information from map\n";
  mExtractLaneInformation = false;
}

OsmWay OsmWayProcessor::osmWay(::osmium::object_id_type const wayId) const
{
  if (mWay.count(wayId) > 0)
  {
    return mWay.at(wayId);
  }
  return OsmWay();
}

void OsmWayProcessor::processWays(std::shared_ptr<OsmObjectStore> store)
{
  for (auto wayId : store->allWayIds())
  {
    mLog(common::LogLevel::Info) << "Processing way: " << wayId << "\n";
    extractWayData(wayId, store);
  }
}

bool OsmWayProcessor::vectorOfDoubleValueForTag(const char *const nameOfKey,
                                                ::osmium::Way const &way,
                                                std::vector<double> &result) const
{
  const char *const value = way.tags()[nameOfKey];
  if (!value)
  {
    return false;
  }

  auto valueElement = common::splitString(value, '|');
  std::vector<double> extractedResult;
  for (auto elem : valueElement)
  {
    double extractedValue{};
    if (!common::doubleFromString(elem.c_str(), extractedValue))
    {
      return false;
    }

    extractedResult.push_back(extractedValue);
  }

  result = extractedResult;
  return true;
}

bool OsmWayProcessor::vectorOfStringForTag(const char *const nameOfKey,
                                           ::osmium::Way const &way,
                                           std::vector<std::string> &result) const
{
  const char *const value = way.tags()[nameOfKey];
  if (!value)
  {
    return false;
  }

  result = common::splitString(value, '|');
  return true;
}

bool OsmWayProcessor::doubleValueForTag(const char *const nameOfKey, ::osmium::Way const &way, double &result) const
{
  const char *const value = way.tags()[nameOfKey];
  if (!value)
  {
    return false;
  }

  return common::doubleFromString(value, result);
}

bool OsmWayProcessor::integerValueForTag(const char *const nameOfKey, ::osmium::Way const &way, int32_t &result) const
{
  const char *const value = way.tags()[nameOfKey];
  if (!value)
  {
    return false;
  }

  return common::integerFromString(value, result);
}

bool OsmWayProcessor::booleanValueForTag(const char *const nameOfKey, ::osmium::Way const &way, bool &result) const
{
  const char *const value = way.tags()[nameOfKey];
  if (!value)
  {
    return false;
  }

  if (strcmp(value, "yes") == 0)
  {
    result = true;
    return true;
  }
  else if (strcmp(value, "no") == 0)
  {
    result = false;
    return true;
  }
  // else not required here
  return false;
}

/* tags to be extracted:
 * - width
 * - lanes
 * - oneway
 * - turn:lanes - if we extract this we should cross check with the number of lanes, possible value: 'left|right|right'
 * - width:lanes - if we extract this we should cross check with the number of lanes, possible value: '3.5|3.5'
 * - maxspeed
 * [- shoulder], eventually
 * later:
 * - placement
 */
void OsmWayProcessor::extractWayData(::osmium::object_id_type wayId, std::shared_ptr<OsmObjectStore> store)
{
  ::osmium::Way const &way = store->way(wayId);
  const char *const highway = way.tags()["highway"];
  if (!highway)
  {
    mLog(common::LogLevel::Warning) << "Encountered way without tag \"highway\", id: " << way.id() << "\n";
    return;
  }

  OsmHighwayType highwayType = highwayTypeFromString(highway);
  if (highwayType == OsmHighwayType::Invalid)
  {
    highwayType = OsmHighwayType::Residential;
    mLog(common::LogLevel::Info) << "  Unhandled type of highway: " << highway << ". Falling back to "
                                 << highwayTypeToString(highwayType) << "\n";
  }

  bool isOneway{false};
  (void)booleanValueForTag("oneway", way, isOneway);

  uint32_t forwardLanes{};
  uint32_t backwardLanes{};
  extractNumberOfLanes(way, highwayType, isOneway, forwardLanes, backwardLanes);
  mLog(common::LogLevel::Verbose) << "  Number of lanes for " << way.id() << " " << backwardLanes << "|" << forwardLanes
                                  << " (backward|forward)\n";

  OsmWay osmWay;
  osmWay.mWayId = way.id();

  if (mExtractLaneInformation)
  {
    extractAndAssignWidthToOsmWay(way, highwayType, forwardLanes, backwardLanes, osmWay);
    extractAndAssignTurnDirectionsToOsmWay(way, forwardLanes, backwardLanes, osmWay);
  }
  else
  {
    osmWay.mBackwardLanes.mWidths.push_back(mDefaultLaneWidth);
    osmWay.mForwardLanes.mWidths.push_back(mDefaultLaneWidth);
  }
  assignHighwayTypeToOsmWay(highwayType, osmWay);
  extractLayerInformation(way, osmWay);
  extractSpeedLimit(way, osmWay);

  mWay[way.id()] = osmWay;
  logExtractedLaneWidth(osmWay);
}

std::string toStringWithPrecision(double const value, uint32_t const precision)
{
  std::string const result = std::to_string(value);
  auto pos = result.find(".");
  if (pos != std::string::npos)
  {
    pos += precision + 1;
    if (pos < result.length())
    {
      return result.substr(0, pos);
    }
  }
  return result;
}

void OsmWayProcessor::logExtractedLaneWidth(OsmWay const &osmWay)
{
  common::LogLevel logLevel = common::LogLevel::Info;
  if (mLog.willLogBeWrittenAtLevel(logLevel))
  {
    std::string result{"|"};
    for (auto w : osmWay.mBackwardLanes.mWidths)
    {
      result += toStringWithPrecision(w, 2u) + std::string("|");
    }
    result += "#|";
    for (auto w : osmWay.mForwardLanes.mWidths)
    {
      result += toStringWithPrecision(w, 2u) + std::string("|");
    }
    mLog(logLevel) << "  Way: " << osmWay.mWayId << " with layout of lanes " << result << "\n";
  }
}

void OsmWayProcessor::extractNumberOfLanes(::osmium::Way const &way,
                                           OsmHighwayType const highwayType,
                                           bool const isOneway,
                                           uint32_t &forward,
                                           uint32_t &backward) const
{
  int32_t forwardLanes{};
  bool const hasForwardLanes = integerValueForTag("lanes:forward", way, forwardLanes);

  int32_t backwardLanes{};
  bool const hasBackwardLanes = integerValueForTag("lanes:backward", way, backwardLanes);

  int32_t numTotalLanes{};
  bool const hasTotalLanes = integerValueForTag("lanes", way, numTotalLanes);

  // Log statistics here...

  if (hasForwardLanes && hasBackwardLanes)
  {
    forward = static_cast<uint32_t>(forwardLanes);
    backward = static_cast<uint32_t>(backwardLanes);
    return;
  }

  if (hasForwardLanes && !hasBackwardLanes)
  {
    forward = static_cast<uint32_t>(forwardLanes);
    if (hasTotalLanes)
    {
      backward = static_cast<uint32_t>(numTotalLanes - forwardLanes);
    }
    return;
  }

  if (hasBackwardLanes && !hasForwardLanes)
  {
    backward = static_cast<uint32_t>(backwardLanes);
    if (hasTotalLanes)
    {
      forward = static_cast<uint32_t>(numTotalLanes - backwardLanes);
    }
    return;
  }

  if (numTotalLanes < 1)
  {
    numTotalLanes = assumedLaneCount(highwayType, isOneway);
    mLog(common::LogLevel::Info) << "  No info about number of lanes, assuming a total number of " << numTotalLanes
                                 << " lane(s)\n";
  }

  if (isOneway)
  {
    forward = static_cast<uint32_t>(numTotalLanes);
    backward = 0;
  }
  else
  {
    forward = static_cast<uint32_t>(numTotalLanes - numTotalLanes / 2);
    backward = static_cast<uint32_t>(numTotalLanes / 2);
  }
}

void OsmWayProcessor::extractAndAssignWidthToOsmWay(::osmium::Way const &way,
                                                    OsmHighwayType const highwayType,
                                                    uint32_t const numForwardLanes,
                                                    uint32_t const numBackwardLanes,
                                                    OsmWay &osmWay) const
{
  /* the width can be specified as:
   * - specific for a direction: <tag k='width:lanes:backward' v='2.5|1' />
   * - per lane for the road (used when it is a oneway?!?): <tag k='width:lanes' v='4.2|4.2' />
   * - as a total width: <tag k='width' v='15.5' />
   *
   * In general same approach as for extracting the number of lanes
   * 1. Check direction specific information
   * 2. Check overall information
   * 3. Apply default values
   */

  std::vector<double> forwardWidth;
  bool const hasForwardWidth = vectorOfDoubleValueForTag("width:lanes:forward", way, forwardWidth);
  osmWay.mForwardLanes.mWidths.clear();
  if (hasForwardWidth)
  {
    mLog(common::LogLevel::Verbose) << "Got specific widths for forward lanes\n";
    uint32_t numElem = std::min(numForwardLanes, static_cast<uint32_t>(forwardWidth.size()));
    for (uint32_t i = 0u; i < numElem; ++i)
    {
      osmWay.mForwardLanes.mWidths.push_back(forwardWidth[i]);
    }
  }

  std::vector<double> backwardWidth;
  bool const hasBackwardWidth = vectorOfDoubleValueForTag("width:lanes:backward", way, backwardWidth);
  osmWay.mBackwardLanes.mWidths.clear();
  if (hasBackwardWidth)
  {
    mLog(common::LogLevel::Verbose) << "Got specific widths for backward lanes\n";
    uint32_t numElem = std::min(numBackwardLanes, static_cast<uint32_t>(backwardWidth.size()));
    for (uint32_t i = 0u; i < numElem; ++i)
    {
      osmWay.mBackwardLanes.mWidths.push_back(backwardWidth[i]);
    }
  }

  if ((osmWay.mBackwardLanes.mWidths.size() == numBackwardLanes)
      && (osmWay.mForwardLanes.mWidths.size() == numForwardLanes))
  {
    return;
  }

  std::vector<double> totalWidthVector;
  bool const hasTotalWidthVector = vectorOfDoubleValueForTag("width:lanes", way, totalWidthVector);
  if (hasTotalWidthVector)
  {
    // should only be available for oneway=yes ...
    // and the sizes should match
    if (numForwardLanes == totalWidthVector.size())
    {
      mLog(common::LogLevel::Verbose) << "Got specific widths for lanes\n";
      osmWay.mForwardLanes.mWidths = totalWidthVector;
    }
    else
    {
      mLog(common::LogLevel::Warning) << "Got widths for all lanes but the number of lanes do not match\n";
    }
  }

  double totalWidth{};
  bool const hasTotalWidth = doubleValueForTag("width", way, totalWidth);
  if (!hasTotalWidth)
  {
    totalWidth = defaultWidthForHighwayType(highwayType) * (numBackwardLanes + numForwardLanes);
    mLog(common::LogLevel::Info) << "  No widths for lanes. Falling back to default width per lane of: "
                                 << defaultWidthForHighwayType(highwayType) << " m\n";
  }

  double widthPerLane = totalWidth / static_cast<double>(numBackwardLanes + numForwardLanes);

  // fill up the missing parts
  for (auto i = osmWay.mBackwardLanes.mWidths.size(); i < numBackwardLanes; ++i)
  {
    osmWay.mBackwardLanes.mWidths.push_back(widthPerLane);
  }

  for (auto i = osmWay.mForwardLanes.mWidths.size(); i < numForwardLanes; ++i)
  {
    osmWay.mForwardLanes.mWidths.push_back(widthPerLane);
  }
}

void OsmWayProcessor::extractAndAssignTurnDirectionsToOsmWay(::osmium::Way const &way,
                                                             uint32_t const forwardLanes,
                                                             uint32_t const backwardLanes,
                                                             OsmWay &osmWay) const
{
  osmWay.mForwardLanes.mTurnDirection.clear();
  osmWay.mBackwardLanes.mTurnDirection.clear();

  std::vector<std::string> turnDirections{};
  bool const hasTurnLanes = vectorOfStringForTag("turn:lanes", way, turnDirections);
  if (hasTurnLanes)
  {
    for (auto const &value : turnDirections)
    {
      osmWay.mForwardLanes.mTurnDirection.push_back(fromString<OsmTurnDirection>(value));
    }
  }

  std::vector<std::string> forwardTurnLanes{};
  bool const hasFwdTurnLanes = vectorOfStringForTag("turn:lanes:forward", way, forwardTurnLanes);
  if (hasFwdTurnLanes)
  {
    for (auto const &value : forwardTurnLanes)
    {
      osmWay.mForwardLanes.mTurnDirection.push_back(fromString<OsmTurnDirection>(value));
    }
  }

  std::vector<std::string> backwardTurnLanes{};
  bool const hasBckTurnLanes = vectorOfStringForTag("turn:lanes:backward", way, backwardTurnLanes);
  if (hasBckTurnLanes)
  {
    for (auto const &value : backwardTurnLanes)
    {
      osmWay.mBackwardLanes.mTurnDirection.push_back(fromString<OsmTurnDirection>(value));
    }
  }

  bool const hasBckTurnLanesForAllLanes = vectorOfStringForTag("turn:backward", way, turnDirections);
  if (hasBckTurnLanesForAllLanes)
  {
    for (uint32_t i = 0u; i < backwardLanes; ++i)
    {
      for (auto const &value : turnDirections)
      {
        osmWay.mBackwardLanes.mTurnDirection.push_back(fromString<OsmTurnDirection>(value));
      }
    }
  }

  bool const hasFwdTurnLanesForAllLanes = vectorOfStringForTag("turn:forward", way, turnDirections);
  if (hasFwdTurnLanesForAllLanes)
  {
    for (uint32_t i = 0u; i < forwardLanes; ++i)
    {
      for (auto const &value : turnDirections)
      {
        osmWay.mForwardLanes.mTurnDirection.push_back(fromString<OsmTurnDirection>(value));
      }
    }
  }

  // Fill with defaults if no info gathered
  if (osmWay.mForwardLanes.mTurnDirection.size() == 0 && forwardLanes > 0)
  {
    osmWay.mForwardLanes.mTurnDirection
      = std::vector<std::vector<OsmTurnDirection>>(forwardLanes, {OsmTurnDirection::None});
  }
  if (osmWay.mBackwardLanes.mTurnDirection.size() == 0 && backwardLanes > 0)
  {
    osmWay.mBackwardLanes.mTurnDirection
      = std::vector<std::vector<OsmTurnDirection>>(backwardLanes, {OsmTurnDirection::None});
  }

  // Fall back to default if data is inconsistent, let turn directions be greater to forward lanes
  // as the bike lanes provide also turn direction info
  if (osmWay.mForwardLanes.mTurnDirection.size() < forwardLanes)
  {
    mLog(common::LogLevel::Warning) << "  Invalid turn-direction information for way: " << osmWay.mWayId << "\n";
    osmWay.mForwardLanes.mTurnDirection
      = std::vector<std::vector<OsmTurnDirection>>(forwardLanes, {OsmTurnDirection::None});
  }
  if (osmWay.mBackwardLanes.mTurnDirection.size() < backwardLanes)
  {
    mLog(common::LogLevel::Warning) << "  Invalid turn-direction information for way: " << osmWay.mWayId << "\n";
    osmWay.mBackwardLanes.mTurnDirection
      = std::vector<std::vector<OsmTurnDirection>>(backwardLanes, {OsmTurnDirection::None});
  }
}

void OsmWayProcessor::assignHighwayTypeToOsmWay(OsmHighwayType const highwayType, OsmWay &osmWay) const
{
  if (highwayType == OsmHighwayType::Invalid)
  {
    mLog(common::LogLevel::Warning) << "  Osm highway type invalid!\n";
  }
  osmWay.mHighwayType = highwayType;
}

void OsmWayProcessor::extractLayerInformation(::osmium::Way const &way, OsmWay &osmWay) const
{
  const char *const layer = way.tags()["layer"];
  osmWay.mLayer = 0;
  if (layer)
  {
    osmWay.mLayer = std::stoi(layer);
  }
}

int32_t OsmWayProcessor::assumedLaneCount(OsmHighwayType const highwayType, bool const isOneWay) const
{
  // see http://wiki.openstreetmap.org/wiki/Key:lanes#Assumptions
  if (isOneWay)
  {
    if ((highwayType == OsmHighwayType::Motorway) || (highwayType == OsmHighwayType::Trunk))
    {
      return 2;
    }
    return 1;
  }
  else
  {
    if (highwayType == OsmHighwayType::Service)
    {
      return 1;
    }
    return 2;
  }
}

double OsmWayProcessor::defaultWidthForHighwayType(OsmHighwayType const highwayType) const
{
  if (mDefaultLaneWidths.count(highwayType) > 0)
  {
    return mDefaultLaneWidths.at(highwayType);
  }

  return mDefaultLaneWidth;
}

void OsmWayProcessor::adaptDefaultLaneWidth(std::string const &value)
{
  double const defaultWidth = std::atof(value.c_str());
  if (defaultWidth > 0.1)
  {
    mLog(common::LogLevel::Info) << "Setting default lane width to: " << defaultWidth << "\n";
    mDefaultLaneWidth = defaultWidth;
  }
  else
  {
    mLog(common::LogLevel::Warning) << "Invalid configuration: Invalid lane width: " << defaultWidth << "\n";
  }
}

void OsmWayProcessor::adaptDefaultLaneWidthForHighwayType(std::string const &key, std::string const &value)
{
  auto highwayType = highwayTypeFromString(key);
  if (highwayType == OsmHighwayType::Invalid)
  {
    mLog(common::LogLevel::Warning) << "Invalid configuration: Unknown highway type: " << key << "\n";
    return;
  }

  double const defaultWidth = std::atof(value.c_str());
  if (defaultWidth > 0.1)
  {
    mLog(common::LogLevel::Info) << "Setting default lane width for highway type: " << key << " to: " << defaultWidth
                                 << "\n";
    mDefaultLaneWidths[highwayType] = defaultWidth;
  }
  else
  {
    mLog(common::LogLevel::Warning) << "Invalid configuration: Invalid lane width: " << defaultWidth
                                    << " for highway type: " << key << "\n";
  }
}

void OsmWayProcessor::configureDefaultLaneWidths(std::string const &laneWidthsConfiguration)
{
  std::vector<std::string> configEntries = common::splitString(laneWidthsConfiguration, ',');
  for (auto entry : configEntries)
  {
    std::vector<std::string> keyValue = common::splitString(entry, ':');
    if (keyValue.size() == 1)
    {
      adaptDefaultLaneWidth(keyValue[0]);
    }
    else if (keyValue.size() == 2)
    {
      adaptDefaultLaneWidthForHighwayType(keyValue[0], keyValue[1]);
    }
    else
    {
      // trigger a warning
      mLog(common::LogLevel::Warning) << "Invalid configuration of default lane widths: " << entry << "\n";
    }
  }
}

bool getSpeedLimit(std::string attribute, double &speedLimit)
{
  auto unitPosition = attribute.find(" mph"); // use ChandlerCampusCrosswalk.osm for testing
  double valueToKilometerPerHour{1.};
  if (unitPosition != std::string::npos)
  {
    attribute.resize(unitPosition);
    // convert from miles per hour into kilometer per hour
    valueToKilometerPerHour = OsmWayProcessor::mphToKmh;
  }
  if (!common::doubleFromString(attribute.c_str(), speedLimit))
  {
    return false;
  }
  speedLimit *= valueToKilometerPerHour;
  return true;
}

bool OsmWayProcessor::getSpeedLimitForWay(::osmium::Way const &way, const char *const key, double &result) const
{
  const char *const value = way.tags()[key];
  if (value != nullptr)
  {
    if (!getSpeedLimit(value, result))
    {
      mLog(common::LogLevel::Verbose) << "Unable to extract speed limit from value: " << value << "\n";
    }
    else
    {
      // finally, convert from km/h to m/s
      mLog(common::LogLevel::Verbose) << "Speed: " << result << "km/h -> " << result / map_data::cMsToKmh << "m/s\n";
      result /= map_data::cMsToKmh;
      return true;
    }
  }
  return false;
}

void OsmWayProcessor::extractSpeedLimit(::osmium::Way const &way, OsmWay &osmWay) const
{
  /* possible keys:
   * maxspeed = <val> [unit]
   * maxspeed:forward
   * maxspeed:lanes
   * for now we will only consider:
   * maxspeed (sole key)
   * maxspeed:forward
   * maxspeed: backward
   */
  double forwardSpeed{-1};
  if (!getSpeedLimitForWay(way, "maxspeed:forward", forwardSpeed))
  {
    if (!getSpeedLimitForWay(way, "maxspeed", forwardSpeed))
    {
      mLog(common::LogLevel::Info) << "No speed limit for way: " << way.id() << "\n";
      return;
    }
  }
  double backwardSpeed{forwardSpeed};
  if (!getSpeedLimitForWay(way, "maxspeed:backward", backwardSpeed))
  {
    mLog(common::LogLevel::Info) << "No speed limit for backward direction. Using forward speed limit\n";
  }
  mLog(common::LogLevel::Verbose) << "Extracted speed limits (f|b): " << forwardSpeed << "|" << backwardSpeed << "\n";
  osmWay.mForwardLanes.mMaxSpeed = forwardSpeed;
  osmWay.mBackwardLanes.mMaxSpeed = backwardSpeed;
}

} // namespace osm_converter
} // namespace maker
} // namespace map
} // namespace ad
