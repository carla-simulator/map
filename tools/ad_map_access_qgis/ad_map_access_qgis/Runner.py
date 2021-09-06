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

    def __init__(self):
        "..."
        QtCore.QObject.__init__(self)

    def progress(self, percent):
        "..."

    def debug(self, msg):
        "..."
        Globs.log.debug(msg)

    def info(self, msg):
        "..."
        Globs.log.info(msg)

    def warning(self, msg):
        "..."
        Globs.log.warning(msg)

    def error(self, msg):
        "..."
        Globs.log.error(msg)

    def exxception(self, msg):
        "..."
        self.error("Thread " + self.title + "raised exception! See message log for more info!")
        QgsMessageLog.logMessage("Thread " + self.title + " exception: " + msg)
