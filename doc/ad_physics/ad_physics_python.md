## Usage of Python binding for ad_physics

Compilation of ad_physics_python (build option *BUILD_PYTHON_BINDING*)
will create a libad_physics_python.so shared library inside
the install/ad_physics/lib folder.
The shared library can now be used inside any Python code to use
datatypes or call methods defined in ad_physics.

## Usage of Python binding
To use the compiled Python binding, one has to extend the current environment
to be able to use the newly created library. Afterwards, one can import the
Python library as module and use it as any other Python module.
```bash
 map$>  export PYTHONPATH=$PYTHONPATH:<path/to/>install/ad_physics/lib
 map$>  python
 >>> import libad_physics_python as physics
 >>> distance = physics.Distance(2.0)
 >>> print(distance)
```

For some simple examples, you might also want to spot into the ad_physics_python/tests folder.
