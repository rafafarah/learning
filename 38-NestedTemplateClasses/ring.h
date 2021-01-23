/*
 * ring.h
 *
 *  Created on: 18 de mai de 2020
 *      Author: rfarah
 */

#ifndef RING_H_
#define RING_H_

#include <iostream>
using namespace std;

template<class T>
class ring {
public:
	class iterator;
};

// Nested class with the implementation outside the main class
template<class T>
class ring<T>::iterator {
public:
	void print() {
		cout << "Hello from iterator: " << T() << endl;
	}
};

#endif /* RING_H_ */
