# Introduction to map_maker

*map_maker* is a set of tools that convert from one map-format to another. The idea is to use a common map (or an extract of a map) and convert it into the desired target format. Currently, the generation of adm-files for ad_map_access is supported as output format. As source format only OpenStreetMap is supported.

## DISCLAIMER
**Since the original map data is taken from OpenStreetMap (OSM) be careful when using the generated maps for autonomous driving on real roads! There is no guarantee that either the original OSM data matches exactly reality nor that the maps are generated correctly!**

## PROCEDURE
The general procedure for generating and using a map is as follows:
1. Get required map data from [OpenStreetMap](https://www.openstreetmap.org)
2. Convert map into adm format
3. Check generated map

When running any of the tools in step 2, they should not produce any warnings or other messages on the console (unless explicitly requested via [logging parameters](#Logging).

### DOWNLOADING A MAP
This step has to be done at least once in the beginning to get map data for the requested region. Repeating this step is only required if it is known that relevant parts have been fixed or if the original map is outdated.
The recommended tool for downloading map-data is *[JOSM](https://josm.openstreetmap.de)*. This is a java tool that can run under Windows and Linux.
When josm is started it shows its release notes. To see the actual map (and to be able to navigate to the relevant region of interest), select the menu "Imagery" and select "OpenStreetMap Carto (Standard)". Hold down the right mouse button and move around to move within the map, zoom in/out to quickly where you want.
Once you've located the requested location, open menu "File" and select "Download data". This brings a new window with a highlighted rectangular region. This highlighted region will be downloaded when you click on "Download". Within the window you also can use right-mouse-button-down for navigation + plus zoom. You mark the region of interest by left-clicking on any point and holding down the left mouse buttom while moving. If the selected region is too big, the download is refused.
When you are asked for a file name, make sure that you select ".osm" as file format because this is the only supported format for now by map-maker tools.

### KNOWN LIMITATIONS
Since OpenStreetMap only defines the center line of a road, the reconstruction of the geometry of the road (especially the widths of all lanes) is done based on assumptions. Furthermore, there will be always parts of the map that cannot be converted correctly (again because some assumptions are violated). Therefore it is always recommended to check the generated maps.

### SUPPORTED FEATURES FROM OSM
- node: Location of a node, features: tree, street lamp, crosswalk.
- way: Value of key="highway".

## Logging

The tools of map_maker use an internal logging system which can be configured on the command-line. Every entity of the tools (e.g. the reader of the OSM data) comes with its own logging context. A log message triggered by such an entity will result in a line such as

[OsmConverter|Info] The content of the messages
where OsmConverter is the name of the entity, and Info is the severity of the log message.

### Filtering log message
Every log message is given with a certain severity (sometimes also called the log level of the message. The known log-levels are (from severest to least significant)
- Error: A message of log level Error is triggered when the program execution stumbles across an unrecoverable error.
- Warning: A Warning message is triggered when the program detects conditions that should be considered by the user.
- Info: Messages of severity Info are used to give basic information about the normal flow of operations without flooding the user with information. Typical usages are feedback about the
various phases of a program, e.g. reading a file, converting data, writing a file.
- Verbose: All messages with severity Verbose are mainly useful during development of the application(s) or to investigate
ill-formed map-processing.

In order to adjust the amount of log messages there is a concept of filtering of log messages. A log message is only triggered (and generated) if its severity passes a given threshold. As an example if the threshold is set to
Warning only messages with severity Warning Error are reported to the user. To completely turn off logging, there exists a special value named Off

### Configuration
Every logging context is defined by a sink where the logs are finally written threshold which controls the amount of logs name which is preprended to each log message

The behavior of each logging context can be configured through a string of the form

    config1,config2,...

where each config-entry has the form:

    <modulename>:<threshold>:<output>[:<target>]

Where modulename is the name of the module. This string is prepended to every log, and it is also used internally to distinguish between different logging contexts. Therefore, different
logging contexts must be named differently. If no module name is given in the config the setting applies to all logging contexts.
The threshold used for logging. If none is given, default=Warning is assumed.
Output denotes the target of the logs. Must be one of:
- console: Logs are written to stdout
- file: Log are written to a file. The configuration requires an additional file name, named "target" in the config-entry.
- buffer: Log are stored in memory. This is only useful within Unit Tests. Also requires an additional "target"

### Precedence of settings
If no setting is given for a specific modulename, the default values are taken. If no default settings are given in the configuration, the built-in values are taken (Warning, and stdout).

### Examples

    setting=:Off:

Turn logging off.

    setting=:Info:

Sets the threshold for all logging contexts to Info

    setting=::/tmp/log.txt

Sets all output to be written to /tmp/log.txt

    setting=ModuleA:Info:

The logging context for ModuleA will filter at level Info (in contrast to the default threshold Warning
All other logging contexts use default values.

    setting=ModuleA::file:/tmp/moduleA.log

The logging context for ModuleA will filter at default threshold Warning and writes to the file /tmp/moduleA.log (instead of the default behavior of writing to console). All other logging contexts use default values.

    setting=ModuleA:Info:file:/tmp/moduleA.log

The logging context for ModuleA will filter at level Info and will output into a buffer, all other logging contexts will use the built-in default values.

    setting=ModuleA:Info:buffer:module_buffer,:Warning:file:/tmp/log.txt

The logging context for ModuleA will filter at level "Info" and will output into a buffer, all other logging contexts will use the provided default values Warning as threshold and output to the file /tmp/log.txt
