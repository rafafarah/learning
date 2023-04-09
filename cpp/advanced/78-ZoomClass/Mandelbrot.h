/*
 * Mandelbrot.h
 *
 *  Created on: 25 de mai de 2020
 *      Author: rfarah
 */

#ifndef MANDELBROT_H_
#define MANDELBROT_H_

namespace rfh {

class Mandelbrot {
public:
	static const int MAX_ITERATIONS = 1000;

public:
	Mandelbrot();
	virtual ~Mandelbrot();

	static int getIterations(double x, double y);
};

} /* namespace rfh */

#endif /* MANDELBROT_H_ */
