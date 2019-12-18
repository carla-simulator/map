# ----------------- BEGIN LICENSE BLOCK ---------------------------------
#
# Copyright (C) 2018-2019 Intel Corporation
#
# SPDX-License-Identifier: MIT
#
# ----------------- END LICENSE BLOCK -----------------------------------
"..."

import ad_map_access_python as admap
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
            lane = admap.GetLane(lane_id)
            if lane is not None:
                self.work_lane(lane)
            else:
                self.error.emit("Failed to GetLane(" + str(lane_id) + ")")
                return None
        return len(self.lane_ids)

    def work_lane(self, lane):
        "..."
        raise NotImplementedError
