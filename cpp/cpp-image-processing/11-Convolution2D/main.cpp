//============================================================================
// Name        : 115-ImageProcessingLibrary.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "ImageProcessing.h"
using namespace std;
using namespace rfh;

int main() {
	ImageProcessing img;
	Mask mask;

	mask.rows = 5;
	mask.cols = 5;
	mask.data.resize(mask.rows * mask.cols);
	/*
	 * -1 -1 -1 -1 -1
	 * -1 -1 -1 -1 -1
	 * -1 -1 24 -1 -1
	 * -1 -1 -1 -1 -1
	 * -1 -1 -1 -1 -1
	 * */
	for (auto &i : mask.data) {
		i = (signed char) -1;
	}
	mask.data[(mask.rows * mask.cols) / 2] = (signed char) 24;

	img.readImage("images/girlface.bmp");
	img.print();
	img.convolve2D(mask);
	img.writeImage("images/girlface-conv.bmp");

	cout << "Finished" << endl;

	return 0;
}
