// ----------------- BEGIN LICENSE BLOCK ---------------------------------
//
// Copyright (C) 2018-2019 Intel Corporation
//
// SPDX-License-Identifier: MIT
//
// ----------------- END LICENSE BLOCK -----------------------------------

#pragma once

#include <ad/map/maker/common/RightOfWay.hpp>
#include <set>
#include <vector>
#include "ad/map/maker/map_data/IntersectionArm.hpp"
#include "ad/map/maker/map_data/IntersectionConnector.hpp"
#include "ad/map/maker/map_data/MapDataElement.hpp"
#include "ad/map/maker/map_data/RoadType.hpp"

namespace ad {
namespace map {
namespace maker {

namespace common {
struct LogChannel;
class LogFactory;
} // namespace common

namespace geometry {
struct Point2d;
struct Polyline2d;
struct Line2d;
} // namespace geometry

namespace map_data {
class MapDataStore;
struct Road;
struct PolyLine;

enum class IntersectionType
{
  Unknown,
  Service,          //!< Intersection with one or more service roads
  Regular,          //!< normal intersection
  Complex,          //!< cluster of several intersections
  CrosswalkZebra,   //!< crosswalk with zebra (for pedestrians)
  CrosswalkPelican, //!< crosswalk with traffic light (for pedestrians)
  Ramp              //!< motorway exit, entry with a ramp
};

/**
 * @brief representation of intersection
 *
 * Represents all required information that makes up an intersection.
 * Furthermore has functionality to transform basic information (incoming and outgoing
 * roads into a fully flavored intersection with all internal roads together with
 * adapted incoming, outgoing roads.
 *
 * Basic procedure to set up an intersetion is:
 * - define type of intersection
 * - set the id of the center point
 * - add all roads the lead into/out of the intersection using addIncomingRoad, addOutgoingRoad
 * For further processing, call transformToSkeleton to interpolate the internal geometry in terms
 * of internal roads leading from one arm to another
 */
struct Intersection : MapDataElement
{
  /**
   * @brief transform the initial data into full featured data, i.e. internal roads are set up
   *
   * Derive connection points for all connected roads, create internal roads that lead
   * from one arm to another (if applicable)
   *
   * During transformation, also the connected roads will be adjusted such that they are shortened
   * and the connection point will be the first/last point of the underlying PolyLine.
   *
   * As a consequence, objects within the MapDataStore must be changeable
   *
   * @param interpolationStepSize size of one step [m] when interpolating with bezier curves
   * @param fullInterpolation not only create the skeleton line but also all lanes inside the intersection
   */
  void generateInnerData(double interpolationStepSize, bool fullInterpolation);

  /**
   * @brief Calculate the connection points and adjustment distances.
   */
  void generateArmData(double interpolationStepSize, bool fullInterpolation);

  /**
   * @brief Adjust the intersection's arms and generate the internal connection roads.
   */
  void generateInternalRoadsAndGeometry(double interpolationStepSize, bool fullInterpolation);

  MapDataId mCenterPointId{InvalidId};
  std::vector<IntersectionArm> mArms;
  IntersectionType mIntersectionType{IntersectionType::Unknown};
  std::vector<MapDataId> mRoads; //!< list of internal roads

  Intersection() = delete;
  Intersection &operator=(Intersection const &other) = delete;

  Intersection(MapDataStore &dataStore, common::LogFactory &logFactory);

  bool addIncomingRoad(MapDataId const roadId, common::RightOfWay const regulation);
  bool addOutgoingRoad(MapDataId const roadId, common::RightOfWay const regulation);
  void orderArmsByDirection();

  /**
   * @brief Returns true if the road(roadId) leads to the intersection
   */
  bool isRoadEntry(MapDataId roadId) const;

  /**
   * @brief Returns true if the road(roadId) starts from the intersection
   */
  bool isRoadExit(MapDataId roadId) const;

  /**
   * @brief succPointIdForForwardLane
   *
   * Return id of the point that succeeds given border of given lane inside the intersection.
   * Example:
   *
   * A ---> x_0..x_n ---> B
   *
   * The intersection has an internal road x connecting A with B (through skeleton points x_0..x_n)
   * Road A connects to the intersection at point x_0
   * Road B connects to the intersection at point x_n
   *
   * The internal road has lanes |Bn|..|B0||F0|..|Fn| (Bn backward lanes, Fn forward lanes)
   *  (A)                      (Intersection)         (B)
   *        ------------  (4)                  (8) ------------
   *        < backward <        lane B0            < backward <
   * center ------------> (1) x_0 -------> x_n (5) ------------
   *        > forward >         lane F0            > forward >
   *        ------------  (2)                  (6) ------------
   *        > forward >         lane F1            > forward >
   *        ------------  (3)                  (7) ------------
   *
   * @param connectionPointId
   * @param forLeftBorder left with respect to the direction of the road
   * @param indexOfLane
   *
   * For Road A:
   * succPointIdForForwardLane(x_0, true, 0) --> 1
   * succPointIdForForwardLane(x_0, false, 0) --> 2
   * succPointIdForForwardLane(x_0, true, 1) --> 2
   * succPointIdForForwardLane(x_0, false, 1) --> 3
   * prevPointIdForBackwardLane(x_0, true, 0) --> 4
   * prevPointIdForBackwardLane(x_0, false, 0) --> 1
   *
   * For Road B:
   * prevPointIdForForwardLane(x_n, true, 0) --> 5
   * prevPointIdForForwardLane(x_n, false, 0) --> 6
   * prevPointIdForForwardLane(x_n, true, 1) --> 6
   * prevPointIdForForwardLane(x_n, false, 1) --> 7
   * succPointIdForBackwardLane(x_n, true, 0) --> 8
   * succPointIdForBackwardLane(x_n, false, 0) --> 5
   *
   * In case the internal road has opposite direction (going from x_n to x_0) the returned values are still the same.
   *
   * @return InvalidId in case of non-existing point, e.g. index out of range or connectionPointId not part of
   *         intersection
   */
  MapDataId succPointIdForForwardLane(MapDataId connectionPointId, bool forLeftBorder, uint32_t indexOfLane) const;
  MapDataId prevPointIdForForwardLane(MapDataId connectionPointId, bool forLeftBorder, uint32_t indexOfLane) const;
  MapDataId succPointIdForBackwardLane(MapDataId connectionPointId, bool forLeftBorder, uint32_t indexOfLane) const;
  MapDataId prevPointIdForBackwardLane(MapDataId connectionPointId, bool forLeftBorder, uint32_t indexOfLane) const;

  /**
   * @brief return all internal roads that connect to given connection point
   */
  std::set<MapDataId> roadsAtConnectionPoint(MapDataId const connectionPoint) const;

  /**
   * @brief return all internal roads that connect to given road
   */
  std::set<MapDataId> roadsConnectedTo(MapDataId const connectedRoadId) const;

  /**
   * @brief return the internal road connected to the connectedRoadId,
   *
   * There could be multiple roads connected, this function returns the first result found.
   */
  MapDataId roadConnectedTo(MapDataId const connectedRoadId) const;

  /**
   * @brief return the list of internal roads (if any) that connect the roads roadAId and roadBId,
   *
   * @return a list of road ids. There could be zero or multiple roads connected.
   */
  std::vector<MapDataId> findConnectingRoad(MapDataId const roadAId, MapDataId const roadBId) const;

  /**
   * @brief return index of arm for given connection points
   *
   * @return -1 if point is not connected to intersection
   */
  int32_t indexOfArmForConnectionPoint(MapDataId const connectionPoint) const;

  /**
   * @brief return the index of the arm that is connected with the specified road, -1 otherwise.
   *
   * Due to the fact that a road could be connected as entry and exit, it is necessary to specify if the road is entry
   * or not.
   */
  int32_t indexOfArmForConnectedRoad(MapDataId const connectedRoadId, bool isEntry) const;

  bool isCrosswalk() const;

  void generateCenter();

private:
  MapDataStore &mStore;
  common::LogChannel &mLog;
  common::LogChannel &mRoadLog;

  struct InternalRoad
  {
    MapDataId startPointId{InvalidId}; //! id of connection point where internal road starts
    MapDataId endPointId{InvalidId};   //! id of connection point where internal road ends
    uint64_t startIndex;               //! index of arm where internal road starts
    uint64_t endIndex;                 //! index of arm where internal road ends
    uint32_t inCenterLaneId{0u};
    uint32_t outCenterLaneId{0u};
    MapDataId roadId{InvalidId}; //! id of internal road going from startPointId to endPointId
  };
  std::vector<InternalRoad> mInternalRoads;

  bool addRoad(MapDataId const roadId, common::RightOfWay const regulation, bool isEntry);

  //! iterate over all possible connections (between all arms) and setup the internal connections
  void generateInternalRoads();
  void adjustRoads();
  void calculateConnectionPoints();
  //! iterate over all generated (internal) roads and generate polylines
  void generateInternalGeometry();

  /**
   * @brief Calculate the centroid of the intersection's arms.
   *
   * @returns the centroid of the arm connection points.
   */
  geometry::Point2d calculateIntersectionCentroid() const;

  /**
   * @brief Calculate the intersection point of the arm's polylines.
   *
   * @returns intersecting point of the arm's lines using a LSQ approach.
   */
  geometry::Point2d calculateLSQIntersectionPoint() const;

  /**
   * @brief Checks the consistency of an arm's data
   */
  bool isValidArm(const IntersectionArm &arm);

  /*
   * Either create a new road and add the widths of the lanes accordingly (forward lanes)
   * Or re-use an already existing road and add backward lanes
   */
  void setupOrUpdateInternalRoad(uint64_t startIndex, uint64_t endIndex, uint64_t numLanes);
  //! return id of road that goes from startId to endId
  MapDataId getInternalRoadId(MapDataId const startId, MapDataId const endId) const;
  //! return id of road that either starts or end with pointId
  MapDataId getInternalRoadId(MapDataId const pointId) const;
  MapDataId pointForInternalRoad(uint64_t index, double offset) const;

  /**
   * @brief remove points from connected road at arm
   */
  void adjustArm(IntersectionArm &arm, double distance) const;

  void interpolateInternalRoad(InternalRoad const &internalRoad) const;

  /**
   * @brief Returns the margin distance for a given road type.
   */
  double marginForTypeOfRoad(RoadType const &roadType) const;

  /** @brief _Safety_ margin (in [m]). Used to generated suitable cubic spines of the
   *  internal roads.
   *
   * Illustration on one arm:
   *
   * A--------M--D----X
   *
   * A: arm leading into intersection
   * X: center of intersection
   * M: connection point of arm
   *
   * |MD|: safety margin
   * |DX|: min dist to center (calculated internally)
   *
   * The angle between |AM|, |MD| is _always_ 180 degree. This is required to generate valid lanes (using shifted
   * polylines)
   * The margin is selected based on the arm's road type.
   * OPEN: should this be configurable?
   */
  double intersectionMargin();

  double mBezierInterpolationSteps{10.}; //!< number of samples in the interval (0,1] for bezier interpolation
  bool mFullInterpolation{true};

  /**
   * @brief Adds a Intersection connection to the current list of internal roads.
   *
   * First looks up if there is a road already connecting the arms, in such case it adds the connection
   * as a new lane without creating additional roads.
   *
   */
  void addInternalRoadConnection(const IntersectionConnection &connection);

  geometry::Polyline2d generateBasicPolylineForInterpolation(InternalRoad const &internalRoad,
                                                             double shiftStart = 0.0,
                                                             double shiftEnd = 0.0) const;
  PolyLine generateBezierInterpolation(geometry::Polyline2d const &source) const;
  double calculateAdjustingDistance(const IntersectionArm &thisArm, const IntersectionArm &otherArm) const;
  double calculateMaxDistanceToCenter() const;
};

} // namespace map_data
} // namespace maker
} // namespace map
} // namespace ad
