// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from auro_interfaces:srv/CheckGoal.idl
// generated code does not contain a copyright notice

#ifndef AURO_INTERFACES__SRV__DETAIL__CHECK_GOAL__STRUCT_H_
#define AURO_INTERFACES__SRV__DETAIL__CHECK_GOAL__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in srv/CheckGoal in the package auro_interfaces.
typedef struct auro_interfaces__srv__CheckGoal_Request
{
  double x;
  double y;
} auro_interfaces__srv__CheckGoal_Request;

// Struct for a sequence of auro_interfaces__srv__CheckGoal_Request.
typedef struct auro_interfaces__srv__CheckGoal_Request__Sequence
{
  auro_interfaces__srv__CheckGoal_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} auro_interfaces__srv__CheckGoal_Request__Sequence;


// Constants defined in the message

/// Struct defined in srv/CheckGoal in the package auro_interfaces.
typedef struct auro_interfaces__srv__CheckGoal_Response
{
  bool obstacle;
} auro_interfaces__srv__CheckGoal_Response;

// Struct for a sequence of auro_interfaces__srv__CheckGoal_Response.
typedef struct auro_interfaces__srv__CheckGoal_Response__Sequence
{
  auro_interfaces__srv__CheckGoal_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} auro_interfaces__srv__CheckGoal_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // AURO_INTERFACES__SRV__DETAIL__CHECK_GOAL__STRUCT_H_
