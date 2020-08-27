#ifndef EVENTD_EVENTS_HPP__
#define EVENTD_EVENTS_HPP__

#include <string>

namespace eventd {
namespace events {

// -----------------------------------------------------------------------------
// Profile changed
// -----------------------------------------------------------------------------

enum class ProfileStates : int { kModified = 1, kActivated = 2 };

class ProfileChanged {
 public:
  ProfileChanged(ProfileStates state) : state_(state) {}

  ProfileStates state() const { return state_; }

 private:
  ProfileStates state_;
};

class ProfileChangedListener {
 public:
  virtual ~ProfileChangedListener() {}
  virtual void Listen(ProfileChanged&& event) = 0;

 protected:
  ProfileChangedListener() {}
};


// -----------------------------------------------------------------------------
// Input state changed
// -----------------------------------------------------------------------------

enum class InputStates : int { kHigh = 1, kLow = 2 };

class InputStateChanged {
 public:
  InputStateChanged(std::string const& input, InputStates state)
      : input_(input), state_(state) {}

  std::string input() const { return input_; }
  InputStates state() const { return state_; }

 private:
  std::string input_;
  InputStates state_;
};

class InputStateChangedListener {
 public:
  virtual ~InputStateChangedListener() {}
  virtual void Listen(InputStateChanged&& event) = 0;

 protected:
  InputStateChangedListener() {}
};

}  // namespace events
}  // namespace eventd

#endif  // EVENTD_EVENTS_HPP__
