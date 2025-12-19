#include <iostream>
#include <Python.h>

int32_t fibonacci(int32_t num)
{
    if (num <= 2)
        return 1;
    return fibonacci(num - 1) + fibonacci(num - 2);
}

static PyObject* cutils_fibonacci(PyObject* self, PyObject* args)
{
    int32_t size;
    if (!PyArg_ParseTuple(args, "l", &size))
    {
        std::cerr << "Faile to parse arguments" << std::endl;
        return nullptr;
    }
    int32_t res = fibonacci(size);
    return Py_BuildValue("l", res);
}

static PyObject* cutils_sum(PyObject* self, PyObject* args)
{
    int32_t size;
    PyObject* list;
    if (!PyArg_ParseTuple(args, "lO", &size, &list))
    {
        std::cerr << "Faile to parse arguments" << std::endl;
        return nullptr;
    }

    size_t list_size = PyList_Size(list);
    int32_t res = 0;
    for (size_t i = 0; i < list_size && i < size; ++i)
    {
        PyObject* tmp = PyList_GetItem(list, i);
        res += PyLong_AsLong(tmp);
    }
    return Py_BuildValue("l", res);
}

static PyMethodDef cutils_methods[] = {
    {"sum", cutils_sum, METH_VARARGS, "Функция сложения"},
    {"fibonacci", cutils_fibonacci, METH_VARARGS, "Функция вычисления i-го числа Фибоначчи"},
    {nullptr, nullptr, 0, nullptr}
};

static PyModuleDef module_info = {
    PyModuleDef_HEAD_INIT,
    "cutils",
    "Пример работы с C API",
    -1,
    cutils_methods
};

PyMODINIT_FUNC PyInit_cutils(void) {
    return PyModule_Create(&module_info);
}
