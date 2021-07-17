#include "parallel_sum.h"

template <typename RandomIt>
typename RandomIt::value_type parallel_sum(
    RandomIt beg, 
    RandomIt end, 
    typename RandomIt::value_type initial_sum, 
    std::size_t one_thread_length
)
{
    auto len = end - beg;
    if (len < one_thread_length)
        return std::accumulate(beg, end, initial_sum);

    RandomIt mid = beg + len / 2;
    auto handle = std::async(std::launch::async,
        parallel_sum<RandomIt>, mid, end, initial_sum, one_thread_length);
    typename RandomIt::value_type sum = parallel_sum(beg, mid, initial_sum, one_thread_length);
    
    return sum + handle.get();
}
