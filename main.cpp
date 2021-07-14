#include <chrono>
#include <iostream>
#include <thread>

#include "sum.h"

int main() {
	int result = 5;
	std::cout << result << std::endl;

	std::thread thread1([&result](){ result = sum(7, 12); });
	
	for (int i = 0; i < 10; ++i) {
		std::cout << std::this_thread::get_id() << " main() " << i << std::endl;
		std::this_thread::sleep_for(std::chrono::milliseconds(250));
	}
	
	thread1.join();
	std::cout << result << std::endl;

	return 0;
}