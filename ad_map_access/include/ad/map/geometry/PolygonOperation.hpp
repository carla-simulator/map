// ----------------- BEGIN LICENSE BLOCK ---------------------------------
//
// Copyright (C) 2020-2022 Intel Corporation
//
// SPDX-License-Identifier: MIT
//
// ----------------- END LICENSE BLOCK -----------------------------------
/**
 * @file
 */

#pragma once

#include <ad/geometry/GeometryOperation.hpp>
#include <ad/geometry/Types.hpp>
#include <ad/physics/ParametricValue.hpp>
#include <algorithm>
#include "ad/map/access/Logging.hpp"
#include "ad/map/access/Operation.hpp"
#include "ad/map/geometry/LaneRegions.hpp"
#include "ad/map/geometry/PolygonIntersection.hpp"
#include "ad/map/landmark/LandmarkOperation.hpp"
#include "ad/map/lane/Lane.hpp"
#include "ad/map/lane/LaneOperation.hpp"
#include "ad/map/match/LaneOccupiedRegionList.hpp"
#include "ad/map/match/Types.hpp"
#include "ad/map/point/ENUPointList.hpp"
#include "ad/map/point/Operation.hpp"
#include "ad/map/point/Types.hpp"
#include "ad/map/route/RouteOperation.hpp"
#include "ad/map/route/Types.hpp"
#include "spdlog/spdlog.h"

/** @brief namespace ad */
namespace ad {
/** @brief namespace map */
namespace map {
/** @brief namespace geometry */
namespace geometry {

/**
 * @brief Retrieve edges of a LaneInterval as a boost polygon
 *
 * @param[in] laneInterval the lane interval
 * @returns polygon the polygon output
 */
::ad::geometry::Polygon toPolygon(::ad::map::route::LaneInterval const &laneInterval);

/**
 * @brief Retrieve edges of a LaneInterval as a boost polygon
 *
 * @param[in] laneInterval the lane interval
 * @param[out] polygon the polygon output
 */
inline void toPolygon(::ad::map::route::LaneInterval const &laneInterval, ::ad::geometry::Polygon &polygon)
{
  polygon = toPolygon(laneInterval);
}

/**
 * @brief Retrieve edges of a ENUBoderList as a boost polygon
 *
 * @Param[in] enuBorderList the list of ENU borders
 * @param[out] polygon the polygon output
 */
::ad::geometry::Polygon toPolygon(::ad::map::lane::ENUBorderList const &enuBorderList);

/**
 * @brief Adds the points of the input polygon to form a line
 *
 * @param[in] inputPolygon The input polygon
 * @param[out] outputPolygon The output lines as a vector of points contained in input polygon
 */
void addpolygonPoints(::ad::geometry::Polygon const &inputPolygon,
                      ::ad::map::geometry::PolygonIntersection &outputPolygon);

/**
 * @brief Inline function to add point to polygon (required for use in python)
 *
 * @param[in/out] polygon The polygon
 * @param[in] point The point to be added to the polygon
 */
inline void appendToPolygon(::ad::geometry::Polygon &polygon, ::ad::geometry::Point point)
{
  ::boost::geometry::append(polygon, point);
}

/**
 * @brief Inline function to correct polygon (required for use in python)
 *
 * @param[in/out] polygon The polygon to be corrected
 */
inline void correctPolygon(::ad::geometry::Polygon &polygon)
{
  boost::geometry::correct(polygon);
}

/**
 * @brief Function to cut portions of the input polygon outside a specified area.
 *   If there is no intersection of the polygon and the area, the original polygon is returned.
 *   If there are multiple independent intersections of the polygon and the area, the intersecting polygon closest to
 * the referencePoint is returned.
 *
 * @param[in] polygon The polygon to be restricted
 * @param[in] area The area, the polygon should be restricted to in case it is within the area
 * @param[in] referencePoint The reference point used to determine the closest result if the operation of polygon
 * intersection returns multiple independent results
 *
 * @retval In case of overlap between polygon and area: The (closest) result of the polygon intersection operation
 * @retval Otherwise: The input polygon is returned.
 */
::ad::geometry::Polygon restrictPolygonToAreaClostestToReferencePoint(::ad::geometry::Polygon const &polygon,
                                                                      ::ad::geometry::Polygon const &area,
                                                                      ad::geometry::Point const &referencePoint);

/**
 * @brief Extract the occupied region of each lane
 *
 * @param[in] polygonIntersection The input polygon
 * @param[in] laneId The relevant lane id.
 *
 * @returns The Lane occupied region list.
 */
match::LaneOccupiedRegionList
extractOccupiedRegions(::ad::map::geometry::PolygonIntersection const &polygonIntersection,
                       ::ad::map::lane::LaneId const &laneId);

/**
 * @brief Extract the lane regions which are inside the polygon
 *
 * @param[in] polygon The reference polygon
 * @param[in] lane_intervals The lane intervals to be considered
 *
 * returns The occupied region list inside the polygon.
 */
match::LaneOccupiedRegionList extractInnerRegions(::ad::geometry::Polygon const &polygon,
                                                  std::vector<::ad::map::route::LaneInterval> const &lane_intervals);

/**
 * @brief Extract the lane regions which are inside the polygons
 *
 * @param[in] polygons The reference polygons
 * @param[in] lane_intervals The lane intervals to be considered
 *
 * returns The occupied region list inside the polygons.
 */
match::LaneOccupiedRegionList extractInnerRegions(::ad::geometry::PolygonVector const &polygons,
                                                  std::vector<::ad::map::route::LaneInterval> const &lane_intervals);

/**
 * @brief Extract the lane regions which are outside the polygon
 *
 * @param[in] polygon The reference polygon
 * @param[in] lane_intervals The lane intervals to be considered
 *
 * returns The occupied region list outside the polygon.
 */
match::LaneOccupiedRegionList extractOuterRegions(::ad::geometry::Polygon const &polygon,
                                                  std::vector<::ad::map::route::LaneInterval> const &lane_intervals);

/**
 * @brief Extract the lane regions which are outside the polygons
 *
 * @param[in] polygons The reference polygons
 * @param[in] lane_intervals The lane intervals to be considered
 *
 * returns The occupied region list outside the polygons.
 */
match::LaneOccupiedRegionList extractOuterRegions(::ad::geometry::PolygonVector const &polygons,
                                                  std::vector<::ad::map::route::LaneInterval> const &lane_intervals);

/**
 * @brief Collect the lanes within a certain influence distance and provide their complete lane intervals
 *
 * @param[in] referencePoint The ego vehicle reference point
 * @param[in] influenceDistance The distance around the reference point
 *
 * returns The lane intervals [0.0; 1.0] of all lanes that are within the provided influence distance arount the
 * reference point.
 */
std::vector<::ad::map::route::LaneInterval>
collectLanesWithinInfluenceDistance(::ad::map::point::ECEFPoint const &referencePoint,
                                    ::ad::physics::Distance const &influenceDistance);

/**
 * @brief Extract the fully occluded, fully visible and partly occlluded areas as Region datatype, which are outside the
 * polygon of visibility
 *
 * @param[in] visiblePolygon The polygon defining the visible area
 * @param[in] referencePoint The ego vehicle reference point
 * @param[in] influenceDistance The distance around the reference point
 *
 * returns The regions describing fully occluded, fully visible and partly occluded regions as Region datatype.
 */
LaneRegions extractRegions(::ad::geometry::Polygon const &visiblePolygon,
                           ::ad::map::point::ECEFPoint const &referencePoint,
                           ::ad::physics::Distance const &influenceDistance);

/**
 * @brief Extract the fully occluded, fully visible and partly occlluded areas as Region datatype, which are outside the
 * polygons of visibility
 *
 * @param[in] visiblePolygons The polygons defining the visible area
 * @param[in] referencePoint The ego vehicle reference point
 * @param[in] influenceDistance The distance around the reference point
 *
 * returns The regions describing fully occluded, fully visible and partly occluded regions as Region datatype.
 */
LaneRegions extractRegions(::ad::geometry::PolygonVector const &visiblePolygons,
                           ::ad::map::point::ECEFPoint const &referencePoint,
                           ::ad::physics::Distance const &influenceDistance);

/**
 * @brief Subtract the subtrahend regions from the minuend regions while considering the longitudinal_range
 *
 * All longitudinal lane regions present in subtrahend are substracted from the longitudinal_range lane regions of the
 * same lane in the minuend regions list applying ad::physics::subtract(ad::physics::ParametricRange,
 * ad::physics::ParametricRange). The lateral_range of the subtrahend are ignored. The lateral_range of the resulting
 * regions are identical with the ones from the original within minuend.
 *
 * Be ware: the subtraction operation can lead to a split of a minuend region into multiple parts.
 */
match::LaneOccupiedRegionList subtractRegionsLongitudinally(match::LaneOccupiedRegionList const &minuend,
                                                            match::LaneOccupiedRegionList const &subtrahend);

/**
 * @brief Merge the fully occluded regions of both lane regions
 *
 * Removes fully/partly visible regions present of one from the fully occluded regions of the other and
 * return new merged fully occluded regions as LaneOccupiedRegionList.
 *
 * @param[in] left One lane region
 * @param[in] right Other lane region
 *
 * returns The merged fully occluded regions
 */
match::LaneOccupiedRegionList mergeFullyOccludedRegions(LaneRegions const &left, LaneRegions const &right);

} // namespace geometry
} // namespace map
} // namespace ad
