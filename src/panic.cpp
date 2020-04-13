//
// Created by jake on 09/04/2020.
//
#include <iostream>
#include "SDL2/SDL.h"
#include "SDL2/SDL_ttf.h"
#include "panic.h"

namespace Panic {

void init() {
	if (!initSDL() || !initSDLttf()) {
		exit(-1);
	}
}

bool initSDL() {
	int returnCode = SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS);
	if (returnCode != 0) { // Non-zero value indicates an error
		std::cout << "Failed to initialize SDL!\n";
		std::cout << "Error: " << SDL_GetError() << std::endl;
		return false;
	}
	return true;
}

bool initSDLttf() {
	int returnCode = TTF_Init();
	if (returnCode != 0) { // Non-zero value indicates an error
		std::cout << "Failed to initialize SDL TTF!\n";
		std::cout << "Error: " << TTF_GetError() << std::endl;
		return false;
	}
	return true;
}

void quit() {
	SDL_Quit();
}

}