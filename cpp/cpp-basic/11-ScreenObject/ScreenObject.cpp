//============================================================================
// Name        : ScreenObject.cpp
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
		// Check for messages/events
		if (screen.processEvents() == false) {
			break;
		}
	}

	return 0;
}
