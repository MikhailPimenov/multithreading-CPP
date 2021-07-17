#pragma once

#include <chrono>
#include <iostream>
#include <thread>
#include <cassert>

class SlowIntSum final {
private:
    int m_number;
    int m_sum_delay_ms;
public:
    SlowIntSum(); 
    SlowIntSum(int number, int delay = 20);


    SlowIntSum operator+(const SlowIntSum& object);

    friend std::ostream& operator<<(std::ostream& out, const SlowIntSum& object);
};
