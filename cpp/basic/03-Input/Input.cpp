//============================================================================
// Name        : Input.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int main() {

	cout << "Enter your name: " << flush;
	string input;
	cin >> input;
	cout << "You entered: " << input << endl;

	cout << "Enter your age: " << flush;
	int age;
	cin >> age;
	cout << "You are " << age << " years old." << endl;

	return 0;
}
