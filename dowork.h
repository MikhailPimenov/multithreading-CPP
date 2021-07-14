#pragma once

#include <chrono>
#include <iostream>
#include <mutex>
#include <thread>

void doWork_with_deadlock(char symbol);
void doWork_with_deadlock2(char symbol);
void doWork3(char symbol);
void doWork4(char symbol);