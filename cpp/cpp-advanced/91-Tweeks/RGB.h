/*
 * RGB.h
 *
 *  Created on: 26 de mai de 2020
 *      Author: rfarah
 */

#ifndef RGB_H_
#define RGB_H_

namespace rfh {

struct RGB {
	double r;
	double g;
	double b;

	RGB(double r, double g, double b);
};

RGB operator-(const RGB &first, const RGB &second);

} /* namespace rfh */

#endif /* RGB_H_ */
