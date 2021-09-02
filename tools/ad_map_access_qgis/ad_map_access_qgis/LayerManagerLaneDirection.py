# ----------------- BEGIN LICENSE BLOCK ---------------------------------
#
# Copyright (C) 2018-2021 Intel Corporation
#
# SPDX-License-Identifier: MIT
#
# ----------------- END LICENSE BLOCK -----------------------------------
"..."
import Globs
import ad_map_access as ad
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
        attrs = [str(lane_id), str(direction)]
        feature_1 = None
        feature_2 = None
        if str(direction) == 'POSITIVE':
            feature_1 = self.layer.add_lla(pt0, pt1, attrs)
        if str(direction) == 'NEGATIVE':
            feature_1 = self.layer.add_lla(pt1, pt0, attrs)
        if str(direction) == 'REVERSABLE':
            pt0 = GetLaneParamPoint(lane_id, 0.45, 0.4)
            pt1 = GetLaneParamPoint(lane_id, 0.55, 0.4)
            pt2 = GetLaneParamPoint(lane_id, 0.45, 0.6)
            pt3 = GetLaneParamPoint(lane_id, 0.55, 0.6)
            feature_1 = self.layer.add_lla(pt0, pt1, attrs)
            feature_2 = self.layer.add_lla(pt2, pt3, attrs)
        if str(direction) == 'BIDIRECTIONAL':
            feature_1 = self.layer.add_lla(pt0, pt1, attrs)
            feature_2 = self.layer.add_lla(pt1, pt0, attrs)
        LayerManager.add_new_feature(self, lane_id, feature_1, feature_2)

    def change_attribute_value(self, lane_id, index, val):
        "..."
        Globs.log.warning("Attribute change not supported")
