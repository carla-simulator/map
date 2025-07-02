# ----------------- BEGIN LICENSE BLOCK ---------------------------------
#
# Copyright (C) 2019-2021 Intel Corporation
#
# SPDX-License-Identifier: MIT
#
# ----------------- END LICENSE BLOCK -----------------------------------
"..."

import ad_map_access as ad
from utility import *
from .LayerManager import LayerManager


class LayerManagerTrafficLight(LayerManager):

    "..."

    def __init__(self, layer):
        "..."
        LayerManager.__init__(self, layer)
        self.layer = layer

    def add(self, lane):
        "..."
        lane_id = lane.id
        successors = ad.map.lane.getContactLanes(lane, ad.map.lane.ContactLocation.SUCCESSOR)
        predecessors = ad.map.lane.getContactLanes(lane, ad.map.lane.ContactLocation.PREDECESSOR)

        all_contacts = []
        all_contacts.extend(successors)
        all_contacts.extend(predecessors)
        for each_contact in successors:
            for con in each_contact.types:
                if str(con) == "TRAFFIC_LIGHT":
                    try:
                        to_lane_id = each_contact.to_lane
                        traffic_light_id = each_contact.landmark_id
                        landmark = ad.map.landmark.getENULandmark(traffic_light_id)
                        geo = ad.map.point.toGeo(landmark.position)
                        pt_from = GetLaneParamPoint(lane_id, 1.0, 0.5)
                        attrs = [str(lane_id)]
                        feature = self.layer.add_lla(pt_from, geo, attrs)
                        LayerManager.add_new_feature(self, lane_id, feature)
                    except:
                        print("LayerManagerTrafficLight: Exception at lane {}".format(lane_id))
                        pass
        for each_contact in predecessors:
            for con in each_contact.types:
                if str(con) == "TRAFFIC_LIGHT":
                    try:
                        traffic_light_id = each_contact.landmark_id
                        enu = ad.map.landmark.getENULandmark(traffic_light_id).position
                        geo = ad.map.point.toGeo(enu)

                        pt_from = GetLaneParamPoint(lane_id, 0.0, 0.5)
                        attrs = [str(lane_id)]
                        feature = self.layer.add_lla(pt_from, geo, attrs)
                        LayerManager.add_new_feature(self, lane_id, feature)
                    except:
                        print("LayerManagerTrafficLight: Exception at lane {}".format(lane_id))
                        pass
