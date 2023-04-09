//============================================================================
// Name        : 079-AutoPointers.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <memory>
using namespace std;

class Test {
public:
	Test() {
		cout << "created" << endl;
	}

	void greet() {
		cout << "hello" << endl;
	}

	~Test() {
		cout << "destroyed" << endl;
	}
};

class Temp {
private:
	unique_ptr<Test[]> pTest;

public:
	Temp(): pTest(new Test[2]) {

	}
};

int main() {
	// Automatically deallocate memory when goes out of scope
//	unique_ptr<Test[]> pTest(new Test[2]);

//	pTest[1].greet();

	Temp temp;

	cout << "Finished" << endl;
	return 0;
}
