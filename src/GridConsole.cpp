//
// Created by jake on 14/06/2020.
//

#include <GridConsole.h>

Panic::GridConsole::GridConsole(int x, int y, int width, int height, SDL_Renderer *renderer, int pixelHeight,
								int pixelWidth)
								: Console(x, y, width, height, renderer), cellHeight(pixelHeight), cellWidth(pixelWidth),
								font("terminus_bold", 18, 0, FontMode::SQUARE, renderer)
								{
	// intitalize the grid to be empty
	for(int i=0; i<getGridWidth(); i++) {
		// Create a row
		grid.emplace_back();

		// Populate that row
		for(int j=0; j<getGridHeight(); j++) {
			grid[i].emplace_back(' ');
		}
	}
								}

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

	for(int x=0; x < grid.size(); x++) {
		for(int y=0; y < grid[0].size(); y++) {
			drawLetter('a'+x+y, cellWidth*x, cellHeight*y, renderer);
		}
	}

	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
}

void Panic::GridConsole::drawLetter(wchar_t letter, int x, int y, SDL_Renderer *renderer) {
	auto letterTex = font.getGlyph(letter);
	SDL_RenderCopy(renderer, letterTex.first, &letterTex.second, new SDL_Rect{x, y, cellWidth, cellHeight});
}

void Panic::GridConsole::print(std::string text, int x, int y) {

}