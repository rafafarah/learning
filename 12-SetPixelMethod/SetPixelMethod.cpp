//============================================================================
// Name        : 12-SetPixelMethod.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <SDL.h>
#include "Screen.h"

using namespace std;
using namespace rfh;

int main() {
	Screen screen;

	if (screen.init() == false) {
		cout << "Error initializing SDL." << endl;
	}

	while (true) {
		// Update particles

		// Draw particles
		for (int y = 0; y < Screen::SCREEN_HEIGHT; y++) {
			for (int x = 0; x < Screen::SCREEN_WIDTH; x++) {
				screen.setPixel(x, y, 128, 0, 255);
			}
		}

//		for (int i = 0; i < Screen::SCREEN_WIDTH * Screen::SCREEN_HEIGHT; i++) {
//			//		m_pBuffer[i] = 0xFF0000FF; // Red
//			//		m_pBuffer[i] = 0x00FF00FF; // Green
//			//		m_pBuffer[i] = 0x123456FF; // Blue
//			//		m_pBuffer[i] = 0xFF00FFFF; // Magenta
//			//		m_pBuffer[i] = 0xFFFF00FF; // Yellow
//			//		m_pBuffer[i] = 0x00FFFFFF; // Cyan
//		}
		screen.setPixel(400, 300, 255, 255, 255);

// Draw the screen
		screen.update();

		if (screen.processEvents() == false) {
			break;
		}
	}

	return 0;
}
