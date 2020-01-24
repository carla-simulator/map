# ----------------- BEGIN LICENSE BLOCK ---------------------------------
#
# Copyright (C) 2018-2020 Intel Corporation
#
# SPDX-License-Identifier: MIT
#
# ----------------- END LICENSE BLOCK -----------------------------------
"..."

import ad_map_access_qgis_python as admap
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
        lane_id = lane['Id']
        LayerManager.remove_old_feature(self, lane_id)
        lla_left = admap.GetLaneEdgeLeft(lane_id)
        lla_right = admap.GetLaneEdgeRight(lane_id)
        attrs_left = [lane_id, "Left"]
        attrs_right = [lane_id, "Right"]
        left_feature = self.layer.add_lla(lla_left, attrs_left)
        right_feature = self.layer.add_lla(lla_right, attrs_right)
        LayerManager.add_new_feature(self, lane_id, left_feature, right_feature)
