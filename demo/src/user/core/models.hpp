#ifndef USER_MODELS_HPP__
#define USER_MODELS_HPP__

#include <string>

namespace user {
namespace core {
namespace models {

enum class UserGroups : int { kReadWrite = 1, kRead = 2, kStatus = 3 };

class User {
 public:
  User() {}
  User(bool is_active, std::string const& username, std::string const& password,
       UserGroups group)
      : is_active_(is_active),
        username_(username),
        password_(password),
        group_(group) {}

  bool is_active() const { return is_active_; }
  void set_is_active(bool is_active) { is_active_ = is_active; }
  std::string username() const { return username_; }
  void set_username(std::string const& username) { username_ = username; }
  std::string password() const { return password_; }
  void set_password(std::string const& password) { password_ = password; }
  UserGroups group() const { return group_; }
  void set_group(UserGroups group) { group_ = group; }

 private:
  bool is_active_;
  std::string username_;
  std::string password_;
  UserGroups group_;
};

inline User MakeUser(bool is_active, std::string const& username,
                     std::string const& password, UserGroups group) {
  return User(is_active, username, password, group);
}

}  // namespace models
}  // namespace core
}  // namespace user

#endif  // USER_MODELS_HPP__
