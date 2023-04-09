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
		inFile.read(reinterpret_cast<char*>(colorTable.data()),
				colorTable.size());
	}

	buffer.resize(width * height);
	inFile.read(reinterpret_cast<char*>(buffer.data()), buffer.size());

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

	outFile.write(reinterpret_cast<char*>(header.data()), header.size());
	//	for(auto &i: header) {
	//		i = outFile.get();
	//	}

	if (bitDepth <= 8) {
		outFile.write(reinterpret_cast<char*>(colorTable.data()),
				colorTable.size());
	}

	outFile.write(reinterpret_cast<char*>(buffer.data()), buffer.size());

	outFile.close();
	if (!outFile) {
		cout << "Error closing file" << endl;
		return;
	}
}

void ImageProcessing::copyImageBuffer(const vector<unsigned char> &buff) {
	buffer = buff;
}

void ImageProcessing::binarizeImage(int threshold) {
	for (auto &i : buffer) {
		i = ((int) i > threshold) ? WHITE : BLACK;
	}
}

void ImageProcessing::changeBrightness(int brightness) {
	for (auto &i : buffer) {
		int temp = i + brightness;
		temp = (temp > MAX_COLOR) ? MAX_COLOR : temp;
		temp = (temp < MIN_COLOR) ? MIN_COLOR : temp;
		i = temp;
	}
}

void ImageProcessing::computeHistogram(string name) {
	ofstream outFile;

	outFile.open(name, ios::out);
	if (!outFile) {
		cout << "Error opening file" << endl;
		return;
	}

	array<double, TOTAL_COLORS> iHist { };

	for (int y = 0; y < height; ++y) {
		for (int x = 0; x < width; ++x) {
			int index = buffer.at(x + y * width);
			++(iHist[index]);
		}
	}

	for (int i = 0; i < TOTAL_COLORS; ++i) {
		histogram[i] = (iHist[i] / (width * height));
	}

	for (auto &i : histogram) {
		outFile << "\n" << i;
	}
	outFile.close();
	if (!outFile) {
		cout << "Error closing file" << endl;
		return;
	}
}

void ImageProcessing::equalizeHistogram(string name) {
	computeHistogram(name);
	array<int, TOTAL_COLORS> histogramEq { };

	for (int i = 0; i < TOTAL_COLORS; ++i) {
		float sum = 0.0;
		for (int j = 0; j < i; ++j) {
			sum += histogram[j];
		}
		histogramEq[i] = (int) ((TOTAL_COLORS - 1) * sum /*+ 0.5*/);
	}

	for (int i = 0; i < width * height; ++i) {
		buffer[i] = histogramEq[buffer[i]];
	}
	computeHistogram("eq_" + name);
}

void ImageProcessing::print() {
	cout << "height: " << height << " width: " << width << " bitDepth: "
			<< bitDepth << endl;
}

} /* namespace rfh */
