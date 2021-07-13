#include <chrono>
#include <iostream>
#include <thread>

#include "dowork.h"


int main() {
	int result = 5;
	std::cout << result << std::endl;

	std::thread thread1(doWork, std::ref(result));
	
	for (int i = 0; i < 10; ++i) {
		std::cout << std::this_thread::get_id() << " main() " << i << std::endl;
		std::this_thread::sleep_for(std::chrono::milliseconds(250));
	}


	thread1.join();            // stop and wait here unless thread1 finishes
	//thread1.detach();        // in case of using detach() it is important 
	                           // to call detach() after result changes in doWork
	
	std::cout << result << std::endl;

	return 0;
}