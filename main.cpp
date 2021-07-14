#include <chrono>
#include <iostream>
#include <thread>

#include "dowork.h"
#include "Timer.h"

int main() {

	Timer timer;
	std::thread thread1(doWork, '$');
	std::thread thread2(doWork, '#');
	
	thread1.join();
	thread2.join();
	double time = timer.elapsed();
	std::cout << "time = " << time << std::endl;

	return 0;
}