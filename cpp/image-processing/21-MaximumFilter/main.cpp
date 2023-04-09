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
	img.maximumFilter();
	img.writeImage("images/girlface-max.bmp");

	cout << "Finished" << endl;

	return 0;
}
