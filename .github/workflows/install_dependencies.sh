#!/bin/bash

IS_DEFAULT_PYTHON_VERSION=1
if [ `lsb_release -a | grep Release | grep "22.04" | wc -l` == 1 ]; then
  if [ "${PYTHON_BINDING_VERSION}" == "" ]; then
    echo "!!!!!!! Setting default python version for Ubuntu22.04 !!!!!!!"
    PYTHON_BINDING_VERSION="3.10"
  elif [ "${PYTHON_BINDING_VERSION}" != "3.10" ]; then
    IS_DEFAULT_PYTHON_VERSION=0
  fi
fi

if [ `lsb_release -a | grep Release | grep "24.04" | wc -l` == 1 ]; then
  if [ "${PYTHON_BINDING_VERSION}" == "" ]; then
    echo "!!!!!!! Setting default python version for Ubuntu24.04 !!!!!!!"
    PYTHON_BINDING_VERSION="3.12"
  elif [ "${PYTHON_BINDING_VERSION}" != "3.12" ]; then
    IS_DEFAULT_PYTHON_VERSION=0
  fi
fi

echo "!!!!!!! Python version: ${PYTHON_BINDING_VERSION} !!!!!!!"

if ((! IS_DEFAULT_PYTHON_VERSION)); then
  sudo add-apt-repository ppa:deadsnakes/ppa
fi

sudo apt-get update

sudo apt-get install -y lsb-core
sudo apt-get install -y --no-install-recommends build-essential castxml cmake sqlite3 libgtest-dev libboost-all-dev libpugixml-dev libgtest-dev liblapacke-dev libspdlog-dev



sudo apt-get install -y --no-install-recommends python${PYTHON_BINDING_VERSION}-dev libpython${PYTHON_BINDING_VERSION}-dev

if [[ "${BUILD_DOCU}x" != "x" ]]; then
  sudo apt-get install doxygen graphviz lcov
fi

sudo apt remove python3-pygments

python${PYTHON_BINDING_VERSION} -m venv build/map-build-venv
source build/map-build-venv/bin/activate
curl -sS https://bootstrap.pypa.io/get-pip.py | python${PYTHON_BINDING_VERSION}
python${PYTHON_BINDING_VERSION} -m pip install -r .github/workflows/requirements.txt
