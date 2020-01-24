## Usage of Python binding for ad_map_access

Compilation of ad_map_access_python (build option *BUILD_PYTHON_BINDING*)
will create a libad_map_access_python.so shared library inside
the install/ad_map_access/lib folder.
The shared library can now be used inside any Python code to use
datatypes or call methods defined in ad_map_access.

## Usage of Python binding
To use the compiled Python binding, one has to extend the current environment
to be able to use the newly created library. Afterwards, one can import the
Python library as module and use it as any other Python module.
```bash
 ad_map_access_python$>  export PYTHONPATH=$PYTHONPATH:<path/to/>install/ad_map_access/lib:<path/to/>install/ad_physics/lib
 ad_map_access_python$>  export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:<path/to/>install/ad_map_access/lib:<path/to/>install/ad_map_opendrive_reader/lib:<path/to/>install/ad_physics/lib
 ad_map_access_python$>  python
 >>> import libad_physics_python as physics
 >>> import libad_map_access_python as admap
 >>> admap.init("tests/test_files/TPK.adm.txt")
 >>> lanes = admap.getLanes()
 >>> print(len(lanes))
```

For some simple examples, you might also want to spot into the ad_map_access_python/tests folder.
