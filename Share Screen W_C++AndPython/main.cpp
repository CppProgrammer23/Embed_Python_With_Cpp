int main()
{
	const char* scriptDirectoryName = "your project directory";
	Py_Initialize();
	PyObject* sysPath = PySys_GetObject("path");
	PyObject* path = PyUnicode_FromString(scriptDirectoryName);
	PyList_Insert(sysPath, 0, path);
  PyObject* mod = PyImport_ImportModule("SS_SER");
	PyObject* pQr = PyObject_GetAttrString(mod, "share");
	PyObject_CallObject(pQr, NULL);

	PyErr_Print();
	Py_Finalize();
	return 0;
}
