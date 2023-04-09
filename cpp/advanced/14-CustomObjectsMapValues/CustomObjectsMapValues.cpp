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

class Person {
private:
	string name;
	unsigned int age;

public:
	// Parameterless constructor is needed because maps build the object with it
	// and then copy the object created with the parameter constructor via equals signs.
	Person() :
			name(""), age(0) {
	}

	// Copy constructor
	Person(const Person &other) {
		cout << "Copy constructor running." << endl;
		name = other.name;
		age = other.age;
	}

	Person(string name, unsigned int age) :
			name(name), age(age) {
	}

	// const means the the attributes cannot be written here
	void print() const {
		cout << name << ": " << age << endl;
	}
};

int main() {
	map<int, Person> people;

	// Both parameterless and parameter constructors are used here:
	people[50] = Person("Mike", 40);
	people[32] = Person("Raj", 30);
	people[1] = Person("Vicky", 20);

	people.insert(make_pair(55, Person("Bob", 45)));
	people.insert(make_pair(8, Person("Sue", 19)));

	for (map<int, Person>::iterator it = people.begin(); it != people.end();
			++it) {
		cout << it->first << ": " << flush;
		it->second.print();
	}

	return 0;
}
