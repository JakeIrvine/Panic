//
// Created by jake on 10/04/2020.
//

#ifndef PANICLIB_CONSOLE_H
#define PANICLIB_CONSOLE_H
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include "Font.h"

namespace Panic {


/// A console is a region in a Window that can be rendered
class Console {
public:
	Console(int x, int y, int width, int height, SDL_Renderer* renderer);

	int getX();
	int getY();
	int getWidth();
	int getHeight();
	void setX(int x);
	void setY(int y);
	void setWidth(int w);
	void setHeight(int h);

	bool getEnabled();
	void disable();
	void enable();

	void render(SDL_Renderer* renderer);
private:
	SDL_Rect screenspace;
	SDL_Texture *texture;

	bool enabled;

	Font* fonty;
};

}
#endif //PANICLIB_CONSOLE_H
