#include "demo/src/eventd/daemon.hpp"

#include <memory>

#include "demo/src/eventd/actions.hpp"
#include "demo/src/eventd/events.hpp"
#include "gtest/gtest.h"

class InfoLEDActionDummy : public eventd::actions::InfoLED {
 public:
  bool is_on = false;
  bool is_off = false;
  bool is_blinking = false;

  void On() { is_on = true; };
  void Off() { is_off = true; };
  void Blink() { is_blinking = true; };
};

TEST(eventd_daemon, run_sets_led_to_blinking) {
  // Arrange
  auto info_led_action = std::make_shared<InfoLEDActionDummy>();
  eventd::Daemon daemon{info_led_action};

  // Act & Assert
  auto rc = daemon.Run();

  ASSERT_EQ(rc, 0);
  ASSERT_TRUE(info_led_action->is_blinking);
  ASSERT_FALSE(info_led_action->is_on);
  ASSERT_FALSE(info_led_action->is_off);
}
