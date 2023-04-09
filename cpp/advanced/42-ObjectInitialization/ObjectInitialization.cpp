//============================================================================
// Name        : 062-ObjectInitialization.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

class Test {
private:
	int id { 3 };
	string name { "Mike" };

public:
	// Create default constructor
	Test() = default;
	// Delete copy constructor. It makes object not copyable on creation
	Test(Test &other) = delete;
	// Delete assignment operator. It makes object not copyable after creation
	Test& operator=(const Test &other) = delete;

	Test(int id) :
			id(id) {
	}

	void print() {
		cout << id << ": " << name << endl;
	}
};

int main() {
	Test test;
	test.print();

	Test test1(77);
	test1.print();

	/*Test test2 = test1;
	test2.print();

	test2 = test;
	test2.print();*/

	return 0;
}
