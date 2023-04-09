/*
 * Zoom.h
 *
 *  Created on: 25 de mai de 2020
 *      Author: rfarah
 */

#ifndef ZOOM_H_
#define ZOOM_H_

namespace rfh {

struct Zoom {
	int x { 0 };
	int y { 0 };
	double scale { 0.0 };

	Zoom(int x, int y, double scale) :
			x(x), y(y), scale(scale) {};
};

} /* namespace rfh */

#endif /* ZOOM_H_ */
