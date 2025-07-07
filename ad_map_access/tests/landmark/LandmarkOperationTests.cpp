// ----------------- BEGIN LICENSE BLOCK ---------------------------------
//
// Copyright (C) 2018-2021 Intel Corporation
//
// SPDX-License-Identifier: MIT
//
// ----------------- END LICENSE BLOCK -----------------------------------

#include <ad/map/landmark/LandmarkOperation.hpp>
#include <ad/map/lane/LaneOperation.hpp>
#include <ad/map/test_support/NoLogTestMacros.hpp>
#include "LandmarkTestBase.hpp"

struct LandmarkOperationTests : public LandmarkTestBase
{
};

TEST_F(LandmarkOperationTests, TestLandmark)
{
  GeoPoint point = createGeoPoint(Longitude(8.44038283714), Latitude(49.0199362465), Altitude(115.));
  ECEFPoint position = toECEF(point);

  // setup a landmark
  landmark::LandmarkId landmark_id(1234);
  GeoPoint orientation = createGeoPoint(Longitude(8.44038283714), Latitude(49.0), Altitude(115.));
  ECEFPoint orientationECEF = toECEF(orientation);
  Geometry bounding_box = createGeometry({position, orientationECEF}, true);

  EXPECT_THROW(landmark::uniqueLandmarkId(point), std::invalid_argument);

  EXPECT_TRUE(mFactory->addLandmark(
    mPartitionId, landmark_id, landmark::LandmarkType::UNKNOWN, position, orientationECEF, bounding_box));
  EXPECT_EQ(landmark::getLandmarks().size(), 1u);

  landmark::LandmarkId result;
  result = landmark::uniqueLandmarkId(point);
  ASSERT_EQ(result, landmark_id);
  point = createGeoPoint(Longitude(8.44038283714), Latitude(51.0199362465), Altitude(115.));
  EXPECT_THROW(landmark::uniqueLandmarkId(point), std::invalid_argument);

  // add the landmark as visible landmark to a lane
  EXPECT_TRUE(mFactory->add(mLaneId, landmark_id));

  const auto landmark = landmark::getLandmark(landmark_id);
  EXPECT_NEAR(landmark::getENUHeading(landmark).mENUHeading, -M_PI / 2., 1e-3);

  reinitFromWrittenMap("test_files/test_landmark.adm");

  // check if the landmark is in the store
  EXPECT_EQ(landmark::getLandmarks().size(), 1u);
  EXPECT_TRUE(landmark::getLandmarks().front() == landmark_id);

  // get the lane from the store and check the visible landmarks
  EXPECT_TRUE(lane::getLanes().front() == mLaneId);
  auto lane = lane::getLane(mLaneId);
  EXPECT_EQ(lane.visible_landmarks.size(), 1u);
  EXPECT_TRUE(lane.visible_landmarks.front() == landmark_id);
}

TEST_F(LandmarkOperationTests, TestLandmark_Orientation)
{
  GeoPoint point = createGeoPoint(Longitude(8.4), Latitude(49.1), Altitude(115.));
  ECEFPoint position = toECEF(point);

  ECEFPoint orientation1 = toECEF(createGeoPoint(Longitude(8.4), Latitude(49.2), Altitude(115.)));
  ECEFPoint orientation2 = toECEF(createGeoPoint(Longitude(8.4), Latitude(49.), Altitude(115.)));
  ECEFPoint orientation3 = toECEF(createGeoPoint(Longitude(8.5), Latitude(49.1), Altitude(115.)));
  ECEFPoint orientation4 = toECEF(createGeoPoint(Longitude(8.3), Latitude(49.1), Altitude(115.)));

  // setup a landmark
  Geometry bounding_box = createGeometry({orientation1, orientation4}, true);
  EXPECT_TRUE(mFactory->addLandmark(
    mPartitionId, landmark::LandmarkId(1), landmark::LandmarkType::UNKNOWN, position, orientation1, bounding_box));

  EXPECT_TRUE(mFactory->addLandmark(
    mPartitionId, landmark::LandmarkId(2), landmark::LandmarkType::UNKNOWN, position, orientation2, bounding_box));

  EXPECT_TRUE(mFactory->addLandmark(
    mPartitionId, landmark::LandmarkId(3), landmark::LandmarkType::UNKNOWN, position, orientation3, bounding_box));

  EXPECT_TRUE(mFactory->addLandmark(
    mPartitionId, landmark::LandmarkId(4), landmark::LandmarkType::UNKNOWN, position, orientation4, bounding_box));

  EXPECT_NEAR(landmark::getENUHeading(landmark::getLandmark(landmark::LandmarkId(1))).mENUHeading, M_PI / 2., 1e-3);
  EXPECT_NEAR(landmark::getENUHeading(landmark::getLandmark(landmark::LandmarkId(2))).mENUHeading, -M_PI / 2., 1e-3);
  EXPECT_NEAR(landmark::getENUHeading(landmark::getLandmark(landmark::LandmarkId(3))).mENUHeading, 0., 1e-3);
  EXPECT_NEAR(landmark::getENUHeading(landmark::getLandmark(landmark::LandmarkId(4))).mENUHeading, M_PI, 1e-3);
}

TEST_F(LandmarkOperationTests, TestTrafficLight)
{
  // setup a traffic light
  landmark::LandmarkId landmark_id(1234);
  ECEFPoint orientation = createECEFPoint(0., 0., 0.);
  ECEFPoint position = createECEFPoint(1., 0., 0.);
  Geometry bounding_box = createGeometry({position, orientation}, false);
  EXPECT_TRUE(mFactory->addTrafficLight(mPartitionId,
                                        landmark_id,
                                        landmark::TrafficLightType::SOLID_RED_YELLOW_GREEN,
                                        position,
                                        orientation,
                                        bounding_box));
  EXPECT_EQ(landmark::getLandmarks().size(), 1u);

  // add the traffic light as contact for two lanes
  lane::LaneId x12 = addLane();
  lane::LaneId x13 = addLane();
  ASSERT_TRUE(isValid(x12));
  ASSERT_TRUE(isValid(x13));

  lane::ContactLocation succ(lane::ContactLocation::SUCCESSOR);
  lane::ContactTypeList traffic_light_contact({lane::ContactType::TRAFFIC_LIGHT});
  lane::ContactTypeList free_contact({lane::ContactType::FREE});
  restriction::Restrictions no_restrictions;

  // valid contact, type: traffic light and valid traffic light id
  EXPECT_TRUE(mFactory->add(mLaneId, x12, succ, traffic_light_contact, no_restrictions, landmark_id));
  // invalid contact, type: traffic light and no traffic light id
  EXPECT_FALSE_NO_LOG(mFactory->add(x12, x13, succ, traffic_light_contact, no_restrictions));
  // invalid contact, type: free and valid traffic light id
  EXPECT_FALSE_NO_LOG(mFactory->add(x12, x13, succ, free_contact, no_restrictions, landmark_id));

  // add the traffic light also as visible landmark to the lane mLaneId
  EXPECT_TRUE(mFactory->add(mLaneId, landmark_id));

  reinitFromWrittenMap("test_files/test_traffic_light.adm");

  // check that the traffic light is in the store
  EXPECT_EQ(landmark::getLandmarks().size(), 1u);
  EXPECT_TRUE(landmark::getLandmarks().front() == landmark_id);
  auto traffic_light = landmark::getLandmark(landmark_id);
  EXPECT_TRUE(traffic_light.type == landmark::LandmarkType::TRAFFIC_LIGHT);
  EXPECT_TRUE(traffic_light.traffic_light_type == landmark::TrafficLightType::SOLID_RED_YELLOW_GREEN);

  // check the lane contact in the store
  EXPECT_TRUE(lane::getLanes().front() == mLaneId);
  auto lane = lane::getLane(mLaneId);
  EXPECT_EQ(lane.visible_landmarks.size(), 1u);
  EXPECT_TRUE(lane.visible_landmarks.front() == landmark_id);
  auto contact = lane.contact_lanes.front();
  EXPECT_TRUE(contact.landmark_id == landmark_id);
  EXPECT_TRUE(contact.types.front() == lane::ContactType::TRAFFIC_LIGHT);
}

TEST_F(LandmarkOperationTests, TestTrafficSign)
{
  // setup a landmark
  landmark::LandmarkId landmark_id(1234);
  ECEFPoint orientation = createECEFPoint(0., 0., 0.);
  ECEFPoint position = createECEFPoint(1., 0., 0.);
  Geometry bounding_box = createGeometry({position, orientation}, false);
  std::string text("60");
  EXPECT_TRUE(mFactory->addTrafficSign(
    mPartitionId, landmark_id, landmark::TrafficSignType::MAX_SPEED, position, orientation, bounding_box, text));
  EXPECT_EQ(landmark::getLandmarks().size(), 1u);

  // add the landmark as visible landmark to a lane
  EXPECT_TRUE(mFactory->add(mLaneId, landmark_id));

  reinitFromWrittenMap("test_files/test_traffic_sign.adm");

  // check if the landmark is in the store
  EXPECT_EQ(landmark::getLandmarks().size(), 1u);
  EXPECT_TRUE(landmark::getLandmarks().front() == landmark_id);

  EXPECT_THROW_NO_LOG(landmark::getLandmarkPtr(landmark::LandmarkId(1000)), std::invalid_argument);

  EXPECT_EQ(landmark::getLandmarkPtr(landmark_id)->supplementary_text, "60");

  // get the lane from the store and check the visible landmarks
  EXPECT_TRUE(lane::getLanes().front() == mLaneId);
  auto lane = lane::getLane(mLaneId);
  EXPECT_EQ(lane.visible_landmarks.size(), 1u);
  EXPECT_TRUE(lane.visible_landmarks.front() == landmark_id);
}
