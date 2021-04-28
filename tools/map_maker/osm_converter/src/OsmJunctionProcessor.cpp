// ----------------- BEGIN LICENSE BLOCK ---------------------------------
//
// Copyright (C) 2017-2020 Intel Corporation
//
// SPDX-License-Identifier: MIT
//
// ----------------- END LICENSE BLOCK -----------------------------------

#include "ad/map/maker/osm_converter/OsmJunctionProcessor.hpp"

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wconversion"
#include <osmium/osm/node.hpp>
#include <osmium/osm/way.hpp>
#pragma GCC diagnostic pop

#include <ad/map/maker/common/LogChannel.hpp>
#include <ad/map/maker/common/LogFactory.hpp>
#include <ad/map/maker/common/StringHelper.hpp>
#include "ad/map/maker/osm_converter/OsmHighwayType.hpp"
#include "ad/map/maker/osm_converter/OsmObjectStore.hpp"
#include "ad/map/maker/osm_converter/OsmWayIterator.hpp"
#include "ad/map/maker/osm_converter/PointStore.hpp"

namespace ad {
namespace map {
namespace maker {
namespace osm_converter {

OsmJunctionProcessor::OsmJunctionProcessor(common::LogFactory &logFactory, std::shared_ptr<OsmObjectStore> store)
  : mLog(logFactory.logChannel("OsmJunctionProcessor"))
  , mStore(store)
{
}

void OsmJunctionProcessor::setDefaultPriority(common::RightOfWay const rightOfWay)
{
  mDefaultPriority = rightOfWay;
}

void OsmJunctionProcessor::extractJunctions()
{
  mJunctionArms.clear();
  for (auto wayId : mStore->allWayIds())
  {
    ::osmium::Way const &way = mStore->way(wayId);
    mLog(common::LogLevel::Info) << "Processing way: " << wayId << "\n";
    // we assume that a way has at least two nodes
    for (uint32_t index = 1u; index < way.nodes().size(); ++index)
    {
      // way.nodes()[index] is the center, index-1 leads into it
      OsmJunctionArm in;
      in.mArmId = way.nodes()[index - 1u].ref();
      in.mCenterId = way.nodes()[index].ref();
      in.mIndexOfCenter = index;
      in.mIncoming = true;
      in.mWayId = wayId;
      mJunctionArms[way.nodes()[index].ref()].insert(in);

      // way.nodes()[index-1] is the center, index leads out of it
      OsmJunctionArm out;
      out.mArmId = way.nodes()[index].ref();
      out.mCenterId = way.nodes()[index - 1].ref();
      out.mIndexOfCenter = index - 1;
      out.mIncoming = false;
      out.mWayId = wayId;
      mJunctionArms[way.nodes()[index - 1].ref()].insert(out);
    }
  }

  compileListOfJunctionCenters();
  extractRightOfWay();

  if (mLog.willLogBeWrittenAtLevel(common::LogLevel::Verbose))
  {
    for (auto entry : mJunctionArms)
    {
      logJunction(entry.first);
    }
  }
}

bool OsmJunctionProcessor::isJunctionCenter(::osmium::object_id_type const nodeId) const
{
  if (mJunctionArms.count(nodeId) < 1)
  {
    return false;
  }

  if (mJunctionArms.at(nodeId).size() < 2)
  {
    return false;
  }

  if (mJunctionArms.at(nodeId).size() > 2)
  {
    return true;
  }

  auto it = mJunctionArms.at(nodeId).begin();
  OsmJunctionArm const &arm1 = *(it);
  ++it;
  OsmJunctionArm const &arm2 = *(it);
  if (arm1.mIncoming != arm2.mIncoming)
  {
    return false;
  }

  if (mLog.willLogBeWrittenAtLevel(common::LogLevel::Verbose))
  {
    std::string reason{"end"};
    if (arm1.mIncoming)
    {
      reason = "start";
    }
    mLog(common::LogLevel::Verbose) << "  isJunctionCenter: Two ways " << reason << " at same node: " << nodeId << "\n";
  }
  return true;
}

bool OsmJunctionProcessor::junctionHasRamp(::osmium::object_id_type const &idOfCenter) const
{
  if (!isJunctionCenter(idOfCenter))
  {
    return false;
  }

  auto junctionArms = mJunctionArms.at(idOfCenter);
  for (auto arm : junctionArms)
  {
    if (armIsRamp(arm))
    {
      return true;
    }
  }

  return false;
}

void OsmJunctionProcessor::compileListOfJunctionCenters()
{
  mJunctionCenters.clear();
  for (auto junctionId : mJunctionArms)
  {
    if (isJunctionCenter(junctionId.first))
    {
      mJunctionCenters.insert(junctionId.first);
    }
  }
}

std::unordered_set<::osmium::object_id_type> OsmJunctionProcessor::allJunctions() const
{
  return mJunctionCenters;
}

bool OsmJunctionProcessor::uniqueSuccessorForWay(::osmium::object_id_type const wayId,
                                                 ::osmium::object_id_type &successor) const
{
  ::osmium::Way const &way = mStore->way(wayId);
  ::osmium::object_id_type const &end = way.nodes().back().ref();
  if (mJunctionArms.count(end) == 0)
  {
    return false;
  }
  if (mJunctionArms.at(end).size() != 2)
  {
    return false;
  }

  for (OsmJunctionArm const &entry : mJunctionArms.at(end))
  {
    ::osmium::Way const &otherWay = mStore->way(entry.mWayId);
    if (otherWay.nodes().front().ref() == end)
    {
      successor = entry.mWayId;
      return true;
    }
  }

  return false;
}

bool OsmJunctionProcessor::uniquePredecessorForWay(::osmium::object_id_type const wayId,
                                                   ::osmium::object_id_type &predecessor) const
{
  ::osmium::Way const &way = mStore->way(wayId);
  ::osmium::object_id_type const &start = way.nodes().front().ref();
  if (mJunctionArms.count(start) == 0)
  {
    return false;
  }
  if (mJunctionArms.at(start).size() != 2)
  {
    return false;
  }

  for (OsmJunctionArm const &entry : mJunctionArms.at(start))
  {
    ::osmium::Way const &otherWay = mStore->way(entry.mWayId);
    if (otherWay.nodes().back().ref() == start)
    {
      predecessor = entry.mWayId;
      return true;
    }
  }

  return false;
}

std::unordered_set<OsmJunctionArm>
OsmJunctionProcessor::junctionArms(::osmium::object_id_type const junctionCenter) const
{
  return mJunctionArms.at(junctionCenter);
}

void OsmJunctionProcessor::logJunction(::osmium::object_id_type const junctionCenter)
{
  auto entry = mJunctionArms.find(junctionCenter);
  mLog(common::LogLevel::Verbose) << "Center: " << entry->first << "\n";
  for (OsmJunctionArm const &arm : entry->second)
  {
    std::string dir = " <-- ";
    if (arm.mIncoming)
    {
      dir = " --> ";
    }
    mLog(common::LogLevel::Verbose) << dir << arm.mArmId << " (" << arm.mWayId << ")" << dir << arm.mCenterId
                                    << " right of way: " << rowToString(arm.mRightOfWay) << "\n";
  }
}

OsmJunctionArm OsmJunctionProcessor::getOsmArm(::osmium::object_id_type centerNode,
                                               ::osmium::object_id_type entryNode) const
{
  auto osmJunctionEntries = junctionArms(centerNode);
  for (auto osmArm : osmJunctionEntries)
  {
    if (osmArm.mArmId == entryNode)
    {
      return osmArm;
    }
  }

  throw std::runtime_error("Unable to extract OsmJunctionArm for center " + std::to_string(centerNode)
                           + std::string(" and entry ") + std::to_string(entryNode));
}

bool OsmJunctionProcessor::armIsRamp(OsmJunctionArm const &arm) const
{
  ::osmium::Way const &way = mStore->way(arm.mWayId);
  const char *highway = way.tags()["highway"];
  if (common::endsWith(highway, "_link"))
  {
    return true;
  }
  return false;
}

bool OsmJunctionProcessor::junctionIsOffRamp(::osmium::object_id_type const idOfCenter) const
{
  auto junctionArms = mJunctionArms.at(idOfCenter);
  for (auto arm : junctionArms)
  {
    if (armIsRamp(arm) && !arm.mIncoming)
    {
      return true;
    }
  }

  return false;
}

OsmJunctionArm OsmJunctionProcessor::getRampForJunction(::osmium::object_id_type const idOfCenter) const
{
  auto junctionArms = mJunctionArms.at(idOfCenter);
  for (auto arm : junctionArms)
  {
    if (armIsRamp(arm))
    {
      return arm;
    }
  }

  throw std::runtime_error("Unable to return OsmJunctionArm as ramp " + std::to_string(idOfCenter));
}

bool nodeIsTrafficSign(::osmium::Node const &node, bool isForward, const char *typeOfSign)
{
  if (isForward)
  {
    const char *traffic_sign = node.tags()["traffic_sign"];
    if (traffic_sign)
    {
      return (strstr(traffic_sign, typeOfSign) != nullptr);
    }
    const char *traffic_sign_forward = node.tags()["traffic_sign:forward"];
    if (traffic_sign_forward)
    {
      return (strstr(traffic_sign_forward, typeOfSign) != nullptr);
    }
    return false;
  }
  else
  {
    const char *traffic_sign_backward = node.tags()["traffic_sign:backward"];
    if (traffic_sign_backward)
    {
      return (strstr(traffic_sign_backward, typeOfSign) != nullptr);
    }
    return false;
  }
}

bool nodeIsGiveWay(::osmium::Node const &node, bool isForward)
{
  return nodeIsTrafficSign(node, isForward, "DE:205");
}

bool nodeIsStop(::osmium::Node const &node, bool isForward)
{
  return nodeIsTrafficSign(node, isForward, "DE:206");
}

common::RightOfWay OsmJunctionProcessor::getRowDefinedByNode(OsmJunctionArm const &arm,
                                                             ::osmium::Node const &node) const
{
  const char *highway = node.tags()["highway"];
  if (!highway)
  {
    mLog(common::LogLevel::Info) << "Given node " << node.id() << " has no attribute \"highway\".\n";
    return common::RightOfWay::Undefined;
  }

  // check for attribute trafficsign:[forward:backward] = DE:205 (GiveWay) or DE:206 (Stop)
  if (strcmp("give_way", highway) == 0)
  {
    if (nodeIsGiveWay(node, arm.mIncoming))
    {
      mLog(common::LogLevel::Verbose) << "Given node " << node.id() << " is GiveWay\n";
      return common::RightOfWay::GiveWay;
    }
    mLog(common::LogLevel::Info) << "Given node " << node.id() << " is not GiveWay\n";
  }
  else if (strcmp("stop", highway) == 0)
  {
    const char *stop = node.tags()["stop"];
    if (bool(stop) && (strcmp("all", stop) == 0))
    {
      if (nodeIsStop(node, arm.mIncoming))
      {
        mLog(common::LogLevel::Verbose) << "Given node " << node.id() << " is AllWayStop\n";
        return common::RightOfWay::AllWayStop;
      }
      mLog(common::LogLevel::Info) << "Given node " << node.id() << " is not AllWayStop\n";
    }
    else
    {
      if (nodeIsStop(node, arm.mIncoming))
      {
        mLog(common::LogLevel::Verbose) << "Given node " << node.id() << " is Stop\n";
        return common::RightOfWay::Stop;
      }
      mLog(common::LogLevel::Info) << "Given node " << node.id() << " is not Stop\n";
    }
  }

  return common::RightOfWay::Undefined;
}

common::RightOfWay OsmJunctionProcessor::rowForArm(OsmJunctionArm const &arm) const
{
  // extract node
  if (!mStore->hasNode(arm.mArmId))
  {
    mLog(common::LogLevel::Warning) << "Given arm-node " << arm.mArmId << " is not a node! Return Undefined\n";
    return common::RightOfWay::Undefined;
  }

  // get index of arm node within way
  int32_t currentIndex = 0;
  ::osmium::Way const &way = mStore->way(arm.mWayId);
  for (uint32_t i = 0; i < way.nodes().size(); i++)
  {
    if (way.nodes()[i].ref() == arm.mArmId)
    {
      currentIndex = static_cast<int32_t>(i);
    }
  }

  int32_t offset = 1;
  if (arm.mIncoming)
  {
    offset = -1;
  }

  auto currentNodeId = arm.mArmId;

  while (!isJunctionCenter(currentNodeId) && mStore->hasNode(currentNodeId))
  {
    auto const &node = mStore->node(currentNodeId);

    auto row = getRowDefinedByNode(arm, node);

    if (row != common::RightOfWay::Undefined)
    {
      mLog(common::LogLevel::Warning) << "Given arm-node " << arm.mArmId << " is " << rowToString(row) << "\n";
      return row;
    }

    // update nodeid
    currentIndex += offset;
    if ((currentIndex == static_cast<int32_t>(way.nodes().size())) || (currentIndex < 0))
    {
      // Not really an error, we simply don't know the regulation
      mLog(common::LogLevel::Info) << "No traffic regulation found. Reached end of way. Return undefined \n";
      return common::RightOfWay::Undefined;

      // @todo: change the way to predecessor/successor and continue iteration
      //        for now iterating over one way should be sufficient
    }
    currentNodeId = way.nodes()[static_cast<size_t>(currentIndex)].ref();
  }

  return common::RightOfWay::Undefined;
}

OsmHighwayType getHighwayType(::osmium::Way const &way)
{
  const char *highway = way.tags()["highway"];

  if (!highway)
  {
    return OsmHighwayType::Invalid;
  }

  return highwayTypeFromString(std::string(highway));
}

void OsmJunctionProcessor::setRightOfWayRamp(::osmium::object_id_type const idOfCenter)
{
  std::unordered_set<OsmJunctionArm> arms;
  for (auto arm : junctionArms(idOfCenter))
  {
    auto newArm = arm;
    newArm.mRightOfWay = common::RightOfWay::Ramp;
    arms.insert(newArm);
  }
  mJunctionArms[idOfCenter] = arms;
  mLog(common::LogLevel::Verbose) << "    Detected off-ramp\n";
}

bool OsmJunctionProcessor::setRightOfWayNormalIntersectionFirstPass(::osmium::object_id_type const idOfCenter,
                                                                    std::unordered_set<OsmJunctionArm> &arms) const
{
  bool assignHasWay{false};
  common::RightOfWay detectedRule{common::RightOfWay::Undefined};
  std::unordered_set<OsmJunctionArm> intermediateArms;
  for (auto const &arm : junctionArms(idOfCenter))
  {
    OsmJunctionArm newArm = arm;
    auto regulation = rowForArm(arm);
    mLog(common::LogLevel::Verbose) << "    junction arm: " << arm.mArmId << " has priority " << rowToString(regulation)
                                    << "\n";
    if ((regulation == common::RightOfWay::GiveWay) || (regulation == common::RightOfWay::Stop)
        || (regulation == common::RightOfWay::AllWayStop))
    {
      if ((regulation != detectedRule) && (detectedRule != common::RightOfWay::Undefined))
      {
        mLog(common::LogLevel::Warning) << "    Inconsistent right of way for arm/center: " << arm.mArmId << "/"
                                        << arm.mCenterId << "\n";
      }
      assignHasWay = true;
      detectedRule = regulation;
      newArm.mRightOfWay = regulation;
    }

    // if regulation is undefined, and the arm is an on-ramp (off-ramps are handled elsewhere)
    // set regulation for this arm to GiveWay
    if (armIsRamp(arm) && (regulation == common::RightOfWay::Undefined))
    {
      assignHasWay = true;
      newArm.mRightOfWay = common::RightOfWay::GiveWay;
    }

    intermediateArms.insert(newArm);
  }

  // if there is no traffic regulation detected, check if the connecting arms have different priorities
  // provided through the OSM Highway type (primary, secondary, etc.)
  if (detectedRule == common::RightOfWay::Undefined)
  {
    mLog(common::LogLevel::Verbose) << "    No traffic rule found for junction " << idOfCenter
                                    << " Checking now the highway types\n";
    // get highest priority of all roads in intersection
    OsmHighwayType highwayType = OsmHighwayType::Invalid;
    for (auto const &arm : junctionArms(idOfCenter))
    {
      const auto armHighwayType = getHighwayType(mStore->way(arm.mWayId));
      if (highwayType > armHighwayType)
      {
        highwayType = armHighwayType;
      }
    }

    mLog(common::LogLevel::Verbose) << "       Found road with highest priority to be "
                                    << highwayTypeToString(highwayType) << "\n";
    arms.clear();
    for (auto const &arm : junctionArms(idOfCenter))
    {
      OsmJunctionArm newArm = arm;
      const auto armHighwayType = getHighwayType(mStore->way(arm.mWayId));
      if (highwayType < armHighwayType)
      {
        newArm.mRightOfWay = common::RightOfWay::GiveWay;
        assignHasWay = true;
      }
      arms.insert(newArm);
      mLog(common::LogLevel::Verbose) << "       Updating arm  " << arm.mArmId << " to have regulation "
                                      << rowToString(newArm.mRightOfWay) << "\n";
    }
  }
  else
  {
    arms = intermediateArms;
  }

  return assignHasWay;
}

void OsmJunctionProcessor::setRightOfWayNormalIntersectionSecondPass(::osmium::object_id_type const idOfCenter,
                                                                     bool const assignHasWay,
                                                                     std::unordered_set<OsmJunctionArm> const &input,
                                                                     std::unordered_set<OsmJunctionArm> &output) const
{
  uint32_t numAssignedHasWay{0u};
  for (auto &arm : input)
  {
    OsmJunctionArm newArm = arm;
    if (arm.mRightOfWay == common::RightOfWay::Undefined)
    {
      newArm.mRightOfWay = (assignHasWay ? common::RightOfWay::HasWay : mDefaultPriority);
      mLog(common::LogLevel::Verbose) << "    adjusting regulation for junction arm: " << newArm.mArmId << " has "
                                      << rowToString(newArm.mRightOfWay) << "\n";

      if (assignHasWay)
      {
        ++numAssignedHasWay;
      }
    }
    output.insert(newArm);
  }
  if ((numAssignedHasWay > 0) && (numAssignedHasWay != 2))
  {
    mLog(common::LogLevel::Error) << "    Invalid number of arms (" << numAssignedHasWay
                                  << ") with HasWay for junction center: " << idOfCenter << "\n";
  }
}

void OsmJunctionProcessor::setRightOfWayNormalIntersection(::osmium::object_id_type const idOfCenter)
{
  // first run, extract all row of all arms and assign to the arms
  // this means go over all arms, first check:
  //   --  if there are traffic rules assigned
  //   --  if an arm is an on-ramp --> will lead to GiveWay regulation
  //   --  if the connecting arms have different priorities (i.e. OSM Highway types)
  std::unordered_set<OsmJunctionArm> firstFlush;
  bool assignHasWay = setRightOfWayNormalIntersectionFirstPass(idOfCenter, firstFlush);

  // second run, validity check: either assign HaveWay (if others have GiveWay or Stop) or assign default priority...
  std::unordered_set<OsmJunctionArm> secondFlush;
  setRightOfWayNormalIntersectionSecondPass(idOfCenter, assignHasWay, firstFlush, secondFlush);
  mJunctionArms[idOfCenter] = secondFlush;
}

void OsmJunctionProcessor::extractRightOfWay()
{
  mLog(common::LogLevel::Info) << "Setting up right of way for junctions\n";
  for (auto const &junctionCenter : allJunctions())
  {
    mLog(common::LogLevel::Verbose) << "  Processing junction center: " << junctionCenter << "\n";

    // handle off-ramp intersections in a special way to avoid yielding on straight roads
    if (junctionIsOffRamp(junctionCenter))
    {
      setRightOfWayRamp(junctionCenter);
    }
    else
    {
      setRightOfWayNormalIntersection(junctionCenter);
    }
  }
}

} // namespace osm_converter
} // namespace maker
} // namespace map
} // namespace ad
