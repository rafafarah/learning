/*
 * Complex.h
 *
 *  Created on: 13 de mai de 2020
 *      Author: rfarah
 */

#ifndef COMPLEX_H_
#define COMPLEX_H_

#include <iostream>
using namespace std;

namespace rfh {

class Complex {
private:
	double real;
	double imaginary;

public:
	Complex();
	Complex(double real, double imaginary);
	Complex(const Complex &other);
	const Complex& operator=(const Complex &other);
	Complex& operator+=(const Complex &other);
	Complex& operator+=(double real);
	bool operator==(const Complex &other) const;
	bool operator!=(const Complex &other) const;
	Complex operator*() const;

	double getReal() const {
		return real;
	}

	double getImaginary() const {
		return imaginary;
	}
};

ostream& operator<<(ostream &out, const Complex &c);
Complex operator+(const Complex &c1, const Complex &c2);
Complex operator+(const Complex &c, double real);
Complex operator+(double real, const Complex &c);

} /* namespace rfh */

#endif /* COMPLEX_H_ */
