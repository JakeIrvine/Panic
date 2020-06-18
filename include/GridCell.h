//
// Created by jake on 18/06/2020.
//

#ifndef PANICLIB_GRIDCELL_H
#define PANICLIB_GRIDCELL_H

#include <SDL2/SDL_pixels.h>

namespace Panic {

// TODO: Make this an enum
static const SDL_Color WHITE = SDL_Color{.r =  255,
										 .g =  255,
										 .b =  255};

// Basic implementation
// TODO: Make better later
class GridCell {
public:

	GridCell(wchar_t letter, SDL_Color fg, SDL_Color bg);

	// oh no now I have to make a Color class :(
	// Ehh this will do for now

	SDL_Color bg;
	SDL_Color fg;

	// TODO: tileset support at some point
	// Not really needed for a while
	wchar_t letter;
};

}

#endif //PANICLIB_GRIDCELL_H
