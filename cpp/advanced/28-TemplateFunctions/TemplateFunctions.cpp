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
	cout << obj << endl;
}

int main() {
	print<string>("Hello");
	print<int>(1);

	print("Hello there");
	print(2);

	return 0;
}
