## Usage of Python binding for ad_physics

Compilation of ad_physics_python (build option *-DBUILD_PYTHON_BINDING=ON*)
will create an *ad_physics* python package
inside the install/ad_physics/lib/pythonMaj.Min/site-packages folder.
The package be used inside any Python code
to use datatypes or call methods defined in ad_physics.

## Usage of Python binding
To use the compiled Python binding, one has to extend the current environment
to be able to use the newly created package. Afterwards, one can import the
Python package and use it as any other Python module.
```bash
 map$>  export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:<path/to/>install/ad_physics/lib
 map$>  export PYTHONPATH=$PYTHONPATH:<path/to/>install/ad_physics/lib/python3.6/site-packages
 map$>  python3.6
 >>> import ad_physics as ad
 >>> distance = ad.physics.Distance(2.0)
 >>> print(distance)
```

When using other python versions you have to set PYTHONPATH accordingly.
If enforcing static linking, you can omit to set the LD_LIBRARY_PATH upfront.

For some simple examples, you might also want to spot into the ad_physics/python/tests folder.
