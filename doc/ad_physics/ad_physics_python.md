## Usage of Python binding for ad_physics

Compilation of ad_physics_python (build option *BUILD_PYTHON_BINDING*)
will create a ad/physics python package inside
the install/ad_physics/lib/python{2,3} folder.
The package be used inside any Python code to use
datatypes or call methods defined in ad_physics.

## Usage of Python binding
To use the compiled Python binding, one has to extend the current environment
to be able to use the newly created package. Afterwards, one can import the
Python package and use it as any other Python module.
```bash
 map$>  export PYTHONPATH=$PYTHONPATH:<path/to/>install/ad_physics/lib/python3
 map$>  python3
 >>> import ad.physics
 >>> distance = ad.physics.Distance(2.0)
 >>> print(distance)
```

When using python2 you have to set PYTHONPATH to <path/to/>install/ad_physics/lib/python2 instead.
For some simple examples, you might also want to spot into the ad_physics_python/tests folder.
