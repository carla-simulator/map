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

#include "opendrive/parser/ObjectParser.h"

void opendrive::parser::ObjectParser::Parse(const pugi::xml_node &xmlNode,
                                            std::vector<opendrive::RoadObjects> &out_objects)
{
  opendrive::RoadObjects gRoadObjects;

  // parse all objects
  pugi::xml_node node_objects = xmlNode.child("objects");
  if (node_objects)
  {
    for (pugi::xml_node node_object : node_objects.children("object"))
    {
      // type Crosswalk
      gRoadObjects.type = node_object.attribute("type").as_string();
      gRoadObjects.name = node_object.attribute("name").as_string();
      if (gRoadObjects.type == "crosswalk")
      {
        // read all points
        pugi::xml_node node_outline = node_object.child("outline");
        if (node_outline)
        {
          for (pugi::xml_node node_corner : node_outline.children("cornerLocal"))
          {
            gRoadObjects.outline.u = node_corner.attribute("u").as_double();
            gRoadObjects.outline.v = node_corner.attribute("v").as_double();
            gRoadObjects.outline.z = node_corner.attribute("z").as_double();
          }
        }
      }
      else if (gRoadObjects.name.substr(0, 6) == "Speed_" || gRoadObjects.name.substr(0, 6) == "speed_")
      {
        std::string speed_str = gRoadObjects.name.substr(6);
        gRoadObjects.speed = std::stod(speed_str);
      }
      else if (gRoadObjects.name.find("Stencil_STOP") != std::string::npos)
      {
      }
      out_objects.emplace_back(gRoadObjects);
    }
  }
}
