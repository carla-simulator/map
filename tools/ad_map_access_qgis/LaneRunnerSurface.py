# ----------------- BEGIN LICENSE BLOCK ---------------------------------
#
# Copyright (C) 2018-2019 Intel Corporation
#
# SPDX-License-Identifier: MIT
#
# ----------------- END LICENSE BLOCK -----------------------------------
"..."

from .LaneRunner import LaneRunner


class LaneRunnerSurface(LaneRunner):

    "..."

    def __init__(self, layer_manager, lane_ids, high_definition):
        "..."
        LaneRunner.__init__(self, lane_ids)
        self.layer_manager = layer_manager
        self.high_definition = high_definition

    def work_lane(self, lane):
        "..."
        if (lane.complianceVersion != 0) == self.high_definition:
            self.layer_manager.add(lane)
