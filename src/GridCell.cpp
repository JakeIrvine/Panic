//
// Created by jake on 18/06/2020.
//

#include "GridCell.h"

Panic::GridCell::GridCell(wchar_t letter, SDL_Color fg, SDL_Color bg) : letter(letter), fg(fg), bg(bg) {}

Panic::GridCell::GridCell(wchar_t letter) : letter(letter), fg(WHITE) {
	// Leave bg as a nullptr to inform that it's meant to be transparent
}
