//============================================================================
// Name        : 114-ImageReaderImageWriter.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

#define BMP_HEADER_SIZE 54
#define BMP_COLOR_TABLE_SIZE 1024
#define OFFSET_WIDTH 18
#define OFFSET_HEIGHT 22
#define OFFSET_BIT_DEPTH 28
const int CUSTOM_IMG_SIZE = 1024 * 1024;

int imageReader(const char *imgName, int *_height, int *_width, int *_bitDepth,
		unsigned char *_header, unsigned char *_colorTable,
		unsigned char *_buf);

int imageWriter(const char *imgName, const int height, const int width,
		const int bitDepth, const unsigned char *header,
		const unsigned char *colorTable, const unsigned char *buf);

int main() {
	int ret = 0;
	int height = 0;
	int width = 0;
	int bitDepth = 0;
	unsigned char header[BMP_HEADER_SIZE];
	unsigned char colorTable[BMP_COLOR_TABLE_SIZE];
	unsigned char buf[CUSTOM_IMG_SIZE];

	ret = imageReader("images/man.bmp", &height, &width, &bitDepth, header,
			colorTable, buf);
	if (ret) {
		cout << "Error reading file" << endl;
		return ret;
	}
	ret = imageWriter("images/man_copy.bmp", height, width, bitDepth, header,
			colorTable, buf);
	if (ret) {
		cout << "Error writing file" << endl;
		return ret;
	}

	cout << "Finished" << endl;

	return 0;
}

int imageReader(const char *imgName, int *_height, int *_width, int *_bitDepth,
		unsigned char *_header, unsigned char *_colorTable,
		unsigned char *_buf) {
	FILE *streamIn = fopen(imgName, "rb");
	if (!streamIn) {
		cout << "File do not exist" << endl;
		return 1;
	}

	for (int i = 0; i < BMP_HEADER_SIZE; ++i) {
		_header[i] = getc(streamIn);
	}
	*_width = *(int*) &_header[OFFSET_WIDTH];
	*_height = *(int*) &_header[OFFSET_HEIGHT];
	*_bitDepth = *(int*) &_header[OFFSET_BIT_DEPTH];

	if (*_bitDepth <= 8) {
		fread(_colorTable, sizeof(unsigned char), BMP_COLOR_TABLE_SIZE,
				streamIn);
	}

	fread(_buf, sizeof(unsigned char), *_width * *_height, streamIn);

	fclose(streamIn);

	return 0;
}

int imageWriter(const char *imgName, const int height, const int width,
		const int bitDepth, const unsigned char *header,
		const unsigned char *colorTable, const unsigned char *buf) {
	FILE *fo = fopen(imgName, "wb");

	if (!fo) {
		cout << "Problem creating file." << endl;
		return 2;
	}

	fwrite(header, sizeof(unsigned char), BMP_HEADER_SIZE, fo);

	if (bitDepth <= 8) {
		fwrite(colorTable, sizeof(unsigned char), BMP_COLOR_TABLE_SIZE, fo);
	}

	fwrite(buf, sizeof(unsigned char), width * height, fo);

	fclose(fo);

	return 0;
}
