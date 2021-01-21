/*
 * Screen.cpp
 *
 *  Created on: 5 de mai de 2020
 *      Author: rfarah
 */

#include "Screen.h"

namespace rfh {
Screen::Screen() :
		m_pWindow(NULL), m_pRenderer(NULL), m_pTexture(NULL), m_pBuffer1(NULL), m_pBuffer2(NULL) {

}

bool Screen::init() {
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		SDL_Quit();
		return false;
	}

	m_pWindow = SDL_CreateWindow("Particle Fire Explosion",
	SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH,
			SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

	if (m_pWindow == NULL) {
		SDL_DestroyWindow(m_pWindow);
		SDL_Quit();
		return false;
	}

	m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, SDL_RENDERER_PRESENTVSYNC);

	if (m_pRenderer == NULL) {
		SDL_DestroyRenderer(m_pRenderer);
		SDL_DestroyWindow(m_pWindow);
		SDL_Quit();
		return false;
	}

	m_pTexture = SDL_CreateTexture(m_pRenderer, SDL_PIXELFORMAT_RGBA8888,
			SDL_TEXTUREACCESS_STATIC, SCREEN_WIDTH, SCREEN_HEIGHT);

	if (m_pTexture == NULL) {
		SDL_DestroyTexture(m_pTexture);
		SDL_DestroyRenderer(m_pRenderer);
		SDL_DestroyWindow(m_pWindow);
		SDL_Quit();
		return false;
	}

	m_pBuffer1 = new Uint32[SCREEN_WIDTH * SCREEN_HEIGHT]; // should be checked to success
	m_pBuffer2 = new Uint32[SCREEN_WIDTH * SCREEN_HEIGHT]; // should be checked to success

	memset(m_pBuffer1, 0x00, SCREEN_WIDTH * SCREEN_HEIGHT * sizeof(Uint32));
	memset(m_pBuffer2, 0x00, SCREEN_WIDTH * SCREEN_HEIGHT * sizeof(Uint32));

	return true;
}

void Screen::update() {
	SDL_UpdateTexture(m_pTexture, NULL, m_pBuffer1,
			SCREEN_WIDTH * sizeof(Uint32));
	SDL_RenderClear(m_pRenderer);
	SDL_RenderCopy(m_pRenderer, m_pTexture, NULL, NULL);
	SDL_RenderPresent(m_pRenderer);
}

void Screen::clear() {
	memset(m_pBuffer1, 0x00, SCREEN_WIDTH * SCREEN_HEIGHT * sizeof(Uint32));
	memset(m_pBuffer2, 0x00, SCREEN_WIDTH * SCREEN_HEIGHT * sizeof(Uint32));
}

void Screen::setPixel(int x, int y, Uint8 red, Uint8 green, Uint8 blue) {
	if (x < 0 || x >= SCREEN_WIDTH || y < 0 || y >= SCREEN_HEIGHT) {
		return;
	}

	Uint32 color = 0;

	color += red;
	color <<= 8;
	color += green;
	color <<= 8;
	color += blue;
	color <<= 8;
	color += 0xFF;

	m_pBuffer1[(y * SCREEN_WIDTH) + x] = color;
}

void Screen::boxBlur() {
	// Swap buffers
	Uint32 *temp = m_pBuffer1;

	m_pBuffer1 = m_pBuffer2;
	m_pBuffer2 = temp;

	for (int y = 0; y < SCREEN_HEIGHT; y++) {
		for (int x = 0; x < SCREEN_WIDTH; x++) {
			/*
			 * 0 0 0
			 * 0 1 0
			 * 0 0 0
			 */

			int redTotal = 0;
			int greenTotal = 0;
			int blueTotal = 0;

			for (int row = -1; row <= 1; row++) {
				for (int col = -1; col <= 1; col++) {
					int currentX = x + col;
					int currentY = y + row;

					if (currentX >= 0 && currentX < SCREEN_WIDTH
							&& currentY >= 0 && currentY < SCREEN_HEIGHT) {
						Uint32 color = m_pBuffer2[currentY * SCREEN_WIDTH + currentX];
						Uint8 red = (color & 0xFF000000) >> (3 * 8);
						Uint8 green = (color & 0x00FF0000) >> (2 * 8);
						Uint8 blue = (color & 0x0000FF00) >> (1 * 8);

						redTotal += red;
						greenTotal += green;
						blueTotal += blue;
					}
				}
			}

			Uint8 red = redTotal / 9;
			Uint8 green = greenTotal / 9;
			Uint8 blue = blueTotal / 9;

			setPixel(x, y, red, green, blue);
		}
	}
}

bool Screen::processEvents() {
	SDL_Event event;

	while (SDL_PollEvent(&event)) {
		if (event.type == SDL_QUIT) {
			return false;
		}
	}
	return true;
}

void Screen::close() {
	delete[] m_pBuffer1;
	delete[] m_pBuffer2;
	SDL_DestroyTexture(m_pTexture);
	SDL_DestroyRenderer(m_pRenderer);
	SDL_DestroyWindow(m_pWindow);
	SDL_Quit();
}

} /* namespace rfh */
