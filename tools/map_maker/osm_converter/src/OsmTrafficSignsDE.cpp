// ----------------- BEGIN LICENSE BLOCK ---------------------------------
//
// Copyright (C) 2018-2020 Intel Corporation
//
// SPDX-License-Identifier: MIT
//
// ----------------- END LICENSE BLOCK -----------------------------------

#include "ad/map/maker/osm_converter/OsmTrafficSignsDE.hpp"

namespace ad {
namespace map {
namespace maker {
namespace osm_converter {

std::unordered_map<std::string, map_data::LandmarkType> const &getTrafficSignsDE()
{
  // German signs:
  // https://de.wikipedia.org/wiki/Bildtafel_der_Verkehrszeichen_in_der_Bundesrepublik_Deutschland_seit_2017
  // clang-format off
  static std::unordered_map<std::string, map_data::LandmarkType> strToTrafficSignMap
  {
    // DE:1000 additional arrows
    {"DE:1000-11", map_data::LandmarkType::SignAdditionalSignArrowTurningLeft},
    {"DE:1000-21", map_data::LandmarkType::SignAdditionalSignArrowTurningRight},
    {"DE:1000-30", map_data::LandmarkType::SignAdditionalSignArrowBothDirLeftRight},
    {"DE:1000-31", map_data::LandmarkType::SignAdditionalSignArrowBothDirUpDown},
    {"DE:1000-32", map_data::LandmarkType::SignAdditionalSignArrowBothDirLeftRightBicycle},
    {"DE:1000-33", map_data::LandmarkType::SignAdditionalSignArrowBothDirUpDownBicycle},
    {"DE:1001-31", map_data::LandmarkType::SignAdditionalSignNextNKm},
    {"DE:1012-31", map_data::LandmarkType::SignAdditionalSignEndOf},
    {"DE:1020-30", map_data::LandmarkType::SignAdditionalSignAnliegerFrei},
    {"DE:1022-10", map_data::LandmarkType::SignAdditionalSignBicycleAllowed},
    {"DE:1022-11", map_data::LandmarkType::SignAdditionalSignMopedAllowed},
    {"DE:1024-16", map_data::LandmarkType::SignAdditionalSignTramAllowed},
    {"DE:1026-37", map_data::LandmarkType::SignAdditionalSignForrestalAllowed},
    {"DE:1028-30", map_data::LandmarkType::SignAdditionalSignWorkingVehiclesAllowed},
    {"DE:1031-51", map_data::LandmarkType::SignAdditionalSignEnvironmentZoneYellowGreen},
    {"DE:1048-18", map_data::LandmarkType::SignAdditionalSignTram},
    {"DE:1052-53", map_data::LandmarkType::SignAdditionalSignWeight}, // typo in maps, should be 1052-35 (which is replaced by 1053-33 since 2017)
    {"DE:1053-33", map_data::LandmarkType::SignAdditionalSignWeight},
    {"DE:101",     map_data::LandmarkType::SignDanger},
    {"DE:120",     map_data::LandmarkType::SignLanesMerging},
    {"DE:133",     map_data::LandmarkType::SignPedestrian}, // should be either -10 (from right) or -20 (from left)
    {"DE:136",     map_data::LandmarkType::SignChildren},   // same here with -10, -20
    {"DE:138",     map_data::LandmarkType::SignBicycle},    // same here with -10, -20
    {"DE:142",     map_data::LandmarkType::SignAnimals},    // same here with -10, -20 (Wildwechsel)
    {"DE:150",     map_data::LandmarkType::SignTrainCrossingWithBarrier}, // only valid until Oct 2022 :-)
    {"DE:151",     map_data::LandmarkType::SignTrainCrossing},

    {"DE:201",     map_data::LandmarkType::SignYieldTrain}, // Andreaskreuz
    {"DE:205",     map_data::LandmarkType::SignYield},
    {"DE:206",     map_data::LandmarkType::SignStop},
    {"DE:209",     map_data::LandmarkType::SignRequiredDirectionRight},
    {"DE:209-10",  map_data::LandmarkType::SignRequiredDirectionLeft},
    {"DE:209-20",  map_data::LandmarkType::SignRequiredDirectionRight},
    {"DE:209-30",  map_data::LandmarkType::SignRequiredDirectionStraight},
    {"DE:214",     map_data::LandmarkType::SignRequiredDirectionStraightOrRight},
    {"DE:214-10",  map_data::LandmarkType::SignRequiredDirectionStraightOrLeft},
    {"DE:214-20",  map_data::LandmarkType::SignRequiredDirectionStraightOrRight},
    {"DE:215",     map_data::LandmarkType::SignRoundabout},
    {"DE:222",     map_data::LandmarkType::SignPassOnTheRight},
    {"DE:222-10",  map_data::LandmarkType::SignPassOnTheLeft},
    {"DE:222-20",  map_data::LandmarkType::SignPassOnTheRight},
    {"DE:237",     map_data::LandmarkType::SignBicyclePath},
    {"DE:239",     map_data::LandmarkType::SignFootwalk},
    {"DE:240",     map_data::LandmarkType::SignFootwalkAndBicycleShared},
    {"DE:241",     map_data::LandmarkType::SignFootwalkAndBicycleSeparatedBicycleRight}, // doesn't exist
    {"DE:241-30",  map_data::LandmarkType::SignFootwalkAndBicycleSeparatedBicycleLeft},
    {"DE:241-31",  map_data::LandmarkType::SignFootwalkAndBicycleSeparatedBicycleRight},
    {"DE:242.1",   map_data::LandmarkType::SignPedestrianArea},
    {"DE:250",     map_data::LandmarkType::SignAccessForbidden},
    {"DE:253",     map_data::LandmarkType::SignAccessForbiddenTrucks}, // >3.5t
    {"DE:254",     map_data::LandmarkType::SignAccessForbiddenBicycles},
    {"DE:260",     map_data::LandmarkType::SignAccessForbiddenMotorvehicles}, // Kraftfahrzeuge
    {"DE:262",     map_data::LandmarkType::SignAccessForbiddenWeight},
    {"DE:263",     map_data::LandmarkType::SignAccessForbiddenWidth},
    {"DE:265",     map_data::LandmarkType::SignAccessForbiddenHeight},
    {"DE:267",     map_data::LandmarkType::SignEntranceForbidden}, // Gegen Einbahnstrasse
    {"DE:270.1",   map_data::LandmarkType::SignEnvironmentZoneBegin},
    {"DE:270.2",   map_data::LandmarkType::SignEnvironmentZoneEnd},
    {"DE:274",     map_data::LandmarkType::SignMaxSpeed}, // Geschwindigkeitsbeschraenkung
    {"DE:274.1",   map_data::LandmarkType::SignZoneMaxSpeed30Begin},
    {"DE:274.2",   map_data::LandmarkType::SignZoneMaxSpeed30End},
    {"DE:301",     map_data::LandmarkType::SignHasWayOnNextIntersection},
    {"DE:306",     map_data::LandmarkType::SignPriorityWay}, // Vorfahrtsstrasse
    {"DE:310",     map_data::LandmarkType::SignCityBegin},
    {"DE:311",     map_data::LandmarkType::SignCityEnd},
    {"DE:330.1",   map_data::LandmarkType::SignMotorwayBegin},
    {"DE:330.2",   map_data::LandmarkType::SignMotorwayEnd},
    {"DE:331.1",   map_data::LandmarkType::SignMotorVehicleBegin}, // Kraftfahrtstrasse
    {"DE:331.2",   map_data::LandmarkType::SignMotorVehicleEnd},   // Kraftfahrtstrasse
    {"DE:332",     map_data::LandmarkType::SignMotorwayExitInfo},
    {"DE:357",     map_data::LandmarkType::SignCulDeSacRoad}, // Sackgasse
    {"DE:357-50",  map_data::LandmarkType::SignCulDeSacRoadPedestrianBicycleAllowed},
    {"DE:405",     map_data::LandmarkType::SignNumberOfAutobahn},
    {"DE:430",     map_data::LandmarkType::SignTurnToAutobahn},       // Wegweiser zur Autobahn
    {"DE:432",     map_data::LandmarkType::SignTurnToLocalDirection}, // Wegweiser zu lokalem Ziel, e.g. Bahnhof
    {"DE:438",     map_data::LandmarkType::SignBigTurnInformation},   // Wegweisertafel
    {"DE:439",     map_data::LandmarkType::SignBigTurnInformation}
  };
  // clang-format on
  return strToTrafficSignMap;
}

} // namespace osm_converter
} // namespace maker
} // namespace map
} // namespace ad
