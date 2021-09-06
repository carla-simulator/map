# ----------------- BEGIN LICENSE BLOCK ---------------------------------
#
# Copyright (C) 2018-2021 Intel Corporation
#
# SPDX-License-Identifier: MIT
#
# ----------------- END LICENSE BLOCK -----------------------------------
"..."
import Globs
import ad_map_access as ad


def GetLaneParamPoint(lane_id, pt1, pt2):
    lane = ad.map.lane.getLane(lane_id)
    tlon = ad.physics.ParametricValue(pt1)
    tlat = ad.physics.ParametricValue(pt2)
    ecef = ad.map.lane.getParametricPoint(lane, tlon, tlat)
    pt0 = ad.map.point.toGeo(ecef)
    return pt0


def GetLaneEdge(lane_id, tf):
    lane_t = ad.map.lane.getLane(lane_id)
    geom = lane_t.edgeLeft if tf else lane_t.edgeRight
    geos = ad.map.point.GeoEdge()
    mCoordinateTransform = ad.map.point.CoordinateTransform()
    mCoordinateTransform.convert(geom.ecefEdge, geos)
    return geos


def GetLaneSubEdge(lane_id, tstart, tend, tf):
    start = ad.physics.ParametricValue(tstart)
    end = ad.physics.ParametricValue(tend)
    lane = ad.map.lane.getLane(lane_id)
    trange = ad.physics.ParametricRange()
    trange.minimum = start
    trange.maximum = end
    ecefs = ad.map.point.ECEFEdge()
    geom = lane.edgeLeft if tf else lane.edgeRight
    ad.map.point.getParametricRange(geom, trange, ecefs)
    geos = ad.map.point.toGeo(ecefs)
    return geos


def GetGeoDistance(point1, point2):
    d = ad.map.point.distance(point1, point2)
    return d


def GetLaneEdgeLeft(lane_id):
    return GetLaneEdge(lane_id, True)


def GetLaneEdgeRight(lane_id):
    return GetLaneEdge(lane_id, False)


def GetLaneSubEdgeLeft(lane_id, tstart, tend):
    return GetLaneSubEdge(lane_id, tstart, tend, True)


def GetLaneSubEdgeRight(lane_id, tstart, tend):
    return GetLaneSubEdge(lane_id, tstart, tend, False)


def Predictions(pt, createMode, length, duration):
    if createMode == "Same Driving Direction":
        entryMode = ad.map.route.RouteCreationMode.SameDrivingDirection
    elif createMode == "All Routable Lanes":
        entryMode = ad.map.route.RouteCreationMode.AllRoutableLanes
    elif createMode == "All Routable Lanes":
        entryMode = ad.map.route.RouteCreationMode.AllNeighborLanes
    else:
        entryMode = ad.map.route.RouteCreationMode.Undefined

    default_radius = ad.physics.Distance(2.)
    mmpts_start = ad.map.match.AdMapMatching.findLanes(pt, default_radius)

    default_prediction_length = ad.physics.Distance(length)
    default_prediction_duration = ad.physics.Duration(duration)

    para_start = ad.map.route.createRoutingPoint(mmpts_start[0].lanePoint.paraPoint)
    routeResult = ad.map.route.predictRoutes(
        para_start, default_prediction_length, default_prediction_duration, entryMode)
    return routeResult


def Route(start_pt, end_pt, createMode):
    if createMode == "Same Driving Direction":
        entryMode = ad.map.route.RouteCreationMode.SameDrivingDirection
    elif createMode == "All Routable Lanes":
        entryMode = ad.map.route.RouteCreationMode.AllRoutableLanes
    elif createMode == "All Routable Lanes":
        entryMode = ad.map.route.RouteCreationMode.AllNeighborLanes
    else:
        entryMode = ad.map.route.RouteCreationMode.Undefined

    default_radius = ad.physics.Distance(2.)
    mmpts_start = ad.map.match.AdMapMatching.findLanes(start_pt, default_radius)
    mmpts_dest = ad.map.match.AdMapMatching.findLanes(end_pt, default_radius)
    para_start = ad.map.route.createRoutingPoint(mmpts_start[0].lanePoint.paraPoint)
    para_dest = ad.map.route.createRoutingPoint(mmpts_dest[0].lanePoint.paraPoint)
    routeResult = ad.map.route.planRoute(para_start, para_dest, entryMode)

    return routeResult
