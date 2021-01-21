/*
 * Screen.cpp
 *
 *  Created on: 4 de mai de 2020
 *      Author: rfarah
 */

#include "Screen.h"

namespace rfh {
Screen::Screen() :
		m_pWindow(NULL), m_pRenderer(NULL), m_pTexture(NULL), m_pBuffer(NULL) {

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

	m_pBuffer = new Uint32[SCREEN_WIDTH * SCREEN_HEIGHT]; // should be checked to success

	memset(m_pBuffer, 0x00, SCREEN_WIDTH * SCREEN_HEIGHT * sizeof(Uint32));

	for (int i = 0; i < SCREEN_WIDTH * SCREEN_HEIGHT; i++) {
		//		m_pBuffer[i] = 0xFF0000FF; // Red
		//		m_pBuffer[i] = 0x00FF00FF; // Green
		m_pBuffer[i] = 0x123456FF; // Blue
		//		m_pBuffer[i] = 0xFF00FFFF; // Magenta
		//		m_pBuffer[i] = 0xFFFF00FF; // Yellow
		//		m_pBuffer[i] = 0x00FFFFFF; // Cyan
	}

	SDL_UpdateTexture(m_pTexture, NULL, m_pBuffer,
			SCREEN_WIDTH * sizeof(Uint32));
	SDL_RenderClear(m_pRenderer);
	SDL_RenderCopy(m_pRenderer, m_pTexture, NULL, NULL);
	SDL_RenderPresent(m_pRenderer);

	return true;
}

bool Screen::processEvents() {
	SDL_Event event;

	while (SDL_PollEvent (&event)) {
		if (event.type == SDL_QUIT) {
			return false;
		}
	}
	return true;
}

void Screen::close() {
	delete[] m_pBuffer;
	SDL_DestroyTexture(m_pTexture);
	SDL_DestroyRenderer(m_pRenderer);
	SDL_DestroyWindow(m_pWindow);
	SDL_Quit();
}

} /* namespace rfh */
