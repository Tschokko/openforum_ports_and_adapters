#include <iostream>
#include <memory>

#include "user/core/models.hpp"
#include "user/core/service.hpp"
#include "user/infrastructure/file_user_repository.hpp"

using user::core::UserService;
using user::core::models::UserGroups;
using user::infrastructure::FileUserRepositoryAdapter;

int main() {
  auto user_repo = std::make_shared<FileUserRepositoryAdapter>("/tmp/db1.txt");
  UserService user_service{user_repo};
  std::error_code ec;
  user_service.Add(user::core::models::MakeUser(true, "insys", "icom",
                                                UserGroups::kReadWrite),
                   ec);
  if (ec) {
    std::cerr << ec.message() << std::endl;
    return 1;
  }

  return 0;
}
