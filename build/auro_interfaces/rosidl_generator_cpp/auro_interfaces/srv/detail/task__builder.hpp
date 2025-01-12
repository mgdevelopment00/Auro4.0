// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from auro_interfaces:srv/Task.idl
// generated code does not contain a copyright notice

#ifndef AURO_INTERFACES__SRV__DETAIL__TASK__BUILDER_HPP_
#define AURO_INTERFACES__SRV__DETAIL__TASK__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "auro_interfaces/srv/detail/task__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace auro_interfaces
{

namespace srv
{

namespace builder
{

class Init_Task_Request_move_to_target
{
public:
  explicit Init_Task_Request_move_to_target(::auro_interfaces::srv::Task_Request & msg)
  : msg_(msg)
  {}
  ::auro_interfaces::srv::Task_Request move_to_target(::auro_interfaces::srv::Task_Request::_move_to_target_type arg)
  {
    msg_.move_to_target = std::move(arg);
    return std::move(msg_);
  }

private:
  ::auro_interfaces::srv::Task_Request msg_;
};

class Init_Task_Request_diameter
{
public:
  Init_Task_Request_diameter()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Task_Request_move_to_target diameter(::auro_interfaces::srv::Task_Request::_diameter_type arg)
  {
    msg_.diameter = std::move(arg);
    return Init_Task_Request_move_to_target(msg_);
  }

private:
  ::auro_interfaces::srv::Task_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::auro_interfaces::srv::Task_Request>()
{
  return auro_interfaces::srv::builder::Init_Task_Request_diameter();
}

}  // namespace auro_interfaces


namespace auro_interfaces
{

namespace srv
{

namespace builder
{

class Init_Task_Response_success
{
public:
  Init_Task_Response_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::auro_interfaces::srv::Task_Response success(::auro_interfaces::srv::Task_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return std::move(msg_);
  }

private:
  ::auro_interfaces::srv::Task_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::auro_interfaces::srv::Task_Response>()
{
  return auro_interfaces::srv::builder::Init_Task_Response_success();
}

}  // namespace auro_interfaces

#endif  // AURO_INTERFACES__SRV__DETAIL__TASK__BUILDER_HPP_
