#!/bin/env python

# ----------------- BEGIN LICENSE BLOCK ---------------------------------
#
# Copyright (c) 2019-2021 Intel Corporation
#
# SPDX-License-Identifier: MIT
#
# ----------------- END LICENSE BLOCK -----------------------------------

"""
Simple unittest module to ensure that the Python binding is functional
"""

import unittest
import xmlrunner
import sys
import os

import ad_map_access as ad


class AdMapAccessPythonTest(unittest.TestCase):

    """
    Test class for Python interface
    """

    def test_interface(self):
        """
        Main test part
        """

        ad.map.access.setLogLevel(ad.map.access.level_enum.trace)

        self.assertTrue(ad.map.access.init("test_files/TPK.adm.txt"))

        # map loaded
        lanes = ad.map.lane.getLanes()
        self.assertEqual(len(lanes), 141)

        # map matching
        mapMatching = ad.map.match.AdMapMatching()
        geo_point = ad.map.point.GeoPoint()
        geo_point.longitude = ad.map.point.Longitude(8.43985)
        geo_point.latitude = ad.map.point.Latitude(49.0188)
        geo_point.altitude = ad.map.point.Altitude(0.)
        mapMatchingResults = mapMatching.getMapMatchedPositions(
            geo_point, ad.physics.Distance(0.01), ad.physics.Probability(0.))
        self.assertEqual(len(mapMatchingResults), 1)

        # route planning along to the end of the lane
        pointEnteringTPK = mapMatchingResults[0].lane_point.para_point
        laneEndEnteringTPK = ad.map.point.ParaPoint()
        laneEndEnteringTPK.lane_id = pointEnteringTPK.lane_id
        laneEndEnteringTPK.parametric_offset = ad.physics.ParametricValue(1.0)

        routeResult = ad.map.route.planRoute(ad.map.route.createRoutingPoint(
            pointEnteringTPK), ad.map.route.createRoutingPoint(laneEndEnteringTPK))
        self.assertEqual(1, len(routeResult.road_segments))
        segmentLength = ad.map.route.calcLength(routeResult.road_segments[0])
        self.assertLessEqual(46., segmentLength.mDistance, "first segment length")
        routeLength = ad.map.route.calcLength(routeResult)
        self.assertEqual(segmentLength, routeLength, "full route length")

        # route planning along to the end of the lane
        geoEmmyNoether09 = ad.map.point.GeoPoint()
        geoEmmyNoether09.longitude = ad.map.point.Longitude(8.4404225)
        geoEmmyNoether09.latitude = ad.map.point.Latitude(49.0199442)
        geoEmmyNoether09.altitude = ad.map.point.Altitude(0.)
        routeResult = ad.map.route.planRoute(ad.map.route.createRoutingPoint(
            pointEnteringTPK), geoEmmyNoether09)
        self.assertEqual(5, len(routeResult.road_segments))

        geoEmmyNoether09Back = ad.map.point.GeoPoint()
        geoEmmyNoether09Back.longitude = ad.map.point.Longitude(8.43950488)
        geoEmmyNoether09Back.latitude = ad.map.point.Latitude(49.01946888)
        geoEmmyNoether09Back.altitude = ad.map.point.Altitude(0.)

        geoPointList = ad.map.point.GeoPointList()
        geoPointList.append(geoEmmyNoether09)
        geoPointList.append(geoEmmyNoether09Back)
        routeResult = ad.map.route.planRoute(ad.map.route.createRoutingPoint(
            pointEnteringTPK), geoPointList)
        self.assertEqual(11, len(routeResult.road_segments))

        routeLength = ad.map.route.calcLength(routeResult)
        self.assertLessEqual(200., routeLength.mDistance, "route length")

        lane_polygon = ad.geometry.Polygon()
        ad.map.geometry.toPolygon(routeResult.road_segments[0].drivable_lane_segments[0].lane_interval, lane_polygon)
        debug_drawing = ad.geometry.DebugDrawing.getInstance()
        debug_drawing.drawPolygon(lane_polygon, "red", "test")

        ad.map.access.cleanup()


if __name__ == '__main__':
    if os.environ.get('GTEST_OUTPUT') and os.environ['GTEST_OUTPUT'].startswith('xml:'):
        base_folder = os.environ['GTEST_OUTPUT'][4:]
        unittest.main(testRunner=xmlrunner.XMLTestRunner(output=base_folder))
    else:
        unittest.main()
