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
from .Runner import Runner


class LandmarkRunner(Runner):

    "..."

    def __init__(self, landmark_ids):
        "..."
        Runner.__init__(self)
        self.landmark_ids = landmark_ids

    def work(self):
        "..."
        for landmark_id in self.landmark_ids:
            landmark = ad.map.landmark.getLandmark(landmark_id)
            if landmark is not None:
                self.work_landmark(landmark)
            else:
                self.error.emit("Failed to GetLandmark(" + str(landmark_id) + ")")
                return None
        return len(self.landmark_ids)

    def work_landmark(self, landmark):
        "..."
        raise NotImplementedError
