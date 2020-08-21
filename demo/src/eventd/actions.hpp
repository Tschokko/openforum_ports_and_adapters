#ifndef EVENTD_ACTIONS_HPP__
#define EVENTD_ACTIONS_HPP__

namespace eventd {
namespace action {

class info_led {
 protected:
  info_led() {}

 public:
  virtual ~info_led() {}
  virtual void on() = 0;
  virtual void off() = 0;
  virtual void blink() = 0;
};

}  // namespace action
}  // namespace eventd

#endif  // EVENTD_ACTIONS_HPP__
