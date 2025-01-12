// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from auro_interfaces:srv/Rotate.idl
// generated code does not contain a copyright notice

#ifndef AURO_INTERFACES__SRV__DETAIL__ROTATE__STRUCT_H_
#define AURO_INTERFACES__SRV__DETAIL__ROTATE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in srv/Rotate in the package auro_interfaces.
typedef struct auro_interfaces__srv__Rotate_Request
{
  bool direction;
} auro_interfaces__srv__Rotate_Request;

// Struct for a sequence of auro_interfaces__srv__Rotate_Request.
typedef struct auro_interfaces__srv__Rotate_Request__Sequence
{
  auro_interfaces__srv__Rotate_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} auro_interfaces__srv__Rotate_Request__Sequence;


// Constants defined in the message

/// Struct defined in srv/Rotate in the package auro_interfaces.
typedef struct auro_interfaces__srv__Rotate_Response
{
  bool success;
} auro_interfaces__srv__Rotate_Response;

// Struct for a sequence of auro_interfaces__srv__Rotate_Response.
typedef struct auro_interfaces__srv__Rotate_Response__Sequence
{
  auro_interfaces__srv__Rotate_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} auro_interfaces__srv__Rotate_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // AURO_INTERFACES__SRV__DETAIL__ROTATE__STRUCT_H_
