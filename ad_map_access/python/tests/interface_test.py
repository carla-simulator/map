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
import xmlrunner
import sys
import os

if sys.version_info.major == 3:
    import libad_physics_python3 as physics
    import libad_map_access_python3 as admap
else:
    import libad_physics_python2 as physics
    import libad_map_access_python2 as admap


class AdMapAccessPythonTest(unittest.TestCase):

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
    if os.environ.get('GTEST_OUTPUT') and os.environ['GTEST_OUTPUT'].startswith('xml:'):
        base_folder = os.environ['GTEST_OUTPUT'][4:]
        result_filename = base_folder + 'ad_map_access_interface_test_python' + str(sys.version_info.major) + ".xml"
        with open(result_filename, "w+") as result_file:
            unittest.main(testRunner=xmlrunner.XMLTestRunner(output=result_file))
    else:
        unittest.main()
