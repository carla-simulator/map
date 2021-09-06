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


class LayerManagerLaneSurface(LayerManager):

    "..."

    def __init__(self, layer):
        "..."
        LayerManager.__init__(self, layer)
        self.layer = layer

    def add(self, lane):
        "..."
        lane_id = lane.id
        lane_id_int = int(str(lane_id))
        LayerManager.remove_old_feature(self, lane_id)
        lla_left = GetLaneEdgeLeft(lane_id)
        lla_right = GetLaneEdgeRight(lane_id)
        attrs = []
        attrs.append(str(lane.id))
        attrs.append(str(lane.type))
        attrs.append(str(ad.map.lane.getHOV(lane)))
        if lane_id_int > 10000:
            attrs.append(int(lane_id_int / 10000))
            attrs.append(int((lane_id_int % 10000) / 100))
            attrs.append((lane_id_int % 10000) % 100)
        feature = self.layer.add_lla2(lla_left, lla_right, attrs)
        LayerManager.add_new_feature(self, lane_id, feature)

    def change_attribute_value(self, lane_id, index, val):
        "..."
        Globs.log.warning("Attribute Change not supported")
