// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from auro_interfaces:action/Move.idl
// generated code does not contain a copyright notice

#ifndef AURO_INTERFACES__ACTION__DETAIL__MOVE__FUNCTIONS_H_
#define AURO_INTERFACES__ACTION__DETAIL__MOVE__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "auro_interfaces/msg/rosidl_generator_c__visibility_control.h"

#include "auro_interfaces/action/detail/move__struct.h"

/// Initialize action/Move message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * auro_interfaces__action__Move_Goal
 * )) before or use
 * auro_interfaces__action__Move_Goal__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_auro_interfaces
bool
auro_interfaces__action__Move_Goal__init(auro_interfaces__action__Move_Goal * msg);

/// Finalize action/Move message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_auro_interfaces
void
auro_interfaces__action__Move_Goal__fini(auro_interfaces__action__Move_Goal * msg);

/// Create action/Move message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * auro_interfaces__action__Move_Goal__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_auro_interfaces
auro_interfaces__action__Move_Goal *
auro_interfaces__action__Move_Goal__create();

/// Destroy action/Move message.
/**
 * It calls
 * auro_interfaces__action__Move_Goal__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_auro_interfaces
void
auro_interfaces__action__Move_Goal__destroy(auro_interfaces__action__Move_Goal * msg);

/// Check for action/Move message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_auro_interfaces
bool
auro_interfaces__action__Move_Goal__are_equal(const auro_interfaces__action__Move_Goal * lhs, const auro_interfaces__action__Move_Goal * rhs);

/// Copy a action/Move message.
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
auro_interfaces__action__Move_Goal__copy(
  const auro_interfaces__action__Move_Goal * input,
  auro_interfaces__action__Move_Goal * output);

/// Initialize array of action/Move messages.
/**
 * It allocates the memory for the number of elements and calls
 * auro_interfaces__action__Move_Goal__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_auro_interfaces
bool
auro_interfaces__action__Move_Goal__Sequence__init(auro_interfaces__action__Move_Goal__Sequence * array, size_t size);

/// Finalize array of action/Move messages.
/**
 * It calls
 * auro_interfaces__action__Move_Goal__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_auro_interfaces
void
auro_interfaces__action__Move_Goal__Sequence__fini(auro_interfaces__action__Move_Goal__Sequence * array);

/// Create array of action/Move messages.
/**
 * It allocates the memory for the array and calls
 * auro_interfaces__action__Move_Goal__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_auro_interfaces
auro_interfaces__action__Move_Goal__Sequence *
auro_interfaces__action__Move_Goal__Sequence__create(size_t size);

/// Destroy array of action/Move messages.
/**
 * It calls
 * auro_interfaces__action__Move_Goal__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_auro_interfaces
void
auro_interfaces__action__Move_Goal__Sequence__destroy(auro_interfaces__action__Move_Goal__Sequence * array);

/// Check for action/Move message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_auro_interfaces
bool
auro_interfaces__action__Move_Goal__Sequence__are_equal(const auro_interfaces__action__Move_Goal__Sequence * lhs, const auro_interfaces__action__Move_Goal__Sequence * rhs);

/// Copy an array of action/Move messages.
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
auro_interfaces__action__Move_Goal__Sequence__copy(
  const auro_interfaces__action__Move_Goal__Sequence * input,
  auro_interfaces__action__Move_Goal__Sequence * output);

/// Initialize action/Move message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * auro_interfaces__action__Move_Result
 * )) before or use
 * auro_interfaces__action__Move_Result__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_auro_interfaces
bool
auro_interfaces__action__Move_Result__init(auro_interfaces__action__Move_Result * msg);

/// Finalize action/Move message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_auro_interfaces
void
auro_interfaces__action__Move_Result__fini(auro_interfaces__action__Move_Result * msg);

/// Create action/Move message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * auro_interfaces__action__Move_Result__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_auro_interfaces
auro_interfaces__action__Move_Result *
auro_interfaces__action__Move_Result__create();

/// Destroy action/Move message.
/**
 * It calls
 * auro_interfaces__action__Move_Result__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_auro_interfaces
void
auro_interfaces__action__Move_Result__destroy(auro_interfaces__action__Move_Result * msg);

/// Check for action/Move message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_auro_interfaces
bool
auro_interfaces__action__Move_Result__are_equal(const auro_interfaces__action__Move_Result * lhs, const auro_interfaces__action__Move_Result * rhs);

/// Copy a action/Move message.
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
auro_interfaces__action__Move_Result__copy(
  const auro_interfaces__action__Move_Result * input,
  auro_interfaces__action__Move_Result * output);

/// Initialize array of action/Move messages.
/**
 * It allocates the memory for the number of elements and calls
 * auro_interfaces__action__Move_Result__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_auro_interfaces
bool
auro_interfaces__action__Move_Result__Sequence__init(auro_interfaces__action__Move_Result__Sequence * array, size_t size);

/// Finalize array of action/Move messages.
/**
 * It calls
 * auro_interfaces__action__Move_Result__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_auro_interfaces
void
auro_interfaces__action__Move_Result__Sequence__fini(auro_interfaces__action__Move_Result__Sequence * array);

/// Create array of action/Move messages.
/**
 * It allocates the memory for the array and calls
 * auro_interfaces__action__Move_Result__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_auro_interfaces
auro_interfaces__action__Move_Result__Sequence *
auro_interfaces__action__Move_Result__Sequence__create(size_t size);

/// Destroy array of action/Move messages.
/**
 * It calls
 * auro_interfaces__action__Move_Result__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_auro_interfaces
void
auro_interfaces__action__Move_Result__Sequence__destroy(auro_interfaces__action__Move_Result__Sequence * array);

/// Check for action/Move message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_auro_interfaces
bool
auro_interfaces__action__Move_Result__Sequence__are_equal(const auro_interfaces__action__Move_Result__Sequence * lhs, const auro_interfaces__action__Move_Result__Sequence * rhs);

/// Copy an array of action/Move messages.
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
auro_interfaces__action__Move_Result__Sequence__copy(
  const auro_interfaces__action__Move_Result__Sequence * input,
  auro_interfaces__action__Move_Result__Sequence * output);

/// Initialize action/Move message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * auro_interfaces__action__Move_Feedback
 * )) before or use
 * auro_interfaces__action__Move_Feedback__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_auro_interfaces
bool
auro_interfaces__action__Move_Feedback__init(auro_interfaces__action__Move_Feedback * msg);

/// Finalize action/Move message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_auro_interfaces
void
auro_interfaces__action__Move_Feedback__fini(auro_interfaces__action__Move_Feedback * msg);

/// Create action/Move message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * auro_interfaces__action__Move_Feedback__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_auro_interfaces
auro_interfaces__action__Move_Feedback *
auro_interfaces__action__Move_Feedback__create();

/// Destroy action/Move message.
/**
 * It calls
 * auro_interfaces__action__Move_Feedback__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_auro_interfaces
void
auro_interfaces__action__Move_Feedback__destroy(auro_interfaces__action__Move_Feedback * msg);

/// Check for action/Move message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_auro_interfaces
bool
auro_interfaces__action__Move_Feedback__are_equal(const auro_interfaces__action__Move_Feedback * lhs, const auro_interfaces__action__Move_Feedback * rhs);

/// Copy a action/Move message.
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
auro_interfaces__action__Move_Feedback__copy(
  const auro_interfaces__action__Move_Feedback * input,
  auro_interfaces__action__Move_Feedback * output);

/// Initialize array of action/Move messages.
/**
 * It allocates the memory for the number of elements and calls
 * auro_interfaces__action__Move_Feedback__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_auro_interfaces
bool
auro_interfaces__action__Move_Feedback__Sequence__init(auro_interfaces__action__Move_Feedback__Sequence * array, size_t size);

/// Finalize array of action/Move messages.
/**
 * It calls
 * auro_interfaces__action__Move_Feedback__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_auro_interfaces
void
auro_interfaces__action__Move_Feedback__Sequence__fini(auro_interfaces__action__Move_Feedback__Sequence * array);

/// Create array of action/Move messages.
/**
 * It allocates the memory for the array and calls
 * auro_interfaces__action__Move_Feedback__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_auro_interfaces
auro_interfaces__action__Move_Feedback__Sequence *
auro_interfaces__action__Move_Feedback__Sequence__create(size_t size);

/// Destroy array of action/Move messages.
/**
 * It calls
 * auro_interfaces__action__Move_Feedback__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_auro_interfaces
void
auro_interfaces__action__Move_Feedback__Sequence__destroy(auro_interfaces__action__Move_Feedback__Sequence * array);

/// Check for action/Move message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_auro_interfaces
bool
auro_interfaces__action__Move_Feedback__Sequence__are_equal(const auro_interfaces__action__Move_Feedback__Sequence * lhs, const auro_interfaces__action__Move_Feedback__Sequence * rhs);

/// Copy an array of action/Move messages.
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
auro_interfaces__action__Move_Feedback__Sequence__copy(
  const auro_interfaces__action__Move_Feedback__Sequence * input,
  auro_interfaces__action__Move_Feedback__Sequence * output);

/// Initialize action/Move message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * auro_interfaces__action__Move_SendGoal_Request
 * )) before or use
 * auro_interfaces__action__Move_SendGoal_Request__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_auro_interfaces
bool
auro_interfaces__action__Move_SendGoal_Request__init(auro_interfaces__action__Move_SendGoal_Request * msg);

/// Finalize action/Move message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_auro_interfaces
void
auro_interfaces__action__Move_SendGoal_Request__fini(auro_interfaces__action__Move_SendGoal_Request * msg);

/// Create action/Move message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * auro_interfaces__action__Move_SendGoal_Request__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_auro_interfaces
auro_interfaces__action__Move_SendGoal_Request *
auro_interfaces__action__Move_SendGoal_Request__create();

/// Destroy action/Move message.
/**
 * It calls
 * auro_interfaces__action__Move_SendGoal_Request__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_auro_interfaces
void
auro_interfaces__action__Move_SendGoal_Request__destroy(auro_interfaces__action__Move_SendGoal_Request * msg);

/// Check for action/Move message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_auro_interfaces
bool
auro_interfaces__action__Move_SendGoal_Request__are_equal(const auro_interfaces__action__Move_SendGoal_Request * lhs, const auro_interfaces__action__Move_SendGoal_Request * rhs);

/// Copy a action/Move message.
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
auro_interfaces__action__Move_SendGoal_Request__copy(
  const auro_interfaces__action__Move_SendGoal_Request * input,
  auro_interfaces__action__Move_SendGoal_Request * output);

/// Initialize array of action/Move messages.
/**
 * It allocates the memory for the number of elements and calls
 * auro_interfaces__action__Move_SendGoal_Request__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_auro_interfaces
bool
auro_interfaces__action__Move_SendGoal_Request__Sequence__init(auro_interfaces__action__Move_SendGoal_Request__Sequence * array, size_t size);

/// Finalize array of action/Move messages.
/**
 * It calls
 * auro_interfaces__action__Move_SendGoal_Request__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_auro_interfaces
void
auro_interfaces__action__Move_SendGoal_Request__Sequence__fini(auro_interfaces__action__Move_SendGoal_Request__Sequence * array);

/// Create array of action/Move messages.
/**
 * It allocates the memory for the array and calls
 * auro_interfaces__action__Move_SendGoal_Request__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_auro_interfaces
auro_interfaces__action__Move_SendGoal_Request__Sequence *
auro_interfaces__action__Move_SendGoal_Request__Sequence__create(size_t size);

/// Destroy array of action/Move messages.
/**
 * It calls
 * auro_interfaces__action__Move_SendGoal_Request__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_auro_interfaces
void
auro_interfaces__action__Move_SendGoal_Request__Sequence__destroy(auro_interfaces__action__Move_SendGoal_Request__Sequence * array);

/// Check for action/Move message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_auro_interfaces
bool
auro_interfaces__action__Move_SendGoal_Request__Sequence__are_equal(const auro_interfaces__action__Move_SendGoal_Request__Sequence * lhs, const auro_interfaces__action__Move_SendGoal_Request__Sequence * rhs);

/// Copy an array of action/Move messages.
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
auro_interfaces__action__Move_SendGoal_Request__Sequence__copy(
  const auro_interfaces__action__Move_SendGoal_Request__Sequence * input,
  auro_interfaces__action__Move_SendGoal_Request__Sequence * output);

/// Initialize action/Move message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * auro_interfaces__action__Move_SendGoal_Response
 * )) before or use
 * auro_interfaces__action__Move_SendGoal_Response__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_auro_interfaces
bool
auro_interfaces__action__Move_SendGoal_Response__init(auro_interfaces__action__Move_SendGoal_Response * msg);

/// Finalize action/Move message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_auro_interfaces
void
auro_interfaces__action__Move_SendGoal_Response__fini(auro_interfaces__action__Move_SendGoal_Response * msg);

/// Create action/Move message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * auro_interfaces__action__Move_SendGoal_Response__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_auro_interfaces
auro_interfaces__action__Move_SendGoal_Response *
auro_interfaces__action__Move_SendGoal_Response__create();

/// Destroy action/Move message.
/**
 * It calls
 * auro_interfaces__action__Move_SendGoal_Response__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_auro_interfaces
void
auro_interfaces__action__Move_SendGoal_Response__destroy(auro_interfaces__action__Move_SendGoal_Response * msg);

/// Check for action/Move message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_auro_interfaces
bool
auro_interfaces__action__Move_SendGoal_Response__are_equal(const auro_interfaces__action__Move_SendGoal_Response * lhs, const auro_interfaces__action__Move_SendGoal_Response * rhs);

/// Copy a action/Move message.
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
auro_interfaces__action__Move_SendGoal_Response__copy(
  const auro_interfaces__action__Move_SendGoal_Response * input,
  auro_interfaces__action__Move_SendGoal_Response * output);

/// Initialize array of action/Move messages.
/**
 * It allocates the memory for the number of elements and calls
 * auro_interfaces__action__Move_SendGoal_Response__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_auro_interfaces
bool
auro_interfaces__action__Move_SendGoal_Response__Sequence__init(auro_interfaces__action__Move_SendGoal_Response__Sequence * array, size_t size);

/// Finalize array of action/Move messages.
/**
 * It calls
 * auro_interfaces__action__Move_SendGoal_Response__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_auro_interfaces
void
auro_interfaces__action__Move_SendGoal_Response__Sequence__fini(auro_interfaces__action__Move_SendGoal_Response__Sequence * array);

/// Create array of action/Move messages.
/**
 * It allocates the memory for the array and calls
 * auro_interfaces__action__Move_SendGoal_Response__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_auro_interfaces
auro_interfaces__action__Move_SendGoal_Response__Sequence *
auro_interfaces__action__Move_SendGoal_Response__Sequence__create(size_t size);

/// Destroy array of action/Move messages.
/**
 * It calls
 * auro_interfaces__action__Move_SendGoal_Response__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_auro_interfaces
void
auro_interfaces__action__Move_SendGoal_Response__Sequence__destroy(auro_interfaces__action__Move_SendGoal_Response__Sequence * array);

/// Check for action/Move message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_auro_interfaces
bool
auro_interfaces__action__Move_SendGoal_Response__Sequence__are_equal(const auro_interfaces__action__Move_SendGoal_Response__Sequence * lhs, const auro_interfaces__action__Move_SendGoal_Response__Sequence * rhs);

/// Copy an array of action/Move messages.
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
auro_interfaces__action__Move_SendGoal_Response__Sequence__copy(
  const auro_interfaces__action__Move_SendGoal_Response__Sequence * input,
  auro_interfaces__action__Move_SendGoal_Response__Sequence * output);

/// Initialize action/Move message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * auro_interfaces__action__Move_GetResult_Request
 * )) before or use
 * auro_interfaces__action__Move_GetResult_Request__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_auro_interfaces
bool
auro_interfaces__action__Move_GetResult_Request__init(auro_interfaces__action__Move_GetResult_Request * msg);

/// Finalize action/Move message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_auro_interfaces
void
auro_interfaces__action__Move_GetResult_Request__fini(auro_interfaces__action__Move_GetResult_Request * msg);

/// Create action/Move message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * auro_interfaces__action__Move_GetResult_Request__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_auro_interfaces
auro_interfaces__action__Move_GetResult_Request *
auro_interfaces__action__Move_GetResult_Request__create();

/// Destroy action/Move message.
/**
 * It calls
 * auro_interfaces__action__Move_GetResult_Request__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_auro_interfaces
void
auro_interfaces__action__Move_GetResult_Request__destroy(auro_interfaces__action__Move_GetResult_Request * msg);

/// Check for action/Move message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_auro_interfaces
bool
auro_interfaces__action__Move_GetResult_Request__are_equal(const auro_interfaces__action__Move_GetResult_Request * lhs, const auro_interfaces__action__Move_GetResult_Request * rhs);

/// Copy a action/Move message.
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
auro_interfaces__action__Move_GetResult_Request__copy(
  const auro_interfaces__action__Move_GetResult_Request * input,
  auro_interfaces__action__Move_GetResult_Request * output);

/// Initialize array of action/Move messages.
/**
 * It allocates the memory for the number of elements and calls
 * auro_interfaces__action__Move_GetResult_Request__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_auro_interfaces
bool
auro_interfaces__action__Move_GetResult_Request__Sequence__init(auro_interfaces__action__Move_GetResult_Request__Sequence * array, size_t size);

/// Finalize array of action/Move messages.
/**
 * It calls
 * auro_interfaces__action__Move_GetResult_Request__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_auro_interfaces
void
auro_interfaces__action__Move_GetResult_Request__Sequence__fini(auro_interfaces__action__Move_GetResult_Request__Sequence * array);

/// Create array of action/Move messages.
/**
 * It allocates the memory for the array and calls
 * auro_interfaces__action__Move_GetResult_Request__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_auro_interfaces
auro_interfaces__action__Move_GetResult_Request__Sequence *
auro_interfaces__action__Move_GetResult_Request__Sequence__create(size_t size);

/// Destroy array of action/Move messages.
/**
 * It calls
 * auro_interfaces__action__Move_GetResult_Request__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_auro_interfaces
void
auro_interfaces__action__Move_GetResult_Request__Sequence__destroy(auro_interfaces__action__Move_GetResult_Request__Sequence * array);

/// Check for action/Move message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_auro_interfaces
bool
auro_interfaces__action__Move_GetResult_Request__Sequence__are_equal(const auro_interfaces__action__Move_GetResult_Request__Sequence * lhs, const auro_interfaces__action__Move_GetResult_Request__Sequence * rhs);

/// Copy an array of action/Move messages.
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
auro_interfaces__action__Move_GetResult_Request__Sequence__copy(
  const auro_interfaces__action__Move_GetResult_Request__Sequence * input,
  auro_interfaces__action__Move_GetResult_Request__Sequence * output);

/// Initialize action/Move message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * auro_interfaces__action__Move_GetResult_Response
 * )) before or use
 * auro_interfaces__action__Move_GetResult_Response__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_auro_interfaces
bool
auro_interfaces__action__Move_GetResult_Response__init(auro_interfaces__action__Move_GetResult_Response * msg);

/// Finalize action/Move message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_auro_interfaces
void
auro_interfaces__action__Move_GetResult_Response__fini(auro_interfaces__action__Move_GetResult_Response * msg);

/// Create action/Move message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * auro_interfaces__action__Move_GetResult_Response__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_auro_interfaces
auro_interfaces__action__Move_GetResult_Response *
auro_interfaces__action__Move_GetResult_Response__create();

/// Destroy action/Move message.
/**
 * It calls
 * auro_interfaces__action__Move_GetResult_Response__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_auro_interfaces
void
auro_interfaces__action__Move_GetResult_Response__destroy(auro_interfaces__action__Move_GetResult_Response * msg);

/// Check for action/Move message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_auro_interfaces
bool
auro_interfaces__action__Move_GetResult_Response__are_equal(const auro_interfaces__action__Move_GetResult_Response * lhs, const auro_interfaces__action__Move_GetResult_Response * rhs);

/// Copy a action/Move message.
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
auro_interfaces__action__Move_GetResult_Response__copy(
  const auro_interfaces__action__Move_GetResult_Response * input,
  auro_interfaces__action__Move_GetResult_Response * output);

/// Initialize array of action/Move messages.
/**
 * It allocates the memory for the number of elements and calls
 * auro_interfaces__action__Move_GetResult_Response__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_auro_interfaces
bool
auro_interfaces__action__Move_GetResult_Response__Sequence__init(auro_interfaces__action__Move_GetResult_Response__Sequence * array, size_t size);

/// Finalize array of action/Move messages.
/**
 * It calls
 * auro_interfaces__action__Move_GetResult_Response__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_auro_interfaces
void
auro_interfaces__action__Move_GetResult_Response__Sequence__fini(auro_interfaces__action__Move_GetResult_Response__Sequence * array);

/// Create array of action/Move messages.
/**
 * It allocates the memory for the array and calls
 * auro_interfaces__action__Move_GetResult_Response__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_auro_interfaces
auro_interfaces__action__Move_GetResult_Response__Sequence *
auro_interfaces__action__Move_GetResult_Response__Sequence__create(size_t size);

/// Destroy array of action/Move messages.
/**
 * It calls
 * auro_interfaces__action__Move_GetResult_Response__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_auro_interfaces
void
auro_interfaces__action__Move_GetResult_Response__Sequence__destroy(auro_interfaces__action__Move_GetResult_Response__Sequence * array);

/// Check for action/Move message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_auro_interfaces
bool
auro_interfaces__action__Move_GetResult_Response__Sequence__are_equal(const auro_interfaces__action__Move_GetResult_Response__Sequence * lhs, const auro_interfaces__action__Move_GetResult_Response__Sequence * rhs);

/// Copy an array of action/Move messages.
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
auro_interfaces__action__Move_GetResult_Response__Sequence__copy(
  const auro_interfaces__action__Move_GetResult_Response__Sequence * input,
  auro_interfaces__action__Move_GetResult_Response__Sequence * output);

/// Initialize action/Move message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * auro_interfaces__action__Move_FeedbackMessage
 * )) before or use
 * auro_interfaces__action__Move_FeedbackMessage__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_auro_interfaces
bool
auro_interfaces__action__Move_FeedbackMessage__init(auro_interfaces__action__Move_FeedbackMessage * msg);

/// Finalize action/Move message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_auro_interfaces
void
auro_interfaces__action__Move_FeedbackMessage__fini(auro_interfaces__action__Move_FeedbackMessage * msg);

/// Create action/Move message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * auro_interfaces__action__Move_FeedbackMessage__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_auro_interfaces
auro_interfaces__action__Move_FeedbackMessage *
auro_interfaces__action__Move_FeedbackMessage__create();

/// Destroy action/Move message.
/**
 * It calls
 * auro_interfaces__action__Move_FeedbackMessage__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_auro_interfaces
void
auro_interfaces__action__Move_FeedbackMessage__destroy(auro_interfaces__action__Move_FeedbackMessage * msg);

/// Check for action/Move message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_auro_interfaces
bool
auro_interfaces__action__Move_FeedbackMessage__are_equal(const auro_interfaces__action__Move_FeedbackMessage * lhs, const auro_interfaces__action__Move_FeedbackMessage * rhs);

/// Copy a action/Move message.
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
auro_interfaces__action__Move_FeedbackMessage__copy(
  const auro_interfaces__action__Move_FeedbackMessage * input,
  auro_interfaces__action__Move_FeedbackMessage * output);

/// Initialize array of action/Move messages.
/**
 * It allocates the memory for the number of elements and calls
 * auro_interfaces__action__Move_FeedbackMessage__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_auro_interfaces
bool
auro_interfaces__action__Move_FeedbackMessage__Sequence__init(auro_interfaces__action__Move_FeedbackMessage__Sequence * array, size_t size);

/// Finalize array of action/Move messages.
/**
 * It calls
 * auro_interfaces__action__Move_FeedbackMessage__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_auro_interfaces
void
auro_interfaces__action__Move_FeedbackMessage__Sequence__fini(auro_interfaces__action__Move_FeedbackMessage__Sequence * array);

/// Create array of action/Move messages.
/**
 * It allocates the memory for the array and calls
 * auro_interfaces__action__Move_FeedbackMessage__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_auro_interfaces
auro_interfaces__action__Move_FeedbackMessage__Sequence *
auro_interfaces__action__Move_FeedbackMessage__Sequence__create(size_t size);

/// Destroy array of action/Move messages.
/**
 * It calls
 * auro_interfaces__action__Move_FeedbackMessage__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_auro_interfaces
void
auro_interfaces__action__Move_FeedbackMessage__Sequence__destroy(auro_interfaces__action__Move_FeedbackMessage__Sequence * array);

/// Check for action/Move message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_auro_interfaces
bool
auro_interfaces__action__Move_FeedbackMessage__Sequence__are_equal(const auro_interfaces__action__Move_FeedbackMessage__Sequence * lhs, const auro_interfaces__action__Move_FeedbackMessage__Sequence * rhs);

/// Copy an array of action/Move messages.
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
auro_interfaces__action__Move_FeedbackMessage__Sequence__copy(
  const auro_interfaces__action__Move_FeedbackMessage__Sequence * input,
  auro_interfaces__action__Move_FeedbackMessage__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // AURO_INTERFACES__ACTION__DETAIL__MOVE__FUNCTIONS_H_
