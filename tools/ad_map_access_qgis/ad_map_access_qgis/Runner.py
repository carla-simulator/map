# ----------------- BEGIN LICENSE BLOCK ---------------------------------
#
# Copyright (C) 2018-2021 Intel Corporation
#
# SPDX-License-Identifier: MIT
#
# ----------------- END LICENSE BLOCK -----------------------------------
"..."

import traceback
import Globs
from PyQt5 import QtCore


class Runner(QtCore.QObject):

    "..."
    progress = QtCore.pyqtSignal(int)

    def __init__(self):
        "..."
        super(QtCore.QObject, self).__init__()
