#ifndef USER_CORE_ERROR_CODES_HPP_
#define USER_CORE_ERROR_CODES_HPP_

#include <system_error>

namespace user {
enum class error_codes {
  // no 0
  user_username_exists = 1,
  user_username_required = 2,
  user_password_required = 3
};
}  // namespace user

namespace std {
template <>
struct is_error_code_enum<user::error_codes> : true_type {};
}  // namespace std

namespace user {
std::error_code make_error_code(user::error_codes);
}

#endif  // USER_CORE_ERROR_CODES_HPP_