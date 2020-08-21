#ifndef EVENTD_DAEMON_HPP__
#define EVENTD_DAEMON_HPP__

#include <iostream>
#include <memory>

#include "actions.hpp"

namespace eventd {

class daemon {
 protected:
  daemon() {}  // prevent instanciation of a daemon without required services

 public:
  daemon(std::shared_ptr<action::info_led> action_info_led)
      : action_info_led_(action_info_led) {}

  void handle_event() { action_info_led_->blink(); }

 private:
  std::shared_ptr<action::info_led> action_info_led_;
};

}  // namespace eventd

#endif  // EVENTD_DAEMON_HPP__
