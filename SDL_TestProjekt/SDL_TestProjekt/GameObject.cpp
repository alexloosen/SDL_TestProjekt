#include "TextureManager.h"
#include "GameObject.h"

GameObject::GameObject(const char * textureSheet, int x, int y)
{
	this->x = x;
	this->y = y;
	objectTexture = TextureManager::LoadTexture(textureSheet);
}

GameObject::~GameObject()
{
}

void GameObject::update()
{

	x++;
	y++;
	srcRect.h = 342;
	srcRect.w = 214;
	srcRect.x = 0;
	srcRect.y = 0;

	destRect.x = x;
	destRect.y = y;
	destRect.w = srcRect.w / 3;
	destRect.h = srcRect.h / 3;
}

void GameObject::render()
{
	SDL_RenderCopy(Game::renderer, objectTexture, &srcRect, &destRect);
}
