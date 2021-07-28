## Usage of Python binding for ad_map_access

Compilation of ad_map_access_python (build option *BUILD_PYTHON_BINDING*)
will create an *ad_map_access* python package
inside the install/ad_map_access/lib/pythonMaj.Min/site-packages folder.
The packages can be used inside any Python code to use
datatypes or call methods defined in ad_map_access and its dependency ad_physics.

## Usage of Python binding
To use the compiled Python binding, one has to extend the current environment
to be able to use the newly created packages. Afterwards, one can import the
Python package and use it as any other Python module.
```bash
 map/ad_map_access/python$>  export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:<path/to/>install/ad_map_access/lib:<path/to/>install/ad_map_opendrive_reader/lib:<path/to/>install/ad_physics/lib
 map/ad_map_access/python$>  export PYTHONPATH=$PYTHONPATH:<path/to/>install/ad_map_access/lib/python3.8/site-packages
 map/ad_map_access/python$>  python3.8
 >>> import ad_map_access as ad
 >>> ad.map.access.init("tests/test_files/TPK.adm.txt")
 >>> lanes = ad.map.lane.getLanes()
 >>> print(len(lanes))
```
Also the interface of the dependency can be accessed directly, since ad_map_access is relying on those
and imports them into it's namespace:
```bash
 >>> distance = ad.physics.Distance(2.0)
 >>> print(distance)
```

When using other python versions you have to set PYTHONPATH accordingly.
If enforcing static linking, you can omit to set the LD_LIBRARY_PATH upfront.

For some simple examples, you might also want to spot into the ad_map_access/python/tests folder.
