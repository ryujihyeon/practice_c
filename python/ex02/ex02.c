#include <Python.h>

static char add_doc[] = "add two integers";
static PyObject *sample_add(PyObject *self, PyObject *args)
{
    int a, b, r;
    if (!PyArg_ParseTuple(args, "ii", &a, &b))
        return NULL;
    r = a + b;
    return Py_BuildValue("i", r);
}

static struct PyMethodDef _methods[] = {
    {"add",sample_add,METH_VARARGS,add_doc},
    {NULL}};

static struct PyModuleDef _module = {
    PyModuleDef_HEAD_INIT,
    "_ex02",
    "this is simple sample module doc",
    -1,
    _methods};

PyMODINIT_FUNC
PyInit__ex02(void)
{
    PyObject *m;
    m = PyModule_Create(&_module);
    return m;
}
