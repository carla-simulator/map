// ----------------- BEGIN LICENSE BLOCK ---------------------------------
//
// Copyright (C) 2017-2020 Intel Corporation
//
// SPDX-License-Identifier: MIT
//
// ----------------- END LICENSE BLOCK -----------------------------------

#include "ad/map/maker/osm_converter/OsmWayIterator.hpp"

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wconversion"
#include <osmium/osm/node.hpp>
#include <osmium/osm/way.hpp>
#pragma GCC diagnostic pop

#include <ad/map/maker/common/LogChannel.hpp>
#include "ad/map/maker/osm_converter/OsmJunctionProcessor.hpp"
#include "ad/map/maker/osm_converter/OsmObjectStore.hpp"

namespace ad {
namespace map {
namespace maker {
namespace osm_converter {

OsmWayIterator OsmWayIterator::setupWayIteratorForJunctionArm(std::shared_ptr<OsmObjectStore> store,
                                                              std::shared_ptr<OsmJunctionProcessor> junctionProcessor,
                                                              OsmJunctionArm const &osmArm,
                                                              common::LogChannel &logging)
{
  OsmWayIterator it(store, junctionProcessor, osmArm.mWayId, osmArm.mIndexOfCenter, logging);
  if (!it.isValid())
  {
    logging(common::LogLevel::Error) << "Unable to create iterator for way " << osmArm.mWayId << " and starting node "
                                     << osmArm.mArmId << "\n";
    throw std::runtime_error("Unable to create iterator for way " + std::to_string(osmArm.mWayId)
                             + std::string(" and starting node ") + std::to_string(osmArm.mArmId));
  }

  // only rewind if the arm is an incoming arm
  if (osmArm.mIncoming)
  {
    logging(common::LogLevel::Verbose) << "  rewind iterator (incoming arm).\n";
    it.rewind();
  }
  if (!it.isValid())
  {
    logging(common::LogLevel::Error) << "Invalid iterator after rewind for way " << osmArm.mWayId
                                     << " and starting node " << osmArm.mArmId << "\n";
    throw std::runtime_error("Invalid iterator after rewind for way " + std::to_string(osmArm.mWayId)
                             + std::string(" and starting node ") + std::to_string(osmArm.mArmId));
  }
  return it;
  // TODO does OsmWayIterator need an explicit move constructor (OsmWayIterator&&)?
  // TODO hopefully this can be removed once the old lanelet_generator is removed
}

OsmWayIterator::OsmWayIterator(std::shared_ptr<OsmObjectStore> store,
                               std::shared_ptr<OsmJunctionProcessor> junctionProcessor,
                               ::osmium::object_id_type const wayId,
                               size_t const indexInNodeList,
                               common::LogChannel &logging)
  : mStore(store)
  , mJunctionProcessor(junctionProcessor)
  , mWay(wayId)
  , mCurrentNode()
  , mIndex(indexInNodeList)
  , mLog(logging)
{
  if (!bool(mStore))
  {
    throw std::invalid_argument("invalid store");
  }

  extractNodeAndValidateIndex();
}

void OsmWayIterator::extractNodeAndValidateIndex()
{
  mIsValid = false;
  if (mStore->hasWay(mWay))
  {
    // verify index
    ::osmium::Way const &way = mStore->way(mWay);
    if (mIndex < way.nodes().size())
    {
      mCurrentNode = way.nodes()[mIndex].ref();
      mIsValid = true;
    }
  }
}

bool OsmWayIterator::isValid() const
{
  return mIsValid;
}

::osmium::object_id_type OsmWayIterator::currentWay() const
{
  return mWay;
}

::osmium::object_id_type OsmWayIterator::currentNode() const
{
  return mCurrentNode;
}

bool OsmWayIterator::next()
{
  if (!isValid())
  {
    return false;
  }

  ::osmium::Way const &myWay = mStore->way(currentWay());
  if ((mIndex + 1) < myWay.nodes().size())
  {
    ++mIndex;
  }
  else
  {
    // end of the way, two cases:
    // 1. exactly one successor (which is not us)
    // 2. else exit with false (and log message)
    ::osmium::object_id_type successorId;
    if (mJunctionProcessor->uniqueSuccessorForWay(currentWay(), successorId))
    {
      mWay = successorId;
      mIndex = 1;
      mLog(common::LogLevel::Verbose) << "[next]  switching to unambigous next way " << currentWay() << " at point "
                                      << myWay.nodes()[mIndex].ref() << "\n";
    }
  }

  ::osmium::Way const &way = mStore->way(currentWay());
  mCurrentNode = way.nodes()[mIndex].ref();
  if ((mIndex + 1) < way.nodes().size())
  {
    return !(mJunctionProcessor->isJunctionCenter(mCurrentNode));
  }
  else
  {
    ::osmium::object_id_type tmp{};
    return (mJunctionProcessor->uniqueSuccessorForWay(currentWay(), tmp));
  }
  return false;
}

bool OsmWayIterator::prev()
{
  if (!isValid())
  {
    return false;
  }

  if (mIndex > 0)
  {
    --mIndex;
  }
  else
  {
    ::osmium::object_id_type prevWayId;
    if (mJunctionProcessor->uniquePredecessorForWay(currentWay(), prevWayId))
    {
      ::osmium::Way const &way = mStore->way(prevWayId);
      if (way.nodes().size() < 2)
      {
        mLog(common::LogLevel::Error) << "OsmWayIterator: Way has only one node! WayId " << prevWayId << "\n";
        throw std::runtime_error("OsmWayIterator: Way has only one node! while parsing " + std::to_string(prevWayId));
      }
      mIndex = way.nodes().size() - 2;
      mWay = prevWayId;

      mLog(common::LogLevel::Verbose) << "[prev]  switching to unambigous previous way " << currentWay() << " at point "
                                      << way.nodes()[mIndex].ref() << "\n";
    }
  }

  ::osmium::Way const &myWay = mStore->way(currentWay());
  mCurrentNode = myWay.nodes()[mIndex].ref();
  if (mIndex > 0)
  {
    return !(mJunctionProcessor->isJunctionCenter(currentNode()));
  }
  else
  {
    ::osmium::object_id_type tmp{};
    return mJunctionProcessor->uniquePredecessorForWay(currentWay(), tmp);
  }
}

void OsmWayIterator::rewind()
{
  if (!isValid())
  {
    return;
  }

  // make sure we do not loop infinitely
  std::unordered_set<::osmium::object_id_type> visitedNodes;

  // only for logging
  ::osmium::object_id_type const enterWayId = currentWay();
  ::osmium::object_id_type const enterNodeId = currentNode();
  mLog(common::LogLevel::Verbose) << "[rewind] enter " << currentWay() << " node: " << currentNode() << "\n";
  do
  {
    mLog(common::LogLevel::Verbose) << "[rewind]   " << currentWay() << " node: " << currentNode() << "\n";
    if (!visitedNodes.insert(currentNode()).second)
    {
      mLog(common::LogLevel::Warning) << "[rewind] Loop detected. Giving up. (way id: " << enterWayId
                                      << ", starting node: " << enterNodeId << ")\n";
      return;
    }
  } while (prev());
  mLog(common::LogLevel::Verbose) << "[rewind] exit " << currentWay() << " node: " << currentNode() << "\n";
}

} // namespace osm_converter
} // namespace maker
} // namespace map
} // namespace ad
