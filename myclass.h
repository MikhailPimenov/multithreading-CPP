#pragma once

#include <chrono>
#include <iostream>
#include <thread>

class MyClass final
{
public:
	MyClass();
	MyClass(const MyClass& object);
	MyClass(MyClass&& object);

	~MyClass();

	MyClass& operator=(const MyClass& object);
	MyClass& operator=(MyClass&& object);

	void doWork() const;
	void doWork2(int a) const;
	int sum(int a, int b) const;
};

