//============================================================================
// Name        : 056-AutoKeyword.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <typeinfo>
using namespace std;

template<class T, class K>
// To use auto as return type of function, it's necessary specify the type after the prototype
auto test(T value1, K value2) -> decltype(value1 + value2) {
	return value1 + value2;
}

int get() {
	return 999;
}

auto test2() -> decltype(get()) {
	return get();
}

int main() {
	auto value = "Hello";

	cout << typeid(value).name() << endl;
	cout << test(5, 6) << endl;
	cout << test2() << endl;

	return 0;
}
