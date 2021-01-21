//============================================================================
// Name        : Variables.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int main() {
	int numberCats = 5;
	int numberDogs = 7;
	int numberAnimals = numberCats + numberDogs;

	cout << "Number of cats: " << numberCats << endl;
	cout << "Number of dogs: " << numberDogs << endl;
	cout << "Number of animals: " << numberAnimals << endl;
	cout << "New dog acquired!" << endl;

	numberDogs++;

	cout << "New number of dogs: " << numberDogs << endl;
	return 0;
}
