// ----------------- BEGIN LICENSE BLOCK ---------------------------------
//
// Copyright (C) 2018-2019 Intel Corporation
//
// SPDX-License-Identifier: MIT
//
// ----------------- END LICENSE BLOCK -----------------------------------

#pragma once

#include <string>

namespace ad {
namespace map {
namespace maker {
namespace map_data {

/**
 * @brief various types of landmarks
 *
 * Landmarkers are
 * - traffic lights
 * - traffic signs
 * - other landmarks
 *
 * In the below listing the first section is for traffic signs,
 * followed by traffic lights and finalized with misc. types
 * of landmarks.
 *
 * Whenever a new type is added it should also be added to the
 * two conversion functions fromString, toString as well as to
 * the accompagnying unit test.
 */
enum class LandmarkType
{
  /* first section: traffic signs */
  SignAdditionalSignArrowTurningLeft,
  SignAdditionalSignArrowTurningRight,
  SignAdditionalSignArrowBothDirLeftRight,
  SignAdditionalSignArrowBothDirUpDown,
  SignAdditionalSignArrowBothDirLeftRightBicycle,
  SignAdditionalSignArrowBothDirUpDownBicycle,
  SignAdditionalSignNextNKm,
  SignAdditionalSignEndOf,
  SignAdditionalSignAnliegerFrei,
  SignAdditionalSignBicycleAllowed,
  SignAdditionalSignMopedAllowed,
  SignAdditionalSignTramAllowed,
  SignAdditionalSignForrestalAllowed,
  SignAdditionalSignWorkingVehiclesAllowed,
  SignAdditionalSignEnvironmentZoneYellowGreen,
  SignAdditionalSignTram,
  SignAdditionalSignWeight,
  SignDanger,
  SignLanesMerging,
  SignPedestrian,
  SignChildren,
  SignBicycle,
  SignAnimals,
  SignTrainCrossingWithBarrier,
  SignTrainCrossing,
  SignYieldTrain,
  SignYield,
  SignStop,
  SignRequiredDirectionRight,
  SignRequiredDirectionLeft,
  SignRequiredDirectionStraight,
  SignRequiredDirectionStraightOrRight,
  SignRequiredDirectionStraightOrLeft,
  SignRoundabout,
  SignPassOnTheRight,
  SignPassOnTheLeft,
  SignBicyclePath,
  SignFootwalk,
  SignFootwalkAndBicycleShared,
  SignFootwalkAndBicycleSeparatedBicycleRight,
  SignFootwalkAndBicycleSeparatedBicycleLeft,
  SignPedestrianArea,
  SignAccessForbidden,
  SignAccessForbiddenTrucks,
  SignAccessForbiddenBicycles,
  SignAccessForbiddenMotorvehicles,
  SignAccessForbiddenWeight,
  SignAccessForbiddenWidth,
  SignAccessForbiddenHeight,
  SignEntranceForbidden,
  SignEnvironmentZoneBegin,
  SignEnvironmentZoneEnd,
  SignMaxSpeed,
  SignZoneMaxSpeed30Begin,
  SignZoneMaxSpeed30End,
  SignHasWayOnNextIntersection,
  SignPriorityWay,
  SignCityBegin,
  SignCityEnd,
  SignMotorwayBegin,
  SignMotorwayEnd,
  SignMotorVehicleBegin,
  SignMotorVehicleEnd,
  SignMotorwayExitInfo,
  SignCulDeSacRoad,
  SignCulDeSacRoadPedestrianBicycleAllowed,
  SignNumberOfAutobahn,
  SignTurnToAutobahn,
  SignTurnToLocalDirection,
  SignBigTurnInformation,
  SignFreeText, //!< a blank sign with arbitrary text on it, e.g. '15 m'

  /* second section: traffic lights */
  TrafficLight, //!< The type of traffic light is given via Landmark.supplement
  Crosswalk,

  /* third section: all others */
  MiscTree, //!< provide link to OSM wikipedia
  MiscStreetLamp,
  MiscPostBox,
  MiscManHole,
  MiscPowerCabinet,
  MiscFireHydrant,
  MiscBollard,

  /* this is the end */
  Unknown
};

LandmarkType fromString(std::string const &name);
std::string toString(LandmarkType markerType);

} // namespace map_data
} // namespace maker
} // namespace map
} // namespace ad
