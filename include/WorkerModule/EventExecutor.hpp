#pragma once

#include "Events.hpp"

namespace worker_utility {
class EventExecutor {
  public:
  void operator()(const std::shared_ptr<Event1> ) const;
  void operator()(const std::shared_ptr<Event2> ) const;
};
}  // namespace worker_utility