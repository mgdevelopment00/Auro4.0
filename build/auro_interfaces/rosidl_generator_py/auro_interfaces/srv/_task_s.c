// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from auro_interfaces:srv/Task.idl
// generated code does not contain a copyright notice
#define NPY_NO_DEPRECATED_API NPY_1_7_API_VERSION
#include <Python.h>
#include <stdbool.h>
#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-function"
#endif
#include "numpy/ndarrayobject.h"
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif
#include "rosidl_runtime_c/visibility_control.h"
#include "auro_interfaces/srv/detail/task__struct.h"
#include "auro_interfaces/srv/detail/task__functions.h"


ROSIDL_GENERATOR_C_EXPORT
bool auro_interfaces__srv__task__request__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[39];
    {
      char * class_name = NULL;
      char * module_name = NULL;
      {
        PyObject * class_attr = PyObject_GetAttrString(_pymsg, "__class__");
        if (class_attr) {
          PyObject * name_attr = PyObject_GetAttrString(class_attr, "__name__");
          if (name_attr) {
            class_name = (char *)PyUnicode_1BYTE_DATA(name_attr);
            Py_DECREF(name_attr);
          }
          PyObject * module_attr = PyObject_GetAttrString(class_attr, "__module__");
          if (module_attr) {
            module_name = (char *)PyUnicode_1BYTE_DATA(module_attr);
            Py_DECREF(module_attr);
          }
          Py_DECREF(class_attr);
        }
      }
      if (!class_name || !module_name) {
        return false;
      }
      snprintf(full_classname_dest, sizeof(full_classname_dest), "%s.%s", module_name, class_name);
    }
    assert(strncmp("auro_interfaces.srv._task.Task_Request", full_classname_dest, 38) == 0);
  }
  auro_interfaces__srv__Task_Request * ros_message = _ros_message;
  {  // diameter
    PyObject * field = PyObject_GetAttrString(_pymsg, "diameter");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->diameter = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // move_to_target
    PyObject * field = PyObject_GetAttrString(_pymsg, "move_to_target");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->move_to_target = (Py_True == field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * auro_interfaces__srv__task__request__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of Task_Request */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("auro_interfaces.srv._task");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "Task_Request");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  auro_interfaces__srv__Task_Request * ros_message = (auro_interfaces__srv__Task_Request *)raw_ros_message;
  {  // diameter
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->diameter);
    {
      int rc = PyObject_SetAttrString(_pymessage, "diameter", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // move_to_target
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->move_to_target ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "move_to_target", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}

#define NPY_NO_DEPRECATED_API NPY_1_7_API_VERSION
// already included above
// #include <Python.h>
// already included above
// #include <stdbool.h>
// already included above
// #include "numpy/ndarrayobject.h"
// already included above
// #include "rosidl_runtime_c/visibility_control.h"
// already included above
// #include "auro_interfaces/srv/detail/task__struct.h"
// already included above
// #include "auro_interfaces/srv/detail/task__functions.h"


ROSIDL_GENERATOR_C_EXPORT
bool auro_interfaces__srv__task__response__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[40];
    {
      char * class_name = NULL;
      char * module_name = NULL;
      {
        PyObject * class_attr = PyObject_GetAttrString(_pymsg, "__class__");
        if (class_attr) {
          PyObject * name_attr = PyObject_GetAttrString(class_attr, "__name__");
          if (name_attr) {
            class_name = (char *)PyUnicode_1BYTE_DATA(name_attr);
            Py_DECREF(name_attr);
          }
          PyObject * module_attr = PyObject_GetAttrString(class_attr, "__module__");
          if (module_attr) {
            module_name = (char *)PyUnicode_1BYTE_DATA(module_attr);
            Py_DECREF(module_attr);
          }
          Py_DECREF(class_attr);
        }
      }
      if (!class_name || !module_name) {
        return false;
      }
      snprintf(full_classname_dest, sizeof(full_classname_dest), "%s.%s", module_name, class_name);
    }
    assert(strncmp("auro_interfaces.srv._task.Task_Response", full_classname_dest, 39) == 0);
  }
  auro_interfaces__srv__Task_Response * ros_message = _ros_message;
  {  // success
    PyObject * field = PyObject_GetAttrString(_pymsg, "success");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->success = (Py_True == field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * auro_interfaces__srv__task__response__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of Task_Response */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("auro_interfaces.srv._task");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "Task_Response");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  auro_interfaces__srv__Task_Response * ros_message = (auro_interfaces__srv__Task_Response *)raw_ros_message;
  {  // success
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->success ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "success", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
