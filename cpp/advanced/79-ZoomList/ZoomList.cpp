/*
 * ZoomList.cpp
 *
 *  Created on: 25 de mai de 2020
 *      Author: rfarah
 */

#include "ZoomList.h"

namespace rfh {

ZoomList::ZoomList(int width, int height) :
		m_width(width), m_height(height) {

}

void ZoomList::add(Zoom &zoom) {
	zooms.push_back(zoom);
}

pair<double, double> ZoomList::doZoom(int x, int y) {
	return pair<double, double>(0, 0);
}

} /* namespace rfh */
