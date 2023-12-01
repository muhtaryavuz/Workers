#pragma once

#include <string>
#include <variant>
#include <memory>

namespace worker_utility {
struct Event1 {
  std::string id{"event_1"};
};

struct Event2 {
  std::string id{"event_2"};
};

using worker_variant_t =
    std::variant<std::shared_ptr<Event1>, std::shared_ptr<Event2>>;
}  // namespace worker_utility