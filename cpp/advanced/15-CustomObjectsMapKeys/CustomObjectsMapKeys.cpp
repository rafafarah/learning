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

	// Operator overloading
	bool operator<(const Person &other) const {
		if (name == other.name) {
			return age < other.age;
		} else {
			return name < other.name;
		}
	}
};

int main() {
	map<Person, int> people;

	// Both parameterless and parameter constructors are used here:
	people[Person("Mike", 40)] = 40;
	people[Person("Mike", 44)] = 50;
	people[Person("Raj", 30)] = 30;
	people[Person("Vicky", 20)] = 20;

//	people.insert(make_pair(Person("Bob", 45), 45));
//	people.insert(make_pair(Person("Sue", 19), 19));

	for (map<Person, int>::iterator it = people.begin(); it != people.end();
			++it) {
		cout << it->second << ": " << flush;
		it->first.print();
	}

	return 0;
}
