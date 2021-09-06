# ----------------- BEGIN LICENSE BLOCK ---------------------------------
#
# Copyright (C) 2018-2021 Intel Corporation
#
# SPDX-License-Identifier: MIT
#
# ----------------- END LICENSE BLOCK -----------------------------------
"..."

from .LaneRunner import LaneRunner


class LaneRunnerGeneric(LaneRunner):

    "..."

    def __init__(self, layer_manager, lane_ids):
        "..."
        LaneRunner.__init__(self, lane_ids)
        self.layer_manager = layer_manager

    def work_lane(self, lane):
        "..."
        self.layer_manager.add(lane)
