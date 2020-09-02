#ifndef USER_CORE_SERVICE_HPP__
#define USER_CORE_SERVICE_HPP__

#include <iostream>
#include <memory>

#include "error_codes.hpp"
#include "models.hpp"
#include "ports.hpp"

using user::core::models::User;
using user::core::ports::UserManager;
using user::core::ports::UserRepository;

namespace user {
namespace core {

// UserService is our core domain logic that implements our primary ports
class UserService : public UserManager {
 public:
  typedef std::shared_ptr<UserRepository> UserRepositoryPtr;

  UserService(UserRepositoryPtr repo) : repo_(repo) {}

  void Add(User const& user, std::error_code& ec) {
    if (repo_->Exists(user.username())) {
      ec = user::error_codes::user_username_exists;
      return;
    }
    /*if (user.username().empty()) {
      ec = user::error_codes::user_username_required;
      return;
    }
    if (user.password().empty()) {
      ec = user::error_codes::user_password_required;
      return;
    }*/
    repo_->Create(user);
  }

 private:
  UserService() {}

  UserRepositoryPtr repo_;
};

}  // namespace core
}  // namespace user

#endif  // USER_CORE_SERVICE_HPP__