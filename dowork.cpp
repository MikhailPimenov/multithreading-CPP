#include "dowork.h"

std::mutex g_mutex1;
std::mutex g_mutex2;


void doWork_with_deadlock(char symbol) {
	std::cout << std::this_thread::get_id() << " Dead lock warning =========== doWork(): START " << std::endl;
	
	g_mutex1.lock(); // order of locking mutexes got to be the same
	std::this_thread::sleep_for(std::chrono::milliseconds(5000));
	g_mutex2.lock(); // order of locking mutexes got to be the same

	for (int i = 0; i < 10; ++i) {
		for (int j = 0; j < 20; ++j) {
			std::cout << symbol;
			std::this_thread::sleep_for(std::chrono::milliseconds(1));
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
	g_mutex2.unlock();
	g_mutex1.unlock();
	
	std::cout << std::this_thread::get_id() << " =========== doWork(): END " << std::endl;
	std::this_thread::sleep_for(std::chrono::milliseconds(5000));
}

void doWork_with_deadlock2(char symbol) {
	std::cout << std::this_thread::get_id() << " Dead lock warning =========== doWork(): START " << std::endl;
	
	g_mutex2.lock(); // order of locking mutexes got to be the same (here it is violated causing dead lock)
	std::this_thread::sleep_for(std::chrono::milliseconds(5000));
	g_mutex1.lock(); // order of locking mutexes got to be the same (here it is violated causing dead lock)
	
	for (int i = 0; i < 5; ++i) {
		for (int j = 0; j < 40; ++j) {
			std::cout << symbol;
			std::this_thread::sleep_for(std::chrono::milliseconds(1));
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
	g_mutex1.unlock();
	g_mutex2.unlock();

	std::cout << std::this_thread::get_id() << " =========== doWork(): END " << std::endl;
	std::this_thread::sleep_for(std::chrono::milliseconds(5000));
}



std::mutex g_mutex3;
std::mutex g_mutex4;


void doWork3(char symbol) {
	std::cout << std::this_thread::get_id() << " =========== doWork(): START " << std::endl;

	g_mutex3.lock(); // order of locking mutexes got to be the same
	std::this_thread::sleep_for(std::chrono::milliseconds(5000));
	g_mutex4.lock(); // order of locking mutexes got to be the same

	for (int i = 0; i < 10; ++i) {
		for (int j = 0; j < 20; ++j) {
			std::cout << symbol;
			std::this_thread::sleep_for(std::chrono::milliseconds(1));
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
	g_mutex4.unlock(); // order of locking mutexes got to be the same
	g_mutex3.unlock(); // order of locking mutexes got to be the same

	std::cout << std::this_thread::get_id() << " =========== doWork(): END " << std::endl;
	std::this_thread::sleep_for(std::chrono::milliseconds(5000));
}

void doWork4(char symbol) {
	std::cout << std::this_thread::get_id() << " =========== doWork(): START " << std::endl;

	g_mutex3.lock();
	std::this_thread::sleep_for(std::chrono::milliseconds(5000));
	g_mutex4.lock();

	for (int i = 0; i < 5; ++i) {
		for (int j = 0; j < 40; ++j) {
			std::cout << symbol;
			std::this_thread::sleep_for(std::chrono::milliseconds(1));
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
	g_mutex4.unlock();
	g_mutex3.unlock();

	std::cout << std::this_thread::get_id() << " =========== doWork(): END " << std::endl;
	std::this_thread::sleep_for(std::chrono::milliseconds(5000));
}
