// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from auro_interfaces:srv/ZoneRequest.idl
// generated code does not contain a copyright notice
#include "auro_interfaces/srv/detail/zone_request__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"

// Include directives for member types
// Member `robot_id`
// Member `colour`
#include "rosidl_runtime_c/string_functions.h"

bool
auro_interfaces__srv__ZoneRequest_Request__init(auro_interfaces__srv__ZoneRequest_Request * msg)
{
  if (!msg) {
    return false;
  }
  // robot_id
  if (!rosidl_runtime_c__String__init(&msg->robot_id)) {
    auro_interfaces__srv__ZoneRequest_Request__fini(msg);
    return false;
  }
  // x
  // y
  // colour
  if (!rosidl_runtime_c__String__init(&msg->colour)) {
    auro_interfaces__srv__ZoneRequest_Request__fini(msg);
    return false;
  }
  return true;
}

void
auro_interfaces__srv__ZoneRequest_Request__fini(auro_interfaces__srv__ZoneRequest_Request * msg)
{
  if (!msg) {
    return;
  }
  // robot_id
  rosidl_runtime_c__String__fini(&msg->robot_id);
  // x
  // y
  // colour
  rosidl_runtime_c__String__fini(&msg->colour);
}

bool
auro_interfaces__srv__ZoneRequest_Request__are_equal(const auro_interfaces__srv__ZoneRequest_Request * lhs, const auro_interfaces__srv__ZoneRequest_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // robot_id
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->robot_id), &(rhs->robot_id)))
  {
    return false;
  }
  // x
  if (lhs->x != rhs->x) {
    return false;
  }
  // y
  if (lhs->y != rhs->y) {
    return false;
  }
  // colour
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->colour), &(rhs->colour)))
  {
    return false;
  }
  return true;
}

bool
auro_interfaces__srv__ZoneRequest_Request__copy(
  const auro_interfaces__srv__ZoneRequest_Request * input,
  auro_interfaces__srv__ZoneRequest_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // robot_id
  if (!rosidl_runtime_c__String__copy(
      &(input->robot_id), &(output->robot_id)))
  {
    return false;
  }
  // x
  output->x = input->x;
  // y
  output->y = input->y;
  // colour
  if (!rosidl_runtime_c__String__copy(
      &(input->colour), &(output->colour)))
  {
    return false;
  }
  return true;
}

auro_interfaces__srv__ZoneRequest_Request *
auro_interfaces__srv__ZoneRequest_Request__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  auro_interfaces__srv__ZoneRequest_Request * msg = (auro_interfaces__srv__ZoneRequest_Request *)allocator.allocate(sizeof(auro_interfaces__srv__ZoneRequest_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(auro_interfaces__srv__ZoneRequest_Request));
  bool success = auro_interfaces__srv__ZoneRequest_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
auro_interfaces__srv__ZoneRequest_Request__destroy(auro_interfaces__srv__ZoneRequest_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    auro_interfaces__srv__ZoneRequest_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
auro_interfaces__srv__ZoneRequest_Request__Sequence__init(auro_interfaces__srv__ZoneRequest_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  auro_interfaces__srv__ZoneRequest_Request * data = NULL;

  if (size) {
    data = (auro_interfaces__srv__ZoneRequest_Request *)allocator.zero_allocate(size, sizeof(auro_interfaces__srv__ZoneRequest_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = auro_interfaces__srv__ZoneRequest_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        auro_interfaces__srv__ZoneRequest_Request__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
auro_interfaces__srv__ZoneRequest_Request__Sequence__fini(auro_interfaces__srv__ZoneRequest_Request__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      auro_interfaces__srv__ZoneRequest_Request__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

auro_interfaces__srv__ZoneRequest_Request__Sequence *
auro_interfaces__srv__ZoneRequest_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  auro_interfaces__srv__ZoneRequest_Request__Sequence * array = (auro_interfaces__srv__ZoneRequest_Request__Sequence *)allocator.allocate(sizeof(auro_interfaces__srv__ZoneRequest_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = auro_interfaces__srv__ZoneRequest_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
auro_interfaces__srv__ZoneRequest_Request__Sequence__destroy(auro_interfaces__srv__ZoneRequest_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    auro_interfaces__srv__ZoneRequest_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
auro_interfaces__srv__ZoneRequest_Request__Sequence__are_equal(const auro_interfaces__srv__ZoneRequest_Request__Sequence * lhs, const auro_interfaces__srv__ZoneRequest_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!auro_interfaces__srv__ZoneRequest_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
auro_interfaces__srv__ZoneRequest_Request__Sequence__copy(
  const auro_interfaces__srv__ZoneRequest_Request__Sequence * input,
  auro_interfaces__srv__ZoneRequest_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(auro_interfaces__srv__ZoneRequest_Request);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    auro_interfaces__srv__ZoneRequest_Request * data =
      (auro_interfaces__srv__ZoneRequest_Request *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!auro_interfaces__srv__ZoneRequest_Request__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          auro_interfaces__srv__ZoneRequest_Request__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!auro_interfaces__srv__ZoneRequest_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


bool
auro_interfaces__srv__ZoneRequest_Response__init(auro_interfaces__srv__ZoneRequest_Response * msg)
{
  if (!msg) {
    return false;
  }
  // x
  // y
  return true;
}

void
auro_interfaces__srv__ZoneRequest_Response__fini(auro_interfaces__srv__ZoneRequest_Response * msg)
{
  if (!msg) {
    return;
  }
  // x
  // y
}

bool
auro_interfaces__srv__ZoneRequest_Response__are_equal(const auro_interfaces__srv__ZoneRequest_Response * lhs, const auro_interfaces__srv__ZoneRequest_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // x
  if (lhs->x != rhs->x) {
    return false;
  }
  // y
  if (lhs->y != rhs->y) {
    return false;
  }
  return true;
}

bool
auro_interfaces__srv__ZoneRequest_Response__copy(
  const auro_interfaces__srv__ZoneRequest_Response * input,
  auro_interfaces__srv__ZoneRequest_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // x
  output->x = input->x;
  // y
  output->y = input->y;
  return true;
}

auro_interfaces__srv__ZoneRequest_Response *
auro_interfaces__srv__ZoneRequest_Response__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  auro_interfaces__srv__ZoneRequest_Response * msg = (auro_interfaces__srv__ZoneRequest_Response *)allocator.allocate(sizeof(auro_interfaces__srv__ZoneRequest_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(auro_interfaces__srv__ZoneRequest_Response));
  bool success = auro_interfaces__srv__ZoneRequest_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
auro_interfaces__srv__ZoneRequest_Response__destroy(auro_interfaces__srv__ZoneRequest_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    auro_interfaces__srv__ZoneRequest_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
auro_interfaces__srv__ZoneRequest_Response__Sequence__init(auro_interfaces__srv__ZoneRequest_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  auro_interfaces__srv__ZoneRequest_Response * data = NULL;

  if (size) {
    data = (auro_interfaces__srv__ZoneRequest_Response *)allocator.zero_allocate(size, sizeof(auro_interfaces__srv__ZoneRequest_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = auro_interfaces__srv__ZoneRequest_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        auro_interfaces__srv__ZoneRequest_Response__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
auro_interfaces__srv__ZoneRequest_Response__Sequence__fini(auro_interfaces__srv__ZoneRequest_Response__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      auro_interfaces__srv__ZoneRequest_Response__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

auro_interfaces__srv__ZoneRequest_Response__Sequence *
auro_interfaces__srv__ZoneRequest_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  auro_interfaces__srv__ZoneRequest_Response__Sequence * array = (auro_interfaces__srv__ZoneRequest_Response__Sequence *)allocator.allocate(sizeof(auro_interfaces__srv__ZoneRequest_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = auro_interfaces__srv__ZoneRequest_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
auro_interfaces__srv__ZoneRequest_Response__Sequence__destroy(auro_interfaces__srv__ZoneRequest_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    auro_interfaces__srv__ZoneRequest_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
auro_interfaces__srv__ZoneRequest_Response__Sequence__are_equal(const auro_interfaces__srv__ZoneRequest_Response__Sequence * lhs, const auro_interfaces__srv__ZoneRequest_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!auro_interfaces__srv__ZoneRequest_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
auro_interfaces__srv__ZoneRequest_Response__Sequence__copy(
  const auro_interfaces__srv__ZoneRequest_Response__Sequence * input,
  auro_interfaces__srv__ZoneRequest_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(auro_interfaces__srv__ZoneRequest_Response);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    auro_interfaces__srv__ZoneRequest_Response * data =
      (auro_interfaces__srv__ZoneRequest_Response *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!auro_interfaces__srv__ZoneRequest_Response__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          auro_interfaces__srv__ZoneRequest_Response__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!auro_interfaces__srv__ZoneRequest_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
