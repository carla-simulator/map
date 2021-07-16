#!/bin/bash

DOC_STRING="Build Docker image for building manylinux wheels."

USAGE_STRING=$(cat <<- END
Usage: $0 [-h|--help] [-p|--python-version PYTHON_VERSION]

The following python versions are supported:
    * 2.7
    * 3.6
    * 3.7
    * 3.8
END
)

usage() { echo "${DOC_STRING}"; echo "${USAGE_STRING}"; exit 1; }

# Defaults
PYTHON_VERSION="3.6"

while [[ $# -gt 0 ]]; do
  case "$1" in
    -p |--python-version )
      PYTHON_VERSION=$2
      if [ "${PYTHON_VERSION}" != "2.7" ] && [ "${PYTHON_VERSION}" != "3.6" ] && [ "${PYTHON_VERSION}" != "3.7" ] && [ "${PYTHON_VERSION}" != "3.8" ]; then
        usage
      fi
      shift 2 ;;
    -h | --help )
      usage
      ;;
    * )
      shift ;;
  esac
done

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
docker build \
  -t map:${PYTHON_VERSION} \
  -f Dockerfile ${SCRIPT_DIR} \
  --build-arg PYTHON_BINDING_VERSION=${PYTHON_VERSION}
