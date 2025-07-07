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
#include <string>

#include "ad/map/access/Types.hpp"
#include "ad/map/intersection/Types.hpp"
#include "ad/map/landmark/Types.hpp"
#include "ad/map/lane/Types.hpp"
#include "ad/map/point/Types.hpp"
#include "ad/map/restriction/Types.hpp"

/** @brief namespace ad */
namespace ad {
/** @brief namespace map */
namespace map {
/** @brief namespace access */
namespace access {

class Store;

/**
 * @brief Autonomus Driving Map Factory.
 *        Contains method to be used to initialize and modify content in the Store.
 */
class Factory
{
public: // Constructor/Destructor
  /**
   * @brief Constructor.
   * @param[in] store Store on which this Factory will operate.
   */
  explicit Factory(Store &store)
    : mStore(store)
  {
  }

  /**
   * @brief Destructor.
   *        Releases all resources.
   */
  virtual ~Factory() = default;

public: // Atomic Operations -- Main
  /**
   * @brief Adds or modifies new Lane in the Store.
   * @param[in] part_id     Partition to which this lane belongs.
   * @param[in] id          Identifier of this lane.
   * @param[in] type        Type of the lane.
   * @param[in] direction   Direction of traffic flow of this lane.
   * @returns true if new Lane is added, false if existing Lane is modified.
   */
  bool add(PartitionId part_id, const lane::LaneId &id, lane::LaneType type, lane::LaneDirection direction);

  /**
   * @brief Add new lane to the store.
   * @param[in] part_id   Partition to which this lane belongs.
   * @param[in] left_geo  Left edge geometry.
   * @param[in] right_geo Right edge geometry.
   * @returns New lane identifier. It will be invalid if not successful.
   * \note Lane Type will be set to NORMAL and Lane Direction to POSITIVE.
   */
  lane::LaneId add(PartitionId part_id, const point::GeoPointList &left_geo, const point::GeoPointList &right_geo);

  /**
   * @brief Add new intersection lane to the store.
   * @param[in] part_id   Partition to which this lane belongs.
   * @param[in] left_ecef  Left edge geometry.
   * @param[in] right_ecef Right edge geometry.
   * @param[in] lane_id_0 First connecting lane.
   * @param[in] lane_id_1 Second connecting lane.
   * @returns New lane identifier. It will be invalid if not successful.
   * \note Lane Type will be set to INTERSECTION and Lane Direction to POSITIVE.
   *            SUCCESSOR/PREDECESSOR contacts will be added to involved lanes.
   */
  lane::LaneId add(PartitionId part_id,
                   const point::ECEFPointList &left_ecef,
                   const point::ECEFPointList &right_ecef,
                   const lane::LaneId &lane_id_0,
                   const lane::LaneId &lane_id_1);

  /**
   * @brief Adds or modifies new landmark in the Store.
   * @param[in] part_id           Partition to which this landmark belongs.
   * @param[in] id                Identifier of this landmark.
   * @param[in] type              Type of the landmark.
   * @param[in] position          Position of the landmark.
   * @param[in] orientation       Orientation of the landmark.
   * @param[in] bounding_box      Bounding box of the landmark.
   * @returns true if new Landmark is added, false if existing Landmark is modified.
   */
  bool addLandmark(PartitionId part_id,
                   const landmark::LandmarkId &id,
                   const landmark::LandmarkType type,
                   const point::ECEFPoint &position,
                   const point::ECEFPoint &orientation,
                   const point::Geometry &bounding_box);

  /**
   * @brief Adds or modifies new traffic light landmark in the Store.
   * @param[in] part_id           Partition to which this landmark belongs.
   * @param[in] id                Identifier of this landmark.
   * @param[in] type              Type of the traffic light landmark.
   * @param[in] position          Position of the landmark.
   * @param[in] orientation       Orientation of the landmark.
   * @param[in] bounding_box      Bounding box of the landmark.
   * @returns true if new Landmark is added, false if existing Landmark is modified.
   */
  bool addTrafficLight(PartitionId part_id,
                       const landmark::LandmarkId &id,
                       const landmark::TrafficLightType type,
                       const point::ECEFPoint &position,
                       const point::ECEFPoint &orientation,
                       const point::Geometry &bounding_box);

  /**
   * @brief Adds or modifies new traffic sign landmark in the Store.
   * @param[in] part_id           Partition to which this landmark belongs.
   * @param[in] id                Identifier of this landmark.
   * @param[in] type              Type of the traffic sign landmark.
   * @param[in] position          Position of the landmark.
   * @param[in] orientation       Orientation of the landmark.
   * @param[in] bounding_box      Bounding box of the landmark.
   * @param[in] text              Text of the traffic sign landmark.
   * @returns true if new Landmark is added, false if existing Landmark is modified.
   */
  bool addTrafficSign(PartitionId part_id,
                      const landmark::LandmarkId &id,
                      const landmark::TrafficSignType type,
                      const point::ECEFPoint &position,
                      const point::ECEFPoint &orientation,
                      const point::Geometry &bounding_box,
                      const std::string &text);

private:
  /**
   * @brief Adds or modifies new traffic sign landmark in the Store.
   * @param[in] part_id               Partition to which this landmark belongs.
   * @param[in] id                    Identifier of this landmark.
   * @param[in] type                  Type of the traffic sign landmark.
   * @param[in] position              Position of the landmark.
   * @param[in] orientation           Orientation of the landmark.
   * @param[in] bounding_box          Bounding box of the landmark.
   * @param[in] traffic_light_type    Type of traffic light of this landmark (may be INVALID).
   * @param[in] traffic_sign_type     Type of traffic sign of this landmark (may be INVALID).
   * @param[in] text                  Supplementory text of the landmark.
   * @returns true if new Landmark is added, false if existing Landmark is modified.
   */
  bool add(PartitionId part_id,
           const landmark::LandmarkId &id,
           const landmark::LandmarkType type,
           const point::ECEFPoint &position,
           const point::ECEFPoint &orientation,
           const point::Geometry &bounding_box,
           const landmark::TrafficLightType traffic_light_type,
           const landmark::TrafficSignType traffic_sign_type,
           const std::string &text);

public: // Atomic Operations -- Add Lane Attribute
  /**
   * @brief Adds Contact to Lane to the Lane object.
   * @param[in] id Lane Identifier.
   * @param[in] contact_lane Contact lane to be added.
   * @returns true if sucessful (lane exists).
   */
  bool add(const lane::LaneId &id, const lane::ContactLane &contact_lane);

  /**
   * @brief Adds Contacts to Lane to the Lane object.
   * @param[in] id Lane Identifier.
   * @param[in] contact_lanes Contacts to lanes to be added.
   * @returns true if sucessful (lane exists).
   */
  bool add(const lane::LaneId &id, const lane::ContactLaneList &contact_lanes);

  /**
   * @brief Add parametic speed limit to the Lane object.
   * @param[in] id Lane Identifier.
   * @param[in] para_speed Parametric speed limit restriction.
   * @returns true if sucessful (lane exists).
   */
  bool add(const lane::LaneId &id, const restriction::SpeedLimit &para_speed);

  /**
   * @brief Add visible landmark to the Lane object
   * @param[in] id Lane Identifier.
   * @param[in] landmark to be added.
   * @returns true if sucessful (lane exists).
   */
  bool add(const lane::LaneId &id, const landmark::LandmarkId &landmark);

  /**
   * @brief Add Restriction to the Lane object.
   * @param[in] id Lane Identifier.
   * @param[in] restriction Restriction to add set.
   * @param[in] andx Add restriction to and_ collection.
   * @returns true if sucessful (lane exists).
   */
  bool add(const lane::LaneId &id, const restriction::Restriction &restriction, bool andx);

  /**
   * @brief Add Contact to Lane to the Lane object.
   * @param[in] id_from   From-Lane Identifier.
   * @param[in] id_to     Identifier of object to which connection is leading.
   * @param[in] location  Location of the contact.
   * @param[in] types     Types of the contact.
   * @param[in] restrs    Legal restrictions for the contact.
   * @returns true if sucessful (lane exists).
   */
  bool add(const lane::LaneId &id_from,
           const lane::LaneId &id_to,
           const lane::ContactLocation location,
           const lane::ContactTypeList &types,
           const restriction::Restrictions &restrs);

  /**
   * @brief Add Contact to Lane to the Lane object.
   * @param[in] id_from   From-Lane Identifier.
   * @param[in] id_to     Identifier of object to which connection is leading.
   * @param[in] location  Location of the contact.
   * @param[in] types     Types of the contact.
   * @param[in] restrs    Legal restrictions for the contact.
   * @param[in] traffic_light  Identifier of the traffic light for this Contact (may be invalid).
   * @returns true if sucessful (lane exists).
   */
  bool add(const lane::LaneId &id_from,
           const lane::LaneId &id_to,
           const lane::ContactLocation location,
           const lane::ContactTypeList &types,
           const restriction::Restrictions &restrs,
           const landmark::LandmarkId &traffic_light);

public: // Atomic Operations -- Set Lane Attribute
  /**
   * @brief Sets the lane attribute.
   * @param[in] id          Identifier of this lane.
   * @param[in] direction   Direction of traffic flow of this lane.
   * @returns true if successful (lane exists).
   */
  bool set(const lane::LaneId &id, lane::LaneDirection direction);

  /**
   * @brief Sets the lane attribute.
   * @param[in] id          Identifier of this lane.
   * @param[in] type        Type of the lane.
   * @returns true if successful (lane exists).
   */
  bool set(const lane::LaneId &id, lane::LaneType type);

  /**
   * @brief Sets the lane attribute.
   * @param[in] id              Identifier of this lane.
   * @param[in] compliance_ver  Data version compliance of this lane.
   * @returns true if successful (lane exists).
   */
  bool set(const lane::LaneId &id, lane::ComplianceVersion compliance_ver);

  /**
   * @brief Sets the Lane Edges.
   * @param[in] id Lane identifier.
   * @param[in] edge_left Left lane geometry.
   * @param[in] edge_right Right lane point::Geometry.
   * @returns true if successful (lane exists).
   */
  bool set(const lane::LaneId &id, const point::Geometry &edge_left, const point::Geometry &edge_right);

  /**
   * @brief Sets speed limit for the COMPLETE lane.
   * @param[in] id Lane identifier.
   * @param[in] speed_limit Speed limit for the COMPLETE lane.
   * @return true if successful.
   */
  bool set(const lane::LaneId &id, const physics::Speed &speed_limit);

  /**
   * @brief Set Restrictions to the Lane object.
   * @param[in] id Lane Identifier.
   * @param[in] restrictions Restrictions to set.
   * @returns true if sucessful (lane exists).
   */
  bool set(const lane::LaneId &id, const restriction::Restrictions &restrictions);

  /**
   * @brief Set visible landmarks to the Lane object.
   * @param[in] id Lane Identifier.
   * @param[in] landmarks to set.
   * @returns true if sucessful (lane exists).
   */
  bool set(const lane::LaneId &id, const landmark::LandmarkIdList &landmarks);

public: // Atomic Operations -- Set Map Meta Data
  /**
   * @brief Set traffic type of the map.
   * @param[in] traffic_type the type of traffic within the map.
   * @returns true if sucessful.
   */
  bool set(const TrafficType &traffic_type);

public: // Atomic operations -- remove things
  /**
   * @brief Method to be called to delete Lane from the Store.
   * @param[in] id Lane identifier.
   * @returns true if lane was successfuly deleted.
   */
  bool deleteLane(lane::LaneId id);

  /**
   * @brief Delete all contacts from one lane to another.
   * @param[in] from_id Lane identifier.
   * @param[in] to_id To-lane identifier.
   * @returns true if contacts were successfuly deleted.
   */
  bool deleteContacts(lane::LaneId from_id, lane::LaneId to_id);

  /**
   * @brief Method to be called to delete landmark from the Store.
   * @param[in] id Landmark identifier.
   * @returns true if landmark was successfuly deleted.
   */
  bool deleteLandmark(landmark::LandmarkId id);

public: // change things
  /**
   * @brief Method to be called to change a secific contact type of a lane.
   *     All contact occurences of the given old_contact type are replaced by
   *     the given new_contact type
   * @param[in] id_from   From-Lane Identifier.
   * @param[in] id_to     Identifier of object to which connection is leading.
   * @param[in] old_contact The original contact type to be replaced.
   * @param[in] new_contact The new contact type to be set.
   *
   * @returns true if the operation succeeeded.
   */
  bool changeLaneContact(const lane::LaneId &id_from,
                         const lane::LaneId &id_to,
                         const lane::ContactType &old_contact,
                         const lane::ContactType &new_contact);

public: // Other methods
  /**
   * @brief Creates missing topological contacts from one lane to another.
   * @param[in] from_lane_id First lane identifer.
   * @param[in] to_lane_id Second lane identifier.
   * @returns True if connection is added.
   * \note Method is limited to SUCCESSOR/PREDECESSOR relationship!
   */
  bool autoConnect(lane::LaneId from_lane_id, lane::LaneId to_lane_id);

  /**
   * @brief Correct lane border.
   * @param[in] from_lane_id First lane identifer. That lane's border to be corrected.
   * @param[in] to_lane_id Second lane identifier. The reference lane try to connect to by shortening/enlarging the
   * other lane.
   * @returns True if correction was perfomred.
   * \note Method is limited to small adaptions of the borders below one meter!
   */
  bool correctLaneBorder(lane::LaneId from_lane_id, lane::LaneId to_lane_id);

  /**
   * @brief Sets the default Intersection type.
   * @param[in] defaultIntersectionType The type of intersection to be set as default.
   */
  void setDefaultIntersectionType(intersection::IntersectionType const defaultIntersectionType);

  /**
   * @brief Sets the default Traffic Light type.
   * @param[in] defaultTrafficLightType The type of traffic light to be set as default.
   */
  void setDefaultTrafficLightType(landmark::TrafficLightType const defaultTrafficLightType);

  /**
   * @brief Adds default contacts to lanes at intersection entries if no contact information has been added yet.
   */
  void addDefaultIntersectionContacts();

private: // Aux Methods
         /**
          * @returns Next available lane identifer.
          */
  lane::LaneId getNextLaneId() const;

protected:
  /**
   * @brief Creates default access restrictions, i.e. all vehicles are allowed.
   */
  restriction::Restrictions createRoadRestrictions() const;

  Store &mStore; ///< Store on which this Factory operates.
  intersection::IntersectionType mDefaultIntersectionType{intersection::IntersectionType::Unknown};
  landmark::TrafficLightType mDefaultTrafficLightType{landmark::TrafficLightType::INVALID};
};

} // namespace access
} // namespace map
} // namespace ad
