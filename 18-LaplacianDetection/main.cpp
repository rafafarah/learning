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

	img.readImage("images/lighthouse.bmp");
	img.print();
	img.convolve2D(LAPLACE_POSITIVE);
	img.writeImage("images/lighthouse-positive.bmp");

	cout << "Finished" << endl;

	return 0;
}
