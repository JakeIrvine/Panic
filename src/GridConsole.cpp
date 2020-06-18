//
// Created by jake on 14/06/2020.
//

#include <GridConsole.h>

#include "GridConsole.h"

Panic::GridConsole::GridConsole(int x, int y, int width, int height, SDL_Renderer *renderer, int pixelHeight,
								int pixelWidth)
								: Console(x, y, width, height, renderer), cellHeight(pixelHeight), cellWidth(pixelWidth),
								font("terminus_bold", 16, 1, FontMode::SQUARE, renderer)
								{}

int Panic::GridConsole::getCellHeight() {
	return cellHeight;
}

int Panic::GridConsole::getCellWidth() {
	return cellWidth;
}

int Panic::GridConsole::getGridHeight() {
	return getHeight() / getCellHeight();
}

int Panic::GridConsole::getGridWidth() {
	return getWidth() / getCellWidth();
}

void Panic::GridConsole::draw(SDL_Renderer *renderer) {
	SDL_SetRenderDrawColor(renderer, 255, 255, 0, 255);

	drawLetter('t', 100, 100, renderer);
	drawLetter('e', 100+9, 100, renderer);
	drawLetter('s', 100+9*2, 100, renderer);
	drawLetter('t', 100+9*3, 100, renderer);

	//SDL_RenderClear(renderer);
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
}

void Panic::GridConsole::drawLetter(wchar_t letter, int x, int y, SDL_Renderer *renderer) {
	auto letterTex = font.getGlyph(letter);
	SDL_RenderCopy(renderer, letterTex.first, &letterTex.second, new SDL_Rect{x, y, cellWidth, cellHeight});
}


