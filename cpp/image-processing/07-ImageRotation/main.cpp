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

	img.readImage("images/lena512.bmp");
	img.print();
	img.rotateImage(0);
	img.writeImage("images/lena512rot0.bmp");

	cout << "Finished" << endl;

	return 0;
}
