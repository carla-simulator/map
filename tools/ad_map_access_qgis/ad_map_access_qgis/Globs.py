# ----------------- BEGIN LICENSE BLOCK ---------------------------------
#
# Copyright (C) 2018-2021 Intel Corporation
#
# SPDX-License-Identifier: MIT
#
# ----------------- END LICENSE BLOCK -----------------------------------
"..."


# pylint: disable=C0103
map_dirty = False
dirty_lanes = []
dirty_landmarks = []
removed_lanes = []
removed_landmarks = []
log = None
iface = None
main = None


def geo_str(pts):
    "..."
    return "[" + ", ".join("(%.6f, %.6f)" % pt for pt in pts) + "]"
