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
  if (mSegmentToPoiMap.count(first) == 0)
  {
    return false;
  }

  if (mSegmentToPoiMap.at(first).count(last) == 0)
  {
    return false;
  }

  return true;
}

std::unordered_set<::osmium::object_id_type> OsmPoiProcessor::poisForSegment(::osmium::object_id_type first,
                                                                             ::osmium::object_id_type last) const
{
  std::unordered_set<::osmium::object_id_type> result;
  if (!hasPoisForSegment(first, last))
  {
    return result;
  }

  return mSegmentToPoiMap.at(first).at(last);
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
  for (auto wayId : objectStore->allWayIds())
  {
    ::osmium::Way const &way = objectStore->way(wayId);
    auto const &nodes = way.nodes();
    for (uint32_t index = 0u; index < nodes.size() - 1; ++index)
    {
      // Create a local coordinate system for each pair of nodes of the segment
      auto start = pointStore->point(nodes[index].ref());
      auto end = pointStore->point(nodes[index + 1].ref());
      geometry::LineCoordinateSystem lcs(geometry::Point2d{start.x, start.y}, geometry::Point2d{end.x, end.y});
      // ... and project all POIs to that coordinate system
      for (::osmium::object_id_type poiId : listOfPoi)
      {
        auto poiLoc = geometry::Point2d{pointStore->point(poiId).x, pointStore->point(poiId).y};
        geometry::Point2d projection = lcs.projectToLineCoordinateSystem(poiLoc);
        if (lcs.pointIsInsideSegment(projection, 0.))
        {
          geometry::Point p;
          p.x = projection.x;
          p.y = projection.y;
          mPoiToSegmentMapping[poiId].update(nodes[index].ref(), nodes[index + 1].ref(), p, typeOfPoi, poiId);
        }
      }
    }
  }
}

/*
 * Map POIs to the closest line segment
 * Iterate over all types of POIs
 *  - if there are any POIs of given type, iterator over all ways
 *
 * Maybe we should change this for use in map_data, since there we will only transfer all related information
 */
void OsmPoiProcessor::processPois(std::shared_ptr<OsmPoiExtractor> poiExtractor,
                                  std::shared_ptr<OsmObjectStore> objectStore,
                                  std::shared_ptr<PointStore> pointStore)
{
  for (PoiType typeOfPoi : mPoiTypes)
  {
    auto listOfPoi = poiExtractor->getPois(typeOfPoi);
    if (listOfPoi.size() > 0)
    {
      processPoisForWay(objectStore, pointStore, listOfPoi, typeOfPoi);
    }
  }

  for (auto poiId : mPoiToSegmentMapping)
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
