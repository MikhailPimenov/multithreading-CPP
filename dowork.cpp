#include "dowork.h"

void doWork() {
	for (int i = 0; i < 10; ++i) {
		std::cout << std::this_thread::get_id() << " doWork() " << i << std::endl;
		std::this_thread::sleep_for(std::chrono::milliseconds(500));
	}
}
