/*
 * FractalCreator.h
 *
 *  Created on: 25 de mai de 2020
 *      Author: rfarah
 */

#ifndef FRACTALCREATOR_H_
#define FRACTALCREATOR_H_

#include <string>
#include "Zoom.h"
using namespace std;

namespace rfh {

class FractalCreator {
public:
	FractalCreator(int width, int height);
	virtual ~FractalCreator();

	void calculateIteration();
	void addZoom(const Zoom &zoom);
	void drawFractal();
	void writeBitmap(string filename);
};

} /* namespace rfh */

#endif /* FRACTALCREATOR_H_ */
