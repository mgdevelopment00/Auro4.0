// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from auro_interfaces:srv/ZoneRequest.idl
// generated code does not contain a copyright notice

#ifndef AURO_INTERFACES__SRV__DETAIL__ZONE_REQUEST__STRUCT_H_
#define AURO_INTERFACES__SRV__DETAIL__ZONE_REQUEST__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'robot_id'
// Member 'colour'
#include "rosidl_runtime_c/string.h"

/// Struct defined in srv/ZoneRequest in the package auro_interfaces.
typedef struct auro_interfaces__srv__ZoneRequest_Request
{
  rosidl_runtime_c__String robot_id;
  double x;
  double y;
  rosidl_runtime_c__String colour;
} auro_interfaces__srv__ZoneRequest_Request;

// Struct for a sequence of auro_interfaces__srv__ZoneRequest_Request.
typedef struct auro_interfaces__srv__ZoneRequest_Request__Sequence
{
  auro_interfaces__srv__ZoneRequest_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} auro_interfaces__srv__ZoneRequest_Request__Sequence;


// Constants defined in the message

/// Struct defined in srv/ZoneRequest in the package auro_interfaces.
typedef struct auro_interfaces__srv__ZoneRequest_Response
{
  double x;
  double y;
} auro_interfaces__srv__ZoneRequest_Response;

// Struct for a sequence of auro_interfaces__srv__ZoneRequest_Response.
typedef struct auro_interfaces__srv__ZoneRequest_Response__Sequence
{
  auro_interfaces__srv__ZoneRequest_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} auro_interfaces__srv__ZoneRequest_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // AURO_INTERFACES__SRV__DETAIL__ZONE_REQUEST__STRUCT_H_
