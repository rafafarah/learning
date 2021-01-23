//============================================================================
// Name        : 064-LambdaParametersAndReturnType.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

void testGreet(void (*pFunc)(string), string name) {
	pFunc(name);
}

void runDivede(double (*pFunc)(double, double), double num, double div) {
	auto rval = pFunc(num, div);

	cout << rval << endl;
}

int main() {
	auto pGreet = [](string name) {
		cout << "Hello " << name << endl;
	};

	pGreet("Mike");

	testGreet(pGreet, "Bob");

	auto pDivide = [](double num, double div) -> double {
		if (div == 0.0) {
			return 0;
		}
		return (num / div);
	};

	cout << pDivide(7, 3) << endl;
	cout << pDivide(7, 0) << endl;

	runDivede(pDivide, 8, 3);

	return 0;
}
