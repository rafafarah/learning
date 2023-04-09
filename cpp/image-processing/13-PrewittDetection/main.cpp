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

	img.readImage("images/houses.bmp");
	img.print();
	img.convolve2D(PREWITT_VERTICAL);
	img.writeImage("images/houses-vertical.bmp");

	cout << "Finished" << endl;

	return 0;
}
