#include <stdio.h>
#include <Python.h>

/**
 * print_python_bytes - Prints basic informations about Python byte objects.
 * @p: PyObject byte object.
 */
void print_python_bytes(PyObject *p)
{
        PyBytesObject *bytes = (PyBytesObject *)p;
        ssize_t size, i;

        printf("[.] bytes object info\n");

        if (!PyBytes_Check(bytes))
        {
                printf("  [ERROR] Invalid Bytes Object\n");
                return;
        }

        size = PyBytes_GET_SIZE(p);

        printf("  size: %zd\n", size);
        printf("  trying string: %s\n", PyBytes_AsString(p));

        printf("  first %zd bytes:", size < 10 ? size : 10);
        for (i = 0; i < size && i < 10; i++)
        {
                printf(" %02x", (unsigned char)PyBytes_AsString(p)[i]);
        }
        printf("\n");
}

/**
 * print_python_list - Prints basic informations about Python lists.
 * @p: PyObject list object.
 */

void print_python_list(PyObject *p)
{
        PyListObject *list = (PyListObject *)p;
        Py_ssize_t size, i;
        PyObject *item;

        printf("[*] Python list info\n");

        size = Py_SIZE(list);

        printf("[*] Size of the Python List = %zd\n", size);
        printf("[*] Allocated = %zd\n", list->allocated);

        for (i = 0; i < size; i++)
        {
                item = PyList_GetItem(p, i);
                printf("Element %zd: ", i);
                if (PyBytes_Check(item))
                {
                        print_python_bytes(item);
                }
                else if (PyList_Check(item))
                {
                        printf("[*] Python list info\n");
                        // Print additional list information here if needed
                }
                else if (PyTuple_Check(item))
                {
                        printf("[*] Python tuple info\n");
                        // Print additional tuple information here if needed
                }
                else if (PyLong_Check(item))
                {
                        printf("long\n");
                }
                else if (PyFloat_Check(item))
                {
                        printf("float\n");
                }
                else if (PyUnicode_Check(item))
                {
                        printf("str\n");
                }
                else
                {
                        printf("[*] Unknown type\n");
                }
        }
}
