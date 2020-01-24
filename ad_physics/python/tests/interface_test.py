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


class InterfaceTest(unittest.TestCase):

    """
    Test class for Python interface
    """

    def test_interface(self):
        """
        Main test part
        """
        speed_a = physics.Speed(10.)
        speed_b = physics.Speed(20.)
        speed_c = speed_a + speed_b

        self.assertEqual(speed_c, 30.)

        t = physics.Duration(2.)

        a_2 = speed_a / t
        self.assertEqual(a_2, 5.)

        a = physics.Acceleration(10.)

        speed_c = t * a

        self.assertEqual(speed_c, 20.)


if __name__ == '__main__':
    unittest.main()
