#pragma once
#include "Game.h"

class TextureManager
{
public:
	static SDL_Texture* LoadTexture(const char* fileName);
	static void draw(SDL_Texture* texture, SDL_Rect src, SDL_Rect dest);
};
