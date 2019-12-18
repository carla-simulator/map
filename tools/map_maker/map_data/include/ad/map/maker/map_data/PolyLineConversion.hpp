// ----------------- BEGIN LICENSE BLOCK ---------------------------------
//
// Copyright (C) 2018-2019 Intel Corporation
//
// SPDX-License-Identifier: MIT
//
// ----------------- END LICENSE BLOCK -----------------------------------

#pragma once

#include <ad/map/maker/geometry/Polyline2d.hpp>
#include "ad/map/maker/map_data/MapDataStore.hpp"
#include "ad/map/maker/map_data/PolyLine.hpp"

namespace ad {
namespace map {
namespace maker {
namespace map_data {

/**
 * @brief Converts a map_data::PolyLine to a geometry::Polyline2d
 *
 * The conversion is done by retrieving all the PolyLine points from the store.
 */
geometry::Polyline2d polylineToGeometry(MapDataStore const &store, PolyLine const &polyline);

/**
 * @brief Converts a geometry::Polyline2d to a map_data::PolyLine
 *
 * The conversion adds all the Polyline2d points to the store.
 */
PolyLine geometryToPolyline(MapDataStore &store, geometry::Polyline2d const &polyline2d);

/**
 * @brief Converts a geometry::Polyline2d to a map_data::PolyLine
 *
 * The conversion adds all the Polyline2d points to the store.
 * All points from \ref indexOfFirstPoint until size()-indexOfLastPoint are converted
 */
PolyLine geometryToPolyline(MapDataStore &store,
                            geometry::Polyline2d const &polyline2d,
                            std::size_t indexOfFirstPoint,
                            std::size_t indexOfLastPoint);

} // namespace map_data
} // namespace maker
} // namespace map
} // namespace ad
