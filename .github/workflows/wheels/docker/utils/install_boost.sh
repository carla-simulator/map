#!/bin/bash

BOOST_VERSION=1.72.0
BOOST_BASENAME="boost-${BOOST_VERSION}"
BOOST_PACKAGE_BASENAME=boost_${BOOST_VERSION//./_}

DOC_STRING="Build boost."

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

wget "https://boostorg.jfrog.io/artifactory/main/release/${BOOST_VERSION}/source/${BOOST_PACKAGE_BASENAME}.tar.gz" || true

tar -xzf ${BOOST_PACKAGE_BASENAME}.tar.gz

pushd ${BOOST_PACKAGE_BASENAME} >/dev/null

BOOST_CFLAGS="-fPIC -std=c++14 -DBOOST_ERROR_CODE_HEADER_ONLY"

py="/usr/bin/env python${PYTHON_VERSION}"
py_root=`${py} -c "import sys; print(sys.prefix)"`
pyv=`$py -c "import sys;x='{v[0]}.{v[1]}'.format(v=list(sys.version_info[:2]));sys.stdout.write(x)";`
./bootstrap.sh \
  --with-libraries=python,filesystem,system,program_options \
  --with-python=${py} --with-python-root=${py_root}

echo "using python : ${pyv} : ${py_root}/bin/python${PYTHON_VERSION} ;" > project-config.jam

./b2 install

popd >/dev/null

rm -rf ${BOOST_PACKAGE_BASENAME}
rm -rf ${BOOST_PACKAGE_BASENAME}.tar.gz
