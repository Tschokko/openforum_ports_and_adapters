#ifndef EVENTD_IMPL_MANAGER__
#define EVENTD_IMPL_MANAGER__

#include <memory>
#include <vector>

#include "../models.hpp"
#include "../outbound_ports.hpp"

namespace eventd {
namespace core {
namespace impl {

using eventd::core::event_check_repo;
// namespace models = eventd::core::models;

class event_check_manager_impl {
 public:
  event_check_manager_impl(std::shared_ptr<event_check_repo> repository)
      : repository_(repository) {}

  void add(models::event_check&& model) {
    repository_->create(std::move(model));
  }

  std::vector<models::event_check> list() { return repository_->all(); }

 private:
  std::shared_ptr<event_check_repo> repository_;
};

}  // namespace impl
}  // namespace core
}  // namespace eventd

#endif  //  EVENTD_IMPL_MANAGER__