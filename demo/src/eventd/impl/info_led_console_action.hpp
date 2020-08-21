#ifndef EVENTD_IMPL_INFO_LED_CONSOLE_ACTION_HPP__
#define EVENTD_IMPL_INFO_LED_CONSOLE_ACTION_HPP__

#include <iostream>

#include "../actions.hpp"

namespace eventd {
namespace impl {

class info_led_console_action : public action::info_led {
 public:
  void on() { std::cout << "info led on" << std::endl; };
  void off() { std::cout << "info led off" << std::endl; };
  void blink() { std::cout << "info led blinking" << std::endl; };
};

}  // namespace impl
}  // namespace eventd

#endif  // EVENTD_IMPL_INFO_LED_CONSOLE_ACTION_HPP__
