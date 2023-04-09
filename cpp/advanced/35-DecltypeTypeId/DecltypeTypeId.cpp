//============================================================================
// Name        : 55-DecltypeTypeId.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <typeinfo>
using namespace std;

int main() {
	string value;

	// Typeid returns an object with information about the type
	cout << typeid(value).name() << endl;

	// Declares a variable with the same type as value
	decltype(value) name = "Bob";

	cout << typeid(name).name() << endl;

	return 0;
}
