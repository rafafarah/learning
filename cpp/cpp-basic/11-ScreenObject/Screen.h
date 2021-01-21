/*
 * Screen.h
 *
 *  Created on: 4 de mai de 2020
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
	Uint32 *m_pBuffer;

public:
	Screen();
	bool init();
	bool processEvents();
	void close();
};

} /* namespace rfh */

#endif /* SCREEN_H_ */
