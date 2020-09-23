## Usage of Python binding for ad_map_access

Compilation of ad_map_access_python (build option *BUILD_PYTHON_BINDING*
and ideally *-DBUILD_SHARED_LIBS=OFF*) will create an *ad* python package
inside the install/ad_map_access/lib/pythonMaj.Min folder.
The packages can be used inside any Python code to use
datatypes or call methods defined in ad_map_access and its dependency ad_physics.

## Usage of Python binding
To use the compiled Python binding, one has to extend the current environment
to be able to use the newly created packages. Afterwards, one can import the
Python package and use it as any other Python module.
```bash
 ad_map_access_python$>  export PYTHONPATH=$PYTHONPATH:<path/to/>install/ad_map_access/lib/python3.6
 ad_map_access_python$>  python3.6
 >>> import ad_map_access as ad
 >>> ad.map.access.init("tests/test_files/TPK.adm.txt")
 >>> lanes = ad.map.lane.getLanes()
 >>> print(len(lanes))
```
Also the interface of the dependency can be accessed directly, since ad_map_access is relying on those:
```bash
 >>> distance = ad.physics.Distance(2.0)
 >>> print(distance)
```

When using other python versions you have to set PYTHONPATH accordingly.
If not enforcing static linking, you require to set the LD_LIBRARY_PATH upfront, too:
```bash
 ad_map_access_python$>  export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:<path/to/>install/ad_map_access/lib:<path/to/>install/ad_map_opendrive_reader/lib:<path/to/>install/ad_physics/lib
```

For some simple examples, you might also want to spot into the ad_map_access_python/tests folder.
