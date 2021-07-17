#include <iostream>
#include <future>
#include <string>

#include "class_for_async.h"


int main() {
    
    Class_for_async_example x;
    std::future<std::string> future_foo = std::async(std::launch::async, &Class_for_async_example::foo, &x);
    std::this_thread::sleep_for(std::chrono::milliseconds(10));
    
    std::future<std::string> future_bar = std::async(std::launch::deferred, &Class_for_async_example::bar, &x);
    
    std::this_thread::sleep_for(std::chrono::milliseconds(10));
    std::future<std::string> future_operator = std::async(std::launch::async, &Class_for_async_example::operator(), &x);


    std::this_thread::sleep_for(std::chrono::milliseconds(2000));
    
    std::cout << "\ncalling future_bar.wait():\n";
    future_bar.wait();
    
    std::cout << "\ncalling future_operator.get():\n";
    std::cout << future_operator.get() << '\n';

    return 0;
}