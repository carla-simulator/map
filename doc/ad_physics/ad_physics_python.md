## Usage of python binding for ad_physics

Compilation of ad_physics_python (build option *-DBUILD_PYTHON_BINDING=ON*)
will create an *ad_physics* python package
inside the install/ad_physics/lib/pythonMaj.Min/site-packages folder.
The package be used inside any python code
to use datatypes or call methods defined in ad_physics.

## Usage of python binding
To use the compiled python binding, one has to extend the current environment
to be able to use the newly created package. Afterwards, one can import the
python package and use it as any other python module.
```bash
 map$> echo "Setting PYTHONPATH and LD_LIBRARY_PATH:"
 map$> source install/setup.bash
 map$> python3.8
 >>> import ad_physics as ad
 >>> distance = ad.physics.Distance(2.0)
 >>> print(distance)
```

For some simple examples, you might also want to spot into the ad_physics/python/tests folder.
