// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from auro_interfaces:srv/Collision.idl
// generated code does not contain a copyright notice

#ifndef AURO_INTERFACES__SRV__DETAIL__COLLISION__BUILDER_HPP_
#define AURO_INTERFACES__SRV__DETAIL__COLLISION__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "auro_interfaces/srv/detail/collision__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace auro_interfaces
{

namespace srv
{


}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::auro_interfaces::srv::Collision_Request>()
{
  return ::auro_interfaces::srv::Collision_Request(rosidl_runtime_cpp::MessageInitialization::ZERO);
}

}  // namespace auro_interfaces


namespace auro_interfaces
{

namespace srv
{

namespace builder
{

class Init_Collision_Response_success
{
public:
  explicit Init_Collision_Response_success(::auro_interfaces::srv::Collision_Response & msg)
  : msg_(msg)
  {}
  ::auro_interfaces::srv::Collision_Response success(::auro_interfaces::srv::Collision_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return std::move(msg_);
  }

private:
  ::auro_interfaces::srv::Collision_Response msg_;
};

class Init_Collision_Response_direction
{
public:
  Init_Collision_Response_direction()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Collision_Response_success direction(::auro_interfaces::srv::Collision_Response::_direction_type arg)
  {
    msg_.direction = std::move(arg);
    return Init_Collision_Response_success(msg_);
  }

private:
  ::auro_interfaces::srv::Collision_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::auro_interfaces::srv::Collision_Response>()
{
  return auro_interfaces::srv::builder::Init_Collision_Response_direction();
}

}  // namespace auro_interfaces

#endif  // AURO_INTERFACES__SRV__DETAIL__COLLISION__BUILDER_HPP_
