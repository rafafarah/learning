//============================================================================
// Name        : MultidimensionalArray.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int main() {
	string animals[2][3] = {
			{"fox", "dog", "cat"},
			{"mouse", "squirrel", "parrot"}
	};

	for (int i=0; i<6; i++) {
		cout << animals[0][i] << " " << flush;
	}

	return 0;
}
