#!/bin/env python

# ----------------- BEGIN LICENSE BLOCK ---------------------------------
#
# Copyright (c) 2019-2020 Intel Corporation
#
# SPDX-License-Identifier: MIT
#
# ----------------- END LICENSE BLOCK -----------------------------------

"""
Simple unittest module to ensure that the Python binding is functional
"""

import unittest

import libad_physics_python as physics
import libad_map_access_python as admap


class InterfaceTest(unittest.TestCase):

    """
    Test class for Python interface
    """

    def test_interface(self):
        """
        Main test part
        """
        self.assertTrue(admap.init("test_files/TPK.adm.txt"))

        # map loaded
        lanes = admap.getLanes()
        self.assertEqual(len(lanes), 141)

        # map matching
        mapMatching = admap.AdMapMatching()
        geoPoint = admap.GeoPoint()
        geoPoint.longitude = admap.Longitude(8.4401803)
        geoPoint.latitude = admap.Latitude(49.0191987)
        geoPoint.altitude = admap.Altitude(0.)

        mapMatchingResults = mapMatching.getMapMatchedPositions(
            geoPoint, physics.Distance(0.01), physics.Probability(0.05))
        self.assertEqual(len(mapMatchingResults), 1)

        # route planning
        routingStart = mapMatchingResults[0].lanePoint.paraPoint
        routingEnd = admap.ParaPoint()
        routingEnd.laneId = routingStart.laneId
        routingEnd.parametricOffset = physics.ParametricValue(0.0)

        routeResult = admap.planRoute(admap.createRoutingPoint(routingStart), admap.createRoutingPoint(routingEnd))
        routeLength = admap.calcLength(routeResult.roadSegments[0])
        self.assertEqual(int(float(routeLength)), 4)

        admap.cleanup()

if __name__ == '__main__':
    unittest.main()
