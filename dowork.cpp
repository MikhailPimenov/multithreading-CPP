#include "dowork.h"

std::mutex g_mutex;

void doWork(char symbol) {
	std::cout << std::this_thread::get_id() << " =========== doWork(): START " << std::endl;
	std::this_thread::sleep_for(std::chrono::milliseconds(5000));

	g_mutex.lock();
	for (int i = 0; i < 10; ++i) {
		for (int j = 0; j < 20; ++j) {
			std::cout << symbol;
        	std::this_thread::sleep_for(std::chrono::milliseconds(1));
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
	g_mutex.unlock();

	std::cout << std::this_thread::get_id() << " =========== doWork(): END " << std::endl;
	std::this_thread::sleep_for(std::chrono::milliseconds(5000));
}
