#ifndef EVENTD_IMPL_CONSOLE_INFO_LED_ACTION_HPP__
#define EVENTD_IMPL_CONSOLE_INFO_LED_ACTION_HPP__

#include <iostream>

#include "../actions.hpp"

namespace eventd {
namespace actions {
namespace impl {

class ConsoleInfoLED : public actions::InfoLED {
 public:
  void On() { std::cout << "info led on" << std::endl; };
  void Off() { std::cout << "info led off" << std::endl; };
  void Blink() { std::cout << "info led blinking" << std::endl; };
};

}  // namespace impl
}  // namespace actions
}  // namespace eventd

#endif  // EVENTD_IMPL_CONSOLE_INFO_LED_ACTION_HPP__
