//============================================================================
// Name        : 36-Multimap.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <map>
using namespace std;

int main() {
	// Enables storing different pair with same key
	multimap<int, string> lookup;

	lookup.insert(make_pair(30, "Mike"));
	lookup.insert(make_pair(10, "Vicky"));
	lookup.insert(make_pair(30, "Raj"));
	lookup.insert(make_pair(20, "Bob"));

	for (multimap<int, string>::iterator it = lookup.begin();
			it != lookup.end(); ++it) {
		cout << it->first << ": " << it->second << endl;
	}

	cout << endl;

	// Finds the first with the selected key and continues iterating till the end of the multimap
	for (multimap<int, string>::iterator it = lookup.find(20);
			it != lookup.end(); ++it) {
		cout << it->first << ": " << it->second << endl;
	}

	cout << endl;

	// Create a pair of iterator. its.first: iterator with the first key equals to range.
	// its.second: iterator after the last key equals to range
	pair<multimap<int, string>::iterator, multimap<int, string>::iterator> its =
			lookup.equal_range(30);

	for (multimap<int, string>::iterator it = its.first; it != its.second;
			++it) {
		cout << it->first << ": " << it->second << endl;
	}

	cout << endl;

	// Same idea as before, but using auto keyword from C++11
	// to realize the right type for the iterator
	auto its2 = lookup.equal_range(30);

	for (multimap<int, string>::iterator it = its2.first; it != its2.second;
			++it) {
		cout << it->first << ": " << it->second << endl;
	}

	return 0;
}
