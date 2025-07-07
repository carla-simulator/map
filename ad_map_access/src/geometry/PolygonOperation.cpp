// ----------------- BEGIN LICENSE BLOCK ---------------------------------
//
// Copyright (C) 2020-2022 Intel Corporation
//
// SPDX-License-Identifier: MIT
//
// ----------------- END LICENSE BLOCK -----------------------------------

#include "ad/map/geometry/PolygonOperation.hpp"
#include "ad/map/access/Logging.hpp"
#include "ad/map/match/AdMapMatching.hpp"
#include "ad/map/match/MapMatchedOperation.hpp"

namespace ad {
namespace map {
namespace geometry {

enum OperationMode
{
  eMODE_INTERSECTION,
  eMODE_DIFFERENCE,
};

::ad::geometry::Polygon toPolygon(::ad::map::lane::ENUBorderList const &enuBorderList)
{
  ::ad::geometry::Polygon polygon;

  for (auto const &border : enuBorderList)
  {
    for (auto const &point : border.left.points)
    {
      ::boost::geometry::append(polygon, ::ad::geometry::toPoint(point.x.mENUCoordinate, point.y.mENUCoordinate));
    }
  }
  for (auto const &border : boost::adaptors::reverse(enuBorderList))
  {
    for (auto const &point : boost::adaptors::reverse(border.right.points))
    {
      ::boost::geometry::append(polygon, ::ad::geometry::toPoint(point.x.mENUCoordinate, point.y.mENUCoordinate));
    }
  }

  boost::geometry::correct(polygon);

  return polygon;
}

::ad::geometry::Polygon toPolygon(::ad::map::route::LaneInterval const &laneInterval)
{
  ::ad::geometry::Polygon polygon;

  auto const leftEdge = ::ad::map::route::getLeftENUEdge(laneInterval);
  auto const rightEdge = ::ad::map::route::getRightENUEdge(laneInterval);

  for (auto const &point : leftEdge.points)
  {
    ::boost::geometry::append(polygon, ::ad::geometry::toPoint(point.x.mENUCoordinate, point.y.mENUCoordinate));
  }
  for (auto const &point : boost::adaptors::reverse(rightEdge.points))
  {
    ::boost::geometry::append(polygon, ::ad::geometry::toPoint(point.x.mENUCoordinate, point.y.mENUCoordinate));
  }

  boost::geometry::correct(polygon);

  return polygon;
}

void addpolygonPoints(::ad::geometry::Polygon const &inputPolygon,
                      ::ad::map::geometry::PolygonIntersection &outputPolygon)
{
  ::ad::map::point::ENUPointList intersectionLinePoints;
  for (auto it = boost::begin(boost::geometry::exterior_ring(inputPolygon));
       it != boost::end(boost::geometry::exterior_ring(inputPolygon));
       ++it)

  {
    intersectionLinePoints.push_back(
      ::ad::map::point::createENUPoint(boost::geometry::get<0>(*it), boost::geometry::get<1>(*it), 0));
  }
  outputPolygon.intersection_lines.push_back(intersectionLinePoints);
}

::ad::geometry::Polygon restrictPolygonToAreaClostestToReferencePoint(::ad::geometry::Polygon const &polygon,
                                                                      ::ad::geometry::Polygon const &area,
                                                                      ad::geometry::Point const &referencePoint)
{
  ::ad::geometry::Polygon resultPolygon;
  ::ad::geometry::PolygonVector resultPolygons;
  boost::geometry::intersection(polygon, area, resultPolygons);

  if (resultPolygons.size() == 0u)
  {
    // no overlap: keep the original polygon
    resultPolygon = polygon;
  }
  else if (resultPolygons.size() == 1u)
  {
    // exactly one intersection result
    resultPolygon = resultPolygons[0];
  }
  else
  {
    // select result closest to reference point
    resultPolygon = resultPolygons[0];
    auto minDistance = boost::geometry::distance(resultPolygon, referencePoint);
    for (size_t i = 1u; i < resultPolygons.size(); ++i)
    {
      auto distance = boost::geometry::distance(resultPolygons[i], referencePoint);
      if (distance < minDistance)
      {
        minDistance = distance;
        resultPolygon = resultPolygons[i];
      }
    }
  }

  return resultPolygon;
}

match::LaneOccupiedRegionList
extractOccupiedRegions(::ad::map::geometry::PolygonIntersection const &polygonIntersection,
                       ::ad::map::lane::LaneId const &laneId)
{
  match::LaneOccupiedRegionList lane_occupied_regions;
  ::ad::map::lane::Lane currentLane;

  currentLane = lane::getLane(laneId);

  for (auto const &eachLine : polygonIntersection.intersection_lines)
  {
    match::MapMatchedPositionConfidenceList mapMatchedPositions;
    for (auto const &eachPoint : eachLine)
    {
      match::MapMatchedPosition mmpos;
      if (lane::findNearestPointOnLaneIgnoreZ(currentLane, eachPoint, mmpos))
      {
        mapMatchedPositions.push_back(mmpos);
      }
    }
    match::LaneOccupiedRegionList lane_occupied_region;
    match::AdMapMatching::addLaneRegions(lane_occupied_region, mapMatchedPositions);
    lane_occupied_regions.insert(lane_occupied_regions.end(), lane_occupied_region.begin(), lane_occupied_region.end());
  }

  return lane_occupied_regions;
}

match::LaneOccupiedRegionList
extractRegionsBasedOnMode(::ad::geometry::PolygonVector const &visiblePolygons,
                          std::vector<::ad::map::route::LaneInterval> const &lane_intervals,
                          OperationMode const &currentMode)
{
  match::LaneOccupiedRegionList occRegion, lane_regions;
  ::ad::geometry::Polygon lane_polygon;

  for (auto const &lane_interval : lane_intervals)
  {
    lane_polygon = ::ad::map::geometry::toPolygon(lane_interval);

    ::ad::geometry::PolygonVector output;
    bool process_lane_polygon = true;
    for (auto const &visiblePolygon : visiblePolygons)
    {
      if (currentMode == eMODE_INTERSECTION)
      {
        // adding all consecutive intersections to the output
        boost::geometry::intersection(lane_polygon, visiblePolygon, output);
      }
      else
      {
        if (process_lane_polygon)
        {
          // for the first time we can create the difference to the original lane polygon
          boost::geometry::difference(lane_polygon, visiblePolygon, output);
          process_lane_polygon = false;
        }
        else
        {
          // if there are multiple input polygons we have to perform the difference of the
          // previous output to reduce it further in case of overlap
          ::ad::geometry::PolygonVector last_output;
          last_output.swap(output);
          for (auto last_output_polygon : last_output)
          {
            boost::geometry::difference(last_output_polygon, visiblePolygon, output);
          }
        }
      }
    }

    ::ad::map::geometry::PolygonIntersection outputLines;
    for (auto const &eachPolygon : output)
    {
      addpolygonPoints(eachPolygon, outputLines);
    }
    lane_regions = extractOccupiedRegions(outputLines, lane_interval.lane_id);

    for (auto const &eachOccupiedRegion : lane_regions)
    {
      occRegion.push_back(eachOccupiedRegion);
    }
  }

  return occRegion;
}

match::LaneOccupiedRegionList
extractRegionsBasedOnMode(::ad::geometry::Polygon const &visiblePolygon,
                          std::vector<::ad::map::route::LaneInterval> const &lane_intervals,
                          OperationMode const &currentMode)
{
  ::ad::geometry::PolygonVector visiblePolygons{visiblePolygon};
  return extractRegionsBasedOnMode(visiblePolygons, lane_intervals, currentMode);
}

match::LaneOccupiedRegionList extractInnerRegions(::ad::geometry::Polygon const &visiblePolygon,
                                                  std::vector<::ad::map::route::LaneInterval> const &lane_intervals)
{
  match::LaneOccupiedRegionList result;
  result = extractRegionsBasedOnMode(visiblePolygon, lane_intervals, eMODE_INTERSECTION);
  return result;
}

match::LaneOccupiedRegionList extractInnerRegions(::ad::geometry::PolygonVector const &visiblePolygons,
                                                  std::vector<::ad::map::route::LaneInterval> const &lane_intervals)
{
  match::LaneOccupiedRegionList result;
  result = extractRegionsBasedOnMode(visiblePolygons, lane_intervals, eMODE_INTERSECTION);
  return result;
}

match::LaneOccupiedRegionList extractOuterRegions(::ad::geometry::Polygon const &visiblePolygon,
                                                  std::vector<::ad::map::route::LaneInterval> const &lane_intervals)
{
  match::LaneOccupiedRegionList result;
  result = extractRegionsBasedOnMode(visiblePolygon, lane_intervals, eMODE_DIFFERENCE);
  return result;
}

match::LaneOccupiedRegionList extractOuterRegions(::ad::geometry::PolygonVector const &visiblePolygons,
                                                  std::vector<::ad::map::route::LaneInterval> const &lane_intervals)
{
  match::LaneOccupiedRegionList result;
  result = extractRegionsBasedOnMode(visiblePolygons, lane_intervals, eMODE_DIFFERENCE);
  return result;
}

match::LaneOccupiedRegionList findPolygonDifference(match::LaneOccupiedRegion const &first_region,
                                                    match::LaneOccupiedRegion const &second_region,
                                                    OperationMode const &currentMode)
{
  match::LaneOccupiedRegionList lane_regions;

  ::ad::geometry::PolygonVector output;

  auto enu_border_first = ::ad::map::match::getENUBorder(first_region);
  auto enu_border_second = ::ad::map::match::getENUBorder(second_region);

  auto const lane_polygon_first = ::ad::map::geometry::toPolygon({enu_border_first});
  auto const lane_polygon_second = ::ad::map::geometry::toPolygon({enu_border_second});

  if (currentMode == eMODE_INTERSECTION)
  {
    boost::geometry::intersection(lane_polygon_first, lane_polygon_second, output);
  }
  else
  {
    boost::geometry::difference(lane_polygon_first, lane_polygon_second, output);
  }

  ::ad::map::geometry::PolygonIntersection outputLines;
  for (auto const &eachPolygon : output)
  {
    addpolygonPoints(eachPolygon, outputLines);
  }
  lane_regions = extractOccupiedRegions(outputLines, first_region.lane_id);

  return lane_regions;
}

std::vector<::ad::map::route::LaneInterval>
collectLanesWithinInfluenceDistance(::ad::map::point::ECEFPoint const &referencePoint,
                                    ::ad::physics::Distance const &influenceDistance)
{
  match::MapMatchedPositionConfidenceList mapMatchingResults
    = match::AdMapMatching::findLanes(referencePoint, influenceDistance);

  std::vector<::ad::map::route::LaneInterval> lane_intervals;
  for (auto const &eachLane : mapMatchingResults)
  {
    ::ad::map::route::LaneInterval lane_interval;
    lane_interval.lane_id = eachLane.lane_point.para_point.lane_id;
    lane_interval.start = ::ad::physics::ParametricValue(0.0);
    lane_interval.end = ::ad::physics::ParametricValue(1.0);
    lane_intervals.push_back(lane_interval);
  }
  return lane_intervals;
}

LaneRegions extractRegions(::ad::geometry::PolygonVector const &visiblePolygons,
                           ::ad::map::point::ECEFPoint const &referencePoint,
                           ::ad::physics::Distance const &influenceDistance)
{
  LaneRegions output_regions;
  output_regions.reference_position.center = referencePoint;
  output_regions.reference_position.radius = influenceDistance;
  access::getLogger()->trace("ad::map::geometry::extractRegions() start");
  auto const lane_intervals = collectLanesWithinInfluenceDistance(referencePoint, influenceDistance);
  auto const occluded_lane_regions = extractOuterRegions(visiblePolygons, lane_intervals);
  auto const visible_lane_regions = extractInnerRegions(visiblePolygons, lane_intervals);

  for (auto const &each_occluded_region : occluded_lane_regions)
  {
    for (auto const &each_visible_region : visible_lane_regions)
    {
      if (each_occluded_region.lane_id == each_visible_region.lane_id)
      {
        auto const lane_regions = findPolygonDifference(each_occluded_region, each_visible_region, eMODE_INTERSECTION);
        for (auto const &eachOccupiedRegion : lane_regions)
        {
          output_regions.partly_occluded.push_back(eachOccupiedRegion);
        }
      }
    }
  }

  // remove partially occluded from occluded regions to get fully occluded regions
  access::getLogger()->trace("ad::map::geometry::extractRegions() resulting partly_occluded_regions {}",
                             output_regions.partly_occluded);
  output_regions.fully_occluded = subtractRegionsLongitudinally(occluded_lane_regions, output_regions.partly_occluded);
  access::getLogger()->trace("ad::map::geometry::extractRegions() resulting fully_occluded_regions {}",
                             output_regions.fully_occluded);
  output_regions.fully_visible = subtractRegionsLongitudinally(visible_lane_regions, output_regions.partly_occluded);
  access::getLogger()->trace("ad::map::geometry::extractRegions() resulting fully_visible_regions {}",
                             output_regions.fully_visible);
  return output_regions;
}

LaneRegions extractRegions(::ad::geometry::Polygon const &visiblePolygon,
                           ::ad::map::point::ECEFPoint const &referencePoint,
                           ::ad::physics::Distance const &influenceDistance)
{
  ::ad::geometry::PolygonVector visiblePolygons{visiblePolygon};
  return extractRegions(visiblePolygons, referencePoint, influenceDistance);
}

match::LaneOccupiedRegionList subtractRegionsLongitudinally(match::LaneOccupiedRegionList const &minuend,
                                                            match::LaneOccupiedRegionList const &subtrahend)
{
  match::LaneOccupiedRegionList output_list;

  for (auto const &current_region : minuend)
  {
    std::list<ad::physics::ParametricRange> resulting_ranges;
    resulting_ranges.push_back(current_region.longitudinal_range);

    // access::getLogger()->trace("ad::map::geometry::subtractRegionsLon() minuend {}", current_region);
    for (auto const &subtrahend_region : subtrahend)
    {
      if (current_region.lane_id == subtrahend_region.lane_id)
      {
        // access::getLogger()->trace("ad::map::geometry::subtractRegionsLon() subtrahend {}", subtrahend_region);
        for (auto iter = resulting_ranges.begin(); iter != resulting_ranges.end();)
        {
          // access::getLogger()->trace("ad::map::geometry::subtractRegionsLon() check[{}/{}] {}",
          // resulting_ranges.size(), std::distance(resulting_ranges.begin(), iter), *iter);
          auto const subtraction_result = ::ad::physics::subtract(*iter, subtrahend_region.longitudinal_range);
          if (subtraction_result.empty())
          {
            iter = resulting_ranges.erase(iter);
            // access::getLogger()->trace("ad::map::geometry::subtractRegionsLon() results in[{}/{}] erasing",
            // resulting_ranges.size(), std::distance(resulting_ranges.begin(), iter));
          }
          else
          {
            if (subtraction_result.size() >= 1u)
            {
              *iter = subtraction_result[0];
              // access::getLogger()->trace("ad::map::geometry::subtractRegionsLon() results in[{}/{}] {}",
              // resulting_ranges.size(), std::distance(resulting_ranges.begin(), iter), *iter);
            }
            if (subtraction_result.size() > 1u)
            {
              resulting_ranges.insert(iter, subtraction_result[1]);
              // access::getLogger()->trace("ad::map::geometry::subtractRegionsLon() results in[{}/{}] {}",
              // resulting_ranges.size(), std::distance(resulting_ranges.begin(), iter), subtraction_result[1]);
            }
            iter++;
          }
        }
      }
    }

    for (auto const &range : resulting_ranges)
    {
      if (!ad::physics::isRangeEmpty(range))
      {
        match::LaneOccupiedRegion subtraction_output = current_region;
        subtraction_output.longitudinal_range = range;
        output_list.push_back(subtraction_output);
      }
    }
  }
  return output_list;
}

match::LaneOccupiedRegionList mergeFullyOccludedRegions(LaneRegions const &left, LaneRegions const &right)
{
  match::LaneOccupiedRegionList merged_fully_occluded_regions;

  auto fully_occluded_left = subtractRegionsLongitudinally(left.fully_occluded, right.fully_visible);
  fully_occluded_left = subtractRegionsLongitudinally(fully_occluded_left, right.partly_occluded);

  auto fully_occluded_right = subtractRegionsLongitudinally(right.fully_occluded, left.fully_visible);
  fully_occluded_right = subtractRegionsLongitudinally(fully_occluded_right, left.partly_occluded);

  merged_fully_occluded_regions.insert(
    merged_fully_occluded_regions.end(), fully_occluded_left.begin(), fully_occluded_left.end());
  merged_fully_occluded_regions.insert(
    merged_fully_occluded_regions.end(), fully_occluded_right.begin(), fully_occluded_right.end());

  return merged_fully_occluded_regions;
}

} // namespace geometry
} // namespace map
} // namespace ad
