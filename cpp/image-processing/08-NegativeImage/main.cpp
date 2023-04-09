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

	img.readImage("images/girlface.bmp");
	img.print();
	img.negativeImage();
	img.writeImage("images/girlface-negative.bmp");

	cout << "Finished" << endl;

	return 0;
}
