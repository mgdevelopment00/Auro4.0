// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from auro_interfaces:srv/FindTarget.idl
// generated code does not contain a copyright notice

#ifndef AURO_INTERFACES__SRV__DETAIL__FIND_TARGET__STRUCT_HPP_
#define AURO_INTERFACES__SRV__DETAIL__FIND_TARGET__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__auro_interfaces__srv__FindTarget_Request __attribute__((deprecated))
#else
# define DEPRECATED__auro_interfaces__srv__FindTarget_Request __declspec(deprecated)
#endif

namespace auro_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct FindTarget_Request_
{
  using Type = FindTarget_Request_<ContainerAllocator>;

  explicit FindTarget_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->structure_needs_at_least_one_member = 0;
    }
  }

  explicit FindTarget_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->structure_needs_at_least_one_member = 0;
    }
  }

  // field types and members
  using _structure_needs_at_least_one_member_type =
    uint8_t;
  _structure_needs_at_least_one_member_type structure_needs_at_least_one_member;


  // constant declarations

  // pointer types
  using RawPtr =
    auro_interfaces::srv::FindTarget_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const auro_interfaces::srv::FindTarget_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<auro_interfaces::srv::FindTarget_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<auro_interfaces::srv::FindTarget_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      auro_interfaces::srv::FindTarget_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<auro_interfaces::srv::FindTarget_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      auro_interfaces::srv::FindTarget_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<auro_interfaces::srv::FindTarget_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<auro_interfaces::srv::FindTarget_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<auro_interfaces::srv::FindTarget_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__auro_interfaces__srv__FindTarget_Request
    std::shared_ptr<auro_interfaces::srv::FindTarget_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__auro_interfaces__srv__FindTarget_Request
    std::shared_ptr<auro_interfaces::srv::FindTarget_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const FindTarget_Request_ & other) const
  {
    if (this->structure_needs_at_least_one_member != other.structure_needs_at_least_one_member) {
      return false;
    }
    return true;
  }
  bool operator!=(const FindTarget_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct FindTarget_Request_

// alias to use template instance with default allocator
using FindTarget_Request =
  auro_interfaces::srv::FindTarget_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace auro_interfaces


#ifndef _WIN32
# define DEPRECATED__auro_interfaces__srv__FindTarget_Response __attribute__((deprecated))
#else
# define DEPRECATED__auro_interfaces__srv__FindTarget_Response __declspec(deprecated)
#endif

namespace auro_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct FindTarget_Response_
{
  using Type = FindTarget_Response_<ContainerAllocator>;

  explicit FindTarget_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->success = false;
    }
  }

  explicit FindTarget_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
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
    auro_interfaces::srv::FindTarget_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const auro_interfaces::srv::FindTarget_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<auro_interfaces::srv::FindTarget_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<auro_interfaces::srv::FindTarget_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      auro_interfaces::srv::FindTarget_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<auro_interfaces::srv::FindTarget_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      auro_interfaces::srv::FindTarget_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<auro_interfaces::srv::FindTarget_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<auro_interfaces::srv::FindTarget_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<auro_interfaces::srv::FindTarget_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__auro_interfaces__srv__FindTarget_Response
    std::shared_ptr<auro_interfaces::srv::FindTarget_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__auro_interfaces__srv__FindTarget_Response
    std::shared_ptr<auro_interfaces::srv::FindTarget_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const FindTarget_Response_ & other) const
  {
    if (this->success != other.success) {
      return false;
    }
    return true;
  }
  bool operator!=(const FindTarget_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct FindTarget_Response_

// alias to use template instance with default allocator
using FindTarget_Response =
  auro_interfaces::srv::FindTarget_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace auro_interfaces

namespace auro_interfaces
{

namespace srv
{

struct FindTarget
{
  using Request = auro_interfaces::srv::FindTarget_Request;
  using Response = auro_interfaces::srv::FindTarget_Response;
};

}  // namespace srv

}  // namespace auro_interfaces

#endif  // AURO_INTERFACES__SRV__DETAIL__FIND_TARGET__STRUCT_HPP_
