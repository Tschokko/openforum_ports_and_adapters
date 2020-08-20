#ifndef EVENTD_IMPL_FILE_REPOSITORY__
#define EVENTD_IMPL_FILE_REPOSITORY__

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#include "../outbound_ports.hpp"

using eventd::core::event_check_repo;

namespace eventd {
namespace core {
namespace impl {

class event_check_file_repo : public event_check_repo {
 public:
  explicit event_check_file_repo(std::string const& file_name)
      : file_name_(file_name) {}

  int create(models::event_check&& model) {
    auto id = next_id();

    std::fstream file;
    file.open(file_name_, std::ios::out | std::ios::app);
    if (!file.is_open()) {
      std::cerr << "could not open file: " << file_name_ << std::endl;
    }
    file << id << "," << model.description() << "\n";
    file.close();

    std::cout << "wrote event_check with id: " << id << std::endl;

    return id;
  }

  std::vector<models::event_check> all() {
    std::vector<models::event_check> rows = {};

    std::ifstream file(file_name_);
    std::string str;
    while (std::getline(file, str)) {
      auto model = scanline(str);
      rows.push_back(std::move(model));
    }

    return rows;
  }

 private:
  std::string file_name_;

  int next_id() {
    int id = 0;

    std::ifstream file(file_name_);
    std::string str;
    while (std::getline(file, str)) {
      auto model = scanline(str);
      if (model.id() > id) {
        id = model.id();
      }
    }

    return ++id;
  }

  eventd::core::models::event_check scanline(std::string const& s) {
    char delim = ',';
    std::vector<std::string> columns;
    std::stringstream ss(s);
    std::string item;

    while (getline(ss, item, delim)) {
      columns.push_back(item);
    }

    int id = atoi(columns[0].c_str());
    auto description = columns[1];

    return eventd::core::models::make_event_check(id, description);
  }
};

}  // namespace impl
}  // namespace core
}  // namespace eventd

#endif  // EVENTD_IMPL_FILE_REPOSITORY__
