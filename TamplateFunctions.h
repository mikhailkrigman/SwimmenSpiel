#pragma once

#include <iostream>

using namespace std;

template <typename T>
void swap(T& a, T& b) {
	T temp = a;
	a = b;
	b = temp;
}