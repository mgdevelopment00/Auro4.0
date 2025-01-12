// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from auro_interfaces:srv/Task.idl
// generated code does not contain a copyright notice

#ifndef AURO_INTERFACES__SRV__DETAIL__TASK__TRAITS_HPP_
#define AURO_INTERFACES__SRV__DETAIL__TASK__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "auro_interfaces/srv/detail/task__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace auro_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const Task_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: diameter
  {
    out << "diameter: ";
    rosidl_generator_traits::value_to_yaml(msg.diameter, out);
    out << ", ";
  }

  // member: move_to_target
  {
    out << "move_to_target: ";
    rosidl_generator_traits::value_to_yaml(msg.move_to_target, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Task_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: diameter
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "diameter: ";
    rosidl_generator_traits::value_to_yaml(msg.diameter, out);
    out << "\n";
  }

  // member: move_to_target
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "move_to_target: ";
    rosidl_generator_traits::value_to_yaml(msg.move_to_target, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Task_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace auro_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use auro_interfaces::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const auro_interfaces::srv::Task_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  auro_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use auro_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const auro_interfaces::srv::Task_Request & msg)
{
  return auro_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<auro_interfaces::srv::Task_Request>()
{
  return "auro_interfaces::srv::Task_Request";
}

template<>
inline const char * name<auro_interfaces::srv::Task_Request>()
{
  return "auro_interfaces/srv/Task_Request";
}

template<>
struct has_fixed_size<auro_interfaces::srv::Task_Request>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<auro_interfaces::srv::Task_Request>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<auro_interfaces::srv::Task_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace auro_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const Task_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: success
  {
    out << "success: ";
    rosidl_generator_traits::value_to_yaml(msg.success, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Task_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: success
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "success: ";
    rosidl_generator_traits::value_to_yaml(msg.success, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Task_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace auro_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use auro_interfaces::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const auro_interfaces::srv::Task_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  auro_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use auro_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const auro_interfaces::srv::Task_Response & msg)
{
  return auro_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<auro_interfaces::srv::Task_Response>()
{
  return "auro_interfaces::srv::Task_Response";
}

template<>
inline const char * name<auro_interfaces::srv::Task_Response>()
{
  return "auro_interfaces/srv/Task_Response";
}

template<>
struct has_fixed_size<auro_interfaces::srv::Task_Response>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<auro_interfaces::srv::Task_Response>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<auro_interfaces::srv::Task_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<auro_interfaces::srv::Task>()
{
  return "auro_interfaces::srv::Task";
}

template<>
inline const char * name<auro_interfaces::srv::Task>()
{
  return "auro_interfaces/srv/Task";
}

template<>
struct has_fixed_size<auro_interfaces::srv::Task>
  : std::integral_constant<
    bool,
    has_fixed_size<auro_interfaces::srv::Task_Request>::value &&
    has_fixed_size<auro_interfaces::srv::Task_Response>::value
  >
{
};

template<>
struct has_bounded_size<auro_interfaces::srv::Task>
  : std::integral_constant<
    bool,
    has_bounded_size<auro_interfaces::srv::Task_Request>::value &&
    has_bounded_size<auro_interfaces::srv::Task_Response>::value
  >
{
};

template<>
struct is_service<auro_interfaces::srv::Task>
  : std::true_type
{
};

template<>
struct is_service_request<auro_interfaces::srv::Task_Request>
  : std::true_type
{
};

template<>
struct is_service_response<auro_interfaces::srv::Task_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // AURO_INTERFACES__SRV__DETAIL__TASK__TRAITS_HPP_
