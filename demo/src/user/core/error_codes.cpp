#include "error_codes.hpp"

#include <string>

namespace {  // anonymous namespace

struct user_error_category : std::error_category {
  const char* name() const noexcept override;
  std::string message(int ev) const override;
};

const char* user_error_category::name() const noexcept { return "user"; }

std::string user_error_category::message(int ev) const {
  switch (static_cast<user::error_codes>(ev)) {
    case user::error_codes::user_username_exists:
      return "username exists already";
    case user::error_codes::user_username_required:
      return "username is required";
    case user::error_codes::user_password_required:
      return "password is required";
    default:
      return "(unrecognized error)";
  }
}

const user_error_category g_user_error_category{};

}  // anonymous namespace

namespace user {
std::error_code make_error_code(user::error_codes ec) {
  return {static_cast<int>(ec), g_user_error_category};
}
}  // namespace user