//============================================================================
// Name        : 37-Sets.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <set>
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

	void print() const {
		cout << id << ": " << name << endl;
	}

	// Operator overloading
	bool operator<(const Test &other) const {
		if (name == other.name) {
			return id < other.id;
		} else {
			return name < other.name;
		}
	}
};

int main() {
	// Unique set of int objects. Cannot insert double, no error is issued,
	// but the second insertion is ignored.
	set<int> numbers;

	numbers.insert(0);
	numbers.insert(3);
	numbers.insert(2);
	numbers.insert(3);

	for (set<int>::iterator it = numbers.begin(); it != numbers.end(); ++it) {
		cout << *it << endl;
	}

	set<int>::iterator itFind = numbers.find(1);

	if (itFind != numbers.end()) {
		cout << "Found number in set." << endl;
	} else {
		cout << "Number not found." << endl;
	}

	// Alternative way of searching
	// Since set is unique, count will return 1 if the element is in the set, 0 otherwise.
	if (numbers.count(3)) {
		cout << "Found!" << endl;
	} else {
		cout << "Not found!" << endl;
	}

	// Custom objects in set:
	set<Test> testSet;

	testSet.insert(Test(10, "Mike"));
	testSet.insert(Test(30, "Sue"));
	testSet.insert(Test(20, "Sue"));

	for (set<Test>::iterator it = testSet.begin(); it != testSet.end(); ++it) {
		it->print();
	}

	return 0;
}
