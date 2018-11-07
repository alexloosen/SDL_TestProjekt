#pragma once
#include "Components.h"
#include "Vector2D.h"

class TransformComponent : public Component
{
public:

	Vector2D position;
	Vector2D velocity;

	int height = 32;
	int width = 32;
	float scale = 1;

	float speed = 3;


	TransformComponent()
	{
		position.x = 0;
		position.y = 0;
	}

	TransformComponent(float sc)
	{
		position.x = 0;
		position.y = 0;
		scale = sc;
	}

	TransformComponent(float x, float y)
	{
		this->position.x = x;
		this->position.y = x;
	}

	TransformComponent(float x, float y, int h, int w, float scale)
	{
		this->position.x = x;
		this->position.y = x;
		this->height = h;
		this->width = w;
		this->scale = scale;
	}

	void init() override
	{
		velocity.x = 0;
		velocity.y = 0;
	}

	void update() override
	{
		position.x += velocity.x * speed;
		position.y += velocity.y * speed;
	}
};