#pragma once
#include <iostream>

#include "Timer.h"

template <typename T>
double test_parallel_sum(const T& iterable, int max_one_thread_length, int amount_of_tests);
