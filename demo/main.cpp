//
// Created by jake on 09/04/2020.
//
#include "panic.h"
#include <thread>
#include <SDL2/SDL.h>

int main() {
	Panic::init();
	auto window = Panic::Window("Kernel's Shitty Library Test Thing", 1000, 1000);

	window.createConsole(0, 0, 4590, 1800, 0);
	window.render();


	bool quit = false;
	int counter = 0;
	while(!quit) {
		int start = SDL_GetTicks();
		counter++;
		if (counter == 1) {
			counter = 0;
			if(window.getConsole(0)->getEnabled()) {
				//window.getConsole(0)->disable();
				//window.getConsole(0)->setX(window.getConsole(0)->getX()-1);
			} else {
				window.getConsole(0)->enable();
			}
		}
		window.render();
		int time = SDL_GetTicks() - start;
		int timeToSleep = 16 - time;
		if(timeToSleep > 16) {
			timeToSleep = 0;
			// Sometimes SDL_GetTicks can overflow, prevent that here
		}
		SDL_Delay(timeToSleep);
	}

}