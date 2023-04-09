/*
 * ImageProcessing.cpp
 *
 *  Created on: 26 de mai de 2020
 *      Author: rfarah
 */

#include <fstream>
#include <iostream>
#include "ImageProcessing.h"

namespace rfh {

ImageProcessing::ImageProcessing() {

}

ImageProcessing::~ImageProcessing() {
}

void ImageProcessing::readImage(string name) {
	ifstream inFile;

	inFile.open(name, ios::in | ios::binary);
	if (!inFile) {
		cout << "Error opening file" << endl;
		return;
	}

//	inFile.read(header.data(), header.size());
	for (auto &i : header) {
		i = inFile.get();
	}

	width = *(reinterpret_cast<int*>(&header[OFFSET_WIDTH]));
	height = *(reinterpret_cast<int*>(&header[OFFSET_HEIGHT]));
	bitDepth = static_cast<int>(header.at(OFFSET_BIT_DEPTH));

	if (bitDepth <= 8) {
		inFile.read(colorTable.data(), colorTable.size());
	}

	buffer.resize(width * height);
	inFile.read(buffer.data(), buffer.size());

	inFile.close();
	if (!inFile) {
		cout << "Error closing file" << endl;
		return;
	}
}

void ImageProcessing::writeImage(string name) {
	ofstream outFile;

	outFile.open(name, ios::out | ios::binary);
	if (!outFile) {
		cout << "Error opening file" << endl;
		return;
	}

	outFile.write(header.data(), header.size());
	//	for(auto &i: header) {
	//		i = outFile.get();
	//	}

	if (bitDepth <= 8) {
		outFile.write(colorTable.data(), colorTable.size());
	}

	outFile.write(buffer.data(), buffer.size());

	outFile.close();
	if (!outFile) {
		cout << "Error closing file" << endl;
		return;
	}
}

void ImageProcessing::copyImageBuffer(const vector<char> &buff) {
	buffer = buff;
}

void ImageProcessing::print() {
	cout << "height: " << height << " width: " << width << " bitDepth: "
			<< bitDepth << endl;
}

} /* namespace rfh */
