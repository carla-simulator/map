# ----------------- BEGIN LICENSE BLOCK ---------------------------------
#
# Copyright (C) 2018-2019 Intel Corporation
#
# SPDX-License-Identifier: MIT
#
# ----------------- END LICENSE BLOCK -----------------------------------
"..."

from .LaneRunner import LaneRunner


class LaneRunnerSpeed(LaneRunner):

    "..."

    def __init__(self, admap_qgis, lane_ids):
        "..."
        LaneRunner.__init__(self, lane_ids)
        self.admap_qgis = admap_qgis

    def work_lane(self, lane):
        "..."
        if "SpeedLimit" in lane.keys():
            for speed_limit in lane['SpeedLimit']:
                limit = speed_limit[0]
                layer_manager = self.admap_qgis.layers.speed_layer_manager(limit)
                layer_manager.add_speed_limit(lane, speed_limit)
        else:
            layer_manager = self.admap_qgis.layers.speed_layer_manager(0)
            layer_manager.add_speed_limit(lane, (0.0, 0.0, 1.0))
