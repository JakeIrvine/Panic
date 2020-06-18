//
// Created by jake on 10/04/2020.
//

#include "Font.h"
#include <cassert>

using namespace Panic;

// Defines the range of characters to cache and render
const int MIN_CHAR = 0;
const int MAX_CHAR = 255;

Font::Font(std::string fontName, int pixelSize, int padding, FontMode mode, SDL_Renderer* renderer) {
	int y = pixelSize;
	this->pixelSize = pixelSize;
	font = TTF_OpenFont(("res/" + fontName + ".ttf").c_str(), pixelSize);

	// Get the width of the font to determine if we need padding
	int minx,maxx,miny,maxy,advance;
	TTF_GlyphMetrics(font,'O',&minx,&maxx,&miny,&maxy,&advance);


	fontWidth = maxx-minx;
	fontHeight = maxy-miny;
	if (fontHeight < fontWidth) {
		static_assert("Panic does not yet support fonts that are wider than they are tall.");
	}

	vpad = padding;
	lpad = padding;// + fontWidth/2;
	rpad = padding;// + fontWidth/2;
	if (fontWidth % 2 != 0) {
		rpad ++; // Ensure that the pixels line up properly even if the width of the font is odd.
	}

	// Create big boy texture for all the glyphs
	glyphCache = SDL_CreateTexture(renderer,
			SDL_PIXELFORMAT_ARGB8888,
			SDL_TEXTUREACCESS_TARGET,
								   (pixelSize+padding*2)*(MAX_CHAR - MIN_CHAR),
			fontHeight+padding*2);

	SDL_SetRenderTarget(renderer, glyphCache);
	SDL_RenderClear(renderer);
	// Render each glyph to the texture
	for (wchar_t ch = MIN_CHAR; ch <= MAX_CHAR; ch++) {
		SDL_Surface* surface = TTF_RenderGlyph_Solid(font, ch, {255,255,255});
		if(surface) {
			SDL_Texture *glyph = SDL_CreateTextureFromSurface(renderer, surface);
			SDL_Rect r{
					lpad + (ch * (pixelSize + padding * 2)),
					vpad,
					fontWidth,
					fontHeight,//surface->h/*+vpad*2*/, // For some font sizes, the surface height can change over time. I have no idea what causes this.
			};

			SDL_Rect dest {
				0,
				0,
				fontWidth,
				fontHeight
			};
			SDL_RenderCopy(renderer, glyph, &dest, &r);
		}
	}
	SDL_SetRenderTarget(renderer, nullptr);
}

std::pair<SDL_Texture*, SDL_Rect> Font::getGlyph(wchar_t glyph) {
	/**SDL_Rect rect = {
			glyph*(fontWidth+rpad+lpad), // Perhaps add two?
			0,
			fontWidth+rpad+lpad,
			fontHeight+vpad*2
	};**/
	SDL_Rect rect = {
			glyph*(pixelSize+lpad+rpad), // Perhaps add two?
			0,
			pixelSize+lpad+rpad,
			fontHeight+vpad*2
	};
	return std::pair<SDL_Texture*, SDL_Rect>(glyphCache, rect);
}
