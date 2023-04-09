//============================================================================
// Name        : 113-OpeningAndCopyingAnImage.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int main() {
	FILE *streamIn = fopen("images/cameraman.bmp", "rb");
	FILE *fo = fopen("images/cameraman_copy.bmp", "wb");

	if (!streamIn) {
		cout << "File do not exist" << endl;
		return 1;
	}
	if (!fo) {
		cout << "Problem creating file." << endl;
		return 2;
	}

	unsigned char header[54];
	unsigned char colorTable[1024];

	for (int i = 0; i < 54; ++i) {
		header[i] = getc(streamIn);
	}

	int width = *(int*) &header[18];
	int height = *(int*) &header[22];
	int bitDepth = *(int*) &header[28];

	if (bitDepth <= 8) {
		fread(colorTable, sizeof(unsigned char), 1024, streamIn);
	}

	unsigned char buff[width * height];
	fread(buff, sizeof(unsigned char), width * height, streamIn);

	fwrite(header, sizeof(unsigned char), 54, fo);

	if (bitDepth <= 8) {
		fwrite(colorTable, sizeof(unsigned char), 1024, fo);
	}

	fwrite(buff, sizeof(unsigned char), width * height, fo);

	fclose(streamIn);
	fclose(fo);

	cout << "Finished" << endl;

	return 0;
}
