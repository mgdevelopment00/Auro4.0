// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from auro_interfaces:srv/ZoneRequest.idl
// generated code does not contain a copyright notice

#ifndef AURO_INTERFACES__SRV__DETAIL__ZONE_REQUEST__STRUCT_HPP_
#define AURO_INTERFACES__SRV__DETAIL__ZONE_REQUEST__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__auro_interfaces__srv__ZoneRequest_Request __attribute__((deprecated))
#else
# define DEPRECATED__auro_interfaces__srv__ZoneRequest_Request __declspec(deprecated)
#endif

namespace auro_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct ZoneRequest_Request_
{
  using Type = ZoneRequest_Request_<ContainerAllocator>;

  explicit ZoneRequest_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->robot_id = "";
      this->x = 0.0;
      this->y = 0.0;
      this->colour = "";
    }
  }

  explicit ZoneRequest_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : robot_id(_alloc),
    colour(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->robot_id = "";
      this->x = 0.0;
      this->y = 0.0;
      this->colour = "";
    }
  }

  // field types and members
  using _robot_id_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _robot_id_type robot_id;
  using _x_type =
    double;
  _x_type x;
  using _y_type =
    double;
  _y_type y;
  using _colour_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _colour_type colour;

  // setters for named parameter idiom
  Type & set__robot_id(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->robot_id = _arg;
    return *this;
  }
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
  Type & set__colour(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->colour = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    auro_interfaces::srv::ZoneRequest_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const auro_interfaces::srv::ZoneRequest_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<auro_interfaces::srv::ZoneRequest_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<auro_interfaces::srv::ZoneRequest_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      auro_interfaces::srv::ZoneRequest_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<auro_interfaces::srv::ZoneRequest_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      auro_interfaces::srv::ZoneRequest_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<auro_interfaces::srv::ZoneRequest_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<auro_interfaces::srv::ZoneRequest_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<auro_interfaces::srv::ZoneRequest_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__auro_interfaces__srv__ZoneRequest_Request
    std::shared_ptr<auro_interfaces::srv::ZoneRequest_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__auro_interfaces__srv__ZoneRequest_Request
    std::shared_ptr<auro_interfaces::srv::ZoneRequest_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const ZoneRequest_Request_ & other) const
  {
    if (this->robot_id != other.robot_id) {
      return false;
    }
    if (this->x != other.x) {
      return false;
    }
    if (this->y != other.y) {
      return false;
    }
    if (this->colour != other.colour) {
      return false;
    }
    return true;
  }
  bool operator!=(const ZoneRequest_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct ZoneRequest_Request_

// alias to use template instance with default allocator
using ZoneRequest_Request =
  auro_interfaces::srv::ZoneRequest_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace auro_interfaces


#ifndef _WIN32
# define DEPRECATED__auro_interfaces__srv__ZoneRequest_Response __attribute__((deprecated))
#else
# define DEPRECATED__auro_interfaces__srv__ZoneRequest_Response __declspec(deprecated)
#endif

namespace auro_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct ZoneRequest_Response_
{
  using Type = ZoneRequest_Response_<ContainerAllocator>;

  explicit ZoneRequest_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->x = 0.0;
      this->y = 0.0;
    }
  }

  explicit ZoneRequest_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
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
    auro_interfaces::srv::ZoneRequest_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const auro_interfaces::srv::ZoneRequest_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<auro_interfaces::srv::ZoneRequest_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<auro_interfaces::srv::ZoneRequest_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      auro_interfaces::srv::ZoneRequest_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<auro_interfaces::srv::ZoneRequest_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      auro_interfaces::srv::ZoneRequest_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<auro_interfaces::srv::ZoneRequest_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<auro_interfaces::srv::ZoneRequest_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<auro_interfaces::srv::ZoneRequest_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__auro_interfaces__srv__ZoneRequest_Response
    std::shared_ptr<auro_interfaces::srv::ZoneRequest_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__auro_interfaces__srv__ZoneRequest_Response
    std::shared_ptr<auro_interfaces::srv::ZoneRequest_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const ZoneRequest_Response_ & other) const
  {
    if (this->x != other.x) {
      return false;
    }
    if (this->y != other.y) {
      return false;
    }
    return true;
  }
  bool operator!=(const ZoneRequest_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct ZoneRequest_Response_

// alias to use template instance with default allocator
using ZoneRequest_Response =
  auro_interfaces::srv::ZoneRequest_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace auro_interfaces

namespace auro_interfaces
{

namespace srv
{

struct ZoneRequest
{
  using Request = auro_interfaces::srv::ZoneRequest_Request;
  using Response = auro_interfaces::srv::ZoneRequest_Response;
};

}  // namespace srv

}  // namespace auro_interfaces

#endif  // AURO_INTERFACES__SRV__DETAIL__ZONE_REQUEST__STRUCT_HPP_
