# Embed_Python_With_Cpp

since python3, PyString_FromString() is replaced by PyUnicode_FromString() or PyBytes_FromString().

to pass arguments to a function use Py_BuildValue() instead of PyTuple_Pack(). PyTuple_Pack() will cause a seg fault.

# How to configure the project

add the python37.dll to the directory and add the link to the project with the python37.lib and the include directory to Python.h
