#ifndef EVENTD_CORE_EVENT_HANDLER_HPP__
#define EVENTD_CORE_EVENT_HANDLER_HPP__

#include "events.hpp"

namespace eventd {
namespace event {

class handler {
 public:
  virtual ~handler() {}

  virtual void handle_event(base const& ev) = 0;

 protected:
  handler() {}
};

}  // namespace event
}  // namespace eventd

#endif  // EVENTD_CORE_EVENT_HANDLER_HPP__
