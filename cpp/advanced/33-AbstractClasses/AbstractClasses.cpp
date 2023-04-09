//============================================================================
// Name        : 53-AbstractClasses.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

// Abstract class, cannot be instanciated
class Animal {
public:
	virtual ~Animal() {
	}

	virtual void run() = 0;
	virtual void speak() = 0;
};

// In order to be instanciated,
// a class has to implement all abstract methods of the parental class.
// Otherwise, it will also be abstract
class Dog: public Animal {
public:
	~Dog() {
	}

	virtual void speak() {
		cout << "Woof" << endl;
	}
};

// Implements all abstract functions. Can be instanciated.
class Labrador: public Dog {
public:
	Labrador() {
		cout << "New labrador" << endl;
	}

	virtual void run() {
		cout << "Labrador running" << endl;
	}
};

void test(Animal &a) {
	a.run();
}

int main() {
	Labrador dog;
	dog.speak();
	dog.run();

	// Can't instanciate Animal object. However, it is possible to create array of pointers
	Animal * animals[5];
	animals[0] = &dog;

	animals[0]->speak();
	animals[0]->run();

	test(dog);

	return 0;
}
