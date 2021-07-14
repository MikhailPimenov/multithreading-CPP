#include "myclass.h"

MyClass::MyClass() {
	std::cout << "MyClass acquired\n";
}

MyClass::MyClass(const MyClass& object) {
	std::cout << "MyClass acquired using copy constructor\n";
}

MyClass::MyClass(MyClass&& object) {
	std::cout << "MyClass acquired using move constructor\n";
}

MyClass::~MyClass() {
	std::cout << "MyClass destroyed\n";
}

MyClass& MyClass::operator=(const MyClass& object) {
	if (this == &object)
		return *this;
	std::cout << "MyClass acquired using copy assignment operator\n";

	return *this;
}

MyClass& MyClass::operator=(MyClass&& object) {
	if (this == &object)
		return *this;
	std::cout << "MyClass acquired using move assignment operator\n";

	return *this;
}

void MyClass::doWork() const {
	std::this_thread::sleep_for(std::chrono::milliseconds(1000));
	std::cout << "id: " << std::this_thread::get_id() << " ========= doWork(): START\n";

	std::this_thread::sleep_for(std::chrono::milliseconds(5000));

	std::cout << "id: " << std::this_thread::get_id() << " ========= doWork(): FINISHED\n";
	std::this_thread::sleep_for(std::chrono::milliseconds(1000));
}

void MyClass::doWork2(int a) const {
	std::this_thread::sleep_for(std::chrono::milliseconds(1000));
	std::cout << "id: " << std::this_thread::get_id() << " ========= doWork2(): START\n";

	std::cout << "id: " << std::this_thread::get_id() << " ========= doWork2(): CALCULATING\n";
	std::this_thread::sleep_for(std::chrono::milliseconds(5000));
	int result_to_be_ignored = 2 * a;

	std::cout << "id: " << std::this_thread::get_id() << " ========= doWork2(): FINISHED\n";
	std::this_thread::sleep_for(std::chrono::milliseconds(1000));
}

int MyClass::sum(int a, int b) const {
	std::this_thread::sleep_for(std::chrono::milliseconds(1000));
	std::cout << "id: " << std::this_thread::get_id() << " ========= sum(): START\n";

	std::cout << "id: " << std::this_thread::get_id() << " ========= sum(): CALCULATING\n";
	std::this_thread::sleep_for(std::chrono::milliseconds(5000));
	int result = a + b;

	std::cout << "id: " << std::this_thread::get_id() << " ========= sum(): FINISHED\n";
	std::this_thread::sleep_for(std::chrono::milliseconds(1000));

	return result;
}