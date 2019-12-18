// ----------------- BEGIN LICENSE BLOCK ---------------------------------
//
// Copyright (C) 2018-2019 Intel Corporation
//
// SPDX-License-Identifier: MIT
//
// ----------------- END LICENSE BLOCK -----------------------------------

#include "ad/map/maker/map_data/PolyLineConversion.hpp"

namespace ad {
namespace map {
namespace maker {
namespace map_data {

geometry::Polyline2d polylineToGeometry(MapDataStore const &store, PolyLine const &polyline)
{
  geometry::Polyline2d polyline2d;
  for (auto pointId : polyline.mNodes)
  {
    polyline2d.points.push_back(store.point(pointId));
  }
  return polyline2d;
}

PolyLine geometryToPolyline(MapDataStore &store, geometry::Polyline2d const &polyline2d)
{
  return geometryToPolyline(store, polyline2d, 0, 0);
}

PolyLine geometryToPolyline(MapDataStore &store,
                            geometry::Polyline2d const &polyline2d,
                            std::size_t indexOfFirstPoint,
                            std::size_t indexOfLastPoint)
{
  PolyLine polyline;
  polyline.mNodes.clear();
  for (std::size_t i = indexOfFirstPoint; i < polyline2d.points.size() - indexOfLastPoint; ++i)
  {
    polyline.mNodes.push_back(store.getOrCreateIdForPoint(polyline2d.points[i]));
  }
  return polyline;
}

} // namespace map_data
} // namespace maker
} // namespace map
} // namespace ad
