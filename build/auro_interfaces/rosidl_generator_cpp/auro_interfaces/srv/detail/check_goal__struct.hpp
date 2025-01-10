// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from auro_interfaces:srv/CheckGoal.idl
// generated code does not contain a copyright notice

#ifndef AURO_INTERFACES__SRV__DETAIL__CHECK_GOAL__STRUCT_HPP_
#define AURO_INTERFACES__SRV__DETAIL__CHECK_GOAL__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__auro_interfaces__srv__CheckGoal_Request __attribute__((deprecated))
#else
# define DEPRECATED__auro_interfaces__srv__CheckGoal_Request __declspec(deprecated)
#endif

namespace auro_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct CheckGoal_Request_
{
  using Type = CheckGoal_Request_<ContainerAllocator>;

  explicit CheckGoal_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->x = 0.0;
      this->y = 0.0;
    }
  }

  explicit CheckGoal_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->x = 0.0;
      this->y = 0.0;
    }
  }

  // field types and members
  using _x_type =
    double;
  _x_type x;
  using _y_type =
    double;
  _y_type y;

  // setters for named parameter idiom
  Type & set__x(
    const double & _arg)
  {
    this->x = _arg;
    return *this;
  }
  Type & set__y(
    const double & _arg)
  {
    this->y = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    auro_interfaces::srv::CheckGoal_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const auro_interfaces::srv::CheckGoal_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<auro_interfaces::srv::CheckGoal_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<auro_interfaces::srv::CheckGoal_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      auro_interfaces::srv::CheckGoal_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<auro_interfaces::srv::CheckGoal_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      auro_interfaces::srv::CheckGoal_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<auro_interfaces::srv::CheckGoal_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<auro_interfaces::srv::CheckGoal_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<auro_interfaces::srv::CheckGoal_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__auro_interfaces__srv__CheckGoal_Request
    std::shared_ptr<auro_interfaces::srv::CheckGoal_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__auro_interfaces__srv__CheckGoal_Request
    std::shared_ptr<auro_interfaces::srv::CheckGoal_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const CheckGoal_Request_ & other) const
  {
    if (this->x != other.x) {
      return false;
    }
    if (this->y != other.y) {
      return false;
    }
    return true;
  }
  bool operator!=(const CheckGoal_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct CheckGoal_Request_

// alias to use template instance with default allocator
using CheckGoal_Request =
  auro_interfaces::srv::CheckGoal_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace auro_interfaces


#ifndef _WIN32
# define DEPRECATED__auro_interfaces__srv__CheckGoal_Response __attribute__((deprecated))
#else
# define DEPRECATED__auro_interfaces__srv__CheckGoal_Response __declspec(deprecated)
#endif

namespace auro_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct CheckGoal_Response_
{
  using Type = CheckGoal_Response_<ContainerAllocator>;

  explicit CheckGoal_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->obstacle = false;
    }
  }

  explicit CheckGoal_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->obstacle = false;
    }
  }

  // field types and members
  using _obstacle_type =
    bool;
  _obstacle_type obstacle;

  // setters for named parameter idiom
  Type & set__obstacle(
    const bool & _arg)
  {
    this->obstacle = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    auro_interfaces::srv::CheckGoal_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const auro_interfaces::srv::CheckGoal_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<auro_interfaces::srv::CheckGoal_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<auro_interfaces::srv::CheckGoal_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      auro_interfaces::srv::CheckGoal_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<auro_interfaces::srv::CheckGoal_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      auro_interfaces::srv::CheckGoal_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<auro_interfaces::srv::CheckGoal_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<auro_interfaces::srv::CheckGoal_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<auro_interfaces::srv::CheckGoal_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__auro_interfaces__srv__CheckGoal_Response
    std::shared_ptr<auro_interfaces::srv::CheckGoal_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__auro_interfaces__srv__CheckGoal_Response
    std::shared_ptr<auro_interfaces::srv::CheckGoal_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const CheckGoal_Response_ & other) const
  {
    if (this->obstacle != other.obstacle) {
      return false;
    }
    return true;
  }
  bool operator!=(const CheckGoal_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct CheckGoal_Response_

// alias to use template instance with default allocator
using CheckGoal_Response =
  auro_interfaces::srv::CheckGoal_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace auro_interfaces

namespace auro_interfaces
{

namespace srv
{

struct CheckGoal
{
  using Request = auro_interfaces::srv::CheckGoal_Request;
  using Response = auro_interfaces::srv::CheckGoal_Response;
};

}  // namespace srv

}  // namespace auro_interfaces

#endif  // AURO_INTERFACES__SRV__DETAIL__CHECK_GOAL__STRUCT_HPP_
