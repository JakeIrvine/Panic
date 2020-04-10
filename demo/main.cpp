//
// Created by jake on 09/04/2020.
//
#include "panic.h"
#include <thread>
#include <SDL2/SDL.h>

int main() {
	Panic::init();
	auto window = Panic::Window("Jake's Shitty Library Test Thing");

	window.createConsole(10, 10, 80, 80, 0);
	window.render();

	bool quit = false;
	int counter = 0;
	while(!quit) {
		int start = SDL_GetTicks();
		counter++;
		if (counter == 60) {
			counter = 0;
			if(window.getConsole(0)->getEnabled()) {
				window.getConsole(0)->disable();
			} else {
				window.getConsole(0)->enable();
			}
		}
		window.render();
		int time = SDL_GetTicks() - start;
		int timeToSleep = 16 - time;
		SDL_Delay(timeToSleep);
	}

	std::this_thread::sleep_for(std::chrono::seconds(1000));
}