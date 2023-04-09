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
	ImageProcessingColor imgColor;

	imgColor.readImage("images/fruits.bmp");
	imgColor.print();
	imgColor.blurImage();
	imgColor.writeImage("images/fruits-blur.bmp");

	cout << "Finished" << endl;

	return 0;
}
