#include "file_user_repository.hpp"

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using user::core::models::MakeUser;
using user::core::models::User;
using user::core::models::UserGroups;

namespace user {
namespace infrastructure {

namespace helper {
static User scanline(std::string const& s) {
  char delim = ';';
  std::vector<std::string> columns;
  std::stringstream ss(s);
  std::string item;

  while (getline(ss, item, delim)) {
    columns.push_back(item);
  }

  bool is_active = atoi(columns[0].c_str());
  auto username = columns[1];
  auto password = columns[2];
  UserGroups group = static_cast<UserGroups>(atoi(columns[3].c_str()));

  return MakeUser(is_active, username, password, group);
}
}  // namespace helper

bool FileUserRepositoryAdapter::Exists(std::string const& username) {
  std::ifstream file(file_path_);
  std::string s;
  while (std::getline(file, s)) {
    auto user = helper::scanline(s);
    if (user.username() == username) return true;
  }

  return false;
}

inline void FileUserRepositoryAdapter::Create(User const& user) {
  std::fstream file;
  file.open(file_path_, std::ios::out | std::ios::app);
  if (!file.is_open()) {
    std::cerr << "could not open file: " << file_path_ << std::endl;
    // TODO(DGL) Set an error code here
    return;
  }
  file << user.is_active() << ";" << user.username() << ";" << user.password()
       << ";" << static_cast<int>(user.group()) << "\n";
  file.close();
}

}  // namespace infrastructure
}  // namespace user