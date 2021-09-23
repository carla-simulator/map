ARG PYTHON_BINDING_VERSION

FROM ubuntu:18.04 AS ubuntu

ARG PYTHON_BINDING_VERSION

ENV DEBIAN_FRONTEND=noninteractive

RUN apt-get update && apt-get install -y --no-install-recommends \
  build-essential \
  ca-certificates \
  cmake \
  git \
  unzip \
  wget \
  autoconf \
  automake \
  castxml \
  libpugixml-dev \
  libproj-dev && \
  rm -rf /var/lib/apt/lists/*

RUN \
  if [ ${PYTHON_BINDING_VERSION} = "2.7" ]; then \
    PYTHON3_VERSION=3.6 ; \
  else \
    PYTHON3_VERSION=${PYTHON_BINDING_VERSION} ; \
  fi ; \
  # Install python libraries
  apt-get update && apt-get install -y --no-install-recommends \
   python$PYTHON3_VERSION-dev \
   python3-pip \
   python-dev \
   python-pip \
  && rm -rf /var/lib/apt/lists/* ; \
  # Install python packages
  python$PYTHON3_VERSION -m pip install --upgrade pip ; \
  python$PYTHON3_VERSION -m pip install setuptools ; \
  python$PYTHON3_VERSION -m pip install wheel auditwheel twine pygccxml pyplusplus colcon-common-extensions ; \
  if [ "$PYTHON_BINDING_VERSION" = "2.7" ]; then \
    python2.7 -m pip install --upgrade pip; \
    python2.7 -m pip install setuptools; \
    python2.7 -m pip install install wheel pygccxml pyplusplus; \
  fi

WORKDIR /workspace

COPY ./utils .

RUN bash install_patchelf.sh
RUN bash install_boost.sh --python-version $PYTHON_BINDING_VERSION

ENV LD_LIBRARY_PATH "$LD_LIBRARY_PATH:/usr/local/lib"

CMD ["/bin/bash"]
