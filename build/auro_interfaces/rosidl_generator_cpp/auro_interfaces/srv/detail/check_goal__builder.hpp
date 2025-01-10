// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from auro_interfaces:srv/CheckGoal.idl
// generated code does not contain a copyright notice

#ifndef AURO_INTERFACES__SRV__DETAIL__CHECK_GOAL__BUILDER_HPP_
#define AURO_INTERFACES__SRV__DETAIL__CHECK_GOAL__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "auro_interfaces/srv/detail/check_goal__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace auro_interfaces
{

namespace srv
{

namespace builder
{

class Init_CheckGoal_Request_y
{
public:
  explicit Init_CheckGoal_Request_y(::auro_interfaces::srv::CheckGoal_Request & msg)
  : msg_(msg)
  {}
  ::auro_interfaces::srv::CheckGoal_Request y(::auro_interfaces::srv::CheckGoal_Request::_y_type arg)
  {
    msg_.y = std::move(arg);
    return std::move(msg_);
  }

private:
  ::auro_interfaces::srv::CheckGoal_Request msg_;
};

class Init_CheckGoal_Request_x
{
public:
  Init_CheckGoal_Request_x()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_CheckGoal_Request_y x(::auro_interfaces::srv::CheckGoal_Request::_x_type arg)
  {
    msg_.x = std::move(arg);
    return Init_CheckGoal_Request_y(msg_);
  }

private:
  ::auro_interfaces::srv::CheckGoal_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::auro_interfaces::srv::CheckGoal_Request>()
{
  return auro_interfaces::srv::builder::Init_CheckGoal_Request_x();
}

}  // namespace auro_interfaces


namespace auro_interfaces
{

namespace srv
{

namespace builder
{

class Init_CheckGoal_Response_obstacle
{
public:
  Init_CheckGoal_Response_obstacle()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::auro_interfaces::srv::CheckGoal_Response obstacle(::auro_interfaces::srv::CheckGoal_Response::_obstacle_type arg)
  {
    msg_.obstacle = std::move(arg);
    return std::move(msg_);
  }

private:
  ::auro_interfaces::srv::CheckGoal_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::auro_interfaces::srv::CheckGoal_Response>()
{
  return auro_interfaces::srv::builder::Init_CheckGoal_Response_obstacle();
}

}  // namespace auro_interfaces

#endif  // AURO_INTERFACES__SRV__DETAIL__CHECK_GOAL__BUILDER_HPP_
