//============================================================================
// Name        : EnablingPixelAccess.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <SDL.h>

using namespace std;

int main() {
	const int SCREEN_WIDTH = 800;
	const int SCREEN_HEIGHT = 600;

	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		cout << "SDL init failed" << endl;
		SDL_Quit();
		return 1;
	}

	SDL_Window *pWindow = SDL_CreateWindow("Particle Fire Explosion",
	SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH,
			SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

	if (pWindow == NULL) {
		cout << "Failed creating the window. Error: " << SDL_GetError() << endl;
		SDL_DestroyWindow(pWindow);
		SDL_Quit();
		return 2;
	}

	SDL_Renderer *pRenderer = SDL_CreateRenderer(pWindow, -1,
			SDL_RENDERER_PRESENTVSYNC);

	if (pRenderer == NULL) {
		cout << "Failed creating the renderer. Error: " << SDL_GetError()
				<< endl;
		SDL_DestroyRenderer(pRenderer);
		SDL_DestroyWindow(pWindow);
		SDL_Quit();
		return 3;
	}

	SDL_Texture *pTexture = SDL_CreateTexture(pRenderer,
			SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_STATIC, SCREEN_WIDTH,
			SCREEN_HEIGHT);

	if (pTexture == NULL) {
		cout << "Failed creating the texture. Error: " << SDL_GetError()
				<< endl;
		SDL_DestroyTexture(pTexture);
		SDL_DestroyRenderer(pRenderer);
		SDL_DestroyWindow(pWindow);
		SDL_Quit();
		return 4;
	}

	Uint32 *pBuffer = new Uint32[SCREEN_WIDTH * SCREEN_HEIGHT]; // should be checked to success

	memset(pBuffer, 0xFF, SCREEN_WIDTH*SCREEN_HEIGHT*sizeof(Uint32));

	SDL_UpdateTexture(pTexture, NULL, pBuffer, SCREEN_WIDTH * sizeof(Uint32));
	SDL_RenderClear(pRenderer);
	SDL_RenderCopy(pRenderer, pTexture, NULL, NULL);
	SDL_RenderPresent(pRenderer);

	bool quit = false;

	SDL_Event event;

	while (!quit) {
		// Update particles
		// Draw particles
		// Check for messages/events

		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_QUIT) {
				quit = true;
			}
		}
	}

	delete [] pBuffer;
	SDL_DestroyTexture(pTexture);
	SDL_DestroyRenderer(pRenderer);
	SDL_DestroyWindow(pWindow);
	SDL_Quit();
	return 0;
}
