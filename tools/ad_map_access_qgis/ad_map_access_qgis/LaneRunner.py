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
        progress_count = 0
        next_progress_report = 10
        for lane_id in self.lane_ids:
            lane = ad.map.lane.getLane(lane_id)
            if lane is not None:
                self.work_lane(lane)
            else:
                Globs.log.error("Failed to GetLane(" + str(lane_id) + ")")
                return None
            progress_count += 1
            if float(progress_count)/len(self.lane_ids)*100 > next_progress_report:
                self.progress.emit(next_progress_report)
                next_progress_report += 10

        return len(self.lane_ids)

    def work_lane(self, lane):
        "..."
        raise NotImplementedError
