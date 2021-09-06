// ----------------- BEGIN LICENSE BLOCK ---------------------------------
//
// Copyright (C) 2018-2021 Intel Corporation
//
// SPDX-License-Identifier: MIT
//
// ----------------- END LICENSE BLOCK -----------------------------------

#pragma once

#include <map>
#include <memory>
#include <sstream>
#include <string>
#include <vector>
#include "ad/map/lane/Types.hpp"
#include "ad/map/match/Types.hpp"
#include "ad/map/point/Types.hpp"
#include "ad/map/route/RouteOperation.hpp"

/** @brief namespace ad */
namespace ad {
/** @brief namespace map */
namespace map {
/** @brief namespace intersection */
namespace intersection {

/**
 * @brief forward declaration of CoreIntersection class
 */
class CoreIntersection;

/**
 * @brief typedef for shared_ptr of CoreIntersection class
 */
typedef std::shared_ptr<CoreIntersection> CoreIntersectionPtr;

/**
 * @brief typedef for shared_ptr of const CoreIntersection class
 */
typedef std::shared_ptr<CoreIntersection const> CoreIntersectionConstPtr;

/**
 * Class to provide basic intersection information.
 *
 *  The CoreIntersection class provides:
 *  - the list of all lanes of the intersection and their extends (see CoreIntersection::internalLanes() and
 * CoreIntersection::getBoundingSphere())
 *  - the list of lanes entering the intersection (see CoreIntersection::entryLanes() and
 * CoreIntersection::entryParaPoints())
 *  - the list of lanes exiting the intersection (see CoreIntersection::exitLanes() and
 * CoreIntersection::exitParaPoints())
 *  - supporting functions to check how lanes, routes, objects are interacting with the intersection
 */
class CoreIntersection
{
public:
  /**
   * @brief check if a lane is part of any intersection
   */
  static bool isLanePartOfAnIntersection(lane::LaneId const laneId);

  /**
   * @brief check if any lane in the route is part of any intersection
   *
   * @param[in] route planned route
   *
   * @return If there is an intersection within the route, \c true is returned.
   */
  static bool isRoutePartOfAnIntersection(route::FullRoute const &route);

  /**
   * @brief check if there is an intersection for the given route
   *
   * @param[in] route planned route
   *
   * @return If there is an intersection within the route, \c true is returned.
   */
  static bool isIntersectionOnRoute(route::FullRoute const &route);

  /**
   * @brief check if the road segment enters an intersection
   *
   * @param[in] routeIterator the route iterator of the road segment
   * @param[out] routePreviousSegmentIter if an intersectin is entered,
   *   this holds the previous route segment that is part of the transition
   *
   * @returns \c true if given routeIterator enters an intersection
   */
  static bool isRoadSegmentEnteringIntersection(route::RouteIterator const &routeIterator,
                                                route::RoadSegmentList::const_iterator &routePreviousSegmentIter);

  /**
   * @returns \c true if the provided \c objectRoute contains an internal lane
   *
   * This is the case if one of the internalLanes()
   * is part of the objectRoute.
   */
  bool objectRouteCrossesIntersection(route::FullRoute const &objectRoute) const;

  /** @brief calculate and return the physics::Distance of the object to the intersection */
  physics::Distance objectDistanceToIntersection(match::Object const &object) const;

  /** @returns \c true if the object is within the intersection (touches one of the internalLanes) */
  bool objectWithinIntersection(match::MapMatchedObjectBoundingBox const &object) const;

  /** @return all lanes that are inside the intersection (independent of route) */
  lane::LaneIdSet const &internalLanes() const;

  /** @return all lanes that lead into the intersection  (not part of the intersection themselves) */
  lane::LaneIdSet const &entryLanes() const;

  /** @return the border points of all lanes that lead into the intersection as ParaPoint's */
  point::ParaPointList const &entryParaPoints() const;

  /** @return all lanes that lead out of the intersection (not part of the intersection themselves) */
  lane::LaneIdSet const &exitLanes() const;

  /** @return the border points of all lanes that lead out of the intersection as ParaPoint's */
  point::ParaPointList const &exitParaPoints() const;

  /** @return the bounding sphere of all the inner lanes of the intersection **/
  point::BoundingSphere const &getBoundingSphere() const
  {
    return mInternalLanesBoundingSphere;
  }

  /**
   * @brief retrieve the core intersection for the given laneId
   *
   * @param[in] laneId the laneId to use for creation of the CoreIntersection
   *
   * @return if the provided \a laneId is part of an intersection a CoreIntersection object is created and returned.
   */
  static CoreIntersectionPtr getCoreIntersectionFor(lane::LaneId const &laneId);

  /**
   * @brief retrieve all CoreIntersection objects for the given lane Ids
   *
   * @param[in] laneIds the set of laneIds to use for creation of the CoreIntersection
   *
   * @return if one of the provided lane Ids is part of an intersection a CoreIntersection object is created and
   * returned.
   * if multiple lane Ids are part of the same CoreIntersection only one single CoreIntersection is returned.
   * if lane Ids are part of different CoreIntersections, multiple CoreIntersections are returned.
   * In summary: the CoreIntersections of all lanedIds are returned, so that
   * every laneId of the provided \a laneIds set that belongs to an intersection is present in one of the returned
   * CoreIntersection::internalLanes() set.
   */
  static std::vector<CoreIntersectionPtr> getCoreIntersectionsFor(lane::LaneIdSet const &laneIds);

  /**
   * @brief retrieve all CoreIntersection objects for the given lane Ids
   *
   * @param[in] laneIds the vector of laneIds to use for creation of the CoreIntersection
   *
   * @return if one of the provided lane Ids is part of an intersection a CoreIntersection object is created and
   * returned.
   * if multiple lane Ids are part of the same CoreIntersection only one single CoreIntersection is returned.
   * if lane Ids are part of different CoreIntersections, multiple CoreIntersections are returned.
   * In summary: the CoreIntersections of all lanedIds are returned, so that
   * every laneId of the provided \a laneIds set that belongs to an intersection is present in one of the returned
   * CoreIntersection::internalLanes() set.
   */
  static std::vector<CoreIntersectionPtr> getCoreIntersectionsFor(lane::LaneIdList const &laneIds);

  /**
   * @brief retrieve all CoreIntersection objects of the map
   *
   * @return getCoreIntersectionsFor(lane::getLanes())
   */
  static std::vector<CoreIntersectionPtr> getCoreIntersectionsForMap();

  /**
   * @brief retrieve the core intersection for the given mapMatchedPosition
   *
   * @returns getCoreIntersectionFor(mapMatchedPosition.lanePoint.paraPoint.laneId)
   **/
  static CoreIntersectionPtr getCoreIntersectionFor(match::MapMatchedPosition const &mapMatchedPosition);

  /**
   * @brief retrieve the core intersection for the given ENU \a position
   *
   * Performs map matching of the given \a position and
   * returns getCoreIntersectionsForInLaneMatches(MapMatchedPositionConfidenceList) of the matching result.
   */
  static std::vector<CoreIntersectionPtr> getCoreIntersectionsForInLaneMatches(point::ENUPoint const &position);

  /**
   * @brief retrieve the core intersection for the given mapMatchedPositionConfidenceList
   *
   * Collects all in lane matches part of the \a mapMatchedPositionConfidenceList in a LaneIdSet and returns the vector
   *of CoreIntersection
   * returned by getCoreIntersectionsFor(laneIdSet).
   * Usually the result vector size is zero or one. In cases where multiple intersections are on top of each other and
   *the map matching
   * distance exceeded the altitude difference of the intersections, multiple CoreIntersection results are possible.
   **/
  static std::vector<CoreIntersectionPtr>
  getCoreIntersectionsForInLaneMatches(match::MapMatchedPositionConfidenceList const &mapMatchedPositionConfidenceList);

  /**
   * @brief retrieve the core intersection for the given object
   *
   * @returns Collects all in lane matches part of the \a MapMatchedObjectBoundingBox in a LaneIdSet and returns the
   *vector of CoreIntersection
   * returned by getCoreIntersectionsFor(laneIdSet).
   * Usually the result vector size is zero or one. In cases where multiple intersections are on top of each other and
   *the map matching
   * distance exceeded the altitude difference of the intersections, multiple CoreIntersection results are possible.
   **/
  static std::vector<CoreIntersectionPtr>
  getCoreIntersectionsForInLaneMatches(match::MapMatchedObjectBoundingBox const &object);

protected:
  CoreIntersection() = default;

  //! check if given lane is inside the intersection
  bool isLanePartOfCoreIntersection(lane::LaneId const laneId) const;

  void extractLanesOfCoreIntersection(lane::LaneId const laneId);

  enum SuccessorMode
  {
    OwnIntersection,
    AnyIntersection
  };

  bool isLanePartOfIntersection(lane::LaneId const laneId, SuccessorMode const successorMode) const;

  /**
   * @brief Provide the direct successor lane segments in lane direction within and outside of the intersection.
   *
   * @param laneId LaneId
   * @return a pair with <the laneID segments within the intersection, the laneID segments outside the intersection>
   */
  std::pair<lane::LaneIdSet, lane::LaneIdSet>
  getDirectSuccessorsInLaneDirection(lane::LaneId const laneId, SuccessorMode const successorMode) const;

  /**
   * @brief Provide the direct successor lane segments in lane direction within the intersection.
   *
   * @param laneId LaneId
   * @return the laneID segments within the intersection.
   */
  lane::LaneIdSet getDirectSuccessorsInLaneDirectionWithinIntersection(lane::LaneId const laneId,
                                                                       SuccessorMode const successorMode) const;

  /**
   * @brief Provide the successor lane segments in lane direction within the intersection recursively until the
   * intersection is left
   *
   * @param laneId LaneId
   * @return the laneID segments within the intersection.
   */
  lane::LaneIdSet getAllSuccessorsInLaneDirectionWithinIntersection(lane::LaneId const laneId,
                                                                    SuccessorMode const successorMode) const;

  /**
   * @brief Provide the successor lane segments in lane direction within the intersection recursively until the
   * intersection is left including the input laneId if part of the inner lanes.
   *
   * @param laneId LaneId
   * @return the laneID segments within the intersection.
   */
  lane::LaneIdSet getLaneAndAllSuccessorsInLaneDirectionWithinIntersection(lane::LaneId const laneId,
                                                                           SuccessorMode const successorMode) const;

  /**
   * @brief Provide the outgoing lane segments that are reachable in lane direction
   *
   * @param laneId LaneId
   * @return the outgoing laneID segments outside the intersection.
   */
  lane::LaneIdSet getAllReachableOutgoingLanes(lane::LaneId const laneId, SuccessorMode const successorMode) const;

  /**
   * @brief Provide the outgoing lane segments that are reachable in lane direction as well as the intersection internal
   * lanes
   *
   * @param laneId LaneId
   * @return a pair with <the laneID segments within the intersection, the laneID segments outside the intersection>
   */
  std::pair<lane::LaneIdSet, lane::LaneIdSet>
  getAllReachableInternalAndOutgoingLanes(lane::LaneId const laneId, SuccessorMode const successorMode) const;

  point::ParaPoint getEntryParaPointOfExternalLane(lane::LaneId const &laneId) const;
  point::ParaPoint getExitParaPointOfExternalLane(lane::LaneId const &laneId) const;
  point::ParaPoint getEntryParaPointOfInternalLane(lane::LaneId const &laneId) const;
  point::ParaPoint getExitParaPointOfInternalLane(lane::LaneId const &laneId) const;

  //! all lanes inside the intersection
  lane::LaneIdSet mInternalLanes{};

  //! lanes going into the intersection
  lane::LaneIdSet mEntryLanes{};

  //! lanes going into the intersection represented as ParaPoint
  point::ParaPointList mEntryParaPoints{};

  //! lanes going out of the intersection
  lane::LaneIdSet mExitLanes{};

  //! lanes going out of the intersection represented as ParaPoint
  point::ParaPointList mExitParaPoints{};

  /**
   * Managing relations between lanes through separate maps with sets. Reading:
   * key: id of lane
   * value: set of lanes that relate with this one (e.g. overlap)
   */
  std::map<lane::LaneId, lane::LaneIdSet> mOverlapping;
  std::map<lane::LaneId, lane::LaneIdSet> mSuccessor;
  std::map<lane::LaneId, lane::LaneIdSet> mPredecessor;

  point::BoundingSphere mInternalLanesBoundingSphere;

private:
  explicit CoreIntersection(lane::LaneId const &laneId);

  void checkAndInsertEntryLane(lane::LaneId const laneId);
  void checkAndInsertExitLane(lane::LaneId const laneId);
  void processContactsForLane(lane::Lane const &lane, lane::ContactLane const &contact);

  template <typename CONTAINER>
  static std::vector<CoreIntersectionPtr> getCoreIntersectionsForLaneIds(CONTAINER const &laneIds);
};

} // namespace intersection
} // namespace map
} // namespace ad

namespace std {

/**
 * \brief standard ostream operator for ad::map::intersection::CoreIntersection
 *
 * \param[in] os The output stream to write to
 * \param[in] intersection The core intersection object
 *
 * \returns The stream object.
 *
 */
std::ostream &operator<<(std::ostream &os, ::ad::map::intersection::CoreIntersection const &intersection);

/**
 * \brief overload of the std::to_string for ad::map::intersection::CoreIntersection
 */
static inline std::string to_string(::ad::map::intersection::CoreIntersection const &intersection)
{
  stringstream sstream;
  sstream << intersection;
  return sstream.str();
}
} // namespace std
