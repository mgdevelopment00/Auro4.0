// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from auro_interfaces:srv/Rotate.idl
// generated code does not contain a copyright notice

#ifndef AURO_INTERFACES__SRV__DETAIL__ROTATE__BUILDER_HPP_
#define AURO_INTERFACES__SRV__DETAIL__ROTATE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "auro_interfaces/srv/detail/rotate__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace auro_interfaces
{

namespace srv
{

namespace builder
{

class Init_Rotate_Request_direction
{
public:
  Init_Rotate_Request_direction()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::auro_interfaces::srv::Rotate_Request direction(::auro_interfaces::srv::Rotate_Request::_direction_type arg)
  {
    msg_.direction = std::move(arg);
    return std::move(msg_);
  }

private:
  ::auro_interfaces::srv::Rotate_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::auro_interfaces::srv::Rotate_Request>()
{
  return auro_interfaces::srv::builder::Init_Rotate_Request_direction();
}

}  // namespace auro_interfaces


namespace auro_interfaces
{

namespace srv
{

namespace builder
{

class Init_Rotate_Response_success
{
public:
  Init_Rotate_Response_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::auro_interfaces::srv::Rotate_Response success(::auro_interfaces::srv::Rotate_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return std::move(msg_);
  }

private:
  ::auro_interfaces::srv::Rotate_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::auro_interfaces::srv::Rotate_Response>()
{
  return auro_interfaces::srv::builder::Init_Rotate_Response_success();
}

}  // namespace auro_interfaces

#endif  // AURO_INTERFACES__SRV__DETAIL__ROTATE__BUILDER_HPP_
