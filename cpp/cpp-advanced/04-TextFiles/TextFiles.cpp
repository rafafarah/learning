//============================================================================
// Name        : 24-TextFiles.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>
using namespace std;

int main() {
//	ofstream outFile;

	fstream outFile;
	string outputFileName = "text.txt";

//	outFile.open(outputFileName);
	outFile.open(outputFileName, ios::out);

	if (outFile.is_open()) {
		outFile << "Hello there" << endl;
		outFile << "File name:" << outputFileName << endl;
		outFile << "File id: " << 1234;
		outFile.close();
	} else {
		cout << "Could not create file: " << outputFileName << endl;
	}

	return 0;
}
