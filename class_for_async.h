#pragma once

#include <chrono>
#include <iostream>
#include <thread>

class Class_for_async_example {
public:
    std::string foo() const;
    std::string bar() const;
    std::string operator()() const;
};
