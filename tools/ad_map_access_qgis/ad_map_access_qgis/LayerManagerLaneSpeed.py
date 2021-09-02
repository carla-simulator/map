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
from utility import *
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
        lane_id = lane.id
        limit = round(float(speed_limit.speedLimit), 1)
        tstart = speed_limit.lanePiece.minimum
        tend = speed_limit.lanePiece.maximum
        LayerManager.remove_old_feature(self, lane_id)
        lla_left = GetLaneSubEdgeLeft(lane_id, tstart, tend)
        lla_right = GetLaneSubEdgeRight(lane_id, tstart, tend)
        attrs = [str(lane_id), str(tstart), str(tend), str(limit)]
        feature = self.layer.add_lla2(lla_left, lla_right, attrs)
        LayerManager.add_new_feature(self, lane_id, feature)

    def change_attribute_value(self, lane_id, index, val):
        "..."
        Globs.log.warning("Attribute change not supported")
