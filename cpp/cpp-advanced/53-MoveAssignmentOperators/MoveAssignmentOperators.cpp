//============================================================================
// Name        : 070-ElisionAndOptimization.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
#include <memory.h>
using namespace std;

class Test {
private:
	static const int SIZE = 100;
	int *_pBuffer{nullptr};

public:
	Test() {
		_pBuffer = new int[SIZE] { };
	}

	Test(int i) {
		_pBuffer = new int[SIZE] { };
		for (int j = 0; j < SIZE; ++j) {
			_pBuffer[j] = 7 * i;
		}
	}

	Test(const Test &other) {
		_pBuffer = new int[SIZE] { };
		memcpy(_pBuffer, other._pBuffer, SIZE * sizeof(int));
	}

	// Constructor with Rvalue reference
	Test (Test &&other) {
		cout << "move constructor" << endl;
		_pBuffer = other._pBuffer;
		other._pBuffer = nullptr;
	}

	Test& operator=(const Test &other) {
		_pBuffer = new int[SIZE] { };
		memcpy(_pBuffer, other._pBuffer, SIZE * sizeof(int));
		return *this;
	}

	Test& operator=(Test &&other) {
		cout << "move assignment" << endl;

		delete _pBuffer;
		_pBuffer = other._pBuffer;
		other._pBuffer = nullptr;

		return *this;
	}

	~Test() {
		delete[] _pBuffer;
	}

	friend ostream& operator<<(ostream &out, const Test &test);
};

ostream& operator<<(ostream &out, const Test &test) {
	out << "Hello from test";
	return out;
}

Test getTest() {
	return Test();
}

int main() {
	vector<Test> vec;
	vec.push_back(Test());

	Test test;
	test = getTest();

	return 0;
}
