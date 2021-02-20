#define PY_SSIZE_T_CLEAN
#include <Python.h>

int main()
{
	const char* scriptDirectoryName = "your directory path";
	Py_Initialize();
	PyObject* sysPath = PySys_GetObject("path");
	PyObject* path = PyUnicode_FromString(scriptDirectoryName);
	PyList_Insert(sysPath, 0, path);
  PyObject* main = PyImport_AddModule("__main__");
	PyObject* pDict = PyModule_GetDict(main);
	PyModule_AddObject(main, "test", mod);
	PyObject* pInstance = PyRun_String("test.Student('Sean',14)",Py_eval_input,pDict,pDict);
	PyObject* resultNone = PyObject_CallMethod(pInstance, "addStudent","(i,s)", 15,"Paul");
	PyObject* resultN = PyObject_CallMethod(pInstance, "show","()");
  PyErr_Print();
	Py_Finalize();
	return 0;
}
