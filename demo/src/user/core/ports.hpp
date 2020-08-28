#ifndef USER_PORTS_HPP__
#define USER_PORTS_HPP__

#include <string>

#include "models.hpp"

using user::core::models::User;

namespace user {
namespace core {
namespace ports {

// UserManager is a primary port for driving our domain logic
class UserManager {
 public:
  virtual ~UserManager() = default;
  virtual void Add(User const& user, std::error_code& ec) = 0;

 protected:
  UserManager() {}
};

// UserRepository is a secondary port which is consumed by our domain logic
class UserRepository {
 public:
  virtual ~UserRepository() = default;
  virtual bool Exists(std::string const& username) = 0;
  virtual void Create(User const& user) = 0;

 protected:
  UserRepository() {}
};

}  // namespace ports
}  // namespace core
}  // namespace user

#endif  // USER_PORTS_HPP__