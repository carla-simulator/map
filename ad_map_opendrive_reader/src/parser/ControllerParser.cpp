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

#include "opendrive/parser/ControllerParser.h"

void opendrive::parser::ControllerParser::Parse(const pugi::xml_node &xmlNode,
                                                std::vector<opendrive::Controller> &out_controllers,
                                                std::vector<opendrive::ControllerSignal> &out_controller_signals)
{
  for (pugi::xml_node controller_node = xmlNode.child("controller"); controller_node;
       controller_node = controller_node.next_sibling("controller"))
  {
    opendrive::Controller gController;
    gController.id = std::stoi(controller_node.attribute("id").value());
    gController.name = controller_node.attribute("name").value();
    gController.sequence = controller_node.attribute("sequence").as_int();

    out_controllers.emplace_back(gController);

    for (pugi::xml_node control_node : controller_node.children("control"))
    {
      opendrive::ControllerSignal gControllerSignal;
      gControllerSignal.id = control_node.attribute("signalId").as_int();
      gControllerSignal.type = control_node.attribute("type").value();
      out_controller_signals.emplace_back(gControllerSignal);
    }
  }
}
