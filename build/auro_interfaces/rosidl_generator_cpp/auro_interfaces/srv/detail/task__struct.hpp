// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from auro_interfaces:srv/Task.idl
// generated code does not contain a copyright notice

#ifndef AURO_INTERFACES__SRV__DETAIL__TASK__STRUCT_HPP_
#define AURO_INTERFACES__SRV__DETAIL__TASK__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__auro_interfaces__srv__Task_Request __attribute__((deprecated))
#else
# define DEPRECATED__auro_interfaces__srv__Task_Request __declspec(deprecated)
#endif

namespace auro_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct Task_Request_
{
  using Type = Task_Request_<ContainerAllocator>;

  explicit Task_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->diameter = 0.0;
      this->move_to_target = false;
      this->colour = "";
    }
  }

  explicit Task_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : colour(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->diameter = 0.0;
      this->move_to_target = false;
      this->colour = "";
    }
  }

  // field types and members
  using _diameter_type =
    double;
  _diameter_type diameter;
  using _move_to_target_type =
    bool;
  _move_to_target_type move_to_target;
  using _colour_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _colour_type colour;

  // setters for named parameter idiom
  Type & set__diameter(
    const double & _arg)
  {
    this->diameter = _arg;
    return *this;
  }
  Type & set__move_to_target(
    const bool & _arg)
  {
    this->move_to_target = _arg;
    return *this;
  }
  Type & set__colour(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->colour = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    auro_interfaces::srv::Task_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const auro_interfaces::srv::Task_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<auro_interfaces::srv::Task_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<auro_interfaces::srv::Task_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      auro_interfaces::srv::Task_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<auro_interfaces::srv::Task_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      auro_interfaces::srv::Task_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<auro_interfaces::srv::Task_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<auro_interfaces::srv::Task_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<auro_interfaces::srv::Task_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__auro_interfaces__srv__Task_Request
    std::shared_ptr<auro_interfaces::srv::Task_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__auro_interfaces__srv__Task_Request
    std::shared_ptr<auro_interfaces::srv::Task_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Task_Request_ & other) const
  {
    if (this->diameter != other.diameter) {
      return false;
    }
    if (this->move_to_target != other.move_to_target) {
      return false;
    }
    if (this->colour != other.colour) {
      return false;
    }
    return true;
  }
  bool operator!=(const Task_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Task_Request_

// alias to use template instance with default allocator
using Task_Request =
  auro_interfaces::srv::Task_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace auro_interfaces


#ifndef _WIN32
# define DEPRECATED__auro_interfaces__srv__Task_Response __attribute__((deprecated))
#else
# define DEPRECATED__auro_interfaces__srv__Task_Response __declspec(deprecated)
#endif

namespace auro_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct Task_Response_
{
  using Type = Task_Response_<ContainerAllocator>;

  explicit Task_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->success = false;
    }
  }

  explicit Task_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->success = false;
    }
  }

  // field types and members
  using _success_type =
    bool;
  _success_type success;

  // setters for named parameter idiom
  Type & set__success(
    const bool & _arg)
  {
    this->success = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    auro_interfaces::srv::Task_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const auro_interfaces::srv::Task_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<auro_interfaces::srv::Task_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<auro_interfaces::srv::Task_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      auro_interfaces::srv::Task_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<auro_interfaces::srv::Task_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      auro_interfaces::srv::Task_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<auro_interfaces::srv::Task_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<auro_interfaces::srv::Task_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<auro_interfaces::srv::Task_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__auro_interfaces__srv__Task_Response
    std::shared_ptr<auro_interfaces::srv::Task_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__auro_interfaces__srv__Task_Response
    std::shared_ptr<auro_interfaces::srv::Task_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Task_Response_ & other) const
  {
    if (this->success != other.success) {
      return false;
    }
    return true;
  }
  bool operator!=(const Task_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Task_Response_

// alias to use template instance with default allocator
using Task_Response =
  auro_interfaces::srv::Task_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace auro_interfaces

namespace auro_interfaces
{

namespace srv
{

struct Task
{
  using Request = auro_interfaces::srv::Task_Request;
  using Response = auro_interfaces::srv::Task_Response;
};

}  // namespace srv

}  // namespace auro_interfaces

#endif  // AURO_INTERFACES__SRV__DETAIL__TASK__STRUCT_HPP_
