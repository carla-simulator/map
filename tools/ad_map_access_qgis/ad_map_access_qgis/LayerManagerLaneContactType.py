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
        to_lane_id = contact.to_lane
        for contact_type in contact_types:
            if str(contact_type) == self.contact_type:
                pt0 = GetLaneParamPoint(lane_id, tlon, 0.5)
                attrs = [str(lane_id), str(to_lane_id), str(contact_type)]
                feature = self.layer.add_lla(pt0, attrs)
                LayerManager.add_new_feature(self, lane_id, feature)

    def change_attribute_value(self, lane_id, index, val, attributes):
        "..."
        if index == 2:
            # since the ad-map types are no actual python enumerations, we need to covert the hard way
            new_contact_type = ad.map.lane.ContactType.INVALID
            old_contact_type = ad.map.lane.ContactType.INVALID
            for contact_type_key, contact_type_value in ad.map.lane.ContactType.values.items():
                if str(contact_type_value) == str(val):
                    new_contact_type = ad.map.lane.ContactType.values[contact_type_key]
                if str(contact_type_value) == self.contact_type:
                    old_contact_type = ad.map.lane.ContactType.values[contact_type_key]
            from_lane_id = ad.map.lane.LaneId(int(lane_id))
            to_lane_id = ad.map.lane.LaneId(int(attributes[1]))
            if new_contact_type != ad.map.lane.ContactType.INVALID and old_contact_type != ad.map.lane.ContactType.INVALID:
                succeeded = ad.map.lane.switchLaneContact(from_lane_id, to_lane_id, old_contact_type, new_contact_type)
                if succeeded:
                    Globs.log.info("Changed contact type from_lane {} to_lane {} old_contact_type {} -> new_contact_type {}".format(
                        from_lane_id, to_lane_id, old_contact_type, new_contact_type))
                else:
                    Globs.log.warning("Changing contact type from_lane {} to_lane {} old_contact_type {} -> new_contact_type {} failed".format(
                        from_lane_id, to_lane_id, old_contact_type, new_contact_type))
                return succeeded
            # todo: should move to different layer, but the layer update procedure is incomplete
        else:
            Globs.log.warning("Attribute Change only supported for contact type")

        return False
