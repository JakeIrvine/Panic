//
// Created by jake on 14/06/2020.
//

#ifndef PANICLIB_GRIDCONSOLE_H
#define PANICLIB_GRIDCONSOLE_H

#include "Console.h"

namespace Panic {

// GridConsole is like console but with grids and shit
class GridConsole : public Console {
public:
	GridConsole(int x, int y, int width, int height, SDL_Renderer *renderer, int pixelHeight, int pixelWidth);
	~GridConsole();

	int getCellHeight();
	int getCellWidth();
	int getGridHeight();
	int getGridWidth();

	void draw(SDL_Renderer *renderer) override;
	void print(std::string text, int x, int y);

private:
	int cellHeight;
	int cellWidth;

	Font font;

	void drawLetter(wchar_t letter, int x, int y, SDL_Renderer *renderer);
};

}

#endif //PANICLIB_GRIDCONSOLE_H
