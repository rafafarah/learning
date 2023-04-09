//============================================================================
// Name        : 061-InitializerLists.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
#include <initializer_list>
using namespace std;

class Test {
public:
	Test(initializer_list<string> texts) {
		for (auto value : texts) {
			cout << value << endl;
		}
	}

	void print(initializer_list<string> texts) {
		for (auto value: texts) {
			cout << value << endl;
		}
	}
};

int main() {
	Test test { "apple", "orange", "banana" };

	test.print({"one", "two", "three", "four"});

	return 0;
}
