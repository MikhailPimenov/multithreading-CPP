#include "dowork.h"

void doWork(int a, int b, const std::string &message) {
	std::cout << std::this_thread::get_id() << " =========== doWork(): " << message << std::endl;
	
	std::cout << std::this_thread::get_id() << " =========== doWork(): START " << std::endl;
	std::this_thread::sleep_for(std::chrono::milliseconds(1000));

	std::cout << std::this_thread::get_id() << " =========== doWork(): a + b = " << a + b << std::endl;
	std::this_thread::sleep_for(std::chrono::milliseconds(1000));
	
	std::cout << std::this_thread::get_id() << " =========== doWork(): END " << std::endl;
	std::this_thread::sleep_for(std::chrono::milliseconds(1000));
}
