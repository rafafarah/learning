//============================================================================
// Name        : 115-ImageProcessingLibrary.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "ImageProcessing.h"

#include <fstream>

using namespace std;
using namespace rfh;

int main() {
	ImageProcessingColor imgColor;

	imgColor.readImage("images/lenna.bmp");
	imgColor.print();
	imgColor.sepia();
	imgColor.writeImage("images/lenna-sepia.bmp");

	cout << "Finished" << endl;

	return 0;
}
