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

class ImageProcessing {
public:
	const static int BMP_HEADER_SIZE = 54;
	const static int BMP_COLOR_TABLE_SIZE = 1024;
	const static int OFFSET_WIDTH = 18;
	const static int OFFSET_HEIGHT = 22;
	const static int OFFSET_BIT_DEPTH = 28;

private:
	int height { 0 };
	int width { 0 };
	int bitDepth { 0 };
	array<char, BMP_HEADER_SIZE> header { };
	array<char, BMP_COLOR_TABLE_SIZE> colorTable { };
	vector<char> buffer { };

public:
	ImageProcessing();
	virtual ~ImageProcessing();

	void readImage(string name);
	void writeImage(string name);
	void copyImageBuffer(const vector<char> &buff);
	void print();
};

} /* namespace rfh */

#endif /* IMAGEPROCESSING_H_ */
