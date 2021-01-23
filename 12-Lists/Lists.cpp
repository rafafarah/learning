//============================================================================
// Name        : 32-Lists.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <list>
using namespace std;

int main() {
	list<int> numbers;

	numbers.push_back(1);
	numbers.push_back(2);
	numbers.push_back(3);
	numbers.push_front(0);

	list<int>::iterator it = numbers.begin();
	it++;
	numbers.insert(it, 100);
	cout << "Element: " << *it << endl;

	list<int>::iterator it1 = numbers.begin();
	it1++;
	// erase invalidates iterator. It returns pointer to element after the erased
	it1 = numbers.erase(it1);
	cout << "Element1: " << *it1 << endl;

	for (list<int>::iterator it = numbers.begin(); it != numbers.end(); ++it) {
		if (*it == 2) {
			numbers.insert(it, 1234);
		}
		 if (*it == 1) {
			 it = numbers.erase(it);
			 --it;
		 }
	}

	for (list<int>::iterator it = numbers.begin(); it != numbers.end(); ++it) {
		cout << *it << endl;
	}

	return 0;
}
