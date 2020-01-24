# ----------------- BEGIN LICENSE BLOCK ---------------------------------
#
# Copyright (C) 2018-2020 Intel Corporation
#
# SPDX-License-Identifier: MIT
#
# ----------------- END LICENSE BLOCK -----------------------------------
"..."

import ad_map_access_qgis_python as admap
from .LayerManager import LayerManager


class LayerManagerLaneSpeed(LayerManager):

    "..."

    def __init__(self, layer):
        "..."
        LayerManager.__init__(self, layer)
        self.layer = layer

    def add(self, lane):
        "..."

    # WARNING: This code does not handle properly multiple sub-segments with same speed limit!

    def add_speed_limit(self, lane, speed_limit):
        "..."
        lane_id = lane['Id']
        limit = round(speed_limit[0], 1)
        tstart = speed_limit[1]
        tend = speed_limit[2]
        LayerManager.remove_old_feature(self, lane_id)
        lla_left = admap.GetLaneSubEdgeLeft(lane_id, tstart, tend)
        lla_right = admap.GetLaneSubEdgeRight(lane_id, tstart, tend)
        attrs = [lane_id, tstart, tend, limit]
        feature = self.layer.add_lla2(lla_left, lla_right, attrs)
        LayerManager.add_new_feature(self, lane_id, feature)

    def change_attribute_value(self, lane_id, index, val):
        "..."
        if index == 3:
            if admap.SetLaneSpeedLimit(lane_id, float(val)):
                return True
            return LayerManager.attribute_change_failed(self, lane_id, "Speed Limit", val)
        return LayerManager.change_attribute_value(self, lane_id, index, val)
