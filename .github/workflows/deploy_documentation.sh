#!/bin/bash

# ----------------- BEGIN LICENSE BLOCK ---------------------------------
#
# Copyright (c) 2019-2020 Intel Corporation
#
# ----------------- END LICENSE BLOCK -----------------------------------
##

# prepare
cp -r doc/ doctmp/ && cp README.md README.md.tmp
git checkout origin/doc
git checkout -b doc

# clean old
rm -rf doc
mkdir doc

# copy new doc
cp -r doctmp/* doc/. && cp README.md.tmp README.md

# apidoc
cp -r build/ad_physics/apidoc doc/ad_physics/.
cp -r build/ad_map_access/apidoc doc/ad_map_access/.

# coverage
mv coverage/ad_physics doc/ad_physics/coverage
mv coverage/ad_map_access doc/ad_map_access/coverage

# cleanup
rm -rf build install log doctmp README.md.tmp

# commit
git add doc/ README.md
git status

git config user.email "noemail@email.com"
git config user.name "Github Action"
git commit -m "Updated documentation" --no-edit

if [ "$1" = true ]; then
  git push origin doc
else
  echo "Only testing mode - No deployment"
fi
