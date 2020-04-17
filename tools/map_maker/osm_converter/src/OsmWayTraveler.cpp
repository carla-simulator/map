// ----------------- BEGIN LICENSE BLOCK ---------------------------------
//
// Copyright (C) 2017-2020 Intel Corporation
//
// SPDX-License-Identifier: MIT
//
// ----------------- END LICENSE BLOCK -----------------------------------

#include "ad/map/maker/osm_converter/OsmWayTraveler.hpp"

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wconversion"
#include <osmium/osm/node.hpp>
#include <osmium/osm/way.hpp>
#pragma GCC diagnostic pop

#include <ad/map/maker/common/LogChannel.hpp>
#include <ad/map/maker/geometry/Point.hpp>
#include "ad/map/maker/osm_converter/OsmJunctionProcessor.hpp"
#include "ad/map/maker/osm_converter/OsmObjectStore.hpp"
#include "ad/map/maker/osm_converter/PointStore.hpp"

namespace ad {
namespace map {
namespace maker {
namespace osm_converter {

OsmWayTraveler::OsmWayTraveler(std::shared_ptr<OsmObjectStore> store,
                               std::shared_ptr<OsmJunctionProcessor> junctionProcessor,
                               std::shared_ptr<PointStore> pointStore,
                               OsmJunctionArm const &osmArm,
                               common::LogChannel &logging)
  : mPointStore(pointStore)
  , mIterator(OsmWayIterator::setupWayIteratorForJunctionArm(store, junctionProcessor, osmArm, logging))
{
  mPreviousNode = mIterator.currentNode();
  mPreviousWay = mIterator.currentWay();
  (void)stillTraveling();
}

bool OsmWayTraveler::stillTraveling()
{
  if (mEndIsReached)
  {
    return false;
  }

  mTraveledDistance += distanceFromPreviousToCurrent();

  mPreviousNode = mIterator.currentNode();
  mPreviousWay = mIterator.currentWay();

  // This is the real magic. If OsmWayIterator reports false here
  // we still get a valid (last) point. Therefore we will return "true"
  // because this time all is fine. The next call to stillTravelling will
  // return false immediately and the OsmWayIterator will not be called again
  mEndIsReached = !mIterator.next();
  mWayHasChanged = (mPreviousWay != mIterator.currentWay());

  if (mEndIsReached)
  {
    mTotalDistance = mTraveledDistance + distanceFromPreviousToCurrent();
  }

  return true;
}

double OsmWayTraveler::distanceFromPreviousToCurrent() const
{
  geometry::Point const &previous = mPointStore->point(mPreviousNode);
  geometry::Point const &current = mPointStore->point(mIterator.currentNode());

  return std::sqrt(squaredDistance(previous, current));
}

::osmium::object_id_type OsmWayTraveler::currentNode() const
{
  return mIterator.currentNode();
}

::osmium::object_id_type OsmWayTraveler::previousNode() const
{
  return mPreviousNode;
}

::osmium::object_id_type OsmWayTraveler::currentWay() const
{
  return mIterator.currentWay();
}

::osmium::object_id_type OsmWayTraveler::previousWay() const
{
  return mPreviousWay;
}

bool OsmWayTraveler::wayHasChanged() const
{
  return mWayHasChanged;
}

double OsmWayTraveler::traveledDistance() const
{
  return mTraveledDistance;
}

double OsmWayTraveler::totalDistance() const
{
  return mTotalDistance;
}

bool OsmWayTraveler::endReached() const
{
  return mEndIsReached;
}

} // namespace osm_converter
} // namespace maker
} // namespace map
} // namespace ad
