/*
 * FractalCreator.h
 *
 *  Created on: 25 de mai de 2020
 *      Author: rfarah
 */

#ifndef FRACTALCREATOR_H_
#define FRACTALCREATOR_H_

#include <string>
#include <cstdint>
#include <memory>
#include <math.h>
#include <vector>
#include "Zoom.h"
#include "Mandelbrot.h"
#include "Bitmap.h"
#include "ZoomList.h"
#include "RGB.h"
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
	int m_total { 0 };

	vector<int> m_ranges;
	vector<RGB> m_colors;
	vector<int> m_rangeTotals;

	bool m_bGotFirstRange { false };

private:
	void calculateIteration();
	void calculateTotalIterations();
	void calculateRangeTotals();
	void drawFractal();
	void writeBitmap(string name);

public:
	void addZoom(const Zoom &zoom);
	void addRange(double rangeEnd, const RGB &rgb);
	void run(string name);
	FractalCreator(int width, int height);
	virtual ~FractalCreator();
};

} /* namespace rfh */

#endif /* FRACTALCREATOR_H_ */
