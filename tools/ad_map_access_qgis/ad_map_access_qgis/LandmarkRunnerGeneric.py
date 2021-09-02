# ----------------- BEGIN LICENSE BLOCK ---------------------------------
#
# Copyright (C) 2018-2021 Intel Corporation
#
# SPDX-License-Identifier: MIT
#
# ----------------- END LICENSE BLOCK -----------------------------------
"..."

import Globs
from .LandmarkRunner import LandmarkRunner


class LandmarkRunnerGeneric(LandmarkRunner):

    "..."

    def __init__(self, layer_manager, landmark_ids):
        "..."
        LandmarkRunner.__init__(self, landmark_ids)
        self.layer_manager = layer_manager

    def work_landmark(self, landmark):
        "..."
        self.layer_manager.add(landmark)
