/*
 * Screen.h
 *
 *  Created on: 5 de mai de 2020
 *      Author: rfarah
 */

#ifndef SCREEN_H_
#define SCREEN_H_

#include <SDL.h>

namespace rfh {

class Screen {
public:
	const static int SCREEN_WIDTH = 800;
	const static int SCREEN_HEIGHT = 600;
private:
	SDL_Window *m_pWindow;
	SDL_Renderer *m_pRenderer;
	SDL_Texture *m_pTexture;
	Uint32 *m_pBuffer1;
	Uint32 *m_pBuffer2;

public:
	Screen();
	bool init();
	void update();
	void clear();
	void setPixel(int x, int y, Uint8 red, Uint8 green, Uint8 blue);
	void boxBlur();
	bool processEvents();
	void close();
};

} /* namespace rfh */

#endif /* SCREEN_H_ */
