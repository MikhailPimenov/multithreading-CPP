#include <vector>

#include "parallel_sum.h"
#include "SlowIntSum.h"

#include "test_parallel_sum.cpp"

using iterable_type = std::vector<SlowIntSum>;

template double test_parallel_sum<iterable_type>(const iterable_type&, int, int);
