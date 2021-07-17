#include <iostream>
#include <vector>

#include "SlowIntSum.h"
#include "test_parallel_sum.h"  

int main() {
    std::cout << "threads available: " << std::thread::hardware_concurrency() << '\n';
    const int length = 64;
    const std::vector <SlowIntSum> vector = [=]() {
        std::vector <SlowIntSum> temp;
        temp.reserve(length);

        for (std::size_t i = 0; i < length; ++i)
            temp.push_back(SlowIntSum(1, 5));

        return std::move(temp);
    }();

    const double time1 = test_parallel_sum(vector, 16384u, 10);
    const double time2 = test_parallel_sum(vector, 2u, 10);
    std::cout << "average time = " << time1 << std::endl;
    std::cout << "average time = " << time2 << std::endl;

    const double ratio = time1 / time2;
    std::cout << "time1 / time2 = " << ratio << std::endl;
    return 0;
}