#ifndef EVENTD_ENITITIES_HPP__
#define EVENTD_ENITITIES_HPP__

#include <string>

namespace eventd {
namespace core {
namespace models {

class event_check {
 public:
  event_check(){};
  explicit event_check(std::string const& description)
      : description_(description) {}
  event_check(int id, std::string const& description)
      : id_(id), description_(description) {}
  event_check(event_check const& other) = delete;
  event_check(event_check&& other) {
    id_ = other.id_;
    description_ = std::move(other.description_);
  }

  event_check& operator=(event_check const& other) = delete;
  event_check& operator=(event_check&& other) {
    if (this == &other) {
      return *this;
    }

    id_ = other.id_;
    description_ = std::move(other.description_);

    return *this;
  }

  int id() const { return id_; }
  std::string description() const { return description_; }

 private:
  int id_ = 0;
  std::string description_;
  // event
  // condition
  // action
};

event_check make_event_check(std::string const& description) {
  return event_check(description);
}

event_check make_event_check(int id, std::string const& description) {
  return event_check(id, description);
}

}  // namespace models
}  // namespace core
}  // namespace eventd

#endif  // EVENTD_ENITITIES_HPP__
