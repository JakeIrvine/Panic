//
// Created by jake on 10/04/2020.
//


#include "Console.h"

using namespace Panic;

// Library users: do not use this constructor directly, use functions from a Window instead.
Console::Console(int x, int y, int width, int height, SDL_Renderer* renderer) {
	screenspace = SDL_Rect();
	screenspace.x = x;
	screenspace.y = y;
	screenspace.w = width;
	screenspace.h = height;

	texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, width, height);
}

int Console::getX() {
	return screenspace.x;
}

int Console::getY() {
	return screenspace.y;
}

int Console::getWidth() {
	return screenspace.w;
}

int Console::getHeight() {
	return screenspace.h;
}

void Console::setX(int x) {
	screenspace.x = x;
}

void Console::setY(int y) {
	screenspace.y = y;
}

void Console::setWidth(int w) {
	screenspace.w = w;
}

void Console::setHeight(int h) {
	screenspace.h = h;
}

bool Console::getEnabled() {
	return enabled;
}

void Console::enable() {
	enabled = true;
}

void Console::disable() {
	enabled = false;
}

void Console::render(SDL_Renderer* renderer) {
	if (enabled) {
		SDL_SetRenderTarget(renderer, texture);
		draw(renderer);
		SDL_SetRenderTarget(renderer, nullptr);

		SDL_RenderCopy(renderer, texture, nullptr, &screenspace);
	}
}

void Console::draw(SDL_Renderer* renderer) {
	SDL_SetRenderDrawColor(renderer, 255, 0, 255, 255);
	SDL_RenderClear(renderer);
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
}

