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


class LayerManagerLaneContactType(LayerManager):

    "..."

    def __init__(self, layer, contact_type):
        "..."
        LayerManager.__init__(self, layer)
        self.layer = layer
        self.contact_type = contact_type

    def add(self, lane):
        "..."
        lane_id = lane['Id']
        successors = lane['Successor']
        for succ in successors:
            self.addContact(lane_id, succ, 1.0)

        predecessors = lane['Predecessor']
        for pred in predecessors:
            self.addContact(lane_id, pred, 0.0)

    def addContact(self, lane_id, contact, tlon):
        "..."
        contact_types = contact['Type']
        to_lane_id = contact['ToLane']
        for contact_type in contact_types:
            if contact_type == self.contact_type:
                pt0 = admap.GetLaneParamPoint(lane_id, tlon, 0.5)
                attrs = [lane_id, to_lane_id, contact_type]
                feature = self.layer.add_lla(pt0, attrs)
                LayerManager.add_new_feature(self, lane_id, feature)
