// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from auro_interfaces:srv/Collision.idl
// generated code does not contain a copyright notice
#include "auro_interfaces/srv/detail/collision__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"

bool
auro_interfaces__srv__Collision_Request__init(auro_interfaces__srv__Collision_Request * msg)
{
  if (!msg) {
    return false;
  }
  // structure_needs_at_least_one_member
  return true;
}

void
auro_interfaces__srv__Collision_Request__fini(auro_interfaces__srv__Collision_Request * msg)
{
  if (!msg) {
    return;
  }
  // structure_needs_at_least_one_member
}

bool
auro_interfaces__srv__Collision_Request__are_equal(const auro_interfaces__srv__Collision_Request * lhs, const auro_interfaces__srv__Collision_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // structure_needs_at_least_one_member
  if (lhs->structure_needs_at_least_one_member != rhs->structure_needs_at_least_one_member) {
    return false;
  }
  return true;
}

bool
auro_interfaces__srv__Collision_Request__copy(
  const auro_interfaces__srv__Collision_Request * input,
  auro_interfaces__srv__Collision_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // structure_needs_at_least_one_member
  output->structure_needs_at_least_one_member = input->structure_needs_at_least_one_member;
  return true;
}

auro_interfaces__srv__Collision_Request *
auro_interfaces__srv__Collision_Request__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  auro_interfaces__srv__Collision_Request * msg = (auro_interfaces__srv__Collision_Request *)allocator.allocate(sizeof(auro_interfaces__srv__Collision_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(auro_interfaces__srv__Collision_Request));
  bool success = auro_interfaces__srv__Collision_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
auro_interfaces__srv__Collision_Request__destroy(auro_interfaces__srv__Collision_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    auro_interfaces__srv__Collision_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
auro_interfaces__srv__Collision_Request__Sequence__init(auro_interfaces__srv__Collision_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  auro_interfaces__srv__Collision_Request * data = NULL;

  if (size) {
    data = (auro_interfaces__srv__Collision_Request *)allocator.zero_allocate(size, sizeof(auro_interfaces__srv__Collision_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = auro_interfaces__srv__Collision_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        auro_interfaces__srv__Collision_Request__fini(&data[i - 1]);
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
auro_interfaces__srv__Collision_Request__Sequence__fini(auro_interfaces__srv__Collision_Request__Sequence * array)
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
      auro_interfaces__srv__Collision_Request__fini(&array->data[i]);
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

auro_interfaces__srv__Collision_Request__Sequence *
auro_interfaces__srv__Collision_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  auro_interfaces__srv__Collision_Request__Sequence * array = (auro_interfaces__srv__Collision_Request__Sequence *)allocator.allocate(sizeof(auro_interfaces__srv__Collision_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = auro_interfaces__srv__Collision_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
auro_interfaces__srv__Collision_Request__Sequence__destroy(auro_interfaces__srv__Collision_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    auro_interfaces__srv__Collision_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
auro_interfaces__srv__Collision_Request__Sequence__are_equal(const auro_interfaces__srv__Collision_Request__Sequence * lhs, const auro_interfaces__srv__Collision_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!auro_interfaces__srv__Collision_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
auro_interfaces__srv__Collision_Request__Sequence__copy(
  const auro_interfaces__srv__Collision_Request__Sequence * input,
  auro_interfaces__srv__Collision_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(auro_interfaces__srv__Collision_Request);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    auro_interfaces__srv__Collision_Request * data =
      (auro_interfaces__srv__Collision_Request *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!auro_interfaces__srv__Collision_Request__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          auro_interfaces__srv__Collision_Request__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!auro_interfaces__srv__Collision_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `direction`
#include "rosidl_runtime_c/string_functions.h"

bool
auro_interfaces__srv__Collision_Response__init(auro_interfaces__srv__Collision_Response * msg)
{
  if (!msg) {
    return false;
  }
  // direction
  if (!rosidl_runtime_c__String__init(&msg->direction)) {
    auro_interfaces__srv__Collision_Response__fini(msg);
    return false;
  }
  // success
  return true;
}

void
auro_interfaces__srv__Collision_Response__fini(auro_interfaces__srv__Collision_Response * msg)
{
  if (!msg) {
    return;
  }
  // direction
  rosidl_runtime_c__String__fini(&msg->direction);
  // success
}

bool
auro_interfaces__srv__Collision_Response__are_equal(const auro_interfaces__srv__Collision_Response * lhs, const auro_interfaces__srv__Collision_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // direction
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->direction), &(rhs->direction)))
  {
    return false;
  }
  // success
  if (lhs->success != rhs->success) {
    return false;
  }
  return true;
}

bool
auro_interfaces__srv__Collision_Response__copy(
  const auro_interfaces__srv__Collision_Response * input,
  auro_interfaces__srv__Collision_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // direction
  if (!rosidl_runtime_c__String__copy(
      &(input->direction), &(output->direction)))
  {
    return false;
  }
  // success
  output->success = input->success;
  return true;
}

auro_interfaces__srv__Collision_Response *
auro_interfaces__srv__Collision_Response__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  auro_interfaces__srv__Collision_Response * msg = (auro_interfaces__srv__Collision_Response *)allocator.allocate(sizeof(auro_interfaces__srv__Collision_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(auro_interfaces__srv__Collision_Response));
  bool success = auro_interfaces__srv__Collision_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
auro_interfaces__srv__Collision_Response__destroy(auro_interfaces__srv__Collision_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    auro_interfaces__srv__Collision_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
auro_interfaces__srv__Collision_Response__Sequence__init(auro_interfaces__srv__Collision_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  auro_interfaces__srv__Collision_Response * data = NULL;

  if (size) {
    data = (auro_interfaces__srv__Collision_Response *)allocator.zero_allocate(size, sizeof(auro_interfaces__srv__Collision_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = auro_interfaces__srv__Collision_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        auro_interfaces__srv__Collision_Response__fini(&data[i - 1]);
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
auro_interfaces__srv__Collision_Response__Sequence__fini(auro_interfaces__srv__Collision_Response__Sequence * array)
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
      auro_interfaces__srv__Collision_Response__fini(&array->data[i]);
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

auro_interfaces__srv__Collision_Response__Sequence *
auro_interfaces__srv__Collision_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  auro_interfaces__srv__Collision_Response__Sequence * array = (auro_interfaces__srv__Collision_Response__Sequence *)allocator.allocate(sizeof(auro_interfaces__srv__Collision_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = auro_interfaces__srv__Collision_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
auro_interfaces__srv__Collision_Response__Sequence__destroy(auro_interfaces__srv__Collision_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    auro_interfaces__srv__Collision_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
auro_interfaces__srv__Collision_Response__Sequence__are_equal(const auro_interfaces__srv__Collision_Response__Sequence * lhs, const auro_interfaces__srv__Collision_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!auro_interfaces__srv__Collision_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
auro_interfaces__srv__Collision_Response__Sequence__copy(
  const auro_interfaces__srv__Collision_Response__Sequence * input,
  auro_interfaces__srv__Collision_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(auro_interfaces__srv__Collision_Response);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    auro_interfaces__srv__Collision_Response * data =
      (auro_interfaces__srv__Collision_Response *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!auro_interfaces__srv__Collision_Response__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          auro_interfaces__srv__Collision_Response__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!auro_interfaces__srv__Collision_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
