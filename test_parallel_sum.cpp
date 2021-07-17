#include "test_parallel_sum.h"

template <typename T>
double test_parallel_sum(const T& iterable, int max_one_thread_length, int amount_of_tests) {
    double average_time = 0.0;
    Timer timer;
    for (int i = 0; i < amount_of_tests; ++i) {
        timer.reset();
        std::cout << "The sum is " << parallel_sum(iterable.cbegin(), iterable.cend(), T::value_type(0), max_one_thread_length) << '\n';
        double time = timer.elapsed();
        std::cout << "time = " << time << '\n';
        average_time += time;
    }

    return average_time /= amount_of_tests;
}