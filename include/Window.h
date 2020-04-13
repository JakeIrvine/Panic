//
// Created by jake on 09/04/2020.
//

#ifndef PANICLIB_WINDOW_H
#define PANICLIB_WINDOW_H

#include <SDL2/SDL.h>
#include <iostream>
#include <vector>
#include "Console.h"
#include "Font.h"

namespace Panic {
typedef unsigned char byte;
class Window {
public:
	Window(std::string title, int w, int h);
	~Window();

	Console* createConsole(int x, int y, int w, int h, byte index);
	Console* getConsole(byte index);
	void removeConsole(byte index);

	Font createFont(std::string fontName, int pixelSize, int padding, FontMode mode);

	void render();
private:
	SDL_Window* window;
	SDL_Renderer* renderer;
	std::string windowName;

	std::vector<Console*> consoles;
};

}

#endif //PANICLIB_WINDOW_H
