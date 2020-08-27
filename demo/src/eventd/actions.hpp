#ifndef EVENTD_ACTIONS_HPP__
#define EVENTD_ACTIONS_HPP__

namespace eventd {
namespace actions {

class InfoLED {
 public:
  virtual ~InfoLED() {}
  virtual void On() = 0;
  virtual void Off() = 0;
  virtual void Blink() = 0;

 protected:
  InfoLED() {}
};

}  // namespace actions
}  // namespace eventd

#endif  // EVENTD_ACTIONS_HPP__
