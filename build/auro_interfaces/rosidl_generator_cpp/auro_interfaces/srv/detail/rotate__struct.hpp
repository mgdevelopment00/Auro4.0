// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from auro_interfaces:srv/Rotate.idl
// generated code does not contain a copyright notice

#ifndef AURO_INTERFACES__SRV__DETAIL__ROTATE__STRUCT_HPP_
#define AURO_INTERFACES__SRV__DETAIL__ROTATE__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__auro_interfaces__srv__Rotate_Request __attribute__((deprecated))
#else
# define DEPRECATED__auro_interfaces__srv__Rotate_Request __declspec(deprecated)
#endif

namespace auro_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct Rotate_Request_
{
  using Type = Rotate_Request_<ContainerAllocator>;

  explicit Rotate_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->direction = false;
    }
  }

  explicit Rotate_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->direction = false;
    }
  }

  // field types and members
  using _direction_type =
    bool;
  _direction_type direction;

  // setters for named parameter idiom
  Type & set__direction(
    const bool & _arg)
  {
    this->direction = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    auro_interfaces::srv::Rotate_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const auro_interfaces::srv::Rotate_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<auro_interfaces::srv::Rotate_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<auro_interfaces::srv::Rotate_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      auro_interfaces::srv::Rotate_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<auro_interfaces::srv::Rotate_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      auro_interfaces::srv::Rotate_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<auro_interfaces::srv::Rotate_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<auro_interfaces::srv::Rotate_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<auro_interfaces::srv::Rotate_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__auro_interfaces__srv__Rotate_Request
    std::shared_ptr<auro_interfaces::srv::Rotate_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__auro_interfaces__srv__Rotate_Request
    std::shared_ptr<auro_interfaces::srv::Rotate_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Rotate_Request_ & other) const
  {
    if (this->direction != other.direction) {
      return false;
    }
    return true;
  }
  bool operator!=(const Rotate_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Rotate_Request_

// alias to use template instance with default allocator
using Rotate_Request =
  auro_interfaces::srv::Rotate_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace auro_interfaces


#ifndef _WIN32
# define DEPRECATED__auro_interfaces__srv__Rotate_Response __attribute__((deprecated))
#else
# define DEPRECATED__auro_interfaces__srv__Rotate_Response __declspec(deprecated)
#endif

namespace auro_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct Rotate_Response_
{
  using Type = Rotate_Response_<ContainerAllocator>;

  explicit Rotate_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->success = false;
    }
  }

  explicit Rotate_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
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
    auro_interfaces::srv::Rotate_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const auro_interfaces::srv::Rotate_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<auro_interfaces::srv::Rotate_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<auro_interfaces::srv::Rotate_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      auro_interfaces::srv::Rotate_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<auro_interfaces::srv::Rotate_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      auro_interfaces::srv::Rotate_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<auro_interfaces::srv::Rotate_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<auro_interfaces::srv::Rotate_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<auro_interfaces::srv::Rotate_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__auro_interfaces__srv__Rotate_Response
    std::shared_ptr<auro_interfaces::srv::Rotate_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__auro_interfaces__srv__Rotate_Response
    std::shared_ptr<auro_interfaces::srv::Rotate_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Rotate_Response_ & other) const
  {
    if (this->success != other.success) {
      return false;
    }
    return true;
  }
  bool operator!=(const Rotate_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Rotate_Response_

// alias to use template instance with default allocator
using Rotate_Response =
  auro_interfaces::srv::Rotate_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace auro_interfaces

namespace auro_interfaces
{

namespace srv
{

struct Rotate
{
  using Request = auro_interfaces::srv::Rotate_Request;
  using Response = auro_interfaces::srv::Rotate_Response;
};

}  // namespace srv

}  // namespace auro_interfaces

#endif  // AURO_INTERFACES__SRV__DETAIL__ROTATE__STRUCT_HPP_
