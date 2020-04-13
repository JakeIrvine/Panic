//
// Created by jake on 10/04/2020.
//

#ifndef PANICLIB_FONT_H
#define PANICLIB_FONT_H

#include <SDL2/SDL_ttf.h>
#include <string>
#include <vector>

namespace Panic {

enum FontMode {
	SQUARE,
	HALFWIDTH
};

class Font {
public:
	Font(std::string fontName, int pixelSize, int padding, FontMode mode, SDL_Renderer* renderer);
	std::pair<SDL_Texture*, SDL_Rect> getGlyph(wchar_t glyph);
	SDL_Texture* glyphCache;

private:
	TTF_Font* font;
	SDL_Renderer* renderer;
	//std::vector<SDL_Rect> glyphCacheAreas;

	int fontWidth;
	int fontHeight;
	int vpad;
	int lpad;
	int rpad;

};

}
#endif //PANICLIB_FONT_H
