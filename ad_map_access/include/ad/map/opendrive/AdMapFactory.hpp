// ----------------- BEGIN LICENSE BLOCK ---------------------------------
//
// Copyright (C) 2019-2021 Intel Corporation
//
// SPDX-License-Identifier: MIT
//
// ----------------- END LICENSE BLOCK -----------------------------------
/**
 * @file
 */

#pragma once

#include <opendrive/types.hpp>
#include <string>

#include "ad/map/access/Factory.hpp"
#include "ad/map/lane/ContactLocationList.hpp"
#include "ad/map/restriction/Types.hpp"

/** @brief namespace ad */
namespace ad {
/** @brief namespace map */
namespace map {
/** @brief namespace opendrive */
namespace opendrive {

/**
 * @class AdMapFactory
 * @brief Creates an AdMap from an OpenDRIVE map file
 *
 * Calls the OpenDRIVE map parser and the geometry generator.
 * Once these operations are done, converts the resulting map into AdMap
 * The AdMap is generated in the store via factory calls.
 *
 */
class AdMapFactory : public access::Factory
{
public:
  explicit AdMapFactory(access::Store &store);

  AdMapFactory() = delete;
  AdMapFactory(AdMapFactory const &) = delete;
  AdMapFactory(AdMapFactory const &&) = delete;
  AdMapFactory &operator=(AdMapFactory &&) = delete;
  AdMapFactory &operator=(AdMapFactory const &) = delete;

  /**
   * @brief Reads the OpenDRIVE map xml, generates a lane map and populates the AdMap store with it via admap Factory.
   *
   * @param[in] mapFilePath The path to the map file.
   * @param[in] overlapMargin margin the lanes are narrowed when calculating overlaps.
   *
   * @returns \c true if a map was generated, false otherwise.
   */
  bool createAdMap(std::string const &mapFilePath, double const overlapMargin);

  /**
   * @brief Parses OpenDRIVE map content string, generates a lane map and populates the AdMap store with it via admap
   * Factory.
   *
   * @param[in] mapContent The content of the map file.
   * @param[in] overlapMargin margin the lanes are narrowed when calculating overlaps.
   *
   * @returns \c true if a map was generated, false otherwise.
   */
  bool createAdMapFromString(std::string const &mapContent, double const overlapMargin);

  /**
   * @brief Returns true if the given file matches an OpenDRIVE map file.
   * @param[in] mapName The name of the map file.
   * @returns \c true if the map is generated without any fatal error
   */
  static bool isOpenDriveMap(std::string const &mapName);

private:
  /**
   * @brief Generates a lane map and populates the AdMap store with previously parsed OpenDRIVE data.
   *
   * @param[in] openDriveData The data from the open drive map using which lane map is generated.
   * @param[in] overlapMargin margin the lanes are narrowed when calculating overlaps.
   *
   * @returns \c true if a map was generated, false otherwise.
   */
  bool createAdMap(::opendrive::OpenDriveData &openDriveData, double const overlapMargin);

  /**
   * @brief Generates an AdMap using the extended map data generated from the openDrive data.
   *
   * @param[in,out] mapData The OpenDRIVE map data container
   *
   * @returns \c true if the map is generated in the AdMap store without any fatal error
   */
  bool convertToAdMap(::opendrive::OpenDriveData &mapData);

  /**
   * @brief Reads the parametric speed from the given lane and updates the store accordlingy
   * @param[in] lane The lane from which the lane speed will be read
   * @returns \c true if the information is successfully updated in the store
   */
  bool setLaneSpeed(::opendrive::Lane const &lane);

  /**
   * @brief Adds a landmark to the admap store
   * @param[in] landmark The landmark from which the information will be read
   * @returns \c true if successfully added to the store
   */
  bool addLandmark(::opendrive::Landmark const &landmark);

  /**
   * @brief Adds the lane to the admap store
   * @param[in] lane ::opendrive::Lane data
   * @returns \c true if successfully added to the store
   */
  bool addLane(::opendrive::Lane const &lane);

  /**
   * @brief Updates the admap store with the contacts for the given lane
   * @param[in] lane lane to be modified
   * @param[in] landmark landmark info in case the contact requires it
   * @param[in] location specifies the location where the contact takes place
   * @returns \c true if successfully added to the store
   */
  bool addSpecialContact(::opendrive::Lane const &lane,
                         ::opendrive::Landmark const &landmark,
                         lane::ContactLocation const &location);

  /**
   * @brief Return true if a vehicle can drive on this lane
   * @param[in] laneType
   * @returns \c true if it is possible to drive on this lane type
   */
  bool isDrivableLane(lane::LaneType laneType) const;

  /**
   * @brief Iterates over the traffic signals and traffic signs and adds the info the store
   * @param[in] lane The lane holds a list of all the landmarks that will be added
   * @param[in] landmarks A map of all the landmarks present in the current map
   * @returns \c true if successfully added to the store
   */
  bool addSpecialContacts(::opendrive::Lane const &lane, ::opendrive::LandmarkMap const &landmarks);

  /**
   * @brief Adds the successor, predecessor and neighbor contacts to the admap store for the given lane
   * @param[in] lane The lane to be modified
   *
   * @returns \c true if successfully added to the store
   */
  bool addContactLanes(::opendrive::Lane const &lane);
};

} // namespace opendrive
} // namespace map
} // namespace ad
