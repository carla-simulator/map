// ----------------- BEGIN LICENSE BLOCK ---------------------------------
//
// Copyright (C) 2018-2021 Intel Corporation
//
// SPDX-License-Identifier: MIT
//
// ----------------- END LICENSE BLOCK -----------------------------------
/**
 * @file
 */

#pragma once

#include <memory>
#include "ad/map/access/MapMetaDataValidInputRange.hpp"
#include "ad/map/access/Store.hpp"
#include "ad/map/config/PointOfInterest.hpp"
#include "ad/map/intersection/IntersectionType.hpp"
#include "ad/map/landmark/TrafficLightType.hpp"
#include "ad/map/lane/Types.hpp"
#include "ad/map/route/Types.hpp"

/** @brief namespace ad */
namespace ad {
/** @brief namespace map */
namespace map {

namespace point {
class CoordinateTransform;
} // namespace point

/** @brief namespace access */
namespace access {

/**
 * @brief checks if the given MapMetaData is valid
 *
 * The metaData is valid if it's within valid input range.
 */
inline bool isValid(MapMetaData const &metaData, bool const logErrors = true)
{
  bool isValidInputRange
    = withinValidInputRange(metaData, logErrors) && (metaData.traffic_type != TrafficType::INVALID);
  if (!isValidInputRange && logErrors)
  {
    spdlog::error("withinValidInputRange(::ad::map::access::MapMetaData)>> {} not valid", metaData);
  }
  return isValidInputRange;
}

/**
 * @brief get the coordinate transformation object
 */
std::shared_ptr<point::CoordinateTransform> getCoordinateTransform();

/**
 * @brief initialize singleton with given configuration file
 *
 * @param[in] configFileName The configuration file specifies all available maps, see ConfigFileHandler for details of
 * the semantics
 *
 * @return true if initialization was successful (i.e. config file exists or singleton was already initialized)
 * @return false if config file doesn't exist or the singleton was already initialized with a different config file
 */
bool init(std::string const &configFileName);

/**
 * @brief initialize singleton with OpenDRIVE content
 *
 * @param[in] openDriveContent the open drive content extracted from the opendrive file
 * @param[in] overlapMargin margin the lanes are narrowed when calculating overlaps.
 * @param[in] defaultIntersectionType the default intersection type, set to Unknown if no value is passed by the caller.
 * @param[in] defaultTrafficLightType the default traffic light type, set to UNKNOWN if no value is passed by the
 * caller.
 *
 * @return true if initialization was successful (i.e. map content was valid or singleton was already initialized)
 * @return false if map content was invalid or the singleton was already initialized with a different config file
 */
bool initFromOpenDriveContent(std::string const &openDriveContent,
                              double const overlapMargin,
                              intersection::IntersectionType const defaultIntersectionType
                              = intersection::IntersectionType::Unknown,
                              landmark::TrafficLightType const defaultTrafficLightType
                              = landmark::TrafficLightType::UNKNOWN);
/**
 * @brief initialize singleton with given store
 *
 * No map files will be read. The store has to be filled by other means.
 */
bool init(Store::Ptr store);

/**
 * @brief remove all loaded maps and configuration
 */
void cleanup();

/**
 * @brief set the current ENU reference point
 *
 * @param[in] point the geo point defining the reference point
 */
void setENUReferencePoint(point::GeoPoint const &point);

/**
 * @brief get the current ENU reference point set in the map
 *
 * @returns Set ENU reference point in Geo coordinates
 */
point::GeoPoint getENUReferencePoint();

/**
 * @brief check if ENU Reference Point is set
 */
bool isENUReferencePointSet();

/**
 * @brief get points of interest in the surrounding of a given geo_point
 *
 * @param[in] geo_point GeoPoint to be used to query the POIs
 * @param[in] radius radius to be use for the query
 *
 * @returns the list with the PointOfInterest within the queried region.
 */
std::vector<config::PointOfInterest> getPointsOfInterest(point::GeoPoint const &geo_point,
                                                         physics::Distance const &radius);

/**
 * @brief get all points of interest
 *
 * @returns the complete list of PointOfInterest currently available
 */
std::vector<config::PointOfInterest> const &getPointsOfInterest();

/**
 * @brief get a certain point of interest if exists
 *
 * Calls getPointsOfInterest() and searches for the point with the given name.
 *
 * @param[in] name the name of the POI to query
 * @param[out] poi the found PointOfInterest
 *
 * @returns \c true if the PointOfInterest with the given \a name if exits
 */
bool getPointOfInterest(std::string const &name, config::PointOfInterest &poi);

/**
 * @returns \c true if the map is a left hand traffic map
 */
bool isLeftHandedTraffic();

/**
 * @returns \c true if the map is a left hand traffic map
 */
bool isRightHandedTraffic();

/**
 * @returns reference to the map store object
 */
Store &getStore();

/**
 * @brief save the current map content in binary adm format
 *
 * @param[in] admFileName The file name to store the map data in binary format (suggest to use file ending '.adm')
 * @param[in] writeConfigFile Flag to note if a configuration file (admFileName + '.txt') containing the geo reference
 * position of the map should be written
 *
 * @returns \¢ true if the operation succeeded
 */
bool saveAsAdm(std::string const &admFileName, bool writeConfigFile = true);

} // namespace access
} // namespace map
} // namespace ad
