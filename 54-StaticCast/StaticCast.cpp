//============================================================================
// Name        : 074-StaticCast.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

class Parent {
public:
	void speak() {
		cout << "parent!" << endl;
	}

};

class Brother: public Parent {

};

class Sister: public Parent {

};

int main() {
	Parent parent;
	Brother brother;

	Parent *ppb = &brother;

	// Dangerous casting. ppb could have missing methods that pbb will crash if it tries to call.
	// static_cast is a compile casting
	Brother *pbb = static_cast<Brother *>(ppb);

	cout << pbb << endl;

	// Rvalue receiving Lvalue casted
	Parent &&p = static_cast<Parent &&>(parent);
	p.speak();


	return 0;
}
