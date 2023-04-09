//============================================================================
// Name        : 33-Maps.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <map>
using namespace std;

int main() {
	map<string, int> ages;

	ages["Mike"] = 40;
	ages["Raj"] = 20;
	ages["Vicky"] = 30;

	ages["Jorge"] = 70;

	// Inserting new member:
	ages.insert(make_pair("Peter", 100));

	cout << ages["Raj"] << endl;

	// Search key in map
	if (ages.find("Sue") != ages.end()) {
		cout << "Found key!" << endl;
	} else {
		cout << "Key not found." << endl;
	}

	cout << "Accessing map via iterator:" << endl;
	for (map<string, int>::iterator it = ages.begin(); it != ages.end(); ++it) {
		cout << it->first << ": " << it->second << endl;
	}

	cout << "Accessing map via pair:" << endl;
	// Each member of map is a pair of data
	for (map<string, int>::iterator it = ages.begin(); it != ages.end(); ++it) {
		pair<string, int> age = *it;
		cout << age.first << ": " <<age.second << endl;
	}

	return 0;
}
