#include "SlowIntSum.h"

SlowIntSum::SlowIntSum() : m_number(0), m_sum_delay_ms(20) {

}
SlowIntSum::SlowIntSum(int number, int delay) : m_number(number), m_sum_delay_ms(delay) {
    assert(m_sum_delay_ms >= 0 && "Delay can not be negative!");
}

SlowIntSum SlowIntSum::operator+(const SlowIntSum& object) {
    //std::cout << "operator '+' as method\n";
    
    
    // with that it executes faster with concurrent threads
    std::this_thread::sleep_for(std::chrono::milliseconds(this->m_sum_delay_ms)); 
    

    // with that it does not execute faster with concurrent threads
    // might be because of additional work to do when creating new thread
    /*int a = 0;
    for (int i = 0; i < 1000; ++i)
        for (int j = 0; j < 1000; ++j)
            ++a;*/

    return SlowIntSum(this->m_number + object.m_number);
}

std::ostream& operator<<(std::ostream& out, const SlowIntSum& object) {
    out << object.m_number;
    return out;
}
