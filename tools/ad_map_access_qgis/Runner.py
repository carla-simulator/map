# ----------------- BEGIN LICENSE BLOCK ---------------------------------
#
# Copyright (C) 2018-2019 Intel Corporation
#
# SPDX-License-Identifier: MIT
#
# ----------------- END LICENSE BLOCK -----------------------------------
"..."

import traceback
from PyQt4 import QtCore


class Runner(QtCore.QObject):

    "..."
    #
    progress = QtCore.pyqtSignal(float)
    finished = QtCore.pyqtSignal(object)
    #
    debug = QtCore.pyqtSignal(str)
    info = QtCore.pyqtSignal(str)
    warning = QtCore.pyqtSignal(str)
    error = QtCore.pyqtSignal(str)
    exxception = QtCore.pyqtSignal(basestring)

    def __init__(self):
        "..."
        QtCore.QObject.__init__(self)

    def run(self):
        "..."
        try:
            result = self.work()
            self.finished.emit(result)
        except:  # pylint: disable=W0702
            self.exxception.emit(traceback.format_exc())
            self.finished.emit(None)

    def work(self):
        "..."
        raise NotImplementedError
