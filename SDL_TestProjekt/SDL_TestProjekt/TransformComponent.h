#pragma once
#include "Components.h"

class TransformComponent : public Component
{
private:
	int x;
	int y;
public:
	TransformComponent()
	{
		this->x = 0;
		this->y = 0;
	}

	TransformComponent(int x, int y)
	{
		this->x = x;
		this->y = y;
	}

	int getX() { return x; }
	int getY() { return y; }
	void setX(int x) { this->x = x; }
	void setY(int y) { this->y = y; }

	void update() override
	{
		x++;
		y++;
	}

	void setPos(int x, int y)
	{
		this->x = x;
		this->y = y;
	}
};