//============================================================================
// Name        : 069-DelegatingConstructors.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

class Parent {
private:
	int dogs;
	string text;

public:
	Parent() :
			Parent("Hello") {
		dogs = 5;
		cout << "No parameter parent constructor" << endl;
	}

	Parent(string text) {
		dogs = 5;
		this->text = text;
		cout << "String parent constructor" << endl;
	}
};

class Child: public Parent {
public:
	Child() {

	}
};

int main() {
	Parent parent("Hello");
	Child child;

	return 0;
}
