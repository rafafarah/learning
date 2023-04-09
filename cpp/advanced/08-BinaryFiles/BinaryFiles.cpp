//============================================================================
// Name        : 27-BinaryFiles.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>
using namespace std;

#pragma pack(push, 1)
struct Person {
	char name[50];
	int age;
	double height;
};
#pragma pack(pop)

int main() {
	string fileName = "text.bin";

	/******************* Write binary file *******************/

	Person person = { "Frodo", 50, 0.91 };
	ofstream outputFile;

	outputFile.open(fileName, ios::binary);

	if (!outputFile.is_open()) {
		cout << "Could not write file: " + fileName << endl;
		return 1;
	}

	// Writing person casted to char*
	outputFile.write(reinterpret_cast<char*>(&person), sizeof(person));

	outputFile.close();

	/******************* Read binary file *******************/

	Person person2 = {};
	ifstream inputFile;

	inputFile.open(fileName, ios::binary);

	if (!inputFile.is_open()) {
		cout << "Could not read file: " + fileName << endl;
		return 2;
	}

	// Writing person casted to char*
	inputFile.read(reinterpret_cast<char*>(&person2), sizeof(person2));

	cout << person2.name << ", " << person2.age << ", " << person2.height << endl;

	inputFile.close();

	return 0;
}
