/*
 * Bitmap.cpp
 *
 *  Created on: 25 de mai de 2020
 *      Author: rfarah
 */

#include "Bitmap.h"
#include "BitmapInfoHeader.h"
#include "BitmapFileHeader.h"
using namespace rfh;

namespace rfh {

Bitmap::Bitmap(int width, int height) :
		m_width(width), m_height(height), m_pPixels(
				new uint8_t[width * height * 3] { }) {

}

void Bitmap::setPixel(int x, int y, uint8_t red, uint8_t green, uint8_t blue) {

}

bool Bitmap::write(string filename) {
	BitmapFileHeader fileHeader;
	BitmapInfoHeader infoHeader;

	fileHeader.fileSize = sizeof(fileHeader) + sizeof(infoHeader)
			+ (m_width * m_height * 3);
	fileHeader.dataOffset = sizeof(fileHeader) + sizeof(infoHeader);

	infoHeader.width = m_width;
	infoHeader.height = m_height;

	return false;
}

Bitmap::~Bitmap() {
	// TODO Auto-generated destructor stub
}

} /* namespace rfh */
