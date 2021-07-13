#include "dowork.h"

void doWork(int &a) {
	std::cout << std::this_thread::get_id() << " =========== doWork(): START " << std::endl;
	std::this_thread::sleep_for(std::chrono::milliseconds(1000));

	a *= 2;
	std::this_thread::sleep_for(std::chrono::milliseconds(1000));
	
	std::cout << std::this_thread::get_id() << " =========== doWork(): END " << std::endl;
	std::this_thread::sleep_for(std::chrono::milliseconds(1000));
}
