//============================================================================
// Name        : 38-StackAndQueue.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <stack>
#include <queue>
using namespace std;

class Test {
private:
	string name;

public:
	Test(string name) :
			name(name) {
	}

	~Test() {
//		cout << "Object destroyed" << endl;
	}

	void print() {
		cout << name << endl;
	}
};

int main() {
	// LIFO
	stack<Test> stack;

	stack.push(Test("Mike"));
	stack.push(Test("Raj"));
	stack.push(Test("Sue"));

	// Takes a reference to the top element
	/*Test &test = stack.top();
	test.print();*/

	// Drops top element
	/*stack.pop();

	Test &test1 = stack.top();
	test1.print();*/

	// Iterate through the stack, dropping the elements one by one.
	while (stack.size() > 0) {
		Test &test1 = stack.top();
		test1.print();
		stack.pop();
	}

	cout << endl;

	// FIFO
	queue<Test> queue;

	queue.push(Test("Mike"));
	queue.push(Test("Raj"));
	queue.push(Test("Sue"));

	// Takes a reference to the top element
	/*Test &test2 = queue.front();
	test2.print();*/

	// Drops front element
	/*queue.pop();

	Test &test3 = queue.front();
	test3.print();*/

	// Iterate through the queue, dropping the elements one by one.
	while (queue.size() > 0) {
		Test &test1 = queue.front();
		test1.print();
		queue.pop();
	}

	return 0;
}
