#include "class_for_async.h"

std::string Class_for_async_example::foo() const {
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    std::cout << "foo() START\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    std::cout << "foo() FINISH\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(100));

    return "result from foo()";
}

std::string Class_for_async_example::bar() const {
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    std::cout << "bar() START\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    std::cout << "bar() FINISH\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(100));

    return "result from bar()";
}

std::string Class_for_async_example::operator()() const {
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    std::cout << "operator() START\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    std::cout << "operator() FINISH\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(100));

    return "result from operator()";
}

