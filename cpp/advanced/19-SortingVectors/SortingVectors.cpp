//============================================================================
// Name        : SortingVectors.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Test {
private:
	int id;
	string name;

public:
	Test(int id, string name) :
			id(id), name(name) {
	}

	void print() {
		cout << id << ": " << name << endl;
	}

	// friend allows function to access private members of class.
	friend bool comp(const Test &a, const Test &b);

//	bool operator<(const Test &other) const {
//		if (id == other.id) {
//			return name < other.name;
//		} else {
//			return id < other.id;
//		}
//	}
};

bool comp(const Test &a, const Test &b) {
	if (a.id == b.id) {
		return a.name < b.name;
	} else {
		return a.id < b.id;
	}
}

int main() {
	vector<Test> tests;

	tests.push_back(Test(5, "Mike"));
	tests.push_back(Test(10, "Sue"));
	tests.push_back(Test(7, "Raj"));
	tests.push_back(Test(3, "Vicky"));

	std::sort(tests.begin(), tests.end(), comp);

	for (unsigned int i = 0; i < tests.size(); ++i) {
		tests[i].print();
	}

	return 0;
}
