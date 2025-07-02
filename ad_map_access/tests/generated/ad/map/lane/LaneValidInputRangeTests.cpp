/*
 * ----------------- BEGIN LICENSE BLOCK ---------------------------------
 *
 * Copyright (C) 2018-2022 Intel Corporation
 *
 * SPDX-License-Identifier: MIT
 *
 * ----------------- END LICENSE BLOCK -----------------------------------
 */

/*
 * Generated file
 */

#include <gtest/gtest.h>

#include <limits>

#include "ad/map/lane/LaneValidInputRange.hpp"

TEST(LaneValidInputRangeTests, testValidInputRange)
{
  ::ad::map::lane::Lane value;
  ::ad::map::lane::LaneId valueId(1);
  value.id = valueId;
  ::ad::map::lane::LaneType valueType(::ad::map::lane::LaneType::INVALID);
  value.type = valueType;
  ::ad::map::lane::LaneDirection valueDirection(::ad::map::lane::LaneDirection::INVALID);
  value.direction = valueDirection;
  ::ad::map::restriction::Restrictions valueRestrictions;
  ::ad::map::restriction::RestrictionList valueRestrictionsConjunctions;
  ::ad::map::restriction::Restriction valueRestrictionsConjunctionsElement;
  bool valueRestrictionsConjunctionsElementNegated{true};
  valueRestrictionsConjunctionsElement.negated = valueRestrictionsConjunctionsElementNegated;
  ::ad::map::restriction::RoadUserTypeList valueRestrictionsConjunctionsElementRoad_user_types;
  ::ad::map::restriction::RoadUserType valueRestrictionsConjunctionsElementRoad_user_typesElement(
    ::ad::map::restriction::RoadUserType::INVALID);
  valueRestrictionsConjunctionsElementRoad_user_types.resize(
    1, valueRestrictionsConjunctionsElementRoad_user_typesElement);
  valueRestrictionsConjunctionsElement.road_user_types = valueRestrictionsConjunctionsElementRoad_user_types;
  ::ad::map::restriction::PassengerCount valueRestrictionsConjunctionsElementPassengers_min(
    std::numeric_limits<::ad::map::restriction::PassengerCount>::lowest());
  valueRestrictionsConjunctionsElement.passengers_min = valueRestrictionsConjunctionsElementPassengers_min;
  valueRestrictionsConjunctions.resize(1, valueRestrictionsConjunctionsElement);
  valueRestrictions.conjunctions = valueRestrictionsConjunctions;
  ::ad::map::restriction::RestrictionList valueRestrictionsDisjunctions;
  ::ad::map::restriction::Restriction valueRestrictionsDisjunctionsElement;
  bool valueRestrictionsDisjunctionsElementNegated{true};
  valueRestrictionsDisjunctionsElement.negated = valueRestrictionsDisjunctionsElementNegated;
  ::ad::map::restriction::RoadUserTypeList valueRestrictionsDisjunctionsElementRoad_user_types;
  ::ad::map::restriction::RoadUserType valueRestrictionsDisjunctionsElementRoad_user_typesElement(
    ::ad::map::restriction::RoadUserType::INVALID);
  valueRestrictionsDisjunctionsElementRoad_user_types.resize(
    1, valueRestrictionsDisjunctionsElementRoad_user_typesElement);
  valueRestrictionsDisjunctionsElement.road_user_types = valueRestrictionsDisjunctionsElementRoad_user_types;
  ::ad::map::restriction::PassengerCount valueRestrictionsDisjunctionsElementPassengers_min(
    std::numeric_limits<::ad::map::restriction::PassengerCount>::lowest());
  valueRestrictionsDisjunctionsElement.passengers_min = valueRestrictionsDisjunctionsElementPassengers_min;
  valueRestrictionsDisjunctions.resize(1, valueRestrictionsDisjunctionsElement);
  valueRestrictions.disjunctions = valueRestrictionsDisjunctions;
  value.restrictions = valueRestrictions;
  ::ad::physics::Distance valueLength(-1e9);
  value.length = valueLength;
  ::ad::physics::MetricRange valueLength_range;
  ::ad::physics::Distance valueLength_rangeMinimum(-1e9);
  valueLength_rangeMinimum = ::ad::physics::Distance(0.); // set to valid value within struct
  valueLength_range.minimum = valueLength_rangeMinimum;
  ::ad::physics::Distance valueLength_rangeMaximum(-1e9);
  valueLength_range.maximum = valueLength_rangeMaximum;
  valueLength_range.maximum = valueLength_range.minimum;
  valueLength_range.minimum = valueLength_range.maximum;
  value.length_range = valueLength_range;
  ::ad::physics::Distance valueWidth(-1e9);
  value.width = valueWidth;
  ::ad::physics::MetricRange valueWidth_range;
  ::ad::physics::Distance valueWidth_rangeMinimum(-1e9);
  valueWidth_rangeMinimum = ::ad::physics::Distance(0.); // set to valid value within struct
  valueWidth_range.minimum = valueWidth_rangeMinimum;
  ::ad::physics::Distance valueWidth_rangeMaximum(-1e9);
  valueWidth_range.maximum = valueWidth_rangeMaximum;
  valueWidth_range.maximum = valueWidth_range.minimum;
  valueWidth_range.minimum = valueWidth_range.maximum;
  value.width_range = valueWidth_range;
  ::ad::map::restriction::SpeedLimitList valueSpeed_limits;
  ::ad::map::restriction::SpeedLimit valueSpeed_limitsElement;
  ::ad::physics::Speed valueSpeed_limitsElementSpeed_limit(-100.);
  valueSpeed_limitsElement.speed_limit = valueSpeed_limitsElementSpeed_limit;
  ::ad::physics::ParametricRange valueSpeed_limitsElementLane_piece;
  ::ad::physics::ParametricValue valueSpeed_limitsElementLane_pieceMinimum(0.);
  valueSpeed_limitsElementLane_piece.minimum = valueSpeed_limitsElementLane_pieceMinimum;
  ::ad::physics::ParametricValue valueSpeed_limitsElementLane_pieceMaximum(0.);
  valueSpeed_limitsElementLane_piece.maximum = valueSpeed_limitsElementLane_pieceMaximum;
  valueSpeed_limitsElementLane_piece.maximum = valueSpeed_limitsElementLane_piece.minimum;
  valueSpeed_limitsElementLane_piece.minimum = valueSpeed_limitsElementLane_piece.maximum;
  valueSpeed_limitsElement.lane_piece = valueSpeed_limitsElementLane_piece;
  valueSpeed_limits.resize(1, valueSpeed_limitsElement);
  value.speed_limits = valueSpeed_limits;
  ::ad::map::point::Geometry valueEdge_left;
  bool valueEdge_leftIs_valid{true};
  valueEdge_left.is_valid = valueEdge_leftIs_valid;
  bool valueEdge_leftIs_closed{true};
  valueEdge_left.is_closed = valueEdge_leftIs_closed;
  ::ad::map::point::ECEFPointList valueEdge_leftEcef_points;
  ::ad::map::point::ECEFPoint valueEdge_leftEcef_pointsElement;
  ::ad::map::point::ECEFCoordinate valueEdge_leftEcef_pointsElementX(-6400000);
  valueEdge_leftEcef_pointsElement.x = valueEdge_leftEcef_pointsElementX;
  ::ad::map::point::ECEFCoordinate valueEdge_leftEcef_pointsElementY(-6400000);
  valueEdge_leftEcef_pointsElement.y = valueEdge_leftEcef_pointsElementY;
  ::ad::map::point::ECEFCoordinate valueEdge_leftEcef_pointsElementZ(-6400000);
  valueEdge_leftEcef_pointsElement.z = valueEdge_leftEcef_pointsElementZ;
  valueEdge_leftEcef_points.resize(1, valueEdge_leftEcef_pointsElement);
  valueEdge_left.ecef_points = valueEdge_leftEcef_points;
  ::ad::physics::Distance valueEdge_leftLength(-1e9);
  valueEdge_left.length = valueEdge_leftLength;
  ::ad::map::point::ENUPointCache valueEdge_leftPrivate_enu_points_cache;
  ::ad::map::point::ENUPointList valueEdge_leftPrivate_enu_points_cacheEnu_points;
  ::ad::map::point::ENUPoint valueEdge_leftPrivate_enu_points_cacheEnu_pointsElement;
  ::ad::map::point::ENUCoordinate valueEdge_leftPrivate_enu_points_cacheEnu_pointsElementX(-1e8);
  valueEdge_leftPrivate_enu_points_cacheEnu_pointsElement.x = valueEdge_leftPrivate_enu_points_cacheEnu_pointsElementX;
  ::ad::map::point::ENUCoordinate valueEdge_leftPrivate_enu_points_cacheEnu_pointsElementY(-1e8);
  valueEdge_leftPrivate_enu_points_cacheEnu_pointsElement.y = valueEdge_leftPrivate_enu_points_cacheEnu_pointsElementY;
  ::ad::map::point::ENUCoordinate valueEdge_leftPrivate_enu_points_cacheEnu_pointsElementZ(-1e8);
  valueEdge_leftPrivate_enu_points_cacheEnu_pointsElement.z = valueEdge_leftPrivate_enu_points_cacheEnu_pointsElementZ;
  valueEdge_leftPrivate_enu_points_cacheEnu_points.resize(1, valueEdge_leftPrivate_enu_points_cacheEnu_pointsElement);
  valueEdge_leftPrivate_enu_points_cache.enu_points = valueEdge_leftPrivate_enu_points_cacheEnu_points;
  uint64_t valueEdge_leftPrivate_enu_points_cacheEnu_version{std::numeric_limits<uint64_t>::min()};
  valueEdge_leftPrivate_enu_points_cache.enu_version = valueEdge_leftPrivate_enu_points_cacheEnu_version;
  valueEdge_left.private_enu_points_cache = valueEdge_leftPrivate_enu_points_cache;
  value.edge_left = valueEdge_left;
  ::ad::map::point::Geometry valueEdge_right;
  bool valueEdge_rightIs_valid{true};
  valueEdge_right.is_valid = valueEdge_rightIs_valid;
  bool valueEdge_rightIs_closed{true};
  valueEdge_right.is_closed = valueEdge_rightIs_closed;
  ::ad::map::point::ECEFPointList valueEdge_rightEcef_points;
  ::ad::map::point::ECEFPoint valueEdge_rightEcef_pointsElement;
  ::ad::map::point::ECEFCoordinate valueEdge_rightEcef_pointsElementX(-6400000);
  valueEdge_rightEcef_pointsElement.x = valueEdge_rightEcef_pointsElementX;
  ::ad::map::point::ECEFCoordinate valueEdge_rightEcef_pointsElementY(-6400000);
  valueEdge_rightEcef_pointsElement.y = valueEdge_rightEcef_pointsElementY;
  ::ad::map::point::ECEFCoordinate valueEdge_rightEcef_pointsElementZ(-6400000);
  valueEdge_rightEcef_pointsElement.z = valueEdge_rightEcef_pointsElementZ;
  valueEdge_rightEcef_points.resize(1, valueEdge_rightEcef_pointsElement);
  valueEdge_right.ecef_points = valueEdge_rightEcef_points;
  ::ad::physics::Distance valueEdge_rightLength(-1e9);
  valueEdge_right.length = valueEdge_rightLength;
  ::ad::map::point::ENUPointCache valueEdge_rightPrivate_enu_points_cache;
  ::ad::map::point::ENUPointList valueEdge_rightPrivate_enu_points_cacheEnu_points;
  ::ad::map::point::ENUPoint valueEdge_rightPrivate_enu_points_cacheEnu_pointsElement;
  ::ad::map::point::ENUCoordinate valueEdge_rightPrivate_enu_points_cacheEnu_pointsElementX(-1e8);
  valueEdge_rightPrivate_enu_points_cacheEnu_pointsElement.x
    = valueEdge_rightPrivate_enu_points_cacheEnu_pointsElementX;
  ::ad::map::point::ENUCoordinate valueEdge_rightPrivate_enu_points_cacheEnu_pointsElementY(-1e8);
  valueEdge_rightPrivate_enu_points_cacheEnu_pointsElement.y
    = valueEdge_rightPrivate_enu_points_cacheEnu_pointsElementY;
  ::ad::map::point::ENUCoordinate valueEdge_rightPrivate_enu_points_cacheEnu_pointsElementZ(-1e8);
  valueEdge_rightPrivate_enu_points_cacheEnu_pointsElement.z
    = valueEdge_rightPrivate_enu_points_cacheEnu_pointsElementZ;
  valueEdge_rightPrivate_enu_points_cacheEnu_points.resize(1, valueEdge_rightPrivate_enu_points_cacheEnu_pointsElement);
  valueEdge_rightPrivate_enu_points_cache.enu_points = valueEdge_rightPrivate_enu_points_cacheEnu_points;
  uint64_t valueEdge_rightPrivate_enu_points_cacheEnu_version{std::numeric_limits<uint64_t>::min()};
  valueEdge_rightPrivate_enu_points_cache.enu_version = valueEdge_rightPrivate_enu_points_cacheEnu_version;
  valueEdge_right.private_enu_points_cache = valueEdge_rightPrivate_enu_points_cache;
  value.edge_right = valueEdge_right;
  ::ad::map::lane::ContactLaneList valueContact_lanes;
  ::ad::map::lane::ContactLane valueContact_lanesElement;
  ::ad::map::lane::LaneId valueContact_lanesElementTo_lane(1);
  valueContact_lanesElement.to_lane = valueContact_lanesElementTo_lane;
  ::ad::map::lane::ContactLocation valueContact_lanesElementLocation(::ad::map::lane::ContactLocation::INVALID);
  valueContact_lanesElement.location = valueContact_lanesElementLocation;
  ::ad::map::lane::ContactTypeList valueContact_lanesElementTypes;
  ::ad::map::lane::ContactType valueContact_lanesElementTypesElement(::ad::map::lane::ContactType::INVALID);
  valueContact_lanesElementTypes.resize(1, valueContact_lanesElementTypesElement);
  valueContact_lanesElement.types = valueContact_lanesElementTypes;
  ::ad::map::restriction::Restrictions valueContact_lanesElementRestrictions;
  ::ad::map::restriction::RestrictionList valueContact_lanesElementRestrictionsConjunctions;
  ::ad::map::restriction::Restriction valueContact_lanesElementRestrictionsConjunctionsElement;
  bool valueContact_lanesElementRestrictionsConjunctionsElementNegated{true};
  valueContact_lanesElementRestrictionsConjunctionsElement.negated
    = valueContact_lanesElementRestrictionsConjunctionsElementNegated;
  ::ad::map::restriction::RoadUserTypeList valueContact_lanesElementRestrictionsConjunctionsElementRoad_user_types;
  ::ad::map::restriction::RoadUserType valueContact_lanesElementRestrictionsConjunctionsElementRoad_user_typesElement(
    ::ad::map::restriction::RoadUserType::INVALID);
  valueContact_lanesElementRestrictionsConjunctionsElementRoad_user_types.resize(
    1, valueContact_lanesElementRestrictionsConjunctionsElementRoad_user_typesElement);
  valueContact_lanesElementRestrictionsConjunctionsElement.road_user_types
    = valueContact_lanesElementRestrictionsConjunctionsElementRoad_user_types;
  ::ad::map::restriction::PassengerCount valueContact_lanesElementRestrictionsConjunctionsElementPassengers_min(
    std::numeric_limits<::ad::map::restriction::PassengerCount>::lowest());
  valueContact_lanesElementRestrictionsConjunctionsElement.passengers_min
    = valueContact_lanesElementRestrictionsConjunctionsElementPassengers_min;
  valueContact_lanesElementRestrictionsConjunctions.resize(1, valueContact_lanesElementRestrictionsConjunctionsElement);
  valueContact_lanesElementRestrictions.conjunctions = valueContact_lanesElementRestrictionsConjunctions;
  ::ad::map::restriction::RestrictionList valueContact_lanesElementRestrictionsDisjunctions;
  ::ad::map::restriction::Restriction valueContact_lanesElementRestrictionsDisjunctionsElement;
  bool valueContact_lanesElementRestrictionsDisjunctionsElementNegated{true};
  valueContact_lanesElementRestrictionsDisjunctionsElement.negated
    = valueContact_lanesElementRestrictionsDisjunctionsElementNegated;
  ::ad::map::restriction::RoadUserTypeList valueContact_lanesElementRestrictionsDisjunctionsElementRoad_user_types;
  ::ad::map::restriction::RoadUserType valueContact_lanesElementRestrictionsDisjunctionsElementRoad_user_typesElement(
    ::ad::map::restriction::RoadUserType::INVALID);
  valueContact_lanesElementRestrictionsDisjunctionsElementRoad_user_types.resize(
    1, valueContact_lanesElementRestrictionsDisjunctionsElementRoad_user_typesElement);
  valueContact_lanesElementRestrictionsDisjunctionsElement.road_user_types
    = valueContact_lanesElementRestrictionsDisjunctionsElementRoad_user_types;
  ::ad::map::restriction::PassengerCount valueContact_lanesElementRestrictionsDisjunctionsElementPassengers_min(
    std::numeric_limits<::ad::map::restriction::PassengerCount>::lowest());
  valueContact_lanesElementRestrictionsDisjunctionsElement.passengers_min
    = valueContact_lanesElementRestrictionsDisjunctionsElementPassengers_min;
  valueContact_lanesElementRestrictionsDisjunctions.resize(1, valueContact_lanesElementRestrictionsDisjunctionsElement);
  valueContact_lanesElementRestrictions.disjunctions = valueContact_lanesElementRestrictionsDisjunctions;
  valueContact_lanesElement.restrictions = valueContact_lanesElementRestrictions;
  ::ad::map::landmark::LandmarkId valueContact_lanesElementLandmark_id(
    std::numeric_limits<::ad::map::landmark::LandmarkId>::lowest());
  valueContact_lanesElement.landmark_id = valueContact_lanesElementLandmark_id;
  valueContact_lanes.resize(1, valueContact_lanesElement);
  value.contact_lanes = valueContact_lanes;
  ::ad::map::lane::ComplianceVersion valueCompliance_version(
    std::numeric_limits<::ad::map::lane::ComplianceVersion>::lowest());
  value.compliance_version = valueCompliance_version;
  ::ad::map::point::BoundingSphere valueBounding_sphere;
  ::ad::map::point::ECEFPoint valueBounding_sphereCenter;
  ::ad::map::point::ECEFCoordinate valueBounding_sphereCenterX(-6400000);
  valueBounding_sphereCenter.x = valueBounding_sphereCenterX;
  ::ad::map::point::ECEFCoordinate valueBounding_sphereCenterY(-6400000);
  valueBounding_sphereCenter.y = valueBounding_sphereCenterY;
  ::ad::map::point::ECEFCoordinate valueBounding_sphereCenterZ(-6400000);
  valueBounding_sphereCenter.z = valueBounding_sphereCenterZ;
  valueBounding_sphere.center = valueBounding_sphereCenter;
  ::ad::physics::Distance valueBounding_sphereRadius(-1e9);
  valueBounding_sphere.radius = valueBounding_sphereRadius;
  value.bounding_sphere = valueBounding_sphere;
  ::ad::map::landmark::LandmarkIdList valueVisible_landmarks;
  ::ad::map::landmark::LandmarkId valueVisible_landmarksElement(
    std::numeric_limits<::ad::map::landmark::LandmarkId>::lowest());
  valueVisible_landmarks.resize(1, valueVisible_landmarksElement);
  value.visible_landmarks = valueVisible_landmarks;
  ASSERT_TRUE(withinValidInputRange(value));
}

TEST(LaneValidInputRangeTests, testValidInputRangeTypeTooSmall)
{
  ::ad::map::lane::Lane value;
  ::ad::map::lane::LaneId valueId(1);
  value.id = valueId;
  ::ad::map::lane::LaneType valueType(::ad::map::lane::LaneType::INVALID);
  value.type = valueType;
  ::ad::map::lane::LaneDirection valueDirection(::ad::map::lane::LaneDirection::INVALID);
  value.direction = valueDirection;
  ::ad::map::restriction::Restrictions valueRestrictions;
  ::ad::map::restriction::RestrictionList valueRestrictionsConjunctions;
  ::ad::map::restriction::Restriction valueRestrictionsConjunctionsElement;
  bool valueRestrictionsConjunctionsElementNegated{true};
  valueRestrictionsConjunctionsElement.negated = valueRestrictionsConjunctionsElementNegated;
  ::ad::map::restriction::RoadUserTypeList valueRestrictionsConjunctionsElementRoad_user_types;
  ::ad::map::restriction::RoadUserType valueRestrictionsConjunctionsElementRoad_user_typesElement(
    ::ad::map::restriction::RoadUserType::INVALID);
  valueRestrictionsConjunctionsElementRoad_user_types.resize(
    1, valueRestrictionsConjunctionsElementRoad_user_typesElement);
  valueRestrictionsConjunctionsElement.road_user_types = valueRestrictionsConjunctionsElementRoad_user_types;
  ::ad::map::restriction::PassengerCount valueRestrictionsConjunctionsElementPassengers_min(
    std::numeric_limits<::ad::map::restriction::PassengerCount>::lowest());
  valueRestrictionsConjunctionsElement.passengers_min = valueRestrictionsConjunctionsElementPassengers_min;
  valueRestrictionsConjunctions.resize(1, valueRestrictionsConjunctionsElement);
  valueRestrictions.conjunctions = valueRestrictionsConjunctions;
  ::ad::map::restriction::RestrictionList valueRestrictionsDisjunctions;
  ::ad::map::restriction::Restriction valueRestrictionsDisjunctionsElement;
  bool valueRestrictionsDisjunctionsElementNegated{true};
  valueRestrictionsDisjunctionsElement.negated = valueRestrictionsDisjunctionsElementNegated;
  ::ad::map::restriction::RoadUserTypeList valueRestrictionsDisjunctionsElementRoad_user_types;
  ::ad::map::restriction::RoadUserType valueRestrictionsDisjunctionsElementRoad_user_typesElement(
    ::ad::map::restriction::RoadUserType::INVALID);
  valueRestrictionsDisjunctionsElementRoad_user_types.resize(
    1, valueRestrictionsDisjunctionsElementRoad_user_typesElement);
  valueRestrictionsDisjunctionsElement.road_user_types = valueRestrictionsDisjunctionsElementRoad_user_types;
  ::ad::map::restriction::PassengerCount valueRestrictionsDisjunctionsElementPassengers_min(
    std::numeric_limits<::ad::map::restriction::PassengerCount>::lowest());
  valueRestrictionsDisjunctionsElement.passengers_min = valueRestrictionsDisjunctionsElementPassengers_min;
  valueRestrictionsDisjunctions.resize(1, valueRestrictionsDisjunctionsElement);
  valueRestrictions.disjunctions = valueRestrictionsDisjunctions;
  value.restrictions = valueRestrictions;
  ::ad::physics::Distance valueLength(-1e9);
  value.length = valueLength;
  ::ad::physics::MetricRange valueLength_range;
  ::ad::physics::Distance valueLength_rangeMinimum(-1e9);
  valueLength_rangeMinimum = ::ad::physics::Distance(0.); // set to valid value within struct
  valueLength_range.minimum = valueLength_rangeMinimum;
  ::ad::physics::Distance valueLength_rangeMaximum(-1e9);
  valueLength_range.maximum = valueLength_rangeMaximum;
  valueLength_range.maximum = valueLength_range.minimum;
  valueLength_range.minimum = valueLength_range.maximum;
  value.length_range = valueLength_range;
  ::ad::physics::Distance valueWidth(-1e9);
  value.width = valueWidth;
  ::ad::physics::MetricRange valueWidth_range;
  ::ad::physics::Distance valueWidth_rangeMinimum(-1e9);
  valueWidth_rangeMinimum = ::ad::physics::Distance(0.); // set to valid value within struct
  valueWidth_range.minimum = valueWidth_rangeMinimum;
  ::ad::physics::Distance valueWidth_rangeMaximum(-1e9);
  valueWidth_range.maximum = valueWidth_rangeMaximum;
  valueWidth_range.maximum = valueWidth_range.minimum;
  valueWidth_range.minimum = valueWidth_range.maximum;
  value.width_range = valueWidth_range;
  ::ad::map::restriction::SpeedLimitList valueSpeed_limits;
  ::ad::map::restriction::SpeedLimit valueSpeed_limitsElement;
  ::ad::physics::Speed valueSpeed_limitsElementSpeed_limit(-100.);
  valueSpeed_limitsElement.speed_limit = valueSpeed_limitsElementSpeed_limit;
  ::ad::physics::ParametricRange valueSpeed_limitsElementLane_piece;
  ::ad::physics::ParametricValue valueSpeed_limitsElementLane_pieceMinimum(0.);
  valueSpeed_limitsElementLane_piece.minimum = valueSpeed_limitsElementLane_pieceMinimum;
  ::ad::physics::ParametricValue valueSpeed_limitsElementLane_pieceMaximum(0.);
  valueSpeed_limitsElementLane_piece.maximum = valueSpeed_limitsElementLane_pieceMaximum;
  valueSpeed_limitsElementLane_piece.maximum = valueSpeed_limitsElementLane_piece.minimum;
  valueSpeed_limitsElementLane_piece.minimum = valueSpeed_limitsElementLane_piece.maximum;
  valueSpeed_limitsElement.lane_piece = valueSpeed_limitsElementLane_piece;
  valueSpeed_limits.resize(1, valueSpeed_limitsElement);
  value.speed_limits = valueSpeed_limits;
  ::ad::map::point::Geometry valueEdge_left;
  bool valueEdge_leftIs_valid{true};
  valueEdge_left.is_valid = valueEdge_leftIs_valid;
  bool valueEdge_leftIs_closed{true};
  valueEdge_left.is_closed = valueEdge_leftIs_closed;
  ::ad::map::point::ECEFPointList valueEdge_leftEcef_points;
  ::ad::map::point::ECEFPoint valueEdge_leftEcef_pointsElement;
  ::ad::map::point::ECEFCoordinate valueEdge_leftEcef_pointsElementX(-6400000);
  valueEdge_leftEcef_pointsElement.x = valueEdge_leftEcef_pointsElementX;
  ::ad::map::point::ECEFCoordinate valueEdge_leftEcef_pointsElementY(-6400000);
  valueEdge_leftEcef_pointsElement.y = valueEdge_leftEcef_pointsElementY;
  ::ad::map::point::ECEFCoordinate valueEdge_leftEcef_pointsElementZ(-6400000);
  valueEdge_leftEcef_pointsElement.z = valueEdge_leftEcef_pointsElementZ;
  valueEdge_leftEcef_points.resize(1, valueEdge_leftEcef_pointsElement);
  valueEdge_left.ecef_points = valueEdge_leftEcef_points;
  ::ad::physics::Distance valueEdge_leftLength(-1e9);
  valueEdge_left.length = valueEdge_leftLength;
  ::ad::map::point::ENUPointCache valueEdge_leftPrivate_enu_points_cache;
  ::ad::map::point::ENUPointList valueEdge_leftPrivate_enu_points_cacheEnu_points;
  ::ad::map::point::ENUPoint valueEdge_leftPrivate_enu_points_cacheEnu_pointsElement;
  ::ad::map::point::ENUCoordinate valueEdge_leftPrivate_enu_points_cacheEnu_pointsElementX(-1e8);
  valueEdge_leftPrivate_enu_points_cacheEnu_pointsElement.x = valueEdge_leftPrivate_enu_points_cacheEnu_pointsElementX;
  ::ad::map::point::ENUCoordinate valueEdge_leftPrivate_enu_points_cacheEnu_pointsElementY(-1e8);
  valueEdge_leftPrivate_enu_points_cacheEnu_pointsElement.y = valueEdge_leftPrivate_enu_points_cacheEnu_pointsElementY;
  ::ad::map::point::ENUCoordinate valueEdge_leftPrivate_enu_points_cacheEnu_pointsElementZ(-1e8);
  valueEdge_leftPrivate_enu_points_cacheEnu_pointsElement.z = valueEdge_leftPrivate_enu_points_cacheEnu_pointsElementZ;
  valueEdge_leftPrivate_enu_points_cacheEnu_points.resize(1, valueEdge_leftPrivate_enu_points_cacheEnu_pointsElement);
  valueEdge_leftPrivate_enu_points_cache.enu_points = valueEdge_leftPrivate_enu_points_cacheEnu_points;
  uint64_t valueEdge_leftPrivate_enu_points_cacheEnu_version{std::numeric_limits<uint64_t>::min()};
  valueEdge_leftPrivate_enu_points_cache.enu_version = valueEdge_leftPrivate_enu_points_cacheEnu_version;
  valueEdge_left.private_enu_points_cache = valueEdge_leftPrivate_enu_points_cache;
  value.edge_left = valueEdge_left;
  ::ad::map::point::Geometry valueEdge_right;
  bool valueEdge_rightIs_valid{true};
  valueEdge_right.is_valid = valueEdge_rightIs_valid;
  bool valueEdge_rightIs_closed{true};
  valueEdge_right.is_closed = valueEdge_rightIs_closed;
  ::ad::map::point::ECEFPointList valueEdge_rightEcef_points;
  ::ad::map::point::ECEFPoint valueEdge_rightEcef_pointsElement;
  ::ad::map::point::ECEFCoordinate valueEdge_rightEcef_pointsElementX(-6400000);
  valueEdge_rightEcef_pointsElement.x = valueEdge_rightEcef_pointsElementX;
  ::ad::map::point::ECEFCoordinate valueEdge_rightEcef_pointsElementY(-6400000);
  valueEdge_rightEcef_pointsElement.y = valueEdge_rightEcef_pointsElementY;
  ::ad::map::point::ECEFCoordinate valueEdge_rightEcef_pointsElementZ(-6400000);
  valueEdge_rightEcef_pointsElement.z = valueEdge_rightEcef_pointsElementZ;
  valueEdge_rightEcef_points.resize(1, valueEdge_rightEcef_pointsElement);
  valueEdge_right.ecef_points = valueEdge_rightEcef_points;
  ::ad::physics::Distance valueEdge_rightLength(-1e9);
  valueEdge_right.length = valueEdge_rightLength;
  ::ad::map::point::ENUPointCache valueEdge_rightPrivate_enu_points_cache;
  ::ad::map::point::ENUPointList valueEdge_rightPrivate_enu_points_cacheEnu_points;
  ::ad::map::point::ENUPoint valueEdge_rightPrivate_enu_points_cacheEnu_pointsElement;
  ::ad::map::point::ENUCoordinate valueEdge_rightPrivate_enu_points_cacheEnu_pointsElementX(-1e8);
  valueEdge_rightPrivate_enu_points_cacheEnu_pointsElement.x
    = valueEdge_rightPrivate_enu_points_cacheEnu_pointsElementX;
  ::ad::map::point::ENUCoordinate valueEdge_rightPrivate_enu_points_cacheEnu_pointsElementY(-1e8);
  valueEdge_rightPrivate_enu_points_cacheEnu_pointsElement.y
    = valueEdge_rightPrivate_enu_points_cacheEnu_pointsElementY;
  ::ad::map::point::ENUCoordinate valueEdge_rightPrivate_enu_points_cacheEnu_pointsElementZ(-1e8);
  valueEdge_rightPrivate_enu_points_cacheEnu_pointsElement.z
    = valueEdge_rightPrivate_enu_points_cacheEnu_pointsElementZ;
  valueEdge_rightPrivate_enu_points_cacheEnu_points.resize(1, valueEdge_rightPrivate_enu_points_cacheEnu_pointsElement);
  valueEdge_rightPrivate_enu_points_cache.enu_points = valueEdge_rightPrivate_enu_points_cacheEnu_points;
  uint64_t valueEdge_rightPrivate_enu_points_cacheEnu_version{std::numeric_limits<uint64_t>::min()};
  valueEdge_rightPrivate_enu_points_cache.enu_version = valueEdge_rightPrivate_enu_points_cacheEnu_version;
  valueEdge_right.private_enu_points_cache = valueEdge_rightPrivate_enu_points_cache;
  value.edge_right = valueEdge_right;
  ::ad::map::lane::ContactLaneList valueContact_lanes;
  ::ad::map::lane::ContactLane valueContact_lanesElement;
  ::ad::map::lane::LaneId valueContact_lanesElementTo_lane(1);
  valueContact_lanesElement.to_lane = valueContact_lanesElementTo_lane;
  ::ad::map::lane::ContactLocation valueContact_lanesElementLocation(::ad::map::lane::ContactLocation::INVALID);
  valueContact_lanesElement.location = valueContact_lanesElementLocation;
  ::ad::map::lane::ContactTypeList valueContact_lanesElementTypes;
  ::ad::map::lane::ContactType valueContact_lanesElementTypesElement(::ad::map::lane::ContactType::INVALID);
  valueContact_lanesElementTypes.resize(1, valueContact_lanesElementTypesElement);
  valueContact_lanesElement.types = valueContact_lanesElementTypes;
  ::ad::map::restriction::Restrictions valueContact_lanesElementRestrictions;
  ::ad::map::restriction::RestrictionList valueContact_lanesElementRestrictionsConjunctions;
  ::ad::map::restriction::Restriction valueContact_lanesElementRestrictionsConjunctionsElement;
  bool valueContact_lanesElementRestrictionsConjunctionsElementNegated{true};
  valueContact_lanesElementRestrictionsConjunctionsElement.negated
    = valueContact_lanesElementRestrictionsConjunctionsElementNegated;
  ::ad::map::restriction::RoadUserTypeList valueContact_lanesElementRestrictionsConjunctionsElementRoad_user_types;
  ::ad::map::restriction::RoadUserType valueContact_lanesElementRestrictionsConjunctionsElementRoad_user_typesElement(
    ::ad::map::restriction::RoadUserType::INVALID);
  valueContact_lanesElementRestrictionsConjunctionsElementRoad_user_types.resize(
    1, valueContact_lanesElementRestrictionsConjunctionsElementRoad_user_typesElement);
  valueContact_lanesElementRestrictionsConjunctionsElement.road_user_types
    = valueContact_lanesElementRestrictionsConjunctionsElementRoad_user_types;
  ::ad::map::restriction::PassengerCount valueContact_lanesElementRestrictionsConjunctionsElementPassengers_min(
    std::numeric_limits<::ad::map::restriction::PassengerCount>::lowest());
  valueContact_lanesElementRestrictionsConjunctionsElement.passengers_min
    = valueContact_lanesElementRestrictionsConjunctionsElementPassengers_min;
  valueContact_lanesElementRestrictionsConjunctions.resize(1, valueContact_lanesElementRestrictionsConjunctionsElement);
  valueContact_lanesElementRestrictions.conjunctions = valueContact_lanesElementRestrictionsConjunctions;
  ::ad::map::restriction::RestrictionList valueContact_lanesElementRestrictionsDisjunctions;
  ::ad::map::restriction::Restriction valueContact_lanesElementRestrictionsDisjunctionsElement;
  bool valueContact_lanesElementRestrictionsDisjunctionsElementNegated{true};
  valueContact_lanesElementRestrictionsDisjunctionsElement.negated
    = valueContact_lanesElementRestrictionsDisjunctionsElementNegated;
  ::ad::map::restriction::RoadUserTypeList valueContact_lanesElementRestrictionsDisjunctionsElementRoad_user_types;
  ::ad::map::restriction::RoadUserType valueContact_lanesElementRestrictionsDisjunctionsElementRoad_user_typesElement(
    ::ad::map::restriction::RoadUserType::INVALID);
  valueContact_lanesElementRestrictionsDisjunctionsElementRoad_user_types.resize(
    1, valueContact_lanesElementRestrictionsDisjunctionsElementRoad_user_typesElement);
  valueContact_lanesElementRestrictionsDisjunctionsElement.road_user_types
    = valueContact_lanesElementRestrictionsDisjunctionsElementRoad_user_types;
  ::ad::map::restriction::PassengerCount valueContact_lanesElementRestrictionsDisjunctionsElementPassengers_min(
    std::numeric_limits<::ad::map::restriction::PassengerCount>::lowest());
  valueContact_lanesElementRestrictionsDisjunctionsElement.passengers_min
    = valueContact_lanesElementRestrictionsDisjunctionsElementPassengers_min;
  valueContact_lanesElementRestrictionsDisjunctions.resize(1, valueContact_lanesElementRestrictionsDisjunctionsElement);
  valueContact_lanesElementRestrictions.disjunctions = valueContact_lanesElementRestrictionsDisjunctions;
  valueContact_lanesElement.restrictions = valueContact_lanesElementRestrictions;
  ::ad::map::landmark::LandmarkId valueContact_lanesElementLandmark_id(
    std::numeric_limits<::ad::map::landmark::LandmarkId>::lowest());
  valueContact_lanesElement.landmark_id = valueContact_lanesElementLandmark_id;
  valueContact_lanes.resize(1, valueContact_lanesElement);
  value.contact_lanes = valueContact_lanes;
  ::ad::map::lane::ComplianceVersion valueCompliance_version(
    std::numeric_limits<::ad::map::lane::ComplianceVersion>::lowest());
  value.compliance_version = valueCompliance_version;
  ::ad::map::point::BoundingSphere valueBounding_sphere;
  ::ad::map::point::ECEFPoint valueBounding_sphereCenter;
  ::ad::map::point::ECEFCoordinate valueBounding_sphereCenterX(-6400000);
  valueBounding_sphereCenter.x = valueBounding_sphereCenterX;
  ::ad::map::point::ECEFCoordinate valueBounding_sphereCenterY(-6400000);
  valueBounding_sphereCenter.y = valueBounding_sphereCenterY;
  ::ad::map::point::ECEFCoordinate valueBounding_sphereCenterZ(-6400000);
  valueBounding_sphereCenter.z = valueBounding_sphereCenterZ;
  valueBounding_sphere.center = valueBounding_sphereCenter;
  ::ad::physics::Distance valueBounding_sphereRadius(-1e9);
  valueBounding_sphere.radius = valueBounding_sphereRadius;
  value.bounding_sphere = valueBounding_sphere;
  ::ad::map::landmark::LandmarkIdList valueVisible_landmarks;
  ::ad::map::landmark::LandmarkId valueVisible_landmarksElement(
    std::numeric_limits<::ad::map::landmark::LandmarkId>::lowest());
  valueVisible_landmarks.resize(1, valueVisible_landmarksElement);
  value.visible_landmarks = valueVisible_landmarks;

  // override member with data type value below input range minimum
  ::ad::map::lane::LaneType invalidInitializedMember(static_cast<::ad::map::lane::LaneType>(-1));
  value.type = invalidInitializedMember;
  ASSERT_FALSE(withinValidInputRange(value));
}

TEST(LaneValidInputRangeTests, testValidInputRangeTypeTooBig)
{
  ::ad::map::lane::Lane value;
  ::ad::map::lane::LaneId valueId(1);
  value.id = valueId;
  ::ad::map::lane::LaneType valueType(::ad::map::lane::LaneType::INVALID);
  value.type = valueType;
  ::ad::map::lane::LaneDirection valueDirection(::ad::map::lane::LaneDirection::INVALID);
  value.direction = valueDirection;
  ::ad::map::restriction::Restrictions valueRestrictions;
  ::ad::map::restriction::RestrictionList valueRestrictionsConjunctions;
  ::ad::map::restriction::Restriction valueRestrictionsConjunctionsElement;
  bool valueRestrictionsConjunctionsElementNegated{true};
  valueRestrictionsConjunctionsElement.negated = valueRestrictionsConjunctionsElementNegated;
  ::ad::map::restriction::RoadUserTypeList valueRestrictionsConjunctionsElementRoad_user_types;
  ::ad::map::restriction::RoadUserType valueRestrictionsConjunctionsElementRoad_user_typesElement(
    ::ad::map::restriction::RoadUserType::INVALID);
  valueRestrictionsConjunctionsElementRoad_user_types.resize(
    1, valueRestrictionsConjunctionsElementRoad_user_typesElement);
  valueRestrictionsConjunctionsElement.road_user_types = valueRestrictionsConjunctionsElementRoad_user_types;
  ::ad::map::restriction::PassengerCount valueRestrictionsConjunctionsElementPassengers_min(
    std::numeric_limits<::ad::map::restriction::PassengerCount>::lowest());
  valueRestrictionsConjunctionsElement.passengers_min = valueRestrictionsConjunctionsElementPassengers_min;
  valueRestrictionsConjunctions.resize(1, valueRestrictionsConjunctionsElement);
  valueRestrictions.conjunctions = valueRestrictionsConjunctions;
  ::ad::map::restriction::RestrictionList valueRestrictionsDisjunctions;
  ::ad::map::restriction::Restriction valueRestrictionsDisjunctionsElement;
  bool valueRestrictionsDisjunctionsElementNegated{true};
  valueRestrictionsDisjunctionsElement.negated = valueRestrictionsDisjunctionsElementNegated;
  ::ad::map::restriction::RoadUserTypeList valueRestrictionsDisjunctionsElementRoad_user_types;
  ::ad::map::restriction::RoadUserType valueRestrictionsDisjunctionsElementRoad_user_typesElement(
    ::ad::map::restriction::RoadUserType::INVALID);
  valueRestrictionsDisjunctionsElementRoad_user_types.resize(
    1, valueRestrictionsDisjunctionsElementRoad_user_typesElement);
  valueRestrictionsDisjunctionsElement.road_user_types = valueRestrictionsDisjunctionsElementRoad_user_types;
  ::ad::map::restriction::PassengerCount valueRestrictionsDisjunctionsElementPassengers_min(
    std::numeric_limits<::ad::map::restriction::PassengerCount>::lowest());
  valueRestrictionsDisjunctionsElement.passengers_min = valueRestrictionsDisjunctionsElementPassengers_min;
  valueRestrictionsDisjunctions.resize(1, valueRestrictionsDisjunctionsElement);
  valueRestrictions.disjunctions = valueRestrictionsDisjunctions;
  value.restrictions = valueRestrictions;
  ::ad::physics::Distance valueLength(-1e9);
  value.length = valueLength;
  ::ad::physics::MetricRange valueLength_range;
  ::ad::physics::Distance valueLength_rangeMinimum(-1e9);
  valueLength_rangeMinimum = ::ad::physics::Distance(0.); // set to valid value within struct
  valueLength_range.minimum = valueLength_rangeMinimum;
  ::ad::physics::Distance valueLength_rangeMaximum(-1e9);
  valueLength_range.maximum = valueLength_rangeMaximum;
  valueLength_range.maximum = valueLength_range.minimum;
  valueLength_range.minimum = valueLength_range.maximum;
  value.length_range = valueLength_range;
  ::ad::physics::Distance valueWidth(-1e9);
  value.width = valueWidth;
  ::ad::physics::MetricRange valueWidth_range;
  ::ad::physics::Distance valueWidth_rangeMinimum(-1e9);
  valueWidth_rangeMinimum = ::ad::physics::Distance(0.); // set to valid value within struct
  valueWidth_range.minimum = valueWidth_rangeMinimum;
  ::ad::physics::Distance valueWidth_rangeMaximum(-1e9);
  valueWidth_range.maximum = valueWidth_rangeMaximum;
  valueWidth_range.maximum = valueWidth_range.minimum;
  valueWidth_range.minimum = valueWidth_range.maximum;
  value.width_range = valueWidth_range;
  ::ad::map::restriction::SpeedLimitList valueSpeed_limits;
  ::ad::map::restriction::SpeedLimit valueSpeed_limitsElement;
  ::ad::physics::Speed valueSpeed_limitsElementSpeed_limit(-100.);
  valueSpeed_limitsElement.speed_limit = valueSpeed_limitsElementSpeed_limit;
  ::ad::physics::ParametricRange valueSpeed_limitsElementLane_piece;
  ::ad::physics::ParametricValue valueSpeed_limitsElementLane_pieceMinimum(0.);
  valueSpeed_limitsElementLane_piece.minimum = valueSpeed_limitsElementLane_pieceMinimum;
  ::ad::physics::ParametricValue valueSpeed_limitsElementLane_pieceMaximum(0.);
  valueSpeed_limitsElementLane_piece.maximum = valueSpeed_limitsElementLane_pieceMaximum;
  valueSpeed_limitsElementLane_piece.maximum = valueSpeed_limitsElementLane_piece.minimum;
  valueSpeed_limitsElementLane_piece.minimum = valueSpeed_limitsElementLane_piece.maximum;
  valueSpeed_limitsElement.lane_piece = valueSpeed_limitsElementLane_piece;
  valueSpeed_limits.resize(1, valueSpeed_limitsElement);
  value.speed_limits = valueSpeed_limits;
  ::ad::map::point::Geometry valueEdge_left;
  bool valueEdge_leftIs_valid{true};
  valueEdge_left.is_valid = valueEdge_leftIs_valid;
  bool valueEdge_leftIs_closed{true};
  valueEdge_left.is_closed = valueEdge_leftIs_closed;
  ::ad::map::point::ECEFPointList valueEdge_leftEcef_points;
  ::ad::map::point::ECEFPoint valueEdge_leftEcef_pointsElement;
  ::ad::map::point::ECEFCoordinate valueEdge_leftEcef_pointsElementX(-6400000);
  valueEdge_leftEcef_pointsElement.x = valueEdge_leftEcef_pointsElementX;
  ::ad::map::point::ECEFCoordinate valueEdge_leftEcef_pointsElementY(-6400000);
  valueEdge_leftEcef_pointsElement.y = valueEdge_leftEcef_pointsElementY;
  ::ad::map::point::ECEFCoordinate valueEdge_leftEcef_pointsElementZ(-6400000);
  valueEdge_leftEcef_pointsElement.z = valueEdge_leftEcef_pointsElementZ;
  valueEdge_leftEcef_points.resize(1, valueEdge_leftEcef_pointsElement);
  valueEdge_left.ecef_points = valueEdge_leftEcef_points;
  ::ad::physics::Distance valueEdge_leftLength(-1e9);
  valueEdge_left.length = valueEdge_leftLength;
  ::ad::map::point::ENUPointCache valueEdge_leftPrivate_enu_points_cache;
  ::ad::map::point::ENUPointList valueEdge_leftPrivate_enu_points_cacheEnu_points;
  ::ad::map::point::ENUPoint valueEdge_leftPrivate_enu_points_cacheEnu_pointsElement;
  ::ad::map::point::ENUCoordinate valueEdge_leftPrivate_enu_points_cacheEnu_pointsElementX(-1e8);
  valueEdge_leftPrivate_enu_points_cacheEnu_pointsElement.x = valueEdge_leftPrivate_enu_points_cacheEnu_pointsElementX;
  ::ad::map::point::ENUCoordinate valueEdge_leftPrivate_enu_points_cacheEnu_pointsElementY(-1e8);
  valueEdge_leftPrivate_enu_points_cacheEnu_pointsElement.y = valueEdge_leftPrivate_enu_points_cacheEnu_pointsElementY;
  ::ad::map::point::ENUCoordinate valueEdge_leftPrivate_enu_points_cacheEnu_pointsElementZ(-1e8);
  valueEdge_leftPrivate_enu_points_cacheEnu_pointsElement.z = valueEdge_leftPrivate_enu_points_cacheEnu_pointsElementZ;
  valueEdge_leftPrivate_enu_points_cacheEnu_points.resize(1, valueEdge_leftPrivate_enu_points_cacheEnu_pointsElement);
  valueEdge_leftPrivate_enu_points_cache.enu_points = valueEdge_leftPrivate_enu_points_cacheEnu_points;
  uint64_t valueEdge_leftPrivate_enu_points_cacheEnu_version{std::numeric_limits<uint64_t>::min()};
  valueEdge_leftPrivate_enu_points_cache.enu_version = valueEdge_leftPrivate_enu_points_cacheEnu_version;
  valueEdge_left.private_enu_points_cache = valueEdge_leftPrivate_enu_points_cache;
  value.edge_left = valueEdge_left;
  ::ad::map::point::Geometry valueEdge_right;
  bool valueEdge_rightIs_valid{true};
  valueEdge_right.is_valid = valueEdge_rightIs_valid;
  bool valueEdge_rightIs_closed{true};
  valueEdge_right.is_closed = valueEdge_rightIs_closed;
  ::ad::map::point::ECEFPointList valueEdge_rightEcef_points;
  ::ad::map::point::ECEFPoint valueEdge_rightEcef_pointsElement;
  ::ad::map::point::ECEFCoordinate valueEdge_rightEcef_pointsElementX(-6400000);
  valueEdge_rightEcef_pointsElement.x = valueEdge_rightEcef_pointsElementX;
  ::ad::map::point::ECEFCoordinate valueEdge_rightEcef_pointsElementY(-6400000);
  valueEdge_rightEcef_pointsElement.y = valueEdge_rightEcef_pointsElementY;
  ::ad::map::point::ECEFCoordinate valueEdge_rightEcef_pointsElementZ(-6400000);
  valueEdge_rightEcef_pointsElement.z = valueEdge_rightEcef_pointsElementZ;
  valueEdge_rightEcef_points.resize(1, valueEdge_rightEcef_pointsElement);
  valueEdge_right.ecef_points = valueEdge_rightEcef_points;
  ::ad::physics::Distance valueEdge_rightLength(-1e9);
  valueEdge_right.length = valueEdge_rightLength;
  ::ad::map::point::ENUPointCache valueEdge_rightPrivate_enu_points_cache;
  ::ad::map::point::ENUPointList valueEdge_rightPrivate_enu_points_cacheEnu_points;
  ::ad::map::point::ENUPoint valueEdge_rightPrivate_enu_points_cacheEnu_pointsElement;
  ::ad::map::point::ENUCoordinate valueEdge_rightPrivate_enu_points_cacheEnu_pointsElementX(-1e8);
  valueEdge_rightPrivate_enu_points_cacheEnu_pointsElement.x
    = valueEdge_rightPrivate_enu_points_cacheEnu_pointsElementX;
  ::ad::map::point::ENUCoordinate valueEdge_rightPrivate_enu_points_cacheEnu_pointsElementY(-1e8);
  valueEdge_rightPrivate_enu_points_cacheEnu_pointsElement.y
    = valueEdge_rightPrivate_enu_points_cacheEnu_pointsElementY;
  ::ad::map::point::ENUCoordinate valueEdge_rightPrivate_enu_points_cacheEnu_pointsElementZ(-1e8);
  valueEdge_rightPrivate_enu_points_cacheEnu_pointsElement.z
    = valueEdge_rightPrivate_enu_points_cacheEnu_pointsElementZ;
  valueEdge_rightPrivate_enu_points_cacheEnu_points.resize(1, valueEdge_rightPrivate_enu_points_cacheEnu_pointsElement);
  valueEdge_rightPrivate_enu_points_cache.enu_points = valueEdge_rightPrivate_enu_points_cacheEnu_points;
  uint64_t valueEdge_rightPrivate_enu_points_cacheEnu_version{std::numeric_limits<uint64_t>::min()};
  valueEdge_rightPrivate_enu_points_cache.enu_version = valueEdge_rightPrivate_enu_points_cacheEnu_version;
  valueEdge_right.private_enu_points_cache = valueEdge_rightPrivate_enu_points_cache;
  value.edge_right = valueEdge_right;
  ::ad::map::lane::ContactLaneList valueContact_lanes;
  ::ad::map::lane::ContactLane valueContact_lanesElement;
  ::ad::map::lane::LaneId valueContact_lanesElementTo_lane(1);
  valueContact_lanesElement.to_lane = valueContact_lanesElementTo_lane;
  ::ad::map::lane::ContactLocation valueContact_lanesElementLocation(::ad::map::lane::ContactLocation::INVALID);
  valueContact_lanesElement.location = valueContact_lanesElementLocation;
  ::ad::map::lane::ContactTypeList valueContact_lanesElementTypes;
  ::ad::map::lane::ContactType valueContact_lanesElementTypesElement(::ad::map::lane::ContactType::INVALID);
  valueContact_lanesElementTypes.resize(1, valueContact_lanesElementTypesElement);
  valueContact_lanesElement.types = valueContact_lanesElementTypes;
  ::ad::map::restriction::Restrictions valueContact_lanesElementRestrictions;
  ::ad::map::restriction::RestrictionList valueContact_lanesElementRestrictionsConjunctions;
  ::ad::map::restriction::Restriction valueContact_lanesElementRestrictionsConjunctionsElement;
  bool valueContact_lanesElementRestrictionsConjunctionsElementNegated{true};
  valueContact_lanesElementRestrictionsConjunctionsElement.negated
    = valueContact_lanesElementRestrictionsConjunctionsElementNegated;
  ::ad::map::restriction::RoadUserTypeList valueContact_lanesElementRestrictionsConjunctionsElementRoad_user_types;
  ::ad::map::restriction::RoadUserType valueContact_lanesElementRestrictionsConjunctionsElementRoad_user_typesElement(
    ::ad::map::restriction::RoadUserType::INVALID);
  valueContact_lanesElementRestrictionsConjunctionsElementRoad_user_types.resize(
    1, valueContact_lanesElementRestrictionsConjunctionsElementRoad_user_typesElement);
  valueContact_lanesElementRestrictionsConjunctionsElement.road_user_types
    = valueContact_lanesElementRestrictionsConjunctionsElementRoad_user_types;
  ::ad::map::restriction::PassengerCount valueContact_lanesElementRestrictionsConjunctionsElementPassengers_min(
    std::numeric_limits<::ad::map::restriction::PassengerCount>::lowest());
  valueContact_lanesElementRestrictionsConjunctionsElement.passengers_min
    = valueContact_lanesElementRestrictionsConjunctionsElementPassengers_min;
  valueContact_lanesElementRestrictionsConjunctions.resize(1, valueContact_lanesElementRestrictionsConjunctionsElement);
  valueContact_lanesElementRestrictions.conjunctions = valueContact_lanesElementRestrictionsConjunctions;
  ::ad::map::restriction::RestrictionList valueContact_lanesElementRestrictionsDisjunctions;
  ::ad::map::restriction::Restriction valueContact_lanesElementRestrictionsDisjunctionsElement;
  bool valueContact_lanesElementRestrictionsDisjunctionsElementNegated{true};
  valueContact_lanesElementRestrictionsDisjunctionsElement.negated
    = valueContact_lanesElementRestrictionsDisjunctionsElementNegated;
  ::ad::map::restriction::RoadUserTypeList valueContact_lanesElementRestrictionsDisjunctionsElementRoad_user_types;
  ::ad::map::restriction::RoadUserType valueContact_lanesElementRestrictionsDisjunctionsElementRoad_user_typesElement(
    ::ad::map::restriction::RoadUserType::INVALID);
  valueContact_lanesElementRestrictionsDisjunctionsElementRoad_user_types.resize(
    1, valueContact_lanesElementRestrictionsDisjunctionsElementRoad_user_typesElement);
  valueContact_lanesElementRestrictionsDisjunctionsElement.road_user_types
    = valueContact_lanesElementRestrictionsDisjunctionsElementRoad_user_types;
  ::ad::map::restriction::PassengerCount valueContact_lanesElementRestrictionsDisjunctionsElementPassengers_min(
    std::numeric_limits<::ad::map::restriction::PassengerCount>::lowest());
  valueContact_lanesElementRestrictionsDisjunctionsElement.passengers_min
    = valueContact_lanesElementRestrictionsDisjunctionsElementPassengers_min;
  valueContact_lanesElementRestrictionsDisjunctions.resize(1, valueContact_lanesElementRestrictionsDisjunctionsElement);
  valueContact_lanesElementRestrictions.disjunctions = valueContact_lanesElementRestrictionsDisjunctions;
  valueContact_lanesElement.restrictions = valueContact_lanesElementRestrictions;
  ::ad::map::landmark::LandmarkId valueContact_lanesElementLandmark_id(
    std::numeric_limits<::ad::map::landmark::LandmarkId>::lowest());
  valueContact_lanesElement.landmark_id = valueContact_lanesElementLandmark_id;
  valueContact_lanes.resize(1, valueContact_lanesElement);
  value.contact_lanes = valueContact_lanes;
  ::ad::map::lane::ComplianceVersion valueCompliance_version(
    std::numeric_limits<::ad::map::lane::ComplianceVersion>::lowest());
  value.compliance_version = valueCompliance_version;
  ::ad::map::point::BoundingSphere valueBounding_sphere;
  ::ad::map::point::ECEFPoint valueBounding_sphereCenter;
  ::ad::map::point::ECEFCoordinate valueBounding_sphereCenterX(-6400000);
  valueBounding_sphereCenter.x = valueBounding_sphereCenterX;
  ::ad::map::point::ECEFCoordinate valueBounding_sphereCenterY(-6400000);
  valueBounding_sphereCenter.y = valueBounding_sphereCenterY;
  ::ad::map::point::ECEFCoordinate valueBounding_sphereCenterZ(-6400000);
  valueBounding_sphereCenter.z = valueBounding_sphereCenterZ;
  valueBounding_sphere.center = valueBounding_sphereCenter;
  ::ad::physics::Distance valueBounding_sphereRadius(-1e9);
  valueBounding_sphere.radius = valueBounding_sphereRadius;
  value.bounding_sphere = valueBounding_sphere;
  ::ad::map::landmark::LandmarkIdList valueVisible_landmarks;
  ::ad::map::landmark::LandmarkId valueVisible_landmarksElement(
    std::numeric_limits<::ad::map::landmark::LandmarkId>::lowest());
  valueVisible_landmarks.resize(1, valueVisible_landmarksElement);
  value.visible_landmarks = valueVisible_landmarks;

  // override member with data type value above input range maximum
  ::ad::map::lane::LaneType invalidInitializedMember(static_cast<::ad::map::lane::LaneType>(-1));
  value.type = invalidInitializedMember;
  ASSERT_FALSE(withinValidInputRange(value));
}

TEST(LaneValidInputRangeTests, testValidInputRangeDirectionTooSmall)
{
  ::ad::map::lane::Lane value;
  ::ad::map::lane::LaneId valueId(1);
  value.id = valueId;
  ::ad::map::lane::LaneType valueType(::ad::map::lane::LaneType::INVALID);
  value.type = valueType;
  ::ad::map::lane::LaneDirection valueDirection(::ad::map::lane::LaneDirection::INVALID);
  value.direction = valueDirection;
  ::ad::map::restriction::Restrictions valueRestrictions;
  ::ad::map::restriction::RestrictionList valueRestrictionsConjunctions;
  ::ad::map::restriction::Restriction valueRestrictionsConjunctionsElement;
  bool valueRestrictionsConjunctionsElementNegated{true};
  valueRestrictionsConjunctionsElement.negated = valueRestrictionsConjunctionsElementNegated;
  ::ad::map::restriction::RoadUserTypeList valueRestrictionsConjunctionsElementRoad_user_types;
  ::ad::map::restriction::RoadUserType valueRestrictionsConjunctionsElementRoad_user_typesElement(
    ::ad::map::restriction::RoadUserType::INVALID);
  valueRestrictionsConjunctionsElementRoad_user_types.resize(
    1, valueRestrictionsConjunctionsElementRoad_user_typesElement);
  valueRestrictionsConjunctionsElement.road_user_types = valueRestrictionsConjunctionsElementRoad_user_types;
  ::ad::map::restriction::PassengerCount valueRestrictionsConjunctionsElementPassengers_min(
    std::numeric_limits<::ad::map::restriction::PassengerCount>::lowest());
  valueRestrictionsConjunctionsElement.passengers_min = valueRestrictionsConjunctionsElementPassengers_min;
  valueRestrictionsConjunctions.resize(1, valueRestrictionsConjunctionsElement);
  valueRestrictions.conjunctions = valueRestrictionsConjunctions;
  ::ad::map::restriction::RestrictionList valueRestrictionsDisjunctions;
  ::ad::map::restriction::Restriction valueRestrictionsDisjunctionsElement;
  bool valueRestrictionsDisjunctionsElementNegated{true};
  valueRestrictionsDisjunctionsElement.negated = valueRestrictionsDisjunctionsElementNegated;
  ::ad::map::restriction::RoadUserTypeList valueRestrictionsDisjunctionsElementRoad_user_types;
  ::ad::map::restriction::RoadUserType valueRestrictionsDisjunctionsElementRoad_user_typesElement(
    ::ad::map::restriction::RoadUserType::INVALID);
  valueRestrictionsDisjunctionsElementRoad_user_types.resize(
    1, valueRestrictionsDisjunctionsElementRoad_user_typesElement);
  valueRestrictionsDisjunctionsElement.road_user_types = valueRestrictionsDisjunctionsElementRoad_user_types;
  ::ad::map::restriction::PassengerCount valueRestrictionsDisjunctionsElementPassengers_min(
    std::numeric_limits<::ad::map::restriction::PassengerCount>::lowest());
  valueRestrictionsDisjunctionsElement.passengers_min = valueRestrictionsDisjunctionsElementPassengers_min;
  valueRestrictionsDisjunctions.resize(1, valueRestrictionsDisjunctionsElement);
  valueRestrictions.disjunctions = valueRestrictionsDisjunctions;
  value.restrictions = valueRestrictions;
  ::ad::physics::Distance valueLength(-1e9);
  value.length = valueLength;
  ::ad::physics::MetricRange valueLength_range;
  ::ad::physics::Distance valueLength_rangeMinimum(-1e9);
  valueLength_rangeMinimum = ::ad::physics::Distance(0.); // set to valid value within struct
  valueLength_range.minimum = valueLength_rangeMinimum;
  ::ad::physics::Distance valueLength_rangeMaximum(-1e9);
  valueLength_range.maximum = valueLength_rangeMaximum;
  valueLength_range.maximum = valueLength_range.minimum;
  valueLength_range.minimum = valueLength_range.maximum;
  value.length_range = valueLength_range;
  ::ad::physics::Distance valueWidth(-1e9);
  value.width = valueWidth;
  ::ad::physics::MetricRange valueWidth_range;
  ::ad::physics::Distance valueWidth_rangeMinimum(-1e9);
  valueWidth_rangeMinimum = ::ad::physics::Distance(0.); // set to valid value within struct
  valueWidth_range.minimum = valueWidth_rangeMinimum;
  ::ad::physics::Distance valueWidth_rangeMaximum(-1e9);
  valueWidth_range.maximum = valueWidth_rangeMaximum;
  valueWidth_range.maximum = valueWidth_range.minimum;
  valueWidth_range.minimum = valueWidth_range.maximum;
  value.width_range = valueWidth_range;
  ::ad::map::restriction::SpeedLimitList valueSpeed_limits;
  ::ad::map::restriction::SpeedLimit valueSpeed_limitsElement;
  ::ad::physics::Speed valueSpeed_limitsElementSpeed_limit(-100.);
  valueSpeed_limitsElement.speed_limit = valueSpeed_limitsElementSpeed_limit;
  ::ad::physics::ParametricRange valueSpeed_limitsElementLane_piece;
  ::ad::physics::ParametricValue valueSpeed_limitsElementLane_pieceMinimum(0.);
  valueSpeed_limitsElementLane_piece.minimum = valueSpeed_limitsElementLane_pieceMinimum;
  ::ad::physics::ParametricValue valueSpeed_limitsElementLane_pieceMaximum(0.);
  valueSpeed_limitsElementLane_piece.maximum = valueSpeed_limitsElementLane_pieceMaximum;
  valueSpeed_limitsElementLane_piece.maximum = valueSpeed_limitsElementLane_piece.minimum;
  valueSpeed_limitsElementLane_piece.minimum = valueSpeed_limitsElementLane_piece.maximum;
  valueSpeed_limitsElement.lane_piece = valueSpeed_limitsElementLane_piece;
  valueSpeed_limits.resize(1, valueSpeed_limitsElement);
  value.speed_limits = valueSpeed_limits;
  ::ad::map::point::Geometry valueEdge_left;
  bool valueEdge_leftIs_valid{true};
  valueEdge_left.is_valid = valueEdge_leftIs_valid;
  bool valueEdge_leftIs_closed{true};
  valueEdge_left.is_closed = valueEdge_leftIs_closed;
  ::ad::map::point::ECEFPointList valueEdge_leftEcef_points;
  ::ad::map::point::ECEFPoint valueEdge_leftEcef_pointsElement;
  ::ad::map::point::ECEFCoordinate valueEdge_leftEcef_pointsElementX(-6400000);
  valueEdge_leftEcef_pointsElement.x = valueEdge_leftEcef_pointsElementX;
  ::ad::map::point::ECEFCoordinate valueEdge_leftEcef_pointsElementY(-6400000);
  valueEdge_leftEcef_pointsElement.y = valueEdge_leftEcef_pointsElementY;
  ::ad::map::point::ECEFCoordinate valueEdge_leftEcef_pointsElementZ(-6400000);
  valueEdge_leftEcef_pointsElement.z = valueEdge_leftEcef_pointsElementZ;
  valueEdge_leftEcef_points.resize(1, valueEdge_leftEcef_pointsElement);
  valueEdge_left.ecef_points = valueEdge_leftEcef_points;
  ::ad::physics::Distance valueEdge_leftLength(-1e9);
  valueEdge_left.length = valueEdge_leftLength;
  ::ad::map::point::ENUPointCache valueEdge_leftPrivate_enu_points_cache;
  ::ad::map::point::ENUPointList valueEdge_leftPrivate_enu_points_cacheEnu_points;
  ::ad::map::point::ENUPoint valueEdge_leftPrivate_enu_points_cacheEnu_pointsElement;
  ::ad::map::point::ENUCoordinate valueEdge_leftPrivate_enu_points_cacheEnu_pointsElementX(-1e8);
  valueEdge_leftPrivate_enu_points_cacheEnu_pointsElement.x = valueEdge_leftPrivate_enu_points_cacheEnu_pointsElementX;
  ::ad::map::point::ENUCoordinate valueEdge_leftPrivate_enu_points_cacheEnu_pointsElementY(-1e8);
  valueEdge_leftPrivate_enu_points_cacheEnu_pointsElement.y = valueEdge_leftPrivate_enu_points_cacheEnu_pointsElementY;
  ::ad::map::point::ENUCoordinate valueEdge_leftPrivate_enu_points_cacheEnu_pointsElementZ(-1e8);
  valueEdge_leftPrivate_enu_points_cacheEnu_pointsElement.z = valueEdge_leftPrivate_enu_points_cacheEnu_pointsElementZ;
  valueEdge_leftPrivate_enu_points_cacheEnu_points.resize(1, valueEdge_leftPrivate_enu_points_cacheEnu_pointsElement);
  valueEdge_leftPrivate_enu_points_cache.enu_points = valueEdge_leftPrivate_enu_points_cacheEnu_points;
  uint64_t valueEdge_leftPrivate_enu_points_cacheEnu_version{std::numeric_limits<uint64_t>::min()};
  valueEdge_leftPrivate_enu_points_cache.enu_version = valueEdge_leftPrivate_enu_points_cacheEnu_version;
  valueEdge_left.private_enu_points_cache = valueEdge_leftPrivate_enu_points_cache;
  value.edge_left = valueEdge_left;
  ::ad::map::point::Geometry valueEdge_right;
  bool valueEdge_rightIs_valid{true};
  valueEdge_right.is_valid = valueEdge_rightIs_valid;
  bool valueEdge_rightIs_closed{true};
  valueEdge_right.is_closed = valueEdge_rightIs_closed;
  ::ad::map::point::ECEFPointList valueEdge_rightEcef_points;
  ::ad::map::point::ECEFPoint valueEdge_rightEcef_pointsElement;
  ::ad::map::point::ECEFCoordinate valueEdge_rightEcef_pointsElementX(-6400000);
  valueEdge_rightEcef_pointsElement.x = valueEdge_rightEcef_pointsElementX;
  ::ad::map::point::ECEFCoordinate valueEdge_rightEcef_pointsElementY(-6400000);
  valueEdge_rightEcef_pointsElement.y = valueEdge_rightEcef_pointsElementY;
  ::ad::map::point::ECEFCoordinate valueEdge_rightEcef_pointsElementZ(-6400000);
  valueEdge_rightEcef_pointsElement.z = valueEdge_rightEcef_pointsElementZ;
  valueEdge_rightEcef_points.resize(1, valueEdge_rightEcef_pointsElement);
  valueEdge_right.ecef_points = valueEdge_rightEcef_points;
  ::ad::physics::Distance valueEdge_rightLength(-1e9);
  valueEdge_right.length = valueEdge_rightLength;
  ::ad::map::point::ENUPointCache valueEdge_rightPrivate_enu_points_cache;
  ::ad::map::point::ENUPointList valueEdge_rightPrivate_enu_points_cacheEnu_points;
  ::ad::map::point::ENUPoint valueEdge_rightPrivate_enu_points_cacheEnu_pointsElement;
  ::ad::map::point::ENUCoordinate valueEdge_rightPrivate_enu_points_cacheEnu_pointsElementX(-1e8);
  valueEdge_rightPrivate_enu_points_cacheEnu_pointsElement.x
    = valueEdge_rightPrivate_enu_points_cacheEnu_pointsElementX;
  ::ad::map::point::ENUCoordinate valueEdge_rightPrivate_enu_points_cacheEnu_pointsElementY(-1e8);
  valueEdge_rightPrivate_enu_points_cacheEnu_pointsElement.y
    = valueEdge_rightPrivate_enu_points_cacheEnu_pointsElementY;
  ::ad::map::point::ENUCoordinate valueEdge_rightPrivate_enu_points_cacheEnu_pointsElementZ(-1e8);
  valueEdge_rightPrivate_enu_points_cacheEnu_pointsElement.z
    = valueEdge_rightPrivate_enu_points_cacheEnu_pointsElementZ;
  valueEdge_rightPrivate_enu_points_cacheEnu_points.resize(1, valueEdge_rightPrivate_enu_points_cacheEnu_pointsElement);
  valueEdge_rightPrivate_enu_points_cache.enu_points = valueEdge_rightPrivate_enu_points_cacheEnu_points;
  uint64_t valueEdge_rightPrivate_enu_points_cacheEnu_version{std::numeric_limits<uint64_t>::min()};
  valueEdge_rightPrivate_enu_points_cache.enu_version = valueEdge_rightPrivate_enu_points_cacheEnu_version;
  valueEdge_right.private_enu_points_cache = valueEdge_rightPrivate_enu_points_cache;
  value.edge_right = valueEdge_right;
  ::ad::map::lane::ContactLaneList valueContact_lanes;
  ::ad::map::lane::ContactLane valueContact_lanesElement;
  ::ad::map::lane::LaneId valueContact_lanesElementTo_lane(1);
  valueContact_lanesElement.to_lane = valueContact_lanesElementTo_lane;
  ::ad::map::lane::ContactLocation valueContact_lanesElementLocation(::ad::map::lane::ContactLocation::INVALID);
  valueContact_lanesElement.location = valueContact_lanesElementLocation;
  ::ad::map::lane::ContactTypeList valueContact_lanesElementTypes;
  ::ad::map::lane::ContactType valueContact_lanesElementTypesElement(::ad::map::lane::ContactType::INVALID);
  valueContact_lanesElementTypes.resize(1, valueContact_lanesElementTypesElement);
  valueContact_lanesElement.types = valueContact_lanesElementTypes;
  ::ad::map::restriction::Restrictions valueContact_lanesElementRestrictions;
  ::ad::map::restriction::RestrictionList valueContact_lanesElementRestrictionsConjunctions;
  ::ad::map::restriction::Restriction valueContact_lanesElementRestrictionsConjunctionsElement;
  bool valueContact_lanesElementRestrictionsConjunctionsElementNegated{true};
  valueContact_lanesElementRestrictionsConjunctionsElement.negated
    = valueContact_lanesElementRestrictionsConjunctionsElementNegated;
  ::ad::map::restriction::RoadUserTypeList valueContact_lanesElementRestrictionsConjunctionsElementRoad_user_types;
  ::ad::map::restriction::RoadUserType valueContact_lanesElementRestrictionsConjunctionsElementRoad_user_typesElement(
    ::ad::map::restriction::RoadUserType::INVALID);
  valueContact_lanesElementRestrictionsConjunctionsElementRoad_user_types.resize(
    1, valueContact_lanesElementRestrictionsConjunctionsElementRoad_user_typesElement);
  valueContact_lanesElementRestrictionsConjunctionsElement.road_user_types
    = valueContact_lanesElementRestrictionsConjunctionsElementRoad_user_types;
  ::ad::map::restriction::PassengerCount valueContact_lanesElementRestrictionsConjunctionsElementPassengers_min(
    std::numeric_limits<::ad::map::restriction::PassengerCount>::lowest());
  valueContact_lanesElementRestrictionsConjunctionsElement.passengers_min
    = valueContact_lanesElementRestrictionsConjunctionsElementPassengers_min;
  valueContact_lanesElementRestrictionsConjunctions.resize(1, valueContact_lanesElementRestrictionsConjunctionsElement);
  valueContact_lanesElementRestrictions.conjunctions = valueContact_lanesElementRestrictionsConjunctions;
  ::ad::map::restriction::RestrictionList valueContact_lanesElementRestrictionsDisjunctions;
  ::ad::map::restriction::Restriction valueContact_lanesElementRestrictionsDisjunctionsElement;
  bool valueContact_lanesElementRestrictionsDisjunctionsElementNegated{true};
  valueContact_lanesElementRestrictionsDisjunctionsElement.negated
    = valueContact_lanesElementRestrictionsDisjunctionsElementNegated;
  ::ad::map::restriction::RoadUserTypeList valueContact_lanesElementRestrictionsDisjunctionsElementRoad_user_types;
  ::ad::map::restriction::RoadUserType valueContact_lanesElementRestrictionsDisjunctionsElementRoad_user_typesElement(
    ::ad::map::restriction::RoadUserType::INVALID);
  valueContact_lanesElementRestrictionsDisjunctionsElementRoad_user_types.resize(
    1, valueContact_lanesElementRestrictionsDisjunctionsElementRoad_user_typesElement);
  valueContact_lanesElementRestrictionsDisjunctionsElement.road_user_types
    = valueContact_lanesElementRestrictionsDisjunctionsElementRoad_user_types;
  ::ad::map::restriction::PassengerCount valueContact_lanesElementRestrictionsDisjunctionsElementPassengers_min(
    std::numeric_limits<::ad::map::restriction::PassengerCount>::lowest());
  valueContact_lanesElementRestrictionsDisjunctionsElement.passengers_min
    = valueContact_lanesElementRestrictionsDisjunctionsElementPassengers_min;
  valueContact_lanesElementRestrictionsDisjunctions.resize(1, valueContact_lanesElementRestrictionsDisjunctionsElement);
  valueContact_lanesElementRestrictions.disjunctions = valueContact_lanesElementRestrictionsDisjunctions;
  valueContact_lanesElement.restrictions = valueContact_lanesElementRestrictions;
  ::ad::map::landmark::LandmarkId valueContact_lanesElementLandmark_id(
    std::numeric_limits<::ad::map::landmark::LandmarkId>::lowest());
  valueContact_lanesElement.landmark_id = valueContact_lanesElementLandmark_id;
  valueContact_lanes.resize(1, valueContact_lanesElement);
  value.contact_lanes = valueContact_lanes;
  ::ad::map::lane::ComplianceVersion valueCompliance_version(
    std::numeric_limits<::ad::map::lane::ComplianceVersion>::lowest());
  value.compliance_version = valueCompliance_version;
  ::ad::map::point::BoundingSphere valueBounding_sphere;
  ::ad::map::point::ECEFPoint valueBounding_sphereCenter;
  ::ad::map::point::ECEFCoordinate valueBounding_sphereCenterX(-6400000);
  valueBounding_sphereCenter.x = valueBounding_sphereCenterX;
  ::ad::map::point::ECEFCoordinate valueBounding_sphereCenterY(-6400000);
  valueBounding_sphereCenter.y = valueBounding_sphereCenterY;
  ::ad::map::point::ECEFCoordinate valueBounding_sphereCenterZ(-6400000);
  valueBounding_sphereCenter.z = valueBounding_sphereCenterZ;
  valueBounding_sphere.center = valueBounding_sphereCenter;
  ::ad::physics::Distance valueBounding_sphereRadius(-1e9);
  valueBounding_sphere.radius = valueBounding_sphereRadius;
  value.bounding_sphere = valueBounding_sphere;
  ::ad::map::landmark::LandmarkIdList valueVisible_landmarks;
  ::ad::map::landmark::LandmarkId valueVisible_landmarksElement(
    std::numeric_limits<::ad::map::landmark::LandmarkId>::lowest());
  valueVisible_landmarks.resize(1, valueVisible_landmarksElement);
  value.visible_landmarks = valueVisible_landmarks;

  // override member with data type value below input range minimum
  ::ad::map::lane::LaneDirection invalidInitializedMember(static_cast<::ad::map::lane::LaneDirection>(-1));
  value.direction = invalidInitializedMember;
  ASSERT_FALSE(withinValidInputRange(value));
}

TEST(LaneValidInputRangeTests, testValidInputRangeDirectionTooBig)
{
  ::ad::map::lane::Lane value;
  ::ad::map::lane::LaneId valueId(1);
  value.id = valueId;
  ::ad::map::lane::LaneType valueType(::ad::map::lane::LaneType::INVALID);
  value.type = valueType;
  ::ad::map::lane::LaneDirection valueDirection(::ad::map::lane::LaneDirection::INVALID);
  value.direction = valueDirection;
  ::ad::map::restriction::Restrictions valueRestrictions;
  ::ad::map::restriction::RestrictionList valueRestrictionsConjunctions;
  ::ad::map::restriction::Restriction valueRestrictionsConjunctionsElement;
  bool valueRestrictionsConjunctionsElementNegated{true};
  valueRestrictionsConjunctionsElement.negated = valueRestrictionsConjunctionsElementNegated;
  ::ad::map::restriction::RoadUserTypeList valueRestrictionsConjunctionsElementRoad_user_types;
  ::ad::map::restriction::RoadUserType valueRestrictionsConjunctionsElementRoad_user_typesElement(
    ::ad::map::restriction::RoadUserType::INVALID);
  valueRestrictionsConjunctionsElementRoad_user_types.resize(
    1, valueRestrictionsConjunctionsElementRoad_user_typesElement);
  valueRestrictionsConjunctionsElement.road_user_types = valueRestrictionsConjunctionsElementRoad_user_types;
  ::ad::map::restriction::PassengerCount valueRestrictionsConjunctionsElementPassengers_min(
    std::numeric_limits<::ad::map::restriction::PassengerCount>::lowest());
  valueRestrictionsConjunctionsElement.passengers_min = valueRestrictionsConjunctionsElementPassengers_min;
  valueRestrictionsConjunctions.resize(1, valueRestrictionsConjunctionsElement);
  valueRestrictions.conjunctions = valueRestrictionsConjunctions;
  ::ad::map::restriction::RestrictionList valueRestrictionsDisjunctions;
  ::ad::map::restriction::Restriction valueRestrictionsDisjunctionsElement;
  bool valueRestrictionsDisjunctionsElementNegated{true};
  valueRestrictionsDisjunctionsElement.negated = valueRestrictionsDisjunctionsElementNegated;
  ::ad::map::restriction::RoadUserTypeList valueRestrictionsDisjunctionsElementRoad_user_types;
  ::ad::map::restriction::RoadUserType valueRestrictionsDisjunctionsElementRoad_user_typesElement(
    ::ad::map::restriction::RoadUserType::INVALID);
  valueRestrictionsDisjunctionsElementRoad_user_types.resize(
    1, valueRestrictionsDisjunctionsElementRoad_user_typesElement);
  valueRestrictionsDisjunctionsElement.road_user_types = valueRestrictionsDisjunctionsElementRoad_user_types;
  ::ad::map::restriction::PassengerCount valueRestrictionsDisjunctionsElementPassengers_min(
    std::numeric_limits<::ad::map::restriction::PassengerCount>::lowest());
  valueRestrictionsDisjunctionsElement.passengers_min = valueRestrictionsDisjunctionsElementPassengers_min;
  valueRestrictionsDisjunctions.resize(1, valueRestrictionsDisjunctionsElement);
  valueRestrictions.disjunctions = valueRestrictionsDisjunctions;
  value.restrictions = valueRestrictions;
  ::ad::physics::Distance valueLength(-1e9);
  value.length = valueLength;
  ::ad::physics::MetricRange valueLength_range;
  ::ad::physics::Distance valueLength_rangeMinimum(-1e9);
  valueLength_rangeMinimum = ::ad::physics::Distance(0.); // set to valid value within struct
  valueLength_range.minimum = valueLength_rangeMinimum;
  ::ad::physics::Distance valueLength_rangeMaximum(-1e9);
  valueLength_range.maximum = valueLength_rangeMaximum;
  valueLength_range.maximum = valueLength_range.minimum;
  valueLength_range.minimum = valueLength_range.maximum;
  value.length_range = valueLength_range;
  ::ad::physics::Distance valueWidth(-1e9);
  value.width = valueWidth;
  ::ad::physics::MetricRange valueWidth_range;
  ::ad::physics::Distance valueWidth_rangeMinimum(-1e9);
  valueWidth_rangeMinimum = ::ad::physics::Distance(0.); // set to valid value within struct
  valueWidth_range.minimum = valueWidth_rangeMinimum;
  ::ad::physics::Distance valueWidth_rangeMaximum(-1e9);
  valueWidth_range.maximum = valueWidth_rangeMaximum;
  valueWidth_range.maximum = valueWidth_range.minimum;
  valueWidth_range.minimum = valueWidth_range.maximum;
  value.width_range = valueWidth_range;
  ::ad::map::restriction::SpeedLimitList valueSpeed_limits;
  ::ad::map::restriction::SpeedLimit valueSpeed_limitsElement;
  ::ad::physics::Speed valueSpeed_limitsElementSpeed_limit(-100.);
  valueSpeed_limitsElement.speed_limit = valueSpeed_limitsElementSpeed_limit;
  ::ad::physics::ParametricRange valueSpeed_limitsElementLane_piece;
  ::ad::physics::ParametricValue valueSpeed_limitsElementLane_pieceMinimum(0.);
  valueSpeed_limitsElementLane_piece.minimum = valueSpeed_limitsElementLane_pieceMinimum;
  ::ad::physics::ParametricValue valueSpeed_limitsElementLane_pieceMaximum(0.);
  valueSpeed_limitsElementLane_piece.maximum = valueSpeed_limitsElementLane_pieceMaximum;
  valueSpeed_limitsElementLane_piece.maximum = valueSpeed_limitsElementLane_piece.minimum;
  valueSpeed_limitsElementLane_piece.minimum = valueSpeed_limitsElementLane_piece.maximum;
  valueSpeed_limitsElement.lane_piece = valueSpeed_limitsElementLane_piece;
  valueSpeed_limits.resize(1, valueSpeed_limitsElement);
  value.speed_limits = valueSpeed_limits;
  ::ad::map::point::Geometry valueEdge_left;
  bool valueEdge_leftIs_valid{true};
  valueEdge_left.is_valid = valueEdge_leftIs_valid;
  bool valueEdge_leftIs_closed{true};
  valueEdge_left.is_closed = valueEdge_leftIs_closed;
  ::ad::map::point::ECEFPointList valueEdge_leftEcef_points;
  ::ad::map::point::ECEFPoint valueEdge_leftEcef_pointsElement;
  ::ad::map::point::ECEFCoordinate valueEdge_leftEcef_pointsElementX(-6400000);
  valueEdge_leftEcef_pointsElement.x = valueEdge_leftEcef_pointsElementX;
  ::ad::map::point::ECEFCoordinate valueEdge_leftEcef_pointsElementY(-6400000);
  valueEdge_leftEcef_pointsElement.y = valueEdge_leftEcef_pointsElementY;
  ::ad::map::point::ECEFCoordinate valueEdge_leftEcef_pointsElementZ(-6400000);
  valueEdge_leftEcef_pointsElement.z = valueEdge_leftEcef_pointsElementZ;
  valueEdge_leftEcef_points.resize(1, valueEdge_leftEcef_pointsElement);
  valueEdge_left.ecef_points = valueEdge_leftEcef_points;
  ::ad::physics::Distance valueEdge_leftLength(-1e9);
  valueEdge_left.length = valueEdge_leftLength;
  ::ad::map::point::ENUPointCache valueEdge_leftPrivate_enu_points_cache;
  ::ad::map::point::ENUPointList valueEdge_leftPrivate_enu_points_cacheEnu_points;
  ::ad::map::point::ENUPoint valueEdge_leftPrivate_enu_points_cacheEnu_pointsElement;
  ::ad::map::point::ENUCoordinate valueEdge_leftPrivate_enu_points_cacheEnu_pointsElementX(-1e8);
  valueEdge_leftPrivate_enu_points_cacheEnu_pointsElement.x = valueEdge_leftPrivate_enu_points_cacheEnu_pointsElementX;
  ::ad::map::point::ENUCoordinate valueEdge_leftPrivate_enu_points_cacheEnu_pointsElementY(-1e8);
  valueEdge_leftPrivate_enu_points_cacheEnu_pointsElement.y = valueEdge_leftPrivate_enu_points_cacheEnu_pointsElementY;
  ::ad::map::point::ENUCoordinate valueEdge_leftPrivate_enu_points_cacheEnu_pointsElementZ(-1e8);
  valueEdge_leftPrivate_enu_points_cacheEnu_pointsElement.z = valueEdge_leftPrivate_enu_points_cacheEnu_pointsElementZ;
  valueEdge_leftPrivate_enu_points_cacheEnu_points.resize(1, valueEdge_leftPrivate_enu_points_cacheEnu_pointsElement);
  valueEdge_leftPrivate_enu_points_cache.enu_points = valueEdge_leftPrivate_enu_points_cacheEnu_points;
  uint64_t valueEdge_leftPrivate_enu_points_cacheEnu_version{std::numeric_limits<uint64_t>::min()};
  valueEdge_leftPrivate_enu_points_cache.enu_version = valueEdge_leftPrivate_enu_points_cacheEnu_version;
  valueEdge_left.private_enu_points_cache = valueEdge_leftPrivate_enu_points_cache;
  value.edge_left = valueEdge_left;
  ::ad::map::point::Geometry valueEdge_right;
  bool valueEdge_rightIs_valid{true};
  valueEdge_right.is_valid = valueEdge_rightIs_valid;
  bool valueEdge_rightIs_closed{true};
  valueEdge_right.is_closed = valueEdge_rightIs_closed;
  ::ad::map::point::ECEFPointList valueEdge_rightEcef_points;
  ::ad::map::point::ECEFPoint valueEdge_rightEcef_pointsElement;
  ::ad::map::point::ECEFCoordinate valueEdge_rightEcef_pointsElementX(-6400000);
  valueEdge_rightEcef_pointsElement.x = valueEdge_rightEcef_pointsElementX;
  ::ad::map::point::ECEFCoordinate valueEdge_rightEcef_pointsElementY(-6400000);
  valueEdge_rightEcef_pointsElement.y = valueEdge_rightEcef_pointsElementY;
  ::ad::map::point::ECEFCoordinate valueEdge_rightEcef_pointsElementZ(-6400000);
  valueEdge_rightEcef_pointsElement.z = valueEdge_rightEcef_pointsElementZ;
  valueEdge_rightEcef_points.resize(1, valueEdge_rightEcef_pointsElement);
  valueEdge_right.ecef_points = valueEdge_rightEcef_points;
  ::ad::physics::Distance valueEdge_rightLength(-1e9);
  valueEdge_right.length = valueEdge_rightLength;
  ::ad::map::point::ENUPointCache valueEdge_rightPrivate_enu_points_cache;
  ::ad::map::point::ENUPointList valueEdge_rightPrivate_enu_points_cacheEnu_points;
  ::ad::map::point::ENUPoint valueEdge_rightPrivate_enu_points_cacheEnu_pointsElement;
  ::ad::map::point::ENUCoordinate valueEdge_rightPrivate_enu_points_cacheEnu_pointsElementX(-1e8);
  valueEdge_rightPrivate_enu_points_cacheEnu_pointsElement.x
    = valueEdge_rightPrivate_enu_points_cacheEnu_pointsElementX;
  ::ad::map::point::ENUCoordinate valueEdge_rightPrivate_enu_points_cacheEnu_pointsElementY(-1e8);
  valueEdge_rightPrivate_enu_points_cacheEnu_pointsElement.y
    = valueEdge_rightPrivate_enu_points_cacheEnu_pointsElementY;
  ::ad::map::point::ENUCoordinate valueEdge_rightPrivate_enu_points_cacheEnu_pointsElementZ(-1e8);
  valueEdge_rightPrivate_enu_points_cacheEnu_pointsElement.z
    = valueEdge_rightPrivate_enu_points_cacheEnu_pointsElementZ;
  valueEdge_rightPrivate_enu_points_cacheEnu_points.resize(1, valueEdge_rightPrivate_enu_points_cacheEnu_pointsElement);
  valueEdge_rightPrivate_enu_points_cache.enu_points = valueEdge_rightPrivate_enu_points_cacheEnu_points;
  uint64_t valueEdge_rightPrivate_enu_points_cacheEnu_version{std::numeric_limits<uint64_t>::min()};
  valueEdge_rightPrivate_enu_points_cache.enu_version = valueEdge_rightPrivate_enu_points_cacheEnu_version;
  valueEdge_right.private_enu_points_cache = valueEdge_rightPrivate_enu_points_cache;
  value.edge_right = valueEdge_right;
  ::ad::map::lane::ContactLaneList valueContact_lanes;
  ::ad::map::lane::ContactLane valueContact_lanesElement;
  ::ad::map::lane::LaneId valueContact_lanesElementTo_lane(1);
  valueContact_lanesElement.to_lane = valueContact_lanesElementTo_lane;
  ::ad::map::lane::ContactLocation valueContact_lanesElementLocation(::ad::map::lane::ContactLocation::INVALID);
  valueContact_lanesElement.location = valueContact_lanesElementLocation;
  ::ad::map::lane::ContactTypeList valueContact_lanesElementTypes;
  ::ad::map::lane::ContactType valueContact_lanesElementTypesElement(::ad::map::lane::ContactType::INVALID);
  valueContact_lanesElementTypes.resize(1, valueContact_lanesElementTypesElement);
  valueContact_lanesElement.types = valueContact_lanesElementTypes;
  ::ad::map::restriction::Restrictions valueContact_lanesElementRestrictions;
  ::ad::map::restriction::RestrictionList valueContact_lanesElementRestrictionsConjunctions;
  ::ad::map::restriction::Restriction valueContact_lanesElementRestrictionsConjunctionsElement;
  bool valueContact_lanesElementRestrictionsConjunctionsElementNegated{true};
  valueContact_lanesElementRestrictionsConjunctionsElement.negated
    = valueContact_lanesElementRestrictionsConjunctionsElementNegated;
  ::ad::map::restriction::RoadUserTypeList valueContact_lanesElementRestrictionsConjunctionsElementRoad_user_types;
  ::ad::map::restriction::RoadUserType valueContact_lanesElementRestrictionsConjunctionsElementRoad_user_typesElement(
    ::ad::map::restriction::RoadUserType::INVALID);
  valueContact_lanesElementRestrictionsConjunctionsElementRoad_user_types.resize(
    1, valueContact_lanesElementRestrictionsConjunctionsElementRoad_user_typesElement);
  valueContact_lanesElementRestrictionsConjunctionsElement.road_user_types
    = valueContact_lanesElementRestrictionsConjunctionsElementRoad_user_types;
  ::ad::map::restriction::PassengerCount valueContact_lanesElementRestrictionsConjunctionsElementPassengers_min(
    std::numeric_limits<::ad::map::restriction::PassengerCount>::lowest());
  valueContact_lanesElementRestrictionsConjunctionsElement.passengers_min
    = valueContact_lanesElementRestrictionsConjunctionsElementPassengers_min;
  valueContact_lanesElementRestrictionsConjunctions.resize(1, valueContact_lanesElementRestrictionsConjunctionsElement);
  valueContact_lanesElementRestrictions.conjunctions = valueContact_lanesElementRestrictionsConjunctions;
  ::ad::map::restriction::RestrictionList valueContact_lanesElementRestrictionsDisjunctions;
  ::ad::map::restriction::Restriction valueContact_lanesElementRestrictionsDisjunctionsElement;
  bool valueContact_lanesElementRestrictionsDisjunctionsElementNegated{true};
  valueContact_lanesElementRestrictionsDisjunctionsElement.negated
    = valueContact_lanesElementRestrictionsDisjunctionsElementNegated;
  ::ad::map::restriction::RoadUserTypeList valueContact_lanesElementRestrictionsDisjunctionsElementRoad_user_types;
  ::ad::map::restriction::RoadUserType valueContact_lanesElementRestrictionsDisjunctionsElementRoad_user_typesElement(
    ::ad::map::restriction::RoadUserType::INVALID);
  valueContact_lanesElementRestrictionsDisjunctionsElementRoad_user_types.resize(
    1, valueContact_lanesElementRestrictionsDisjunctionsElementRoad_user_typesElement);
  valueContact_lanesElementRestrictionsDisjunctionsElement.road_user_types
    = valueContact_lanesElementRestrictionsDisjunctionsElementRoad_user_types;
  ::ad::map::restriction::PassengerCount valueContact_lanesElementRestrictionsDisjunctionsElementPassengers_min(
    std::numeric_limits<::ad::map::restriction::PassengerCount>::lowest());
  valueContact_lanesElementRestrictionsDisjunctionsElement.passengers_min
    = valueContact_lanesElementRestrictionsDisjunctionsElementPassengers_min;
  valueContact_lanesElementRestrictionsDisjunctions.resize(1, valueContact_lanesElementRestrictionsDisjunctionsElement);
  valueContact_lanesElementRestrictions.disjunctions = valueContact_lanesElementRestrictionsDisjunctions;
  valueContact_lanesElement.restrictions = valueContact_lanesElementRestrictions;
  ::ad::map::landmark::LandmarkId valueContact_lanesElementLandmark_id(
    std::numeric_limits<::ad::map::landmark::LandmarkId>::lowest());
  valueContact_lanesElement.landmark_id = valueContact_lanesElementLandmark_id;
  valueContact_lanes.resize(1, valueContact_lanesElement);
  value.contact_lanes = valueContact_lanes;
  ::ad::map::lane::ComplianceVersion valueCompliance_version(
    std::numeric_limits<::ad::map::lane::ComplianceVersion>::lowest());
  value.compliance_version = valueCompliance_version;
  ::ad::map::point::BoundingSphere valueBounding_sphere;
  ::ad::map::point::ECEFPoint valueBounding_sphereCenter;
  ::ad::map::point::ECEFCoordinate valueBounding_sphereCenterX(-6400000);
  valueBounding_sphereCenter.x = valueBounding_sphereCenterX;
  ::ad::map::point::ECEFCoordinate valueBounding_sphereCenterY(-6400000);
  valueBounding_sphereCenter.y = valueBounding_sphereCenterY;
  ::ad::map::point::ECEFCoordinate valueBounding_sphereCenterZ(-6400000);
  valueBounding_sphereCenter.z = valueBounding_sphereCenterZ;
  valueBounding_sphere.center = valueBounding_sphereCenter;
  ::ad::physics::Distance valueBounding_sphereRadius(-1e9);
  valueBounding_sphere.radius = valueBounding_sphereRadius;
  value.bounding_sphere = valueBounding_sphere;
  ::ad::map::landmark::LandmarkIdList valueVisible_landmarks;
  ::ad::map::landmark::LandmarkId valueVisible_landmarksElement(
    std::numeric_limits<::ad::map::landmark::LandmarkId>::lowest());
  valueVisible_landmarks.resize(1, valueVisible_landmarksElement);
  value.visible_landmarks = valueVisible_landmarks;

  // override member with data type value above input range maximum
  ::ad::map::lane::LaneDirection invalidInitializedMember(static_cast<::ad::map::lane::LaneDirection>(-1));
  value.direction = invalidInitializedMember;
  ASSERT_FALSE(withinValidInputRange(value));
}

TEST(LaneValidInputRangeTests, testValidInputRangeLengthTooSmall)
{
  ::ad::map::lane::Lane value;
  ::ad::map::lane::LaneId valueId(1);
  value.id = valueId;
  ::ad::map::lane::LaneType valueType(::ad::map::lane::LaneType::INVALID);
  value.type = valueType;
  ::ad::map::lane::LaneDirection valueDirection(::ad::map::lane::LaneDirection::INVALID);
  value.direction = valueDirection;
  ::ad::map::restriction::Restrictions valueRestrictions;
  ::ad::map::restriction::RestrictionList valueRestrictionsConjunctions;
  ::ad::map::restriction::Restriction valueRestrictionsConjunctionsElement;
  bool valueRestrictionsConjunctionsElementNegated{true};
  valueRestrictionsConjunctionsElement.negated = valueRestrictionsConjunctionsElementNegated;
  ::ad::map::restriction::RoadUserTypeList valueRestrictionsConjunctionsElementRoad_user_types;
  ::ad::map::restriction::RoadUserType valueRestrictionsConjunctionsElementRoad_user_typesElement(
    ::ad::map::restriction::RoadUserType::INVALID);
  valueRestrictionsConjunctionsElementRoad_user_types.resize(
    1, valueRestrictionsConjunctionsElementRoad_user_typesElement);
  valueRestrictionsConjunctionsElement.road_user_types = valueRestrictionsConjunctionsElementRoad_user_types;
  ::ad::map::restriction::PassengerCount valueRestrictionsConjunctionsElementPassengers_min(
    std::numeric_limits<::ad::map::restriction::PassengerCount>::lowest());
  valueRestrictionsConjunctionsElement.passengers_min = valueRestrictionsConjunctionsElementPassengers_min;
  valueRestrictionsConjunctions.resize(1, valueRestrictionsConjunctionsElement);
  valueRestrictions.conjunctions = valueRestrictionsConjunctions;
  ::ad::map::restriction::RestrictionList valueRestrictionsDisjunctions;
  ::ad::map::restriction::Restriction valueRestrictionsDisjunctionsElement;
  bool valueRestrictionsDisjunctionsElementNegated{true};
  valueRestrictionsDisjunctionsElement.negated = valueRestrictionsDisjunctionsElementNegated;
  ::ad::map::restriction::RoadUserTypeList valueRestrictionsDisjunctionsElementRoad_user_types;
  ::ad::map::restriction::RoadUserType valueRestrictionsDisjunctionsElementRoad_user_typesElement(
    ::ad::map::restriction::RoadUserType::INVALID);
  valueRestrictionsDisjunctionsElementRoad_user_types.resize(
    1, valueRestrictionsDisjunctionsElementRoad_user_typesElement);
  valueRestrictionsDisjunctionsElement.road_user_types = valueRestrictionsDisjunctionsElementRoad_user_types;
  ::ad::map::restriction::PassengerCount valueRestrictionsDisjunctionsElementPassengers_min(
    std::numeric_limits<::ad::map::restriction::PassengerCount>::lowest());
  valueRestrictionsDisjunctionsElement.passengers_min = valueRestrictionsDisjunctionsElementPassengers_min;
  valueRestrictionsDisjunctions.resize(1, valueRestrictionsDisjunctionsElement);
  valueRestrictions.disjunctions = valueRestrictionsDisjunctions;
  value.restrictions = valueRestrictions;
  ::ad::physics::Distance valueLength(-1e9);
  value.length = valueLength;
  ::ad::physics::MetricRange valueLength_range;
  ::ad::physics::Distance valueLength_rangeMinimum(-1e9);
  valueLength_rangeMinimum = ::ad::physics::Distance(0.); // set to valid value within struct
  valueLength_range.minimum = valueLength_rangeMinimum;
  ::ad::physics::Distance valueLength_rangeMaximum(-1e9);
  valueLength_range.maximum = valueLength_rangeMaximum;
  valueLength_range.maximum = valueLength_range.minimum;
  valueLength_range.minimum = valueLength_range.maximum;
  value.length_range = valueLength_range;
  ::ad::physics::Distance valueWidth(-1e9);
  value.width = valueWidth;
  ::ad::physics::MetricRange valueWidth_range;
  ::ad::physics::Distance valueWidth_rangeMinimum(-1e9);
  valueWidth_rangeMinimum = ::ad::physics::Distance(0.); // set to valid value within struct
  valueWidth_range.minimum = valueWidth_rangeMinimum;
  ::ad::physics::Distance valueWidth_rangeMaximum(-1e9);
  valueWidth_range.maximum = valueWidth_rangeMaximum;
  valueWidth_range.maximum = valueWidth_range.minimum;
  valueWidth_range.minimum = valueWidth_range.maximum;
  value.width_range = valueWidth_range;
  ::ad::map::restriction::SpeedLimitList valueSpeed_limits;
  ::ad::map::restriction::SpeedLimit valueSpeed_limitsElement;
  ::ad::physics::Speed valueSpeed_limitsElementSpeed_limit(-100.);
  valueSpeed_limitsElement.speed_limit = valueSpeed_limitsElementSpeed_limit;
  ::ad::physics::ParametricRange valueSpeed_limitsElementLane_piece;
  ::ad::physics::ParametricValue valueSpeed_limitsElementLane_pieceMinimum(0.);
  valueSpeed_limitsElementLane_piece.minimum = valueSpeed_limitsElementLane_pieceMinimum;
  ::ad::physics::ParametricValue valueSpeed_limitsElementLane_pieceMaximum(0.);
  valueSpeed_limitsElementLane_piece.maximum = valueSpeed_limitsElementLane_pieceMaximum;
  valueSpeed_limitsElementLane_piece.maximum = valueSpeed_limitsElementLane_piece.minimum;
  valueSpeed_limitsElementLane_piece.minimum = valueSpeed_limitsElementLane_piece.maximum;
  valueSpeed_limitsElement.lane_piece = valueSpeed_limitsElementLane_piece;
  valueSpeed_limits.resize(1, valueSpeed_limitsElement);
  value.speed_limits = valueSpeed_limits;
  ::ad::map::point::Geometry valueEdge_left;
  bool valueEdge_leftIs_valid{true};
  valueEdge_left.is_valid = valueEdge_leftIs_valid;
  bool valueEdge_leftIs_closed{true};
  valueEdge_left.is_closed = valueEdge_leftIs_closed;
  ::ad::map::point::ECEFPointList valueEdge_leftEcef_points;
  ::ad::map::point::ECEFPoint valueEdge_leftEcef_pointsElement;
  ::ad::map::point::ECEFCoordinate valueEdge_leftEcef_pointsElementX(-6400000);
  valueEdge_leftEcef_pointsElement.x = valueEdge_leftEcef_pointsElementX;
  ::ad::map::point::ECEFCoordinate valueEdge_leftEcef_pointsElementY(-6400000);
  valueEdge_leftEcef_pointsElement.y = valueEdge_leftEcef_pointsElementY;
  ::ad::map::point::ECEFCoordinate valueEdge_leftEcef_pointsElementZ(-6400000);
  valueEdge_leftEcef_pointsElement.z = valueEdge_leftEcef_pointsElementZ;
  valueEdge_leftEcef_points.resize(1, valueEdge_leftEcef_pointsElement);
  valueEdge_left.ecef_points = valueEdge_leftEcef_points;
  ::ad::physics::Distance valueEdge_leftLength(-1e9);
  valueEdge_left.length = valueEdge_leftLength;
  ::ad::map::point::ENUPointCache valueEdge_leftPrivate_enu_points_cache;
  ::ad::map::point::ENUPointList valueEdge_leftPrivate_enu_points_cacheEnu_points;
  ::ad::map::point::ENUPoint valueEdge_leftPrivate_enu_points_cacheEnu_pointsElement;
  ::ad::map::point::ENUCoordinate valueEdge_leftPrivate_enu_points_cacheEnu_pointsElementX(-1e8);
  valueEdge_leftPrivate_enu_points_cacheEnu_pointsElement.x = valueEdge_leftPrivate_enu_points_cacheEnu_pointsElementX;
  ::ad::map::point::ENUCoordinate valueEdge_leftPrivate_enu_points_cacheEnu_pointsElementY(-1e8);
  valueEdge_leftPrivate_enu_points_cacheEnu_pointsElement.y = valueEdge_leftPrivate_enu_points_cacheEnu_pointsElementY;
  ::ad::map::point::ENUCoordinate valueEdge_leftPrivate_enu_points_cacheEnu_pointsElementZ(-1e8);
  valueEdge_leftPrivate_enu_points_cacheEnu_pointsElement.z = valueEdge_leftPrivate_enu_points_cacheEnu_pointsElementZ;
  valueEdge_leftPrivate_enu_points_cacheEnu_points.resize(1, valueEdge_leftPrivate_enu_points_cacheEnu_pointsElement);
  valueEdge_leftPrivate_enu_points_cache.enu_points = valueEdge_leftPrivate_enu_points_cacheEnu_points;
  uint64_t valueEdge_leftPrivate_enu_points_cacheEnu_version{std::numeric_limits<uint64_t>::min()};
  valueEdge_leftPrivate_enu_points_cache.enu_version = valueEdge_leftPrivate_enu_points_cacheEnu_version;
  valueEdge_left.private_enu_points_cache = valueEdge_leftPrivate_enu_points_cache;
  value.edge_left = valueEdge_left;
  ::ad::map::point::Geometry valueEdge_right;
  bool valueEdge_rightIs_valid{true};
  valueEdge_right.is_valid = valueEdge_rightIs_valid;
  bool valueEdge_rightIs_closed{true};
  valueEdge_right.is_closed = valueEdge_rightIs_closed;
  ::ad::map::point::ECEFPointList valueEdge_rightEcef_points;
  ::ad::map::point::ECEFPoint valueEdge_rightEcef_pointsElement;
  ::ad::map::point::ECEFCoordinate valueEdge_rightEcef_pointsElementX(-6400000);
  valueEdge_rightEcef_pointsElement.x = valueEdge_rightEcef_pointsElementX;
  ::ad::map::point::ECEFCoordinate valueEdge_rightEcef_pointsElementY(-6400000);
  valueEdge_rightEcef_pointsElement.y = valueEdge_rightEcef_pointsElementY;
  ::ad::map::point::ECEFCoordinate valueEdge_rightEcef_pointsElementZ(-6400000);
  valueEdge_rightEcef_pointsElement.z = valueEdge_rightEcef_pointsElementZ;
  valueEdge_rightEcef_points.resize(1, valueEdge_rightEcef_pointsElement);
  valueEdge_right.ecef_points = valueEdge_rightEcef_points;
  ::ad::physics::Distance valueEdge_rightLength(-1e9);
  valueEdge_right.length = valueEdge_rightLength;
  ::ad::map::point::ENUPointCache valueEdge_rightPrivate_enu_points_cache;
  ::ad::map::point::ENUPointList valueEdge_rightPrivate_enu_points_cacheEnu_points;
  ::ad::map::point::ENUPoint valueEdge_rightPrivate_enu_points_cacheEnu_pointsElement;
  ::ad::map::point::ENUCoordinate valueEdge_rightPrivate_enu_points_cacheEnu_pointsElementX(-1e8);
  valueEdge_rightPrivate_enu_points_cacheEnu_pointsElement.x
    = valueEdge_rightPrivate_enu_points_cacheEnu_pointsElementX;
  ::ad::map::point::ENUCoordinate valueEdge_rightPrivate_enu_points_cacheEnu_pointsElementY(-1e8);
  valueEdge_rightPrivate_enu_points_cacheEnu_pointsElement.y
    = valueEdge_rightPrivate_enu_points_cacheEnu_pointsElementY;
  ::ad::map::point::ENUCoordinate valueEdge_rightPrivate_enu_points_cacheEnu_pointsElementZ(-1e8);
  valueEdge_rightPrivate_enu_points_cacheEnu_pointsElement.z
    = valueEdge_rightPrivate_enu_points_cacheEnu_pointsElementZ;
  valueEdge_rightPrivate_enu_points_cacheEnu_points.resize(1, valueEdge_rightPrivate_enu_points_cacheEnu_pointsElement);
  valueEdge_rightPrivate_enu_points_cache.enu_points = valueEdge_rightPrivate_enu_points_cacheEnu_points;
  uint64_t valueEdge_rightPrivate_enu_points_cacheEnu_version{std::numeric_limits<uint64_t>::min()};
  valueEdge_rightPrivate_enu_points_cache.enu_version = valueEdge_rightPrivate_enu_points_cacheEnu_version;
  valueEdge_right.private_enu_points_cache = valueEdge_rightPrivate_enu_points_cache;
  value.edge_right = valueEdge_right;
  ::ad::map::lane::ContactLaneList valueContact_lanes;
  ::ad::map::lane::ContactLane valueContact_lanesElement;
  ::ad::map::lane::LaneId valueContact_lanesElementTo_lane(1);
  valueContact_lanesElement.to_lane = valueContact_lanesElementTo_lane;
  ::ad::map::lane::ContactLocation valueContact_lanesElementLocation(::ad::map::lane::ContactLocation::INVALID);
  valueContact_lanesElement.location = valueContact_lanesElementLocation;
  ::ad::map::lane::ContactTypeList valueContact_lanesElementTypes;
  ::ad::map::lane::ContactType valueContact_lanesElementTypesElement(::ad::map::lane::ContactType::INVALID);
  valueContact_lanesElementTypes.resize(1, valueContact_lanesElementTypesElement);
  valueContact_lanesElement.types = valueContact_lanesElementTypes;
  ::ad::map::restriction::Restrictions valueContact_lanesElementRestrictions;
  ::ad::map::restriction::RestrictionList valueContact_lanesElementRestrictionsConjunctions;
  ::ad::map::restriction::Restriction valueContact_lanesElementRestrictionsConjunctionsElement;
  bool valueContact_lanesElementRestrictionsConjunctionsElementNegated{true};
  valueContact_lanesElementRestrictionsConjunctionsElement.negated
    = valueContact_lanesElementRestrictionsConjunctionsElementNegated;
  ::ad::map::restriction::RoadUserTypeList valueContact_lanesElementRestrictionsConjunctionsElementRoad_user_types;
  ::ad::map::restriction::RoadUserType valueContact_lanesElementRestrictionsConjunctionsElementRoad_user_typesElement(
    ::ad::map::restriction::RoadUserType::INVALID);
  valueContact_lanesElementRestrictionsConjunctionsElementRoad_user_types.resize(
    1, valueContact_lanesElementRestrictionsConjunctionsElementRoad_user_typesElement);
  valueContact_lanesElementRestrictionsConjunctionsElement.road_user_types
    = valueContact_lanesElementRestrictionsConjunctionsElementRoad_user_types;
  ::ad::map::restriction::PassengerCount valueContact_lanesElementRestrictionsConjunctionsElementPassengers_min(
    std::numeric_limits<::ad::map::restriction::PassengerCount>::lowest());
  valueContact_lanesElementRestrictionsConjunctionsElement.passengers_min
    = valueContact_lanesElementRestrictionsConjunctionsElementPassengers_min;
  valueContact_lanesElementRestrictionsConjunctions.resize(1, valueContact_lanesElementRestrictionsConjunctionsElement);
  valueContact_lanesElementRestrictions.conjunctions = valueContact_lanesElementRestrictionsConjunctions;
  ::ad::map::restriction::RestrictionList valueContact_lanesElementRestrictionsDisjunctions;
  ::ad::map::restriction::Restriction valueContact_lanesElementRestrictionsDisjunctionsElement;
  bool valueContact_lanesElementRestrictionsDisjunctionsElementNegated{true};
  valueContact_lanesElementRestrictionsDisjunctionsElement.negated
    = valueContact_lanesElementRestrictionsDisjunctionsElementNegated;
  ::ad::map::restriction::RoadUserTypeList valueContact_lanesElementRestrictionsDisjunctionsElementRoad_user_types;
  ::ad::map::restriction::RoadUserType valueContact_lanesElementRestrictionsDisjunctionsElementRoad_user_typesElement(
    ::ad::map::restriction::RoadUserType::INVALID);
  valueContact_lanesElementRestrictionsDisjunctionsElementRoad_user_types.resize(
    1, valueContact_lanesElementRestrictionsDisjunctionsElementRoad_user_typesElement);
  valueContact_lanesElementRestrictionsDisjunctionsElement.road_user_types
    = valueContact_lanesElementRestrictionsDisjunctionsElementRoad_user_types;
  ::ad::map::restriction::PassengerCount valueContact_lanesElementRestrictionsDisjunctionsElementPassengers_min(
    std::numeric_limits<::ad::map::restriction::PassengerCount>::lowest());
  valueContact_lanesElementRestrictionsDisjunctionsElement.passengers_min
    = valueContact_lanesElementRestrictionsDisjunctionsElementPassengers_min;
  valueContact_lanesElementRestrictionsDisjunctions.resize(1, valueContact_lanesElementRestrictionsDisjunctionsElement);
  valueContact_lanesElementRestrictions.disjunctions = valueContact_lanesElementRestrictionsDisjunctions;
  valueContact_lanesElement.restrictions = valueContact_lanesElementRestrictions;
  ::ad::map::landmark::LandmarkId valueContact_lanesElementLandmark_id(
    std::numeric_limits<::ad::map::landmark::LandmarkId>::lowest());
  valueContact_lanesElement.landmark_id = valueContact_lanesElementLandmark_id;
  valueContact_lanes.resize(1, valueContact_lanesElement);
  value.contact_lanes = valueContact_lanes;
  ::ad::map::lane::ComplianceVersion valueCompliance_version(
    std::numeric_limits<::ad::map::lane::ComplianceVersion>::lowest());
  value.compliance_version = valueCompliance_version;
  ::ad::map::point::BoundingSphere valueBounding_sphere;
  ::ad::map::point::ECEFPoint valueBounding_sphereCenter;
  ::ad::map::point::ECEFCoordinate valueBounding_sphereCenterX(-6400000);
  valueBounding_sphereCenter.x = valueBounding_sphereCenterX;
  ::ad::map::point::ECEFCoordinate valueBounding_sphereCenterY(-6400000);
  valueBounding_sphereCenter.y = valueBounding_sphereCenterY;
  ::ad::map::point::ECEFCoordinate valueBounding_sphereCenterZ(-6400000);
  valueBounding_sphereCenter.z = valueBounding_sphereCenterZ;
  valueBounding_sphere.center = valueBounding_sphereCenter;
  ::ad::physics::Distance valueBounding_sphereRadius(-1e9);
  valueBounding_sphere.radius = valueBounding_sphereRadius;
  value.bounding_sphere = valueBounding_sphere;
  ::ad::map::landmark::LandmarkIdList valueVisible_landmarks;
  ::ad::map::landmark::LandmarkId valueVisible_landmarksElement(
    std::numeric_limits<::ad::map::landmark::LandmarkId>::lowest());
  valueVisible_landmarks.resize(1, valueVisible_landmarksElement);
  value.visible_landmarks = valueVisible_landmarks;

  // override member with data type value below input range minimum
  ::ad::physics::Distance invalidInitializedMember(-1e9 * 1.1);
  value.length = invalidInitializedMember;
  ASSERT_FALSE(withinValidInputRange(value));
}

TEST(LaneValidInputRangeTests, testValidInputRangeLengthTooBig)
{
  ::ad::map::lane::Lane value;
  ::ad::map::lane::LaneId valueId(1);
  value.id = valueId;
  ::ad::map::lane::LaneType valueType(::ad::map::lane::LaneType::INVALID);
  value.type = valueType;
  ::ad::map::lane::LaneDirection valueDirection(::ad::map::lane::LaneDirection::INVALID);
  value.direction = valueDirection;
  ::ad::map::restriction::Restrictions valueRestrictions;
  ::ad::map::restriction::RestrictionList valueRestrictionsConjunctions;
  ::ad::map::restriction::Restriction valueRestrictionsConjunctionsElement;
  bool valueRestrictionsConjunctionsElementNegated{true};
  valueRestrictionsConjunctionsElement.negated = valueRestrictionsConjunctionsElementNegated;
  ::ad::map::restriction::RoadUserTypeList valueRestrictionsConjunctionsElementRoad_user_types;
  ::ad::map::restriction::RoadUserType valueRestrictionsConjunctionsElementRoad_user_typesElement(
    ::ad::map::restriction::RoadUserType::INVALID);
  valueRestrictionsConjunctionsElementRoad_user_types.resize(
    1, valueRestrictionsConjunctionsElementRoad_user_typesElement);
  valueRestrictionsConjunctionsElement.road_user_types = valueRestrictionsConjunctionsElementRoad_user_types;
  ::ad::map::restriction::PassengerCount valueRestrictionsConjunctionsElementPassengers_min(
    std::numeric_limits<::ad::map::restriction::PassengerCount>::lowest());
  valueRestrictionsConjunctionsElement.passengers_min = valueRestrictionsConjunctionsElementPassengers_min;
  valueRestrictionsConjunctions.resize(1, valueRestrictionsConjunctionsElement);
  valueRestrictions.conjunctions = valueRestrictionsConjunctions;
  ::ad::map::restriction::RestrictionList valueRestrictionsDisjunctions;
  ::ad::map::restriction::Restriction valueRestrictionsDisjunctionsElement;
  bool valueRestrictionsDisjunctionsElementNegated{true};
  valueRestrictionsDisjunctionsElement.negated = valueRestrictionsDisjunctionsElementNegated;
  ::ad::map::restriction::RoadUserTypeList valueRestrictionsDisjunctionsElementRoad_user_types;
  ::ad::map::restriction::RoadUserType valueRestrictionsDisjunctionsElementRoad_user_typesElement(
    ::ad::map::restriction::RoadUserType::INVALID);
  valueRestrictionsDisjunctionsElementRoad_user_types.resize(
    1, valueRestrictionsDisjunctionsElementRoad_user_typesElement);
  valueRestrictionsDisjunctionsElement.road_user_types = valueRestrictionsDisjunctionsElementRoad_user_types;
  ::ad::map::restriction::PassengerCount valueRestrictionsDisjunctionsElementPassengers_min(
    std::numeric_limits<::ad::map::restriction::PassengerCount>::lowest());
  valueRestrictionsDisjunctionsElement.passengers_min = valueRestrictionsDisjunctionsElementPassengers_min;
  valueRestrictionsDisjunctions.resize(1, valueRestrictionsDisjunctionsElement);
  valueRestrictions.disjunctions = valueRestrictionsDisjunctions;
  value.restrictions = valueRestrictions;
  ::ad::physics::Distance valueLength(-1e9);
  value.length = valueLength;
  ::ad::physics::MetricRange valueLength_range;
  ::ad::physics::Distance valueLength_rangeMinimum(-1e9);
  valueLength_rangeMinimum = ::ad::physics::Distance(0.); // set to valid value within struct
  valueLength_range.minimum = valueLength_rangeMinimum;
  ::ad::physics::Distance valueLength_rangeMaximum(-1e9);
  valueLength_range.maximum = valueLength_rangeMaximum;
  valueLength_range.maximum = valueLength_range.minimum;
  valueLength_range.minimum = valueLength_range.maximum;
  value.length_range = valueLength_range;
  ::ad::physics::Distance valueWidth(-1e9);
  value.width = valueWidth;
  ::ad::physics::MetricRange valueWidth_range;
  ::ad::physics::Distance valueWidth_rangeMinimum(-1e9);
  valueWidth_rangeMinimum = ::ad::physics::Distance(0.); // set to valid value within struct
  valueWidth_range.minimum = valueWidth_rangeMinimum;
  ::ad::physics::Distance valueWidth_rangeMaximum(-1e9);
  valueWidth_range.maximum = valueWidth_rangeMaximum;
  valueWidth_range.maximum = valueWidth_range.minimum;
  valueWidth_range.minimum = valueWidth_range.maximum;
  value.width_range = valueWidth_range;
  ::ad::map::restriction::SpeedLimitList valueSpeed_limits;
  ::ad::map::restriction::SpeedLimit valueSpeed_limitsElement;
  ::ad::physics::Speed valueSpeed_limitsElementSpeed_limit(-100.);
  valueSpeed_limitsElement.speed_limit = valueSpeed_limitsElementSpeed_limit;
  ::ad::physics::ParametricRange valueSpeed_limitsElementLane_piece;
  ::ad::physics::ParametricValue valueSpeed_limitsElementLane_pieceMinimum(0.);
  valueSpeed_limitsElementLane_piece.minimum = valueSpeed_limitsElementLane_pieceMinimum;
  ::ad::physics::ParametricValue valueSpeed_limitsElementLane_pieceMaximum(0.);
  valueSpeed_limitsElementLane_piece.maximum = valueSpeed_limitsElementLane_pieceMaximum;
  valueSpeed_limitsElementLane_piece.maximum = valueSpeed_limitsElementLane_piece.minimum;
  valueSpeed_limitsElementLane_piece.minimum = valueSpeed_limitsElementLane_piece.maximum;
  valueSpeed_limitsElement.lane_piece = valueSpeed_limitsElementLane_piece;
  valueSpeed_limits.resize(1, valueSpeed_limitsElement);
  value.speed_limits = valueSpeed_limits;
  ::ad::map::point::Geometry valueEdge_left;
  bool valueEdge_leftIs_valid{true};
  valueEdge_left.is_valid = valueEdge_leftIs_valid;
  bool valueEdge_leftIs_closed{true};
  valueEdge_left.is_closed = valueEdge_leftIs_closed;
  ::ad::map::point::ECEFPointList valueEdge_leftEcef_points;
  ::ad::map::point::ECEFPoint valueEdge_leftEcef_pointsElement;
  ::ad::map::point::ECEFCoordinate valueEdge_leftEcef_pointsElementX(-6400000);
  valueEdge_leftEcef_pointsElement.x = valueEdge_leftEcef_pointsElementX;
  ::ad::map::point::ECEFCoordinate valueEdge_leftEcef_pointsElementY(-6400000);
  valueEdge_leftEcef_pointsElement.y = valueEdge_leftEcef_pointsElementY;
  ::ad::map::point::ECEFCoordinate valueEdge_leftEcef_pointsElementZ(-6400000);
  valueEdge_leftEcef_pointsElement.z = valueEdge_leftEcef_pointsElementZ;
  valueEdge_leftEcef_points.resize(1, valueEdge_leftEcef_pointsElement);
  valueEdge_left.ecef_points = valueEdge_leftEcef_points;
  ::ad::physics::Distance valueEdge_leftLength(-1e9);
  valueEdge_left.length = valueEdge_leftLength;
  ::ad::map::point::ENUPointCache valueEdge_leftPrivate_enu_points_cache;
  ::ad::map::point::ENUPointList valueEdge_leftPrivate_enu_points_cacheEnu_points;
  ::ad::map::point::ENUPoint valueEdge_leftPrivate_enu_points_cacheEnu_pointsElement;
  ::ad::map::point::ENUCoordinate valueEdge_leftPrivate_enu_points_cacheEnu_pointsElementX(-1e8);
  valueEdge_leftPrivate_enu_points_cacheEnu_pointsElement.x = valueEdge_leftPrivate_enu_points_cacheEnu_pointsElementX;
  ::ad::map::point::ENUCoordinate valueEdge_leftPrivate_enu_points_cacheEnu_pointsElementY(-1e8);
  valueEdge_leftPrivate_enu_points_cacheEnu_pointsElement.y = valueEdge_leftPrivate_enu_points_cacheEnu_pointsElementY;
  ::ad::map::point::ENUCoordinate valueEdge_leftPrivate_enu_points_cacheEnu_pointsElementZ(-1e8);
  valueEdge_leftPrivate_enu_points_cacheEnu_pointsElement.z = valueEdge_leftPrivate_enu_points_cacheEnu_pointsElementZ;
  valueEdge_leftPrivate_enu_points_cacheEnu_points.resize(1, valueEdge_leftPrivate_enu_points_cacheEnu_pointsElement);
  valueEdge_leftPrivate_enu_points_cache.enu_points = valueEdge_leftPrivate_enu_points_cacheEnu_points;
  uint64_t valueEdge_leftPrivate_enu_points_cacheEnu_version{std::numeric_limits<uint64_t>::min()};
  valueEdge_leftPrivate_enu_points_cache.enu_version = valueEdge_leftPrivate_enu_points_cacheEnu_version;
  valueEdge_left.private_enu_points_cache = valueEdge_leftPrivate_enu_points_cache;
  value.edge_left = valueEdge_left;
  ::ad::map::point::Geometry valueEdge_right;
  bool valueEdge_rightIs_valid{true};
  valueEdge_right.is_valid = valueEdge_rightIs_valid;
  bool valueEdge_rightIs_closed{true};
  valueEdge_right.is_closed = valueEdge_rightIs_closed;
  ::ad::map::point::ECEFPointList valueEdge_rightEcef_points;
  ::ad::map::point::ECEFPoint valueEdge_rightEcef_pointsElement;
  ::ad::map::point::ECEFCoordinate valueEdge_rightEcef_pointsElementX(-6400000);
  valueEdge_rightEcef_pointsElement.x = valueEdge_rightEcef_pointsElementX;
  ::ad::map::point::ECEFCoordinate valueEdge_rightEcef_pointsElementY(-6400000);
  valueEdge_rightEcef_pointsElement.y = valueEdge_rightEcef_pointsElementY;
  ::ad::map::point::ECEFCoordinate valueEdge_rightEcef_pointsElementZ(-6400000);
  valueEdge_rightEcef_pointsElement.z = valueEdge_rightEcef_pointsElementZ;
  valueEdge_rightEcef_points.resize(1, valueEdge_rightEcef_pointsElement);
  valueEdge_right.ecef_points = valueEdge_rightEcef_points;
  ::ad::physics::Distance valueEdge_rightLength(-1e9);
  valueEdge_right.length = valueEdge_rightLength;
  ::ad::map::point::ENUPointCache valueEdge_rightPrivate_enu_points_cache;
  ::ad::map::point::ENUPointList valueEdge_rightPrivate_enu_points_cacheEnu_points;
  ::ad::map::point::ENUPoint valueEdge_rightPrivate_enu_points_cacheEnu_pointsElement;
  ::ad::map::point::ENUCoordinate valueEdge_rightPrivate_enu_points_cacheEnu_pointsElementX(-1e8);
  valueEdge_rightPrivate_enu_points_cacheEnu_pointsElement.x
    = valueEdge_rightPrivate_enu_points_cacheEnu_pointsElementX;
  ::ad::map::point::ENUCoordinate valueEdge_rightPrivate_enu_points_cacheEnu_pointsElementY(-1e8);
  valueEdge_rightPrivate_enu_points_cacheEnu_pointsElement.y
    = valueEdge_rightPrivate_enu_points_cacheEnu_pointsElementY;
  ::ad::map::point::ENUCoordinate valueEdge_rightPrivate_enu_points_cacheEnu_pointsElementZ(-1e8);
  valueEdge_rightPrivate_enu_points_cacheEnu_pointsElement.z
    = valueEdge_rightPrivate_enu_points_cacheEnu_pointsElementZ;
  valueEdge_rightPrivate_enu_points_cacheEnu_points.resize(1, valueEdge_rightPrivate_enu_points_cacheEnu_pointsElement);
  valueEdge_rightPrivate_enu_points_cache.enu_points = valueEdge_rightPrivate_enu_points_cacheEnu_points;
  uint64_t valueEdge_rightPrivate_enu_points_cacheEnu_version{std::numeric_limits<uint64_t>::min()};
  valueEdge_rightPrivate_enu_points_cache.enu_version = valueEdge_rightPrivate_enu_points_cacheEnu_version;
  valueEdge_right.private_enu_points_cache = valueEdge_rightPrivate_enu_points_cache;
  value.edge_right = valueEdge_right;
  ::ad::map::lane::ContactLaneList valueContact_lanes;
  ::ad::map::lane::ContactLane valueContact_lanesElement;
  ::ad::map::lane::LaneId valueContact_lanesElementTo_lane(1);
  valueContact_lanesElement.to_lane = valueContact_lanesElementTo_lane;
  ::ad::map::lane::ContactLocation valueContact_lanesElementLocation(::ad::map::lane::ContactLocation::INVALID);
  valueContact_lanesElement.location = valueContact_lanesElementLocation;
  ::ad::map::lane::ContactTypeList valueContact_lanesElementTypes;
  ::ad::map::lane::ContactType valueContact_lanesElementTypesElement(::ad::map::lane::ContactType::INVALID);
  valueContact_lanesElementTypes.resize(1, valueContact_lanesElementTypesElement);
  valueContact_lanesElement.types = valueContact_lanesElementTypes;
  ::ad::map::restriction::Restrictions valueContact_lanesElementRestrictions;
  ::ad::map::restriction::RestrictionList valueContact_lanesElementRestrictionsConjunctions;
  ::ad::map::restriction::Restriction valueContact_lanesElementRestrictionsConjunctionsElement;
  bool valueContact_lanesElementRestrictionsConjunctionsElementNegated{true};
  valueContact_lanesElementRestrictionsConjunctionsElement.negated
    = valueContact_lanesElementRestrictionsConjunctionsElementNegated;
  ::ad::map::restriction::RoadUserTypeList valueContact_lanesElementRestrictionsConjunctionsElementRoad_user_types;
  ::ad::map::restriction::RoadUserType valueContact_lanesElementRestrictionsConjunctionsElementRoad_user_typesElement(
    ::ad::map::restriction::RoadUserType::INVALID);
  valueContact_lanesElementRestrictionsConjunctionsElementRoad_user_types.resize(
    1, valueContact_lanesElementRestrictionsConjunctionsElementRoad_user_typesElement);
  valueContact_lanesElementRestrictionsConjunctionsElement.road_user_types
    = valueContact_lanesElementRestrictionsConjunctionsElementRoad_user_types;
  ::ad::map::restriction::PassengerCount valueContact_lanesElementRestrictionsConjunctionsElementPassengers_min(
    std::numeric_limits<::ad::map::restriction::PassengerCount>::lowest());
  valueContact_lanesElementRestrictionsConjunctionsElement.passengers_min
    = valueContact_lanesElementRestrictionsConjunctionsElementPassengers_min;
  valueContact_lanesElementRestrictionsConjunctions.resize(1, valueContact_lanesElementRestrictionsConjunctionsElement);
  valueContact_lanesElementRestrictions.conjunctions = valueContact_lanesElementRestrictionsConjunctions;
  ::ad::map::restriction::RestrictionList valueContact_lanesElementRestrictionsDisjunctions;
  ::ad::map::restriction::Restriction valueContact_lanesElementRestrictionsDisjunctionsElement;
  bool valueContact_lanesElementRestrictionsDisjunctionsElementNegated{true};
  valueContact_lanesElementRestrictionsDisjunctionsElement.negated
    = valueContact_lanesElementRestrictionsDisjunctionsElementNegated;
  ::ad::map::restriction::RoadUserTypeList valueContact_lanesElementRestrictionsDisjunctionsElementRoad_user_types;
  ::ad::map::restriction::RoadUserType valueContact_lanesElementRestrictionsDisjunctionsElementRoad_user_typesElement(
    ::ad::map::restriction::RoadUserType::INVALID);
  valueContact_lanesElementRestrictionsDisjunctionsElementRoad_user_types.resize(
    1, valueContact_lanesElementRestrictionsDisjunctionsElementRoad_user_typesElement);
  valueContact_lanesElementRestrictionsDisjunctionsElement.road_user_types
    = valueContact_lanesElementRestrictionsDisjunctionsElementRoad_user_types;
  ::ad::map::restriction::PassengerCount valueContact_lanesElementRestrictionsDisjunctionsElementPassengers_min(
    std::numeric_limits<::ad::map::restriction::PassengerCount>::lowest());
  valueContact_lanesElementRestrictionsDisjunctionsElement.passengers_min
    = valueContact_lanesElementRestrictionsDisjunctionsElementPassengers_min;
  valueContact_lanesElementRestrictionsDisjunctions.resize(1, valueContact_lanesElementRestrictionsDisjunctionsElement);
  valueContact_lanesElementRestrictions.disjunctions = valueContact_lanesElementRestrictionsDisjunctions;
  valueContact_lanesElement.restrictions = valueContact_lanesElementRestrictions;
  ::ad::map::landmark::LandmarkId valueContact_lanesElementLandmark_id(
    std::numeric_limits<::ad::map::landmark::LandmarkId>::lowest());
  valueContact_lanesElement.landmark_id = valueContact_lanesElementLandmark_id;
  valueContact_lanes.resize(1, valueContact_lanesElement);
  value.contact_lanes = valueContact_lanes;
  ::ad::map::lane::ComplianceVersion valueCompliance_version(
    std::numeric_limits<::ad::map::lane::ComplianceVersion>::lowest());
  value.compliance_version = valueCompliance_version;
  ::ad::map::point::BoundingSphere valueBounding_sphere;
  ::ad::map::point::ECEFPoint valueBounding_sphereCenter;
  ::ad::map::point::ECEFCoordinate valueBounding_sphereCenterX(-6400000);
  valueBounding_sphereCenter.x = valueBounding_sphereCenterX;
  ::ad::map::point::ECEFCoordinate valueBounding_sphereCenterY(-6400000);
  valueBounding_sphereCenter.y = valueBounding_sphereCenterY;
  ::ad::map::point::ECEFCoordinate valueBounding_sphereCenterZ(-6400000);
  valueBounding_sphereCenter.z = valueBounding_sphereCenterZ;
  valueBounding_sphere.center = valueBounding_sphereCenter;
  ::ad::physics::Distance valueBounding_sphereRadius(-1e9);
  valueBounding_sphere.radius = valueBounding_sphereRadius;
  value.bounding_sphere = valueBounding_sphere;
  ::ad::map::landmark::LandmarkIdList valueVisible_landmarks;
  ::ad::map::landmark::LandmarkId valueVisible_landmarksElement(
    std::numeric_limits<::ad::map::landmark::LandmarkId>::lowest());
  valueVisible_landmarks.resize(1, valueVisible_landmarksElement);
  value.visible_landmarks = valueVisible_landmarks;

  // override member with data type value above input range maximum
  ::ad::physics::Distance invalidInitializedMember(1e9 * 1.1);
  value.length = invalidInitializedMember;
  ASSERT_FALSE(withinValidInputRange(value));
}

TEST(LaneValidInputRangeTests, testValidInputRangelengthDefault)
{
  ::ad::map::lane::Lane value;
  ::ad::physics::Distance valueDefault;
  value.length = valueDefault;
  ASSERT_FALSE(withinValidInputRange(value));
}

TEST(LaneValidInputRangeTests, testValidInputRangeLength_rangeTooSmall)
{
  ::ad::map::lane::Lane value;
  ::ad::map::lane::LaneId valueId(1);
  value.id = valueId;
  ::ad::map::lane::LaneType valueType(::ad::map::lane::LaneType::INVALID);
  value.type = valueType;
  ::ad::map::lane::LaneDirection valueDirection(::ad::map::lane::LaneDirection::INVALID);
  value.direction = valueDirection;
  ::ad::map::restriction::Restrictions valueRestrictions;
  ::ad::map::restriction::RestrictionList valueRestrictionsConjunctions;
  ::ad::map::restriction::Restriction valueRestrictionsConjunctionsElement;
  bool valueRestrictionsConjunctionsElementNegated{true};
  valueRestrictionsConjunctionsElement.negated = valueRestrictionsConjunctionsElementNegated;
  ::ad::map::restriction::RoadUserTypeList valueRestrictionsConjunctionsElementRoad_user_types;
  ::ad::map::restriction::RoadUserType valueRestrictionsConjunctionsElementRoad_user_typesElement(
    ::ad::map::restriction::RoadUserType::INVALID);
  valueRestrictionsConjunctionsElementRoad_user_types.resize(
    1, valueRestrictionsConjunctionsElementRoad_user_typesElement);
  valueRestrictionsConjunctionsElement.road_user_types = valueRestrictionsConjunctionsElementRoad_user_types;
  ::ad::map::restriction::PassengerCount valueRestrictionsConjunctionsElementPassengers_min(
    std::numeric_limits<::ad::map::restriction::PassengerCount>::lowest());
  valueRestrictionsConjunctionsElement.passengers_min = valueRestrictionsConjunctionsElementPassengers_min;
  valueRestrictionsConjunctions.resize(1, valueRestrictionsConjunctionsElement);
  valueRestrictions.conjunctions = valueRestrictionsConjunctions;
  ::ad::map::restriction::RestrictionList valueRestrictionsDisjunctions;
  ::ad::map::restriction::Restriction valueRestrictionsDisjunctionsElement;
  bool valueRestrictionsDisjunctionsElementNegated{true};
  valueRestrictionsDisjunctionsElement.negated = valueRestrictionsDisjunctionsElementNegated;
  ::ad::map::restriction::RoadUserTypeList valueRestrictionsDisjunctionsElementRoad_user_types;
  ::ad::map::restriction::RoadUserType valueRestrictionsDisjunctionsElementRoad_user_typesElement(
    ::ad::map::restriction::RoadUserType::INVALID);
  valueRestrictionsDisjunctionsElementRoad_user_types.resize(
    1, valueRestrictionsDisjunctionsElementRoad_user_typesElement);
  valueRestrictionsDisjunctionsElement.road_user_types = valueRestrictionsDisjunctionsElementRoad_user_types;
  ::ad::map::restriction::PassengerCount valueRestrictionsDisjunctionsElementPassengers_min(
    std::numeric_limits<::ad::map::restriction::PassengerCount>::lowest());
  valueRestrictionsDisjunctionsElement.passengers_min = valueRestrictionsDisjunctionsElementPassengers_min;
  valueRestrictionsDisjunctions.resize(1, valueRestrictionsDisjunctionsElement);
  valueRestrictions.disjunctions = valueRestrictionsDisjunctions;
  value.restrictions = valueRestrictions;
  ::ad::physics::Distance valueLength(-1e9);
  value.length = valueLength;
  ::ad::physics::MetricRange valueLength_range;
  ::ad::physics::Distance valueLength_rangeMinimum(-1e9);
  valueLength_rangeMinimum = ::ad::physics::Distance(0.); // set to valid value within struct
  valueLength_range.minimum = valueLength_rangeMinimum;
  ::ad::physics::Distance valueLength_rangeMaximum(-1e9);
  valueLength_range.maximum = valueLength_rangeMaximum;
  valueLength_range.maximum = valueLength_range.minimum;
  valueLength_range.minimum = valueLength_range.maximum;
  value.length_range = valueLength_range;
  ::ad::physics::Distance valueWidth(-1e9);
  value.width = valueWidth;
  ::ad::physics::MetricRange valueWidth_range;
  ::ad::physics::Distance valueWidth_rangeMinimum(-1e9);
  valueWidth_rangeMinimum = ::ad::physics::Distance(0.); // set to valid value within struct
  valueWidth_range.minimum = valueWidth_rangeMinimum;
  ::ad::physics::Distance valueWidth_rangeMaximum(-1e9);
  valueWidth_range.maximum = valueWidth_rangeMaximum;
  valueWidth_range.maximum = valueWidth_range.minimum;
  valueWidth_range.minimum = valueWidth_range.maximum;
  value.width_range = valueWidth_range;
  ::ad::map::restriction::SpeedLimitList valueSpeed_limits;
  ::ad::map::restriction::SpeedLimit valueSpeed_limitsElement;
  ::ad::physics::Speed valueSpeed_limitsElementSpeed_limit(-100.);
  valueSpeed_limitsElement.speed_limit = valueSpeed_limitsElementSpeed_limit;
  ::ad::physics::ParametricRange valueSpeed_limitsElementLane_piece;
  ::ad::physics::ParametricValue valueSpeed_limitsElementLane_pieceMinimum(0.);
  valueSpeed_limitsElementLane_piece.minimum = valueSpeed_limitsElementLane_pieceMinimum;
  ::ad::physics::ParametricValue valueSpeed_limitsElementLane_pieceMaximum(0.);
  valueSpeed_limitsElementLane_piece.maximum = valueSpeed_limitsElementLane_pieceMaximum;
  valueSpeed_limitsElementLane_piece.maximum = valueSpeed_limitsElementLane_piece.minimum;
  valueSpeed_limitsElementLane_piece.minimum = valueSpeed_limitsElementLane_piece.maximum;
  valueSpeed_limitsElement.lane_piece = valueSpeed_limitsElementLane_piece;
  valueSpeed_limits.resize(1, valueSpeed_limitsElement);
  value.speed_limits = valueSpeed_limits;
  ::ad::map::point::Geometry valueEdge_left;
  bool valueEdge_leftIs_valid{true};
  valueEdge_left.is_valid = valueEdge_leftIs_valid;
  bool valueEdge_leftIs_closed{true};
  valueEdge_left.is_closed = valueEdge_leftIs_closed;
  ::ad::map::point::ECEFPointList valueEdge_leftEcef_points;
  ::ad::map::point::ECEFPoint valueEdge_leftEcef_pointsElement;
  ::ad::map::point::ECEFCoordinate valueEdge_leftEcef_pointsElementX(-6400000);
  valueEdge_leftEcef_pointsElement.x = valueEdge_leftEcef_pointsElementX;
  ::ad::map::point::ECEFCoordinate valueEdge_leftEcef_pointsElementY(-6400000);
  valueEdge_leftEcef_pointsElement.y = valueEdge_leftEcef_pointsElementY;
  ::ad::map::point::ECEFCoordinate valueEdge_leftEcef_pointsElementZ(-6400000);
  valueEdge_leftEcef_pointsElement.z = valueEdge_leftEcef_pointsElementZ;
  valueEdge_leftEcef_points.resize(1, valueEdge_leftEcef_pointsElement);
  valueEdge_left.ecef_points = valueEdge_leftEcef_points;
  ::ad::physics::Distance valueEdge_leftLength(-1e9);
  valueEdge_left.length = valueEdge_leftLength;
  ::ad::map::point::ENUPointCache valueEdge_leftPrivate_enu_points_cache;
  ::ad::map::point::ENUPointList valueEdge_leftPrivate_enu_points_cacheEnu_points;
  ::ad::map::point::ENUPoint valueEdge_leftPrivate_enu_points_cacheEnu_pointsElement;
  ::ad::map::point::ENUCoordinate valueEdge_leftPrivate_enu_points_cacheEnu_pointsElementX(-1e8);
  valueEdge_leftPrivate_enu_points_cacheEnu_pointsElement.x = valueEdge_leftPrivate_enu_points_cacheEnu_pointsElementX;
  ::ad::map::point::ENUCoordinate valueEdge_leftPrivate_enu_points_cacheEnu_pointsElementY(-1e8);
  valueEdge_leftPrivate_enu_points_cacheEnu_pointsElement.y = valueEdge_leftPrivate_enu_points_cacheEnu_pointsElementY;
  ::ad::map::point::ENUCoordinate valueEdge_leftPrivate_enu_points_cacheEnu_pointsElementZ(-1e8);
  valueEdge_leftPrivate_enu_points_cacheEnu_pointsElement.z = valueEdge_leftPrivate_enu_points_cacheEnu_pointsElementZ;
  valueEdge_leftPrivate_enu_points_cacheEnu_points.resize(1, valueEdge_leftPrivate_enu_points_cacheEnu_pointsElement);
  valueEdge_leftPrivate_enu_points_cache.enu_points = valueEdge_leftPrivate_enu_points_cacheEnu_points;
  uint64_t valueEdge_leftPrivate_enu_points_cacheEnu_version{std::numeric_limits<uint64_t>::min()};
  valueEdge_leftPrivate_enu_points_cache.enu_version = valueEdge_leftPrivate_enu_points_cacheEnu_version;
  valueEdge_left.private_enu_points_cache = valueEdge_leftPrivate_enu_points_cache;
  value.edge_left = valueEdge_left;
  ::ad::map::point::Geometry valueEdge_right;
  bool valueEdge_rightIs_valid{true};
  valueEdge_right.is_valid = valueEdge_rightIs_valid;
  bool valueEdge_rightIs_closed{true};
  valueEdge_right.is_closed = valueEdge_rightIs_closed;
  ::ad::map::point::ECEFPointList valueEdge_rightEcef_points;
  ::ad::map::point::ECEFPoint valueEdge_rightEcef_pointsElement;
  ::ad::map::point::ECEFCoordinate valueEdge_rightEcef_pointsElementX(-6400000);
  valueEdge_rightEcef_pointsElement.x = valueEdge_rightEcef_pointsElementX;
  ::ad::map::point::ECEFCoordinate valueEdge_rightEcef_pointsElementY(-6400000);
  valueEdge_rightEcef_pointsElement.y = valueEdge_rightEcef_pointsElementY;
  ::ad::map::point::ECEFCoordinate valueEdge_rightEcef_pointsElementZ(-6400000);
  valueEdge_rightEcef_pointsElement.z = valueEdge_rightEcef_pointsElementZ;
  valueEdge_rightEcef_points.resize(1, valueEdge_rightEcef_pointsElement);
  valueEdge_right.ecef_points = valueEdge_rightEcef_points;
  ::ad::physics::Distance valueEdge_rightLength(-1e9);
  valueEdge_right.length = valueEdge_rightLength;
  ::ad::map::point::ENUPointCache valueEdge_rightPrivate_enu_points_cache;
  ::ad::map::point::ENUPointList valueEdge_rightPrivate_enu_points_cacheEnu_points;
  ::ad::map::point::ENUPoint valueEdge_rightPrivate_enu_points_cacheEnu_pointsElement;
  ::ad::map::point::ENUCoordinate valueEdge_rightPrivate_enu_points_cacheEnu_pointsElementX(-1e8);
  valueEdge_rightPrivate_enu_points_cacheEnu_pointsElement.x
    = valueEdge_rightPrivate_enu_points_cacheEnu_pointsElementX;
  ::ad::map::point::ENUCoordinate valueEdge_rightPrivate_enu_points_cacheEnu_pointsElementY(-1e8);
  valueEdge_rightPrivate_enu_points_cacheEnu_pointsElement.y
    = valueEdge_rightPrivate_enu_points_cacheEnu_pointsElementY;
  ::ad::map::point::ENUCoordinate valueEdge_rightPrivate_enu_points_cacheEnu_pointsElementZ(-1e8);
  valueEdge_rightPrivate_enu_points_cacheEnu_pointsElement.z
    = valueEdge_rightPrivate_enu_points_cacheEnu_pointsElementZ;
  valueEdge_rightPrivate_enu_points_cacheEnu_points.resize(1, valueEdge_rightPrivate_enu_points_cacheEnu_pointsElement);
  valueEdge_rightPrivate_enu_points_cache.enu_points = valueEdge_rightPrivate_enu_points_cacheEnu_points;
  uint64_t valueEdge_rightPrivate_enu_points_cacheEnu_version{std::numeric_limits<uint64_t>::min()};
  valueEdge_rightPrivate_enu_points_cache.enu_version = valueEdge_rightPrivate_enu_points_cacheEnu_version;
  valueEdge_right.private_enu_points_cache = valueEdge_rightPrivate_enu_points_cache;
  value.edge_right = valueEdge_right;
  ::ad::map::lane::ContactLaneList valueContact_lanes;
  ::ad::map::lane::ContactLane valueContact_lanesElement;
  ::ad::map::lane::LaneId valueContact_lanesElementTo_lane(1);
  valueContact_lanesElement.to_lane = valueContact_lanesElementTo_lane;
  ::ad::map::lane::ContactLocation valueContact_lanesElementLocation(::ad::map::lane::ContactLocation::INVALID);
  valueContact_lanesElement.location = valueContact_lanesElementLocation;
  ::ad::map::lane::ContactTypeList valueContact_lanesElementTypes;
  ::ad::map::lane::ContactType valueContact_lanesElementTypesElement(::ad::map::lane::ContactType::INVALID);
  valueContact_lanesElementTypes.resize(1, valueContact_lanesElementTypesElement);
  valueContact_lanesElement.types = valueContact_lanesElementTypes;
  ::ad::map::restriction::Restrictions valueContact_lanesElementRestrictions;
  ::ad::map::restriction::RestrictionList valueContact_lanesElementRestrictionsConjunctions;
  ::ad::map::restriction::Restriction valueContact_lanesElementRestrictionsConjunctionsElement;
  bool valueContact_lanesElementRestrictionsConjunctionsElementNegated{true};
  valueContact_lanesElementRestrictionsConjunctionsElement.negated
    = valueContact_lanesElementRestrictionsConjunctionsElementNegated;
  ::ad::map::restriction::RoadUserTypeList valueContact_lanesElementRestrictionsConjunctionsElementRoad_user_types;
  ::ad::map::restriction::RoadUserType valueContact_lanesElementRestrictionsConjunctionsElementRoad_user_typesElement(
    ::ad::map::restriction::RoadUserType::INVALID);
  valueContact_lanesElementRestrictionsConjunctionsElementRoad_user_types.resize(
    1, valueContact_lanesElementRestrictionsConjunctionsElementRoad_user_typesElement);
  valueContact_lanesElementRestrictionsConjunctionsElement.road_user_types
    = valueContact_lanesElementRestrictionsConjunctionsElementRoad_user_types;
  ::ad::map::restriction::PassengerCount valueContact_lanesElementRestrictionsConjunctionsElementPassengers_min(
    std::numeric_limits<::ad::map::restriction::PassengerCount>::lowest());
  valueContact_lanesElementRestrictionsConjunctionsElement.passengers_min
    = valueContact_lanesElementRestrictionsConjunctionsElementPassengers_min;
  valueContact_lanesElementRestrictionsConjunctions.resize(1, valueContact_lanesElementRestrictionsConjunctionsElement);
  valueContact_lanesElementRestrictions.conjunctions = valueContact_lanesElementRestrictionsConjunctions;
  ::ad::map::restriction::RestrictionList valueContact_lanesElementRestrictionsDisjunctions;
  ::ad::map::restriction::Restriction valueContact_lanesElementRestrictionsDisjunctionsElement;
  bool valueContact_lanesElementRestrictionsDisjunctionsElementNegated{true};
  valueContact_lanesElementRestrictionsDisjunctionsElement.negated
    = valueContact_lanesElementRestrictionsDisjunctionsElementNegated;
  ::ad::map::restriction::RoadUserTypeList valueContact_lanesElementRestrictionsDisjunctionsElementRoad_user_types;
  ::ad::map::restriction::RoadUserType valueContact_lanesElementRestrictionsDisjunctionsElementRoad_user_typesElement(
    ::ad::map::restriction::RoadUserType::INVALID);
  valueContact_lanesElementRestrictionsDisjunctionsElementRoad_user_types.resize(
    1, valueContact_lanesElementRestrictionsDisjunctionsElementRoad_user_typesElement);
  valueContact_lanesElementRestrictionsDisjunctionsElement.road_user_types
    = valueContact_lanesElementRestrictionsDisjunctionsElementRoad_user_types;
  ::ad::map::restriction::PassengerCount valueContact_lanesElementRestrictionsDisjunctionsElementPassengers_min(
    std::numeric_limits<::ad::map::restriction::PassengerCount>::lowest());
  valueContact_lanesElementRestrictionsDisjunctionsElement.passengers_min
    = valueContact_lanesElementRestrictionsDisjunctionsElementPassengers_min;
  valueContact_lanesElementRestrictionsDisjunctions.resize(1, valueContact_lanesElementRestrictionsDisjunctionsElement);
  valueContact_lanesElementRestrictions.disjunctions = valueContact_lanesElementRestrictionsDisjunctions;
  valueContact_lanesElement.restrictions = valueContact_lanesElementRestrictions;
  ::ad::map::landmark::LandmarkId valueContact_lanesElementLandmark_id(
    std::numeric_limits<::ad::map::landmark::LandmarkId>::lowest());
  valueContact_lanesElement.landmark_id = valueContact_lanesElementLandmark_id;
  valueContact_lanes.resize(1, valueContact_lanesElement);
  value.contact_lanes = valueContact_lanes;
  ::ad::map::lane::ComplianceVersion valueCompliance_version(
    std::numeric_limits<::ad::map::lane::ComplianceVersion>::lowest());
  value.compliance_version = valueCompliance_version;
  ::ad::map::point::BoundingSphere valueBounding_sphere;
  ::ad::map::point::ECEFPoint valueBounding_sphereCenter;
  ::ad::map::point::ECEFCoordinate valueBounding_sphereCenterX(-6400000);
  valueBounding_sphereCenter.x = valueBounding_sphereCenterX;
  ::ad::map::point::ECEFCoordinate valueBounding_sphereCenterY(-6400000);
  valueBounding_sphereCenter.y = valueBounding_sphereCenterY;
  ::ad::map::point::ECEFCoordinate valueBounding_sphereCenterZ(-6400000);
  valueBounding_sphereCenter.z = valueBounding_sphereCenterZ;
  valueBounding_sphere.center = valueBounding_sphereCenter;
  ::ad::physics::Distance valueBounding_sphereRadius(-1e9);
  valueBounding_sphere.radius = valueBounding_sphereRadius;
  value.bounding_sphere = valueBounding_sphere;
  ::ad::map::landmark::LandmarkIdList valueVisible_landmarks;
  ::ad::map::landmark::LandmarkId valueVisible_landmarksElement(
    std::numeric_limits<::ad::map::landmark::LandmarkId>::lowest());
  valueVisible_landmarks.resize(1, valueVisible_landmarksElement);
  value.visible_landmarks = valueVisible_landmarks;

  // override member with data type value below input range minimum
  ::ad::physics::MetricRange invalidInitializedMember;
  ::ad::physics::Distance invalidInitializedMemberMinimum(-1e9 * 1.1);
  invalidInitializedMember.minimum = invalidInitializedMemberMinimum;
  value.length_range = invalidInitializedMember;
  ASSERT_FALSE(withinValidInputRange(value));
}

TEST(LaneValidInputRangeTests, testValidInputRangeLength_rangeTooBig)
{
  ::ad::map::lane::Lane value;
  ::ad::map::lane::LaneId valueId(1);
  value.id = valueId;
  ::ad::map::lane::LaneType valueType(::ad::map::lane::LaneType::INVALID);
  value.type = valueType;
  ::ad::map::lane::LaneDirection valueDirection(::ad::map::lane::LaneDirection::INVALID);
  value.direction = valueDirection;
  ::ad::map::restriction::Restrictions valueRestrictions;
  ::ad::map::restriction::RestrictionList valueRestrictionsConjunctions;
  ::ad::map::restriction::Restriction valueRestrictionsConjunctionsElement;
  bool valueRestrictionsConjunctionsElementNegated{true};
  valueRestrictionsConjunctionsElement.negated = valueRestrictionsConjunctionsElementNegated;
  ::ad::map::restriction::RoadUserTypeList valueRestrictionsConjunctionsElementRoad_user_types;
  ::ad::map::restriction::RoadUserType valueRestrictionsConjunctionsElementRoad_user_typesElement(
    ::ad::map::restriction::RoadUserType::INVALID);
  valueRestrictionsConjunctionsElementRoad_user_types.resize(
    1, valueRestrictionsConjunctionsElementRoad_user_typesElement);
  valueRestrictionsConjunctionsElement.road_user_types = valueRestrictionsConjunctionsElementRoad_user_types;
  ::ad::map::restriction::PassengerCount valueRestrictionsConjunctionsElementPassengers_min(
    std::numeric_limits<::ad::map::restriction::PassengerCount>::lowest());
  valueRestrictionsConjunctionsElement.passengers_min = valueRestrictionsConjunctionsElementPassengers_min;
  valueRestrictionsConjunctions.resize(1, valueRestrictionsConjunctionsElement);
  valueRestrictions.conjunctions = valueRestrictionsConjunctions;
  ::ad::map::restriction::RestrictionList valueRestrictionsDisjunctions;
  ::ad::map::restriction::Restriction valueRestrictionsDisjunctionsElement;
  bool valueRestrictionsDisjunctionsElementNegated{true};
  valueRestrictionsDisjunctionsElement.negated = valueRestrictionsDisjunctionsElementNegated;
  ::ad::map::restriction::RoadUserTypeList valueRestrictionsDisjunctionsElementRoad_user_types;
  ::ad::map::restriction::RoadUserType valueRestrictionsDisjunctionsElementRoad_user_typesElement(
    ::ad::map::restriction::RoadUserType::INVALID);
  valueRestrictionsDisjunctionsElementRoad_user_types.resize(
    1, valueRestrictionsDisjunctionsElementRoad_user_typesElement);
  valueRestrictionsDisjunctionsElement.road_user_types = valueRestrictionsDisjunctionsElementRoad_user_types;
  ::ad::map::restriction::PassengerCount valueRestrictionsDisjunctionsElementPassengers_min(
    std::numeric_limits<::ad::map::restriction::PassengerCount>::lowest());
  valueRestrictionsDisjunctionsElement.passengers_min = valueRestrictionsDisjunctionsElementPassengers_min;
  valueRestrictionsDisjunctions.resize(1, valueRestrictionsDisjunctionsElement);
  valueRestrictions.disjunctions = valueRestrictionsDisjunctions;
  value.restrictions = valueRestrictions;
  ::ad::physics::Distance valueLength(-1e9);
  value.length = valueLength;
  ::ad::physics::MetricRange valueLength_range;
  ::ad::physics::Distance valueLength_rangeMinimum(-1e9);
  valueLength_rangeMinimum = ::ad::physics::Distance(0.); // set to valid value within struct
  valueLength_range.minimum = valueLength_rangeMinimum;
  ::ad::physics::Distance valueLength_rangeMaximum(-1e9);
  valueLength_range.maximum = valueLength_rangeMaximum;
  valueLength_range.maximum = valueLength_range.minimum;
  valueLength_range.minimum = valueLength_range.maximum;
  value.length_range = valueLength_range;
  ::ad::physics::Distance valueWidth(-1e9);
  value.width = valueWidth;
  ::ad::physics::MetricRange valueWidth_range;
  ::ad::physics::Distance valueWidth_rangeMinimum(-1e9);
  valueWidth_rangeMinimum = ::ad::physics::Distance(0.); // set to valid value within struct
  valueWidth_range.minimum = valueWidth_rangeMinimum;
  ::ad::physics::Distance valueWidth_rangeMaximum(-1e9);
  valueWidth_range.maximum = valueWidth_rangeMaximum;
  valueWidth_range.maximum = valueWidth_range.minimum;
  valueWidth_range.minimum = valueWidth_range.maximum;
  value.width_range = valueWidth_range;
  ::ad::map::restriction::SpeedLimitList valueSpeed_limits;
  ::ad::map::restriction::SpeedLimit valueSpeed_limitsElement;
  ::ad::physics::Speed valueSpeed_limitsElementSpeed_limit(-100.);
  valueSpeed_limitsElement.speed_limit = valueSpeed_limitsElementSpeed_limit;
  ::ad::physics::ParametricRange valueSpeed_limitsElementLane_piece;
  ::ad::physics::ParametricValue valueSpeed_limitsElementLane_pieceMinimum(0.);
  valueSpeed_limitsElementLane_piece.minimum = valueSpeed_limitsElementLane_pieceMinimum;
  ::ad::physics::ParametricValue valueSpeed_limitsElementLane_pieceMaximum(0.);
  valueSpeed_limitsElementLane_piece.maximum = valueSpeed_limitsElementLane_pieceMaximum;
  valueSpeed_limitsElementLane_piece.maximum = valueSpeed_limitsElementLane_piece.minimum;
  valueSpeed_limitsElementLane_piece.minimum = valueSpeed_limitsElementLane_piece.maximum;
  valueSpeed_limitsElement.lane_piece = valueSpeed_limitsElementLane_piece;
  valueSpeed_limits.resize(1, valueSpeed_limitsElement);
  value.speed_limits = valueSpeed_limits;
  ::ad::map::point::Geometry valueEdge_left;
  bool valueEdge_leftIs_valid{true};
  valueEdge_left.is_valid = valueEdge_leftIs_valid;
  bool valueEdge_leftIs_closed{true};
  valueEdge_left.is_closed = valueEdge_leftIs_closed;
  ::ad::map::point::ECEFPointList valueEdge_leftEcef_points;
  ::ad::map::point::ECEFPoint valueEdge_leftEcef_pointsElement;
  ::ad::map::point::ECEFCoordinate valueEdge_leftEcef_pointsElementX(-6400000);
  valueEdge_leftEcef_pointsElement.x = valueEdge_leftEcef_pointsElementX;
  ::ad::map::point::ECEFCoordinate valueEdge_leftEcef_pointsElementY(-6400000);
  valueEdge_leftEcef_pointsElement.y = valueEdge_leftEcef_pointsElementY;
  ::ad::map::point::ECEFCoordinate valueEdge_leftEcef_pointsElementZ(-6400000);
  valueEdge_leftEcef_pointsElement.z = valueEdge_leftEcef_pointsElementZ;
  valueEdge_leftEcef_points.resize(1, valueEdge_leftEcef_pointsElement);
  valueEdge_left.ecef_points = valueEdge_leftEcef_points;
  ::ad::physics::Distance valueEdge_leftLength(-1e9);
  valueEdge_left.length = valueEdge_leftLength;
  ::ad::map::point::ENUPointCache valueEdge_leftPrivate_enu_points_cache;
  ::ad::map::point::ENUPointList valueEdge_leftPrivate_enu_points_cacheEnu_points;
  ::ad::map::point::ENUPoint valueEdge_leftPrivate_enu_points_cacheEnu_pointsElement;
  ::ad::map::point::ENUCoordinate valueEdge_leftPrivate_enu_points_cacheEnu_pointsElementX(-1e8);
  valueEdge_leftPrivate_enu_points_cacheEnu_pointsElement.x = valueEdge_leftPrivate_enu_points_cacheEnu_pointsElementX;
  ::ad::map::point::ENUCoordinate valueEdge_leftPrivate_enu_points_cacheEnu_pointsElementY(-1e8);
  valueEdge_leftPrivate_enu_points_cacheEnu_pointsElement.y = valueEdge_leftPrivate_enu_points_cacheEnu_pointsElementY;
  ::ad::map::point::ENUCoordinate valueEdge_leftPrivate_enu_points_cacheEnu_pointsElementZ(-1e8);
  valueEdge_leftPrivate_enu_points_cacheEnu_pointsElement.z = valueEdge_leftPrivate_enu_points_cacheEnu_pointsElementZ;
  valueEdge_leftPrivate_enu_points_cacheEnu_points.resize(1, valueEdge_leftPrivate_enu_points_cacheEnu_pointsElement);
  valueEdge_leftPrivate_enu_points_cache.enu_points = valueEdge_leftPrivate_enu_points_cacheEnu_points;
  uint64_t valueEdge_leftPrivate_enu_points_cacheEnu_version{std::numeric_limits<uint64_t>::min()};
  valueEdge_leftPrivate_enu_points_cache.enu_version = valueEdge_leftPrivate_enu_points_cacheEnu_version;
  valueEdge_left.private_enu_points_cache = valueEdge_leftPrivate_enu_points_cache;
  value.edge_left = valueEdge_left;
  ::ad::map::point::Geometry valueEdge_right;
  bool valueEdge_rightIs_valid{true};
  valueEdge_right.is_valid = valueEdge_rightIs_valid;
  bool valueEdge_rightIs_closed{true};
  valueEdge_right.is_closed = valueEdge_rightIs_closed;
  ::ad::map::point::ECEFPointList valueEdge_rightEcef_points;
  ::ad::map::point::ECEFPoint valueEdge_rightEcef_pointsElement;
  ::ad::map::point::ECEFCoordinate valueEdge_rightEcef_pointsElementX(-6400000);
  valueEdge_rightEcef_pointsElement.x = valueEdge_rightEcef_pointsElementX;
  ::ad::map::point::ECEFCoordinate valueEdge_rightEcef_pointsElementY(-6400000);
  valueEdge_rightEcef_pointsElement.y = valueEdge_rightEcef_pointsElementY;
  ::ad::map::point::ECEFCoordinate valueEdge_rightEcef_pointsElementZ(-6400000);
  valueEdge_rightEcef_pointsElement.z = valueEdge_rightEcef_pointsElementZ;
  valueEdge_rightEcef_points.resize(1, valueEdge_rightEcef_pointsElement);
  valueEdge_right.ecef_points = valueEdge_rightEcef_points;
  ::ad::physics::Distance valueEdge_rightLength(-1e9);
  valueEdge_right.length = valueEdge_rightLength;
  ::ad::map::point::ENUPointCache valueEdge_rightPrivate_enu_points_cache;
  ::ad::map::point::ENUPointList valueEdge_rightPrivate_enu_points_cacheEnu_points;
  ::ad::map::point::ENUPoint valueEdge_rightPrivate_enu_points_cacheEnu_pointsElement;
  ::ad::map::point::ENUCoordinate valueEdge_rightPrivate_enu_points_cacheEnu_pointsElementX(-1e8);
  valueEdge_rightPrivate_enu_points_cacheEnu_pointsElement.x
    = valueEdge_rightPrivate_enu_points_cacheEnu_pointsElementX;
  ::ad::map::point::ENUCoordinate valueEdge_rightPrivate_enu_points_cacheEnu_pointsElementY(-1e8);
  valueEdge_rightPrivate_enu_points_cacheEnu_pointsElement.y
    = valueEdge_rightPrivate_enu_points_cacheEnu_pointsElementY;
  ::ad::map::point::ENUCoordinate valueEdge_rightPrivate_enu_points_cacheEnu_pointsElementZ(-1e8);
  valueEdge_rightPrivate_enu_points_cacheEnu_pointsElement.z
    = valueEdge_rightPrivate_enu_points_cacheEnu_pointsElementZ;
  valueEdge_rightPrivate_enu_points_cacheEnu_points.resize(1, valueEdge_rightPrivate_enu_points_cacheEnu_pointsElement);
  valueEdge_rightPrivate_enu_points_cache.enu_points = valueEdge_rightPrivate_enu_points_cacheEnu_points;
  uint64_t valueEdge_rightPrivate_enu_points_cacheEnu_version{std::numeric_limits<uint64_t>::min()};
  valueEdge_rightPrivate_enu_points_cache.enu_version = valueEdge_rightPrivate_enu_points_cacheEnu_version;
  valueEdge_right.private_enu_points_cache = valueEdge_rightPrivate_enu_points_cache;
  value.edge_right = valueEdge_right;
  ::ad::map::lane::ContactLaneList valueContact_lanes;
  ::ad::map::lane::ContactLane valueContact_lanesElement;
  ::ad::map::lane::LaneId valueContact_lanesElementTo_lane(1);
  valueContact_lanesElement.to_lane = valueContact_lanesElementTo_lane;
  ::ad::map::lane::ContactLocation valueContact_lanesElementLocation(::ad::map::lane::ContactLocation::INVALID);
  valueContact_lanesElement.location = valueContact_lanesElementLocation;
  ::ad::map::lane::ContactTypeList valueContact_lanesElementTypes;
  ::ad::map::lane::ContactType valueContact_lanesElementTypesElement(::ad::map::lane::ContactType::INVALID);
  valueContact_lanesElementTypes.resize(1, valueContact_lanesElementTypesElement);
  valueContact_lanesElement.types = valueContact_lanesElementTypes;
  ::ad::map::restriction::Restrictions valueContact_lanesElementRestrictions;
  ::ad::map::restriction::RestrictionList valueContact_lanesElementRestrictionsConjunctions;
  ::ad::map::restriction::Restriction valueContact_lanesElementRestrictionsConjunctionsElement;
  bool valueContact_lanesElementRestrictionsConjunctionsElementNegated{true};
  valueContact_lanesElementRestrictionsConjunctionsElement.negated
    = valueContact_lanesElementRestrictionsConjunctionsElementNegated;
  ::ad::map::restriction::RoadUserTypeList valueContact_lanesElementRestrictionsConjunctionsElementRoad_user_types;
  ::ad::map::restriction::RoadUserType valueContact_lanesElementRestrictionsConjunctionsElementRoad_user_typesElement(
    ::ad::map::restriction::RoadUserType::INVALID);
  valueContact_lanesElementRestrictionsConjunctionsElementRoad_user_types.resize(
    1, valueContact_lanesElementRestrictionsConjunctionsElementRoad_user_typesElement);
  valueContact_lanesElementRestrictionsConjunctionsElement.road_user_types
    = valueContact_lanesElementRestrictionsConjunctionsElementRoad_user_types;
  ::ad::map::restriction::PassengerCount valueContact_lanesElementRestrictionsConjunctionsElementPassengers_min(
    std::numeric_limits<::ad::map::restriction::PassengerCount>::lowest());
  valueContact_lanesElementRestrictionsConjunctionsElement.passengers_min
    = valueContact_lanesElementRestrictionsConjunctionsElementPassengers_min;
  valueContact_lanesElementRestrictionsConjunctions.resize(1, valueContact_lanesElementRestrictionsConjunctionsElement);
  valueContact_lanesElementRestrictions.conjunctions = valueContact_lanesElementRestrictionsConjunctions;
  ::ad::map::restriction::RestrictionList valueContact_lanesElementRestrictionsDisjunctions;
  ::ad::map::restriction::Restriction valueContact_lanesElementRestrictionsDisjunctionsElement;
  bool valueContact_lanesElementRestrictionsDisjunctionsElementNegated{true};
  valueContact_lanesElementRestrictionsDisjunctionsElement.negated
    = valueContact_lanesElementRestrictionsDisjunctionsElementNegated;
  ::ad::map::restriction::RoadUserTypeList valueContact_lanesElementRestrictionsDisjunctionsElementRoad_user_types;
  ::ad::map::restriction::RoadUserType valueContact_lanesElementRestrictionsDisjunctionsElementRoad_user_typesElement(
    ::ad::map::restriction::RoadUserType::INVALID);
  valueContact_lanesElementRestrictionsDisjunctionsElementRoad_user_types.resize(
    1, valueContact_lanesElementRestrictionsDisjunctionsElementRoad_user_typesElement);
  valueContact_lanesElementRestrictionsDisjunctionsElement.road_user_types
    = valueContact_lanesElementRestrictionsDisjunctionsElementRoad_user_types;
  ::ad::map::restriction::PassengerCount valueContact_lanesElementRestrictionsDisjunctionsElementPassengers_min(
    std::numeric_limits<::ad::map::restriction::PassengerCount>::lowest());
  valueContact_lanesElementRestrictionsDisjunctionsElement.passengers_min
    = valueContact_lanesElementRestrictionsDisjunctionsElementPassengers_min;
  valueContact_lanesElementRestrictionsDisjunctions.resize(1, valueContact_lanesElementRestrictionsDisjunctionsElement);
  valueContact_lanesElementRestrictions.disjunctions = valueContact_lanesElementRestrictionsDisjunctions;
  valueContact_lanesElement.restrictions = valueContact_lanesElementRestrictions;
  ::ad::map::landmark::LandmarkId valueContact_lanesElementLandmark_id(
    std::numeric_limits<::ad::map::landmark::LandmarkId>::lowest());
  valueContact_lanesElement.landmark_id = valueContact_lanesElementLandmark_id;
  valueContact_lanes.resize(1, valueContact_lanesElement);
  value.contact_lanes = valueContact_lanes;
  ::ad::map::lane::ComplianceVersion valueCompliance_version(
    std::numeric_limits<::ad::map::lane::ComplianceVersion>::lowest());
  value.compliance_version = valueCompliance_version;
  ::ad::map::point::BoundingSphere valueBounding_sphere;
  ::ad::map::point::ECEFPoint valueBounding_sphereCenter;
  ::ad::map::point::ECEFCoordinate valueBounding_sphereCenterX(-6400000);
  valueBounding_sphereCenter.x = valueBounding_sphereCenterX;
  ::ad::map::point::ECEFCoordinate valueBounding_sphereCenterY(-6400000);
  valueBounding_sphereCenter.y = valueBounding_sphereCenterY;
  ::ad::map::point::ECEFCoordinate valueBounding_sphereCenterZ(-6400000);
  valueBounding_sphereCenter.z = valueBounding_sphereCenterZ;
  valueBounding_sphere.center = valueBounding_sphereCenter;
  ::ad::physics::Distance valueBounding_sphereRadius(-1e9);
  valueBounding_sphere.radius = valueBounding_sphereRadius;
  value.bounding_sphere = valueBounding_sphere;
  ::ad::map::landmark::LandmarkIdList valueVisible_landmarks;
  ::ad::map::landmark::LandmarkId valueVisible_landmarksElement(
    std::numeric_limits<::ad::map::landmark::LandmarkId>::lowest());
  valueVisible_landmarks.resize(1, valueVisible_landmarksElement);
  value.visible_landmarks = valueVisible_landmarks;

  // override member with data type value above input range maximum
  ::ad::physics::MetricRange invalidInitializedMember;
  ::ad::physics::Distance invalidInitializedMemberMinimum(1e9 * 1.1);
  invalidInitializedMember.minimum = invalidInitializedMemberMinimum;
  value.length_range = invalidInitializedMember;
  ASSERT_FALSE(withinValidInputRange(value));
}

TEST(LaneValidInputRangeTests, testValidInputRangeWidthTooSmall)
{
  ::ad::map::lane::Lane value;
  ::ad::map::lane::LaneId valueId(1);
  value.id = valueId;
  ::ad::map::lane::LaneType valueType(::ad::map::lane::LaneType::INVALID);
  value.type = valueType;
  ::ad::map::lane::LaneDirection valueDirection(::ad::map::lane::LaneDirection::INVALID);
  value.direction = valueDirection;
  ::ad::map::restriction::Restrictions valueRestrictions;
  ::ad::map::restriction::RestrictionList valueRestrictionsConjunctions;
  ::ad::map::restriction::Restriction valueRestrictionsConjunctionsElement;
  bool valueRestrictionsConjunctionsElementNegated{true};
  valueRestrictionsConjunctionsElement.negated = valueRestrictionsConjunctionsElementNegated;
  ::ad::map::restriction::RoadUserTypeList valueRestrictionsConjunctionsElementRoad_user_types;
  ::ad::map::restriction::RoadUserType valueRestrictionsConjunctionsElementRoad_user_typesElement(
    ::ad::map::restriction::RoadUserType::INVALID);
  valueRestrictionsConjunctionsElementRoad_user_types.resize(
    1, valueRestrictionsConjunctionsElementRoad_user_typesElement);
  valueRestrictionsConjunctionsElement.road_user_types = valueRestrictionsConjunctionsElementRoad_user_types;
  ::ad::map::restriction::PassengerCount valueRestrictionsConjunctionsElementPassengers_min(
    std::numeric_limits<::ad::map::restriction::PassengerCount>::lowest());
  valueRestrictionsConjunctionsElement.passengers_min = valueRestrictionsConjunctionsElementPassengers_min;
  valueRestrictionsConjunctions.resize(1, valueRestrictionsConjunctionsElement);
  valueRestrictions.conjunctions = valueRestrictionsConjunctions;
  ::ad::map::restriction::RestrictionList valueRestrictionsDisjunctions;
  ::ad::map::restriction::Restriction valueRestrictionsDisjunctionsElement;
  bool valueRestrictionsDisjunctionsElementNegated{true};
  valueRestrictionsDisjunctionsElement.negated = valueRestrictionsDisjunctionsElementNegated;
  ::ad::map::restriction::RoadUserTypeList valueRestrictionsDisjunctionsElementRoad_user_types;
  ::ad::map::restriction::RoadUserType valueRestrictionsDisjunctionsElementRoad_user_typesElement(
    ::ad::map::restriction::RoadUserType::INVALID);
  valueRestrictionsDisjunctionsElementRoad_user_types.resize(
    1, valueRestrictionsDisjunctionsElementRoad_user_typesElement);
  valueRestrictionsDisjunctionsElement.road_user_types = valueRestrictionsDisjunctionsElementRoad_user_types;
  ::ad::map::restriction::PassengerCount valueRestrictionsDisjunctionsElementPassengers_min(
    std::numeric_limits<::ad::map::restriction::PassengerCount>::lowest());
  valueRestrictionsDisjunctionsElement.passengers_min = valueRestrictionsDisjunctionsElementPassengers_min;
  valueRestrictionsDisjunctions.resize(1, valueRestrictionsDisjunctionsElement);
  valueRestrictions.disjunctions = valueRestrictionsDisjunctions;
  value.restrictions = valueRestrictions;
  ::ad::physics::Distance valueLength(-1e9);
  value.length = valueLength;
  ::ad::physics::MetricRange valueLength_range;
  ::ad::physics::Distance valueLength_rangeMinimum(-1e9);
  valueLength_rangeMinimum = ::ad::physics::Distance(0.); // set to valid value within struct
  valueLength_range.minimum = valueLength_rangeMinimum;
  ::ad::physics::Distance valueLength_rangeMaximum(-1e9);
  valueLength_range.maximum = valueLength_rangeMaximum;
  valueLength_range.maximum = valueLength_range.minimum;
  valueLength_range.minimum = valueLength_range.maximum;
  value.length_range = valueLength_range;
  ::ad::physics::Distance valueWidth(-1e9);
  value.width = valueWidth;
  ::ad::physics::MetricRange valueWidth_range;
  ::ad::physics::Distance valueWidth_rangeMinimum(-1e9);
  valueWidth_rangeMinimum = ::ad::physics::Distance(0.); // set to valid value within struct
  valueWidth_range.minimum = valueWidth_rangeMinimum;
  ::ad::physics::Distance valueWidth_rangeMaximum(-1e9);
  valueWidth_range.maximum = valueWidth_rangeMaximum;
  valueWidth_range.maximum = valueWidth_range.minimum;
  valueWidth_range.minimum = valueWidth_range.maximum;
  value.width_range = valueWidth_range;
  ::ad::map::restriction::SpeedLimitList valueSpeed_limits;
  ::ad::map::restriction::SpeedLimit valueSpeed_limitsElement;
  ::ad::physics::Speed valueSpeed_limitsElementSpeed_limit(-100.);
  valueSpeed_limitsElement.speed_limit = valueSpeed_limitsElementSpeed_limit;
  ::ad::physics::ParametricRange valueSpeed_limitsElementLane_piece;
  ::ad::physics::ParametricValue valueSpeed_limitsElementLane_pieceMinimum(0.);
  valueSpeed_limitsElementLane_piece.minimum = valueSpeed_limitsElementLane_pieceMinimum;
  ::ad::physics::ParametricValue valueSpeed_limitsElementLane_pieceMaximum(0.);
  valueSpeed_limitsElementLane_piece.maximum = valueSpeed_limitsElementLane_pieceMaximum;
  valueSpeed_limitsElementLane_piece.maximum = valueSpeed_limitsElementLane_piece.minimum;
  valueSpeed_limitsElementLane_piece.minimum = valueSpeed_limitsElementLane_piece.maximum;
  valueSpeed_limitsElement.lane_piece = valueSpeed_limitsElementLane_piece;
  valueSpeed_limits.resize(1, valueSpeed_limitsElement);
  value.speed_limits = valueSpeed_limits;
  ::ad::map::point::Geometry valueEdge_left;
  bool valueEdge_leftIs_valid{true};
  valueEdge_left.is_valid = valueEdge_leftIs_valid;
  bool valueEdge_leftIs_closed{true};
  valueEdge_left.is_closed = valueEdge_leftIs_closed;
  ::ad::map::point::ECEFPointList valueEdge_leftEcef_points;
  ::ad::map::point::ECEFPoint valueEdge_leftEcef_pointsElement;
  ::ad::map::point::ECEFCoordinate valueEdge_leftEcef_pointsElementX(-6400000);
  valueEdge_leftEcef_pointsElement.x = valueEdge_leftEcef_pointsElementX;
  ::ad::map::point::ECEFCoordinate valueEdge_leftEcef_pointsElementY(-6400000);
  valueEdge_leftEcef_pointsElement.y = valueEdge_leftEcef_pointsElementY;
  ::ad::map::point::ECEFCoordinate valueEdge_leftEcef_pointsElementZ(-6400000);
  valueEdge_leftEcef_pointsElement.z = valueEdge_leftEcef_pointsElementZ;
  valueEdge_leftEcef_points.resize(1, valueEdge_leftEcef_pointsElement);
  valueEdge_left.ecef_points = valueEdge_leftEcef_points;
  ::ad::physics::Distance valueEdge_leftLength(-1e9);
  valueEdge_left.length = valueEdge_leftLength;
  ::ad::map::point::ENUPointCache valueEdge_leftPrivate_enu_points_cache;
  ::ad::map::point::ENUPointList valueEdge_leftPrivate_enu_points_cacheEnu_points;
  ::ad::map::point::ENUPoint valueEdge_leftPrivate_enu_points_cacheEnu_pointsElement;
  ::ad::map::point::ENUCoordinate valueEdge_leftPrivate_enu_points_cacheEnu_pointsElementX(-1e8);
  valueEdge_leftPrivate_enu_points_cacheEnu_pointsElement.x = valueEdge_leftPrivate_enu_points_cacheEnu_pointsElementX;
  ::ad::map::point::ENUCoordinate valueEdge_leftPrivate_enu_points_cacheEnu_pointsElementY(-1e8);
  valueEdge_leftPrivate_enu_points_cacheEnu_pointsElement.y = valueEdge_leftPrivate_enu_points_cacheEnu_pointsElementY;
  ::ad::map::point::ENUCoordinate valueEdge_leftPrivate_enu_points_cacheEnu_pointsElementZ(-1e8);
  valueEdge_leftPrivate_enu_points_cacheEnu_pointsElement.z = valueEdge_leftPrivate_enu_points_cacheEnu_pointsElementZ;
  valueEdge_leftPrivate_enu_points_cacheEnu_points.resize(1, valueEdge_leftPrivate_enu_points_cacheEnu_pointsElement);
  valueEdge_leftPrivate_enu_points_cache.enu_points = valueEdge_leftPrivate_enu_points_cacheEnu_points;
  uint64_t valueEdge_leftPrivate_enu_points_cacheEnu_version{std::numeric_limits<uint64_t>::min()};
  valueEdge_leftPrivate_enu_points_cache.enu_version = valueEdge_leftPrivate_enu_points_cacheEnu_version;
  valueEdge_left.private_enu_points_cache = valueEdge_leftPrivate_enu_points_cache;
  value.edge_left = valueEdge_left;
  ::ad::map::point::Geometry valueEdge_right;
  bool valueEdge_rightIs_valid{true};
  valueEdge_right.is_valid = valueEdge_rightIs_valid;
  bool valueEdge_rightIs_closed{true};
  valueEdge_right.is_closed = valueEdge_rightIs_closed;
  ::ad::map::point::ECEFPointList valueEdge_rightEcef_points;
  ::ad::map::point::ECEFPoint valueEdge_rightEcef_pointsElement;
  ::ad::map::point::ECEFCoordinate valueEdge_rightEcef_pointsElementX(-6400000);
  valueEdge_rightEcef_pointsElement.x = valueEdge_rightEcef_pointsElementX;
  ::ad::map::point::ECEFCoordinate valueEdge_rightEcef_pointsElementY(-6400000);
  valueEdge_rightEcef_pointsElement.y = valueEdge_rightEcef_pointsElementY;
  ::ad::map::point::ECEFCoordinate valueEdge_rightEcef_pointsElementZ(-6400000);
  valueEdge_rightEcef_pointsElement.z = valueEdge_rightEcef_pointsElementZ;
  valueEdge_rightEcef_points.resize(1, valueEdge_rightEcef_pointsElement);
  valueEdge_right.ecef_points = valueEdge_rightEcef_points;
  ::ad::physics::Distance valueEdge_rightLength(-1e9);
  valueEdge_right.length = valueEdge_rightLength;
  ::ad::map::point::ENUPointCache valueEdge_rightPrivate_enu_points_cache;
  ::ad::map::point::ENUPointList valueEdge_rightPrivate_enu_points_cacheEnu_points;
  ::ad::map::point::ENUPoint valueEdge_rightPrivate_enu_points_cacheEnu_pointsElement;
  ::ad::map::point::ENUCoordinate valueEdge_rightPrivate_enu_points_cacheEnu_pointsElementX(-1e8);
  valueEdge_rightPrivate_enu_points_cacheEnu_pointsElement.x
    = valueEdge_rightPrivate_enu_points_cacheEnu_pointsElementX;
  ::ad::map::point::ENUCoordinate valueEdge_rightPrivate_enu_points_cacheEnu_pointsElementY(-1e8);
  valueEdge_rightPrivate_enu_points_cacheEnu_pointsElement.y
    = valueEdge_rightPrivate_enu_points_cacheEnu_pointsElementY;
  ::ad::map::point::ENUCoordinate valueEdge_rightPrivate_enu_points_cacheEnu_pointsElementZ(-1e8);
  valueEdge_rightPrivate_enu_points_cacheEnu_pointsElement.z
    = valueEdge_rightPrivate_enu_points_cacheEnu_pointsElementZ;
  valueEdge_rightPrivate_enu_points_cacheEnu_points.resize(1, valueEdge_rightPrivate_enu_points_cacheEnu_pointsElement);
  valueEdge_rightPrivate_enu_points_cache.enu_points = valueEdge_rightPrivate_enu_points_cacheEnu_points;
  uint64_t valueEdge_rightPrivate_enu_points_cacheEnu_version{std::numeric_limits<uint64_t>::min()};
  valueEdge_rightPrivate_enu_points_cache.enu_version = valueEdge_rightPrivate_enu_points_cacheEnu_version;
  valueEdge_right.private_enu_points_cache = valueEdge_rightPrivate_enu_points_cache;
  value.edge_right = valueEdge_right;
  ::ad::map::lane::ContactLaneList valueContact_lanes;
  ::ad::map::lane::ContactLane valueContact_lanesElement;
  ::ad::map::lane::LaneId valueContact_lanesElementTo_lane(1);
  valueContact_lanesElement.to_lane = valueContact_lanesElementTo_lane;
  ::ad::map::lane::ContactLocation valueContact_lanesElementLocation(::ad::map::lane::ContactLocation::INVALID);
  valueContact_lanesElement.location = valueContact_lanesElementLocation;
  ::ad::map::lane::ContactTypeList valueContact_lanesElementTypes;
  ::ad::map::lane::ContactType valueContact_lanesElementTypesElement(::ad::map::lane::ContactType::INVALID);
  valueContact_lanesElementTypes.resize(1, valueContact_lanesElementTypesElement);
  valueContact_lanesElement.types = valueContact_lanesElementTypes;
  ::ad::map::restriction::Restrictions valueContact_lanesElementRestrictions;
  ::ad::map::restriction::RestrictionList valueContact_lanesElementRestrictionsConjunctions;
  ::ad::map::restriction::Restriction valueContact_lanesElementRestrictionsConjunctionsElement;
  bool valueContact_lanesElementRestrictionsConjunctionsElementNegated{true};
  valueContact_lanesElementRestrictionsConjunctionsElement.negated
    = valueContact_lanesElementRestrictionsConjunctionsElementNegated;
  ::ad::map::restriction::RoadUserTypeList valueContact_lanesElementRestrictionsConjunctionsElementRoad_user_types;
  ::ad::map::restriction::RoadUserType valueContact_lanesElementRestrictionsConjunctionsElementRoad_user_typesElement(
    ::ad::map::restriction::RoadUserType::INVALID);
  valueContact_lanesElementRestrictionsConjunctionsElementRoad_user_types.resize(
    1, valueContact_lanesElementRestrictionsConjunctionsElementRoad_user_typesElement);
  valueContact_lanesElementRestrictionsConjunctionsElement.road_user_types
    = valueContact_lanesElementRestrictionsConjunctionsElementRoad_user_types;
  ::ad::map::restriction::PassengerCount valueContact_lanesElementRestrictionsConjunctionsElementPassengers_min(
    std::numeric_limits<::ad::map::restriction::PassengerCount>::lowest());
  valueContact_lanesElementRestrictionsConjunctionsElement.passengers_min
    = valueContact_lanesElementRestrictionsConjunctionsElementPassengers_min;
  valueContact_lanesElementRestrictionsConjunctions.resize(1, valueContact_lanesElementRestrictionsConjunctionsElement);
  valueContact_lanesElementRestrictions.conjunctions = valueContact_lanesElementRestrictionsConjunctions;
  ::ad::map::restriction::RestrictionList valueContact_lanesElementRestrictionsDisjunctions;
  ::ad::map::restriction::Restriction valueContact_lanesElementRestrictionsDisjunctionsElement;
  bool valueContact_lanesElementRestrictionsDisjunctionsElementNegated{true};
  valueContact_lanesElementRestrictionsDisjunctionsElement.negated
    = valueContact_lanesElementRestrictionsDisjunctionsElementNegated;
  ::ad::map::restriction::RoadUserTypeList valueContact_lanesElementRestrictionsDisjunctionsElementRoad_user_types;
  ::ad::map::restriction::RoadUserType valueContact_lanesElementRestrictionsDisjunctionsElementRoad_user_typesElement(
    ::ad::map::restriction::RoadUserType::INVALID);
  valueContact_lanesElementRestrictionsDisjunctionsElementRoad_user_types.resize(
    1, valueContact_lanesElementRestrictionsDisjunctionsElementRoad_user_typesElement);
  valueContact_lanesElementRestrictionsDisjunctionsElement.road_user_types
    = valueContact_lanesElementRestrictionsDisjunctionsElementRoad_user_types;
  ::ad::map::restriction::PassengerCount valueContact_lanesElementRestrictionsDisjunctionsElementPassengers_min(
    std::numeric_limits<::ad::map::restriction::PassengerCount>::lowest());
  valueContact_lanesElementRestrictionsDisjunctionsElement.passengers_min
    = valueContact_lanesElementRestrictionsDisjunctionsElementPassengers_min;
  valueContact_lanesElementRestrictionsDisjunctions.resize(1, valueContact_lanesElementRestrictionsDisjunctionsElement);
  valueContact_lanesElementRestrictions.disjunctions = valueContact_lanesElementRestrictionsDisjunctions;
  valueContact_lanesElement.restrictions = valueContact_lanesElementRestrictions;
  ::ad::map::landmark::LandmarkId valueContact_lanesElementLandmark_id(
    std::numeric_limits<::ad::map::landmark::LandmarkId>::lowest());
  valueContact_lanesElement.landmark_id = valueContact_lanesElementLandmark_id;
  valueContact_lanes.resize(1, valueContact_lanesElement);
  value.contact_lanes = valueContact_lanes;
  ::ad::map::lane::ComplianceVersion valueCompliance_version(
    std::numeric_limits<::ad::map::lane::ComplianceVersion>::lowest());
  value.compliance_version = valueCompliance_version;
  ::ad::map::point::BoundingSphere valueBounding_sphere;
  ::ad::map::point::ECEFPoint valueBounding_sphereCenter;
  ::ad::map::point::ECEFCoordinate valueBounding_sphereCenterX(-6400000);
  valueBounding_sphereCenter.x = valueBounding_sphereCenterX;
  ::ad::map::point::ECEFCoordinate valueBounding_sphereCenterY(-6400000);
  valueBounding_sphereCenter.y = valueBounding_sphereCenterY;
  ::ad::map::point::ECEFCoordinate valueBounding_sphereCenterZ(-6400000);
  valueBounding_sphereCenter.z = valueBounding_sphereCenterZ;
  valueBounding_sphere.center = valueBounding_sphereCenter;
  ::ad::physics::Distance valueBounding_sphereRadius(-1e9);
  valueBounding_sphere.radius = valueBounding_sphereRadius;
  value.bounding_sphere = valueBounding_sphere;
  ::ad::map::landmark::LandmarkIdList valueVisible_landmarks;
  ::ad::map::landmark::LandmarkId valueVisible_landmarksElement(
    std::numeric_limits<::ad::map::landmark::LandmarkId>::lowest());
  valueVisible_landmarks.resize(1, valueVisible_landmarksElement);
  value.visible_landmarks = valueVisible_landmarks;

  // override member with data type value below input range minimum
  ::ad::physics::Distance invalidInitializedMember(-1e9 * 1.1);
  value.width = invalidInitializedMember;
  ASSERT_FALSE(withinValidInputRange(value));
}

TEST(LaneValidInputRangeTests, testValidInputRangeWidthTooBig)
{
  ::ad::map::lane::Lane value;
  ::ad::map::lane::LaneId valueId(1);
  value.id = valueId;
  ::ad::map::lane::LaneType valueType(::ad::map::lane::LaneType::INVALID);
  value.type = valueType;
  ::ad::map::lane::LaneDirection valueDirection(::ad::map::lane::LaneDirection::INVALID);
  value.direction = valueDirection;
  ::ad::map::restriction::Restrictions valueRestrictions;
  ::ad::map::restriction::RestrictionList valueRestrictionsConjunctions;
  ::ad::map::restriction::Restriction valueRestrictionsConjunctionsElement;
  bool valueRestrictionsConjunctionsElementNegated{true};
  valueRestrictionsConjunctionsElement.negated = valueRestrictionsConjunctionsElementNegated;
  ::ad::map::restriction::RoadUserTypeList valueRestrictionsConjunctionsElementRoad_user_types;
  ::ad::map::restriction::RoadUserType valueRestrictionsConjunctionsElementRoad_user_typesElement(
    ::ad::map::restriction::RoadUserType::INVALID);
  valueRestrictionsConjunctionsElementRoad_user_types.resize(
    1, valueRestrictionsConjunctionsElementRoad_user_typesElement);
  valueRestrictionsConjunctionsElement.road_user_types = valueRestrictionsConjunctionsElementRoad_user_types;
  ::ad::map::restriction::PassengerCount valueRestrictionsConjunctionsElementPassengers_min(
    std::numeric_limits<::ad::map::restriction::PassengerCount>::lowest());
  valueRestrictionsConjunctionsElement.passengers_min = valueRestrictionsConjunctionsElementPassengers_min;
  valueRestrictionsConjunctions.resize(1, valueRestrictionsConjunctionsElement);
  valueRestrictions.conjunctions = valueRestrictionsConjunctions;
  ::ad::map::restriction::RestrictionList valueRestrictionsDisjunctions;
  ::ad::map::restriction::Restriction valueRestrictionsDisjunctionsElement;
  bool valueRestrictionsDisjunctionsElementNegated{true};
  valueRestrictionsDisjunctionsElement.negated = valueRestrictionsDisjunctionsElementNegated;
  ::ad::map::restriction::RoadUserTypeList valueRestrictionsDisjunctionsElementRoad_user_types;
  ::ad::map::restriction::RoadUserType valueRestrictionsDisjunctionsElementRoad_user_typesElement(
    ::ad::map::restriction::RoadUserType::INVALID);
  valueRestrictionsDisjunctionsElementRoad_user_types.resize(
    1, valueRestrictionsDisjunctionsElementRoad_user_typesElement);
  valueRestrictionsDisjunctionsElement.road_user_types = valueRestrictionsDisjunctionsElementRoad_user_types;
  ::ad::map::restriction::PassengerCount valueRestrictionsDisjunctionsElementPassengers_min(
    std::numeric_limits<::ad::map::restriction::PassengerCount>::lowest());
  valueRestrictionsDisjunctionsElement.passengers_min = valueRestrictionsDisjunctionsElementPassengers_min;
  valueRestrictionsDisjunctions.resize(1, valueRestrictionsDisjunctionsElement);
  valueRestrictions.disjunctions = valueRestrictionsDisjunctions;
  value.restrictions = valueRestrictions;
  ::ad::physics::Distance valueLength(-1e9);
  value.length = valueLength;
  ::ad::physics::MetricRange valueLength_range;
  ::ad::physics::Distance valueLength_rangeMinimum(-1e9);
  valueLength_rangeMinimum = ::ad::physics::Distance(0.); // set to valid value within struct
  valueLength_range.minimum = valueLength_rangeMinimum;
  ::ad::physics::Distance valueLength_rangeMaximum(-1e9);
  valueLength_range.maximum = valueLength_rangeMaximum;
  valueLength_range.maximum = valueLength_range.minimum;
  valueLength_range.minimum = valueLength_range.maximum;
  value.length_range = valueLength_range;
  ::ad::physics::Distance valueWidth(-1e9);
  value.width = valueWidth;
  ::ad::physics::MetricRange valueWidth_range;
  ::ad::physics::Distance valueWidth_rangeMinimum(-1e9);
  valueWidth_rangeMinimum = ::ad::physics::Distance(0.); // set to valid value within struct
  valueWidth_range.minimum = valueWidth_rangeMinimum;
  ::ad::physics::Distance valueWidth_rangeMaximum(-1e9);
  valueWidth_range.maximum = valueWidth_rangeMaximum;
  valueWidth_range.maximum = valueWidth_range.minimum;
  valueWidth_range.minimum = valueWidth_range.maximum;
  value.width_range = valueWidth_range;
  ::ad::map::restriction::SpeedLimitList valueSpeed_limits;
  ::ad::map::restriction::SpeedLimit valueSpeed_limitsElement;
  ::ad::physics::Speed valueSpeed_limitsElementSpeed_limit(-100.);
  valueSpeed_limitsElement.speed_limit = valueSpeed_limitsElementSpeed_limit;
  ::ad::physics::ParametricRange valueSpeed_limitsElementLane_piece;
  ::ad::physics::ParametricValue valueSpeed_limitsElementLane_pieceMinimum(0.);
  valueSpeed_limitsElementLane_piece.minimum = valueSpeed_limitsElementLane_pieceMinimum;
  ::ad::physics::ParametricValue valueSpeed_limitsElementLane_pieceMaximum(0.);
  valueSpeed_limitsElementLane_piece.maximum = valueSpeed_limitsElementLane_pieceMaximum;
  valueSpeed_limitsElementLane_piece.maximum = valueSpeed_limitsElementLane_piece.minimum;
  valueSpeed_limitsElementLane_piece.minimum = valueSpeed_limitsElementLane_piece.maximum;
  valueSpeed_limitsElement.lane_piece = valueSpeed_limitsElementLane_piece;
  valueSpeed_limits.resize(1, valueSpeed_limitsElement);
  value.speed_limits = valueSpeed_limits;
  ::ad::map::point::Geometry valueEdge_left;
  bool valueEdge_leftIs_valid{true};
  valueEdge_left.is_valid = valueEdge_leftIs_valid;
  bool valueEdge_leftIs_closed{true};
  valueEdge_left.is_closed = valueEdge_leftIs_closed;
  ::ad::map::point::ECEFPointList valueEdge_leftEcef_points;
  ::ad::map::point::ECEFPoint valueEdge_leftEcef_pointsElement;
  ::ad::map::point::ECEFCoordinate valueEdge_leftEcef_pointsElementX(-6400000);
  valueEdge_leftEcef_pointsElement.x = valueEdge_leftEcef_pointsElementX;
  ::ad::map::point::ECEFCoordinate valueEdge_leftEcef_pointsElementY(-6400000);
  valueEdge_leftEcef_pointsElement.y = valueEdge_leftEcef_pointsElementY;
  ::ad::map::point::ECEFCoordinate valueEdge_leftEcef_pointsElementZ(-6400000);
  valueEdge_leftEcef_pointsElement.z = valueEdge_leftEcef_pointsElementZ;
  valueEdge_leftEcef_points.resize(1, valueEdge_leftEcef_pointsElement);
  valueEdge_left.ecef_points = valueEdge_leftEcef_points;
  ::ad::physics::Distance valueEdge_leftLength(-1e9);
  valueEdge_left.length = valueEdge_leftLength;
  ::ad::map::point::ENUPointCache valueEdge_leftPrivate_enu_points_cache;
  ::ad::map::point::ENUPointList valueEdge_leftPrivate_enu_points_cacheEnu_points;
  ::ad::map::point::ENUPoint valueEdge_leftPrivate_enu_points_cacheEnu_pointsElement;
  ::ad::map::point::ENUCoordinate valueEdge_leftPrivate_enu_points_cacheEnu_pointsElementX(-1e8);
  valueEdge_leftPrivate_enu_points_cacheEnu_pointsElement.x = valueEdge_leftPrivate_enu_points_cacheEnu_pointsElementX;
  ::ad::map::point::ENUCoordinate valueEdge_leftPrivate_enu_points_cacheEnu_pointsElementY(-1e8);
  valueEdge_leftPrivate_enu_points_cacheEnu_pointsElement.y = valueEdge_leftPrivate_enu_points_cacheEnu_pointsElementY;
  ::ad::map::point::ENUCoordinate valueEdge_leftPrivate_enu_points_cacheEnu_pointsElementZ(-1e8);
  valueEdge_leftPrivate_enu_points_cacheEnu_pointsElement.z = valueEdge_leftPrivate_enu_points_cacheEnu_pointsElementZ;
  valueEdge_leftPrivate_enu_points_cacheEnu_points.resize(1, valueEdge_leftPrivate_enu_points_cacheEnu_pointsElement);
  valueEdge_leftPrivate_enu_points_cache.enu_points = valueEdge_leftPrivate_enu_points_cacheEnu_points;
  uint64_t valueEdge_leftPrivate_enu_points_cacheEnu_version{std::numeric_limits<uint64_t>::min()};
  valueEdge_leftPrivate_enu_points_cache.enu_version = valueEdge_leftPrivate_enu_points_cacheEnu_version;
  valueEdge_left.private_enu_points_cache = valueEdge_leftPrivate_enu_points_cache;
  value.edge_left = valueEdge_left;
  ::ad::map::point::Geometry valueEdge_right;
  bool valueEdge_rightIs_valid{true};
  valueEdge_right.is_valid = valueEdge_rightIs_valid;
  bool valueEdge_rightIs_closed{true};
  valueEdge_right.is_closed = valueEdge_rightIs_closed;
  ::ad::map::point::ECEFPointList valueEdge_rightEcef_points;
  ::ad::map::point::ECEFPoint valueEdge_rightEcef_pointsElement;
  ::ad::map::point::ECEFCoordinate valueEdge_rightEcef_pointsElementX(-6400000);
  valueEdge_rightEcef_pointsElement.x = valueEdge_rightEcef_pointsElementX;
  ::ad::map::point::ECEFCoordinate valueEdge_rightEcef_pointsElementY(-6400000);
  valueEdge_rightEcef_pointsElement.y = valueEdge_rightEcef_pointsElementY;
  ::ad::map::point::ECEFCoordinate valueEdge_rightEcef_pointsElementZ(-6400000);
  valueEdge_rightEcef_pointsElement.z = valueEdge_rightEcef_pointsElementZ;
  valueEdge_rightEcef_points.resize(1, valueEdge_rightEcef_pointsElement);
  valueEdge_right.ecef_points = valueEdge_rightEcef_points;
  ::ad::physics::Distance valueEdge_rightLength(-1e9);
  valueEdge_right.length = valueEdge_rightLength;
  ::ad::map::point::ENUPointCache valueEdge_rightPrivate_enu_points_cache;
  ::ad::map::point::ENUPointList valueEdge_rightPrivate_enu_points_cacheEnu_points;
  ::ad::map::point::ENUPoint valueEdge_rightPrivate_enu_points_cacheEnu_pointsElement;
  ::ad::map::point::ENUCoordinate valueEdge_rightPrivate_enu_points_cacheEnu_pointsElementX(-1e8);
  valueEdge_rightPrivate_enu_points_cacheEnu_pointsElement.x
    = valueEdge_rightPrivate_enu_points_cacheEnu_pointsElementX;
  ::ad::map::point::ENUCoordinate valueEdge_rightPrivate_enu_points_cacheEnu_pointsElementY(-1e8);
  valueEdge_rightPrivate_enu_points_cacheEnu_pointsElement.y
    = valueEdge_rightPrivate_enu_points_cacheEnu_pointsElementY;
  ::ad::map::point::ENUCoordinate valueEdge_rightPrivate_enu_points_cacheEnu_pointsElementZ(-1e8);
  valueEdge_rightPrivate_enu_points_cacheEnu_pointsElement.z
    = valueEdge_rightPrivate_enu_points_cacheEnu_pointsElementZ;
  valueEdge_rightPrivate_enu_points_cacheEnu_points.resize(1, valueEdge_rightPrivate_enu_points_cacheEnu_pointsElement);
  valueEdge_rightPrivate_enu_points_cache.enu_points = valueEdge_rightPrivate_enu_points_cacheEnu_points;
  uint64_t valueEdge_rightPrivate_enu_points_cacheEnu_version{std::numeric_limits<uint64_t>::min()};
  valueEdge_rightPrivate_enu_points_cache.enu_version = valueEdge_rightPrivate_enu_points_cacheEnu_version;
  valueEdge_right.private_enu_points_cache = valueEdge_rightPrivate_enu_points_cache;
  value.edge_right = valueEdge_right;
  ::ad::map::lane::ContactLaneList valueContact_lanes;
  ::ad::map::lane::ContactLane valueContact_lanesElement;
  ::ad::map::lane::LaneId valueContact_lanesElementTo_lane(1);
  valueContact_lanesElement.to_lane = valueContact_lanesElementTo_lane;
  ::ad::map::lane::ContactLocation valueContact_lanesElementLocation(::ad::map::lane::ContactLocation::INVALID);
  valueContact_lanesElement.location = valueContact_lanesElementLocation;
  ::ad::map::lane::ContactTypeList valueContact_lanesElementTypes;
  ::ad::map::lane::ContactType valueContact_lanesElementTypesElement(::ad::map::lane::ContactType::INVALID);
  valueContact_lanesElementTypes.resize(1, valueContact_lanesElementTypesElement);
  valueContact_lanesElement.types = valueContact_lanesElementTypes;
  ::ad::map::restriction::Restrictions valueContact_lanesElementRestrictions;
  ::ad::map::restriction::RestrictionList valueContact_lanesElementRestrictionsConjunctions;
  ::ad::map::restriction::Restriction valueContact_lanesElementRestrictionsConjunctionsElement;
  bool valueContact_lanesElementRestrictionsConjunctionsElementNegated{true};
  valueContact_lanesElementRestrictionsConjunctionsElement.negated
    = valueContact_lanesElementRestrictionsConjunctionsElementNegated;
  ::ad::map::restriction::RoadUserTypeList valueContact_lanesElementRestrictionsConjunctionsElementRoad_user_types;
  ::ad::map::restriction::RoadUserType valueContact_lanesElementRestrictionsConjunctionsElementRoad_user_typesElement(
    ::ad::map::restriction::RoadUserType::INVALID);
  valueContact_lanesElementRestrictionsConjunctionsElementRoad_user_types.resize(
    1, valueContact_lanesElementRestrictionsConjunctionsElementRoad_user_typesElement);
  valueContact_lanesElementRestrictionsConjunctionsElement.road_user_types
    = valueContact_lanesElementRestrictionsConjunctionsElementRoad_user_types;
  ::ad::map::restriction::PassengerCount valueContact_lanesElementRestrictionsConjunctionsElementPassengers_min(
    std::numeric_limits<::ad::map::restriction::PassengerCount>::lowest());
  valueContact_lanesElementRestrictionsConjunctionsElement.passengers_min
    = valueContact_lanesElementRestrictionsConjunctionsElementPassengers_min;
  valueContact_lanesElementRestrictionsConjunctions.resize(1, valueContact_lanesElementRestrictionsConjunctionsElement);
  valueContact_lanesElementRestrictions.conjunctions = valueContact_lanesElementRestrictionsConjunctions;
  ::ad::map::restriction::RestrictionList valueContact_lanesElementRestrictionsDisjunctions;
  ::ad::map::restriction::Restriction valueContact_lanesElementRestrictionsDisjunctionsElement;
  bool valueContact_lanesElementRestrictionsDisjunctionsElementNegated{true};
  valueContact_lanesElementRestrictionsDisjunctionsElement.negated
    = valueContact_lanesElementRestrictionsDisjunctionsElementNegated;
  ::ad::map::restriction::RoadUserTypeList valueContact_lanesElementRestrictionsDisjunctionsElementRoad_user_types;
  ::ad::map::restriction::RoadUserType valueContact_lanesElementRestrictionsDisjunctionsElementRoad_user_typesElement(
    ::ad::map::restriction::RoadUserType::INVALID);
  valueContact_lanesElementRestrictionsDisjunctionsElementRoad_user_types.resize(
    1, valueContact_lanesElementRestrictionsDisjunctionsElementRoad_user_typesElement);
  valueContact_lanesElementRestrictionsDisjunctionsElement.road_user_types
    = valueContact_lanesElementRestrictionsDisjunctionsElementRoad_user_types;
  ::ad::map::restriction::PassengerCount valueContact_lanesElementRestrictionsDisjunctionsElementPassengers_min(
    std::numeric_limits<::ad::map::restriction::PassengerCount>::lowest());
  valueContact_lanesElementRestrictionsDisjunctionsElement.passengers_min
    = valueContact_lanesElementRestrictionsDisjunctionsElementPassengers_min;
  valueContact_lanesElementRestrictionsDisjunctions.resize(1, valueContact_lanesElementRestrictionsDisjunctionsElement);
  valueContact_lanesElementRestrictions.disjunctions = valueContact_lanesElementRestrictionsDisjunctions;
  valueContact_lanesElement.restrictions = valueContact_lanesElementRestrictions;
  ::ad::map::landmark::LandmarkId valueContact_lanesElementLandmark_id(
    std::numeric_limits<::ad::map::landmark::LandmarkId>::lowest());
  valueContact_lanesElement.landmark_id = valueContact_lanesElementLandmark_id;
  valueContact_lanes.resize(1, valueContact_lanesElement);
  value.contact_lanes = valueContact_lanes;
  ::ad::map::lane::ComplianceVersion valueCompliance_version(
    std::numeric_limits<::ad::map::lane::ComplianceVersion>::lowest());
  value.compliance_version = valueCompliance_version;
  ::ad::map::point::BoundingSphere valueBounding_sphere;
  ::ad::map::point::ECEFPoint valueBounding_sphereCenter;
  ::ad::map::point::ECEFCoordinate valueBounding_sphereCenterX(-6400000);
  valueBounding_sphereCenter.x = valueBounding_sphereCenterX;
  ::ad::map::point::ECEFCoordinate valueBounding_sphereCenterY(-6400000);
  valueBounding_sphereCenter.y = valueBounding_sphereCenterY;
  ::ad::map::point::ECEFCoordinate valueBounding_sphereCenterZ(-6400000);
  valueBounding_sphereCenter.z = valueBounding_sphereCenterZ;
  valueBounding_sphere.center = valueBounding_sphereCenter;
  ::ad::physics::Distance valueBounding_sphereRadius(-1e9);
  valueBounding_sphere.radius = valueBounding_sphereRadius;
  value.bounding_sphere = valueBounding_sphere;
  ::ad::map::landmark::LandmarkIdList valueVisible_landmarks;
  ::ad::map::landmark::LandmarkId valueVisible_landmarksElement(
    std::numeric_limits<::ad::map::landmark::LandmarkId>::lowest());
  valueVisible_landmarks.resize(1, valueVisible_landmarksElement);
  value.visible_landmarks = valueVisible_landmarks;

  // override member with data type value above input range maximum
  ::ad::physics::Distance invalidInitializedMember(1e9 * 1.1);
  value.width = invalidInitializedMember;
  ASSERT_FALSE(withinValidInputRange(value));
}

TEST(LaneValidInputRangeTests, testValidInputRangewidthDefault)
{
  ::ad::map::lane::Lane value;
  ::ad::physics::Distance valueDefault;
  value.width = valueDefault;
  ASSERT_FALSE(withinValidInputRange(value));
}

TEST(LaneValidInputRangeTests, testValidInputRangeWidth_rangeTooSmall)
{
  ::ad::map::lane::Lane value;
  ::ad::map::lane::LaneId valueId(1);
  value.id = valueId;
  ::ad::map::lane::LaneType valueType(::ad::map::lane::LaneType::INVALID);
  value.type = valueType;
  ::ad::map::lane::LaneDirection valueDirection(::ad::map::lane::LaneDirection::INVALID);
  value.direction = valueDirection;
  ::ad::map::restriction::Restrictions valueRestrictions;
  ::ad::map::restriction::RestrictionList valueRestrictionsConjunctions;
  ::ad::map::restriction::Restriction valueRestrictionsConjunctionsElement;
  bool valueRestrictionsConjunctionsElementNegated{true};
  valueRestrictionsConjunctionsElement.negated = valueRestrictionsConjunctionsElementNegated;
  ::ad::map::restriction::RoadUserTypeList valueRestrictionsConjunctionsElementRoad_user_types;
  ::ad::map::restriction::RoadUserType valueRestrictionsConjunctionsElementRoad_user_typesElement(
    ::ad::map::restriction::RoadUserType::INVALID);
  valueRestrictionsConjunctionsElementRoad_user_types.resize(
    1, valueRestrictionsConjunctionsElementRoad_user_typesElement);
  valueRestrictionsConjunctionsElement.road_user_types = valueRestrictionsConjunctionsElementRoad_user_types;
  ::ad::map::restriction::PassengerCount valueRestrictionsConjunctionsElementPassengers_min(
    std::numeric_limits<::ad::map::restriction::PassengerCount>::lowest());
  valueRestrictionsConjunctionsElement.passengers_min = valueRestrictionsConjunctionsElementPassengers_min;
  valueRestrictionsConjunctions.resize(1, valueRestrictionsConjunctionsElement);
  valueRestrictions.conjunctions = valueRestrictionsConjunctions;
  ::ad::map::restriction::RestrictionList valueRestrictionsDisjunctions;
  ::ad::map::restriction::Restriction valueRestrictionsDisjunctionsElement;
  bool valueRestrictionsDisjunctionsElementNegated{true};
  valueRestrictionsDisjunctionsElement.negated = valueRestrictionsDisjunctionsElementNegated;
  ::ad::map::restriction::RoadUserTypeList valueRestrictionsDisjunctionsElementRoad_user_types;
  ::ad::map::restriction::RoadUserType valueRestrictionsDisjunctionsElementRoad_user_typesElement(
    ::ad::map::restriction::RoadUserType::INVALID);
  valueRestrictionsDisjunctionsElementRoad_user_types.resize(
    1, valueRestrictionsDisjunctionsElementRoad_user_typesElement);
  valueRestrictionsDisjunctionsElement.road_user_types = valueRestrictionsDisjunctionsElementRoad_user_types;
  ::ad::map::restriction::PassengerCount valueRestrictionsDisjunctionsElementPassengers_min(
    std::numeric_limits<::ad::map::restriction::PassengerCount>::lowest());
  valueRestrictionsDisjunctionsElement.passengers_min = valueRestrictionsDisjunctionsElementPassengers_min;
  valueRestrictionsDisjunctions.resize(1, valueRestrictionsDisjunctionsElement);
  valueRestrictions.disjunctions = valueRestrictionsDisjunctions;
  value.restrictions = valueRestrictions;
  ::ad::physics::Distance valueLength(-1e9);
  value.length = valueLength;
  ::ad::physics::MetricRange valueLength_range;
  ::ad::physics::Distance valueLength_rangeMinimum(-1e9);
  valueLength_rangeMinimum = ::ad::physics::Distance(0.); // set to valid value within struct
  valueLength_range.minimum = valueLength_rangeMinimum;
  ::ad::physics::Distance valueLength_rangeMaximum(-1e9);
  valueLength_range.maximum = valueLength_rangeMaximum;
  valueLength_range.maximum = valueLength_range.minimum;
  valueLength_range.minimum = valueLength_range.maximum;
  value.length_range = valueLength_range;
  ::ad::physics::Distance valueWidth(-1e9);
  value.width = valueWidth;
  ::ad::physics::MetricRange valueWidth_range;
  ::ad::physics::Distance valueWidth_rangeMinimum(-1e9);
  valueWidth_rangeMinimum = ::ad::physics::Distance(0.); // set to valid value within struct
  valueWidth_range.minimum = valueWidth_rangeMinimum;
  ::ad::physics::Distance valueWidth_rangeMaximum(-1e9);
  valueWidth_range.maximum = valueWidth_rangeMaximum;
  valueWidth_range.maximum = valueWidth_range.minimum;
  valueWidth_range.minimum = valueWidth_range.maximum;
  value.width_range = valueWidth_range;
  ::ad::map::restriction::SpeedLimitList valueSpeed_limits;
  ::ad::map::restriction::SpeedLimit valueSpeed_limitsElement;
  ::ad::physics::Speed valueSpeed_limitsElementSpeed_limit(-100.);
  valueSpeed_limitsElement.speed_limit = valueSpeed_limitsElementSpeed_limit;
  ::ad::physics::ParametricRange valueSpeed_limitsElementLane_piece;
  ::ad::physics::ParametricValue valueSpeed_limitsElementLane_pieceMinimum(0.);
  valueSpeed_limitsElementLane_piece.minimum = valueSpeed_limitsElementLane_pieceMinimum;
  ::ad::physics::ParametricValue valueSpeed_limitsElementLane_pieceMaximum(0.);
  valueSpeed_limitsElementLane_piece.maximum = valueSpeed_limitsElementLane_pieceMaximum;
  valueSpeed_limitsElementLane_piece.maximum = valueSpeed_limitsElementLane_piece.minimum;
  valueSpeed_limitsElementLane_piece.minimum = valueSpeed_limitsElementLane_piece.maximum;
  valueSpeed_limitsElement.lane_piece = valueSpeed_limitsElementLane_piece;
  valueSpeed_limits.resize(1, valueSpeed_limitsElement);
  value.speed_limits = valueSpeed_limits;
  ::ad::map::point::Geometry valueEdge_left;
  bool valueEdge_leftIs_valid{true};
  valueEdge_left.is_valid = valueEdge_leftIs_valid;
  bool valueEdge_leftIs_closed{true};
  valueEdge_left.is_closed = valueEdge_leftIs_closed;
  ::ad::map::point::ECEFPointList valueEdge_leftEcef_points;
  ::ad::map::point::ECEFPoint valueEdge_leftEcef_pointsElement;
  ::ad::map::point::ECEFCoordinate valueEdge_leftEcef_pointsElementX(-6400000);
  valueEdge_leftEcef_pointsElement.x = valueEdge_leftEcef_pointsElementX;
  ::ad::map::point::ECEFCoordinate valueEdge_leftEcef_pointsElementY(-6400000);
  valueEdge_leftEcef_pointsElement.y = valueEdge_leftEcef_pointsElementY;
  ::ad::map::point::ECEFCoordinate valueEdge_leftEcef_pointsElementZ(-6400000);
  valueEdge_leftEcef_pointsElement.z = valueEdge_leftEcef_pointsElementZ;
  valueEdge_leftEcef_points.resize(1, valueEdge_leftEcef_pointsElement);
  valueEdge_left.ecef_points = valueEdge_leftEcef_points;
  ::ad::physics::Distance valueEdge_leftLength(-1e9);
  valueEdge_left.length = valueEdge_leftLength;
  ::ad::map::point::ENUPointCache valueEdge_leftPrivate_enu_points_cache;
  ::ad::map::point::ENUPointList valueEdge_leftPrivate_enu_points_cacheEnu_points;
  ::ad::map::point::ENUPoint valueEdge_leftPrivate_enu_points_cacheEnu_pointsElement;
  ::ad::map::point::ENUCoordinate valueEdge_leftPrivate_enu_points_cacheEnu_pointsElementX(-1e8);
  valueEdge_leftPrivate_enu_points_cacheEnu_pointsElement.x = valueEdge_leftPrivate_enu_points_cacheEnu_pointsElementX;
  ::ad::map::point::ENUCoordinate valueEdge_leftPrivate_enu_points_cacheEnu_pointsElementY(-1e8);
  valueEdge_leftPrivate_enu_points_cacheEnu_pointsElement.y = valueEdge_leftPrivate_enu_points_cacheEnu_pointsElementY;
  ::ad::map::point::ENUCoordinate valueEdge_leftPrivate_enu_points_cacheEnu_pointsElementZ(-1e8);
  valueEdge_leftPrivate_enu_points_cacheEnu_pointsElement.z = valueEdge_leftPrivate_enu_points_cacheEnu_pointsElementZ;
  valueEdge_leftPrivate_enu_points_cacheEnu_points.resize(1, valueEdge_leftPrivate_enu_points_cacheEnu_pointsElement);
  valueEdge_leftPrivate_enu_points_cache.enu_points = valueEdge_leftPrivate_enu_points_cacheEnu_points;
  uint64_t valueEdge_leftPrivate_enu_points_cacheEnu_version{std::numeric_limits<uint64_t>::min()};
  valueEdge_leftPrivate_enu_points_cache.enu_version = valueEdge_leftPrivate_enu_points_cacheEnu_version;
  valueEdge_left.private_enu_points_cache = valueEdge_leftPrivate_enu_points_cache;
  value.edge_left = valueEdge_left;
  ::ad::map::point::Geometry valueEdge_right;
  bool valueEdge_rightIs_valid{true};
  valueEdge_right.is_valid = valueEdge_rightIs_valid;
  bool valueEdge_rightIs_closed{true};
  valueEdge_right.is_closed = valueEdge_rightIs_closed;
  ::ad::map::point::ECEFPointList valueEdge_rightEcef_points;
  ::ad::map::point::ECEFPoint valueEdge_rightEcef_pointsElement;
  ::ad::map::point::ECEFCoordinate valueEdge_rightEcef_pointsElementX(-6400000);
  valueEdge_rightEcef_pointsElement.x = valueEdge_rightEcef_pointsElementX;
  ::ad::map::point::ECEFCoordinate valueEdge_rightEcef_pointsElementY(-6400000);
  valueEdge_rightEcef_pointsElement.y = valueEdge_rightEcef_pointsElementY;
  ::ad::map::point::ECEFCoordinate valueEdge_rightEcef_pointsElementZ(-6400000);
  valueEdge_rightEcef_pointsElement.z = valueEdge_rightEcef_pointsElementZ;
  valueEdge_rightEcef_points.resize(1, valueEdge_rightEcef_pointsElement);
  valueEdge_right.ecef_points = valueEdge_rightEcef_points;
  ::ad::physics::Distance valueEdge_rightLength(-1e9);
  valueEdge_right.length = valueEdge_rightLength;
  ::ad::map::point::ENUPointCache valueEdge_rightPrivate_enu_points_cache;
  ::ad::map::point::ENUPointList valueEdge_rightPrivate_enu_points_cacheEnu_points;
  ::ad::map::point::ENUPoint valueEdge_rightPrivate_enu_points_cacheEnu_pointsElement;
  ::ad::map::point::ENUCoordinate valueEdge_rightPrivate_enu_points_cacheEnu_pointsElementX(-1e8);
  valueEdge_rightPrivate_enu_points_cacheEnu_pointsElement.x
    = valueEdge_rightPrivate_enu_points_cacheEnu_pointsElementX;
  ::ad::map::point::ENUCoordinate valueEdge_rightPrivate_enu_points_cacheEnu_pointsElementY(-1e8);
  valueEdge_rightPrivate_enu_points_cacheEnu_pointsElement.y
    = valueEdge_rightPrivate_enu_points_cacheEnu_pointsElementY;
  ::ad::map::point::ENUCoordinate valueEdge_rightPrivate_enu_points_cacheEnu_pointsElementZ(-1e8);
  valueEdge_rightPrivate_enu_points_cacheEnu_pointsElement.z
    = valueEdge_rightPrivate_enu_points_cacheEnu_pointsElementZ;
  valueEdge_rightPrivate_enu_points_cacheEnu_points.resize(1, valueEdge_rightPrivate_enu_points_cacheEnu_pointsElement);
  valueEdge_rightPrivate_enu_points_cache.enu_points = valueEdge_rightPrivate_enu_points_cacheEnu_points;
  uint64_t valueEdge_rightPrivate_enu_points_cacheEnu_version{std::numeric_limits<uint64_t>::min()};
  valueEdge_rightPrivate_enu_points_cache.enu_version = valueEdge_rightPrivate_enu_points_cacheEnu_version;
  valueEdge_right.private_enu_points_cache = valueEdge_rightPrivate_enu_points_cache;
  value.edge_right = valueEdge_right;
  ::ad::map::lane::ContactLaneList valueContact_lanes;
  ::ad::map::lane::ContactLane valueContact_lanesElement;
  ::ad::map::lane::LaneId valueContact_lanesElementTo_lane(1);
  valueContact_lanesElement.to_lane = valueContact_lanesElementTo_lane;
  ::ad::map::lane::ContactLocation valueContact_lanesElementLocation(::ad::map::lane::ContactLocation::INVALID);
  valueContact_lanesElement.location = valueContact_lanesElementLocation;
  ::ad::map::lane::ContactTypeList valueContact_lanesElementTypes;
  ::ad::map::lane::ContactType valueContact_lanesElementTypesElement(::ad::map::lane::ContactType::INVALID);
  valueContact_lanesElementTypes.resize(1, valueContact_lanesElementTypesElement);
  valueContact_lanesElement.types = valueContact_lanesElementTypes;
  ::ad::map::restriction::Restrictions valueContact_lanesElementRestrictions;
  ::ad::map::restriction::RestrictionList valueContact_lanesElementRestrictionsConjunctions;
  ::ad::map::restriction::Restriction valueContact_lanesElementRestrictionsConjunctionsElement;
  bool valueContact_lanesElementRestrictionsConjunctionsElementNegated{true};
  valueContact_lanesElementRestrictionsConjunctionsElement.negated
    = valueContact_lanesElementRestrictionsConjunctionsElementNegated;
  ::ad::map::restriction::RoadUserTypeList valueContact_lanesElementRestrictionsConjunctionsElementRoad_user_types;
  ::ad::map::restriction::RoadUserType valueContact_lanesElementRestrictionsConjunctionsElementRoad_user_typesElement(
    ::ad::map::restriction::RoadUserType::INVALID);
  valueContact_lanesElementRestrictionsConjunctionsElementRoad_user_types.resize(
    1, valueContact_lanesElementRestrictionsConjunctionsElementRoad_user_typesElement);
  valueContact_lanesElementRestrictionsConjunctionsElement.road_user_types
    = valueContact_lanesElementRestrictionsConjunctionsElementRoad_user_types;
  ::ad::map::restriction::PassengerCount valueContact_lanesElementRestrictionsConjunctionsElementPassengers_min(
    std::numeric_limits<::ad::map::restriction::PassengerCount>::lowest());
  valueContact_lanesElementRestrictionsConjunctionsElement.passengers_min
    = valueContact_lanesElementRestrictionsConjunctionsElementPassengers_min;
  valueContact_lanesElementRestrictionsConjunctions.resize(1, valueContact_lanesElementRestrictionsConjunctionsElement);
  valueContact_lanesElementRestrictions.conjunctions = valueContact_lanesElementRestrictionsConjunctions;
  ::ad::map::restriction::RestrictionList valueContact_lanesElementRestrictionsDisjunctions;
  ::ad::map::restriction::Restriction valueContact_lanesElementRestrictionsDisjunctionsElement;
  bool valueContact_lanesElementRestrictionsDisjunctionsElementNegated{true};
  valueContact_lanesElementRestrictionsDisjunctionsElement.negated
    = valueContact_lanesElementRestrictionsDisjunctionsElementNegated;
  ::ad::map::restriction::RoadUserTypeList valueContact_lanesElementRestrictionsDisjunctionsElementRoad_user_types;
  ::ad::map::restriction::RoadUserType valueContact_lanesElementRestrictionsDisjunctionsElementRoad_user_typesElement(
    ::ad::map::restriction::RoadUserType::INVALID);
  valueContact_lanesElementRestrictionsDisjunctionsElementRoad_user_types.resize(
    1, valueContact_lanesElementRestrictionsDisjunctionsElementRoad_user_typesElement);
  valueContact_lanesElementRestrictionsDisjunctionsElement.road_user_types
    = valueContact_lanesElementRestrictionsDisjunctionsElementRoad_user_types;
  ::ad::map::restriction::PassengerCount valueContact_lanesElementRestrictionsDisjunctionsElementPassengers_min(
    std::numeric_limits<::ad::map::restriction::PassengerCount>::lowest());
  valueContact_lanesElementRestrictionsDisjunctionsElement.passengers_min
    = valueContact_lanesElementRestrictionsDisjunctionsElementPassengers_min;
  valueContact_lanesElementRestrictionsDisjunctions.resize(1, valueContact_lanesElementRestrictionsDisjunctionsElement);
  valueContact_lanesElementRestrictions.disjunctions = valueContact_lanesElementRestrictionsDisjunctions;
  valueContact_lanesElement.restrictions = valueContact_lanesElementRestrictions;
  ::ad::map::landmark::LandmarkId valueContact_lanesElementLandmark_id(
    std::numeric_limits<::ad::map::landmark::LandmarkId>::lowest());
  valueContact_lanesElement.landmark_id = valueContact_lanesElementLandmark_id;
  valueContact_lanes.resize(1, valueContact_lanesElement);
  value.contact_lanes = valueContact_lanes;
  ::ad::map::lane::ComplianceVersion valueCompliance_version(
    std::numeric_limits<::ad::map::lane::ComplianceVersion>::lowest());
  value.compliance_version = valueCompliance_version;
  ::ad::map::point::BoundingSphere valueBounding_sphere;
  ::ad::map::point::ECEFPoint valueBounding_sphereCenter;
  ::ad::map::point::ECEFCoordinate valueBounding_sphereCenterX(-6400000);
  valueBounding_sphereCenter.x = valueBounding_sphereCenterX;
  ::ad::map::point::ECEFCoordinate valueBounding_sphereCenterY(-6400000);
  valueBounding_sphereCenter.y = valueBounding_sphereCenterY;
  ::ad::map::point::ECEFCoordinate valueBounding_sphereCenterZ(-6400000);
  valueBounding_sphereCenter.z = valueBounding_sphereCenterZ;
  valueBounding_sphere.center = valueBounding_sphereCenter;
  ::ad::physics::Distance valueBounding_sphereRadius(-1e9);
  valueBounding_sphere.radius = valueBounding_sphereRadius;
  value.bounding_sphere = valueBounding_sphere;
  ::ad::map::landmark::LandmarkIdList valueVisible_landmarks;
  ::ad::map::landmark::LandmarkId valueVisible_landmarksElement(
    std::numeric_limits<::ad::map::landmark::LandmarkId>::lowest());
  valueVisible_landmarks.resize(1, valueVisible_landmarksElement);
  value.visible_landmarks = valueVisible_landmarks;

  // override member with data type value below input range minimum
  ::ad::physics::MetricRange invalidInitializedMember;
  ::ad::physics::Distance invalidInitializedMemberMinimum(-1e9 * 1.1);
  invalidInitializedMember.minimum = invalidInitializedMemberMinimum;
  value.width_range = invalidInitializedMember;
  ASSERT_FALSE(withinValidInputRange(value));
}

TEST(LaneValidInputRangeTests, testValidInputRangeWidth_rangeTooBig)
{
  ::ad::map::lane::Lane value;
  ::ad::map::lane::LaneId valueId(1);
  value.id = valueId;
  ::ad::map::lane::LaneType valueType(::ad::map::lane::LaneType::INVALID);
  value.type = valueType;
  ::ad::map::lane::LaneDirection valueDirection(::ad::map::lane::LaneDirection::INVALID);
  value.direction = valueDirection;
  ::ad::map::restriction::Restrictions valueRestrictions;
  ::ad::map::restriction::RestrictionList valueRestrictionsConjunctions;
  ::ad::map::restriction::Restriction valueRestrictionsConjunctionsElement;
  bool valueRestrictionsConjunctionsElementNegated{true};
  valueRestrictionsConjunctionsElement.negated = valueRestrictionsConjunctionsElementNegated;
  ::ad::map::restriction::RoadUserTypeList valueRestrictionsConjunctionsElementRoad_user_types;
  ::ad::map::restriction::RoadUserType valueRestrictionsConjunctionsElementRoad_user_typesElement(
    ::ad::map::restriction::RoadUserType::INVALID);
  valueRestrictionsConjunctionsElementRoad_user_types.resize(
    1, valueRestrictionsConjunctionsElementRoad_user_typesElement);
  valueRestrictionsConjunctionsElement.road_user_types = valueRestrictionsConjunctionsElementRoad_user_types;
  ::ad::map::restriction::PassengerCount valueRestrictionsConjunctionsElementPassengers_min(
    std::numeric_limits<::ad::map::restriction::PassengerCount>::lowest());
  valueRestrictionsConjunctionsElement.passengers_min = valueRestrictionsConjunctionsElementPassengers_min;
  valueRestrictionsConjunctions.resize(1, valueRestrictionsConjunctionsElement);
  valueRestrictions.conjunctions = valueRestrictionsConjunctions;
  ::ad::map::restriction::RestrictionList valueRestrictionsDisjunctions;
  ::ad::map::restriction::Restriction valueRestrictionsDisjunctionsElement;
  bool valueRestrictionsDisjunctionsElementNegated{true};
  valueRestrictionsDisjunctionsElement.negated = valueRestrictionsDisjunctionsElementNegated;
  ::ad::map::restriction::RoadUserTypeList valueRestrictionsDisjunctionsElementRoad_user_types;
  ::ad::map::restriction::RoadUserType valueRestrictionsDisjunctionsElementRoad_user_typesElement(
    ::ad::map::restriction::RoadUserType::INVALID);
  valueRestrictionsDisjunctionsElementRoad_user_types.resize(
    1, valueRestrictionsDisjunctionsElementRoad_user_typesElement);
  valueRestrictionsDisjunctionsElement.road_user_types = valueRestrictionsDisjunctionsElementRoad_user_types;
  ::ad::map::restriction::PassengerCount valueRestrictionsDisjunctionsElementPassengers_min(
    std::numeric_limits<::ad::map::restriction::PassengerCount>::lowest());
  valueRestrictionsDisjunctionsElement.passengers_min = valueRestrictionsDisjunctionsElementPassengers_min;
  valueRestrictionsDisjunctions.resize(1, valueRestrictionsDisjunctionsElement);
  valueRestrictions.disjunctions = valueRestrictionsDisjunctions;
  value.restrictions = valueRestrictions;
  ::ad::physics::Distance valueLength(-1e9);
  value.length = valueLength;
  ::ad::physics::MetricRange valueLength_range;
  ::ad::physics::Distance valueLength_rangeMinimum(-1e9);
  valueLength_rangeMinimum = ::ad::physics::Distance(0.); // set to valid value within struct
  valueLength_range.minimum = valueLength_rangeMinimum;
  ::ad::physics::Distance valueLength_rangeMaximum(-1e9);
  valueLength_range.maximum = valueLength_rangeMaximum;
  valueLength_range.maximum = valueLength_range.minimum;
  valueLength_range.minimum = valueLength_range.maximum;
  value.length_range = valueLength_range;
  ::ad::physics::Distance valueWidth(-1e9);
  value.width = valueWidth;
  ::ad::physics::MetricRange valueWidth_range;
  ::ad::physics::Distance valueWidth_rangeMinimum(-1e9);
  valueWidth_rangeMinimum = ::ad::physics::Distance(0.); // set to valid value within struct
  valueWidth_range.minimum = valueWidth_rangeMinimum;
  ::ad::physics::Distance valueWidth_rangeMaximum(-1e9);
  valueWidth_range.maximum = valueWidth_rangeMaximum;
  valueWidth_range.maximum = valueWidth_range.minimum;
  valueWidth_range.minimum = valueWidth_range.maximum;
  value.width_range = valueWidth_range;
  ::ad::map::restriction::SpeedLimitList valueSpeed_limits;
  ::ad::map::restriction::SpeedLimit valueSpeed_limitsElement;
  ::ad::physics::Speed valueSpeed_limitsElementSpeed_limit(-100.);
  valueSpeed_limitsElement.speed_limit = valueSpeed_limitsElementSpeed_limit;
  ::ad::physics::ParametricRange valueSpeed_limitsElementLane_piece;
  ::ad::physics::ParametricValue valueSpeed_limitsElementLane_pieceMinimum(0.);
  valueSpeed_limitsElementLane_piece.minimum = valueSpeed_limitsElementLane_pieceMinimum;
  ::ad::physics::ParametricValue valueSpeed_limitsElementLane_pieceMaximum(0.);
  valueSpeed_limitsElementLane_piece.maximum = valueSpeed_limitsElementLane_pieceMaximum;
  valueSpeed_limitsElementLane_piece.maximum = valueSpeed_limitsElementLane_piece.minimum;
  valueSpeed_limitsElementLane_piece.minimum = valueSpeed_limitsElementLane_piece.maximum;
  valueSpeed_limitsElement.lane_piece = valueSpeed_limitsElementLane_piece;
  valueSpeed_limits.resize(1, valueSpeed_limitsElement);
  value.speed_limits = valueSpeed_limits;
  ::ad::map::point::Geometry valueEdge_left;
  bool valueEdge_leftIs_valid{true};
  valueEdge_left.is_valid = valueEdge_leftIs_valid;
  bool valueEdge_leftIs_closed{true};
  valueEdge_left.is_closed = valueEdge_leftIs_closed;
  ::ad::map::point::ECEFPointList valueEdge_leftEcef_points;
  ::ad::map::point::ECEFPoint valueEdge_leftEcef_pointsElement;
  ::ad::map::point::ECEFCoordinate valueEdge_leftEcef_pointsElementX(-6400000);
  valueEdge_leftEcef_pointsElement.x = valueEdge_leftEcef_pointsElementX;
  ::ad::map::point::ECEFCoordinate valueEdge_leftEcef_pointsElementY(-6400000);
  valueEdge_leftEcef_pointsElement.y = valueEdge_leftEcef_pointsElementY;
  ::ad::map::point::ECEFCoordinate valueEdge_leftEcef_pointsElementZ(-6400000);
  valueEdge_leftEcef_pointsElement.z = valueEdge_leftEcef_pointsElementZ;
  valueEdge_leftEcef_points.resize(1, valueEdge_leftEcef_pointsElement);
  valueEdge_left.ecef_points = valueEdge_leftEcef_points;
  ::ad::physics::Distance valueEdge_leftLength(-1e9);
  valueEdge_left.length = valueEdge_leftLength;
  ::ad::map::point::ENUPointCache valueEdge_leftPrivate_enu_points_cache;
  ::ad::map::point::ENUPointList valueEdge_leftPrivate_enu_points_cacheEnu_points;
  ::ad::map::point::ENUPoint valueEdge_leftPrivate_enu_points_cacheEnu_pointsElement;
  ::ad::map::point::ENUCoordinate valueEdge_leftPrivate_enu_points_cacheEnu_pointsElementX(-1e8);
  valueEdge_leftPrivate_enu_points_cacheEnu_pointsElement.x = valueEdge_leftPrivate_enu_points_cacheEnu_pointsElementX;
  ::ad::map::point::ENUCoordinate valueEdge_leftPrivate_enu_points_cacheEnu_pointsElementY(-1e8);
  valueEdge_leftPrivate_enu_points_cacheEnu_pointsElement.y = valueEdge_leftPrivate_enu_points_cacheEnu_pointsElementY;
  ::ad::map::point::ENUCoordinate valueEdge_leftPrivate_enu_points_cacheEnu_pointsElementZ(-1e8);
  valueEdge_leftPrivate_enu_points_cacheEnu_pointsElement.z = valueEdge_leftPrivate_enu_points_cacheEnu_pointsElementZ;
  valueEdge_leftPrivate_enu_points_cacheEnu_points.resize(1, valueEdge_leftPrivate_enu_points_cacheEnu_pointsElement);
  valueEdge_leftPrivate_enu_points_cache.enu_points = valueEdge_leftPrivate_enu_points_cacheEnu_points;
  uint64_t valueEdge_leftPrivate_enu_points_cacheEnu_version{std::numeric_limits<uint64_t>::min()};
  valueEdge_leftPrivate_enu_points_cache.enu_version = valueEdge_leftPrivate_enu_points_cacheEnu_version;
  valueEdge_left.private_enu_points_cache = valueEdge_leftPrivate_enu_points_cache;
  value.edge_left = valueEdge_left;
  ::ad::map::point::Geometry valueEdge_right;
  bool valueEdge_rightIs_valid{true};
  valueEdge_right.is_valid = valueEdge_rightIs_valid;
  bool valueEdge_rightIs_closed{true};
  valueEdge_right.is_closed = valueEdge_rightIs_closed;
  ::ad::map::point::ECEFPointList valueEdge_rightEcef_points;
  ::ad::map::point::ECEFPoint valueEdge_rightEcef_pointsElement;
  ::ad::map::point::ECEFCoordinate valueEdge_rightEcef_pointsElementX(-6400000);
  valueEdge_rightEcef_pointsElement.x = valueEdge_rightEcef_pointsElementX;
  ::ad::map::point::ECEFCoordinate valueEdge_rightEcef_pointsElementY(-6400000);
  valueEdge_rightEcef_pointsElement.y = valueEdge_rightEcef_pointsElementY;
  ::ad::map::point::ECEFCoordinate valueEdge_rightEcef_pointsElementZ(-6400000);
  valueEdge_rightEcef_pointsElement.z = valueEdge_rightEcef_pointsElementZ;
  valueEdge_rightEcef_points.resize(1, valueEdge_rightEcef_pointsElement);
  valueEdge_right.ecef_points = valueEdge_rightEcef_points;
  ::ad::physics::Distance valueEdge_rightLength(-1e9);
  valueEdge_right.length = valueEdge_rightLength;
  ::ad::map::point::ENUPointCache valueEdge_rightPrivate_enu_points_cache;
  ::ad::map::point::ENUPointList valueEdge_rightPrivate_enu_points_cacheEnu_points;
  ::ad::map::point::ENUPoint valueEdge_rightPrivate_enu_points_cacheEnu_pointsElement;
  ::ad::map::point::ENUCoordinate valueEdge_rightPrivate_enu_points_cacheEnu_pointsElementX(-1e8);
  valueEdge_rightPrivate_enu_points_cacheEnu_pointsElement.x
    = valueEdge_rightPrivate_enu_points_cacheEnu_pointsElementX;
  ::ad::map::point::ENUCoordinate valueEdge_rightPrivate_enu_points_cacheEnu_pointsElementY(-1e8);
  valueEdge_rightPrivate_enu_points_cacheEnu_pointsElement.y
    = valueEdge_rightPrivate_enu_points_cacheEnu_pointsElementY;
  ::ad::map::point::ENUCoordinate valueEdge_rightPrivate_enu_points_cacheEnu_pointsElementZ(-1e8);
  valueEdge_rightPrivate_enu_points_cacheEnu_pointsElement.z
    = valueEdge_rightPrivate_enu_points_cacheEnu_pointsElementZ;
  valueEdge_rightPrivate_enu_points_cacheEnu_points.resize(1, valueEdge_rightPrivate_enu_points_cacheEnu_pointsElement);
  valueEdge_rightPrivate_enu_points_cache.enu_points = valueEdge_rightPrivate_enu_points_cacheEnu_points;
  uint64_t valueEdge_rightPrivate_enu_points_cacheEnu_version{std::numeric_limits<uint64_t>::min()};
  valueEdge_rightPrivate_enu_points_cache.enu_version = valueEdge_rightPrivate_enu_points_cacheEnu_version;
  valueEdge_right.private_enu_points_cache = valueEdge_rightPrivate_enu_points_cache;
  value.edge_right = valueEdge_right;
  ::ad::map::lane::ContactLaneList valueContact_lanes;
  ::ad::map::lane::ContactLane valueContact_lanesElement;
  ::ad::map::lane::LaneId valueContact_lanesElementTo_lane(1);
  valueContact_lanesElement.to_lane = valueContact_lanesElementTo_lane;
  ::ad::map::lane::ContactLocation valueContact_lanesElementLocation(::ad::map::lane::ContactLocation::INVALID);
  valueContact_lanesElement.location = valueContact_lanesElementLocation;
  ::ad::map::lane::ContactTypeList valueContact_lanesElementTypes;
  ::ad::map::lane::ContactType valueContact_lanesElementTypesElement(::ad::map::lane::ContactType::INVALID);
  valueContact_lanesElementTypes.resize(1, valueContact_lanesElementTypesElement);
  valueContact_lanesElement.types = valueContact_lanesElementTypes;
  ::ad::map::restriction::Restrictions valueContact_lanesElementRestrictions;
  ::ad::map::restriction::RestrictionList valueContact_lanesElementRestrictionsConjunctions;
  ::ad::map::restriction::Restriction valueContact_lanesElementRestrictionsConjunctionsElement;
  bool valueContact_lanesElementRestrictionsConjunctionsElementNegated{true};
  valueContact_lanesElementRestrictionsConjunctionsElement.negated
    = valueContact_lanesElementRestrictionsConjunctionsElementNegated;
  ::ad::map::restriction::RoadUserTypeList valueContact_lanesElementRestrictionsConjunctionsElementRoad_user_types;
  ::ad::map::restriction::RoadUserType valueContact_lanesElementRestrictionsConjunctionsElementRoad_user_typesElement(
    ::ad::map::restriction::RoadUserType::INVALID);
  valueContact_lanesElementRestrictionsConjunctionsElementRoad_user_types.resize(
    1, valueContact_lanesElementRestrictionsConjunctionsElementRoad_user_typesElement);
  valueContact_lanesElementRestrictionsConjunctionsElement.road_user_types
    = valueContact_lanesElementRestrictionsConjunctionsElementRoad_user_types;
  ::ad::map::restriction::PassengerCount valueContact_lanesElementRestrictionsConjunctionsElementPassengers_min(
    std::numeric_limits<::ad::map::restriction::PassengerCount>::lowest());
  valueContact_lanesElementRestrictionsConjunctionsElement.passengers_min
    = valueContact_lanesElementRestrictionsConjunctionsElementPassengers_min;
  valueContact_lanesElementRestrictionsConjunctions.resize(1, valueContact_lanesElementRestrictionsConjunctionsElement);
  valueContact_lanesElementRestrictions.conjunctions = valueContact_lanesElementRestrictionsConjunctions;
  ::ad::map::restriction::RestrictionList valueContact_lanesElementRestrictionsDisjunctions;
  ::ad::map::restriction::Restriction valueContact_lanesElementRestrictionsDisjunctionsElement;
  bool valueContact_lanesElementRestrictionsDisjunctionsElementNegated{true};
  valueContact_lanesElementRestrictionsDisjunctionsElement.negated
    = valueContact_lanesElementRestrictionsDisjunctionsElementNegated;
  ::ad::map::restriction::RoadUserTypeList valueContact_lanesElementRestrictionsDisjunctionsElementRoad_user_types;
  ::ad::map::restriction::RoadUserType valueContact_lanesElementRestrictionsDisjunctionsElementRoad_user_typesElement(
    ::ad::map::restriction::RoadUserType::INVALID);
  valueContact_lanesElementRestrictionsDisjunctionsElementRoad_user_types.resize(
    1, valueContact_lanesElementRestrictionsDisjunctionsElementRoad_user_typesElement);
  valueContact_lanesElementRestrictionsDisjunctionsElement.road_user_types
    = valueContact_lanesElementRestrictionsDisjunctionsElementRoad_user_types;
  ::ad::map::restriction::PassengerCount valueContact_lanesElementRestrictionsDisjunctionsElementPassengers_min(
    std::numeric_limits<::ad::map::restriction::PassengerCount>::lowest());
  valueContact_lanesElementRestrictionsDisjunctionsElement.passengers_min
    = valueContact_lanesElementRestrictionsDisjunctionsElementPassengers_min;
  valueContact_lanesElementRestrictionsDisjunctions.resize(1, valueContact_lanesElementRestrictionsDisjunctionsElement);
  valueContact_lanesElementRestrictions.disjunctions = valueContact_lanesElementRestrictionsDisjunctions;
  valueContact_lanesElement.restrictions = valueContact_lanesElementRestrictions;
  ::ad::map::landmark::LandmarkId valueContact_lanesElementLandmark_id(
    std::numeric_limits<::ad::map::landmark::LandmarkId>::lowest());
  valueContact_lanesElement.landmark_id = valueContact_lanesElementLandmark_id;
  valueContact_lanes.resize(1, valueContact_lanesElement);
  value.contact_lanes = valueContact_lanes;
  ::ad::map::lane::ComplianceVersion valueCompliance_version(
    std::numeric_limits<::ad::map::lane::ComplianceVersion>::lowest());
  value.compliance_version = valueCompliance_version;
  ::ad::map::point::BoundingSphere valueBounding_sphere;
  ::ad::map::point::ECEFPoint valueBounding_sphereCenter;
  ::ad::map::point::ECEFCoordinate valueBounding_sphereCenterX(-6400000);
  valueBounding_sphereCenter.x = valueBounding_sphereCenterX;
  ::ad::map::point::ECEFCoordinate valueBounding_sphereCenterY(-6400000);
  valueBounding_sphereCenter.y = valueBounding_sphereCenterY;
  ::ad::map::point::ECEFCoordinate valueBounding_sphereCenterZ(-6400000);
  valueBounding_sphereCenter.z = valueBounding_sphereCenterZ;
  valueBounding_sphere.center = valueBounding_sphereCenter;
  ::ad::physics::Distance valueBounding_sphereRadius(-1e9);
  valueBounding_sphere.radius = valueBounding_sphereRadius;
  value.bounding_sphere = valueBounding_sphere;
  ::ad::map::landmark::LandmarkIdList valueVisible_landmarks;
  ::ad::map::landmark::LandmarkId valueVisible_landmarksElement(
    std::numeric_limits<::ad::map::landmark::LandmarkId>::lowest());
  valueVisible_landmarks.resize(1, valueVisible_landmarksElement);
  value.visible_landmarks = valueVisible_landmarks;

  // override member with data type value above input range maximum
  ::ad::physics::MetricRange invalidInitializedMember;
  ::ad::physics::Distance invalidInitializedMemberMinimum(1e9 * 1.1);
  invalidInitializedMember.minimum = invalidInitializedMemberMinimum;
  value.width_range = invalidInitializedMember;
  ASSERT_FALSE(withinValidInputRange(value));
}

TEST(LaneValidInputRangeTests, testValidInputRangeEdge_leftTooSmall)
{
  ::ad::map::lane::Lane value;
  ::ad::map::lane::LaneId valueId(1);
  value.id = valueId;
  ::ad::map::lane::LaneType valueType(::ad::map::lane::LaneType::INVALID);
  value.type = valueType;
  ::ad::map::lane::LaneDirection valueDirection(::ad::map::lane::LaneDirection::INVALID);
  value.direction = valueDirection;
  ::ad::map::restriction::Restrictions valueRestrictions;
  ::ad::map::restriction::RestrictionList valueRestrictionsConjunctions;
  ::ad::map::restriction::Restriction valueRestrictionsConjunctionsElement;
  bool valueRestrictionsConjunctionsElementNegated{true};
  valueRestrictionsConjunctionsElement.negated = valueRestrictionsConjunctionsElementNegated;
  ::ad::map::restriction::RoadUserTypeList valueRestrictionsConjunctionsElementRoad_user_types;
  ::ad::map::restriction::RoadUserType valueRestrictionsConjunctionsElementRoad_user_typesElement(
    ::ad::map::restriction::RoadUserType::INVALID);
  valueRestrictionsConjunctionsElementRoad_user_types.resize(
    1, valueRestrictionsConjunctionsElementRoad_user_typesElement);
  valueRestrictionsConjunctionsElement.road_user_types = valueRestrictionsConjunctionsElementRoad_user_types;
  ::ad::map::restriction::PassengerCount valueRestrictionsConjunctionsElementPassengers_min(
    std::numeric_limits<::ad::map::restriction::PassengerCount>::lowest());
  valueRestrictionsConjunctionsElement.passengers_min = valueRestrictionsConjunctionsElementPassengers_min;
  valueRestrictionsConjunctions.resize(1, valueRestrictionsConjunctionsElement);
  valueRestrictions.conjunctions = valueRestrictionsConjunctions;
  ::ad::map::restriction::RestrictionList valueRestrictionsDisjunctions;
  ::ad::map::restriction::Restriction valueRestrictionsDisjunctionsElement;
  bool valueRestrictionsDisjunctionsElementNegated{true};
  valueRestrictionsDisjunctionsElement.negated = valueRestrictionsDisjunctionsElementNegated;
  ::ad::map::restriction::RoadUserTypeList valueRestrictionsDisjunctionsElementRoad_user_types;
  ::ad::map::restriction::RoadUserType valueRestrictionsDisjunctionsElementRoad_user_typesElement(
    ::ad::map::restriction::RoadUserType::INVALID);
  valueRestrictionsDisjunctionsElementRoad_user_types.resize(
    1, valueRestrictionsDisjunctionsElementRoad_user_typesElement);
  valueRestrictionsDisjunctionsElement.road_user_types = valueRestrictionsDisjunctionsElementRoad_user_types;
  ::ad::map::restriction::PassengerCount valueRestrictionsDisjunctionsElementPassengers_min(
    std::numeric_limits<::ad::map::restriction::PassengerCount>::lowest());
  valueRestrictionsDisjunctionsElement.passengers_min = valueRestrictionsDisjunctionsElementPassengers_min;
  valueRestrictionsDisjunctions.resize(1, valueRestrictionsDisjunctionsElement);
  valueRestrictions.disjunctions = valueRestrictionsDisjunctions;
  value.restrictions = valueRestrictions;
  ::ad::physics::Distance valueLength(-1e9);
  value.length = valueLength;
  ::ad::physics::MetricRange valueLength_range;
  ::ad::physics::Distance valueLength_rangeMinimum(-1e9);
  valueLength_rangeMinimum = ::ad::physics::Distance(0.); // set to valid value within struct
  valueLength_range.minimum = valueLength_rangeMinimum;
  ::ad::physics::Distance valueLength_rangeMaximum(-1e9);
  valueLength_range.maximum = valueLength_rangeMaximum;
  valueLength_range.maximum = valueLength_range.minimum;
  valueLength_range.minimum = valueLength_range.maximum;
  value.length_range = valueLength_range;
  ::ad::physics::Distance valueWidth(-1e9);
  value.width = valueWidth;
  ::ad::physics::MetricRange valueWidth_range;
  ::ad::physics::Distance valueWidth_rangeMinimum(-1e9);
  valueWidth_rangeMinimum = ::ad::physics::Distance(0.); // set to valid value within struct
  valueWidth_range.minimum = valueWidth_rangeMinimum;
  ::ad::physics::Distance valueWidth_rangeMaximum(-1e9);
  valueWidth_range.maximum = valueWidth_rangeMaximum;
  valueWidth_range.maximum = valueWidth_range.minimum;
  valueWidth_range.minimum = valueWidth_range.maximum;
  value.width_range = valueWidth_range;
  ::ad::map::restriction::SpeedLimitList valueSpeed_limits;
  ::ad::map::restriction::SpeedLimit valueSpeed_limitsElement;
  ::ad::physics::Speed valueSpeed_limitsElementSpeed_limit(-100.);
  valueSpeed_limitsElement.speed_limit = valueSpeed_limitsElementSpeed_limit;
  ::ad::physics::ParametricRange valueSpeed_limitsElementLane_piece;
  ::ad::physics::ParametricValue valueSpeed_limitsElementLane_pieceMinimum(0.);
  valueSpeed_limitsElementLane_piece.minimum = valueSpeed_limitsElementLane_pieceMinimum;
  ::ad::physics::ParametricValue valueSpeed_limitsElementLane_pieceMaximum(0.);
  valueSpeed_limitsElementLane_piece.maximum = valueSpeed_limitsElementLane_pieceMaximum;
  valueSpeed_limitsElementLane_piece.maximum = valueSpeed_limitsElementLane_piece.minimum;
  valueSpeed_limitsElementLane_piece.minimum = valueSpeed_limitsElementLane_piece.maximum;
  valueSpeed_limitsElement.lane_piece = valueSpeed_limitsElementLane_piece;
  valueSpeed_limits.resize(1, valueSpeed_limitsElement);
  value.speed_limits = valueSpeed_limits;
  ::ad::map::point::Geometry valueEdge_left;
  bool valueEdge_leftIs_valid{true};
  valueEdge_left.is_valid = valueEdge_leftIs_valid;
  bool valueEdge_leftIs_closed{true};
  valueEdge_left.is_closed = valueEdge_leftIs_closed;
  ::ad::map::point::ECEFPointList valueEdge_leftEcef_points;
  ::ad::map::point::ECEFPoint valueEdge_leftEcef_pointsElement;
  ::ad::map::point::ECEFCoordinate valueEdge_leftEcef_pointsElementX(-6400000);
  valueEdge_leftEcef_pointsElement.x = valueEdge_leftEcef_pointsElementX;
  ::ad::map::point::ECEFCoordinate valueEdge_leftEcef_pointsElementY(-6400000);
  valueEdge_leftEcef_pointsElement.y = valueEdge_leftEcef_pointsElementY;
  ::ad::map::point::ECEFCoordinate valueEdge_leftEcef_pointsElementZ(-6400000);
  valueEdge_leftEcef_pointsElement.z = valueEdge_leftEcef_pointsElementZ;
  valueEdge_leftEcef_points.resize(1, valueEdge_leftEcef_pointsElement);
  valueEdge_left.ecef_points = valueEdge_leftEcef_points;
  ::ad::physics::Distance valueEdge_leftLength(-1e9);
  valueEdge_left.length = valueEdge_leftLength;
  ::ad::map::point::ENUPointCache valueEdge_leftPrivate_enu_points_cache;
  ::ad::map::point::ENUPointList valueEdge_leftPrivate_enu_points_cacheEnu_points;
  ::ad::map::point::ENUPoint valueEdge_leftPrivate_enu_points_cacheEnu_pointsElement;
  ::ad::map::point::ENUCoordinate valueEdge_leftPrivate_enu_points_cacheEnu_pointsElementX(-1e8);
  valueEdge_leftPrivate_enu_points_cacheEnu_pointsElement.x = valueEdge_leftPrivate_enu_points_cacheEnu_pointsElementX;
  ::ad::map::point::ENUCoordinate valueEdge_leftPrivate_enu_points_cacheEnu_pointsElementY(-1e8);
  valueEdge_leftPrivate_enu_points_cacheEnu_pointsElement.y = valueEdge_leftPrivate_enu_points_cacheEnu_pointsElementY;
  ::ad::map::point::ENUCoordinate valueEdge_leftPrivate_enu_points_cacheEnu_pointsElementZ(-1e8);
  valueEdge_leftPrivate_enu_points_cacheEnu_pointsElement.z = valueEdge_leftPrivate_enu_points_cacheEnu_pointsElementZ;
  valueEdge_leftPrivate_enu_points_cacheEnu_points.resize(1, valueEdge_leftPrivate_enu_points_cacheEnu_pointsElement);
  valueEdge_leftPrivate_enu_points_cache.enu_points = valueEdge_leftPrivate_enu_points_cacheEnu_points;
  uint64_t valueEdge_leftPrivate_enu_points_cacheEnu_version{std::numeric_limits<uint64_t>::min()};
  valueEdge_leftPrivate_enu_points_cache.enu_version = valueEdge_leftPrivate_enu_points_cacheEnu_version;
  valueEdge_left.private_enu_points_cache = valueEdge_leftPrivate_enu_points_cache;
  value.edge_left = valueEdge_left;
  ::ad::map::point::Geometry valueEdge_right;
  bool valueEdge_rightIs_valid{true};
  valueEdge_right.is_valid = valueEdge_rightIs_valid;
  bool valueEdge_rightIs_closed{true};
  valueEdge_right.is_closed = valueEdge_rightIs_closed;
  ::ad::map::point::ECEFPointList valueEdge_rightEcef_points;
  ::ad::map::point::ECEFPoint valueEdge_rightEcef_pointsElement;
  ::ad::map::point::ECEFCoordinate valueEdge_rightEcef_pointsElementX(-6400000);
  valueEdge_rightEcef_pointsElement.x = valueEdge_rightEcef_pointsElementX;
  ::ad::map::point::ECEFCoordinate valueEdge_rightEcef_pointsElementY(-6400000);
  valueEdge_rightEcef_pointsElement.y = valueEdge_rightEcef_pointsElementY;
  ::ad::map::point::ECEFCoordinate valueEdge_rightEcef_pointsElementZ(-6400000);
  valueEdge_rightEcef_pointsElement.z = valueEdge_rightEcef_pointsElementZ;
  valueEdge_rightEcef_points.resize(1, valueEdge_rightEcef_pointsElement);
  valueEdge_right.ecef_points = valueEdge_rightEcef_points;
  ::ad::physics::Distance valueEdge_rightLength(-1e9);
  valueEdge_right.length = valueEdge_rightLength;
  ::ad::map::point::ENUPointCache valueEdge_rightPrivate_enu_points_cache;
  ::ad::map::point::ENUPointList valueEdge_rightPrivate_enu_points_cacheEnu_points;
  ::ad::map::point::ENUPoint valueEdge_rightPrivate_enu_points_cacheEnu_pointsElement;
  ::ad::map::point::ENUCoordinate valueEdge_rightPrivate_enu_points_cacheEnu_pointsElementX(-1e8);
  valueEdge_rightPrivate_enu_points_cacheEnu_pointsElement.x
    = valueEdge_rightPrivate_enu_points_cacheEnu_pointsElementX;
  ::ad::map::point::ENUCoordinate valueEdge_rightPrivate_enu_points_cacheEnu_pointsElementY(-1e8);
  valueEdge_rightPrivate_enu_points_cacheEnu_pointsElement.y
    = valueEdge_rightPrivate_enu_points_cacheEnu_pointsElementY;
  ::ad::map::point::ENUCoordinate valueEdge_rightPrivate_enu_points_cacheEnu_pointsElementZ(-1e8);
  valueEdge_rightPrivate_enu_points_cacheEnu_pointsElement.z
    = valueEdge_rightPrivate_enu_points_cacheEnu_pointsElementZ;
  valueEdge_rightPrivate_enu_points_cacheEnu_points.resize(1, valueEdge_rightPrivate_enu_points_cacheEnu_pointsElement);
  valueEdge_rightPrivate_enu_points_cache.enu_points = valueEdge_rightPrivate_enu_points_cacheEnu_points;
  uint64_t valueEdge_rightPrivate_enu_points_cacheEnu_version{std::numeric_limits<uint64_t>::min()};
  valueEdge_rightPrivate_enu_points_cache.enu_version = valueEdge_rightPrivate_enu_points_cacheEnu_version;
  valueEdge_right.private_enu_points_cache = valueEdge_rightPrivate_enu_points_cache;
  value.edge_right = valueEdge_right;
  ::ad::map::lane::ContactLaneList valueContact_lanes;
  ::ad::map::lane::ContactLane valueContact_lanesElement;
  ::ad::map::lane::LaneId valueContact_lanesElementTo_lane(1);
  valueContact_lanesElement.to_lane = valueContact_lanesElementTo_lane;
  ::ad::map::lane::ContactLocation valueContact_lanesElementLocation(::ad::map::lane::ContactLocation::INVALID);
  valueContact_lanesElement.location = valueContact_lanesElementLocation;
  ::ad::map::lane::ContactTypeList valueContact_lanesElementTypes;
  ::ad::map::lane::ContactType valueContact_lanesElementTypesElement(::ad::map::lane::ContactType::INVALID);
  valueContact_lanesElementTypes.resize(1, valueContact_lanesElementTypesElement);
  valueContact_lanesElement.types = valueContact_lanesElementTypes;
  ::ad::map::restriction::Restrictions valueContact_lanesElementRestrictions;
  ::ad::map::restriction::RestrictionList valueContact_lanesElementRestrictionsConjunctions;
  ::ad::map::restriction::Restriction valueContact_lanesElementRestrictionsConjunctionsElement;
  bool valueContact_lanesElementRestrictionsConjunctionsElementNegated{true};
  valueContact_lanesElementRestrictionsConjunctionsElement.negated
    = valueContact_lanesElementRestrictionsConjunctionsElementNegated;
  ::ad::map::restriction::RoadUserTypeList valueContact_lanesElementRestrictionsConjunctionsElementRoad_user_types;
  ::ad::map::restriction::RoadUserType valueContact_lanesElementRestrictionsConjunctionsElementRoad_user_typesElement(
    ::ad::map::restriction::RoadUserType::INVALID);
  valueContact_lanesElementRestrictionsConjunctionsElementRoad_user_types.resize(
    1, valueContact_lanesElementRestrictionsConjunctionsElementRoad_user_typesElement);
  valueContact_lanesElementRestrictionsConjunctionsElement.road_user_types
    = valueContact_lanesElementRestrictionsConjunctionsElementRoad_user_types;
  ::ad::map::restriction::PassengerCount valueContact_lanesElementRestrictionsConjunctionsElementPassengers_min(
    std::numeric_limits<::ad::map::restriction::PassengerCount>::lowest());
  valueContact_lanesElementRestrictionsConjunctionsElement.passengers_min
    = valueContact_lanesElementRestrictionsConjunctionsElementPassengers_min;
  valueContact_lanesElementRestrictionsConjunctions.resize(1, valueContact_lanesElementRestrictionsConjunctionsElement);
  valueContact_lanesElementRestrictions.conjunctions = valueContact_lanesElementRestrictionsConjunctions;
  ::ad::map::restriction::RestrictionList valueContact_lanesElementRestrictionsDisjunctions;
  ::ad::map::restriction::Restriction valueContact_lanesElementRestrictionsDisjunctionsElement;
  bool valueContact_lanesElementRestrictionsDisjunctionsElementNegated{true};
  valueContact_lanesElementRestrictionsDisjunctionsElement.negated
    = valueContact_lanesElementRestrictionsDisjunctionsElementNegated;
  ::ad::map::restriction::RoadUserTypeList valueContact_lanesElementRestrictionsDisjunctionsElementRoad_user_types;
  ::ad::map::restriction::RoadUserType valueContact_lanesElementRestrictionsDisjunctionsElementRoad_user_typesElement(
    ::ad::map::restriction::RoadUserType::INVALID);
  valueContact_lanesElementRestrictionsDisjunctionsElementRoad_user_types.resize(
    1, valueContact_lanesElementRestrictionsDisjunctionsElementRoad_user_typesElement);
  valueContact_lanesElementRestrictionsDisjunctionsElement.road_user_types
    = valueContact_lanesElementRestrictionsDisjunctionsElementRoad_user_types;
  ::ad::map::restriction::PassengerCount valueContact_lanesElementRestrictionsDisjunctionsElementPassengers_min(
    std::numeric_limits<::ad::map::restriction::PassengerCount>::lowest());
  valueContact_lanesElementRestrictionsDisjunctionsElement.passengers_min
    = valueContact_lanesElementRestrictionsDisjunctionsElementPassengers_min;
  valueContact_lanesElementRestrictionsDisjunctions.resize(1, valueContact_lanesElementRestrictionsDisjunctionsElement);
  valueContact_lanesElementRestrictions.disjunctions = valueContact_lanesElementRestrictionsDisjunctions;
  valueContact_lanesElement.restrictions = valueContact_lanesElementRestrictions;
  ::ad::map::landmark::LandmarkId valueContact_lanesElementLandmark_id(
    std::numeric_limits<::ad::map::landmark::LandmarkId>::lowest());
  valueContact_lanesElement.landmark_id = valueContact_lanesElementLandmark_id;
  valueContact_lanes.resize(1, valueContact_lanesElement);
  value.contact_lanes = valueContact_lanes;
  ::ad::map::lane::ComplianceVersion valueCompliance_version(
    std::numeric_limits<::ad::map::lane::ComplianceVersion>::lowest());
  value.compliance_version = valueCompliance_version;
  ::ad::map::point::BoundingSphere valueBounding_sphere;
  ::ad::map::point::ECEFPoint valueBounding_sphereCenter;
  ::ad::map::point::ECEFCoordinate valueBounding_sphereCenterX(-6400000);
  valueBounding_sphereCenter.x = valueBounding_sphereCenterX;
  ::ad::map::point::ECEFCoordinate valueBounding_sphereCenterY(-6400000);
  valueBounding_sphereCenter.y = valueBounding_sphereCenterY;
  ::ad::map::point::ECEFCoordinate valueBounding_sphereCenterZ(-6400000);
  valueBounding_sphereCenter.z = valueBounding_sphereCenterZ;
  valueBounding_sphere.center = valueBounding_sphereCenter;
  ::ad::physics::Distance valueBounding_sphereRadius(-1e9);
  valueBounding_sphere.radius = valueBounding_sphereRadius;
  value.bounding_sphere = valueBounding_sphere;
  ::ad::map::landmark::LandmarkIdList valueVisible_landmarks;
  ::ad::map::landmark::LandmarkId valueVisible_landmarksElement(
    std::numeric_limits<::ad::map::landmark::LandmarkId>::lowest());
  valueVisible_landmarks.resize(1, valueVisible_landmarksElement);
  value.visible_landmarks = valueVisible_landmarks;

  // override member with data type value below input range minimum
  ::ad::map::point::Geometry invalidInitializedMember;
  ::ad::physics::Distance invalidInitializedMemberLength(-1e9 * 1.1);
  invalidInitializedMember.length = invalidInitializedMemberLength;
  value.edge_left = invalidInitializedMember;
  ASSERT_FALSE(withinValidInputRange(value));
}

TEST(LaneValidInputRangeTests, testValidInputRangeEdge_leftTooBig)
{
  ::ad::map::lane::Lane value;
  ::ad::map::lane::LaneId valueId(1);
  value.id = valueId;
  ::ad::map::lane::LaneType valueType(::ad::map::lane::LaneType::INVALID);
  value.type = valueType;
  ::ad::map::lane::LaneDirection valueDirection(::ad::map::lane::LaneDirection::INVALID);
  value.direction = valueDirection;
  ::ad::map::restriction::Restrictions valueRestrictions;
  ::ad::map::restriction::RestrictionList valueRestrictionsConjunctions;
  ::ad::map::restriction::Restriction valueRestrictionsConjunctionsElement;
  bool valueRestrictionsConjunctionsElementNegated{true};
  valueRestrictionsConjunctionsElement.negated = valueRestrictionsConjunctionsElementNegated;
  ::ad::map::restriction::RoadUserTypeList valueRestrictionsConjunctionsElementRoad_user_types;
  ::ad::map::restriction::RoadUserType valueRestrictionsConjunctionsElementRoad_user_typesElement(
    ::ad::map::restriction::RoadUserType::INVALID);
  valueRestrictionsConjunctionsElementRoad_user_types.resize(
    1, valueRestrictionsConjunctionsElementRoad_user_typesElement);
  valueRestrictionsConjunctionsElement.road_user_types = valueRestrictionsConjunctionsElementRoad_user_types;
  ::ad::map::restriction::PassengerCount valueRestrictionsConjunctionsElementPassengers_min(
    std::numeric_limits<::ad::map::restriction::PassengerCount>::lowest());
  valueRestrictionsConjunctionsElement.passengers_min = valueRestrictionsConjunctionsElementPassengers_min;
  valueRestrictionsConjunctions.resize(1, valueRestrictionsConjunctionsElement);
  valueRestrictions.conjunctions = valueRestrictionsConjunctions;
  ::ad::map::restriction::RestrictionList valueRestrictionsDisjunctions;
  ::ad::map::restriction::Restriction valueRestrictionsDisjunctionsElement;
  bool valueRestrictionsDisjunctionsElementNegated{true};
  valueRestrictionsDisjunctionsElement.negated = valueRestrictionsDisjunctionsElementNegated;
  ::ad::map::restriction::RoadUserTypeList valueRestrictionsDisjunctionsElementRoad_user_types;
  ::ad::map::restriction::RoadUserType valueRestrictionsDisjunctionsElementRoad_user_typesElement(
    ::ad::map::restriction::RoadUserType::INVALID);
  valueRestrictionsDisjunctionsElementRoad_user_types.resize(
    1, valueRestrictionsDisjunctionsElementRoad_user_typesElement);
  valueRestrictionsDisjunctionsElement.road_user_types = valueRestrictionsDisjunctionsElementRoad_user_types;
  ::ad::map::restriction::PassengerCount valueRestrictionsDisjunctionsElementPassengers_min(
    std::numeric_limits<::ad::map::restriction::PassengerCount>::lowest());
  valueRestrictionsDisjunctionsElement.passengers_min = valueRestrictionsDisjunctionsElementPassengers_min;
  valueRestrictionsDisjunctions.resize(1, valueRestrictionsDisjunctionsElement);
  valueRestrictions.disjunctions = valueRestrictionsDisjunctions;
  value.restrictions = valueRestrictions;
  ::ad::physics::Distance valueLength(-1e9);
  value.length = valueLength;
  ::ad::physics::MetricRange valueLength_range;
  ::ad::physics::Distance valueLength_rangeMinimum(-1e9);
  valueLength_rangeMinimum = ::ad::physics::Distance(0.); // set to valid value within struct
  valueLength_range.minimum = valueLength_rangeMinimum;
  ::ad::physics::Distance valueLength_rangeMaximum(-1e9);
  valueLength_range.maximum = valueLength_rangeMaximum;
  valueLength_range.maximum = valueLength_range.minimum;
  valueLength_range.minimum = valueLength_range.maximum;
  value.length_range = valueLength_range;
  ::ad::physics::Distance valueWidth(-1e9);
  value.width = valueWidth;
  ::ad::physics::MetricRange valueWidth_range;
  ::ad::physics::Distance valueWidth_rangeMinimum(-1e9);
  valueWidth_rangeMinimum = ::ad::physics::Distance(0.); // set to valid value within struct
  valueWidth_range.minimum = valueWidth_rangeMinimum;
  ::ad::physics::Distance valueWidth_rangeMaximum(-1e9);
  valueWidth_range.maximum = valueWidth_rangeMaximum;
  valueWidth_range.maximum = valueWidth_range.minimum;
  valueWidth_range.minimum = valueWidth_range.maximum;
  value.width_range = valueWidth_range;
  ::ad::map::restriction::SpeedLimitList valueSpeed_limits;
  ::ad::map::restriction::SpeedLimit valueSpeed_limitsElement;
  ::ad::physics::Speed valueSpeed_limitsElementSpeed_limit(-100.);
  valueSpeed_limitsElement.speed_limit = valueSpeed_limitsElementSpeed_limit;
  ::ad::physics::ParametricRange valueSpeed_limitsElementLane_piece;
  ::ad::physics::ParametricValue valueSpeed_limitsElementLane_pieceMinimum(0.);
  valueSpeed_limitsElementLane_piece.minimum = valueSpeed_limitsElementLane_pieceMinimum;
  ::ad::physics::ParametricValue valueSpeed_limitsElementLane_pieceMaximum(0.);
  valueSpeed_limitsElementLane_piece.maximum = valueSpeed_limitsElementLane_pieceMaximum;
  valueSpeed_limitsElementLane_piece.maximum = valueSpeed_limitsElementLane_piece.minimum;
  valueSpeed_limitsElementLane_piece.minimum = valueSpeed_limitsElementLane_piece.maximum;
  valueSpeed_limitsElement.lane_piece = valueSpeed_limitsElementLane_piece;
  valueSpeed_limits.resize(1, valueSpeed_limitsElement);
  value.speed_limits = valueSpeed_limits;
  ::ad::map::point::Geometry valueEdge_left;
  bool valueEdge_leftIs_valid{true};
  valueEdge_left.is_valid = valueEdge_leftIs_valid;
  bool valueEdge_leftIs_closed{true};
  valueEdge_left.is_closed = valueEdge_leftIs_closed;
  ::ad::map::point::ECEFPointList valueEdge_leftEcef_points;
  ::ad::map::point::ECEFPoint valueEdge_leftEcef_pointsElement;
  ::ad::map::point::ECEFCoordinate valueEdge_leftEcef_pointsElementX(-6400000);
  valueEdge_leftEcef_pointsElement.x = valueEdge_leftEcef_pointsElementX;
  ::ad::map::point::ECEFCoordinate valueEdge_leftEcef_pointsElementY(-6400000);
  valueEdge_leftEcef_pointsElement.y = valueEdge_leftEcef_pointsElementY;
  ::ad::map::point::ECEFCoordinate valueEdge_leftEcef_pointsElementZ(-6400000);
  valueEdge_leftEcef_pointsElement.z = valueEdge_leftEcef_pointsElementZ;
  valueEdge_leftEcef_points.resize(1, valueEdge_leftEcef_pointsElement);
  valueEdge_left.ecef_points = valueEdge_leftEcef_points;
  ::ad::physics::Distance valueEdge_leftLength(-1e9);
  valueEdge_left.length = valueEdge_leftLength;
  ::ad::map::point::ENUPointCache valueEdge_leftPrivate_enu_points_cache;
  ::ad::map::point::ENUPointList valueEdge_leftPrivate_enu_points_cacheEnu_points;
  ::ad::map::point::ENUPoint valueEdge_leftPrivate_enu_points_cacheEnu_pointsElement;
  ::ad::map::point::ENUCoordinate valueEdge_leftPrivate_enu_points_cacheEnu_pointsElementX(-1e8);
  valueEdge_leftPrivate_enu_points_cacheEnu_pointsElement.x = valueEdge_leftPrivate_enu_points_cacheEnu_pointsElementX;
  ::ad::map::point::ENUCoordinate valueEdge_leftPrivate_enu_points_cacheEnu_pointsElementY(-1e8);
  valueEdge_leftPrivate_enu_points_cacheEnu_pointsElement.y = valueEdge_leftPrivate_enu_points_cacheEnu_pointsElementY;
  ::ad::map::point::ENUCoordinate valueEdge_leftPrivate_enu_points_cacheEnu_pointsElementZ(-1e8);
  valueEdge_leftPrivate_enu_points_cacheEnu_pointsElement.z = valueEdge_leftPrivate_enu_points_cacheEnu_pointsElementZ;
  valueEdge_leftPrivate_enu_points_cacheEnu_points.resize(1, valueEdge_leftPrivate_enu_points_cacheEnu_pointsElement);
  valueEdge_leftPrivate_enu_points_cache.enu_points = valueEdge_leftPrivate_enu_points_cacheEnu_points;
  uint64_t valueEdge_leftPrivate_enu_points_cacheEnu_version{std::numeric_limits<uint64_t>::min()};
  valueEdge_leftPrivate_enu_points_cache.enu_version = valueEdge_leftPrivate_enu_points_cacheEnu_version;
  valueEdge_left.private_enu_points_cache = valueEdge_leftPrivate_enu_points_cache;
  value.edge_left = valueEdge_left;
  ::ad::map::point::Geometry valueEdge_right;
  bool valueEdge_rightIs_valid{true};
  valueEdge_right.is_valid = valueEdge_rightIs_valid;
  bool valueEdge_rightIs_closed{true};
  valueEdge_right.is_closed = valueEdge_rightIs_closed;
  ::ad::map::point::ECEFPointList valueEdge_rightEcef_points;
  ::ad::map::point::ECEFPoint valueEdge_rightEcef_pointsElement;
  ::ad::map::point::ECEFCoordinate valueEdge_rightEcef_pointsElementX(-6400000);
  valueEdge_rightEcef_pointsElement.x = valueEdge_rightEcef_pointsElementX;
  ::ad::map::point::ECEFCoordinate valueEdge_rightEcef_pointsElementY(-6400000);
  valueEdge_rightEcef_pointsElement.y = valueEdge_rightEcef_pointsElementY;
  ::ad::map::point::ECEFCoordinate valueEdge_rightEcef_pointsElementZ(-6400000);
  valueEdge_rightEcef_pointsElement.z = valueEdge_rightEcef_pointsElementZ;
  valueEdge_rightEcef_points.resize(1, valueEdge_rightEcef_pointsElement);
  valueEdge_right.ecef_points = valueEdge_rightEcef_points;
  ::ad::physics::Distance valueEdge_rightLength(-1e9);
  valueEdge_right.length = valueEdge_rightLength;
  ::ad::map::point::ENUPointCache valueEdge_rightPrivate_enu_points_cache;
  ::ad::map::point::ENUPointList valueEdge_rightPrivate_enu_points_cacheEnu_points;
  ::ad::map::point::ENUPoint valueEdge_rightPrivate_enu_points_cacheEnu_pointsElement;
  ::ad::map::point::ENUCoordinate valueEdge_rightPrivate_enu_points_cacheEnu_pointsElementX(-1e8);
  valueEdge_rightPrivate_enu_points_cacheEnu_pointsElement.x
    = valueEdge_rightPrivate_enu_points_cacheEnu_pointsElementX;
  ::ad::map::point::ENUCoordinate valueEdge_rightPrivate_enu_points_cacheEnu_pointsElementY(-1e8);
  valueEdge_rightPrivate_enu_points_cacheEnu_pointsElement.y
    = valueEdge_rightPrivate_enu_points_cacheEnu_pointsElementY;
  ::ad::map::point::ENUCoordinate valueEdge_rightPrivate_enu_points_cacheEnu_pointsElementZ(-1e8);
  valueEdge_rightPrivate_enu_points_cacheEnu_pointsElement.z
    = valueEdge_rightPrivate_enu_points_cacheEnu_pointsElementZ;
  valueEdge_rightPrivate_enu_points_cacheEnu_points.resize(1, valueEdge_rightPrivate_enu_points_cacheEnu_pointsElement);
  valueEdge_rightPrivate_enu_points_cache.enu_points = valueEdge_rightPrivate_enu_points_cacheEnu_points;
  uint64_t valueEdge_rightPrivate_enu_points_cacheEnu_version{std::numeric_limits<uint64_t>::min()};
  valueEdge_rightPrivate_enu_points_cache.enu_version = valueEdge_rightPrivate_enu_points_cacheEnu_version;
  valueEdge_right.private_enu_points_cache = valueEdge_rightPrivate_enu_points_cache;
  value.edge_right = valueEdge_right;
  ::ad::map::lane::ContactLaneList valueContact_lanes;
  ::ad::map::lane::ContactLane valueContact_lanesElement;
  ::ad::map::lane::LaneId valueContact_lanesElementTo_lane(1);
  valueContact_lanesElement.to_lane = valueContact_lanesElementTo_lane;
  ::ad::map::lane::ContactLocation valueContact_lanesElementLocation(::ad::map::lane::ContactLocation::INVALID);
  valueContact_lanesElement.location = valueContact_lanesElementLocation;
  ::ad::map::lane::ContactTypeList valueContact_lanesElementTypes;
  ::ad::map::lane::ContactType valueContact_lanesElementTypesElement(::ad::map::lane::ContactType::INVALID);
  valueContact_lanesElementTypes.resize(1, valueContact_lanesElementTypesElement);
  valueContact_lanesElement.types = valueContact_lanesElementTypes;
  ::ad::map::restriction::Restrictions valueContact_lanesElementRestrictions;
  ::ad::map::restriction::RestrictionList valueContact_lanesElementRestrictionsConjunctions;
  ::ad::map::restriction::Restriction valueContact_lanesElementRestrictionsConjunctionsElement;
  bool valueContact_lanesElementRestrictionsConjunctionsElementNegated{true};
  valueContact_lanesElementRestrictionsConjunctionsElement.negated
    = valueContact_lanesElementRestrictionsConjunctionsElementNegated;
  ::ad::map::restriction::RoadUserTypeList valueContact_lanesElementRestrictionsConjunctionsElementRoad_user_types;
  ::ad::map::restriction::RoadUserType valueContact_lanesElementRestrictionsConjunctionsElementRoad_user_typesElement(
    ::ad::map::restriction::RoadUserType::INVALID);
  valueContact_lanesElementRestrictionsConjunctionsElementRoad_user_types.resize(
    1, valueContact_lanesElementRestrictionsConjunctionsElementRoad_user_typesElement);
  valueContact_lanesElementRestrictionsConjunctionsElement.road_user_types
    = valueContact_lanesElementRestrictionsConjunctionsElementRoad_user_types;
  ::ad::map::restriction::PassengerCount valueContact_lanesElementRestrictionsConjunctionsElementPassengers_min(
    std::numeric_limits<::ad::map::restriction::PassengerCount>::lowest());
  valueContact_lanesElementRestrictionsConjunctionsElement.passengers_min
    = valueContact_lanesElementRestrictionsConjunctionsElementPassengers_min;
  valueContact_lanesElementRestrictionsConjunctions.resize(1, valueContact_lanesElementRestrictionsConjunctionsElement);
  valueContact_lanesElementRestrictions.conjunctions = valueContact_lanesElementRestrictionsConjunctions;
  ::ad::map::restriction::RestrictionList valueContact_lanesElementRestrictionsDisjunctions;
  ::ad::map::restriction::Restriction valueContact_lanesElementRestrictionsDisjunctionsElement;
  bool valueContact_lanesElementRestrictionsDisjunctionsElementNegated{true};
  valueContact_lanesElementRestrictionsDisjunctionsElement.negated
    = valueContact_lanesElementRestrictionsDisjunctionsElementNegated;
  ::ad::map::restriction::RoadUserTypeList valueContact_lanesElementRestrictionsDisjunctionsElementRoad_user_types;
  ::ad::map::restriction::RoadUserType valueContact_lanesElementRestrictionsDisjunctionsElementRoad_user_typesElement(
    ::ad::map::restriction::RoadUserType::INVALID);
  valueContact_lanesElementRestrictionsDisjunctionsElementRoad_user_types.resize(
    1, valueContact_lanesElementRestrictionsDisjunctionsElementRoad_user_typesElement);
  valueContact_lanesElementRestrictionsDisjunctionsElement.road_user_types
    = valueContact_lanesElementRestrictionsDisjunctionsElementRoad_user_types;
  ::ad::map::restriction::PassengerCount valueContact_lanesElementRestrictionsDisjunctionsElementPassengers_min(
    std::numeric_limits<::ad::map::restriction::PassengerCount>::lowest());
  valueContact_lanesElementRestrictionsDisjunctionsElement.passengers_min
    = valueContact_lanesElementRestrictionsDisjunctionsElementPassengers_min;
  valueContact_lanesElementRestrictionsDisjunctions.resize(1, valueContact_lanesElementRestrictionsDisjunctionsElement);
  valueContact_lanesElementRestrictions.disjunctions = valueContact_lanesElementRestrictionsDisjunctions;
  valueContact_lanesElement.restrictions = valueContact_lanesElementRestrictions;
  ::ad::map::landmark::LandmarkId valueContact_lanesElementLandmark_id(
    std::numeric_limits<::ad::map::landmark::LandmarkId>::lowest());
  valueContact_lanesElement.landmark_id = valueContact_lanesElementLandmark_id;
  valueContact_lanes.resize(1, valueContact_lanesElement);
  value.contact_lanes = valueContact_lanes;
  ::ad::map::lane::ComplianceVersion valueCompliance_version(
    std::numeric_limits<::ad::map::lane::ComplianceVersion>::lowest());
  value.compliance_version = valueCompliance_version;
  ::ad::map::point::BoundingSphere valueBounding_sphere;
  ::ad::map::point::ECEFPoint valueBounding_sphereCenter;
  ::ad::map::point::ECEFCoordinate valueBounding_sphereCenterX(-6400000);
  valueBounding_sphereCenter.x = valueBounding_sphereCenterX;
  ::ad::map::point::ECEFCoordinate valueBounding_sphereCenterY(-6400000);
  valueBounding_sphereCenter.y = valueBounding_sphereCenterY;
  ::ad::map::point::ECEFCoordinate valueBounding_sphereCenterZ(-6400000);
  valueBounding_sphereCenter.z = valueBounding_sphereCenterZ;
  valueBounding_sphere.center = valueBounding_sphereCenter;
  ::ad::physics::Distance valueBounding_sphereRadius(-1e9);
  valueBounding_sphere.radius = valueBounding_sphereRadius;
  value.bounding_sphere = valueBounding_sphere;
  ::ad::map::landmark::LandmarkIdList valueVisible_landmarks;
  ::ad::map::landmark::LandmarkId valueVisible_landmarksElement(
    std::numeric_limits<::ad::map::landmark::LandmarkId>::lowest());
  valueVisible_landmarks.resize(1, valueVisible_landmarksElement);
  value.visible_landmarks = valueVisible_landmarks;

  // override member with data type value above input range maximum
  ::ad::map::point::Geometry invalidInitializedMember;
  ::ad::physics::Distance invalidInitializedMemberLength(1e9 * 1.1);
  invalidInitializedMember.length = invalidInitializedMemberLength;
  value.edge_left = invalidInitializedMember;
  ASSERT_FALSE(withinValidInputRange(value));
}

TEST(LaneValidInputRangeTests, testValidInputRangeEdge_rightTooSmall)
{
  ::ad::map::lane::Lane value;
  ::ad::map::lane::LaneId valueId(1);
  value.id = valueId;
  ::ad::map::lane::LaneType valueType(::ad::map::lane::LaneType::INVALID);
  value.type = valueType;
  ::ad::map::lane::LaneDirection valueDirection(::ad::map::lane::LaneDirection::INVALID);
  value.direction = valueDirection;
  ::ad::map::restriction::Restrictions valueRestrictions;
  ::ad::map::restriction::RestrictionList valueRestrictionsConjunctions;
  ::ad::map::restriction::Restriction valueRestrictionsConjunctionsElement;
  bool valueRestrictionsConjunctionsElementNegated{true};
  valueRestrictionsConjunctionsElement.negated = valueRestrictionsConjunctionsElementNegated;
  ::ad::map::restriction::RoadUserTypeList valueRestrictionsConjunctionsElementRoad_user_types;
  ::ad::map::restriction::RoadUserType valueRestrictionsConjunctionsElementRoad_user_typesElement(
    ::ad::map::restriction::RoadUserType::INVALID);
  valueRestrictionsConjunctionsElementRoad_user_types.resize(
    1, valueRestrictionsConjunctionsElementRoad_user_typesElement);
  valueRestrictionsConjunctionsElement.road_user_types = valueRestrictionsConjunctionsElementRoad_user_types;
  ::ad::map::restriction::PassengerCount valueRestrictionsConjunctionsElementPassengers_min(
    std::numeric_limits<::ad::map::restriction::PassengerCount>::lowest());
  valueRestrictionsConjunctionsElement.passengers_min = valueRestrictionsConjunctionsElementPassengers_min;
  valueRestrictionsConjunctions.resize(1, valueRestrictionsConjunctionsElement);
  valueRestrictions.conjunctions = valueRestrictionsConjunctions;
  ::ad::map::restriction::RestrictionList valueRestrictionsDisjunctions;
  ::ad::map::restriction::Restriction valueRestrictionsDisjunctionsElement;
  bool valueRestrictionsDisjunctionsElementNegated{true};
  valueRestrictionsDisjunctionsElement.negated = valueRestrictionsDisjunctionsElementNegated;
  ::ad::map::restriction::RoadUserTypeList valueRestrictionsDisjunctionsElementRoad_user_types;
  ::ad::map::restriction::RoadUserType valueRestrictionsDisjunctionsElementRoad_user_typesElement(
    ::ad::map::restriction::RoadUserType::INVALID);
  valueRestrictionsDisjunctionsElementRoad_user_types.resize(
    1, valueRestrictionsDisjunctionsElementRoad_user_typesElement);
  valueRestrictionsDisjunctionsElement.road_user_types = valueRestrictionsDisjunctionsElementRoad_user_types;
  ::ad::map::restriction::PassengerCount valueRestrictionsDisjunctionsElementPassengers_min(
    std::numeric_limits<::ad::map::restriction::PassengerCount>::lowest());
  valueRestrictionsDisjunctionsElement.passengers_min = valueRestrictionsDisjunctionsElementPassengers_min;
  valueRestrictionsDisjunctions.resize(1, valueRestrictionsDisjunctionsElement);
  valueRestrictions.disjunctions = valueRestrictionsDisjunctions;
  value.restrictions = valueRestrictions;
  ::ad::physics::Distance valueLength(-1e9);
  value.length = valueLength;
  ::ad::physics::MetricRange valueLength_range;
  ::ad::physics::Distance valueLength_rangeMinimum(-1e9);
  valueLength_rangeMinimum = ::ad::physics::Distance(0.); // set to valid value within struct
  valueLength_range.minimum = valueLength_rangeMinimum;
  ::ad::physics::Distance valueLength_rangeMaximum(-1e9);
  valueLength_range.maximum = valueLength_rangeMaximum;
  valueLength_range.maximum = valueLength_range.minimum;
  valueLength_range.minimum = valueLength_range.maximum;
  value.length_range = valueLength_range;
  ::ad::physics::Distance valueWidth(-1e9);
  value.width = valueWidth;
  ::ad::physics::MetricRange valueWidth_range;
  ::ad::physics::Distance valueWidth_rangeMinimum(-1e9);
  valueWidth_rangeMinimum = ::ad::physics::Distance(0.); // set to valid value within struct
  valueWidth_range.minimum = valueWidth_rangeMinimum;
  ::ad::physics::Distance valueWidth_rangeMaximum(-1e9);
  valueWidth_range.maximum = valueWidth_rangeMaximum;
  valueWidth_range.maximum = valueWidth_range.minimum;
  valueWidth_range.minimum = valueWidth_range.maximum;
  value.width_range = valueWidth_range;
  ::ad::map::restriction::SpeedLimitList valueSpeed_limits;
  ::ad::map::restriction::SpeedLimit valueSpeed_limitsElement;
  ::ad::physics::Speed valueSpeed_limitsElementSpeed_limit(-100.);
  valueSpeed_limitsElement.speed_limit = valueSpeed_limitsElementSpeed_limit;
  ::ad::physics::ParametricRange valueSpeed_limitsElementLane_piece;
  ::ad::physics::ParametricValue valueSpeed_limitsElementLane_pieceMinimum(0.);
  valueSpeed_limitsElementLane_piece.minimum = valueSpeed_limitsElementLane_pieceMinimum;
  ::ad::physics::ParametricValue valueSpeed_limitsElementLane_pieceMaximum(0.);
  valueSpeed_limitsElementLane_piece.maximum = valueSpeed_limitsElementLane_pieceMaximum;
  valueSpeed_limitsElementLane_piece.maximum = valueSpeed_limitsElementLane_piece.minimum;
  valueSpeed_limitsElementLane_piece.minimum = valueSpeed_limitsElementLane_piece.maximum;
  valueSpeed_limitsElement.lane_piece = valueSpeed_limitsElementLane_piece;
  valueSpeed_limits.resize(1, valueSpeed_limitsElement);
  value.speed_limits = valueSpeed_limits;
  ::ad::map::point::Geometry valueEdge_left;
  bool valueEdge_leftIs_valid{true};
  valueEdge_left.is_valid = valueEdge_leftIs_valid;
  bool valueEdge_leftIs_closed{true};
  valueEdge_left.is_closed = valueEdge_leftIs_closed;
  ::ad::map::point::ECEFPointList valueEdge_leftEcef_points;
  ::ad::map::point::ECEFPoint valueEdge_leftEcef_pointsElement;
  ::ad::map::point::ECEFCoordinate valueEdge_leftEcef_pointsElementX(-6400000);
  valueEdge_leftEcef_pointsElement.x = valueEdge_leftEcef_pointsElementX;
  ::ad::map::point::ECEFCoordinate valueEdge_leftEcef_pointsElementY(-6400000);
  valueEdge_leftEcef_pointsElement.y = valueEdge_leftEcef_pointsElementY;
  ::ad::map::point::ECEFCoordinate valueEdge_leftEcef_pointsElementZ(-6400000);
  valueEdge_leftEcef_pointsElement.z = valueEdge_leftEcef_pointsElementZ;
  valueEdge_leftEcef_points.resize(1, valueEdge_leftEcef_pointsElement);
  valueEdge_left.ecef_points = valueEdge_leftEcef_points;
  ::ad::physics::Distance valueEdge_leftLength(-1e9);
  valueEdge_left.length = valueEdge_leftLength;
  ::ad::map::point::ENUPointCache valueEdge_leftPrivate_enu_points_cache;
  ::ad::map::point::ENUPointList valueEdge_leftPrivate_enu_points_cacheEnu_points;
  ::ad::map::point::ENUPoint valueEdge_leftPrivate_enu_points_cacheEnu_pointsElement;
  ::ad::map::point::ENUCoordinate valueEdge_leftPrivate_enu_points_cacheEnu_pointsElementX(-1e8);
  valueEdge_leftPrivate_enu_points_cacheEnu_pointsElement.x = valueEdge_leftPrivate_enu_points_cacheEnu_pointsElementX;
  ::ad::map::point::ENUCoordinate valueEdge_leftPrivate_enu_points_cacheEnu_pointsElementY(-1e8);
  valueEdge_leftPrivate_enu_points_cacheEnu_pointsElement.y = valueEdge_leftPrivate_enu_points_cacheEnu_pointsElementY;
  ::ad::map::point::ENUCoordinate valueEdge_leftPrivate_enu_points_cacheEnu_pointsElementZ(-1e8);
  valueEdge_leftPrivate_enu_points_cacheEnu_pointsElement.z = valueEdge_leftPrivate_enu_points_cacheEnu_pointsElementZ;
  valueEdge_leftPrivate_enu_points_cacheEnu_points.resize(1, valueEdge_leftPrivate_enu_points_cacheEnu_pointsElement);
  valueEdge_leftPrivate_enu_points_cache.enu_points = valueEdge_leftPrivate_enu_points_cacheEnu_points;
  uint64_t valueEdge_leftPrivate_enu_points_cacheEnu_version{std::numeric_limits<uint64_t>::min()};
  valueEdge_leftPrivate_enu_points_cache.enu_version = valueEdge_leftPrivate_enu_points_cacheEnu_version;
  valueEdge_left.private_enu_points_cache = valueEdge_leftPrivate_enu_points_cache;
  value.edge_left = valueEdge_left;
  ::ad::map::point::Geometry valueEdge_right;
  bool valueEdge_rightIs_valid{true};
  valueEdge_right.is_valid = valueEdge_rightIs_valid;
  bool valueEdge_rightIs_closed{true};
  valueEdge_right.is_closed = valueEdge_rightIs_closed;
  ::ad::map::point::ECEFPointList valueEdge_rightEcef_points;
  ::ad::map::point::ECEFPoint valueEdge_rightEcef_pointsElement;
  ::ad::map::point::ECEFCoordinate valueEdge_rightEcef_pointsElementX(-6400000);
  valueEdge_rightEcef_pointsElement.x = valueEdge_rightEcef_pointsElementX;
  ::ad::map::point::ECEFCoordinate valueEdge_rightEcef_pointsElementY(-6400000);
  valueEdge_rightEcef_pointsElement.y = valueEdge_rightEcef_pointsElementY;
  ::ad::map::point::ECEFCoordinate valueEdge_rightEcef_pointsElementZ(-6400000);
  valueEdge_rightEcef_pointsElement.z = valueEdge_rightEcef_pointsElementZ;
  valueEdge_rightEcef_points.resize(1, valueEdge_rightEcef_pointsElement);
  valueEdge_right.ecef_points = valueEdge_rightEcef_points;
  ::ad::physics::Distance valueEdge_rightLength(-1e9);
  valueEdge_right.length = valueEdge_rightLength;
  ::ad::map::point::ENUPointCache valueEdge_rightPrivate_enu_points_cache;
  ::ad::map::point::ENUPointList valueEdge_rightPrivate_enu_points_cacheEnu_points;
  ::ad::map::point::ENUPoint valueEdge_rightPrivate_enu_points_cacheEnu_pointsElement;
  ::ad::map::point::ENUCoordinate valueEdge_rightPrivate_enu_points_cacheEnu_pointsElementX(-1e8);
  valueEdge_rightPrivate_enu_points_cacheEnu_pointsElement.x
    = valueEdge_rightPrivate_enu_points_cacheEnu_pointsElementX;
  ::ad::map::point::ENUCoordinate valueEdge_rightPrivate_enu_points_cacheEnu_pointsElementY(-1e8);
  valueEdge_rightPrivate_enu_points_cacheEnu_pointsElement.y
    = valueEdge_rightPrivate_enu_points_cacheEnu_pointsElementY;
  ::ad::map::point::ENUCoordinate valueEdge_rightPrivate_enu_points_cacheEnu_pointsElementZ(-1e8);
  valueEdge_rightPrivate_enu_points_cacheEnu_pointsElement.z
    = valueEdge_rightPrivate_enu_points_cacheEnu_pointsElementZ;
  valueEdge_rightPrivate_enu_points_cacheEnu_points.resize(1, valueEdge_rightPrivate_enu_points_cacheEnu_pointsElement);
  valueEdge_rightPrivate_enu_points_cache.enu_points = valueEdge_rightPrivate_enu_points_cacheEnu_points;
  uint64_t valueEdge_rightPrivate_enu_points_cacheEnu_version{std::numeric_limits<uint64_t>::min()};
  valueEdge_rightPrivate_enu_points_cache.enu_version = valueEdge_rightPrivate_enu_points_cacheEnu_version;
  valueEdge_right.private_enu_points_cache = valueEdge_rightPrivate_enu_points_cache;
  value.edge_right = valueEdge_right;
  ::ad::map::lane::ContactLaneList valueContact_lanes;
  ::ad::map::lane::ContactLane valueContact_lanesElement;
  ::ad::map::lane::LaneId valueContact_lanesElementTo_lane(1);
  valueContact_lanesElement.to_lane = valueContact_lanesElementTo_lane;
  ::ad::map::lane::ContactLocation valueContact_lanesElementLocation(::ad::map::lane::ContactLocation::INVALID);
  valueContact_lanesElement.location = valueContact_lanesElementLocation;
  ::ad::map::lane::ContactTypeList valueContact_lanesElementTypes;
  ::ad::map::lane::ContactType valueContact_lanesElementTypesElement(::ad::map::lane::ContactType::INVALID);
  valueContact_lanesElementTypes.resize(1, valueContact_lanesElementTypesElement);
  valueContact_lanesElement.types = valueContact_lanesElementTypes;
  ::ad::map::restriction::Restrictions valueContact_lanesElementRestrictions;
  ::ad::map::restriction::RestrictionList valueContact_lanesElementRestrictionsConjunctions;
  ::ad::map::restriction::Restriction valueContact_lanesElementRestrictionsConjunctionsElement;
  bool valueContact_lanesElementRestrictionsConjunctionsElementNegated{true};
  valueContact_lanesElementRestrictionsConjunctionsElement.negated
    = valueContact_lanesElementRestrictionsConjunctionsElementNegated;
  ::ad::map::restriction::RoadUserTypeList valueContact_lanesElementRestrictionsConjunctionsElementRoad_user_types;
  ::ad::map::restriction::RoadUserType valueContact_lanesElementRestrictionsConjunctionsElementRoad_user_typesElement(
    ::ad::map::restriction::RoadUserType::INVALID);
  valueContact_lanesElementRestrictionsConjunctionsElementRoad_user_types.resize(
    1, valueContact_lanesElementRestrictionsConjunctionsElementRoad_user_typesElement);
  valueContact_lanesElementRestrictionsConjunctionsElement.road_user_types
    = valueContact_lanesElementRestrictionsConjunctionsElementRoad_user_types;
  ::ad::map::restriction::PassengerCount valueContact_lanesElementRestrictionsConjunctionsElementPassengers_min(
    std::numeric_limits<::ad::map::restriction::PassengerCount>::lowest());
  valueContact_lanesElementRestrictionsConjunctionsElement.passengers_min
    = valueContact_lanesElementRestrictionsConjunctionsElementPassengers_min;
  valueContact_lanesElementRestrictionsConjunctions.resize(1, valueContact_lanesElementRestrictionsConjunctionsElement);
  valueContact_lanesElementRestrictions.conjunctions = valueContact_lanesElementRestrictionsConjunctions;
  ::ad::map::restriction::RestrictionList valueContact_lanesElementRestrictionsDisjunctions;
  ::ad::map::restriction::Restriction valueContact_lanesElementRestrictionsDisjunctionsElement;
  bool valueContact_lanesElementRestrictionsDisjunctionsElementNegated{true};
  valueContact_lanesElementRestrictionsDisjunctionsElement.negated
    = valueContact_lanesElementRestrictionsDisjunctionsElementNegated;
  ::ad::map::restriction::RoadUserTypeList valueContact_lanesElementRestrictionsDisjunctionsElementRoad_user_types;
  ::ad::map::restriction::RoadUserType valueContact_lanesElementRestrictionsDisjunctionsElementRoad_user_typesElement(
    ::ad::map::restriction::RoadUserType::INVALID);
  valueContact_lanesElementRestrictionsDisjunctionsElementRoad_user_types.resize(
    1, valueContact_lanesElementRestrictionsDisjunctionsElementRoad_user_typesElement);
  valueContact_lanesElementRestrictionsDisjunctionsElement.road_user_types
    = valueContact_lanesElementRestrictionsDisjunctionsElementRoad_user_types;
  ::ad::map::restriction::PassengerCount valueContact_lanesElementRestrictionsDisjunctionsElementPassengers_min(
    std::numeric_limits<::ad::map::restriction::PassengerCount>::lowest());
  valueContact_lanesElementRestrictionsDisjunctionsElement.passengers_min
    = valueContact_lanesElementRestrictionsDisjunctionsElementPassengers_min;
  valueContact_lanesElementRestrictionsDisjunctions.resize(1, valueContact_lanesElementRestrictionsDisjunctionsElement);
  valueContact_lanesElementRestrictions.disjunctions = valueContact_lanesElementRestrictionsDisjunctions;
  valueContact_lanesElement.restrictions = valueContact_lanesElementRestrictions;
  ::ad::map::landmark::LandmarkId valueContact_lanesElementLandmark_id(
    std::numeric_limits<::ad::map::landmark::LandmarkId>::lowest());
  valueContact_lanesElement.landmark_id = valueContact_lanesElementLandmark_id;
  valueContact_lanes.resize(1, valueContact_lanesElement);
  value.contact_lanes = valueContact_lanes;
  ::ad::map::lane::ComplianceVersion valueCompliance_version(
    std::numeric_limits<::ad::map::lane::ComplianceVersion>::lowest());
  value.compliance_version = valueCompliance_version;
  ::ad::map::point::BoundingSphere valueBounding_sphere;
  ::ad::map::point::ECEFPoint valueBounding_sphereCenter;
  ::ad::map::point::ECEFCoordinate valueBounding_sphereCenterX(-6400000);
  valueBounding_sphereCenter.x = valueBounding_sphereCenterX;
  ::ad::map::point::ECEFCoordinate valueBounding_sphereCenterY(-6400000);
  valueBounding_sphereCenter.y = valueBounding_sphereCenterY;
  ::ad::map::point::ECEFCoordinate valueBounding_sphereCenterZ(-6400000);
  valueBounding_sphereCenter.z = valueBounding_sphereCenterZ;
  valueBounding_sphere.center = valueBounding_sphereCenter;
  ::ad::physics::Distance valueBounding_sphereRadius(-1e9);
  valueBounding_sphere.radius = valueBounding_sphereRadius;
  value.bounding_sphere = valueBounding_sphere;
  ::ad::map::landmark::LandmarkIdList valueVisible_landmarks;
  ::ad::map::landmark::LandmarkId valueVisible_landmarksElement(
    std::numeric_limits<::ad::map::landmark::LandmarkId>::lowest());
  valueVisible_landmarks.resize(1, valueVisible_landmarksElement);
  value.visible_landmarks = valueVisible_landmarks;

  // override member with data type value below input range minimum
  ::ad::map::point::Geometry invalidInitializedMember;
  ::ad::physics::Distance invalidInitializedMemberLength(-1e9 * 1.1);
  invalidInitializedMember.length = invalidInitializedMemberLength;
  value.edge_right = invalidInitializedMember;
  ASSERT_FALSE(withinValidInputRange(value));
}

TEST(LaneValidInputRangeTests, testValidInputRangeEdge_rightTooBig)
{
  ::ad::map::lane::Lane value;
  ::ad::map::lane::LaneId valueId(1);
  value.id = valueId;
  ::ad::map::lane::LaneType valueType(::ad::map::lane::LaneType::INVALID);
  value.type = valueType;
  ::ad::map::lane::LaneDirection valueDirection(::ad::map::lane::LaneDirection::INVALID);
  value.direction = valueDirection;
  ::ad::map::restriction::Restrictions valueRestrictions;
  ::ad::map::restriction::RestrictionList valueRestrictionsConjunctions;
  ::ad::map::restriction::Restriction valueRestrictionsConjunctionsElement;
  bool valueRestrictionsConjunctionsElementNegated{true};
  valueRestrictionsConjunctionsElement.negated = valueRestrictionsConjunctionsElementNegated;
  ::ad::map::restriction::RoadUserTypeList valueRestrictionsConjunctionsElementRoad_user_types;
  ::ad::map::restriction::RoadUserType valueRestrictionsConjunctionsElementRoad_user_typesElement(
    ::ad::map::restriction::RoadUserType::INVALID);
  valueRestrictionsConjunctionsElementRoad_user_types.resize(
    1, valueRestrictionsConjunctionsElementRoad_user_typesElement);
  valueRestrictionsConjunctionsElement.road_user_types = valueRestrictionsConjunctionsElementRoad_user_types;
  ::ad::map::restriction::PassengerCount valueRestrictionsConjunctionsElementPassengers_min(
    std::numeric_limits<::ad::map::restriction::PassengerCount>::lowest());
  valueRestrictionsConjunctionsElement.passengers_min = valueRestrictionsConjunctionsElementPassengers_min;
  valueRestrictionsConjunctions.resize(1, valueRestrictionsConjunctionsElement);
  valueRestrictions.conjunctions = valueRestrictionsConjunctions;
  ::ad::map::restriction::RestrictionList valueRestrictionsDisjunctions;
  ::ad::map::restriction::Restriction valueRestrictionsDisjunctionsElement;
  bool valueRestrictionsDisjunctionsElementNegated{true};
  valueRestrictionsDisjunctionsElement.negated = valueRestrictionsDisjunctionsElementNegated;
  ::ad::map::restriction::RoadUserTypeList valueRestrictionsDisjunctionsElementRoad_user_types;
  ::ad::map::restriction::RoadUserType valueRestrictionsDisjunctionsElementRoad_user_typesElement(
    ::ad::map::restriction::RoadUserType::INVALID);
  valueRestrictionsDisjunctionsElementRoad_user_types.resize(
    1, valueRestrictionsDisjunctionsElementRoad_user_typesElement);
  valueRestrictionsDisjunctionsElement.road_user_types = valueRestrictionsDisjunctionsElementRoad_user_types;
  ::ad::map::restriction::PassengerCount valueRestrictionsDisjunctionsElementPassengers_min(
    std::numeric_limits<::ad::map::restriction::PassengerCount>::lowest());
  valueRestrictionsDisjunctionsElement.passengers_min = valueRestrictionsDisjunctionsElementPassengers_min;
  valueRestrictionsDisjunctions.resize(1, valueRestrictionsDisjunctionsElement);
  valueRestrictions.disjunctions = valueRestrictionsDisjunctions;
  value.restrictions = valueRestrictions;
  ::ad::physics::Distance valueLength(-1e9);
  value.length = valueLength;
  ::ad::physics::MetricRange valueLength_range;
  ::ad::physics::Distance valueLength_rangeMinimum(-1e9);
  valueLength_rangeMinimum = ::ad::physics::Distance(0.); // set to valid value within struct
  valueLength_range.minimum = valueLength_rangeMinimum;
  ::ad::physics::Distance valueLength_rangeMaximum(-1e9);
  valueLength_range.maximum = valueLength_rangeMaximum;
  valueLength_range.maximum = valueLength_range.minimum;
  valueLength_range.minimum = valueLength_range.maximum;
  value.length_range = valueLength_range;
  ::ad::physics::Distance valueWidth(-1e9);
  value.width = valueWidth;
  ::ad::physics::MetricRange valueWidth_range;
  ::ad::physics::Distance valueWidth_rangeMinimum(-1e9);
  valueWidth_rangeMinimum = ::ad::physics::Distance(0.); // set to valid value within struct
  valueWidth_range.minimum = valueWidth_rangeMinimum;
  ::ad::physics::Distance valueWidth_rangeMaximum(-1e9);
  valueWidth_range.maximum = valueWidth_rangeMaximum;
  valueWidth_range.maximum = valueWidth_range.minimum;
  valueWidth_range.minimum = valueWidth_range.maximum;
  value.width_range = valueWidth_range;
  ::ad::map::restriction::SpeedLimitList valueSpeed_limits;
  ::ad::map::restriction::SpeedLimit valueSpeed_limitsElement;
  ::ad::physics::Speed valueSpeed_limitsElementSpeed_limit(-100.);
  valueSpeed_limitsElement.speed_limit = valueSpeed_limitsElementSpeed_limit;
  ::ad::physics::ParametricRange valueSpeed_limitsElementLane_piece;
  ::ad::physics::ParametricValue valueSpeed_limitsElementLane_pieceMinimum(0.);
  valueSpeed_limitsElementLane_piece.minimum = valueSpeed_limitsElementLane_pieceMinimum;
  ::ad::physics::ParametricValue valueSpeed_limitsElementLane_pieceMaximum(0.);
  valueSpeed_limitsElementLane_piece.maximum = valueSpeed_limitsElementLane_pieceMaximum;
  valueSpeed_limitsElementLane_piece.maximum = valueSpeed_limitsElementLane_piece.minimum;
  valueSpeed_limitsElementLane_piece.minimum = valueSpeed_limitsElementLane_piece.maximum;
  valueSpeed_limitsElement.lane_piece = valueSpeed_limitsElementLane_piece;
  valueSpeed_limits.resize(1, valueSpeed_limitsElement);
  value.speed_limits = valueSpeed_limits;
  ::ad::map::point::Geometry valueEdge_left;
  bool valueEdge_leftIs_valid{true};
  valueEdge_left.is_valid = valueEdge_leftIs_valid;
  bool valueEdge_leftIs_closed{true};
  valueEdge_left.is_closed = valueEdge_leftIs_closed;
  ::ad::map::point::ECEFPointList valueEdge_leftEcef_points;
  ::ad::map::point::ECEFPoint valueEdge_leftEcef_pointsElement;
  ::ad::map::point::ECEFCoordinate valueEdge_leftEcef_pointsElementX(-6400000);
  valueEdge_leftEcef_pointsElement.x = valueEdge_leftEcef_pointsElementX;
  ::ad::map::point::ECEFCoordinate valueEdge_leftEcef_pointsElementY(-6400000);
  valueEdge_leftEcef_pointsElement.y = valueEdge_leftEcef_pointsElementY;
  ::ad::map::point::ECEFCoordinate valueEdge_leftEcef_pointsElementZ(-6400000);
  valueEdge_leftEcef_pointsElement.z = valueEdge_leftEcef_pointsElementZ;
  valueEdge_leftEcef_points.resize(1, valueEdge_leftEcef_pointsElement);
  valueEdge_left.ecef_points = valueEdge_leftEcef_points;
  ::ad::physics::Distance valueEdge_leftLength(-1e9);
  valueEdge_left.length = valueEdge_leftLength;
  ::ad::map::point::ENUPointCache valueEdge_leftPrivate_enu_points_cache;
  ::ad::map::point::ENUPointList valueEdge_leftPrivate_enu_points_cacheEnu_points;
  ::ad::map::point::ENUPoint valueEdge_leftPrivate_enu_points_cacheEnu_pointsElement;
  ::ad::map::point::ENUCoordinate valueEdge_leftPrivate_enu_points_cacheEnu_pointsElementX(-1e8);
  valueEdge_leftPrivate_enu_points_cacheEnu_pointsElement.x = valueEdge_leftPrivate_enu_points_cacheEnu_pointsElementX;
  ::ad::map::point::ENUCoordinate valueEdge_leftPrivate_enu_points_cacheEnu_pointsElementY(-1e8);
  valueEdge_leftPrivate_enu_points_cacheEnu_pointsElement.y = valueEdge_leftPrivate_enu_points_cacheEnu_pointsElementY;
  ::ad::map::point::ENUCoordinate valueEdge_leftPrivate_enu_points_cacheEnu_pointsElementZ(-1e8);
  valueEdge_leftPrivate_enu_points_cacheEnu_pointsElement.z = valueEdge_leftPrivate_enu_points_cacheEnu_pointsElementZ;
  valueEdge_leftPrivate_enu_points_cacheEnu_points.resize(1, valueEdge_leftPrivate_enu_points_cacheEnu_pointsElement);
  valueEdge_leftPrivate_enu_points_cache.enu_points = valueEdge_leftPrivate_enu_points_cacheEnu_points;
  uint64_t valueEdge_leftPrivate_enu_points_cacheEnu_version{std::numeric_limits<uint64_t>::min()};
  valueEdge_leftPrivate_enu_points_cache.enu_version = valueEdge_leftPrivate_enu_points_cacheEnu_version;
  valueEdge_left.private_enu_points_cache = valueEdge_leftPrivate_enu_points_cache;
  value.edge_left = valueEdge_left;
  ::ad::map::point::Geometry valueEdge_right;
  bool valueEdge_rightIs_valid{true};
  valueEdge_right.is_valid = valueEdge_rightIs_valid;
  bool valueEdge_rightIs_closed{true};
  valueEdge_right.is_closed = valueEdge_rightIs_closed;
  ::ad::map::point::ECEFPointList valueEdge_rightEcef_points;
  ::ad::map::point::ECEFPoint valueEdge_rightEcef_pointsElement;
  ::ad::map::point::ECEFCoordinate valueEdge_rightEcef_pointsElementX(-6400000);
  valueEdge_rightEcef_pointsElement.x = valueEdge_rightEcef_pointsElementX;
  ::ad::map::point::ECEFCoordinate valueEdge_rightEcef_pointsElementY(-6400000);
  valueEdge_rightEcef_pointsElement.y = valueEdge_rightEcef_pointsElementY;
  ::ad::map::point::ECEFCoordinate valueEdge_rightEcef_pointsElementZ(-6400000);
  valueEdge_rightEcef_pointsElement.z = valueEdge_rightEcef_pointsElementZ;
  valueEdge_rightEcef_points.resize(1, valueEdge_rightEcef_pointsElement);
  valueEdge_right.ecef_points = valueEdge_rightEcef_points;
  ::ad::physics::Distance valueEdge_rightLength(-1e9);
  valueEdge_right.length = valueEdge_rightLength;
  ::ad::map::point::ENUPointCache valueEdge_rightPrivate_enu_points_cache;
  ::ad::map::point::ENUPointList valueEdge_rightPrivate_enu_points_cacheEnu_points;
  ::ad::map::point::ENUPoint valueEdge_rightPrivate_enu_points_cacheEnu_pointsElement;
  ::ad::map::point::ENUCoordinate valueEdge_rightPrivate_enu_points_cacheEnu_pointsElementX(-1e8);
  valueEdge_rightPrivate_enu_points_cacheEnu_pointsElement.x
    = valueEdge_rightPrivate_enu_points_cacheEnu_pointsElementX;
  ::ad::map::point::ENUCoordinate valueEdge_rightPrivate_enu_points_cacheEnu_pointsElementY(-1e8);
  valueEdge_rightPrivate_enu_points_cacheEnu_pointsElement.y
    = valueEdge_rightPrivate_enu_points_cacheEnu_pointsElementY;
  ::ad::map::point::ENUCoordinate valueEdge_rightPrivate_enu_points_cacheEnu_pointsElementZ(-1e8);
  valueEdge_rightPrivate_enu_points_cacheEnu_pointsElement.z
    = valueEdge_rightPrivate_enu_points_cacheEnu_pointsElementZ;
  valueEdge_rightPrivate_enu_points_cacheEnu_points.resize(1, valueEdge_rightPrivate_enu_points_cacheEnu_pointsElement);
  valueEdge_rightPrivate_enu_points_cache.enu_points = valueEdge_rightPrivate_enu_points_cacheEnu_points;
  uint64_t valueEdge_rightPrivate_enu_points_cacheEnu_version{std::numeric_limits<uint64_t>::min()};
  valueEdge_rightPrivate_enu_points_cache.enu_version = valueEdge_rightPrivate_enu_points_cacheEnu_version;
  valueEdge_right.private_enu_points_cache = valueEdge_rightPrivate_enu_points_cache;
  value.edge_right = valueEdge_right;
  ::ad::map::lane::ContactLaneList valueContact_lanes;
  ::ad::map::lane::ContactLane valueContact_lanesElement;
  ::ad::map::lane::LaneId valueContact_lanesElementTo_lane(1);
  valueContact_lanesElement.to_lane = valueContact_lanesElementTo_lane;
  ::ad::map::lane::ContactLocation valueContact_lanesElementLocation(::ad::map::lane::ContactLocation::INVALID);
  valueContact_lanesElement.location = valueContact_lanesElementLocation;
  ::ad::map::lane::ContactTypeList valueContact_lanesElementTypes;
  ::ad::map::lane::ContactType valueContact_lanesElementTypesElement(::ad::map::lane::ContactType::INVALID);
  valueContact_lanesElementTypes.resize(1, valueContact_lanesElementTypesElement);
  valueContact_lanesElement.types = valueContact_lanesElementTypes;
  ::ad::map::restriction::Restrictions valueContact_lanesElementRestrictions;
  ::ad::map::restriction::RestrictionList valueContact_lanesElementRestrictionsConjunctions;
  ::ad::map::restriction::Restriction valueContact_lanesElementRestrictionsConjunctionsElement;
  bool valueContact_lanesElementRestrictionsConjunctionsElementNegated{true};
  valueContact_lanesElementRestrictionsConjunctionsElement.negated
    = valueContact_lanesElementRestrictionsConjunctionsElementNegated;
  ::ad::map::restriction::RoadUserTypeList valueContact_lanesElementRestrictionsConjunctionsElementRoad_user_types;
  ::ad::map::restriction::RoadUserType valueContact_lanesElementRestrictionsConjunctionsElementRoad_user_typesElement(
    ::ad::map::restriction::RoadUserType::INVALID);
  valueContact_lanesElementRestrictionsConjunctionsElementRoad_user_types.resize(
    1, valueContact_lanesElementRestrictionsConjunctionsElementRoad_user_typesElement);
  valueContact_lanesElementRestrictionsConjunctionsElement.road_user_types
    = valueContact_lanesElementRestrictionsConjunctionsElementRoad_user_types;
  ::ad::map::restriction::PassengerCount valueContact_lanesElementRestrictionsConjunctionsElementPassengers_min(
    std::numeric_limits<::ad::map::restriction::PassengerCount>::lowest());
  valueContact_lanesElementRestrictionsConjunctionsElement.passengers_min
    = valueContact_lanesElementRestrictionsConjunctionsElementPassengers_min;
  valueContact_lanesElementRestrictionsConjunctions.resize(1, valueContact_lanesElementRestrictionsConjunctionsElement);
  valueContact_lanesElementRestrictions.conjunctions = valueContact_lanesElementRestrictionsConjunctions;
  ::ad::map::restriction::RestrictionList valueContact_lanesElementRestrictionsDisjunctions;
  ::ad::map::restriction::Restriction valueContact_lanesElementRestrictionsDisjunctionsElement;
  bool valueContact_lanesElementRestrictionsDisjunctionsElementNegated{true};
  valueContact_lanesElementRestrictionsDisjunctionsElement.negated
    = valueContact_lanesElementRestrictionsDisjunctionsElementNegated;
  ::ad::map::restriction::RoadUserTypeList valueContact_lanesElementRestrictionsDisjunctionsElementRoad_user_types;
  ::ad::map::restriction::RoadUserType valueContact_lanesElementRestrictionsDisjunctionsElementRoad_user_typesElement(
    ::ad::map::restriction::RoadUserType::INVALID);
  valueContact_lanesElementRestrictionsDisjunctionsElementRoad_user_types.resize(
    1, valueContact_lanesElementRestrictionsDisjunctionsElementRoad_user_typesElement);
  valueContact_lanesElementRestrictionsDisjunctionsElement.road_user_types
    = valueContact_lanesElementRestrictionsDisjunctionsElementRoad_user_types;
  ::ad::map::restriction::PassengerCount valueContact_lanesElementRestrictionsDisjunctionsElementPassengers_min(
    std::numeric_limits<::ad::map::restriction::PassengerCount>::lowest());
  valueContact_lanesElementRestrictionsDisjunctionsElement.passengers_min
    = valueContact_lanesElementRestrictionsDisjunctionsElementPassengers_min;
  valueContact_lanesElementRestrictionsDisjunctions.resize(1, valueContact_lanesElementRestrictionsDisjunctionsElement);
  valueContact_lanesElementRestrictions.disjunctions = valueContact_lanesElementRestrictionsDisjunctions;
  valueContact_lanesElement.restrictions = valueContact_lanesElementRestrictions;
  ::ad::map::landmark::LandmarkId valueContact_lanesElementLandmark_id(
    std::numeric_limits<::ad::map::landmark::LandmarkId>::lowest());
  valueContact_lanesElement.landmark_id = valueContact_lanesElementLandmark_id;
  valueContact_lanes.resize(1, valueContact_lanesElement);
  value.contact_lanes = valueContact_lanes;
  ::ad::map::lane::ComplianceVersion valueCompliance_version(
    std::numeric_limits<::ad::map::lane::ComplianceVersion>::lowest());
  value.compliance_version = valueCompliance_version;
  ::ad::map::point::BoundingSphere valueBounding_sphere;
  ::ad::map::point::ECEFPoint valueBounding_sphereCenter;
  ::ad::map::point::ECEFCoordinate valueBounding_sphereCenterX(-6400000);
  valueBounding_sphereCenter.x = valueBounding_sphereCenterX;
  ::ad::map::point::ECEFCoordinate valueBounding_sphereCenterY(-6400000);
  valueBounding_sphereCenter.y = valueBounding_sphereCenterY;
  ::ad::map::point::ECEFCoordinate valueBounding_sphereCenterZ(-6400000);
  valueBounding_sphereCenter.z = valueBounding_sphereCenterZ;
  valueBounding_sphere.center = valueBounding_sphereCenter;
  ::ad::physics::Distance valueBounding_sphereRadius(-1e9);
  valueBounding_sphere.radius = valueBounding_sphereRadius;
  value.bounding_sphere = valueBounding_sphere;
  ::ad::map::landmark::LandmarkIdList valueVisible_landmarks;
  ::ad::map::landmark::LandmarkId valueVisible_landmarksElement(
    std::numeric_limits<::ad::map::landmark::LandmarkId>::lowest());
  valueVisible_landmarks.resize(1, valueVisible_landmarksElement);
  value.visible_landmarks = valueVisible_landmarks;

  // override member with data type value above input range maximum
  ::ad::map::point::Geometry invalidInitializedMember;
  ::ad::physics::Distance invalidInitializedMemberLength(1e9 * 1.1);
  invalidInitializedMember.length = invalidInitializedMemberLength;
  value.edge_right = invalidInitializedMember;
  ASSERT_FALSE(withinValidInputRange(value));
}

TEST(LaneValidInputRangeTests, testValidInputRangeBounding_sphereTooSmall)
{
  ::ad::map::lane::Lane value;
  ::ad::map::lane::LaneId valueId(1);
  value.id = valueId;
  ::ad::map::lane::LaneType valueType(::ad::map::lane::LaneType::INVALID);
  value.type = valueType;
  ::ad::map::lane::LaneDirection valueDirection(::ad::map::lane::LaneDirection::INVALID);
  value.direction = valueDirection;
  ::ad::map::restriction::Restrictions valueRestrictions;
  ::ad::map::restriction::RestrictionList valueRestrictionsConjunctions;
  ::ad::map::restriction::Restriction valueRestrictionsConjunctionsElement;
  bool valueRestrictionsConjunctionsElementNegated{true};
  valueRestrictionsConjunctionsElement.negated = valueRestrictionsConjunctionsElementNegated;
  ::ad::map::restriction::RoadUserTypeList valueRestrictionsConjunctionsElementRoad_user_types;
  ::ad::map::restriction::RoadUserType valueRestrictionsConjunctionsElementRoad_user_typesElement(
    ::ad::map::restriction::RoadUserType::INVALID);
  valueRestrictionsConjunctionsElementRoad_user_types.resize(
    1, valueRestrictionsConjunctionsElementRoad_user_typesElement);
  valueRestrictionsConjunctionsElement.road_user_types = valueRestrictionsConjunctionsElementRoad_user_types;
  ::ad::map::restriction::PassengerCount valueRestrictionsConjunctionsElementPassengers_min(
    std::numeric_limits<::ad::map::restriction::PassengerCount>::lowest());
  valueRestrictionsConjunctionsElement.passengers_min = valueRestrictionsConjunctionsElementPassengers_min;
  valueRestrictionsConjunctions.resize(1, valueRestrictionsConjunctionsElement);
  valueRestrictions.conjunctions = valueRestrictionsConjunctions;
  ::ad::map::restriction::RestrictionList valueRestrictionsDisjunctions;
  ::ad::map::restriction::Restriction valueRestrictionsDisjunctionsElement;
  bool valueRestrictionsDisjunctionsElementNegated{true};
  valueRestrictionsDisjunctionsElement.negated = valueRestrictionsDisjunctionsElementNegated;
  ::ad::map::restriction::RoadUserTypeList valueRestrictionsDisjunctionsElementRoad_user_types;
  ::ad::map::restriction::RoadUserType valueRestrictionsDisjunctionsElementRoad_user_typesElement(
    ::ad::map::restriction::RoadUserType::INVALID);
  valueRestrictionsDisjunctionsElementRoad_user_types.resize(
    1, valueRestrictionsDisjunctionsElementRoad_user_typesElement);
  valueRestrictionsDisjunctionsElement.road_user_types = valueRestrictionsDisjunctionsElementRoad_user_types;
  ::ad::map::restriction::PassengerCount valueRestrictionsDisjunctionsElementPassengers_min(
    std::numeric_limits<::ad::map::restriction::PassengerCount>::lowest());
  valueRestrictionsDisjunctionsElement.passengers_min = valueRestrictionsDisjunctionsElementPassengers_min;
  valueRestrictionsDisjunctions.resize(1, valueRestrictionsDisjunctionsElement);
  valueRestrictions.disjunctions = valueRestrictionsDisjunctions;
  value.restrictions = valueRestrictions;
  ::ad::physics::Distance valueLength(-1e9);
  value.length = valueLength;
  ::ad::physics::MetricRange valueLength_range;
  ::ad::physics::Distance valueLength_rangeMinimum(-1e9);
  valueLength_rangeMinimum = ::ad::physics::Distance(0.); // set to valid value within struct
  valueLength_range.minimum = valueLength_rangeMinimum;
  ::ad::physics::Distance valueLength_rangeMaximum(-1e9);
  valueLength_range.maximum = valueLength_rangeMaximum;
  valueLength_range.maximum = valueLength_range.minimum;
  valueLength_range.minimum = valueLength_range.maximum;
  value.length_range = valueLength_range;
  ::ad::physics::Distance valueWidth(-1e9);
  value.width = valueWidth;
  ::ad::physics::MetricRange valueWidth_range;
  ::ad::physics::Distance valueWidth_rangeMinimum(-1e9);
  valueWidth_rangeMinimum = ::ad::physics::Distance(0.); // set to valid value within struct
  valueWidth_range.minimum = valueWidth_rangeMinimum;
  ::ad::physics::Distance valueWidth_rangeMaximum(-1e9);
  valueWidth_range.maximum = valueWidth_rangeMaximum;
  valueWidth_range.maximum = valueWidth_range.minimum;
  valueWidth_range.minimum = valueWidth_range.maximum;
  value.width_range = valueWidth_range;
  ::ad::map::restriction::SpeedLimitList valueSpeed_limits;
  ::ad::map::restriction::SpeedLimit valueSpeed_limitsElement;
  ::ad::physics::Speed valueSpeed_limitsElementSpeed_limit(-100.);
  valueSpeed_limitsElement.speed_limit = valueSpeed_limitsElementSpeed_limit;
  ::ad::physics::ParametricRange valueSpeed_limitsElementLane_piece;
  ::ad::physics::ParametricValue valueSpeed_limitsElementLane_pieceMinimum(0.);
  valueSpeed_limitsElementLane_piece.minimum = valueSpeed_limitsElementLane_pieceMinimum;
  ::ad::physics::ParametricValue valueSpeed_limitsElementLane_pieceMaximum(0.);
  valueSpeed_limitsElementLane_piece.maximum = valueSpeed_limitsElementLane_pieceMaximum;
  valueSpeed_limitsElementLane_piece.maximum = valueSpeed_limitsElementLane_piece.minimum;
  valueSpeed_limitsElementLane_piece.minimum = valueSpeed_limitsElementLane_piece.maximum;
  valueSpeed_limitsElement.lane_piece = valueSpeed_limitsElementLane_piece;
  valueSpeed_limits.resize(1, valueSpeed_limitsElement);
  value.speed_limits = valueSpeed_limits;
  ::ad::map::point::Geometry valueEdge_left;
  bool valueEdge_leftIs_valid{true};
  valueEdge_left.is_valid = valueEdge_leftIs_valid;
  bool valueEdge_leftIs_closed{true};
  valueEdge_left.is_closed = valueEdge_leftIs_closed;
  ::ad::map::point::ECEFPointList valueEdge_leftEcef_points;
  ::ad::map::point::ECEFPoint valueEdge_leftEcef_pointsElement;
  ::ad::map::point::ECEFCoordinate valueEdge_leftEcef_pointsElementX(-6400000);
  valueEdge_leftEcef_pointsElement.x = valueEdge_leftEcef_pointsElementX;
  ::ad::map::point::ECEFCoordinate valueEdge_leftEcef_pointsElementY(-6400000);
  valueEdge_leftEcef_pointsElement.y = valueEdge_leftEcef_pointsElementY;
  ::ad::map::point::ECEFCoordinate valueEdge_leftEcef_pointsElementZ(-6400000);
  valueEdge_leftEcef_pointsElement.z = valueEdge_leftEcef_pointsElementZ;
  valueEdge_leftEcef_points.resize(1, valueEdge_leftEcef_pointsElement);
  valueEdge_left.ecef_points = valueEdge_leftEcef_points;
  ::ad::physics::Distance valueEdge_leftLength(-1e9);
  valueEdge_left.length = valueEdge_leftLength;
  ::ad::map::point::ENUPointCache valueEdge_leftPrivate_enu_points_cache;
  ::ad::map::point::ENUPointList valueEdge_leftPrivate_enu_points_cacheEnu_points;
  ::ad::map::point::ENUPoint valueEdge_leftPrivate_enu_points_cacheEnu_pointsElement;
  ::ad::map::point::ENUCoordinate valueEdge_leftPrivate_enu_points_cacheEnu_pointsElementX(-1e8);
  valueEdge_leftPrivate_enu_points_cacheEnu_pointsElement.x = valueEdge_leftPrivate_enu_points_cacheEnu_pointsElementX;
  ::ad::map::point::ENUCoordinate valueEdge_leftPrivate_enu_points_cacheEnu_pointsElementY(-1e8);
  valueEdge_leftPrivate_enu_points_cacheEnu_pointsElement.y = valueEdge_leftPrivate_enu_points_cacheEnu_pointsElementY;
  ::ad::map::point::ENUCoordinate valueEdge_leftPrivate_enu_points_cacheEnu_pointsElementZ(-1e8);
  valueEdge_leftPrivate_enu_points_cacheEnu_pointsElement.z = valueEdge_leftPrivate_enu_points_cacheEnu_pointsElementZ;
  valueEdge_leftPrivate_enu_points_cacheEnu_points.resize(1, valueEdge_leftPrivate_enu_points_cacheEnu_pointsElement);
  valueEdge_leftPrivate_enu_points_cache.enu_points = valueEdge_leftPrivate_enu_points_cacheEnu_points;
  uint64_t valueEdge_leftPrivate_enu_points_cacheEnu_version{std::numeric_limits<uint64_t>::min()};
  valueEdge_leftPrivate_enu_points_cache.enu_version = valueEdge_leftPrivate_enu_points_cacheEnu_version;
  valueEdge_left.private_enu_points_cache = valueEdge_leftPrivate_enu_points_cache;
  value.edge_left = valueEdge_left;
  ::ad::map::point::Geometry valueEdge_right;
  bool valueEdge_rightIs_valid{true};
  valueEdge_right.is_valid = valueEdge_rightIs_valid;
  bool valueEdge_rightIs_closed{true};
  valueEdge_right.is_closed = valueEdge_rightIs_closed;
  ::ad::map::point::ECEFPointList valueEdge_rightEcef_points;
  ::ad::map::point::ECEFPoint valueEdge_rightEcef_pointsElement;
  ::ad::map::point::ECEFCoordinate valueEdge_rightEcef_pointsElementX(-6400000);
  valueEdge_rightEcef_pointsElement.x = valueEdge_rightEcef_pointsElementX;
  ::ad::map::point::ECEFCoordinate valueEdge_rightEcef_pointsElementY(-6400000);
  valueEdge_rightEcef_pointsElement.y = valueEdge_rightEcef_pointsElementY;
  ::ad::map::point::ECEFCoordinate valueEdge_rightEcef_pointsElementZ(-6400000);
  valueEdge_rightEcef_pointsElement.z = valueEdge_rightEcef_pointsElementZ;
  valueEdge_rightEcef_points.resize(1, valueEdge_rightEcef_pointsElement);
  valueEdge_right.ecef_points = valueEdge_rightEcef_points;
  ::ad::physics::Distance valueEdge_rightLength(-1e9);
  valueEdge_right.length = valueEdge_rightLength;
  ::ad::map::point::ENUPointCache valueEdge_rightPrivate_enu_points_cache;
  ::ad::map::point::ENUPointList valueEdge_rightPrivate_enu_points_cacheEnu_points;
  ::ad::map::point::ENUPoint valueEdge_rightPrivate_enu_points_cacheEnu_pointsElement;
  ::ad::map::point::ENUCoordinate valueEdge_rightPrivate_enu_points_cacheEnu_pointsElementX(-1e8);
  valueEdge_rightPrivate_enu_points_cacheEnu_pointsElement.x
    = valueEdge_rightPrivate_enu_points_cacheEnu_pointsElementX;
  ::ad::map::point::ENUCoordinate valueEdge_rightPrivate_enu_points_cacheEnu_pointsElementY(-1e8);
  valueEdge_rightPrivate_enu_points_cacheEnu_pointsElement.y
    = valueEdge_rightPrivate_enu_points_cacheEnu_pointsElementY;
  ::ad::map::point::ENUCoordinate valueEdge_rightPrivate_enu_points_cacheEnu_pointsElementZ(-1e8);
  valueEdge_rightPrivate_enu_points_cacheEnu_pointsElement.z
    = valueEdge_rightPrivate_enu_points_cacheEnu_pointsElementZ;
  valueEdge_rightPrivate_enu_points_cacheEnu_points.resize(1, valueEdge_rightPrivate_enu_points_cacheEnu_pointsElement);
  valueEdge_rightPrivate_enu_points_cache.enu_points = valueEdge_rightPrivate_enu_points_cacheEnu_points;
  uint64_t valueEdge_rightPrivate_enu_points_cacheEnu_version{std::numeric_limits<uint64_t>::min()};
  valueEdge_rightPrivate_enu_points_cache.enu_version = valueEdge_rightPrivate_enu_points_cacheEnu_version;
  valueEdge_right.private_enu_points_cache = valueEdge_rightPrivate_enu_points_cache;
  value.edge_right = valueEdge_right;
  ::ad::map::lane::ContactLaneList valueContact_lanes;
  ::ad::map::lane::ContactLane valueContact_lanesElement;
  ::ad::map::lane::LaneId valueContact_lanesElementTo_lane(1);
  valueContact_lanesElement.to_lane = valueContact_lanesElementTo_lane;
  ::ad::map::lane::ContactLocation valueContact_lanesElementLocation(::ad::map::lane::ContactLocation::INVALID);
  valueContact_lanesElement.location = valueContact_lanesElementLocation;
  ::ad::map::lane::ContactTypeList valueContact_lanesElementTypes;
  ::ad::map::lane::ContactType valueContact_lanesElementTypesElement(::ad::map::lane::ContactType::INVALID);
  valueContact_lanesElementTypes.resize(1, valueContact_lanesElementTypesElement);
  valueContact_lanesElement.types = valueContact_lanesElementTypes;
  ::ad::map::restriction::Restrictions valueContact_lanesElementRestrictions;
  ::ad::map::restriction::RestrictionList valueContact_lanesElementRestrictionsConjunctions;
  ::ad::map::restriction::Restriction valueContact_lanesElementRestrictionsConjunctionsElement;
  bool valueContact_lanesElementRestrictionsConjunctionsElementNegated{true};
  valueContact_lanesElementRestrictionsConjunctionsElement.negated
    = valueContact_lanesElementRestrictionsConjunctionsElementNegated;
  ::ad::map::restriction::RoadUserTypeList valueContact_lanesElementRestrictionsConjunctionsElementRoad_user_types;
  ::ad::map::restriction::RoadUserType valueContact_lanesElementRestrictionsConjunctionsElementRoad_user_typesElement(
    ::ad::map::restriction::RoadUserType::INVALID);
  valueContact_lanesElementRestrictionsConjunctionsElementRoad_user_types.resize(
    1, valueContact_lanesElementRestrictionsConjunctionsElementRoad_user_typesElement);
  valueContact_lanesElementRestrictionsConjunctionsElement.road_user_types
    = valueContact_lanesElementRestrictionsConjunctionsElementRoad_user_types;
  ::ad::map::restriction::PassengerCount valueContact_lanesElementRestrictionsConjunctionsElementPassengers_min(
    std::numeric_limits<::ad::map::restriction::PassengerCount>::lowest());
  valueContact_lanesElementRestrictionsConjunctionsElement.passengers_min
    = valueContact_lanesElementRestrictionsConjunctionsElementPassengers_min;
  valueContact_lanesElementRestrictionsConjunctions.resize(1, valueContact_lanesElementRestrictionsConjunctionsElement);
  valueContact_lanesElementRestrictions.conjunctions = valueContact_lanesElementRestrictionsConjunctions;
  ::ad::map::restriction::RestrictionList valueContact_lanesElementRestrictionsDisjunctions;
  ::ad::map::restriction::Restriction valueContact_lanesElementRestrictionsDisjunctionsElement;
  bool valueContact_lanesElementRestrictionsDisjunctionsElementNegated{true};
  valueContact_lanesElementRestrictionsDisjunctionsElement.negated
    = valueContact_lanesElementRestrictionsDisjunctionsElementNegated;
  ::ad::map::restriction::RoadUserTypeList valueContact_lanesElementRestrictionsDisjunctionsElementRoad_user_types;
  ::ad::map::restriction::RoadUserType valueContact_lanesElementRestrictionsDisjunctionsElementRoad_user_typesElement(
    ::ad::map::restriction::RoadUserType::INVALID);
  valueContact_lanesElementRestrictionsDisjunctionsElementRoad_user_types.resize(
    1, valueContact_lanesElementRestrictionsDisjunctionsElementRoad_user_typesElement);
  valueContact_lanesElementRestrictionsDisjunctionsElement.road_user_types
    = valueContact_lanesElementRestrictionsDisjunctionsElementRoad_user_types;
  ::ad::map::restriction::PassengerCount valueContact_lanesElementRestrictionsDisjunctionsElementPassengers_min(
    std::numeric_limits<::ad::map::restriction::PassengerCount>::lowest());
  valueContact_lanesElementRestrictionsDisjunctionsElement.passengers_min
    = valueContact_lanesElementRestrictionsDisjunctionsElementPassengers_min;
  valueContact_lanesElementRestrictionsDisjunctions.resize(1, valueContact_lanesElementRestrictionsDisjunctionsElement);
  valueContact_lanesElementRestrictions.disjunctions = valueContact_lanesElementRestrictionsDisjunctions;
  valueContact_lanesElement.restrictions = valueContact_lanesElementRestrictions;
  ::ad::map::landmark::LandmarkId valueContact_lanesElementLandmark_id(
    std::numeric_limits<::ad::map::landmark::LandmarkId>::lowest());
  valueContact_lanesElement.landmark_id = valueContact_lanesElementLandmark_id;
  valueContact_lanes.resize(1, valueContact_lanesElement);
  value.contact_lanes = valueContact_lanes;
  ::ad::map::lane::ComplianceVersion valueCompliance_version(
    std::numeric_limits<::ad::map::lane::ComplianceVersion>::lowest());
  value.compliance_version = valueCompliance_version;
  ::ad::map::point::BoundingSphere valueBounding_sphere;
  ::ad::map::point::ECEFPoint valueBounding_sphereCenter;
  ::ad::map::point::ECEFCoordinate valueBounding_sphereCenterX(-6400000);
  valueBounding_sphereCenter.x = valueBounding_sphereCenterX;
  ::ad::map::point::ECEFCoordinate valueBounding_sphereCenterY(-6400000);
  valueBounding_sphereCenter.y = valueBounding_sphereCenterY;
  ::ad::map::point::ECEFCoordinate valueBounding_sphereCenterZ(-6400000);
  valueBounding_sphereCenter.z = valueBounding_sphereCenterZ;
  valueBounding_sphere.center = valueBounding_sphereCenter;
  ::ad::physics::Distance valueBounding_sphereRadius(-1e9);
  valueBounding_sphere.radius = valueBounding_sphereRadius;
  value.bounding_sphere = valueBounding_sphere;
  ::ad::map::landmark::LandmarkIdList valueVisible_landmarks;
  ::ad::map::landmark::LandmarkId valueVisible_landmarksElement(
    std::numeric_limits<::ad::map::landmark::LandmarkId>::lowest());
  valueVisible_landmarks.resize(1, valueVisible_landmarksElement);
  value.visible_landmarks = valueVisible_landmarks;

  // override member with data type value below input range minimum
  ::ad::map::point::BoundingSphere invalidInitializedMember;
  ::ad::map::point::ECEFPoint invalidInitializedMemberCenter;
  ::ad::map::point::ECEFCoordinate invalidInitializedMemberCenterX(-6400000 * 1.1);
  invalidInitializedMemberCenter.x = invalidInitializedMemberCenterX;
  invalidInitializedMember.center = invalidInitializedMemberCenter;
  value.bounding_sphere = invalidInitializedMember;
  ASSERT_FALSE(withinValidInputRange(value));
}

TEST(LaneValidInputRangeTests, testValidInputRangeBounding_sphereTooBig)
{
  ::ad::map::lane::Lane value;
  ::ad::map::lane::LaneId valueId(1);
  value.id = valueId;
  ::ad::map::lane::LaneType valueType(::ad::map::lane::LaneType::INVALID);
  value.type = valueType;
  ::ad::map::lane::LaneDirection valueDirection(::ad::map::lane::LaneDirection::INVALID);
  value.direction = valueDirection;
  ::ad::map::restriction::Restrictions valueRestrictions;
  ::ad::map::restriction::RestrictionList valueRestrictionsConjunctions;
  ::ad::map::restriction::Restriction valueRestrictionsConjunctionsElement;
  bool valueRestrictionsConjunctionsElementNegated{true};
  valueRestrictionsConjunctionsElement.negated = valueRestrictionsConjunctionsElementNegated;
  ::ad::map::restriction::RoadUserTypeList valueRestrictionsConjunctionsElementRoad_user_types;
  ::ad::map::restriction::RoadUserType valueRestrictionsConjunctionsElementRoad_user_typesElement(
    ::ad::map::restriction::RoadUserType::INVALID);
  valueRestrictionsConjunctionsElementRoad_user_types.resize(
    1, valueRestrictionsConjunctionsElementRoad_user_typesElement);
  valueRestrictionsConjunctionsElement.road_user_types = valueRestrictionsConjunctionsElementRoad_user_types;
  ::ad::map::restriction::PassengerCount valueRestrictionsConjunctionsElementPassengers_min(
    std::numeric_limits<::ad::map::restriction::PassengerCount>::lowest());
  valueRestrictionsConjunctionsElement.passengers_min = valueRestrictionsConjunctionsElementPassengers_min;
  valueRestrictionsConjunctions.resize(1, valueRestrictionsConjunctionsElement);
  valueRestrictions.conjunctions = valueRestrictionsConjunctions;
  ::ad::map::restriction::RestrictionList valueRestrictionsDisjunctions;
  ::ad::map::restriction::Restriction valueRestrictionsDisjunctionsElement;
  bool valueRestrictionsDisjunctionsElementNegated{true};
  valueRestrictionsDisjunctionsElement.negated = valueRestrictionsDisjunctionsElementNegated;
  ::ad::map::restriction::RoadUserTypeList valueRestrictionsDisjunctionsElementRoad_user_types;
  ::ad::map::restriction::RoadUserType valueRestrictionsDisjunctionsElementRoad_user_typesElement(
    ::ad::map::restriction::RoadUserType::INVALID);
  valueRestrictionsDisjunctionsElementRoad_user_types.resize(
    1, valueRestrictionsDisjunctionsElementRoad_user_typesElement);
  valueRestrictionsDisjunctionsElement.road_user_types = valueRestrictionsDisjunctionsElementRoad_user_types;
  ::ad::map::restriction::PassengerCount valueRestrictionsDisjunctionsElementPassengers_min(
    std::numeric_limits<::ad::map::restriction::PassengerCount>::lowest());
  valueRestrictionsDisjunctionsElement.passengers_min = valueRestrictionsDisjunctionsElementPassengers_min;
  valueRestrictionsDisjunctions.resize(1, valueRestrictionsDisjunctionsElement);
  valueRestrictions.disjunctions = valueRestrictionsDisjunctions;
  value.restrictions = valueRestrictions;
  ::ad::physics::Distance valueLength(-1e9);
  value.length = valueLength;
  ::ad::physics::MetricRange valueLength_range;
  ::ad::physics::Distance valueLength_rangeMinimum(-1e9);
  valueLength_rangeMinimum = ::ad::physics::Distance(0.); // set to valid value within struct
  valueLength_range.minimum = valueLength_rangeMinimum;
  ::ad::physics::Distance valueLength_rangeMaximum(-1e9);
  valueLength_range.maximum = valueLength_rangeMaximum;
  valueLength_range.maximum = valueLength_range.minimum;
  valueLength_range.minimum = valueLength_range.maximum;
  value.length_range = valueLength_range;
  ::ad::physics::Distance valueWidth(-1e9);
  value.width = valueWidth;
  ::ad::physics::MetricRange valueWidth_range;
  ::ad::physics::Distance valueWidth_rangeMinimum(-1e9);
  valueWidth_rangeMinimum = ::ad::physics::Distance(0.); // set to valid value within struct
  valueWidth_range.minimum = valueWidth_rangeMinimum;
  ::ad::physics::Distance valueWidth_rangeMaximum(-1e9);
  valueWidth_range.maximum = valueWidth_rangeMaximum;
  valueWidth_range.maximum = valueWidth_range.minimum;
  valueWidth_range.minimum = valueWidth_range.maximum;
  value.width_range = valueWidth_range;
  ::ad::map::restriction::SpeedLimitList valueSpeed_limits;
  ::ad::map::restriction::SpeedLimit valueSpeed_limitsElement;
  ::ad::physics::Speed valueSpeed_limitsElementSpeed_limit(-100.);
  valueSpeed_limitsElement.speed_limit = valueSpeed_limitsElementSpeed_limit;
  ::ad::physics::ParametricRange valueSpeed_limitsElementLane_piece;
  ::ad::physics::ParametricValue valueSpeed_limitsElementLane_pieceMinimum(0.);
  valueSpeed_limitsElementLane_piece.minimum = valueSpeed_limitsElementLane_pieceMinimum;
  ::ad::physics::ParametricValue valueSpeed_limitsElementLane_pieceMaximum(0.);
  valueSpeed_limitsElementLane_piece.maximum = valueSpeed_limitsElementLane_pieceMaximum;
  valueSpeed_limitsElementLane_piece.maximum = valueSpeed_limitsElementLane_piece.minimum;
  valueSpeed_limitsElementLane_piece.minimum = valueSpeed_limitsElementLane_piece.maximum;
  valueSpeed_limitsElement.lane_piece = valueSpeed_limitsElementLane_piece;
  valueSpeed_limits.resize(1, valueSpeed_limitsElement);
  value.speed_limits = valueSpeed_limits;
  ::ad::map::point::Geometry valueEdge_left;
  bool valueEdge_leftIs_valid{true};
  valueEdge_left.is_valid = valueEdge_leftIs_valid;
  bool valueEdge_leftIs_closed{true};
  valueEdge_left.is_closed = valueEdge_leftIs_closed;
  ::ad::map::point::ECEFPointList valueEdge_leftEcef_points;
  ::ad::map::point::ECEFPoint valueEdge_leftEcef_pointsElement;
  ::ad::map::point::ECEFCoordinate valueEdge_leftEcef_pointsElementX(-6400000);
  valueEdge_leftEcef_pointsElement.x = valueEdge_leftEcef_pointsElementX;
  ::ad::map::point::ECEFCoordinate valueEdge_leftEcef_pointsElementY(-6400000);
  valueEdge_leftEcef_pointsElement.y = valueEdge_leftEcef_pointsElementY;
  ::ad::map::point::ECEFCoordinate valueEdge_leftEcef_pointsElementZ(-6400000);
  valueEdge_leftEcef_pointsElement.z = valueEdge_leftEcef_pointsElementZ;
  valueEdge_leftEcef_points.resize(1, valueEdge_leftEcef_pointsElement);
  valueEdge_left.ecef_points = valueEdge_leftEcef_points;
  ::ad::physics::Distance valueEdge_leftLength(-1e9);
  valueEdge_left.length = valueEdge_leftLength;
  ::ad::map::point::ENUPointCache valueEdge_leftPrivate_enu_points_cache;
  ::ad::map::point::ENUPointList valueEdge_leftPrivate_enu_points_cacheEnu_points;
  ::ad::map::point::ENUPoint valueEdge_leftPrivate_enu_points_cacheEnu_pointsElement;
  ::ad::map::point::ENUCoordinate valueEdge_leftPrivate_enu_points_cacheEnu_pointsElementX(-1e8);
  valueEdge_leftPrivate_enu_points_cacheEnu_pointsElement.x = valueEdge_leftPrivate_enu_points_cacheEnu_pointsElementX;
  ::ad::map::point::ENUCoordinate valueEdge_leftPrivate_enu_points_cacheEnu_pointsElementY(-1e8);
  valueEdge_leftPrivate_enu_points_cacheEnu_pointsElement.y = valueEdge_leftPrivate_enu_points_cacheEnu_pointsElementY;
  ::ad::map::point::ENUCoordinate valueEdge_leftPrivate_enu_points_cacheEnu_pointsElementZ(-1e8);
  valueEdge_leftPrivate_enu_points_cacheEnu_pointsElement.z = valueEdge_leftPrivate_enu_points_cacheEnu_pointsElementZ;
  valueEdge_leftPrivate_enu_points_cacheEnu_points.resize(1, valueEdge_leftPrivate_enu_points_cacheEnu_pointsElement);
  valueEdge_leftPrivate_enu_points_cache.enu_points = valueEdge_leftPrivate_enu_points_cacheEnu_points;
  uint64_t valueEdge_leftPrivate_enu_points_cacheEnu_version{std::numeric_limits<uint64_t>::min()};
  valueEdge_leftPrivate_enu_points_cache.enu_version = valueEdge_leftPrivate_enu_points_cacheEnu_version;
  valueEdge_left.private_enu_points_cache = valueEdge_leftPrivate_enu_points_cache;
  value.edge_left = valueEdge_left;
  ::ad::map::point::Geometry valueEdge_right;
  bool valueEdge_rightIs_valid{true};
  valueEdge_right.is_valid = valueEdge_rightIs_valid;
  bool valueEdge_rightIs_closed{true};
  valueEdge_right.is_closed = valueEdge_rightIs_closed;
  ::ad::map::point::ECEFPointList valueEdge_rightEcef_points;
  ::ad::map::point::ECEFPoint valueEdge_rightEcef_pointsElement;
  ::ad::map::point::ECEFCoordinate valueEdge_rightEcef_pointsElementX(-6400000);
  valueEdge_rightEcef_pointsElement.x = valueEdge_rightEcef_pointsElementX;
  ::ad::map::point::ECEFCoordinate valueEdge_rightEcef_pointsElementY(-6400000);
  valueEdge_rightEcef_pointsElement.y = valueEdge_rightEcef_pointsElementY;
  ::ad::map::point::ECEFCoordinate valueEdge_rightEcef_pointsElementZ(-6400000);
  valueEdge_rightEcef_pointsElement.z = valueEdge_rightEcef_pointsElementZ;
  valueEdge_rightEcef_points.resize(1, valueEdge_rightEcef_pointsElement);
  valueEdge_right.ecef_points = valueEdge_rightEcef_points;
  ::ad::physics::Distance valueEdge_rightLength(-1e9);
  valueEdge_right.length = valueEdge_rightLength;
  ::ad::map::point::ENUPointCache valueEdge_rightPrivate_enu_points_cache;
  ::ad::map::point::ENUPointList valueEdge_rightPrivate_enu_points_cacheEnu_points;
  ::ad::map::point::ENUPoint valueEdge_rightPrivate_enu_points_cacheEnu_pointsElement;
  ::ad::map::point::ENUCoordinate valueEdge_rightPrivate_enu_points_cacheEnu_pointsElementX(-1e8);
  valueEdge_rightPrivate_enu_points_cacheEnu_pointsElement.x
    = valueEdge_rightPrivate_enu_points_cacheEnu_pointsElementX;
  ::ad::map::point::ENUCoordinate valueEdge_rightPrivate_enu_points_cacheEnu_pointsElementY(-1e8);
  valueEdge_rightPrivate_enu_points_cacheEnu_pointsElement.y
    = valueEdge_rightPrivate_enu_points_cacheEnu_pointsElementY;
  ::ad::map::point::ENUCoordinate valueEdge_rightPrivate_enu_points_cacheEnu_pointsElementZ(-1e8);
  valueEdge_rightPrivate_enu_points_cacheEnu_pointsElement.z
    = valueEdge_rightPrivate_enu_points_cacheEnu_pointsElementZ;
  valueEdge_rightPrivate_enu_points_cacheEnu_points.resize(1, valueEdge_rightPrivate_enu_points_cacheEnu_pointsElement);
  valueEdge_rightPrivate_enu_points_cache.enu_points = valueEdge_rightPrivate_enu_points_cacheEnu_points;
  uint64_t valueEdge_rightPrivate_enu_points_cacheEnu_version{std::numeric_limits<uint64_t>::min()};
  valueEdge_rightPrivate_enu_points_cache.enu_version = valueEdge_rightPrivate_enu_points_cacheEnu_version;
  valueEdge_right.private_enu_points_cache = valueEdge_rightPrivate_enu_points_cache;
  value.edge_right = valueEdge_right;
  ::ad::map::lane::ContactLaneList valueContact_lanes;
  ::ad::map::lane::ContactLane valueContact_lanesElement;
  ::ad::map::lane::LaneId valueContact_lanesElementTo_lane(1);
  valueContact_lanesElement.to_lane = valueContact_lanesElementTo_lane;
  ::ad::map::lane::ContactLocation valueContact_lanesElementLocation(::ad::map::lane::ContactLocation::INVALID);
  valueContact_lanesElement.location = valueContact_lanesElementLocation;
  ::ad::map::lane::ContactTypeList valueContact_lanesElementTypes;
  ::ad::map::lane::ContactType valueContact_lanesElementTypesElement(::ad::map::lane::ContactType::INVALID);
  valueContact_lanesElementTypes.resize(1, valueContact_lanesElementTypesElement);
  valueContact_lanesElement.types = valueContact_lanesElementTypes;
  ::ad::map::restriction::Restrictions valueContact_lanesElementRestrictions;
  ::ad::map::restriction::RestrictionList valueContact_lanesElementRestrictionsConjunctions;
  ::ad::map::restriction::Restriction valueContact_lanesElementRestrictionsConjunctionsElement;
  bool valueContact_lanesElementRestrictionsConjunctionsElementNegated{true};
  valueContact_lanesElementRestrictionsConjunctionsElement.negated
    = valueContact_lanesElementRestrictionsConjunctionsElementNegated;
  ::ad::map::restriction::RoadUserTypeList valueContact_lanesElementRestrictionsConjunctionsElementRoad_user_types;
  ::ad::map::restriction::RoadUserType valueContact_lanesElementRestrictionsConjunctionsElementRoad_user_typesElement(
    ::ad::map::restriction::RoadUserType::INVALID);
  valueContact_lanesElementRestrictionsConjunctionsElementRoad_user_types.resize(
    1, valueContact_lanesElementRestrictionsConjunctionsElementRoad_user_typesElement);
  valueContact_lanesElementRestrictionsConjunctionsElement.road_user_types
    = valueContact_lanesElementRestrictionsConjunctionsElementRoad_user_types;
  ::ad::map::restriction::PassengerCount valueContact_lanesElementRestrictionsConjunctionsElementPassengers_min(
    std::numeric_limits<::ad::map::restriction::PassengerCount>::lowest());
  valueContact_lanesElementRestrictionsConjunctionsElement.passengers_min
    = valueContact_lanesElementRestrictionsConjunctionsElementPassengers_min;
  valueContact_lanesElementRestrictionsConjunctions.resize(1, valueContact_lanesElementRestrictionsConjunctionsElement);
  valueContact_lanesElementRestrictions.conjunctions = valueContact_lanesElementRestrictionsConjunctions;
  ::ad::map::restriction::RestrictionList valueContact_lanesElementRestrictionsDisjunctions;
  ::ad::map::restriction::Restriction valueContact_lanesElementRestrictionsDisjunctionsElement;
  bool valueContact_lanesElementRestrictionsDisjunctionsElementNegated{true};
  valueContact_lanesElementRestrictionsDisjunctionsElement.negated
    = valueContact_lanesElementRestrictionsDisjunctionsElementNegated;
  ::ad::map::restriction::RoadUserTypeList valueContact_lanesElementRestrictionsDisjunctionsElementRoad_user_types;
  ::ad::map::restriction::RoadUserType valueContact_lanesElementRestrictionsDisjunctionsElementRoad_user_typesElement(
    ::ad::map::restriction::RoadUserType::INVALID);
  valueContact_lanesElementRestrictionsDisjunctionsElementRoad_user_types.resize(
    1, valueContact_lanesElementRestrictionsDisjunctionsElementRoad_user_typesElement);
  valueContact_lanesElementRestrictionsDisjunctionsElement.road_user_types
    = valueContact_lanesElementRestrictionsDisjunctionsElementRoad_user_types;
  ::ad::map::restriction::PassengerCount valueContact_lanesElementRestrictionsDisjunctionsElementPassengers_min(
    std::numeric_limits<::ad::map::restriction::PassengerCount>::lowest());
  valueContact_lanesElementRestrictionsDisjunctionsElement.passengers_min
    = valueContact_lanesElementRestrictionsDisjunctionsElementPassengers_min;
  valueContact_lanesElementRestrictionsDisjunctions.resize(1, valueContact_lanesElementRestrictionsDisjunctionsElement);
  valueContact_lanesElementRestrictions.disjunctions = valueContact_lanesElementRestrictionsDisjunctions;
  valueContact_lanesElement.restrictions = valueContact_lanesElementRestrictions;
  ::ad::map::landmark::LandmarkId valueContact_lanesElementLandmark_id(
    std::numeric_limits<::ad::map::landmark::LandmarkId>::lowest());
  valueContact_lanesElement.landmark_id = valueContact_lanesElementLandmark_id;
  valueContact_lanes.resize(1, valueContact_lanesElement);
  value.contact_lanes = valueContact_lanes;
  ::ad::map::lane::ComplianceVersion valueCompliance_version(
    std::numeric_limits<::ad::map::lane::ComplianceVersion>::lowest());
  value.compliance_version = valueCompliance_version;
  ::ad::map::point::BoundingSphere valueBounding_sphere;
  ::ad::map::point::ECEFPoint valueBounding_sphereCenter;
  ::ad::map::point::ECEFCoordinate valueBounding_sphereCenterX(-6400000);
  valueBounding_sphereCenter.x = valueBounding_sphereCenterX;
  ::ad::map::point::ECEFCoordinate valueBounding_sphereCenterY(-6400000);
  valueBounding_sphereCenter.y = valueBounding_sphereCenterY;
  ::ad::map::point::ECEFCoordinate valueBounding_sphereCenterZ(-6400000);
  valueBounding_sphereCenter.z = valueBounding_sphereCenterZ;
  valueBounding_sphere.center = valueBounding_sphereCenter;
  ::ad::physics::Distance valueBounding_sphereRadius(-1e9);
  valueBounding_sphere.radius = valueBounding_sphereRadius;
  value.bounding_sphere = valueBounding_sphere;
  ::ad::map::landmark::LandmarkIdList valueVisible_landmarks;
  ::ad::map::landmark::LandmarkId valueVisible_landmarksElement(
    std::numeric_limits<::ad::map::landmark::LandmarkId>::lowest());
  valueVisible_landmarks.resize(1, valueVisible_landmarksElement);
  value.visible_landmarks = valueVisible_landmarks;

  // override member with data type value above input range maximum
  ::ad::map::point::BoundingSphere invalidInitializedMember;
  ::ad::map::point::ECEFPoint invalidInitializedMemberCenter;
  ::ad::map::point::ECEFCoordinate invalidInitializedMemberCenterX(6400000 * 1.1);
  invalidInitializedMemberCenter.x = invalidInitializedMemberCenterX;
  invalidInitializedMember.center = invalidInitializedMemberCenter;
  value.bounding_sphere = invalidInitializedMember;
  ASSERT_FALSE(withinValidInputRange(value));
}
