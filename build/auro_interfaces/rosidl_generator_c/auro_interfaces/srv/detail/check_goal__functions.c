// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from auro_interfaces:srv/CheckGoal.idl
// generated code does not contain a copyright notice
#include "auro_interfaces/srv/detail/check_goal__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"

bool
auro_interfaces__srv__CheckGoal_Request__init(auro_interfaces__srv__CheckGoal_Request * msg)
{
  if (!msg) {
    return false;
  }
  // x
  // y
  return true;
}

void
auro_interfaces__srv__CheckGoal_Request__fini(auro_interfaces__srv__CheckGoal_Request * msg)
{
  if (!msg) {
    return;
  }
  // x
  // y
}

bool
auro_interfaces__srv__CheckGoal_Request__are_equal(const auro_interfaces__srv__CheckGoal_Request * lhs, const auro_interfaces__srv__CheckGoal_Request * rhs)
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
auro_interfaces__srv__CheckGoal_Request__copy(
  const auro_interfaces__srv__CheckGoal_Request * input,
  auro_interfaces__srv__CheckGoal_Request * output)
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

auro_interfaces__srv__CheckGoal_Request *
auro_interfaces__srv__CheckGoal_Request__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  auro_interfaces__srv__CheckGoal_Request * msg = (auro_interfaces__srv__CheckGoal_Request *)allocator.allocate(sizeof(auro_interfaces__srv__CheckGoal_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(auro_interfaces__srv__CheckGoal_Request));
  bool success = auro_interfaces__srv__CheckGoal_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
auro_interfaces__srv__CheckGoal_Request__destroy(auro_interfaces__srv__CheckGoal_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    auro_interfaces__srv__CheckGoal_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
auro_interfaces__srv__CheckGoal_Request__Sequence__init(auro_interfaces__srv__CheckGoal_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  auro_interfaces__srv__CheckGoal_Request * data = NULL;

  if (size) {
    data = (auro_interfaces__srv__CheckGoal_Request *)allocator.zero_allocate(size, sizeof(auro_interfaces__srv__CheckGoal_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = auro_interfaces__srv__CheckGoal_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        auro_interfaces__srv__CheckGoal_Request__fini(&data[i - 1]);
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
auro_interfaces__srv__CheckGoal_Request__Sequence__fini(auro_interfaces__srv__CheckGoal_Request__Sequence * array)
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
      auro_interfaces__srv__CheckGoal_Request__fini(&array->data[i]);
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

auro_interfaces__srv__CheckGoal_Request__Sequence *
auro_interfaces__srv__CheckGoal_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  auro_interfaces__srv__CheckGoal_Request__Sequence * array = (auro_interfaces__srv__CheckGoal_Request__Sequence *)allocator.allocate(sizeof(auro_interfaces__srv__CheckGoal_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = auro_interfaces__srv__CheckGoal_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
auro_interfaces__srv__CheckGoal_Request__Sequence__destroy(auro_interfaces__srv__CheckGoal_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    auro_interfaces__srv__CheckGoal_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
auro_interfaces__srv__CheckGoal_Request__Sequence__are_equal(const auro_interfaces__srv__CheckGoal_Request__Sequence * lhs, const auro_interfaces__srv__CheckGoal_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!auro_interfaces__srv__CheckGoal_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
auro_interfaces__srv__CheckGoal_Request__Sequence__copy(
  const auro_interfaces__srv__CheckGoal_Request__Sequence * input,
  auro_interfaces__srv__CheckGoal_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(auro_interfaces__srv__CheckGoal_Request);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    auro_interfaces__srv__CheckGoal_Request * data =
      (auro_interfaces__srv__CheckGoal_Request *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!auro_interfaces__srv__CheckGoal_Request__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          auro_interfaces__srv__CheckGoal_Request__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!auro_interfaces__srv__CheckGoal_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


bool
auro_interfaces__srv__CheckGoal_Response__init(auro_interfaces__srv__CheckGoal_Response * msg)
{
  if (!msg) {
    return false;
  }
  // obstacle
  return true;
}

void
auro_interfaces__srv__CheckGoal_Response__fini(auro_interfaces__srv__CheckGoal_Response * msg)
{
  if (!msg) {
    return;
  }
  // obstacle
}

bool
auro_interfaces__srv__CheckGoal_Response__are_equal(const auro_interfaces__srv__CheckGoal_Response * lhs, const auro_interfaces__srv__CheckGoal_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // obstacle
  if (lhs->obstacle != rhs->obstacle) {
    return false;
  }
  return true;
}

bool
auro_interfaces__srv__CheckGoal_Response__copy(
  const auro_interfaces__srv__CheckGoal_Response * input,
  auro_interfaces__srv__CheckGoal_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // obstacle
  output->obstacle = input->obstacle;
  return true;
}

auro_interfaces__srv__CheckGoal_Response *
auro_interfaces__srv__CheckGoal_Response__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  auro_interfaces__srv__CheckGoal_Response * msg = (auro_interfaces__srv__CheckGoal_Response *)allocator.allocate(sizeof(auro_interfaces__srv__CheckGoal_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(auro_interfaces__srv__CheckGoal_Response));
  bool success = auro_interfaces__srv__CheckGoal_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
auro_interfaces__srv__CheckGoal_Response__destroy(auro_interfaces__srv__CheckGoal_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    auro_interfaces__srv__CheckGoal_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
auro_interfaces__srv__CheckGoal_Response__Sequence__init(auro_interfaces__srv__CheckGoal_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  auro_interfaces__srv__CheckGoal_Response * data = NULL;

  if (size) {
    data = (auro_interfaces__srv__CheckGoal_Response *)allocator.zero_allocate(size, sizeof(auro_interfaces__srv__CheckGoal_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = auro_interfaces__srv__CheckGoal_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        auro_interfaces__srv__CheckGoal_Response__fini(&data[i - 1]);
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
auro_interfaces__srv__CheckGoal_Response__Sequence__fini(auro_interfaces__srv__CheckGoal_Response__Sequence * array)
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
      auro_interfaces__srv__CheckGoal_Response__fini(&array->data[i]);
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

auro_interfaces__srv__CheckGoal_Response__Sequence *
auro_interfaces__srv__CheckGoal_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  auro_interfaces__srv__CheckGoal_Response__Sequence * array = (auro_interfaces__srv__CheckGoal_Response__Sequence *)allocator.allocate(sizeof(auro_interfaces__srv__CheckGoal_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = auro_interfaces__srv__CheckGoal_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
auro_interfaces__srv__CheckGoal_Response__Sequence__destroy(auro_interfaces__srv__CheckGoal_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    auro_interfaces__srv__CheckGoal_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
auro_interfaces__srv__CheckGoal_Response__Sequence__are_equal(const auro_interfaces__srv__CheckGoal_Response__Sequence * lhs, const auro_interfaces__srv__CheckGoal_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!auro_interfaces__srv__CheckGoal_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
auro_interfaces__srv__CheckGoal_Response__Sequence__copy(
  const auro_interfaces__srv__CheckGoal_Response__Sequence * input,
  auro_interfaces__srv__CheckGoal_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(auro_interfaces__srv__CheckGoal_Response);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    auro_interfaces__srv__CheckGoal_Response * data =
      (auro_interfaces__srv__CheckGoal_Response *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!auro_interfaces__srv__CheckGoal_Response__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          auro_interfaces__srv__CheckGoal_Response__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!auro_interfaces__srv__CheckGoal_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
