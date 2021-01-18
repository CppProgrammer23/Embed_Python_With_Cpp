#define PY_SSIZE_T_CLEAN
#include <Python.h>
#include <iostream>



int main(int argc, char* argv[])
{



	PySys_SetPath(L"."); //it means the current path of the project

	PyObject* mod = PyImport_ImportModule("test");
	PyObject* pFunc = PyObject_GetAttrString(mod, "mul");
	PyObject* args = Py_BuildValue("(dd)", 2.3, 4.1);
	PyObject* pVal = PyObject_CallObject(pFunc, args);
	double result = PyFloat_AsDouble(pVal);
	std::cout << result;
	return 0;
}
