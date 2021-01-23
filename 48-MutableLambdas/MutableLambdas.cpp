//============================================================================
// Name        : 068-MutableLambdas.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int main() {
	int cats = 5;

	// mutable enables variable captured by value be changed inside the lambda scope
	[cats]() mutable {
		cats = 8;
		cout << cats << endl;
	}();
	cout << cats << endl;

	return 0;
}
