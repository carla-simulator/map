## Usage of python binding for ad_map_access

Compilation of ad_map_access_python (build option *-DBUILD_PYTHON_BINDING=ON*)
will create an *ad_map_access* python package
inside the install/ad_map_access/lib/pythonMaj.Min/site-packages folder.
The packages can be used inside any python code to use
datatypes or call methods defined in ad_map_access and its dependency ad_physics.

## Usage of python binding
To use the compiled python binding, one has to extend the current environment
to be able to use the newly created packages. Afterwards, one can import the
python package and use it as any other python module.
```bash
 map$> echo "Setting PYTHONPATH and LD_LIBRARY_PATH:"
 map$> source install/setup.bash
 map$> python3.8
 >>> import ad_map_access as ad
 >>> ad.map.access.init("ad_map_access/python/tests/test_files/TPK.adm.txt")
 >>> lanes = ad.map.lane.getLanes()
 >>> print(len(lanes))
```
Also the interface of the dependency can be accessed directly, since ad_map_access is relying on those
and imports them into it's namespace:
```bash
 >>> distance = ad.physics.Distance(2.0)
 >>> print(distance)
```

For some simple examples, you might also want to spot into the ad_map_access/python/tests folder.
