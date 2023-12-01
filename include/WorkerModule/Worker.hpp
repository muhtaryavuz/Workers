#pragma once

#include <condition_variable>
#include <mutex>
#include <queue>
#include <thread>
#include <iostream>

#include "EventExecutor.hpp"
#include "Publishable.hpp"

namespace worker_utility {
class Worker {
  int m_id{-1};
  std::queue<worker_variant_t> m_queue;
  std::unique_ptr<std::thread> m_thread;
  std::shared_ptr<Publishable> m_publisher;
  std::mutex m_mutex;
  std::condition_variable m_cv;  
  bool m_is_running{true};

 public:
  explicit Worker(int, std::shared_ptr<Publishable>);
  ~Worker();

  void init(std::string);
  void insertToQueue(worker_variant_t const&);
  std::size_t getQueueSize();
  void stopExecution();

 private:
  void process();
};
}  // namespace worker_utility