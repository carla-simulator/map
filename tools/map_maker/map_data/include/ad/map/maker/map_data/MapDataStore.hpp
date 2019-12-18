// ----------------- BEGIN LICENSE BLOCK ---------------------------------
//
// Copyright (C) 2018-2019 Intel Corporation
//
// SPDX-License-Identifier: MIT
//
// ----------------- END LICENSE BLOCK -----------------------------------

#pragma once

#include <ad/map/maker/geometry/CoordinateTransform.hpp>
#include <ad/map/maker/geometry/Point2d.hpp>
#include <cmath>
#include <map>
#include <unordered_map>
#include <vector>
#include "ad/map/maker/map_data/Intersection.hpp"
#include "ad/map/maker/map_data/Landmark.hpp"
#include "ad/map/maker/map_data/Lane.hpp"
#include "ad/map/maker/map_data/PolyLine.hpp"
#include "ad/map/maker/map_data/Road.hpp"

namespace ad {
namespace map {
namespace maker {

namespace common {
class LogFactory;
struct LogChannel;
} // namespace common

namespace map_data {

/**
 * @brief holds all information extrapolated from any source (road5, osm)
 *
 * Holds a list of all points a.k.a. nodes and segments
 *
 * OPEN: How to deal with all the different types of data we want to store?
 * Basic requirement: we want something like std::vector<MapDataId> getListOf<Type>Ids();
 * Basic requirement: adding points needs special handling as these will be massivly reused.
 *
 * Option 1: Be explicit, create a map together with add/get for each type
 * Option 2: Create a base class MapDataEntity and only stores these. This would require
 *   either dynamic_casts on all internal objects (if dynamic_cast<Type>(object)
 *   or to store each type in a separate list, this could also utilize the templated function from below
 * Option 3: Use some fancy templating together with decl_type of C++11, e.g.
 *   typedef std::map<MapDataId, typename Type> <Type>Map;
 *   std::map<Type, TypeMap> mObjectMaps;
 *
 *   template std::vector<MapDataId> getListOfMapDataIdsFor<Type>();
 *   whenever adding an yet unknown type is added, a new entry in mObjectsMaps would be created (is this possible?)
 *   without knowing the type upfront?
 *
 * For now we will go with Option 1 just to proceed
 *
 */
class MapDataStore
{
public:
  MapDataStore(common::LogFactory &logFactory);

  /**
   * @brief Return id for given point
   *
   * If the point does not exist in the internal data, a new entry with
   * a new id is created. Otherwise the already existing id is returned.
   *
   * @return id for given point
   */
  MapDataId getOrCreateIdForPoint(geometry::Point2d const &point);
  geometry::Point2d const &point(MapDataId const id) const;
  std::vector<MapDataId> listOfPointIds() const;
  bool hasPoint(MapDataId const id) const;

  MapDataId createPolyLine();
  MapDataId addPolyLine(PolyLine const &element);
  PolyLine const &polyLine(MapDataId const id) const;
  PolyLine &polyLine(MapDataId const id);
  std::vector<MapDataId> listOfPolyLineIds() const;
  bool hasPolyLine(MapDataId const id) const;

  MapDataId addLane(Lane const &element);
  Lane const &lane(MapDataId const id) const;
  Lane &lane(MapDataId const id);
  std::vector<MapDataId> listOfLaneIds() const;
  bool hasLane(MapDataId const id) const;
  void deleteLane(MapDataId const id);

  MapDataId createRoad(common::LogChannel &logChannel);
  MapDataId addRoad(Road const &element);
  Road const &road(MapDataId const id) const;
  Road &road(MapDataId const id);
  std::vector<MapDataId> listOfRoadIds() const;
  bool hasRoad(MapDataId const id) const;
  void deleteRoad(MapDataId const id);

  MapDataId addIntersection(Intersection const &element);
  Intersection const &intersection(MapDataId const id) const;
  Intersection &intersection(MapDataId const id);
  std::vector<MapDataId> listOfIntersectionIds() const;
  bool hasIntersection(MapDataId const id) const;
  void deleteIntersection(MapDataId const id);

  MapDataId addLandmark(Landmark const &element);
  Landmark const &landmark(MapDataId const id) const;
  Landmark &landmark(MapDataId const id);
  std::vector<MapDataId> listOfLandmarkIds() const;

  /**
   * @brief Transform all points in the MapDataStore to GCS coordinates
   *
   * This method uses a CoordinateTransform to transform all the metric coordinates
   * to its representation in GCS coordinates. The metric information is not kept
   * but replaced for its GCS equivalent.
   *
   */
  void transformToGCS(geometry::CoordinateTransform const &transformer);

  //! return the next free id, does it need to be public
  MapDataId getNextId();

  //! activate left-hand traffic regulation
  void setLeftHandTraffic();

  //! returns true if left-hand traffic, false otherwise
  bool isLeftHandTraffic() const;

  //! activate prio_to_right_and_straight traffic regulation instead of prio_to_right
  void setPrioToRightAndStraight();

  //! returns true if prio_to_right_and_straight traffic regulation is used, false otherwise
  bool isPrioToRightAndStraight() const;

private:
  common::LogChannel &mLog;
  MapDataId mNextId{1};

  /* It is intended to have hash and compare private inside this class as we only use it
   * for the one specialized unordered_map of points
   */
  struct PointHash
  {
    std::size_t operator()(geometry::Point2d const &t) const
    {
      double const xRounded = std::round(t.x * 10000);
      double const yRounded = std::round(t.y * 10000);

      // this is from http://en.cppreference.com/w/cpp/utility/hash
      std::size_t xHash = std::hash<double>{}(xRounded);
      std::size_t yHash = std::hash<double>{}(yRounded);
      return xHash ^ (yHash << 1);
    }
  };

  /* It is intended to have hash and compare private inside this class as we only use it
   * for the one specialized unordered_map of points
   */
  struct PointCompareWithEpsilon
  {
    bool operator()(geometry::Point2d const &me, geometry::Point2d const &other) const
    {
      return (me.squaredDistance(other) < epsilon);
    }

    static constexpr double epsilon{1e-9};
  };

  std::unordered_map<geometry::Point2d, MapDataId, PointHash, PointCompareWithEpsilon> mPointToId;
  std::map<MapDataId, geometry::Point2d> mPointIds;
  std::map<MapDataId, PolyLine> mPolyLines;
  std::map<MapDataId, Lane> mLanes;
  std::map<MapDataId, Road> mRoads;
  std::map<MapDataId, Intersection> mIntersections;
  std::map<MapDataId, Landmark> mLandmarks;

  //! left-hand/right-hand traffic regulation
  bool mUseLeftHandTraffic{false};

  //! prio_to_right_and_straight traffic regulation
  bool mUsePrioToRightAndStraight{false};
};

} // namespace map_data
} // namespace maker
} // namespace map
} // namespace ad
