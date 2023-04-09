/*
 * ImageProcessing.h
 *
 *  Created on: 26 de mai de 2020
 *      Author: rfarah
 */

#ifndef IMAGEPROCESSING_H_
#define IMAGEPROCESSING_H_

#include <string>
#include <array>
#include <vector>

using namespace std;

namespace rfh {

struct Mask {
	int rows;
	int cols;
	vector<char> data { };
};

static const int HORIZONTAL_MASK[3][3] = { { -1, 2, -1 }, { -1, 2, -1 }, { -1,
		2, -1 } };

static const int VERTICAL_MASK[3][3] = { { -1, -1, -1 }, { 2, 2, 2 }, { -1, -1,
		-1 } };

static const int RIGHT_DIAGONAL_MASK[3][3] = { { 2, -1, -1 }, { -1, 2, -1 }, {
		-1, -1, 2 } };

static const int LEFT_DIAGONAL_MASK[3][3] = { { -1, -1, 2 }, { -1, 2, -1 }, { 2,
		-1, -1 } };

static const Mask PREWITT_VERTICAL = { 3, 3, { -1, 0, 1, -1, 0, 1, -1, 0, 1 } };
static const Mask PREWITT_HORIZONTAL =
		{ 3, 3, { -1, -1, -1, 0, 0, 0, 1, 1, 1 } };

class ImageProcessing {
public:
	static const int BMP_HEADER_SIZE = 54;
	static const int BMP_COLOR_TABLE_SIZE = 1024;
	static const int OFFSET_WIDTH = 18;
	static const int OFFSET_HEIGHT = 22;
	static const int OFFSET_BIT_DEPTH = 28;
	static const int MAX_COLOR = 255;
	static const int MIN_COLOR = 0;
	static const int WHITE = MAX_COLOR;
	static const int BLACK = MIN_COLOR;
	static const int TOTAL_COLORS = 256;

private:
	int height { 0 };
	int width { 0 };
	int bitDepth { 0 };
	array<unsigned char, BMP_HEADER_SIZE> header { };
	array<unsigned char, BMP_COLOR_TABLE_SIZE> colorTable { };
	vector<unsigned char> buffer { };
	array<double, TOTAL_COLORS> histogram { };

private:
	void rotateRight();
	void rotateLeft();
	void rotateUpSideDown();
	void copyVector2DToBuffer(vector<vector<unsigned char>> &imgTemp);

public:
	ImageProcessing();
	virtual ~ImageProcessing();

	void readImage(string name);
	void writeImage(string name);
//	void copyImageBuffer(const vector<unsigned char> &buff);
	void binarizeImage(int threshold);
	void changeBrightness(int brightness);
	void computeHistogram(string name);
	void equalizeHistogram(string name);
	void rotateImage(int rotation);
	void negativeImage();
	void convolve2D(const Mask &mask);
	void lineDetector(const int mask[][3]);

	void print();
};

} /* namespace rfh */

#endif /* IMAGEPROCESSING_H_ */
