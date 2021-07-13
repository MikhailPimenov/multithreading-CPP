#include <chrono>
#include <iostream>
#include <thread>

#include "dowork.h"


int main() {
	std::thread thread1(doWork, 7, 11, "message to pass");
	
	for (int i = 0; i < 10; ++i) {
		std::cout << std::this_thread::get_id() << " main() " << i << std::endl;
		std::this_thread::sleep_for(std::chrono::milliseconds(250));
	}

	thread1.join(); // stop and wait here unless thread1 finishes
	//thread1.detach(); // do not wait here for thread1

	return 0;
}