# Embed_Python_With_Cpp

since python3, PyString_FromString() is replaced by PyUnicode_FromString() or PyBytes_FromString().

to pass arguments to a function use Py_BuildValue() instead of PyTuple_Pack(). PyTuple_Pack() will cause a seg fault.
