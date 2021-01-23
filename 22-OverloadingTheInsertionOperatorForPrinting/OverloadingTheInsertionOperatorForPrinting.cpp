//============================================================================
// Name        : 41-OverloadingAssignmentOperator.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

class Test {
private:
	int id;
	string name;

public:
	Test() :
			id(0), name("") {
	}

	Test(int id, string name) :
			id(id), name(name) {
	}

	Test(const Test &other) {
		// Using equals operator
		*this = other;
	}

	const Test& operator=(const Test &other) {
		id = other.id;
		name = other.name;

		return *this;
	}

	// Overload insertion operator for printing
	friend ostream &operator<<(ostream &out, const Test &test) {
		out << test.id << ": " << test.name;
		return out;
	}
};

int main() {
	Test test1(10, "Mike");
	Test test2(20, "Bob");

	// Using overloaded operator
	cout << test1 << endl << test2 << endl;

	return 0;
}
