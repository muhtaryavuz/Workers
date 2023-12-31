
#include <iostream>
#include "EventExecutor.hpp"

void worker_utility::EventExecutor::operator()(const std::shared_ptr<worker_utility::Event1> event) const 
{
    std::cout<< "Executing " << event->id <<"...\n";
    for (int i = 0; i < 10000; i++);
}

void worker_utility::EventExecutor::operator()(const std::shared_ptr<worker_utility::Event2> event) const 
{
    std::cout<< "Executing " << event->id <<"...\n";
    for (int i = 0; i < 1000; i++);
}