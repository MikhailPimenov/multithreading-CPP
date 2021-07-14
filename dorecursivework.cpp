#include "dorecursivework.h"

std::recursive_mutex g_rmutex;

void doRecursiveWork(int a) {
	g_rmutex.lock();
	
	std::cout << a << ' ';
	std::this_thread::sleep_for(std::chrono::milliseconds(100));

	if (a <= 1) {
		std::cout << std::endl;
		g_rmutex.unlock();
		return;
	}

	doRecursiveWork(a - 1);

	g_rmutex.unlock();
}