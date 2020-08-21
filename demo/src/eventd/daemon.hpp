#ifndef EVENTD_DAEMON_HPP__
#define EVENTD_DAEMON_HPP__

#include <iostream>
#include <memory>

#include "actions.hpp"
#include "events.hpp"

namespace eventd {

class daemon {
 protected:
  daemon() {}  // prevent instanciation of a daemon without required services

 public:
  daemon(std::shared_ptr<action::info_led> action_info_led)
      : action_info_led_(action_info_led) {}

  void handle_event(event::base const& ev) {
    switch (ev.type()) {
      case event::event_types::profile_changed:
        action_info_led_->blink();
        break;
    }
  }

  void set_no_log() { no_log_ = true; }

 private:
  bool no_log_ = false;
  std::shared_ptr<action::info_led> action_info_led_;

  void log(std::string const& s) const {
    if (!no_log_) std::cout << "[eventd] " << s << std::endl;
  }
};

}  // namespace eventd

#endif  // EVENTD_DAEMON_HPP__
