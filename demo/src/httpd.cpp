#include <iostream>
#include <memory>

#include "user/core/models.hpp"
#include "user/core/service.hpp"
#include "user/infrastructure/api_handler.hpp"
#include "user/infrastructure/file_user_repository.hpp"

using user::core::UserService;
using user::core::models::UserGroups;
using user::infrastructure::ApiHandler;
using user::infrastructure::FileUserRepositoryAdapter;

int main() {
  auto user_repo = std::make_shared<FileUserRepositoryAdapter>("/tmp/db1.txt");
  auto user_service = std::make_shared<UserService>(user_repo);

  served::multiplexer mux;
  ApiHandler api_handler{user_service};
  api_handler.SetupHandle(mux);

  served::net::server server("0.0.0.0", "8888", mux);
  server.run(10);

  return (EXIT_SUCCESS);
}
