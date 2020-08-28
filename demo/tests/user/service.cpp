#include "demo/src/user/core/service.hpp"

#include <memory>
#include <string>

#include "demo/src/user/core/error_codes.hpp"
#include "demo/src/user/core/ports.hpp"
#include "gtest/gtest.h"

using user::core::UserService;
using user::core::models::MakeUser;
using user::core::models::User;
using user::core::models::UserGroups;
using user::core::ports::UserRepository;

class DummyUserRepositoryAdapter : public UserRepository {
 public:
  std::map<std::string, User> users;

  virtual bool Exists(std::string const& username) {
    auto it = users.find(username);
    if (it != users.end()) {
      return true;
    }
    return false;
  }

  virtual void Create(User const& user) { users[user.username()] = user; }
};

TEST(user, AddUser_Successfully) {
  // Arrange
  auto user_repo = std::make_shared<DummyUserRepositoryAdapter>();
  UserService user_service{user_repo};
  std::error_code ec;
  bool is_active = true;
  std::string username = "insys";
  std::string password = "icom";
  UserGroups group = UserGroups::kReadWrite;

  // Act & Assert
  user_service.Add(MakeUser(is_active, username, password, group), ec);

  ASSERT_FALSE(ec);
  ASSERT_TRUE(user_repo->Exists(username));
  ASSERT_EQ(user_repo->users[username].is_active(), is_active);
  ASSERT_EQ(user_repo->users[username].username(), username);
  ASSERT_EQ(user_repo->users[username].password(), password);
  ASSERT_EQ(user_repo->users[username].group(), group);
}

TEST(user, AddUser_Exists) {
  // Arrange
  auto user_repo = std::make_shared<DummyUserRepositoryAdapter>();
  UserService user_service{user_repo};
  std::error_code ec;
  bool is_active = true;
  std::string username = "insys";
  std::string password = "icom";
  UserGroups group = UserGroups::kReadWrite;

  // Act & Assert
  user_service.Add(MakeUser(is_active, username, password, group), ec);
  user_service.Add(MakeUser(is_active, username, password, group), ec);

  ASSERT_TRUE(ec);
  ASSERT_EQ(ec, user::error_codes::user_username_exists);
}

/*TEST(user, AddUser_UsernameRequired) {
  // Arrange
  auto user_repo = std::make_shared<DummyUserRepositoryAdapter>();
  UserService user_service{user_repo};
  std::error_code ec;
  bool is_active = true;
  std::string username = "";
  std::string password = "icom";
  UserGroups group = UserGroups::kReadWrite;

  // Act & Assert
  user_service.Add(MakeUser(is_active, username, password, group), ec);

  ASSERT_TRUE(ec);
  ASSERT_EQ(ec, user::error_codes::user_username_required);
}

TEST(user, AddUser_PasswordRequired) {
  // Arrange
  auto user_repo = std::make_shared<DummyUserRepositoryAdapter>();
  UserService user_service{user_repo};
  std::error_code ec;
  bool is_active = true;
  std::string username = "insys";
  std::string password = "";
  UserGroups group = UserGroups::kReadWrite;

  // Act & Assert
  user_service.Add(MakeUser(is_active, username, password, group), ec);

  ASSERT_TRUE(ec);
  ASSERT_EQ(ec, user::error_codes::user_password_required);
}*/
