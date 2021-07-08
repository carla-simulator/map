/*
 * ----------------- BEGIN LICENSE BLOCK ---------------------------------
 *
 * Copyright (c) 2017 Computer Vision Center (CVC) at the Universitat Autonoma
 * de Barcelona (UAB).
 * Copyright (C) 2019-2021 Intel Corporation
 *
 * SPDX-License-Identifier: MIT
 *
 * ----------------- END LICENSE BLOCK -----------------------------------
 */

#include "opendrive/parser/TrafficSignalsParser.h"
#include <iostream>

double assignDefaultValues(std::string const &s, double const defaultValue)
{
  double output{0.0};
  try
  {
    output = std::stod(s);
  }
  catch (...)
  {
    output = defaultValue;
  }
  return output;
}

opendrive::Validity opendrive::parser::TrafficSignalsParser::AddValidity(const pugi::xml_node &parent_node,
                                                                         const std::string &node_name)
{
  const pugi::xml_node validityNode = parent_node.child(node_name.c_str());
  Validity validityInfo;
  if (validityNode)
  {
    validityInfo.from_lane = std::stoi(validityNode.attribute("fromLane").value());
    validityInfo.to_lane = std::stoi(validityNode.attribute("toLane").value());
  }
  return validityInfo;
}

void opendrive::parser::TrafficSignalsParser::Parse(
  const pugi::xml_node &xmlNode,
  std::vector<opendrive::TrafficSignalInformation> &out_traffic_signals,
  std::vector<opendrive::TrafficSignalReference> &out_traffic_signal_references)
{
  for (pugi::xml_node signal = xmlNode.child("signal"); signal; signal = signal.next_sibling("signal"))
  {
    opendrive::TrafficSignalInformation trafficSignalInformation;

    trafficSignalInformation.id = std::stoi(signal.attribute("id").value());

    trafficSignalInformation.start_position = std::stod(signal.attribute("s").value());
    trafficSignalInformation.track_position = std::stod(signal.attribute("t").value());

    trafficSignalInformation.zoffset = std::stod(signal.attribute("zOffset").value());

    trafficSignalInformation.value = signal.attribute("value").as_double();

    trafficSignalInformation.name = signal.attribute("name").value();
    trafficSignalInformation.dynamic = signal.attribute("dynamic").value();
    trafficSignalInformation.orientation = signal.attribute("orientation").value();

    trafficSignalInformation.type = signal.attribute("type").value();
    trafficSignalInformation.subtype = signal.attribute("subtype").value();
    trafficSignalInformation.country = signal.attribute("country").value();

    if (signal.attribute("height") != nullptr)
    {
      trafficSignalInformation.height = assignDefaultValues(signal.attribute("height").value(), 0.0);
    }
    if (signal.attribute("width") != nullptr)
    {
      trafficSignalInformation.width = assignDefaultValues(signal.attribute("width").value(), 0.0);
    }
    if (signal.attribute("text") != nullptr)
    {
      trafficSignalInformation.text = signal.attribute("text").value();
    }
    if (signal.attribute("hOffset") != nullptr)
    {
      trafficSignalInformation.hoffset = assignDefaultValues(signal.attribute("hOffset").value(), 0.0);
    }
    if (signal.attribute("pitch") != nullptr)
    {
      trafficSignalInformation.pitch = assignDefaultValues(signal.attribute("pitch").value(), 2 * M_PI);
    }
    if (signal.attribute("roll") != nullptr)
    {
      trafficSignalInformation.roll = assignDefaultValues(signal.attribute("roll").value(), 2 * M_PI);
    }

    trafficSignalInformation.validityInformation = AddValidity(signal, "validity");

    for (pugi::xml_node dependency_node : signal.children("dependency"))
    {
      opendrive::TrafficSignalDependency dependency;
      dependency.dependent_signal_id = std::stoi(dependency_node.attribute("id").value());
      dependency.type = dependency_node.attribute("type").value();
      trafficSignalInformation.dependencies.push_back(dependency);
    }

    for (pugi::xml_node position_node_inertial : signal.children("positionInertial"))
    {
      trafficSignalInformation.physical_position_inertial.valid = true;
      trafficSignalInformation.physical_position_inertial.location.x
        = position_node_inertial.attribute("x").as_double();
      trafficSignalInformation.physical_position_inertial.location.y
        = position_node_inertial.attribute("y").as_double();
      trafficSignalInformation.physical_position_inertial.location.z
        = position_node_inertial.attribute("z").as_double();
      trafficSignalInformation.physical_position_inertial.hdg = position_node_inertial.attribute("hdg").as_double();
      trafficSignalInformation.physical_position_inertial.pitch = position_node_inertial.attribute("pitch").as_double();
      trafficSignalInformation.physical_position_inertial.roll = position_node_inertial.attribute("roll").as_double();
    }

    for (pugi::xml_node position_node_road : signal.children("positionRoad"))
    {
      trafficSignalInformation.physical_position_road.valid = true;
      trafficSignalInformation.physical_position_road.reference_road_id
        = std::stoi(position_node_road.attribute("roadId").value());
      trafficSignalInformation.physical_position_road.sOffset = position_node_road.attribute("s").as_double();
      trafficSignalInformation.physical_position_road.tOffset = position_node_road.attribute("t").as_double();
      trafficSignalInformation.physical_position_road.zOffset = position_node_road.attribute("zOffset").as_double();
      trafficSignalInformation.physical_position_road.hOffset = position_node_road.attribute("hOffset").as_double();
      trafficSignalInformation.physical_position_road.pitch = position_node_road.attribute("pitch").as_double();
      trafficSignalInformation.physical_position_road.roll = position_node_road.attribute("roll").as_double();
    }

    out_traffic_signals.emplace_back(trafficSignalInformation);
  }

  for (pugi::xml_node signal = xmlNode.child("signalReference"); signal;
       signal = signal.next_sibling("signalReference"))
  {
    opendrive::TrafficSignalReference trafficSignalReference;

    trafficSignalReference.id = std::stoi(signal.attribute("id").value());
    trafficSignalReference.start_position = std::stod(signal.attribute("s").value());
    trafficSignalReference.track_position = std::stod(signal.attribute("t").value());
    trafficSignalReference.orientation = signal.attribute("orientation").value();

    for (pugi::xml_node userData = xmlNode.child("signalReference").child("userData"); userData;
         userData = userData.next_sibling("userData"))
    {
      std::string node_name = "vectorSignal";
      for (pugi::xml_node vector_node = userData.child(node_name.c_str()); vector_node;
           vector_node = vector_node.next_sibling("vectorSignal"))
      {
        trafficSignalReference.relation = vector_node.attribute("turnRelation").value();
      }
    }

    trafficSignalReference.validityInfo = AddValidity(signal, "validity");
    out_traffic_signal_references.emplace_back(trafficSignalReference);
  }
}
