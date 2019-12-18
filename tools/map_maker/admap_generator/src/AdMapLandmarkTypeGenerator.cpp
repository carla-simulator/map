// ----------------- BEGIN LICENSE BLOCK ---------------------------------
//
// Copyright (C) 2018-2019 Intel Corporation
//
// SPDX-License-Identifier: MIT
//
// ----------------- END LICENSE BLOCK -----------------------------------

#include "ad/map/maker/admap_generator/AdMapLandmarkTypeGenerator.hpp"
#include <ad/map/maker/map_data/LandmarkType.hpp>
#include <stdexcept>

namespace ad {
namespace map {
namespace maker {
namespace admap_generator {

landmark::TrafficSignType trafficSignToAdMap(map_data::LandmarkType trafficSign)
{
  switch (trafficSign)
  {
    case map_data::LandmarkType::SignDanger:
      return landmark::TrafficSignType::DANGER;
    case map_data::LandmarkType::SignLanesMerging:
      return landmark::TrafficSignType::LANES_MERGING;
    case map_data::LandmarkType::SignPedestrian:
      return landmark::TrafficSignType::CAUTION_PEDESTRIAN;
    case map_data::LandmarkType::SignChildren:
      return landmark::TrafficSignType::CAUTION_CHILDREN;
    case map_data::LandmarkType::SignBicycle:
      return landmark::TrafficSignType::CAUTION_BICYCLE;
    case map_data::LandmarkType::SignAnimals:
      return landmark::TrafficSignType::CAUTION_ANIMALS;
    case map_data::LandmarkType::SignTrainCrossingWithBarrier:
      return landmark::TrafficSignType::CAUTION_RAIL_CROSSING_WITH_BARRIER;
    case map_data::LandmarkType::SignTrainCrossing:
      return landmark::TrafficSignType::CAUTION_RAIL_CROSSING;
    case map_data::LandmarkType::SignYieldTrain:
      return landmark::TrafficSignType::YIELD_TRAIN;
    case map_data::LandmarkType::SignYield:
      return landmark::TrafficSignType::YIELD;
    case map_data::LandmarkType::SignStop:
      return landmark::TrafficSignType::STOP;
    case map_data::LandmarkType::SignRequiredDirectionLeft:
      return landmark::TrafficSignType::REQUIRED_LEFT_TURN;
    case map_data::LandmarkType::SignRequiredDirectionStraight:
      return landmark::TrafficSignType::REQUIRED_STRAIGHT;
    case map_data::LandmarkType::SignRequiredDirectionRight:
      return landmark::TrafficSignType::REQUIRED_RIGHT_TURN;
    case map_data::LandmarkType::SignRequiredDirectionStraightOrLeft:
      return landmark::TrafficSignType::REQUIRED_STRAIGHT_OR_LEFT_TURN;
    case map_data::LandmarkType::SignRequiredDirectionStraightOrRight:
      return landmark::TrafficSignType::REQUIRED_STRAIGHT_OR_RIGHT_TURN;
    case map_data::LandmarkType::SignRoundabout:
      return landmark::TrafficSignType::ROUNDABOUT;
    case map_data::LandmarkType::SignPassOnTheLeft:
      return landmark::TrafficSignType::PASS_LEFT;
    case map_data::LandmarkType::SignPassOnTheRight:
      return landmark::TrafficSignType::PASS_RIGHT;
    case map_data::LandmarkType::SignBicyclePath:
      return landmark::TrafficSignType::BYBICLE_PATH;
    case map_data::LandmarkType::SignFootwalk:
      return landmark::TrafficSignType::FOOTWALK;
    case map_data::LandmarkType::SignFootwalkAndBicycleShared:
      return landmark::TrafficSignType::FOOTWALK_BICYCLE_SHARED;
    case map_data::LandmarkType::SignFootwalkAndBicycleSeparatedBicycleLeft:
      return landmark::TrafficSignType::FOOTWALK_BICYCLE_SEP_LEFT;
    case map_data::LandmarkType::SignFootwalkAndBicycleSeparatedBicycleRight:
      return landmark::TrafficSignType::FOOTWALK_BICYCLE_SEP_RIGHT;
    case map_data::LandmarkType::SignPedestrianArea:
      return landmark::TrafficSignType::PEDESTRIAN_AREA_BEGIN;
    case map_data::LandmarkType::SignAccessForbidden:
      return landmark::TrafficSignType::ACCESS_FORBIDDEN;
    case map_data::LandmarkType::SignAccessForbiddenTrucks:
      return landmark::TrafficSignType::ACCESS_FORBIDDEN_TRUCKS;
    case map_data::LandmarkType::SignAccessForbiddenBicycles:
      return landmark::TrafficSignType::ACCESS_FORBIDDEN_BICYCLE;
    case map_data::LandmarkType::SignAccessForbiddenMotorvehicles:
      return landmark::TrafficSignType::ACCESS_FORBIDDEN_MOTORVEHICLES;
    case map_data::LandmarkType::SignAccessForbiddenWeight:
      return landmark::TrafficSignType::ACCESS_FORBIDDEN_WEIGHT;
    case map_data::LandmarkType::SignAccessForbiddenWidth:
      return landmark::TrafficSignType::ACCESS_FORBIDDEN_WIDTH;
    case map_data::LandmarkType::SignAccessForbiddenHeight:
      return landmark::TrafficSignType::ACCESS_FORBIDDEN_HEIGHT;
    case map_data::LandmarkType::SignEntranceForbidden:
      return landmark::TrafficSignType::ACCESS_FORBIDDEN_WRONG_DIR;
    case map_data::LandmarkType::SignEnvironmentZoneBegin:
      return landmark::TrafficSignType::ENVIORNMENT_ZONE_BEGIN;
    case map_data::LandmarkType::SignEnvironmentZoneEnd:
      return landmark::TrafficSignType::ENVIORNMENT_ZONE_END;
    case map_data::LandmarkType::SignZoneMaxSpeed30Begin:
      return landmark::TrafficSignType::SPEED_ZONE_30_BEGIN;
    case map_data::LandmarkType::SignZoneMaxSpeed30End:
      return landmark::TrafficSignType::SPEED_ZONE_30_END;
    case map_data::LandmarkType::SignMaxSpeed:
      return landmark::TrafficSignType::MAX_SPEED;
    case map_data::LandmarkType::SignHasWayOnNextIntersection:
      return landmark::TrafficSignType::HAS_WAY_NEXT_INTERSECTION;
    case map_data::LandmarkType::SignPriorityWay:
      return landmark::TrafficSignType::PRIORITY_WAY;
    case map_data::LandmarkType::SignCityBegin:
      return landmark::TrafficSignType::CITY_BEGIN;
    case map_data::LandmarkType::SignCityEnd:
      return landmark::TrafficSignType::CITY_END;
    case map_data::LandmarkType::SignMotorwayBegin:
      return landmark::TrafficSignType::MOTORWAY_BEGIN;
    case map_data::LandmarkType::SignMotorwayEnd:
      return landmark::TrafficSignType::MOTORWAY_END;
    case map_data::LandmarkType::SignMotorVehicleBegin:
      return landmark::TrafficSignType::MOTORVEHICLE_BEGIN;
    case map_data::LandmarkType::SignMotorVehicleEnd:
      return landmark::TrafficSignType::MOTORVEHICLE_END;
    case map_data::LandmarkType::SignMotorwayExitInfo:
      return landmark::TrafficSignType::INFO_MOTORWAY_INFO;
    case map_data::LandmarkType::SignCulDeSacRoadPedestrianBicycleAllowed:
      return landmark::TrafficSignType::CUL_DE_SAC_EXCEPT_PED_BICYCLE;
    case map_data::LandmarkType::SignCulDeSacRoad:
      return landmark::TrafficSignType::CUL_DE_SAC;
    case map_data::LandmarkType::SignNumberOfAutobahn:
      return landmark::TrafficSignType::INFO_NUMBER_OF_AUTOBAHN;
    case map_data::LandmarkType::SignTurnToAutobahn:
      return landmark::TrafficSignType::DIRECTION_TURN_TO_AUTOBAHN;
    case map_data::LandmarkType::SignTurnToLocalDirection:
      return landmark::TrafficSignType::DIRECTION_TURN_TO_LOCAL;
    case map_data::LandmarkType::SignBigTurnInformation:
      return landmark::TrafficSignType::DESTINATION_BOARD;
    case map_data::LandmarkType::SignAdditionalSignArrowTurningLeft:
      return landmark::TrafficSignType::SUPPLEMENT_ARROW_APPLIES_LEFT;
    case map_data::LandmarkType::SignAdditionalSignArrowTurningRight:
      return landmark::TrafficSignType::SUPPLEMENT_ARROW_APPLIES_RIGHT;
    case map_data::LandmarkType::SignAdditionalSignArrowBothDirLeftRight:
      return landmark::TrafficSignType::SUPPLEMENT_ARROW_APPLIES_LEFT_RIGHT;
    case map_data::LandmarkType::SignAdditionalSignArrowBothDirUpDown:
      return landmark::TrafficSignType::SUPPLEMENT_ARROW_APPLIES_UP_DOWN;
    case map_data::LandmarkType::SignAdditionalSignArrowBothDirLeftRightBicycle:
      return landmark::TrafficSignType::SUPPLEMENT_ARROW_APPLIES_LEFT_RIGHT_BICYCLE;
    case map_data::LandmarkType::SignAdditionalSignArrowBothDirUpDownBicycle:
      return landmark::TrafficSignType::SUPPLEMENT_ARROW_APPLIES_UP_DOWN_BICYCLE;
    case map_data::LandmarkType::SignAdditionalSignNextNKm:
      return landmark::TrafficSignType::SUPPLEMENT_APPLIES_NEXT_N_KM_TIME;
    case map_data::LandmarkType::SignAdditionalSignEndOf:
      return landmark::TrafficSignType::SUPPLEMENT_ENDS;
    case map_data::LandmarkType::SignAdditionalSignAnliegerFrei:
      return landmark::TrafficSignType::SUPPLEMENT_RESIDENTS_ALLOWED;
    case map_data::LandmarkType::SignAdditionalSignBicycleAllowed:
      return landmark::TrafficSignType::SUPPLEMENT_BICYCLE_ALLOWED;
    case map_data::LandmarkType::SignAdditionalSignMopedAllowed:
      return landmark::TrafficSignType::SUPPLEMENT_MOPED_ALLOWED;
    case map_data::LandmarkType::SignAdditionalSignTramAllowed:
      return landmark::TrafficSignType::SUPPLEMENT_TRAM_ALLOWED;
    case map_data::LandmarkType::SignAdditionalSignForrestalAllowed:
      return landmark::TrafficSignType::SUPPLEMENT_FORESTAL_ALLOWED;
    case map_data::LandmarkType::SignAdditionalSignWorkingVehiclesAllowed:
      return landmark::TrafficSignType::SUPPLEMENT_CONSTRUCTION_VEHICLE_ALLOWED;
    case map_data::LandmarkType::SignAdditionalSignEnvironmentZoneYellowGreen:
      return landmark::TrafficSignType::SUPPLEMENT_ENVIRONMENT_ZONE_YELLOW_GREEN;
    case map_data::LandmarkType::SignAdditionalSignTram:
      return landmark::TrafficSignType::SUPPLEMENT_RAILWAY_ONLY;
    case map_data::LandmarkType::SignAdditionalSignWeight:
      return landmark::TrafficSignType::SUPPLEMENT_APPLIES_FOR_WEIGHT;
    case map_data::LandmarkType::SignFreeText:
      return landmark::TrafficSignType::UNKNOWN;
    case map_data::LandmarkType::Unknown:
      return landmark::TrafficSignType::UNKNOWN;
    case map_data::LandmarkType::Crosswalk:
      return landmark::TrafficSignType::UNKNOWN;
    case map_data::LandmarkType::MiscStreetLamp:
      return landmark::TrafficSignType::UNKNOWN;
    case map_data::LandmarkType::TrafficLight:
      return landmark::TrafficSignType::UNKNOWN;
    case map_data::LandmarkType::MiscManHole:
      return landmark::TrafficSignType::UNKNOWN;
    case map_data::LandmarkType::MiscBollard:
      return landmark::TrafficSignType::UNKNOWN;
    case map_data::LandmarkType::MiscPowerCabinet:
      return landmark::TrafficSignType::UNKNOWN;
    case map_data::LandmarkType::MiscTree:
      return landmark::TrafficSignType::UNKNOWN;
    case map_data::LandmarkType::MiscFireHydrant:
      return landmark::TrafficSignType::UNKNOWN;
    case map_data::LandmarkType::MiscPostBox:
      return landmark::TrafficSignType::UNKNOWN;
  }
  throw std::runtime_error("Unhandled enum of map_data::LandmarkType");
}

landmark::LandmarkType landmarkTypeToAdMap(map_data::LandmarkType landmarkType)
{
  switch (landmarkType)
  {
    case map_data::LandmarkType::SignFreeText:
      return landmark::LandmarkType::UNKNOWN;
    case map_data::LandmarkType::Unknown:
      return landmark::LandmarkType::UNKNOWN;
    case map_data::LandmarkType::Crosswalk:
      return landmark::LandmarkType::UNKNOWN;
    case map_data::LandmarkType::MiscStreetLamp:
      return landmark::LandmarkType::STREET_LAMP;
    case map_data::LandmarkType::TrafficLight:
      return landmark::LandmarkType::UNKNOWN;
    case map_data::LandmarkType::MiscManHole:
      return landmark::LandmarkType::MANHOLE;
    case map_data::LandmarkType::MiscBollard:
      return landmark::LandmarkType::BOLLARD;
    case map_data::LandmarkType::MiscPowerCabinet:
      return landmark::LandmarkType::POWERCABINET;
    case map_data::LandmarkType::MiscTree:
      return landmark::LandmarkType::TREE;
    case map_data::LandmarkType::MiscFireHydrant:
      return landmark::LandmarkType::FIRE_HYDRANT;
    case map_data::LandmarkType::MiscPostBox:
      return landmark::LandmarkType::POSTBOX;
    default:
      return landmark::LandmarkType::UNKNOWN;
  }
}

} // namespace admap_generator
} // namespace maker
} // namespace map
} // namespace ad
