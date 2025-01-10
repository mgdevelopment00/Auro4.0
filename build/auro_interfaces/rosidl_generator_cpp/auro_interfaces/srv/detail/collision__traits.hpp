// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from auro_interfaces:srv/Collision.idl
// generated code does not contain a copyright notice

#ifndef AURO_INTERFACES__SRV__DETAIL__COLLISION__TRAITS_HPP_
#define AURO_INTERFACES__SRV__DETAIL__COLLISION__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "auro_interfaces/srv/detail/collision__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace auro_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const Collision_Request & msg,
  std::ostream & out)
{
  (void)msg;
  out << "null";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Collision_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  (void)msg;
  (void)indentation;
  out << "null\n";
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Collision_Request & msg, bool use_flow_style = false)
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
  const auro_interfaces::srv::Collision_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  auro_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use auro_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const auro_interfaces::srv::Collision_Request & msg)
{
  return auro_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<auro_interfaces::srv::Collision_Request>()
{
  return "auro_interfaces::srv::Collision_Request";
}

template<>
inline const char * name<auro_interfaces::srv::Collision_Request>()
{
  return "auro_interfaces/srv/Collision_Request";
}

template<>
struct has_fixed_size<auro_interfaces::srv::Collision_Request>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<auro_interfaces::srv::Collision_Request>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<auro_interfaces::srv::Collision_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace auro_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const Collision_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: direction
  {
    out << "direction: ";
    rosidl_generator_traits::value_to_yaml(msg.direction, out);
    out << ", ";
  }

  // member: success
  {
    out << "success: ";
    rosidl_generator_traits::value_to_yaml(msg.success, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Collision_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: direction
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "direction: ";
    rosidl_generator_traits::value_to_yaml(msg.direction, out);
    out << "\n";
  }

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

inline std::string to_yaml(const Collision_Response & msg, bool use_flow_style = false)
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
  const auro_interfaces::srv::Collision_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  auro_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use auro_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const auro_interfaces::srv::Collision_Response & msg)
{
  return auro_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<auro_interfaces::srv::Collision_Response>()
{
  return "auro_interfaces::srv::Collision_Response";
}

template<>
inline const char * name<auro_interfaces::srv::Collision_Response>()
{
  return "auro_interfaces/srv/Collision_Response";
}

template<>
struct has_fixed_size<auro_interfaces::srv::Collision_Response>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<auro_interfaces::srv::Collision_Response>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<auro_interfaces::srv::Collision_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<auro_interfaces::srv::Collision>()
{
  return "auro_interfaces::srv::Collision";
}

template<>
inline const char * name<auro_interfaces::srv::Collision>()
{
  return "auro_interfaces/srv/Collision";
}

template<>
struct has_fixed_size<auro_interfaces::srv::Collision>
  : std::integral_constant<
    bool,
    has_fixed_size<auro_interfaces::srv::Collision_Request>::value &&
    has_fixed_size<auro_interfaces::srv::Collision_Response>::value
  >
{
};

template<>
struct has_bounded_size<auro_interfaces::srv::Collision>
  : std::integral_constant<
    bool,
    has_bounded_size<auro_interfaces::srv::Collision_Request>::value &&
    has_bounded_size<auro_interfaces::srv::Collision_Response>::value
  >
{
};

template<>
struct is_service<auro_interfaces::srv::Collision>
  : std::true_type
{
};

template<>
struct is_service_request<auro_interfaces::srv::Collision_Request>
  : std::true_type
{
};

template<>
struct is_service_response<auro_interfaces::srv::Collision_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // AURO_INTERFACES__SRV__DETAIL__COLLISION__TRAITS_HPP_
