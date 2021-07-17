#include "parallel_sum.cpp"

#include <vector>

#include "SlowIntSum.h"

using value_type = SlowIntSum;
using iterator_type = std::vector<value_type>::const_iterator;

template value_type parallel_sum<iterator_type>(
	iterator_type,
	iterator_type,
	value_type,
	std::size_t
);
