#ifndef EVENTD_DAEMON_HPP__
#define EVENTD_DAEMON_HPP__

#include <iostream>
#include <memory>

#include "core/actions.hpp"


namespace eventd {

class daemon {
 protected:
  daemon() {}  // prevent instanciating a daemon class without required services

 public:
  daemon(std::shared_ptr<action::info_led> action_info_led)
      : action_info_led_(action_info_led) {}

  int run() {
    log("daemon started");
    log("set info led to blinking");
    action_info_led_->blink();

    return 0;
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
