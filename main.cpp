#include <chrono>
#include <iostream>
#include <thread>

#include "dowork.h"
#include "Timer.h"

int main() {
	Timer timer;

	std::thread thread1(doWork, '*');
	std::this_thread::sleep_for(std::chrono::milliseconds(6000));
	std::thread thread2(doWork, '#');

	thread2.join();
	thread1.join();

	double time = timer.elapsed();
	std::cout << "time = " << time << std::endl;

	return 0;
}