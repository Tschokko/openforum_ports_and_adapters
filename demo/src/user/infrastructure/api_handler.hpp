#ifndef USER_INFRASTRUCTURE_API_HANLDER_HPP__
#define USER_INFRASTRUCTURE_API_HANLDER_HPP__

#include <memory>
#include <sstream>
#include <string>

#include "../core/models.hpp"
#include "../core/ports.hpp"
#include "boost/property_tree/json_parser.hpp"
#include "served/served.hpp"

using user::core::models::MakeUser;
using user::core::models::UserGroups;
using user::core::ports::UserManager;

namespace user {
namespace infrastructure {

class ApiHandler {
 public:
  typedef std::shared_ptr<UserManager> UserManagerPtr;

  ApiHandler(UserManagerPtr user_manager) : user_manager_(user_manager) {}

  void SetupHandle(served::multiplexer& mux) {
    mux.handle("/users").post(
        [&](served::response& res, const served::request& req) {
          // Stream body to a string stream for our json parser
          std::stringstream ss;
          ss << req.body();

          // Parse json payload
          boost::property_tree::ptree data;
          boost::property_tree::read_json(ss, data);

          auto is_active = data.get<bool>("active");
          auto username = data.get<std::string>("username");
          auto password = data.get<std::string>("password");
          auto group = static_cast<UserGroups>(data.get<int>("group"));

          // Add a new user thru our primary port
          auto user = MakeUser(is_active, username, password, group);
          std::error_code ec;
          user_manager_->Add(user, ec);

          res.set_status(201);
        });
  }

 private:
  UserManagerPtr user_manager_;
};

}  // namespace infrastructure
}  // namespace user

#endif  // USER_INFRASTRUCTURE_API_HANLDER_HPP__
