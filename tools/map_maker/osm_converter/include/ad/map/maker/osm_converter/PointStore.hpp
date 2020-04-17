// ----------------- BEGIN LICENSE BLOCK ---------------------------------
//
// Copyright (C) 2017-2020 Intel Corporation
//
// SPDX-License-Identifier: MIT
//
// ----------------- END LICENSE BLOCK -----------------------------------

#pragma once

#include <memory>
#include <unordered_map>

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wconversion"
#include <osmium/osm/types.hpp>
#pragma GCC diagnostic pop

#include <ad/map/maker/geometry/Point.hpp>

namespace osmium {
class Location;
} // namespace osmium

namespace ad {
namespace map {
namespace maker {
namespace common {
class LogFactory;
struct LogChannel;
} // namespace common

namespace geometry {
class CoordinateTransform;
} // namespace geometry

namespace osm_converter {
struct OsmObjectStore;

/**
 * @brief Provide list of all available points
 *
 * Provide coordinate transformation
 * Provide geometric operations on points
 *
 * Use logging only for verbose information
 */
class PointStore
{
public:
  PointStore(common::LogFactory &logFactory);

  /**
   * @brief retrieve all nodes from OsmObjectStore and add to internal data
   */
  void extractPointsFromStore(std::shared_ptr<OsmObjectStore> store);
  /**
   * @brief Add given point to internal list of points
   * @param pointId the osm id for referencing the point/location
   * @param pointLocation location of the point to be added
   */
  void addPoint(::osmium::object_id_type const pointId, ::osmium::Location const &pointLocation);

  /**
   * @brief Apply coordinate transformation for all points from GCS to metric coordinate system
   * @param transformer Coordinate transformatin to be used
   *
   * While transforming, it will dump all data to @ref mLog
   */
  void transformToMetric(geometry::CoordinateTransform const &transformer);

  bool hasPoint(::osmium::object_id_type const pointId) const;
  geometry::Point const &point(::osmium::object_id_type const pointId) const;

  /**
   * @brief Calculate and return the direction of the line start-end
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
   * Thus the angle alpha is: alpha = asin( ||YZ|| / ||YX|| ), alpha is in range [0..2*PI)
   *
   * @return direction (in radians)
   */
  double direction(::osmium::object_id_type const start, ::osmium::object_id_type const end) const;

private:
  std::unordered_map<::osmium::object_id_type, geometry::Point> mPointStore;

  common::LogChannel &mLog;
};

} // namespace osm_converter
} // namespace maker
} // namespace map
} // namespace ad
