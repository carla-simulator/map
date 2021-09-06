# ----------------- BEGIN LICENSE BLOCK ---------------------------------
#
# Copyright (C) 2018-2021 Intel Corporation
#
# SPDX-License-Identifier: MIT
#
# ----------------- END LICENSE BLOCK -----------------------------------
"..."

import ad_map_access as ad
from utility import *
import Globs
from qgis.core import QgsFeatureRequest
from .LayerManager import LayerManager


class LayerManagerLaneEdge(LayerManager):

    "..."

    def __init__(self, layer):
        "..."
        LayerManager.__init__(self, layer)
        self.layer = layer

    def add(self, lane):
        "..."
        lane_id = lane.id
        LayerManager.remove_old_feature(self, lane_id)
        lla_left = GetLaneEdgeLeft(lane_id)
        lla_right = GetLaneEdgeRight(lane_id)
        attrs_left = [str(lane_id), "Left"]
        attrs_right = [str(lane_id), "Right"]
        left_feature = self.layer.add_lla(lla_left, attrs_left)
        right_feature = self.layer.add_lla(lla_right, attrs_right)
        LayerManager.add_new_feature(self, lane_id, left_feature, right_feature)
