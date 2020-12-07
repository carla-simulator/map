#!/bin/bash

source /opt/ad-map/setup.bash

for element in `ls /opt/ad-map/ad_map_access/lib/ | grep "python3"`; do
  export PYTHONPATH=$PYTHONPATH:/opt/ad-map/ad_map_access/lib/$element
done
