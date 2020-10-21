## Changes made to existing python bindings and how to make it all work
  - All imports from the old python interface(for e.g. import ad_map_access_qgis_python as admap) were discarded.
  - All the differences between the two versions were adapted to the plugin code at different places.
  - For e.g, 
    Porting from Python2 to Python 3
    Migration from PyQt4 to PyQt5 libraries
    Moved, Renamed and Removed classes and methods.
  - Functionalities related to Partition Manager was removed, as it is not a part of the new python bindings yet.
  - After building and compiling the new python bindings, the current environment must be extended to be able to use the new python bindings.
  - The python path is set to the current python bindings and the working folder. 
   $map> export PYTHONPATH=$PYTHONPATH:/localdisk/shreyade/map/install/ad_map_access/lib/python3.6:/localdisk/shreyade/map/install/ad_physics/lib/python3.6:/localdisk/shreyade/map/tools
  - Load qgis from the working folder where the python environment was set.
  - The QGIS_PLUGINPATH can be configured optionally as a shell script file to avoid loading the plugin everytime, Qgis is opened.

## Understanding of how the layers in QGis is created
 
**__init__.py**
- The starting point of the plugin. It has to have the classFactory() method and may have any other initialisation code.

**metadata.txt**
- Required for QGIS >= 1.8.0. Contains general info, version, name and some other metadata used by plugins website and plugin infrastructure. Since QGIS 2.0 the   metadata from __init__.py are not accepted anymore and the metadata.txt is required.

- The __init__.py file initialises the Intel AD Map plugin and loads all the relevant icons for all the functionalities it has to offer.
- ADMapQgsLayers.py : This file creates all the layers in Qgis and adds groups to the layers according to different map parameters like lane type, lane speed limits, lane topology, lane contact type and landmark type.
- The layer instances created in AdMapQgsLayers.py are passed to the modules which then add all the features and attributes to each created layer.

## New features added to the plugin
- QGis-Logger is restored.
- Button to enable LaneIDs in view for all layers at once.
- Settings for Route Prediction test(e.g. duration/length/Route Creation Mode) and Routing Test(Route Creation mode) can be added at run time.
- For open drive map, the attributes roadId, laneSectionIndex and laneIndex is now visible as an attribute and can be visualized using the feature identification tool.
- During the Snapping Test, now the ENU coordinates of the map snapped point can be viewed on the logging console and also as an attribute of the map snapped point.



