# ----------------- BEGIN LICENSE BLOCK ---------------------------------
#
# Copyright (C) 2018-2021 Intel Corporation
#
# SPDX-License-Identifier: MIT
#
# ----------------- END LICENSE BLOCK -----------------------------------
"..."


import Globs
import ad_map_access as ad
from .Runner import Runner


class LaneRunner(Runner):

    "..."

    def __init__(self, lane_ids):
        "..."
        Runner.__init__(self)
        self.lane_ids = lane_ids

    def work(self):
        "..."
        for lane_id in self.lane_ids:
            lane = ad.map.lane.getLane(lane_id)
            if lane is not None:
                self.work_lane(lane)
            else:
                self.error.emit("Failed to GetLane(" + str(lane_id) + ")")
                return None
        return len(self.lane_ids)

    def work_lane(self, lane):
        "..."
        raise NotImplementedError
