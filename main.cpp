#include <chrono>
#include <iostream>
#include <thread>

#include "myclass.h"

int main() {
	int result3 = 15;
	std::cout << result3 << std::endl;
	int a = 12;
	int b = 7;


	MyClass m;
	std::thread thread1(&MyClass::doWork, &m);
	std::thread thread2(&MyClass::doWork, m); // passing the copy of object m
	std::thread thread3(&MyClass::doWork2, &m, a);
	std::thread thread4([&m, &result3, a, b]() { result3 = m.sum(a, b); });
	
	for (int i = 0; i < 10; ++i) {
		std::cout << std::this_thread::get_id() << " main() " << i << std::endl;
		std::this_thread::sleep_for(std::chrono::milliseconds(250));
	}
	
	thread1.join();
	thread2.join();
	thread3.join();
	thread4.join();
	std::cout << result3 << std::endl;

	return 0;
}