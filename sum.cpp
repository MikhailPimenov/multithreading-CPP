#include "sum.h"

int sum(int a, int b) {
    std::cout << "id: " << std::this_thread::get_id() << " ========== sum(): STARTED" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(2000));

    std::cout << "id: " << std::this_thread::get_id() << " ========== sum(): CALCULATING" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(2000));
    int result = a + b;

    std::this_thread::sleep_for(std::chrono::milliseconds(2000));
    std::cout << "id: " << std::this_thread::get_id() << " ========== sum(): FINISHED" << std::endl;
    
    return result;
}
