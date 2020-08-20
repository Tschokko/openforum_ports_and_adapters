#include <iostream>
#include <memory>

#include "daemon.hpp"
#include "impl/info_led_console_action.hpp"

int main() {
  auto info_led_action =
      std::make_shared<eventd::impl::info_led_console_action>();
  eventd::daemon daemon{info_led_action};
  return daemon.run();
}
