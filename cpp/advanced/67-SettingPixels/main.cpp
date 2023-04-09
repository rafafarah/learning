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

	bitmap.setPixel(WIDTH / 2, HEIGHT / 2, 0xFF, 0, 0);
	for (int x = 0; x < WIDTH; ++x) {
		for (int y = 0; y < HEIGHT; ++y) {
			bitmap.setPixel(x, y, 0xFF, 0, 0);
		}
	}
	bitmap.write("test.bmp");

	cout << "Finished" << endl;
	return 0;
}
