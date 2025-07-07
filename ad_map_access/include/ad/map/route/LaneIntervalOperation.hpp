// ----------------- BEGIN LICENSE BLOCK ---------------------------------
//
// Copyright (C) 2018-2021 Intel Corporation
//
// SPDX-License-Identifier: MIT
//
// ----------------- END LICENSE BLOCK -----------------------------------
/**
 * @file
 */

#pragma once

#include "ad/map/access/Types.hpp"
#include "ad/map/lane/BorderOperation.hpp"
#include "ad/map/lane/Types.hpp"
#include "ad/map/route/Types.hpp"

/** @brief namespace ad */
namespace ad {
/** @brief namespace map */
namespace map {
/** @brief namespace route */
namespace route {

/**
 * @brief class defining a route interval with one lane
 *
 * The route interval consists of the id of the lane, the start and end point of lane on the route as TParam.
 * TParam describes a parametric point along the lane geometry. By defining the start and end of the route interval,
 * also a direction of the route is defined ... at least if @c start and @c end points differ from each other.
 *
 * If start == end, the route interval is degenerated and therefore no meaningful route direction can be derived.
 * Only if start != end, checks like isAfterInterval(), isBeforeInterval(),
 * isRouteDirectionPositive(), isRouteDirectionNegative() provide the expected information.
 */

/**
 * @brief get interval start as ParaPoint
 */
inline point::ParaPoint getIntervalStart(LaneInterval const &lane_interval)
{
  point::ParaPoint result;
  result.lane_id = lane_interval.lane_id;
  result.parametric_offset = lane_interval.start;
  return result;
}

/**
 * @brief get interval start as ParaPoint for a given lane_id and a given route
 *
 * throws if lane_id not found in route
 */
point::ParaPoint getIntervalStart(FullRoute const &route, lane::LaneId const &lane_id);

/**
 * @brief get interval end as ParaPoint
 */
inline point::ParaPoint getIntervalEnd(LaneInterval const &lane_interval)
{
  point::ParaPoint result;
  result.lane_id = lane_interval.lane_id;
  result.parametric_offset = lane_interval.end;
  return result;
}

/**
 * @brief convert lane interval to ParametricRange
 */
inline physics::ParametricRange toParametricRange(route::LaneInterval const &lane_interval)
{
  physics::ParametricRange range;
  if (lane_interval.start <= lane_interval.end)
  {
    range.minimum = lane_interval.start;
    range.maximum = lane_interval.end;
  }
  else
  {
    range.minimum = lane_interval.end;
    range.maximum = lane_interval.start;
  }
  return range;
}

/**
 * @brief get the signed parametric physics::Distance between two parametric points respecting the lane_interval's
 * direction
 *
 * @retval > 0, if the \c first point is before the \c second point within the interval
 * @retval < 0, if the \c second point is before the \c first point within the interval
 * @retval = 0, if both are equal
 *
 * @throws std::invalid_argument if the parametric points are not referring to the landId
 */
physics::ParametricValue
getSignedDistance(LaneInterval const &lane_interval, point::ParaPoint const &first, point::ParaPoint const &second);

/**
 * @brief get the unsigned parametric physics::Distance between two parametric points
 *
 * @retval | \c first.parametric_offset - \c second.parametric_offset |
 * @throws std::invalid_argument if the parametric points are not referring to the landId
 */
physics::ParametricValue
getUnsignedDistance(LaneInterval const &lane_interval, point::ParaPoint const &first, point::ParaPoint const &second);

/**
 * @brief checks if the point marks the start of the interval
 *
 * @param[in] point parametric point to be checked against the route interval start
 *
 * @returns @c true if LaneId and TParam at start of this matches the given @c point
 */
inline bool isStartOfInterval(LaneInterval const &lane_interval, point::ParaPoint const &point)
{
  return (point.lane_id == lane_interval.lane_id) && (point.parametric_offset == lane_interval.start);
}

/**
 * @brief checks if the point marks the end of the interval
 *
 * @param[in] point parametric point to be checked against the route interval end
 *
 * @returns @c true if LaneId and TParam at end of this matches the given @c point
 */
inline bool isEndOfInterval(LaneInterval const &lane_interval, point::ParaPoint const &point)
{
  return (point.lane_id == lane_interval.lane_id) && (point.parametric_offset == lane_interval.end);
}

/**
 * @brief checks if the direction of this route interval is positive in respect to the lane geometry
 *
 * @returns @c true if the parametric points follow: start < end
 * @returns @c lane::isLaneDirectionPositive(lane_interval.lane_id) ^ wrong_way if start == end  (degenerated interval
 * uses
 * wrong way flag to determine
 *  the route direction)
 */
bool isRouteDirectionPositive(LaneInterval const &lane_interval);

/**
 * @brief checks if the direction of this route interval is negative in respect to the lane geometry
 *
 * @returns !isRouteDirectionPositive()
 */
inline bool isRouteDirectionNegative(LaneInterval const &lane_interval)
{
  return !isRouteDirectionPositive(lane_interval);
}

/**
 * @brief checks if the route direction is aligned with the nominal driving direction of the lane
 */
bool isRouteDirectionAlignedWithDrivingDirection(LaneInterval const &lane_interval);

/**
 * @brief checks if the parametric offset is within the interval
 *
 * @param[in] parametric_offset parametric offset to be checked against the route interval
 *
 * @returns @c true if parametric offset  is within the interval
 */
inline bool isWithinInterval(LaneInterval const &lane_interval, physics::ParametricValue const &parametric_offset)
{
  if (isRouteDirectionPositive(lane_interval))
  {
    return (lane_interval.start <= parametric_offset) && (parametric_offset <= lane_interval.end);
  }
  else
  {
    return (lane_interval.end <= parametric_offset) && (parametric_offset <= lane_interval.start);
  }
}

/**
 * @brief checks if the point is within the interval
 *
 * @param[in] point parametric point to be checked against the route interval
 *
 * @returns @c true if LaneId matches and TParam of the given @c point is within the interval
 */
inline bool isWithinInterval(LaneInterval const &lane_interval, point::ParaPoint const &point)
{
  return (point.lane_id == lane_interval.lane_id) && isWithinInterval(lane_interval, point.parametric_offset);
}

/**
 * @brief checks if the interval is degenerated
 *
 * The interval is degenerated if start and end of the interval are equal.
 * In such a case no meaningful information on route direction is possible.
 *
 * @returns @c true if the interval is degenerated: start == end
 */
inline bool isDegenerated(LaneInterval const &lane_interval)
{
  return (lane_interval.start == lane_interval.end);
}

/**
 * @brief checks if the  parametric offset is after the interval
 *
 * @param[in] parametric_offset parametric offset to be checked against the route interval
 *
 * @returns @c true if given parametric offset is after the interval
 * Be aware: if the route interval is degenerated isAfterInterval() and isBeforeInterval() return the same value
 */
inline bool isAfterInterval(LaneInterval const &lane_interval, physics::ParametricValue const parametric_offset)
{
  if (isRouteDirectionPositive(lane_interval))
  {
    return (parametric_offset > lane_interval.end);
  }
  else
  {
    return (parametric_offset < lane_interval.end);
  }
}

/**
 * @brief checks if the point is after the interval
 *
 * @param[in] point parametric point to be checked against the route interval
 *
 * @returns @c true if LaneId matches and TParam of the given @c point is after the interval
 * Be aware: if the route interval is degenerated isAfterInterval() and isBeforeInterval() return the same value
 * ( point != end )
 */
inline bool isAfterInterval(LaneInterval const &lane_interval, point::ParaPoint const &point)
{
  if (point.lane_id == lane_interval.lane_id)
  {
    return isAfterInterval(lane_interval, point.parametric_offset);
  }
  return false;
}

/**
 * @brief checks if the parametric offset is before the interval
 *
 * @param[in] parametric_offset parametric offset to be checked against the route interval
 *
 * @returns @c true if parametric offset is before the interval
 * Be aware: if the route interval is degenerated isAfterInterval() and isBeforeInterval() return the same value
 */
inline bool isBeforeInterval(LaneInterval const &lane_interval, physics::ParametricValue const parametric_offset)
{
  if (isRouteDirectionPositive(lane_interval))
  {
    return (parametric_offset < lane_interval.start);
  }
  else
  {
    return (parametric_offset > lane_interval.start);
  }
}

/**
 * @brief checks if the point is before the interval
 *
 * @param[in] point parametric point to be checked against the route interval
 *
 * @returns @c true if LaneId matches and TParam of the given @c point is before the interval
 * Be aware: if the route interval is degenerated isAfterInterval() and isBeforeInterval() return the same value
 * ( point != start )
 */
inline bool isBeforeInterval(LaneInterval const &lane_interval, point::ParaPoint const &point)
{
  if (point.lane_id == lane_interval.lane_id)
  {
    return isBeforeInterval(lane_interval, point.parametric_offset);
  }
  return false;
}

/**
 * @brief checks if the range overlaps with the interval
 *
 * @param[in] range parametric range to be checked against the route interval
 *
 * @returns @c true if range overlaps with the interval
 */
inline bool overlapsInterval(LaneInterval const &lane_interval, physics::ParametricRange const &range)
{
  bool rangeIsOutside
    = (isBeforeInterval(lane_interval, range.minimum) && isBeforeInterval(lane_interval, range.maximum))
    || (isAfterInterval(lane_interval, range.minimum) && isAfterInterval(lane_interval, range.maximum));
  return !rangeIsOutside;
}

/**
 * @brief checks if the two lane intervals overlap with each other
 *
 * @param[in] other LaneInterval to be checked against this lane interval
 *
 * @returns @c true if intervals overlap
 */
inline bool overlapsInterval(LaneInterval const &lane_interval, LaneInterval const &other)
{
  bool otherIsOutside = (lane_interval.lane_id != other.lane_id)
    || (isBeforeInterval(lane_interval, other.start) && isBeforeInterval(lane_interval, other.end))
    || (isAfterInterval(lane_interval, other.start) && isAfterInterval(lane_interval, other.end));
  return !otherIsOutside;
}

/**
 * @brief project a given parametric position (offset) to the center line of the given
 *        neighbor lane
 *
 * @param[in] currentInterval is the current lane
 * @param[in] neighborInterval is the neighbor lane
 * @param[in] parametric_offset is the current position that should be projected to the neighbor lane
 *
 * Note: If the given neighborInterval is not a neighbor of the currentInterval the function will throw
 *
 * @return Projected position as parametric offset
 */
physics::ParametricValue getProjectedParametricOffsetOnNeighborLane(LaneInterval const &currentInterval,
                                                                    LaneInterval const &neighborInterval,
                                                                    physics::ParametricValue const &parametric_offset);

/**
 * @brief calculate the length of the provided lane interval as parametric value
 */
physics::ParametricValue calcParametricLength(LaneInterval const &lane_interval);

/** @brief calculate the length of the provided lane interval as physics::Distance value
 *
 * For length calculation the parametric length of the interval (calcParametricLength())
 * is multiplied by the lane's length.
 */
physics::Distance calcLength(LaneInterval const &lane_interval);

/** @brief calculate the Duration of the provided lane interval as duration value
 *
 * For Duration calculations maximum allowed speed combined with the length is taken into account
 */
physics::Duration calcDuration(LaneInterval const &lane_interval);

/**
 * @brief get right edge of the lane interval as ENUEdge
 *
 * Be aware: Right is in the sense of the lane interval orientation.
 *    If the lane interval has negative direction the physical left edge of the underlying lane is returned.
 *    Furthermore, the points are ordered in the logical lane interval direction:
 *    the first point is at lane interval start and the last one at lane interval end.
 */
void getRightEdge(LaneInterval const &lane_interval, lane::ENUEdge &enuEdge);

/**
 * @brief get right edge of the lane interval as ECEFEdge
 *
 * Be aware: Right is in the sense of the lane interval orientation.
 *    If the lane interval has negative direction the physical left edge of the underlying lane is returned.
 *    Furthermore, the points are ordered in the logical lane interval direction:
 *    the first point is at lane interval start and the last one at lane interval end.
 */
void getRightEdge(LaneInterval const &lane_interval, lane::ECEFEdge &ecefEdge);

/**
 * @brief get right edge of the lane interval as GeoEdge
 *
 * Be aware: Right is in the sense of the lane interval orientation.
 *    If the lane interval has negative direction the physical left edge of the underlying lane is returned.
 *    Furthermore, the points are ordered in the logical lane interval direction:
 *    the first point is at lane interval start and the last one at lane interval end.
 */
void getRightEdge(LaneInterval const &lane_interval, lane::GeoEdge &geoEdge);

/**
 * @brief get right edge of the lane interval as ENUEdge
 *
 * Be aware: Right is in the sense of the lane interval orientation.
 *    If the lane interval has negative direction the physical left edge of the underlying lane is returned.
 *    Furthermore, the points are ordered in the logical lane interval direction:
 *    the first point is at lane interval start and the last one at lane interval end.
 */
lane::ENUEdge getRightENUEdge(LaneInterval const &lane_interval);

/**
 * @brief get right edge of the lane interval as ECEFEdge
 *
 * Be aware: Right is in the sense of the lane interval orientation.
 *    If the lane interval has negative direction the physical left edge of the underlying lane is returned.
 *    Furthermore, the points are ordered in the logical lane interval direction:
 *    the first point is at lane interval start and the last one at lane interval end.
 */
lane::ECEFEdge getRightECEFEdge(LaneInterval const &lane_interval);

/**
 * @brief get right edge of the lane interval as GeoEdge
 *
 * Be aware: Right is in the sense of the lane interval orientation.
 *    If the lane interval has negative direction the physical left edge of the underlying lane is returned.
 *    Furthermore, the points are ordered in the logical lane interval direction:
 *    the first point is at lane interval start and the last one at lane interval end.
 */
lane::GeoEdge getRightGeoEdge(LaneInterval const &lane_interval);

/**
 * @brief get right edge of the lane interval as ENUEdge using projection to find the start of the edge
 *
 * Be aware: Right is in the sense of the lane interval orientation.
 *    If the lane interval has negative direction the physical left edge of the underlying lane is returned.
 *    Furthermore, the points are ordered in the logical lane interval direction:
 *    the first point is at lane interval start and the last one at lane interval end.
 */
void getRightProjectedEdge(LaneInterval const &lane_interval, lane::ENUEdge &enuEdge);

/**
 * @brief get right edge of the lane interval as ECEFEdge using projection to find the start of the edge
 *
 * Be aware: Right is in the sense of the lane interval orientation.
 *    If the lane interval has negative direction the physical left edge of the underlying lane is returned.
 *    Furthermore, the points are ordered in the logical lane interval direction:
 *    the first point is at lane interval start and the last one at lane interval end.
 */
void getRightProjectedEdge(LaneInterval const &lane_interval, lane::ECEFEdge &ecefEdge);

/**
 * @brief get right edge of the lane interval as GeoEdge using projection to find the start of the edge
 *
 * Be aware: Right is in the sense of the lane interval orientation.
 *    If the lane interval has negative direction the physical left edge of the underlying lane is returned.
 *    Furthermore, the points are ordered in the logical lane interval direction:
 *    the first point is at lane interval start and the last one at lane interval end.
 */
void getRightProjectedEdge(LaneInterval const &lane_interval, lane::GeoEdge &geoEdge);

/**
 * @brief get right edge of the lane interval as ENUEdge using projection to find the start of the edge
 *
 * Be aware: Right is in the sense of the lane interval orientation.
 *    If the lane interval has negative direction the physical left edge of the underlying lane is returned.
 *    Furthermore, the points are ordered in the logical lane interval direction:
 *    the first point is at lane interval start and the last one at lane interval end.
 */
lane::ENUEdge getRightProjectedENUEdge(LaneInterval const &lane_interval);

/**
 * @brief get right edge of the lane interval as ECEFEdge using projection to find the start of the edge
 *
 * Be aware: Right is in the sense of the lane interval orientation.
 *    If the lane interval has negative direction the physical left edge of the underlying lane is returned.
 *    Furthermore, the points are ordered in the logical lane interval direction:
 *    the first point is at lane interval start and the last one at lane interval end.
 */
lane::ECEFEdge getRightProjectedECEFEdge(LaneInterval const &lane_interval);

/**
 * @brief get right edge of the lane interval as GeoEdge using projection to find the start of the edge
 *
 * Be aware: Right is in the sense of the lane interval orientation.
 *    If the lane interval has negative direction the physical left edge of the underlying lane is returned.
 *    Furthermore, the points are ordered in the logical lane interval direction:
 *    the first point is at lane interval start and the last one at lane interval end.
 */
lane::GeoEdge getRightProjectedGeoEdge(LaneInterval const &lane_interval);

/**
 * @brief get Left edge of the lane interval as ENUEdge
 *
 * Be aware: Left is in the sense of the lane interval orientation.
 *    If the lane interval has negative direction the physical right edge of the underlying lane is returned.
 *    Furthermore, the points are ordered in the logical lane interval direction:
 *    the first point is at lane interval start and the last one at lane interval end.
 */
void getLeftEdge(LaneInterval const &lane_interval, lane::ENUEdge &enuEdge);

/**
 * @brief get Left edge of the lane interval as ECEFEdge
 *
 * Be aware: Left is in the sense of the lane interval orientation.
 *    If the lane interval has negative direction the physical right edge of the underlying lane is returned.
 *    Furthermore, the points are ordered in the logical lane interval direction:
 *    the first point is at lane interval start and the last one at lane interval end.
 */
void getLeftEdge(LaneInterval const &lane_interval, lane::ECEFEdge &ecefEdge);

/**
 * @brief get Left edge of the lane interval as GeoEdge
 *
 * Be aware: Left is in the sense of the lane interval orientation.
 *    If the lane interval has negative direction the physical right edge of the underlying lane is returned.
 *    Furthermore, the points are ordered in the logical lane interval direction:
 *    the first point is at lane interval start and the last one at lane interval end.
 */
void getLeftEdge(LaneInterval const &lane_interval, lane::GeoEdge &geoEdge);

/**
 * @brief get left edge of the lane interval as ENUEdge
 *
 * Be aware: Left is in the sense of the lane interval orientation.
 *    If the lane interval has negative direction the physical right edge of the underlying lane is returned.
 *    Furthermore, the points are ordered in the logical lane interval direction:
 *    the first point is at lane interval start and the last one at lane interval end.
 */
lane::ENUEdge getLeftENUEdge(LaneInterval const &lane_interval);

/**
 * @brief get left edge of the lane interval as ECEFEdge
 *
 * Be aware: Left is in the sense of the lane interval orientation.
 *    If the lane interval has negative direction the physical right edge of the underlying lane is returned.
 *    Furthermore, the points are ordered in the logical lane interval direction:
 *    the first point is at lane interval start and the last one at lane interval end.
 */
lane::ECEFEdge getLeftECEFEdge(LaneInterval const &lane_interval);

/**
 * @brief get left edge of the lane interval as GeoEdge
 *
 * Be aware: Left is in the sense of the lane interval orientation.
 *    If the lane interval has negative direction the physical right edge of the underlying lane is returned.
 *    Furthermore, the points are ordered in the logical lane interval direction:
 *    the first point is at lane interval start and the last one at lane interval end.
 */
lane::GeoEdge getLeftGeoEdge(LaneInterval const &lane_interval);

/**
 * @brief get Left edge of the lane interval as ENUEdge using projection to find the start of the edge
 *
 * Be aware: Left is in the sense of the lane interval orientation.
 *    If the lane interval has negative direction the physical right edge of the underlying lane is returned.
 *    Furthermore, the points are ordered in the logical lane interval direction:
 *    the first point is at lane interval start and the last one at lane interval end.
 */
void getLeftProjectedEdge(LaneInterval const &lane_interval, lane::ENUEdge &enuEdge);

/**
 * @brief get Left edge of the lane interval as ECEFEdge using projection to find the start of the edge
 *
 * Be aware: Left is in the sense of the lane interval orientation.
 *    If the lane interval has negative direction the physical right edge of the underlying lane is returned.
 *    Furthermore, the points are ordered in the logical lane interval direction:
 *    the first point is at lane interval start and the last one at lane interval end.
 */
void getLeftProjectedEdge(LaneInterval const &lane_interval, lane::ECEFEdge &ecefEdge);

/**
 * @brief get Left edge of the lane interval as GeoEdge using projection to find the start of the edge
 *
 * Be aware: Left is in the sense of the lane interval orientation.
 *    If the lane interval has negative direction the physical right edge of the underlying lane is returned.
 *    Furthermore, the points are ordered in the logical lane interval direction:
 *    the first point is at lane interval start and the last one at lane interval end.
 */
void getLeftProjectedEdge(LaneInterval const &lane_interval, lane::GeoEdge &geoEdge);

/**
 * @brief get left edge of the lane interval as ENUEdge using projection to find the start of the edge
 *
 * Be aware: Left is in the sense of the lane interval orientation.
 *    If the lane interval has negative direction the physical right edge of the underlying lane is returned.
 *    Furthermore, the points are ordered in the logical lane interval direction:
 *    the first point is at lane interval start and the last one at lane interval end.
 */
lane::ENUEdge getLeftProjectedENUEdge(LaneInterval const &lane_interval);

/**
 * @brief get left edge of the lane interval as ECEFEdge using projection to find the start of the edge
 *
 * Be aware: Left is in the sense of the lane interval orientation.
 *    If the lane interval has negative direction the physical right edge of the underlying lane is returned.
 *    Furthermore, the points are ordered in the logical lane interval direction:
 *    the first point is at lane interval start and the last one at lane interval end.
 */
lane::ECEFEdge getLeftProjectedECEFEdge(LaneInterval const &lane_interval);

/**
 * @brief get left edge of the lane interval as GeoEdge using projection to find the start of the edge
 *
 * Be aware: Left is in the sense of the lane interval orientation.
 *    If the lane interval has negative direction the physical right edge of the underlying lane is returned.
 *    Furthermore, the points are ordered in the logical lane interval direction:
 *    the first point is at lane interval start and the last one at lane interval end.
 */
lane::GeoEdge getLeftProjectedGeoEdge(LaneInterval const &lane_interval);

/**
 * @brief get the geo borders of this lane
 */
lane::GeoBorder getGeoBorder(LaneInterval const &lane_interval);

/**
 * @brief get the ecef borders of this lane
 */
lane::ECEFBorder getECEFBorder(LaneInterval const &lane_interval);

/**
 * @brief get the enu borders of this lane
 *
 * Note: The border (left/right edge) will start with the parametric offset
 * given by the lane_interval.
 */
lane::ENUBorder getENUBorder(LaneInterval const &lane_interval);

/**
 * @brief get the enu borders of this lane
 *
 * Note: The border (left/right edge) does not necessarily start/end with the
 * parametric offset given by the lane_interval. Instead this offset is used
 * for the center line and the resulting point is orthogonally projected on
 * the edges to obtain the border
 */
lane::ENUBorder getENUProjectedBorder(LaneInterval const &lane_interval);

/**
 * @brief shorten the LaneInterval about a given physics::Distance.
 * Will remove at the begin of the LaneInterval
 *
 * @param[in] the LaneInterval that should be shortened
 * @param[in] physics::Distance the LaneInterval should be shortened
 *
 * @returns resulting shortened LaneInterval
 *
 * If physics::Distance is bigger then the length of the interval. Resulting length will be zero. LaneInterval.start =
 * LaneInterval.end
 */
LaneInterval shortenIntervalFromBegin(LaneInterval const &lane_interval, physics::Distance const &distance);

/**
 * @brief shorten the LaneInterval about a given physics::Distance.
 * Will remove at the end of the LaneInterval
 *
 * @param[in] lane_interval the LaneInterval that should be shortened
 * @param[in] physics::Distance the LaneInterval should be shortened
 *
 * @returns resulting shortened LaneInterval
 *
 * If physics::Distance is bigger then the length of the interval. Resulting length will be zero. LaneInterval.end =
 * LaneInterval.start
 */
LaneInterval shortenIntervalFromEnd(LaneInterval const &lane_interval, physics::Distance const &distance);

/**
 * @brief Restrict length of the LaneInterval to a given physics::Distance from start.
 *
 * @param[in] lane_interval the LaneInterval that should be restricted
 * @param[in] physics::Distance the LaneInterval should be restricted to
 *
 * @returns resulting shortened LaneInterval
 *
 * If physics::Distance is bigger then the length of the interval. Resulting LaneInterval is the input Interval.
 */
LaneInterval restrictIntervalFromBegin(LaneInterval const &lane_interval, physics::Distance const &distance);

/**
 * @brief extend the lane interval until the end of the lane reached
 *
 * The end is set to the lane's maximal value (depending on the route direction to 0. or 1.).
 * If the lane interval is degenerated nothing is done.
 *
 * @param[in] lane_interval the LaneInterval that should be extended
 *
 * @returns resulting extended LaneInterval
 */
LaneInterval extendIntervalUntilEnd(LaneInterval const &lane_interval);

/**
 * @brief cut the LaneInterval at a given parametric point.
 * Will remove at the start of the LaneInterval
 *
 * @param[in] the LaneInterval that should be shortened
 * @param[in] newIntervalStart the new start of the interval if the point is within the LaneInterval
 *
 * @returns resulting shortened LaneInterval
 *
 * If the parametric offset is outside of the interval, the original lane interval is returned.
 */
LaneInterval cutIntervalAtStart(LaneInterval const &lane_interval, physics::ParametricValue const &newIntervalStart);

/**
 * @brief extend the lane interval until the start of the lane reached
 *
 * The start is set to the lane's minimal value (depending on the route direction to 1. or 0.).
 * If the lane interval is degenerated nothing is done.
 *
 * @param[in] lane_interval the LaneInterval that should be extended
 *
 * @returns resulting extended LaneInterval
 */
LaneInterval extendIntervalUntilStart(LaneInterval const &lane_interval);

/**
 * @brief extend the lane interval by moving its start position by physics::Distance
 *
 * If the lane interval is degenerated nothing is done.
 *
 * @param[in] lane_interval the LaneInterval that should be extended
 * @param[in] physics::Distance by which the LaneInterval should be extended
 *
 * @returns resulting extended LaneInterval
 */
LaneInterval extendIntervalFromStart(LaneInterval const &lane_interval, physics::Distance const &distance);

/**
 * @brief extend the lane interval by moving its end position by physics::Distance
 *
 * If the lane interval is degenerated nothing is done.
 *
 * @param[in] lane_interval the LaneInterval that should be extended
 * @param[in] physics::Distance by which the LaneInterval should be extended
 *
 * @returns resulting extended LaneInterval
 */
LaneInterval extendIntervalFromEnd(LaneInterval const &lane_interval, physics::Distance const &distance);

/**
 * @brief cut the LaneInterval at a given parametric point.
 * Will remove at the end of the LaneInterval
 *
 * @param[in] the LaneInterval that should be shortened
 * @param[in] newIntervalEnd the new end of the interval if the point is within the LaneInterval
 *
 * @returns resulting shortened LaneInterval
 *
 * If the parametric offset is outside of the interval, the original lane interval is returned.
 */
LaneInterval cutIntervalAtEnd(LaneInterval const &lane_interval, physics::ParametricValue const &newIntervalEnd);

/**
 * @brief get the speed limits of the lane interval
 */
restriction::SpeedLimitList getSpeedLimits(LaneInterval const &lane_interval);

/**
 * @brief get the metric ranges of the lane interval
 */
void getMetricRanges(LaneInterval const &lane_interval,
                     physics::MetricRange &length_range,
                     physics::MetricRange &width_range);

} // namespace route
} // namespace map
} // namespace ad
