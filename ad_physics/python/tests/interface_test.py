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
import time

import ad_physics as ad


class AdPhysicsPythonTest(unittest.TestCase):

    """
    Test class for Python interface
    """

    def test_interface(self):
        """
        Main test part
        """
        speed_1 = ad.physics.Speed(10.)
        speed_2 = ad.physics.Speed(20.)
        speed_3 = speed_1 + speed_2

        self.assertEqual(speed_3, 30.)

        duration_1 = ad.physics.Duration(2.)
        accleration_1 = ad.physics.Acceleration(10.)
        self.assertEqual(accleration_1.mAcceleration, 10.)

        speed_4 = duration_1 * accleration_1
        self.assertEqual(speed_4, 20.)

        speed_5 = accleration_1 * duration_1
        self.assertEqual(speed_4, speed_5)

        duration_2 = speed_4 / accleration_1
        self.assertEqual(duration_2, duration_1)

        speed_squared_1 = speed_1 * speed_2
        self.assertEqual(speed_squared_1, 200.)

        accleration_2 = ad.physics.Acceleration(8.)
        distance_1 = speed_squared_1 / accleration_2
        self.assertEqual(distance_1, 25.)

    def test_time_point(self):
        time_point = ad.physics.time_point()
        time_point.set_time(time.time())
        print(time_point)

    def test_geometry(self):
        """
        Geometry namespace
        """
        heading_range = ad.geometry.HeadingRange()
        heading_range.begin = ad.physics.Angle(0)
        heading_range.end = ad.physics.cPI

        overlap_ranges = ad.geometry.HeadingRangeVector()
        result_range = ad.geometry.HeadingRange()
        result_range.begin = ad.physics.Angle(0)
        result_range.end = ad.physics.Angle(0)
        overlap_ranges.append(result_range)

        result_range.begin = ad.physics.Angle(1. / 4. * ad.physics.cPI)
        result_range.end = ad.physics.Angle(1. / 2. * ad.physics.cPI)
        overlap_ranges.append(result_range)

        self.assertTrue(ad.geometry.getHeadingOverlap(heading_range, overlap_ranges))
        self.assertEqual(2, len(overlap_ranges))
        self.assertEqual(ad.physics.Angle(0.0), overlap_ranges[0].begin)
        self.assertEqual(ad.physics.Angle(0.0), overlap_ranges[0].end)
        self.assertEqual(1. / 4. * ad.physics.cPI, overlap_ranges[1].begin)
        self.assertEqual(1. / 2. * ad.physics.cPI, overlap_ranges[1].end)

        point = ad.geometry.Point()
        distance_2d = ad.physics.Distance2D()
        distance_2d.x = ad.physics.Distance(1.)
        distance_2d.y = ad.physics.Distance(2.)
        point = ad.geometry.toPoint(distance_2d)
        distance_2d_res = ad.geometry.toDistance(point)
        self.assertEqual(distance_2d.x.mDistance, distance_2d_res.x.mDistance)
        self.assertEqual(distance_2d.y.mDistance, distance_2d_res.y.mDistance)

        # ensure Polygon made it into the output
        polygon = ad.geometry.Polygon()
        point_vector = ad.geometry.PointVector()
        point_vector.append(point)
        distance_list_in = ad.physics.Distance2DList()
        distance_list_in.append(distance_2d)
        distance_2d.x = ad.physics.Distance(3.)
        distance_2d.y = ad.physics.Distance(4.)
        point = ad.geometry.toPoint(distance_2d)
        point_vector.append(point)
        distance_list_in.append(distance_2d)
        distance_2d.x = ad.physics.Distance(5.)
        distance_2d.y = ad.physics.Distance(6.)
        point = ad.geometry.toPoint(distance_2d)
        point_vector.append(point)
        distance_list_in.append(distance_2d)
        self.assertEqual(3, len(point_vector))
        ad.geometry.toPolygon(point_vector, polygon)
        distance_list_out = ad.physics.Distance2DList()
        ad.geometry.toTrajectorySet(polygon, distance_list_out)
        # polygon correction duplicates first point
        point_vector.append(point_vector[0])
        distance_list_in.append(distance_list_in[0])
        print("distance_list_in {}".format(ad.physics.to_string(distance_list_in)))
        print("distance_list_out {}".format(ad.physics.to_string(distance_list_out)))
        self.assertEqual(len(point_vector), len(distance_list_out))
        for a, b in zip(distance_list_in, distance_list_out):
            self.assertEqual(a, b)

        polygon_vector = ad.geometry.PolygonVector()
        polygon_vector.append(polygon)
        self.assertEqual(1, len(polygon_vector))


if __name__ == '__main__':
    if os.environ.get('GTEST_OUTPUT') and os.environ['GTEST_OUTPUT'].startswith('xml:'):
        base_folder = os.environ['GTEST_OUTPUT'][4:]
        unittest.main(testRunner=xmlrunner.XMLTestRunner(output=base_folder))
    else:
        unittest.main()
