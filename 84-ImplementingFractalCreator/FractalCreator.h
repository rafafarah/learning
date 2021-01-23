/*
 * FractalCreator.h
 *
 *  Created on: 25 de mai de 2020
 *      Author: rfarah
 */

#ifndef FRACTALCREATOR_H_
#define FRACTALCREATOR_H_

#include <string>
#include <memory>
#include "Zoom.h"
#include "Mandelbrot.h"
#include "Bitmap.h"
#include "ZoomList.h"
using namespace std;

namespace rfh {

class FractalCreator {
private:
	int m_width { 0 };
	int m_height { 0 };
	unique_ptr<int[]> m_histogram;
	unique_ptr<int[]> m_fractal;
	Bitmap m_bitmap;
	ZoomList m_zoomList;
	int m_total{0};

public:
	FractalCreator(int width, int height);
	virtual ~FractalCreator();

	void calculateIteration();
	void calculateTotalIterations();
	void addZoom(const Zoom &zoom);
	void drawFractal();
	void writeBitmap(string name);
};

} /* namespace rfh */

#endif /* FRACTALCREATOR_H_ */
