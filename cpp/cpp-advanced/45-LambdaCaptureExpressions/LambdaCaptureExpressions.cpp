//============================================================================
// Name        : 065-LambdaCaptureExpressions.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int main() {
	int one = 1;
	int two = 2;
	int three = 3;

	// Capture one and two by value
	[one, two]() {
		cout << one << ", " << two << endl;
	}();

	// Capture all local variables by value
	[=]() {
		cout << one << ", " << two << endl;
	}();

	// Default capture all local variable by value, but capture three by reference
	[=, &three]() {
		three = 9;
		cout << one << ", " << two << ", " << three << endl;
	}();
	cout << three << endl;

	// Default capture all local variable by reference
	[&]() {
		three = 9;
		two = 8;
		cout << one << ", " << two << ", " << three << endl;
	}();
	cout << two << endl;

	// Default capture all local variable by reference, but two and three by value
	[&, two, three]() {
		one = 5;
		cout << one << ", " << two << ", " << three << endl;
	}();
	cout << one << endl;

	return 0;
}
