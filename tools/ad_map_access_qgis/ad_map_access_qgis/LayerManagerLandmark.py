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
from .LayerManager import LayerManager


class LayerManagerLandmark(LayerManager):

    "..."

    def __init__(self, layer, landmark_type, excluded_types=None):
        "..."
        LayerManager.__init__(self, layer)
        self.layer = layer
        self.landmark_type = landmark_type
        self.excluded_types = excluded_types
        if landmark_type == "LANDMARK":
            self.landmark_types = {"UNKNOWN", "POLE", "OTHER", "GUIDE_POST",
                                   "POSTBOX", "MANHOLE", "POWERCABINET", "FIRE_HYDRANT", "BOLLARD", "INVALID"}
        else:
            self.landmark_types = {landmark_type}

    def add(self, landmark):
        "..."
        landmark_id = landmark.id
        typ = landmark.type
        trafficlighttype = landmark.traffic_light_type
        trafficsigntype = landmark.traffic_sign_type

        typ_str = str(typ)
        sign_str = str(trafficsigntype)
        effective_type = sign_str if typ_str == "TRAFFIC_SIGN" else typ_str
        if self.excluded_types is not None:
            if effective_type in self.excluded_types:
                return
        elif effective_type not in self.landmark_types:
            return

        pt0 = ad.map.point.toGeo(landmark.position)
        if pt0 is None:
            return

        heading = ad.map.landmark.getENUHeading(landmark)
        orientation = round(heading.mENUHeading, 5)
        attrs = [str(landmark_id), typ_str, orientation, str(trafficlighttype), sign_str]
        feature_1 = self.layer.add_lla(pt0, attrs)
        LayerManager.add_new_feature(self, landmark_id, feature_1)
