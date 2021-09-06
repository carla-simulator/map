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

    def __init__(self, layer, landmark_type):
        "..."
        LayerManager.__init__(self, layer)
        self.layer = layer
        self.landmark_type = landmark_type
        if landmark_type == "LANDMARK":
            self.landmark_types = ["UNKNOWN", "POLE", "OTHER", "GUIDE_POST",
                                   "POSTBOX", "MANHOLE", "POWERCABINET", "FIRE_HYDRANT", "BOLLARD"]
        else:
            self.landmark_types = [landmark_type]

    def add(self, landmark):
        "..."
        landmark_id = landmark.id
        pt0 = ad.map.point.toGeo(landmark.position)
        typ = landmark.type

        if pt0 is None:
            return
        if str(typ) not in self.landmark_types:
            return

        heading = ad.map.landmark.getENUHeading(landmark)
        orientation = round(float(heading), 5)
        attrs = [str(landmark_id), str(typ), orientation]
        feature_1 = self.layer.add_lla(pt0, attrs)
        LayerManager.add_new_feature(self, landmark_id, feature_1)
