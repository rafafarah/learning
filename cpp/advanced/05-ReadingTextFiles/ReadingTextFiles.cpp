//============================================================================
// Name        : 25-ReadingTextFiles.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>
using namespace std;

int main() {
	ifstream inFile;
	string inputFileName = "/home/rfarah/eclipse-workspace/24-TextFiles/text.txt";

	inFile.open(inputFileName);

	if (inFile.is_open()) {
		string line;

		while (!inFile.eof()) {
			getline(inFile, line);
			cout << line << endl;
		}

		inFile.close();
	} else {
		cout << "Could not open file:" << inputFileName << endl;
	}
	return 0;
}
