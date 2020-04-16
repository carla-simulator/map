// ----------------- BEGIN LICENSE BLOCK ---------------------------------
//
// Copyright (C) 2017-2020 Intel Corporation
//
// SPDX-License-Identifier: MIT
//
// ----------------- END LICENSE BLOCK -----------------------------------

#include "ad/map/maker/osm_converter/PointStore.hpp"

#include <ostream>

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wconversion"
#include <osmium/osm/location.hpp>
#pragma GCC diagnostic pop

#include <ad/map/maker/common/LogChannel.hpp>
#include <ad/map/maker/common/LogFactory.hpp>
#include <ad/map/maker/geometry/CoordinateTransform.hpp>
#include "ad/map/maker/osm_converter/OsmObjectStore.hpp"

namespace ad {
namespace map {
namespace maker {
namespace osm_converter {

PointStore::PointStore(common::LogFactory &logFactory)
  : mLog(logFactory.logChannel("PointStore"))
{
}

void PointStore::extractPointsFromStore(std::shared_ptr<OsmObjectStore> store)
{
  for (auto nodeId : store->allNodeIds())
  {
    ::osmium::Node const &node = store->node(nodeId);
    addPoint(nodeId, node.location());
  }
}

void PointStore::addPoint(::osmium::object_id_type const pointId, ::osmium::Location const &pointLocation)
{
  mLog(common::LogLevel::Verbose) << "Adding point " << pointId << "\n";
  geometry::Point p;
  p.latitude = pointLocation.lat_without_check();
  p.longitude = pointLocation.lon_without_check();
  mPointStore[pointId] = p;
}

void PointStore::transformToMetric(geometry::CoordinateTransform const &transformer)
{
  for (auto &pointEntry : mPointStore)
  {
    geometry::Point &p = pointEntry.second;
    transformer.gcsToMetric(p.latitude, p.longitude, p.x, p.y);
  }
}

bool PointStore::hasPoint(::osmium::object_id_type const pointId) const
{
  auto const &found = mPointStore.find(pointId);
  return (found != mPointStore.end());
}

geometry::Point const &PointStore::point(::osmium::object_id_type const pointId) const
{
  try
  {
    return mPointStore.at(pointId);
  }
  catch (std::out_of_range &)
  {
    std::throw_with_nested(
      std::logic_error{std::string("Point ") + std::to_string(pointId) + std::string(" was not found in PointStore")});
  }
}

/**
 *
 * Calculation of the absolute orientation w.r.t to the x-axis of the line described by start-end.
 * The x-axis is pointing east/right
 *
 *           Y end
 *          /
 *         /
 *        /
 * start X---Z
 *
 * |XY|, |XZ| denote the lines between X and Y,Z respectively.
 * Thus the angle alpha is: tan(alpha) = ||YZ|| / ||XZ||
 *
 */
double PointStore::direction(::osmium::object_id_type const start, ::osmium::object_id_type const end) const
{
  geometry::Point const &a = point(start);
  geometry::Point const &b = point(end);

  double result = atan2((b.y - a.y), (b.x - a.x));

  if (result < 0)
  {
    result += 2. * M_PI;
  }

  return result;
}

} // namespace osm_converter
} // namespace maker
} // namespace map
} // namespace ad
