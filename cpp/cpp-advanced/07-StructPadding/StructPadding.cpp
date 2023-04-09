//============================================================================
// Name        : 27-BinaryFiles.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

#pragma pack(push, 1)
struct Person {
	char name[50];
	int age;
	double weight;
};
#pragma pack(pop)

int main() {
	cout << "sizeof(Person): " << sizeof(Person) << endl;
	cout << "sizeof(int): " << sizeof(int) << endl;
	cout << "sizeof(double): " << sizeof(double) << endl;

	return 0;
}
