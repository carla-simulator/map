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


class LayerManagerLaneTopology(LayerManager):

    "..."

    def __init__(self, layer, position, tlon, tlat):
        "..."
        LayerManager.__init__(self, layer)
        self.layer = layer
        self.position = position
        self.tlon = tlon
        self.tlat = tlat
        self.to_topo = {}

    def add(self, lane):
        "..."
        lane_id = lane.id
        pts_from = self.__generate_alt_points__(lane_id, self.tlon, self.tlat)
        if self.position is "Left":
            conns = ad.map.lane.getContactLanes(lane, ad.map.lane.ContactLocation.LEFT)
        elif self.position is "Right":
            conns = ad.map.lane.getContactLanes(lane, ad.map.lane.ContactLocation.RIGHT)
        elif self.position is "Successor":
            conns = ad.map.lane.getContactLanes(lane, ad.map.lane.ContactLocation.SUCCESSOR)
        elif self.position is "Predecessor":
            conns = ad.map.lane.getContactLanes(lane, ad.map.lane.ContactLocation.PREDECESSOR)
        else:
            conns = ad.map.lane.getContactLanes(lane, ad.map.lane.ContactLocation.OVERLAP)
        for conn in conns:
            to_lane_id = conn.toLane
            to_lane = ad.map.lane.getLane(to_lane_id)
            if to_lane is not None:
                key = (lane_id, to_lane_id)
                LayerManager.remove_old_feature(self, key)
                types = conn.types
                attrs = [str(lane_id), str(to_lane_id), str(types)]
                pts_to = self.__generate_alt_points__(to_lane_id, self.tlon, self.tlat)
                feature = self.__add_shortest_arrow__(self.layer, pts_from, pts_to, attrs)
                LayerManager.add_new_feature(self, key, feature)
                if lane_id in self.to_topo:
                    self.to_topo[lane_id].append(to_lane_id)
                else:
                    self.to_topo[lane_id] = [to_lane_id]

    def remove(self, lane_id):
        "..."
        if lane_id in self.to_topo:
            for to_lane_id in self.to_topo[lane_id]:
                key = (lane_id, to_lane_id)
                LayerManager.remove_old_feature(self, key)
            del self.to_topo[lane_id]

    def readd(self, lane_id):
        "..."
        lane = ad.map.lane.getLane(lane_id)
        self.remove(lane_id)
        self.add(lane)

    def __generate_alt_points__(self, lane_id, tlon, tlat):
        "..."
        pt0 = GetLaneParamPoint(lane_id, tlon, tlat)
        pt1 = GetLaneParamPoint(lane_id, 1.0 - tlon, tlat)
        pt2 = GetLaneParamPoint(lane_id, tlon, 1.0 - tlat)
        pt3 = GetLaneParamPoint(lane_id, 1.0 - tlon, 1.0 - tlat)
        return [pt0, pt1, pt2, pt3]

    def __add_shortest_arrow__(self, layer, pts_from, pts_to, attributes):
        "..."
        if pts_from:
            if pts_to:
                from_min = 0
                to_min = 0
                dmin = GetGeoDistance(pts_from[0], pts_to[0])
                for i in range(0, len(pts_from)):  # pylint: disable=C0200
                    for j in range(0, len(pts_to)):  # pylint: disable=C0200
                        dij = GetGeoDistance(pts_from[i], pts_to[j])
                        if dij < dmin:
                            from_min = i
                            to_min = j
                            dmin = dij
                return layer.add_lla(pts_from[from_min], pts_to[to_min], attributes)
        return None

    def features_removed(self, _, deleted_feature_ids):
        "..."
        for feature_id in deleted_feature_ids:
            if feature_id in self.feature_id_to_lane_id_map_1:
                key = self.feature_id_to_lane_id_map_1[feature_id]
                lane_id = key[0]
                to_lane_id = key[1]
                if ad.map.factory.deleteContacts(lane_id, to_lane_id):
                    Globs.dirty_lanes.append(lane_id)
                    Globs.map_dirty = True
                else:
                    Globs.log.error("Failed to delete lane " + str(lane_id))
                self.remove_old_feature(key, False)
            else:
                Globs.log.error("Feature to delete not found on layer!?")
        Globs.main.map_refresh()
