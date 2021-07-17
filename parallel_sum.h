#pragma once

#include <algorithm>
#include <numeric>
#include <future>

template <typename RandomIt>
extern typename RandomIt::value_type parallel_sum(
	RandomIt beg, 
	RandomIt end, 
	typename RandomIt::value_type initial_sum, 
	std::size_t one_thread_length
);

//template <typename T>
//T gagaga(T);