#!/bin/bash

# ----------------- BEGIN LICENSE BLOCK ---------------------------------
#
# Copyright (c) 2019-2020 Intel Corporation
#
# ----------------- END LICENSE BLOCK -----------------------------------
##

cp -r doc/ doctmp/ && cp README.md README.md.tmp
git checkout origin/doc
git checkout -b doc
cp -r doctmp/* doc/. && cp README.md.tmp README.md
# apidoc
rm -rf doc/ad_physics/apidoc
rm -rf doc/ad_map_access/apidoc
cp -r build/ad_physics/apidoc doc/ad_physics/.
cp -r build/ad_map_access/apidoc doc/ad_map_access/.
# coverage
rm -rf doc/ad_physics/coverage
rm -rf doc/ad_map_access/coverage
mv coverage/ad_physics doc/ad_physics/coverage
mv coverage/ad_map_access doc/ad_map_access/coverage
# cleanup
rm -rf build install log doctmp README.md.tmp coverage
git add doc/ README.md
git commit -m "Updated documentation" --no-edit || true
git remote add origin-doc https://${GITHUB_TOKEN}@github.com/carla-simulator/map.git > /dev/null 2>&1

if [ "$1" = true ]; then
  git push --set-upstream origin-doc doc
else
  echo "Only testing mode - No deployment"
fi
