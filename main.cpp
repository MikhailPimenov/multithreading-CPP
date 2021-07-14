#include <chrono>
#include <iostream>
#include <thread>

#include "dowork.h"
#include "Timer.h"

int main() {
	Timer timer;

	std::thread thread1(doWork3, '*');
	std::thread thread2(doWork4, '#');

	thread1.join();
	thread2.join();

	double time = timer.elapsed();
	std::cout << "time = " << time << std::endl;

	
	timer.reset();
	std::thread thread3(doWork_with_deadlock, '*');
	std::thread thread4(doWork_with_deadlock2, '#');

	thread3.join();
	thread4.join();

	time = timer.elapsed();
	std::cout << "time = " << time << std::endl;

	return 0;
}