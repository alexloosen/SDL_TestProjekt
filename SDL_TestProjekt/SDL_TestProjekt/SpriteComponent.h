#pragma once
#include "Components.h"
#include "SDL.h"

class SpriteComponent : public Component
{
private:
	TransformComponent * position;
	SDL_Texture* texture;
	SDL_Rect srcRect, destRect;

public:
	SpriteComponent() = default;
	SpriteComponent(const char* path)
	{
		setTexture(path);
	}

	void setTexture(const char* path)
	{
		texture = TextureManager::LoadTexture(path);
	}
	void init() override
	{
		position = &entity->getComponent<TransformComponent>();

		srcRect.x = 0;
		srcRect.y = 0;

		srcRect.w = 214;
		srcRect.h = 342;

		//destRect.x = 0;
		//destRect.y = 0;

		destRect.w = 64;
		destRect.h = 64;
	}

	void update() override
	{
		destRect.x = position->getX();
		destRect.y = position->getY();
	}

	void draw() override
	{
		TextureManager::draw(texture, srcRect, destRect);
	}
};
