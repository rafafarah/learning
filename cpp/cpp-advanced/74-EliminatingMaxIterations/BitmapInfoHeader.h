/*
 * BitmapInfoHeader.h
 *
 *  Created on: 25 de mai de 2020
 *      Author: rfarah
 */

#ifndef BITMAPINFOHEADER_H_
#define BITMAPINFOHEADER_H_

#include <cstdint>
using namespace std;

#pragma pack(2)

namespace rfh {

struct BitmapInfoHeader {
	int32_t headerSizer { sizeof(struct BitmapInfoHeader) };
	int32_t width;
	int32_t height;
	int16_t planes { 1 };
	int16_t bitsPerPixel { 24 };
	int32_t compression { 0 };
	int32_t dataSize { 0 };
	int32_t horizontalResolution { 2400 };
	int32_t verticalResolution { 2400 };
	int32_t colors { 0 };
	int32_t importantColors { 0 };
};

}  // namespace rfh

#endif /* BITMAPINFOHEADER_H_ */
