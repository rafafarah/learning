//============================================================================
// Name        : 122-BlurDoZero.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>
using namespace std;

int main() {
	ifstream inFile;
	ofstream outFile;
	unsigned char header[54];
	unsigned char colorTable[1024];

	inFile.open("fruits.bmp", ios::in | ios::binary);
	if (!inFile) {
		cout << "Error opening file" << endl;
		return 1;
	}

	outFile.open("fruits-blur.bmp", ios::out | ios::binary);
	if (!outFile) {
		cout << "Error opening file" << endl;
		return 2;
	}

	for (int i = 0; i < 54; ++i) {
		header[i] = inFile.get();
	}

	outFile.write((char*) header, 54);

	int width = *(int*) &header[18];
	int height = *(int*) &header[22];
	int bitDepth = *(int*) &header[28];

	if (bitDepth <= 8) {
		inFile.read((char*) colorTable, 1024);
		outFile.write((char*) colorTable, 1024);
	}

	int imgSize = width * height;
	unsigned char buffer[imgSize][3];
	unsigned char outBuffer[imgSize][3];

	for (int i = 0; i < imgSize; ++i) {
		buffer[i][2] = inFile.get();
		buffer[i][1] = inFile.get();
		buffer[i][0] = inFile.get();
	}

	float v = 1.0 / 9.0;
	float kernel[3][3] = { { v, v, v }, { v, v, v }, { v, v, v } };

	for (int x = 1; x < height - 1; ++x) {
		for (int y = 1; y < width - 1; ++y) {
			float sum0 = 0.0;
			float sum1 = 0.0;
			float sum2 = 0.0;

			for (int i = -1; i <= 1; ++i) {
				for (int j = -1; j <= 1; ++j) {
					sum0 = sum0
							+ (float) kernel[i + 1][j + 1]
									* buffer[(x + i) * width + (y + j)][0];
					sum1 = sum1
							+ (float) kernel[i + 1][j + 1]
									* buffer[(x + i) * width + (y + j)][1];
					sum2 = sum2
							+ (float) kernel[i + 1][j + 1]
									* buffer[(x + i) * width + (y + j)][2];
				}
			}

			outBuffer[(x) * width + (y)][0] = sum0;
			outBuffer[(x) * width + (y)][1] = sum1;
			outBuffer[(x) * width + (y)][2] = sum2;
		}
	}

	for (int i = 0; i < imgSize; ++i) {
		outFile.put(outBuffer[i][2]);
		outFile.put(outBuffer[i][1]);
		outFile.put(outBuffer[i][0]);
	}

	inFile.close();
	if (!inFile) {
		cout << "Error closing file" << endl;
		return 3;
	}

	outFile.close();
	if (!outFile) {
		cout << "Error closing file" << endl;
		return 4;
	}

	cout << "Finished" << endl;
	return 0;
}
