#ifndef EVENTD_CORE_EVENTS_HPP__
#define EVENTD_CORE_EVENTS_HPP__

namespace eventd {
namespace event {

enum class event_types : int { profile_changed = 1 };

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

}  // namespace event
}  // namespace eventd

#endif  // EVENTD_CORE_EVENTS_HPP__
