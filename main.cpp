#include <chrono>
#include <iostream>
#include <thread>

#include "dorecursivework.h"

int main() {

	std::thread thread1(doRecursiveWork, 10);
	std::thread thread2(doRecursiveWork, 10);

	thread1.join();
	thread2.join();

	return 0;
}