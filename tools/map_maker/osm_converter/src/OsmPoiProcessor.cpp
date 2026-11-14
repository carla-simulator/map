// ----------------- BEGIN LICENSE BLOCK ---------------------------------
//
// Copyright (C) 2017-2020 Intel Corporation
//
// SPDX-License-Identifier: MIT
//
// ----------------- END LICENSE BLOCK -----------------------------------

#include "ad/map/maker/osm_converter/OsmPoiProcessor.hpp"
#include <ad/map/maker/common/LogChannel.hpp>
#include <ad/map/maker/common/LogFactory.hpp>
#include <ad/map/maker/geometry/LineCoordinateSystem.hpp>
#include <utility>
#include <vector>
#include "ad/map/maker/osm_converter/OsmObjectStore.hpp"
#include "ad/map/maker/osm_converter/OsmPoiExtractor.hpp"
#include "ad/map/maker/osm_converter/PointStore.hpp"

namespace ad {
namespace map {
namespace maker {
namespace osm_converter {

OsmPoiProcessor::OsmPoiProcessor(common::LogFactory &logFactory)
  : mLog(logFactory.logChannel("OsmPoiProcessor"))
{
  mPoiTypes.insert(PoiType::Tree);
  mPoiTypes.insert(PoiType::StreetLamp);
  mPoiTypes.insert(PoiType::Crosswalk);
  mPoiTypes.insert(PoiType::FireHydrant);
  mPoiTypes.insert(PoiType::PowerCabinet);
  mPoiTypes.insert(PoiType::Bollard);
  mPoiTypes.insert(PoiType::PostBox);
  mPoiTypes.insert(PoiType::ManHole);
  mPoiTypes.insert(PoiType::TrafficLight);
}

bool OsmPoiProcessor::hasPoisForSegment(::osmium::object_id_type first, ::osmium::object_id_type last) const
{
  auto const firstIter = mSegmentToPoiMap.find(first);
  if (firstIter == mSegmentToPoiMap.end())
  {
    return false;
  }

  return firstIter->second.find(last) != firstIter->second.end();
}

std::unordered_set<::osmium::object_id_type> OsmPoiProcessor::poisForSegment(::osmium::object_id_type first,
                                                                             ::osmium::object_id_type last) const
{
  auto const firstIter = mSegmentToPoiMap.find(first);
  if (firstIter == mSegmentToPoiMap.end())
  {
    return {};
  }
  auto const lastIter = firstIter->second.find(last);
  if (lastIter == firstIter->second.end())
  {
    return {};
  }

  return lastIter->second;
}

/*
 * Iterate over all known segments
 *   Iterate over all nodes of the segment
 *     Setup a local coordinate system for mapping all POIs to the segment
 *     Iterate over all POIs and project its coordinates to the local one
 *       Update the mapping if the projection is closer than the exisiting one
 */
void OsmPoiProcessor::processPoisForWay(std::shared_ptr<OsmObjectStore> objectStore,
                                        std::shared_ptr<PointStore> pointStore,
                                        std::unordered_set<::osmium::object_id_type> const &listOfPoi,
                                        PoiType typeOfPoi)
{
  if (listOfPoi.empty())
  {
    return;
  }

  std::vector<std::pair<::osmium::object_id_type, geometry::Point2d>> poiLocations;
  poiLocations.reserve(listOfPoi.size());
  for (::osmium::object_id_type poiId : listOfPoi)
  {
    auto const &poiPt = pointStore->point(poiId);
    poiLocations.emplace_back(poiId, geometry::Point2d{poiPt.x, poiPt.y});
  }

  for (auto wayId : objectStore->allWayIds())
  {
    ::osmium::Way const &way = objectStore->way(wayId);
    auto const &nodes = way.nodes();
    if (nodes.size() < 2u)
    {
      continue;
    }
    for (std::size_t index = 0u; index + 1u < nodes.size(); ++index)
    {
      auto const startRef = nodes[index].ref();
      auto const endRef = nodes[index + 1u].ref();
      // Create a local coordinate system for each pair of nodes of the segment
      auto const &start = pointStore->point(startRef);
      auto const &end = pointStore->point(endRef);
      geometry::LineCoordinateSystem lcs(geometry::Point2d{start.x, start.y}, geometry::Point2d{end.x, end.y});
      // ... and project all POIs to that coordinate system
      for (auto const &poiEntry : poiLocations)
      {
        geometry::Point2d const projection = lcs.projectToLineCoordinateSystem(poiEntry.second);
        if (lcs.pointIsInsideSegment(projection, 0.))
        {
          geometry::Point p;
          p.x = projection.x;
          p.y = projection.y;
          mPoiToSegmentMapping[poiEntry.first].update(startRef, endRef, p, typeOfPoi, poiEntry.first);
        }
      }
    }
  }
}

/*
 * Map POIs to the closest line segment
 * Collect all POIs across all configured types once and perform a single pass over ways/segments.
 */
void OsmPoiProcessor::processPois(std::shared_ptr<OsmPoiExtractor> poiExtractor,
                                  std::shared_ptr<OsmObjectStore> objectStore,
                                  std::shared_ptr<PointStore> pointStore)
{
  mPoiToSegmentMapping.clear();
  mSegmentToPoiMap.clear();

  struct PoiCandidate
  {
    ::osmium::object_id_type id;
    geometry::Point2d location;
    PoiType type;
  };

  std::vector<PoiCandidate> candidates;
  for (PoiType typeOfPoi : mPoiTypes)
  {
    auto const &listOfPoi = poiExtractor->getPois(typeOfPoi);
    for (::osmium::object_id_type poiId : listOfPoi)
    {
      auto const &poiPt = pointStore->point(poiId);
      candidates.push_back(PoiCandidate{poiId, geometry::Point2d{poiPt.x, poiPt.y}, typeOfPoi});
    }
  }

  if (!candidates.empty())
  {
    for (auto wayId : objectStore->allWayIds())
    {
      ::osmium::Way const &way = objectStore->way(wayId);
      auto const &nodes = way.nodes();
      if (nodes.size() < 2u)
      {
        continue;
      }
      for (std::size_t index = 0u; index + 1u < nodes.size(); ++index)
      {
        auto const startRef = nodes[index].ref();
        auto const endRef = nodes[index + 1u].ref();
        auto const &start = pointStore->point(startRef);
        auto const &end = pointStore->point(endRef);
        geometry::LineCoordinateSystem lcs(geometry::Point2d{start.x, start.y}, geometry::Point2d{end.x, end.y});
        for (auto const &candidate : candidates)
        {
          geometry::Point2d const projection = lcs.projectToLineCoordinateSystem(candidate.location);
          if (lcs.pointIsInsideSegment(projection, 0.))
          {
            geometry::Point p;
            p.x = projection.x;
            p.y = projection.y;
            mPoiToSegmentMapping[candidate.id].update(startRef, endRef, p, candidate.type, candidate.id);
          }
        }
      }
    }
  }

  for (auto const &poiId : mPoiToSegmentMapping)
  {
    const PointOfInterest &mapping = poiId.second;
    mSegmentToPoiMap[mapping.mStart][mapping.mEnd].insert(poiId.first);
    mLog(common::LogLevel::Verbose) << "Mapped POI " << poiId.first << " to segment from " << mapping.mStart << " to "
                                    << mapping.mEnd << " with offset [s, t] " << mapping.mProjection.x << ", "
                                    << mapping.mProjection.y << "\n";
  }
}

PointOfInterest const &OsmPoiProcessor::pointMappingForNodeId(::osmium::object_id_type nodeId) const
{
  return mPoiToSegmentMapping.at(nodeId);
}

} // namespace osm_converter
} // namespace maker
} // namespace map
} // namespace ad
