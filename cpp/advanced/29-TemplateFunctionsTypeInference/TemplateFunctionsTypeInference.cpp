//============================================================================
// Name        : 48-TemplateFunctions.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

template<class T>
void print(T obj) {
	cout <<  "Template version: " << obj << endl;
}

void print(int value) {
	cout << "Non-template version: " << value << endl;
}

template<class T>
void show() {
	cout << T() << endl;
}

int main() {
	print<string>("Hello");
	print<int>(1);

	print("Hello there");
	print(2);
	print<>(3);

	show<double>();

	return 0;
}
