//============================================================================
// Name        : main.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "Bitmap.h"
using namespace std;
using namespace rfh;

int main() {
	int const WIDTH = 800;
	int const HEIGHT = 600;
	Bitmap bitmap(WIDTH, HEIGHT);

	double min = 999999;
	double max = -min;

	for (int x = 0; x < WIDTH; ++x) {
		for (int y = 0; y < HEIGHT; ++y) {
			double xFractal = (x - WIDTH / 2.0) * (2.0 / WIDTH);
			double yFractal = (y - HEIGHT / 2.0) * (2.0 / HEIGHT);

			if (yFractal < min) {
				min = yFractal;
			}
			if (yFractal > max) {
				max = yFractal;
			}
		}
	}

	cout << min << ", " << max << endl;

	bitmap.write("test.bmp");

	cout << "Finished" << endl;
	return 0;
}
