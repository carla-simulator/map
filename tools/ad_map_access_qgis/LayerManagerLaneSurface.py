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


class LayerManagerLaneSurface(LayerManager):

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
        attrs = []
        attrs.append(lane['Id'])
        attrs.append(lane['Type'])
        attrs.append(lane['HOV'])
        attrs.append(lane['ComplianceVer'])
        feature = self.layer.add_lla2(lla_left, lla_right, attrs)
        LayerManager.add_new_feature(self, lane_id, feature)

    def change_attribute_value(self, lane_id, index, val):
        "..."
        if index == 1:
            if admap.SetLaneType(lane_id, str(val)):
                return True
            return LayerManager.attribute_change_failed(self, lane_id, "Type", val)
        elif index == 3:
            if admap.SetLaneComplianceVer(lane_id, int(val)):
                return True
            return LayerManager.attribute_change_failed(self, lane_id, "ComplianceVer", val)
        return LayerManager.change_attribute_value(self, lane_id, index, val)
