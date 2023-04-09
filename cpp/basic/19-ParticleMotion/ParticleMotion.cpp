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
#include <stdlib.h>
#include <time.h>
#include "Screen.h"
#include "Swarm.h"

using namespace std;
using namespace rfh;

int main() {
	srand(time(NULL));

	Screen screen;

	if (screen.init() == false) {
		cout << "Error initializing SDL." << endl;
	}

	Swarm swarm;

	while (true) {
		int elapsed = SDL_GetTicks();

		// Update particles
		swarm.update(elapsed);

		unsigned char red = (1 + sin(elapsed * 0.0003)) * 128;
		unsigned char green = (1 + sin(elapsed * 0.0006)) * 128;
		unsigned char blue = (1 + sin(elapsed * 0.0009)) * 128;

		const Particle *const pParticles = swarm.getParticles();

		for (int i = 0; i < Swarm::NPARTICLES; i++) {
			Particle particle = pParticles[i];

			int x = (particle.m_x + 1) * (Screen::SCREEN_WIDTH / 2);
			int y = particle.m_y * (Screen::SCREEN_WIDTH / 2)
					+ Screen::SCREEN_HEIGHT / 2;
			screen.setPixel(x, y, red, green, blue);
		}

		screen.boxBlur();

		// Draw the screen
		screen.update();

		if (screen.processEvents() == false) {
			break;
		}
	}

	return 0;
}
