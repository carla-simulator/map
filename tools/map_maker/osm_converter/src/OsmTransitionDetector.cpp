// ----------------- BEGIN LICENSE BLOCK ---------------------------------
//
// Copyright (C) 2018-2020 Intel Corporation
//
// SPDX-License-Identifier: MIT
//
// ----------------- END LICENSE BLOCK -----------------------------------

#include "ad/map/maker/osm_converter/OsmTransitionDetector.hpp"
#include <ad/map/maker/map_data/IntersectionArm.hpp>
#include "ad/map/maker/osm_converter/OsmToInternalConverter.hpp"

namespace ad {
namespace map {
namespace maker {
namespace osm_converter {

std::size_t lanesIn(map_data::Road const &road, bool const isEntry)
{
  if (isEntry)
  {
    return road.mForwardWidths.size();
  }
  else
  {
    return road.mBackwardWidths.size();
  }
}

std::size_t lanesOut(map_data::Road const &road, bool const isEntry)
{
  if (isEntry)
  {
    return road.mBackwardWidths.size();
  }
  else
  {
    return road.mForwardWidths.size();
  }
}

double widthIn(map_data::Road const &road, bool const isEntry)
{
  if (isEntry)
  {
    return road.forwardWidth();
  }
  else
  {
    return road.backwardWidth();
  }
}

double widthOut(map_data::Road const &road, bool const isEntry)
{
  if (isEntry)
  {
    return road.backwardWidth();
  }
  else
  {
    return road.forwardWidth();
  }
}

std::size_t totalLanes(map_data::Road const &road)
{
  return (road.mForwardWidths.size() + road.mBackwardWidths.size());
}

double defaultRoadOffset(map_data::Road const &road)
{
  if (road.mBackwardWidths.size() > 0u)
  {
    return 0.0;
  }
  return (road.forwardWidth() / 2.);
}

bool isTwoWayRoad(map_data::Road const &road)
{
  return ((road.mForwardWidths.size() > 0) && (road.mBackwardWidths.size() > 0));
}

bool isLinkRoad(map_data::Road const &road)
{
  return road.mRoadType == map_data::RoadType::Link;
}

std::size_t findRoadGeometry(std::vector<RoadGeometry> const &roadsGeometry, map_data::MapDataId roadId)
{
  for (uint32_t index = 0; index < roadsGeometry.size(); ++index)
  {
    if (roadsGeometry[index].roadId == roadId)
    {
      return index;
    }
  }
  throw std::runtime_error("No road geometry found for road " + std::to_string(roadId));
}

bool OsmTransitionDetector::setRoadsGeometry(std::vector<RoadGeometry> const &roadsGeometry)
{
  for (auto const &arm : mArms)
  {
    auto const roadGeometryIndex = findRoadGeometry(roadsGeometry, arm.connectedRoad);
    mRoadsGeometry.push_back(roadsGeometry[roadGeometryIndex]);
  }
  return true;
}

void OsmTransitionDetector::calculateArmsOrientation()
{
  for (uint32_t armIndex = 0; armIndex < mArms.size(); ++armIndex)
  {
    auto const &geometry = mRoadsGeometry[armIndex];
    auto const &geometryPoints = geometry.centerLineGeometry.points;

    double armOrientation{0.};
    if (mArms[armIndex].isEntry)
    {
      auto const &roadPoint = geometryPoints[geometryPoints.size() - 2];
      auto const &connPoint = geometryPoints[geometryPoints.size() - 1];
      armOrientation = geometry::Direction2d(roadPoint, connPoint).orientation;
    }
    else
    {
      auto const &roadPoint = geometryPoints[1];
      auto const &connPoint = geometryPoints[0];
      armOrientation = geometry::Direction2d(roadPoint, connPoint).orientation;
    }
    mArms[armIndex].orientation = armOrientation;
  }
}

double OsmTransitionDetector::transitionOffsetAngleForRoad(map_data::MapDataId roadId)
{
  return mTransitionAngleForRoad.at(roadId);
}

double OsmTransitionDetector::transitionOffsetForRoad(map_data::MapDataId roadId)
{
  return mTransitionOffsetForRoad.at(roadId);
}

bool OsmTransitionDetector::isRampJunction(map_data::MapDataStore const &store, RampJunction &junction)
{
  std::vector<uint32_t> linkArmIndexes;
  std::vector<uint32_t> mergingArmIndexes;

  for (uint32_t armIndex = 0; armIndex < mArms.size(); armIndex++)
  {
    auto const &road = store.road(mArms[armIndex].connectedRoad);
    if (isLinkRoad(road))
    {
      linkArmIndexes.push_back(armIndex);
    }
    else
    {
      mergingArmIndexes.push_back(armIndex);
    }
  }

  if (linkArmIndexes.size() != 1)
  {
    return false;
  }

  junction.rampArmIndex = linkArmIndexes.front();
  auto const &linkArm = mArms[junction.rampArmIndex];
  auto const &mergingArm1 = mArms[mergingArmIndexes.front()];
  auto const &mergingArm2 = mArms[mergingArmIndexes.back()];

  double const angleMergingArm1 = geometry::minimumAngleDifference(linkArm.orientation, mergingArm1.orientation);
  double const angleMergingArm2 = geometry::minimumAngleDifference(linkArm.orientation, mergingArm2.orientation);

  if (fabs(angleMergingArm1) > fabs(angleMergingArm2))
  {
    junction.mergingArmIndex = mergingArmIndexes.front();
    junction.normalArmIndex = mergingArmIndexes.back();
  }
  else
  {
    junction.mergingArmIndex = mergingArmIndexes.back();
    junction.normalArmIndex = mergingArmIndexes.front();
  }

  return true;
}

bool OsmTransitionDetector::isMergeJunction(map_data::MapDataStore const &store, MergeJunction &junction)
{
  std::vector<uint32_t> twoWayArmIndexes;
  std::vector<uint32_t> oneWayArmIndexes;

  for (uint32_t armIndex = 0; armIndex < mArms.size(); armIndex++)
  {
    auto const &road = store.road(mArms[armIndex].connectedRoad);
    if (isTwoWayRoad(road))
    {
      twoWayArmIndexes.push_back(armIndex);
    }
    else
    {
      oneWayArmIndexes.push_back(armIndex);
    }
  }

  if (twoWayArmIndexes.size() != 1)
  {
    return false;
  }

  junction.mergingArmIndex = twoWayArmIndexes.front();
  junction.leftArmIndex = oneWayArmIndexes.front();
  junction.rightArmIndex = oneWayArmIndexes.back();

  return true;
}

bool OsmTransitionDetector::isYJunction(map_data::MapDataStore const &store, MergeJunction &junction)
{
  if (!isMergeJunction(store, junction))
  {
    return false;
  }

  auto const twoWayArm = mArms[junction.mergingArmIndex];
  auto const firstArm = mArms[junction.leftArmIndex];
  auto const secondArm = mArms[junction.rightArmIndex];

  double alpha = fabs(geometry::minimumAngleDifference(twoWayArm.orientation, firstArm.orientation));
  double beta = fabs(geometry::minimumAngleDifference(twoWayArm.orientation, secondArm.orientation));
  double gamma = fabs(geometry::minimumAngleDifference(firstArm.orientation, secondArm.orientation));

  /**
   * Angles for a Y junction
   * Y connection
   *     gamma
   *    \     /
   *     \   /
   *      \ /
   * alpha x beta
   *       |
   *       |
   *       |
   * The junction is considered a Y junction if
   * gamma < M_PI_2
   * alpha < M_PI
   * beta  < M_PI
   *                            a T junction otherwise
   */

  if ((gamma < M_PI_2) && (alpha < M_PI) && (beta < M_PI))
  {
    return true;
  }
  else
  {
    return false;
  }
}

bool OsmTransitionDetector::isTJunction(map_data::MapDataStore const &store, MergeJunction &junction)
{
  if (!isMergeJunction(store, junction))
  {
    return false;
  }

  // A T junction is a merge junction that is not a Y junction.
  return (!isYJunction(store, junction));
}

bool OsmTransitionDetector::generateTJunctionOffset(map_data::MapDataStore const &store)
{
  MergeJunction junction;
  if (!isTJunction(store, junction))
  {
    return false;
  }

  auto const &twoWayArm = mArms[junction.mergingArmIndex];

  for (auto const &arm : mArms)
  {
    auto const &road = store.road(arm.connectedRoad);
    mTransitionOffsetForRoad[arm.connectedRoad] = defaultRoadOffset(road);
    mTransitionAngleForRoad[arm.connectedRoad] = arm.orientation;
  }
  // No offset for the two way arm
  mTransitionOffsetForRoad[twoWayArm.connectedRoad] = 0.0;
  mTransitionAngleForRoad[twoWayArm.connectedRoad] = twoWayArm.orientation;
  mGenerated = true;
  return true;
}

bool OsmTransitionDetector::generateYJunctionOffset(map_data::MapDataStore const &store)
{
  MergeJunction junction;
  if (!isYJunction(store, junction))
  {
    return false;
  }

  for (auto const &arm : mArms)
  {
    mTransitionOffsetForRoad[arm.connectedRoad] = 0.0;
    mTransitionAngleForRoad[arm.connectedRoad] = arm.orientation;
  }

  mGenerated = true;
  return true;
}

bool OsmTransitionDetector::generateRampJunctionOffset(map_data::MapDataStore const &store)
{
  RampJunction junction;
  if (!isRampJunction(store, junction))
  {
    return false;
  }

  auto const &mergingArm = mArms[junction.mergingArmIndex];
  auto const &mergingRoad = store.road(mergingArm.connectedRoad);
  for (auto const &arm : mArms)
  {
    mTransitionOffsetForRoad[arm.connectedRoad] = defaultRoadOffset(mergingRoad);
    mTransitionAngleForRoad[arm.connectedRoad] = arm.orientation;
  }
  auto const &linkArm = mArms[junction.rampArmIndex];
  auto const linkRoadId = linkArm.connectedRoad;
  auto const &linkRoad = store.road(linkRoadId);

  double mergingArmWidth{0.};

  double linkLanes = static_cast<double>(linkRoad.mForwardWidths.size());
  double widthOfMergingLane{0.};

  if (linkArm.isEntry)
  {
    mergingArmWidth = widthOut(mergingRoad, mergingArm.isEntry) - defaultRoadOffset(mergingRoad);
    widthOfMergingLane
      = widthOut(mergingRoad, mergingArm.isEntry) / static_cast<double>(lanesOut(mergingRoad, mergingArm.isEntry));
  }
  else
  {
    mergingArmWidth = widthIn(mergingRoad, mergingArm.isEntry) - defaultRoadOffset(mergingRoad);
    widthOfMergingLane
      = widthIn(mergingRoad, mergingArm.isEntry) / static_cast<double>(lanesIn(mergingRoad, mergingArm.isEntry));
  }

  mTransitionOffsetForRoad[linkRoadId] = -(mergingArmWidth - linkLanes * widthOfMergingLane);
  mTransitionAngleForRoad[linkRoadId] = mergingArm.orientation + M_PI;

  mGenerated = true;
  return true;
}

void OsmTransitionDetector::generateDefaultOffset(map_data::MapDataStore const &store)
{
  for (auto const &arm : mArms)
  {
    auto const &road = store.road(arm.connectedRoad);
    mTransitionOffsetForRoad[arm.connectedRoad] = defaultRoadOffset(road);
    mTransitionAngleForRoad[arm.connectedRoad] = arm.orientation;
  }
  mGenerated = true;
}

void OsmTransitionDetector::generateTransitionOffsets(map_data::MapDataStore const &store,
                                                      std::vector<RoadGeometry> const &roadsGeometry,
                                                      map_data::MapDataId const intersectionId)
{
  mArms = store.intersection(intersectionId).mArms;

  if (mGenerated)
  {
    return;
  }

  if (!setRoadsGeometry(roadsGeometry))
  {
    generateDefaultOffset(store);
    return;
  }

  calculateArmsOrientation();

  if (mArms.size() != 3u)
  {
    generateDefaultOffset(store);
    return;
  }

  if (generateYJunctionOffset(store))
  {
    return;
  }
  else if (generateTJunctionOffset(store))
  {
    return;
  }
  else if (generateRampJunctionOffset(store))
  {
    return;
  }
  else
  {
    generateDefaultOffset(store);
  }
}

} // namespace osm_converter
} // namespace maker
} // namespace map
} // namespace ad
