#include "Game.h"
#include "TextureManager.h"
#include "Map.h"
#include "Components.h"
#include "Vector2D.h"
#include "Collision.h"

Map* map;

SDL_Renderer* Game::renderer = nullptr;
SDL_Event Game::event;

Manager manager;
auto& player(manager.addEntity());
auto& wall(manager.addEntity());

Game::Game()
{
}

Game::~Game()
{
}

void Game::init(const char * title, int x, int y, int width, int height, bool fullscreen)
{
	int flags = 0;
	if (fullscreen)
	{
		flags = SDL_WINDOW_FULLSCREEN;
	}

	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		std::cout << "SDL-Subsystems initialized..." << std::endl;
		window = SDL_CreateWindow(title, x, y, width, height, flags);
		if (window)
		{
			std::cout << "Window created" << std::endl;
		}

		renderer = SDL_CreateRenderer(window, -1, 0);
		if (renderer)
		{
			SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
			std::cout << "Renderer created" << std::endl;
		}
		isRunning = true;
	}
	else
	{
		isRunning = false;
	}
	map = new Map();

	player.addComponent<TransformComponent>(3);
	player.addComponent<SpriteComponent>("..\\Ressources\\img\\test.png");
	player.addComponent<KeyboardController>();
	player.addComponent<ColliderComponent>("player");

	wall.addComponent<TransformComponent>(300.f,300.f,600,1100,0.15);
	wall.addComponent<SpriteComponent>("..\\Ressources\\img\\tile.png");
	wall.addComponent<ColliderComponent>("wall");
	wall.getComponent<ColliderComponent>().update();
}

void Game::handleEvents()
{
	SDL_PollEvent(&event);
	switch (event.type)
	{
	case SDL_QUIT:
		isRunning = false;
		break;
	default:
		break;
	}
}

void Game::update()
{
	manager.refresh();
	manager.update();
	if (Collision::AABB(player.getComponent<ColliderComponent>().collider,
		wall.getComponent<ColliderComponent>().collider))
	{
		player.getComponent<TransformComponent>().scale = 1;
		std::cout << "Wall Hit!" << std::endl;
	}
}

void Game::render()
{
	SDL_RenderClear(renderer);
	// add stuff to render
	map->drawMap();

	manager.draw();
	SDL_RenderPresent(renderer);
}

void Game::clean()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	std::cout << "Game cleaned...";
}