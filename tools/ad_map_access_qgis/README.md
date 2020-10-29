## Features of QGis 3.14 <a name="features"></a>
Version 3.0 brings changes to many underlying dependencies which QGIS is built upon.
### Python 3.0
QGIS 3.0 is based on Python 3.
### Qt5
QGIS 3.0 is based off version 5 of the underlying Qt libraries. Many changes and API breaks were introduced in Qt5.
### PyQt 5
Together with the Python and Qt version changes, the PyQt libraries which expose Qt classes to Python have also had their version bumped to PyQt 5.

## Changes made to existing python bindings and how to make it all work
- After building and compiling the new python bindings, the current environment must be extended to be able to use the new python bindings.
- The python path is set to the current python bindings and the working folder. 
$map> export PYTHONPATH=$PYTHONPATH:<path/to/>install/ad_map_access/lib/python3.6
- Load qgis from the working folder where the python environment was set.
- The QGIS_PLUGINPATH can be configured optionally as a shell script file to avoid loading the plugin everytime, Qgis is opened.

## Understanding of how the layers in QGis is created
 
**__init__.py**
       - The starting point of the plugin. It has to have the classFactory() method and may have any other initialisation code.

**metadata.txt**
- Required for QGIS >= 1.8.0. Contains general info, version, name and some other metadata used by plugins website and plugin infrastructure. Since QGIS 2.0 the   metadata from __init__.py are not accepted anymore and the metadata.txt is required.

- The __init__.py file initialises the CARLA ad_map_access plugin and loads all the relevant icons for all the functionalities it has to offer.
- ADMapQgsLayers.py : This file creates all the layers in Qgis and adds groups to the layers according to different map parameters like lane type, lane speed limits, lane topology, lane contact type and landmark type.
- The layer instances created in AdMapQgsLayers.py are passed to the modules which then add all the features and attributes to each created layer.




