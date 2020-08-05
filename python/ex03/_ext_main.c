#include <Python.h>
#include <stdio.h>
#include <SDL2/SDL.h>

static PyObject *initSDL()
{
    puts("init sdl2 python v1");
    return Py_BuildValue(" ");
}

static struct PyMethodDef _sample_methods[] = {
    {"initSDL", initSDL, METH_NOARGS, NULL},
    {NULL}};

static struct PyModuleDef _sample_module = {
    PyModuleDef_HEAD_INIT,
    "_ex03",
    "this is simple sample module doc",
    -1,
    _sample_methods};

PyMODINIT_FUNC
PyInit__ex01(void)
{
    PyObject *m;
    m = PyModule_Create(&_sample_module);
    return m;
}
