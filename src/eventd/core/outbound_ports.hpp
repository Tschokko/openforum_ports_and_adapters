#ifndef EVENTD_PROVIDERS_HPP__
#define EVENTD_PROVIDERS_HPP__

#include <string>

#include "models.hpp"

namespace eventd {
namespace core {

class event_check_repo {
 protected:
  event_check_repo() {}

 public:
  virtual ~event_check_repo() {}
  virtual std::vector<models::event_check> all() = 0;
  virtual int create(models::event_check&& model) = 0;
};

}  // namespace core
}  // namespace eventd

#endif  // EVENTD_PROVIDERS_HPP__
