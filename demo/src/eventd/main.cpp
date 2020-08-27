#include <iostream>
#include <memory>

#include "daemon.hpp"
#include "impl/console_info_led.hpp"

int main() {
  auto info_led_action =
      std::make_shared<eventd::actions::impl::ConsoleInfoLED>();
  eventd::Daemon daemon{info_led_action};
  return daemon.Run();
}
