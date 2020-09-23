## Usage of Python binding for ad_physics

Compilation of ad_physics_python (build option *-DBUILD_PYTHON_BINDING=ON*
and ideally *-DBUILD_SHARED_LIBS=OFF*) will create an *ad* python package
inside the install/ad_physics/lib/pythonMaj.Min folder.
The package be used inside any Python code
to use datatypes or call methods defined in ad_physics.

## Usage of Python binding
To use the compiled Python binding, one has to extend the current environment
to be able to use the newly created package. Afterwards, one can import the
Python package and use it as any other Python module.
```bash
 map$>  export PYTHONPATH=$PYTHONPATH:<path/to/>install/ad_physics/lib/python3.6
 map$>  python3.6
 >>> import ad_physics as ad
 >>> distance = ad.physics.Distance(2.0)
 >>> print(distance)
```

When using other python versions you have to set PYTHONPATH accordingly.
If not enforcing static linking, you require to set the LD_LIBRARY_PATH upfront, too:
```bash
 map$>  export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:<path/to/>install/ad_physics/lib
```

For some simple examples, you might also want to spot into the ad_physics_python/tests folder.
