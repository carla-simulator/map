#!/bin/bash

# ----------------- BEGIN LICENSE BLOCK ---------------------------------
#
# Copyright (c) 2025 Intel Corporation
#
# ----------------- END LICENSE BLOCK -----------------------------------
##

# use virtual environment for our build dependencies
if [ ! -f build/map-build-venv/bin/activate ]; then
    python${PYTHON_BINDING_VERSION} -m venv build/map-build-venv
fi
source build/map-build-venv/bin/activate
