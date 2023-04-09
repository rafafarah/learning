/*
 * ZoomList.h
 *
 *  Created on: 25 de mai de 2020
 *      Author: rfarah
 */

#ifndef ZOOMLIST_H_
#define ZOOMLIST_H_

#include <vector>
#include <utility>
#include "Zoom.h"

using namespace std;

namespace rfh {

class ZoomList {
private:
	int m_width { 0 };
	int m_height { 0 };
	vector<Zoom> zooms;

public:
	ZoomList(int width, int height);
	void add(Zoom &zoom);
	pair<double, double> doZoom(int x, int y);
};

} /* namespace rfh */

#endif /* ZOOMLIST_H_ */
