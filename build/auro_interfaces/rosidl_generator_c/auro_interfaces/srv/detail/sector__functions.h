// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from auro_interfaces:srv/Sector.idl
// generated code does not contain a copyright notice

#ifndef AURO_INTERFACES__SRV__DETAIL__SECTOR__FUNCTIONS_H_
#define AURO_INTERFACES__SRV__DETAIL__SECTOR__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "auro_interfaces/msg/rosidl_generator_c__visibility_control.h"

#include "auro_interfaces/srv/detail/sector__struct.h"

/// Initialize srv/Sector message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * auro_interfaces__srv__Sector_Request
 * )) before or use
 * auro_interfaces__srv__Sector_Request__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_auro_interfaces
bool
auro_interfaces__srv__Sector_Request__init(auro_interfaces__srv__Sector_Request * msg);

/// Finalize srv/Sector message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_auro_interfaces
void
auro_interfaces__srv__Sector_Request__fini(auro_interfaces__srv__Sector_Request * msg);

/// Create srv/Sector message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * auro_interfaces__srv__Sector_Request__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_auro_interfaces
auro_interfaces__srv__Sector_Request *
auro_interfaces__srv__Sector_Request__create();

/// Destroy srv/Sector message.
/**
 * It calls
 * auro_interfaces__srv__Sector_Request__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_auro_interfaces
void
auro_interfaces__srv__Sector_Request__destroy(auro_interfaces__srv__Sector_Request * msg);

/// Check for srv/Sector message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_auro_interfaces
bool
auro_interfaces__srv__Sector_Request__are_equal(const auro_interfaces__srv__Sector_Request * lhs, const auro_interfaces__srv__Sector_Request * rhs);

/// Copy a srv/Sector message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_auro_interfaces
bool
auro_interfaces__srv__Sector_Request__copy(
  const auro_interfaces__srv__Sector_Request * input,
  auro_interfaces__srv__Sector_Request * output);

/// Initialize array of srv/Sector messages.
/**
 * It allocates the memory for the number of elements and calls
 * auro_interfaces__srv__Sector_Request__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_auro_interfaces
bool
auro_interfaces__srv__Sector_Request__Sequence__init(auro_interfaces__srv__Sector_Request__Sequence * array, size_t size);

/// Finalize array of srv/Sector messages.
/**
 * It calls
 * auro_interfaces__srv__Sector_Request__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_auro_interfaces
void
auro_interfaces__srv__Sector_Request__Sequence__fini(auro_interfaces__srv__Sector_Request__Sequence * array);

/// Create array of srv/Sector messages.
/**
 * It allocates the memory for the array and calls
 * auro_interfaces__srv__Sector_Request__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_auro_interfaces
auro_interfaces__srv__Sector_Request__Sequence *
auro_interfaces__srv__Sector_Request__Sequence__create(size_t size);

/// Destroy array of srv/Sector messages.
/**
 * It calls
 * auro_interfaces__srv__Sector_Request__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_auro_interfaces
void
auro_interfaces__srv__Sector_Request__Sequence__destroy(auro_interfaces__srv__Sector_Request__Sequence * array);

/// Check for srv/Sector message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_auro_interfaces
bool
auro_interfaces__srv__Sector_Request__Sequence__are_equal(const auro_interfaces__srv__Sector_Request__Sequence * lhs, const auro_interfaces__srv__Sector_Request__Sequence * rhs);

/// Copy an array of srv/Sector messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_auro_interfaces
bool
auro_interfaces__srv__Sector_Request__Sequence__copy(
  const auro_interfaces__srv__Sector_Request__Sequence * input,
  auro_interfaces__srv__Sector_Request__Sequence * output);

/// Initialize srv/Sector message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * auro_interfaces__srv__Sector_Response
 * )) before or use
 * auro_interfaces__srv__Sector_Response__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_auro_interfaces
bool
auro_interfaces__srv__Sector_Response__init(auro_interfaces__srv__Sector_Response * msg);

/// Finalize srv/Sector message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_auro_interfaces
void
auro_interfaces__srv__Sector_Response__fini(auro_interfaces__srv__Sector_Response * msg);

/// Create srv/Sector message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * auro_interfaces__srv__Sector_Response__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_auro_interfaces
auro_interfaces__srv__Sector_Response *
auro_interfaces__srv__Sector_Response__create();

/// Destroy srv/Sector message.
/**
 * It calls
 * auro_interfaces__srv__Sector_Response__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_auro_interfaces
void
auro_interfaces__srv__Sector_Response__destroy(auro_interfaces__srv__Sector_Response * msg);

/// Check for srv/Sector message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_auro_interfaces
bool
auro_interfaces__srv__Sector_Response__are_equal(const auro_interfaces__srv__Sector_Response * lhs, const auro_interfaces__srv__Sector_Response * rhs);

/// Copy a srv/Sector message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_auro_interfaces
bool
auro_interfaces__srv__Sector_Response__copy(
  const auro_interfaces__srv__Sector_Response * input,
  auro_interfaces__srv__Sector_Response * output);

/// Initialize array of srv/Sector messages.
/**
 * It allocates the memory for the number of elements and calls
 * auro_interfaces__srv__Sector_Response__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_auro_interfaces
bool
auro_interfaces__srv__Sector_Response__Sequence__init(auro_interfaces__srv__Sector_Response__Sequence * array, size_t size);

/// Finalize array of srv/Sector messages.
/**
 * It calls
 * auro_interfaces__srv__Sector_Response__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_auro_interfaces
void
auro_interfaces__srv__Sector_Response__Sequence__fini(auro_interfaces__srv__Sector_Response__Sequence * array);

/// Create array of srv/Sector messages.
/**
 * It allocates the memory for the array and calls
 * auro_interfaces__srv__Sector_Response__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_auro_interfaces
auro_interfaces__srv__Sector_Response__Sequence *
auro_interfaces__srv__Sector_Response__Sequence__create(size_t size);

/// Destroy array of srv/Sector messages.
/**
 * It calls
 * auro_interfaces__srv__Sector_Response__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_auro_interfaces
void
auro_interfaces__srv__Sector_Response__Sequence__destroy(auro_interfaces__srv__Sector_Response__Sequence * array);

/// Check for srv/Sector message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_auro_interfaces
bool
auro_interfaces__srv__Sector_Response__Sequence__are_equal(const auro_interfaces__srv__Sector_Response__Sequence * lhs, const auro_interfaces__srv__Sector_Response__Sequence * rhs);

/// Copy an array of srv/Sector messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_auro_interfaces
bool
auro_interfaces__srv__Sector_Response__Sequence__copy(
  const auro_interfaces__srv__Sector_Response__Sequence * input,
  auro_interfaces__srv__Sector_Response__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // AURO_INTERFACES__SRV__DETAIL__SECTOR__FUNCTIONS_H_
