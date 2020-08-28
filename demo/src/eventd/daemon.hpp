#ifndef EVENTD_DAEMON_HPP__
#define EVENTD_DAEMON_HPP__

#include <memory>

#include "actions.hpp"
#include "events.hpp"

namespace eventd {

class Daemon {
 public:
  typedef std::shared_ptr<actions::InfoLedAction> InfoLedActionPtr;

  Daemon(InfoLedActionPtr const& info_led_action)
      : info_led_action_(info_led_action) {}

  int Run() {
    info_led_action_->Blink();
    return 0;
  }

 protected:
  Daemon() {}  // prevent instanciating a daemon class without required services

 private:
  InfoLedActionPtr info_led_action_;
};

}  // namespace eventd

#endif  // EVENTD_DAEMON_HPP__
