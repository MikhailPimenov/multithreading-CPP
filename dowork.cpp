#include "dowork.h"

std::mutex g_mutex;

void doWork(char symbol) {
	std::cout << std::this_thread::get_id() << " =========== doWork(): START " << std::endl;

	std::unique_lock<std::mutex> ulock(g_mutex, std::defer_lock); // std::defer_lock is needed to not lock the mutex

	std::this_thread::sleep_for(std::chrono::milliseconds(5000));
	
	ulock.lock();
	for (int i = 0; i < 10; ++i) {
		for (int j = 0; j < 20; ++j) {
			std::cout << symbol;
			// any function that can throw an exception because 
			// when unique_lock leaves scope in its destructor mutex becomes unlocked
			std::this_thread::sleep_for(std::chrono::milliseconds(1));
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
	ulock.unlock();
	

	std::cout << std::this_thread::get_id() << " =========== doWork(): END " << std::endl;
	std::this_thread::sleep_for(std::chrono::milliseconds(5000));
}
