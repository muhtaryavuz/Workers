#include <iostream>
#include "WorkerController.hpp"

int main() {
  worker_utility::WorkerController worker_controller(20, std::make_shared<worker_utility::LoadBalanceStrategy>());

  auto event1 = std::make_shared<worker_utility::Event1>();
  auto event2 = std::make_shared<worker_utility::Event2>();
  worker_utility::worker_variant_t my_var_1 = event1;
  worker_utility::worker_variant_t my_var_2 = event2;

  while (true) {
    for (int i = 0; i < 1000; i++) {
      worker_controller.sendToWorkers(my_var_1);
      worker_controller.sendToWorkers(my_var_2);
    }
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
  }
}