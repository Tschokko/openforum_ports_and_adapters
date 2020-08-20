#ifndef EVENTD_SERVICES_HPP__
#define EVENTD_SERVICES_HPP__

#include <memory>

#include "models.hpp"

namespace eventd {
namespace core {

class event_check_manager {
 protected:
  event_check_manager() {}

 public:
  virtual ~event_check_manager() {}
  virtual void add(models::event_check&& model) = 0;
};

}  // namespace core
}  // namespace eventd

#endif  // EVENTD_SERVICES_HPP__
