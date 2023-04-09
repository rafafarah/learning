/*
 * BitmapFileHeader.h
 *
 *  Created on: 25 de mai de 2020
 *      Author: rfarah
 */

#ifndef BITMAPFILEHEADER_H_
#define BITMAPFILEHEADER_H_

#include <cstdint>
using namespace std;

#pragma pack(2)

namespace rfh {

struct BitmapFileHeader {
	char header[2] { 'B', 'M' };
	int32_t sizeFile;
	int32_t reserved { 0 };
	int32_t dataOffset;
};

}  // namespace rfh

#endif /* BITMAPFILEHEADER_H_ */
