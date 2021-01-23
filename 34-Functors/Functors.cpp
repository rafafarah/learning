//============================================================================
// Name        : 54-Functors.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

// Parental Functor
struct Test {
	virtual ~Test() {
	}

	virtual bool operator()(string &text) = 0;
};

// Functor
struct MatchTest: public Test {
	bool operator()(string &text) {
		return (text == "lion");
	}
};

void check(string text, Test &pred) {
	cout << pred(text) << endl;
}

int main() {
	MatchTest pred;

	check("lion", pred);

	return 0;
}
