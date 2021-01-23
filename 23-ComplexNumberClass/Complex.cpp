/*
 * Complex.cpp
 *
 *  Created on: 13 de mai de 2020
 *      Author: rfarah
 */

#include "Complex.h"

namespace rfh {

ostream& operator<<(ostream &out, const Complex &c) {
	out << "(" << c.getReal() << "," << c.getImaginary() << ")";
	return out;
}

Complex::Complex() :
		real(0), imaginary(0) {
	// TODO Auto-generated constructor stub
}

Complex::Complex(double real, double imaginary) :
		real(real), imaginary(imaginary) {
}

Complex::Complex(const Complex &other) {
	real = other.real;
	imaginary = other.imaginary;
}

const Complex& Complex::operator=(const Complex &other) {
	cout << "Assign operator." << endl;
	real = other.real;
	imaginary = other.imaginary;

	return *this;
}

} /* namespace rfh */
