#ifndef USER_INFRASTRUCTURE_FILE_USER_REPOSITORY_HPP__
#define USER_INFRASTRUCTURE_FILE_USER_REPOSITORY_HPP__

#include <fstream>
#include <sstream>
#include <string>
#include <vector>

#include "../core/models.hpp"
#include "../core/ports.hpp"

using user::core::models::User;
using user::core::ports::UserRepository;

namespace user {
namespace infrastructure {

// FileUserRepositoryAdapter is a secondary adapter (driven by domain) and
// implements the UserRepository secondary port
class FileUserRepositoryAdapter : public UserRepository {
 public:
  FileUserRepositoryAdapter(std::string const& file_path)
      : file_path_(file_path) {}

  bool Exists(std::string const& username);

  void Create(User const& user);

 private:
  std::string file_path_;
};

}  // namespace infrastructure
}  // namespace user

#endif  // USER_INFRASTRUCTURE_FILE_USER_REPOSITORY_HPP__