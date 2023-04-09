//============================================================================
// Name        : 123-Sepia-NãoIntegrado.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>
using namespace std;

#define MAX_PIXEL 255

int main() {
	ifstream inFile;
	ofstream outFile;
	unsigned char header[54];
	unsigned char colorTable[1024];

	inFile.open("lenna.bmp", ios::in | ios::binary);
	if (!inFile) {
		cout << "Error opening file" << endl;
		return 1;
	}

	outFile.open("lenna-sepia.bmp", ios::out | ios::binary);
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
	int r, g, b;
	unsigned char buffer[imgSize][3];

	for (int i = 0; i < imgSize; ++i) {
		r = g = b = 0;
		buffer[i][0] = inFile.get();	// R
		buffer[i][1] = inFile.get();	// G
		buffer[i][2] = inFile.get();	// B

		r = (buffer[i][0] * 0.393) + (buffer[i][1] * 0.769)
				+ (buffer[i][2] * 0.189);
		g = (buffer[i][0] * 0.349) + (buffer[i][1] * 0.686)
				+ (buffer[i][2] * 0.168);
		b = (buffer[i][0] * 0.272) + (buffer[i][1] * 0.534)
				+ (buffer[i][2] * 0.131);

		if (MAX_PIXEL < r) {
			r = MAX_PIXEL;
		}
		if (MAX_PIXEL < g) {
			g = MAX_PIXEL;
		}
		if (MAX_PIXEL < b) {
			b = MAX_PIXEL;
		}
		outFile.put(b);
		outFile.put(g);
		outFile.put(r);
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
