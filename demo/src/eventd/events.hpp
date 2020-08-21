#ifndef EVENTD_EVENTS_HPP__
#define EVENTD_EVENTS_HPP__

#include <string>

namespace eventd {
namespace event {

//------------------------------------------------------------------------------
// base event
//------------------------------------------------------------------------------

enum class event_types : int { profile_changed = 1, io_changed = 2 };

class base {
 public:
  virtual ~base() {}

  event_types type() const { return type_; }

 protected:
  base(event_types typ) : type_(typ) {}

 private:
  event_types type_;

  base() {}
};

//------------------------------------------------------------------------------
// profile changed event
//------------------------------------------------------------------------------

enum class profile_changed_states : int { modified = 1, activated = 2 };

class profile_changed : public base {
 public:
  profile_changed(profile_changed_states state)
      : base(event_types::profile_changed), state_(state) {}

 private:
  profile_changed_states state_;
};

profile_changed make_profile_changed(profile_changed_states state) {
  return profile_changed{state};
}

//------------------------------------------------------------------------------
// io changed event
//------------------------------------------------------------------------------
enum class io_changed_states : int { high = 1, low = 2, pulse = 3 };

class io_changed : public base {
 public:
  io_changed(std::string const& input, io_changed_states state)
      : base(event_types::io_changed), input_(input), state_(state) {}

 private:
  std::string input_;
  io_changed_states state_;
};

io_changed make_io_changed(std::string const& input, io_changed_states state) {
  return io_changed{input, state};
}

}  // namespace event
}  // namespace eventd

#endif  // EVENTD_EVENTS_HPP__
