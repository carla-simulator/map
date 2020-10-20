# ----------------- BEGIN LICENSE BLOCK ---------------------------------
#
# Copyright (C) 2018-2020 Intel Corporation
#
# SPDX-License-Identifier: MIT
#
# ----------------- END LICENSE BLOCK -----------------------------------
"..."
import Globs
import ad.map
from utility import *
from .LayerManager import LayerManager


class LayerManagerLaneDirection(LayerManager):

    "..."

    def __init__(self, layer):
        "..."
        LayerManager.__init__(self, layer)
        self.layer = layer

    def add(self, lane):
        "..."
        lane_id = lane.id
        LayerManager.remove_old_feature(self, lane_id)
        pt0 = GetLaneParamPoint(lane_id, 0.45, 0.5)
        pt1 = GetLaneParamPoint(lane_id, 0.55, 0.5)
        direction = lane.direction
        attrs = [lane_id, direction]
        feature_1 = None
        feature_2 = None
        if direction == 'POSITIVE':
            feature_1 = self.layer.add_lla(pt0, pt1, attrs)
        if direction == 'NEGATIVE':
            feature_1 = self.layer.add_lla(pt1, pt0, attrs)
        if direction == 'REVERSABLE':
            pt0 = GetLaneParamPoint(lane_id, 0.45, 0.4)
            pt1 = GetLaneParamPoint(lane_id, 0.55, 0.4)
            pt2 = GetLaneParamPoint(lane_id, 0.45, 0.6)
            pt3 = GetLaneParamPoint(lane_id, 0.55, 0.6)
            feature_1 = self.layer.add_lla(pt0, pt1, attrs)
            feature_2 = self.layer.add_lla(pt2, pt3, attrs)
        if direction == 'BIDIRECTIONAL':
            feature_1 = self.layer.add_lla(pt0, pt1, attrs)
            feature_2 = self.layer.add_lla(pt1, pt0, attrs)
        LayerManager.add_new_feature(self, lane_id, feature_1, feature_2)

    def change_attribute_value(self, lane_id, index, val):
        "..."
        if index == 1:
            return LayerManager.attribute_change_failed(self, lane_id, "Direction", val)
        return LayerManager.change_attribute_value(self, lane_id, index, val)
