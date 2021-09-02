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


class LayerManagerLaneContactType(LayerManager):

    "..."

    def __init__(self, layer, contact_type):
        "..."
        LayerManager.__init__(self, layer)
        self.layer = layer
        self.contact_type = contact_type

    def add(self, lane):
        "..."
        lane_id = lane.id
        successors = ad.map.lane.getContactLanes(lane, ad.map.lane.ContactLocation.SUCCESSOR)
        for succ in successors:
            self.addContact(lane_id, succ, 1.0)

        predecessors = ad.map.lane.getContactLanes(lane, ad.map.lane.ContactLocation.PREDECESSOR)
        for pred in predecessors:
            self.addContact(lane_id, pred, 0.0)

    def addContact(self, lane_id, contact, tlon):
        "..."
        contact_types = contact.types
        to_lane_id = contact.toLane
        for contact_type in contact_types:
            if str(contact_type) == self.contact_type:
                pt0 = GetLaneParamPoint(lane_id, tlon, 0.5)
                attrs = [str(lane_id), str(to_lane_id), str(contact_type)]
                feature = self.layer.add_lla(pt0, attrs)
                LayerManager.add_new_feature(self, lane_id, feature)
