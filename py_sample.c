#include "Python.h"
#include "sample.h"

static PyObject *py_gcd(PyObject *self, PyObject *args) {
    int x, y, result;

    if (!PyArg_ParseTuple(args, "ii", &x, &y)) {
        return NULL;
    }
    result = gcd(x, y);
    return Py_BuildValue("i", result);
}

static PyObject *py_Point(PyObject *self, PyObject *args) {
    Point *p;
    double x, y;
    if (!PyArg_ParseTuple(args, "dd",  &x, &y)) {
        return NULL;
    }
    printf("x = %lf, y = %lf\n", x, y);
    p = (Point *)malloc(sizeof(Point));
    p->x = x;
    p->y = y;
    printf("addr: %lX, point: (%lf, %lf)\n", p, p->x, p->y);
    PyObject *r = Py_BuildValue("O", p);
    free(p);
    return r;
}

static PyObject *py_FreePoint(PyObject *self, PyObject *args) {
    PyObject *py_p;
    if (!PyArg_ParseTuple(args, "O",  &py_p)) {
        return NULL;
    }
    printf("free %lX\n", py_p);
    free(py_p);
    return Py_BuildValue("");
}

static PyObject *py_distance(PyObject *self, PyObject *args) {
    Point *p1, *p2;
    PyObject *py_p1, *py_p2;
    double result;

    if (!PyArg_ParseTuple(args, "OO",  &py_p1, &py_p2)) {
        return NULL;
    }

    printf("py_p1: %lX, py_p2: %lX\n", py_p1, py_p2);
    result = distance((Point*)py_p1, (Point*)py_p2);
    return Py_BuildValue("d", result);
}

static PyMethodDef SampleMethods[] = {
    {"gcd", py_gcd, METH_VARARGS, "Greatest Common Divisor"},
    {"Point", py_Point, METH_VARARGS, ""},
    {"FreePoint", py_FreePoint, METH_VARARGS, ""},
    {"distance", py_distance, METH_VARARGS, "get the distance between two Points"},
    {NULL, NULL, 0, NULL}
};

void initsample() {
    Py_InitModule("sample", SampleMethods);
}

