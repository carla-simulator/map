#!/bin/bash

PATCHELF_VERSION=0.12
PATCHELF_REPO=https://github.com/NixOS/patchelf/archive/${PATCHELF_VERSION}.tar.gz

PATCHELF_TAR=${PATCHELF_VERSION}.tar.gz
PATCHELF_SOURCE_DIR=patchelf-${PATCHELF_VERSION}

wget ${PATCHELF_REPO}
tar -xzf ${PATCHELF_TAR}

pushd ${PATCHELF_SOURCE_DIR} >/dev/null

./bootstrap.sh
./configure
make install

popd >/dev/null

rm -Rf ${PATCHELF_TAR}
rm -Rf ${PATCHELF_SOURCE_DIR}
