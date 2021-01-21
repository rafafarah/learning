//============================================================================
// Name        : 13-AnimatingColors.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <SDL.h>
#include <math.h>
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
		int elapsed = SDL_GetTicks();

		unsigned char red = (1 + sin(elapsed*0.0003)) * 128;
		unsigned char green = (1 + sin(elapsed*0.0006)) * 128;
		unsigned char blue = (1 + sin(elapsed*0.0009)) * 128;

		// Draw particles
		for (int y = 0; y < Screen::SCREEN_HEIGHT; y++) {
			for (int x = 0; x < Screen::SCREEN_WIDTH; x++) {
				screen.setPixel(x, y, red, green, blue);
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

// Draw the screen
		screen.update();

		if (screen.processEvents() == false) {
			break;
		}
	}

	return 0;
}
