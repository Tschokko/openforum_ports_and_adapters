#ifndef EVENTD_EVENTS_HPP__
#define EVENTD_EVENTS_HPP__

#include <string>

namespace eventd {
namespace events {

// -----------------------------------------------------------------------------
// Base event
// -----------------------------------------------------------------------------

enum class EventTypes : int { kProfileChanged = 1, kInputStateChanged = 2 };

class BaseEvent {
 public:
  virtual ~BaseEvent() = default;
  EventTypes type() const { return type_; }

 protected:
  BaseEvent(EventTypes type) : type_(type) {}

 private:
  BaseEvent() {}  // Prevent an instance of BaseEvent
  EventTypes type_;
};

// -----------------------------------------------------------------------------
// Profile changed
// -----------------------------------------------------------------------------

enum class ProfileStates : int { kModified = 1, kActivated = 2 };

class ProfileEvent : public BaseEvent {
 public:
  ProfileEvent(ProfileStates state)
      : BaseEvent(EventTypes::kProfileChanged), state_(state) {}

  ProfileStates state() const { return state_; }

 private:
  ProfileStates state_;
};

class ProfileEventListener {
 public:
  virtual ~ProfileEventListener() = default;
  virtual void Listen(ProfileEvent&& event) = 0;

 protected:
  ProfileEventListener() {}
};


// -----------------------------------------------------------------------------
// Input state event
// -----------------------------------------------------------------------------

enum class InputStates : int { kHigh = 1, kLow = 2 };

class InputStateEvent : public BaseEvent {
 public:
  InputStateEvent(std::string const& input, InputStates state)
      : BaseEvent(EventTypes::kInputStateChanged),
        input_(input),
        state_(state) {}

  std::string input() const { return input_; }
  InputStates state() const { return state_; }

 private:
  std::string input_;
  InputStates state_;
};

class InputStateEventListener {
 public:
  virtual ~InputStateEventListener() = default;
  virtual void Listen(InputStateEvent&& event) = 0;

 protected:
  InputStateEventListener() {}
};

}  // namespace events
}  // namespace eventd

#endif  // EVENTD_EVENTS_HPP__
