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
private:
	int m_pos;
	int m_size;
	T *m_values;

public:
	class iterator;

public:
	ring(int size) :
			m_pos(0), m_size(size), m_values(NULL) {
		m_values = new T[size];
	}

	~ring() {
		delete[] m_values;
	}

	int size() {
		return m_size;
	}

	iterator begin() {
		return iterator(0, *this);
	}

	iterator end() {
		return iterator(m_size, *this);
	}

	void add(T value) {
		m_values[m_pos] = value;

		// Increments position and check end of buffer
		if (++m_pos >= m_size) {
			m_pos = 0;
		}
	}

	// get() does not check for pos > m_size
	T& get(int pos) {
		return m_values[pos];
	}
};

// Nested class with the implementation outside the main class
template<class T>
class ring<T>::iterator {
private:
	int m_pos;
	ring &m_ring;

public:
	iterator(int pos, ring &aRing) :
			m_pos(pos), m_ring(aRing) {
	}

	// Post fixed iterator needs a parameter
	iterator& operator++(int) {
		++m_pos;

		return *this;
	}

	// Pre fixed iterator has no parameter
	iterator& operator++() {
		++m_pos;

		return *this;
	}

	T& operator*() {
		return m_ring.get(m_pos);
	}

	bool operator!=(const iterator &other) const {
		return (m_pos != other.m_pos);
	}
};

#endif /* RING_H_ */
