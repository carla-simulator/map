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

#if defined(__clang__) && (__clang_major__ >= 7)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wself-assign-overloaded"
#endif

#include <gtest/gtest.h>
#include <limits>
#include "ad/map/lane/Lane.hpp"

class LaneTests : public testing::Test
{
protected:
  virtual void SetUp() override
  {
    // valid initialization
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
    valueEdge_leftPrivate_enu_points_cacheEnu_pointsElement.x
      = valueEdge_leftPrivate_enu_points_cacheEnu_pointsElementX;
    ::ad::map::point::ENUCoordinate valueEdge_leftPrivate_enu_points_cacheEnu_pointsElementY(-1e8);
    valueEdge_leftPrivate_enu_points_cacheEnu_pointsElement.y
      = valueEdge_leftPrivate_enu_points_cacheEnu_pointsElementY;
    ::ad::map::point::ENUCoordinate valueEdge_leftPrivate_enu_points_cacheEnu_pointsElementZ(-1e8);
    valueEdge_leftPrivate_enu_points_cacheEnu_pointsElement.z
      = valueEdge_leftPrivate_enu_points_cacheEnu_pointsElementZ;
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
    valueEdge_rightPrivate_enu_points_cacheEnu_points.resize(1,
                                                             valueEdge_rightPrivate_enu_points_cacheEnu_pointsElement);
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
    valueContact_lanesElementRestrictionsConjunctions.resize(1,
                                                             valueContact_lanesElementRestrictionsConjunctionsElement);
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
    valueContact_lanesElementRestrictionsDisjunctions.resize(1,
                                                             valueContact_lanesElementRestrictionsDisjunctionsElement);
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
    mValue = value;
  }

  ::ad::map::lane::Lane mValue;
};

TEST_F(LaneTests, copyConstruction)
{
  ::ad::map::lane::Lane value(mValue);
  EXPECT_EQ(mValue, value);
}

TEST_F(LaneTests, moveConstruction)
{
  ::ad::map::lane::Lane tmpValue(mValue);
  ::ad::map::lane::Lane value(std::move(tmpValue));
  EXPECT_EQ(mValue, value);
}

TEST_F(LaneTests, copyAssignment)
{
  ::ad::map::lane::Lane value;
  value = mValue;
  EXPECT_EQ(mValue, value);
}

TEST_F(LaneTests, moveAssignment)
{
  ::ad::map::lane::Lane tmpValue(mValue);
  ::ad::map::lane::Lane value;
  value = std::move(tmpValue);
  EXPECT_EQ(mValue, value);
}

TEST_F(LaneTests, comparisonOperatorEqual)
{
  ::ad::map::lane::Lane valueA = mValue;
  ::ad::map::lane::Lane valueB = mValue;

  EXPECT_TRUE(valueA == valueB);
  EXPECT_FALSE(valueA != valueB);
}

TEST_F(LaneTests, stringConversionTest)
{
  std::stringstream stream;
  stream << mValue;
  std::string ostreamStr = stream.str();
  std::string toStr = std::to_string(mValue);
  ASSERT_EQ(ostreamStr, toStr);
}

TEST_F(LaneTests, comparisonOperatorIdDiffers)
{
  ::ad::map::lane::Lane valueA = mValue;
  ::ad::map::lane::LaneId id(std::numeric_limits<::ad::map::lane::LaneId>::max());
  valueA.id = id;
  ::ad::map::lane::Lane valueB = mValue;

  EXPECT_FALSE(valueA == valueB);
  EXPECT_TRUE(valueA != valueB);
}

TEST_F(LaneTests, comparisonOperatorTypeDiffers)
{
  ::ad::map::lane::Lane valueA = mValue;
  ::ad::map::lane::LaneType type(::ad::map::lane::LaneType::OPENDRIVE_REFERENCE_LINE);
  valueA.type = type;
  ::ad::map::lane::Lane valueB = mValue;

  EXPECT_FALSE(valueA == valueB);
  EXPECT_TRUE(valueA != valueB);
}

TEST_F(LaneTests, comparisonOperatorDirectionDiffers)
{
  ::ad::map::lane::Lane valueA = mValue;
  ::ad::map::lane::LaneDirection direction(::ad::map::lane::LaneDirection::NONE);
  valueA.direction = direction;
  ::ad::map::lane::Lane valueB = mValue;

  EXPECT_FALSE(valueA == valueB);
  EXPECT_TRUE(valueA != valueB);
}

TEST_F(LaneTests, comparisonOperatorRestrictionsDiffers)
{
  ::ad::map::lane::Lane valueA = mValue;
  ::ad::map::restriction::Restrictions restrictions;
  ::ad::map::restriction::RestrictionList restrictionsConjunctions;
  ::ad::map::restriction::Restriction restrictionsConjunctionsElement;
  bool restrictionsConjunctionsElementNegated{false};
  restrictionsConjunctionsElement.negated = restrictionsConjunctionsElementNegated;
  ::ad::map::restriction::RoadUserTypeList restrictionsConjunctionsElementRoad_user_types;
  ::ad::map::restriction::RoadUserType restrictionsConjunctionsElementRoad_user_typesElement(
    ::ad::map::restriction::RoadUserType::CAR_DIESEL);
  restrictionsConjunctionsElementRoad_user_types.resize(2, restrictionsConjunctionsElementRoad_user_typesElement);
  restrictionsConjunctionsElement.road_user_types = restrictionsConjunctionsElementRoad_user_types;
  ::ad::map::restriction::PassengerCount restrictionsConjunctionsElementPassengers_min(
    std::numeric_limits<::ad::map::restriction::PassengerCount>::max());
  restrictionsConjunctionsElement.passengers_min = restrictionsConjunctionsElementPassengers_min;
  restrictionsConjunctions.resize(2, restrictionsConjunctionsElement);
  restrictions.conjunctions = restrictionsConjunctions;
  ::ad::map::restriction::RestrictionList restrictionsDisjunctions;
  ::ad::map::restriction::Restriction restrictionsDisjunctionsElement;
  bool restrictionsDisjunctionsElementNegated{false};
  restrictionsDisjunctionsElement.negated = restrictionsDisjunctionsElementNegated;
  ::ad::map::restriction::RoadUserTypeList restrictionsDisjunctionsElementRoad_user_types;
  ::ad::map::restriction::RoadUserType restrictionsDisjunctionsElementRoad_user_typesElement(
    ::ad::map::restriction::RoadUserType::CAR_DIESEL);
  restrictionsDisjunctionsElementRoad_user_types.resize(2, restrictionsDisjunctionsElementRoad_user_typesElement);
  restrictionsDisjunctionsElement.road_user_types = restrictionsDisjunctionsElementRoad_user_types;
  ::ad::map::restriction::PassengerCount restrictionsDisjunctionsElementPassengers_min(
    std::numeric_limits<::ad::map::restriction::PassengerCount>::max());
  restrictionsDisjunctionsElement.passengers_min = restrictionsDisjunctionsElementPassengers_min;
  restrictionsDisjunctions.resize(2, restrictionsDisjunctionsElement);
  restrictions.disjunctions = restrictionsDisjunctions;
  valueA.restrictions = restrictions;
  ::ad::map::lane::Lane valueB = mValue;

  EXPECT_FALSE(valueA == valueB);
  EXPECT_TRUE(valueA != valueB);
}

TEST_F(LaneTests, comparisonOperatorLengthDiffers)
{
  ::ad::map::lane::Lane valueA = mValue;
  ::ad::physics::Distance length(1e9);
  valueA.length = length;
  ::ad::map::lane::Lane valueB = mValue;

  EXPECT_FALSE(valueA == valueB);
  EXPECT_TRUE(valueA != valueB);
}

TEST_F(LaneTests, comparisonOperatorLength_rangeDiffers)
{
  ::ad::map::lane::Lane valueA = mValue;
  ::ad::physics::MetricRange length_range;
  ::ad::physics::Distance length_rangeMinimum(1e9);
  length_range.minimum = length_rangeMinimum;
  ::ad::physics::Distance length_rangeMaximum(1e9);
  length_rangeMaximum = ::ad::physics::Distance(1e6); // set to valid value within struct
  length_range.maximum = length_rangeMaximum;
  length_range.maximum = length_range.minimum;
  length_range.minimum = length_range.maximum;
  valueA.length_range = length_range;
  ::ad::map::lane::Lane valueB = mValue;

  EXPECT_FALSE(valueA == valueB);
  EXPECT_TRUE(valueA != valueB);
}

TEST_F(LaneTests, comparisonOperatorWidthDiffers)
{
  ::ad::map::lane::Lane valueA = mValue;
  ::ad::physics::Distance width(1e9);
  valueA.width = width;
  ::ad::map::lane::Lane valueB = mValue;

  EXPECT_FALSE(valueA == valueB);
  EXPECT_TRUE(valueA != valueB);
}

TEST_F(LaneTests, comparisonOperatorWidth_rangeDiffers)
{
  ::ad::map::lane::Lane valueA = mValue;
  ::ad::physics::MetricRange width_range;
  ::ad::physics::Distance width_rangeMinimum(1e9);
  width_range.minimum = width_rangeMinimum;
  ::ad::physics::Distance width_rangeMaximum(1e9);
  width_rangeMaximum = ::ad::physics::Distance(1e6); // set to valid value within struct
  width_range.maximum = width_rangeMaximum;
  width_range.maximum = width_range.minimum;
  width_range.minimum = width_range.maximum;
  valueA.width_range = width_range;
  ::ad::map::lane::Lane valueB = mValue;

  EXPECT_FALSE(valueA == valueB);
  EXPECT_TRUE(valueA != valueB);
}

TEST_F(LaneTests, comparisonOperatorSpeed_limitsDiffers)
{
  ::ad::map::lane::Lane valueA = mValue;
  ::ad::map::restriction::SpeedLimitList speed_limits;
  ::ad::map::restriction::SpeedLimit speed_limitsElement;
  ::ad::physics::Speed speed_limitsElementSpeed_limit(100.);
  speed_limitsElement.speed_limit = speed_limitsElementSpeed_limit;
  ::ad::physics::ParametricRange speed_limitsElementLane_piece;
  ::ad::physics::ParametricValue speed_limitsElementLane_pieceMinimum(1.);
  speed_limitsElementLane_piece.minimum = speed_limitsElementLane_pieceMinimum;
  ::ad::physics::ParametricValue speed_limitsElementLane_pieceMaximum(1.);
  speed_limitsElementLane_piece.maximum = speed_limitsElementLane_pieceMaximum;
  speed_limitsElementLane_piece.maximum = speed_limitsElementLane_piece.minimum;
  speed_limitsElementLane_piece.minimum = speed_limitsElementLane_piece.maximum;
  speed_limitsElement.lane_piece = speed_limitsElementLane_piece;
  speed_limits.resize(2, speed_limitsElement);
  valueA.speed_limits = speed_limits;
  ::ad::map::lane::Lane valueB = mValue;

  EXPECT_FALSE(valueA == valueB);
  EXPECT_TRUE(valueA != valueB);
}

TEST_F(LaneTests, comparisonOperatorEdge_leftDiffers)
{
  ::ad::map::lane::Lane valueA = mValue;
  ::ad::map::point::Geometry edge_left;
  bool edge_leftIs_valid{false};
  edge_left.is_valid = edge_leftIs_valid;
  bool edge_leftIs_closed{false};
  edge_left.is_closed = edge_leftIs_closed;
  ::ad::map::point::ECEFPointList edge_leftEcef_points;
  ::ad::map::point::ECEFPoint edge_leftEcef_pointsElement;
  ::ad::map::point::ECEFCoordinate edge_leftEcef_pointsElementX(6400000);
  edge_leftEcef_pointsElement.x = edge_leftEcef_pointsElementX;
  ::ad::map::point::ECEFCoordinate edge_leftEcef_pointsElementY(6400000);
  edge_leftEcef_pointsElement.y = edge_leftEcef_pointsElementY;
  ::ad::map::point::ECEFCoordinate edge_leftEcef_pointsElementZ(6400000);
  edge_leftEcef_pointsElement.z = edge_leftEcef_pointsElementZ;
  edge_leftEcef_points.resize(2, edge_leftEcef_pointsElement);
  edge_left.ecef_points = edge_leftEcef_points;
  ::ad::physics::Distance edge_leftLength(1e9);
  edge_left.length = edge_leftLength;
  ::ad::map::point::ENUPointCache edge_leftPrivate_enu_points_cache;
  ::ad::map::point::ENUPointList edge_leftPrivate_enu_points_cacheEnu_points;
  ::ad::map::point::ENUPoint edge_leftPrivate_enu_points_cacheEnu_pointsElement;
  ::ad::map::point::ENUCoordinate edge_leftPrivate_enu_points_cacheEnu_pointsElementX(1e8);
  edge_leftPrivate_enu_points_cacheEnu_pointsElement.x = edge_leftPrivate_enu_points_cacheEnu_pointsElementX;
  ::ad::map::point::ENUCoordinate edge_leftPrivate_enu_points_cacheEnu_pointsElementY(1e8);
  edge_leftPrivate_enu_points_cacheEnu_pointsElement.y = edge_leftPrivate_enu_points_cacheEnu_pointsElementY;
  ::ad::map::point::ENUCoordinate edge_leftPrivate_enu_points_cacheEnu_pointsElementZ(1e8);
  edge_leftPrivate_enu_points_cacheEnu_pointsElement.z = edge_leftPrivate_enu_points_cacheEnu_pointsElementZ;
  edge_leftPrivate_enu_points_cacheEnu_points.resize(2, edge_leftPrivate_enu_points_cacheEnu_pointsElement);
  edge_leftPrivate_enu_points_cache.enu_points = edge_leftPrivate_enu_points_cacheEnu_points;
  uint64_t edge_leftPrivate_enu_points_cacheEnu_version{std::numeric_limits<uint64_t>::max()};
  edge_leftPrivate_enu_points_cache.enu_version = edge_leftPrivate_enu_points_cacheEnu_version;
  edge_left.private_enu_points_cache = edge_leftPrivate_enu_points_cache;
  valueA.edge_left = edge_left;
  ::ad::map::lane::Lane valueB = mValue;

  EXPECT_FALSE(valueA == valueB);
  EXPECT_TRUE(valueA != valueB);
}

TEST_F(LaneTests, comparisonOperatorEdge_rightDiffers)
{
  ::ad::map::lane::Lane valueA = mValue;
  ::ad::map::point::Geometry edge_right;
  bool edge_rightIs_valid{false};
  edge_right.is_valid = edge_rightIs_valid;
  bool edge_rightIs_closed{false};
  edge_right.is_closed = edge_rightIs_closed;
  ::ad::map::point::ECEFPointList edge_rightEcef_points;
  ::ad::map::point::ECEFPoint edge_rightEcef_pointsElement;
  ::ad::map::point::ECEFCoordinate edge_rightEcef_pointsElementX(6400000);
  edge_rightEcef_pointsElement.x = edge_rightEcef_pointsElementX;
  ::ad::map::point::ECEFCoordinate edge_rightEcef_pointsElementY(6400000);
  edge_rightEcef_pointsElement.y = edge_rightEcef_pointsElementY;
  ::ad::map::point::ECEFCoordinate edge_rightEcef_pointsElementZ(6400000);
  edge_rightEcef_pointsElement.z = edge_rightEcef_pointsElementZ;
  edge_rightEcef_points.resize(2, edge_rightEcef_pointsElement);
  edge_right.ecef_points = edge_rightEcef_points;
  ::ad::physics::Distance edge_rightLength(1e9);
  edge_right.length = edge_rightLength;
  ::ad::map::point::ENUPointCache edge_rightPrivate_enu_points_cache;
  ::ad::map::point::ENUPointList edge_rightPrivate_enu_points_cacheEnu_points;
  ::ad::map::point::ENUPoint edge_rightPrivate_enu_points_cacheEnu_pointsElement;
  ::ad::map::point::ENUCoordinate edge_rightPrivate_enu_points_cacheEnu_pointsElementX(1e8);
  edge_rightPrivate_enu_points_cacheEnu_pointsElement.x = edge_rightPrivate_enu_points_cacheEnu_pointsElementX;
  ::ad::map::point::ENUCoordinate edge_rightPrivate_enu_points_cacheEnu_pointsElementY(1e8);
  edge_rightPrivate_enu_points_cacheEnu_pointsElement.y = edge_rightPrivate_enu_points_cacheEnu_pointsElementY;
  ::ad::map::point::ENUCoordinate edge_rightPrivate_enu_points_cacheEnu_pointsElementZ(1e8);
  edge_rightPrivate_enu_points_cacheEnu_pointsElement.z = edge_rightPrivate_enu_points_cacheEnu_pointsElementZ;
  edge_rightPrivate_enu_points_cacheEnu_points.resize(2, edge_rightPrivate_enu_points_cacheEnu_pointsElement);
  edge_rightPrivate_enu_points_cache.enu_points = edge_rightPrivate_enu_points_cacheEnu_points;
  uint64_t edge_rightPrivate_enu_points_cacheEnu_version{std::numeric_limits<uint64_t>::max()};
  edge_rightPrivate_enu_points_cache.enu_version = edge_rightPrivate_enu_points_cacheEnu_version;
  edge_right.private_enu_points_cache = edge_rightPrivate_enu_points_cache;
  valueA.edge_right = edge_right;
  ::ad::map::lane::Lane valueB = mValue;

  EXPECT_FALSE(valueA == valueB);
  EXPECT_TRUE(valueA != valueB);
}

TEST_F(LaneTests, comparisonOperatorContact_lanesDiffers)
{
  ::ad::map::lane::Lane valueA = mValue;
  ::ad::map::lane::ContactLaneList contact_lanes;
  ::ad::map::lane::ContactLane contact_lanesElement;
  ::ad::map::lane::LaneId contact_lanesElementTo_lane(std::numeric_limits<::ad::map::lane::LaneId>::max());
  contact_lanesElement.to_lane = contact_lanesElementTo_lane;
  ::ad::map::lane::ContactLocation contact_lanesElementLocation(::ad::map::lane::ContactLocation::OVERLAP);
  contact_lanesElement.location = contact_lanesElementLocation;
  ::ad::map::lane::ContactTypeList contact_lanesElementTypes;
  ::ad::map::lane::ContactType contact_lanesElementTypesElement(
    ::ad::map::lane::ContactType::PRIO_TO_RIGHT_AND_STRAIGHT);
  contact_lanesElementTypes.resize(2, contact_lanesElementTypesElement);
  contact_lanesElement.types = contact_lanesElementTypes;
  ::ad::map::restriction::Restrictions contact_lanesElementRestrictions;
  ::ad::map::restriction::RestrictionList contact_lanesElementRestrictionsConjunctions;
  ::ad::map::restriction::Restriction contact_lanesElementRestrictionsConjunctionsElement;
  bool contact_lanesElementRestrictionsConjunctionsElementNegated{false};
  contact_lanesElementRestrictionsConjunctionsElement.negated
    = contact_lanesElementRestrictionsConjunctionsElementNegated;
  ::ad::map::restriction::RoadUserTypeList contact_lanesElementRestrictionsConjunctionsElementRoad_user_types;
  ::ad::map::restriction::RoadUserType contact_lanesElementRestrictionsConjunctionsElementRoad_user_typesElement(
    ::ad::map::restriction::RoadUserType::CAR_DIESEL);
  contact_lanesElementRestrictionsConjunctionsElementRoad_user_types.resize(
    2, contact_lanesElementRestrictionsConjunctionsElementRoad_user_typesElement);
  contact_lanesElementRestrictionsConjunctionsElement.road_user_types
    = contact_lanesElementRestrictionsConjunctionsElementRoad_user_types;
  ::ad::map::restriction::PassengerCount contact_lanesElementRestrictionsConjunctionsElementPassengers_min(
    std::numeric_limits<::ad::map::restriction::PassengerCount>::max());
  contact_lanesElementRestrictionsConjunctionsElement.passengers_min
    = contact_lanesElementRestrictionsConjunctionsElementPassengers_min;
  contact_lanesElementRestrictionsConjunctions.resize(2, contact_lanesElementRestrictionsConjunctionsElement);
  contact_lanesElementRestrictions.conjunctions = contact_lanesElementRestrictionsConjunctions;
  ::ad::map::restriction::RestrictionList contact_lanesElementRestrictionsDisjunctions;
  ::ad::map::restriction::Restriction contact_lanesElementRestrictionsDisjunctionsElement;
  bool contact_lanesElementRestrictionsDisjunctionsElementNegated{false};
  contact_lanesElementRestrictionsDisjunctionsElement.negated
    = contact_lanesElementRestrictionsDisjunctionsElementNegated;
  ::ad::map::restriction::RoadUserTypeList contact_lanesElementRestrictionsDisjunctionsElementRoad_user_types;
  ::ad::map::restriction::RoadUserType contact_lanesElementRestrictionsDisjunctionsElementRoad_user_typesElement(
    ::ad::map::restriction::RoadUserType::CAR_DIESEL);
  contact_lanesElementRestrictionsDisjunctionsElementRoad_user_types.resize(
    2, contact_lanesElementRestrictionsDisjunctionsElementRoad_user_typesElement);
  contact_lanesElementRestrictionsDisjunctionsElement.road_user_types
    = contact_lanesElementRestrictionsDisjunctionsElementRoad_user_types;
  ::ad::map::restriction::PassengerCount contact_lanesElementRestrictionsDisjunctionsElementPassengers_min(
    std::numeric_limits<::ad::map::restriction::PassengerCount>::max());
  contact_lanesElementRestrictionsDisjunctionsElement.passengers_min
    = contact_lanesElementRestrictionsDisjunctionsElementPassengers_min;
  contact_lanesElementRestrictionsDisjunctions.resize(2, contact_lanesElementRestrictionsDisjunctionsElement);
  contact_lanesElementRestrictions.disjunctions = contact_lanesElementRestrictionsDisjunctions;
  contact_lanesElement.restrictions = contact_lanesElementRestrictions;
  ::ad::map::landmark::LandmarkId contact_lanesElementLandmark_id(
    std::numeric_limits<::ad::map::landmark::LandmarkId>::max());
  contact_lanesElement.landmark_id = contact_lanesElementLandmark_id;
  contact_lanes.resize(2, contact_lanesElement);
  valueA.contact_lanes = contact_lanes;
  ::ad::map::lane::Lane valueB = mValue;

  EXPECT_FALSE(valueA == valueB);
  EXPECT_TRUE(valueA != valueB);
}

TEST_F(LaneTests, comparisonOperatorCompliance_versionDiffers)
{
  ::ad::map::lane::Lane valueA = mValue;
  ::ad::map::lane::ComplianceVersion compliance_version(std::numeric_limits<::ad::map::lane::ComplianceVersion>::max());
  valueA.compliance_version = compliance_version;
  ::ad::map::lane::Lane valueB = mValue;

  EXPECT_FALSE(valueA == valueB);
  EXPECT_TRUE(valueA != valueB);
}

TEST_F(LaneTests, comparisonOperatorBounding_sphereDiffers)
{
  ::ad::map::lane::Lane valueA = mValue;
  ::ad::map::point::BoundingSphere bounding_sphere;
  ::ad::map::point::ECEFPoint bounding_sphereCenter;
  ::ad::map::point::ECEFCoordinate bounding_sphereCenterX(6400000);
  bounding_sphereCenter.x = bounding_sphereCenterX;
  ::ad::map::point::ECEFCoordinate bounding_sphereCenterY(6400000);
  bounding_sphereCenter.y = bounding_sphereCenterY;
  ::ad::map::point::ECEFCoordinate bounding_sphereCenterZ(6400000);
  bounding_sphereCenter.z = bounding_sphereCenterZ;
  bounding_sphere.center = bounding_sphereCenter;
  ::ad::physics::Distance bounding_sphereRadius(1e9);
  bounding_sphere.radius = bounding_sphereRadius;
  valueA.bounding_sphere = bounding_sphere;
  ::ad::map::lane::Lane valueB = mValue;

  EXPECT_FALSE(valueA == valueB);
  EXPECT_TRUE(valueA != valueB);
}

TEST_F(LaneTests, comparisonOperatorVisible_landmarksDiffers)
{
  ::ad::map::lane::Lane valueA = mValue;
  ::ad::map::landmark::LandmarkIdList visible_landmarks;
  ::ad::map::landmark::LandmarkId visible_landmarksElement(std::numeric_limits<::ad::map::landmark::LandmarkId>::max());
  visible_landmarks.resize(2, visible_landmarksElement);
  valueA.visible_landmarks = visible_landmarks;
  ::ad::map::lane::Lane valueB = mValue;

  EXPECT_FALSE(valueA == valueB);
  EXPECT_TRUE(valueA != valueB);
}

#if defined(__clang__) && (__clang_major__ >= 7)
#pragma GCC diagnostic pop
#endif
