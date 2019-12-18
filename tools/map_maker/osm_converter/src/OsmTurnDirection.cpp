// ----------------- BEGIN LICENSE BLOCK ---------------------------------
//
// INTEL CONFIDENTIAL
//
// Copyright (c) 2017-2019 Intel Corporation
//
// This software and the related documents are Intel copyrighted materials, and
// your use of them is governed by the express license under which they were
// provided to you (License). Unless the License provides otherwise, you may not
// use, modify, copy, publish, distribute, disclose or transmit this software or
// the related documents without Intel's prior written permission.
//
// This software and the related documents are provided as is, with no express or
// implied warranties, other than those that are expressly stated in the License.
//
// ----------------- END LICENSE BLOCK -----------------------------------

#include "ad/map/maker/osm_converter/OsmTurnDirection.hpp"
#include <ad/map/maker/common/StringHelper.hpp>
#include <cstring>
#include <iostream>
#include <map>

template <> std::vector<ad::map::maker::osm_converter::OsmTurnDirection> fromString(std::string const &str)
{
  static std::map<std::string const, ::ad::map::maker::osm_converter::OsmTurnDirection> strToOsmTurnDirectionMap{
    {{"left"}, ::ad::map::maker::osm_converter::OsmTurnDirection::Left},
    {{"slight_left"}, ::ad::map::maker::osm_converter::OsmTurnDirection::SlightLeft},
    {{"sharp_left"}, ::ad::map::maker::osm_converter::OsmTurnDirection::SharpLeft},
    {{"through"}, ::ad::map::maker::osm_converter::OsmTurnDirection::Through},
    {{"right"}, ::ad::map::maker::osm_converter::OsmTurnDirection::Right},
    {{"slight_right"}, ::ad::map::maker::osm_converter::OsmTurnDirection::SlightRight},
    {{"sharp_right"}, ::ad::map::maker::osm_converter::OsmTurnDirection::SharpRight},
    {{"reverse"}, ::ad::map::maker::osm_converter::OsmTurnDirection::Reverse},
    {{"merge_to_left"}, ::ad::map::maker::osm_converter::OsmTurnDirection::MergeToLeft},
    {{"merge_to_right"}, ::ad::map::maker::osm_converter::OsmTurnDirection::MergeToRight},
    {{"none"}, ::ad::map::maker::osm_converter::OsmTurnDirection::None},
    {{""}, ::ad::map::maker::osm_converter::OsmTurnDirection::None}};

  std::vector<::ad::map::maker::osm_converter::OsmTurnDirection> result;

  for (auto const &turnLane : ::ad::map::maker::common::splitString(str, ';'))
  {
    try
    {
      result.push_back(strToOsmTurnDirectionMap.at(turnLane.c_str()));
    }
    catch (std::exception const &e)
    {
      result.push_back(::ad::map::maker::osm_converter::OsmTurnDirection::Invalid);
    }
  }

  return result;
}
