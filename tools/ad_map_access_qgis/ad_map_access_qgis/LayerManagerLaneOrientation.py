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
from .LayerManager import LayerManager


class LayerManagerLaneOrientation(LayerManager):

    "..."

    def __init__(self, layer):
        "..."
        LayerManager.__init__(self, layer)
        self.layer = layer

    def add(self, lane):
        "..."
        lane_id = lane.id
        LayerManager.remove_old_feature(self, lane_id)
        pt0 = GetLaneParamPoint(lane_id, 0.20, 0.5)
        pt1 = GetLaneParamPoint(lane_id, 0.35, 0.5)
        attrs = [str(lane_id)]
        feature = self.layer.add_lla(pt0, pt1, attrs)
        LayerManager.add_new_feature(self, lane_id, feature)
