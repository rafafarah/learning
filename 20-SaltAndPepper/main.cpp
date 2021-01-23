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
	img.saltAndPepper(0.1);
	img.writeImage("images/lena512-salt-pepper.bmp");

	cout << "Finished" << endl;

	return 0;
}
