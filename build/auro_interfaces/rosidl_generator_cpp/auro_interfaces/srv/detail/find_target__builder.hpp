// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from auro_interfaces:srv/FindTarget.idl
// generated code does not contain a copyright notice

#ifndef AURO_INTERFACES__SRV__DETAIL__FIND_TARGET__BUILDER_HPP_
#define AURO_INTERFACES__SRV__DETAIL__FIND_TARGET__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "auro_interfaces/srv/detail/find_target__struct.hpp"
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
auto build<::auro_interfaces::srv::FindTarget_Request>()
{
  return ::auro_interfaces::srv::FindTarget_Request(rosidl_runtime_cpp::MessageInitialization::ZERO);
}

}  // namespace auro_interfaces


namespace auro_interfaces
{

namespace srv
{

namespace builder
{

class Init_FindTarget_Response_success
{
public:
  Init_FindTarget_Response_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::auro_interfaces::srv::FindTarget_Response success(::auro_interfaces::srv::FindTarget_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return std::move(msg_);
  }

private:
  ::auro_interfaces::srv::FindTarget_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::auro_interfaces::srv::FindTarget_Response>()
{
  return auro_interfaces::srv::builder::Init_FindTarget_Response_success();
}

}  // namespace auro_interfaces

#endif  // AURO_INTERFACES__SRV__DETAIL__FIND_TARGET__BUILDER_HPP_
