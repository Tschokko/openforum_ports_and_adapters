#include "demo/src/eventd/daemon.hpp"

#include <memory>

#include "demo/src/eventd/core/actions.hpp"
#include "gtest/gtest.h"

class info_led_action_dummy : public eventd::action::info_led {
 public:
  bool is_on = false;
  bool is_off = false;
  bool is_blinking = false;

  void on() { is_on = true; };
  void off() { is_off = true; };
  void blink() { is_blinking = true; };
};

TEST(eventd_daemon, run_sets_led_to_blinking) {
  // Arrange
  auto info_led_action = std::make_shared<info_led_action_dummy>();
  eventd::daemon daemon{info_led_action};
  daemon.set_no_log();

  // Act & Assert
  auto rc = daemon.run();
  ASSERT_EQ(rc, 0);
  ASSERT_TRUE(info_led_action->is_blinking);
}
