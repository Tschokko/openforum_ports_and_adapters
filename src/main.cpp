#include <iostream>
#include <memory>

#include "eventd/core/impl/file_repository.hpp"
#include "eventd/core/impl/manager.hpp"
#include "eventd/core/models.hpp"

using eventd::core::impl::event_check_file_repo;
using eventd::core::impl::event_check_manager_impl;
using eventd::core::models::event_check;
using eventd::core::models::make_event_check;

int main() {
  std::cout << "Starting eventd" << std::endl;

  auto repo = std::make_shared<event_check_file_repo>("/tmp/db.txt");
  event_check_manager_impl mgr{repo};


  // mgr.add(std::move(make_event_check("test3")));
  // mgr.add(std::move(make_event_check("test4")));

  auto results = mgr.list();
  for (auto const& v : results) {
    std::cout << v.id() << " => " << v.description() << std::endl;
  }

  return 0;
}
