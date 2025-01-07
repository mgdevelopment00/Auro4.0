// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from auro_interfaces:srv/Sector.idl
// generated code does not contain a copyright notice

#ifndef AURO_INTERFACES__SRV__DETAIL__SECTOR__BUILDER_HPP_
#define AURO_INTERFACES__SRV__DETAIL__SECTOR__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "auro_interfaces/srv/detail/sector__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace auro_interfaces
{

namespace srv
{

namespace builder
{

class Init_Sector_Request_y
{
public:
  explicit Init_Sector_Request_y(::auro_interfaces::srv::Sector_Request & msg)
  : msg_(msg)
  {}
  ::auro_interfaces::srv::Sector_Request y(::auro_interfaces::srv::Sector_Request::_y_type arg)
  {
    msg_.y = std::move(arg);
    return std::move(msg_);
  }

private:
  ::auro_interfaces::srv::Sector_Request msg_;
};

class Init_Sector_Request_x
{
public:
  explicit Init_Sector_Request_x(::auro_interfaces::srv::Sector_Request & msg)
  : msg_(msg)
  {}
  Init_Sector_Request_y x(::auro_interfaces::srv::Sector_Request::_x_type arg)
  {
    msg_.x = std::move(arg);
    return Init_Sector_Request_y(msg_);
  }

private:
  ::auro_interfaces::srv::Sector_Request msg_;
};

class Init_Sector_Request_robot_id
{
public:
  Init_Sector_Request_robot_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Sector_Request_x robot_id(::auro_interfaces::srv::Sector_Request::_robot_id_type arg)
  {
    msg_.robot_id = std::move(arg);
    return Init_Sector_Request_x(msg_);
  }

private:
  ::auro_interfaces::srv::Sector_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::auro_interfaces::srv::Sector_Request>()
{
  return auro_interfaces::srv::builder::Init_Sector_Request_robot_id();
}

}  // namespace auro_interfaces


namespace auro_interfaces
{

namespace srv
{

namespace builder
{

class Init_Sector_Response_y
{
public:
  explicit Init_Sector_Response_y(::auro_interfaces::srv::Sector_Response & msg)
  : msg_(msg)
  {}
  ::auro_interfaces::srv::Sector_Response y(::auro_interfaces::srv::Sector_Response::_y_type arg)
  {
    msg_.y = std::move(arg);
    return std::move(msg_);
  }

private:
  ::auro_interfaces::srv::Sector_Response msg_;
};

class Init_Sector_Response_x
{
public:
  Init_Sector_Response_x()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Sector_Response_y x(::auro_interfaces::srv::Sector_Response::_x_type arg)
  {
    msg_.x = std::move(arg);
    return Init_Sector_Response_y(msg_);
  }

private:
  ::auro_interfaces::srv::Sector_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::auro_interfaces::srv::Sector_Response>()
{
  return auro_interfaces::srv::builder::Init_Sector_Response_x();
}

}  // namespace auro_interfaces

#endif  // AURO_INTERFACES__SRV__DETAIL__SECTOR__BUILDER_HPP_
