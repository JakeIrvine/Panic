//
// Created by jake on 09/04/2020.
//

#ifndef PANICLIB_PANIC_H
#define PANICLIB_PANIC_H

#include "Window.h"
#include "Font.h"

namespace Panic {

void init();

bool initSDL();
bool initSDLttf();

void quit();
}
#endif //PANICLIB_PANIC_H
