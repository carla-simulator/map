# ----------------- BEGIN LICENSE BLOCK ---------------------------------
#
# Copyright (C) 2018-2021 Intel Corporation
#
# SPDX-License-Identifier: MIT
#
# ----------------- END LICENSE BLOCK -----------------------------------
"..."
import ad_map_access as ad
import Globs
from .LaneRunner import LaneRunner


class LaneRunnerSpeed(LaneRunner):

    "..."

    def __init__(self, admap_qgis, lane_ids):
        "..."
        LaneRunner.__init__(self, lane_ids)
        self.admap_qgis = admap_qgis

    def work_lane(self, lane):
        "..."
        for speed_limit in lane.speedLimits:
            limit = speed_limit.speedLimit
            layer_manager = self.admap_qgis.layers.speed_layer_manager(limit)
            layer_manager.add_speed_limit(lane, speed_limit)
