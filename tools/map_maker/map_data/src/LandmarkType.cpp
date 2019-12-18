// ----------------- BEGIN LICENSE BLOCK ---------------------------------
//
// Copyright (C) 2018-2019 Intel Corporation
//
// SPDX-License-Identifier: MIT
//
// ----------------- END LICENSE BLOCK -----------------------------------

#include "ad/map/maker/map_data/LandmarkType.hpp"

#include <stdexcept>

namespace ad {
namespace map {
namespace maker {
namespace map_data {

LandmarkType fromString(std::string const &strVal)
{
  if (strVal == "SignAdditionalSignArrowTurningLeft")
  {
    return LandmarkType::SignAdditionalSignArrowTurningLeft;
  }
  else if (strVal == "SignAdditionalSignArrowTurningRight")
  {
    return LandmarkType::SignAdditionalSignArrowTurningRight;
  }
  else if (strVal == "SignAdditionalSignArrowBothDirLeftRight")
  {
    return LandmarkType::SignAdditionalSignArrowBothDirLeftRight;
  }
  else if (strVal == "SignAdditionalSignArrowBothDirUpDown")
  {
    return LandmarkType::SignAdditionalSignArrowBothDirUpDown;
  }
  else if (strVal == "SignAdditionalSignArrowBothDirLeftRightBicycle")
  {
    return LandmarkType::SignAdditionalSignArrowBothDirLeftRightBicycle;
  }
  else if (strVal == "SignAdditionalSignArrowBothDirUpDownBicycle")
  {
    return LandmarkType::SignAdditionalSignArrowBothDirUpDownBicycle;
  }
  else if (strVal == "SignAdditionalSignNextNKm")
  {
    return LandmarkType::SignAdditionalSignNextNKm;
  }
  else if (strVal == "SignAdditionalSignEndOf")
  {
    return LandmarkType::SignAdditionalSignEndOf;
  }
  else if (strVal == "SignAdditionalSignAnliegerFrei")
  {
    return LandmarkType::SignAdditionalSignAnliegerFrei;
  }
  else if (strVal == "SignAdditionalSignBicycleAllowed")
  {
    return LandmarkType::SignAdditionalSignBicycleAllowed;
  }
  else if (strVal == "SignAdditionalSignMopedAllowed")
  {
    return LandmarkType::SignAdditionalSignMopedAllowed;
  }
  else if (strVal == "SignAdditionalSignTramAllowed")
  {
    return LandmarkType::SignAdditionalSignTramAllowed;
  }
  else if (strVal == "SignAdditionalSignForrestalAllowed")
  {
    return LandmarkType::SignAdditionalSignForrestalAllowed;
  }
  else if (strVal == "SignAdditionalSignWorkingVehiclesAllowed")
  {
    return LandmarkType::SignAdditionalSignWorkingVehiclesAllowed;
  }
  else if (strVal == "SignAdditionalSignEnvironmentZoneYellowGreen")
  {
    return LandmarkType::SignAdditionalSignEnvironmentZoneYellowGreen;
  }
  else if (strVal == "SignAdditionalSignTram")
  {
    return LandmarkType::SignAdditionalSignTram;
  }
  else if (strVal == "SignAdditionalSignWeight")
  {
    return LandmarkType::SignAdditionalSignWeight;
  }
  else if (strVal == "SignDanger")
  {
    return LandmarkType::SignDanger;
  }
  else if (strVal == "SignLanesMerging")
  {
    return LandmarkType::SignLanesMerging;
  }
  else if (strVal == "SignPedestrian")
  {
    return LandmarkType::SignPedestrian;
  }
  else if (strVal == "SignChildren")
  {
    return LandmarkType::SignChildren;
  }
  else if (strVal == "SignBicycle")
  {
    return LandmarkType::SignBicycle;
  }
  else if (strVal == "SignAnimals")
  {
    return LandmarkType::SignAnimals;
  }
  else if (strVal == "SignTrainCrossingWithBarrier")
  {
    return LandmarkType::SignTrainCrossingWithBarrier;
  }
  else if (strVal == "SignTrainCrossing")
  {
    return LandmarkType::SignTrainCrossing;
  }
  else if (strVal == "SignYieldTrain")
  {
    return LandmarkType::SignYieldTrain;
  }
  else if (strVal == "SignYield")
  {
    return LandmarkType::SignYield;
  }
  else if (strVal == "SignStop")
  {
    return LandmarkType::SignStop;
  }
  else if (strVal == "SignRequiredDirectionRight")
  {
    return LandmarkType::SignRequiredDirectionRight;
  }
  else if (strVal == "SignRequiredDirectionLeft")
  {
    return LandmarkType::SignRequiredDirectionLeft;
  }
  else if (strVal == "SignRequiredDirectionStraight")
  {
    return LandmarkType::SignRequiredDirectionStraight;
  }
  else if (strVal == "SignRequiredDirectionStraightOrRight")
  {
    return LandmarkType::SignRequiredDirectionStraightOrRight;
  }
  else if (strVal == "SignRequiredDirectionStraightOrLeft")
  {
    return LandmarkType::SignRequiredDirectionStraightOrLeft;
  }
  else if (strVal == "SignRoundabout")
  {
    return LandmarkType::SignRoundabout;
  }
  else if (strVal == "SignPassOnTheRight")
  {
    return LandmarkType::SignPassOnTheRight;
  }
  else if (strVal == "SignPassOnTheLeft")
  {
    return LandmarkType::SignPassOnTheLeft;
  }
  else if (strVal == "SignBicyclePath")
  {
    return LandmarkType::SignBicyclePath;
  }
  else if (strVal == "SignFootwalk")
  {
    return LandmarkType::SignFootwalk;
  }
  else if (strVal == "SignFootwalkAndBicycleShared")
  {
    return LandmarkType::SignFootwalkAndBicycleShared;
  }
  else if (strVal == "SignFootwalkAndBicycleSeparatedBicycleRight")
  {
    return LandmarkType::SignFootwalkAndBicycleSeparatedBicycleRight;
  }
  else if (strVal == "SignFootwalkAndBicycleSeparatedBicycleLeft")
  {
    return LandmarkType::SignFootwalkAndBicycleSeparatedBicycleLeft;
  }
  else if (strVal == "SignPedestrianArea")
  {
    return LandmarkType::SignPedestrianArea;
  }
  else if (strVal == "SignAccessForbidden")
  {
    return LandmarkType::SignAccessForbidden;
  }
  else if (strVal == "SignAccessForbiddenTrucks")
  {
    return LandmarkType::SignAccessForbiddenTrucks;
  }
  else if (strVal == "SignAccessForbiddenBicycles")
  {
    return LandmarkType::SignAccessForbiddenBicycles;
  }
  else if (strVal == "SignAccessForbiddenMotorvehicles")
  {
    return LandmarkType::SignAccessForbiddenMotorvehicles;
  }
  else if (strVal == "SignAccessForbiddenWeight")
  {
    return LandmarkType::SignAccessForbiddenWeight;
  }
  else if (strVal == "SignAccessForbiddenWidth")
  {
    return LandmarkType::SignAccessForbiddenWidth;
  }
  else if (strVal == "SignAccessForbiddenHeight")
  {
    return LandmarkType::SignAccessForbiddenHeight;
  }
  else if (strVal == "SignEntranceForbidden")
  {
    return LandmarkType::SignEntranceForbidden;
  }
  else if (strVal == "SignEnvironmentZoneBegin")
  {
    return LandmarkType::SignEnvironmentZoneBegin;
  }
  else if (strVal == "SignEnvironmentZoneEnd")
  {
    return LandmarkType::SignEnvironmentZoneEnd;
  }
  else if (strVal == "SignMaxSpeed")
  {
    return LandmarkType::SignMaxSpeed;
  }
  else if (strVal == "SignZoneMaxSpeed30Begin")
  {
    return LandmarkType::SignZoneMaxSpeed30Begin;
  }
  else if (strVal == "SignZoneMaxSpeed30End")
  {
    return LandmarkType::SignZoneMaxSpeed30End;
  }
  else if (strVal == "SignHasWayOnNextIntersection")
  {
    return LandmarkType::SignHasWayOnNextIntersection;
  }
  else if (strVal == "SignPriorityWay")
  {
    return LandmarkType::SignPriorityWay;
  }
  else if (strVal == "SignCityBegin")
  {
    return LandmarkType::SignCityBegin;
  }
  else if (strVal == "SignCityEnd")
  {
    return LandmarkType::SignCityEnd;
  }
  else if (strVal == "SignMotorwayBegin")
  {
    return LandmarkType::SignMotorwayBegin;
  }
  else if (strVal == "SignMotorwayEnd")
  {
    return LandmarkType::SignMotorwayEnd;
  }
  else if (strVal == "SignMotorVehicleBegin")
  {
    return LandmarkType::SignMotorVehicleBegin;
  }
  else if (strVal == "SignMotorVehicleEnd")
  {
    return LandmarkType::SignMotorVehicleEnd;
  }
  else if (strVal == "SignMotorwayExitInfo")
  {
    return LandmarkType::SignMotorwayExitInfo;
  }
  else if (strVal == "SignCulDeSacRoad")
  {
    return LandmarkType::SignCulDeSacRoad;
  }
  else if (strVal == "SignCulDeSacRoadPedestrianBicycleAllowed")
  {
    return LandmarkType::SignCulDeSacRoadPedestrianBicycleAllowed;
  }
  else if (strVal == "SignNumberOfAutobahn")
  {
    return LandmarkType::SignNumberOfAutobahn;
  }
  else if (strVal == "SignTurnToAutobahn")
  {
    return LandmarkType::SignTurnToAutobahn;
  }
  else if (strVal == "SignTurnToLocalDirection")
  {
    return LandmarkType::SignTurnToLocalDirection;
  }
  else if (strVal == "SignBigTurnInformation")
  {
    return LandmarkType::SignBigTurnInformation;
  }
  else if (strVal == "SignFreeText")
  {
    return LandmarkType::SignFreeText;
  }
  else if (strVal == "TrafficLight")
  {
    return LandmarkType::TrafficLight;
  }
  else if (strVal == "Crosswalk")
  {
    return LandmarkType::Crosswalk;
  }
  else if (strVal == "MiscTree")
  {
    return LandmarkType::MiscTree;
  }
  else if (strVal == "MiscStreetLamp")
  {
    return LandmarkType::MiscStreetLamp;
  }
  else if (strVal == "MiscPostBox")
  {
    return LandmarkType::MiscPostBox;
  }
  else if (strVal == "MiscManHole")
  {
    return LandmarkType::MiscManHole;
  }
  else if (strVal == "MiscPowerCabinet")
  {
    return LandmarkType::MiscPowerCabinet;
  }
  else if (strVal == "MiscFireHydrant")
  {
    return LandmarkType::MiscFireHydrant;
  }
  else if (strVal == "MiscBollard")
  {
    return LandmarkType::MiscBollard;
  }
  else
  {
    return LandmarkType::Unknown;
  }
}

std::string toString(LandmarkType markerType)
{
  // clang-format off
  switch (markerType)
  {
    case LandmarkType::SignAdditionalSignArrowTurningLeft: return "SignAdditionalSignArrowTurningLeft";
    case LandmarkType::SignAdditionalSignArrowTurningRight: return "SignAdditionalSignArrowTurningRight";
    case LandmarkType::SignAdditionalSignArrowBothDirLeftRight: return "SignAdditionalSignArrowBothDirLeftRight";
    case LandmarkType::SignAdditionalSignArrowBothDirUpDown: return "SignAdditionalSignArrowBothDirUpDown";
    case LandmarkType::SignAdditionalSignArrowBothDirLeftRightBicycle: return "SignAdditionalSignArrowBothDirLeftRightBicycle";
    case LandmarkType::SignAdditionalSignArrowBothDirUpDownBicycle: return "SignAdditionalSignArrowBothDirUpDownBicycle";
    case LandmarkType::SignAdditionalSignNextNKm: return "SignAdditionalSignNextNKm";
    case LandmarkType::SignAdditionalSignEndOf: return "SignAdditionalSignEndOf";
    case LandmarkType::SignAdditionalSignAnliegerFrei: return "SignAdditionalSignAnliegerFrei";
    case LandmarkType::SignAdditionalSignBicycleAllowed: return "SignAdditionalSignBicycleAllowed";
    case LandmarkType::SignAdditionalSignMopedAllowed: return "SignAdditionalSignMopedAllowed";
    case LandmarkType::SignAdditionalSignTramAllowed: return "SignAdditionalSignTramAllowed";
    case LandmarkType::SignAdditionalSignForrestalAllowed: return "SignAdditionalSignForrestalAllowed";
    case LandmarkType::SignAdditionalSignWorkingVehiclesAllowed: return "SignAdditionalSignWorkingVehiclesAllowed";
    case LandmarkType::SignAdditionalSignEnvironmentZoneYellowGreen: return "SignAdditionalSignEnvironmentZoneYellowGreen";
    case LandmarkType::SignAdditionalSignTram: return "SignAdditionalSignTram";
    case LandmarkType::SignAdditionalSignWeight: return "SignAdditionalSignWeight";
    case LandmarkType::SignDanger: return "SignDanger";
    case LandmarkType::SignLanesMerging: return "SignLanesMerging";
    case LandmarkType::SignPedestrian: return "SignPedestrian";
    case LandmarkType::SignChildren: return "SignChildren";
    case LandmarkType::SignBicycle: return "SignBicycle";
    case LandmarkType::SignAnimals: return "SignAnimals";
    case LandmarkType::SignTrainCrossingWithBarrier: return "SignTrainCrossingWithBarrier";
    case LandmarkType::SignTrainCrossing: return "SignTrainCrossing";
    case LandmarkType::SignYieldTrain: return "SignYieldTrain";
    case LandmarkType::SignYield: return "SignYield";
    case LandmarkType::SignStop: return "SignStop";
    case LandmarkType::SignRequiredDirectionRight: return "SignRequiredDirectionRight";
    case LandmarkType::SignRequiredDirectionLeft: return "SignRequiredDirectionLeft";
    case LandmarkType::SignRequiredDirectionStraight: return "SignRequiredDirectionStraight";
    case LandmarkType::SignRequiredDirectionStraightOrRight: return "SignRequiredDirectionStraightOrRight";
    case LandmarkType::SignRequiredDirectionStraightOrLeft: return "SignRequiredDirectionStraightOrLeft";
    case LandmarkType::SignRoundabout: return "SignRoundabout";
    case LandmarkType::SignPassOnTheRight: return "SignPassOnTheRight";
    case LandmarkType::SignPassOnTheLeft: return "SignPassOnTheLeft";
    case LandmarkType::SignBicyclePath: return "SignBicyclePath";
    case LandmarkType::SignFootwalk: return "SignFootwalk";
    case LandmarkType::SignFootwalkAndBicycleShared: return "SignFootwalkAndBicycleShared";
    case LandmarkType::SignFootwalkAndBicycleSeparatedBicycleRight: return "SignFootwalkAndBicycleSeparatedBicycleRight";
    case LandmarkType::SignFootwalkAndBicycleSeparatedBicycleLeft: return "SignFootwalkAndBicycleSeparatedBicycleLeft";
    case LandmarkType::SignPedestrianArea: return "SignPedestrianArea";
    case LandmarkType::SignAccessForbidden: return "SignAccessForbidden";
    case LandmarkType::SignAccessForbiddenTrucks: return "SignAccessForbiddenTrucks";
    case LandmarkType::SignAccessForbiddenBicycles: return "SignAccessForbiddenBicycles";
    case LandmarkType::SignAccessForbiddenMotorvehicles: return "SignAccessForbiddenMotorvehicles";
    case LandmarkType::SignAccessForbiddenWeight: return "SignAccessForbiddenWeight";
    case LandmarkType::SignAccessForbiddenWidth: return "SignAccessForbiddenWidth";
    case LandmarkType::SignAccessForbiddenHeight: return "SignAccessForbiddenHeight";
    case LandmarkType::SignEntranceForbidden: return "SignEntranceForbidden";
    case LandmarkType::SignEnvironmentZoneBegin: return "SignEnvironmentZoneBegin";
    case LandmarkType::SignEnvironmentZoneEnd: return "SignEnvironmentZoneEnd";
    case LandmarkType::SignMaxSpeed: return "SignMaxSpeed";
    case LandmarkType::SignZoneMaxSpeed30Begin: return "SignZoneMaxSpeed30Begin";
    case LandmarkType::SignZoneMaxSpeed30End: return "SignZoneMaxSpeed30End";
    case LandmarkType::SignHasWayOnNextIntersection: return "SignHasWayOnNextIntersection";
    case LandmarkType::SignPriorityWay: return "SignPriorityWay";
    case LandmarkType::SignCityBegin: return "SignCityBegin";
    case LandmarkType::SignCityEnd: return "SignCityEnd";
    case LandmarkType::SignMotorwayBegin: return "SignMotorwayBegin";
    case LandmarkType::SignMotorwayEnd: return "SignMotorwayEnd";
    case LandmarkType::SignMotorVehicleBegin: return "SignMotorVehicleBegin";
    case LandmarkType::SignMotorVehicleEnd: return "SignMotorVehicleEnd";
    case LandmarkType::SignMotorwayExitInfo: return "SignMotorwayExitInfo";
    case LandmarkType::SignCulDeSacRoad: return "SignCulDeSacRoad";
    case LandmarkType::SignCulDeSacRoadPedestrianBicycleAllowed: return "SignCulDeSacRoadPedestrianBicycleAllowed";
    case LandmarkType::SignNumberOfAutobahn: return "SignNumberOfAutobahn";
    case LandmarkType::SignTurnToAutobahn: return "SignTurnToAutobahn";
    case LandmarkType::SignTurnToLocalDirection: return "SignTurnToLocalDirection";
    case LandmarkType::SignBigTurnInformation: return "SignBigTurnInformation";
    case LandmarkType::SignFreeText: return "SignFreeText";
    case LandmarkType::TrafficLight: return "TrafficLight";
    case LandmarkType::Crosswalk: return "Crosswalk";
    case LandmarkType::MiscTree: return "MiscTree";
    case LandmarkType::MiscStreetLamp: return "MiscStreetLamp";
    case LandmarkType::MiscPostBox: return "MiscPostBox";
    case LandmarkType::MiscManHole: return "MiscManHole";
    case LandmarkType::MiscPowerCabinet: return "MiscPowerCabinet";
    case LandmarkType::MiscFireHydrant: return "MiscFireHydrant";
    case LandmarkType::MiscBollard: return "MiscBollard";
    case LandmarkType::Unknown: return "Unknown";
  }
  // clang-format on
  throw std::runtime_error("Unknown enum value");
}

} // namespace map_data
} // namespace maker
} // namespace map
} // namespace ad
