// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from auro_interfaces:action/Move.idl
// generated code does not contain a copyright notice

#ifndef AURO_INTERFACES__ACTION__DETAIL__MOVE__BUILDER_HPP_
#define AURO_INTERFACES__ACTION__DETAIL__MOVE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "auro_interfaces/action/detail/move__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace auro_interfaces
{

namespace action
{

namespace builder
{

class Init_Move_Goal_y
{
public:
  explicit Init_Move_Goal_y(::auro_interfaces::action::Move_Goal & msg)
  : msg_(msg)
  {}
  ::auro_interfaces::action::Move_Goal y(::auro_interfaces::action::Move_Goal::_y_type arg)
  {
    msg_.y = std::move(arg);
    return std::move(msg_);
  }

private:
  ::auro_interfaces::action::Move_Goal msg_;
};

class Init_Move_Goal_x
{
public:
  Init_Move_Goal_x()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Move_Goal_y x(::auro_interfaces::action::Move_Goal::_x_type arg)
  {
    msg_.x = std::move(arg);
    return Init_Move_Goal_y(msg_);
  }

private:
  ::auro_interfaces::action::Move_Goal msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::auro_interfaces::action::Move_Goal>()
{
  return auro_interfaces::action::builder::Init_Move_Goal_x();
}

}  // namespace auro_interfaces


namespace auro_interfaces
{

namespace action
{

namespace builder
{

class Init_Move_Result_status
{
public:
  Init_Move_Result_status()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::auro_interfaces::action::Move_Result status(::auro_interfaces::action::Move_Result::_status_type arg)
  {
    msg_.status = std::move(arg);
    return std::move(msg_);
  }

private:
  ::auro_interfaces::action::Move_Result msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::auro_interfaces::action::Move_Result>()
{
  return auro_interfaces::action::builder::Init_Move_Result_status();
}

}  // namespace auro_interfaces


namespace auro_interfaces
{

namespace action
{

namespace builder
{

class Init_Move_Feedback_progress
{
public:
  Init_Move_Feedback_progress()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::auro_interfaces::action::Move_Feedback progress(::auro_interfaces::action::Move_Feedback::_progress_type arg)
  {
    msg_.progress = std::move(arg);
    return std::move(msg_);
  }

private:
  ::auro_interfaces::action::Move_Feedback msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::auro_interfaces::action::Move_Feedback>()
{
  return auro_interfaces::action::builder::Init_Move_Feedback_progress();
}

}  // namespace auro_interfaces


namespace auro_interfaces
{

namespace action
{

namespace builder
{

class Init_Move_SendGoal_Request_goal
{
public:
  explicit Init_Move_SendGoal_Request_goal(::auro_interfaces::action::Move_SendGoal_Request & msg)
  : msg_(msg)
  {}
  ::auro_interfaces::action::Move_SendGoal_Request goal(::auro_interfaces::action::Move_SendGoal_Request::_goal_type arg)
  {
    msg_.goal = std::move(arg);
    return std::move(msg_);
  }

private:
  ::auro_interfaces::action::Move_SendGoal_Request msg_;
};

class Init_Move_SendGoal_Request_goal_id
{
public:
  Init_Move_SendGoal_Request_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Move_SendGoal_Request_goal goal_id(::auro_interfaces::action::Move_SendGoal_Request::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return Init_Move_SendGoal_Request_goal(msg_);
  }

private:
  ::auro_interfaces::action::Move_SendGoal_Request msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::auro_interfaces::action::Move_SendGoal_Request>()
{
  return auro_interfaces::action::builder::Init_Move_SendGoal_Request_goal_id();
}

}  // namespace auro_interfaces


namespace auro_interfaces
{

namespace action
{

namespace builder
{

class Init_Move_SendGoal_Response_stamp
{
public:
  explicit Init_Move_SendGoal_Response_stamp(::auro_interfaces::action::Move_SendGoal_Response & msg)
  : msg_(msg)
  {}
  ::auro_interfaces::action::Move_SendGoal_Response stamp(::auro_interfaces::action::Move_SendGoal_Response::_stamp_type arg)
  {
    msg_.stamp = std::move(arg);
    return std::move(msg_);
  }

private:
  ::auro_interfaces::action::Move_SendGoal_Response msg_;
};

class Init_Move_SendGoal_Response_accepted
{
public:
  Init_Move_SendGoal_Response_accepted()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Move_SendGoal_Response_stamp accepted(::auro_interfaces::action::Move_SendGoal_Response::_accepted_type arg)
  {
    msg_.accepted = std::move(arg);
    return Init_Move_SendGoal_Response_stamp(msg_);
  }

private:
  ::auro_interfaces::action::Move_SendGoal_Response msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::auro_interfaces::action::Move_SendGoal_Response>()
{
  return auro_interfaces::action::builder::Init_Move_SendGoal_Response_accepted();
}

}  // namespace auro_interfaces


namespace auro_interfaces
{

namespace action
{

namespace builder
{

class Init_Move_GetResult_Request_goal_id
{
public:
  Init_Move_GetResult_Request_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::auro_interfaces::action::Move_GetResult_Request goal_id(::auro_interfaces::action::Move_GetResult_Request::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return std::move(msg_);
  }

private:
  ::auro_interfaces::action::Move_GetResult_Request msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::auro_interfaces::action::Move_GetResult_Request>()
{
  return auro_interfaces::action::builder::Init_Move_GetResult_Request_goal_id();
}

}  // namespace auro_interfaces


namespace auro_interfaces
{

namespace action
{

namespace builder
{

class Init_Move_GetResult_Response_result
{
public:
  explicit Init_Move_GetResult_Response_result(::auro_interfaces::action::Move_GetResult_Response & msg)
  : msg_(msg)
  {}
  ::auro_interfaces::action::Move_GetResult_Response result(::auro_interfaces::action::Move_GetResult_Response::_result_type arg)
  {
    msg_.result = std::move(arg);
    return std::move(msg_);
  }

private:
  ::auro_interfaces::action::Move_GetResult_Response msg_;
};

class Init_Move_GetResult_Response_status
{
public:
  Init_Move_GetResult_Response_status()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Move_GetResult_Response_result status(::auro_interfaces::action::Move_GetResult_Response::_status_type arg)
  {
    msg_.status = std::move(arg);
    return Init_Move_GetResult_Response_result(msg_);
  }

private:
  ::auro_interfaces::action::Move_GetResult_Response msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::auro_interfaces::action::Move_GetResult_Response>()
{
  return auro_interfaces::action::builder::Init_Move_GetResult_Response_status();
}

}  // namespace auro_interfaces


namespace auro_interfaces
{

namespace action
{

namespace builder
{

class Init_Move_FeedbackMessage_feedback
{
public:
  explicit Init_Move_FeedbackMessage_feedback(::auro_interfaces::action::Move_FeedbackMessage & msg)
  : msg_(msg)
  {}
  ::auro_interfaces::action::Move_FeedbackMessage feedback(::auro_interfaces::action::Move_FeedbackMessage::_feedback_type arg)
  {
    msg_.feedback = std::move(arg);
    return std::move(msg_);
  }

private:
  ::auro_interfaces::action::Move_FeedbackMessage msg_;
};

class Init_Move_FeedbackMessage_goal_id
{
public:
  Init_Move_FeedbackMessage_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Move_FeedbackMessage_feedback goal_id(::auro_interfaces::action::Move_FeedbackMessage::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return Init_Move_FeedbackMessage_feedback(msg_);
  }

private:
  ::auro_interfaces::action::Move_FeedbackMessage msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::auro_interfaces::action::Move_FeedbackMessage>()
{
  return auro_interfaces::action::builder::Init_Move_FeedbackMessage_goal_id();
}

}  // namespace auro_interfaces

#endif  // AURO_INTERFACES__ACTION__DETAIL__MOVE__BUILDER_HPP_
